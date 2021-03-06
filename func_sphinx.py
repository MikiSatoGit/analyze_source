#
#	func_sphinx.py
#	Create rst file for Sphinx
#	Create on: 2017.05.26
#	Author   : Miki Sato <miki.sam.sato@gmail.com>
#
#   NOTE:
#

# coding: shift-JIS
import os
import glob
import copy
import pandas




class FileList:
	def __init__(self):
		self.name = ''
		self.arg = []
		self.ret = []
		self.proc = []
		self.cond = []
		self.fig = []
	def clear(self):
		self.name = ''
		del self.arg[:]
		del self.ret[:]
		del self.proc[:]
		del self.cond[:]
		del self.fig[:]


debug_out = False


def get_file_list(sourcefilename, func_list):
	if len(sourcefilename)>1:
		if os.path.exists(sourcefilename[0] + '\\csv')==False:
			os.makedirs(sourcefilename[0] + '\\csv')
		csv_file_base = sourcefilename[0] + '\\csv\\' + sourcefilename[1]

		if os.path.exists(sourcefilename[0] + '\\fig')==False:
			os.makedirs(sourcefilename[0] + '\\fig')
		fig_file_base = sourcefilename[0] + '\\fig\\' + sourcefilename[1]
	else:
		if os.path.exists('\\csv')==False:
			os.makedirs('\\csv')
		csv_file_base = '\\csv\\' + sourcefilename[0]
		if os.path.exists('\\fig')==False:
			os.makedirs('\\fig')
		fig_file_base = '\\fig\\' + sourcefilename[0]

	csv_file_base = csv_file_base[0:csv_file_base.rfind('.')] + '_'
	fig_file_base = fig_file_base[0:fig_file_base.rfind('.')] + '_'

	file_list = FileList()
	FileList_list = []
	for index1 in range(0, func_list.func_num):
		file_list.clear()
		funcname = func_list.function_data[index1].name

		if isinstance(funcname, list):
			funcname = ','.join(funcname)

		argfile = csv_file_base + funcname + '*' + 'arg.csv'
		retfile = csv_file_base + funcname + '*' + 'ret.csv'
		procfile = csv_file_base + funcname + '_' + '*' + '_proc.csv'
		condfile = csv_file_base + funcname + '_' + '*' + '_cond.csv'
		figfile = fig_file_base + funcname + '_' + '*'

		argfile_list = glob.glob(argfile)
		retfile_list = glob.glob(retfile)
		procfile_list = glob.glob(procfile)
		condfile_list = glob.glob(condfile)
		figfile_list = glob.glob(figfile)


		# remove files which includes same word in funcname ( such as aaa() and aaa2() ) #20170606
		argfile_list = check_file_include_funcname(argfile_list, funcname, func_list)
		retfile_list = check_file_include_funcname(retfile_list, funcname, func_list)
		procfile_list = check_file_include_funcname(procfile_list, funcname, func_list)
		condfile_list = check_file_include_funcname(condfile_list, funcname, func_list)
		figfile_list = check_file_include_funcname(figfile_list, funcname, func_list)


		file_list.name = funcname
		file_list.arg = argfile_list
		file_list.ret = retfile_list
		file_list.proc = procfile_list
		file_list.cond = condfile_list
		file_list.fig = figfile_list


		FileList_list.append( copy.deepcopy(file_list) )

	return FileList_list

def set_doc_path(sourcefilename):
	file_title = ''
	if len(sourcefilename)>1:
		file_title = sourcefilename[1][:sourcefilename[1].rfind('.')]
		if os.path.exists(sourcefilename[0] + '\\doc')==False:
			os.makedirs(sourcefilename[0] + '\\doc')
		doc_path = sourcefilename[0] + '\\doc\\source'
		if os.path.exists(doc_path)==False:
			os.makedirs(doc_path)
		doc_path += '\\'
		doc_path += file_title
		if os.path.exists(doc_path)==False:
			os.makedirs(doc_path)
		doc_path += '\\'
	else:
		file_title = sourcefilename[0][:sourcefilename[0].rfind('.')]
		if os.path.exists('\\doc')==False:
			os.makedirs('\\doc')
		doc_path = '\\doc\\source'
		if os.path.exists(doc_path)==False:
			os.makedirs(doc_path)
		doc_path += '\\'
		doc_path += file_title
		if os.path.exists(doc_path)==False:
			os.makedirs(doc_path)
		doc_path += '\\'

	return doc_path


def create_index(doc_path, func_list):
	file_title = doc_path[:doc_path.rfind('\\')]
	file_title = file_title[file_title.rfind('\\')+1:]
	rstfile = doc_path + 'index.rst'
	code =''

	fout_rst = open(rstfile,'w')

	code = '================================================='
	code += '\n'
	code += file_title
	code += '\n'
	code += '================================================='
	code += '\n'
	code += '\n'
	code += '\n'
	code += '.. toctree::'
	code += '\n'
	code += indent()
	code += ':maxdepth: 1'
	code += '\n'
	code += '\n'

	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name

		if isinstance(funcname, list):
			funcname = ','.join(funcname)

		code += indent()
		code += funcname
		code += '\n'

	fout_rst.write(code)
	fout_rst.close()

	return rstfile


def create_func_main(doc_path, func_list, fileList_list):
	if debug_out:
		print '<create_func_main> [PATH] %s' % doc_path

	code = ''
	doc_title = doc_path[:doc_path.rfind('\\')]
	doc_title = doc_title[doc_title.rfind('\\')+1:]

	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name

		if debug_out:
			print '<create_func_main> [FUNCNAME] %s[%d/%d]' % (funcname, index1+1, func_list.func_num)


		if isinstance(funcname, list):
			funcname = ','.join(funcname)

		code = ''
		tmp_filelist = fileList_list[index1]

##### Open file #####
		rstfile = doc_path + funcname + '.rst'
		fout_rst = open(rstfile,'w')


##### TITLE #####
		tmp_code = title_top(funcname, '')
		code += tmp_code


##### INTERFACE #####
		tmp_code = title_interface()
		code += tmp_code

		# Arguments
		# replaced create_argument_code() to parse_arg_csv_to_listtable to include blockdiag code in rst file 20160622
		#tmp_code, tmp_filelist = create_argument_code(tmp_filelist)
		tmp_code, tmp_filelist = parse_arg_csv_to_listtable(tmp_filelist, doc_path)
		code += tmp_code

		# Return value
		# replaced create_return_value_code() to parse_ret_csv_to_listtable to include blockdiag code in rst file 20160622
		#tmp_code, tmp_filelist = create_return_value_code(tmp_filelist)
		tmp_code, tmp_filelist = parse_ret_csv_to_listtable(tmp_filelist, doc_path)
		code += tmp_code


##### MAIN FLOW #####
		tmp_code = title_main_flow()
		code += tmp_code

		# Main process flow
		# replaced create_main_flow_code() to parse_main_flow_code() to include blockdiag code in rst file 20160622
		#tmp_code, tmp_filelist = create_main_flow_code('MAINPROCESS', tmp_filelist, funcname)
		tmp_code, tmp_filelist = parse_main_flow_code('MAINPROCESS', tmp_filelist, funcname, doc_path)
		code += tmp_code


##### PROCESS TABLE #####
		tmp_code = title_proc_table()
		code += tmp_code

		# Proc. table
		# replaced create_proc_code() to parse_proc_csv_to_listtable() to include table code in rst file 20160622
		#tmp_code, tmp_filelist = create_proc_code('MAINPROCESS', tmp_filelist, funcname)
		tmp_code, tmp_filelist = parse_proc_csv_to_listtable('MAINPROCESS', tmp_filelist, funcname, doc_path)
		code += tmp_code


##### CONDITION TABLE #####
		tmp_code = title_cond_table()
		code += tmp_code

		# Cond. table
		# replaced create_cond_code() to parse_cond_csv_to_listtable() to include table code in rst file 20160622
		#tmp_code, tmp_filelist = create_cond_code('MAINPROCESS', tmp_filelist, funcname)
		tmp_code, tmp_filelist = parse_cond_csv_to_listtable('MAINPROCESS', tmp_filelist, funcname, doc_path)
		code += tmp_code


##### SUBPROC LINK #####
		tmp_code = title_subproc_link()
		code += tmp_code

		# Subproc link
		tmp_code = create_subproc_link_code('SUBPROCESS', funcname, tmp_filelist, doc_title)
		code += tmp_code

##### Close file #####
		fout_rst.write(code)
		fout_rst.close()

		fileList_list[index1] = tmp_filelist

	return fileList_list



def create_func_sub(doc_path, func_list, fileList_list, level_title):

	if debug_out:
		print '<create_func_sub> [PATH] %s' % doc_path

	code = ''
	level_key = '_' + level_title + '.'
	doc_title = doc_path[:doc_path.rfind('\\')]
	doc_title = doc_title[doc_title.rfind('\\')+1:]

	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name

		tmp_filelist = fileList_list[index1]
		for fig in reversed(fileList_list[index1].fig):
			if debug_out:
				print '<create_func_sub> ...cheking %s@%s' % (fig, level_key)

			if fig.find(level_key)!=-1:
				subproc_file = fig[fig.rfind('\\')+1:fig.rfind(".")]
				subproc_file = subproc_file[subproc_file.find(funcname):]
				sub_funcname = subproc_file.replace('_'+level_title, '')

##### Open file #####
				code = ''
				rstfile = doc_path + subproc_file + '.rst'
				fout_rst = open(rstfile,'w')

##### TITLE #####
				subproc_name = subproc_file.replace(funcname+'_','')
				subproc_name = subproc_name.replace('PROCESS','1')

				if debug_out:
					print '<create_func_sub>----------------------------------'
					print '<create_func_sub> [FUNC] %s' % funcname
					print '<create_func_sub> [SUB FILE] %s' % subproc_file
					print '<create_func_sub> [SUB FUNC] %s' % sub_funcname
					print '<create_func_sub> [SUB NAME] %s' % subproc_name
					print '<create_func_sub>----------------------------------'

				tmp_code = title_top(funcname, subproc_name)
				code += tmp_code

##### MAIN FLOW #####
				tmp_code = title_main_flow()
				code += tmp_code

				# Main process flow
				# replaced create_main_flow_code() to parse_main_flow_code() to include blockdiag code in rst file 20160622
				#tmp_code, tmp_filelist = create_main_flow_code(level_title, tmp_filelist, sub_funcname)
				tmp_code, tmp_filelist = parse_main_flow_code(level_title, tmp_filelist, sub_funcname, doc_path)
				code += tmp_code

##### PROCESS TABLE #####
				tmp_code = title_proc_table()
				code += tmp_code

				# Proc. table
				# replaced create_proc_code() to parse_proc_csv_to_listtable() to include table code in rst file 20160622
				#tmp_code, tmp_filelist = create_proc_code(level_title, tmp_filelist, sub_funcname)
				tmp_code, tmp_filelist = parse_proc_csv_to_listtable(level_title, tmp_filelist, sub_funcname, doc_path)
				code += tmp_code

##### CONDITION TABLE #####
				tmp_code = title_cond_table()
				code += tmp_code

				# Cond. table
				# replaced create_cond_code() to parse_cond_csv_to_listtable() to include table code in rst file 20160622
				#tmp_code, tmp_filelist = create_cond_code(level_title, tmp_filelist, sub_funcname)
				tmp_code, tmp_filelist = parse_cond_csv_to_listtable(level_title, tmp_filelist, sub_funcname, doc_path)
				code += tmp_code


##### SUBPROC LINK #####
				tmp_code = title_subproc_link()
				code += tmp_code

				# Subproc link
				tmp_code = create_subproc_link_code('SUB'+level_title, sub_funcname, tmp_filelist, doc_title)
				code += tmp_code

##### Close file #####
				fout_rst.write(code)
				fout_rst.close()


		fileList_list[index1] = tmp_filelist

	return fileList_list











def indent():
	indent = '   '
	return indent

def table_header_top():
	table_header_top = '.. csv-table:: '
#	table_header_top += '\n'
#	table_header_top += indent()
#	table_header_top += ':header: '
	return table_header_top

def image_header():
	image_header_top = '.. image:: ../../../fig/'
	return image_header_top

def image_footer():
	image_footer = '\n'
	image_footer += indent()
	image_footer += ':width: 600px'
	return image_footer

def table_footer_interface():
	table_footer_interface = '\n'
	table_footer_interface += indent()
	table_footer_interface += ':encoding: utf-8'
	table_footer_interface += '\n'

	table_footer_interface += indent()
	table_footer_interface += ':align: left'
	table_footer_interface += '\n'

	table_footer_interface += indent()
	table_footer_interface += ':header-rows: 1'
	table_footer_interface += '\n'
	table_footer_interface += indent()
	table_footer_interface += ':widths: 40, 5, 10, 5, 10, 10, 10, 10'
	table_footer_interface += '\n'
	table_footer_interface += indent()
	table_footer_interface += ':file: ../../../csv/'
	return table_footer_interface

def list_footer_interface():
	list_footer_interface  = indent()
	list_footer_interface += ':header-rows: 1'
	list_footer_interface += '\n'
	list_footer_interface += indent()
	list_footer_interface += ':widths: 40, 5, 10, 5, 10, 10, 10, 10'
	list_footer_interface += '\n'
	return list_footer_interface

def table_footer_proc():
	table_footer_proc = '\n'
	table_footer_proc += indent()
	table_footer_proc += ':encoding: utf-8'
	table_footer_proc += '\n'

	table_footer_proc += indent()
	table_footer_proc += ':align: left'
	table_footer_proc += '\n'

	table_footer_proc += indent()
	table_footer_proc += ':header-rows: 1'
	table_footer_proc += '\n'
	table_footer_proc += indent()
	table_footer_proc += ':widths: 20, 40, 25, 15'
	table_footer_proc += '\n'
	table_footer_proc += indent()
	table_footer_proc += ':file: ../../../csv/'
	return table_footer_proc

def list_footer_proc():
	list_footer_proc = indent()
	list_footer_proc += ':header-rows: 1'
	list_footer_proc += '\n'
	list_footer_proc += indent()
	list_footer_proc += ':widths: 20, 40, 25, 15'
	list_footer_proc += '\n'
	return list_footer_proc

def table_footer_cond():
	table_footer_cond = '\n'
	table_footer_cond += indent()
	table_footer_cond += ':encoding: utf-8'
	table_footer_cond += '\n'

	table_footer_cond += indent()
	table_footer_cond += ':align: left'
	table_footer_cond += '\n'

	table_footer_cond += indent()
	table_footer_cond += ':header-rows: 1'
	table_footer_cond += '\n'
	table_footer_cond += indent()
	table_footer_cond += ':widths: 20, 40, 40'
	table_footer_cond += '\n'
	table_footer_cond += indent()
	table_footer_cond += ':file: ../../../csv/'
	return table_footer_cond

def list_footer_cond():
	list_footer_cond  = indent()
	list_footer_cond += ':header-rows: 1'
	list_footer_cond += '\n'
	list_footer_cond += indent()
	list_footer_cond += ':widths: 20, 40, 40'
	list_footer_cond += '\n'
	return list_footer_cond

def link_header():
	link_header = '.. toctree::'
	link_header += indent()
	link_header += ':maxdepth: 1'
	link_header += '\n'
	link_header += '\n'
	return link_header

def title_top(funcname, subproc_name):
	num = len(funcname)
	num += len(subproc_name)
	num += 5

	code = ''
#	code = '================================================='
	for index in range(0,num):
		code += '='
	code += '\n'
	code += funcname
	if subproc_name != '':
		code += '::'
		code += subproc_name
	code += '\n'
#	code += '================================================='
	for index in range(0,num):
		code += '='
	code += '\n'
	code += '\n'
	code += '\n'
	return code

def title_interface():
	code = ''
	code += '+++++++++++++++++++'
	code += '\n'
	code += 'Interface'
	code += '\n'
	code += '+++++++++++++++++++'
	code += '\n'
	code += '\n'
	return code

def title_main_flow():
	code = ''
	code += '+++++++++++++++++++'
	code += '\n'
	code += 'Main Process Flow'
	code += '\n'
	code += '+++++++++++++++++++'
	code += '\n'
	code += '\n'
	return code

def title_proc_table():
	code = ''
	code += '+++++++++++++++++++'
	code += '\n'
	code += 'Process Table'
	code += '\n'
	code += '+++++++++++++++++++'
	code += '\n'
	code += '\n'
	return code

def title_cond_table():
	code = ''
	code += '+++++++++++++++++++'
	code += '\n'
	code += 'Condition Table'
	code += '\n'
	code += '+++++++++++++++++++'
	code += '\n'
	code += '\n'
	return code

def title_subproc_link():
	code = ''
	code += '+++++++++++++++++++'
	code += '\n'
	code += 'Subprocesses'
	code += '\n'
	code += '+++++++++++++++++++'
	code += '\n'
	code += '\n'
	return code

def create_argument_code(filelist):
	table_header_arg = table_header_top()
	table_header_arg += 'Arguments'
	table_header_arg += table_footer_interface()
	code = ''
	cnt = 0
	used_arg = []
	for item in filelist.arg:
		arg_file =  item[item.rfind('\\')+1:]
		code += table_header_arg
		code += arg_file
		code += '\n'
		code += '\n'
		used_arg.append(cnt)
		cnt += 1
	for id in reversed(used_arg):
		filelist.arg.pop(id)
	return code, filelist

def parse_arg_csv_to_listtable(filelist, doc_path):
	code = ''
	cnt = 0
	used_arg = []
	for item in filelist.arg:
		arg_file =  item[item.rfind('\\')+1:]

		# \doc\source\(source file)
		# \csv\
		csv_file_path = doc_path
		for tmp_cnt in range(0,4):
			csv_file_path = csv_file_path[:csv_file_path.rfind('\\')]
		csv_file_path += '/csv/' + arg_file

		datalist = read_csv_file(csv_file_path)

		code += '.. list-table:: '
		code += 'Arguments'
		code += '\n'
		code += list_footer_interface()
		code += '\n'
		code += datalist
		code += '\n'
		code += '\n'
		code += '-----------------------------'
		code += '\n'
		code += '\n'

		used_arg.append(cnt)
		cnt += 1
	for id in reversed(used_arg):
		filelist.arg.pop(id)
	return code, filelist

def create_return_value_code(filelist):
	table_header_ret = table_header_top()
	table_header_ret += 'Return Value'
	table_header_ret += table_footer_interface()
	code = ''
	cnt = 0
	used_ret = []
	for item in filelist.ret:
		ret_file =  item[item.rfind('\\')+1:]
		code += table_header_ret
		code += ret_file
		code += '\n'
		code += '\n'
		used_ret.append(cnt)
		cnt += 1
	for id in reversed(used_ret):
		filelist.ret.pop(id)
	return code, filelist

def parse_ret_csv_to_listtable(filelist, doc_path):
	code = ''
	cnt = 0
	used_ret = []
	for item in filelist.ret:
		ret_file =  item[item.rfind('\\')+1:]

		# \doc\source\(source file)
		# \csv\
		csv_file_path = doc_path
		for tmp_cnt in range(0,4):
			csv_file_path = csv_file_path[:csv_file_path.rfind('\\')]
		csv_file_path += '/csv/' + ret_file

		datalist = read_csv_file(csv_file_path)

		code += '.. list-table:: '
		code += 'Return Value'
		code += '\n'
		code += list_footer_interface()
		code += '\n'
		code += datalist
		code += '\n'
		code += '\n'
		code += '-----------------------------'
		code += '\n'
		code += '\n'

		used_ret.append(cnt)
		cnt += 1
	for id in reversed(used_ret):
		filelist.ret.pop(id)
	return code, filelist

def create_main_flow_code(level_title, filelist, funcname):
	code = ''
	cnt = 0
	used_fig = []
	level_key = '_' + level_title + '.'
	for item in filelist.fig:
		fig_title = funcname + level_key
		fig_file =  item[item.rfind('\\')+1:]
		if fig_file.find(fig_title)!=-1:
			code += image_header()
			code += fig_file
			code += image_footer()
			code += '\n'
			code += '\n'
			used_fig.append(cnt)
		cnt += 1
	for id in reversed(used_fig):
		filelist.fig.pop(id)

	return code, filelist


def parse_main_flow_code(level_title, filelist, funcname, doc_path):
	code = ''
	cnt = 0
	used_fig = []
	level_key = '_' + level_title + '.'
	for item in filelist.fig:
		fig_title = funcname + level_key
		fig_file =  item[item.rfind('\\')+1:]
		if fig_file.find(fig_title)!=-1:

			diag_file_path = doc_path[:doc_path.find('\\')]
			diag_file_path += '/fig/' + fig_file

			# \doc\source\(source file)
			# \fig\
			diag_file_path = doc_path
			for tmp_cnt in range(0,4):
				diag_file_path = diag_file_path[:diag_file_path.rfind('\\')]
			diag_file_path += '/fig/' + fig_file

			f_diag = open(diag_file_path,'r')

			code += '.. blockdiag::\n'
			code += '\n'
			for line in f_diag:
				code += indent()
				code += line
			code += '\n'
			code += '\n'

			used_fig.append(cnt)
			f_diag.close()
		cnt += 1
	for id in reversed(used_fig):
		filelist.fig.pop(id)

	return code, filelist


def create_proc_code(level_title, filelist, funcname):
	code = ''
	cnt = 0
	used_proc = []
	level_key = '_' + level_title +'_'
	for item in filelist.proc:
		proc_title = funcname + level_key
		proc_file =  item[item.rfind('\\')+1:]
		proc_sub_title = proc_file[proc_file.find(level_key)+len(level_key):]
		proc_sub_title = proc_sub_title.replace('_proc.csv','')
		if proc_file.find(proc_title)!=-1:
			code += table_header_top()
			code += proc_sub_title
			code += table_footer_proc()
			code += proc_file
			code += '\n'
			code += '\n'
			code += '-----------------------------'
			code += '\n'
			code += '\n'
			used_proc.append(cnt)
		cnt += 1
	for id in reversed(used_proc):
		filelist.proc.pop(id)
	return code, filelist


def parse_proc_csv_to_listtable(level_title, filelist, funcname, doc_path):
	code = ''
	cnt = 0
	used_proc = []
	level_key = '_' + level_title +'_'
	for item in filelist.proc:
		proc_title = funcname + level_key
		proc_file =  item[item.rfind('\\')+1:]
		proc_sub_title = proc_file[proc_file.find(level_key)+len(level_key):]
		proc_sub_title = proc_sub_title.replace('_proc.csv','')
		if proc_file.find(proc_title)!=-1:

			# \doc\source\(source file)
			# \csv\
			csv_file_path = doc_path
			for tmp_cnt in range(0,4):
				csv_file_path = csv_file_path[:csv_file_path.rfind('\\')]
			csv_file_path += '/csv/' + proc_file

			datalist = read_csv_file(csv_file_path)

			code += '.. list-table:: '
			code += proc_sub_title
			code += '\n'
			code += list_footer_proc()
			code += '\n'
			code += datalist
			code += '\n'
			code += '\n'
			code += '-----------------------------'
			code += '\n'
			code += '\n'

			used_proc.append(cnt)
		cnt += 1
	for id in reversed(used_proc):
		filelist.proc.pop(id)
	return code, filelist

def create_cond_code(level_title, filelist, funcname):
	code = ''
	cnt = 0
	used_cond = []
	level_key = '_' + level_title +'_'
	for item in filelist.cond:
		cond_title = funcname + level_key
		cond_file =  item[item.rfind('\\')+1:]
		cond_sub_title = cond_file[cond_file.find(level_key)+len(level_key):]
		cond_sub_title = cond_sub_title.replace('_cond.csv','')
		cond_sub_title = cond_sub_title[:cond_sub_title.rfind('_')]
		if cond_file.find(cond_title)!=-1:
			code += table_header_top()
			code += cond_sub_title
			code += table_footer_cond()
			code += cond_file
			code += '\n'
			code += '\n'
			code += '-----------------------------'
			code += '\n'
			code += '\n'
			used_cond.append(cnt)
		cnt += 1
	for id in reversed(used_cond):
		filelist.cond.pop(id)
	return code, filelist

def parse_cond_csv_to_listtable(level_title, filelist, funcname, doc_path):
	code = ''
	cnt = 0
	used_cond = []
	level_key = '_' + level_title +'_'
	for item in filelist.cond:
		cond_title = funcname + level_key
		cond_file =  item[item.rfind('\\')+1:]
		cond_sub_title = cond_file[cond_file.find(level_key)+len(level_key):]
		cond_sub_title = cond_sub_title.replace('_cond.csv','')
		cond_sub_title = cond_sub_title[:cond_sub_title.rfind('_')]
		if cond_file.find(cond_title)!=-1:

			# \doc\source\(source file)
			# \csv\
			csv_file_path = doc_path
			for tmp_cnt in range(0,4):
				csv_file_path = csv_file_path[:csv_file_path.rfind('\\')]
			csv_file_path += '/csv/' + cond_file

			datalist = read_csv_file(csv_file_path)

			code += '.. list-table:: '
			code += cond_sub_title
			code += '\n'
			code += list_footer_cond()
			code += '\n'
			code += datalist
			code += '\n'
			code += '\n'
			code += '-----------------------------'
			code += '\n'
			code += '\n'

			used_cond.append(cnt)
		cnt += 1
	for id in reversed(used_cond):
		filelist.cond.pop(id)
	return code, filelist


def create_subproc_link_code(level_title, func_title, filelist, doc_title):
	code = ''
	level_key = '_' + level_title +'.'
	header_flg = False

	for item in filelist.fig:
		fig_title = level_key
		fig_file =  item[item.rfind('\\')+1:]
		sub_link =  fig_file[fig_file.find(doc_title + '_')+len(doc_title)+1:]
		sub_link =  sub_link[:sub_link.rfind('.')]
		if fig_file.find(fig_title)!=-1 and fig_file.find(func_title)!=-1:
			if not header_flg:
				code += link_header()
				header_flg = True
			code += indent()
			code += sub_link
			code += '\n'
			code += '\n'
	code += '\n'
	return code


def check_files(fileList_list):
	bret = False
	if len(fileList_list)!=0:
		for filelist in fileList_list:

			if debug_out:
				print '<check_files>---------------------------------------'
				print '<check_files> arg: %d' % len(filelist.arg)
				print '<check_files> ret: %d' % len(filelist.ret)
				print '<check_files> proc: %d' % len(filelist.proc)
				print '<check_files> cond: %d' % len(filelist.cond)
				print '<check_files> fig: %d' % len(filelist.fig)

			if len(filelist.arg)!=0 \
			or len(filelist.ret)!=0 \
			or len(filelist.proc)!=0 \
			or len(filelist.cond)!=0 \
			or len(filelist.fig)!=0:
				bret = True
	return bret


def check_file_include_funcname(file_list, funcname, func_list):
	file_list_out = []
	counfusing_filename_list = []
	for index1 in range(0, func_list.func_num):
		tmp_funcname = func_list.function_data[index1].name.strip()
		if tmp_funcname!=funcname.strip() and tmp_funcname.find(funcname.strip())!=-1:
			counfusing_filename_list.append(tmp_funcname)

	for filename in file_list:
		erase = False
		for counfusing_filename in counfusing_filename_list:
			if filename.find(counfusing_filename)!=-1:
				erase = True

		if not erase:
			file_list_out.append(filename)


	return file_list_out


def read_csv_file(csvfile_path):
	code = ''
	print csvfile_path
	csv = pandas.read_csv(csvfile_path, header=None)
	for index1 in range(0,len(csv.index)):
		for index2 in range(0,len(csv.columns)):
			item = str(csv.iloc[index1, index2])
			item = item.strip()
			if item=='nan':
				item = ''
			code += indent()
			if index2 ==0:
				code += '* '
				code += '- '
			else:
				code += '  '
				code += '- '
			code += item
			code += '\n'
	return code

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
	indent = '   '

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
	code += indent
	code += ':maxdepth: 2'
	code += '\n'
	code += '\n'

	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name
		code += indent
		code += funcname
		code += '\n'

	fout_rst.write(code)
	fout_rst.close()

	return rstfile


def create_func_main(doc_path, func_list, fileList_list):
	debug_out = True

	if debug_out:
		print '<create_func_main> [PATH] %s' % doc_path

	code =''
	indent = '   '


	table_header_arg = table_header_top()
	table_header_arg += 'Arguments'
	table_header_arg += table_header_interface()

	table_header_ret = table_header_top()
	table_header_ret += 'Return Value'
	table_header_ret += table_header_interface()



	image_header_fig = '.. image:: ../../../fig/'
	table_footer_fig = '\n'
	table_footer_fig += indent
	table_footer_fig += ':width: 600px'


	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name
		rstfile = doc_path + funcname + '.rst'
		fout_rst = open(rstfile,'w')

		code = '================================================='
		code += '\n'
		code += funcname
		code += '\n'
		code += '================================================='
		code += '\n'
		code += '\n'
		code += '\n'


		code += '+++++++++++++++++++'
		code += '\n'
		code += 'Interface'
		code += '\n'
		code += '+++++++++++++++++++'
		code += '\n'
		code += '\n'

		# Arguments
		cnt = 0
		used_arg = []
		for item in fileList_list[index1].arg:
			arg_file =  item[item.rfind('\\')+1:]
			code += table_header_arg
			code += arg_file
			code += '\n'
			code += '\n'
			used_arg.append(cnt)
			cnt += 1
		for id in reversed(used_arg):
			fileList_list[index1].arg.pop(id)

		# Return value
		cnt = 0
		used_ret = []
		for item in fileList_list[index1].ret:
			ret_file =  item[item.rfind('\\')+1:]
			code += table_header_ret
			code += ret_file
			code += '\n'
			code += '\n'
			used_ret.append(cnt)
			cnt += 1
		for id in reversed(used_ret):
			fileList_list[index1].ret.pop(id)


		code += '+++++++++++++++++++'
		code += '\n'
		code += 'Main Process Flow'
		code += '\n'
		code += '+++++++++++++++++++'
		code += '\n'
		code += '\n'

		# Main process flow
		cnt = 0
		used_fig = []
		for item in fileList_list[index1].fig:
			fig_title = funcname + '_MAINPROCESS.'
			fig_file =  item[item.rfind('\\')+1:]
			if fig_file.find(fig_title)!=-1:
				code += image_header_fig
				code += fig_file
				code += table_footer_fig
				code += '\n'
				code += '\n'
				used_fig.append(cnt)
			cnt += 1
		print used_fig
		for id in reversed(used_fig):
			print len(fileList_list[index1].fig)
			fileList_list[index1].fig.pop(id)
			print len(fileList_list[index1].fig)


		code += '================================================='
		code += '\n'
		code += 'Process Table'
		code += '\n'
		code += '================================================='
		code += '\n'
		code += '\n'

		# Proc. table
		cnt = 0
		used_proc = []
		for item in fileList_list[index1].proc:
			proc_title = funcname + '_MAINPROCESS_'
			proc_file =  item[item.rfind('\\')+1:]
			proc_sub_title = proc_file[proc_file.find('_MAINPROCESS_')+len('_MAINPROCESS_'):]
			proc_sub_title = proc_sub_title.replace('_proc.csv','')
			if proc_file.find(proc_title)!=-1:
				code += table_header_top()
				code += proc_sub_title
				code += table_header_proc()
				code += proc_file
				code += '\n'
				code += '\n'
				code += '============================='
				code += '\n'
				code += '\n'
				used_proc.append(cnt)
			cnt += 1
		for id in reversed(used_proc):
			fileList_list[index1].proc.pop(id)


		code += '================================================='
		code += '\n'
		code += 'Condition Table'
		code += '\n'
		code += '================================================='
		code += '\n'
		code += '\n'

		# Cond. table
		cnt = 0
		used_cond = []
		for item in fileList_list[index1].cond:
			cond_title = funcname + '_MAINPROCESS_'
			cond_file =  item[item.rfind('\\')+1:]
			cond_sub_title = cond_file[cond_file.find('_MAINPROCESS_')+len('_MAINPROCESS_'):]
			cond_sub_title = cond_sub_title.replace('_cond.csv','')
			cond_sub_title = cond_sub_title[:cond_sub_title.rfind('_')]
			if cond_file.find(cond_title)!=-1:
				code += table_header_top()
				code += cond_sub_title
				code += table_header_cond()
				code += cond_file
				code += '\n'
				code += '\n'
				code += '============================='
				code += '\n'
				code += '\n'
				used_cond.append(cnt)
			cnt += 1
		for id in reversed(used_cond):
			fileList_list[index1].cond.pop(id)



		code += '================================================='
		code += '\n'
		code += 'Subprocesses'
		code += '\n'
		code += '================================================='
		code += '\n'
		code += '\n'

		# Subproc link
		cnt = 0
		for item in fileList_list[index1].fig:
			fig_title = '_SUBPROCESS.'
			fig_file =  item[item.rfind('\\')+1:]
			sub_link =  fig_file[fig_file.find('_', 1)+1:]
			sub_link =  sub_link[:sub_link.rfind('.')]
			if fig_file.find(fig_title)!=-1:
				code += sub_link
				code += '\n'
				code += '\n'
		code += '\n'


		fout_rst.write(code)
		fout_rst.close()







	return fileList_list


def table_header_top():
	table_header_top = '.. csv-table:: '
	return table_header_top


def table_header_interface():
	table_header_interface = '\n'
	table_header_interface += indent
	table_header_interface += ':encoding: utf-8'
	table_header_interface += '\n'
	table_header_interface += indent
	table_header_interface += ':header-rows: 1'
	table_header_interface += '\n'
	table_header_interface += indent
	table_header_interface += ':widths: 40, 5, 10, 5, 10, 10, 10, 10'
	table_header_interface += '\n'
	table_header_interface += indent
	table_header_interface += ':file: ../../../csv/'
	return table_header_interface


def table_header_proc():
	table_header_proc = '\n'
	table_header_proc += indent
	table_header_proc += ':encoding: utf-8'
	table_header_proc += '\n'
	table_header_proc += indent
	table_header_proc += ':header-rows: 1'
	table_header_proc += '\n'
	table_header_proc += indent
	table_header_proc += ':widths: 20, 40, 25, 15'
	table_header_proc += '\n'
	table_header_proc += indent
	table_header_proc += ':file: ../../../csv/'
	return table_header_proc


def table_header_cond():
	table_header_cond = '\n'
	table_header_cond += indent
	table_header_cond += ':encoding: utf-8'
	table_header_cond += '\n'
	table_header_cond += indent
	table_header_cond += ':header-rows: 1'
	table_header_cond += '\n'
	table_header_cond += indent
	table_header_cond += ':widths: 20, 40, 40'
	table_header_cond += '\n'
	table_header_cond += indent
	table_header_cond += ':file: ../../../csv/'
	return table_header_cond

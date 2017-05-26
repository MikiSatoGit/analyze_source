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

def create_func_main(doc_path, func_list):
	code =''
	indent = '   '

	table_header = '\n'
	table_header += indent
	table_header += ':encoding: utf-8'
	table_header += '\n'
	table_header += indent
	table_header += ':header-rows: 1'
	table_header += '\n'
	table_header += indent
	table_header += ':widths: 40, 5, 10, 5, 10, 10, 10, 10'
	table_header += '\n'
	table_header += indent
	table_header += ':file: ..\\..\\..\\'

	table_header_top = '.. csv-table:: '

	table_header_arg = table_header_top
	table_header_arg += 'Arguments'
	table_header_arg += table_header

	table_header_ret = table_header_top
	table_header_ret = 'Return Value'
	table_header_ret += table_header





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


		code += '+++++++++++++++++++'
		code += '\n'
		code += 'Main Process Flow'
		code += '\n'
		code += '+++++++++++++++++++'
		code += '\n'
		code += '\n'


		fout_rst.write(code)
		fout_rst.close()

	return

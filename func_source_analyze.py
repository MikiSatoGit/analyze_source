#
#	func_source_analyze.py
#	Data and funtion class for analyzing C source code
#	Create on: 2017.04.10
#	Author   : Miki Sato <miki_sato@denso-diam.com>
#	Copyright (C) 2017
#		DENSO International America Inc.
#

# coding: shift-JIS
import csv

class Data:
	def __init__(self):
		self.type = []
		self.name = []

class ArgumentData:
	def __init__(self):
		self.argument_data = []

class ReturnData:
	def __init__(self):
		self.return_data = []


class FunctionData:
	def __init__(self):
		self.name = []
		self.argument_list = []
		self.return_list = []
		self.codes = []
		self.line_num = 0

class FunctionList:
	def __init__(self):
		self.function_data = []
		self.func_num = 0

def load_valid_source_code(source_file):
	cnt = 0
	skipping = 0
	valid_lines = []
	lines = source_file.readlines()
	for line_org in lines :
		line = line_org.strip()
		if skipping == 0:
			if line.find('#include')!=-1 \
			or line.find('#define')!=-1 \
			or line.find('//')== 0:
				# skip current line
				cnt = cnt
			else:
				if line.find('/*')== 0:	#start comment out
					if line.find('*/')!= -1: #finish comment out at the same line
						# skip current line
						cnt = cnt
					else: # skip till the end of comment out
						skipping = 1
				else:
					if len(line)>0: # not NULL
						# save line
						valid_lines.append(line_org)
						cnt += 1
		else:
			if line.find('*/')!= -1: # fine the end of comment out
					skipping = 0
	return cnt, valid_lines

def find_functions(valid_lines):
	cnt = 0
	func_list = FunctionList()
	searching = 0
	line_num = -1
	for line in valid_lines:
		line_num += 1
		#find "{"
		if searching == 0:
			if line.find('{')!=-1:
				if line.find('=')!=-1 \
				and line.find('=')<line.find('{'): #start array definition
					searching = 1	#array
					level = 1
					if line.find('}')!=-1: #finish function at the same line
						searching = 0
						level = 0
				else: #start function definition
					searching = 2	#function
					level = 1
					print "start@ %d" % (line_num+1)
					function_data = FunctionData()
					function_data.codes.append(valid_lines)
					function_data.line_num += 1
					if line.find('}')!=-1: #finish function at the same line
						searching = 0
						level = 0
						print "end@ %d" % (line_num+1)
						func_list.function_data.append(function_data)
						func_list.func_num += 1	
		#find "}"
		else:
			if line.find('{')!=-1:
				level += 1
			elif line.find('}')!=-1:
				level -= 1
				if level == 0:
					if searching == 2:	#function
						print "end@ %d" % (line_num+1)
						function_data.codes.append(valid_lines)
						function_data.line_num += 1
						func_list.function_data.append(function_data)
						func_list.func_num += 1	
					searching = 0
				else:
					function_data.codes.append(valid_lines)
					function_data.line_num += 1


	return func_list

#
#	func_source_analyze.py
#	Data and funtion class for analyzing C source code
#	Create on: 2017.04.10
#	Author   : Miki Sato <miki_sato@denso-diam.com>
#	Copyright (C) 2017
#		DENSO International America Inc.
#

# coding: shift-JIS
import copy
import csv

class ArgumentData:
	def __init__(self):
		self.name = ''
		self.type = ''


class ProcessData:
	def __init__(self):
		self.type = []	#if, for, while, process...
		self.left = []
		self.right = []

class ProcessList:
	def __init__(self):
		self.process = []
		self.subprocess = []


class FunctionData:
	def __init__(self):
		self.name = ''
		self.return_type = ''
		self.argument_list = []
		self.argument_num = 0
		self.func_def = []
		self.codes = []
		self.line_num = 0
		self.process_list = []

	def set_name(self):
		func_name = ''
		for index1 in range(0, len(self.func_def)):
			str = self.func_def[index1]
			if str.find('(')!=-1:
				str.strip()
				num = str.find('(')
				func_name += str[0:num]
				break
			else:
				func_name = str.strip()
		str = ''
		str = func_name.split()
		if len(str)>2:
			self.return_type = str[0]
			for index in range(1, len(str)-1):
				self.return_type += " "
				self.return_type += str[index]
			self.name = str[len(str)-1]
		elif len(str)>1:
			self.return_type = str[0]
			self.name = str[1]
		else:
			self.return_type = ''
			self.name = str

		return

	def count_arguments(self):
		str = ''
		str_name = ''
		str_type = ''
		level = 0

		for index1 in range(0, len(self.func_def)):
			str = self.func_def[index1]
			str = remove_comment_line(str)
			if str!='':
				if str.find('(')!=-1:
					level += 1
					if level==1:
						str = str[str.find('('):-1]
				if str.find(')')!=-1:
					level -= 1
					if level==0:
						str = str[0:str.find(')')]
				if str.find(',')!=-1:
					str = str[0:str.find(',')]
				if len(str)!=0:
					str = str.split()
					if len(str)>2:
						str_type = str[0]
						for index in range(1, len(str)-1):
							str_type += " "
							str_type += str[index]
						str_name = str[len(str)-1]
					elif len(str)>1:
						str_type = str[0]
						str_name = str[1]
					else:
						str_type = ''
						str_name = ''
					arg_data = ArgumentData()
					arg_data.type = str_type
					arg_data.name = str_name
					self.argument_list.append(arg_data)
		self.argument_num = len(self.argument_list)
		if self.argument_num==1 and self.argument_list[0].name=='':
			self.argument_num = 0
		return self.argument_num



	def count_lines(self):
		self.line_num = len(self.codes)
		return

class FunctionList:
	def __init__(self):
		self.function_data = []
		self.func_num = 0


############################################################################################

def set_func_def_lines(FunctionData, lines):
	for index in range(0,len(lines)):
		FunctionData.func_def.append(lines[index])
	return 


def set_code_lines(FunctionData, lines):
	for index in range(0,len(lines)):
		FunctionData.codes.append(lines[index])
	return 


def set_function_data(FunctionData, func_def_lines, func_content_lines):
	set_func_def_lines(FunctionData, func_def_lines)
	FunctionData.set_name()
	FunctionData.count_arguments()
	set_code_lines(FunctionData, func_content_lines)
	FunctionData.count_lines()


def load_valid_source_code(source_file):
	cnt = 0
	skipping = 0
	valid_lines = []
	lines = source_file.readlines()

	cnt, valid_lines = remove_undefined_codes(lines)
	cnt, valid_lines = remove_comment_codes(valid_lines)

	return cnt, valid_lines


def remove_comment_line(line):
	line_out = line.strip()
	str1 = ''
	str2 = ''
	if line_out.find('//')!=-1:
		str1 = line_out[0:line_out.find('//')]
		line_out = str1
		line_out = line_out.strip()
	str1 = ''
	while line_out.find('/*')!=-1 or line_out.find('*/')!=-1:
		if line_out.find('/*')!=-1:
			if line_out.find('*/')!=-1:
				str1 = line_out[0:line_out.find('/*')]
				str2 = line_out[line_out.find('*/')+2:-1]
				line_out = str1 + str2
			else:
				str1 = line_out[0:line_out.find('/*')]
				line_out = str1
		if line_out.find('*/')!=-1:
			if line_out.find('/*')!=-1:
				str1 = line_out[0:line_out.find('*/')]
				str2 = line_out[line_out.find('/*')+2:-1]
				line_out = str1 + str2
			else:
				str1 = line_out[line_out.find('*/')+2:-1]
				line_out = str1
		line_out = line_out.strip()
	return line_out

def remove_comment_codes(lines):
	cnt = 0
	skipping = 0
	valid_lines = []
	for line_org in lines :
		line = line_org.strip()
		if skipping == 0:
			if line.find('#include')!=-1 \
			or line.find('#define')!=-1 \
			or line.find('//')== 0:
				# skip current line
				cnt = cnt
			else:
				# comment out (/* */) -> skip
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
			if line.find('*/')!= -1: # find the end of comment out
					skipping = 0
	return cnt, valid_lines

def remove_undefined_codes(lines):
	########## VARID PREPROCESSOR (only for #if) #################
	valid_preprocessor_code = []
	valid_preprocessor_code.append('SIM_MODE')
	valid_preprocessor_code.append('TYPE_B')
	valid_preprocessor_code.append('_291B_20161101_BTT_OUTPUT_T')
	##############################################################

	cnt = 0
	skipping = 0
	valid_lines = []
	invalid_else = 0
	skip_dummy = 0
	for line_org in lines :
		line = line_org.strip()
		if skipping == 0:
			# preprocessor (#ifdef - #else) -> skip
			if line.find('#ifdef')!=-1:	#start preprocessor (invalid)
				# skip till the end of preprocessor
				skipping = 1
				level = 1
			# preprocessor (#ifndef - #else) -> save
			elif line.find('#ifndef')!=-1: #start preprocessor (valid)
				# skip current line
				skip_dummy = cnt
			elif line.find('#else')!= -1: #else of #ifndef or #if(valid)?
				if invalid_else == 1: #else of #if(valid)
					# skip till the end of preprocessor
					skipping = 1
					level = 1
				else: #else of #else of #if(invalid)
					# skip current line
					skip_dummy = cnt
			elif line.find('#endif')!= -1: #finish preprocessor for ifndef
				# skip current line
				skip_dummy = cnt
			elif line.find('#if ')!=-1 or line.find('#if(')!=-1: #start preprocessor (select)
				if line.find('#if 0')!=-1:
					# skip till the end of preprocessor
					skipping = 1
					level = 1
				else:
					# check valid preprocessor
					for index in range(0, len(valid_preprocessor_code)):
						if line.find(valid_preprocessor_code[index])!=-1: #start preprocessor (valid)
							# skip current line only
							skipping = 0
							level = 0
							invalid_else = 1 #'else' should be skipped
							break
						else:
							# skip till the end of preprocessor
							skipping = 1
							level = 1
							invalid_else = 0
			elif line.find('#elif')!=-1: #start preprocessor (select)
				# check valid preprocessor
				for index in range(0, len(valid_preprocessor_code)):
					if line.find(valid_preprocessor_code[index])!=-1: #start preprocessor (valid)
						# skip current line only
						skipping = 0
						level = 0
						invalid_else = 1 #'else' should be skipped
						break
					else:
						# skip till the end of preprocessor
						skipping = 1
						level = 1
						invalid_else = 0
			else:
				# save line
				valid_lines.append(line_org)
				cnt += 1
		else: #while skipping
			if line.find('#ifdef')!=-1 or line.find('#ifndef')!=-1:	#start sub-preprocessor
				level += 1
			if line.find('#endif')!=-1: #finish preprocessor at the same line
				level -= 1
				if level==0:
					skipping = 0
			if line.find('#else')!=-1: #else of #ifdef or #if(valid)?
				level -= 1
				if level==0:
					if invalid_else==1: #'else' should be skipped (else of #if(valid))
						#keep skipping
						skip_dummy = cnt
					else: #'else' should be saved (else of #if(invalid))
						skipping = 0
			if line.find('#elif')!=-1:	#elif of #if preprocessor
				# check valid preprocessor
				for index in range(0, len(valid_preprocessor_code)):
					if line.find(valid_preprocessor_code[index])!=-1: #start preprocessor after #if(invalid)
						# skip current line only
						skipping = 0
						level = 0
						invalid_else = 1 #'else' should be skipped
						break
					else: #'elif' should be skipped
						# skip till the end of preprocessor
						skipping = 1
						level = 1
						invalid_else = 0 #'else' should be saved

	return cnt, valid_lines


def find_functions(valid_lines):
	cnt = 0
	func_list = FunctionList()
	searching = 0
	line_num = -1
	func_def_lines = []
	func_content_lines = []
	level = 0
	for line_org in valid_lines:
		line_num += 1

		#remove space and comment
		line = remove_comment_line(line_org)

		#find "{"
		if searching == 0:
			func_def_lines.append(line_org)
			if line.find('{')!=-1:

				if line.find('=')!=-1 \
				and line.find('=')<line.find('{'): #start array definition
					searching = 1	#array
					level = 1
					if line.find('}')!=-1: #finish array definition at the same line
						searching = 0
						level = 0


				else: #start function code
					searching = 2	#function
					level = 1
					##print "start@ %d" % (line_num+1)
					function_data = FunctionData()
					func_def_lines.pop()
					func_content_lines.append(line_org)
					if line.find('}')!=-1: #finish function code at the same line
						searching = 0
						level = 0
						##print "end@ %d" % (line_num+1)


						set_function_data(function_data, func_def_lines, func_content_lines)


						func_list.function_data.append(function_data)
						func_list.func_num += 1	
			elif line.find(');')!=-1: #ignore function predefinition
				del func_def_lines[:]

		#find "}"
		else:
			func_content_lines.append(line_org)
			if line.find('{')!=-1:
				level += 1
			if line.find('}')!=-1:
				level -= 1
				if level == 0:
					if searching == 2:	#finish function code
						##print "end@ %d" % (line_num+1)

						set_function_data(function_data, func_def_lines, func_content_lines)

						func_list.function_data.append(function_data)
						func_list.func_num += 1

					searching = 0
					del func_content_lines[:]
					del func_def_lines[:]

	return func_list

def analyze_function(FunctionData):
	level = 0
	valid_lines = []
	line = ''
	str1 = ''
	str2 = ''
	proc_codes = []
	sub_proc_codes = []
	proc_list = ProcessList()

	print '-------------------------------------'
	print FunctionData.name, 
	print len(FunctionData.codes)

	for index1 in range(0, len(FunctionData.codes)):
		valid_lines.append( remove_comment_line(FunctionData.codes[index1]) )
		line = valid_lines[index1]
		if line.find('{')!=-1 or line.find('}')!=-1:
			while line.find('{')!=-1 or line.find('}')!=-1:

########## find start Curly bracket ({)
				if line.find('{')!=-1: 
					level += 1

##### main function
					if level == 1:
						if len(line)==1:
# { only [MAIN]
							if line.find('{')==0:
								str1 =''
								str2 = line.replace('{', '')
						else:
# { - end [MAIN]
							str1 = line[line.find('{')+1:-1]
							str1 = str1.strip()
							str2 = ''
# begin - { [MAIN]
							if str1.find('{')!=-1:
								str1 = str1[0:line.find('{')]
								str1 = str1.strip()
								# erase copied part
								str2 = str1[line.find('{')+1:-1]
							if str1 != '':
								proc_codes.append(str1)
						line = str2
##### sub function
					elif level > 1:
						str1 = 'SUBFPROCESS(%s)' % level
						proc_codes.append(str1)

						if len(line)==1:
							if line.find('{')==0:
# { only [SUB]
								if level > 2:
									sub_proc_codes.append('{') # save { of sub-sub-function
								#erase {
								str2 = line.replace('{', '')

						else: 
							str1 = line[0:line.find('{')]
							str1 = str1.strip()
							if str1 != '':
								if level > 2:
# begin - { [SUBSUB]
									sub_proc_codes.append(str1)
									sub_proc_codes.append('{') # save { of sub-sub-function
# begin - { [SUB]
								else:
									proc_codes.append(str1)
							# erase copied part
#							str2  = line[line.find('{'):-1]
							str2  = line[line.find('{')+1:-1]
						line = str2


########## find end Curly bracket (})
				if line.find('}')!=-1: #finish Curly bracket at the same line
					level -= 1
##### sub function
					if level > 0:
						if len(line)==1:
# } only [SUB]
							if line.find('}')==0:
								str1 = line.replace('}', '')
							if level > 1:
								sub_proc_codes.append('}') # save } of sub-sub-function
						else:
							str1 = line[line.find('}')+1:-1]
							str1 = str1.strip()
							str2 = ''
							if str1 != '':
								if level > 1:
# } - end [SUBSUB]
									sub_proc_codes.append('}') # save } of sub-sub-function
									sub_proc_codes.append(str1)
# } - end [SUB]
								else:
									sub_proc_codes.append(str1)

##### save sub function (end of sub function)
						if level == 1:
							if len(sub_proc_codes)!=0:
								for code in sub_proc_codes:
									proc_list.subprocess.append(copy.deepcopy(sub_proc_codes))
								del sub_proc_codes[:]
								sub_proc_codes = []
#								for code in proc_list.subprocess[-1]:
#									print ' <SUB>   %s' % code

						# erase copied part
						if line.find('}')==0:
							str1 = line.replace('}', '')
						else:
							str1 = line[line.find('}')+1:-1]
						str1 = str1.strip()
						line = str1

##### main function
					elif level == 0:
						if len(line)==1:
# } only [MAIN]
							if line.find('}')==0:
								str1 =''
								str2 = line.replace('}', '')
						else:
# begin - } [MAIN]
							str1 = line[0,line.find('}')]
							str1 = str1.strip()
							str2 = ''
							if str1 != '':
								proc_codes.append(str1)
						line = str1

########## No Curly bracket ({, })
				else:
					if level > 1:
						# begin - end
						str1 = line
						str1 = str1.strip()
						if str1 != '':
							sub_proc_codes.append(str1)
						# erase copied part
						line = ''

########## No Curly bracket ({, })
		else:
			if level > 1:
				str1 = line
				str1 = str1.strip()
				if str1 != '':
					sub_proc_codes.append(str1)
			else:
				str1 = line
				str1 = str1.strip()
				if str1 != '':
					proc_codes.append(str1)




	# save processes
	if len(proc_codes)!=0:
		proc_list.process = copy.deepcopy(proc_codes)
	FunctionData.process_list = proc_list






	print '---------'
	print 'PROC:%d' % len(FunctionData.process_list.process)
	print 'SUB PROC:%d' % len(FunctionData.process_list.subprocess)
	cnt = 0
	sub_cnt = 0
	for code in FunctionData.process_list.process:
		cnt += 1
		if code.find('SUBFPROCESS')!=-1:
			sub_cnt += 1
			print '(%d) %s %d' % (cnt, code, sub_cnt)
#			print '  (sub %d) Line in SUB PROC:%d' % (sub_cnt, len(FunctionData.process_list.subprocess[sub_cnt-1]))
#			sub_cnt += 1
#			print 'SUB PROC(%d)' % sub_cnt
#			for subproc in FunctionData.process_list.subprocess:
#				sub_proc_cnt = 0
#				for subcode in subproc:
#					sub_proc_cnt += 1
#					print '  SUB(%d) %s' % (sub_proc_cnt, subcode)
		else:
			print '(%d) %s' % (cnt, code)










	return

def analyze_sub_function(lines):
	return

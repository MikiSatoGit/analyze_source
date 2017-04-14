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
import numpy

class ArgumentData:
	def __init__(self):
		self.name = ''
		self.type = ''


class ProcessData:
	def __init__(self):
		self.type = []	#if, for, while, process...
		self.left = []
		self.right = []


class ProcessCodes:
	def __init__(self):
		self.main = []
		self.sub = []


class ProcessCodeList:
	def __init__(self):
		self.main_proc = []
		self.sub_proc = []

	def clear(self):
		del self.main_proc[:]
		del self.sub_proc[:]

class FunctionData:
	def __init__(self):
		self.name = ''
		self.return_type = ''
		self.argument_list = []
		self.argument_num = 0
		self.func_def = []
		self.codes = []
		self.line_num = 0
		self.process_code_list = ProcessCodeList()

	def clear(self):
		self.name = ''
		self.return_type = ''
		del self.argument_list[:]
		self.argument_num = 0
		del self.func_def[:]
		del self.codes[:]
		self.line_num = 0
		self.process_code_list.clear()

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
debug_out = False
########## VARID PREPROCESSOR (only for #if) #################
valid_preprocessor_code = []
valid_preprocessor_code.append('SIM_MODE')
valid_preprocessor_code.append('TYPE_B')
valid_preprocessor_code.append('_291B_20161101_BTT_OUTPUT_T')
##############################################################




############################################################################################
def set_func_def_lines(FunctionData, lines):
	for index in range(0,len(lines)):
		FunctionData.func_def.append(lines[index])
	return 


def set_code_lines(FunctionData, lines):
	code_list = []
	code_tmp = ''
	code_divided = ''
	code_tmp2 = ''
	code_divided2 = ''

	for index in range(0,len(lines)):
		code_tmp = ''
		code_divided = ''
		code_tmp = lines[index].strip()
		# find { ========================================
		if code_tmp.find('{')!=-1:
			code_divided= code_tmp.split('{')
			if len(code_divided)!=0:
				# TOP ({)
				if code_tmp.find('{') == 0:
					code_list.append('{')

				# MIDDLE ({)
				code_tmp2 = ''
				code_divided2 = ''
				for index2 in range(0, len(code_divided)-1):
					if code_divided[index2].strip() != '':
						
						# find } ========================================
						if code_divided[index2].find('}')!=-1:
							code_tmp2 = code_divided[index2].strip()
							code_divided2= code_tmp2.split('}')
							if len(code_divided2)!=0:
								# TOP (})
								if code_tmp2.find('}') == 0:
									code_list.append('}')
								else:
									# MIDDLE (})
									for index3 in range(0, len(code_divided2)-1):
										if code_divided2[index3].strip() != '':
											code_list.append(code_divided2[index3])
										code_list.append('}')
									# END (})
									if code_divided2[-1].strip() != '':
										code_list.append(code_divided2[-1].strip())
							else:
								code_list.append('}')
							code_list.append('{')
						# Not find } ========================================
						else:
							code_list.append(code_divided[index2])
							code_list.append('{')

				# END ({)
				if code_divided[-1].strip() != '':
					# find } ========================================
					if code_divided[-1].find('}')!=-1:
						code_tmp2 = code_divided[-1].strip()
						code_divided2= code_tmp2.split('}')
						if len(code_divided2)!=0:
							# TOP (})
							if code_tmp2.find('}') == 0:
								code_list.append('}')
							else:
								# MIDDLE (})
								for index3 in range(0, len(code_divided2)-1):
									if code_divided2[index3].strip() != '':
										code_list.append(code_divided2[index3])
									code_list.append('}')
								# END (})
								if code_divided2[-1].strip() != '':
									code_list.append(code_divided2[-1].strip())
						else:
							code_list.append('}')
					# Not find } ========================================
					else:
						code_list.append(code_divided[-1].strip())
			else:
				code_list.append('{')
		# Not find { ========================================
		else:
			# find } ========================================
			code_tmp2 = ''
			code_divided2 = ''
			if code_tmp.find('}')!=-1:
				code_tmp2 = code_tmp.strip()
				code_divided2= code_tmp2.split('}')
				if len(code_divided2)!=0:
					# TOP (})
					if code_tmp2.find('}') == 0:
						code_list.append('}')
					else:
						# MIDDLE (})
						for index3 in range(0, len(code_divided2)-1):
							if code_divided2[index3].strip() != '':
								code_list.append(code_divided2[index3])
							code_list.append('}')
						# END (})
						if code_divided2[-1].strip() != '':
							code_list.append(code_divided2[-1].strip())
				else:
					code_list.append('}')
			# Not find } ========================================
			else:
				code_list.append(code_tmp)

	FunctionData.codes = copy.deepcopy(code_list)
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
#	valid_preprocessor_code = []
#	valid_preprocessor_code.append('SIM_MODE')
#	valid_preprocessor_code.append('TYPE_B')
#	valid_preprocessor_code.append('_291B_20161101_BTT_OUTPUT_T')
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


def analyze_code(function_codes, title):
	level = 0
	valid_lines = []
	line = ''
	code_save = ''
	code_remain = ''
	proc_codes = []
	sub_proc_codes = []
	proc_list = ProcessCodeList()
	sub_proc_list = ProcessCodes()
	sub_proc_flg = False
	sub_proc_flg_prev = False
	line_cnt = 0
	sub_proc_id = 0
	current_title = title
########## find start Curly bracket ({) ########## 
##### main process (level 1) [proc_codes]
# (1) { only	: remove {
# (2) begin - {	: save [0:find({)-1] (should be N/A)
# (3) { - }		: save [find({)+1:find(})-1]
# (4) { - {		: save [find(1st{)+1:find(2nd{)-1] / remove 1st{ (beginning of sub process)
# (5) { - end	: save [find({)+1:-1] / remove {

##### sub process (level 2+) [sub_proc_codes]
# (1) { only	: save {
# (2) begin - {	: save [0:find({)-1] and { 
# (3) { - }		: save { and  [find({)+1:find(})-1] and }
# (4) { - {		: save 1st{ and [find(1st{)+1:find(2nd{)-1] and 2nd{
# (5) { - end	: save { and [find({)+1:-1]

########## find end Curly bracket (}) ########## 
##### main process (level 0) [proc_codes]
# (1) } only	: remove }
# (2) begin - }	: save [0:find(})-1] / remove }
# (3) } - {		: save [find({)+1:find(})-1] (should be N/A)
# (4) } - }		: save [find(1st})+1:find(2nd})-1] / remove 1st{ (end of sub process)
# (5) } - end	: save [find(})+1:-1] / remove } (should be N/A)

##### sub process (level 1+) [proc_codes]
# (1) } only	: save }
# (2) begin - }	: save [0:find(})-1] and }
# (3) } - {		: save } and [find({)+1:find(})-1] and {
# (4) } - }		: save 1st} and [find(1st})+1:find(2nd})-1] and 2nd}
# (5) } - end	: save } and [find(})+1:-1]

	for index1 in range(0, len(function_codes)):
		line_cnt += 1
		valid_lines.append( remove_comment_line(function_codes[index1]) )
		line = valid_lines[index1]
		line = line.strip()
		del proc_codes[:]
		del sub_proc_codes[:]


		if sub_proc_flg==True:
			sub_proc_flg_prev = True
		else:
			sub_proc_flg_prev = False


		if line.find('{')!=-1 or line.find('}')!=-1:
			while line.find('{')!=-1 or line.find('}')!=-1:
				code_save = ''
				code_remain = ''
########## find start Curly bracket ({) ########## 
				if line.find('{')!=-1: 
					level += 1
					if level==2:
						sub_proc_flg = True

##### main process (level 1) [proc_codes]
					if level<2:
# (1) { only	: remove {
						if len(line)==1:
							if line.find('{')==0:
								code_save =''
								code_remain = line.replace('{', '',1)
								code_remain.strip()
								line = code_remain
						else:
# (2) begin - {	: save [0:find({)-1] (should be N/A)
							if line.find('{')>0:
								code_save = line[0:line.find('{')-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{'):-1]
								code_remain.strip()
								line = code_remain

# (3) { - }		: save [find({)+1:find(})-1] => main } (2)
# (4) { - {		: save [find(1st{)+1:find(2nd{)-1] and 2nd{ / remove 1st{ (beginning of sub process)
							if line.find('{') < line.rfind('{'):
								code_save = line.replace('{','',1)
								code_save.strip()
								code_save = code_save[0:code_save.find('{')]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = code_save[code_save.find('{'):-1]
								code_remain.strip()
								line = code_remain
# (5) { - end	: save [find({)+1:-1] / remove {
							if line.find('{') < len(line)-1:
								code_save = line[line.find('{')+1:-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

##### sub process (level 2+) [sub_proc_codes]
					else:
# (1) { only	: save {
						if len(line)==1:
							if line.find('{')==0:
								code_save ='{'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line.replace('{', '',1)
								code_remain.strip()
								line = code_remain
						else:
# (2) begin - {	: save [0:find({)-1] and { 
							if line.find('{')>0:
								code_save = line[0:line.find('{')-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{')+1:-1]
								code_remain.strip()
								line = code_remain
# (3) { - }		: save { and  [find({)+1:find(})-1] and } => next sub } (2)
# (4) { - {		: save 1st{ and [find(1st{)+1:find(2nd{)-1] and 2nd{
							if line.find('{') < line.rfind('{'):
								code_save ='{'
								sub_proc_codes.append(copy.deepcopy(code_save))
								code_save = line.replace('{','',1)
								code_save.strip()
								code_save = code_save[0:code_save.find('{')]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = code_save[code_save.find('{'):-1]
								code_remain.strip()
								line = code_remain
# (5) { - end	: save { and [find({)+1:-1]
							if line.find('{')==line.rfind('{') and line.find('{') < len(line)-1:
								code_save ='{'
								sub_proc_codes.append(copy.deepcopy(code_save))
								code_save = line[line.find('{')+1:-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

########## find end Curly bracket (}) ########## 
				if line.find('}')!=-1:
					level -= 1
					if level==1:
						sub_proc_flg = False

##### main process (level 0) [proc_codes]
					if level<1:
# (1) } only	: remove }
						if len(line)==1:
							if line.find('}')==0:
								code_save =''
								code_remain = line.replace('}', '',1)
								code_remain.strip()
								line = code_remain
						else:
# (2) begin - }	: save [0:find(})-1] / remove }
							if line.find('}')>0:
								code_save = line[0:line.find('}')-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('}'):-1]
								code_remain.strip()
								line = code_remain

# (3) } - {		: save [find({)+1:find(})-1] (should be N/A)
							if line.find('}') < line.rfind('{'):
								code_save = line[line.find('}')+1:line.find('{')-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{'):-1]
								code_remain.strip()
								line = code_remain
# (4) } - }		: save [find(1st})+1:find(2nd})-1] / remove 1st{ (end of sub process) => save } (sub) and next main } (2)
							if line.find('}') < line.rfind('}'):
								level += 1
								if level==2:
									sub_proc_flg = True

								code_save ='}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('}')+1:-1]
								code_remain.strip()
								line = code_remain
# (5) } - end	: save [find(})+1:-1] / remove } (should be N/A)
							if line.find('}') < len(line)-1:
								code_save = line[line.find('}')+1:-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

##### sub process (level 1+) [sub_proc_codes]
					else:
# (1) } only	: save }
						if len(line)==1:
							if line.find('}')==0:
								code_save ='}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line.replace('}', '',1)
								code_remain.strip()
								line = code_remain
						else:
# (2) begin - }	: save [0:find(})-1] and }
							if line.find('}')>0:
								code_save = line[0:line.find('}')-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('}')+1:-1]
								code_remain.strip()
								line = code_remain
# (3) } - {		: save } and [find({)+1:find(})-1] 
							if line.find('}') < line.rfind('{'):
								code_save = '}'
								sub_proc_codes.append(copy.deepcopy(code_save))
								code_save = line[line.find('}')+1:line.find('{')-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{'):-1]
								code_remain.strip()
								line = code_remain
# (4) } - }		: save 1st} and [find(1st})+1:find(2nd})-1] and 2nd}
							if line.find('}') < line.rfind('}'):
								level += 1
								if level==2:
									sub_proc_flg = True

								code_save = '}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = code_save[code_save.find('}')+1:-1]
								code_remain.strip()
								line = code_remain
# (5) } - end	: save } and [find(})+1:-1]
							if line.find('}') < len(line)-1:
								code_save = line[line.find('}')+1:-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

########## No Curly bracket ({,}) ########## 
		else:
			line = line.strip()
			if line != '':
##### sub process (level 2+) [sub_proc_codes]
				if level>1:
					sub_proc_codes.append(line)
##### main process (level 1) [proc_codes]
				else:
					proc_codes.append(line)


########## save sub process block ##########
		if len(sub_proc_codes)!=0:
			sub_proc_list.main.append( list(sub_proc_codes) )


		if sub_proc_flg_prev==False and sub_proc_flg==True:
			sub_proc_id += 1
			current_title = 'SUB' + title
			proc_codes.append(current_title + '(%s)' % sub_proc_id)

		if sub_proc_flg_prev==True and sub_proc_flg==False:
			proc_list.sub_proc.append( list(sub_proc_list.main) )

########## save main process block ########## 
		if len(proc_codes)!=0:
			for code in proc_codes:
				proc_list.main_proc.append( code )

	return proc_list, current_title


def analyze_function(FunctionData, title):
	##### For Debug #####
	if debug_out:
		print '-------------------------------------'
		print FunctionData.name, 
		print len(FunctionData.codes)


	proc_list = ProcessCodeList()
	proc_list,current_title = analyze_code(FunctionData.codes, title)
	FunctionData.process_code_list = proc_list

	##### For Debug #####
	if debug_out:
		if len(FunctionData.process_code_list.main_proc)!=0:
			for code in FunctionData.process_code_list.main_proc:
				print '(main) %s' %code
		if len(FunctionData.process_code_list.sub_proc)!=0:
			for code in FunctionData.process_code_list.sub_proc:
				print '--------'
				for subcode in code:
					print '(sub) %s' % subcode[0]

	return current_title

def analyze_sub_process(proc_list, title):
	sub_proc_flag = False
	sub_proc_list_pre = []
	sub_proc_list = ProcessCodeList()
	current_title = title

	for code in proc_list.main_proc:
		tmp = title.replace('PROCESS','',1)
		tmp = tmp.replace('SUB','',1)
		if tmp.find('SUB')==-1:
			print "[PROCESS] %s"  % (code.strip())


		if code.find('SUBPROCESS')!=-1:
			sub_proc_flag = True
			sub_proc_id = int(code[code.find('(')+1 : code.find(')')])-1
			print '--------'
			del sub_proc_list_pre[:]
			sub_proc_list.clear()
			for subcode in proc_list.sub_proc[sub_proc_id]:
				sub_proc_list_pre.append(subcode[0])
			sub_proc_list,current_title = analyze_code(sub_proc_list_pre, title)

			##### For Debug #####
#			if debug_out:
			if len(sub_proc_list.main_proc)!=0:
				for code in sub_proc_list.main_proc:
					print '[%sPROCESS(%d)] %s' % (title.replace('PROCESS','',1), sub_proc_id+1, code)
			print '--------'
	return sub_proc_list, sub_proc_flag,current_title

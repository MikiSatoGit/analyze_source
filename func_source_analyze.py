#
#	func_source_analyze.py
#	Data and funtion class for analyzing C source code
#	Create on: 2017.04.10
#	Author   : Miki Sato <miki.sam.sato@gmail.com>
#
#   NOTE:
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
		self.title =[]
		self.type = []	#subproc,equal,proc,func,ctrl(if,else if, else, for, while, switch) ...
		self.left = []
		self.right = []

	def clear(self):
		del self.title[:]
		del self.type[:]
		del self.left[:]
		del self.right[:]

	def append_data(self, title, type, left, right):
		self.title.append(title)
		self.type.append(type)
		self.left.append(left)
		self.right.append(right)

	def get_size(self):
		return len(self.left)

	def debug_print(self):
		if len(self.left)==0:
			print 'NULL'
		for index in range(0,len(self.left)):
			print ' -> ',
			print self.title[index],
			print self.type[index],
			print self.left[index],
			print self.right[index]
		return

	def debug_print(self, index):
		if index > len(self.left):
			print '-> (no data)'
		else:
			print ' -> ',
			print self.title[index],
			print self.type[index],
			print self.left[index],
			print self.right[index]
		return

	def file_print_out(self, file, index):
		if index > len(self.left):
			print_out(file, '(no data)', 1)
		else:
			print_out(file, self.title[index], 0)
			print_out(file, self.type[index], 0)
			print_out(file, self.left[index], 0)
			print_out(file, self.right[index], 1)
		return


class ProcessCodes:
	def __init__(self):
		self.main = []
		self.title = []
		self.func_name = ''
		self.proc_data_list = []	# List of ProcessData

	def clear(self):
		del self.main[:]
		del self.title[:]
		self.func_name = ''
		del self.proc_data_list[:]

	def set_func_name(self, func_name):
		self.func_name = func_name

	def append_code(self, code, title):
		self.main.append(code)
		self.title.append(title)

	def append_list(self, ProcessCodes):
		for index in range(0,len(ProcessCodes.main)):
			self.main.append(ProcessCodes.main[index])
			self.title.append(ProcessCodes.title[index])

	def get_size(self):
		return len(self.main)

	def get_proc_data_size(self):
		return len(self.proc_data_list)

	def debug_print_proc_data_list(self):
		for index in range(0, len(self.proc_data_list)):
			for index2 in range(0,self.proc_data_list[index].get_size()):
				self.proc_data_list[index].debug_print(index2)

	def file_print_proc_data_list(self, file):
		cnt = 0;
		for index in range(0, self.get_proc_data_size()):
			for index2 in range(0,self.proc_data_list[index].get_size()):
				cnt += 1;
				print_out(file, '[%d]' % cnt, 0)
				self.proc_data_list[index].file_print_out(file, index2)
		return cnt

class ProcessCodesList:
	def __init__(self):
		self.main_proc = []
		self.sub_proc = []

	def clear(self):
		del self.main_proc[:]
		del self.sub_proc[:]

	def debug_print_main_proc(self):
		cnt = 0
		for proc in self.main_proc:
			cnt += 1
			print 'MAIN in list[%d]: %s' %(cnt, proc)
		return

	def debug_print_sub_proc(self):
		cnt = 0
		for proc in self.sub_proc:
			cnt += 1
			print 'SUB in list[%d]: %s' %(cnt, proc)
		return

class FunctionData:
	def __init__(self):
		self.name = ''
		self.return_type = ''
		self.argument_list = []
		self.argument_num = 0
		self.func_def = []
		self.codes = []
		self.line_num = 0
		self.process_code_list = ProcessCodesList()

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
			str.strip()
			if str!='':
				if str.find('(')!=-1:
					level += 1
					if level==1:
						str = str[str.find('('): ]
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

					str_type.strip()
					str_name.strip()
					if len(str_type)!=0 or len(str_name)!=0:
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

def print_out(file, output_string, breakline):
	if file == "":
		if breakline == 0:
			print output_string,
		else:
			print output_string
	else:
		if breakline == 0:
			file.write(output_string)
			file.write(" ")
		else:
			file.write(output_string)
			file.write('\n')
	return


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
					# TOP (isinstance})
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
				str2 = line_out[line_out.find('*/')+2: ]
				line_out = str1 + str2
			else:
				str1 = line_out[0:line_out.find('/*')]
				line_out = str1
		if line_out.find('*/')!=-1:
			if line_out.find('/*')!=-1:
				str1 = line_out[0:line_out.find('*/')]
				str2 = line_out[line_out.find('/*')+2: ]
				line_out = str1 + str2
			else:
				str1 = line_out[line_out.find('*/')+2: ]
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


def load_valid_source_code(source_file):
	cnt = 0
	skipping = 0
	valid_lines = []
	lines = source_file.readlines()

	cnt, valid_lines = remove_undefined_codes(lines)
	cnt, valid_lines = remove_comment_codes(valid_lines)

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













def analyze_function_list(FunctionData, title):
#0419
	print '==analyze_function_list'

	proc_list = ProcessCodesList()
	proc_list,current_title = analyze_function_codes(FunctionData.codes, title)
	FunctionData.process_code_list = proc_list

	##### For Debug #####
	if debug_out:
		print '-------------------------------------'
		print FunctionData.name, 
		print len(FunctionData.codes)
		if len(FunctionData.process_code_list.main_proc)!=0:
			for code in FunctionData.process_code_list.main_proc:
				print '(main) %s' %code
		if len(FunctionData.process_code_list.sub_proc)!=0:
			for code in FunctionData.process_code_list.sub_proc:
				print '--------'
				for subcode in code:
					print '(sub) %s' % subcode[0]

#0419
	print '== END of analyze_function_list'

	return current_title
























def analyze_function_codes(function_codes, title):	# function_codes = List
#0419
	print ' ===analyze_function_codes[/%d]' % len(function_codes)
	for code in function_codes:
		print 'code in function_codes %s' % code
	function_codes = divide_end_of_function_in_code(function_codes)
	print ' ===after divide_end_of_function_in_code[/%d]' % len(function_codes)
	for code in function_codes:
		print 'devided code in function_codes %s' % code



	parent_level = 0
	level = 0
	valid_lines = []
	line = ''
	code_save = ''
	code_remain = ''
	proc_codes = []
	sub_proc_codes = []
	proc_list = ProcessCodesList()
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
# (5) { - end	: save [find({)+1: ] / remove {

##### sub process (level 2+) [sub_proc_codes]
# (1) { only	: save {
# (2) begin - {	: save [0:find({)-1] and { 
# (3) { - }		: save { and  [find({)+1:find(})-1] and }
# (4) { - {		: save 1st{ and [find(1st{)+1:find(2nd{)-1] and 2nd{
# (5) { - end	: save { and [find({)+1: ]

########## find end Curly bracket (}) ########## 
##### main process (level 0) [proc_codes]
# (1) } only	: remove }
# (2) begin - }	: save [0:find(})-1] / remove }
# (3) } - {		: save [find({)+1:find(})-1] (should be N/A)
# (4) } - }		: save [find(1st})+1:find(2nd})-1] / remove 1st{ (end of sub process)
# (5) } - end	: save [find(})+1: ] / remove } (should be N/A)

##### sub process (level 1+) [proc_codes]
# (1) } only	: save }
# (2) begin - }	: save [0:find(})-1] and }
# (3) } - {		: save } and [find({)+1:find(})-1] and {
# (4) } - }		: save 1st} and [find(1st})+1:find(2nd})-1] and 2nd}
# (5) } - end	: save } and [find(})+1: ]

	for index1 in range(0, len(function_codes)):
		line_cnt += 1
		valid_lines.append( remove_comment_line(function_codes[index1]) )
		line = valid_lines[index1]
		line = line.strip()

#0419
		print '=============================================================='
		print '   cheking %s' % line


		del proc_codes[:]
		del sub_proc_codes[:]

		sub_proc_flg_prev = sub_proc_flg #0419


		if line.find('{')!=-1 or line.find('}')!=-1:
			while line.find('{')!=-1 or line.find('}')!=-1:
				line.strip()

				code_save = ''
				code_remain = ''
########## find start Curly bracket ({) ########## 
				if line.find('{')!=-1: 
#0419
					print '   searching {'
					level += 1
					if level > parent_level + 1: #0419
						sub_proc_flg = True

##### main process (level 1) [proc_codes]
					if level < parent_level + 2:
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

								code_remain = line[line.find('{'): ]
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

								code_remain = code_save[code_save.find('{'): ]
								code_remain.strip()
								line = code_remain
# (5) { - end	: save [find({)+1: ] / remove {
							if line.find('{') < len(line)-1:
								code_save = line[line.find('{')+1: ]
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

								code_remain = line[line.find('{')+1: ]
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

								code_remain = code_save[code_save.find('{'): ]
								code_remain.strip()
								line = code_remain
# (5) { - end	: save { and [find({)+1: ]
							if line.find('{')==line.rfind('{') and line.find('{') < len(line)-1:
								code_save ='{'
								sub_proc_codes.append(copy.deepcopy(code_save))
								code_save = line[line.find('{')+1: ]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

########## find end Curly bracket (}) ########## 
				if line.find('}')!=-1:
#0419
					print '   searching }'

					level -= 1
#0419					if level==1:
					if level < parent_level + 2:	#0419????
						sub_proc_flg = False


##### main process (level 0) [proc_codes]
					if level < parent_level +1:
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

								code_remain = line[line.find('}'): ]
								code_remain.strip()
								line = code_remain

# (3) } - {		: save [find({)+1:find(})-1] (should be N/A)
							if line.find('}') < line.rfind('{'):
								code_save = line[line.find('}')+1:line.find('{')-1]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{'): ]
								code_remain.strip()
								line = code_remain
# (4) } - }		: save [find(1st})+1:find(2nd})-1] / remove 1st{ (end of sub process) => save } (sub) and next main } (2)
							if line.find('}') < line.rfind('}'):
								level += 1
								if level > parent_level +1: #0419
									sub_proc_flg = True

								code_save ='}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('}')+1: ]
								code_remain.strip()
								line = code_remain
# (5) } - end	: save [find(})+1: ] / remove } (should be N/A)
							if line.find('}') < len(line)-1:
								code_save = line[line.find('}')+1: ]
								code_save.strip()
								proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

##### sub process (level 1+) [sub_proc_codes]
					else:
# (1) } only	: save }
						if len(line)==1:

#0419
							print '   find } (1)'


							if line.find('}')==0:
								code_save ='}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line.replace('}', '',1)
								code_remain.strip()
								line = code_remain














						else:

#0419
							print '   find } (2)'



# (2) begin - }	: save [0:find(})-1] and }
							if line.find('}')>0:
								code_save = line[0:line.find('}')-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('}')+1: ]
								code_remain.strip()
								line = code_remain
# (3) } - {		: save } and [find({)+1:find(})-1] 
							if line.find('}') < line.rfind('{'):
								code_save = '}'
								sub_proc_codes.append(copy.deepcopy(code_save))
								code_save = line[line.find('}')+1:line.find('{')-1]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = line[line.find('{'): ]
								code_remain.strip()
								line = code_remain
# (4) } - }		: save 1st} and [find(1st})+1:find(2nd})-1] and 2nd}
							if line.find('}') < line.rfind('}'):
								level += 1
								if level > parent_level + 1: #0419
									sub_proc_flg = True


								code_save = '}'
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = code_save[code_save.find('}')+1: ]
								code_remain.strip()
								line = code_remain
# (5) } - end	: save } and [find(})+1: ]
							if line.find('}') < len(line)-1:
								code_save = line[line.find('}')+1: ]
								code_save.strip()
								sub_proc_codes.append(copy.deepcopy(code_save))

								code_remain = ''
								line = code_remain

########## No Curly bracket ({,}) ########## 
		else:
			line = line.strip()

#0419
			print '   --> NO {} in %s' % line


			if line != '':
##### sub process (level 2+) [sub_proc_codes]
				if level > parent_level + 1: #0419
					sub_proc_codes.append(line)

#0419
					print '   ----> added to SUB %s' % line

##### main process (level 1) [proc_codes]
				else:
					proc_codes.append(line)

#0419
					print '   ----> added to MAIN %s' % line



########## save sub process block ##########
#0419
		print '------------------------'
		if len(sub_proc_codes)!=0:
			for tmp_code in sub_proc_codes:
				sub_proc_list.main.append( tmp_code )
#0419
				print '           ----> ADDED to SUBPROC %s' % (tmp_code)
		del sub_proc_codes[:]
















		# 
		if sub_proc_flg_prev==False and sub_proc_flg==True:
			sub_proc_id += 1
			current_title = 'SUB' + title
			proc_codes.append(current_title + '(%s)' % sub_proc_id)

#0419
			print '           ----> ADDED to PROC %s(%s)' % (current_title, sub_proc_id)
			print '           ----> START of SUBPROC'






		if sub_proc_flg_prev==True and sub_proc_flg==False:
#0419
			print '           ----> END of SUBPROC'


			proc_list.sub_proc.append( list(sub_proc_list.main) )
			sub_proc_list.clear()































########## save main process block ########## 
		if len(proc_codes)!=0:
			for code in proc_codes:
#0419
				print '  ---->main %s' % code
				proc_list.main_proc.append( code )
#0419
	print ' ===END of analyze_function_codes'


	return proc_list, current_title










def divide_end_of_function_in_code(proc_codes):		# proc_codes = List
#0419
#	print '  ====divide_end_of_function_in_code'


	copy_proc_codes = copy.deepcopy(proc_codes)
	out_proc_codes = []
	for index in xrange(0,len(copy_proc_codes)):

# divide by ';'
		divided_code = copy_proc_codes[index].strip()
		divided_code = divided_code.split(';')

# No ';'
		if len(divided_code)==1:
			tmp_code = copy_proc_codes[index].strip()
			out_proc_codes.append( tmp_code )
		else:
			for index2 in range(0,len(divided_code)):
				if index == len(divided_code):
					break
				if len(divided_code[index2])==0:
					break
				else:
					if is_ctrl_stat(divided_code[index2])==True:
						tmp_code = divided_code[index2]
					else:
						tmp_code = divided_code[index2]+';'
# check );
				if tmp_code.rfind(';')!=-1 \
				 and tmp_code.rfind(')')!=-1 \
				 and tmp_code.rfind(')') < tmp_code.rfind(';'):
					tmp_bracket_to_end = tmp_code[tmp_code.rfind(')')+1:tmp_code.rfind(';')].strip()
					if len(tmp_bracket_to_end)==0:
						tmp_start_to_bracket = tmp_code[:tmp_code.rfind(')')].strip()
						if len(tmp_start_to_bracket)!=0:
							out_proc_codes.append( tmp_start_to_bracket )
							out_proc_codes.append(');')
						else:
							out_proc_codes.append(');')
				else:
					out_proc_codes.append( tmp_code.strip() )

#0419
#		print '   ---->devided code %s' % out_proc_codes[-1]



#0419
#	print '  ====END of divide_end_of_function_in_code'

	return out_proc_codes









































def analyze_sub_process(proc_list, title):
#0419
	print '==analyze_sub_process'

	sub_proc_flag = False
	sub_proc_list_pre = []
	sub_proc_list = ProcessCodesList()
	serial_proc_codes = ProcessCodes()
	current_title = title

	cnt = 0

#0419
	print 'proc_list [/%d]' % (len(proc_list.main_proc))


	for code in proc_list.main_proc:
		cnt += 1
		tmp = title.replace('PROCESS','',1)
		tmp = tmp.replace('SUB','',1)

#0419
		print '%s -> %s' % (code, tmp)


		if tmp.find('SUB')==-1:
			if debug_out:
				print "[PROCESS] %s"  % (code.strip())
			serial_proc_codes.append_code(code,'MAINPROCESS')

		if code.find('SUBPROCESS')!=-1:
			sub_proc_flag = True
			sub_proc_id = int(code[code.find('(')+1 : code.find(')')])-1
#0419			if debug_out:
			print '--------'

			del sub_proc_list_pre[:]
			sub_proc_list.clear()

			for subcode in proc_list.sub_proc[sub_proc_id]:

#0419
				print 'SUB CODE %s' % subcode



				if isinstance(subcode, str) or subcode!='':
					sub_proc_list_pre.append(subcode)
				else:
					for subsubcode in subcode:
						sub_proc_list_pre.append(subsubcode)
	

#0419
				print 'SUB CODE %s' % subcode
				print '>>>>>>>>>>>>>> CALL analyze_function_codes in analyze_sub_process'


			sub_proc_list,current_title = analyze_function_codes(sub_proc_list_pre, title)

#0419
			print ' SUB CODE [%d]->[%d]' % (len(sub_proc_list_pre), len(sub_proc_list.main_proc))


			if len(sub_proc_list.main_proc)!=0:
#0419
				print 'sub_proc_list is not empty'


				for code in sub_proc_list.main_proc:
#0419					if debug_out:
					print '[%sPROCESS(%d)] %s' % (title.replace('PROCESS','',1), sub_proc_id+1, code)
					tmp_str = '%sPROCESS(%d)' % (title.replace('PROCESS','',1), sub_proc_id+1)
					serial_proc_codes.append_code(code,tmp_str)
#0419			if debug_out:
			print '-------- %s' % sub_proc_flag


#0419
	print '==END of analyze_sub_process %s' % sub_proc_flag

	return sub_proc_list, sub_proc_flag, current_title, serial_proc_codes




























def analyze_process_code(proc_codes):
#0419
	print '==analyze_process_code'

########## analyze sub process code ##########
	proc_codes = analyze_sub_process_code(proc_codes)

########## analyze control statement ##########
	ctrl_stat_list = analyze_control_statement(proc_codes)
	ctrl_proc_num = 0
	for ctrl in ctrl_stat_list:
		ctrl_proc_num +=1
#0419		if debug_out:
		print '-->ctrl stat %s / %d' %  (ctrl, ctrl_proc_num)

########## analyze condition of control statement ########## 

########## analyze call function ########## 

#######################
#	if debug_out:
	proc_codes.debug_print_proc_data_list()


#0419
	print '== END of analyze_process_code'

	return proc_codes




























def analyze_sub_process_code(proc_codes):
	proc_data = ProcessData()
	is_for = False
	for index in range(0,proc_codes.get_size()):
		tmp_title = proc_codes.title[index]
		tmp_code = proc_codes.main[index]
		proc_data.clear()
########## skip sub process ##########
		if tmp_code.find('SUBPROCESS')!=-1:
			titel = tmp_code.strip()
			proc_data.append_data(tmp_title, 'subproc', tmp_code.strip(), '')
########## find process ##########
		else:
# find process code (hoge;)
			if is_ctrl_stat(tmp_code)==False:

######################################################################
				while tmp_code.find(';')!=-1:
					if is_for:
						tmp_type = '???'
					else:
						tmp_type = 'proc'
					tmp_proc = tmp_code[0:tmp_code.find(';')+1]
					tmp_proc.strip()
					tmp_left = ''
					tmp_right = ''
# find equal process (hoge = A;)
					if tmp_proc.find('=')!=-1:
						tmp_left = tmp_proc[0:tmp_proc.find('=')]
						tmp_right = tmp_proc[tmp_proc.find('=')+1: ]
						proc_data.append_data(tmp_title, 'equal', tmp_left.strip(), tmp_right.strip())
					else:
						tmp_left = tmp_proc
						tmp_right = ''
# find func call (hoge();)
						if tmp_left.rfind(')')!=-1:
							tmp_bracket_to_end = tmp_left[tmp_left.rfind(')')+1:tmp_left.find(';')].strip()
							if len(tmp_bracket_to_end)==0:
								if is_for:
									tmp_left = tmp_left[:tmp_left.find(';')]
									proc_data.append_data(tmp_title,'???', tmp_left.strip(), tmp_right.strip())	#for<end>
								else:
									proc_data.append_data(tmp_title,'func<end>', tmp_left.strip(), tmp_right.strip())

# check bracket level
								# count ')' level
								bracket_level = 0
								tmp_find_end = tmp_left
								tmp_find_end.strip()
								while tmp_find_end.rfind(')')!=-1:
									bracket_level += 1
									tmp_find_end = tmp_find_end[0:tmp_find_end.rfind(')')]
									tmp_find_end.strip()
								# count '(' level
								tmp_find_start = tmp_left
								tmp_find_start.strip()
								while tmp_find_start.rfind('(')!=-1:
									bracket_level -= 1
									tmp_find_start = tmp_find_start[0:tmp_find_start.rfind('(')]
									tmp_find_start.strip()


#find start '('
								bracket_search_flag = True
								for index1_r in xrange(proc_codes.get_proc_data_size()-1,-1,-1):
									if index1_r==-1 or bracket_search_flag==False:
										break
									for index2_r in xrange(proc_codes.proc_data_list[index1_r].get_size()-1,-1,-1):
										if index2_r==-1:
											bracket_search_flag=False
											break
										tmp_title_r = proc_codes.proc_data_list[index1_r].title[index2_r]
										tmp_type_r = proc_codes.proc_data_list[index1_r].type[index2_r]
										tmp_left_r = proc_codes.proc_data_list[index1_r].left[index2_r]
										tmp_right_r = proc_codes.proc_data_list[index1_r].right[index2_r]

# reached to previous subproc
										if tmp_type_r=='subproc':
											bracket_search_flag=False
											break

# check bracket level
										# count ')' level
										tmp_find_end = tmp_left_r
										tmp_find_end.strip()
										while tmp_find_end.rfind(')')!=-1:
											bracket_level += 1
											tmp_find_end = tmp_find_end[0:tmp_find_end.rfind(')')]
											tmp_find_end.strip()
										# count '(' level
										tmp_find_start = tmp_left_r
										tmp_find_start.strip()
										while tmp_find_start.rfind('(')!=-1:
											bracket_level -= 1
											tmp_find_start = tmp_find_start[0:tmp_find_start.rfind('(')]
											tmp_find_start.strip()

										if tmp_type_r.find('???')!=-1:
											if is_for:
												proc_codes.proc_data_list[index1_r].type[index2_r] = '???'
											else:
												proc_codes.proc_data_list[index1_r].type[index2_r] = 'func'
											if bracket_level==0:
												if is_for:
													is_for = False
												else:
													proc_codes.proc_data_list[index1_r].type[index2_r] += '<start>'
												bracket_search_flag=False
												break
										else:
											bracket_search_flag=False
											break

# find process(ctrl statement) (return, break, continue...;)
						else:
							if is_for:
								proc_data.append_data(tmp_title,'???', tmp_left.strip(), tmp_right.strip())
							else:
								proc_data.append_data(tmp_title,'proc', tmp_left.strip(), tmp_right.strip())
					tmptmp_code = copy.deepcopy(tmp_code)
					tmp_code = tmptmp_code[tmptmp_code.find(';',1)+1: ]
######################################################################
			else:
				if is_for==False and is_ctrl_stat_word('for', tmp_code):
					is_for = is_ctrl_stat_word('for', tmp_code)
######################################################################


# could not find end of process(;) -> 
			if len(tmp_code)!=0:
				tmp_left = tmp_code
				tmp_right = ''
				proc_data.append_data(tmp_title, '???', tmp_left.strip(), tmp_right.strip())
########## save data ########## 
		proc_codes.proc_data_list.append( copy.deepcopy(proc_data) )

	return proc_codes







def is_ctrl_stat(code):
	if is_ctrl_stat_word('else if', code):
		return True
	if is_ctrl_stat_word('if', code):
		return True
	if is_ctrl_stat_word('else', code):	# Need to fix 'else (' -> should be error
		return True
	if is_ctrl_stat_word('for', code):
		return True
	if is_ctrl_stat_word('while', code):
		return True
	if is_ctrl_stat_word('switch', code):
		return True

	return False


def is_ctrl_stat_word(word, code):
	tmp_code = code.strip()
	if tmp_code.find(word)!=-1:
		# 'for...' or '...[space]for...''
		if (tmp_code.find(word)==0) or (tmp_code.find(word)>0 and tmp_code[tmp_code.find(word)-1]==' '):
			# 'for'
			if len(code)==len(word):
				return True
			else:
				# 'for[space]('
				if tmp_code.find('(')!=0 and tmp_code.find(word)<tmp_code.find('('):
					tmp_word_to_bracket = tmp_code[tmp_code.find(word)+len(word):tmp_code.find('(')]
					if len(tmp_word_to_bracket.strip())==0:
						return True
	return False


























def analyze_control_statement(proc_codes):
########## find condition ########## 
#	if()					condition
#	else if()	 			condition
#	else 					condition
#	for() 					loop
#	while()					loop
#	do...while()			loop(N/A)
#	switch(case, default) 	select
#	return 					exit function
#	break 					exit loop
#	continue				skip remaining process in loop
#	goto 					jump


#0419
	print ' ===analyze_control_statement'



	condition_start_index1 = -1
	condition_start_index2 = -1
	condition_end_index1 = -1
	condition_end_index2 = -1
	previous_process_index1 = 0
	previous_process_index2 = 0
	ctrl_proc_num = 0
	ctrl_stat_list = []
	sub_proc_flag = False

	for index in range(0, proc_codes.get_proc_data_size()):
		sub_proc_flag = False
		for index2 in range(0,proc_codes.proc_data_list[index].get_size()):
			if proc_codes.proc_data_list[index].type[index2].find('subproc')!=-1:
				sub_proc_flag = True
				ctrl_proc_num += 1

# check previous data
				condition_start_index1 = -1
				condition_start_index2 = -1
				condition_end_index1 = -1
				condition_end_index2 = -1
				previous_process_index1 = 0
				previous_process_index2 = 0

				if debug_out:
					print 'START->[%d][%d]%s' % (index, index2, proc_codes.proc_data_list[index].left[index2])

				org_index1 = index
				org_index2 = index2
				subproc_search = True




# search by reverse loop
				for index1_r in xrange(index,-1,-1):
					if index1_r==-1 or subproc_search==False:
						break

					for index2_r in xrange(index2,-1,-1):
						if index2_r==-1:
							continue



# reverse loop until previous main process(not ???)

#0419
#						print ' --> start cheking in [%d][%d]%s' % (index1_r, index2_r, proc_codes.proc_data_list[index1_r].left[index2_r])
#						print 'length %d' % len(proc_codes.proc_data_list[index1_r].left[index2_r])

						if proc_codes.proc_data_list[index1_r].type[index2_r].find('???')==-1:
							if index1_r!=org_index1 or index2_r!= org_index2:
								if debug_out:
									print '[%d][%d] No more ()' % (index1_r, index2_r)
								previous_process_index1 = index1_r
								previous_process_index2 = index2_r
								subproc_search = False
								break;
						else:
# find ')' of condition
							if proc_codes.proc_data_list[index1_r].left[index2_r].rfind(')')!=-1 \
							 and condition_end_index1==-1:
								if debug_out:
									print '[%d][%d] Find ) @[%d]' % (index1_r, index2_r, proc_codes.proc_data_list[index1_r].left[index2_r].rfind(')'))

								condition_end_index1 = index1_r
								condition_end_index2 = index2_r
# find '(' of condition
							if proc_codes.proc_data_list[index1_r].left[index2_r].find('(')!=-1:
								if debug_out:
									print '[%d][%d] Find ( @[%d]' % (index1_r, index2_r, proc_codes.proc_data_list[index1_r].left[index2_r].rfind('('))
								condition_start_index1 = index1_r
								condition_start_index2 = index2_r
# divide by ( and )
								tmp_left_split = [ \
									proc_codes.proc_data_list[index1_r].left[index2_r][0:proc_codes.proc_data_list[index1_r].left[index2_r].find('(')+1].strip(), \
									proc_codes.proc_data_list[index1_r].left[index2_r][proc_codes.proc_data_list[index1_r].left[index2_r].find('(')+1:].strip() \
								]
								if tmp_left_split[1].rfind(')')!=-1 \
								 and len(tmp_left_split[1][tmp_left_split[1].rfind(')')+1:].strip())==0:
									tmp_left_split[-1] = tmp_left_split[-1][0:tmp_left_split[-1].rfind(')')].strip()
									tmp_left_split.append(')')

								tmp_left_split_num = 0
								for tmp_div in tmp_left_split:
									tmp_left_split_num += 1

								if len(tmp_left_split[-1])!=0:
									tmp_title_split = []
									tmp_type_split = []
									tmp_right_split = []
									for i in range(0, tmp_left_split_num):
										tmp_title_split.append(proc_codes.proc_data_list[index1_r].title[index2_r])
										tmp_type_split.append(proc_codes.proc_data_list[index1_r].type[index2_r])
										tmp_right_split.append(proc_codes.proc_data_list[index1_r].right[index2_r])

									proc_codes.proc_data_list[index1_r].left[index2_r : index2_r+1] = tmp_left_split
									proc_codes.proc_data_list[index1_r].title[index2_r : index2_r+1] = tmp_title_split
									proc_codes.proc_data_list[index1_r].type[index2_r : index2_r+1] = tmp_type_split
									proc_codes.proc_data_list[index1_r].right[index2_r : index2_r+1] = tmp_right_split

# find 'else'
				# Could not find Ctrl Stat
				if sub_proc_flag==True and condition_start_index1==-1 and condition_end_index2==-1:
					if previous_process_index1 <= org_index1:
						for index1_f in xrange(previous_process_index1,org_index1):
							if previous_process_index2 <= org_index2:
								for index2_f in xrange(previous_process_index2, org_index2+1):
									if proc_codes.proc_data_list[index1_f].left[index2_f].find('else')!=-1:
										condition_start_index1 = -2
										condition_start_index2 = -2
										condition_end_index1 = -2
										condition_end_index2 = -2
									else:
										condition_start_index1 = -3
										condition_start_index2 = -3
										condition_end_index1 = -3
										condition_end_index2 = -3

# find strl statement before '('
				if debug_out:
					print '-> start index [%d][%d]' %  (condition_start_index1,condition_start_index2)
					print '-> end index [%d][%d]' %  (condition_end_index1,condition_end_index2)
					print '-> previous index [%d][%d]' %  (previous_process_index1,previous_process_index2)
				tmp_ctrl = ''
				tmptmp_ctrl = ''
				if condition_start_index1!=-1 and condition_end_index1!=-1:
					if condition_start_index1==-2:		#else
						tmp_ctrl = 'else'
					elif condition_start_index1==-3:	#no ctrl stat
						tmp_ctrl = 'noctrl'
					else:
						for index1_r in xrange(condition_start_index1, previous_process_index1-1,-1):
							if index1_r==-1:
								break
							for index2_r in xrange(condition_start_index2,-1,-1):
								if index2_r==-1:
									break
								if proc_codes.proc_data_list[index1_r].type[index2_r].find('???')!=-1:
									if debug_out:
										print 'search in <%s>' % proc_codes.proc_data_list[index1_r].left[index2_r]
									tmptmp_ctrl = proc_codes.proc_data_list[index1_r].left[index2_r][0:proc_codes.proc_data_list[index1_r].left[index2_r].find('(')]
									tmp_ctrl = tmptmp_ctrl + tmp_ctrl
									tmp_ctrl.strip()
				ctrl_stat_list.append(tmp_ctrl)
				if debug_out:
					print '->ctrl stat %s / %d' %  (tmp_ctrl, ctrl_proc_num)

# set type in ProcessData
	tmp_ctrl_stat = '???'
	ctrl_stat_id = 0
	ctrl_stat_flag = False
	last_ctrl_stat_flag = False

	for index in range(0, proc_codes.get_proc_data_size()):
		for index2 in range(0, proc_codes.proc_data_list[index].get_size()):




# find start of ctrl stat
			if ctrl_stat_id > len(ctrl_stat_list)-1:
				break

			if proc_codes.proc_data_list[index].type[index2].find('???')!=-1:
				if ctrl_stat_list[ctrl_stat_id].find('noctrl')!=-1:
					ctrl_stat_id += 1
					if ctrl_stat_id > len(ctrl_stat_list)-1:
						ctrl_stat_id = len(ctrl_stat_list)-1
						break

#0419				if proc_codes.proc_data_list[index].left[index2].find(ctrl_stat_list[ctrl_stat_id])!=-1:
				if is_ctrl_stat_word(ctrl_stat_list[ctrl_stat_id], proc_codes.proc_data_list[index].left[index2]):

					tmp_ctrl_stat = ctrl_stat_list[ctrl_stat_id]
					proc_codes.proc_data_list[index].type[index2] = tmp_ctrl_stat+'<start>'

#0419
#					print'    !!!!!! %s !!!!!!' % proc_codes.proc_data_list[index].type[index2]
#					print ' -->[%d/%d][%d/%d]%s' % (index, proc_codes.get_proc_data_size(), index2, proc_codes.proc_data_list[index].get_size(), proc_codes.proc_data_list[index].left[index2])


					ctrl_stat_flag = True
					ctrl_stat_id += 1
					if ctrl_stat_id > len(ctrl_stat_list)-1:
						ctrl_stat_id = len(ctrl_stat_list)-1
					continue
# keep setting type until type = subproc
			if proc_codes.proc_data_list[index].type[index2].find('subproc')!=-1:
				ctrl_stat_flag = False
				if last_ctrl_stat_flag==True:
					break
			if ctrl_stat_flag:
				proc_codes.proc_data_list[index].type[index2] = tmp_ctrl_stat





	if debug_out:
		ctrl_proc_num = 0
		for ctrl in ctrl_stat_list:
			ctrl_proc_num +=1
			print '-->ctrl stat %s / %d' %  (ctrl, ctrl_proc_num)

# find end of ctrl stat
#	for index in range(0, proc_codes.get_proc_data_size()):
#		for index2 in range(0,proc_codes.proc_data_list[index].get_size()):


#0419
	print ' ===END of analyze_control_statement'


	return 	ctrl_stat_list

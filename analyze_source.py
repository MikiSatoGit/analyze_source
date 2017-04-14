# coding: shift-JIS
#
#	analyze_source.py
#	Main class for analyzing C source
#	Create on: 2017.04.10
#	Author   : Miki Sato <miki_sato@denso-diam.com>
#	Copyright (C) 2017
#		DENSO International America Inc.
#
#	ARGUMENT:
#	python analyze_source.py [source file path] 
#
#   NOTE:
#     NG code : } xxxx {


import sys
import csv
import operator
import copy
import func_source_analyze

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

##################################################
# open file
##################################################
argvs = sys.argv
argc = len(argvs)
if(argc==2):
	if argvs[1]=="-h":
		print "# ARGUMENT:"
		print "#  python analyze_source.py [source file path]"
		print "#    [source file path]   : C source file"
		quit()

fout = ""

if argc==2 :
	filename1 = argvs[1]
	sourcefile = open(filename1)
else:
	print "ERROR:Could not start %s." % argvs[0]
	print "Please specify [source file path]."
	quit()

if filename1.find('\\')!=-1:
	str = filename1.rsplit('\\',1)
elif filename1.find('/')!=-1:
	str = filename1.rsplit('/',1)
if len(str)>1:
	outfile = str[0] +'\\analyze_' + str[1]
else:
	outfile = 'analyze_' + str[0]


outfile = outfile[0:outfile.rfind('.')] + '.txt'
fout = open(outfile,'w')

#tmp_string = "<open source file: " + filename1 + ">"
#print_out(fout, tmp_string, 1)
#tmp_string = "<open output file: " + outfile + ">"
#print_out(fout, tmp_string, 1)



##################################################
# analyze source code
##################################################

###### call function (load_valid_source_code) ######
cnt, lines = func_source_analyze.load_valid_source_code(sourcefile)

####### output original code #######
#for line in lines:
#	print_out(fout, line, 0)
#print_out(fout, "", 1)

print_out(fout, "Total lines: %d "  % cnt, 1)

###### call function (find_functions) ######
func_list = func_source_analyze.find_functions(lines)

###### call function (analyze_function) ######
for index1 in range(0, func_list.func_num):
	current_title_org = func_source_analyze.analyze_function(func_list.function_data[index1], "PROCESS")

###### File output (Header) ######
print_out(fout, "Total functions : %d "  % func_list.func_num, 1)
serial_proc_list = func_source_analyze.ProcessCodes()

for index1 in range(0, func_list.func_num):
	current_title = current_title_org
	serial_proc_list.clear()
	print_out(fout, "--------------------------", 1)
	print '====== %s ======' % func_list.function_data[index1].name
	# FUNCTION
	print_out(fout, "[Function Name] : %s "  % func_list.function_data[index1].name, 1)
	#print_out(fout, "-Code size : %s lines"  % len(func_list.function_data[index1].func_def), 1)
	print_out(fout, "-Return type : %s "  % func_list.function_data[index1].return_type, 1)
	print_out(fout, "-Argument : %s "  % func_list.function_data[index1].argument_num, 1)

	# ARGUMENT
	for index2 in range(0, func_list.function_data[index1].argument_num):
		print_out(fout, "     [%d] : %s "  %(index2, func_list.function_data[index1].argument_list[index2].type), 0),
		print_out(fout, " %s "  %(func_list.function_data[index1].argument_list[index2].name), 1),
	
	# CODE
	#print_out(fout, "-Code size: %s lines"  % func_list.function_data[index1].line_num, 1)
	#for index2 in range(0, len(func_list.function_data[index1].codes)):
	#	print_out(fout, "%s"  % func_list.function_data[index1].codes[index2], 1)

	print_out(fout, "-Codes (approx. %d line)" % func_list.function_data[index1].line_num, 1)


###### copy data ######
	tmp_proc_list = func_source_analyze.ProcessCodesList()
	tmp_proc_list = copy.deepcopy(func_list.function_data[index1].process_code_list)
	sub_proc_list = func_source_analyze.ProcessCodesList()
	sub_proc_flag = True
###### call function (analyze_sub_process) ######
	while sub_proc_flag == True:
		sub_proc_list, sub_proc_flag, current_title, tmp_serial_proc_list = func_source_analyze.analyze_sub_process(tmp_proc_list,current_title)
		serial_proc_list.append_list(tmp_serial_proc_list)
		###### copy data ######
		tmp_proc_list.clear()
		tmp_proc_list = copy.deepcopy(sub_proc_list)
		sub_proc_list.clear()
	serial_proc_list.set_func_name(func_list.function_data[index1].name)


	print_out(fout, "-Codes (%d process)" % serial_proc_list.get_size(), 1)
	for index2 in range(0,serial_proc_list.get_size()):
		tmp_title = serial_proc_list.title[index2]
		tmp_process = serial_proc_list.main[index2]
		print_out(fout, '[%s] ' % tmp_title, 0)
		print_out(fout, '%s ' % tmp_process, 1)









	##### For Debug #####
	# CODE
	print serial_proc_list.func_name,
	print 'code:%d (include subprocess header)' % serial_proc_list.get_size()
	# ARGUMENT
	print func_list.function_data[index1].name,
	print func_list.function_data[index1].argument_num
	#for index2 in range(0, func_list.function_data[index1].argument_num):
	#		print_out(fout, func_list.function_data[index1].argument_list[index2].type, 0),
	#		print_out(fout, func_list.function_data[index1].argument_list[index2].name, 0)



##################################################
# close file
##################################################
#tmp_string = "<close correct file: " + filename1 + ">"
#print_out(fout, tmp_string, 1)
sourcefile.close()

#tmp_string = "<close output file: " + outfile + ">"
#print_out(fout, tmp_string, 1)
if fout != "":
	fout.close()

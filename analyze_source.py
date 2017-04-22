# coding: shift-JIS
#
#	analyze_source.py
#	Main class for analyzing C source
#	Create on: 2017.04.10
#	Author   : Miki Sato <miki.sam.sato@gmail.com>
#
#	ARGUMENT:
#	python analyze_source.py [source file path] 
#
#   NOTE:
#

import sys
import csv
import operator
import copy
import func_source_analyze

############################################################################################
debug_out = False


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
#func_source_analyze.print_out(fout, tmp_string, 1)
#tmp_string = "<open output file: " + outfile + ">"
#func_source_analyze.print_out(fout, tmp_string, 1)



##################################################
# analyze source code
##################################################

###### call function (load_valid_source_code) ######
cnt, lines = func_source_analyze.load_valid_source_code(sourcefile)

####### output CODE (ORIGINAL) #######
if debug_out:
	for line in lines:
		func_source_analyze.print_out(fout, line, 0)
	func_source_analyze.print_out(fout, "", 1)

func_source_analyze.print_out(fout, "Total lines: %d "  % cnt, 1)

###### call function (find_functions) ######
func_list = func_source_analyze.find_functions(lines)
# [in] lines : List
# [out] func_list : FunctionList

###### call function (analyze_function_list) ######
for index1 in range(0, func_list.func_num):
	func_source_analyze.analyze_function_list(func_list.function_data[index1])
# [in] func_list.function_data : FunctionData
# [out] func_list.process_code_list : ProcessCodes

###### File output (Header) ######
func_source_analyze.print_out(fout, "Total functions : %d "  % func_list.func_num, 1)
for index1 in range(0, func_list.func_num):
	func_source_analyze.print_out(fout, "--------------------------", 1)

	if debug_out:
		print '====== %s ======' % func_list.function_data[index1].name

	# FUNCTION
	func_source_analyze.print_out(fout, "[Function Name] : %s "  % func_list.function_data[index1].name, 1)
	#func_source_analyze.print_out(fout, "-Code size : %s lines"  % len(func_list.function_data[index1].func_def), 1)
	func_source_analyze.print_out(fout, "-Return type : %s "  % func_list.function_data[index1].return_type, 1)
	func_source_analyze.print_out(fout, "-Argument : %s "  % func_list.function_data[index1].argument_num, 1)

	# ARGUMENT
	for index2 in range(0, func_list.function_data[index1].argument_num):
		func_source_analyze.print_out(fout, "     [%d] : %s "  %(index2, func_list.function_data[index1].argument_list[index2].type), 0),
		func_source_analyze.print_out(fout, " %s "  %(func_list.function_data[index1].argument_list[index2].name), 1),
	
	# CODE
	if debug_out:
		func_source_analyze.print_out(fout, "-Codes: %s lines" % func_list.function_data[index1].line_num, 1)
		for index2 in range(0, len(func_list.function_data[index1].codes)):
			func_source_analyze.print_out(fout, "%s"  % func_list.function_data[index1].codes[index2], 1)









###### call function (analyze_process_code) ######
	if debug_out:
		for index2 in range (0, func_list.function_data[index1].process_code_list.get_main_size()):
			print '--> %s' % func_list.function_data[index1].process_code_list.title[index2],
			print ' %s' % func_list.function_data[index1].process_code_list.main[index2]

	func_source_analyze.analyze_process_code(func_list.function_data[index1].process_code_list)
	# CODE
	func_source_analyze.print_out(fout, '----- Codes -----', 1)
	total_lines = func_list.function_data[index1].process_code_list.file_print_proc_data_list(fout)
	func_source_analyze.print_out(fout, "----------------- Total Codes : %d lines" % total_lines, 1)









##################################################
# close file
##################################################
#tmp_string = "<close correct file: " + filename1 + ">"
#func_source_analyze.print_out(fout, tmp_string, 1)
sourcefile.close()

#tmp_string = "<close output file: " + outfile + ">"
#func_source_analyze.print_out(fout, tmp_string, 1)
if fout != "":
	fout.close()

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
import os.path
import sys
#import csv
#import operator
import copy
import func_source_analyze
import func_blockdiag
import func_sphinx

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
else:
	filename1 = raw_input("Please specify [source file path] -> ")
print '...checking %s' % filename1
if not os.path.exists(filename1):
	print "ERROR:Could not start %s." % argvs[0]
	quit()


str_filename1 = filename1
if filename1.find('\\')!=-1:
	str_filename1 = filename1.rsplit('\\',1)
elif filename1.find('/')!=-1:
	str_filename1 = str_filename1.rsplit('/',1)

if len(str_filename1)>1:
	outfile = str_filename1[0] +'\\analyze_' + str_filename1[1]
else:
	outfile = 'analyze_' + str_filename1[0]

sourcefile = open(filename1)
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
func_list = func_source_analyze.FunctionList()
func_list = func_source_analyze.find_functions(lines)
# [in] lines : List
# [out] func_list : FunctionList


###### call function (analyze_function_list) ######
for func in func_list.function_data:
	func_source_analyze.analyze_function_list(func)
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
	func_source_analyze.print_out(fout, "-Return type : %s "  % func_list.function_data[index1].return_type, 1)
	func_source_analyze.print_out(fout, "-Argument : %s "  % func_list.function_data[index1].argument_num, 1)

	# ARGUMENT
	for index2 in range(0, func_list.function_data[index1].argument_num):
		func_source_analyze.print_out(fout, "     [%d] : %s "  %(index2, func_list.function_data[index1].argument_list[index2].type), 0),
		func_source_analyze.print_out(fout, " %s "  %(func_list.function_data[index1].argument_list[index2].name), 1),
	

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
# draw flow chart and output proc&cond to csv file
##################################################
###### call function (draw_diag) ######
##### main
	sub_proc_codes_list, sub_header_list = func_blockdiag.draw_diag( \
		str_filename1, \
		func_list.function_data[index1].name, \
		func_list.function_data[index1].process_code_list, \
		'MAINPROCESS', \
		0
	)

	if debug_out:
		for degug_proc_codes in sub_proc_codes_list:
			total_lines = degug_proc_codes.file_print_proc_data_list(fout)
		func_source_analyze.print_out(fout, "---------------------------", 1)
		print '<main>------------------------- sub proc list(%d)' % len(sub_proc_codes_list) 
		print '<main>------------------------- header list(%d)' % len(sub_header_list) 

##### sub
	loop_flg = True
	level_title = 'PROCESS'
	next_header_list = []
	next_proc_list = []
	while loop_flg:
		level_title = 'SUB' + level_title
		sub_proc_num = 0

		if debug_out:
			for i in range(0, len(sub_proc_codes_list)):
				print sub_header_list[i]
				for j in range(0, sub_proc_codes_list[i].get_main_size()):
					print sub_proc_codes_list[i].title[j],
					print sub_proc_codes_list[i].main[j],
					print sub_proc_codes_list[i].get_proc_data_size(),
					print sub_proc_codes_list[i].proc_data_list[j].type


		for index in range( 0, len(sub_proc_codes_list) ):
			each_proc_codes = sub_proc_codes_list[index]
			tmp_header = sub_header_list[index]

			if debug_out:
				print '<%d>>>>>>>>>>>>>%s' % (index, tmp_header)


			if isinstance(func_list.function_data[index1].name, list):
				func_list.function_data[index1].name = ','.join(func_list.function_data[index1].name)


			tmp_proc_codes_list, tmp_header_list = func_blockdiag.draw_diag( \
				str_filename1, \
				func_list.function_data[index1].name + '_'+ tmp_header, \
				each_proc_codes, \
				level_title, \
				0
			)
			if len(tmp_header_list)!=0:
				for i in range(0, len(tmp_header_list)):
					tmp_header_list[i] = tmp_header + '_' + tmp_header_list[i]
			sub_proc_num += len(tmp_proc_codes_list)

			if debug_out:
				print '<<<<<<<<<<<<<%d> %d/%d' % (index, len(tmp_proc_codes_list),sub_proc_num)

			if len(tmp_header_list)!=0:
				next_header_list += tmp_header_list
			if len(tmp_proc_codes_list)!=0:
				next_proc_list += tmp_proc_codes_list

		if len(next_proc_list)==0:
			loop_flg = False
		else:
			del sub_header_list[:]
			del sub_proc_codes_list[:]
			sub_header_list = copy.deepcopy(next_header_list)
			sub_proc_codes_list = copy.deepcopy(next_proc_list)
			del next_header_list[:]
			del next_proc_list[:]


##################################################
# create func definition to csv file
##################################################
func_blockdiag.output_func_def_to_csv(
	str_filename1, \
	func_list, \
	'arg'
)
func_blockdiag.output_func_def_to_csv(
	str_filename1, \
	func_list, \
	'ret'
)

##################################################
# create rst file for Sphinx
##################################################
# check csv / fig files
fileList_list = func_sphinx.get_file_list( str_filename1, func_list )

#create index file
doc_path = func_sphinx.set_doc_path( str_filename1 )
rst_index_file = func_sphinx.create_index( doc_path, func_list )

if debug_out:
	for file_list in fileList_list:
		print '[FUNCTION] %s' % file_list.name
		cnt = 0
		for item in file_list.arg:
			print 'arg[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.ret:
			print 'ret[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.fig:
			print 'fig[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.proc:
			print 'proc[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.cond:
			print 'cond[%d] %s' % (cnt, item)
			cnt += 1
	print '>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>'


#create main file
fileList_list = func_sphinx.create_func_main( doc_path, func_list, fileList_list )

if debug_out:
	for file_list in fileList_list:
		print '[FUNCTION] %s' % file_list.name
		cnt = 0
		for item in file_list.arg:
			print 'arg[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.ret:
			print 'ret[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.fig:
			print 'fig[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.proc:
			print 'proc[%d] %s' % (cnt, item)
			cnt += 1
		cnt = 0
		for item in file_list.cond:
			print 'cond[%d] %s' % (cnt, item)
			cnt += 1
	print '>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>'


print '*******************************************************************************'

#create sub process file
level_title = 'PROCESS'
while func_sphinx.check_files(fileList_list):
	level_title = 'SUB' + level_title
	fileList_list = func_sphinx.create_func_sub( doc_path, func_list, fileList_list, level_title )

	if debug_out:
		for file_list in fileList_list:
			print '[FUNCTION] %s' % file_list.name
			cnt = 0
			for item in file_list.arg:
				print 'arg[%d] %s' % (cnt, item)
				cnt += 1
			cnt = 0
			for item in file_list.ret:
				print 'ret[%d] %s' % (cnt, item)
				cnt += 1
			cnt = 0
			for item in file_list.fig:
				print 'fig[%d] %s' % (cnt, item)
				cnt += 1
			cnt = 0
			for item in file_list.proc:
				print 'proc[%d] %s' % (cnt, item)
				cnt += 1
			cnt = 0
			for item in file_list.cond:
				print 'cond[%d] %s' % (cnt, item)
				cnt += 1
		print '>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>'


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

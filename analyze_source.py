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


import sys
import csv
import operator
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

outfile = filename1[filename1.find('_')+1:len(filename1)]
outfile = 'analyze_' + filename1
outfile = outfile[0:outfile.rfind('.')] + '.txt'
fout = open(outfile,'w')

#tmp_string = "<open source file: " + filename1 + ">"
#print_out(fout, tmp_string, 1)
#tmp_string = "<open output file: " + outfile + ">"
#print_out(fout, tmp_string, 1)



##################################################
# analyze source code
##################################################
cnt, lines = func_source_analyze.load_valid_source_code(sourcefile)
for line in lines:
	print_out(fout, line, 0)
print_out(fout, "total : %d lines"  % cnt, 1)

func_list = func_source_analyze.find_functions(lines)

for index1 in range(0, func_list.func_num):
	print func_list.function_data[index1].line_num
#	for index2 in range(0, func_list.function_data[index1].line_num):
#		print_out(fout, func_list.function_data[index1].codes[index2], 0)
#		print func_list.function_data[index1].codes[index2]


##################################################
# close file
##################################################
tmp_string = "<close correct file: " + filename1 + ">"
print_out(fout, tmp_string, 1)
sourcefile.close()

tmp_string = "<close output file: " + outfile + ">"
print_out(fout, tmp_string, 1)
if fout != "":
	fout.close()

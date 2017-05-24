#
#	func_blockdiag.py
#	Draw Blockdialogue
#	Create on: 2017.05.11
#	Author   : Miki Sato <miki.sam.sato@gmail.com>
#
#   NOTE:
#

# coding: shift-JIS
from blockdiag import parser, builder, drawer 
import func_source_analyze
import copy
import os
import glob

class BlockDataList:
	def __init__(self):
		self.blockdata = [] #BlockData
	def size(self):
		return len(self.blockdata)
	def clear(self):
		del self.blockdata[:]
		return

class BlockData:
	def __init__(self):
		self.title = ''
		self.type = ''
		self.procs = [] #ProcessData
	def proc_size(self):
		return len(self.procs)
	def clear(self):
		self.title = ''
		self.type = ''
		del self.procs[:]
		return


debug_out = False

def draw_diag(sourcefilename, funcname, proc_codes, level_title, outputmode):
# [in] sourcefilename : C source file name(str)
# [in] funcname : FunctionList.FunctionData.name (str)
# [in] proc_codes : FunctionList.FunctionData.process_code_list (ProcessCodes)
# [in] level_title : process level (str) : MAINPROCESS, SUBPROCESS,...
# [in] outputmode : 0:png, 1:source txt, 2:both

	outfile = ''
	txtfile = ''
	csvfile_base = ''	
	if len(sourcefilename)>1:
		if os.path.exists(sourcefilename[0] + '\\fig')==False:
			os.makedirs(sourcefilename[0] + '\\fig')
		if os.path.exists(sourcefilename[0] + '\\csv')==False:
			os.makedirs(sourcefilename[0] + '\\csv')
		outfile = sourcefilename[0] + '\\fig\\' + sourcefilename[1]
		txtfile = sourcefilename[0] + '\\fig\\' + sourcefilename[1]
		csvfile_base = sourcefilename[0] + '\\csv\\' + sourcefilename[1]
	else:
		if os.path.exists('\\fig')==False:
			os.makedirs('\\fig')
		if os.path.exists('\\csv')==False:
			os.makedirs('\\csv')
		outfile = '\\fig\\' + sourcefilename[0]
		txtfile = '\\fig\\' + sourcefilename[0]
		csvfile_base = '\\csv\\' + sourcefilename[0]
	outfile = outfile[0:outfile.rfind('.')] + '_' + funcname + '_' + level_title +'.svg'
	txtfile = txtfile[0:txtfile.rfind('.')] + '_' + funcname + '_' + level_title +'.diag'
	csvfile_base = csvfile_base[0:csvfile_base.rfind('.')] + '_' + funcname + '_' + level_title

	save_png_flag = False
	save_txt_flag = False
	if outputmode==0 or outputmode==2:
		save_png_flag = True
	if outputmode==1 or outputmode==2:
		save_txt_flag = True

	source_header = 'blockdiag {\n'
	source_header += 'orientation = portrait;\n'
	source_header += 'plugin autoclass;\n'
	source_header += 'span_width = 24;\n'
	source_header += 'span_height = 20;\n'
	source_header += 'class if [shape = diamond];\n'
	source_header += 'class elif [shape = diamond];\n'
#	source_header += 'class else [shape = diamond];\n'
	source_header += 'class for [shape = flowchart.loopin];\n'
	source_header += 'class forend [shape = flowchart.loopout];\n'
	source_header += 'class while [shape = flowchart.loopin, color = gray];\n'
	source_header += 'class whileend [shape = flowchart.loopout, color = gray];\n'
	source_header += 'class switch [shape = diamond, color = gray];\n'
	source_header += 'class pt [shape = minidiamond];\n'
	source_header += 'class subproc [color = pink];\n'
	source_header += 'START -> '


#################### Check process ####################

	if debug_out:
		print '<draw_diag> before ---------------------------------------'
		for index1 in range (0, proc_codes.get_proc_data_size()):
			for index2 in range(0, len(proc_codes.proc_data_list[index1].title)):
				print '  [%d][%d](%s) %s %s' % ( \
					index1, \
					index2, \
					proc_codes.proc_data_list[index1].type[index2], \
					proc_codes.proc_data_list[index1].left[index2], \
					proc_codes.proc_data_list[index1].right[index2] \
				)
		


	block_data_list = check_proc_codes(proc_codes, level_title)



#	if debug_out:
	print '<draw_diag> after ---------------------------------------- %s' % csvfile_base
	print block_data_list.size()
	for index in range(0, block_data_list.size()):
		blockdata = block_data_list.blockdata[index]
		print '[%d]%s(%s) %d' % ( index, blockdata.title, blockdata.type, blockdata.proc_size() )
		for index2 in range(0, blockdata.proc_size()):
			for index3 in range(0, len(blockdata.procs[index2].title) ):
				print '  [%s] %s %s' % ( \
					blockdata.procs[index2].type[index3], \
					blockdata.procs[index2].left[index3], \
					blockdata.procs[index2].right[index3] \
				)


#################### Create csv file of cond & proc ####################
	output_proc_to_csv(csvfile_base, block_data_list)


#################### Create Block diag code ####################
# add main flow
	block_code, sub_proc_list, block_code_cond_list = create_main_blocks(block_data_list)

# add sub flow
	block_code += create_subproc_blocks(sub_proc_list)

# add condition flow
	for block_code_cond in block_code_cond_list:
		block_code += block_code_cond

	source = source_header
	source += block_code
	source += ' }'


#################### Draw Block diag ####################
	print '----------<%s>----------' % funcname
	print source

	if save_png_flag:
		tree = parser.parse_string(source) 
		diagram = builder.ScreenNodeBuilder.build(tree) 
		draw = drawer.DiagramDraw('SVG', diagram, filename=outfile) 
		draw.draw()
		draw.save() 

	if save_txt_flag:
		fout = open(txtfile,'w')
		fout.write(source)
		fout.close()

#################### Extract Sub Block ####################
	out_proc_codes_list, header_list = extract_sub_proc(proc_codes, level_title)

	if debug_out:
		print	'============================'
		print 'header list : %d' % len(header_list)
		for head in header_list:
			print head
		print 'out proc codes list : %d' % len(out_proc_codes_list)
		for code in out_proc_codes_list:
			print code.get_main_size(),
			print code.get_proc_data_size()

	return out_proc_codes_list, header_list


def check_proc_codes(proc_codes, level_title):
# [in] proc_codes : FunctionList.FunctionData.process_code_list (ProcessCodes)
# [in] level_title : process level (str) : MAINPROCESS, SUBPROCESS,...
# [out] block_data_list : BlockDataList = List of [title, type, List of [ProcessData(title,type,left,right)] 

	debug_out = True #0523

	block_data_list = BlockDataList()
	block_data = BlockData()
	current_title = ''
	proc_id = 0
	cond_proc_id = 0

	for index1 in range(0, proc_codes.get_proc_data_size()):


		for index2 in range(0,proc_codes.proc_data_list[index1].get_main_size()):
			proc_title = proc_codes.proc_data_list[index1].title[index2].strip()
			proc_type = proc_codes.proc_data_list[index1].type[index2].strip()
			proc_left = proc_codes.proc_data_list[index1].left[index2]

### MAIN process
			if is_level_title(proc_title, level_title):

				# Skip ";" only
				if proc_codes.proc_data_list[index1].left[0].find(';')!=-1 and len(proc_codes.proc_data_list[index1].left[0])==1:
					if debug_out:
						print '<check_proc_codes> Skip ";" only'
					continue

				# rename title
				proc_title, cond_proc_id, proc_id = rename_title(proc_type, proc_title, cond_proc_id, proc_id, level_title)

				# level title is chaged
				if proc_title != current_title:
### condition
# if, else if, else
# for
# while
# switch, case, default
					if func_source_analyze.is_ctrl_stat(proc_type)==True:
						if block_data.proc_size() != 0:
							block_data_list.blockdata.append(copy.deepcopy(block_data))
						block_data.clear()

						current_title = proc_title

						# convert title
						block_data.title = proc_title
						block_data.type = proc_type

						tmp_procdata = func_source_analyze.ProcessData()
						tmp_procdata.title.append( proc_codes.proc_data_list[index1].title[index2] )
						tmp_procdata.type.append( proc_codes.proc_data_list[index1].type[index2] )
						tmp_procdata.left.append( proc_codes.proc_data_list[index1].left[index2] )
						tmp_procdata.right.append( proc_codes.proc_data_list[index1].right[index2] )
						block_data.procs.append(copy.deepcopy(tmp_procdata))

### not condition
					else:
						if block_data.proc_size() != 0:
							block_data_list.blockdata.append(copy.deepcopy(block_data))
						block_data.clear()

						# subprocess of condition 
						if proc_id==cond_proc_id and proc_type.find('subproc')!=-1:
							proc_title = current_title[:current_title.find('_')] + '_' + proc_left.replace('PROCESS', '')
							proc_title = proc_title.replace('(', '')
							proc_title = proc_title.replace(')', '')

						current_title = proc_title

						block_data.title = current_title
						if debug_out:
							print block_data.title

						tmp_procdata = func_source_analyze.ProcessData()
						tmp_procdata.title.append( proc_codes.proc_data_list[index1].title[index2] )
						tmp_procdata.type.append( proc_codes.proc_data_list[index1].type[index2] )
						tmp_procdata.left.append( proc_codes.proc_data_list[index1].left[index2] )
						tmp_procdata.right.append( proc_codes.proc_data_list[index1].right[index2] )
						block_data.procs.append(copy.deepcopy(tmp_procdata))

				# level title is not chaged
				else:
					tmp_procdata = func_source_analyze.ProcessData()
					tmp_procdata.title.append( proc_codes.proc_data_list[index1].title[index2] )
					tmp_procdata.type.append( proc_codes.proc_data_list[index1].type[index2] )
					tmp_procdata.left.append( proc_codes.proc_data_list[index1].left[index2] )
					tmp_procdata.right.append( proc_codes.proc_data_list[index1].right[index2] )
					block_data.procs.append(copy.deepcopy(tmp_procdata))

					if debug_out:
						print '<check_proc_codes> No diagram'

#### SUB process
			else:
				if debug_out:
					print '<check_proc_codes> Skip sub proc'

#0523





	if block_data.proc_size() != 0:
		block_data_list.blockdata.append(copy.deepcopy(block_data))

	return block_data_list


def is_level_title(proc_title, level_title):
	bret = False
	tmp_proc_title = proc_title
	tmp_proc_title = tmp_proc_title[:tmp_proc_title.find('(')]
	if tmp_proc_title==level_title:
		bret = True
	return bret


def rename_title(proc_type, proc_title, cond_proc_id, proc_id, level_title):
	if func_source_analyze.is_ctrl_stat(proc_type)==True:
		cond_proc_id = int( proc_title[proc_title.find('(')+1:proc_title.find(')')] )
		proc_title = find_ctrl_stat_in_title(proc_title, proc_type, level_title)
	else:
		proc_id = int( proc_title[proc_title.find('(')+1:proc_title.find(')')] )
		proc_title = proc_title.replace('PROCESS', '')
		proc_title = proc_title.replace('(', '')
		proc_title = proc_title.replace(')', '')
	return proc_title, cond_proc_id, proc_id


def find_ctrl_stat_in_title(title, type, level_title):
	title = title.replace('(', '')
	title = title.replace(')', '')
	if type.find('else if')!=-1:
		title = title.replace(level_title, 'ELIF')
		title += '_elif'
	elif type.find('else')!=-1:
		title = title.replace(level_title, 'ELSE')
		title += '_else'
	elif type.find('if')!=-1:
		title = title.replace(level_title, 'IF')
		title += '_if'
	elif type.find('for')!=-1:
		title = title.replace(level_title, 'FORLOOP')
		title += '_for'
	elif type.find('while')!=-1:
		title = title.replace(level_title, 'WHILELOOP')
		title += '_while'
	elif type.find('switch')!=-1:
		title = title.replace(level_title, 'SWITCH')
		title += '_switch'
	else:
		title = title.replace(level_title, 'COND')
		title += '_cond'

	return title


def create_main_blocks(block_data_list):
# [in] block_data_list : BlockDataList = List of [title, type, List of [ProcessData(title,type,left,right)] 
# [out] block_code : main block code
# [out] sub_proc_list :  sub block code
# [out] block_code_cond_list : if, elseif, else block code

	debug_out = True #0523

	if debug_out:
		print '<create_main_blocks> ----------------------------------------'
	block_code =''
	block_code_cond_list = []
	condition_if_prev = ''
	sub_proc_list = []

# main flow
	for index in range(0, len(block_data_list.blockdata)):
		tmp_blockdata = block_data_list.blockdata[index]
		tmp_str = tmp_blockdata.title

		if debug_out:
			print '<create_main_blocks> %s' % tmp_str

		# break if only return 20170523
		if tmp_blockdata.proc_size()==1:
			if tmp_blockdata.procs[0].type[0]=='return':
				break


		if tmp_str.find('_else')!=-1:
			block_code_cond_list += create_if_blocks('_else', tmp_str, condition_if_prev)
			condition_if_prev = ''

		elif tmp_str.find('_elif')!=-1:
			block_code_cond_list += create_if_blocks('_elif', tmp_str, condition_if_prev)
			condition_if_prev = tmp_str

		elif tmp_str.find('_if')!=-1:
			block_code_cond_list += create_if_blocks('_if', tmp_str, condition_if_prev)
			condition_if_prev = tmp_str

			block_code += tmp_str
			block_code += ' -> '
			block_code += tmp_str.replace('_if', '_yes_pt')
			block_code += ';\n'
#			block_code += ' -> '
			block_code += tmp_str.replace('_if', '_end_pt')
			block_code += ' -> '

		elif tmp_str.find('_switch')!=-1:
			block_code += tmp_str
			block_code += ';\n'
			block_code += tmp_str.replace('_switch', '_end_pt')
			block_code += ' -> '

		elif tmp_str.find('_for')!=-1:
			block_code += tmp_str
			block_code += ';\n'
			block_code += tmp_str.replace('_for', '_END_forend')
			block_code += ' -> '

		elif tmp_str.find('_while')!=-1:
			block_code += tmp_str
			block_code += ';\n'
			block_code += tmp_str.replace('_while', '_END_whileend')
			block_code += ' -> '

		else:
			if tmp_str.find('_SUB')==-1:
				block_code += tmp_str
				block_code += ' -> '
			else:
				sub_proc_list.append(tmp_str)

	block_code += 'END;\n'
	return block_code, sub_proc_list, block_code_cond_list


def create_if_blocks(condition_str, code, condition_prev):
	block_code_cond_list = []
	block_code_cond = ''
	parent_condition = ''

	if condition_str.find('_else')!=-1:
		if condition_prev.find('_elif')!=-1:
			parent_condition = '_elif'
		elif condition_prev.find('_if')!=-1:
			parent_condition = '_if'
	if condition_str.find('_elif')!=-1:
		if condition_prev.find('_elif')!=-1:
			parent_condition = '_elif'
		elif condition_prev.find('_if')!=-1:
			parent_condition = '_if'

	if parent_condition!='':
		# no_pt -> code
		block_code_cond = condition_prev
		block_code_cond += ' -> '
		block_code_cond += condition_prev.replace(parent_condition, '_no_pt')
		block_code_cond += ' -> '
		block_code_cond += code
		block_code_cond += ';\n'

		# end_pt -> end_pt(parent)
		block_code_cond += code.replace(condition_str, '_end_pt')
		block_code_cond += ' -> '
		block_code_cond += condition_prev.replace(parent_condition, '_end_pt')
		block_code_cond += ';\n'
		block_code_cond_list.append(block_code_cond)

		block_code_cond = condition_prev.replace(parent_condition, '_no_pt') + '[label = "No"];\n'
		block_code_cond_list.append(block_code_cond)

	if condition_str.find('_else')==-1:
		# code -> yes_pt
		block_code_cond = code
		block_code_cond += ' -> '
		block_code_cond += code.replace(condition_str, '_yes_pt')
		block_code_cond += ';\n'
		block_code_cond_list.append(block_code_cond)

		block_code_cond = code.replace(condition_str, '_yes_pt') + '[label = "yes"];\n'
		block_code_cond_list.append(block_code_cond)

	return block_code_cond_list


def create_subproc_blocks(sub_proc_list):
# [in] sub_proc_list :  sub block code
# [out] block_code : main block code
	block_code = ''
	for block_code_sub in sub_proc_list:
		tmp_pt_start = ''
		tmp_pt_end = '' 
		if block_code_sub.find('ELSE')!=-1:
			tmp_pt_start = '_else'
			tmp_pt_end = '_end_pt'
		elif block_code_sub.find('ELIF')!=-1:
			tmp_pt_start = '_yes_pt'
			tmp_pt_end = '_end_pt'
		elif block_code_sub.find('IF')!=-1:
			tmp_pt_start = '_yes_pt'
			tmp_pt_end = '_end_pt'
		elif block_code_sub.find('SWITCH')!=-1:
			tmp_pt_start = '_switch'
			tmp_pt_end = '_end_pt'
		elif block_code_sub.find('FOR')!=-1:
			tmp_pt_start = '_for'
			tmp_pt_end = '_END_forend'
		elif block_code_sub.find('WHILE')!=-1:
			tmp_pt_start = '_while'
			tmp_pt_end = '_END_whileend'

		block_code += block_code_sub[:block_code_sub.find('_')] + tmp_pt_start
		block_code += ' -> '
		block_code += block_code_sub + '_subproc'
		block_code += ' -> '
		block_code += block_code_sub[:block_code_sub.find('_')] + tmp_pt_end
		block_code += ';\n'

	return block_code


def extract_sub_proc(proc_codes, level_title):
	target_level = level_title.count('SUB')
	header_list = []
	out_proc_codes_list = []
	out_proc_codes = func_source_analyze.ProcessCodes()
	tmp_proc_data = func_source_analyze.ProcessData()
	header_title = ''
	cond_proc_id = 0
	proc_id = 0
	proc_title = ''
	tmp_proc_title = ''
	tmp_level = 0
	tmp_level_prev = 0
	block_flag = False
	block_num = 0

	top_title = 'MAIN'
	for tmp_index in range(0, target_level):
		top_title = top_title.replace('MAIN','')
		top_title += 'SUB'

	if debug_out:
		print '[top] %s' %  top_title

	for index1 in range (0, proc_codes.get_main_size() ):
		tmp_level_prev = tmp_level
		tmp_level = proc_codes.title[index1].count('SUB')

		# check parent title
		if tmp_level < target_level+1:
			tmp_proc_title = proc_codes.title[index1].strip()
			tmp_proc_type = proc_codes.proc_data_list[index1].type[0].strip()
			tmp_proc_title, cond_proc_id, proc_id = rename_title( \
				tmp_proc_type, \
				tmp_proc_title, \
				cond_proc_id, \
				proc_id, \
				level_title
			)
			if tmp_proc_title.rfind('_')!=-1:
				tmp_proc_title = tmp_proc_title[:tmp_proc_title.rfind('_')]

			if debug_out:
				print '[prev] %s(lv%d) -> [curr] %s(lv%d) (proc %d)(cond %d)' % (proc_title, tmp_level_prev, tmp_proc_title, tmp_level, proc_id, cond_proc_id)

			if proc_title != tmp_proc_title:
				proc_title = tmp_proc_title
				if tmp_level==target_level:

					if tmp_level_prev==tmp_level \
					and cond_proc_id != 0 \
					and proc_id == cond_proc_id \
					and proc_title.count(top_title)==1:
						if debug_out:
							print '[header] skip',
					else:
						header_title = proc_title
						header_list.append(header_title)
						block_flag = True
						block_num += 1

						if debug_out:
							print '[header] %s(%d)' % (header_title, block_num)

				else:
					if tmp_level_prev < tmp_level:
						header_title +=	proc_title

						if debug_out:
							print '[header] %s' % (header_title)

		# copy sub process
		else:
			if debug_out:
				#print	proc_codes.main[index1], 
				print	proc_codes.title[index1], 
				#print	proc_codes.level[index1], 
				#print	proc_codes.id[index1],
				print	proc_codes.proc_data_list[index1].get_main_size()

			out_proc_codes.append_code( \
				proc_codes.main[index1], \
				proc_codes.title[index1], \
				proc_codes.level[index1], \
				proc_codes.id[index1], \
			)
			tmp_proc_data.clear() 
			for index2 in range(0,proc_codes.proc_data_list[index1].get_main_size()):
				if is_level_title(proc_codes.proc_data_list[index1].title[index2], level_title) ==False:
					if debug_out:
						#print	' -> %s' % proc_codes.proc_data_list[index1].title[index2],
						print	' -> %s' % proc_codes.proc_data_list[index1].type[index2],
						#print	' -> %s' % proc_codes.proc_data_list[index1].left[index2],
						#print	' -> %s' % proc_codes.proc_data_list[index1].right[index2] 

					tmp_proc_data.append_data( \
						proc_codes.proc_data_list[index1].title[index2], \
						proc_codes.proc_data_list[index1].type[index2], \
						proc_codes.proc_data_list[index1].left[index2], \
						proc_codes.proc_data_list[index1].right[index2] \
					)
			out_proc_codes.proc_data_list.append( copy.deepcopy(tmp_proc_data) )

		# save sub proc
		if block_flag==True and len(header_list)>1: #save after 2nd header
			if out_proc_codes.get_main_size()!=0:
				out_proc_codes_list.append( copy.deepcopy(out_proc_codes) )

				if debug_out:
					print '[saved 1] %s(%d)' % (header_list[len(header_list)-2], out_proc_codes.get_main_size() )

				out_proc_codes.clear()
			else:
				if debug_out:
					print 'erase:%s' % header_list[len(header_list)-2]

				header_list.pop(len(header_list)-2)
			block_flag = False

	# save sub proc
	if out_proc_codes.get_main_size()!=0:
		out_proc_codes_list.append( copy.deepcopy(out_proc_codes) )

		if debug_out:
			print '[saved 2] %s(%d)' % (header_list[-1], out_proc_codes.get_main_size() )

	else:
		if len(header_list)>0:
			header_list.pop()

	return out_proc_codes_list, header_list



def output_proc_to_csv(csvfile_base, block_data_list):
	proc_id = 0
	cond_id = 0
	arg_id = 0
	tmp_files = glob.glob(csvfile_base+'*.csv')
	for tmp_file in tmp_files:
		os.remove(tmp_file)

	for index in range(0, block_data_list.size()):
		blockdata = block_data_list.blockdata[index]
		for index2 in range(0, blockdata.proc_size()):
			for index3 in range(0, len(blockdata.procs[index2].title) ):

				# break if only return 20170523
				if blockdata.proc_size()==1:
					if blockdata.procs[index2].type[index3]=='return':
						break

				### COND
				if func_source_analyze.is_ctrl_stat( blockdata.procs[index2].type[index3] ):
					if index2==0 or blockdata.procs[index2].left[index3]==')':
						continue
					else:
						csvfile = csvfile_base + '_' + blockdata.title + '_cond.csv'
						if os.path.exists(csvfile)==False:
							fout_csv = open(csvfile,'a')
							table = 'COND#' + ', ' \
							+ 'Data'  + ', ' \
							+ 'Condition' + '\n'
							fout_csv.write(table)
						else:
							fout_csv = open(csvfile,'a')
						cond_id += 1
						table = 'COND.' + str(cond_id) + ', ' \
						+ blockdata.procs[index2].left[index3]  + ', ' \
						+ blockdata.procs[index2].right[index3] + '\n'
						fout_csv.write(table)
						fout_csv.close()

				### subproc
				elif blockdata.procs[index2].type[index3].strip()=='subproc':
					continue

				### func
				elif blockdata.procs[index2].type[index3].strip().find('func')!=-1:
					csvfile = csvfile_base + '_' + blockdata.title + '_proc.csv'
					if os.path.exists(csvfile)==False:
						fout_csv = open(csvfile,'a')
						table = 'PROC#' + ', ' \
						+ 'Processing'  + ', ' \
						+ 'Description' + '\n'
						fout_csv.write(table)
					else:
						fout_csv = open(csvfile,'a')

					#########
					if blockdata.procs[index2].type[index3].strip().find('<start>')!=-1:
						proc_id += 1
						arg_id = 0
						table = 'PROC.' + str(proc_id) + ', ' \
						+ blockdata.procs[index2].left[index3] + ')' + blockdata.procs[index2].right[index3] + ',' \
						+ '\n'
						if blockdata.procs[index2].left[index3].find('=')!=-1:
							func_name = blockdata.procs[index2].left[index3][blockdata.procs[index2].left[index3].find('='):blockdata.procs[index2].left[index3].find('(')]
							func_name = func_name.strip()
						else:
							func_name = blockdata.procs[index2].left[index3][:blockdata.procs[index2].left[index3].find('(')]
							func_name = func_name.strip()

#0523						if debug_out:
						print '<draw_diag> func name : %s' % func_name

					elif blockdata.procs[index2].type[index3].strip().find('<end>')!=-1:
						continue
					else:
						arg_id += 1
#0523						table = 'PROC.' + str(proc_id) + ', ' \
#0523						+ func_name + '(): arg.' + str(arg_id) \
						table = '' + ', ' \
						+ '[arg.' + str(arg_id) + ']' + ', ' \
						+ blockdata.procs[index2].left[index3]  + blockdata.procs[index2].right[index3] + '\n'

					#########
					fout_csv.write(table)
					fout_csv.close()

				### PROC
				else:
					csvfile = csvfile_base + '_' + blockdata.title + '_proc.csv'
					if os.path.exists(csvfile)==False:
						fout_csv = open(csvfile,'a')
						table = 'PROC#' + ', ' + 'Processing'  + ', ' + 'Description' + '\n'
						fout_csv.write(table)
					else:
						fout_csv = open(csvfile,'a')
					proc_id += 1
					if blockdata.procs[index2].type[index3].strip().find('equal')!=-1:
						table = 'PROC.' + str(proc_id) + ', ' \
						+ blockdata.procs[index2].left[index3]  + ' = ' + blockdata.procs[index2].right[index3] + ', ' \
						+ '\n'
					else:
						table = 'PROC.' + str(proc_id) + ', ' \
						+ blockdata.procs[index2].left[index3]  + ', ' \
						+ blockdata.procs[index2].right[index3] + '\n'
					fout_csv.write(table)
					fout_csv.close()

	return
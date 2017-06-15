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

	sub_proc_flg = True
	if level_title == 'MAINPROCESS':
		sub_proc_flg = False

	if isinstance(funcname, list):
		funcname = ','.join(funcname)

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
	source_header += 'class else [shape = circle, color = gray];\n'
	source_header += 'class for [shape = flowchart.loopin];\n'
	source_header += 'class forend [shape = flowchart.loopout];\n'
	source_header += 'class while [shape = flowchart.loopin, color = lightblue];\n'
	source_header += 'class whileend [shape = flowchart.loopout, color = lightblue];\n'
	source_header += 'class switch [shape = diamond, color = lightblue];\n'
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

	if debug_out:
		print '<draw_diag> after ---------------------------------------- %s' % csvfile_base
		print '<draw_diag> block size : %d' % block_data_list.size()
		for index in range(0, block_data_list.size()):
			blockdata = block_data_list.blockdata[index]
			print '<draw_diag> [%d]%s(%s) %d' % ( index, blockdata.title, blockdata.type, blockdata.proc_size() )
			for index2 in range(0, blockdata.proc_size()):
				for index3 in range(0, len(blockdata.procs[index2].title) ):
					print '<draw_diag>   >>> <%s (%s)>[%s] %s --- %s' % ( \
						blockdata.title, \
						blockdata.type, \
						blockdata.procs[index2].type[index3], \
						blockdata.procs[index2].left[index3], \
						blockdata.procs[index2].right[index3] \
					)


#################### Create csv file of cond & proc ####################
	output_proc_to_csv(csvfile_base, block_data_list)


#################### CreaFte Block diag code ####################
# add main flow
	block_code, sub_proc_list, block_code_cond_list, skip_code_list = create_main_blocks(block_data_list, sub_proc_flg)

# add sub flow
	block_code += create_subproc_blocks(sub_proc_list)

# add condition flow
	for block_code_cond in block_code_cond_list:
		block_code += block_code_cond

# create source code if there is some process
	if block_code == '':
		source =''
	else:
		source = source_header
		source += block_code
		source += ' }'

	if debug_out:
		print '----------<%s>----------(BEFORE REPLACE RETURN)' % funcname
		print source


# skip "_returnonly" if only return in sub process 20170524
	for skip_code in skip_code_list:
		if debug_out:
			print 'skip: %s' % skip_code
		# remove "_returnonly" if only return in sub process (for if yes) 20170601
		if skip_code.find('<<REMOVE>>')!=-1:
			source = source.replace( skip_code.replace('<<REMOVE>>', ''), '' )
		else:
			source = source.replace(skip_code, '->')


#################### Draw Block diag (call blockdiag) ####################
	if debug_out:
		print '----------<%s>----------' % funcname
		print source

	if source != '':
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
			proc_right = proc_codes.proc_data_list[index1].right[index2]

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

						# add "_returnonly" if only return in sub process 20170524
						if index1+1 < proc_codes.get_proc_data_size():
							if  proc_codes.proc_data_list[index1+1].get_main_size()==1 \
							and proc_codes.proc_data_list[index1+1].type[0]=='return' \
							and proc_codes.proc_data_list[index1].title[index2]!=proc_codes.proc_data_list[index1+1].title[0]:
								if debug_out:
									print '<check_proc_codes> Skip only return in sub proc [%d/%d][%d/%d] %s (%d)' % ( \
										index1, proc_codes.get_proc_data_size(), \
										index2, proc_codes.proc_data_list[index1].get_main_size(), \
										block_data.title, \
										block_data.proc_size()
									)
								block_data.title = block_data.title + '_returnonly'

						if debug_out:
							print '<check_proc_codes> BLOCK(%s)' % block_data.title
							print '<check_proc_codes>  >>>[%d][%d] <%s (%s)> %s --- %s' % (\
							 index1, \
							 index2, \
							 proc_codes.proc_data_list[index1].title[index2], \
							 proc_codes.proc_data_list[index1].type[index2], \
							 proc_codes.proc_data_list[index1].left[index2], \
							 proc_codes.proc_data_list[index1].right[index2] \
							)

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
					print '<check_proc_codes> Skip sub proc[%d][%d] <%s (%s)> %s --- %s' % ( index1, index2, proc_title, proc_type, proc_left, proc_right )

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



def create_main_blocks(block_data_list, sub_proc_flg):
# [in] block_data_list : BlockDataList = List of [title, type, List of [ProcessData(title,type,left,right)] 
# [in] sub_proc_flg : False = Main, True = Sub
# [out] block_code : main block code
# [out] sub_proc_list :  sub block code
# [out] block_code_cond_list : if, elseif, else block code
# [out] skip_code_list

	if debug_out:
		print '<create_main_blocks> ----------------------------------------'
		print '<create_main_blocks> INPUT:blockdata x %d' % len(block_data_list.blockdata)
		for index in range( 0, len(block_data_list.blockdata) ):
			tmp_blockdata = block_data_list.blockdata[index]
			print '<create_main_blocks> INPUT: [%d] procdata x %d' % ( index, len(tmp_blockdata.procs) )
			for index2 in range( 0, len(tmp_blockdata.procs) ):
				tmp_procdata = tmp_blockdata.procs[index2]
				print '<create_main_blocks> INPUT: [%d][%d] proc x %d' % ( index, index2, tmp_procdata.get_main_size() )
				for index3 in range( 0, tmp_procdata.get_main_size() ):
					tmp_data = tmp_procdata.type[index3]
					print '<create_main_blocks> INPUT: [%d][%d] type = %s' % ( index, index2, tmp_data )


	block_code =''
	block_code_cond_list = []
	condition_if_prev = ''
	condition_if_parent = ''
	sub_proc_list = []
	return_flg = False
	skip_code_list = []
	if_no_end = ''
	return_only_flg = False

	# check if process includes return (at the deepest level(block layer=1)) 20170524
	#if len(block_data_list.blockdata)==1:
	if block_data_list.size()==1:
		tmp_blockdata = block_data_list.blockdata[0]
		for index2 in range( 0, len(tmp_blockdata.procs) ):
			tmp_procdata = tmp_blockdata.procs[index2]
			for index3 in range( 0, tmp_procdata.get_main_size() ):
				tmp_data = tmp_procdata.type[index3]
				if tmp_data=='return':
					return_flg = True
					break

# main flow
#	for index in range(0, len(block_data_list.blockdata)):
	for index in range(0, block_data_list.size()):

		# skip if only return 20170601
		blockdata = block_data_list.blockdata[index]
		if blockdata.proc_size()==1:
			if blockdata.proc_size()==1:
				if len(blockdata.procs[0].type)==1:
					if blockdata.procs[0].type[0]=='return':

						if debug_out:
							print '<create_main_blocks> RETURN: [%d][%d] type = %s' % ( index, index2, blockdata.procs[0].type[0] )

						if block_data_list.size()==1:
							return_only_flg = True
						break

		tmp_blockdata = block_data_list.blockdata[index]
		tmp_str = tmp_blockdata.title

		if debug_out:
			print '<create_main_blocks> Checking  %s' % tmp_str

		if tmp_str.find('_else')!=-1:
			block_code_cond_list += create_if_blocks('_else', tmp_str, condition_if_prev, condition_if_parent)
			condition_if_prev = ''
			condition_if_parent = ''

			# need to erase 'no->end' when there is else / else if 20170601
			if if_no_end != '':
				if_no_end = '<<REMOVE>>' + if_no_end
				skip_code_list.append(if_no_end)
				if_no_end = ''

		elif tmp_str.find('_elif')!=-1:
			block_code_cond_list += create_if_blocks('_elif', tmp_str, condition_if_prev, condition_if_parent)
			condition_if_prev = tmp_str

			# need to erase 'no->end' when there is else / else if 20170601
			if if_no_end != '':
				if_no_end = '<<REMOVE>>' + if_no_end
				skip_code_list.append(if_no_end)
				if_no_end = ''

		elif tmp_str.find('_if')!=-1:
			block_code_cond_list += create_if_blocks('_if', tmp_str, condition_if_prev, condition_if_parent)
			condition_if_prev = tmp_str
			condition_if_parent = tmp_str
			if_no_end = ''

			block_code += tmp_str
			block_code += ' -> '
			block_code += tmp_str.replace('_if', '_yes_pt')
			block_code += ';\n'

			# skip "_returnonly" if only return in sub process (for if yes) 20170601
			tmptmp_str = tmp_str.replace('_if','')
			if_return_flg = False
			tmp_skip_code_next = ''
			for tmptmp_blockdata in block_data_list.blockdata:
				if tmptmp_blockdata.title.find(tmptmp_str)==0 \
				and tmptmp_blockdata.title.find('_returnonly')!=-1:
					if_return_flg = True
					tmp_skip_code_next = tmptmp_blockdata.title
					break
			if if_return_flg:
				# if_yes->END
				block_code += tmp_str.replace('_if', '_yes_pt')
				block_code += ' -> END'
				block_code += ';\n'
				# if->if_no
				block_code += tmp_str
				block_code += ' -> '
				block_code += tmp_str.replace('_if', '_no_pt')
				block_code += ';\n'
				block_code += tmp_str.replace('_if', '_no_pt') + '[label = "No"];\n'

				# if_no -> if_end
				# need to erase 'no->end' when there is else / else if
				if_no_end = tmp_str.replace('_if', '_no_pt')
				if_no_end += ' -> '
				if_no_end += tmp_str.replace('_if', '_end_pt')
				if_no_end += ';\n'
				block_code += if_no_end

				# if_end ->
				block_code += tmp_str.replace('_if', '_end_pt')
				block_code += ' -> '

				tmp_skip_code = '<<REMOVE>>'
				tmp_skip_code += tmp_str.replace('_if', '_yes_pt')
				tmp_skip_code += ' -> ' + tmp_skip_code_next
				tmp_skip_code += '_subproc'
				tmp_skip_code += ' -> '
				tmp_skip_code += tmp_str.replace('_if', '_end_pt')
				tmp_skip_code += ';\n'
				skip_code_list.append(tmp_skip_code)

			else:
				# if_end ->
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

				# skip "_returnonly" if only return in sub process 20170524
				if tmp_str.find('_returnonly')!=-1:

					# replace "-> XXX_subproc ->"" to "->" (output skip code and replace after whole process)
					tmp_skip_code = tmp_str
					tmp_skip_code += '_subproc'
					tmp_skip_code = '-> ' + tmp_skip_code + ' ->'
					skip_code_list.append(tmp_skip_code)

					# replace "XXX_end_pt -> PARENT_end_pt" to "XXX_end_pt -> END"
					tmp_end = tmp_str[:tmp_str.find('_')]
					tmp_end += '_end_pt'
					for index_rep in range( 0, len(block_code_cond_list) ):
						tmp_code_cond = block_code_cond_list[index_rep]
						if tmp_code_cond.find(tmp_end)!=-1:
							tmp_end_code = tmp_code_cond[tmp_code_cond.find(tmp_end):]
							tmp_end_code = tmp_end_code[:tmp_end_code.find(';',1)]
							tmp_end_code_replace = tmp_end + ' -> END'
							tmp_code_cond_replace = tmp_code_cond.replace(tmp_end_code, tmp_end_code_replace)
							block_code_cond_list[index_rep] = tmp_code_cond_replace
							break


	if not return_only_flg:
		if sub_proc_flg:
			if return_flg:
				block_code += 'END;\n'
			else:
				block_code += 'NEXT;\n'
		else:
			block_code += 'END;\n'

	return block_code, sub_proc_list, block_code_cond_list, skip_code_list



def create_if_blocks(condition_str, code, condition_prev, condition_if_parent):
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
		# connect to end_pt of original parent condition 20170524
		#block_code_cond += condition_prev.replace(parent_condition, '_end_pt')
		block_code_cond += condition_if_parent.replace('_if', '_end_pt')
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

	if debug_out:
		print '<create_if_blocks>'
		for tmp_code_cond in block_code_cond_list:
			print '\t(cond) %s' % tmp_code_cond

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
	csvfile = ''
	proc_id = 0
	cond_id = 0
	cond_level = 0
	tmp_cond_code = ''
	tmp_cond_code_list = []
	tmp_cond_whole = ''
	tmp_bracket_cnt = 0
	arg_id = 0
	is_equal_seq = False

	tmp_files = glob.glob(csvfile_base+'*.csv')
	for tmp_file in tmp_files:
		os.remove(tmp_file)

	for index in range(0, block_data_list.size()):
		blockdata = block_data_list.blockdata[index]
		for index2 in range(0, blockdata.proc_size()):


			for index3 in range(0, len(blockdata.procs[index2].title) ):

				# break if only return 20170524
				if blockdata.proc_size()==1:
					if blockdata.procs[index2].type[index3].strip()=='return':
						break

##### COND
				if func_source_analyze.is_ctrl_stat( blockdata.procs[index2].type[index3].strip() ):
					if index2==0:
						if debug_out:
							print '<output_proc_to_csv> END of COND(1)'
						continue

					else:
						csvfile = csvfile_base + '_' + blockdata.title + '_cond.csv'
						if os.path.exists(csvfile)==False:
							fout_csv = open(csvfile,'a')

							# COND format
							table = \
								  'COND#' + ', ' \
								+ 'Data'  + ', ' \
								+ 'Condition' + \
								'\n'
							fout_csv.write(table)

							tmp_cond_code = ''
							del tmp_cond_code_list[:]
							tmp_cond_whole = ''
							tmp_bracket_cnt = 0

						else:
							fout_csv = open(csvfile,'a')

						# Check bracket level in Condition 20170613
						cond_level += blockdata.procs[index2].left[index3].count('(')
						cond_level -= blockdata.procs[index2].left[index3].count(')')
						if cond_level < 0 and blockdata.procs[index2].left[index3].strip()==')':
							if debug_out:
								print '<output_proc_to_csv> END of COND(2)'
						else:
							tmp_cond_code += blockdata.procs[index2].left[index3]

						if debug_out:
							print '<output_proc_to_csv> [%d] %s' % (cond_level, tmp_cond_code)

						# Divide condition code by ';','&&','||' 20170613
						if cond_level < 0:
							tmp_cond_code_list = devide_by_condition_div_symbol(tmp_cond_code)
							for tmp_code in tmp_cond_code_list:
								if is_condition_div_symbol(tmp_code):
									tmp_cond_whole += ' ' + tmp_code + ' '
								else:
									cond_id += 1
									table = 'COND.' + str(cond_id) + ', ' \

									# Create total condition expression(1) 
									tmp_bracket_check = tmp_code.strip()
									while tmp_bracket_check.find('(')==0:
										tmp_bracket_check = tmp_bracket_check[1:]
										tmp_cond_whole += '('
									tmp_cond_whole += 'COND.' + str(cond_id)

									# erase top bracket (and corresponding end bracket)
									tmp_right = tmp_code.strip()
									while tmp_right.find('(')==0:
										tmp_right = tmp_right[1:]
										tmp_bracket_cnt += 1
									while tmp_right.rfind(')')==len(tmp_right)-1:
										if tmp_right.count('(') - tmp_right.count(')')==0:
											break
										else:
											tmp_right = tmp_right[:len(tmp_right)-1]
											tmp_bracket_cnt -= 1

									# extract condition data
									tmp_code_item = devide_by_condition_symbol(tmp_code)
									if isinstance(tmp_code_item,list):
										if len(tmp_code_item)==3: #Should be 3 (A symbol, B) or 1(A)
											tmp_left = tmp_code_item[0].strip()
											while tmp_left.find('(')==0:
												tmp_left = tmp_left[1:]
											table += tmp_left + ', ' \
												  + tmp_right \
												  + '\n'
										else:
											table += '' + ', ' \
												  + tmp_right \
												  + '\n'
									else:
										table += 'ERROR?' + ', ' \
											  + tmp_right \
											  + '\n'
									fout_csv.write(table)

									# Create total condition expression(2) 
									tmp_bracket_check = tmp_code.strip()
									while tmp_bracket_check.rfind(')')==len(tmp_bracket_check)-1:
										tmp_bracket_check = tmp_bracket_check[:len(tmp_bracket_check)-1]
										tmp_cond_whole += ')'


							tmp_cond_code = ''
							cond_level = 0


						if tmp_cond_whole!='':
							table = \
								  'TOTAL' + ', ' \
								+ tmp_cond_whole  + ', ' \
								+ '' + \
								'\n'
							fout_csv.write(table)
						fout_csv.close()














##### subproc
				elif blockdata.procs[index2].type[index3].strip()=='subproc':
					continue

##### func
				elif blockdata.procs[index2].type[index3].strip().find('func')!=-1:
					csvfile = csvfile_base + '_' + blockdata.title + '_proc.csv'
					if os.path.exists(csvfile)==False:
						fout_csv = open(csvfile,'a')

						# PROC format (FUNC)
						table = \
							  'PROC#' + ', ' \
							+ 'Processing' + ', ' \
							+ '(Argument)'  + ', ' \
							+ 'Description' \
							+ '\n'

						fout_csv.write(table)
					else:
						fout_csv = open(csvfile,'a')

					#########
					if blockdata.procs[index2].type[index3].strip().find('<start>')!=-1:
						proc_id += 1
						arg_id = 0

						# PROC output (FUNC)
						table = \
							'PROC.' + str(proc_id) + ', ' \
							+ blockdata.procs[index2].left[index3] + ')' + blockdata.procs[index2].right[index3] + ',' \
							+ 'see below' + ', '\
							+ 'TBD' \
							+ '\n'

						if blockdata.procs[index2].left[index3].find('=')!=-1:
							func_name = blockdata.procs[index2].left[index3][blockdata.procs[index2].left[index3].find('='):blockdata.procs[index2].left[index3].find('(')]
							func_name = func_name.strip()
						else:
							func_name = blockdata.procs[index2].left[index3][:blockdata.procs[index2].left[index3].find('(')]
							func_name = func_name.strip()

						if debug_out:
							print '<output_proc_to_csv> func name : %s' % func_name

					elif blockdata.procs[index2].type[index3].strip().find('<end>')!=-1:
						continue
					else:
						arg_id += 1

						# PROC output (FUNC-ARG)
						table = \
							  ' ' + ', ' \
							+ '[arg.' + str(arg_id) + ']' + ', ' \
							+ blockdata.procs[index2].left[index3].replace(',', '') + blockdata.procs[index2].right[index3] + ' ,' \
							+ 'TBD' \
							+ '\n'

					#########
					fout_csv.write(table)
					fout_csv.close()

##### PROC
				else:
					csvfile = csvfile_base + '_' + blockdata.title + '_proc.csv'
					if os.path.exists(csvfile)==False:
						fout_csv = open(csvfile,'a')

						# PROC format
						table = \
							  'PROC#' + ', ' \
							+ 'Processing'  + ', ' \
							+ '(Argument)'  + ', ' \
							+ 'Description' \
							+ '\n'

						fout_csv.write(table)
					else:
						fout_csv = open(csvfile,'a')
					proc_id += 1


					if blockdata.procs[index2].type[index3].strip().find('equal<start>')!=-1:
						is_equal_seq = True
						table = \
							  'PROC.' + str(proc_id) + ', ' \
							+ blockdata.procs[index2].left[index3] + '' + blockdata.procs[index2].right[index3] + ', '\
							+ '(NA)' + ', '\
							+ 'TBD' \
							+ '\n'
					elif blockdata.procs[index2].type[index3].strip().find('equal<end>')!=-1:
						is_equal_seq = False
						table = \
							  '' + ', ' \
							+ blockdata.procs[index2].left[index3] + '' + blockdata.procs[index2].right[index3] + ', ' \
							+ '' + ', '\
							+ '' \
							+ '\n'

					elif blockdata.procs[index2].type[index3].strip().find('equal')!=-1:
						# PROC output
						if is_equal_seq:
							table = \
								  '' + ', ' \
								+ blockdata.procs[index2].left[index3] + '' + blockdata.procs[index2].right[index3] + ', ' \
								+ '' + ', '\
								+ '' \
								+ '\n'
						else:
							table = \
								  'PROC.' + str(proc_id) + ', ' \
								+ blockdata.procs[index2].left[index3]  + ' = ' + blockdata.procs[index2].right[index3] + ', ' \
								+ '(NA)' + ', '\
								+ 'TBD' \
								+ '\n'

					else:

						# COND output
						table = \
							  'PROC.' + str(proc_id) + ', ' \
							+ blockdata.procs[index2].left[index3]  + ', ' \
							+ blockdata.procs[index2].right[index3] \
							+ '\n'

					fout_csv.write(table)
					fout_csv.close()

	return


def is_condition_div_symbol(code):
	bret = False
	if code.strip()==';' \
	or code.strip()=='&&' \
	or code.strip()=='||':
#	or code.strip()=='==' \
#	or code.strip()=='<' \
#	or code.strip()=='<=' \
#	or code.strip()=='>' \
#	or code.strip()=='>=':
		bret = True
	return bret


def devide_by_condition_div_symbol(code):
	code_list = []
	tmp_code = code.replace(' ', '')
	tmp_code = tmp_code.replace(';', '$$;$$')
	tmp_code = tmp_code.replace('&&', '$$&&$$')
	tmp_code = tmp_code.replace('||', '$$||$$')
	code_list = tmp_code.split('$$')
	return code_list

def devide_by_condition_symbol(code):
	code_list = []
	tmp_code = code.replace(' ', '')
	if tmp_code.find('=')!=-1:
		if tmp_code.find('==')!=-1:
			tmp_code = tmp_code.replace('==', '$$==$$')
		elif tmp_code.find('<=')!=-1:
			tmp_code = tmp_code.replace('<=', '$$<=$$')
		elif tmp_code.find('>=')!=-1:
			tmp_code = tmp_code.replace('>=', '$$>=$$')
		else:
			tmp_code = tmp_code.replace('=', '$$=$$')
	else:
		if tmp_code.find('<')!=-1:
			tmp_code = tmp_code.replace('<', '$$<$$')
		if tmp_code.find('>')!=-1:
			tmp_code = tmp_code.replace('>', '$$>$$')
	code_list = tmp_code.split('$$')
	return code_list



def output_func_def_to_csv(sourcefilename, func_list, deftype):
# [in] sourcefilename : C source file name(str)
# [in] func_list : FunctionList
# [in] deftype : arg, ret
	csvfile_base = ''	
	if len(sourcefilename)>1:
		if os.path.exists(sourcefilename[0] + '\\csv')==False:
			os.makedirs(sourcefilename[0] + '\\csv')
		csvfile_base = sourcefilename[0] + '\\csv\\' + sourcefilename[1]
	else:
		if os.path.exists('\\csv')==False:
			os.makedirs('\\csv')
		csvfile_base = '\\csv\\' + sourcefilename[0]
	csvfile_base = csvfile_base[0:csvfile_base.rfind('.')] + '_'

	tmp_files = glob.glob(csvfile_base+'*_' + deftype + '.csv')
	for tmp_file in tmp_files:
		os.remove(tmp_file)

	for index1 in range(0, func_list.func_num):
		funcname = func_list.function_data[index1].name

		if isinstance(funcname, list):
			funcname = ','.join(funcname)

		csvfile = csvfile_base + funcname + '_' + deftype + '.csv'

		fout_csv = open(csvfile,'a')

# header
		table = \
		  'Parameter' + ', ' \
		+ 'Unit'  + ', ' \
		+ 'Default' + ', ' \
		+ 'LSB' + ', ' \
		+ 'Type' + ', ' \
		+ 'Offset' + ', ' \
		+ 'Range' + ', ' \
		+ 'Description' \
		+ '\n'

		fout_csv.write(table)


		fout_csv = open(csvfile,'a')
		table = ''
# argument
		if deftype=='arg':
			if debug_out:
				print '<output_func_def_to_csv> arg num : %d' % func_list.function_data[index1].argument_num

			if func_list.function_data[index1].argument_num!=0:
				for index2 in range(0, func_list.function_data[index1].argument_num):
					param_type = func_list.function_data[index1].argument_list[index2].type
					param_name = func_list.function_data[index1].argument_list[index2].name
					table += \
					  param_name + ', ' \
					+ ' '  + ', ' \
					+ ' ' + ', ' \
					+ ' ' + ', ' \
					+ param_type + ', ' \
					+ ' ' + ', ' \
					+ ' ' \
					+ '\n'
			else:
				table += \
				  '(none)' + ', ' \
				+ ' '  + ', ' \
				+ ' ' + ', ' \
				+ ' ' + ', ' \
				+ ' ' + ', ' \
				+ ' ' + ', ' \
				+ ' ' \
				+ '\n'

# return value
		if deftype=='ret':
			param_type = func_list.function_data[index1].return_type
			table = \
			  '(value)' + ', ' \
			+ ' '  + ', ' \
			+ ' ' + ', ' \
			+ ' ' + ', ' \
			+ param_type + ', ' \
			+ ' ' + ', ' \
			+ ' ' \
			+ '\n'

		fout_csv.write(table)

	return


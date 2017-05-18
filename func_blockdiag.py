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
import re

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

def draw_diag(sourcefilename, funcname, proc_codes, level_title):
# [in] funcname : FunctionList.FunctionData.name (str)
# [in] proc_codes : FunctionList.FunctionData.process_code_list (ProcessCodes)
	outfile = ''
	if len(sourcefilename)>1:
		outfile = sourcefilename[0] + '\\figs\\' + sourcefilename[1]
	else:
		outfile = '\\figs\\' + sourcefilename[0]
	outfile = outfile[0:outfile.rfind('.')] + '_' + funcname + '_' + level_title +'.png'

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
	block_data_list = check_proc_codes(proc_codes, level_title)

	if debug_out:
		print '<draw_diag>----------------------------------------'
		print block_data_list.size()
		for index in range(0, block_data_list.size()):
			blockdata = block_data_list.blockdata[index]
			print '[%d]%s(%s) %d' % ( index, blockdata.title, blockdata.type, blockdata.proc_size() )


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

	tree = parser.parse_string(source) 
	diagram = builder.ScreenNodeBuilder.build(tree) 
	draw = drawer.DiagramDraw('PNG', diagram, filename=outfile) 
	draw.draw() 
	draw.save() 


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
			tmp_proc_title = proc_title
			tmp_proc_title = tmp_proc_title[:tmp_proc_title.find('(')]
			if tmp_proc_title==level_title:

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
						block_data.procs.append(proc_codes.proc_data_list[index1])

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
						block_data.procs.append(proc_codes.proc_data_list[index1])

				# level title is not chaged
				else:
					block_data.procs.append(proc_codes.proc_data_list[index1])
					if debug_out:
						print '<check_proc_codes> No diagram'

#### SUB process
			else:
				if debug_out:
					print '<check_proc_codes> Skip sub proc'

	if block_data.proc_size() != 0:
		block_data_list.blockdata.append(copy.deepcopy(block_data))

	return block_data_list


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

			print '[prev] %s(lv%d) -> [curr] %s(lv%d) (proc %d)(cond %d)' % (proc_title, tmp_level_prev, tmp_proc_title, tmp_level, proc_id, cond_proc_id)
			if proc_title != tmp_proc_title:
				proc_title = tmp_proc_title
				if tmp_level==target_level:

					if tmp_level_prev==tmp_level \
					and cond_proc_id != 0 \
					and proc_id == cond_proc_id \
					and proc_title.count(top_title)==1:
						print '[header] skip',
					else:
						header_title = proc_title
						header_list.append(header_title)
						block_flag = True
						block_num += 1
						print '[header] %s(%d)' % (header_title, block_num)

				else:
					if tmp_level_prev < tmp_level:
						header_title +=	proc_title
						print '[header] %s' % (header_title)

		# copy sub process
		else:
#			print	proc_codes.main[index1], 
			print	proc_codes.title[index1], 
#			print	proc_codes.level[index1], 
#			print	proc_codes.id[index1],
			print	proc_codes.proc_data_list[index1].get_main_size()
			out_proc_codes.append_code( \
				proc_codes.main[index1], \
				proc_codes.title[index1], \
				proc_codes.level[index1], \
				proc_codes.id[index1], \
			)
			tmp_proc_data.clear() 
			for index2 in range(0,proc_codes.proc_data_list[index1].get_main_size()):
				if proc_codes.proc_data_list[index1].title[index2].find(level_title)==-1:
#					print	' -> %s' % proc_codes.proc_data_list[index1].title[index2],
#					print	' -> %s' % proc_codes.proc_data_list[index1].type[index2],
#					print	' -> %s' % proc_codes.proc_data_list[index1].left[index2],
#					print	' -> %s' % proc_codes.proc_data_list[index1].right[index2] 

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
				print '[saved 1] %s(%d)' % (header_list[len(header_list)-2], out_proc_codes.get_main_size() )
				out_proc_codes.clear()
			else:
				print 'erase:%s' % header_list[len(header_list)-2]
				header_list.pop(len(header_list)-2)
			block_flag = False

	# save sub proc
	if out_proc_codes.get_main_size()!=0:
		out_proc_codes_list.append( copy.deepcopy(out_proc_codes) )
		print '[saved 2] %s(%d)' % (header_list[-1], out_proc_codes.get_main_size() )
	else:
		if len(header_list)>0:
			header_list.pop()

	return out_proc_codes_list, header_list
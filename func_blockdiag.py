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
		self.procs = [] #ProcessData
	def proc_size(self):
		return len(self.procs)
	def clear(self):
		self.title = ''
		del self.procs[:]
		return


def draw_diag(sourcefilename, funcname, proc_codes):
# [in] funcname : FunctionList.FunctionData.name (str)
# [in] proc_codes : FunctionList.FunctionData.process_code_list (ProcessCodes)

	outfile = ''
	if len(sourcefilename)>1:
		outfile = sourcefilename[0] + '\\figs\\' + sourcefilename[1]
	else:
		outfile = '\\figs\\' + sourcefilename[0]
	outfile = outfile[0:outfile.rfind('.')] + '_' + funcname + '.png'

	source = ' \
	blockdiag { \
		orientation = portrait; \
		plugin autoclass; \
		class if [shape = diamond]; \
		class pt [shape = minidiamond]; \
		class state [color = pink]; \
		START -> \
	'

	proc_id = 0
	cond_id = 0
	block_data_list = BlockDataList()
	block_data = BlockData()
	block_list = []
	current_title = ''


	for index1 in range(0, proc_codes.get_proc_data_size()):
		for index2 in range(0,proc_codes.proc_data_list[index1].get_main_size()):

			proc_title = proc_codes.proc_data_list[index1].title[index2]

			if proc_title.find('MAINPROCESS')!=-1:
				if proc_title != current_title:
					if func_source_analyze.is_ctrl_stat(proc_codes.proc_data_list[index1].type[index2])==True:
						cond_id += 1
						if block_data.proc_size() != 0:
							block_data_list.blockdata.append(copy.deepcopy(block_data))
						block_data.clear()

						current_title = proc_title
						block_data.title = 'COND%d_if' % cond_id
						block_data.procs.append(proc_codes.proc_data_list[index1])
						print block_data.title
						block_data.procs.append(proc_codes.proc_data_list[index1])

					else:
						if block_data.proc_size() != 0:
							block_data_list.blockdata.append(copy.deepcopy(block_data))
						block_data.clear()
						current_title = proc_title
						block_data.title = current_title
						block_data.title = block_data.title.replace('PROCESS', '')
						block_data.title = block_data.title.replace('(', '')
						block_data.title = block_data.title.replace(')', '')
						print block_data.title
						block_data.procs.append(proc_codes.proc_data_list[index1])

				else:
					block_data.procs.append(proc_codes.proc_data_list[index1])
					print '<draw_diag> No diagram'
			else:
				print '<draw_diag> Skip sub proc'

	if block_data.proc_size() != 0:
		block_data_list.blockdata.append(copy.deepcopy(block_data))

	print block_data_list.size()


	block_code =''
	for tmp_blockdata in block_data_list.blockdata:
		tmp_str = tmp_blockdata.title
		print tmp_str
		block_code += tmp_str
		block_code += ' -> '
	block_code += 'END;'

	source += block_code

#					if proc_codes.proc_data_list[index1].type[index2].find('???')!=-1:
#						proc_id += 1
#					elif proc_codes.proc_data_list[index1].type[index2].find('proc')!=-1:
#						proc_id += 1
#					elif proc_codes.proc_data_list[index1].type[index2].find('equal')!=-1:
#						proc_id += 1
#					elif proc_codes.proc_data_list[index1].type[index2].find('func')!=-1:
#						proc_id += 1

	source += ' }'
	print source


#	source = ' \
#	blockdiag { \
#		orientation = portrait; \
#		plugin autoclass; \
#		class if [shape = diamond]; \
#		class pt [shape = minidiamond]; \
#		class state [color = pink]; \
#		START -> \
#		A -> B -> C_if -> if(1), if2, if3, if4; \
#			if1 ->a -> a1 -> D_if; \
#			if2 -> b1 -> D_if; \
#			if3 -> c1 -> D_if; \
#			if4 -> error_state; \
#		D_if -> E_state, F_state; \
#		if1[label = "if(cond 1)"]; \
#		if2[label = "elif(cond 2)"]; \
#		if3[label = "elif(cond 3)"]; \
#		if4[label = "else"]; \
#	} \
#	'

	tree = parser.parse_string(source) 
	diagram = builder.ScreenNodeBuilder.build(tree) 
	draw = drawer.DiagramDraw('PNG', diagram, filename=outfile) 
	draw.draw() 
	draw.save() 

	return

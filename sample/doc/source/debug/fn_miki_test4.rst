==================
fn_miki_test4
==================


+++++++++++++++++++
Interface
+++++++++++++++++++

.. list-table:: Arguments
   :header-rows: 1
   :widths: 40, 5, 10, 5, 10, 10, 10, 10

   * - Parameter
     - Unit
     - Default
     - LSB
     - Type
     - Offset
     - Range
     - Description
   * - arg1
     - 
     - 
     - 
     - type1
     - 
     - 
     - 
   * - arg2
     - 
     - 
     - 
     - type2
     - 
     - 
     - 


-----------------------------

.. list-table:: Return Value
   :header-rows: 1
   :widths: 40, 5, 10, 5, 10, 10, 10, 10

   * - Parameter
     - Unit
     - Default
     - LSB
     - Type
     - Offset
     - Range
     - Description
   * - (value)
     - 
     - 
     - 
     - VD
     - 
     - 
     - 


-----------------------------

+++++++++++++++++++
Main Process Flow
+++++++++++++++++++

.. blockdiag::

   blockdiag {
   orientation = portrait;
   plugin autoclass;
   span_width = 24;
   span_height = 20;
   height = 200;
   class if [shape = diamond];
   class elif [shape = diamond];
   class else [shape = circle, color = gray];
   class for [shape = flowchart.loopin];
   class forend [shape = flowchart.loopout];
   class while [shape = flowchart.loopin, color = lightblue];
   class whileend [shape = flowchart.loopout, color = lightblue];
   class switch [shape = diamond, color = lightblue];
   class pt [shape = minidiamond];
   class subproc [color = pink];
   START -> IF1_if -> IF1_yes_pt;
   IF1_end_pt -> MAIN2 -> MAIN3 -> SWITCH3_switch;
   SWITCH3_end_pt -> WHILELOOP4_while;
   WHILELOOP4_END_whileend -> IF5_if -> IF5_yes_pt;
   IF5_end_pt -> IF6_if -> IF6_yes_pt;
   IF6_end_pt -> IF8_if -> IF8_yes_pt;
   IF8_end_pt -> FORLOOP11_for;
   FORLOOP11_END_forend -> END;
   IF1_yes_pt -> IF1_SUB1_subproc -> IF1_end_pt;
   SWITCH3_switch -> SWITCH3_SUB1_subproc -> SWITCH3_end_pt;
   WHILELOOP4_while -> WHILELOOP4_SUB1_subproc -> WHILELOOP4_END_whileend;
   IF5_yes_pt -> IF5_SUB1_subproc -> IF5_end_pt;
   IF6_yes_pt -> IF6_SUB1_subproc -> IF6_end_pt;
   ELSE7_else -> ELSE7_SUB1_subproc -> ELSE7_end_pt;
   IF8_yes_pt -> IF8_SUB1_subproc -> IF8_end_pt;
   ELIF9_yes_pt -> ELIF9_SUB1_subproc -> ELIF9_end_pt;
   ELSE10_else -> ELSE10_SUB1_subproc -> ELSE10_end_pt;
   FORLOOP11_for -> FORLOOP11_SUB1_subproc -> FORLOOP11_END_forend;
   IF1_if -> IF1_yes_pt;
   IF1_yes_pt[label = "yes"];
   IF5_if -> IF5_yes_pt;
   IF5_yes_pt[label = "yes"];
   IF6_if -> IF6_yes_pt;
   IF6_yes_pt[label = "yes"];
   IF6_if -> IF6_no_pt -> ELSE7_else;
   ELSE7_end_pt -> IF6_end_pt;
   IF6_no_pt[label = "No"];
   IF8_if -> IF8_yes_pt;
   IF8_yes_pt[label = "yes"];
   IF8_if -> IF8_no_pt -> ELIF9_elif;
   ELIF9_end_pt -> IF8_end_pt;
   IF8_no_pt[label = "No"];
   ELIF9_elif -> ELIF9_yes_pt;
   ELIF9_yes_pt[label = "yes"];
   ELIF9_elif -> ELIF9_no_pt -> ELSE10_else;
   ELSE10_end_pt -> IF8_end_pt;
   ELIF9_no_pt[label = "No"];
    }

+++++++++++++++++++
Process Table
+++++++++++++++++++

.. list-table:: MAIN2
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.1
     - S4 s4_t_lp_normal;
     - 
     - TBD
   * - PROC.2
     - FL fl_t_thd_exobj_range;
     - 
     - TBD
   * - PROC.3
     - FL fl_t_thd_exobj_power;
     - 
     - TBD
   * - PROC.4
     - FL fl_t_obj_power;
     - 
     - TBD
   * - PROC.5
     - FL fl_t_abs_robs;
     - 
     - TBD
   * - PROC.6
     - FL fl_t_abs_vobs;
     - 
     - TBD
   * - const FL CFL_D_MAP_EXOBJ_POWER[CU2_MAP_EXOBJ_POWER_INDEX][2] =
     - see below
     - 
     - 


-----------------------------

.. list-table:: MAIN3
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.8
     - miki2_1 = subsub_1()
     - see below
     - TBD
   * - 
     - [arg.1]
     - (S4)arg2_1_1
     - TBD
   * - PROC.9
     - miki2_2 = subsub_2()
     - see below
     - TBD
   * - 
     - [arg.1]
     - (S1)arg2_2_1
     - TBD
   * - PROC.10
     - miki2_3 = subsub_3()
     - see below
     - TBD
   * - 
     - [arg.1]
     - (S1)arg2_3_1
     - TBD
   * - 
     - [arg.2]
     - arg2_3_2
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

.. list-table:: ELIF9
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.7
     - lv1_2
     - lv1_2==12
   * - TOTAL
     - COND.7
     - 


-----------------------------

.. list-table:: FORLOOP11
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.8
     - i
     - i=(S4)0
   * - COND.9
     - i
     - i<(S4)n
   * - COND.10
     - 
     - i++
   * - TOTAL
     - COND.8 ; COND.9 ; COND.10
     - 


-----------------------------

.. list-table:: IF1
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.1
     - test2
     - test2==1
   * - TOTAL
     - COND.1
     - 


-----------------------------

.. list-table:: IF5
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.4
     - test1
     - test1==1
   * - TOTAL
     - COND.4
     - 


-----------------------------

.. list-table:: IF6
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.5
     - test2
     - test2==1
   * - TOTAL
     - COND.5
     - 


-----------------------------

.. list-table:: IF8
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.6
     - lv1_1
     - lv1_1==11
   * - TOTAL
     - COND.6
     - 


-----------------------------

.. list-table:: SWITCH3
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.2
     - 
     - hogehoge3_2
   * - TOTAL
     - COND.2
     - 


-----------------------------

.. list-table:: WHILELOOP4
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.3
     - test1
     - test1==1
   * - TOTAL
     - COND.3
     - 


-----------------------------

+++++++++++++++++++
Subprocesses
+++++++++++++++++++

.. toctree::   :maxdepth: 1

   fn_miki_test4_ELIF9_SUBPROCESS

   fn_miki_test4_ELSE10_SUBPROCESS

   fn_miki_test4_ELSE7_SUBPROCESS

   fn_miki_test4_FORLOOP11_SUBPROCESS

   fn_miki_test4_IF1_SUBPROCESS

   fn_miki_test4_IF5_SUBPROCESS

   fn_miki_test4_IF6_SUBPROCESS

   fn_miki_test4_IF8_SUBPROCESS

   fn_miki_test4_MAIN2_SUBPROCESS

   fn_miki_test4_SWITCH3_SUBPROCESS

   fn_miki_test4_WHILELOOP4_SUBPROCESS



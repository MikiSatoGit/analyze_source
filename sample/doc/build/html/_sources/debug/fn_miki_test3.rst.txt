==================
fn_miki_test3
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
   START -> MAIN1 -> FORLOOP1_for;
   FORLOOP1_END_forend -> IF2_if -> IF2_yes_pt;
   IF2_end_pt -> SWITCH3_switch;
   SWITCH3_end_pt -> IF4_if -> IF4_yes_pt;
   IF4_end_pt -> MAIN5 -> IF5_if -> IF5_yes_pt;
   IF5_end_pt -> MAIN6 -> END;
   FORLOOP1_for -> FORLOOP1_SUB1_subproc -> FORLOOP1_END_forend;
   IF2_yes_pt -> IF2_SUB1_subproc -> IF2_end_pt;
   SWITCH3_switch -> SWITCH3_SUB1_subproc -> SWITCH3_end_pt;
   IF4_yes_pt -> IF4_SUB1_subproc -> IF4_end_pt;
   IF5_yes_pt -> IF5_SUB1_subproc -> IF5_end_pt;
   IF2_if -> IF2_yes_pt;
   IF2_yes_pt[label = "yes"];
   IF4_if -> IF4_yes_pt;
   IF4_yes_pt[label = "yes"];
   IF5_if -> IF5_yes_pt;
   IF5_yes_pt[label = "yes"];
    }

+++++++++++++++++++
Process Table
+++++++++++++++++++

.. list-table:: MAIN1
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.1
     - miki2_1 = subsub_1()
     - see below
     - TBD
   * - 
     - [arg.1]
     - (S1)arg2_1_1
     - TBD
   * - 
     - [arg.2]
     - arg2_1_2
     - TBD
   * - PROC.2
     - miki2_2 = subsub_2()
     - see below
     - TBD
   * - 
     - [arg.1]
     - (S1)arg2_2_1
     - TBD
   * - 
     - [arg.2]
     - arg2_2_2
     - TBD
   * - PROC.3
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

.. list-table:: MAIN5
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.4
     - fl_t_tmp_theta = -(
     - 
     - TBD
   * - 
     - PI / 180.0F * (
     - 
     - TBD
   * - 
     - miki6_1[0] + miki6_2[s4_t_lp_i] +  (FL)START_ANG
     - 
     - TBD
   * - 
     - )
     - 
     - TBD
   * - 
     - );
     - 
     - TBD


-----------------------------

.. list-table:: MAIN6
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.9
     - miki7_1[num - 1 - i][k] = (
     - 
     - TBD
   * - 
     - 0.5F * fl_abs(miki7_2[up - 1 - i] - miki7_3[k])) + (1.0F * fl_abs((FL)(miki7_4[num - 1 - i] - miki7_5[k]))) + (1.0F * fl_abs((FL)(miki7_6[num - 1 - i] - miki7_7[k] - (FL)t))
     - 
     - TBD
   * - 
     - );
     - 
     - TBD
   * - PROC.12
     - tmp_comp = fl_abs()
     - see below
     - TBD
   * - 
     - [arg.1]
     - miki8_1[k][0]-miki8_2[0][8]) + fl_abs(miki8_3[k][1]-miki8_4[0][7]
     - TBD
   * - PROC.13
     - tmp_comp = fl_abs()
     - see below
     - TBD
   * - 
     - [arg.1]
     - miki9_1[k][0]-miki9_2[0][8]) + fl_abs(miki9_3[k][1]-miki9_4[0][7]
     - TBD
   * - PROC.14
     - return;
     - 
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

.. list-table:: FORLOOP1
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.1
     - i
     - i=(S4)0
   * - COND.2
     - i
     - i<(S4)n
   * - COND.3
     - 
     - i++
   * - TOTAL
     - COND.1 ; COND.2 ; COND.3
     - 


-----------------------------

.. list-table:: IF2
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.4
     - A1
     - A1==(S4)a1
   * - COND.5
     - B1
     - B1==(FL)b1
   * - COND.6
     - B2
     - B2==(FL)b3
   * - COND.7
     - C1
     - C1>c1()
   * - COND.8
     - C2()
     - C2()>c2
   * - COND.9
     - C3
     - C3>(S4)c3()
   * - COND.10
     - D1
     - D1<d1
   * - COND.11
     - D2
     - D2<d2
   * - COND.12
     - D3
     - D3>=d3
   * - COND.13
     - D4
     - D4>=d4
   * - TOTAL
     - COND.4 || (COND.5 && COND.6) || (COND.7) && COND.8 && COND.9)) && ((COND.10 && COND.11) || (COND.12 && COND.13))
     - 


-----------------------------

.. list-table:: IF4
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.15
     - hoge(a1 / a2)
     - hoge(a1 / a2)!=0
   * - TOTAL
     - COND.15
     - 


-----------------------------

.. list-table:: IF5
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.16
     - fl_abs(miki6_3[i]-miki6_4[k])
     - fl_abs(miki6_3[i]-miki6_4[k])<DIFF_ANG
   * - COND.17
     - fl_abs(miki6_5[i]-miki6_6[k])
     - fl_abs(miki6_5[i]-miki6_6[k])<(FL)tmp_diff
   * - TOTAL
     - (COND.16) && (COND.17)
     - 


-----------------------------

.. list-table:: SWITCH3
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.14
     - 
     - hogehoge3_2
   * - TOTAL
     - COND.14
     - 


-----------------------------

+++++++++++++++++++
Subprocesses
+++++++++++++++++++

.. toctree::   :maxdepth: 1

   fn_miki_test3_FORLOOP1_SUBPROCESS

   fn_miki_test3_IF2_SUBPROCESS

   fn_miki_test3_IF4_SUBPROCESS

   fn_miki_test3_IF5_SUBPROCESS

   fn_miki_test3_SWITCH3_SUBPROCESS



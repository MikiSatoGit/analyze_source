==========================
fn_miki_test3::IF5_SUB1
==========================


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
   START -> SUB1 -> NEXT;
    }

+++++++++++++++++++
Process Table
+++++++++++++++++++

.. list-table:: SUB1
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.1
     - miki6_7[i][k] = (
     - 
     - TBD
   * - 
     - 8.0F * fl_abs(miki6_8[i] - miki6_9[k])) + 1.0F * fl_abs((FL)(miki6_10[i] - miki6_11[k])
     - 
     - TBD
   * - 
     - );
     - 
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

+++++++++++++++++++
Subprocesses
+++++++++++++++++++



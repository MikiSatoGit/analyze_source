==============================
fn_miki_test4::SWITCH3_SUB1
==============================


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
   * - case mode1:
     - see below
     - 
     - 
   * - PROC.2
     - miki4_2_1=subsubsubsub_mode_1;
     - 
     - TBD
   * - PROC.3
     - break;
     - 
     - TBD
   * - case mode1:
     - see below
     - 
     - 
   * - PROC.5
     - miki4_2_2=subsubsubsub_mode_2;
     - 
     - TBD
   * - PROC.6
     - break;
     - 
     - TBD
   * - default:
     - see below
     - 
     - 
   * - PROC.8
     - miki4_2_3=subsubsubsub_mode_default;
     - 
     - TBD
   * - PROC.9
     - break;
     - 
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

+++++++++++++++++++
Subprocesses
+++++++++++++++++++



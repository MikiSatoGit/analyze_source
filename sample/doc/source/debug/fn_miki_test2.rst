==================
fn_miki_test2
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
   START -> MAIN1 -> IF1_if -> IF1_yes_pt;
   IF1_end_pt -> END;
   IF1_yes_pt -> IF1_SUB1_subproc -> IF1_end_pt;
   ELIF2_yes_pt -> ELIF2_SUB1_subproc -> ELIF2_end_pt;
   ELSE3_else -> ELSE3_SUB1_subproc -> ELSE3_end_pt;
   IF1_if -> IF1_yes_pt;
   IF1_yes_pt[label = "yes"];
   IF1_if -> IF1_no_pt -> ELIF2_elif;
   ELIF2_end_pt -> IF1_end_pt;
   IF1_no_pt[label = "No"];
   ELIF2_elif -> ELIF2_yes_pt;
   ELIF2_yes_pt[label = "yes"];
   ELIF2_elif -> ELIF2_no_pt -> ELSE3_else;
   ELSE3_end_pt -> IF1_end_pt;
   ELIF2_no_pt[label = "No"];
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
     - TEST_IFNDEF_15_VALID=0;
     - 
     - TBD
   * - PROC.2
     - TEST_ELSE_18_VALID=0;
     - 
     - TBD
   * - PROC.3
     - TEST_IFNDEF_2_VALID=0;
     - 
     - TBD
   * - PROC.4
     - TEST_IFNDEF_21_VALID=0;
     - 
     - TBD
   * - PROC.5
     - TEST_ELSE_24_VALID=0;
     - 
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

.. list-table:: ELIF2
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.2
     - lv1_2
     - lv1_2==12
   * - TOTAL
     - COND.2
     - 


-----------------------------

.. list-table:: IF1
   :header-rows: 1
   :widths: 20, 40, 40

   * - COND#
     - Data
     - Condition
   * - COND.1
     - lv1_1
     - lv1_1==11
   * - TOTAL
     - COND.1
     - 


-----------------------------

+++++++++++++++++++
Subprocesses
+++++++++++++++++++

.. toctree::   :maxdepth: 1

   fn_miki_test2_ELIF2_SUBPROCESS

   fn_miki_test2_ELSE3_SUBPROCESS

   fn_miki_test2_IF1_SUBPROCESS



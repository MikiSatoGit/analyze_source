==================
fn_miki_test5
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
   START -> MAIN1 -> MAIN2 -> END;
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
   * - const FL CFL_D_MAP_EXOBJ_POWER[CU2_MAP_EXOBJ_POWER_INDEX][2] =
     - see below
     - 
     - 


-----------------------------

.. list-table:: MAIN2
   :header-rows: 1
   :widths: 20, 40, 25, 15

   * - PROC#
     - Processing
     - (Argument)
     - Description
   * - PROC.2
     - a=4;
     - 
     - TBD
   * - PROC.3
     - return;
     - 
     - TBD


-----------------------------

+++++++++++++++++++
Condition Table
+++++++++++++++++++

+++++++++++++++++++
Subprocesses
+++++++++++++++++++

.. toctree::   :maxdepth: 1

   fn_miki_test5_MAIN1_SUBPROCESS



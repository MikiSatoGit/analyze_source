=================================================
fn_btt_tle_initialize
=================================================


+++++++++++++++++++
Interface
+++++++++++++++++++

.. csv-table:: Arguments
   :encoding: utf-8
   :header-rows: 1
   :widths: 40, 5, 10, 5, 10, 10, 10, 10
   :file: ../../../csv/debug_fn_btt_tle_initialize_arg.csv

.. csv-table:: Return Value
   :encoding: utf-8
   :header-rows: 1
   :widths: 40, 5, 10, 5, 10, 10, 10, 10
   :file: ../../../csv/debug_fn_btt_tle_initialize_ret.csv

++++++++++++++++++++
Main Process Flow
++++++++++++++++++++

.. image:: ../../../fig/debug_fn_btt_tle_initialize_MAINPROCESS.svg
   :width: 600px


++++++++++++++++++++
Process Table
++++++++++++++++++++

.. csv-table:: MAIN1
   :encoding: utf-8
   :header-rows: 1
   :widths: 20, 40, 25, 15
   :file: ../../../csv/debug_fn_btt_tle_initialize_MAINPROCESS_MAIN1_proc.csv

=============================

.. csv-table:: MAIN5
   :encoding: utf-8
   :header-rows: 1
   :widths: 20, 40, 25, 15
   :file: ../../../csv/debug_fn_btt_tle_initialize_MAINPROCESS_MAIN5_proc.csv


++++++++++++++++++++
Condition Table
++++++++++++++++++++

.. csv-table:: IF1
   :encoding: utf-8
   :header-rows: 1
   :widths: 20, 40, 40
   :file: ../../../csv/debug_fn_btt_tle_initialize_MAINPROCESS_IF1_if_cond.csv


=============================

.. csv-table:: ELIF2
   :encoding: utf-8
   :header-rows: 1
   :widths: 20, 40, 40
   :file: ../../../csv/debug_fn_btt_tle_initialize_MAINPROCESS_ELIF2_elif_cond.csv

=============================

.. csv-table:: ELIF3
   :encoding: utf-8
   :header-rows: 1
   :widths: 20, 40, 40
   :file: ../../../csv/debug_fn_btt_tle_initialize_MAINPROCESS_ELIF3_elif_cond.csv


++++++++++++++++++++
Subprocesses
++++++++++++++++++++

.. toctree::
   :maxdepth: 1


   fn_btt_tle_initialize_IF1_SUBPROCESS

   fn_btt_tle_initialize_ELIF3_SUBPROCESS

   fn_btt_tle_initialize_ELSE4_SUBPROCESS



VD init_btt_configuration_parameter_dummy(
	BSM_STANDARD *pst_a_bsm_alertarea_for_test,		/*!< [in] Standard BSM alert area (should be provided from outside BTT)*/
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [out] (optional) Additional trailer or object info from other system or module */
	BTT_HITCH_ANGLE *pst_a_hitch_angle				/*!< [out] (optional) Angle between subject vehicle and trailer */
)
{

	miki0 = main(
		arg0_1,
		arg0_2,
		(S1)arg0_3 );

	/*! @note (1) do nothing if BTT state is already INITIALIZED */
	if( st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED )
	{																	/* SUBPROCESS(1) « */
		return;
	}																	/* SUBPROCESS(1) ª */


	if(miki==test)
	{ miki = done; hogehoge_ng{ miki = next; } }
	else
	{
		miki = ELSETEST;
	}

	if(
		miki==test
	 && miki==debug
	)
	{																	/* SUBPROCESS(2) « */
		miki1_1=sub; miki1_2 = (S1)sub; miki1_3() ; miki1_4((S1)arg1_1);
		if(hogehoge1)
		{																/* SUBSUBPROCESS(1) « */
			miki2_1 = subsub_1(
				(S1)arg2_1_1,
				arg2_1_2 );
			miki2_2 
			= subsub_2(
				(S1)arg2_2_1,
				arg2_2_2
			);
			for(i=0; i<hogehoge2; i++)
			{															/* SUBSUBSUBPROCESS(1) « */
				miki3 = (S1)subsubsub(arg3_1,arg3_2,arg3_3);
				while(hogehoge3_1)
				{														/* SUBSUBSUBSUBPROCESS(1) « */
					miki4_1 = subsubsubsub((S1)arg4_1,(S2)arg4_2,(S3)arg4_3);
					if(hogehoge4_1)
					{
						(S5)miki5_1 = subsubsubsubsub_5_1;
					}
					else if(hogehoge4_2)
					{
						(S5)miki5_2 = subsubsubsubsub_5_2;
					}
					else if(hogehoge4_3)
					{
						(S5)miki5_3 = subsubsubsubsub_5_3;
					}
					else
					{
						(S5)miki5_4 = subsubsubsubsub_5_4;
					}
				}														/* SUBSUBSUBSUBPROCESS(1) ª */

				switch (hogehoge3_2){									/* SUBSUBSUBSUBPROCESS(2) « */
				case mode1:
					miki4_2_1 = subsubsubsub_mode_1;
					break;
				case mode1:
					miki4_2_2 = subsubsubsub_mode_2;
					break;
				default:
					miki4_2_3 = subsubsubsub_mode_default;
					break;
				}														/* SUBSUBSUBSUBPROCESS(2) ª */

				{														/* SUBSUBSUBSUBPROCESS(3) « */
					miki4_3 = subsubsubsub_mode_default(
						(S1) arg4_3_1,
						arg4_3_2,
						arg4_3_3
					);
				}														/* SUBSUBSUBSUBPROCESS(3) ª */

			}															/* SUBSUBSUBPROCESS(1) ª */
		}																/* SUBSUBPROCESS(2) ª */
		else
		{
			hogehoge1_ELSE();
		}
	}																	/* SUBPROCESS(2) ª */
}


VD fn_btt_initialize(
	U1 u1_a_bsm_configuration,			/*!< [in] BSM CAN configuration */
	U1 u1_a_bsm_drv_cmd,				/*!< [in] BSM on/off switch */
	U1 u1_a_btt_configuration,			/*!< [in] BTT CAN Configuration */
	U1 u1_a_btt_drv_cmd,				/*!< [in] BTT on/off switch */
	BSM_STANDARD st_a_bsm_alertarea		/*!< [in] Standard BSM alert area */
)
{

#ifndef _20170116_BTT_STAT_RESET
	if ((fl_g_v_self_bsm_for_base > BTT_ACTIVE_SPEED_TH)) {
		st_g_btt_stat.BTT_RESET = BTT_TRUE;
	}
	if( st_g_btt_stat.BTT_RESET == BTT_TRUE
	 && st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED
	 && fl_g_v_self_bsm_for_base < (FL)0.5 ){
		 st_g_btt_stat.BTT_timer ++;
		 if(st_g_btt_stat.BTT_timer > (S4)150){
			st_g_btt_stat.BTT_initialized = BTT_RET_t.Init_Stat.UNINITIALIZED;
			st_g_btt_stat.BTT_RESET = BTT_FALSE;
			st_g_btt_stat.BTT_timer = (S4)0;
			st_g_btt_stat.ATD = BTT_RET_t.Func_Stat.ENABLE;
		}
	}
#endif
	/*! @note (1) check initialize status (Do nothing if already initilaized) */
	if(st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED )
	{
		return;
	}

	/*! @note (2) inistialize BSM standard area */
	/* Based on RDD:Table.4.1.3.1-1 */
	st_g_btt_alertarea.standard = st_a_bsm_alertarea;

	/*! @note (3) initialize BTT area */
	/* Based on RDD:Table.2.2.6.2-1 */
	st_g_btt_result.TFlag = BTT_RET_t.TFlag.UNKNOWN;		// _20161130_T modified TFlag initial value
	fn_btt_set_trailer_length( BTT_TRAILER_SIZE_UNKNOWN );
	fn_btt_set_trailer_width( BTT_TRAILER_SIZE_UNKNOWN );
	st_g_btt_alertarea.rear.VarY = (FL) 0.0;
	st_g_btt_alertarea.rear.VarYmax = BTT_REAR_RANGE_MAX;	// value TBD
	st_g_btt_alertarea.side.VarXin = (FL) 0.0;
	st_g_btt_alertarea.side.VarXmax = (FL) 0.0;
	st_g_btt_alertarea.side.VarXout = (FL) 0.0;	// TBD

	/*! @note (4) activate trailer detection function(TTM,ATD) */
	/* Based on RDD:Fig.2.2.7.1-1 */
	fn_btt_ttm_activate();
	fn_btt_atd_activate();
	fn_btt_atd_initialize();
	/* TLE will be activated after ATD detects trailer*/
	/* TWE will be activated after ATD detects trailer*/

	/*! @note (5) update BSM_Final_Stat (BTT initialize) */
	fn_btt_set_bsm_final_state(
		u1_a_bsm_configuration,
		u1_a_bsm_drv_cmd
	);

	/*! @note (6) update BTT_Final_Stat (BTT initialize) */
	fn_btt_set_btt_final_state(
		u1_a_btt_configuration,
		u1_a_btt_drv_cmd,
		st_g_btt_result
	);

	/*! @note (7) activate alert zone adjustment function(AAZ) if BTT SW is ON */
	/* Based on RDD:Fig.2.2.7.1-1 */
	if( u1_a_btt_drv_cmd == BTT_RET_t.Drv_SW.ON )
	{
		fn_btt_aaz_activate();
	}

	/*! @note (8) set BTT initialize state to INITIALIZED */
	st_g_btt_stat.BTT_initialized = BTT_RET_t.Init_Stat.INITIALIZED;

	return;
}

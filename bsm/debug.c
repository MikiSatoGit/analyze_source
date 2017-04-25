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

U1 fn_btt_atd_detect_trailer(						/*!< [out] trailer flag  */
#ifndef _20161209_BTT_ATD_TRACKING
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	NORMAL_BSM *pst_a_object,						/*!< [in] (Current) Position and speed of objects detected by SRR */
	S4 s4_a_object_size,							/*!< [in] (Current) Number of objects */
#ifndef _20170119_ATD_DOADBF_CHECK
	FL fl_a_doa_pow_ave[2][3],
	FL fl_a_doa_pow_dev[2][3],
	S4 s4_a_doa_bf_peak_bin,
	FL fl_a_doa_bf_peak_pow,
#endif
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info	/*!< [in] (optional) Additional trailer or object info from other system or module */
#endif
)
{
	S4 s4_t_lp_i;

	U1 u1_t_btt_trailer_flg = BTT_RET_t.TFlag.UNKNOWN;

#ifndef _20161209_BTT_ATD_TRACKING
	fn_btt_atd_trailerobj_tracking(
		pst_a_object,
		s4_a_object_size
#ifndef _20170119_ATD_DOADBF_CHECK
		,fl_a_doa_pow_ave
		,fl_a_doa_pow_dev
		,s4_a_doa_bf_peak_bin
		,fl_a_doa_bf_peak_pow
#endif
	);	

	if( st_atd_params.atd_counter[0] > BTT_ATD_CONNECT_TH ){
		u1_t_btt_trailer_flg = BTT_RET_t.TFlag.CONNECT;
	} 
	if( (st_atd_params.atd_counter[1] > BTT_ATD_NOTCONNECT_TH)
	&&  (st_atd_params.atd_counter[1] - st_atd_params.atd_counter[0] > BTT_ATD_CNT_DIFF) ){
		u1_t_btt_trailer_flg = BTT_RET_t.TFlag.NOTCONNECT;

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
		/* set trailer object to unknown value for VI output */
		for(s4_t_lp_i=0; s4_t_lp_i<6; s4_t_lp_i++){
			afl_g_btt_atd_obj_tracking[s4_t_lp_i] = (FL)-120;
		}
#endif
	}
#endif


	/*! @note  TBD */
	/*! @test ATD Core Logic Output Signal Pattern\n
		(1) u1_t_btt_trailer_flg = BTT_RET_t.TFlag.CONNECT;	\n
		(2) u1_t_btt_trailer_flg = BTT_RET_t.TFlag.NOTCONNECT;	\n
	*/

	return u1_t_btt_trailer_flg;
}


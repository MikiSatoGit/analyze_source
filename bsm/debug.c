
VD fn_btt_atd_main(
	type1 arg1,
	type1 arg2
)
{
	if(lv1_1 == 11)
	{
		if(lv1_1_1 == 111)
		{
			level1_1_1_1 = hoge1_1_1_1;
			if(hogehoge_1)
			{
				if(hogehoge_2){ level1_1_1_1 = hoge1_1_1_1; level1_1_1_2 = hoge1_1_1_2; }
			}
		}
		else if(lv1_1_2 == 112)
		{
			level1_1_2_1 = hoge1_1_2_1;
		}
		else
		{
			level1_1_3_1 = hoge1_1_3_1;
		}
	}
	else if(lv1_2 == 12)
	{
		level1_2_1 = hoge1_2_1;
	}
	else
	{
		level1_3_1 = hoge1_3_1;
	}

	return;
}


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
	{ miki = done; hogehoge{ miki = next; } }
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



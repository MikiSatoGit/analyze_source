VD fn_btt_tle_initialize()
{
	/*! @note (1) initialize TLE internal parameters */
	st_tle_params.timer = 0;
	fn_btt_set_trailer_length(
		hogege1,
		hogege2,
		(S4)BTT_TRAILER_SIZE_UNKNOWN
	);

	if(a==1 && b==1)
	{
		hogehoge3 = 1;
	}
	else if(a==2)
	{
//		hogehoge3 = 2;
		return;
	}
	else if(a==3)
	{
		hogehoge3 = 3;
//		return;
	}
	else
	{
		hogehoge3 = 4;
		return;
	}

	a = 4;
	return;
}


VD fn_miki_test4(
	type1 arg1
	,type2 arg2
)
{
	if(test2 ==1)
	{
		test2 = 1;
	}

	S4 s4_t_lp_normal;			/* NORMAL¨WΜ[vΟ dlΕΝi */
	FL fl_t_thd_exobj_range;	/* ¨Wθli£j [m] */
	FL fl_t_thd_exobj_power;	/* ¨WθlidΝj [dB] */
	FL fl_t_obj_power;			/* πn6Μ½ΟϋΚdΝi[Ο */
	FL fl_t_abs_robs;			/* RobsΜβΞli[Ο */
	FL fl_t_abs_vobs;			/* VobsΜβΞli[Ο */

	const FL CFL_D_MAP_EXOBJ_POWER[CU2_MAP_EXOBJ_POWER_INDEX][2] = {
		/* Όό£[m]  dΝθl[dB] */
		{(FL)1.0,		(FL)72.0},
		{(FL)2.0,		(FL)65.0},
		{(FL)2.5,		(FL)62.5},
		{(FL)3.0,		(FL)57.7},
		{(FL)4.0,		(FL)52.7},
		{(FL)5.0,		(FL)48.9},
		{(FL)6.0,		(FL)45.7},
		{(FL)9.0,		(FL)38.6}
	};

	miki2_1 = subsub_1( (S4)arg2_1_1 );
	miki2_2 
	= subsub_2(
		(S1)arg2_2_1
	);
	miki2_3 = 
	subsub_3( (S1)arg2_3_1,
		arg2_3_2
	);



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
	}														/* SUBSUBSUBSUBPROCESS(2) ͺ */


	while(test1==1)
	{
		test1 = 2;
	}

	if(test1==1)
	{
		test1 = 1;
	}


	if(test2==1)
	{
		test2 = 1;
	}
	else
	{
		test2 = 0;
	}

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
//			level1_1_3_1 = hoge1_1_3_1;
			return;
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

	for(i=(S4)0; i<(S4)n; i++)
	{
		test1 += 1;
	}

	return;

}


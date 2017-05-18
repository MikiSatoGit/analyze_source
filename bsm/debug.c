VD fn_miki_test4(
	type1 arg1
	,type2 arg2
)
{
	if(test2==1)
	{
		test2 = 1;
	}

	S4 s4_t_lp_normal;			/* NORMAL物標のループ変数 仕様書ではi */
	FL fl_t_thd_exobj_range;	/* 物標除去閾値（距離） [m] */
	FL fl_t_thd_exobj_power;	/* 物標除去閾値（電力） [dB] */
	FL fl_t_obj_power;			/* 条件n6の平均方位電力格納変数 */
	FL fl_t_abs_robs;			/* Robsの絶対値格納変数 */
	FL fl_t_abs_vobs;			/* Vobsの絶対値格納変数 */

	const FL CFL_D_MAP_EXOBJ_POWER[CU2_MAP_EXOBJ_POWER_INDEX][2] = {
		/* 直線距離[m]  電力閾値[dB] */
		{(FL)1.0,		(FL)72.0},
		{(FL)2.0,		(FL)65.0},
		{(FL)2.5,		(FL)62.5},
		{(FL)3.0,		(FL)57.7},
		{(FL)4.0,		(FL)52.7},
		{(FL)5.0,		(FL)48.9},
		{(FL)6.0,		(FL)45.7},
		{(FL)9.0,		(FL)38.6}
	};


	miki2_1 = subsub_1(
		(S1)arg2_1_1,
		arg2_1_2 );
	miki2_2 
	= subsub_2(
		(S1)arg2_2_1,
		arg2_2_2
	);
	miki2_3 = 
	subsub_3(
		(S1)arg2_3_1,
		arg2_3_2
	);



	switch (hogehoge3_2){									/* SUBSUBSUBSUBPROCESS(2) ↓ */
	case mode1:
		miki4_2_1 = subsubsubsub_mode_1;
		break;
	case mode1:
		miki4_2_2 = subsubsubsub_mode_2;
		break;
	default:
		miki4_2_3 = subsubsubsub_mode_default;
		break;
	}														/* SUBSUBSUBSUBPROCESS(2) ↑ */


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

	for(i=0; i<n; i++)
	{
		test1 += 1;
	}

	return;

}


VD fn_miki_test1( type1 arg1, type2 arg2 )
{

#ifndef A_TEST_IFDEF_1
	TEST_IFDEF_1_VALID = 0;		// valid
#ifndef A_TEST_DEF_11
	TEST_IFNDEF_2_VALID = 0;	// valid
#else
	TEST_ELSE_3_INVALID = 0;	// invalid
#endif
	TEST_ELSE_4_VALID = 0;		// valid
#endif


	return;
}

VD fn_miki_test2(
	type1 arg1,
	type2 arg2
)
{

#ifdef TEST_IFDEF_1
	TEST_IFDEF_1_INVALID = 0;	// invalid
#ifndef TEST_DEF_11
	TEST_IFNDEF_12_INVALID = 0;	// invalid
#else
	TEST_ELSE_12_INVALID = 0;	// invalid
#endif
#ifdef TEST_DEF_11
	TEST_IFDEF_13_INVALID = 0;	// invalid
#else
	TEST_ELSE_14_INVALID = 0;	// invalid
#endif

#else

#ifndef TEST_DEF_12
	TEST_IFNDEF_15_VALID = 0;	// valid
#else
	TEST_ELSE_16_INVALID = 0;	// invalid
#endif
#ifdef TEST_DEF_12
	TEST_IFDEF_17_INVALID = 0;	// invalid
#else
	TEST_ELSE_18_VALID = 0;	// valid
#endif
#endif



#ifndef TEST_IFNDEF_2
	TEST_IFNDEF_2_VALID = 0;	// valid
#ifndef TEST_DEF_21
	TEST_IFNDEF_21_VALID = 0;	// valid
#else
	TEST_ELSE_22_INVALID = 0;	// invalid
#endif

#ifdef TEST_DEF_21
	TEST_IFDEF_23_INVALID = 0;	// invalid
#else
	TEST_ELSE_24_VALID = 0;		// valid
#endif

#else

#ifndef TEST_DEF_22
	TEST_IFNDEF_25_INVALID = 0;	// invalid
#else
	TEST_ELSE_26_INVALID = 0;	// invalid
#endif
#ifdef TEST_DEF_22
	TEST_IFDEF_27_INVALID = 0;	// invalid
#else
	TEST_ELSE_28_INVALID = 0;	// invalid
#endif
#endif



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

VD fn_miki_test3(
	type1 arg1
	,type2 arg2
)
{
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

	for(i=(S4)0; i<(S4)n; i++)
	{
		test1 += 1;
	}


	if( A1==(S4)a1 || (B1==(FL)b1 && B2==(FL)b3) || (C1 > c1() && C2() > c2 && C3 > (S4)c3()) && ( (D1 < d1 && D2 < d2) || (D3 >= d3 && D4 >= d4) ) )
	{
		hoge = hogehoge;
	}


	switch (hogehoge3_2){									/* SUBSUBSUBSUBPROCESS(2) ↓ */
	case mode1:
		miki4_2_1 = subsubsubsub_mode_1();
		break;
	case mode1:
		miki4_2_2 = subsubsubsub_mode_2;
		break;
	default:
		miki4_2_3 = subsubsubsub_mode_default;
		break;
	}														/* SUBSUBSUBSUBPROCESS(2) ↑ */
#ifdef _DIRECTIVITY_TEST	// for directivity check
#else
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
	if( hoge(a1, a2)!=0 )
	{
		miki5_1 =0;
	}
#endif
#endif
	fl_t_tmp_theta = -( 
		PI / 180.0F * (
			miki6_1[0] + miki6_2[s4_t_lp_i] +  (FL)START_ANG
		) 
	);

	if (
		( fl_abs( miki6_3[i] - miki6_4[k] ) < DIFF_ANG )							/* COND. j1 */
		&& ( fl_abs( miki6_5[i] - miki6_6[k] ) < (FL)tmp_diff )		/* COND. j2 */
	) {
		miki6_7[i][k] = ( 8.0F * fl_abs(miki6_8[i] - miki6_9[k]))
											  + 1.0F * fl_abs((FL)(miki6_10[i] - miki6_11[k]));
	}


	miki7_1[num - 1 - i][k]
			= (0.5F * fl_abs(miki7_2[up - 1 - i] - miki7_3[k]))
			+ (1.0F * fl_abs((FL)(miki7_4[num - 1 - i] - miki7_5[k])))
			+ (1.0F * fl_abs((FL)(miki7_6[num - 1 - i] - miki7_7[k] - (FL)t)));


	tmp_comp = fl_abs(miki8_1[k][0]-miki8_2[0][8])
				+ fl_abs(miki8_3[k][1]-miki8_4[0][7]);

	tmp_comp = fl_abs(miki9_1[k][0]-miki9_2[0][8]) +
				fl_abs(miki9_3[k][1]-miki9_4[0][7]);

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

	miki2_1 = subsub_1( (S4)arg2_1_1 );
	miki2_2 
	= subsub_2(
		(S1)arg2_2_1
	);
	miki2_3 = 
	subsub_3( (S1)arg2_3_1,
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


VD fn_miki_test5(
	type1 arg1
	,type2 arg2
)
{
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

	a = 4;
	return;

}


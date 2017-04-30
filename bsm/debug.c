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


	if (
		(fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < POW_DIFF_UP_DOWN_DOA)							/* COND. j1 */
		 && (fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]) < (FL)s4_t_tmp_doa_diff_up_down)		/* COND. j2 */
	) {
		afl_t_compare[s4_t_lp_i][s4_t_lp_k] = ( 8.0F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))
											  + 1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]));
	}


	afl_t_compare[s4_a_peak_num_up - 1 - s4_t_lp_i][s4_t_lp_k]
			= (0.5F * fl_abs(afl_a_peak_doa_powers_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))							/* DOA pow.	0.5F: weighting factor */
			+ (1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])))			/* DOA */
			+ (1.0F * fl_abs((FL)(afl_a_peak_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_bins_intpl_dn[s4_t_lp_k] - (FL)s4_t_shift)));	/* FREQ */


	tmp_comp = fl_abs(afl_a_alarmed_target_current[k][0]-afl_a_Tx_float[0][8])	 		/* PROC.15 Rxfil + Ryfil */
				+ fl_abs(afl_a_alarmed_target_current[k][1]-afl_a_Tx_float[0][7]);

	return;
}

static VD fn_bsm_ordinary_check_minimum_pair(S4  s4_a_lp_peak_num_up,
											 S4  s4_a_lp_peak_num_dn,
											 FL  afl_a_compare[ORDINARY_BUFFSIZE * 2][ORDINARY_BUFFSIZE * 2],
											 S4  as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
											 S4  as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],
											 S4  as4_a_pair_index_up[ORDINARY_BUFFSIZE * 2],
											 S4  as4_a_pair_index_dn[ORDINARY_BUFFSIZE * 2],
											 FL* pfl_a_min_comp,
											 S4* ps4_a_found,
											 S4* ps4_a_pair_index_up,
											 S4* ps4_a_pair_index_dn,
											 S4* ps4_a_pair_num)
{
	FL fl_t_min_comp_prev;									/* ペアマッチ評価値の比較対象値の保存変数 */
	FL fl_t_min_comp_temp;									/* ペアマッチ評価値の仮保存変数 */
	S4 s4_t_pair_num_tmp;									/* ペアマッチ数カウント用変数 */
	S4 as4_t_pair_index_up[ORDINARY_BUFFSIZE * 2];			/* ペアマッチインデックス並べ替え用バッファ(上り) */
	S4 as4_t_pair_index_dn[ORDINARY_BUFFSIZE * 2];			/* ペアマッチインデックス並べ替え用バッファ(下り) */
	S4 s4_t_lp_pair_num;									/* ペア個数のループ変数 仕様書ではk,ii,jjが対象 3個の変数を統一している */
	S4 s4_t_lp_num_ordi_2;									/* ORDINARY_BUFFSIZE * 2のループ変数 */

	/* 変数初期化 */
	for (s4_t_lp_num_ordi_2 = (S4)0; s4_t_lp_num_ordi_2 < ((S4)ORDINARY_BUFFSIZE * (S4)2); s4_t_lp_num_ordi_2++) {
		as4_t_pair_index_up[s4_t_lp_num_ordi_2] = (S4)0;
		as4_t_pair_index_dn[s4_t_lp_num_ordi_2] = (S4)0;
	}

	/* ※017-1 <Comparing process> */
	/* 仕様のi = 0 ～ peak_num_up_doa-1とj = 0 ～ peak_num_dn_doa-1のforループは */
	/* 親関数に存在している */
	if (afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn] < *pfl_a_min_comp) {				/* COND. k1 */
		if ((as4_a_used_peak_up[s4_a_lp_peak_num_up] == (S4)0)										/* COND. k2 */
		&&  (as4_a_used_peak_dn[s4_a_lp_peak_num_dn] == (S4)0)) {									/* COND. k3 */
			*pfl_a_min_comp = afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn];
			*ps4_a_found = (S4)1;
			*ps4_a_pair_index_up = s4_a_lp_peak_num_up;
			*ps4_a_pair_index_dn = s4_a_lp_peak_num_dn;
		} else {
			/* Check already paired items */
			for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < *ps4_a_pair_num; s4_t_lp_pair_num++) {
				if (((!(as4_a_used_peak_up[s4_a_lp_peak_num_up] == (S4)0))						/* COND. !k2 */
				&&   (as4_a_pair_index_up[s4_t_lp_pair_num] == s4_a_lp_peak_num_up))			/* COND. k6 */
				||  ((!(as4_a_used_peak_dn[s4_a_lp_peak_num_dn] == (S4)0))						/* COND. !k3 */
				&&   (as4_a_pair_index_dn[s4_t_lp_pair_num] == s4_a_lp_peak_num_dn))) {		/* COND. k7 */
					fl_t_min_comp_temp = *pfl_a_min_comp;
					*pfl_a_min_comp = afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn];
					fl_t_min_comp_prev = afl_a_compare[as4_a_pair_index_up[s4_t_lp_pair_num]][as4_a_pair_index_dn[s4_t_lp_pair_num]];
					if (*pfl_a_min_comp < fl_t_min_comp_prev) {				/* COND. k8 */
						/* Cancel previous pair */
						as4_a_used_peak_up[as4_a_pair_index_up[s4_t_lp_pair_num]] = (S4)0;
						as4_a_used_peak_dn[as4_a_pair_index_dn[s4_t_lp_pair_num]] = (S4)0;
						
						/*  Erase index of previous pair */
						as4_a_pair_index_up[s4_t_lp_pair_num] = (S4)-1;
						as4_a_pair_index_dn[s4_t_lp_pair_num] = (S4)-1;
						
						/* Set new pair */
						*ps4_a_found = (S4)1;
						*ps4_a_pair_index_up = s4_a_lp_peak_num_up;
						*ps4_a_pair_index_dn = s4_a_lp_peak_num_dn;
					} else {
						*pfl_a_min_comp = fl_t_min_comp_temp;
					}
				}
			}
		}
		/*  Trim pair_index_up/dn (trim cancelled items in the pair index buffer) */
		s4_t_pair_num_tmp = (S4)0;
		for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < *ps4_a_pair_num; s4_t_lp_pair_num++) {
			if (as4_a_pair_index_up[s4_t_lp_pair_num] != (S4)-1) {					/* COND. k9 */
				as4_t_pair_index_up[s4_t_pair_num_tmp] = as4_a_pair_index_up[s4_t_lp_pair_num];
				as4_t_pair_index_dn[s4_t_pair_num_tmp] = as4_a_pair_index_dn[s4_t_lp_pair_num];
				s4_t_pair_num_tmp++;
			}
		}
		
		if (s4_t_pair_num_tmp > (S4)0) {					/* COND. k10 */
			for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < s4_t_pair_num_tmp; s4_t_lp_pair_num++) {
				as4_a_pair_index_up[s4_t_lp_pair_num] = as4_t_pair_index_up[s4_t_lp_pair_num];
				as4_a_pair_index_dn[s4_t_lp_pair_num] = as4_t_pair_index_dn[s4_t_lp_pair_num];
			}
		}
		
		*ps4_a_pair_num = s4_t_pair_num_tmp;
	}

	return;
}


FL fl_seek_low_speed_sot(
	const FL afl_a_sot_detect_param[9],			/* [in] */
	U1 u1_a_alarming_flag
)
{
	/*for文ループ変数 */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	S4 i;
#endif	/* VI 表示用 */
	S4 j, k;

	/*** ブロックの途中で宣言されている変数群をブロックの先頭へ移動 *******************/

	/* for DOA-Velocity line(2FCW I) */
	S4 nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1];
	S4 nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE];

	/* for DOA-Velocity line(2FCW Q) */
	S4 nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1];
	S4 nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE];

	/* for DOA of v=0（side direction） */
	S4 v0_doa_def;
	S4 v0_doa;

	/* for appox. line of stationary object line */
	FL dev;
	FL power_ave = 0.0F;

	S4 stationary_doa_line[N_DOA];
	S4 sot_limit_doa_line_forward[N_DOA];
	S4 sot_limit_doa_line_backward[N_DOA];

	FL afl_t_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4];
	FL afl_t_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4];

	S4 fast_sot_num;
	S4 not_fast_sot_num;

	S4 backward_priod = 0;
	S4 forward_point = 0;
	FL tmp_dev[2];
	S4 sot_stop;
	S4 forward_priod = 1;
	U1 u1_t_alarming_flag_local;
	U1 u1_t_num_nearfield_doa_2f_i;
	U1 u1_t_num_nearfield_doa_2f_q;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	tmp_dev[0] = 999.9F;
	tmp_dev[1] = 999.9F;

	fast_sot_num = (S4)0;
	not_fast_sot_num = (S4)0;
	
	u1_t_alarming_flag_local = (U1)0;
	u1_t_num_nearfield_doa_2f_i = (U1)0;
	u1_t_num_nearfield_doa_2f_q = (U1)0;
	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;

	for(j=0; j<N_DOA; j++)
	{
		stationary_doa_line[j] = 0;
	}

	for (j = (S4)0; j < SLOW_SOT_FREQ_BIN_RANGE; j++) {
		for (k = (S4)0; k < (S4)4; k++) {
			afl_t_sot_check_object_i[j][k] = CFL_UNKNOWN_VALUE;
			afl_t_sot_check_object_q[j][k] = CFL_UNKNOWN_VALUE;
		}
	}

	for (j = (S4)0; j < SLOW_SOT_FREQ_BIN_RANGE; j++) {
		nearfield_doa_i[j][0] = (S4)-1;
		nearfield_doa_q[j][0] = (S4)-1;
		nearfield_doa_peak_num_i[j] = (S4)0;
		nearfield_doa_peak_num_q[j] = (S4)0;
	}

/****************************************************************************/
/* (7)	低速SoT判定処理														*/
/****************************************************************************/
/************************************************/
/* 1)	low-speed 2FCW-DOA calculation			*/
/************************************************/
	{
		/* DOA-Velocity line(2FCW I) */
		u1_t_num_nearfield_doa_2f_i = calc_nearfield_doa_2f_I(
			nearfield_doa_i,			/* [out] */
			nearfield_doa_peak_num_i,	/* [out] */
			SLOW_SOT_FREQ_BIN_START_I,	/* [in] */
			afl_t_sot_check_object_i
		);
	}

	{
		/* DOA-Velocity line(2FCW Q) */
		u1_t_num_nearfield_doa_2f_q = calc_nearfield_doa_2f_Q(
			nearfield_doa_q,			/* [out] */
			nearfield_doa_peak_num_q,	/* [out] */
			SLOW_SOT_FREQ_BIN_START_Q,	/* [in] */
			afl_t_sot_check_object_q
		);
	}

/************************************************/
/* 2)	stationary DOA line	calculation			*/
/************************************************/
	/* ideal DOA of v=0（side direction） */
	v0_doa_def = (S4)(180.0 - st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_sot_detect_param[2]);
	v0_doa     = (S4)(180.0 - st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_sot_detect_param[2]);

	/* stationary object line(DOA-Velocity line) */
	set_stationary_doa_line_2f(
		stationary_doa_line,		/* [out] */
		v0_doa_def,					/* [in] */
		v0_doa						/* [in] */
	);

	/* ↓↓↓↓↓ NO NEED TO CALCULATE EVERY CYCLE ↓↓↓↓↓ */
/************************************************/
/* 3)	SoT limit DOA line	calculation			*/
/************************************************/
	set_sot_limit_doa_line_2f(
		sot_limit_doa_line_backward,
		v0_doa_def,
		v0_doa,
		CFL_SoT_V_TH_BWD
	);
	/* ↑↑↑↑↑ NO NEED TO CALCULATE EVERY CYCLE ↑↑↑↑↑ */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy(as4_g_stationary_doa_line, stationary_doa_line, sizeof(S4)*N_DOA);
	memcpy(as4_g_sot_limit_doa_line_backward, sot_limit_doa_line_backward, sizeof(S4)*N_DOA);
	memset(as4_g_nearfield_doa, 0x00, sizeof(as4_g_nearfield_doa));
	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		if(nearfield_doa_i[i][0]!=-1)
		{
			as4_g_nearfield_doa[nearfield_doa_i[i][0]] = SLOW_SOT_FREQ_BIN_START_I+i;
		}
		if(nearfield_doa_q[i][0]!=-1)
		{
			as4_g_nearfield_doa[nearfield_doa_q[i][0]] = SLOW_SOT_FREQ_BIN_START_Q-i;
		}
	}
#endif /*VI 表示用*/


/****************************************************/
/* 4) deviation calulation							*/
/****************************************************/

	fn_bsm_low_calc_deviation(
		forward_priod,
		nearfield_doa_i,
		nearfield_doa_q,
		(const S4 *)stationary_doa_line,
		&backward_priod,
		tmp_dev,
		v0_doa,
		&fast_sot_num,
		&not_fast_sot_num,
		afl_t_sot_check_object_i,
		afl_t_sot_check_object_q
	);


/************************************************/
/* 5)	low-speed SoT judgment					*/
/************************************************/

	fn_bsm_low_judge_sot(
		stationary_doa_line,
		sot_limit_doa_line_forward,
		sot_limit_doa_line_backward,
		(const S4 *)nearfield_doa_peak_num_i,
		nearfield_doa_i,
		(const S4 *)nearfield_doa_peak_num_q,
		nearfield_doa_q,
		forward_priod,
		backward_priod,
		tmp_dev,
		&dev,
		v0_doa,
		u1_a_alarming_flag,
		u1_t_num_nearfield_doa_2f_i,
		u1_t_num_nearfield_doa_2f_q,
		afl_t_sot_check_object_i,
		afl_t_sot_check_object_q,
		&u1_t_num_forward,
		&u1_t_num_backward
	);

/************************************************/
/* 6)	wall judgment							*/
/************************************************/
	fn_bsm_low_judge_wall(
		(const FL *)tmp_dev,
		u1_t_num_nearfield_doa_2f_i,
		u1_t_num_nearfield_doa_2f_q,
		u1_t_num_forward,
		u1_t_num_backward
	);

/************************************************/
/* 7)	fast-SoT judgment						*/
/************************************************/
	fn_bsm_low_judge_fast_sot(
		fast_sot_num,
		not_fast_sot_num,
		u1_a_alarming_flag
	);

/************************************************/
/* 8)	並走車存在判定							*/
/************************************************/
	fn_bsm_low_judge_exist_leading_car_main((const S4 (*)[1])nearfield_doa_i,
											(const S4 (*)[1])nearfield_doa_q,
											(const FL (*)[4])afl_t_sot_check_object_i,
											(const FL (*)[4])afl_t_sot_check_object_q);


	return dev;
}

S4 s4_search_freq_peak_fsk_IQ(
	const FL afl_a_power_2f[NB_FFT_PT_2F],	/* [in] */
	S4 as4_a_bin_2f[AUX_BUFFSIZE],			/* [out] */
	FL afl_a_bin_power_2f[AUX_BUFFSIZE],	/* [out] */
	const FL afl_a_thres_2f[NB_FFT_PT_2F]	/* [in] */
)
{	
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	S4 s4_t_peak_num = 0;
	FL fl_t_temp = 0;

	s4_t_lp_k = 0;

	/* 接近側 */
	for (s4_t_lp_i = FREQ_BIN_LOWER_LIMIT_2F; s4_t_lp_i < FREQ_BIN_UPPER_LIMIT_2F; s4_t_lp_i++) {
		if (
			(afl_a_power_2f[s4_t_lp_i] < afl_a_power_2f[s4_t_lp_i + 1])
		 && (afl_a_power_2f[s4_t_lp_i + 1] > afl_a_power_2f[s4_t_lp_i + 2])
		 && (afl_a_power_2f[s4_t_lp_i + 1] > afl_a_thres_2f[s4_t_lp_i + 1])
		 && (s4_t_lp_k < AUX_BUFFSIZE)
		) {
			as4_a_bin_2f[s4_t_lp_k] = s4_t_lp_i + (S4)1;
			afl_a_bin_power_2f[s4_t_lp_k] = afl_a_power_2f[s4_t_lp_i + 1];
			s4_t_lp_k++;
		}
	}

	/* 離脱側 */
	for (s4_t_lp_i = FREQ_BIN_LOWER_LIMIT_2F_Q; s4_t_lp_i < (S4)((NB_FFT_PT_2F / 2) - 1); s4_t_lp_i++) {
		if (
			(afl_a_power_2f[s4_t_lp_i] < afl_a_power_2f[s4_t_lp_i + 1])
		 && (afl_a_power_2f[s4_t_lp_i + 1] > afl_a_power_2f[s4_t_lp_i + 2])
		 && (afl_a_power_2f[s4_t_lp_i + 1] > afl_a_thres_2f[s4_t_lp_i + 1])
		 && (s4_t_lp_k < AUX_BUFFSIZE)
		) {
			as4_a_bin_2f[s4_t_lp_k] = s4_t_lp_i + (S4)1;
			afl_a_bin_power_2f[s4_t_lp_k] = afl_a_power_2f[s4_t_lp_i + 1];
			s4_t_lp_k++;
		}
	}
	s4_t_peak_num = s4_t_lp_k;

	return (s4_t_peak_num);

}

VD fn_bsm_2f_make_pair(
	S4		   s4_a_doa_peak_num_2f,											/* [in] */
	S4 		   as4_a_peak_wave_num[AUX_BUFFSIZE * 2],							/* [out] */

	const FL   afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],						/* [in] */
	const FL   afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [in] */
	const FL   afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],						/* [in] */

	S4		   *ps4_a_pair_num_2f,												/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE]									/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_pair_num;

	FL afl_t_tmp_Ryy[3];
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Vobs;
	FL fl_t_tmp_Rxobs;
	FL fl_t_tmp_Ryobs;
	FL fl_t_tmp_theta;

	S4 s4_t_wave_number[AUX_BUFFSIZE*2];

	FL fl_t_pow_min = 0.0F;
	S4 s4_t_index = -1;
	U1 u1_t_lp_aux_buffsize;

	for (u1_t_lp_aux_buffsize = (U1)0; u1_t_lp_aux_buffsize < ((U1)AUX_BUFFSIZE * (U1)2); u1_t_lp_aux_buffsize++) {
		s4_t_wave_number[u1_t_lp_aux_buffsize] = (S4)0;
	}

	s4_t_pair_num = 0;
	/******************** 距離計算 ********************/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_doa_peak_num_2f; s4_t_lp_i++) {

		/***** 1) 推定方向を車座標系に変換 *****/
		fl_t_tmp_theta = -(PI / 180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i] +  (FL)DOA_BIN_START_ANG));

		/***** 2) 距離の算出 *****/
		for (s4_t_lp_k = 0 ; s4_t_lp_k < 3 ; s4_t_lp_k++) {
			afl_t_tmp_Ryy[s4_t_lp_k] = afl_g_cvw_fcw_ryy_matrix_2f[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_i]][s4_t_lp_k];
		}
		fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
		fl_t_tmp_Rxobs = (fl_t_tmp_Robs * (FL)fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
		fl_t_tmp_Ryobs = fl_t_tmp_Robs * (FL)fl_cos(fl_t_tmp_theta);

		fl_t_tmp_Vobs = VCOF_2F * (afl_a_peak_bins_intpl_2f[s4_t_lp_i] - (FL)(NB_FFT_PT_2F / 2));
		/* 真横付近の2F物標の速度を０に(車輪ドップラで複数の速度が検出されるため) */
		if (fl_abs(fl_t_tmp_Ryobs) < EKF_RY_SIDE) {		/* COND.d4 */
			fl_t_tmp_Vobs = 0.0F;
		}

		/******************** 推定Ｒから（-1.5m-fl_a_wall) ********************/
		if (s4_t_pair_num < AUX_BUFFSIZE) {											/* COND.d14 */
			if (
				(fl_t_tmp_Rxobs > st_g_bsm_loop_data.afl_installed_angle[1])		/* COND.d12 */
				 && (fl_t_tmp_Rxobs < RX_MAX_2F)									/* COND.d12 */
				 && (fl_t_tmp_Ryobs < RY_MIN_2F)									/* COND.d13 */
				 && (fl_t_tmp_Robs > R_MAX_2F)										/* COND.d11 */
				 && (fl_t_tmp_Robs < R_MIN_2F)										/* COND.d11 */
			) {
				/***** 4) FMCWピーク周波数の算出 *****/
				/***** 5) ピーク補間 *****/
				/* convert to FMCW peak (UP) */
				if (fl_t_tmp_Robs < 0) {											/* COND.d10 */
					ast_a_normal_2f[s4_t_pair_num].s4_bin_up = (S4)(( 0.50F * ((-fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);					/* PROC.1 */
					ast_a_normal_2f[s4_t_pair_num].fl_bin_up_interpolate = ((0.50F * ((-fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);		/* PROC.1 */
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_bin_up = (S4)(( 0.50F * ((fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_up_interpolate = (( 0.50F * (fl_t_tmp_Robs / RCOF - fl_t_tmp_Vobs / VCOF)) + 0.50F) + (FL)(NB_FFT_PT / 2);
				}
				/***** 4) FMCWピーク周波数の算出 *****/
				/***** 5) ピーク補間 *****/
				if (fl_t_tmp_Robs < 0) {											/* COND.d10 */
					ast_a_normal_2f[s4_t_pair_num].s4_bin_dn = (S4)(( 0.50F * ((-fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_dn_interpolate = (( 0.50F * (-fl_t_tmp_Robs / RCOF + fl_t_tmp_Vobs / VCOF)) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_bin_dn = (S4)((0.50F * ((fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF)) + 0.50F)) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_dn_interpolate = ((0.50F * ((fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF))) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);
				}

				/***** 6) 物標情報の保存 *****/
				s4_t_wave_number[s4_t_pair_num]						= as4_a_peak_wave_num[s4_t_lp_i];

				ast_a_normal_2f[s4_t_pair_num].s4_bin_up_music		= (S4)afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i];
				ast_a_normal_2f[s4_t_pair_num].fl_doa_up_interpolate= afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i];
				ast_a_normal_2f[s4_t_pair_num].fl_power_up			= afl_g_cvw_lfm_ftt_power[0][ast_a_normal_2f[s4_t_pair_num].s4_bin_up];
				ast_a_normal_2f[s4_t_pair_num].fl_power_up_music	= afl_a_peak_doa_powers_2f[s4_t_lp_i];
				ast_a_normal_2f[s4_t_pair_num].fl_theta_up	 		= fl_t_tmp_theta;

				ast_a_normal_2f[s4_t_pair_num].s4_bin_dn_music		= ast_a_normal_2f[s4_t_pair_num].s4_bin_up_music;
				ast_a_normal_2f[s4_t_pair_num].fl_doa_dn_interpolate= ast_a_normal_2f[s4_t_pair_num].fl_doa_up_interpolate;
				ast_a_normal_2f[s4_t_pair_num].fl_power_dn			= afl_g_cvw_lfm_ftt_power[1][ast_a_normal_2f[s4_t_pair_num].s4_bin_dn];
				ast_a_normal_2f[s4_t_pair_num].fl_power_dn_music	= ast_a_normal_2f[s4_t_pair_num].fl_power_up_music;
				ast_a_normal_2f[s4_t_pair_num].fl_theta_dn	 		= ast_a_normal_2f[s4_t_pair_num].fl_theta_up;

				/* 観測位置 */
				ast_a_normal_2f[s4_t_pair_num].fl_Robs	 			= fl_t_tmp_Robs;
				ast_a_normal_2f[s4_t_pair_num].fl_Rxobs				= fl_t_tmp_Rxobs;
				ast_a_normal_2f[s4_t_pair_num].fl_Ryobs				= fl_t_tmp_Ryobs;

				/*  観測速度 */
				ast_a_normal_2f[s4_t_pair_num].fl_Vobs				= fl_t_tmp_Vobs;

				/***** 3) 速度の算出 *****/
				/* 速度のXY成分分離 */
				ast_a_normal_2f[s4_t_pair_num].fl_Vxobs = 0.0F;
				ast_a_normal_2f[s4_t_pair_num].fl_Vyobs = fl_get_vy(
					ast_a_normal_2f[s4_t_pair_num].fl_Vobs,
					fl_cos(ast_a_normal_2f[s4_t_pair_num].fl_theta_up),
					ast_a_normal_2f[s4_t_pair_num].fl_Ryobs,
					fl_g_v_self_bsm_for_base
				);

				/***** 7) 物標フラグ情報の保存 *****/
				/*  停止物判定 */
				if (fl_abs(ast_a_normal_2f[s4_t_pair_num].fl_Vyobs + fl_g_v_self_bsm_for_base / 3.6F) < 0.5F) {		/* COND.d15 */
					ast_a_normal_2f[s4_t_pair_num].s4_flg_stop 		= 1;
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_flg_stop 		= 0;
				}
				s4_t_pair_num++;
			}
		} else {
			/***** 8) バッファあふれ対策 *****/
			fl_t_pow_min = 0.0F;
			s4_t_index = -1;
			for(s4_t_lp_k=0; s4_t_lp_k<s4_t_pair_num; s4_t_lp_k++)
			{
				if ((fl_abs(afl_g_cvw_fcw_ftt_power[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_i]]) > fl_abs(afl_g_cvw_fcw_ftt_power[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_k]]))	/* COND.d16 */
				&&  (fl_t_pow_min > afl_g_cvw_fcw_ftt_power[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_k]])) {																	/* COND.d17 */
					fl_t_pow_min =  afl_g_cvw_fcw_ftt_power[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_k]];							/* PROC.1 */
					s4_t_index = s4_t_lp_k;																							/* PROC.2 */
				}
			}
			if(s4_t_index != -1)																									/* COND.d18 */
			{
				fn_init(&ast_a_normal_2f[s4_t_index], 1);																			/* PROC.3 */
				s4_trim_normal_2f(ast_a_normal_2f);																					/* PROC.4 */
				s4_t_pair_num--;																									/* PROC.5 */
				s4_t_lp_i--;																										/* PROC.6 */
				if(s4_t_lp_i<-1){s4_t_lp_i=-1;}
			}
		}
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < (AUX_BUFFSIZE * 2); s4_t_lp_i++){
		as4_a_peak_wave_num[s4_t_lp_i] = s4_t_wave_number[s4_t_lp_i];
	}
	*ps4_a_pair_num_2f = s4_t_pair_num;

	return;
}


static VD fn_bsm_chkfr_check_alart_max_cycle(
	S4 *ps4_a_tos_cycle_max,
	S4 *ps4_a_sot_cycle_max
)
{
	S4 i;

	/***** 2) ToS警報回数の確認 *****/
	/***** 3) SoT警報回数の確認 *****/
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
#if (BSM_OPTION_SW_ALART == TYPE_A)
		if(st_g_bsm_alarm_data.afl_alarmed_target[i][0] != CFL_UNKNOWN_VALUE)				/* COND.f5 */
		{
			/* check ToS event */
			if(
				(st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_TOS) 			/* COND.f6 */
			||  (st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_MERGEIN) 		/* COND.f7 */
			)
			{
				if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_tos_cycle_max)	/* COND.f8 */
				{
					*ps4_a_tos_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
#elif (BSM_OPTION_SW_ALART == TYPE_B)
		if (st_g_bsm_alarm_data.afl_alarmed_target[i][0] != CFL_UNKNOWN_VALUE) {					/* COND.f5 */
			if (st_g_bsm_alarm_data.afl_alarmed_target[i][4] == ALARM_TYPE_TOS) { 					/* COND.f6 */
				if ((S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_tos_cycle_max) {		/* COND.f8 */
					*ps4_a_tos_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ALART */
			/* check SoT event */
			if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_SOT )		/* COND.f9 */
			{
				if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_sot_cycle_max )	/* COND.f10 */
				{
					*ps4_a_sot_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
		}
	}

	return;
}

static S4 s4_bsm_chkfr_check_tos_alart_sts(
	S4 s4_a_tos_cycle_max,
	S4 s4_a_sot_cycle_max
)
{
	S4 s4_t_tmp_tos_flag;

	S4 s4_t_exit;

	s4_t_exit = 0;
	s4_t_tmp_tos_flag = 0;

	/***** 4) ToS警報状態の確認 *****/
	if(s4_a_tos_cycle_max > s4_a_sot_cycle_max)							/* COND.f11 */
	{
			s4_t_tmp_tos_flag = 1;
	}
	/* NOT ToS */
	if ((s4_t_tmp_tos_flag==0)										/* COND.f12 NOT ToS in current frame */
	&&  (st_g_bsm_loop_data.as4_flg_tos_frontline[0]==0)			/* COND.f3  NOT ToS in previous frame */
	&&  (st_g_bsm_loop_data.as4_flg_tos_end[0] == 0)) {				/* COND.f4 */
		s4_t_exit = 1;
	}

	return s4_t_exit;
}

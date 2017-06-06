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


	fl_t_tmp_theta = -( 
		PI / 180.0F * (
			st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i] +  (FL)DOA_BIN_START_ANG
		) 
	);

	if (
//		( fl_abs( afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k] ) < POW_DIFF_UP_DOWN_DOA )							/* COND. j1 */
//		&& ( fl_abs( afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k] ) < (FL)s4_t_tmp_doa_diff_up_down )		/* COND. j2 */
		(
			fl_abs(
				afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]
			) < POW_DIFF_UP_DOWN_DOA
		)							/* COND. j1 */
		&& (
			fl_abs(
				afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]
			) < (FL)s4_t_tmp_doa_diff_up_down
		)		/* COND. j2 */
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

	tmp_comp = fl_abs(afl_a_alarmed_target_current[k][0]-afl_a_Tx_float[0][8]) +	 		/* PROC.15 Rxfil + Ryfil */
				fl_abs(afl_a_alarmed_target_current[k][1]-afl_a_Tx_float[0][7]);

	return;
}


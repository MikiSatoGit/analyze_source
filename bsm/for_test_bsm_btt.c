/********************************************************************************************/
/*! 
	@brief
	TLE main process

	@param[in] (global) st_g_btt_stat.TLE
	@param[in] (global) st_tle_params.timer
	@param[out] (global) st_tle_params.timer

	@return Trailer length

	call function
	- fn_btt_tle_estimate_trailer_length()
	- fn_btt_tle_deactivate()

	@detail
*********************************************************************************************/
FL fn_btt_tle_main(									/*!< [out] Trailer length */
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	NORMAL_BSM *pst_a_object,						/*!< [in] Position and speed of objects detected by SRR */
	S4 s4_a_object_size,							/*!< [in] Number of objects */
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [in] (optional) Additional trailer or object info from other system or module */
													/*   [out(NA)] TLength -> fn_btt_set_trailer_length(retval) before AAZ */
	BTT_STAT *pst_a_btt_stat						/*!< [out] TLE_Stat */
)
{
	/*! @note (1) set lenght to UNKNOWN */
	FL fl_t_length = BTT_TRAILER_SIZE_UNKNOWN;

#ifndef _20170130_BTT_TLE_DBF_POW_DIFF
	S4 s4_t_lp_i;
	FL fl_a_tle_bf_peak[BTT_TLE_RANGE];
	FL fl_a_tle_bf_pow_diff[BTT_TLE_RANGE-(S4)1];

	/* Initialize */
	for(s4_t_lp_i = 0; s4_t_lp_i < BTT_TLE_RANGE; s4_t_lp_i++){
		fl_a_tle_bf_peak[s4_t_lp_i] = (FL)0;
	}	

	for(s4_t_lp_i = 0; s4_t_lp_i < BTT_TLE_RANGE - (S4)1; s4_t_lp_i++){
		fl_a_tle_bf_pow_diff[s4_t_lp_i] = (FL)0;
	}
#endif

	/*! @note (2) do nothing if TLE is not AVTIVE */
	if( st_g_btt_stat.TLE != BTT_RET_t.Func_Stat.ACTIVE )
	{
#ifndef _20170123_AAZ_CHECK
		/* keep the valid value of TLength after TLE is deactivated */
		if( st_g_btt_result.TLength != BTT_TRAILER_SIZE_UNKNOWN ){
			return st_g_btt_result.TLength;
		} else{
			return fl_t_length;
		}
#else
		return fl_t_length;
#endif
	}

#ifndef _20170130_BTT_TLE_DBF_POW_DIFF
	fn_btt_tle_search_peak_bf(
		(const FL (*)[CORRE_SIZE_4CH])(afl_g_cvw_lfm_ryy_matrix[0]),
		fl_a_tle_bf_peak
	);

	fn_btt_tle_calc_bf_power_diff(
		fl_a_tle_bf_peak,
		fl_a_tle_bf_pow_diff
	);

	for (s4_t_lp_i = 0; s4_t_lp_i < 30; s4_t_lp_i++ ) {
		fn_bsm_cal_trailer_range_doa_ave(
			0,
			(const FL (*)[CORRE_SIZE_4CH])(afl_g_cvw_lfm_ryy_matrix[0]),
			(256+s4_t_lp_i),
			&afl_a_doa_pow_ave[s4_t_lp_i],
			&afl_a_doa_pow_dev[s4_t_lp_i]
		);
	}
#endif

	/* Based on RDD:Fig.4.4.4-1 */
	/*! @note (3)-1 estimate trailer length while TLE timer is under BTT_TLE_MAX_TIME  */
	if( st_tle_params.timer < BTT_TLE_MAX_TIME)
	{
		/*! @note @li --> do trailer length estimation core logic  */
		fl_t_length = fn_btt_tle_estimate_trailer_length(
			/* TBD */
		);
	}
	/*! @note (3)-2 finish estimating trailer length when TLE timer is over BTT_TLE_MAX_TIME  */
	else
	{
		/*! @note @li --> deactivate TLE */
		fn_btt_tle_deactivate();
	}
	/*! @note (4) increment TLE timer  */
	st_tle_params.timer++;

#ifndef _20170123_AAZ_CHECK	//set trailer length manually
	fl_t_length = (FL)4;
#endif


	return fl_t_length;
}
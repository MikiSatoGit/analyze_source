VD fn_btt_aaz_initialize(
	FL fl_a_trailer_length,			/*!< [in] TLength */
	FL fl_a_trailer_width			/*!< [in] TWidth */
)
{
	/*! @note (1) check AAZ initialize status (Do nothing if it is not the first cycle) */
	if( st_aaz_params.First == BTT_RET_t.Bool.FALSE )
	{
		return;
	}
	/* Based on RDD:Table.4.2.6.1-1 */
	/*! @note (2) initialize AAZ internal parameters to default value */
	st_aaz_params.VarY = BTT_REAR_RANGE_LONG;	//(TBD) or BTT_REAR_RANGE_MAX?
	st_aaz_params.First = BTT_RET_t.Bool.FALSE;
	st_aaz_params.TLength_AAZ = fl_a_trailer_length;
	st_aaz_params.TLength_valid_count = (S4) 0;
	st_aaz_params.TLength_invalid_count = (S4) 0;
	st_aaz_params.TLength_unknown_count = (S4) 0;
	st_aaz_params.TWidth_AAZ = fl_a_trailer_width;
	st_aaz_params.TWidth_valid_count = (S4) 0;
	st_aaz_params.TWidth_invalid_count = (S4) 0;
	st_aaz_params.TWidth_unknown_count = (S4) 0;
	return;
}



VD fn_btt_atd_trailerobj_tracking(
	NORMAL_BSM pst_a_trailer_obj[TRAILER_BUFFSIZE],
	S4 as4_a_trailer_obj_num
#ifndef _20170119_ATD_DOADBF_CHECK
	,FL fl_a_doa_pow_ave[2][3]
	,FL fl_a_doa_pow_dev[2][3]
	,S4 s4_a_doa_bf_peak_bin
	,FL fl_a_doa_bf_peak_pow
#endif
)
{
	S4 s4_t_lp_i, s4_t_lp_j;

	S4 as4_a_trk_num = (S4)0;
	S4 as4_a_trk_num2 = (S4)0;
	S4 as4_a_tmp_trailer_obj_num = (S4)0;
	FL afl_a_trailer_obj_rx_ave = (FL)0;
	FL afl_a_trailer_obj_rx_dev = (FL)0;
	FL afl_a_trailer_obj_ry_ave = (FL)0;
	FL afl_a_trailer_obj_ry_dev = (FL)0;
	FL afl_a_trailer_obj_vy_ave = (FL)0;
	FL afl_a_trailer_obj_vy_dev = (FL)0;

#ifndef _20170119_ATD_DOADBF_CHECK
	FL afl_a_trailer_doa_pow_up = (FL)0;
	FL afl_a_trailer_doa_pow_dn = (FL)0;
	FL afl_a_trailer_doa_pow_dev_up = (FL)0;
	FL afl_a_trailer_doa_pow_dev_dn = (FL)0;
	FL afl_a_db_doa_peak_ave_diff = (FL)0;
#endif

#ifndef _20170220_BTT_TRAILEROBJ	
	/* set the powert threshold based on the curvature */
	FL afl_a_trailer_doa_pow_th = (FL)0;
	if( s4_abs(s2_g_curvr_for_base) > (S2)80 ){
		afl_a_trailer_doa_pow_th = (FL)58;
	}
	else if( s4_abs(s2_g_curvr_for_base) > (S2)40 ){
		afl_a_trailer_doa_pow_th = (FL)55;
	}
	else{
		if( s2_g_curvr_for_base < 0 ){
			/* outside: lower threshold */
			afl_a_trailer_doa_pow_th = (FL)45;
		} else{
			/* inside: higher threshold to avoid wrong detection */
			afl_a_trailer_doa_pow_th = (FL)58;
		}
	}
#endif

	/* check the detection history (12 cycles) of trailer objects */
	for( s4_t_lp_i = 0; s4_t_lp_i < BTT_OBJ_HISTORY_CYCLE; s4_t_lp_i++ ) {
		as4_a_tmp_trailer_obj_num = st_atd_params.trailer_object_num_total[s4_t_lp_i];
		if( as4_a_tmp_trailer_obj_num != (S4)0 ){
			as4_a_trk_num ++;
			for( s4_t_lp_j = 0; s4_t_lp_j < as4_a_tmp_trailer_obj_num; s4_t_lp_j++ ) {
				/* calculate the average and deviation of trailer objects within ATD range */
				afl_a_trailer_obj_rx_ave += st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Rxobs;
				afl_a_trailer_obj_rx_dev += (st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Rxobs * st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Rxobs);
				afl_a_trailer_obj_ry_ave += st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Ryobs;
				afl_a_trailer_obj_ry_dev += (st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Ryobs * st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Ryobs);
				afl_a_trailer_obj_vy_ave += st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Vyobs;
				afl_a_trailer_obj_vy_dev += (st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Vyobs * st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Vyobs);
				as4_a_trk_num2 ++;
			}
		}
	}

	if( as4_a_trk_num2 != (S4)0){
		afl_a_trailer_obj_rx_ave = afl_a_trailer_obj_rx_ave / (FL)as4_a_trk_num2;
		afl_a_trailer_obj_ry_ave = afl_a_trailer_obj_ry_ave / (FL)as4_a_trk_num2;
		afl_a_trailer_obj_vy_ave = afl_a_trailer_obj_vy_ave / (FL)as4_a_trk_num2;
		afl_a_trailer_obj_rx_dev = fl_abs((afl_a_trailer_obj_rx_dev / (FL)as4_a_trk_num2) - afl_a_trailer_obj_rx_ave * afl_a_trailer_obj_rx_ave);
		afl_a_trailer_obj_ry_dev = (afl_a_trailer_obj_ry_dev / (FL)as4_a_trk_num2) - afl_a_trailer_obj_ry_ave * afl_a_trailer_obj_ry_ave;
		afl_a_trailer_obj_vy_dev = fl_abs((afl_a_trailer_obj_vy_dev / (FL)as4_a_trk_num2) - afl_a_trailer_obj_vy_ave * afl_a_trailer_obj_vy_ave);
	}


#ifndef _20170119_ATD_DOADBF_CHECK
	/* calculate the power difference between dbf doa peak power (0-70) and doa power average (0-30) */
	/* --> if there are both trailer and heisou TV, the difference should be small */
	afl_a_db_doa_peak_ave_diff = fl_a_doa_bf_peak_pow - fl_a_doa_pow_ave[0][1];
#endif

	/* If there is object be detected more than half of history checking cycle */
	if( as4_a_trk_num > BTT_OBJ_DETECT_CYC1 ){
		if( fl_abs(afl_a_trailer_obj_rx_ave) < BTT_OBJ_X_RANGE
#ifndef _20170220_BTT_TRAILEROBJ	//_0314
		&&  afl_a_trailer_obj_ry_ave < BTT_OBJ_Y_RANGE_FORWARD
		&&  afl_a_trailer_obj_ry_ave > BTT_OBJ_Y_RANGE_BACKWARD
#else
		&&  afl_a_trailer_obj_ry_ave < BTT_OBJ_Y_RANGE
		&&  afl_a_trailer_obj_ry_dev < BTT_OBJ_DEV_TH
#endif
		&&  fl_abs(afl_a_trailer_obj_vy_ave) < BTT_OBJ_VY 
		&&  afl_a_trailer_obj_rx_dev < BTT_OBJ_DEV_TH 
		&&  afl_a_trailer_obj_vy_dev < BTT_OBJ_DEV_TH ){
			/* connect */
#ifndef _20170220_BTT_TRAILEROBJ	//_0314
			/* When driving straightly */
			if( s4_abs(s2_g_curvr_for_base) > (S2)CU1_CANOUT_CURVER_MIN_SOT){
				/* check the dbf doa power difference and doa power average */
				if( afl_a_db_doa_peak_ave_diff > (FL)5.0
				||  fl_a_doa_pow_ave[0][1] < afl_a_trailer_doa_pow_th
				){
					st_atd_params.atd_counter[1] ++; 
				} else if( as4_a_trk_num2 < (S4)10 ){
					st_atd_params.atd_counter[1] ++; 
				} else{
					st_atd_params.atd_counter[0] ++;				
				}
			}
			/* When curvature is small (10 < curv < 40 -> not accumulate ATD counter when SV make a turn) */
			else if( s4_abs(s2_g_curvr_for_base) >= (S2)10) {  
				if( fl_a_doa_pow_ave[0][1] > afl_a_trailer_doa_pow_th ){
					st_atd_params.atd_counter[0] ++;
				} else{
					st_atd_params.atd_counter[1] ++;
				}
			}
#else
			st_atd_params.atd_counter[0] ++;
#endif
		} else{
#ifndef _20170119_ATD_DOADBF_CHECK
			/* check the dbf doa power difference and doa power average */
			if( fl_a_doa_pow_ave[0][1] > afl_a_trailer_doa_pow_th 
			&&  afl_a_db_doa_peak_ave_diff < (FL)5.0 ){
				st_atd_params.atd_counter[0] ++; 
			} else{
				st_atd_params.atd_counter[1] ++; 
			}
#else
			st_atd_params.atd_counter[1] ++; 
#endif
		}
	}
#ifndef _20170119_ATD_DOADBF_CHECK
	else{
#ifndef _20170220_BTT_TRAILEROBJ	//_0314
		if( as4_a_trk_num2 > (S4)10
		&&  fl_a_doa_pow_ave[0][1] > afl_a_trailer_doa_pow_th
		&&  afl_a_db_doa_peak_ave_diff < (FL)5.0 ){
			st_atd_params.atd_counter[0] ++;
		}
		else{
			st_atd_params.atd_counter[1] ++; 
		}
#else
		if( as4_a_trk_num > BTT_OBJ_DETECT_CYC3
		&&  fl_a_doa_pow_ave[0][1] > (FL)62.0
		&&  afl_a_db_doa_peak_ave_diff < (FL)5.0 ){
			st_atd_params.atd_counter[0] ++;
		}
		else if( as4_a_trk_num < BTT_OBJ_DETECT_CYC2 ) {
			/* not connect */
			st_atd_params.atd_counter[1] ++; 
		}
		else{
			/* DO NOTHING */
		}
#endif
	}
#endif

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	for( s4_t_lp_i = 0; s4_t_lp_i < BTT_OBJ_HISTORY_CYCLE; s4_t_lp_i++ ){
		for( s4_t_lp_j = 0; s4_t_lp_j < TRAILER_BUFFSIZE; s4_t_lp_j ++ ){
			afl_g_btt_atd_obj_info[0][s4_t_lp_j][s4_t_lp_i] = st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Rxobs;
			afl_g_btt_atd_obj_info[1][s4_t_lp_j][s4_t_lp_i] = st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Ryobs;
			if( st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Vyobs == (FL)0 ){
				afl_g_btt_atd_obj_info[2][s4_t_lp_j][s4_t_lp_i] = (FL)-120;
			} else {
				afl_g_btt_atd_obj_info[2][s4_t_lp_j][s4_t_lp_i] = st_atd_params.trailer_object_total[s4_t_lp_i][s4_t_lp_j].fl_Vyobs * (FL)3.6;
			}
		}
	}
	afl_g_btt_atd_obj_tracking[0] = afl_a_trailer_obj_rx_ave;
	afl_g_btt_atd_obj_tracking[1] = afl_a_trailer_obj_ry_ave;
	afl_g_btt_atd_obj_tracking[2] = afl_a_trailer_obj_vy_ave;
	afl_g_btt_atd_obj_tracking[3] = afl_a_trailer_obj_rx_dev;
	afl_g_btt_atd_obj_tracking[4] = afl_a_trailer_obj_ry_dev;
	afl_g_btt_atd_obj_tracking[5] = afl_a_trailer_obj_vy_dev;

	as4_g_btt_atd_counter[0] = as4_a_trk_num;	/* there is object detected in this cycle */
	as4_g_btt_atd_counter[1] = as4_a_trk_num2;	/* total objects detected in 12 cycles */
	as4_g_btt_atd_counter[2] = st_atd_params.atd_counter[0];	/* connect counter */
	as4_g_btt_atd_counter[3] = st_atd_params.atd_counter[1];	/* not connect counter */

	afl_g_btt_atd_doa_pow_ave[0] = fl_a_doa_pow_ave[0][1];
	afl_g_btt_atd_doa_pow_ave[1] = afl_a_db_doa_peak_ave_diff;
#endif

	return;
}
#endif

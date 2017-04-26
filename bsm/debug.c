VD fn_btt_atd_trailerobj_tracking(
	NORMAL_BSM pst_a_trailer_obj[TRAILER_BUFFSIZE],
	S4 as4_a_trailer_obj_num
	,FL fl_a_doa_pow_ave[2][3]
	,FL fl_a_doa_pow_dev[2][3]
	,S4 s4_a_doa_bf_peak_bin
	,FL fl_a_doa_bf_peak_pow
)
{

	/* If there is object be detected more than half of history checking cycle */
	if( as4_a_trk_num() > (S4)BTT_OBJ_DETECT_CYC1 ){
		if( fl_abs(afl_a_trailer_obj_rx_ave) < BTT_OBJ_X_RANGE
		&&  afl_a_trailer_obj_ry_ave < BTT_OBJ_Y_RANGE_FORWARD
		&&  afl_a_trailer_obj_ry_ave > BTT_OBJ_Y_RANGE_BACKWARD
		&&  fl_abs(afl_a_trailer_obj_vy_ave) < BTT_OBJ_VY 
		&&  afl_a_trailer_obj_rx_dev < BTT_OBJ_DEV_TH 
		&&  afl_a_trailer_obj_vy_dev < BTT_OBJ_DEV_TH ){
			MIKI_TEST = 1;
		}
	}














	return;
}



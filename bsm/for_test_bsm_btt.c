VD fn_btt_atd_main(
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	S1 s1_a_shift_flg,								/*!< [in] Transmission state (D/R/N/P) */
	NORMAL_BSM *pst_a_object,						/*!< [in] Position and speed of objects detected by SRR */
	S4 s4_a_object_size,							/*!< [in] Number of objects */
#ifndef _20170119_ATD_DOADBF_CHECK
	FL fl_a_doa_pow_ave[2][3],
	FL fl_a_doa_pow_dev[2][3],
	S4 s4_a_doa_bf_peak_bin,
	FL fl_a_doa_bf_peak_pow,
#endif
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [in] (optional) Additional trailer or object info from other system or module */
	BTT_RESULT* pst_a_btt_result					/*!< [out] TFlag */
)
{
	/*! @note (1) do nothing if ATD is not AVTIVE */
	if( st_g_btt_stat.ATD != BTT_RET_t.Func_Stat.ACTIVE )
	{
		return;
	}
	/* Based on RDD:Fig.4.3.4-1 */
	/*! @note (2)-1 proceed to ATD process if Shift is not Reverse */
	if( s1_a_shift_flg != (S1) 0 )	/* (tentative) not R */
	{
		/*! @note @li (i) detect trailer when Subject speed is over BTT_ACTIVE_SPEED_TH  */
		if( fl_a_self_v > BTT_ACTIVE_SPEED_TH )
		{







			/*! @note @li (ii)-1 detect trailer while ATD timer is under BTT_ATD_MAX_TIME  */
			if( st_atd_params.timer < BTT_ATD_MAX_TIME)
			{

/* NGNGNGNGNGNGNGNGNGNGNGNGNGNGNG */
				/*! @note @li keep detecting trailer while TFlag is UNKNOWN */
				if( pst_a_btt_result->TFlag == BTT_RET_t.TFlag.UNKNOWN )
				{
					/*! @note @li --> do trailer detection core logic  */
					pst_a_btt_result->TFlag = fn_btt_atd_detect_trailer(
#ifndef _20161209_BTT_ATD_TRACKING
						fl_a_self_v,				/*!< [in] Subject Vehicle speed [km/h] */
						s4_a_curve_r,				/*!< [in] Road curvature [m] */
						pst_a_object,				/*!< [in] Current trailer objects */
						s4_a_object_size,			/*!< [in] Current Number of trailer objects */
#ifndef _20170119_ATD_DOADBF_CHECK
						fl_a_doa_pow_ave,
						fl_a_doa_pow_dev,
						s4_a_doa_bf_peak_bin,
						fl_a_doa_bf_peak_pow,
#endif
						pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
						pst_a_aux_trailer_info		/*!< [in] (optional) Additional trailer or object info from other system or module */
#endif
					);

					/*! @note @li ----> deactivate ATD when trailer presence is detected  */
					if( pst_a_btt_result->TFlag == BTT_RET_t.TFlag.CONNECT )
					{
						fn_btt_atd_deactivate();
					}
					/*! @note @li ----> deactivate ATD when trailer absence is detected  */
					else if( pst_a_btt_result->TFlag == BTT_RET_t.TFlag.NOTCONNECT )
					{
						fn_btt_atd_deactivate();
					}
					/*! @note @li ----> keep ATD active while trailer presence/absence is not detected  */
					else	/* TFlag == BTT_TRAILER_FLAG_UNKNOWN */
					{
						/* wait for next cycle */
					}
				}
/* NGNGNGNGNGNGNGNGNGNGNGNGNGNGNG */


			}







			/*! @note @li (ii)-2 finish detecting trailer when ATD timer is over BTT_ATD_MAX_TIME  */
			else
			{
				/*! @note @li --> set TFlag to UNKNOWN */
				pst_a_btt_result->TFlag = BTT_RET_t.TFlag.UNKNOWN;
				/*! @note @li --> deactivate ATD */
				fn_btt_atd_deactivate();
			}





			/*! @note @li (iii) increment ATD timer  */
			st_atd_params.timer++;






		}
		else
		{
			/* wait for next cycle */
		}
	}
	/*! @note (2)-2 initialize ATD if Shift is Reverse */
	else
	{
		fn_btt_atd_initialize();
	}
	return;
}

/**
 * @file BSM_BTT.c
 * @brief Functions for BTT(BSM with Trailer Towing)
 * @author DIAM SafetySystems M.Sato
 * date 16.10.03	t01
 */

/****************************************************************************/
/*							include											*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../parameter_sig.h"
#ifndef _291B_20161101_BTT_OUTPUT_T
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif
#include "bsm_btt.h"

#include "../../../system/vehicle_spec_mwr.h"

#ifndef _20161209_BTT_ATD_TRACKING
#include "../target/init_cvw.h"
#include "../target/bsm_recog_03.h"
#include "../../common/cmn_signal.h"
#include "../bsm_main.h"
#endif

#include "../target/func_fmcw.h"
#include "../target/bsm_recog_05.h"

/****************************************************************************/
/*							btt status code class							*/
/****************************************************************************/
//const BTT_CAN_t CAN_t = {
//	BTT_CAN_CONFIG_DISABLE,
//	BTT_CAN_CONFIG_ENABLE
//};
//const BTT_DRV_SW_t DRV_SW_t = {
//	BTT_DRV_SW_OFF,
//	BTT_DRV_SW_ON
//};
//const BTT_FINAL_STAT_t FINAL_STAT_t = {
//	BTT_STATE_DISABLE,
//	BTT_STATE_OFF,
//	BTT_STATE_ON,
//	BTT_STATE_OFFTEMP
//};
//const BTT_DRV_STAT_t DRV_STAT_t = {
//	BTT_DRV_STATE_DISABLE,
//	BTT_DRV_STATE_OFF,
//	BTT_DRV_STATE_PENDING,
//	BTT_DRV_STATE_CONNECT,
//	BTT_DRV_STATE_NOTCONNECT,
//	BTT_DRV_STATE_OFFTEMP
//};
//const BTT_FUNC_STAT_t FUNC_STAT_t = {
//	BTT_FUNC_DEACTIVE,
//	BTT_FUNC_ACTIVE,
//	BTT_FUNC_DISABLE,
//	BTT_FUNC_ENABLE
//};
//const BTT_TFLAG_t TFLAG_t = {
//	BTT_TRAILER_FLAG_UNKNOWN,
//	BTT_TRAILER_FLAG_CONNECT,
//	BTT_TRAILER_FLAG_NOTCONNECT
//};
//const BTT_TSIZE_STAT_t TSIZE_STAT_t = {
//	BTT_TRAILER_SIZE_STAT_UNKNOWN,
//	BTT_TRAILER_SIZE_STAT_VALID,
//	BTT_TRAILER_SIZE_STAT_INVALID
//};
//const BTT_CMN_INIT_STAT_t CMN_INIT_t = {
//	BTT_UNINITIALIZED,
//	BTT_INITIALIZED
//};
//const BTT_BOOL_t BOOL_t = {
//	BTT_TRUE,
//	BTT_FALSE
//};


/*! @var  BTT_RET_t
	@brief BTT_RETRUN_t class value

	This variable consists of :
	- BTT_CAN_t
	- BTT_DRV_SW_t
	- BTT_FINAL_STAT_t
	- BTT_DRV_STAT_t
	- BTT_FUNC_STAT_t
	- BTT_TFLAG_t
	- BTT_TSIZE_STAT_t
	- BTT_CMN_INIT_STAT_t
	- BOOL_t
	
*/
const BTT_RETRUN_t BTT_RET_t = {
	BTT_CAN_CONFIG_DISABLE,		/*!< BTT_CAN_t */
	BTT_CAN_CONFIG_ENABLE,		/*!< BTT_CAN_t */
	BTT_DRV_SW_OFF,				/*!< BTT_DRV_SW_t */
	BTT_DRV_SW_ON,				/*!< BTT_DRV_SW_t */
	BTT_STATE_DISABLE,			/*!< BTT_FINAL_STAT_t */
	BTT_STATE_OFF,				/*!< BTT_FINAL_STAT_t */
	BTT_STATE_ON,				/*!< BTT_FINAL_STAT_t */
	BTT_STATE_OFFTEMP,			/*!< BTT_FINAL_STAT_t */
	BTT_DRV_STATE_DISABLE,		/*!< BTT_DRV_STAT_t */
	BTT_DRV_STATE_OFF,			/*!< BTT_DRV_STAT_t */
	BTT_DRV_STATE_PENDING,		/*!< BTT_DRV_STAT_t */
	BTT_DRV_STATE_CONNECT,		/*!< BTT_DRV_STAT_t */
	BTT_DRV_STATE_NOTCONNECT,	/*!< BTT_DRV_STAT_t */
	BTT_DRV_STATE_OFFTEMP,		/*!< BTT_DRV_STAT_t */
	BTT_FUNC_DEACTIVE,			/*!< BTT_FUNC_STAT_t */
	BTT_FUNC_ACTIVE,			/*!< BTT_FUNC_STAT_t */
	BTT_FUNC_DISABLE,			/*!< BTT_FUNC_STAT_t */
	BTT_FUNC_ENABLE,			/*!< BTT_FUNC_STAT_t */
	BTT_TRAILER_FLAG_UNKNOWN,	/*!< BTT_TFLAG_t */
	BTT_TRAILER_FLAG_CONNECT,	/*!< BTT_TFLAG_t */
	BTT_TRAILER_FLAG_NOTCONNECT,/*!< BTT_TFLAG_t */
	BTT_TRAILER_SIZE_STAT_UNKNOWN,	/*!< BTT_TSIZE_STAT_t */
	BTT_TRAILER_SIZE_STAT_VALID,	/*!< BTT_TSIZE_STAT_t */
	BTT_TRAILER_SIZE_STAT_INVALID,	/*!< BTT_TSIZE_STAT_t */
	BTT_UNINITIALIZED,			/*!< BTT_CMN_INIT_STAT_t */
	BTT_INITIALIZED,			/*!< BTT_CMN_INIT_STAT_t */
	BTT_TRUE,					/*!< BOOL_t */
	BTT_FALSE					/*!< BOOL_t */
};

/****************************************************************************/
/*							global variable									*/
/****************************************************************************/
/*! @var  GLOBAL VAR st_g_btt_stat
	@brief BTT_STAT class

	This variable consists of :
	- BSM_final
	- BTT_final
	- ATD
	- TLE
	- TWE (TBD)
	- TTM (TBD)
	- AAZ
	- BTT_initialized
*/
BTT_STAT st_g_btt_stat = {
	BTT_STATE_DISABLE,		/*!< BSM_final */
	BTT_STATE_DISABLE,		/*!< BTT_final */
	BTT_DRV_STATE_DISABLE,	/*!< BTT_drv */
	BTT_FUNC_DEACTIVE,		/*!< ATD */
	BTT_FUNC_DEACTIVE,		/*!< TLE */
	BTT_FUNC_DEACTIVE,		/*!< TWE */
	BTT_FUNC_DEACTIVE,		/*!< TTM */
	BTT_FUNC_DEACTIVE,		/*!< AAZ */
	BTT_UNINITIALIZED		/*!< BTT_initialized */
#ifndef _20170116_BTT_STAT_RESET
	,BTT_FALSE
	,(S4)0
#endif
};

/*! @var  GLOBAL VAR st_g_btt_result
	@brief BTT_RESULT class

	This variable consists of :
	- TFlag
	- TLength
	- TLength_stat
	- TWidth
	- TWidth_stat
*/
BTT_RESULT st_g_btt_result = {
	BTT_TRAILER_FLAG_UNKNOWN,		/*!< TFlag */
	BTT_TRAILER_SIZE_UNKNOWN,		/*!< TLength */
	BTT_TRAILER_SIZE_STAT_UNKNOWN,	/*!< TLength_stat */
	BTT_TRAILER_SIZE_UNKNOWN,		/*!< TWidth */
	BTT_TRAILER_SIZE_STAT_UNKNOWN	/*!< TWidth_stat */
};

/*! @var  GLOBAL VAR st_g_btt_alertarea
	@brief BTT_ALERTAREA class

	This variable consists of :
	- BSM_STANDARD
	- BTT_REAR
	- BTT_SIDE
*/
BTT_ALERTAREA st_g_btt_alertarea = {
	BTT_REAR_RANGE_UNKNOWN,	/*!< BSM_STANDARD:Ymax */
	BTT_REAR_RANGE_UNKNOWN,	/*!< BSM_STANDARD:Ymin */
	BTT_SIDE_RANGE_UNKNOWN,	/*!< BSM_STANDARD:Xmax */
	BTT_SIDE_RANGE_UNKNOWN,	/*!< BSM_STANDARD:Xmin */
	BTT_REAR_RANGE_UNKNOWN,	/*!< BTT_REAR:VarY */
	BTT_REAR_RANGE_UNKNOWN,	/*!< BTT_REAR:VarYmax */
	BTT_SIDE_RANGE_UNKNOWN,	/*!< BTT_SIDE:VarXin */
	BTT_SIDE_RANGE_UNKNOWN,	/*!< BTT_SIDE:VarXout */
	BTT_SIDE_RANGE_UNKNOWN	/*!< BTT_SIDE:VarXmax */
};

/****************************************************************************/
/*							global variable (for test)						*/
/****************************************************************************/
/*! @var  GLOBAL VAR st_g_bsm_alertarea_for_test
	@brief BSM_STANDARD class

	This variable consists of :
	- Ymax
	- Ymin
	- Xmax
	- Xmin
*/
BSM_STANDARD st_g_bsm_alertarea_for_test = {
	BTT_REAR_RANGE_UNKNOWN,	/*!< Ymax */
	BTT_REAR_RANGE_UNKNOWN,	/*!< Ymin */
	BTT_SIDE_RANGE_UNKNOWN,	/*!< Xmax */
	BTT_SIDE_RANGE_UNKNOWN	/*!< Xmin */
};

/*! @var  GLOBAL VAR st_g_cluster_info_for_test
	@brief BTT_CLUSTER_INFO class

	This variable consists of :
	- dummy (TBD)
*/
BTT_CLUSTER_INFO st_g_cluster_info_for_test = {
	CFL_UNKNOWN_VALUE	/*!< dummy */
};

/*! @var  GLOBAL VAR st_g_aux_trailer_info_for_test
	@brief BTT_AUX_TRAILER_INFO class

	This variable consists of :
	- dummy (TBD)
*/
BTT_AUX_TRAILER_INFO st_g_aux_trailer_info_for_test = {
	CFL_UNKNOWN_VALUE	/*!< dummy */
};

/*! @var  GLOBAL VAR st_g_hitch_angle_for_test
	@brief BTT_HITCH_ANGLE class

	This variable consists of :
	- dummy (TBD)
*/
BTT_HITCH_ANGLE st_g_hitch_angle_for_test = {
	CFL_UNKNOWN_VALUE	/*!< dummy */
};

/****************************************************************************/
/*							private variable								*/
/****************************************************************************/
/*! @var  PRIVATE VAR st_atd_params
	@brief BTT_ATD_PARAM class (internal parameter for ATD)

	This variable consists of :
	- timer
*/
BTT_ATD_PARAM st_atd_params = {
	(S4) 0	/*!< timer */
};

/*! @var  PRIVATE VAR st_tle_params
	@brief BTT_TLE_PARAM class (internal parameter for TLE)

	This variable consists of :
	- timer
*/
BTT_TLE_PARAM st_tle_params = {
	(S4) 0	/*!< timer */
};

/*! @var  PRIVATE VAR st_twe_params
	@brief BTT_TWE_PARAM class (internal parameter for TWE)

	This variable consists of :
	- timer
*/
BTT_TWE_PARAM st_twe_params = {
	(S4) 0	/*!< timer */
};

/*! @var  PRIVATE VAR st_aaz_params
	@brief BTT_AAZ_PARAM class (internal parameter for AAZ)

	This variable consists of :
	- VarY
	- First
	- TLength_AAZ
	- TLength_valid_count
	- TLength_invalid_count
	- TLength_unknown_count
	- TWidth_AAZ (TBD)
	- TWidth_valid_count (TBD)
	- TWidth_invalid_count (TBD)
	- TWidth_unknown_count (TBD)
*/
BTT_AAZ_PARAM st_aaz_params = {
	BTT_REAR_RANGE_UNKNOWN,		/*!< VarY */
	BTT_TRUE,					/*!< First */
	BTT_TRAILER_SIZE_UNKNOWN,	/*!< TLength_AAZ */
	(S4) 0,						/*!< TLength_valid_count */
	(S4) 0,						/*!< TLength_invalid_count */
	(S4) 0,						/*!< TLength_unknown_count */
	BTT_TRAILER_SIZE_UNKNOWN,	/*!< TWidth_AAZ */
	(S4) 0,						/*!< TWidth_valid_count */
	(S4) 0,						/*!< TWidth_invalid_count */
	(S4) 0						/*!< TWidth_unknown_count */
};

/****************************************************************************/
/*							function(for test)								*/
/****************************************************************************/

/********************************************************************************************/
/*!
	@brief
	set BTT parameter for test

	@param[in] (global) st_g_btt_stat.BTT_initialized
	@param[out] (global) st_g_btt_stat.ATD
	@param[out] (global) st_g_btt_stat.TLE
	@param[out] (global) st_g_btt_stat.TWE
	@param[out] (global) st_g_btt_stat.TTM

	@return void

	@detail
	This function is used for test only.\n
	Initial configuration of BTT is set by this function.\n
	These parameters should be set once at the beginning of the whole process\n

*********************************************************************************************/
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
						(S5)miki5_1 = subsubsubsubsub_1;
					}
					else if(hogehoge4_2)
					{
						(S5)miki5_2 = subsubsubsubsub_2;
					}
					else if(hogehoge4_3)
					{
						(S5)miki5_3 = subsubsubsubsub_2;
					}
					else
					{
						(S5)miki5_4 = subsubsubsubsub_3;
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




	/* availability of sub function */
	/*! @note (2) set ENABLE/DISABLE state of sub function */
	st_g_btt_stat.ATD = BTT_RET_t.Func_Stat.ENABLE;
	st_g_btt_stat.TLE = BTT_RET_t.Func_Stat.ENABLE;
	st_g_btt_stat.AAZ = BTT_RET_t.Func_Stat.ENABLE;	//_20161201_BUG_T
#ifndef _20170223_BTT_TWE	// enable TWE
	st_g_btt_stat.TWE = BTT_RET_t.Func_Stat.ENABLE;
#else
	st_g_btt_stat.TWE = BTT_RET_t.Func_Stat.DISABLE;
#endif
	st_g_btt_stat.TTM = BTT_RET_t.Func_Stat.DISABLE;

	/* Based on RDD:Table.4.1.3.1-1 */
	/*! @note (3) set standard BSM alert area */
	pst_a_bsm_alertarea_for_test->Ymin = (FL) 1.0;
	pst_a_bsm_alertarea_for_test->Ymax = (FL) -7.0;
	pst_a_bsm_alertarea_for_test->Xmin = (FL) 0.5;
	pst_a_bsm_alertarea_for_test->Xmax = (FL) 3.8;

	/* TBD */
	/*! @note (4) Initialize TBD parameter */
	pst_a_cluster_info->dummy = CFL_UNKNOWN_VALUE;
	pst_a_aux_trailer_info->dummy = CFL_UNKNOWN_VALUE;
	pst_a_hitch_angle->dummy = CFL_UNKNOWN_VALUE;

	return;
}

/********************************************************************************************/
/*! 
	@brief
	ATD main process

	@param[in] (global) st_g_btt_stat.ATD
	@param[in] (global) st_atd_params.timer
	@param[out] (global) st_atd_params.timer

	@return void

	call function
	- fn_btt_atd_detect_trailer()
	- fn_btt_atd_deactivate()
	- fn_btt_atd_initialize()

	@detail
*********************************************************************************************/
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
//	for(s4_t_lp_i = 0; s4_t_lp_i < BTT_TLE_RANGE - 1; s4_t_lp_i++){
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


VD fn_btt_initialize(
	U1 u1_a_bsm_configuration,			/*!< [in] BSM CAN configuration */
	U1 u1_a_bsm_drv_cmd,				/*!< [in] BSM on/off switch */
	U1 u1_a_btt_configuration,			/*!< [in] BTT CAN Configuration */
	U1 u1_a_btt_drv_cmd,				/*!< [in] BTT on/off switch */
	BSM_STANDARD st_a_bsm_alertarea		/*!< [in] Standard BSM alert area */
)
{

#ifndef _20170116_BTT_STAT_RESET
	if ((fl_g_v_self_bsm_for_base > BTT_ACTIVE_SPEED_TH)) {
		st_g_btt_stat.BTT_RESET = BTT_TRUE;
	}
	if( st_g_btt_stat.BTT_RESET == BTT_TRUE
	 && st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED
	 && fl_g_v_self_bsm_for_base < (FL)0.5 ){
		 st_g_btt_stat.BTT_timer ++;
		 if(st_g_btt_stat.BTT_timer > (S4)150){
			st_g_btt_stat.BTT_initialized = BTT_RET_t.Init_Stat.UNINITIALIZED;
			st_g_btt_stat.BTT_RESET = BTT_FALSE;
			st_g_btt_stat.BTT_timer = (S4)0;
			st_g_btt_stat.ATD = BTT_RET_t.Func_Stat.ENABLE;
		}
	}
#endif
	/*! @note (1) check initialize status (Do nothing if already initilaized) */
	if(st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED )
	{
		return;
	}

	/*! @note (2) inistialize BSM standard area */
	/* Based on RDD:Table.4.1.3.1-1 */
	st_g_btt_alertarea.standard = st_a_bsm_alertarea;

	/*! @note (3) initialize BTT area */
	/* Based on RDD:Table.2.2.6.2-1 */
	st_g_btt_result.TFlag = BTT_RET_t.TFlag.UNKNOWN;		// _20161130_T modified TFlag initial value
	fn_btt_set_trailer_length( BTT_TRAILER_SIZE_UNKNOWN );
	fn_btt_set_trailer_width( BTT_TRAILER_SIZE_UNKNOWN );
	st_g_btt_alertarea.rear.VarY = (FL) 0.0;
	st_g_btt_alertarea.rear.VarYmax = BTT_REAR_RANGE_MAX;	// value TBD
	st_g_btt_alertarea.side.VarXin = (FL) 0.0;
	st_g_btt_alertarea.side.VarXmax = (FL) 0.0;
	st_g_btt_alertarea.side.VarXout = (FL) 0.0;	// TBD

	/*! @note (4) activate trailer detection function(TTM,ATD) */
	/* Based on RDD:Fig.2.2.7.1-1 */
	fn_btt_ttm_activate();
	fn_btt_atd_activate();
	fn_btt_atd_initialize();
	/* TLE will be activated after ATD detects trailer*/
	/* TWE will be activated after ATD detects trailer*/

	/*! @note (5) update BSM_Final_Stat (BTT initialize) */
	fn_btt_set_bsm_final_state(
		u1_a_bsm_configuration,
		u1_a_bsm_drv_cmd
	);

	/*! @note (6) update BTT_Final_Stat (BTT initialize) */
	fn_btt_set_btt_final_state(
		u1_a_btt_configuration,
		u1_a_btt_drv_cmd,
		st_g_btt_result
	);

	/*! @note (7) activate alert zone adjustment function(AAZ) if BTT SW is ON */
	/* Based on RDD:Fig.2.2.7.1-1 */
	if( u1_a_btt_drv_cmd == BTT_RET_t.Drv_SW.ON )
	{
		fn_btt_aaz_activate();
	}

	/*! @note (8) set BTT initialize state to INITIALIZED */
	st_g_btt_stat.BTT_initialized = BTT_RET_t.Init_Stat.INITIALIZED;

	return;
}

U1 fn_btt_atd_detect_trailer(						/*!< [out] trailer flag  */
#ifndef _20161209_BTT_ATD_TRACKING
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	NORMAL_BSM *pst_a_object,						/*!< [in] (Current) Position and speed of objects detected by SRR */
	S4 s4_a_object_size,							/*!< [in] (Current) Number of objects */
#ifndef _20170119_ATD_DOADBF_CHECK
	FL fl_a_doa_pow_ave[2][3],
	FL fl_a_doa_pow_dev[2][3],
	S4 s4_a_doa_bf_peak_bin,
	FL fl_a_doa_bf_peak_pow,
#endif
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info	/*!< [in] (optional) Additional trailer or object info from other system or module */
#endif
)
{
	S4 s4_t_lp_i;

	U1 u1_t_btt_trailer_flg = BTT_RET_t.TFlag.UNKNOWN;

#ifndef _20161209_BTT_ATD_TRACKING
	fn_btt_atd_trailerobj_tracking(
		pst_a_object,
		s4_a_object_size
#ifndef _20170119_ATD_DOADBF_CHECK
		,fl_a_doa_pow_ave
		,fl_a_doa_pow_dev
		,s4_a_doa_bf_peak_bin
		,fl_a_doa_bf_peak_pow
#endif
	);	

	if( st_atd_params.atd_counter[0] > BTT_ATD_CONNECT_TH ){
		u1_t_btt_trailer_flg = BTT_RET_t.TFlag.CONNECT;
	} 
	if( (st_atd_params.atd_counter[1] > BTT_ATD_NOTCONNECT_TH)
	&&  (st_atd_params.atd_counter[1] - st_atd_params.atd_counter[0] > BTT_ATD_CNT_DIFF) ){
		u1_t_btt_trailer_flg = BTT_RET_t.TFlag.NOTCONNECT;

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
		/* set trailer object to unknown value for VI output */
		for(s4_t_lp_i=0; s4_t_lp_i<6; s4_t_lp_i++){
			afl_g_btt_atd_obj_tracking[s4_t_lp_i] = (FL)-120;
		}
#endif
	}
#endif


	/*! @note  TBD */
	/*! @test ATD Core Logic Output Signal Pattern\n
		(1) u1_t_btt_trailer_flg = BTT_RET_t.TFlag.CONNECT;	\n
		(2) u1_t_btt_trailer_flg = BTT_RET_t.TFlag.NOTCONNECT;	\n
	*/

	return u1_t_btt_trailer_flg;
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












#ifndef _20170119_ATD_DOADBF_CHECK	//_0422NG
	else{
#ifndef _20170220_BTT_TRAILEROBJ	//_0314NG
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

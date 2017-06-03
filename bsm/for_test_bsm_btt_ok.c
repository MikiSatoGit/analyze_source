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
	{																	/* SUBPROCESS(1) ↓ */
		return;
	}																	/* SUBPROCESS(1) ↑ */


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
	{																	/* SUBPROCESS(2) ↓ */
		miki1_1=sub; miki1_2 = (S1)sub; miki1_3() ; miki1_4((S1)arg1_1);
		if(hogehoge1)
		{																/* SUBSUBPROCESS(1) ↓ */



			miki2_1 = subsub_1(
				(S1)arg2_1_1,
				arg2_1_2 );
			miki2_2 
			= subsub_2(
				(S1)arg2_2_1,
				arg2_2_2
			);
			for(i=0; i<hogehoge2; i++)
			{															/* SUBSUBSUBPROCESS(1) ↓ */
				miki3 = (S1)subsubsub(arg3_1,arg3_2,arg3_3);
				while(hogehoge3_1)
				{														/* SUBSUBSUBSUBPROCESS(1) ↓ */
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
				}														/* SUBSUBSUBSUBPROCESS(1) ↑ */

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

				{														/* SUBSUBSUBSUBPROCESS(3) ↓ */
					miki4_3 = subsubsubsub_mode_default(
						(S1) arg4_3_1,
						arg4_3_2,
						arg4_3_3
					);
				}														/* SUBSUBSUBSUBPROCESS(3) ↑ */

			}															/* SUBSUBSUBPROCESS(1) ↑ */

		}																/* SUBSUBPROCESS(2) ↑ */
		else
		{
			hogehoge1_ELSE();
		}
	}																	/* SUBPROCESS(2) ↑ */




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

static VD fn_bsm_low_calc_deviation(
	S4 s4_a_forward_priod,
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_stationary_doa_line[N_DOA],
	S4 *ps4_a_backward_priod,
	FL afl_a_buf_dev[2],
    S4 s4_a_v0_doa,
    S4 *ps4_a_fast_sot_num,
    S4 *ps4_a_not_fast_sot_num,
    FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
    FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{

	S4 fast_sot_limit_line[N_DOA];


	afl_a_buf_dev[0] = 999.9F;
	afl_a_buf_dev[1] = 999.9F;

	if(
		fl_g_v_self_bsm_for_base>5.0F
	)
	{
		{
			afl_a_buf_dev[0] = calc_deviation_of_doa_freq_line_stationary_2(
				(const S4 (*)[1])as4_a_nearfield_doa_i,
				SLOW_SOT_FREQ_BIN_START_I,
				(const S4 *)as4_stationary_doa_line,
				0
				,ps4_a_backward_priod
				,s4_a_v0_doa
				,ps4_a_fast_sot_num
				,ps4_a_not_fast_sot_num
				,fast_sot_limit_line
				,(const FL (*)[4])afl_a_sot_check_object_i
			);
		}

		{
			afl_a_buf_dev[1] = calc_deviation_of_doa_freq_line_stationary_2(
				(const S4 (*)[1])as4_a_nearfield_doa_q,
				SLOW_SOT_FREQ_BIN_START_Q-SLOW_SOT_FREQ_BIN_RANGE,
				(const S4 *)as4_stationary_doa_line,
				1
				,ps4_a_backward_priod
				,s4_a_v0_doa
				,ps4_a_fast_sot_num
				,ps4_a_not_fast_sot_num
				,fast_sot_limit_line
				,(const FL (*)[4])afl_a_sot_check_object_q
			);
		}
	}
	
	return;
}

static VD fn_bsm_sel_exobj_bumper_reflection(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
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

	for (s4_t_lp_normal = (S4)0; s4_t_lp_normal < s4_a_pair_num_current; s4_t_lp_normal++) {
		if (ast_a_normal_current[s4_t_lp_normal].fl_Robs != CFL_UNKNOWN_VALUE) {			/* COND.b2 */
			/* 条件チェック用に各情報を変換 */
			fl_t_obj_power = (ast_a_normal_current[s4_t_lp_normal].fl_power_up_music + ast_a_normal_current[s4_t_lp_normal].fl_power_dn_music) * (FL)0.5;
			fl_t_abs_robs = fl_abs(ast_a_normal_current[s4_t_lp_normal].fl_Robs);
			fl_t_abs_vobs = fl_abs(ast_a_normal_current[s4_t_lp_normal].fl_Vobs);

			/* 閾値を設定 */
			fl_t_thd_exobj_range = (FL)9.0;
			fl_t_thd_exobj_power = fl_smap_new(CFL_D_MAP_EXOBJ_POWER, CU2_MAP_EXOBJ_POWER_INDEX, fl_t_abs_robs);

			/* 不要物標を削除 */
			if ((ast_a_normal_current[s4_t_lp_normal].s4_flg_dc != (S4)OBJECT_TYPE_2F)		/* COND.n2 */
			&&	(fl_t_abs_robs < fl_t_thd_exobj_range)										/* COND.n3 */
			&&	(ast_a_normal_current[s4_t_lp_normal].fl_Ryobs < (FL)-EKF_RY_SIDE)			/* COND.n4 */
			&&	(fl_t_abs_vobs < ((FL)5.0 * (FL)VCOF))										/* COND.n5 */
			&&	(fl_t_obj_power < fl_t_thd_exobj_power)) {									/* COND.n6 */
				fn_init(&ast_a_normal_current[s4_t_lp_normal], (S4)1);
			}
		}
	}

	if(A==B)
	{
		if(A==C)
		{
			A=D;
		}
	}

	return;
}


VD fn_btt_tle_initialize()
{
	st_tle_params.timer = 0;
	fn_btt_set_trailer_length(
		hogege1,
		hogege2,
		(S4)BTT_TRAILER_SIZE_UNKNOWN
	);

	if(a==1 && b==1)
	{
		hogehoge3 = 1;
		if(c==1)
		{
			hogehoge3 = 11;
		}
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
//	else if(a==1)
//	{
//		a=2;
//		return;
//	}
//	else
//	{
//		a=3;
//		return;
//	}


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

VD fn_btt_aaz_activate()
{
	/*! @note (1) set AAZ state to ACTIVE if AAZ is ENABLE */
	if( st_g_btt_stat.AAZ == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.AAZ = BTT_RET_t.Func_Stat.ACTIVE;

		/* Based on RDD:Table.4.2.6.1-1 */
		/*! @note (2) initialize AAZ internal parameters to initial value */
		st_aaz_params.VarY = (FL) 0.0;
		st_aaz_params.First = BTT_RET_t.Bool.TRUE;
		st_aaz_params.TLength_AAZ = BTT_TRAILER_SIZE_UNKNOWN;
		st_aaz_params.TLength_valid_count = (S4) 0;
		st_aaz_params.TLength_invalid_count = (S4) 0;
		st_aaz_params.TLength_unknown_count = (S4) 0;
		st_aaz_params.TWidth_AAZ = BTT_TRAILER_SIZE_UNKNOWN;
		st_aaz_params.TWidth_valid_count = (S4) 0;
		st_aaz_params.TWidth_invalid_count = (S4) 0;
		st_aaz_params.TWidth_unknown_count = (S4) 0;
	}
	return;
}


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


	fl_t_tmp_theta = -(PI / 180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i] +  (FL)DOA_BIN_START_ANG));

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

	tmp_comp = fl_abs(afl_a_alarmed_target_current[k][0]-afl_a_Tx_float[0][8]) +	 		/* PROC.15 Rxfil + Ryfil */
				fl_abs(afl_a_alarmed_target_current[k][1]-afl_a_Tx_float[0][7]);

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


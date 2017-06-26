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

	for(i=0;i<2;i++)
	{
		for_test = True;
	}

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
	{ miki = done; if(a==0){ miki = next; } }


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
	dummy entry for BTT test

	@return void

	call function
	- fn_btt_initialize()
	- fn_btt_main()
	- fn_btt_set_btt_final_state()

	@detail
	This function is used for test only.\n
	BTT main process should be operated as described in this function.\n

*********************************************************************************************/
VD enter_btt_dummy(
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
	U1 u1_a_bsm_drv_cmd,							/*!< [in] Driver's command to turn BTT on or off */
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [in] (optional) Additional trailer or object info from other system or module */
	BTT_HITCH_ANGLE *pst_a_hitch_angle,				/*!< [in] (optional) Angle between subject vehicle and trailer */
	U1 *pu1_alarm_flg,								/*!< [out] Alarm ON or OFF */
	NORMAL_BSM *pst_a_target,						/*!< [out] Position and speed of target vehicles */
	S4 s4_a_target_size,							/*!< [out] Number of target vehicles */
	BTT_STAT *pst_a_btt_stat						/*!< [out] BSM_Final_Stat & BTT_Drv_Stat */
)
{
	/*! @note (1) initialize btt (once) */
	fn_btt_initialize(
		BTT_RET_t.CAN_Config.ENABLE,	/* BSM = ENABLE */
		BTT_RET_t.Drv_SW.ON,			/* BSM SW = ON */
		BTT_RET_t.CAN_Config.ENABLE,	/* BTT = ENABLE */
		u1_a_bsm_drv_cmd,
		st_g_bsm_alertarea_for_test
	);

	/* btt main process */
	/*! @note (2) do btt main process */
	fn_btt_main(
		fl_a_self_v,
		s4_a_curve_r,
		s1_a_shift_flg,
		pst_a_object,
		s4_a_object_size,
#ifndef _20170119_ATD_DOADBF_CHECK
		fl_a_doa_pow_ave,
		fl_a_doa_pow_dev,
		s4_a_doa_bf_peak_bin,
		fl_a_doa_bf_peak_pow,
#endif
		pst_a_btt_stat,
		pu1_alarm_flg,
		pst_a_cluster_info,
		pst_a_aux_trailer_info,
		pst_a_hitch_angle,
		pst_a_target,
		s4_a_target_size,
		&st_g_btt_result,
		&st_g_btt_alertarea
	);

	/*! @note (3) update BTT_Final_Stat (afte BTT main) */
	fn_btt_set_btt_final_state(
		BTT_RET_t.CAN_Config.ENABLE,
		u1_a_bsm_drv_cmd,
		st_g_btt_result
	);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	au1_g_btt_drv_stat = pst_a_btt_stat->BTT_drv;
	au1_g_btt_fin_stat = st_g_btt_stat.BTT_final;
#endif

	return;
}


/****************************************************************************/
/*							function										*/
/****************************************************************************/

/********************************************************************************************/
/*!
	@brief
	initialize BTT status and parameters

	@param[out] (global) st_g_btt_alertarea.standard
	@param[out] (global) st_g_btt_alertarea.rear.VarY
	@param[out] (global) st_g_btt_alertarea.rear.VarYmax
	@param[out] (global) st_g_btt_alertarea.side.VarXin
	@param[out] (global) st_g_btt_alertarea.side.VarXmax
	@param[out] (global) st_g_btt_alertarea.side.VarXout
	@param[out] (global) st_g_btt_result.TFlag
	@param[out] (global) st_g_btt_stat.BTT_final
	@param[out] (global) st_g_btt_stat.BTT_initialized

	@return void

	call function
	- fn_btt_set_trailer_length()
	- fn_btt_set_trailer_width()
	- fn_btt_ttm_activate()
	- fn_btt_atd_activate()
	- fn_btt_atd_initialize()
	- fn_btt_set_bsm_final_state()
	- fn_btt_set_btt_final_state()
	- fn_btt_aaz_activate()

	@detail

*********************************************************************************************/
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

/********************************************************************************************/
/*! 
	@brief
	set BSM final status based on BSM configuration and sw

	@param[out] (global) st_g_btt_stat.BSM_final

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_bsm_final_state(
	U1 u1_a_bsm_configuration,		/*!< [in] BSM CAN configuration */
	U1 u1_a_bsm_drv_cmd				/*!< [in] BSM on/off switch */
)
{
	/*! @note (1) set BSM state to ON */
	st_g_btt_stat.BSM_final = BTT_RET_t.Final_stat.ON;

	/*! @note (2) set BSM state to DISABLE if BSM CAN configuration is DISABLE */
	if( u1_a_bsm_configuration == BTT_RET_t.CAN_Config.DISABLE)
	{
		 st_g_btt_stat.BSM_final = BTT_RET_t.Final_stat.DISABLE;
	}
	/*! @note (3) set BSM state to OFF if BSM SW is OFF (CAN configuration is not DISABLE) */
	else if( u1_a_bsm_drv_cmd == BTT_RET_t.Drv_SW.OFF )
	{
		 st_g_btt_stat.BSM_final = BTT_RET_t.Final_stat.OFF;
	}

	return;
}

/********************************************************************************************/
/*! 
	@brief
	set BTT final status based on BSM/BTT configuration and sw

	@param[in] (global) st_g_btt_stat.BSM_final
	@param[in] (global) st_g_btt_stat.BTT_drv
	@param[out] (global) st_g_btt_stat.BTT_final

	@return void

	call function
	- fn_btt_set_btt_drv_state()

	@detail
*********************************************************************************************/
VD fn_btt_set_btt_final_state(
	U1 u1_a_btt_configuration,		/*!< [in] BTT CAN configuration */
	U1 u1_a_btt_drv_cmd,			/*!< [in] BTT on/off switch */
	BTT_RESULT st_a_btt_result		/*!< [in] BTT and sub-functions result */
)
{
	//	BSM_Final	| BTT_Final	| BTT_Drv
	//	DISABLE		| ->DISABLE	| ->DISABLE	| 
	//	ENABLE(OFF)	| ->DISABLE	| ->DISABLE	| 
	//	ENABLE(ON)	| DISABLE	| ->DISABLE	| 
	//				| OFF		| ->OFF		| due to ATD	| due to TLE|
	//				| ON		| ->PENDING	| ->CONNECT		| ->CONNECT |
	//				| 			| 			| 				| ->OFFTEMP	| ->BTT_Final=OFFTEMP
	//				| 			| 			| ->NOTCONNECT	|			| 
	//				| 			| 			| ->OFFTEMPT	|			| ->BTT_Final=OFFTEMP
	//				| OFFTEMP	| ->OFFTEMP |				|			| 

	/* Based on RDD:Fig.2.2.1-1 */
	/*! @note (1) set BTT state to (DISABLE -->) ON */
	st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.ON;
	/*! @note (2) set BTT state to DISABLE if BSM or BTT state is DISABLE */
	if( st_g_btt_stat.BSM_final == BTT_RET_t.Final_stat.DISABLE || st_g_btt_stat.BSM_final == BTT_RET_t.Final_stat.OFF )
	{
		st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.DISABLE;
	}
	else{
		/*! @note (3) set BTT state to DISABLE if BTT state is DISABLE */
		if( u1_a_btt_configuration == BTT_RET_t.CAN_Config.DISABLE){
			st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.DISABLE;
		}
		/*! @note (4) in the case of BTT != DISABLE */
		else
		{
			/* Based on RDD:Fig.2.2.6.3-2 */
			/*! @note @li (i) set BTT state to OFF if BTT SW is OFF */
			if( u1_a_btt_drv_cmd == BTT_RET_t.Drv_SW.OFF )
			{
				st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.OFF;
			}
			/*! @note @li (ii) in the case of BTT SW is ON */
			else if( u1_a_btt_drv_cmd == BTT_RET_t.Drv_SW.ON )
			{
				/*! @note @li (iii) update BTT Drive state based on BTT state and sub-function's result */
				/* update BTT_Drv_Stat (after BTT_Final_Stat update ) */
				fn_btt_set_btt_drv_state(
					st_g_btt_stat,
					st_g_btt_result
				);
				/*! @note @li (iv) update BTT state based on sub-function's result */
				/*! @note @li --> set BTT state to ON if BTT Drive state is CONNECT */
				if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.CONNECT )
				{
					st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.ON;
				}
				/*! @note @li --> set BTT state to OFFTEMP if BTT Drive state is OFFTEMP */
				else if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.OFFTEMP )
				{
					st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.OFFTEMP;
				}
				/*! @note @li --> set BTT state to OFF if BTT Drive state is NOTCONNECT */
				else if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.NOTCONNECT )
				{
					st_g_btt_stat.BTT_final = BTT_RET_t.Final_stat.OFF;
				}
				else{
					/*! @note @li --> keep previous state if BTT Drive state is DISABLE/OFF/PENDING */
				}
			}
			else
			{
				/* when u1_a_btt_drv_cmd != BTT_DRV_SW_ON / BTT_DRV_SW_OFF */
			}
		}
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	set BTT drv status based on BSM/BTT final state

	@param[out] (global) st_g_btt_stat.BTT_drv

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_btt_drv_state(
	BTT_STAT st_a_btt_stat,			/*!< [in] BTT and sub-functions status */
	BTT_RESULT st_a_btt_result		/*!< [in] BTT and sub-functions result */
)
{
	/* Based on RDD:Table.2.2.6.1-1 */
	/*! @note (1) update BTT Drive state based on BTT state */
	/*! @note @li (i) set BTT Drive state to DISABLE if BTT state is DISABLE */
	if( st_a_btt_stat.BTT_final == BTT_RET_t.Final_stat.DISABLE )
	{
		st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.DISABLE;
	}
	/*! @note @li (ii) set BTT Drive state to OFF if BTT state is OFF */
	else if( st_a_btt_stat.BTT_final == BTT_RET_t.Drv_Stat.OFF )
	{
		st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.OFF;
	}
	/*! @note @li (iii) set BTT Drive state to PENDING if BTT state is ON */
	else if( st_a_btt_stat.BTT_final == BTT_RET_t.Final_stat.ON )
	{
		st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.PENDING;
	}
	/*! @note @li (iv) set BTT Drive state to OFFTEMP if BTT state is OFFTEMP */
	else if( st_a_btt_stat.BTT_final == BTT_RET_t.Final_stat.OFFTEMP )
	{
		st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.OFFTEMP;
	}
	else
	{
		/* no other BTT_final */
	}

	/* Based on RDD:Fig.2.2.6.3-1 */
	/*! @note (2) update BTT Drive state based on sub-function's result if BTT Drive state=PENDING */
	if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.PENDING )
	{
		/*! @note @li (i) set BTT Drive state to PENDING if ATD state is ACTIVE (ATD is still detecting trailer) */
		if( st_a_btt_stat.ATD == BTT_RET_t.Func_Stat.ACTIVE )
		{
			st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.PENDING;
		}
		/*! @note @li (ii) set BTT Drive state to PENDING if ATD state is DEACTIVE (ATD finished detecting trailer) */
		else if( st_a_btt_stat.ATD == BTT_RET_t.Func_Stat.DEACTIVE )
		{
			/*! @note @li (ii-1)ATD has completed detection (result is CONNECT) */
			if( st_a_btt_result.TFlag == BTT_RET_t.TFlag.CONNECT )
			{
				/*! @note @li --> set BTT Drive state to CONNECT */
				st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.CONNECT;
	
				
				/*! @note @li --> TLE is ENABLE and has completed estimation (DEACTIVE) */
				if( st_a_btt_stat.TLE == BTT_RET_t.Func_Stat.DEACTIVE )
				{
					/*! @note @li ----> set BTT Drive state to CONNECT if Tsize is VALID*/
					if( st_a_btt_result.TLength_stat == BTT_RET_t.TSize_Stat.VALID )
					{
						st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.CONNECT;
					}
					/*! @note @li ----> set BTT Drive state to OFFTEMP if Tsize is INVALID*/
					else if( st_a_btt_result.TLength_stat == BTT_RET_t.TSize_Stat.INVALID )
					{
						st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.OFFTEMP;
					}
					/*! @note @li ----> set BTT Drive state to OFFTEMP if Tsize is UNKNOWN*/
					else if( st_a_btt_result.TLength_stat == BTT_RET_t.TSize_Stat.UNKNOWN )
					{
						st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.OFFTEMP;	
					}
					else
					{
						/* no other TLength_stat */
					}
				}

			}
			/*! @note @li (ii-2)ATD has completed detection (result is NOTCONNECT) */
			else if( st_a_btt_result.TFlag == BTT_RET_t.TFlag.NOTCONNECT )
			{
				/*! @note @li --> set BTT Drive state to NOTCONNECT */
				st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.NOTCONNECT;
			}
			/*! @note @li (ii-3)ATD has completed detection (result is UNKNOWN) */
			else if( st_a_btt_result.TFlag == BTT_RET_t.TFlag.UNKNOWN )
			{
				/*! @note @li --> set BTT Drive state to OFFTEMP */
				st_g_btt_stat.BTT_drv = BTT_RET_t.Drv_Stat.OFFTEMP;
			}
			else
			{
				/* no other TFlag */
			}
		}
		else
		{
			/*  st_a_btt_stat.ATD = ENABLE or DISABLE (ATD has not started)*/
		}
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	set Trailer length and status based on estimated trailer width

	@param[out] (global) st_g_btt_result.TLength
	@param[out] (global) st_g_btt_result.TLength_stat

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_trailer_length(
	FL length					/*!< [in] trailer length */
)
{
	/*! @note (1) set TLength */
	st_g_btt_result.TLength = length;

	/* Based on RDD:Table.4.2.4-1 */
	/*! @note (2) set TLength state */
	/*! @note @li (i) set TLength state to UNKNOWN if length = UNKNOWN */
	if( length == BTT_TRAILER_SIZE_UNKNOWN)
	{
		st_g_btt_result.TLength_stat = BTT_RET_t.TSize_Stat.UNKNOWN;
	}
	/*! @note @li (ii) set TLength state to INVALID if length < BTT_TRAILER_LENGTH_MIN or length >= BTT_TRAILER_LENGTH_MAX */
	/* _20161116_BTT_CHECK_Ting */
	else if( length < BTT_TRAILER_LENGTH_MIN || length >= BTT_TRAILER_LENGTH_MAX )
	{
		st_g_btt_result.TLength_stat = BTT_RET_t.TSize_Stat.INVALID;
	}
	/*! @note @li (iii) set TLength state to VALID if BTT_TRAILER_LENGTH_MIN <= length < BTT_TRAILER_LENGTH_MAX or  */
	else
	{
		st_g_btt_result.TLength_stat = BTT_RET_t.TSize_Stat.VALID;
	}
	return;
};

/********************************************************************************************/
/*! 
	@brief
	set rear length based on estimated trailer width

	@param[in] (global) st_g_btt_alertarea..rear.VarYmax
	@param[out] (global) st_aaz_params.TLength_AAZ
	@param[out] (global) st_g_btt_alertarea.rear.VarY

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_range_rear(
	FL length					/*!< [in] trailer length */
)
{
	/*! @note (1) save current trailer length to AAZ internal length for AAZ judgement */
	st_aaz_params.TLength_AAZ = length;
	/* Based on RDD:Table.4.2.4-1 */

	/*! @note (2) set BTT alert (rear) area as UNKNOWN if AAZ internal length is UNKNOWN */
	if( st_aaz_params.TLength_AAZ == BTT_TRAILER_SIZE_UNKNOWN)
	{
		st_g_btt_alertarea.rear.VarY = BTT_REAR_UNKNOWN;
	}
	/*! @note (3) set BTT alert (rear) area as INVALID if AAZ internal length is under BTT_TRAILER_LENGTH_MIN or over BTT_TRAILER_LENGTH_MAX */
	/* _20161116_BTT_CHECK_Ting */
	else if( st_aaz_params.TLength_AAZ < BTT_TRAILER_LENGTH_MIN || st_aaz_params.TLength_AAZ >= BTT_TRAILER_LENGTH_MAX )
	{
		st_g_btt_alertarea.rear.VarY = BTT_REAR_INVALID;
	}
	/*! @note (4) set BTT alert (rear) area if AAZ internal length is between  BTT_TRAILER_LENGTH_MIN and BTT_TRAILER_LENGTH_MAX */
	else
	{
		/* Based on RDD:Table.4.2.4-2 */
		/*! @note @li (i) set BTT alert (rear) area to SHORT if AAZ internal length is between BTT_TRAILER_LENGTH_MIN and BTT_REAR_RANGE_SHORT  */
		if( st_aaz_params.TLength_AAZ < BTT_REAR_RANGE_SHORT )
		{
			st_g_btt_alertarea.rear.VarY = BTT_REAR_SHORT;
		}
		/*! @note @li (ii) set BTT alert (rear) area to MID if AAZ internal length is between BTT_REAR_RANGE_SHORT and BTT_REAR_RANGE_MID  */
		else if( st_aaz_params.TLength_AAZ < BTT_REAR_RANGE_MID )
		{
			st_g_btt_alertarea.rear.VarY = BTT_REAR_MID;
		}
		/*! @note @li (iii) set BTT alert (rear) area to LONG if AAZ internal length is between BTT_REAR_RANGE_MID and BTT_REAR_RANGE_LONG  */
		else if( st_aaz_params.TLength_AAZ < BTT_REAR_RANGE_LONG )
		{
			st_g_btt_alertarea.rear.VarY = BTT_REAR_LONG;
		}
		/*! @note @li (iii) set BTT alert (rear) area to MAX if AAZ internal length is between BTT_REAR_RANGE_LONG and BTT_REAR_RANGE_MAX  */
		else /* st_aaz_params.TLength_AAZ < BTT_REAR_RANGE_MAX */
		{
			st_g_btt_alertarea.rear.VarY = st_g_btt_alertarea.rear.VarYmax;
		}
	}
	return;
};

/********************************************************************************************/
/*! 
	@brief
	set Trailer length and status based on estimated trailer width

	@param[out] (global) st_g_btt_result.TWidth
	@param[out] (global) st_g_btt_result.TWidth_stat

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_trailer_width(
	FL width					/*!< [in] trailer width */
)
{
	/*! @note (1) set TWidth */
	st_g_btt_result.TWidth = width;

	/* Based on RDD:Table.4.2.5.1-1 */
	/*! @note (2) set TWidth state */
	/*! @note @li (i) set TWidth state to UNKNOWN if length = UNKNOWN */
	if( width == BTT_TRAILER_SIZE_UNKNOWN)
	{
		st_g_btt_result.TWidth_stat = BTT_RET_t.TSize_Stat.UNKNOWN;
	}
	/*! @note @li (ii) set TWidth state to INVALID if width >= BTT_TRAILER_WIDTH_MAX */
	else if( width >= BTT_SIDE_RANGE_MAX )	//_20170302 (FL) 2.6
	{
		st_g_btt_result.TWidth_stat = BTT_RET_t.TSize_Stat.INVALID;
	}
	/*! @note @li (iii) set TWidth state to VALID if width < BTT_TRAILER_WIDTH_MAX */
	else	/* width < 2.6 */
	{
		st_g_btt_result.TWidth_stat = BTT_RET_t.TSize_Stat.VALID;
	}
	return;
};

/********************************************************************************************/
/*! 
	@brief
	set rear length based on estimated trailer width

	@param[out] (global) st_aaz_params.TWidth_AAZ
	@param[out] (global) st_g_btt_alertarea.side.VarXin
	@param[out] (global) st_g_btt_alertarea.side.VarXout

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_set_range_side(
	FL width					/*!< [in] trailer width */
)
{
	/*! @note (1) save current trailer width to AAZ internal width for AAZ judgement */
	st_aaz_params.TWidth_AAZ = width;
	/* Based on RDD:Table.4.2.5-1-1 */
	/*! @note (2) set BTT alert (side) area as UNKNOWN if AAZ internal width is UNKNOWN */
	if( st_aaz_params.TWidth_AAZ == BTT_TRAILER_SIZE_UNKNOWN)
	{
		st_g_btt_alertarea.side.VarXin = BTT_SIDE_RANGE_UNKNOWN;
		st_g_btt_alertarea.side.VarXout = BTT_SIDE_RANGE_UNKNOWN;
	}
	/*! @note (3) set BTT alert (side) area as INVALID if AAZ internal width is over BTT_SIDE_RANGE_MAX */
	else if( st_aaz_params.TWidth_AAZ >= (FL) BTT_SIDE_RANGE_MAX )
	{
		st_g_btt_alertarea.side.VarXin = BTT_SIDE_RANGE_INVALID;
		st_g_btt_alertarea.side.VarXout = BTT_SIDE_RANGE_INVALID;
	}
	/*! @note (4) set BTT alert (side) area if AAZ internal width is under  BTT_SIDE_RANGE_MAX */
	else	/* st_aaz_params.TWidth_AAZ < BTT_SIDE_RANGE_MAX */
	{
		/* Based on RDD:Table.4.2.5-1-2 */
		/*! @note @li (i) set BTT alert (side) area OFFSET to 0 if AAZ internal width is under  BTT_SV_WIDTH */
		if( st_aaz_params.TWidth_AAZ <= BTT_SV_WIDTH )
		{
#ifndef _20170223_BTT_TWE
			/* [TBD] add lateral offset (1/4 trailer width) when trailer is narrower than SV */
			st_g_btt_alertarea.side.VarXin = st_aaz_params.TWidth_AAZ * (FL)0.25;
			st_g_btt_alertarea.side.VarXout = st_aaz_params.TWidth_AAZ * (FL)0.25;
#else
			st_g_btt_alertarea.side.VarXin = (FL)0.0;
			st_g_btt_alertarea.side.VarXout = (FL)0.0;
#endif
		}
		/*! @note @li (ii) calculate BTT alert (side) area OFFSET if AAZ internal width is between BTT_SV_WIDTH and BTT_SIDE_RANGE_MAX */
		else /* BTT_SV_WIDTH < TWidth_AAZ < BTT_SIDE_RANGE_MAX */
		{
			st_g_btt_alertarea.side.VarXin = (st_aaz_params.TWidth_AAZ - BTT_SV_WIDTH) * (FL)0.5;
			st_g_btt_alertarea.side.VarXout = (st_aaz_params.TWidth_AAZ - BTT_SV_WIDTH) * (FL)0.5;
		}
	}
	return;
};


/********************************************************************************************/
/*! 
	@brief
	activate BTT sub function (ATD)

	@param[in] (global) st_g_btt_stat.ATD
	@param[out] (global) st_g_btt_stat.ATD

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_atd_activate()
{
	/*! @note (1) set ATD state to ACTIVE if ATD is ENABLE */
	if( st_g_btt_stat.ATD == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.ATD = BTT_RET_t.Func_Stat.ACTIVE;
	}
	return;
}
/********************************************************************************************/
/*! 
	@brief
	initialize BTT sub function (ATD)

	@param[out] (global) st_g_btt_stat.TFlag
	@param[out] (global) st_atd_params.timer

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_atd_initialize()
{
	/*! @note (1) initialize ATD internal parameters */
	st_atd_params.timer = 0;
	st_g_btt_result.TFlag = BTT_RET_t.TFlag.UNKNOWN;

#ifndef _20161209_BTT_ATD_TRACKING
	fn_init(st_atd_params.trailer_object, TRAILER_BUFFSIZE);
	st_atd_params.atd_counter[0] = 0;
	st_atd_params.atd_counter[1] = 0;

	fn_init_btt(
		st_atd_params.trailer_object_total[BTT_OBJ_HISTORY_CYCLE][TRAILER_BUFFSIZE], 
		st_atd_params.trailer_object_num_total[BTT_OBJ_HISTORY_CYCLE],
		TRAILER_BUFFSIZE, 
		BTT_OBJ_HISTORY_CYCLE
	);

	st_atd_params.trailer_object_num = 0;
#endif

	return;
}

/********************************************************************************************/
/*! 
	@brief
	deactivate BTT sub function (ATD)

	@param[in] (global) st_g_btt_stat.ATD
	@param[out] (global) st_g_btt_stat.ATD

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_atd_deactivate()
{
	/*! @note (1) set ATD state to DEACTIVE if ATD is ACTIVE */
	if( st_g_btt_stat.ATD == BTT_RET_t.Func_Stat.ACTIVE )
	{
		st_g_btt_stat.ATD = BTT_RET_t.Func_Stat.DEACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	activate BTT sub function (TLE)

	@param[in] (global) st_g_btt_stat.TLE
	@param[out] (global) st_g_btt_stat.TLE

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_tle_activate()
{
	/*! @note (1) set TLE state to ACTIVE if ATD is ENABLE */
	if( st_g_btt_stat.TLE == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.TLE = BTT_RET_t.Func_Stat.ACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	initialize BTT sub function (TLE)

	@param[out] (global) st_tle_params.timer

	@return void

	call function
	- fn_btt_set_trailer_length()

	@detail
*********************************************************************************************/
VD fn_btt_tle_initialize()
{
	/*! @note (1) initialize TLE internal parameters */
	st_tle_params.timer = 0;
	fn_btt_set_trailer_length( BTT_TRAILER_SIZE_UNKNOWN );
	return;
}

/********************************************************************************************/
/*! 
	@brief
	deactivate BTT sub function (TLE)

	@param[in] (global) st_g_btt_stat.TLE
	@param[out] (global) st_g_btt_stat.TLE

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_tle_deactivate()
{
	/*! @note (1) set TLE state to DEACTIVE if TLE is ACTIVE */
	if( st_g_btt_stat.TLE == BTT_RET_t.Func_Stat.ACTIVE )
	{
		st_g_btt_stat.TLE = BTT_RET_t.Func_Stat.DEACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	activate BTT sub function (TWE)

	@param[in] (global) st_g_btt_stat.TWE
	@param[out] (global) st_g_btt_stat.TWE

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_twe_activate()
{
	/*! @note (1) set TWE state to ACTIVE if TWE is ENABLE */
	if( st_g_btt_stat.TWE == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.TWE = BTT_RET_t.Func_Stat.ACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	initialize BTT sub function (TWE)

	@param[out] (global) st_twe_params.timer

	@return void

	call function
	- fn_btt_set_trailer_width()

	@detail
*********************************************************************************************/
VD fn_btt_twe_initialize()
{
	/*! @note (1) initialize TWE internal parameters */
	st_twe_params.timer = 0;
	fn_btt_set_trailer_width( BTT_TRAILER_SIZE_UNKNOWN );

#ifndef _20170223_BTT_TWE
	st_twe_params.twe_cycle = (S4)0;
	st_twe_params.twe_final = (FL)0.0;
#endif

	return;
}

/********************************************************************************************/
/*! 
	@brief
	deactivate BTT sub function (TWE)

	@param[in] (global) st_g_btt_stat.TWE
	@param[out] (global) st_g_btt_stat.TWE

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_twe_deactivate()
{
	/*! @note (1) set TWE state to DEACTIVE if TWE is ACTIVE */
	if( st_g_btt_stat.TWE == BTT_RET_t.Func_Stat.ACTIVE )
	{
		st_g_btt_stat.TWE = BTT_RET_t.Func_Stat.DEACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	activate BTT sub function (TTM)

	@param[in] (global) st_g_btt_stat.TTM
	@param[out] (global) st_g_btt_stat.TTM

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_ttm_activate()
{
	/*! @note (1) set TTM state to ACTIVE if TTM is ENABLE */
	if( st_g_btt_stat.TTM == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.TTM = BTT_RET_t.Func_Stat.ACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	deactivate BTT sub function (TTM)

	@param[in] (global) st_g_btt_stat.TTM
	@param[out] (global) st_g_btt_stat.TTM

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_ttm_deactivate()
{
	/*! @note (1) set TTM state to DEACTIVE if TTM is ACTIVE */
	if( st_g_btt_stat.TTM == BTT_RET_t.Func_Stat.ACTIVE )
	{
		st_g_btt_stat.TTM = BTT_RET_t.Func_Stat.DEACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	activate BTT sub function (AAZ)

	@param[in] (global) st_g_btt_stat.AAZ
	@param[out] (global) st_g_btt_stat.AAZ
	@param[out] (global) st_aaz_params.VarY
	@param[out] (global) st_aaz_params.First
	@param[out] (global) st_aaz_params.TLength_AAZ
	@param[out] (global) st_aaz_params.TLength_valid_count
	@param[out] (global) st_aaz_params.TLength_invalid_count
	@param[out] (global) st_aaz_params.TLength_unknown_count
	@param[out] (global) st_aaz_params.TWidth_AAZ
	@param[out] (global) st_aaz_params.TWidth_valid_count
	@param[out] (global) st_aaz_params.TWidth_invalid_count
	@param[out] (global) st_aaz_params.TWidth_unknown_count

	@return void

	@detail
*********************************************************************************************/
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

/********************************************************************************************/
/*! 
	@brief
	initialize BTT sub function (AAZ)

	@param[in] (global) st_aaz_params.First
	@param[out] (global) st_aaz_params.VarY
	@param[out] (global) st_aaz_params.First
	@param[out] (global) st_aaz_params.TLength_AAZ
	@param[out] (global) st_aaz_params.TLength_valid_count
	@param[out] (global) st_aaz_params.TLength_invalid_count
	@param[out] (global) st_aaz_params.TLength_unknown_count
	@param[out] (global) st_aaz_params.TWidth_AAZ
	@param[out] (global) st_aaz_params.TWidth_valid_count
	@param[out] (global) st_aaz_params.TWidth_invalid_count
	@param[out] (global) st_aaz_params.TWidth_unknown_count

	@return void

	@detail
*********************************************************************************************/
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

/********************************************************************************************/
/*! 
	@brief
	deactivate BTT sub function (AAZ)

	@param[in] (global) st_g_btt_stat.AAZ
	@param[out] (global) st_g_btt_stat.AAZ

	@return void

	@detail
*********************************************************************************************/
VD fn_btt_aaz_deactivate()
{
	/*! @note (1) set ATD state to DEACTIVE if ATD is ACTIVE */
	if( st_g_btt_stat.AAZ == BTT_RET_t.Func_Stat.ACTIVE )
	{
		st_g_btt_stat.AAZ = BTT_RET_t.Func_Stat.DEACTIVE;
	}
	return;
}

/********************************************************************************************/
/*! 
	@brief
	BTT main process

	@return void

	call function
	- fn_btt_atd_main()
	- fn_btt_set_btt_drv_state()
	- fn_btt_tle_activate()
	- fn_btt_tle_main()
	- fn_btt_twe_activate()
	- fn_btt_twe_main()
	- fn_btt_set_trailer_length()
	- fn_btt_set_trailer_width()
	- fn_btt_aaz_initialize()
	- fn_btt_aaz_main()
	- fn_btt_tle_initialize()
	- fn_btt_twe_initialize()

	@detail
*********************************************************************************************/
VD fn_btt_main(
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
	BTT_STAT *pst_a_btt_stat,						/*!< [in,out] (in) BSM_Final_Stat & BTT_Final_Stat\n
													              (out) BTT_Drv_Stat */
	U1 *pu1_alarm_flg,								/*!< [in] Alarm ON or OFF */
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [in] (optional) Additional trailer or object info from other system or module */
	BTT_HITCH_ANGLE *pst_a_hitch_angle,				/*!< [in] (optional) Angle between subject vehicle and trailer */
	NORMAL_BSM *pst_a_target,						/*!< [in] Position and speed of target vehicles (condition for aaz) */
	S4 s4_a_target_size,							/*!< [in] Number of target vehicles */
	BTT_RESULT *pst_a_btt_result,					/*!< [out] TFlag */
	BTT_ALERTAREA* pst_a_btt_alertarea				/*!< [out] BTT_AlertArea_Rear & BTT_AlertArea_Side */
)
{
	FL fl_t_length = BTT_TRAILER_SIZE_UNKNOWN;
	FL fl_t_width = BTT_TRAILER_SIZE_UNKNOWN;

#ifndef _20161118_BTT_ATD_TEST	
	/* for test only */
	fn_check_front_trailer_line();
#endif

#ifndef _20170220_BTT_TRAILEROBJ_ERASE_OUTLIER
	/* erase objects which are outside of the specific range */
	fn_btt_sel_exclude_object(
		pst_a_object,
		&s4_a_object_size
	);	
#endif

#ifndef _20170220_BTT_TRAILEROBJ
	/* shift the buffer of trailer objects within 12 cycles */
	fn_btt_shift_trailerobj(
		pst_a_object,
		s4_a_object_size
	);
#endif

	/* Based on RDD:Table.2.2.6.3-1 */
	/*! @note (1) do ATD main process */
	fn_btt_atd_main(
		fl_a_self_v,
		s4_a_curve_r,
		s1_a_shift_flg,
		pst_a_object,
		s4_a_object_size,
#ifndef _20170119_ATD_DOADBF_CHECK
		fl_a_doa_pow_ave,
		fl_a_doa_pow_dev,
		s4_a_doa_bf_peak_bin,
		fl_a_doa_bf_peak_pow,
#endif
		pst_a_cluster_info,
		pst_a_aux_trailer_info,
		pst_a_btt_result
	);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	au1_g_btt_atd_tflag =  pst_a_btt_result->TFlag;
#endif

	/*! @note (2)-1 proceed to next process if ATD has completed detection.(ATD state == DEACTIVE) */
	if( pst_a_btt_stat->ATD == BTT_RET_t.Func_Stat.DEACTIVE )
	{
		/*! @note @li (i) update BTT_Drv_Stat (after ATD) */
		fn_btt_set_btt_drv_state(
			*pst_a_btt_stat,
			*pst_a_btt_result
		);

		/*! @note @li (ii) proceed to Trailer size estimation if ATD has detected Trailer. (BTT Drive state = CONNECt) */
		/* BTT_drv should be BTT_DRV_STATE_CONNECT while TLE is ACTIVE or Tlength_stat is VALID */
		if( pst_a_btt_stat->BTT_drv == BTT_RET_t.Drv_Stat.CONNECT )
		{
			/*! @note @li (iii) do TLE */
			/*! @note @li --> activate TLE  */
			fn_btt_tle_activate();
			/*! @note @li --> do TLE main process */
			fl_t_length = fn_btt_tle_main(
				fl_a_self_v,
				s4_a_curve_r,
				pst_a_object,
				s4_a_object_size,
				pst_a_cluster_info,
				pst_a_aux_trailer_info,
				pst_a_btt_stat
			);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
			afl_g_btt_aaz_area[0] = fl_t_length;
#endif
			/*! @note @li (iv) do TWE (optional) */
			/*! @note @li --> activate TWE  */
			fn_btt_twe_activate();
			/*! @note @li --> do TWE main process */
			fl_t_width = fn_btt_twe_main(
				fl_a_self_v,
				s4_a_curve_r,
				pst_a_object,
				s4_a_object_size,
				pst_a_cluster_info,
				pst_a_aux_trailer_info,
				pst_a_hitch_angle,
				pst_a_btt_stat
			);

#ifndef _20170223_BTT_TWE
			/*! @note @li --> accumulate the value of trailer width and calculate the average after TWE is deactived */
			if( fl_t_width != BTT_TRAILER_SIZE_UNKNOWN ){
				st_twe_params.twe_final += fl_t_width;
				st_twe_params.twe_cycle ++;
			}
			if( st_g_btt_stat.TWE == BTT_RET_t.Func_Stat.DEACTIVE 
			&&	st_twe_params.twe_cycle > (S4)((FL)BTT_TWE_MAX_TIME * (FL)0.6)){
				fl_t_width = st_twe_params.twe_final / (FL)st_twe_params.twe_cycle;
			}
#endif
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
			afl_g_btt_aaz_area[1] = fl_t_width;
#endif
			/*! @note @li (v) update BTT_Drv_Stat (while Trailer size estimation) */
			fn_btt_set_btt_drv_state(
				*pst_a_btt_stat,
				*pst_a_btt_result
			);
		}

		/*! @note @li (vi) proceed to Alert Trailer size estimation if ATD has detected Trailer. (BTT Drive state = CONNECt) */
		/* Check TFlag instead of BTT_drv since BTT_DRV_STATE_CONNECT includes both Tlength_stat = UNKNOWN and BTT_DRV_STATE_OFFTEMP */
		if( pst_a_btt_result->TFlag ==  BTT_RET_t.TFlag.CONNECT )
		{
			/* AAZ */
			fn_btt_set_trailer_length( fl_t_length );
			fn_btt_set_trailer_width( fl_t_width );
			fn_btt_aaz_initialize(
				pst_a_btt_result->TLength,
				pst_a_btt_result->TWidth
			);
			fn_btt_aaz_main(
				fl_a_self_v,
				s4_a_curve_r,
				pst_a_btt_alertarea,
				pu1_alarm_flg,
				pst_a_btt_result,
				pst_a_btt_stat,
				pst_a_target,
				s4_a_target_size,
				pst_a_hitch_angle
			);
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
			afl_g_btt_aaz_area[2] = pst_a_btt_alertarea->rear.VarY;
			afl_g_btt_aaz_area[3] = pst_a_btt_alertarea->side.VarXin;
			afl_g_btt_aaz_area[4] = pst_a_btt_alertarea->side.VarXout;
#endif
		}
	}
	/*! @note (2)-2 do nothing if ATD is still detecting trailer or does not start detection (ATD != DAACTIVE = ACTIVE / ENABLE / FUNC_DISABLE)*/
	else{
		fn_btt_tle_initialize();
		fn_btt_twe_initialize();
	}

	/* update BTT_Drv_Stat (after AAZ) */
	fn_btt_set_btt_drv_state(
		*pst_a_btt_stat,
		*pst_a_btt_result
	);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	as4_g_btt_atd_timer[0] = st_atd_params.timer; 
	as4_g_btt_atd_timer[1] = st_tle_params.timer; 
	as4_g_btt_atd_timer[2] = st_twe_params.timer; 
#endif

/*! 
@test BTT Main Process Output Signal Pattern (Normal pattern)\n
	 BTT_STAT* pst_a_btt_stat,				(BSM_Final_Stat & BTT_Final_Stat, BTT_Drv_Stat)\n
	 BTT_RESULT* pst_a_btt_result,			(TFlag)\n
	 BTT_ALERTAREA* pst_a_btt_alertarea		(BTT_AlertArea_Rear & BTT_AlertArea_Side)\n

@test (1) BSM_final = DISABLE\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_DISABLE	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_DISABLE	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_DISABLE	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (2) BSM_final = OFF & BTT_final = DISABLE	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_OFF	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_DISABLE	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_DISABLE	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (3) BSM_final = ON & BTT_final = DISABLE	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_DISABLE	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_DISABLE	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (4) BSM_final = ON & BTT_final = OFF	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_OFF	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_OFF	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (5) BSM_final = ON & BTT_final = ON	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_PENDING	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (6) (5) + BTT_drv = NOTCONNECT	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_NOTCONNECT	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_NOTCONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| BTT_TRAILER_SIZE_UNKNOWN	\n
	 pst_a_btt_alertarea->rear.VarY	| 0	\n

@test  (7-1) (5) + BTT_drv = CONNECT + TLength_stat = UNKNOWN	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_CONNECT	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| BTT_REAR_RANGE_UNKNOWN \n

@test  (7-2-1) (5) + BTT_drv = CONNECT + TLength_stat = VALID + AAZ = ACTIVE (while AAZ running)	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_CONNECT	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_VALID	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| BTT_REAR_RANGE_LONG (default value, TBD)	\n

@test  (7-2-2) (5) + BTT_drv = CONNECT + TLength_stat = VALID + AAZ = DEACTIVE (AAZ finished running)	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_CONNECT	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_VALID	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| ?	\n

@test  (7-3) (5) + BTT_drv = CONNECT + TLength_stat = INVALID	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_OFFTEMP	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_OFFTEMP	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_INVALID	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| ?	\n

@test  (8) (5) + BTT_drv = OFFTEMP + TFlag = UNKNOWN	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_OFFTEMP	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_OFFTEMP	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_UNKNOWN	\n
	 pst_a_btt_result->TLength_stat	| ?	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| ?	\n

@test  (9) (5) + BTT_drv = OFFTEMP + TFlag = CONNECT + TLength_stat = UNKNOWN	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_OFFTEMP	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_OFFTEMP	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_UNKNOWN	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| ?	\n

@test  (10) (5) + BTT_drv = OFFTEMP + TFlag = CONNECT + TLength_stat = INVALID	\n
	 pst_a_btt_stat->BSM_final		| BTT_STATE_ON	\n
	 pst_a_btt_stat->BTT_final		| BTT_STATE_OFFTEMP	\n
	 pst_a_btt_stat->BTT_drv		| BTT_DRV_STATE_OFFTEMP	\n
	 pst_a_btt_result->TFlag		| BTT_TRAILER_FLAG_CONNECT	\n
	 pst_a_btt_result->TLength_stat	| BTT_TRAILER_SIZE_STAT_INVALID	\n
	 pst_a_btt_result->TLength		| ?	\n
	 pst_a_btt_alertarea->rear.VarY	| ?	\n
*/

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

/********************************************************************************************/
/*! 
	@brief
	TWE main process

	@param[in] (global) st_g_btt_stat.TWE
	@param[in] (global) st_twe_params.timer
	@param[out] (global) st_twe_params.timer

	@return Trailer width

	call function
	- fn_btt_twe_estimate_trailer_width()
	- fn_btt_twe_deactivate()

	@detail
*********************************************************************************************/
FL fn_btt_twe_main(									/*!< [out] Trailer width */
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	NORMAL_BSM *pst_a_object,						/*!< [in] Position and speed of objects detected by SRR */
	S4 s4_a_object_size,							/*!< [in] Number of objects */
	BTT_CLUSTER_INFO *pst_a_cluster_info,			/*!< [in] (optional) Trailer info selected by driver */
	BTT_AUX_TRAILER_INFO *pst_a_aux_trailer_info,	/*!< [in] (optional) Additional trailer or object info from other system or module */
	BTT_HITCH_ANGLE *pst_a_hitch_angle,				/*!< [in] (optional) Angle between subject vehicle and trailer */
													/*   [out(NA)] TWidth -> fn_btt_set_trailer_length(retval) before AAZ */
	BTT_STAT *pst_a_btt_stat						/*!< [out] TWE_Stat */
)
{
	/*! @note (1) set width to UNKNOWN */
	FL fl_t_width = BTT_TRAILER_SIZE_UNKNOWN;

	/*! @note (2) do nothing if TWE is not AVTIVE */
	if( st_g_btt_stat.TWE != BTT_RET_t.Func_Stat.ACTIVE )
	{
		return fl_t_width;
	}

	/* Based on RDD:Fig.4.5.4-1 */
	/*! @note (3)-1 estimate trailer width while TWE timer is under BTT_TWE_MAX_TIME */
	if( st_twe_params.timer < BTT_TWE_MAX_TIME)
	{
		fl_t_width = fn_btt_twe_estimate_trailer_width(
#ifndef _20170223_BTT_TWE
			s4_a_curve_r,
			pst_a_object,
			s4_a_object_size
#endif
			/* TBD */
		);
	}
	/*! @note (3)-2 finish estimating trailer width when TWE timer is over BTT_TWE_MAX_TIME  */
	else
	{
		/*! @note @li --> deactivate TWE */
		fn_btt_twe_deactivate();
	}
	/*! @note (4) increment TWE timer  */
	st_twe_params.timer++;

	return fl_t_width;
}

/********************************************************************************************/
/*! 
	@brief
	AAZ main process

	@param[in] (global) st_g_btt_stat.AAZ
	@param[in] (global) st_aaz_params.First
	@param[in] (global) st_aaz_params.TLength_unknown_count
	@param[in] (global) st_aaz_params.TLength_valid_count
	@param[in] (global) st_aaz_params.TLength_invalid_count
	@param[out] (global) st_aaz_params.TLength_unknown_count
	@param[out] (global) st_aaz_params.TLength_valid_count
	@param[out] (global) st_aaz_params.TLength_invalid_count

	@return void

	call function
	- fn_btt_aaz_deactivate()
	- fn_btt_set_range_rear()

	@detail
*********************************************************************************************/
VD fn_btt_aaz_main(
	FL fl_a_self_v,									/*!< [in] Subject Vehicle speed [km/h] */
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	BTT_ALERTAREA *st_a_btt_alertarea,				/*!< [in,out] (in) BSM_AlertArea\n
													              (out) BTT_AlertArea_Rear & BTT_AlertArea_Side */
	U1 *pu1_alarm_flg,								/*!< [in] Alarm ON or OFF */
	BTT_RESULT* pst_a_btt_result,					/*!< [in] TLength, TWidth */
	BTT_STAT *pst_a_btt_stat,						/*!< [in,out] (in) TLE_Stat, TWE_Stat\n
													              (out) BTT_Drv_Stat */
	NORMAL_BSM *pst_a_target,						/*!< [in] Position and speed of target vehicles */
	S4 s4_a_target_size,							/*!< [in] Number of target vehicles */
	BTT_HITCH_ANGLE *pst_a_hitch_angle				/*!< [in] (optional) Angle between subject vehicle and trailer */
)
{
	/*! @note (1) do nothing if AAZ is not AVTIVE */
	if( st_g_btt_stat.AAZ != BTT_RET_t.Func_Stat.ACTIVE )
	{
		return;
	}

	/*! @note (2) do nothing if AAZ is not AVTIVE */
	/* _20161116_BTT_CHECK_Ting */
	/*! @note (2)-1 do AAZ main when AAZ_First = False (AAZ_First = False when TFlag = CONNECT at the first time and then AAZ parameters are set to default value) */
	if( st_aaz_params.First == BTT_RET_t.Bool.TRUE )
	{
		return;
	}

	/* Based on RDD:Table.4.2.6.2-2 */
	/*! @note (3)-1 check unknown counter when TLength state is UNKNOWN */
	if( pst_a_btt_result->TLength_stat == BTT_RET_t.TSize_Stat.UNKNOWN )
	{
		/*! @note @li (i) increment unknown counter */
		st_aaz_params.TLength_unknown_count++;
		/*! @note @li (ii)-1 judge as UNKNOWN when unknown counter is over BTT_AAZ_TH_OFF */
		if( st_aaz_params.TLength_unknown_count > BTT_AAZ_TH_OFF )
		{
			/*! @note @li --> setup VarY */
			fn_btt_set_range_rear( pst_a_btt_result->TLength );
			/*! @note @li --> deactivate AAZ if TLE is DEACTIVE(has completed estimation) */
			if( pst_a_btt_stat->TLE == BTT_RET_t.Func_Stat.DEACTIVE )
			{
				fn_btt_aaz_deactivate();
			}
			/* TLength_stat=UNKNOWN & TLE_stat=DEACTIVE -> BTT_drv will be set as OFFTEMP @fn_btt_set_btt_drv_state() */
			/* (while TLE_stat=ACTIVE, BTT_drv stay in CONNECT)  */
		}
		/*! @note @li (ii)-2 keep checking lenght when unknown counter is under BTT_AAZ_TH_OFF */
		else
		{
			/* keep previous rear range*/
		}
	}
	/*! @note (3)-2 check valid counter when TLength state is VALID */
	else if( pst_a_btt_result->TLength_stat == BTT_RET_t.TSize_Stat.VALID )
	{
		/*! @note (3)-2-1 do not change range while alarming */
		if( *pu1_alarm_flg == BTT_RET_t.Bool.TRUE ) {
			/* keep previous rear range*/
		} 
		/*! @note (3)-2-2 check valid counter when not alarming */
		else{
			/*! @note @li (i) increment valid counter */
			st_aaz_params.TLength_valid_count++;
			/*! @note @li (ii)-1 update alarm area when valid counter is over BTT_AAZ_TH_ON */
			if( st_aaz_params.TLength_valid_count > BTT_AAZ_TH_ON )
			{
				/*! @note @li --> update length value and rear range */
				fn_btt_set_range_rear( pst_a_btt_result->TLength );
				/*! @note @li --> deactivate AAZ if TLE is DEACTIVE(has completed estimation) */
				if( pst_a_btt_stat->TLE == BTT_RET_t.Func_Stat.DEACTIVE )
				{
					fn_btt_aaz_deactivate();
				}
				/* TLength_stat=VALID & TLE_stat=DEACTIVE -> BTT_drv will be set as CONNECT @fn_btt_set_btt_drv_state() */
				/* (while TLE_stat=ACTIVE, BTT_drv stay in CONNECT)  */
			}
		}
	}
	/*! @note (3)-3 check invalid counter when TLength state is INVALID */
	else if( pst_a_btt_result->TLength_stat == BTT_RET_t.TSize_Stat.INVALID )
	{
		/*! @note @li (i) increment invalid counter */
		st_aaz_params.TLength_invalid_count++;

		/*! @note @li (ii)-1 judge as INVALID when invalid counter is over BTT_AAZ_TH_OFF */
		if( st_aaz_params.TLength_invalid_count > BTT_AAZ_TH_OFF )
		{
			/*! @note @li --> setup VarY */
			fn_btt_set_range_rear( pst_a_btt_result->TLength );
			/*! @note @li --> deactivate TLE */
			fn_btt_tle_deactivate();
			/* TLength_stat=INVALID & TLE_stat=DEACTIVE -> BTT_drv will be set as OFFTEMP @fn_btt_set_btt_drv_state() */
			/* while TLE_stat=DEACTIVE, BTT_drv stay in CONNECT  */
		/*! @note @li (ii)-2 keep checking lenght when invalid counter is under BTT_AAZ_TH_OFF */
		}else
		{
			/* keep previous rear range*/
		}
	}
	else
	{
		/* no other TLength_stat */
	}


#ifndef _20170223_BTT_TWE		
	/* Based on RDD:Table.4.2.6.2-2 */
	/*! @note (3)-1 check unknown counter when TLength state is UNKNOWN */
	if( pst_a_btt_result->TWidth_stat == BTT_RET_t.TSize_Stat.UNKNOWN )
	{
		/*! @note @li (i) increment unknown counter */
		st_aaz_params.TWidth_unknown_count++;
		/*! @note @li (ii)-1 judge as UNKNOWN when unknown counter is over BTT_AAZ_TH_OFF */
		if( st_aaz_params.TWidth_unknown_count > BTT_AAZ_TH_OFF )
		{
			/*! @note @li --> setup VarXin, VarXout */
			fn_btt_set_range_side( pst_a_btt_result->TWidth );
			/*! @note @li --> deactivate AAZ if TWE is DEACTIVE(has completed estimation) */
			if( pst_a_btt_stat->TWE == BTT_RET_t.Func_Stat.DEACTIVE )
			{
				fn_btt_aaz_deactivate();
			}
			/* TWidth_stat=UNKNOWN & TWE_stat=DEACTIVE -> BTT_drv will be set as OFFTEMP @fn_btt_set_btt_drv_state() */
			/* (while TWE_stat=ACTIVE, BTT_drv stay in CONNECT)  */
		}
		/*! @note @li (ii)-2 keep checking width when unknown counter is under BTT_AAZ_TH_OFF */
		else
		{
			/* keep previous side range*/
		}
	}
	/*! @note (3)-2 check valid counter when TWidth state is VALID */
	else if( pst_a_btt_result->TWidth_stat == BTT_RET_t.TSize_Stat.VALID )
	{
		/*! @note (3)-2-1 do not change range while alarming */
		if( *pu1_alarm_flg == BTT_RET_t.Bool.TRUE ) {
			/* keep previous side range*/
		} 
		/*! @note (3)-2-2 check valid counter when not alarming */
		else{
			/*! @note @li (i) increment valid counter */
			st_aaz_params.TWidth_valid_count++;
			/*! @note @li (ii)-1 update alarm area when valid counter is over BTT_AAZ_TH_ON */
			if( st_aaz_params.TWidth_valid_count > BTT_AAZ_TH_ON )
			{
				/*! @note @li --> update width value and side range */
				fn_btt_set_range_side( pst_a_btt_result->TWidth );
				/*! @note @li --> deactivate AAZ if TWE is DEACTIVE(has completed estimation) */
				if( pst_a_btt_stat->TWE == BTT_RET_t.Func_Stat.DEACTIVE )
				{
					fn_btt_aaz_deactivate();
				}
				/* TWidth_stat=VALID & TWE_stat=DEACTIVE -> BTT_drv will be set as CONNECT @fn_btt_set_btt_drv_state() */
				/* (while TWE_stat=ACTIVE, BTT_drv stay in CONNECT)  */
			}
		}
	}
	/*! @note (3)-3 check invalid counter when TWidth state is INVALID */
	else if( pst_a_btt_result->TWidth_stat == BTT_RET_t.TSize_Stat.INVALID )
	{
		/*! @note @li (i) increment invalid counter */
		st_aaz_params.TWidth_invalid_count++;

		/*! @note @li (ii)-1 judge as INVALID when invalid counter is over BTT_AAZ_TH_OFF */
		if( st_aaz_params.TWidth_invalid_count > BTT_AAZ_TH_OFF )
		{
			/*! @note @li --> setup VarXin, VarXout */
			fn_btt_set_range_side( pst_a_btt_result->TWidth );
			/*! @note @li --> deactivate TWE */
			fn_btt_twe_deactivate();
			/* TWidth_stat=INVALID & TLE_stat=DEACTIVE -> BTT_drv will be set as OFFTEMP @fn_btt_set_btt_drv_state() */
			/* while TLE_stat=DEACTIVE, BTT_drv stay in CONNECT  */
		/*! @note @li (ii)-2 keep checking lenght when invalid counter is under BTT_AAZ_TH_OFF */
		}else
		{
			/* keep previous rear range*/
		}
	}
	else
	{
		/* no other TWidth_stat */
	}
#endif

	/*! @note For Width TBD */
	/* Width */
	/* TBD */

	return;
}

/********************************************************************************************/
/*! 
	@brief
	detect trailer

	@param[in] (global) TBD
	@param[out] (global) TBD

	@return trailer flag

	call function
	- TBD

	@detail
*********************************************************************************************/
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

/********************************************************************************************/
/*! 
	@brief
	estimate Trailer length

	@param[in] (global) TBD
	@param[out] (global) TBD

	@return trailer length

	call function
	- TBD

	@detail
*********************************************************************************************/
FL fn_btt_tle_estimate_trailer_length(				/*!< [out] trailer length */
	/*! [in]  TBD */
	/*! [out]  TBD */
)
{
	FL fl_t_length = BTT_TRAILER_SIZE_UNKNOWN;

	/*! @note  TBD */
	/*! @test TLE Core Logic Output Signal Pattern\n
		 (1) fl_t_length = (FL) 0.0;	// INVALID	\n
		 (2) fl_t_length = (FL) 1.0;	// VALID: SHORT	\n
		 (3) fl_t_length = (FL) 2.0;	// VALID: MID	\n
		 (4) fl_t_length = (FL) 5.0;	// VALID: LONG	\n
		 (5) fl_t_length = (FL) 8.0;	// VALID: VarMax	\n
		 (6) fl_t_length = (FL) 10.6;	// INVALID	\n
	*/
	/* _20161116_BTT_CHECK_Ting */

	return fl_t_length;
}

/********************************************************************************************/
/*! 
	@brief
	estimate Trailer width

	@param[in] (global) TBD
	@param[out] (global) TBD

	@return trailer width

	call function
	- TBD

	@detail
*********************************************************************************************/
FL fn_btt_twe_estimate_trailer_width(				/* [out] trailer width */
#ifndef _20170223_BTT_TWE
	S4 s4_a_curve_r,								/*!< [in] Road curvature [m] */
	NORMAL_BSM *pst_a_object,						/*!< [in] (Current) Position and speed of objects detected by SRR */
	S4 s4_a_object_size								/*!< [in] (Current) Number of objects */
#endif
	/*! [in]  TBD */
	/*! [out]  TBD */
)
{
#ifndef _20170223_BTT_TWE
	S4 s4_t_lp_i;
	S4 s4_t_cycle;
	FL fl_t_width;
	FL fl_t_rx_ave = (FL)0.0;
#else
	FL fl_t_width = BTT_TRAILER_SIZE_UNKNOWN;
#endif

#ifndef _20170223_BTT_TWE
	/* Have to stop TWE or adjust the value when there is a TV at the nearside */
	/* calculate the average of Rx in BTT history cycle */
	s4_t_cycle = (S4)0;
	for(s4_t_lp_i = 0; s4_t_lp_i < BTT_OBJ_HISTORY_CYCLE; s4_t_lp_i++){
		/* the nearest object which Ry is within the specific range */
		if( st_atd_params.trailer_object_total[s4_t_lp_i][0].fl_Rxobs != CFL_UNKNOWN_VALUE 
		&&  st_atd_params.trailer_object_total[s4_t_lp_i][0].fl_Ryobs < (FL)-0.5
		&&  st_atd_params.trailer_object_total[s4_t_lp_i][0].fl_Ryobs > (FL)-2.0 ){
			fl_t_rx_ave += fl_abs(st_atd_params.trailer_object_total[s4_t_lp_i][0].fl_Rxobs);
			s4_t_cycle ++;
		}
	}
	if(s4_t_cycle != (S4)0){
		fl_t_rx_ave = fl_t_rx_ave / (FL)s4_t_cycle;
		fl_t_width = (FL)2.0 * fl_t_rx_ave;
	} else{
		fl_t_width = BTT_TRAILER_SIZE_UNKNOWN;
	}	
#endif

	/*! @note  TBD */
	/*! @test TWE Core Logic Output Signal Pattern\n
		 (1) fl_t_width = (FL) 1.0;	// VALID: < BTT_SV_WIDTH	\n
		 (2) fl_t_width = (FL) 1.8;	// VALID: > BTT_SV_WIDTH	\n
		 (3) fl_t_width = (FL) 2.6;	// INVALID	\n
	*/

	return fl_t_width;
}


#ifndef _20161118_BTT_ATD_TEST
VD fn_check_front_trailer_line(
)
{
	S4 i,j;

	FL pfl_a_trailerline_pow_dn;
	S4 as4_a_trailerline_doa_dn[LINE_FREQ_BIN_RANGE][1];
	S4 as4_a_trailerline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE];
	FL afl_a_trailerline_dn[LINE_FREQ_BIN_RANGE][2];

	S4 trailerline_start_bin = FREQ_BIN_LOWER_LIMIT_T;
	
	pfl_a_trailerline_pow_dn = (FL)0;
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		as4_a_trailerline_doa_dn[i][0] = (S4)0;
		as4_a_trailerline_doa_peak_num_dn[i] = (S4)0;
		for(j=0; j<2; j++)
		{
			afl_a_trailerline_dn[i][j] = CFL_UNKNOWN_VALUE;
		}
	}

	pfl_a_trailerline_pow_dn = calc_line_doa_fm(
		(const FL (*)[CORRE_SIZE_4CH])(afl_g_cvw_lfm_ryy_matrix[1]),
		afl_g_cvw_lfm_ftt_power[1],
		trailerline_start_bin,
		trailerline_start_bin + LINE_FREQ_BIN_RANGE,
		(FL)0.0F,
		as4_a_trailerline_doa_dn,
		as4_a_trailerline_doa_peak_num_dn,
		CU2_LFM_MOD_DN
	);


	fn_btt_atd_check_detect_trailerobjs(
		trailerline_start_bin,
		(const S4 (*)[1])as4_a_trailerline_doa_dn,
		as4_a_trailerline_doa_peak_num_dn,
		afl_a_trailerline_dn
	);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<2; j++)
		{
			afl_g_btt_nearfield_line_dn[i][j] = afl_a_trailerline_dn[i][j];
		}
	}
#endif

	return;
}
#endif

#ifndef _20161209_BTT_ATD_TRACKING
VD fn_btt_atd_check_detect_trailerobjs(
	const S4 as4_a_trailerline_start_bin,
	const S4 as4_a_trailerline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_trailerline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE],
	FL afl_a_trailerline_dn[LINE_FREQ_BIN_RANGE][2]
)
{
	S4 i;
	S4 j;

	FL tmp_r = 0.0F;
	FL tmp_rx = CFL_UNKNOWN_VALUE;
	FL tmp_ry = CFL_UNKNOWN_VALUE;
	FL tmp_theta = 0.0F;

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<as4_a_trailerline_doa_peak_num_dn[i]; j++)
		{
			tmp_r = - RCOF * 2.0F * (FL)((as4_a_trailerline_start_bin + i) - (FL)NB_FFT_PT * 0.5F);
			tmp_theta = fl_transform_doabin_to_rad(	/*DBF(S4) */
				as4_a_trailerline_doa_dn[i][j],
				1
			);
			tmp_rx = tmp_r * fl_sin( tmp_theta ) + st_g_bsm_loop_data.afl_installed_angle[1];
			tmp_ry = tmp_r * fl_cos( tmp_theta );
			afl_a_trailerline_dn[i][0] = tmp_rx;
			afl_a_trailerline_dn[i][1] = tmp_ry;
		}
	}

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

#ifndef _20170220_BTT_TRAILEROBJ
VD	fn_btt_shift_trailerobj(
	NORMAL_BSM pst_a_trailer_obj[TRAILER_BUFFSIZE],
	S4 as4_a_trailer_obj_num
)
{
	S4 s4_t_lp_i;

	/* shift buffer and add the current trailer object data */
	for( s4_t_lp_i = BTT_OBJ_HISTORY_CYCLE - (S4)2 ; s4_t_lp_i >= (S4)0; s4_t_lp_i-- ){
		fn_move(st_atd_params.trailer_object_total[s4_t_lp_i + (S4)1], st_atd_params.trailer_object_total[s4_t_lp_i], TRAILER_BUFFSIZE);
		st_atd_params.trailer_object_num_total[s4_t_lp_i + (S4)1] = st_atd_params.trailer_object_num_total[s4_t_lp_i];
	}
	fn_move(st_atd_params.trailer_object_total[(S4)0], pst_a_trailer_obj, TRAILER_BUFFSIZE);
	st_atd_params.trailer_object_num_total[0] = as4_a_trailer_obj_num;

	return;
}
#endif

#ifndef _20170220_BTT_TRAILEROBJ_ERASE_OUTLIER
VD	fn_btt_sel_exclude_object(
	NORMAL_BSM pst_a_trailer_obj[TRAILER_BUFFSIZE],
	S4 *as4_a_trailer_obj_num
)
{
	/* Check Rx */
	fn_btt_sel_exobj_outside_rx(
		pst_a_trailer_obj,
		as4_a_trailer_obj_num
	);

	/* NOTE: maybe have to check Ry or DoA to erase outliers? */

	*as4_a_trailer_obj_num = s4_trim_trailer(pst_a_trailer_obj);

	return;
}

VD fn_btt_sel_exobj_outside_rx(
	NORMAL_BSM pst_a_trailer_obj[TRAILER_BUFFSIZE],
	S4 *as4_a_trailer_obj_num
)
{
	S4 s4_t_lp_i;

	for(s4_t_lp_i = 0; s4_t_lp_i < *as4_a_trailer_obj_num; s4_t_lp_i ++){
		if( pst_a_trailer_obj[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE
		&&  fl_abs(pst_a_trailer_obj[s4_t_lp_i].fl_Rxobs) > (FL)2.0){
			fn_init(&pst_a_trailer_obj[s4_t_lp_i], 1);
		}
	}

	return;
}
#endif

#ifndef _20170130_BTT_TLE_DBF_POW_DIFF
VD fn_btt_tle_search_peak_bf(
	const FL Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (fm) */
	FL fl_a_tle_bf_peak[BTT_TLE_RANGE]
)
{
	U1 u1_t_lp_i, u1_t_lp_n_doa;

	S4 s4_t_focus_bin;
	FL afl_t_doa_spec[N_DOA];
	S4 s4_t_doa[1];	
	S4 s4_t_doa_range;

	s4_t_doa_range = (S4)((FL)(N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0] + BTT_DBF_DOA_RANGE); //70

	for (u1_t_lp_i = (U1)0; u1_t_lp_i < (U1)N_DOA; u1_t_lp_i++) {
		afl_t_doa_spec[u1_t_lp_i] = (FL)0;
	}

	for(u1_t_lp_i = (U1)0; u1_t_lp_i < (U1)BTT_TLE_RANGE; u1_t_lp_i++){

		s4_t_doa[0] = (S4)0;
		s4_t_focus_bin = FREQ_BIN_LOWER_LIMIT_T + (S4)u1_t_lp_i;

		/***** (2) 4) DOA spectrum based on BF (Beam forming) - Power Estimation- *****/
		fn_calc_spec_bf_4ch_fm(
			(const FL *)(Ryy[s4_t_focus_bin]),			/* [in] */
			afl_t_doa_spec,								/* [out] */
			0,											/* [in] */
			s4_t_focus_bin								/* [in] */
		);
		
		for (u1_t_lp_n_doa = (U1)s4_t_doa_range; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
			afl_t_doa_spec[u1_t_lp_n_doa] = (FL)0.0F;
		}

		/***** (2) 5) DOA peak searching based on BF (Beam forming) *****/
		s4_search_peak_bf(
			(const FL *)afl_t_doa_spec,		/* [in] */
			s4_t_doa,						/* [out] */
			&fl_a_tle_bf_peak[u1_t_lp_i],	/* [out] */
			1								/* [in] */
		);
	}

	return;
}

VD fn_btt_tle_calc_bf_power_diff(
	FL fl_a_tle_bf_peak[BTT_TLE_RANGE],
	FL fl_a_tle_bf_pow_diff[BTT_TLE_RANGE-(S4)1]
)
{
	S4 s4_t_lp_i;

	for(s4_t_lp_i = 0; s4_t_lp_i < BTT_TLE_RANGE - (S4)1; s4_t_lp_i++){
		fl_a_tle_bf_pow_diff[s4_t_lp_i] = fl_a_tle_bf_peak[s4_t_lp_i] - fl_a_tle_bf_peak[s4_t_lp_i + 1];
	}

	return;
}
#endif
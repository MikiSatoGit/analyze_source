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

	/*! @note (1) do nothing if BTT state is already INITIALIZED */
	if( st_g_btt_stat.BTT_initialized == BTT_RET_t.Init_Stat.INITIALIZED )
	{
		return;
	}


	if(
		miki==test
	 && miki==debug
	)
	{
		miki1_1=sub; miki1_2 = (S1)sub; miki1_3() ; miki1_4((S1)arg1);
		if(hogehoge1)
		{
			miki2 = subsub(arg1,arg2);
			for(hogehoge2)
			{
				miki3 = (S1)subsubsub(arg1,arg2,arg3);
				while(hogehoge3_1)
				{
					miki4_1 = subsubsubsub((S1)arg1,(S2)arg2,(S3)arg3);
					if(hogehoge4_1)
					{
						(S5)miki5_1 = subsubsubsubsub_1;
					}
					else if(hogehoge4_2)
					{
						(S5)miki5_2 = subsubsubsubsub_2;
					}
					else
					{
						(S5)miki5_3 = subsubsubsubsub_3;
					}
				}
				switch (hogehoge3_2){
				case mode1:
					miki4_2_1 = subsubsubsub_mode_1;
					break;
				case mode1:
					miki4_2_2 = subsubsubsub_mode_2;
					break;
				default:
					miki4_2_3 = subsubsubsub_mode_default;
					break;
				}

			}
		}
	}




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

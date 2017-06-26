/****************************************************************************/
/* ファイル名	: BSM_ABST_00.c												*/
/*--------------------------------------------------------------------------*/
/* モジュール名	: BSMで用いる仕向け毎で異なる適合定数の読込・算出			*/
/*--------------------------------------------------------------------------*/
/* 機能			: 															*/
/*--------------------------------------------------------------------------*/
/* 備考			:															*/
/*--------------------------------------------------------------------------*/
/* 構成関数		: 															*/
/*--------------------------------------------------------------------------*/
/* 変更履歴		:															*/
/* Version				date				name							*/
/*	t01					14.11.03			走安技1 1技室 K.Kato			*/
/*	新規作成	MWR-RECO-24G-BSM-ABST-00-009 適合データ初期化対応			*/
/*	t02					14.11.03			走安技1 1技室 K.Kato			*/
/*	仕様Q&A No.697, 698対応													*/
/*	t03					14.11.04			走安技1 1技室 K.Kato			*/
/*	残課題 No.148対応														*/
/*	t04					14.11.07			走安技1 1技室 K.Kato			*/
/*	残課題 No.153, 154対応													*/
/*	t05					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替対応															*/
/*	t06					15.02.27			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 _ALWAYS_CHECK_FR_SOTの#ifdef削除								*/
/*	t07					15.03.02			走安技2 1技室 Y.Hosoi			*/
/*	MWR-FLASH-24Ｇ-09-A対応													*/
/*	t08					15.03.20			走安技2 1技室 Y.Hosoi			*/
/*	工程内検査 ID 49 BSMBSM角度読替テーブル左右対応検証用ソフト				*/
/*	t10					15.06.26			走安技2 1技室 G.Jomori			*/
/*	t715マージ																*/
/*	t11					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t12					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t13					15.09.11			走安技2 1技室 G.Jomori			*/
/*	MWR-RECO-24G-BSM-ABST-00-013対応										*/
/*	t14					16.01.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM BSM評価用仕様対応												*/
/*	t15					16.01.26			走安技2 1技室 G.Jomori			*/
/*	291B BSM BSM評価用仕様対応(OBJ変更なし)									*/
/*	t16					16.03.11			走安技2 1技室 G.Jomori			*/
/*	010B CV-R 3/8発行 MWR-RECO-24G-BSM-ABST-00-017対応						*/
/*	t17					16.03.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様対応														*/
/*	t18					16.03.28			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 机上セルフ対応(OBJ変更なし)								*/
/*	t19					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t20					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM 残課題No1336対応 OBJ変更なし										*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t21					16.07.19			走安技2 1技室 Y.Hosoi			*/
/*	車種展開対応															*/
/*  p01                 16.12.06            走安技2 1技室 H.Nakamichi       */
/*  291B 1A納入のためP化を実施                                              */
/*	t24					17.02.02			先安技2 1技室 G.Jomori			*/
/*	310B BSM 現図試作仕様対応(hファイルも変更)								*/
/*	t25					17.02.02			先安技2 1技室 G.Jomori			*/
/*	BSM 机上セルフ指摘対応(OBJ変更なし)										*/
/****************************************************************************/

/****************************************************************************/
/*							インクルードファイル							*/
/****************************************************************************/
#include "inc_bsm.h"


#include "../../../app/config/adjust_table_sns.h"
#include "parameter_sig.h"

#include "bsm_abst_00.h"

#include "../../system/vehicle_spec_mwr.h"

/****************************************************************************/
/*							マクロ定義										*/
/****************************************************************************/
/* 警報領域オフセット (内端) */
#define CFL_D_BSM_ALARM_X_OFFSET_IN_NARROW	(0.0F)
#define CFL_D_BSM_ALARM_X_OFFSET_IN_WIDE	(0.0F)

/* 警報領域オフセット (外端) */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW	(0.35F)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE	(0.05F)	//2017.03.15 Miki 0.25->0.05
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW	(0.2F)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE	(0.0F)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */


/* 警報領域オフセット (後端) */
#define CFL_D_BSM_ALARM_Y_OFFSET_NARROW		(0.0F)
#define CFL_D_BSM_ALARM_Y_OFFSET_WIDE		(0.0F)

/* 警報時間オフセット */
#define CFL_D_BSM_ALARM_OFFSET_TIME_NARROW	(0.0F)
#define CFL_D_BSM_ALARM_OFFSET_TIME_WIDE	(0.0F)

/* 真横判定範囲 */
#define CFL_D_BSM_EKF_RY_SIDE_NARROW		(1.0F)
#define CFL_D_BSM_EKF_RY_SIDE_WIDE			(1.5F)

/* AXIS_DEFAULT == 70 */
/* for Sequoia */
#define CS4_D_SOT_CHECK_CYCLE_FWD2_70		(2)				/* ★ [cycle] */
#define CS4_D_SOT_DELAY_CYCLE_70			(SOT_CHECK_CYCLE_FWD_70+SOT_CHECK_CYCLE_BWD_70+SOT_CHECK_CYCLE_FWD2_70+1)
#define CS4_D_SOT_FIND_CYCLE_70				(1)				/* [cycle] */

#define	CS4_D_SOT_CYCLE_TH_FWD_70			(4)				/* ★  [cycle] smaller than SOT_CHECK_CYCLE_FWD */
#define	CS4_D_SOT_CYCLE_TH_BWD_70			(5)				/* ★  [cycle]smaller than SOT_CHECK_CYCLE_BWD */
#define	CS4_D_SOT_CYCLE_TH_FWD2_70			(1)				/* ★  [cycle]smaller than SOT_CHECK_CYCLE_FWD2 */

#define	CS4_D_SOT_POINT_TH_FWD_70			(3)				/* ★  [-] */
#define	CS4_D_SOT_POINT_TH_BWD_70			(3)				/* ★  [-] */

/* AXIS_DEFAULT != 70 */
/* for Camry */
#define CS4_D_SOT_CHECK_CYCLE_FWD2_OTH		(1)				/* [cycle] */
#define CS4_D_SOT_DELAY_CYCLE_OTH			(SOT_CHECK_CYCLE_FWD_OTH+SOT_CHECK_CYCLE_BWD_OTH+SOT_CHECK_CYCLE_FWD2_OTH+1)	/* [cycle] */
#define CS4_D_SOT_FIND_CYCLE_OTH			(1)				/* [cycle] */

#define	CS4_D_SOT_CYCLE_TH_FWD_OTH			(2)				/* [cycle] smaller than SOT_CHECK_CYCLE_FWD */
#define	CS4_D_SOT_CYCLE_TH_BWD_OTH			(3)				/* [cycle] smaller than SOT_CHECK_CYCLE_BWD */
#define	CS4_D_SOT_CYCLE_TH_FWD2_OTH			(1)				/* [cycle] smaller than SOT_CHECK_CYCLE_FWD2 */

#define	CS4_D_SOT_POINT_TH_FWD_OTH			(2)				/* [-] */
#define	CS4_D_SOT_POINT_TH_BWD_OTH			(2)				/* [-] */


/* 車両後端電力閾値 */
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH_NARROW		(50.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH_WIDE		(50.0F)

/* 車両後端電力差閾値 */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW	(15.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE		(15.0F)
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW    (12.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE      (12.0F)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */

/* ToS 除去範囲 */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW		(0.0F)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE		(-0.5F)
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW     (0.0F)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE       (0.0F)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */


/* 車両後端電力閾値２ */
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_NARROW		(54.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_WIDE		(54.0F)

/* ﾄﾗｯｸｼﾌﾄ距離(X 方向) */
#define CFL_D_BSM_TRUCK_WIDTH_NARROW				(0.0F)
#define CFL_D_BSM_TRUCK_WIDTH_WIDE					(2.6F * 0.5F)

/* 併走車－壁間距離閾値 */
#define CFL_D_BSM_SOT_WALL_DIFF_NARROW				(1.4F)
#define CFL_D_BSM_SOT_WALL_DIFF_WIDE				(1.8F)

/* Gain of wall flag reset */
#if (BSM_OPTION_SW_ABST == TYPE_A)
/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_WALL_OFF_GAIN_NARROW				(32.0F)
#define CFL_D_BSM_WALL_OFF_GAIN_WIDE				(8.0F)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */

/****************************************************************************/
/*							構造体定義										*/
/****************************************************************************/

/****************************************************************************/
/*							グローバル変数宣言								*/
/****************************************************************************/
U2 U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH;						/* 車幅	1mm */
U4 U4_BSM_FLSH_DELTA_W;										/* 取り付け位置ｵﾌｾｯﾄΔW	1mm	車幅～BSMレドム中心 */
U4 U4_BSM_FLSH_FLASH_ANGLE;									/* 取り付け角度	0.1deg	車両側面とセンサのなす角 */
FL FL_BSM_FLSH_BSD_ZONE_Y_MAX;
FL FL_BSM_FLSH_ALARM_X_IN;									/* 警報範囲 (内端) */
FL FL_BSM_FLSH_ALARM_X_OUT;									/* 警報領域 (外端) */
FL FL_BSM_FLSH_ALARM_X_OFFSET_IN;							/* 警報領域オフセット (内端) */
FL FL_BSM_FLSH_ALARM_X_OFFSET_OUT;							/* 警報領域オフセット (外端) */
FL FL_BSM_FLSH_ALARM_Y_OFFSET;								/* 警報領域オフセット (後端) */
FL FL_BSM_FLSH_ALARM_OFFSET_TIME;							/* 警報時間オフセット */
FL FL_BSM_FLSH_EKF_RY_SIDE;									/* 真横判定範囲 */
S4 S4_BSM_FLSH_AXIS_DEFAULT;								/* センサ取付角度設定 四捨五入後のデータ */
FL FL_BSM_FLSH_AXIS_DEFAULT;								/* センサ取付角度設定 */
U4 U4_BSM_FLSH_DELTA_L;										/* 取り付け位置ｵﾌｾｯﾄΔL	1mm	Rrバンパ後端～BSMレドム中心 */

S4 S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2;
S4 S4_BSM_FLSH_SOT_FIND_CYCLE;

S4 S4_BSM_FLSH_SOT_CYCLE_TH_FWD;
S4 S4_BSM_FLSH_SOT_CYCLE_TH_BWD;
S4 S4_BSM_FLSH_SOT_CYCLE_TH_FWD2;

S4 S4_BSM_FLSH_SOT_POINT_TH_FWD;
S4 S4_BSM_FLSH_SOT_POINT_TH_BWD;

FL FL_BSM_FLSH_YOMIKAE_TBL_FM[YOMIKAE_TABLE_SIZE];
FL FL_BSM_FLSH_YOMIKAE_TBL_2F[YOMIKAE_TABLE_SIZE];

FL FL_BSM_ALT_ON_SPEED;
FL FL_BSM_ALT_OFF_SPEED;

FL FL_BSM_VI_TOS_END_FFT_POW_TH;							/* 車両後端電力閾値 */
FL FL_BSM_VI_TOS_END_FFT_POW_DIFF;							/* 車両後端電力差閾値 */
FL FL_BSM_VI_TOS_END_ERASE_LIMIT;							/* ToS 除去範囲 */
FL FL_BSM_VI_TOS_END_FFT_POW_TH2;							/* 車両後端電力閾値２ */
FL FL_BSM_TRUCK_WIDTH;										/* ﾄﾗｯｸｼﾌﾄ距離(X 方向) */
FL FL_BSM_SOT_WALL_DIFF;									/* 併走車－壁間距離閾値 */
#if (BSM_OPTION_SW_ABST == TYPE_A)
/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
FL FL_BSM_WALL_OFF_GAIN;									/* Gain of wall flag reset */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */


/****************************************************************************/
/*							スタティック変数宣言							*/
/****************************************************************************/

/****************************************************************************/
/*							スタティック関数宣言							*/
/****************************************************************************/
VD fn_bsm_abst_read_yomikae_table( U1 u1_a_sns_pos );		/* 方位読み替えテーブルを設定する */
VD fn_bsm_abst_read_data_by_bsmdest( VD );		/* 仕向け毎切替データの設定 */
VD fn_bsm_abst_read_dataA_by_bsmdest( VD );		/* 条件a時の値を設定する */
VD fn_bsm_abst_read_dataB_by_bsmdest( VD );		/* 条件b時の値を設定する */

VD fn_bsm_abst_cal_data( VD );					/* フラッシュ値、仕向け毎データを使ってデータ値算出 */

/****************************************************************************/
/*									注意事項								*/
/****************************************************************************/
/* 警報中フラグの設定関数u1_bsm_set_alarming_flagは関数の見通しをよくするため */
/* bsm_main.cに定義している													  */

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_init_data														*/
/*------------------------------------------------------------------------------------------*/
/* 機能			:																			*/
/*																							*/
/* 注意			: 本関数は、EEPROMのデータを使用するため、fn_init_eeprom()の後に呼び出す事	*/
/*				  u1_g_eep_bsm_dest の確定後でもよい。										*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: 																			*/
/* 戻り値		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_init_data( VD )
{
	/* 1. フラッシュ値の読み込み */
	fn_bsm_abst_read_flashdata(u1_g_sns_pos);

	/* 2. 仕向け毎切替データの設定 */
	fn_bsm_abst_read_data_by_bsmdest();

	/* 1. フラッシュ値、2. 仕向け毎データ の設定値を使ってデータを算出する */
	fn_bsm_abst_cal_data();

	return;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_read_flashdata												*/
/*------------------------------------------------------------------------------------------*/
/* 機能			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: 																			*/
/* 戻り値		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_flashdata( U1 u1_a_sns_pos )
{
	U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH = CU2_D_CAR_WIDTH;						/* 車幅	1mm */

	if (u1_a_sns_pos == SENSOR_RIGHT) { 	/* RIGHT */
		U4_BSM_FLSH_DELTA_W		= CU4_D_RIGHT_MOUNT_OFFSET_W;				/* 右用取り付け位置ｵﾌｾｯﾄΔW	1mm	車幅～BSMレドム中心 */
		U4_BSM_FLSH_FLASH_ANGLE	= CU4_D_RIGHT_MOUNT_OFFSET_ANG;				/* 右用取り付け角度	0.1deg	車両側面とセンサのなす角 */
		U4_BSM_FLSH_DELTA_L		= CU4_D_RIGHT_MOUNT_OFFSET_L;				/* 右用取り付け位置ｵﾌｾｯﾄΔL 1mm Rrバンパ後端～BSMレドム中心 */
	}

	else {									/* LEFT */
		U4_BSM_FLSH_DELTA_W		= CU4_D_LEFT_MOUNT_OFFSET_W;				/* 左用取り付け位置ｵﾌｾｯﾄΔW	1mm	車幅～BSMレドム中心 */
		U4_BSM_FLSH_FLASH_ANGLE	= CU4_D_LEFT_MOUNT_OFFSET_ANG;				/* 左用取り付け角度	0.1deg	車両側面とセンサのなす角 */
		U4_BSM_FLSH_DELTA_L		= CU4_D_LEFT_MOUNT_OFFSET_L;				/* 左用取り付け位置ｵﾌｾｯﾄΔL 1mm Rrバンパ後端～BSMレドム中心 */
	}

	FL_BSM_FLSH_AXIS_DEFAULT	= 90.0F - ((FL)U4_BSM_FLSH_FLASH_ANGLE/10.0F);												/* センサ取付角度設定 */
	/* 仕様 Q&A No.697, 698 */
	/* 四捨五入(0.5 加算後に、S4へキャスト)する */
	S4_BSM_FLSH_AXIS_DEFAULT	= s4_cast_from_fl(FL_BSM_FLSH_AXIS_DEFAULT + 0.5F);

	 /* 方位読み替えテーブル読み出し */
	fn_bsm_abst_read_yomikae_table(u1_a_sns_pos);

	return;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_read_yomikae_table											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: 																			*/
/* 戻り値		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_yomikae_table( U1 u1_a_sns_pos )
{
	U1 u1_t_lp_yomikae_table;
	
	if (u1_a_sns_pos == SENSOR_LEFT) { 	/* LEFT */
		for (u1_t_lp_yomikae_table = (U1)0; u1_t_lp_yomikae_table < (U1)YOMIKAE_TABLE_SIZE; u1_t_lp_yomikae_table++) {
			FL_BSM_FLSH_YOMIKAE_TBL_FM[YOMIKAE_TABLE_SIZE - u1_t_lp_yomikae_table - (U1)1] = (FL)180.0 - CAFL_D_YOMIKAE_TABLE_FM[u1_t_lp_yomikae_table];
			FL_BSM_FLSH_YOMIKAE_TBL_2F[YOMIKAE_TABLE_SIZE - u1_t_lp_yomikae_table - (U1)1] = (FL)180.0 - CAFL_D_YOMIKAE_TABLE_2F[u1_t_lp_yomikae_table];
		}
	} else {
		for (u1_t_lp_yomikae_table = (U1)0; u1_t_lp_yomikae_table < (U1)YOMIKAE_TABLE_SIZE; u1_t_lp_yomikae_table++) {
			FL_BSM_FLSH_YOMIKAE_TBL_FM[u1_t_lp_yomikae_table] = CAFL_D_YOMIKAE_TABLE_FM[u1_t_lp_yomikae_table];
			FL_BSM_FLSH_YOMIKAE_TBL_2F[u1_t_lp_yomikae_table] = CAFL_D_YOMIKAE_TABLE_2F[u1_t_lp_yomikae_table];
		}
	}
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_read_data_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: 																			*/
/* 戻り値		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_data_by_bsmdest( VD )
{
	U1 u1_t_bsm_bsd_zone_y_max;
	
	/* EEPROM格納値 BSM_DEST によって設定値を切り替える */
	FL_BSM_ALT_ON_SPEED = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].fl_ON_ACT_SPEED_BSM;
	FL_BSM_ALT_OFF_SPEED = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].fl_OFF_ACT_SPEED_BSM;
	
	/* BSD_ZONE_Y_MAXを整数値で比較するためにLSB変換前にローカル変数に一旦ラッチする */
	u1_t_bsm_bsd_zone_y_max = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone;
	
	if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_WIDE) {
		/* 条件a の値を設定する */
		fn_bsm_abst_read_dataA_by_bsmdest();
	} else {
		/* 条件b の値を設定する */
		fn_bsm_abst_read_dataB_by_bsmdest();
	}
	
	/* BSD_ZONE_Y_MAXのLSB変換 */
	FL_BSM_FLSH_BSD_ZONE_Y_MAX = (FL)u1_t_bsm_bsd_zone_y_max * (FL)0.1F;

	return;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_read_dataA_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: 仕向けによって設定されるパラメータの値設定(条件a)							*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>		: なし																		*/
/* <output>		: FL_BSM_FLSH_ALARM_X_OFFSET_IN				: 警報領域オフセット (内端) 	*/
/*				: FL_BSM_FLSH_ALARM_X_OFFSET_OUT			: 警報領域オフセット (外端)		*/
/*				: FL_BSM_FLSH_ALARM_Y_OFFSET				: 警報領域オフセット (後端)		*/
/*				: FL_BSM_FLSH_ALARM_OFFSET_TIME				: 警報時間オフセット			*/
/*				: FL_BSM_FLSH_EKF_RY_SIDE					: 真横判定範囲					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH				: 車両後端電力閾値				*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_DIFF			: 車両後端電力差閾値			*/
/*				: FL_BSM_VI_TOS_END_ERASE_LIMIT				: ToS 除去範囲					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH2				: 車両後端電力閾値２			*/
/*				: FL_BSM_TRUCK_WIDTH						: ﾄﾗｯｸｼﾌﾄ距離(X 方向)			*/
/*				: FL_BSM_SOT_WALL_DIFF						: 併走車－壁間距離閾値			*/
/*				: FL_BSM_WALL_OFF_GAIN						: Gain of wall flag reset		*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: G.Jomori																	*/
/*------------------------------------------------------------------------------------------*/
/* 注意：この関数を変更した場合はfn_bsm_abst_read_dataB_by_bsmdest関数も変更すること		*/
/********************************************************************************************/
VD fn_bsm_abst_read_dataA_by_bsmdest( VD )
{
	FL_BSM_FLSH_ALARM_X_OFFSET_IN	= CFL_D_BSM_ALARM_X_OFFSET_IN_WIDE;			/* 警報領域オフセット (内端) */
	FL_BSM_FLSH_ALARM_X_OFFSET_OUT	= CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE;		/* 警報領域オフセット (外端) */
	FL_BSM_FLSH_ALARM_Y_OFFSET		= CFL_D_BSM_ALARM_Y_OFFSET_WIDE;			/* 警報領域オフセット (後端) */
	FL_BSM_FLSH_ALARM_OFFSET_TIME	= CFL_D_BSM_ALARM_OFFSET_TIME_WIDE;			/* 警報時間オフセット */
	FL_BSM_FLSH_EKF_RY_SIDE			= CFL_D_BSM_EKF_RY_SIDE_WIDE;				/* 真横判定範囲 */
	FL_BSM_VI_TOS_END_FFT_POW_TH	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH_WIDE;		/* 車両後端電力閾値 */
	FL_BSM_VI_TOS_END_FFT_POW_DIFF	= CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE;	/* 車両後端電力差閾値 */
	FL_BSM_VI_TOS_END_ERASE_LIMIT	= CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE;	/* ToS 除去範囲 */
	FL_BSM_VI_TOS_END_FFT_POW_TH2	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_WIDE;	/* 車両後端電力閾値２ */
	FL_BSM_TRUCK_WIDTH				= CFL_D_BSM_TRUCK_WIDTH_WIDE;				/* ﾄﾗｯｸｼﾌﾄ距離(X 方向) */
	FL_BSM_SOT_WALL_DIFF			= CFL_D_BSM_SOT_WALL_DIFF_WIDE;				/* 併走車－壁間距離閾値 */
#if (BSM_OPTION_SW_ABST == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
	FL_BSM_WALL_OFF_GAIN			= CFL_D_BSM_WALL_OFF_GAIN_WIDE;				/* Gain of wall flag reset */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */

	return;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_read_dataB_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: 仕向けによって設定されるパラメータの値設定(条件b)							*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>		: なし																		*/
/* <output>		: FL_BSM_FLSH_ALARM_X_OFFSET_IN				: 警報領域オフセット (内端) 	*/
/*				: FL_BSM_FLSH_ALARM_X_OFFSET_OUT			: 警報領域オフセット (外端)		*/
/*				: FL_BSM_FLSH_ALARM_Y_OFFSET				: 警報領域オフセット (後端)		*/
/*				: FL_BSM_FLSH_ALARM_OFFSET_TIME				: 警報時間オフセット			*/
/*				: FL_BSM_FLSH_EKF_RY_SIDE					: 真横判定範囲					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH				: 車両後端電力閾値				*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_DIFF			: 車両後端電力差閾値			*/
/*				: FL_BSM_VI_TOS_END_ERASE_LIMIT				: ToS 除去範囲					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH2				: 車両後端電力閾値２			*/
/*				: FL_BSM_TRUCK_WIDTH						: ﾄﾗｯｸｼﾌﾄ距離(X 方向)			*/
/*				: FL_BSM_SOT_WALL_DIFF						: 併走車－壁間距離閾値			*/
/*				: FL_BSM_WALL_OFF_GAIN						: Gain of wall flag reset		*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: G.Jomori																	*/
/*------------------------------------------------------------------------------------------*/
/* 注意：この関数を変更した場合はfn_bsm_abst_read_dataA_by_bsmdest関数も変更すること		*/
/********************************************************************************************/
VD fn_bsm_abst_read_dataB_by_bsmdest( VD )
{
	FL_BSM_FLSH_ALARM_X_OFFSET_IN	= CFL_D_BSM_ALARM_X_OFFSET_IN_NARROW;			/* 警報領域オフセット (内端) */
	FL_BSM_FLSH_ALARM_X_OFFSET_OUT	= CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW;			/* 警報領域オフセット (外端) */
	FL_BSM_FLSH_ALARM_Y_OFFSET		= CFL_D_BSM_ALARM_Y_OFFSET_NARROW;				/* 警報領域オフセット (後端) */
	FL_BSM_FLSH_ALARM_OFFSET_TIME	= CFL_D_BSM_ALARM_OFFSET_TIME_NARROW;			/* 警報時間オフセット */
	FL_BSM_FLSH_EKF_RY_SIDE			= CFL_D_BSM_EKF_RY_SIDE_NARROW;					/* 真横判定範囲 */
	FL_BSM_VI_TOS_END_FFT_POW_TH	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH_NARROW;		/* 車両後端電力閾値 */
	FL_BSM_VI_TOS_END_FFT_POW_DIFF	= CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW;		/* 車両後端電力差閾値 */
	FL_BSM_VI_TOS_END_ERASE_LIMIT	= CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW;		/* ToS 除去範囲 */
	FL_BSM_VI_TOS_END_FFT_POW_TH2	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_NARROW;		/* 車両後端電力閾値２ */
	FL_BSM_TRUCK_WIDTH				= CFL_D_BSM_TRUCK_WIDTH_NARROW;					/* ﾄﾗｯｸｼﾌﾄ距離(X 方向) */
	FL_BSM_SOT_WALL_DIFF			= CFL_D_BSM_SOT_WALL_DIFF_NARROW;				/* 併走車－壁間距離閾値 */
#if (BSM_OPTION_SW_ABST == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
	FL_BSM_WALL_OFF_GAIN			= CFL_D_BSM_WALL_OFF_GAIN_NARROW;				/* Gain of wall flag reset */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_ABST */

	return;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_abst_cal_data														*/
/*------------------------------------------------------------------------------------------*/
/* 機能			:																			*/
/*																							*/
/*																							*/
/* 注意			: 本関数は、下記関数を両者とも呼び出した後にコールする事					*/
/*				  fn_bsm_abst_read_flashdata,  fn_bsm_abst_read_data_by_bsmdest				*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: 																			*/
/* 戻り値		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 作成者		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_cal_data( VD )
{
	FL_BSM_FLSH_ALARM_X_IN		= ((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH / 1000.0F) / (FL)2 + 0.5F;							/* 警報範囲 (内端) */
	FL_BSM_FLSH_ALARM_X_OUT		= ((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH / 1000.0F) / (FL)2 + FL_BSM_FLSH_BSD_ZONE_Y_MAX;	/* 警報領域 (外端) */


	if (S4_BSM_FLSH_AXIS_DEFAULT  == (S4)70) {
		S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2	= CS4_D_SOT_CHECK_CYCLE_FWD2_70;
		S4_BSM_FLSH_SOT_FIND_CYCLE			= CS4_D_SOT_FIND_CYCLE_70;

		S4_BSM_FLSH_SOT_CYCLE_TH_FWD		= CS4_D_SOT_CYCLE_TH_FWD_70;
		S4_BSM_FLSH_SOT_CYCLE_TH_BWD		= CS4_D_SOT_CYCLE_TH_BWD_70;
		S4_BSM_FLSH_SOT_CYCLE_TH_FWD2		= CS4_D_SOT_CYCLE_TH_FWD2_70;

		S4_BSM_FLSH_SOT_POINT_TH_FWD		= CS4_D_SOT_POINT_TH_FWD_70;
		S4_BSM_FLSH_SOT_POINT_TH_BWD		= CS4_D_SOT_POINT_TH_BWD_70;
	} else {
		S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2	= CS4_D_SOT_CHECK_CYCLE_FWD2_OTH;
		S4_BSM_FLSH_SOT_FIND_CYCLE			= CS4_D_SOT_FIND_CYCLE_OTH;

		S4_BSM_FLSH_SOT_CYCLE_TH_FWD		= CS4_D_SOT_CYCLE_TH_FWD_OTH;
		S4_BSM_FLSH_SOT_CYCLE_TH_BWD		= CS4_D_SOT_CYCLE_TH_BWD_OTH;
		S4_BSM_FLSH_SOT_CYCLE_TH_FWD2		= CS4_D_SOT_CYCLE_TH_FWD2_OTH;

		S4_BSM_FLSH_SOT_POINT_TH_FWD		= CS4_D_SOT_POINT_TH_FWD_OTH;
		S4_BSM_FLSH_SOT_POINT_TH_BWD		= CS4_D_SOT_POINT_TH_BWD_OTH;
	}

	return;
}

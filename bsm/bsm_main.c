/****************************************************************************/
/* ファイル名	: BSM_MAIN.c												*/
/*--------------------------------------------------------------------------*/
/* モジュール名	: BSMメインルーチン											*/
/*--------------------------------------------------------------------------*/
/* 機能			: 															*/
/*--------------------------------------------------------------------------*/
/* 備考			:															*/
/*--------------------------------------------------------------------------*/
/* 構成関数		: 															*/
/*--------------------------------------------------------------------------*/
/* 変更履歴		:															*/
/* Version				date				name							*/
/*	t01					14.10.28			走安技1 1技室 K.Kato			*/
/*  9/17版 BSM最新仕様マージ、及び リファクタリング							*/
/*	t02					14.10.29			走安技1 1技室 D.Saburi			*/
/*  汚れ、軸ズレ処理追加													*/
/*	t03 				14.10.30			走安技1 1技室 K.Kato			*/
/*	AUDR BSM認識データラッチ処理追加										*/
/*	t04 				14.10.30			走安技1 1技室 D.Saburi			*/
/*	指摘事項、仕様回答修正													*/
/*	t05 				14.10.31			走安技1 1技室 D.Saburi			*/
/*	暫定ファイルの削除対応													*/
/*	t06 				14.11.03			走安技1 1技室 K.Kato			*/
/*	MWR-RECO-24G-BSM-ABST-00-009 適合データ初期化対応						*/
/*	t07 				14.11.03			走安技1 1技室 D.Saburi			*/
/*	DR指摘事項修正															*/
/*	t08					14.11.03			走安技1 1技室 K.Kato			*/
/*	仕様Q&A No.697, 698対応													*/
/*	t09					14.11.07			走安技1 1技室 K.Kato			*/
/*	残課題 No.153対応														*/
/*	t10					15.01.09			走安技2 1技室 G.Jomori			*/
/*	干渉波対策 MWR-RECO-24G-INTERFERENCE-REDUCTION-01-003対応				*/
/*	t11					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替対応															*/
/*	t12					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 仕様確認項目対応												*/
/*	t13					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM QAC対応(OBJ変更あり)												*/
/*	t14					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM QAC対応(OBJ変更なし)												*/
/*	t15					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM QAC再対応(OBJ変更なし)												*/
/*	t16					15.05.26			走安技2 1技室 G.Jomori			*/
/*	残課題No164対応															*/
/*	t19					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t20					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t21					15.08.19			走安技2 1技室 G.Jomori			*/
/*	AUDR BSM部分を繋げる													*/
/*	t22					15.08.31			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1501対応														*/
/*	t23					15.10.23			走安技2 1技室 M.Tanaka			*/
/*	残課題No.849対応(暗黙のキャストを修正)									*/
/*	t24					15.11.16			走安技2 1技室 Y.Nishioka		*/
/*	残課題No.235対応(インデント修正)		※OBJ変更なし					*/
/*	t25					15.11.17			走安技2 1技室 G.Jomori			*/
/*	BSM CV対応																*/
/*	t26					15.11.17			走安技2 1技室 G.Jomori			*/
/*	BSM 警報判定処理を全て警報判定のメイン関数からコールする				*/
/*	t27					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t28					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1198対応(ローカル配列変数の宣言と同時に実施の初期化分離)		*/
/*	t29					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応(OBJ変更なし)						*/
/*	t30					16.04.07			走安技2 1技室 G.Jomori			*/
/*	BSM QAC 指摘対応														*/
/*	t31					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t32					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t33					16.06.20			走安技2 1技室 H.Nonogaki		*/
/*	QAC 指摘対応(OBJ変更無し)												*/
/*	t34					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t38					16.08.01			走安技2 1技室 Y.Nishioka		*/
/*	310B_CV LCAを追加														*/
/*	t41					16.08.24			走安技2 1技室 G.Jomori			*/
/*	010B 2A 認識部分(BSM,RCTA,AUDR)マージ									*/
/*	t43					17.02.02			先安技2 1技室 G.Jomori			*/
/*	310B BSM 現図試作仕様対応												*/
/*	t44					17.03.02			先安技2 1技室 G.Jomori			*/
/*	残課題No1480対応(定数の数字部分に括弧付与 OBJ変更なし hファイル変更)	*/
//****************************************************************************/

/****************************************************************************/
/*							インクルードファイル							*/
/****************************************************************************/
#include "inc_bsm.h"				/* グローバル変数用define参照 */
//#include "parameter_def.h"
#include "parameter_adj.h"
//#include "normal_def.h"

#include "../common/cmn_signal.h"
#include "target/init_cvw.h"
#include "target/bsm_recog_01.h"
#include "target/bsm_recog_02.h"
#include "target/bsm_recog_03.h"
#include "target/bsm_recog_04.h"
#include "target/bsm_connect_01.h"
#include "app_alarm/bsm_alarm_01.h"

#if !defined( _291B_DEV_20161005_BTT_TEST)
#include "btt/bsm_btt.h"
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
#include "target/bsm_recog_05.h"
#endif

#include "bsm_main.h"

#include "../../common/inc_mwr.h"

#ifdef _DIRECTIVITY_TEST	// for directivity check
#include "../../recog/bsm\target\func_fmcw.h"
#endif


#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif /*VI 表示用*/

/****************************************************************************/
/*							マクロ定義										*/
/****************************************************************************/

/****************************************************************************/
/*							構造体定義										*/
/****************************************************************************/

/****************************************************************************/
/*							スタティック変数宣言							*/
/****************************************************************************/
BSM_LOOP_DATA st_g_bsm_loop_data;			/* 基本データ */

/****************************************************************************/
/* 参照グローバル変数(暫定)													*/
/****************************************************************************/

#if (MODE_ECU_SIM == SIM_MODE)
FL fl_g_wall_dev;											/* SIM出力用データ */
FL afl_g_Tx_float[TARGET_BUFFSIZE][4];						/* SIM出力用データ */
#endif

#if (MODE_ECU_SIM == SIM_MODE)
extern FL fl_g_simm_bsm_auto_axis;
#endif


/****************************************************************************/
/*							スタティック関数宣言							*/
/****************************************************************************/

VD fn_bsm_nbd_input_recog_data( 
	BSM_OUT_DATA *pst_a_out_data,
	S4 s4_a_pair_num_sot,
	S4 s4_a_truck_flg
);

VD fn_bsm_set_low_speed_flg(VD);
U1 u1_bsm_set_alarming_flag(VD);


/********************************************************************************************/
/* 関数名		: fn_bsm_main()																*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: BSMメイン関数																*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	:								 											*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/

VD fn_bsm_main(VD)
{

/****************************************************************************/
/* データ宣言																*/
/****************************************************************************/
	/***** 使用するデータ構造 ***************************************************/
	BSM_OUT_DATA st_t_out_data;

	S4 s4_t_pair_num_sot = 0;

	/***** パラメータ設定変数 ***************************************************/
	FL afl_t_sot_detect_param[9];
	FL afl_t_tos_end_param[6];

	/***** CAN出力用変数 ********************************************************/
	U1 u1_t_1byte_data[2];
	S2 s2_t_2byte_data;

	/***** 補助物標認識処理用変数 ***********************************************/
	FL afl_t_wall_width[1];

	S4 s4_t_flg_bsm_map;
	
	FL fl_t_tmp_frontline_pow_dn;
	S4 as4_t_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1];
	S4 as4_t_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE];

	U1 u1_t_alarming_flag;

#ifdef _DIRECTIVITY_TEST	// for directivity check
	S4 i,j;
	S4 s4_t_target_bin = 280;//68;
	FL fl_t_spec_bf[2][N_DOA] = {0.0F};
	S4 s4_t_peak_bin[2][WAVE_NUMBER_MAX]= {0};
	FL fl_t_peak_power[2][WAVE_NUMBER_MAX]= {0.0F};
	FL fl_t_peak_bin[2][WAVE_NUMBER_MAX]= {0.0F};
#endif

#if !defined( _291B_DEV_20161005_BTT_TEST)
	/* for test */
	U1 u1_t_btt_alarm_flag_for_test;
	NORMAL_BSM ast_t_btt_target_for_test[TARGET_BUFFSIZE];
	S4 s4_t_btt_target_size;
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20170119_ATD_DOADBF_CHECK)
	FL fl_t_doa_pow_ave[2][3];
	FL fl_t_doa_pow_dev[2][3];
	S4 s4_t_doa_bf_peak_bin;
	FL fl_t_doa_bf_peak_pow;
#endif
/****************************************************************************/
/* データ初期化																*/
/****************************************************************************/
#if (MODE_ECU_SIM == ECU_MODE)
	/***** 実車処理時間計測用 ***************************************************/
	/* S4→U1のダウンキャストであるが、値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_connect_pre_pair_num = (U1)st_g_bsm_loop_data.as4_buf_pair_num[0];			/* CheckPoint 前周期の物標数 */
	u1_g_bsm_connect_pre_target_num = (U1)st_g_bsm_loop_data.as4_buf_pair_num[1];		/* CheckPoint 前周期のターゲット数 */
#endif

	/***** 使用するデータ構造 ***************************************************/
	fn_out_data_initialize(&st_t_out_data);

	/***** パラメータ設定変数 ***************************************************/
	afl_t_sot_detect_param[0] = 0.0F;
	afl_t_sot_detect_param[1] = 0.0F;
	afl_t_sot_detect_param[2] = SLOW_SOT_V0_DOA;
	afl_t_sot_detect_param[3] = 0.0F;
	afl_t_sot_detect_param[4] = 0.0F;
	afl_t_sot_detect_param[5] = 0.0F;
	afl_t_sot_detect_param[6] = 0.0F;
	afl_t_sot_detect_param[7] = 0.0F;
	afl_t_sot_detect_param[8] = 0.0F;

	/*** ToS終了検出パラメータ ***/
	afl_t_tos_end_param[0] = VI_TOS_END_FREQ_BIN;
	afl_t_tos_end_param[1] = VI_TOS_END_FFT_POW_TH;
	afl_t_tos_end_param[2] = VI_TOS_END_FFT_POW_DIFF;
	afl_t_tos_end_param[3] = VI_TOS_END_ERASE_LIMIT;
	afl_t_tos_end_param[4] = VI_TOS_END_FFT_POW_TH2;		/* _20131214_3 */
	afl_t_tos_end_param[5] = CFL_VI_TOS_END_FFT_POW_DIFF2;	/* _20131214_3 */

	fl_t_tmp_frontline_pow_dn = (FL)0.0F;

	as4_t_frontline_doa_dn[0][0] = (S4)0;
	as4_t_frontline_doa_dn[1][0] = (S4)0;
	as4_t_frontline_doa_dn[2][0] = (S4)0;
	as4_t_frontline_doa_dn[3][0] = (S4)0;
	as4_t_frontline_doa_dn[4][0] = (S4)0;

	as4_t_froneline_doa_peak_num_dn[0] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[1] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[2] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[3] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[4] = (S4)0;

	afl_t_wall_width[0] = (FL)0.0F;

	/* 低速走行フラグ設定 */
	fn_bsm_set_low_speed_flg();

	/* 警報中フラグの設定 */
	u1_t_alarming_flag = u1_bsm_set_alarming_flag();

#ifdef _DIRECTIVITY_TEST	// for directivity check
	// UP
	fn_calc_spec_bf_4ch_fm(
		afl_g_cvw_lfm_ryy_matrix[0][s4_t_target_bin],
			fl_t_spec_bf[0],
			0,
			s4_t_target_bin
	);
	s4_search_peak_bf(
		fl_t_spec_bf[0],		// [in]
		s4_t_peak_bin[0],		// [out]
		fl_t_peak_power[0],		// [out]
		1						// [in]
	);
	fl_t_peak_bin[0][0] = fl_interpolate_music_peak(
		fl_t_spec_bf[0],
		s4_t_peak_bin[0][0],
		FL_BSM_FLSH_YOMIKAE_TBL_FM
	);
	// DN
	fn_calc_spec_bf_4ch_fm(
		afl_g_cvw_lfm_ryy_matrix[1][s4_t_target_bin],
			fl_t_spec_bf[1],
			1,
			s4_t_target_bin
	);
	s4_search_peak_bf(
		fl_t_spec_bf[1],		// [in]
		s4_t_peak_bin[1],		// [out]
		fl_t_peak_power[1],		// [out]
		1						// [in]
	);
	fl_t_peak_bin[1][0] = fl_interpolate_music_peak(
		fl_t_spec_bf[1],
		s4_t_peak_bin[1][0],
		FL_BSM_FLSH_YOMIKAE_TBL_FM
	);
	for(i=0; i<2; i++)
	{
		for(j=0; j<WAVE_NUMBER_MAX; j++)
		{
			afl_g_peak_power_directivity[i][j] = fl_t_peak_power[i][j];
			afl_g_peak_bin_directivity[i][j] = fl_t_peak_bin[i][j];
		};
	};
#else	// else of _DIRECTIVITY_TEST

#if !defined( _291B_DEV_20161005_BTT_TEST)
	/* for test */
	/* NOTE: These parameters should be set once at the beginning of the whole process ( out of bsm_main() ) */
	init_btt_configuration_parameter_dummy(
		&st_g_bsm_alertarea_for_test,
		&st_g_cluster_info_for_test,
		&st_g_aux_trailer_info_for_test,
		&st_g_hitch_angle_for_test
	);
	u1_t_btt_alarm_flag_for_test = (U1) 0;
	fn_init(ast_t_btt_target_for_test, TARGET_BUFFSIZE);
	s4_t_btt_target_size = (S4) 0;
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20170119_ATD_DOADBF_CHECK)
	fl_t_doa_pow_ave[0][0] = (FL)0;
	fl_t_doa_pow_ave[0][1] = (FL)0;
	fl_t_doa_pow_ave[0][2] = (FL)0;
	fl_t_doa_pow_ave[1][0] = (FL)0;
	fl_t_doa_pow_ave[1][1] = (FL)0;
	fl_t_doa_pow_ave[1][2] = (FL)0;
	fl_t_doa_pow_dev[0][0] = (FL)0;
	fl_t_doa_pow_dev[0][1] = (FL)0;
	fl_t_doa_pow_dev[0][2] = (FL)0;
	fl_t_doa_pow_dev[1][0] = (FL)0;
	fl_t_doa_pow_dev[1][1] = (FL)0;
	fl_t_doa_pow_dev[1][2] = (FL)0;
	s4_t_doa_bf_peak_bin = (S4)-1;
	fl_t_doa_bf_peak_pow = (FL)0;
#endif

/****************************************************************************/
/* 認識処理																	*/
/****************************************************************************/

	/* MWR-RECO-24G-BSM-ALART-01-006の(6)警報エリア前端監視処理		*/
	/* 5)警報エリア前端の物標検出状態の確認の						*/
	/* (ii)警報エリア前端ライン（車両後端相当bin）の方位確認実施	*/
	calc_front_1m_line(
		&fl_t_tmp_frontline_pow_dn,
		(const FL (*))afl_t_tos_end_param,
		as4_t_frontline_doa_dn,
		as4_t_froneline_doa_peak_num_dn
	);

/* FMCWで干渉過多による今サイクルスキップがあれば物標検出ロジックスキップ */
#ifdef _USE_INTERFERENCE_SKIP
if(au4_g_interference_skipcount[0] == 0)
#endif
{	
/****************************************************************************/
/* ２－x． 低速ＳｏＴ(V0.3で追加される機能)                                 */
/****************************************************************************/
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(24, &au2_g_bsm_check_tmr[24]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */
	/* [SEQ:2]物標検出（低速SoT） */
#if (MODE_ECU_SIM == SIM_MODE)
	fl_g_wall_dev = fl_seek_low_speed_sot(
#else
					fl_seek_low_speed_sot(
#endif
						(const FL *)afl_t_sot_detect_param,		/* [in] */
						u1_t_alarming_flag
					);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(25, &au2_g_bsm_check_tmr[25]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

/****************************************************************************/
/* ２－３． 前側方物標認識処理                                              */
/****************************************************************************/
	/* [SEQ:3]物標検出（SoT） */
	s4_t_pair_num_sot = s4_seek_sidewinder(
							st_g_bsm_loop_data.ast_normal_wall,		/* [in/out] */
							st_g_bsm_loop_data.ast_normal_sot		/* [in/out] */
						);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(26, &au2_g_bsm_check_tmr[26]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

/****************************************************************************/
/* ２－１． 優先物標認識処理                                                */
/****************************************************************************/
	/* [SEQ:4]物標検出（優先） */
	fn_bsm_seek_prior_object(
		&st_t_out_data.s4_pair_num_prior,
		st_t_out_data.ast_normal_prior						/* [in/out] */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(27, &au2_g_bsm_check_tmr[27]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* ２－２． 通常物標認識処理                                                */
/****************************************************************************/
	/* [SEQ:5]物標検出（通常） */
	fn_bsm_seek_ordinary_object(
		&st_t_out_data.s4_pair_num_ordinary,
	 	st_t_out_data.ast_normal_ordinary					/* [in/out] */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(30, &au2_g_bsm_check_tmr[30]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* ２－４． 補助物標認識処理                                                */
/****************************************************************************/
	/* [SEQ:6]物標検出（2周波） */
	afl_t_wall_width[0] = WALL_MAX + 4.0F;

	fn_bsm_seek_2f_object(
		&st_t_out_data.s4_pair_num_2f,
		st_t_out_data.ast_normal_2f,
		u1_t_alarming_flag
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(31, &au2_g_bsm_check_tmr[31]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

}	/* if(au4_g_interference_skipcount[0] == 0){ のEND部 */


#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
/****************************************************************************/
/* ２－５． Trailer Object Detection                                        */
/****************************************************************************/
#ifndef _20170220_BTT_TRAILEROBJ
	if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.CONNECT
	||  st_g_btt_stat.ATD == BTT_RET_t.Func_Stat.ACTIVE ){
#endif
		fn_bsm_seek_trailer_object(
			&st_t_out_data.s4_pair_num_ordinary,
	 		st_t_out_data.ast_normal_ordinary,
			&st_t_out_data.s4_pair_num_trailer
			,st_t_out_data.ast_normal_trailer
#ifndef _20170119_ATD_DOADBF_CHECK
			,fl_t_doa_pow_ave
			,fl_t_doa_pow_dev
			,&s4_t_doa_bf_peak_bin
			,&fl_t_doa_bf_peak_pow
#endif
		);
#ifndef _20170220_BTT_TRAILEROBJ
	}
#endif
#endif


/****************************************************************************/
/* ３－１． 物標選択処理                                                    */
/****************************************************************************/
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	s4_g_pair_num_prior = st_t_out_data.s4_pair_num_prior;
	memcpy (ast_g_normal_prior, st_t_out_data.ast_normal_prior, sizeof(NORMAL_BSM)*PRIOR_BUFFSIZE);
	s4_g_pair_num_ordinary = st_t_out_data.s4_pair_num_ordinary;
	memcpy (ast_g_normal_ordinary, st_t_out_data.ast_normal_ordinary, sizeof(NORMAL_BSM)*ORDINARY_BUFFSIZE);
	s4_g_pair_num_2f = st_t_out_data.s4_pair_num_2f;
	memcpy (ast_g_normal_2f, st_t_out_data.ast_normal_2f, sizeof(NORMAL_BSM)*AUX_BUFFSIZE);
	memcpy (ast_g_normal_sot, st_g_bsm_loop_data.ast_normal_sot, sizeof(NORMAL_BSM)*1);
	memcpy (ast_g_normal_wall, st_g_bsm_loop_data.ast_normal_wall, sizeof(NORMAL_BSM)*1);
#endif /*VI 表示用*/

	/* [SEQ:7]トラッキング・物標選択 */
	st_g_bsm_loop_data.s4_final_target_num = s4_bsm_connect(
		/* 優先物標 */
		st_t_out_data.s4_pair_num_prior,
		st_t_out_data.ast_normal_prior,
		/* 通常物標 */
		st_t_out_data.s4_pair_num_ordinary,
		st_t_out_data.ast_normal_ordinary,
		/* 補助物標 */
		st_t_out_data.s4_pair_num_2f,
		(const NORMAL_BSM (*))st_t_out_data.ast_normal_2f,
		/* 前側方物標 */
		s4_t_pair_num_sot,
		st_g_bsm_loop_data.ast_normal_sot,

		st_t_out_data.as4_Tx_int,
		st_t_out_data.afl_Tx_float,

		u1_t_alarming_flag
/* $$$ 2013.11.1 前側方物標も物標統合されているのでここで追加する必要はない */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(32, &au2_g_bsm_check_tmr[32]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */




#if !defined( _291B_DEV_20161005_BTT_TEST)
/****************************************************************************/
/* BTT				                                                        */
/****************************************************************************/
	/* for test */
	/* fn_btt_initialize() and fn_btt_main() should be called in proper step */
	/* just a note: may need "seek_trailer_object()" or something for input object data in the future */
	enter_btt_dummy(
		/********** input **********/
		fl_g_v_self_bsm_for_base,
		s2_g_curvr_for_base,
		1,									/* (tentative) Shift = not R */
#ifndef _20161116_BTT_TRAILER_OBJ_FUNC_T
		st_t_out_data.ast_normal_trailer,	/* (tentative) Ordinary object */
		st_t_out_data.s4_pair_num_trailer,	/* (tentative) Ordinary object */
#else
		st_t_out_data.ast_normal_ordinary,	/* (tentative) Ordinary object */
		st_t_out_data.s4_pair_num_ordinary,	/* (tentative) Ordinary object */
#endif
#ifndef _20170119_ATD_DOADBF_CHECK
		fl_t_doa_pow_ave,
		fl_t_doa_pow_dev,
		s4_t_doa_bf_peak_bin,
		fl_t_doa_bf_peak_pow,
#endif
		BTT_DRV_SW_ON,						/* BTT SW = ON */
		&st_g_cluster_info_for_test,		/* (dummy) Trailer info selected by driver */
		&st_g_aux_trailer_info_for_test,	/* (dummy) Additional trailer or object info from other system or module */
		&st_g_hitch_angle_for_test,			/* (dummy) Angle between subject vehicle and trailer */

		/********** output **********/
		&u1_t_btt_alarm_flag_for_test,
		&ast_t_btt_target_for_test,
		s4_t_btt_target_size,
		&st_g_btt_stat
	);
#endif

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
	s4_g_pair_num_trailer = st_t_out_data.s4_pair_num_trailer;
	memcpy (ast_g_normal_trailer, st_t_out_data.ast_normal_trailer, sizeof(NORMAL_BSM)*TRAILER_BUFFSIZE);
#endif

/****************************************************************************/
/* ４． 警報判定処理                                                        */
/****************************************************************************/

	st_g_bsm_loop_data.s4_flg_alarm = s4_alarm_bsm2(
		st_g_bsm_loop_data.s4_final_target_num,
		st_t_out_data.as4_Tx_int,
		st_t_out_data.afl_Tx_float,
		u1_t_alarming_flag,
		(const FL (*))afl_t_tos_end_param,
		fl_t_tmp_frontline_pow_dn,
		as4_t_frontline_doa_dn,
		(const S4 (*))as4_t_froneline_doa_peak_num_dn
	);

	st_g_bsm_alarm_data.s4_alarm_prev = st_g_bsm_loop_data.s4_flg_alarm;
#endif		// end of _DIRECTIVITY_TEST

#if (MODE_ECU_SIM == SIM_MODE)
	{
		S4 s4_t_lp_i;
		for(s4_t_lp_i=0; s4_t_lp_i<TARGET_BUFFSIZE; s4_t_lp_i++) {
			afl_g_Tx_float[s4_t_lp_i][0] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][1] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][2] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][3] = CFL_UNKNOWN_VALUE;
		}
		for(s4_t_lp_i=0; s4_t_lp_i < st_g_bsm_loop_data.s4_final_target_num; s4_t_lp_i++) {
			if(	st_t_out_data.afl_Tx_float[s4_t_lp_i][8] != CFL_UNKNOWN_VALUE ) {
				afl_g_Tx_float[s4_t_lp_i][0] = st_t_out_data.afl_Tx_float[s4_t_lp_i][8];		/* Rxfil */
				afl_g_Tx_float[s4_t_lp_i][1] = st_t_out_data.afl_Tx_float[s4_t_lp_i][7];		/* Ryfil */
				afl_g_Tx_float[s4_t_lp_i][2] = st_t_out_data.afl_Tx_float[s4_t_lp_i][14]*3.6F;	/* Vxfil [m/s]→[km/h] */
				afl_g_Tx_float[s4_t_lp_i][3] = st_t_out_data.afl_Tx_float[s4_t_lp_i][13]*3.6F;	/* Vyfil */
			}
		}
	}
#endif

#if (MODE_ECU_SIM == ECU_MODE)
		fn_bsm_nbd_input_recog_data(&st_t_out_data, s4_t_pair_num_sot, st_g_bsm_loop_data.u1_truck_flg);
#endif

	return ;

}

/********************************************************************************************/
/* 関数名		: fn_bsm_set_low_speed_flg													*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: 低速走行フラグ値設定														*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-ABST-00-011												*/
/********************************************************************************************/
VD fn_bsm_set_low_speed_flg(VD)
{
	if (fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN) {
		st_g_bsm_loop_data.as4_low_speed_flg[0] = 1;
	}
	if ((st_g_bsm_loop_data.as4_low_speed_flg[0] == 1)
	&&  (fl_g_v_self_bsm_for_base > CANOUT_VSELF_SLOW)) {
		st_g_bsm_loop_data.as4_low_speed_flg[0] = 0;
	}

	return;
}

/********************************************************************************************/
/* 関数名		: u1_bsm_set_alarming_flag													*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: 警報中フラグ値設定														*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/* 戻り値		: u1_t_result_alarming_flag		: 警報中フラグ判定結果						*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	: st_g_bsm_alarm_data.afl_alarmed_target	: 警報ターゲット情報 [in]		*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-ABST-00-011 (※8)警報中フラグについて 					*/
/*------------------------------------------------------------------------------------------*/
/* 備考			: この処理の定義はABST仕様書に定義されているが、処理の見通しさを			*/
/*				  分かりやすくするためbsm_main.cに定義している								*/
/********************************************************************************************/
U1 u1_bsm_set_alarming_flag(VD)
{
	U1 u1_t_result_alarming_flag;
	U1 u1_t_lp_target_num;
	
	u1_t_result_alarming_flag = (U1)0;
	
	for (u1_t_lp_target_num = (U1)0; u1_t_lp_target_num < TARGET_BUFFSIZE; u1_t_lp_target_num++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[u1_t_lp_target_num][0] != CFL_UNKNOWN_VALUE) {
			u1_t_result_alarming_flag = (U1)1;
			break;
		}
	}
	
	return u1_t_result_alarming_flag;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_nbd_input_recog_data												*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: NBD 認識データの格納処理													*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_bsm_nbd_input_recog_data( 
	BSM_OUT_DATA *pst_a_out_data,
	S4 s4_a_pair_num_sot,
	S4 s4_a_truck_flg
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_lp_g;

	/* ガード処理等は今後のリファクタリングで対応予定 */

	/* センサ取り付け位置 */
	afl_g_bsm_sensor_position[0] = st_g_bsm_loop_data.afl_installed_angle[0];
	afl_g_bsm_sensor_position[1] = st_g_bsm_loop_data.afl_installed_angle[1];
	afl_g_bsm_sensor_position[2] = st_g_bsm_loop_data.afl_installed_angle[2];

	/* 物標数 */
	/* ↓S4→U1のダウンキャストであるが、全ての変数の値域がU1の範囲に収まるため問題ない↓ */
	au1_g_bsm_pair_num[0] = (U1)st_g_bsm_loop_data.as4_buf_pair_num[0];			/* 候補物標数 */
	au1_g_bsm_pair_num[1] = (U1)st_g_bsm_loop_data.as4_buf_pair_num[1];			/* ﾀｰｹﾞｯﾄ数 */

	u1_g_bsm_pair_num_prior		= (U1)pst_a_out_data->s4_pair_num_prior;		/* 優先物標数 */
	u1_g_bsm_pair_num_ordinary	= (U1)pst_a_out_data->s4_pair_num_ordinary;		/* 通常物標数 */
	u1_g_bsm_pair_num_2f		= (U1)pst_a_out_data->s4_pair_num_2f;			/* 補助物標数 */
	u1_g_bsm_pair_num_side		= (U1)s4_a_pair_num_sot;						/* 前側方物標数 */
	/* ↑S4→U1のダウンキャストであるが、全ての変数の値域がU1の範囲に収まるため問題ない↑ */
#if		(NBD_TYPE == CU1_DF_NBD_BSM_ONLY)
	for (s4_t_lp_i=0; s4_t_lp_i<20; s4_t_lp_i++ ){
		/* ↓S4→S2のダウンキャストであるが、s4_flg_track以外の変数の値域がS2の範囲に収まるため問題ない↓ */
		/* s4_flg_trackは値域がS2の範囲を超える可能性があるが、ラッチ先のast_g_bsm_normal[]はNBD出力にしか使用されないため、ダウンキャストしても問題ない */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_up					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_up;						/* 上りﾋﾟｰｸbin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_dn					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_dn;						/* 下りﾋﾟｰｸbin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_up_music				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_up_music;					/* 上り方位bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_dn_music				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_dn_music;					/* 下り方位bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_stop					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_stop;						/* 停止物フラグ */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_track				= s2_data_grd((S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_track, CS2_S2MAX, CS2_S2MIN);		/* 履歴接続回数 */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_lost					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_lost;						/* 外挿回数 */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_new					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_new;						/* 新規物標フラグ */
		ast_g_bsm_normal[s4_t_lp_i].s2_ctr_sot_cut				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ctr_sot_cut;					/* fast-Sotカット対象フラグ */
		ast_g_bsm_normal[s4_t_lp_i].s2_ID_num					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ID_num;						/* ﾀｰｹﾞｯﾄID */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_dc					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_dc;						/* 物標種別 */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_reliable				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_reliable;					/* 物標確定フラグ */
		ast_g_bsm_normal[s4_t_lp_i].s2_ctr_tos					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ctr_tos;						/* Tosらしさカウンタ */
		/* ↑S4→S2のダウンキャストであるが、s4_flg_track以外の値域がS2の範囲に収まるため問題ない↑ */
		/* s4_flg_trackは値域がS2の範囲を超える可能性があるが、ラッチ先のast_g_bsm_normal[]はNBD出力にしか使用されないため、ダウンキャストしても問題ない */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_up					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_up;						/* 上りﾋﾟｰｸ電力 */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_dn					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_dn;						/* 下りﾋﾟｰｸ電力 */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_up_music			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_up_music;				/* 上り方位電力 */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_dn_music			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_dn_music;				/* 下り方位電力 */
		ast_g_bsm_normal[s4_t_lp_i].fl_theta_up_pred			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_theta_up_pred;				/* 上りﾋﾟｰｸ検出角度予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_theta_dn_pred			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_theta_dn_pred;				/* 下りﾋﾟｰｸ検出角度予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxobs;						/* X方向距離観測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ryobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ryobs;						/* Y方向距離観測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxfil;						/* X方向距離出力値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ryfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ryfil;						/* Y方向距離出力値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxpred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxpred;						/* X方向距離予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rypred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rypred;						/* Y方向距離予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxobs;						/* X方向速度観測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vyobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vyobs;						/* Y方向速度観測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxfil;						/* X方向速度出力値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vyfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vyfil;						/* Y方向速度出力値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxpred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxpred;						/* X方向速度予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vypred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vypred;						/* Y方向速度予測値 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Axfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Axfil;						/* X方向加速度 */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ayfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ayfil;						/* Y方向加速度 */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_up_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_up_interpolate;			/* 上り方位bin[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_dn_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_dn_interpolate;			/* 下り方位bin[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_up_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_up_interpolate_pred;		/* 上り方位bin予測値[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_dn_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_dn_interpolate_pred;		/* 下り方位bin予測値[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_up_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_up_interpolate;			/* 上りﾋﾟｰｸbin[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_dn_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_dn_interpolate;			/* 下りﾋﾟｰｸbin[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_up_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_up_interpolate_pred;		/* 上りﾋﾟｰｸbin予測値[補間値] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_dn_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_dn_interpolate_pred;		/* 下りﾋﾟｰｸbin予測値[補間値] */
	}
#elif	(NBD_TYPE == CU1_DF_NBD_BSM_LCA)
	/* 何もしない */
#else
	コンパイルエラー
#endif /* NBD_TYPE */
	

	fl_g_bsm_wall_width		= st_g_bsm_loop_data.afl_wall_width[0];			/* 壁推定距離 */
	/* S4→U1のダウンキャストであるが、as4_flg_passing[0]以外の変数の値域がU1の範囲に収まるため問題ない */
	/* as4_flg_passing[0]は値域がU1の範囲を超える可能性があるが、ラッチ先のu1_g_bsm_passing_flgはNBD出力にしか使用されないため、ダウンキャストしても問題ない */
	u1_g_bsm_leading_flg	= (U1)st_g_bsm_loop_data.as4_flg_leading[0];		/* 併走車フラグ */
	u1_g_bsm_passing_flg	= (U1)u1_data_grd((U1)st_g_bsm_loop_data.as4_flg_passing[0], CU1_U1MAX, CU1_U1MIN);		/* 追越車フラグ */
	u1_g_bsm_truck_flg		= (U1)s4_a_truck_flg;								/* トラックフラグ */

	/* 低速SoT判定フラグ */
	/* S4→U1のダウンキャストであるが、as4_slow_sot_find[0,1]の値域がU1の範囲に収まるため問題ない */
	au1_g_bsm_sot_find[0] = (U1)st_g_bsm_loop_data.as4_slow_sot_find[0];	/* SoT判定フラグ */
	au1_g_bsm_sot_find[1] = (U1)st_g_bsm_loop_data.as4_slow_sot_find[1];	/* 壁判定フラグ */

	for (s4_t_lp_i=0; s4_t_lp_i<6; s4_t_lp_i++ ){
		/* S4→S2のダウンキャストであるが、as4_slow_sot_doa_diff_sum[]の値域がU1の範囲に収まるため問題ない */
		as2_g_bsm_doa_diff_sum[s4_t_lp_i] = (S2)st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[s4_t_lp_i];
	}

	for (s4_t_lp_i=0; s4_t_lp_i<2; s4_t_lp_i++ ){
		for (s4_t_lp_k=0; s4_t_lp_k<3; s4_t_lp_k++ ){
			for (s4_t_lp_g=0; s4_t_lp_g<12; s4_t_lp_g++ ){
				/* SoT-停止物の差分量ﾊﾞｯﾌｧ */
				/* S4→S2のダウンキャストであるが、as2_g_bsm_sot_check_sum[][][]はNBD出力にしか使用されないため、問題ない */
				as2_g_bsm_sot_check_sum[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g] 
					= s2_data_grd((S2)st_g_bsm_loop_data.as4_sot_check_sum[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g], CS2_S2MAX, CS2_S2MIN);
				
				/* SoT-停止物の差分点数ﾊﾞｯﾌｧ */
				/* S4→S2のダウンキャストであるが、as2_g_bsm_sot_check_points[][][]はNBD出力にしか使用されないため、問題ない */
				as2_g_bsm_sot_check_points[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g]
					= s2_data_grd((S2)st_g_bsm_loop_data.as4_sot_check_points[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g], CS2_S2MAX, CS2_S2MIN);
			}
		}
	}

	/* fast-SoT 判定フラグ */
	/* S4→U1のダウンキャストであるが、as4_fast_sot_flg[0]の値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_fast_sot_flg = (U1)st_g_bsm_loop_data.as4_fast_sot_flg[0];

	for (s4_t_lp_i=0; s4_t_lp_i<TARGET_BUFFSIZE; s4_t_lp_i++ ){
		/* ↓S4→S2のダウンキャストであるが、as4_Tx_int[][9]以外の変数の値域がS2の範囲に収まるため問題ない↓ */
		/* as4_Tx_int[][9]は値域がS2の範囲を超える可能性があるが、ラッチ先のast_g_bsm_target[]はNBD出力にしか使用されないため、ダウンキャストしても問題ない */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_up						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][0];			/* 上りﾋﾟｰｸbin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_up_music					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][1];			/* 上りﾋﾟｰｸ角度bin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_dn						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][2];			/* 下りﾋﾟｰｸbin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_dn_music					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][3];			/* 下りﾋﾟｰｸ角度bin */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_stop						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][8];			/* 停止物フラグ */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_track					= s2_data_grd((S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][9], CS2_S2MAX, CS2_S2MIN);			/* 履歴接続回数 */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_lost						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][10];		/* 外挿回数 */
		ast_g_bsm_target[s4_t_lp_i].s2_ID_num						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][11];		/* 物標ID (1～8) */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_new						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][12];		/* 新規物標フラグ */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_dc						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][14];		/* 物標種別（※※１） */
		ast_g_bsm_target[s4_t_lp_i].s2_ctr_sot_cut					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][15];		/* fast-Sotカット対象フラグ */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_reliable					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][16];		/* 物標確定フラグ */
		ast_g_bsm_target[s4_t_lp_i].s2_ctr_tos						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][17];		/* Tosらしさカウンタ */
		/* ↑S4→S2のダウンキャストであるが、 as4_Tx_int[][9]以外の値域がS2の範囲に収まるため問題ない↑ */
		/* as4_Tx_int[][9]は値域がS2の範囲を超える可能性があるが、ラッチ先のast_g_bsm_target[]はNBD出力にしか使用されないため、ダウンキャストしても問題ない */
		ast_g_bsm_target[s4_t_lp_i].fl_power_up_music				= pst_a_out_data->afl_Tx_float[s4_t_lp_i][0];		/* 上りﾋﾟｰｸ角度電力 */
		ast_g_bsm_target[s4_t_lp_i].fl_power_dn_music				= pst_a_out_data->afl_Tx_float[s4_t_lp_i][1];		/* 下りﾋﾟｰｸ角度電力 */
		ast_g_bsm_target[s4_t_lp_i].fl_theta_up						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][2];		/* 上りﾋﾟｰｸ方向 */
		ast_g_bsm_target[s4_t_lp_i].fl_theta_dn						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][3];		/* 下りﾋﾟｰｸ方向 */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxobs						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][5];		/* X方向距離観測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Ryobs						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][6];		/* Y方向距離観測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Ryfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][7];		/* Y方向距離出力値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][8];		/* X方向距離出力値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxpred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][9];		/* X方向距離予測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Rypred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][10];		/* Y方向距離予測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Vyfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][13];		/* Y方向速度出力値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Vxfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][14];		/* X方向速度出力値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Vxpred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][15];		/* X方向速度予測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Vypred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][16];		/* Y方向速度予測値 */
		ast_g_bsm_target[s4_t_lp_i].fl_Ayfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][17];		/* Y方向加速度 */
		ast_g_bsm_target[s4_t_lp_i].fl_Axfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][18];		/* X方向加速度 */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_up_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][31];		/* 上り方位bin[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_dn_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][32];		/* 下り方位bin[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_up_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][33];		/* 上り方位bin予測値[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_dn_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][34];		/* 下り方位bin予測値[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_up_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][35];		/* 上りﾋﾟｰｸbin[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_dn_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][36];		/* 下りﾋﾟｰｸbin[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_up_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][37];		/* 上りﾋﾟｰｸbin予測値[補間値] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_dn_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][38];		/* 下りﾋﾟｰｸbin予測値[補間値] */
	}

	for (s4_t_lp_i = (S4)0; s4_t_lp_i < (S4)6; s4_t_lp_i++) {
		afl_g_bsm_alarmed_target[s4_t_lp_i][0]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][0];				/* X方向距離 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][1]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][1];				/* Y方向距離 */
		
		/* ↓S4→U1のダウンキャストであるが、全ての変数の値域がU1の範囲に収まるため問題ない↓ */
		au1_g_bsm_alarmed_target[s4_t_lp_i][2]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][2];			/* ID */
		au1_g_bsm_alarmed_target[s4_t_lp_i][3]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][3];			/* 警報回数 */
		au1_g_bsm_alarmed_target[s4_t_lp_i][4]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][4];			/* 発生時の状態 */
		au1_g_bsm_alarmed_target[s4_t_lp_i][5]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][5];			/* 外挿回数 */
		/* ↑S4→U1のダウンキャストであるが、全ての変数の値域がU1の範囲に収まるため問題ない↑ */
		
		afl_g_bsm_alarmed_target[s4_t_lp_i][6]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][6];				/* 開始時の電力 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][7]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][7];				/* 開始時の電力との差分 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][8]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][8];				/* X方向速度 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][9]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][9];				/* Y方向速度 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][10]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][10];			/* 開始時のX方向距離 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][11]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][11];			/* 開始時のY方向距離 */
		afl_g_bsm_alarmed_target[s4_t_lp_i][12]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][12];			/* 開始時の警報ｴﾘｱ(Xmin) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][13]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][13];			/* 開始時の警報ｴﾘｱ(Xmax) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][14]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][14];			/* 開始時の警報ｴﾘｱ(Ymin) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][15]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][15];			/* 開始時の警報ｴﾘｱ(Ymax) */
	}

	/* S4→U1のダウンキャストであるが、as4_alarm_off_count[0]以外の変数の値域がU1の範囲に収まるため問題ない */
	/* as4_alarm_off_count[0]は値域がS2の範囲を超える可能性があるが、ラッチ先のs2_g_bsm_alarm_off_countはNBD出力にしか使用されないため、ダウンキャストしても問題ない */
	u1_g_bsm_alarm_flg			= (U1)st_g_bsm_loop_data.s4_flg_alarm;					/* 警報フラグ */
	s2_g_bsm_alarm_off_count	= s2_data_grd((S2)st_g_bsm_alarm_data.as4_alarm_off_count[0], CS2_S2MAX, CS2_S2MIN);		/* 警報延長回数 */
	u1_g_bsm_alarmed_num		= (U1)st_g_bsm_alarm_data.as4_alarmed_num[0];			/* 警報物標数 */
	u1_g_bsm_tos_end_flg		= (U1)st_g_bsm_loop_data.as4_flg_tos_end[0];			/* ToS終了フラグ */
	u1_g_bsm_tos_frontline_flag = (U1)st_g_bsm_loop_data.as4_flg_tos_frontline[0];		/* 車両後端フラグ */
	fl_g_bsm_tos_frontline_pow	= st_g_bsm_loop_data.afl_tos_frontline_pow[0];		/* 車両後端電力 */
	s1_g_bsm_ctr_heisou_car		= st_g_bsm_loop_data.s1_ctr_heisou_car;				/* 並走車存在カウンタ */
	u1_g_bsm_flg_heisou_car		= st_g_bsm_loop_data.u1_flg_heisou_car;				/* 並走車存在フラグ */

	return;
}

/********************************************************************************************/
/* 関数名		: fn_loop_data_initialize()													*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: st_g_bsm_loop_data初期化関数												*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_loop_data_initialize(BSM_LOOP_DATA *pst_a_loop_data){

	S4 s4_t_lp_i = 0;
	S4 s4_t_lp_j = 0;

	/***** INPUT *****/
	pst_a_loop_data->as4_flg_wall[0] = 0;
	pst_a_loop_data->afl_wall_width[0] = WALL_MAX;
	pst_a_loop_data->as4_flg_passing[0] = 0;
	pst_a_loop_data->as4_flg_leading[0] = 0;

	/***** FEEDBACK *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
		pst_a_loop_data->as4_buf_pair_num[s4_t_lp_i] = 0;
	}
	pst_a_loop_data->u1_truck_flg = (U1)0;
	fn_init(pst_a_loop_data->ast_normal, NORMAL_BUFFSIZE);
	fn_init(pst_a_loop_data->ast_target, TARGET_BUFFSIZE);


	/***** FEEDBACK (for wall estimation) *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 70; s4_t_lp_i++) {
		pst_a_loop_data->afl_Rx_right[s4_t_lp_i] = WALL_MAX;
	}

	pst_a_loop_data->fl_fm_obj_x_pre = CFL_UNKNOWN_VALUE;
	pst_a_loop_data->u1_flg_fm_obj_x_pre_enable = CU1_DF_OFF;
	pst_a_loop_data->u1_wall_flg_for_fa_judgement = (U1)0;
	pst_a_loop_data->u1_fm_object_stable_count = (U1)0;

	/***** FEEDBACK (for SoT) *****/
	fn_initialize_wall_data(pst_a_loop_data->ast_normal_wall);

	/***** FEEDBACK (for Slow-SoT) *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
		pst_a_loop_data->as4_slow_sot_find[s4_t_lp_i] = 0;
	}
	for (s4_t_lp_i = 0; s4_t_lp_i < 6; s4_t_lp_i++) {
		pst_a_loop_data->as4_slow_sot_doa_diff_sum[s4_t_lp_i] = 0;
	}

	pst_a_loop_data->u1_count_adjacent_lane_exist = (U1)0;

	pst_a_loop_data->s1_ctr_heisou_car = (S1)0;
	pst_a_loop_data->u1_flg_heisou_car = (U1)0;

	/***** FEEDBACK (for ToS End) *****/
	pst_a_loop_data->as4_flg_tos_frontline[0] = 0;
	pst_a_loop_data->afl_tos_frontline_pow[0] = 0.0F;		/* $$$ 2013.08.27-2 */
	pst_a_loop_data->as4_flg_sot_backwardline[0] = 0;		/* $$$ 2013.07.29 TEST */
	pst_a_loop_data->as4_flg_tos_end[0] = 0;				/* $$$ 2013.08.06 */
	pst_a_loop_data->as4_flg_sot_end[0] = 0;				/* $$$ 2013.08.08-4 */
	pst_a_loop_data->as4_low_speed_flg[0] = 1;
	pst_a_loop_data->as4_fast_sot_flg[0] = 0;

	pst_a_loop_data->s4_final_target_num = 0;

	/***** 警報判定 *****/
	pst_a_loop_data->s4_flg_alarm = 0;
	pst_a_loop_data->u1_reliable_jdg_mask_count = (U1)0;
	pst_a_loop_data->u1_shrink_on_count = (U1)0;
	pst_a_loop_data->u1_shrink_keep_count = (U1)0;
	pst_a_loop_data->u1_fa_delete_count = (U1)0;

	return;

}

/********************************************************************************************/
/* 関数名		: fn_loop_data_initialize_sensor()											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: fn_loop_data_initialize_sensor初期化関数									*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_loop_data_initialize_sensor(BSM_LOOP_DATA *pst_a_loop_data)
{
	pst_a_loop_data->afl_installed_angle[0] = FL_BSM_FLSH_AXIS_DEFAULT;
	pst_a_loop_data->afl_installed_angle[1] = (((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH/1000.0F) / 2.0F) - ((FL)U4_BSM_FLSH_DELTA_W / 1000.0F);
	pst_a_loop_data->afl_installed_angle[2] = (FL)U4_BSM_FLSH_DELTA_L / 1000.0F;

	return;
}

/********************************************************************************************/
/* 関数名		: fn_out_data_initialize()														*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: outdata初期化関数															*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_out_data_initialize(BSM_OUT_DATA *pst_a_out_data){

	S4 s4_t_lp_i = 0;
	S4 s4_t_lp_j = 0;
	S4 s4_t_lp_k = 0;

	/***** OUTPUT (SoT) *****/
	pst_a_out_data->as4_flg_sot[0] = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < 4; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 7; s4_t_lp_j++) {
			pst_a_out_data->afl_sot_target_info[s4_t_lp_j][s4_t_lp_i] = CFL_UNKNOWN_VALUE;
		}
	}

	/***** OUTPUT (CAN) *****/
	fn_initialize_Tx_data(
		pst_a_out_data->as4_Tx_int,
		pst_a_out_data->afl_Tx_float
	);

	/***** OUTPUT (OBJECT) *****/
	pst_a_out_data->s4_pair_num_prior = 0;
	fn_init(pst_a_out_data->ast_normal_prior, PRIOR_BUFFSIZE);

	pst_a_out_data->s4_pair_num_ordinary = 0;
	fn_init(pst_a_out_data->ast_normal_ordinary, ORDINARY_BUFFSIZE);
	
	pst_a_out_data->s4_pair_num_2f = 0;
	fn_init(pst_a_out_data->ast_normal_2f, AUX_BUFFSIZE);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
	pst_a_out_data->s4_pair_num_trailer = 0;
	fn_init(pst_a_out_data->ast_normal_trailer, TRAILER_BUFFSIZE);
#endif

	return;

}

/********************************************************************************************/
/* 関数名		: fn_bsm_can_data_init()													*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: BSM/LCAが作成するCANデータの初期化										*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: なし																		*/
/*																							*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  : 																				*/
/* <output>	: st_g_tx_noise_chk_fsk_bsm														*/
/* 			: st_g_tx_noise_chk_fm_bsm 														*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_bsm_can_data_init(VD)
{
	/* CANラッチデータを初期化 */
	st_g_tx_noise_chk_fsk_bsm.u1_peak_num	= 0;
	st_g_tx_noise_chk_fsk_bsm.u2_thres1		= 0;
	st_g_tx_noise_chk_fsk_bsm.u2_thres2		= 0;

	st_g_tx_noise_chk_fm_bsm.u1_peak_num_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u1_peak_num_dn	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres1_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres1_dn	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres2_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres2_dn	= 0;

	return;
}



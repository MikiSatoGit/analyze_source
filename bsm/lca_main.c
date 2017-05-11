
/****************************************************************************/
/* ファイル名	: lca_main.c												*/
/*--------------------------------------------------------------------------*/
/* モジュール名	: 															*/
/*--------------------------------------------------------------------------*/
/* 機能			: 															*/
/*--------------------------------------------------------------------------*/
/* 備考			:															*/
/*--------------------------------------------------------------------------*/
/* 構成関数		: 															*/
/* 				: 															*/
/*--------------------------------------------------------------------------*/
/* 変更履歴		:															*/
/* Version				date				name							*/
/*	t01					14.02.17			走安技1 1技室 H.Nonogaki		*/
/*	新規作成																*/
/*	t03					14.04.02			走安技1 1技室 H.Nonogaki		*/
/*	ファイル名称の変更														*/
/*	算術ヘッダの変更														*/
/*	統合シミュレータ環境の対応												*/
/*	デバッグ用引数・変数の削除												*/
/*	引継ぎデータの初期値見直し												*/
/*	t04					14.04.09			走安技1 1技室 H.Nonogaki		*/
/*	STEP2対応																*/
/*	t05					14.05.06			走安技1 1技室 Y.Yamada			*/
/*	BSM認識処理のSTEP2対応													*/
/*	t06					14.10.15			走安技1 1技室 H.Nonogaki		*/
/*	LCAリファクタリング														*/
/*	t07					14.10.21			走安技1 1技室 H.Nonogaki		*/
/*	警報制御のための警報フラグをグローバルRAM化								*/
/*	t09					16.08.02			走安技2 1技室 Y.Nishioka		*/
/*	310B向けに新規作成														*/
/*	t10					16.08.03			走安技2 1技室 Y.Nishioka		*/
/*	設計DR指摘事項対応　OBJ変更なし											*/
/*	t11					16.08.29			走安技2 1技室 Y.Nishioka		*/
/*	310B 残課題1422対応　グローバル変数の初期化追加							*/
/*	t12					16.10.05			走安技2 1技室 Y.Nishioka		*/
/*	310B LCA構造変更に伴い、ヘッダ読み込み変更								*/
/*	t13					16.12.05			走安技2 1技室 M.Tanaka			*/
/*	仕様確認No.2897 不要グローバル変数を削除								*/
/*	t14					16.12.07			走安技2 1技室 Y.Nishioka		*/
/*	310B 残課題1475 電力閾値修正											*/
/*	tos35				16.12.27			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　形式の修正　※OBJ変更無し					*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-ABST-002B						*/
/*	tos36				16.12.27			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　形式の修正　※OBJ変更あり					*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-ABST-002B	No.23				*/
/*	tos39				17.01.06			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　QAシート No.39の対応						*/
/*	tos55				17.01.12			東芝DME M.Nakamura				*/
/*	不具合の修正(デンソー様修正コードのマージ)								*/
/*	tos56				17.01.13			東芝DME M.Nakamura				*/
/*	形式の修正（Grepによる総点検）											*/
/*	t15					17.01.19			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿 コードレビュー全指摘事項の修正									*/
/*	tos59				17.01.19			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　修正漏れ対応　形式の修正　※OBJ変更無し	*/
/*	t16					17.01.22			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿 検収指摘事項の修正												*/
/*	t17					17.01.22			走安技2 1技室 Y.Nishioka		*/
/*	コメントの修正　※OBJ変更なし											*/
/*	t18					17.01.30			走安技2 1技室 Y.Nishioka		*/
/*	310B_原図試作向け_サンプルコードマージ									*/
/*	t19					17.02.03			先安技2 1技室 Y.Nishioka		*/
/*	310B_原図試作時_ソフトGr指摘による仕様書の修正を反映					*/
/*	t20					17.02.08			先安技2 1技室 Y.Nishioka		*/
/*	机上セルフ指摘事項対応(310B_t081⇒t083)									*/
/*	t21					17.02.17			先安技2 1技室 Y.Yamada			*/
/*	LDA連携判定ロジック追加													*/
/*	t23					17.03.03			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿原図試作向け修正内容をマージ ※OBJ変更なし						*/
/****************************************************************************/

/****************************************************************************/
/*							ヘッダインクルード								*/
/****************************************************************************/
/***** 共通ヘッダ *****/
#include "../../../app/type.h"
#include "../../../app/config/config_sns.h"

/***** マクロ定義ヘッダ *****/
#include "lca_parameter_def.h"

/***** 構造体定義ヘッダ *****/
#include "lca_normal_def.h"

/***** 定数定義ヘッダ *****/

/***** 参照関数ヘッダ *****/
#include "lca_main.h"		/* 外部公開用のAPIを内部で使用している暫定処置 */
#include "lca_core.h"
#include "target/lca_map_01.h"
#include "target/lca_init_cvw.h"
#include "target/lca_recog_01_03_07_08.h"
#include "target/lca_recog_03_04_05_06_10.h"
#include "app_alart/lca_alarm_01.h"

/***** マクロ関数定義ヘッダ *****/

/***** 外部参照ヘッダ *****/
#include "../../common/defcom_mwr.h"
#include "../bsm/bsm_main.h"		/* ヘッダファイル要見直し */
#include "../../../app/config/inc_config.h"


/****************************************************************************/
/*								マクロ定義									*/
/****************************************************************************/

/****************************************************************************/
/*								定数定義									*/
/****************************************************************************/

/****************************************************************************/
/*							スタティック変数宣言							*/
/****************************************************************************/

/****************************************************************************/
/*								スタティック関数							*/
/****************************************************************************/
/* ======================================================================== */
/* 	外部公開API 															*/
/* ======================================================================== */

/****************************************************************************/
/* 関数名	: fn_lca_main													*/
/*--------------------------------------------------------------------------*/
/* 機能		: 																*/
/*--------------------------------------------------------------------------*/
/* 引数		: なし															*/
/* 戻り値	: なし															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* [in]  	: なし															*/
/* [out] 	: なし															*/
/*--------------------------------------------------------------------------*/
/* 仕様書	: 																*/
/****************************************************************************/
VD fn_lca_main(VD)
{
	fn_lca_core_main();

	return;
}

/****************************************************************************/
/* 関数名	: fn_lca_cmn_initialize_loop_data								*/
/*--------------------------------------------------------------------------*/
/* 機能		: グローバル変数宣言＆初期化									*/
/*--------------------------------------------------------------------------*/
/* 引数		: なし															*/
/* 戻り値	: なし															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* [in]  	: なし															*/
/* [out] 	: st_g_lca_ecu_loop_data							: 次サイクルに持ち越すLCA/FHLループデータ	*/
/* [out] 	: afl_g_lca_ecu_lfm_up_side_dft_pow[]				: 自車真横DFTスペクトル(UP)	*/
/* [out] 	: afl_g_lca_ecu_lfm_dn_side_dft_pow[]				: 自車真横DFTスペクトル(DN)	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_zero_point_error			: ヨーレート零点異常*/
/* [out] 	: s2_g_lca_ecu_yaw_rate_1_zero_point				: ヨーレート1零点値		*/
/* [out] 	: s2_g_lca_ecu_yaw_rate_2_zero_point				: ヨーレート2零点値		*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_zero_point_update_info		: ヨーレート零点更新情報	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_sensor_1_validation			: ヨーレートセンサ１無効/有効	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_sensor_2_validation			: ヨーレートセンサ１無効/有効	*/
/* [out] 	: u1_g_lca_ecu_sensor_pow_supply_voltage_validation	: 次センサ電源電圧(IG) 無効/有効	*/
/* [out] 	: u2_g_lca_ecu_yaw_rate_sensor_signal				: ヨーレートセンサ信号	*/
/* [out] 	: u1_g_lca_ecu_yaw_diff_value						: ヨーレート差分値		*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_id							: ヨーレートセンサ識別値*/
/* [out] 	: s2_g_lca_ecu_curv_r								: LCA 用カーブR						*/
/* [out] 	: fl_g_lca_ecu_2f_ave_standard_pow					: 2FCW FFT スペクトルのベース閾値	*/
/* [out] 	: afl_g_lca_ecu_2f_thre								: 2FCW FFT スペクトルの変動閾値		*/
/* [out] 	: fl_g_lca_ecu_noise_floor_fm						: FMCW FFT スペクトルの変動閾値	*/
/* [out] 	: afl_g_lca_ecu_2f_rear_dft_ryy_matrix				: 2FCW 後方DFT の距離相関行列	*/
/* [out] 	: u1_g_lca_ecu_2f_peak_num							: 2FCW 後方DFT スペクトルのピーク数	*/
/* [out] 	: au2_g_lca_ecu_2f_peak_bin							: 2FCW 後方DFT スペクトルのピーク周波数ビン	*/
/* [out] 	: afl_g_lca_ecu_2f_peak_pow							: 2FCW 後方DFT スペクトルのピーク電力	*/
/* [out] 	: afl_g_lca_ecu_2f_rear_dft_pow						: 2FCW 後方DFT スペクトル		*/
/* [out] 	: afl_g_lca_ecu_up_rear_dft_pow						: FMCW(up)後方DFTスペクトル		*/
/* [out] 	: afl_g_lca_ecu_2f_peak_pow							: LCA 警報開始TTC設定値			*/
/*--------------------------------------------------------------------------*/
/* 仕様書	: MWR-RECO-24G-LCA-ABST-002B							 		*/
/*			: 9.1 グローバル変数宣言＆初期化<fn_lca_cmn_initialize_loop_data()>	*/
/****************************************************************************/
VD fn_lca_cmn_initialize_loop_data(VD)
{
	S4	s4_t_i;
	S4	s4_t_m;
	S4	s4_t_k;


	/*****************************************/
	/***** ここからがLCA_LOOP_DATA構造体 *****/
	/*****************************************/

	/***** LCA警報結果 *****/
	st_g_lca_ecu_loop_data.u1_alm_flg	 = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_hazard_flg = CU1_DF_OFF;

	/***** カーブR算出用変数 *****/
	for (s4_t_i = (S4)0; s4_t_i < (S4)CS1_LCA_MAP_CURVR_BUFF; s4_t_i++) {
		st_g_lca_ecu_loop_data.s4_yaw_curv_r_archives[s4_t_i] = CS4_LCA_MAP_CURVR_MAX;
	}

	/***** 前サイクルから持越す軌跡マップ推定変数 *****/
	st_g_lca_ecu_loop_data.u1_decimation_ctr = (U1)0;
	st_g_lca_ecu_loop_data.fl_sum_speed_during_decimation = (FL)0;

	for (s4_t_i = (S4)0; s4_t_i < (S4)2; s4_t_i++) {
		for (s4_t_m = (S4)0; s4_t_m < (S4)CU1_LCA_CMN_APPROXIMATE_BOX; s4_t_m++) {
			st_g_lca_ecu_loop_data.afl_x_out[s4_t_i][s4_t_m]  = (FL)0;
			st_g_lca_ecu_loop_data.afl_ne_out[s4_t_i][s4_t_m] = (FL)0;
			st_g_lca_ecu_loop_data.afl_road_edge_archives_for_fhl[s4_t_i][s4_t_m] = (FL)0;
		}
		for (s4_t_m = (S4)0; s4_t_m < (S4)2; s4_t_m++) {
			for (s4_t_k = (S4)0; s4_t_k < (S4)CU1_LCA_CMN_APPROXIMATE_BOX; s4_t_k++) {
				st_g_lca_ecu_loop_data.afl_P_out[s4_t_i][s4_t_m][s4_t_k]			  = (FL)0;
				st_g_lca_ecu_loop_data.afl_road_edge_archives[s4_t_i][s4_t_m][s4_t_k] = (FL)0;
				st_g_lca_ecu_loop_data.afl_x997[s4_t_i][s4_t_m][s4_t_k]				  = (FL)0;
				st_g_lca_ecu_loop_data.afl_x955[s4_t_i][s4_t_m][s4_t_k]				  = (FL)0;
				st_g_lca_ecu_loop_data.afl_x683[s4_t_i][s4_t_m][s4_t_k]				  = (FL)0;
				st_g_lca_ecu_loop_data.afl_x380[s4_t_i][s4_t_m][s4_t_k]				  = (FL)0;
			}
		}
	}

	for (s4_t_i = (S4)0; s4_t_i < (S4)CU1_LCA_CMN_APPROXIMATE_BOX; s4_t_i++) {
		st_g_lca_ecu_loop_data.afl_kyori_archives[s4_t_i] = (FL)0;
		st_g_lca_ecu_loop_data.afl_wall_archives[s4_t_i]  = (FL)0;
	}

	/***** 前サイクルから持越す物標データ *****/
	st_g_lca_ecu_loop_data.u1_nml_pre_num = (U1)0;
	st_g_lca_ecu_loop_data.u1_tgt_pre_num = (U1)0;
	fn_lca_cmn_init(
		st_g_lca_ecu_loop_data.ast_nml_pre,
		CU1_LCA_CMN_NORMAL_BUFFSIZE
	);
	fn_lca_cmn_init(
		st_g_lca_ecu_loop_data.ast_tgt_pre,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);

	/***** 前サイクルから持越すその他のデータ *****/
	st_g_lca_ecu_loop_data.u1_up_useless_flg = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_dn_useless_flg = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_2f_useless_flg = CU1_DF_OFF;

	/***** DFTによる壁検出データ *****/
	st_g_lca_ecu_loop_data.fl_wall_dist				 = CFL_LCA_WALL_WALL_MAX_DIST_X;
	st_g_lca_ecu_loop_data.u1_cal_wall_flg			 = CU1_DF_ON;
	st_g_lca_ecu_loop_data.u1_cal_wall_ctr			 = CU1_LCA_CMN_ZERO_VALUE;
	st_g_lca_ecu_loop_data.u1_past_wall_ext_ctr		 = CU1_LCA_CMN_ZERO_VALUE;
	st_g_lca_ecu_loop_data.u1_use_prev_wall_dist_ctr = CU1_LCA_CMN_ZERO_VALUE;

	/*****************************************/
	/***** ここまでがLCA_LOOP_DATA構造体 *****/
	/*****************************************/


	/* 自車真横DFTスペクトル */
	for (s4_t_i = (S4)0; s4_t_i < (S4)CU2_LCA_WALL_PEAK_SEARCH_DFT_BIN_NUM; s4_t_i++) {
		afl_g_lca_ecu_lfm_up_side_dft_pow[s4_t_i] = (FL)0;
		afl_g_lca_ecu_lfm_dn_side_dft_pow[s4_t_i] = (FL)0;
	}
	
	/* ヨーレート */
	u1_g_lca_ecu_yaw_rate_id							= (U1)0;
	u1_g_lca_ecu_yaw_rate_zero_point_error				= (U1)0;
	s2_g_lca_ecu_yaw_rate_1_zero_point					= (S2)0;
	s2_g_lca_ecu_yaw_rate_2_zero_point					= (S2)0;
	u1_g_lca_ecu_yaw_rate_zero_point_update_info		= (U1)0;
	u1_g_lca_ecu_yaw_rate_sensor_1_validation			= (U1)0;
	u1_g_lca_ecu_yaw_rate_sensor_2_validation			= (U1)0;
	u1_g_lca_ecu_sensor_pow_supply_voltage_validation	= (U1)0;
	u2_g_lca_ecu_yaw_rate_sensor_signal					= (U2)0;
	u1_g_lca_ecu_yaw_diff_value							= (U1)0;

	/* LCA用カーブR */
	s2_g_lca_ecu_curv_r = (S2)0;
	
	/* 2FCW */
	fl_g_2f_noise_floor_for_lca = (FL)0;
	fl_g_lca_ecu_2f_ave_standard_pow = (FL)0;
	u1_g_lca_ecu_2f_peak_num = (U1)0;
	for (s4_t_i = (S4)0; s4_t_i < (S4)CU2_PCS_FCW_FFT_DATA; s4_t_i++) {
		afl_g_lca_ecu_2f_thre[s4_t_i]			= (FL)0;
		afl_g_lca_ecu_2f_rear_dft_pow[s4_t_i]	= (FL)0;
	}
	for (s4_t_i = (S4)0; s4_t_i < (S4)CU1_LCA_CMN_FSK_PEAK_BUFFSIZE; s4_t_i++) {
		au2_g_lca_ecu_2f_peak_bin[s4_t_i]		= (U2)0;
		afl_g_lca_ecu_2f_peak_pow[s4_t_i]		= (FL)0;
	}
	for (s4_t_i = (S4)0; s4_t_i < (S4)(CU2_PCS_FCW_FFT_DATA / (U2)2); s4_t_i++) {
		for (s4_t_m = (S4)0; s4_t_m < (S4)CU2_PCS_FCW_RYY_MATRIX_2F; s4_t_m++) {
			afl_g_lca_ecu_2f_rear_dft_ryy_matrix[s4_t_i][s4_t_m] = (FL)0;
		}
	}

	/* FMCW */
	fl_g_lca_ecu_fm_noise_floor = (FL)0;
	fl_g_lca_ecu_noise_floor_fm = (FL)0;
	for (s4_t_i = (S4)0; s4_t_i < (S4)CU2_PCS_LFM_FFT_DATA; s4_t_i++) {
		afl_g_lca_ecu_up_rear_dft_pow[s4_t_i] = (FL)0;
	}
	
	/* 環境認識 */
	for (s4_t_i = (S4)0; s4_t_i < (S4)3; s4_t_i++) {
		au1_g_lca_ecu_env_recog_peak_num[s4_t_i] = (U1)0;		/* 0:up 1:dn 2:2f */
		afl_g_lca_ecu_env_recog_ave_pow[s4_t_i]  = (FL)0;		/* 0:up 1:dn 2:2f */
	}
	
	/* LCA警報開始TTC設定値 */
	fl_g_lca_ecu_ttc_thre = (FL)5;
	
	return;
}

/* ======================================================================== */
/* 	内部公開API 															*/
/* ======================================================================== */

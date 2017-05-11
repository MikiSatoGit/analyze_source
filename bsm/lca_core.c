
/****************************************************************************/
/* ファイル名	: lca_core.c												*/
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
/*	t02					14.04.02			走安技1 1技室 H.Nonogaki		*/
/*	ファイル名称の変更														*/
/*	算術ヘッダの変更														*/
/*	統合シミュレータ環境の対応												*/
/*	デバッグ用引数の削除													*/
/*	t03					14.04.09			走安技1 1技室 H.Nonogaki		*/
/*	STEP2対応																*/
/*	t04					14.05.06			走安技1 1技室 Y.Yamada			*/
/*	BSM認識処理のSTEP2対応													*/
/*	t05					14.10.15			走安技1 1技室 H.Nonogaki		*/
/*	LCAリファクタリング														*/
/*	t06					14.10.21			走安技1 1技室 H.Nonogaki		*/
/*	警報制御のための警報フラグをグローバルRAM化								*/
/*	t07 				14.10.30			走安技1 1技室 K.Kato			*/
/*	AUDR BSM認識データラッチ構造体追加に伴うヘッダインクルード追加			*/
/*	t08					14.11.11			走安技1 1技室 H.Nonogaki		*/
/*	左右の定義をdefine値を使用するよう変更※obj変更なし						*/
/*	t11					16.08.02			走安技2 1技室 Y.Nishioka		*/
/*	310B向けに新規作成														*/
/*	t12					16.08.03			走安技2 1技室 Y.Nishioka		*/
/*	設計DR指摘事項対応　OBJ変更なし											*/
/*	t13					16.08.07			走安技2 1技室 Y.Nishioka		*/
/*	AUDRの１次ラッチ変数削除												*/
/*	t14					16.08.08			走安技2 1技室 Y.Nishioka		*/
/*	ドライバーによるTTCカスタマイズ設定 を作成								*/
/*	t15					16.08.22			走安技2 1技室 Y.Nishioka		*/
/*	Normal物標、Target物標をSIM_MODEにおいても有効化 ※ＯＢＪ変更なし		*/
/*	t16					16.08.29			走安技2 1技室 Y.Nishioka		*/
/*	310B 残課題1420対応　AUDR修正											*/
/*	t17					16.08.31			走安技2 1技室 Y.Nishioka		*/
/*	310B LCA_TTC カスタマイズスイッチ修正									*/
/*	t18					16.10.05			走安技2 1技室 Y.Nishioka		*/
/*	310B LCA構造変更に伴い、ヘッダ読み込み変更								*/
/*	t19					16.10.06			走安技2 1技室 Y.Nishioka		*/
/*	仕様確認No.2776, 2777対応 ※OBJ変更なし									*/
/*	tos26				16.12.27			東芝DME T.Azuma					*/
/*	東芝コードレビュー指摘の反映　設計検討の修正							*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-RECOG-10-003 No.1				*/
/*	tos27				16.12.27			東芝DME M.Ejiri					*/
/*	東芝コードレビュー指摘の反映　形式の修正　（※OBJ変更あり）				*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-RECOG-15-001A					*/
/*	tos34				16.12.27			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　設計検討の修正							*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-ABST-002B	No.57-65			*/
/*	tos35				16.12.27			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　形式の修正　※OBJ変更無し					*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-ABST-002B No.1-11, 13-19		*/
/*	tos51				17.01.10			東芝DME T.Azuma					*/
/*	東芝コードレビュー指摘の反映　形式の修正　※OBJ変更無し					*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-RECOG-02-002					*/
/*	tos53				17.01.12			東芝DME Y.Sekine				*/
/*	東芝コードレビュー指摘の反映　形式の修正　※OBJ変更あり					*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-RECOG-09-003A					*/
/*	tos56				17.01.13			東芝DME M.Nakamura				*/
/*	形式の修正（Grepによる総点検）											*/
/*	t22					17.01.19			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿 コードレビュー全指摘事項の修正									*/
/*	tos59				17.01.19			東芝DME M.Nakamura				*/
/*	東芝コードレビュー指摘の反映　修正漏れ対応								*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-ABST-002B No.1-10				*/
/*	tos61				17.01.19			東芝DME S.Fukuda				*/
/*	東芝コードレビュー指摘の反映　修正漏れ対応								*/
/*	トレーサビリィティシート_MWR-RECO-24G-LCA-RECOG-15-001A No.3,4			*/
/*	t23					17.01.22			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿 検収指摘事項の修正												*/
/*	t24					17.01.22			走安技2 1技室 Y.Nishioka		*/
/*	コメントの修正　※OBJ変更なし											*/
/*	t25					17.01.23			走安技2 1技室 Y.Nishioka		*/
/*	演算時間格納用変数の配置見直し ※OBJ変更なし							*/
/*	t26					17.01.23			走安技2 1技室 Y.Nishioka		*/
/*	LCA NBDラッチ用変数を修正												*/
/*	t27					17.01.30			走安技2 1技室 Y.Nishioka		*/
/*	310B_原図試作向け_サンプルコードマージ									*/
/*	t28					17.02.03			先安技2 1技室 Y.Nishioka		*/
/*	MWR-RECO-24G-LCA-ABST-004（Δ4）対応									*/
/*	t29					17.02.08			先安技2 1技室 Y.Nishioka		*/
/*	机上セルフ指摘事項対応(310B_t081⇒t083)									*/
/*	t30					17.02.17			先安技2 1技室 Y.Yamada			*/
/*	LDA連携判定ロジック追加													*/
/*	t32					17.03.03			走安技2 1技室 Y.Nishioka		*/
/*	東芝殿原図試作向け修正内容をマージ　※OBJ変更なし						*/
/*	t33					17.03.10			走安技2 1技室 Y.Nishioka		*/
/*	外側車線オフセット対応													*/
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
#include "lca_core.h"
#include "target/lca_init_cvw.h"
#include "target/lca_map_01.h"
#include "target/lca_recog_01_03_07_08.h"
#include "target/lca_recog_09.h"
#include "target/lca_recog_03_04_05_06_10.h"
#include "target/lca_recog_17.h"
#include "target/lca_connect_01.h"
#include "target/lca_loop_01.h"
#include "app_alart/lca_alarm_01.h"

/***** マクロ関数定義ヘッダ *****/

/***** 外部参照ヘッダ *****/
#include "../../common/defcom_mwr.h"
#include "../../common/distance_ram_nbd_bsm.h"	/* NBDの認識データ用構造体 */
#include "../../common/distance_ram_mwr.h"
#include "../../system/system_mwr.h"			/* LCA TTC カスタマイズスイッチの定数参照 */
#include "../../system/vehicle_spec_mwr.h"		/* 外側車線オフセット量の仕向け切替用 */
#include "../../../app/config/inc_config.h"

/****************************************************************************/
/*								マクロ定義									*/
/****************************************************************************/
VD fn_lca_abst_read_data_by_bsmdest(VD);

/****************************************************************************/
/*								定数定義									*/
/****************************************************************************/

/****************************************************************************/
/*							スタティック変数宣言							*/
/****************************************************************************/
LCA_LOOP_DATA	st_g_lca_ecu_loop_data;			/* 基本データ */
S2	s2_g_lca_ecu_curv_r;						/* LCA用カーブR */

/* 外側車線オフセット量 */
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA;


#if (SIM_VI_OUTPUT==LCA_VI_ON)	/* For Labview */
//NORMAL物標
U1 u1_g_lca_sim_nml_pre_num;													// 前サイクルのNORMAL物標数
U1 u1_g_lca_sim_nml_crn_num;													// 今サイクルのNORMAL物標数
U1 u1_g_lca_sim_nml_crn_num2;													// 今サイクルのNORMAL物標数(履歴接続後)
U1 u1_g_lca_sim_tgt_pre_num;													// 前サイクルのTARGET物標数
U1 u1_g_lca_sim_tgt_crn_num;													// 今サイクルのTARGET物標数(クラスタリング前)
U1 u1_g_lca_sim_tgt_crn_num2;													// 今サイクルのTARGET物標数(クラスタリング後)
U1 u1_g_lca_sim_tgt_crn_num3;													// 今サイクルのTARGET物標数(警報対象)
NORMAL_LCA ast_g_lca_sim_nml_pre[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// 前サイクルのNORMAL物標構造体
NORMAL_LCA ast_g_lca_sim_nml_crn[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// 今サイクルのNORMAL物標構造体
NORMAL_LCA ast_g_lca_sim_nml_crn2[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// 今サイクルのNORMAL物標構造体(履歴接続後)
NORMAL_LCA ast_g_lca_sim_tgt_pre[CU1_LCA_CMN_TGT_BUFFSIZE];						// 前サイクルのTARGET物標構造体
NORMAL_LCA ast_g_lca_sim_tgt_crn[CU1_LCA_CMN_TGT_BUFFSIZE];						// 今サイクルのTARGET物標構造体(クラスタリング前)
NORMAL_LCA ast_g_lca_sim_tgt_crn2[CU1_LCA_CMN_TGT_BUFFSIZE];					// 今サイクルのTARGET物標構造体(クラスタリング後)
NORMAL_LCA ast_g_lca_sim_tgt_crn3[CU1_LCA_CMN_TGT_BUFFSIZE];					// 今サイクルのTARGET物標構造体(警報対象)
#endif




/****************************************************************************/
/*								スタティック関数							*/
/****************************************************************************/

/* ======================================================================== */
/* 	外部公開API 															*/
/* ======================================================================== */

/****************************************************************************/
/* 関数名	: fn_lca_core_main												*/
/*--------------------------------------------------------------------------*/
/* 機能		: LCA/FHL認識処理												*/
/*--------------------------------------------------------------------------*/
/* 引数		: なし															*/
/* 戻り値	: なし															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* [in]  	: st_g_bsm_loop_data.afl_installed_angle[0]	:					*/
/* [out] 	: st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg	: 軸学習角度(BSMと常に同じ)	*/
/* [in]  	: fl_g_lca_ecu_ttc_thre	: LCA 警報開始TTC設定値					*/
/*--------------------------------------------------------------------------*/
/* 仕様書	: MWR-RECO-24G-LCA-ABST-005								 		*/
/*			: 4 LCA/FHL認識処理概要											*/
/****************************************************************************/
VD fn_lca_core_main(VD)
{
	/****************************/
	/***** ローカル変数宣言 *****/
	/****************************/
	U1 u1_t_i;
	U2 u2_t_i;

	/* 2FCW物標 */
	U1 u1_t_peak_music_num_2f;																	/* 2FCW freq-doaマップ上の総抽出ピーク数 */
	U1 au1_t_used_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];										/* 2FCW freq-doaマップ上のピークの使用済フラグ */
	FL afl_t_music_doa_pow_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
	FL afl_t_music_bin_intpl_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
	FL afl_t_music_doa_bin_intpl_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];							/* 2FCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
	U1 au1_t_2f_dft_peak_flg[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doaマップ上のピークがDFTにより発見したピークであることのフラグ */
	U1 au1_t_2f_sharp_dftpeak_flg[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];							/* 2FCW freq-doaマップ上のピークが鋭いことのフラグ */
	/* 通常物標 */
	U1 u1_t_peak_music_num_up;																	/* FMCW freq-doaマップ上の総抽出ピーク数 */
	FL afl_t_music_doa_pow_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
	FL afl_t_music_bin_intpl_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
	FL afl_t_music_doa_bin_intpl_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];							/* FMCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
	U1 au1_t_used_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];										/* FMCW(up) freq-doaマップ上のピークの使用済フラグ */
	U1 u1_t_peak_music_num_dn;																	/* FMCW freq-doaマップ上の総抽出ピーク数 */
	FL afl_t_music_doa_pow_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
	FL afl_t_music_bin_intpl_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
	FL afl_t_music_doa_bin_intpl_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];							/* FMCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
	U1 au1_t_used_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];										/* FMCW(dn) freq-doaマップ上のピークの使用済フラグ */
	/* NORMAL物標 */
	U1 u1_t_nml_crn_num;																		/* 今サイクルのNORMAL物標数 */
	NORMAL_LCA ast_t_nml_crn[CU1_LCA_CMN_NORMAL_BUFFSIZE];										/* 今サイクルのNORMAL物標構造体 */
	/* TARGET物標 */
	U1 u1_t_tgt_crn_num;																		/* 今サイクルのTARGET物標数 */
	NORMAL_LCA ast_t_tgt_crn[CU1_LCA_CMN_TGT_BUFFSIZE];											/* 今サイクルのTARGET物標構造体 */
	/* 警報判定 */
	U1 u1_t_alm_flg;
	U1 u1_t_hazard_flg;

	/******************************/
	/***** ローカル変数初期化 *****/
	/******************************/
	/* 2FCW物標 */
	u1_t_peak_music_num_2f = (U1)0;
	for (u1_t_i = (U1)0; u1_t_i < CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE; u1_t_i++) {
		au1_t_used_2f[u1_t_i] 					= (U1)0;
		afl_t_music_doa_pow_2f	[u1_t_i]		= (FL)0;
		afl_t_music_bin_intpl_2f	[u1_t_i]	= (FL)0;
		afl_t_music_doa_bin_intpl_2f[u1_t_i]	= (FL)0;
		au1_t_2f_dft_peak_flg		[u1_t_i]	= CU1_DF_OFF;
		au1_t_2f_sharp_dftpeak_flg	[u1_t_i]	= CU1_DF_OFF;
	}
	/* 通常物標 */
	u1_t_peak_music_num_up = (U1)0;
	u1_t_peak_music_num_dn = (U1)0;
	for (u1_t_i = (U1)0; u1_t_i < CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE; u1_t_i++) {
		afl_t_music_doa_pow_up[u1_t_i]			= (FL)0;
		afl_t_music_doa_pow_dn[u1_t_i]			= (FL)0;
		afl_t_music_bin_intpl_up[u1_t_i]		= (FL)0;
		afl_t_music_bin_intpl_dn[u1_t_i]		= (FL)0;
		afl_t_music_doa_bin_intpl_up[u1_t_i]	= (FL)0;
		afl_t_music_doa_bin_intpl_dn[u1_t_i]	= (FL)0;
		au1_t_used_up[u1_t_i]					= CU1_DF_OFF;
		au1_t_used_dn[u1_t_i]					= CU1_DF_OFF;
	}
	/* NORMAL物標 */
	u1_t_nml_crn_num = (U1)0;
	/* TARGET物標 */
	u1_t_tgt_crn_num = (U1)0;
	/* 警報判定 */
	u1_t_alm_flg	= CU1_DF_OFF;
	u1_t_hazard_flg = CU1_DF_OFF;

#ifdef _LCA_AUDR_INPUT	/* LCA演算時間確認用のAUDR出力変数 */
	u1_g_lca_ecu_2f_peak_num_nbd_tmp	= (U1)0;				/* LCA_2周波物標後方DFTピーク数 */
	u1_g_lca_tgt_pre_num_nbd_tmp		= (U1)0;				/* LCA_優先物標探索回数 */
	u1_g_lca_music_ctr_2f_nbd_tmp		= (U1)0;				/* LCAで新規に行った2F_MUSIC回数 */
	for (u1_t_i = (U1)0; u1_t_i < (U1)2; u1_t_i++){
		u1_g_lca_music_ctr_fm_nbd_tmp[u1_t_i]		= (U1)0;	/* LCAで新規に行ったFM_MUSIC回数 */
		u1_g_lca_share_peak_num_fm_nbd_tmp[u1_t_i]	= (U1)0;	/* FM_BSMとの共有ピーク数 */
	}
	u1_g_lca_share_peak_num_2f_nbd_tmp			= (U1)0;		/* 2F_BSMとの共有ピーク数 */
	u2_g_lca_make_pair_ctr_up_dn_nbd_tmp		= (U2)0;		/* 通常up/dnのペアマッチ回数 */
	u2_g_lca_make_pair_ctr_up_dn_2f_nbd_tmp		= (U2)0;		/* 通常up/dn/2fのペアマッチ回数 */
	u2_g_lca_make_pair_up_single_ctr_nbd_tmp	= (U2)0;		/* 通常up/2fのペアマッチ回数 */
	u2_g_lca_make_pair_dn_single_ctr_nbd_tmp	= (U2)0;		/* 通常dn/2fのペアマッチ回数 */
	u2_g_lca_nml_trk_ctr_nbd_tmp				= (U2)0;		/* 通常トラッキングのループ回数 */
	u2_g_lca_tgt_trk_ctr_nbd_tmp				= (U2)0;		/* targetトラッキングのループ回数 */
#endif

	/**************************************/
	/***** ローカル変数初期化(構造体) *****/
	/**************************************/
	/* NORMAL物標 */
	fn_lca_cmn_init(
		ast_t_nml_crn,
		CU1_LCA_CMN_NORMAL_BUFFSIZE
	);
	/* TARGET物標 */
	fn_lca_cmn_init(
		ast_t_tgt_crn,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);

	#if (SIM_VI_OUTPUT==LCA_VI_ON)	/* For Labview */
	// 前サイクルのTARGET物標
	fn_lca_cmn_init(
		ast_g_lca_sim_tgt_pre,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);
	u1_g_lca_sim_tgt_pre_num = st_g_lca_ecu_loop_data.u1_tgt_pre_num;
	fn_lca_cmn_nml_output(
		ast_g_lca_sim_tgt_pre,					/* TARGET物標情報のコピー先 */
		st_g_lca_ecu_loop_data.ast_tgt_pre,		/* TARGET物標情報のコピー元 */
		(U2)CU1_LCA_CMN_TGT_BUFFSIZE			/* TARGET物標情報のコピー数 */
	);
	for (u2_t_i = (U2)0; u2_t_i < CU2_PCS_LFM_FFT_DATA; u2_t_i++){
		afl_g_lca_sim_up_rear_dft_thre[u2_t_i] = (FL)0;
	}
	for (u2_t_i = (U2)0; u2_t_i < CU2_PCS_FCW_FFT_DATA; u2_t_i++){
		afl_g_lca_sim_2f_rear_dft_thre[u2_t_i] = (FL)0;
	}
	for (u2_t_i = (U2)0; u2_t_i < (U2)2; u2_t_i++){
		afl_g_lca_sim_fhl_vec_x[u2_t_i] = CFL_LCA_CMN_NEGA_INF;
		afl_g_lca_sim_fhl_vec_y[u2_t_i] = CFL_LCA_CMN_NEGA_INF;
	}
	#endif

	/******************************/
	/***** グローバル変数更新 *****/
	/******************************/
	/* LCA&FHL 搭載角度の更新 */
	st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = st_g_bsm_loop_data.afl_installed_angle[0];

	/* 0～(LCA_DEG_MAX/2) でガードを掛ける */
	if (st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg < (FL)0) {
		st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = (FL)0;
	} else if (st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg > (FL)(LCA_DEG_MAX) / (FL)2) {
		st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = (FL)(LCA_DEG_MAX) / (FL)2;
	} else {
		/* 何もしない */
	}
	
	/* LCA 警報開始 TTC の更新 */
	/*  LCA 警報開始 TTC の設定値 g_lca_ecu_ttc_thre を毎サイクル設定する */
	switch (u1_g_lca_ttc_table_custom_for_base) {			/* lca_ttc_table_custom */
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_OFF:			/* 0：OFF */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_SHORT:		/* 1：SHORT */
		fl_g_lca_ecu_ttc_thre = (FL)3;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_MIDDLE:		/* 2：MIDDLE */
		fl_g_lca_ecu_ttc_thre = (FL)4;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_LONG:		/* 3：LONG */
		fl_g_lca_ecu_ttc_thre = (FL)5;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_INIT:		/* 不定の場合 */
		/* 不定の場合は動作させないため 0：OFF と同じ動作をさせる */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	default:												/* その他。通常はあり得ない */
		/* あり得ないデータの場合は動作させないため 0：OFF と同じ動作をさせる */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	}

	/*************************************/
	/***** 2FCW/FMCW変動閾値算出処理 *****/
	/*************************************/
	fn_lca_recg03_set_freq_threshold_2fcw();
	fn_lca_recg03_set_freq_threshold_fmcw();

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_3 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 3, &au2_g_lca_check_tmr[3]);	/* CheckPoint chk lca */
#endif 
#endif

	/**************************/
	/***** 壁距離算出処理 *****/
	/**************************/
	fn_lca_recg01_cal_wall_dist(
		&u1_t_peak_music_num_up,		/* [out] FMCW(up) freq-doaマップ上の総抽出ピーク数 */
		afl_t_music_doa_pow_up,			/* [out] FMCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
		afl_t_music_bin_intpl_up,		/* [out] FMCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
		afl_t_music_doa_bin_intpl_up,	/* [out] FMCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
		&u1_t_peak_music_num_dn,		/* [out] FMCW(dn) freq-doaマップ上の総抽出ピーク数 */
		afl_t_music_doa_pow_dn,			/* [out] FMCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
		afl_t_music_bin_intpl_dn,		/* [out] FMCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
		afl_t_music_doa_bin_intpl_dn,	/* [out] FMCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
		au1_t_used_up,					/* [out] 使用不可フラグ(up) 0:使用可 1:使用不可 */
		au1_t_used_dn					/* [out] 使用不可フラグ(dn) 0:使用可 1:使用不可 */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_4 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 4, &au2_g_lca_check_tmr[4]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************************************/
	/***** 走行軌跡・隣接車線確率マップ算出処理 *****/
	/************************************************/
	if (fl_g_v_self_bsm_for_base > CFL_LCA_CMN_FHL_ON_SELF_VELOCITY_KMPH) {		/* MWR-RECO-24G-LCA-RECOG-02-002 条件 4.a */
		fn_lca_recg02_one_side_vehicle_map();
	}

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_5 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 5, &au2_g_lca_check_tmr[5]);	/* CheckPoint chk lca */
#endif 
#endif

	/*********************************************/
	/***** 2FCW後方DFTの距離相関行列算出処理 *****/
	/*********************************************/
	fn_lca_recg04_calc_fcw_dft_ryy_matrix();

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_6 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 6, &au2_g_lca_check_tmr[6]);	/* CheckPoint chk lca */
#endif 
#endif

	/***********************************************/
	/****** 2FCW後方DFTの2Dピーク情報算出処理 ******/
	/***********************************************/
	fn_lca_recg05_seak_dft_2f_peak(
		&u1_t_peak_music_num_2f,		/* [out] 2FCWの2次元マップ上の総抽出ピーク数 */
		au1_t_2f_dft_peak_flg,			/* [out] 2FCWの2次元マップ上のピークが後方DFTスペクトルで発見したピークであるフラグ */
		au1_t_2f_sharp_dftpeak_flg,		/* [out] 2FCWの2次元マップ上のピークが鋭利であるフラグ */
		afl_t_music_doa_pow_2f,			/* [out] 2FCWの2次元マップ上のピークのDBF電力 */
		afl_t_music_bin_intpl_2f,		/* [out] 2FCWの2次元マップ上のピークの周波数ビン(補間) */
		afl_t_music_doa_bin_intpl_2f	/* [out] 2FCWの2次元マップ上のピークの方位ビン(補間) */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_8 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 8, &au2_g_lca_check_tmr[8]);	/* CheckPoint chk lca */
#endif 
#endif

	/***********************************/
	/***** 2FCW後方DFT乱れ判定処理 *****/
	/***********************************/
	fn_lca_recg06_calc_2f_useless_flg();


#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_9 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 9, &au2_g_lca_check_tmr[9]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************************/
	/****** FMCW(UP)後方DFTの2Dピーク情報算出処理 ******/
	/***************************************************/
	fn_lca_recg07_seak_dft_fmcw_up_peak(
		&u1_t_peak_music_num_up,		/* [out] FMCW freq-doaマップ上の総抽出ピーク数 */
		afl_t_music_doa_pow_up,			/* [out] FMCW freq-doaマップ上の総抽出ピーク DBF-pow情報 */
		afl_t_music_bin_intpl_up,		/* [out] FMCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
		afl_t_music_doa_bin_intpl_up	/* [out] FMCW freq-doaマップ上の総抽出ピーク DOA-bin情報(補間) */
	);

	/************************/
	/***** 環境認識処理 *****/
	/************************/
	fn_lca_cmn_environ_judgement();

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_11 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 11, &au2_g_lca_check_tmr[11]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************/
	/***** 優先物標処理 *****/
	/************************/
	fn_lca_recg08_seek_prior_obj(
		&u1_t_nml_crn_num,		/* [out] 今サイクルのNORMAL物標数 */
		ast_t_nml_crn			/* [out] 今サイクルのNORMAL物標構造体 */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_13 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 13, &au2_g_lca_check_tmr[13]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************/
	/***** 通常物標処理 *****/
	/************************/
	fn_lca_recg09_seek_ordinary_obj(
		u1_t_peak_music_num_2f,			/* [in] 2FCWの2次元ピーク数 */
		afl_t_music_doa_pow_2f,			/* [in] 2FCWの2次元ピークのDBF電力 */
		afl_t_music_bin_intpl_2f,		/* [in] 2FCWの2次元ピークの周波数bin(補間) */
		afl_t_music_doa_bin_intpl_2f,	/* [in] 2FCWの2次元ピークの方位bin(補間) */
		au1_t_2f_dft_peak_flg,			/* [in] 2FCWの2次元ピークのDFT検出フラグ */
		u1_t_peak_music_num_up,			/* [in] FMCW(up)の2次元ピーク数 */
		afl_t_music_doa_pow_up,			/* [in] FMCW(up)の2次元ピークのDBF電力 */
		afl_t_music_bin_intpl_up,		/* [in] FMCW(up)の2次元ピークの周波数bin(補間) */
		afl_t_music_doa_bin_intpl_up,	/* [in] FMCW(up)の2次元ピークの方位bin(補間) */
		&u1_t_peak_music_num_dn,		/* [in/out] FMCW(dn)の2次元ピーク数 */
		afl_t_music_doa_pow_dn,			/* [in/out] FMCW(dn)の2次元ピークのDBF電力 */
		afl_t_music_bin_intpl_dn,		/* [in/out] FMCW(dn)の2次元ピークの周波数bin(補間) */
		afl_t_music_doa_bin_intpl_dn,	/* [in/out] FMCW(dn)の2次元ピークの方位bin(補間) */
		au1_t_used_up,					/* [in/out] FMCW(up) ピーク使用済フラグ */
		au1_t_used_dn,					/* [in/out] FMCW(dn) ピーク使用済フラグ */
		au1_t_used_2f,					/* [out] 2FCW ピーク使用済フラグ */
		&u1_t_nml_crn_num,				/* [in/out] 今サイクルのNORMAL物標数 */
		ast_t_nml_crn					/* [out] 今サイクルのNORMAL物標情報 */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_22 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 22, &au2_g_lca_check_tmr[22]);	/* CheckPoint chk lca */
#endif 
#endif

	/*******************************/
	/***** 近距離2周波物標処理 *****/
	/*******************************/
	fn_lca_recg10_seek_2f_obj(
		au1_t_used_2f,					/* [in/out] 2FCW 2次元ピークの使用済みフラグ */
		u1_t_peak_music_num_2f,			/* [in] 2FCW 2次元ピークのピーク数 */
		afl_t_music_doa_pow_2f,			/* [in] 2FCW 2次元ピークのDBF電力 */
		afl_t_music_bin_intpl_2f,		/* [in] 2FCW 2次元ピークの周波数ビン(補間) */
		afl_t_music_doa_bin_intpl_2f,	/* [in] 2FCW 2次元ピークの方位ビン(補間) */
		au1_t_2f_sharp_dftpeak_flg,		/* [in] 2FCW 2次元ピークが鋭利であるフラグ */
		&u1_t_nml_crn_num,				/* [in/out] 今サイクルのNORMAL物標数 */
		ast_t_nml_crn					/* [in/out] 今サイクルのNORMAL物標情報 */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_24 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 24, &au2_g_lca_check_tmr[24]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************************/
	/*** BSM情報を用いたNormal物標の追加と削除 *********/
	/***************************************************/
	fn_lca_recg17_normal_erase_and_add(
		&u1_t_nml_crn_num,				/* [in/out] 今サイクルのNORMAL物標数 */
		ast_t_nml_crn					/* [in/out] 今サイクルのNORMAL物標構造体 */
	);

	/**********************************/
	/***** NORMAL物標履歴接続処理 *****/
	/**********************************/
	fn_lca_recg11_nml_connect(
		&u1_t_nml_crn_num,		/* [in/out] Normal物標数 */
		ast_t_nml_crn			/* [in/out] Normal物標情報 */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_27 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 27, &au2_g_lca_check_tmr[27]);	/* CheckPoint chk lca */
#endif 
#endif

#ifdef _LCA_AUDR_INPUT	/* LCA演算時間確認用のAUDR出力変数 */
	/* △AUDR ABST_15 */
	/*********************************/
	/*** Normal物標のNBD格納処理用 ***/
	/*********************************/
	for(u1_t_i = 0; u1_t_i < CU1_LCA_CMN_NORMAL_BUFFSIZE; u1_t_i++ ){
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_stop_flg			= ast_t_nml_crn[u1_t_i].u1_stop_flg;			/*	停止物フラグ	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_trk_num				= ast_t_nml_crn[u1_t_i].u1_trk_num;				/*	トラッキング回数	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_lost_num			= ast_t_nml_crn[u1_t_i].u1_lost_num;			/*	外挿回数	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_new_flg				= ast_t_nml_crn[u1_t_i].u1_new_flg;				/*	新規物標フラグ	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_num					= ast_t_nml_crn[u1_t_i].u1_num;					/*	物標番号	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_used				= ast_t_nml_crn[u1_t_i].u1_used;				/*	捨てフラグ	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_dc_flg				= ast_t_nml_crn[u1_t_i].u1_dc_flg;				/*	物標タイプ情報	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_up_flg	= ast_t_nml_crn[u1_t_i].u1_single_peak_up_flg;	/*	片ピークフラグ(upのみ発見)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_dn_flg	= ast_t_nml_crn[u1_t_i].u1_single_peak_dn_flg;	/*	片ピークフラグ(dnのみ発見)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_trked_flg			= ast_t_nml_crn[u1_t_i].u1_trked_flg;			/*	NORMAL物標のトラッキングフラグ	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_trk_num	= ast_t_nml_crn[u1_t_i].u1_single_peak_trk_num;	/*	片ピーク連続接続回数	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_side_runner_flg		= ast_t_nml_crn[u1_t_i].u1_side_runner_flg;		/*	併走外挿フラグ(TARGET物標で使用)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_car_type			= ast_t_nml_crn[u1_t_i].u1_car_type;			/*	CARタイプ	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_truck_index			= ast_t_nml_crn[u1_t_i].u1_truck_index;			/*	セグメントindex(トラック判定用)	*/

		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_up_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_up_intpl;		/*	周波数upビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_dn_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_dn_intpl;		/*	周波数dnビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_2f_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_2f_intpl;		/*	周波数2fビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_up_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_up_music_intpl;	/*	方位upビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_dn_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_dn_music_intpl;	/*	方位dnビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_2f_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_2f_music_intpl;	/*	方位2fビン(補間)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_up				= ast_t_nml_crn[u1_t_i].fl_pow_up;				/*	FFT pow (up)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_dn				= ast_t_nml_crn[u1_t_i].fl_pow_dn;				/*	FFT pow (down)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_2f				= ast_t_nml_crn[u1_t_i].fl_pow_2f;				/*	FFT pow (2f)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_up_music		= ast_t_nml_crn[u1_t_i].fl_pow_up_music;		/*	DBF pow (up)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_dn_music		= ast_t_nml_crn[u1_t_i].fl_pow_dn_music;		/*	DBF pow (dn)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_2f_music		= ast_t_nml_crn[u1_t_i].fl_pow_2f_music;		/*	DBF pow (2f)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Rxobs				= ast_t_nml_crn[u1_t_i].fl_Rxobs;				/*	X	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Ryobs				= ast_t_nml_crn[u1_t_i].fl_Ryobs;				/*	Y	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Rxfil				= ast_t_nml_crn[u1_t_i].fl_Rxfil;				/*	X(ﾌｨﾙﾀ値)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Ryfil				= ast_t_nml_crn[u1_t_i].fl_Ryfil;				/*	Y(ﾌｨﾙﾀ値)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vxobs_mps			= ast_t_nml_crn[u1_t_i].fl_Vxobs_mps;			/*	VX	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vyobs_mps			= ast_t_nml_crn[u1_t_i].fl_Vyobs_mps;			/*	VY	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vxfil_mps			= ast_t_nml_crn[u1_t_i].fl_Vxfil_mps;			/*	VX(ﾌｨﾙﾀ値)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vyfil_mps			= ast_t_nml_crn[u1_t_i].fl_Vyfil_mps;			/*	VY(ﾌｨﾙﾀ値)	*/
	}
#endif


	/**********************************/
	/***** TARGET物標履歴接続処理 *****/
	/**********************************/
	fn_lca_recg12_tgt_connect(
		u1_t_nml_crn_num,				/* [in]  Normal物標数 */
		ast_t_nml_crn,					/* [in]  Normal物標情報 */
		&u1_t_tgt_crn_num,				/* [out] Target物標数 */
		ast_t_tgt_crn,					/* [out] Target物標情報 */
		u1_t_peak_music_num_2f,			/* [in]  2FCW freq-doaマップ上の総抽出ピーク数 */
		afl_t_music_bin_intpl_2f,		/* [in]  2FCW freq-doaマップ上の総抽出ピーク freq-bin情報(補間) */
		au1_t_2f_sharp_dftpeak_flg		/* [in]  2FCW freq-doaマップ上のピークが鋭いことのフラグ */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_30 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 30, &au2_g_lca_check_tmr[30]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************/
	/***** TARGET物標のLCA警報判定処理 *****/
	/***************************************/
	fn_lca_recg13_lca_alm(
		u1_t_tgt_crn_num,		/* [in]     今サイクルのTARGET物標数 */
		ast_t_tgt_crn,			/* [in/out] 今サイクルのTarget物標情報 ([out] 距離順(Ryfil順)にソート済) */
		&u1_t_alm_flg			/* [out]    LCA警報フラグ */
	);

	/***************************************/
	/***** TARGET物標のFHL警報判定処理 *****/
	/***************************************/
	fn_lca_recg14_fhl_alm(
		u1_t_tgt_crn_num,		/* [in]     今サイクルのTARGET物標数 */
		ast_t_tgt_crn,			/* [in/out] 今サイクルのTarget物標情報 */
		&u1_t_hazard_flg		/* [out]    FHL警報フラグ */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA演算時間格納_31 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 31, &au2_g_lca_check_tmr[31]);	/* CheckPoint chk lca */
#endif 
#endif

#ifdef _LCA_AUDR_INPUT	/* LCA演算時間確認用のAUDR出力変数 */
	/* △AUDR ABST_16 */
	/*********************************/
	/*** Target物標のNBD格納処理用 ***/
	/*********************************/
	for(u1_t_i = 0; u1_t_i < CU1_LCA_CMN_TGT_BUFFSIZE; u1_t_i++ ){
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_stop_flg			= ast_t_tgt_crn[u1_t_i].u1_stop_flg;			/*	停止物フラグ	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_trk_num				= ast_t_tgt_crn[u1_t_i].u1_trk_num;				/*	トラッキング回数	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_lost_num			= ast_t_tgt_crn[u1_t_i].u1_lost_num;			/*	外挿回数	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_new_flg				= ast_t_tgt_crn[u1_t_i].u1_new_flg;				/*	新規物標フラグ	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_num					= ast_t_tgt_crn[u1_t_i].u1_num;					/*	物標番号	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_used				= ast_t_tgt_crn[u1_t_i].u1_used;				/*	捨てフラグ	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_dc_flg				= ast_t_tgt_crn[u1_t_i].u1_dc_flg;				/*	物標タイプ情報	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_up_flg	= ast_t_tgt_crn[u1_t_i].u1_single_peak_up_flg;	/*	片ピークフラグ(upのみ発見)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_dn_flg	= ast_t_tgt_crn[u1_t_i].u1_single_peak_dn_flg;	/*	片ピークフラグ(dnのみ発見)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_trked_flg			= ast_t_tgt_crn[u1_t_i].u1_trked_flg;			/*	TARGET物標のトラッキングフラグ	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_alm_flg				= ast_t_tgt_crn[u1_t_i].u1_alm_flg;				/*	LCA警報物標フラグ(今サイクル)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_pre_alm_flg			= ast_t_tgt_crn[u1_t_i].u1_pre_alm_flg;			/*	LCA警報物標フラグ(前サイクル)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_trk_num	= ast_t_tgt_crn[u1_t_i].u1_single_peak_trk_num;	/*	片ピーク連続接続回数	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_side_runner_flg		= ast_t_tgt_crn[u1_t_i].u1_side_runner_flg;		/*	併走外挿フラグ(TARGET物標で使用)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_car_type			= ast_t_tgt_crn[u1_t_i].u1_car_type;			/*	CARタイプ	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_truck_index			= ast_t_tgt_crn[u1_t_i].u1_truck_index;			/*	セグメントindex(トラック判定用)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_hazard_flg			= ast_t_tgt_crn[u1_t_i].u1_hazard_flg;			/*	FHL警報物標フラグ(今サイクル)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_pre_hazard_flg		= ast_t_tgt_crn[u1_t_i].u1_pre_hazard_flg;		/*	FHL警報物標フラグ(前サイクル)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_fhl_on_cnt			= ast_t_tgt_crn[u1_t_i].u1_fhl_on_cnt;			/*	FHL警報ONカウンタ	*/
        
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_up_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_up_intpl;		/*	周波数upビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_dn_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_dn_intpl;		/*	周波数dnビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_2f_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_2f_intpl;		/*	周波数2fビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_up_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_up_music_intpl;	/*	方位upビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_dn_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_dn_music_intpl;	/*	方位dnビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_2f_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_2f_music_intpl;	/*	方位2fビン(補間)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Rxobs				= ast_t_tgt_crn[u1_t_i].fl_Rxobs;				/*	X	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Ryobs				= ast_t_tgt_crn[u1_t_i].fl_Ryobs;				/*	Y	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Rxfil				= ast_t_tgt_crn[u1_t_i].fl_Rxfil;				/*	X(ﾌｨﾙﾀ値)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Ryfil				= ast_t_tgt_crn[u1_t_i].fl_Ryfil;				/*	Y(ﾌｨﾙﾀ値)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vxobs_mps			= ast_t_tgt_crn[u1_t_i].fl_Vxobs_mps;			/*	VX	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vyobs_mps			= ast_t_tgt_crn[u1_t_i].fl_Vyobs_mps;			/*	VY	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vxfil_mps			= ast_t_tgt_crn[u1_t_i].fl_Vxfil_mps;			/*	VX(ﾌｨﾙﾀ値)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vyfil_mps			= ast_t_tgt_crn[u1_t_i].fl_Vyfil_mps;			/*	VY(ﾌｨﾙﾀ値)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_prob				= ast_t_tgt_crn[u1_t_i].fl_prob;				/*	隣接車線確率(TARGET物標のRfilによる確率)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_trk_prob			= ast_t_tgt_crn[u1_t_i].fl_trk_prob;			/*	隣接車線確率(TARGET物標のトラッキング後の確率)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_ttc					= ast_t_tgt_crn[u1_t_i].fl_ttc;					/*	TTC	*/
	}
#endif

	/**************************************/
	/***** 物標情報を次サイクルに持越し ***/
	/**************************************/
	fn_lca_recg15_loop_data_trim(
		u1_t_nml_crn_num,		/* [in]     今サイクルのNORMAL物標数 */
		ast_t_nml_crn,			/* [in/out] 今サイクルのNORMAL物標情報 */
		u1_t_tgt_crn_num,		/* [in]     今サイクルのTARGET物標数 */
		ast_t_tgt_crn,			/* [in/out] 今サイクルのTARGET物標情報 */
		u1_t_alm_flg,			/* [in]     LCA警報フラグ */
		u1_t_hazard_flg			/* [in]     FHL警報フラグ */
	);

	#if (SIM_VI_OUTPUT==LCA_VI_ON)	/* For Labview */
	fn_lca_cmn_init(
		ast_g_lca_sim_nml_crn2,
		CU1_LCA_CMN_NORMAL_BUFFSIZE
	);
	u1_g_lca_sim_nml_crn_num2 = u1_t_nml_crn_num;
	fn_lca_cmn_nml_output(ast_g_lca_sim_nml_crn2, ast_t_nml_crn, CU1_LCA_CMN_NORMAL_BUFFSIZE);

	fn_lca_cmn_init(
		ast_g_lca_sim_tgt_crn2,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);
	u1_g_lca_sim_tgt_crn_num2 = u1_t_tgt_crn_num;
	fn_lca_cmn_nml_output(ast_g_lca_sim_tgt_crn2, ast_t_tgt_crn, CU1_LCA_CMN_TGT_BUFFSIZE);

	fn_lca_sim_alm_tgt_output(
		u1_t_tgt_crn_num,		// [in] 今サイクルのTARGET物標数
		ast_t_tgt_crn			// [in] 今サイクルのTARGET物標構造体
	);
	#endif

#ifdef _LCA_AUDR_INPUT	/* LCA演算時間確認用のAUDR出力変数 */
#if (MODE_ECU_SIM == ECU_MODE)
	/* △AUDR	NBDinput_ABST_01 ～ 14 */
	/* 仕様書では、ここでAUDR用に変数をラッチするとあるが、		*/
	/* 1)RAM領域削減のため、2)出力変数がこれ以降変化しないため、*/
	/* ここでのラッチは行わず、認識処理後に直接_NBDに出力する。	*/
#endif
#endif
	return;
}



/****************************************************************************/
/* 関数名	: fn_lca_abst_init_data											*/
/*--------------------------------------------------------------------------*/
/* 機能		: LCA_ABSTの設定が必要なものを設定する							*/
/*--------------------------------------------------------------------------*/
/* 引数		: なし															*/
/* 戻り値	: なし															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* [in]  	: なし															*/
/* [out] 	: なし															*/
/*--------------------------------------------------------------------------*/
/* 仕様書	: MWR-RECO-24G-LCA-ABST-006								 		*/
/*			: 6.2.1 LCA/FHL で新規定義する適合値							*/
/****************************************************************************/
VD fn_lca_abst_init_data(VD)
{
	/* 仕向け毎切替データの設定 */
	fn_lca_abst_read_data_by_bsmdest();
	
	return;
}




/* ======================================================================== */
/* 	内部公開API 															*/
/* ======================================================================== */

/****************************************************************************/
/* 関数名	: fn_lca_abst_read_data_by_bsmdest								*/
/*--------------------------------------------------------------------------*/
/* 機能		: BSM_DESTによって、切り替える値を設定する						*/
/*--------------------------------------------------------------------------*/
/* 引数		: なし															*/
/* 戻り値	: なし															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* [in]  	: CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone; */
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA						*/
/*--------------------------------------------------------------------------*/
/* 仕様書	: MWR-RECO-24G-LCA-ABST-006								 		*/
/*			: 6.2.1 LCA/FHL で新規定義する適合値							*/
/****************************************************************************/
VD fn_lca_abst_read_data_by_bsmdest(VD)
{
	U1 u1_t_bsm_bsd_zone_y_max;
	
	/* BSD_ZONE_Y_MAXを整数値で比較するためにLSB変換前にローカル変数に一旦ラッチする */
	u1_t_bsm_bsd_zone_y_max = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone;
	
	if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_WIDE) {
		/* BSM警報領域設定幅がWideな場合は、LCAの外側オフセット量もWideに設定する */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)6.2;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.95;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.7;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.45;
	} else if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_NARROW) {
		/* BSM警報領域設定幅がNarrowな場合は、LCAの外側オフセット量もNarrowに設定する */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)5.75;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.5;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.25;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.0;
	} else {
		/* 不定値の場合は、u1_Warning_zoneの不定値に合わせて、Wideに設定する */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)6.2;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.95;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.7;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.45;
	}

	return;
}
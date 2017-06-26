/****************************************************************************/
/* ファイル名	: BSM_RECOG_02.c											*/
/*--------------------------------------------------------------------------*/
/* モジュール名	: 															*/
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
/*  t300 リファクタリング 及び、9/17版 BSM最新仕様マージ					*/
/*	t02					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替対応															*/
/*	t03					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 仕様確認項目対応												*/
/*	t04					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 int→S4,float→FLに変更										*/
/*	t05					15.02.27			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 仕様確認項目再対応											*/
/*	t06					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM QAC対応(OBJ変更なし)												*/
/*	t07					15.03.23			走安技2 1技室 G.Jomori			*/
/*	仕様確認No992対応														*/
/*	t09					15.05.25			走安技2 1技室 G.Jomori			*/
/*	残課題No480,481対応														*/
/*	t10					15.06.02			走安技2 1技室 G.Jomori			*/
/*	残課題No437対応															*/
/*	t13					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t14					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t15					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 スタックオーバー対策									*/
/*	t16					15.08.07			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 一致確認中に発見したバグ修正							*/
/*	t17					15.08.19			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 一致確認中に発見したバグ修正							*/
/*	t18					15.08.31			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1553対応														*/
/*	t19					15.09.11			走安技2 1技室 G.Jomori			*/
/*	FS_認識巻替_修正項目共有リストNo7対応									*/
/*	t20					15.10.27			走安技2 1技室 Y.Nishioka		*/
/*	関数ヘッダの追加 ※OBJ変更なし											*/
/*	t21					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t22					15.11.25			走安技2 1技室 G.Jomori			*/
/*	仕様確認No.1672,1680対応												*/
/*	t23					16.03.01			走安技2 1技室 G.Jomori			*/
/*	010B BSM CV-R仕様対応													*/
/*	t24					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1198対応(ローカル配列変数の宣言と同時に実施の初期化分離)		*/
/*	t25					16.03.07			走安技2 1技室 G.Jomori			*/
/*	残課題No1139対応(条件の演算式を全てFLで演算)							*/
/*	t26					16.03.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様対応														*/
/*	t27					16.03.28			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 机上セルフ対応											*/
/*	t28					16.03.28			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 机上セルフ対応(OBJ変更なし)								*/
/*	t29					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応									*/
/*	t30					16.03.29			走安技2 1技室 G.Jomori			*/
/*	残課題No1089対応(条件文修正)											*/
/*	t31					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応(OBJ変更なし)						*/
/*	t32					16.03.30			走安技2 1技室 G.Jomori			*/
/*	291B BSM 20degのときのみ使用する変数・関数をコンパイルオプションで囲む(OBJ変更なし)*/
/*	t33					16.03.31			走安技2 1技室 G.Jomori			*/
/*	一致確認で発見したバグ修正(50degではOBJ変更なし 20degではOBJ変更あり)	*/
/*	t34					16.04.12			走安技2 1技室 K.Hanabata		*/
/*	QAC指摘修正																*/
/*	t35					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t36					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(重複定義関連 OBJ変更なし)									*/
/*	t37					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t38					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t39					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM 残課題No1336対応 OBJ変更なし										*/
/*	t40					16.06.21			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t45					16.07.18			走安技2 1技室 G.Jomori			*/
/*	291B開発用ソフトに010Bソフトをマージ(010B 1Aをベースに0024_t822マージ)	*/
/*	t48					16.08.10			走安技2 1技室 Y.Nishioka		*/
/*	関数名変更(shareMUSIC_を追加) ※オブジェクト変更なし					*/
/*	t51					16.08.11			走安技2 1技室 G.Jomori			*/
/*	残課題No1405,1406,1407対応(int→S4に変更 OBJ変更なし)					*/
/*	t54					16.09.15			走安技2 1技室 G.Jomori			*/
/*	010B 2A 認識部分(BSM,RCTA,AUDR)マージ									*/
/*	t55					16.11.18			走安技2 1技室 G.Jomori			*/
/*	MWR-RECO-24G-BSM-RECOG-02-020D対応										*/
/****************************************************************************/

/****************************************************************************/
/*							インクルードファイル							*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "init_cvw.h"
#include "bsm_connect_01.h"
#include "func_fmcw.h"
#include "func_fsk.h"
#include "../../common/cmn_shareMUSIC_mwr.h"
#include "../../../common/inc_mwr.h"


#include "bsm_recog_02.h"

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

/****************************************************************************/
/*							スタティック関数宣言							*/
/****************************************************************************/
VD fn_bsm_ordinary_init_data(
	S4 *ps4_a_peak_num_ordinary,
	S4 as4_a_peak_bin[PEAK_BUFFSIZE],			/* selected peak freq - bin (up) */
	FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],	/*interpolated peak freq - bin (up) */
	FL afl_a_peak_power[PEAK_BUFFSIZE],
    FL afl_a_thres[NB_FFT_PT],

	S4 as4_a_peak_bin_ordinary[ORDINARY_BUFFSIZE],
	FL afl_a_peak_bin_intpl_ordinary[ORDINARY_BUFFSIZE],
	FL afl_a_peak_power_ordinary[ORDINARY_BUFFSIZE],

	S4 *ps4_a_peak_num_music,
	FL afl_a_peak_bins_intpl[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_powers[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers[PEAK_BUFFSIZE * 2]
);

VD fn_bsm_ordinary_estimate_doa(
	S4 s4_a_flg_updn,
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */

	S4 s4_a_peak_num,
	const S4 as4_a_peak_bin[ORDINARY_BUFFSIZE],						/* [in] frequency of peak */
	const FL afl_a_peak_bin_intpl[ORDINARY_BUFFSIZE],				/* [in] interpolated frequency of peak */
	const FL afl_a_peak_power[ORDINARY_BUFFSIZE],					/* [in] afl_a_power of peak */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[ORDINARY_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[ORDINARY_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[ORDINARY_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[ORDINARY_BUFFSIZE * 2]						/* [out] peak doa afl_a_power */
);

VD fn_bsm_ordinary_cal_doa(
	S4 s4_a_updn_flg,										/*  [in] direction of beat-signal */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/*  [in] correlation matrix */

	S4 s4_a_peak_bin,										/*  [in] frequency of peak */
	FL fl_a_peak_bin_intpl,									/*  [in] interpolated frequency of peak */

	S4 *ps4_a_doa_num,										/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],					/* [out] */
	FL afl_a_selected_doa_powers[2],						/* [out] */
	FL afl_a_selected_bins_intpl[2]							/* [out] */
);

VD fn_bsm_ordinary_store_doa(
	const FL afl_a_peak_power[ORDINARY_BUFFSIZE],					/* [in] afl_a_power of peak */

	const S4 as4_a_doa_num[ORDINARY_BUFFSIZE],
	FL afl_a_selected_doa_bins_intpl[ORDINARY_BUFFSIZE][2],
	FL afl_a_selected_doa_powers[ORDINARY_BUFFSIZE][2],
	FL afl_a_selected_bins_intpl[ORDINARY_BUFFSIZE][2],

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[ORDINARY_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[ORDINARY_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[ORDINARY_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[ORDINARY_BUFFSIZE * 2]					/* [out] peak doa afl_a_power */
);

VD fn_bsm_ordinary_make_pair(
	S4 s4_a_peak_num_up_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4*		   ps4_a_pair_num_ordinary,									/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]					/* [out] S4 values of NORMAL_BSM structure */
);

VD fn_bsm_ordinary_make_pair_sot(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[ORDINARY_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
);

VD fn_bsm_ordinary_make_pair_stationary(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],

	S4 s4_a_pair_num
);

VD fn_bsm_ordinary_make_pair_moving(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[ORDINARY_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
);

#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degでは関数定義なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
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
											 S4* ps4_a_pair_num);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */


VD fn_bsm_ordinary_make_pair_outer(
	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
);

static VD fn_bsm_ordinary_compare_with_2FCW(
	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
);

VD fn_bsm_ordinary_set_object(
	const S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
);

/****************************************************************************/
/* 関数名		: fn_bsm_seek_prior_object									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (1)～(11) 通常物標認識処理								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>																	*/
/*																			*/
/* <output>																	*/
/*																			*/
/*--------------------------------------------------------------------------*/
/* 参照関数 	: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (1)～(11) 通常物標認識処理								*/
/*--------------------------------------------------------------------------*/
/* 作成者   	: 															*/
/****************************************************************************/
VD fn_bsm_seek_ordinary_object(
	S4*		   ps4_a_pair_num_ordinary,							/* [out] number of prior object */
	NORMAL_BSM ast_a_normalordinary[ORDINARY_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_peak_num_ordinary_up;
	S4 as4_t_peak_bin_up[PEAK_BUFFSIZE];					/* selected peak freq - bin (up) */
	FL afl_t_peak_bin_intpl_up[PEAK_BUFFSIZE];				/* interpolated peak freq-bin (up) */
	FL afl_t_peak_power_up[PEAK_BUFFSIZE];
    FL afl_t_thres_up[NB_FFT_PT];							/* [out] threashold for spectrum power（up) */

	S4 s4_t_peak_num_ordinary_dn;
	S4 as4_t_peak_bin_dn[PEAK_BUFFSIZE];					/* selected peak freq - bin (down) */
	FL afl_t_peak_bin_intpl_dn[PEAK_BUFFSIZE];				/* interpolated peak freq-bin (down) */
	FL afl_t_peak_power_dn[PEAK_BUFFSIZE];
    FL afl_t_thres_dn[NB_FFT_PT];							/* [out] threashold for spectrum power（down) */

	S4 as4_t_peak_bin_up_ordinary[ORDINARY_BUFFSIZE];					/* selected peak freq - bin (up) SIZE:ORDINARY_BUFFSIZE */
	FL afl_t_peak_bin_intpl_up_ordinary[ORDINARY_BUFFSIZE];				/* interpolated peak freq-bin (up) SIZE:ORDINARY_BUFFSIZE */
	FL afl_t_peak_power_up_ordinary[ORDINARY_BUFFSIZE];

	S4 as4_t_peak_bin_dn_ordinary[ORDINARY_BUFFSIZE];					/* selected peak freq - bin (down) SIZE:ORDINARY_BUFFSIZE */
	FL afl_t_peak_bin_intpl_dn_ordinary[ORDINARY_BUFFSIZE];				/* interpolated peak freq-bin (down) SIZE:ORDINARY_BUFFSIZE */
	FL afl_t_peak_power_dn_ordinary[ORDINARY_BUFFSIZE];

	S4 s4_t_peak_num_up_music;
	FL afl_t_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_powers_up[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2];

	S4 s4_t_peak_num_dn_music;
	FL afl_t_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_powers_dn[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2];
	FL afl_t_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2];

	S4 s4_t_lp_peakbuff;


	/****************************************************************************/
	/* (0)  初期化																*/
	/****************************************************************************/
	fn_bsm_ordinary_init_data(
		&s4_t_peak_num_ordinary_up,
		as4_t_peak_bin_up,
		afl_t_peak_bin_intpl_up,
		afl_t_peak_power_up,
		afl_t_thres_up,

		as4_t_peak_bin_up_ordinary,
		afl_t_peak_bin_intpl_up_ordinary,
		afl_t_peak_power_up_ordinary,

		&s4_t_peak_num_up_music,
		afl_t_peak_bins_intpl_up,
		afl_t_peak_powers_up,
		afl_t_peak_doa_bins_intpl_up,
		afl_t_peak_doa_powers_up
	);

	fn_bsm_ordinary_init_data(
		&s4_t_peak_num_ordinary_dn,
		as4_t_peak_bin_dn,
		afl_t_peak_bin_intpl_dn,
		afl_t_peak_power_dn,
		afl_t_thres_dn,

		as4_t_peak_bin_dn_ordinary,
		afl_t_peak_bin_intpl_dn_ordinary,
		afl_t_peak_power_dn_ordinary,

		&s4_t_peak_num_dn_music,
		afl_t_peak_bins_intpl_dn,
		afl_t_peak_powers_dn,
		afl_t_peak_doa_bins_intpl_dn,
		afl_t_peak_doa_powers_dn
	);

	/****************************************************************************/
	/* (1)  通常ピーク閾値算出処理                                              */
	/****************************************************************************/
	/* 通常ピークサーチ用閾値設定 */
	fn_set_freq_threshold(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],			/* [in] */
		afl_t_thres_up									/* [out] */
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161123_BTT_FM_THRES)
		,OBJECT_TYPE_ORDINARY							/* [in] object type: ordinary object */
#endif
	);
	fn_set_freq_threshold(
		(const FL *)afl_g_cvw_lfm_ftt_power[1],			/* [in] */
		afl_t_thres_dn									/* [out] */
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161123_BTT_FM_THRES)
		,OBJECT_TYPE_ORDINARY							/* [in] object type: ordinary object */
#endif
	);
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy(afl_g_thres_up, afl_t_thres_up, sizeof(FL)*NB_FFT_PT);
	memcpy(afl_g_thres_dn, afl_t_thres_dn, sizeof(FL)*NB_FFT_PT);
#endif /*VI 表示用*/

	/* ノイズ評価用送信データラッチ LSB:0.01に変更 閾値の最大値が u2 / 100 を超えない事を演算チェックで確認すること */
	st_g_tx_noise_chk_fm_bsm.u2_thres1_up = u2_cast_from_fl(afl_t_thres_up[300] * (FL)100);
	st_g_tx_noise_chk_fm_bsm.u2_thres1_dn = u2_cast_from_fl(afl_t_thres_dn[300] * (FL)100);
	st_g_tx_noise_chk_fm_bsm.u2_thres2_up = u2_cast_from_fl(afl_t_thres_up[500] * (FL)100);
	st_g_tx_noise_chk_fm_bsm.u2_thres2_dn = u2_cast_from_fl(afl_t_thres_dn[500] * (FL)100);

	/****************************************************************************/
	/* (2)	優先ピークサーチ処理												*/
	/****************************************************************************/
	/* peak serch */
	s4_t_peak_num_ordinary_up = s4_search_freq_peak(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],				/* [in] */
		as4_t_peak_bin_up,						/* [out] */
		afl_t_peak_bin_intpl_up,				/* [out] */
		afl_t_peak_power_up,					/* [out] */
		(const FL *)afl_t_thres_up,							/* [in] */
		FREQ_BIN_LOWER_LIMIT,
		FREQ_BIN_UPPER_LIMIT_DN
	);

	if (st_g_bsm_loop_data.as4_slow_sot_find[0] != (S4)0) {
		s4_t_peak_num_ordinary_dn = s4_search_freq_peak(
			(const FL *)afl_g_cvw_lfm_ftt_power[1],				/* [in] */
			as4_t_peak_bin_dn,						/* [out] */
			afl_t_peak_bin_intpl_dn,				/* [out] */
			afl_t_peak_power_dn,					/* [out] */
			(const FL *)afl_t_thres_dn,							/* [in] */
			NB_FFT_PT/2+9,
			FREQ_BIN_UPPER_LIMIT_DN
		);

		for (s4_t_lp_peakbuff = (S4)0; s4_t_lp_peakbuff < (S4)8; s4_t_lp_peakbuff++) {
			if (s4_t_peak_num_ordinary_dn < PEAK_BUFFSIZE) {														/* 2) cond.c */
				as4_t_peak_bin_dn[s4_t_peak_num_ordinary_dn] = 256+s4_t_lp_peakbuff;								/* 3) proc.5 */
				afl_t_peak_bin_intpl_dn[s4_t_peak_num_ordinary_dn] = (FL)(256+s4_t_lp_peakbuff);					/* 3) proc.6 */
				afl_t_peak_power_dn[s4_t_peak_num_ordinary_dn] = afl_g_cvw_lfm_ftt_power[1][256+s4_t_lp_peakbuff];	/* 3) proc.7 */
				s4_t_peak_num_ordinary_dn++;																		/* 3) proc.8 */
			}
		}
	} else {
		s4_t_peak_num_ordinary_dn = s4_search_freq_peak(
			(const FL *)afl_g_cvw_lfm_ftt_power[1],				/* [in] */
			as4_t_peak_bin_dn,						/* [out] */
			afl_t_peak_bin_intpl_dn,				/* [out] */
			afl_t_peak_power_dn,					/* [out] */
			(const FL *)afl_t_thres_dn,							/* [in] */
			FREQ_BIN_LOWER_LIMIT,
			FREQ_BIN_UPPER_LIMIT_DN
		);
	}

	/* ノイズ評価用送信データラッチ */
	st_g_tx_noise_chk_fm_bsm.u1_peak_num_up = (U1)s4_t_peak_num_ordinary_up;
	st_g_tx_noise_chk_fm_bsm.u1_peak_num_dn = (U1)s4_t_peak_num_ordinary_dn;


#if (MODE_ECU_SIM == ECU_MODE)
	/* S4→U1のダウンキャストであるが、s4_t_peak_num_ordinary_up/dnの値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_ordinary_music_up_peak_num = (U1)s4_t_peak_num_ordinary_up;		/* CheckPoint BSM_通常物標ピークサーチ結果up */
	u1_g_bsm_ordinary_music_dn_peak_num = (U1)s4_t_peak_num_ordinary_dn;		/* CheckPoint BSM_通常物標ピークサーチ結果dn */
#endif /* MODE_ECU_SIM */

	fn_sort_peak_by_power(
		as4_t_peak_bin_up,					/* [in] */
		afl_t_peak_bin_intpl_up,			/* [in] */
		afl_t_peak_power_up,				/* [in] */
		as4_t_peak_bin_up_ordinary,			/* [out] */
		afl_t_peak_bin_intpl_up_ordinary,	/* [out] */
		afl_t_peak_power_up_ordinary		/* [out] */
	);
	fn_sort_peak_by_power(
		as4_t_peak_bin_dn,					/* [in] */
		afl_t_peak_bin_intpl_dn,			/* [in] */
		afl_t_peak_power_dn,				/* [in] */
		as4_t_peak_bin_dn_ordinary,			/* [out] */
		afl_t_peak_bin_intpl_dn_ordinary,	/* [out] */
		afl_t_peak_power_dn_ordinary		/* [out] */
	);

	/* ピーク個数をガード */
	if (s4_t_peak_num_ordinary_up > ORDINARY_BUFFSIZE) {
		s4_t_peak_num_ordinary_up = ORDINARY_BUFFSIZE;
	}
	if (s4_t_peak_num_ordinary_dn > ORDINARY_BUFFSIZE) {
		s4_t_peak_num_ordinary_dn = ORDINARY_BUFFSIZE;
	}

	/****************************************************************************/
	/* 												*/
	/****************************************************************************/
	fn_bsm_ordinary_estimate_doa(
		0,
		afl_g_cvw_lfm_ryy_matrix[0],

		s4_t_peak_num_ordinary_up,
		(const S4 *)as4_t_peak_bin_up_ordinary,
		(const FL *)afl_t_peak_bin_intpl_up_ordinary,
		(const FL *)afl_t_peak_power_up_ordinary,

		&s4_t_peak_num_up_music,
		afl_t_peak_bins_intpl_up,
		afl_t_peak_powers_up,
		afl_t_peak_doa_bins_intpl_up,
		afl_t_peak_doa_powers_up
	);

	/****************************************************************************/
	/* 												*/
	/****************************************************************************/
	fn_bsm_ordinary_estimate_doa(
		1,
		afl_g_cvw_lfm_ryy_matrix[1],
		
		s4_t_peak_num_ordinary_dn,
		(const S4 *)as4_t_peak_bin_dn_ordinary,
		(const FL *)afl_t_peak_bin_intpl_dn_ordinary,
		(const FL *)afl_t_peak_power_dn_ordinary,

		&s4_t_peak_num_dn_music,
		afl_t_peak_bins_intpl_dn,
		afl_t_peak_powers_dn,
		afl_t_peak_doa_bins_intpl_dn,
		afl_t_peak_doa_powers_dn
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(28, &au2_g_bsm_check_tmr[28]);				/* CheckPoint chk bsm */
	/* S4→U1のダウンキャストであるが、s4_t_peak_num_up/dn_musicの値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_ordinary_up_pair_num = (U1)s4_t_peak_num_up_music;		/* CheckPoint BSM_通常物標物標数up */
	u1_g_bsm_ordinary_dn_pair_num = (U1)s4_t_peak_num_dn_music;		/* CheckPoint BSM_通常物標物標数dn */
#endif /* MODE_ECU_SIM */

	/****************************************************************************/
	/* 												*/
	/****************************************************************************/
	fn_bsm_ordinary_make_pair(
		s4_t_peak_num_up_music,											/* [in] */
		(const FL *)afl_t_peak_bins_intpl_up,							/* [in] */
		afl_t_peak_powers_up,											/* [in] */
		(const FL *)afl_t_peak_doa_bins_intpl_up,						/* [in] */
		(const FL *)afl_t_peak_doa_powers_up,							/* [in] */

		s4_t_peak_num_dn_music,											/* [in] */
		(const FL *)afl_t_peak_bins_intpl_dn,							/* [in] */
		afl_t_peak_powers_dn,											/* [in] */
		(const FL *)afl_t_peak_doa_bins_intpl_dn,						/* [in] */
		(const FL *)afl_t_peak_doa_powers_dn,							/* [in] */

		ps4_a_pair_num_ordinary,										/* [out] number of prior object */
		ast_a_normalordinary											/* [out] S4 values of NORMAL_BSM structure */
	);

/****************************************************************************/
/* (10)	compare with 2FCW											*/
/****************************************************************************/
	fn_bsm_ordinary_compare_with_2FCW(
		ps4_a_pair_num_ordinary,
		ast_a_normalordinary
	);

	/* sorting */
	/* sort とコメントがあるが、中身は前に詰めてる 前段のcompare_with_2FCW で行っているので 不必要な処理では？ */
	
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(29, &au2_g_bsm_check_tmr[29]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

	/* 出力データ保存 */
	fn_bsm_ordinary_set_object(
		(const S4 *)ps4_a_pair_num_ordinary,
		ast_a_normalordinary
	);
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_init_data 								*/
/*--------------------------------------------------------------------------*/
/* 機能			:  (0)  初期化												*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_init_data(
	S4 *ps4_a_peak_num_ordinary,
	S4 as4_a_peak_bin[PEAK_BUFFSIZE],			/* selected peak freq - bin (up) */
	FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],	/*interpolated peak freq - bin (up) */
	FL afl_a_peak_power[PEAK_BUFFSIZE],
    FL afl_a_thres[NB_FFT_PT],

	S4 as4_a_peak_bin_ordinary[ORDINARY_BUFFSIZE],
	FL afl_a_peak_bin_intpl_ordinary[ORDINARY_BUFFSIZE],
	FL afl_a_peak_power_ordinary[ORDINARY_BUFFSIZE],

	S4 *ps4_a_peak_num_music,
	FL afl_a_peak_bins_intpl[ORDINARY_BUFFSIZE * 2],
	FL afl_a_peak_powers[ORDINARY_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl[ORDINARY_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers[ORDINARY_BUFFSIZE * 2]
)
{
	S4 s4_t_lp_i;

	*ps4_a_peak_num_ordinary = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < PEAK_BUFFSIZE; s4_t_lp_i++) {
		as4_a_peak_bin[s4_t_lp_i] = 0;
		afl_a_peak_bin_intpl[s4_t_lp_i] = 0.0F;
		afl_a_peak_power[s4_t_lp_i] = 0.0F;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < NB_FFT_PT; s4_t_lp_i++) {
		afl_a_thres[s4_t_lp_i] = 0.0F;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < ORDINARY_BUFFSIZE; s4_t_lp_i++) {
		as4_a_peak_bin_ordinary[s4_t_lp_i] = (S4)0;
		afl_a_peak_bin_intpl_ordinary[s4_t_lp_i] = (FL)0.0F;
		afl_a_peak_power_ordinary[s4_t_lp_i] = (FL)0.0F;
	}

	*ps4_a_peak_num_music = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < (ORDINARY_BUFFSIZE * 2); s4_t_lp_i++) {
		afl_a_peak_bins_intpl[s4_t_lp_i] = 0;
		afl_a_peak_powers[s4_t_lp_i] = 0.0F;
		afl_a_peak_doa_bins_intpl[s4_t_lp_i] = 0;
		afl_a_peak_doa_powers[s4_t_lp_i] = 0.0F;
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_estimate_doa								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3) 方向推定												*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (3) 方向推定												*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_estimate_doa(
	S4 s4_a_flg_updn,
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */

	S4 s4_a_peak_num,
	const S4 as4_a_peak_bin[ORDINARY_BUFFSIZE],						/* [in] frequency of peak */
	const FL afl_a_peak_bin_intpl[ORDINARY_BUFFSIZE],				/* [in] interpolated frequency of peak */
	const FL afl_a_peak_power[ORDINARY_BUFFSIZE],					/* [in] afl_a_power of peak */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[ORDINARY_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[ORDINARY_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[ORDINARY_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[ORDINARY_BUFFSIZE * 2]						/* [out] peak doa afl_a_power */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_doa_calc_num;

	S4 as4_t_doa_num[ORDINARY_BUFFSIZE];
	FL afl_t_selected_doa_bins_intpl[ORDINARY_BUFFSIZE][2];
	FL afl_t_selected_doa_powers[ORDINARY_BUFFSIZE][2];
	FL afl_t_selected_bins_intpl[ORDINARY_BUFFSIZE][2];
	U2 u2_t_store_array_index;								/* LCAとの共有ピーク情報の記憶配列中のindex番号。後の処理は使用しないので入れ物だけ定義する */
	U1 au1_t_doa_num_copy[ORDINARY_BUFFSIZE];				/* 到来波数コピー用変数 共有ピーク情報の型に合わせる */
	FL afl_t_selected_doa_bins_intpl_copy[ORDINARY_BUFFSIZE][2];	/* 該当FFTピークのMUSICピーク bin(補間値)コピー用変数 */
	FL afl_t_selected_doa_powers_copy[ORDINARY_BUFFSIZE][2];		/* 該当FFTピークのMUSICピーク方位におけるDBF電力値コピー用変数 */
	FL afl_t_selected_bins_intpl_copy[ORDINARY_BUFFSIZE];			/* 該当FFTピークのFFTピークbin(補間値)コピー用変数 */
	U1 u1_t_exist_flag;				/* 該当データが登録済みか否か。登録済み(TRUE = 1), 未登録(FALSE = 0) */

	/* 初期化 */
	for (s4_t_lp_i = 0; s4_t_lp_i < ORDINARY_BUFFSIZE; s4_t_lp_i++) {
		as4_t_doa_num[s4_t_lp_i] = 0;
		au1_t_doa_num_copy[s4_t_lp_i] = (U1)0;
		afl_t_selected_bins_intpl_copy[s4_t_lp_i] = (FL)0.0F;
		for (s4_t_lp_k = 0; s4_t_lp_k < 2; s4_t_lp_k++) {
			afl_t_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_doa_powers[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i][s4_t_lp_k] = (FL)0.0F;
			afl_t_selected_doa_powers_copy[s4_t_lp_i][s4_t_lp_k] = (FL)0.0F;
		}
	}

	s4_t_doa_calc_num = (S4)0;
	u2_t_store_array_index = (U2)0;
	u1_t_exist_flag = CU1_FALSE;

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num; s4_t_lp_i++ ) {
		/* 1)方位推定処理済みピークの確認 */
		u1_t_exist_flag = u1_cmn_shareMUSIC_get_finished_music_data_main( (U1)s4_a_flg_updn,
																		  (U2)as4_a_peak_bin[s4_t_lp_i],
																		  &u2_t_store_array_index,
																		  &au1_t_doa_num_copy[s4_t_lp_i],
																		  &afl_t_selected_bins_intpl_copy[s4_t_lp_i],
																		  afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i],
																		  afl_t_selected_doa_powers_copy[s4_t_lp_i]);

		/* 仕様書では到来波数as4_t_doa_numが0かどうか見ているが			*/
		/* ソフト上では方位推定処理済みピークがあるかどうかのフラグを	*/
		/* 見ている。やりたいことは実現できているため問題なし			*/
		if (u1_t_exist_flag == CU1_FALSE) {
			if (s4_t_doa_calc_num < (ORDINARY_BUFFSIZE - 1))
			{
				s4_t_doa_calc_num++;

				/* (3) - 2)～5) 方位推定 */
				fn_bsm_ordinary_cal_doa(
					s4_a_flg_updn,
					(const FL (*)[10])afl_a_Ryy,

					as4_a_peak_bin[s4_t_lp_i],
					afl_a_peak_bin_intpl[s4_t_lp_i],

					&as4_t_doa_num[s4_t_lp_i],
					afl_t_selected_doa_bins_intpl[s4_t_lp_i],
					afl_t_selected_doa_powers[s4_t_lp_i],
					afl_t_selected_bins_intpl[s4_t_lp_i]
				);

				/* 6)LCAとの共有ピーク情報へ格納 */
				fn_cmn_shareMUSIC_set_finished_music_data_main( (U1)s4_a_flg_updn,
																(U1)as4_t_doa_num[s4_t_lp_i],
																(U2)as4_a_peak_bin[s4_t_lp_i],
																afl_t_selected_bins_intpl[s4_t_lp_i][0],
																afl_t_selected_doa_bins_intpl[s4_t_lp_i],
																afl_t_selected_doa_powers[s4_t_lp_i]);
			}

		} else {
			s4_t_doa_calc_num++;
			as4_t_doa_num[s4_t_lp_i] = (S4)au1_t_doa_num_copy[s4_t_lp_i];

			if (as4_t_doa_num[s4_t_lp_i] == (S4)1) {
				afl_t_selected_bins_intpl[s4_t_lp_i][0] = afl_t_selected_bins_intpl_copy[s4_t_lp_i];
				afl_t_selected_doa_bins_intpl[s4_t_lp_i][0] = afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i][0];
				afl_t_selected_doa_powers[s4_t_lp_i][0] = afl_t_selected_doa_powers_copy[s4_t_lp_i][0];
			} else if (as4_t_doa_num[s4_t_lp_i] == (S4)2) {
				afl_t_selected_bins_intpl[s4_t_lp_i][0] = afl_t_selected_bins_intpl_copy[s4_t_lp_i];
				afl_t_selected_bins_intpl[s4_t_lp_i][1] = afl_t_selected_bins_intpl_copy[s4_t_lp_i];
				afl_t_selected_doa_bins_intpl[s4_t_lp_i][0] = afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i][0];
				afl_t_selected_doa_bins_intpl[s4_t_lp_i][1] = afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i][1];
				afl_t_selected_doa_powers[s4_t_lp_i][0] = afl_t_selected_doa_powers_copy[s4_t_lp_i][0];
				afl_t_selected_doa_powers[s4_t_lp_i][1] = afl_t_selected_doa_powers_copy[s4_t_lp_i][1];
			} else {
				/* ここには来ない */
			}	
		}
	}

	*ps4_a_doa_peak_num = 0;
	/* (3) - 6) 方位推定結果の格納 */
	fn_bsm_ordinary_store_doa(
		(const FL *)afl_a_peak_power,

		(const S4 *)as4_t_doa_num,
		afl_t_selected_doa_bins_intpl,
		afl_t_selected_doa_powers,
		afl_t_selected_bins_intpl,

		ps4_a_doa_peak_num,
		afl_a_peak_bins_intpl,					/* [out] peak frequency */
		afl_a_peak_powers,						/* [out] peak afl_a_power */
		afl_a_peak_doa_bins_intpl,				/* [out] peak doa bin */
		afl_a_peak_doa_powers					/* [out] peak doa afl_a_power */
	);

	return;
}	


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_cal_doa									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3) - 2)～5) 方位推定										*/
/* 				: 2) MUSICによる角度スベクトラムの算出						*/
/* 				: 3) MUSIC角度スペクトラムのピークサーチ					*/
/* 				: 4) BFによる角度スペクトラムの算出（電力推定）				*/
/* 				: 5) 角度ピーク補間											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf 						*/
/*				: (3) - 2)～5) 方位推定										*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_cal_doa(
	S4 s4_a_updn_flg,										/*  [in] direction of beat-signal */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/*  [in] correlation matrix */

	S4 s4_a_peak_bin,										/*  [in] frequency of peak */
	FL fl_a_peak_bin_intpl,									/*  [in] interpolated frequency of peak */

	S4 *ps4_a_doa_num,										/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],					/* [out] */
	FL afl_a_selected_doa_powers[2],						/* [out] */
	FL afl_a_selected_bins_intpl[2]							/* [out] */
)
{
	S4 s4_t_lp_i;

	FL afl_t_spec[N_DOA];
	S4 s4_t_wall_bin;

	S4 as4_t_selected_doa_bins[2];
	S4 s4_t_temp_wave_num = WAVE_NUMBER;
	U1 u1_t_lp_doa_num;

	for (s4_t_lp_i = 0; s4_t_lp_i < N_DOA; s4_t_lp_i++ ) {
		afl_t_spec[s4_t_lp_i] = 0;
	}

	for (u1_t_lp_doa_num = (U1)0; u1_t_lp_doa_num < (U1)2; u1_t_lp_doa_num++) {
		as4_t_selected_doa_bins[u1_t_lp_doa_num] = (S4)0;
	}

	/***** ＤＯＡ推定 *****/
	if (st_g_bsm_loop_data.afl_wall_width[0] == WALL_MAX) {
		s4_t_wall_bin = -1;
	} else {
		s4_t_wall_bin = (S4)((st_g_bsm_loop_data.afl_wall_width[0] / RCOF) * 0.5F) + (NB_FFT_PT / 2) -1;
	}

	/***** 2) MUSICによる角度スペクトラムの算出 *****/
	s4_t_temp_wave_num = s4_calc_spec_music_4ch_all(
		afl_a_Ryy[s4_a_peak_bin],						/*  [in] */
		afl_t_spec,										/*  [out] */
		2,												/*  [in] */
		s4_a_updn_flg									/*  [in] */
	);
	*ps4_a_doa_num = 0;
	if (
		(s4_t_wall_bin != -1)										/* COND. f1 */
		 && ((S4)fl_abs((FL)(s4_a_peak_bin-s4_t_wall_bin)) == 0)	/* COND. f2 */
	) {
		*ps4_a_doa_num = s4_search_peak_music_ex_sidewall(
			(const FL *)afl_t_spec,							/*  [in] */
			afl_a_Ryy[s4_a_peak_bin],						/*  [in] */
			s4_a_peak_bin,									/*  [in] */
			s4_a_updn_flg,									/*  [in] */
			as4_t_selected_doa_bins,						/*  [out] [2] DOA of MUSIC peak */
			afl_a_selected_doa_powers,						/*  [out] [2] afl_a_power of MUSIC peak */
			s4_t_temp_wave_num
		);
	} else {
		*ps4_a_doa_num = s4_search_peak_music(
			(const FL *)afl_t_spec,							/*  [in] */
			as4_t_selected_doa_bins,						/*  [out] [2] DOA of MUSIC peak */
			afl_a_selected_doa_powers,						/*  [out] [2] afl_a_power of MUSIC peak */
			s4_t_temp_wave_num								/*  [in]		$$$ 2013.11.1 s4_t_wave_num(1) -> s4_t_temp_wave_num(推定到来波数) */
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_DOA_RANGE_T)
			,OBJECT_TYPE_ORDINARY							/*  [in] object type: ordinary object */
#endif
		);

		for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
			if (as4_t_selected_doa_bins[s4_t_lp_i] > 0) {
				afl_a_selected_doa_powers[s4_t_lp_i] = fl_calc_spec_bf_4ch_fm_of_specified_doa(
					afl_a_Ryy[s4_a_peak_bin],
					s4_a_updn_flg,
					s4_a_peak_bin,
					as4_t_selected_doa_bins[s4_t_lp_i]
				);
			}
		}
	}

	for(s4_t_lp_i=0; s4_t_lp_i<2; s4_t_lp_i++)
	{
		if(as4_t_selected_doa_bins[s4_t_lp_i]>0)
		{
			afl_a_selected_doa_bins_intpl[s4_t_lp_i] = fl_interpolate_music_peak(
				(const FL *)afl_t_spec,
				as4_t_selected_doa_bins[s4_t_lp_i],
				(const FL *)FL_BSM_FLSH_YOMIKAE_TBL_FM
			);
			afl_a_selected_bins_intpl[s4_t_lp_i] = fl_a_peak_bin_intpl;
		}
		else
		{
			afl_a_selected_doa_bins_intpl[s4_t_lp_i] = 0.0F;
			afl_a_selected_bins_intpl[s4_t_lp_i] = 0.0F;
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_store_doa									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3) - 6) 方位推定結果の格納								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (3) - 6) 方位推定結果の格納								*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_store_doa(
	const FL afl_a_peak_power[ORDINARY_BUFFSIZE],					/* [in] afl_a_power of peak */

	const S4 as4_a_doa_num[ORDINARY_BUFFSIZE],
	FL afl_a_selected_doa_bins_intpl[ORDINARY_BUFFSIZE][2],
	FL afl_a_selected_doa_powers[ORDINARY_BUFFSIZE][2],
	FL afl_a_selected_bins_intpl[ORDINARY_BUFFSIZE][2],

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[ORDINARY_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[ORDINARY_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[ORDINARY_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[ORDINARY_BUFFSIZE * 2]					/* [out] peak doa afl_a_power */
)
{
	S4 s4_t_iRet;

	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	/* ペアマッチ用の方位推定結果を格納 */
	s4_t_iRet = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < ORDINARY_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < as4_a_doa_num[s4_t_lp_i]; s4_t_lp_k++) {
			if( afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] > 0 ) {
				afl_a_peak_bins_intpl[s4_t_iRet]	 = afl_a_selected_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_a_peak_powers[s4_t_iRet]		 = afl_a_peak_power[s4_t_lp_i];
				afl_a_peak_doa_bins_intpl[s4_t_iRet] = afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_a_peak_doa_powers[s4_t_iRet]	 = afl_a_selected_doa_powers[s4_t_lp_i][s4_t_lp_k];
				s4_t_iRet++;
			}
		}
	}
	*ps4_a_doa_peak_num = s4_t_iRet;

}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_make_pair									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)～(9)ペアマッチ処理									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				:(4)～(9)ペアマッチ処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_make_pair(
	S4 s4_a_peak_num_up_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4*		   ps4_a_pair_num_ordinary,									/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]					/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;

	S4 as4_t_used_peak_up[ORDINARY_BUFFSIZE * 2];
	S4 as4_t_used_peak_dn[ORDINARY_BUFFSIZE * 2];
	S4 as4_t_pair_index_up[ORDINARY_BUFFSIZE * 2];
	S4 as4_t_pair_index_dn[ORDINARY_BUFFSIZE * 2];

	for (s4_t_lp_i = 0; s4_t_lp_i < (ORDINARY_BUFFSIZE * 2); s4_t_lp_i++) {
		as4_t_used_peak_up[s4_t_lp_i] = 0;
		as4_t_used_peak_dn[s4_t_lp_i] = 0;
		as4_t_pair_index_up[s4_t_lp_i] = 0;
		as4_t_pair_index_dn[s4_t_lp_i] = 0;
	}

	fn_bsm_ordinary_make_pair_sot(
		s4_a_peak_num_up_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_up,							/* [in] */
		(const FL *)afl_a_peak_powers_up,								/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_up,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_up,							/* [in] */

		s4_a_peak_num_dn_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_dn,							/* [in] */
		(const FL *)afl_a_peak_powers_dn,								/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_dn,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_dn,							/* [in] */

		as4_t_used_peak_up,												/* [out] */
		as4_t_used_peak_dn,												/* [out] */
		as4_t_pair_index_up,											/* [out] */
		as4_t_pair_index_dn,											/* [out] */

		ps4_a_pair_num_ordinary,										/* [out] */
		ast_a_normal_ordinary											/* [out] */
	);

	fn_bsm_ordinary_make_pair_stationary(
		s4_a_peak_num_up_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_up,							/* [in] */
		afl_a_peak_powers_up,											/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_up,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_up,							/* [in] */

		s4_a_peak_num_dn_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_dn,							/* [in] */
		afl_a_peak_powers_dn,											/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_dn,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_dn,							/* [in] */

		as4_t_used_peak_up,												/* [out] */
		as4_t_used_peak_dn,												/* [out] */

		*ps4_a_pair_num_ordinary										/* [in] */
	);

	fn_bsm_ordinary_make_pair_moving(
		s4_a_peak_num_up_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_up,							/* [in] */
		(const FL *)afl_a_peak_powers_up,								/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_up,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_up,							/* [in] */

		s4_a_peak_num_dn_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_dn,							/* [in] */
		(const FL *)afl_a_peak_powers_dn,								/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_dn,						/* [in] */
		(const FL *)afl_a_peak_doa_powers_dn,							/* [in] */

		as4_t_used_peak_up,												/* [out] */
		as4_t_used_peak_dn,												/* [out] */
		as4_t_pair_index_up,											/* [out] */
		as4_t_pair_index_dn,											/* [out] */

		ps4_a_pair_num_ordinary,										/* [out] */
		ast_a_normal_ordinary											/* [out] */
	);

	fn_bsm_ordinary_make_pair_outer(
		ps4_a_pair_num_ordinary,
		ast_a_normal_ordinary
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_make_pair_sot								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)低速SoTペアマッチ処理 & (5)物標情報算出処理(低速SoT)	*/
/*				:	前方から接近する移動物と推定される物標情報を求める。	*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (4)低速SoTペアマッチ処理 & (5)物標情報算出処理(低速SoT)	*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_make_pair_sot(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[ORDINARY_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	FL afl_t_compare[ORDINARY_BUFFSIZE * 2][ORDINARY_BUFFSIZE * 2];

	S4 s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;	/* $$$ 2013.08.07-3 */
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Rxobs;
	FL fl_t_tmp_theta_up;
	FL fl_t_tmp_theta_dn;

	S4 s4_t_found;
	FL fl_t_min_comp;
	S4 as4_t_tmp_pair_index_up = 0;
	S4 as4_t_tmp_pair_index_dn = 0;

	S4 s4_t_pair_num;
	S4 s4_t_tmp_pair_num;

	/* initialize comparsion param. */
	for (s4_t_lp_i = 0; s4_t_lp_i < (ORDINARY_BUFFSIZE * 2); s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < (ORDINARY_BUFFSIZE * 2); s4_t_lp_k++) {
			afl_t_compare[s4_t_lp_i][s4_t_lp_k] = 1000.0;
		}
	}

	s4_t_tmp_pair_num = 0;
	s4_t_pair_num = 0;

	/***** 1) 低速SoTペアマッチ処理 *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		fl_t_tmp_Rxobs = CFL_UNKNOWN_VALUE;
		if (as4_a_used_peak_up[s4_t_lp_i] == 0) {
			fl_t_tmp_theta_up = fl_transform_doabin_to_rad_float(
				afl_a_peak_doa_bins_intpl_up[s4_t_lp_i],
				0
			);
			for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
				if (as4_a_used_peak_dn[s4_t_lp_k] == 0) {
					/***** 1) 角度差の許容範囲の設定 *****/
					if (
						(afl_a_peak_bins_intpl_up[s4_t_lp_i] < (FL)((NB_FFT_PT / 2) + VERYNEAR_FREQ_BIN_LIMIT))
						 && (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)((NB_FFT_PT / 2) + VERYNEAR_FREQ_BIN_LIMIT))
					) {
						s4_t_tmp_doa_diff_up_down = (S4)CU1_DOA_DIFF_UP_DOWN_VERYNEAR;
					} else if (
						(afl_a_peak_bins_intpl_up[s4_t_lp_i] < (FL)((NB_FFT_PT / 2) + NEAR_FREQ_BIN_LIMIT))
						 && (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)((NB_FFT_PT / 2) + NEAR_FREQ_BIN_LIMIT))
					) {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN_NEAR;
					} else {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;
					}

					/***** 2) X方向距離の算出 *****/
					fl_t_tmp_Robs = - RCOF * (afl_a_peak_bins_intpl_up[s4_t_lp_i] + afl_a_peak_bins_intpl_dn[s4_t_lp_k] - (FL)NB_FFT_PT);
					fl_t_tmp_theta_dn = fl_transform_doabin_to_rad_float(
						afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k],
						1
					);
					fl_t_tmp_Rxobs = (fl_t_tmp_Robs * (FL)fl_sin(0.50F * (fl_t_tmp_theta_up + fl_t_tmp_theta_dn))) + st_g_bsm_loop_data.afl_installed_angle[1];
				} else {
					fl_t_tmp_Rxobs = CFL_UNKNOWN_VALUE;
				}

				/***** 3) 低速SoTペアマッチの作動条件の確認 *****/
				if (
					((fl_t_tmp_Rxobs != CFL_UNKNOWN_VALUE)										/* COND. f */
					&& (fl_t_tmp_Rxobs < (st_g_bsm_loop_data.afl_wall_width[0] - 3.0F)))
					&& (afl_a_peak_bins_intpl_up[s4_t_lp_i] > 259.0F)						/* COND. e1 */
					&& (afl_a_peak_bins_intpl_dn[s4_t_lp_k] > 259.0F)						/* COND. e2 */
					&& (afl_a_peak_bins_intpl_up[s4_t_lp_i] < 266.0F)						/* COND. e3 */
					&& (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < 266.0F)						/* COND. e4 */
					&& (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN)							/* COND. d1 */
					&& ((S4)fl_abs((FL)s2_g_curvr_for_base ) > (S4)CU1_CANOUT_CURVER_MIN_SOT)		/* COND. d2 */
				) {
					/***** 4) 低速SoTペアマッチの評価値の算出 *****/
					/* ① SoT interval */
					if (
						(st_g_bsm_loop_data.afl_wall_width[0] > 5.0F)			/* COND. g1 */
						 && (st_g_bsm_loop_data.as4_slow_sot_find[0] > 0)		/* COND. h1 */
					) {
						if (
							(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] > (FL)CS4_SLOW_SOT_DOA_LOWER_LIMIT)		/* COND. i1 */
							 && (afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k] > (FL)CS4_SLOW_SOT_DOA_LOWER_LIMIT)	/* COND. i2 */
						) {
							if (
								(fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < POW_DIFF_UP_DOWN_DOA)							/* COND. j1 */
								 && (fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]) < (FL)s4_t_tmp_doa_diff_up_down)		/* COND. j2 */
							) {
								afl_t_compare[s4_t_lp_i][s4_t_lp_k] = ( 8.0F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))
																	  + 1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]));
							}
						}
					/* ② immature wall */
					} else if (
						(st_g_bsm_loop_data.afl_wall_width[0] <= 4.0F)				/* COND. g2 */
					 && (st_g_bsm_loop_data.as4_slow_sot_find[0] > 0)				/* COND. h1 */
					 && (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH1)	/* COND. g3 */
					) {
						if (
							(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] > ((FL)N_DOA - st_g_bsm_loop_data.afl_installed_angle[0] + (FL)SLOW_SOT_DOA_TH1))	/* COND. i3 */
						 && (afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k] > ((FL)N_DOA - st_g_bsm_loop_data.afl_installed_angle[0] + (FL)SLOW_SOT_DOA_TH1))	/* COND. i4 */
						) {
							if (
								(fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < POW_DIFF_UP_DOWN_DOA)							/* COND. j1 */
							 && (fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]) < (FL)s4_t_tmp_doa_diff_up_down)	/* COND. j2 */
							) {
								afl_t_compare[s4_t_lp_i][s4_t_lp_k] = (8.0F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))
																	+ (1.0F * fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]));
							}
						}
					/* ③ probably SoT */
					} else {
						if (
							(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] > ((FL)N_DOA - st_g_bsm_loop_data.afl_installed_angle[0] + (FL)SLOW_SOT_DOA_TH2))	/* COND. i5 */
						 && (afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k] > ((FL)N_DOA - st_g_bsm_loop_data.afl_installed_angle[0] + (FL)SLOW_SOT_DOA_TH2))	/* COND. i6 */
						 && (afl_a_peak_doa_powers_up[s4_t_lp_i] > SLOW_SOT_DOA_POW_TH)																	/* COND. i7 */
						 && (afl_a_peak_doa_powers_dn[s4_t_lp_k] > SLOW_SOT_DOA_POW_TH)																	/* COND. i8 */
						) {
							if (
								(fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < POW_DIFF_UP_DOWN_DOA)
							&& (fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]) < (FL)s4_t_tmp_doa_diff_up_down)
							&& ((afl_a_peak_bins_intpl_dn[s4_t_lp_k] - afl_a_peak_bins_intpl_up[s4_t_lp_i]) > 0.0F )
							&& ((afl_a_peak_bins_intpl_dn[s4_t_lp_k] - afl_a_peak_bins_intpl_up[s4_t_lp_i]) < 3.0F )
							) {
								afl_t_compare[s4_t_lp_i][s4_t_lp_k] = (8.0F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))
																	+ (1.0F * fl_abs(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k]));
							}
						}
					}
				}
			}
		}
	}

	/***** 5) ペアマッチ評価値が最小となる上り／下りのピークペアを求める *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		fl_t_min_comp = 1000.0;
		s4_t_found = 0;
		for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
			if (
				(afl_t_compare[s4_t_lp_i][s4_t_lp_k] < fl_t_min_comp)	/* COND. k1 */
			 && (as4_a_used_peak_up[s4_t_lp_i] == 0)					/* COND. k2 */
			 && (as4_a_used_peak_dn[s4_t_lp_k] == 0)					/* COND. k3 */
			) {
				fl_t_min_comp = afl_t_compare[s4_t_lp_i][s4_t_lp_k];
				s4_t_found = 1;
				as4_t_tmp_pair_index_up = s4_t_lp_i;
				as4_t_tmp_pair_index_dn = s4_t_lp_k;
			}
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
			fn_bsm_ordinary_check_minimum_pair(s4_t_lp_i,
											   s4_t_lp_k,
											   afl_t_compare,
											   as4_a_used_peak_up,
											   as4_a_used_peak_dn,
											   as4_a_pair_index_up,
											   as4_a_pair_index_dn,
											   &fl_t_min_comp,
											   &s4_t_found,
											   &as4_t_tmp_pair_index_up,
											   &as4_t_tmp_pair_index_dn,
											   &s4_t_pair_num);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		}
		/* set output data */
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
		if (
			(s4_t_found == 1) 									/* COND. k4 */
		&& ((s4_t_pair_num) < ((ORDINARY_BUFFSIZE * 2) - 1)))	/* COND. k5 */			/* 不具合ではないか？ */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
		if (s4_t_found == 1) 									/* COND. k4 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		{
			as4_a_used_peak_up[as4_t_tmp_pair_index_up] = 1;
			as4_a_used_peak_dn[as4_t_tmp_pair_index_dn] = 1;
			as4_a_pair_index_up[s4_t_pair_num] = as4_t_tmp_pair_index_up;
			as4_a_pair_index_dn[s4_t_pair_num] = as4_t_tmp_pair_index_dn;
			s4_t_pair_num++;
		}
	}

/****************************************************************************/
/* (5)	物標情報算出処理（低速SoT）											*/
/****************************************************************************/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_pair_num; s4_t_lp_i++) {
		if (s4_t_lp_i < ORDINARY_BUFFSIZE) {
			fl_t_tmp_theta_up = fl_transform_doabin_to_rad_float(
				afl_a_peak_doa_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],
				0
			);
			fl_t_tmp_theta_dn = fl_transform_doabin_to_rad_float(
				afl_a_peak_doa_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],
				1
			);
			fl_t_tmp_Robs = -RCOF * ((afl_a_peak_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]] + afl_a_peak_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]]) - NB_FFT_PT);
			fl_t_tmp_Rxobs = (fl_t_tmp_Robs * (FL)fl_sin(0.50F * (fl_t_tmp_theta_up + fl_t_tmp_theta_dn))) + st_g_bsm_loop_data.afl_installed_angle[1];
			if (fl_abs(fl_t_tmp_Rxobs - st_g_bsm_loop_data.afl_wall_width[0]) > 0.8F) {
				/***** 1) X方向距離の算出 *****/
				fn_set_normal_data(
					&ast_a_normal_ordinary[s4_t_lp_i],
					afl_a_peak_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak freq-bin (up) */
					afl_a_peak_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak freq-bin (down) */
					afl_a_peak_doa_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],	/*  peak doa-bin (up) */
					afl_a_peak_doa_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],	/*  peak doa-bin (down) */
					afl_a_peak_powers_up[as4_a_pair_index_up[s4_t_lp_i]],			/*  peak freq-power (up) */
					afl_a_peak_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],			/*  peak freq-power (down) */
					afl_a_peak_doa_powers_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak doa-power (up)  */
					afl_a_peak_doa_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak doa-power (down)  */
					1,																/*  stationary object flag */
					0																/*  single peak flag */
				);
				s4_t_tmp_pair_num++;
			} else {
				if (st_g_bsm_loop_data.as4_slow_sot_find[0] > 0) {
					st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;
					st_g_bsm_loop_data.as4_flg_leading[0] = 0;
				}
			}
		}
	}
	*ps4_a_pair_num = s4_t_tmp_pair_num;

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_make_pair_stationary						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)停止物ペアマッチ処理									*/
/*				:   ピークサーチ処理で得られた上り／下り信号のピークbin，	*/
/*				:   ピーク電力，および，方向推定処理で得られた各ピークbin 	*/
/*				:   における推定方向から反射波の上り／下り信号のピークの	*/
/*				:   ペアリングを行い，自車速度情報を用いて停止物と推定される*/
/*				:   物標情報を求める．										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (6)停止物ペアマッチ処理									*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_make_pair_stationary(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],

	S4 s4_a_pair_num
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	FL afl_t_compare[ORDINARY_BUFFSIZE * 2][ORDINARY_BUFFSIZE * 2];

	S4 s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;	/* $$$ 2013.08.07-3 */
	S4 s4_t_shift;

	S4 s4_t_found;
	FL fl_t_min_comp;
	S4 as4_t_tmp_pair_index_up = 0;
	S4 as4_t_tmp_pair_index_dn = 0;
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
	S4 s4_t_pair_num_dummy;										/* ペア個数 共通関数を使用するためのダミー変数 */
	S4 as4_t_pair_index_up_dummy[ORDINARY_BUFFSIZE * 2];		/* 上りペアインデックス 共通関数を使用するためのダミー変数 */
	S4 as4_t_pair_index_dn_dummy[ORDINARY_BUFFSIZE * 2];		/* 下りペアインデックス 共通関数を使用するためのダミー変数 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */

/****************************************************************************/
/* (6)	停止物ペアマッチ処理												*/
/****************************************************************************/
	/***** 1) 自車速相当の上り／下りの周波数bin差を算出 *****/
	s4_t_shift = (S4)(fl_g_v_self_bsm_for_base / 3.60F / VCOF + 0.50F);

	/* initialize comparsion param. */
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
	s4_t_pair_num_dummy = (S4)0;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */

	for (s4_t_lp_i = 0; s4_t_lp_i < (ORDINARY_BUFFSIZE * 2); s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < (ORDINARY_BUFFSIZE * 2); s4_t_lp_k++) {
			afl_t_compare[s4_t_lp_i][s4_t_lp_k] = 1000.0;
		}
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
		as4_t_pair_index_up_dummy[s4_t_lp_i] = (S4)0;
		as4_t_pair_index_dn_dummy[s4_t_lp_i] = (S4)0;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
	}

	/***** 2) 上り／下りのピークのペアマッチ評価値を算出 *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {	/*  UPは大きいほうから(速く遠ざかるものから探していく) */
		if (as4_a_used_peak_up[s4_a_peak_num_up - 1 - s4_t_lp_i] == 0) {												/* COND. a1 */
			if (afl_a_peak_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] > (FL)((NB_FFT_PT / 2) + s4_t_shift)) {		/* COND. a2 */
				for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
					if (
						(as4_a_used_peak_dn[s4_t_lp_k] == 0)																												/* COND. a3 */
					 && ((afl_a_peak_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_bins_intpl_dn[s4_t_lp_k]) > (FL)(s4_t_shift - (S4)(5.0F/3.6F/VCOF) + 1) )	/* COND. a4 +5[km/h](was 10*VCOF=2.02261[m/s]=7.28[km/s]) */
					) {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;
						if (
							(fl_abs(afl_a_peak_doa_powers_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < POW_DIFF_UP_DOWN_DOA)				/*  COND. a5 */
						&& ((S4)fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])) < s4_t_tmp_doa_diff_up_down)	/* COND. a6 */
						) {
							/* 0.5F:重み付け */
							afl_t_compare[s4_a_peak_num_up - 1 - s4_t_lp_i][s4_t_lp_k]
									= (0.5F * fl_abs(afl_a_peak_doa_powers_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))							/* DOA pow.	0.5F: weighting factor */
									+ (1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])))			/* DOA */
									+ (1.0F * fl_abs((FL)(afl_a_peak_bins_intpl_up[s4_a_peak_num_up - 1 - s4_t_lp_i] - afl_a_peak_bins_intpl_dn[s4_t_lp_k] - (FL)s4_t_shift)));	/* FREQ */
						}
					}	
				}
			}
		}
	}

	/***** 3) ペアマッチ評価値が最小となる上り／下りのピークペアを求める *****/
	/*  SoT:[0]～[s4_t_tmp_pair_num-1] */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		fl_t_min_comp = 1000.0;
		s4_t_found = 0;
		for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
			if ((afl_t_compare[s4_a_peak_num_up - 1 - s4_t_lp_i][s4_t_lp_k] < fl_t_min_comp)	/* COND. b1 */
				 && (as4_a_used_peak_up[s4_a_peak_num_up - 1 - s4_t_lp_i] == 0)					/* COND. b2 */
				 && (as4_a_used_peak_dn[s4_t_lp_k] == 0)										/* COND. b3 */
			) {
				fl_t_min_comp = afl_t_compare[s4_a_peak_num_up - 1 - s4_t_lp_i][s4_t_lp_k];
				s4_t_found = 1;
				as4_t_tmp_pair_index_up = s4_a_peak_num_up - 1 - s4_t_lp_i;
				as4_t_tmp_pair_index_dn = s4_t_lp_k;
			}
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
			fn_bsm_ordinary_check_minimum_pair(s4_a_peak_num_up - (S4)1 - s4_t_lp_i,
											   s4_t_lp_k,
											   afl_t_compare,
											   as4_a_used_peak_up,
											   as4_a_used_peak_dn,
											   as4_t_pair_index_up_dummy,		/* 共通関数を使用するためのダミー変数 */
											   as4_t_pair_index_dn_dummy,		/* 共通関数を使用するためのダミー変数 */
											   &fl_t_min_comp,
											   &s4_t_found,
											   &as4_t_tmp_pair_index_up,
											   &as4_t_tmp_pair_index_dn,
											   &s4_t_pair_num_dummy);			/* 共通関数を使用するためのダミー変数 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		}
		
		/*  出力データをセット */
		if (s4_t_found == 1) {									/* COND. b4 */
			as4_a_used_peak_up[as4_t_tmp_pair_index_up] = 1;
			as4_a_used_peak_dn[as4_t_tmp_pair_index_dn] = 1;
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
			/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
			as4_t_pair_index_up_dummy[s4_t_pair_num_dummy] = as4_t_tmp_pair_index_up;
			as4_t_pair_index_dn_dummy[s4_t_pair_num_dummy] = as4_t_tmp_pair_index_dn;
			s4_t_pair_num_dummy++;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_make_pair_moving							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)移動物ペアマッチ処理 & (8)物標情報算出					*/
/*				: (7)ピークサーチ処理で得られた上り／下り信号のピークbin，	*/
/*				:	ピーク電力，および，方向推定処理で得られた各ピークbin 	*/
/*				:	における推定方向から反射波の上り／下り信号のピークの	*/
/*				:	ペアリングを行い，移動物と推定される物標情報を求める．	*/
/*				: (8)ペアマッチ処理により得られた上／下のピーク情報に基づき	*/
/*				:	物標位置・速度情報を算出する。							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (7)移動物ペアマッチ処理 & (8)物標情報算出					*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_make_pair_moving(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_up[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_up[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */
	const FL afl_a_peak_powers_dn[ORDINARY_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[ORDINARY_BUFFSIZE * 2],		/* [in] */
	const FL afl_a_peak_doa_powers_dn[ORDINARY_BUFFSIZE * 2],			/* [in] */

	S4 as4_a_used_peak_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[ORDINARY_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[ORDINARY_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	FL afl_t_compare[ORDINARY_BUFFSIZE * 2][ORDINARY_BUFFSIZE * 2];
	S4 s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;	/* $$$ 2013.08.07-3 */
	FL fl_t_tmp_pow_diff_up_down;
	U2 u2_t_tmp_freq_diff_up_down;

	S4 s4_t_found;
	FL fl_t_min_comp;
	S4 as4_t_tmp_pair_index_up = 0;
	S4 as4_t_tmp_pair_index_dn = 0;

	S4 s4_t_pair_num;
	S4 s4_t_tmp_pair_num;

	fl_t_tmp_pow_diff_up_down = POW_DIFF_UP_DOWN_DOA;
	u2_t_tmp_freq_diff_up_down = NB_FFT_PT;

/****************************************************************************/
/* (7)	移動物ペアマッチ処理												*/
/****************************************************************************/
	/* initialize comparsion param. */
	for (s4_t_lp_i = 0; s4_t_lp_i < (ORDINARY_BUFFSIZE * 2); s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < (ORDINARY_BUFFSIZE * 2); s4_t_lp_k++) {
			afl_t_compare[s4_t_lp_i][s4_t_lp_k] = 1000.0;
		}
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		if (as4_a_used_peak_up[s4_t_lp_i] == 0) {								/* COND a1/c1 */
			for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
				if (as4_a_used_peak_dn[s4_t_lp_k] == 0) {						/* COND a2/c2 */
					/***** 1) 角度差の許容範囲の設定 *****/
					if (
						(afl_a_peak_bins_intpl_up[s4_t_lp_i] < (FL)((NB_FFT_PT / 2) + VERYNEAR_FREQ_BIN_LIMIT))			/* COND. b1 */
					 && (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)((NB_FFT_PT / 2) + VERYNEAR_FREQ_BIN_LIMIT))			/* COND. b2 */
					) {
						s4_t_tmp_doa_diff_up_down = (S4)CU1_DOA_DIFF_UP_DOWN_VERYNEAR;
					} else if (
						(afl_a_peak_bins_intpl_up[s4_t_lp_i] < (FL)((NB_FFT_PT / 2) + NEAR_FREQ_BIN_LIMIT))				/* COND. c1 */
					 && (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)((NB_FFT_PT / 2) + NEAR_FREQ_BIN_LIMIT))				/* COND. c2 */
					) {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN_NEAR;
					} else {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;
					}

					if ((fl_g_v_self_bsm_for_base < CANOUT_VSELF_SLOW)										/* self slow COND. e */
					&&  ((afl_a_peak_doa_powers_up[s4_t_lp_i] < PEAK_POW_TH_FOR_DOA_TH)						/* vanishing COND. f */
					||   (afl_a_peak_doa_powers_dn[s4_t_lp_k] < PEAK_POW_TH_FOR_DOA_TH))) {
						s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN_SLOW;
					}

					/***** 2) 移動物ペアマッチの評価値の算出 *****/
					if ((st_g_bsm_loop_data.as4_slow_sot_find[0] != (S4)0)									/* COND. g1 */
					&&  (afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)(NB_FFT_PT / (S4)2 + (S4)9))) {			/* COND. g2 */
						s4_t_tmp_doa_diff_up_down = (S4)3;															/* PROC.1 */
						fl_t_tmp_pow_diff_up_down = (FL)2.0F;														/* PROC.2 */
						u2_t_tmp_freq_diff_up_down = u2_cast_from_fl((FL)15.0F / (FL)3.6F / (FL)RCOF / (FL)2.0F);	/* PROC.3 */
					} else {
						fl_t_tmp_pow_diff_up_down = POW_DIFF_UP_DOWN_DOA;											/* PROC.4 */
						u2_t_tmp_freq_diff_up_down = NB_FFT_PT;														/* PROC.5 */
					}
					
					if (fl_g_v_self_bsm_for_base < (FL)20.0F) {												/* COND. g3 */
						fl_t_tmp_pow_diff_up_down = (FL)3.0F;												/* PROC.6 */
					}
					
					if ((fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < fl_t_tmp_pow_diff_up_down)							/*  COND. c3 */
					&&  ((S4)fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])) < s4_t_tmp_doa_diff_up_down)		/*  COND. c4 */
					&&  ((afl_a_peak_bins_intpl_up[s4_t_lp_i] - afl_a_peak_bins_intpl_dn[s4_t_lp_k]) < (FL)u2_t_tmp_freq_diff_up_down)) {						/*  COND. c5 */
						afl_t_compare[s4_t_lp_i][s4_t_lp_k] = (0.5F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))				/* DOA pow. 0.5F: weighting factor */
															+ (1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])))	/* DOA */
															+ (0.5F * fl_abs(afl_a_peak_powers_up[s4_t_lp_i] - afl_a_peak_powers_dn[s4_t_lp_k]));						/* FREQ  0.5F: weighting factor */
					}
				}
			}
		}
	}

	/***** 3) ペアマッチ評価値が最小となる上り／下りのピークペアを求める *****/
	s4_t_pair_num = *ps4_a_pair_num;
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		fl_t_min_comp = 1000.0;
		s4_t_found = 0;
		for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
			if ((afl_t_compare[s4_t_lp_i][s4_t_lp_k] < fl_t_min_comp)			/* COND. d1 */
			 && (as4_a_used_peak_up[s4_t_lp_i] == 0)							/* COND. d2 */
			 && (as4_a_used_peak_dn[s4_t_lp_k] == 0)							/* COND. d3 */
			) {
				fl_t_min_comp = afl_t_compare[s4_t_lp_i][s4_t_lp_k];
				s4_t_found = 1;
				as4_t_tmp_pair_index_up = s4_t_lp_i;
				as4_t_tmp_pair_index_dn = s4_t_lp_k;
			}
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
			fn_bsm_ordinary_check_minimum_pair(s4_t_lp_i,
											   s4_t_lp_k,
											   afl_t_compare,
											   as4_a_used_peak_up,
											   as4_a_used_peak_dn,
											   as4_a_pair_index_up,
											   as4_a_pair_index_dn,
											   &fl_t_min_comp,
											   &s4_t_found,
											   &as4_t_tmp_pair_index_up,
											   &as4_t_tmp_pair_index_dn,
											   &s4_t_pair_num);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		}
		
		/*  出力データをセット */
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
		if (
			(s4_t_found == 1)									/* COND. d4 */
		&& ((s4_t_pair_num) < ((ORDINARY_BUFFSIZE * (S4)2) - (S4)1)))	/* for cheking buffer overflow */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
		if (s4_t_found == 1)									/* COND. d4 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */
		{
			as4_a_used_peak_up[as4_t_tmp_pair_index_up] = 1;
			as4_a_used_peak_dn[as4_t_tmp_pair_index_dn] = 1;
			as4_a_pair_index_up[s4_t_pair_num] = as4_t_tmp_pair_index_up;
			as4_a_pair_index_dn[s4_t_pair_num] = as4_t_tmp_pair_index_dn;
			s4_t_pair_num++;
		}
	}

	/*  物標情報算出 */
	/*  SoT&停止物:[0]～[s4_t_tmp_pair_num-1] */
	s4_t_tmp_pair_num = *ps4_a_pair_num;
	for (s4_t_lp_i = s4_t_tmp_pair_num; s4_t_lp_i < s4_t_pair_num; s4_t_lp_i++) {
		if ((s4_t_lp_i) < ORDINARY_BUFFSIZE) {	/* $$$ バッファあふれ防止(30 -> 15なのでちゃんと優先順位をつけたほうがよい) */
			fn_set_normal_data(
				&ast_a_normal_ordinary[s4_t_lp_i],
				afl_a_peak_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak freq-bin (up) */
				afl_a_peak_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak freq-bin (down) */
				afl_a_peak_doa_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],	/*  peak doa-bin (up) */
				afl_a_peak_doa_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],	/*  peak doa-bin (down) */
				afl_a_peak_powers_up[as4_a_pair_index_up[s4_t_lp_i]],			/*  peak freq-power (up) */
				afl_a_peak_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],			/*  peak freq-power (down) */
				afl_a_peak_doa_powers_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak doa-power (up) */
				afl_a_peak_doa_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak doa-power (down) */
				0,																/*  停止物フラグ */
				0																/*  片ピークフラグ */
			);
		}
	}
	*ps4_a_pair_num = s4_t_pair_num;

	/* 後段の処理で配列外参照が発生しないように、ORDINARY_BUFFSIZEで上限ガードをかける */
	if (*ps4_a_pair_num > ORDINARY_BUFFSIZE) {
		*ps4_a_pair_num = ORDINARY_BUFFSIZE;
	}
	
	return;
}

#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degでは関数定義なし */
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_check_minimum_pair						*/
/*--------------------------------------------------------------------------*/
/* 機能			: ペアマッチ評価値が最小となる上り／下りのピークペアを求める*/
/*--------------------------------------------------------------------------*/
/* 引数			: s4_a_lp_peak_num_up	: 上りピークループ変数(仕様書のi)[in]*/
/*				: s4_a_lp_peak_num_dn	: 下りピークループ変数(仕様書のj)[in]*/
/*				: afl_a_compare[][]		: ペアマッチ評価値			[in]	*/
/*				: as4_a_used_peak_up[]	: 上りピーク使用済みフラグ	[in/out]*/
/*				: as4_a_used_peak_dn[]	: 下りピーク使用済みフラグ	[in/out]*/
/*				: as4_a_pair_index_up[]	: 上りペアインデックス配列	[in/out]*/
/*				: as4_a_pair_index_dn[]	: 下りペアインデックス配列	[in/out]*/
/*				: pfl_a_min_comp		: ペアマッチ評価値の最小値	[out]	*/
/*				: ps4_a_found			: ペア検出フラグ			[out]	*/
/*				: ps4_a_pair_index_up	: 上りペアインデックス		[out]	*/
/*				: ps4_a_pair_index_dn	: 下りペアインデックス		[out]	*/
/*				: ps4_a_pair_num		: ペア個数					[in/out]*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-017								*/
/*				: (4)低速SoTペアマッチ処理 (6)停止物ペアマッチ処理			*/
/*				: (7)移動物ペアマッチ処理それぞれの							*/
/*				: ペアマッチ評価値が最小となる上り／下りのピークペアを求める*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
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
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_make_pair_outer							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (9)道路外物標除去処理										*/
/*				:	算出した物標情報から、道路の外側に位置する物標を除外する*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (9)道路外物標除去処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_ordinary_make_pair_outer(
	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	FL afl_t_Rx_right[70];
	S4 s4_t_Ry_int = 0;
	FL fl_t_wall_th;

	/***** 1) 壁外判定の距離閾値の設定 *****/
	/* DIST0  +												*/
	/* DIST1  |		  + 									*/
	/* DIST2  |		  |		  +								*/
	/* DIST3  |		  |		  |		  +						*/
	/* 0m	  |		  |		  |		  |		  +++++++		*/
	/*		SPEED0	SPEED1	SPEED2	SPEED3	SPEED4			*/

	if (fl_g_v_self_bsm_for_base > SLOW_WALL_SPEED4) {
		fl_t_wall_th = SLOW_WALL_DIST4;
	} else if (fl_g_v_self_bsm_for_base > SLOW_WALL_SPEED3) {
		fl_t_wall_th = (((SLOW_WALL_DIST4 - SLOW_WALL_DIST3) / (SLOW_WALL_SPEED4 - SLOW_WALL_SPEED3)) * (fl_g_v_self_bsm_for_base - SLOW_WALL_SPEED3)) + SLOW_WALL_DIST3;
	} else if (fl_g_v_self_bsm_for_base > SLOW_WALL_SPEED2) {
		fl_t_wall_th = (((SLOW_WALL_DIST3 - SLOW_WALL_DIST2) / (SLOW_WALL_SPEED3 - SLOW_WALL_SPEED2)) * (fl_g_v_self_bsm_for_base - SLOW_WALL_SPEED2)) + SLOW_WALL_DIST2;
	} else if (fl_g_v_self_bsm_for_base > SLOW_WALL_SPEED1) {
		fl_t_wall_th = (((SLOW_WALL_DIST2 - SLOW_WALL_DIST1) / (SLOW_WALL_SPEED2 - SLOW_WALL_SPEED1)) * (fl_g_v_self_bsm_for_base - SLOW_WALL_SPEED1)) + SLOW_WALL_DIST1;
	} else {
		fl_t_wall_th = (((SLOW_WALL_DIST1 - SLOW_WALL_DIST0) / (SLOW_WALL_SPEED1 - SLOW_WALL_SPEED0)) * (fl_g_v_self_bsm_for_base - SLOW_WALL_SPEED0)) + SLOW_WALL_DIST0;
	}

	/***** 2) 道路形状の算出 *****/
	fn_estimate_road_shape(
		afl_t_Rx_right							/*  [out] */
	);

	for (s4_t_lp_i = 0; s4_t_lp_i < *ps4_a_pair_num; s4_t_lp_i++) {
		if (ast_a_normal_ordinary[s4_t_lp_i].fl_Ryobs < 0.0F) {
			s4_t_Ry_int = (S4)(-ast_a_normal_ordinary[s4_t_lp_i].fl_Ryobs);
		} else {
			s4_t_Ry_int = 0;
		}

		if (s4_t_Ry_int >= 70 ) {				/* 不具合 */
			s4_t_Ry_int = 69;
		}

		if (s4_t_lp_i < ORDINARY_BUFFSIZE) {
			if (
				(ast_a_normal_ordinary[s4_t_lp_i].fl_Ryobs < -EKF_RY_SIDE)											/* COND. b */
			 && ((ast_a_normal_ordinary[s4_t_lp_i].fl_Rxobs - afl_t_Rx_right[s4_t_Ry_int]) > fl_t_wall_th)			/* COND. c */
			) {
				fn_init(&ast_a_normal_ordinary[s4_t_lp_i], 1);
			}
		}
	}

	*ps4_a_pair_num = s4_trim_ordinary(ast_a_normal_ordinary);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_compare_with_2FCW							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (10)2FCW比較・除去処理									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (10)2FCW比較・除去処理									*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static VD fn_bsm_ordinary_compare_with_2FCW(
	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_erase_flg = 0;
	S4 s4_t_2f_bin;
	S4 s4_t_wave_num = 0;
	S4 s4_t_peak_num = 0;
	FL afl_t_doa_spec[N_DOA];
	S4 as4_t_doa[2];
	FL afl_t_power_music[2];
	U1 u1_t_lp_n_doa;

	/* ローカル変数初期化 */
	for (u1_t_lp_n_doa = (U1)0; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		afl_t_doa_spec[u1_t_lp_n_doa] = (FL)0.0F;
	}
	as4_t_doa[0] = (S4)-1;
	as4_t_doa[1] = (S4)-1;
	afl_t_power_music[0] = (FL)0.0F;
	afl_t_power_music[1] = (FL)0.0F;

	for(s4_t_lp_i=0; s4_t_lp_i<*ps4_a_pair_num; s4_t_lp_i++)
	{
		if (ast_a_normal_ordinary[s4_t_lp_i].fl_Ryobs < -15.0F) {	/* check only far object */
			s4_t_erase_flg = 0;
			s4_t_peak_num = 0;
			s4_t_2f_bin =  NB_FFT_PT_2F/2 + (S4)(ast_a_normal_ordinary[s4_t_lp_i].fl_Vobs/VCOF_2F);
			if (((s4_t_2f_bin > 0)
			&&   (s4_t_2f_bin < (NB_FFT_PT_2F / 2 - CENTER_FREQ_RANGE_2F)))
			||  ((s4_t_2f_bin > (NB_FFT_PT_2F / 2 + CENTER_FREQ_RANGE_2F))
			&&   (s4_t_2f_bin < NB_FFT_PT_2F))) {
				s4_t_wave_num = s4_calc_spec_music_4ch_all(
					(const FL *)(afl_g_cvw_fcw_ryy_matrix[s4_t_2f_bin]),		/* [in] */
					afl_t_doa_spec,												/* [out] */
					2,															/* [in] */
					1															/* [in] */
				);
				s4_t_peak_num = s4_peak_search_music_fsk(
					(const FL *)afl_t_doa_spec,
					as4_t_doa,
					afl_t_power_music,
					s4_t_wave_num
				);
				if(s4_t_peak_num!=0)
				{
					for(s4_t_lp_k=0; s4_t_lp_k<s4_t_peak_num; s4_t_lp_k++)
					{
						if ((s4_abs(as4_t_doa[s4_t_lp_k] - ast_a_normal_ordinary[s4_t_lp_i].s4_bin_up_music) > (S4)CU1_DOA_DIFF_FM_2F)
						||  (s4_abs(as4_t_doa[s4_t_lp_k] - ast_a_normal_ordinary[s4_t_lp_i].s4_bin_dn_music) > (S4)CU1_DOA_DIFF_FM_2F)) {
							s4_t_erase_flg = 1;
						}
					}
				}
				/* erase */
				if( s4_t_erase_flg==1 )
				{
					fn_init(&ast_a_normal_ordinary[s4_t_lp_i], 1);
				}
			}
		}
	}

	*ps4_a_pair_num = s4_trim_ordinary(ast_a_normal_ordinary);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_ordinary_set_object								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (11)出力データ保存										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-013.pdf							*/
/*				: (11)出力データ保存										*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_ordinary_set_object(
	const S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;

	/* set object type */
	for (s4_t_lp_i = 0; s4_t_lp_i < *ps4_a_pair_num; s4_t_lp_i++) {
		ast_a_normal_ordinary[s4_t_lp_i].s4_flg_dc = OBJECT_TYPE_ORDINARY;
	}

	return;
}

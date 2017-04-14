/****************************************************************************/
/* ファイル名	: BSM_RECOG_04.c											*/
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
/*	t04					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM QAC対応(OBJ変更なし)												*/
/*	t05					15.05.26			走安技2 1技室 G.Jomori			*/
/*	残課題No492対応															*/
/*	t06					15.05.26			走安技2 1技室 G.Jomori			*/
/*	残課題No492対応(OBJ変更なし)											*/
/*	t08					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t09					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t10					15.10.23			走安技2 1技室 M.Tanaka			*/
/*	残課題No.849対応(暗黙のキャストを修正)									*/
/*	t11					15.10.27			走安技2 1技室 Y.Nishioka		*/
/*	関数ヘッダの追加 ※OBJ変更なし											*/
/*	t12					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t13					15.11.25			走安技2 1技室 G.Jomori			*/
/*	仕様確認No.1799対応														*/
/*	t14					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1194,1198対応(ローカル配列変数の宣言と同時に実施の初期化分離)	*/
/*	t15					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1109,1091,1092対応(渡す引数の修正、変数初期化処理追加)			*/
/*	t16					16.03.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様対応														*/
/*	t17					16.03.28			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 机上セルフ対応(OBJ変更なし)								*/
/*	t18					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応(OBJ変更なし)						*/
/*	t19					16.04.12			走安技2 1技室 K.Hanabata		*/
/*	QAC指摘修正																*/
/*	t20					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t21					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t22					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t23					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM 残課題No1336対応 OBJ変更なし										*/
/*	t24					16.06.21			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t25					16.06.22			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t28					16.08.10			走安技2 1技室 Y.Nishioka		*/
/*	関数名変更(shareMUSIC_を追加) ※オブジェクト変更なし					*/
/*	p01					16.09.08			走安技2 1技室 G.Jomori			*/
/*	010B 2A リリース用														*/
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
#include "func_fmcw.h"
#include "func_fsk.h"
#include "../../common/cmn_shareMUSIC_mwr.h"

#include "bsm_recog_04.h"

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
VD fn_bsm_2f_init_data(
	S4 *ps4_a_peak_num_2f,
	S4 as4_a_peak_bin_2f[AUX_BUFFSIZE],
	FL afl_a_peak_power_2f[AUX_BUFFSIZE],
	FL afl_a_thres_2f[NB_FFT_PT_2F],

	S4 *ps4_a_peak_num_2f_doa,
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]
);

S4 s4_search_freq_peak_fsk_IQ(
	const FL afl_a_power_2f[NB_FFT_PT_2F],	/* [in] */
	S4 as4_a_bin_2f[AUX_BUFFSIZE],			/* [out] */
	FL afl_a_bin_power_2f[AUX_BUFFSIZE],	/* [out] */
	const FL afl_a_thres_2f[NB_FFT_PT_2F]	/* [in] */
);

S4 s4_search_freq_peak_fsk(
	const FL afl_a_power_2f[NB_FFT_PT_2F],	/* [in] */
	S4 as4_a_bin_2f[AUX_BUFFSIZE],			/* [out] */
	FL afl_a_bin_power_2f[AUX_BUFFSIZE],	/* [out] */
	const FL afl_a_thres_2f[NB_FFT_PT_2F]	/* [in] */
);

VD fn_bsm_2f_estimate_doa(
	S4 s4_a_DOA_mode,												/* [in] method 0:MUSIC, 1:beamformer, 2(N/A):capon, 3(N/A):linear prediction */
	FL afl_a_Ryy_2f[NB_FFT_PT_2F][CORRE_SIZE_4CH],					/* [in] */

	S4 s4_a_peak_num_2f,											/* [in] */
	const S4 as4_a_peak_bin_2f[AUX_BUFFSIZE],						/* [in] */
	const FL afl_a_peak_power_2f[AUX_BUFFSIZE],						/* [in] */

	S4 *ps4_a_doa_peak_num_2f,										/* [out] */
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [out] */
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],						/* [out] */
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],				/* [out] */
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],					/* [out] */
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]						/* [out] */
);

VD fn_bsm_2f_cal_doa(
	S4 s4_a_DOA_mode,											/* [in] method 0:MUSIC, 1:beamformer, 2(N/A):capon, 3(N/A):linear prediction */
	const FL afl_a_Ryy_2f[NB_FFT_PT_2F][CORRE_SIZE_4CH],		/* [in] */

	S4 s4_a_peak_bin_2f,										/* [in] frequency of peak */

	S4 *ps4_a_doa_num,											/* [out] */
	FL afl_a_selected_doa_bins_intpl_2f[2],						/* [out] doa-bin */
	FL afl_a_selected_doa_powers_2f[2]							/* [out] doa-pow */
);

static VD fn_bsm_2f_cal_interpolate_freq_peak(
	S4 s4_a_peak_bin_2f,									/* [in] frequency of peak */
	S4 s4_a_doa_num_2f,										/* [in] */
	FL afl_a_selected_bins_intpl_2f[2]						/* [out] interpolated freq-bin */
);

VD fn_bsm_2f_store_doa(
	const FL afl_a_peak_power_2f[AUX_BUFFSIZE],						/* [in] */

	const S4 as4_a_doa_num_2f[AUX_BUFFSIZE],						/* [in] */
	const FL afl_a_selected_doa_bins_intpl_2f[AUX_BUFFSIZE][2],		/* [in] interpolated doa-bin */
	const FL afl_a_selected_doa_powers_2f[AUX_BUFFSIZE][2],			/* [in] doa-pow */
	const FL afl_a_selected_bins_intpl_2f[AUX_BUFFSIZE][2],			/* [in] interpolated freq-bin */

	S4 *ps4_a_doa_peak_num_2f,										/* [out] */
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [out] */
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],						/* [out] */
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],				/* [out] */
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],					/* [out] */
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]						/* [out] */
);

VD fn_bsm_2f_make_pair(
	S4		   s4_a_doa_peak_num_2f,											/* [in] */
	S4 		   as4_a_peak_wave_num[AUX_BUFFSIZE * 2],							/* [out] */

	const FL   afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],						/* [in] */
	const FL   afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [in] */
	const FL   afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],						/* [in] */

	S4		   *ps4_a_pair_num_2f,												/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE]									/* [out] S4 values of NORMAL_BSM structure */
);

S4 s4_bsm_2f_compare_with_FMCW(						/* [return] */
	S4 peak_num_2f,									/* [in] */
	NORMAL_BSM normal_2f[AUX_BUFFSIZE],				/* [in/out] */
	const S4 peak_wave_num[AUX_BUFFSIZE*2],			/* [in] */
	const FL Ryy_up[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (up) */
	const FL Ryy_dn[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (down) */
	U1 u1_a_alarming_flag
);

static U1 u1_bsm_2f_compare_with_FMCW_b10(FL fl_a_Ryobs);

static U1 u1_bsm_2f_compare_with_FMCW_a3(FL fl_a_power_up_music, FL fl_a_peak_power_up);

VD fn_bsm_2f_set_object(
	const S4 *ps4_a_pair_num_2f,
	NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
);

/****************************************************************************/
/* 関数名		: fn_bsm_seek_2f_object										*/
/*--------------------------------------------------------------------------*/
/* 機能			: 補助物標認識処理											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: 															*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_seek_2f_object(
	/***** OUTPUT (OBJECT) *****/
	S4		   *ps4_a_pair_num_2f,										/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],						/* [out] S4 values of NORMAL_BSM structure */
	U1		   u1_a_alarming_flag
)
{
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	S4 i;
#endif	/*VI 表示用*/

	S4 s4_t_peak_num_2f;
	S4 as4_t_peak_bin_2f[AUX_BUFFSIZE];
	FL afl_t_peak_power_2f[AUX_BUFFSIZE];

	S4 s4_t_peak_num_2f_doa;
	FL afl_t_peak_bins_intpl_2f[AUX_BUFFSIZE * 2];
	FL afl_t_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2];
	FL afl_t_peak_powers_2f[AUX_BUFFSIZE * 2];
	FL afl_t_peak_doa_powers_2f[AUX_BUFFSIZE * 2];
	S4 as4_t_peak_wave_num[AUX_BUFFSIZE*2];


    FL afl_t_thres_2f[NB_FFT_PT_2F];

	fn_bsm_2f_init_data(
		&s4_t_peak_num_2f,
		as4_t_peak_bin_2f,
		afl_t_peak_power_2f,
		afl_t_thres_2f,

		&s4_t_peak_num_2f_doa,
		afl_t_peak_bins_intpl_2f,
		afl_t_peak_powers_2f,
		afl_t_peak_doa_bins_intpl_2f,
		afl_t_peak_doa_powers_2f,
		as4_t_peak_wave_num
	);

	/****************************************************************************/
	/* (1)	２ＦＣＷピーク閾値算出処理											*/
	/****************************************************************************/
	fn_set_freq_threshold_fsk(
		(const FL *)afl_g_cvw_fcw_ftt_power,	/* [in] */
		afl_t_thres_2f,							/* [out] */
		fl_g_v_self_bsm_for_base				/* [in]	 */
	);

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy(afl_g_thres_2f, afl_t_thres_2f, sizeof(FL)*NB_FFT_PT_2F);
#endif /*VI 表示用*/

	/* ノイズ評価用送信データラッチ LSB:0.01に変更 閾値の最大値は120.0F */
	st_g_tx_noise_chk_fsk_bsm.u2_thres1 = u2_cast_from_fl(afl_t_thres_2f[140] * (FL)100);
	st_g_tx_noise_chk_fsk_bsm.u2_thres2 = u2_cast_from_fl(afl_t_thres_2f[180] * (FL)100);


	/****************************************************************************/
	/* (2)	２ＦＣＷピークサーチ処理											*/
	/****************************************************************************/
	if (	/* 車がいる時は2周波の離脱側のピークも探す */
		(st_g_bsm_loop_data.as4_flg_leading[0] != 0)					/* COND. b1 */
	 || (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN)		/* COND. b2 */
	) {
		s4_t_peak_num_2f = s4_search_freq_peak_fsk_IQ(
			(const FL *)afl_g_cvw_fcw_ftt_power,		/* [in] */
			as4_t_peak_bin_2f,							/* [out] */
			afl_t_peak_power_2f,						/* [out] */
			(const FL *)afl_t_thres_2f					/* [in] */
		);
	} else {
		s4_t_peak_num_2f = s4_search_freq_peak_fsk(
			(const FL *)afl_g_cvw_fcw_ftt_power,		/* [in] */
			as4_t_peak_bin_2f,							/* [out] */
			afl_t_peak_power_2f,						/* [out] */
			(const FL *)afl_t_thres_2f					/* [in] */
		);
	}

	st_g_tx_noise_chk_fsk_bsm.u1_peak_num = (U1)s4_t_peak_num_2f;		/* ノイズ評価用送信データラッチ */

#if (MODE_ECU_SIM == ECU_MODE)
	/* S4→U1のダウンキャストであるが、s4_t_peak_num_2fの値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_2f_music_peak_num = (U1)s4_t_peak_num_2f;		/* CheckPoint BSM_補助物標ピークサーチ結果 */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* (3)	方向推定処理														*/
/****************************************************************************/
	fn_bsm_2f_estimate_doa(
		0,														/* [in] method 0:MUSIC, 1:beamformer, 2(N/A):capon, 3(N/A):linear prediction */
		afl_g_cvw_fcw_ryy_matrix,								/* [in] */

		s4_t_peak_num_2f,										/* [in] */
		(const S4 *)as4_t_peak_bin_2f,							/* [in] */
		(const FL *)afl_t_peak_power_2f,						/* [in] */

		&s4_t_peak_num_2f_doa,									/* [out] */
		afl_t_peak_bins_intpl_2f,								/* [out] */
		afl_t_peak_powers_2f,									/* [out] */
		afl_t_peak_doa_bins_intpl_2f,							/* [out] */
		afl_t_peak_doa_powers_2f,								/* [out] */
		as4_t_peak_wave_num										/* [out] */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	/* S4→U1のダウンキャストであるが、s4_t_peak_num_2f_doaの値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_2f_pair_num = (U1)s4_t_peak_num_2f_doa;		/* CheckPoint BSM_補助物標物標数 */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* (4)	物標情報算出処理（２FCW）											*/
/****************************************************************************/
	fn_bsm_2f_make_pair(
		s4_t_peak_num_2f_doa,									/* [in] */
		as4_t_peak_wave_num,									/* [in] */

		(const FL *)afl_t_peak_bins_intpl_2f,					/* [in] */
		(const FL *)afl_t_peak_doa_bins_intpl_2f,				/* [in] */
		(const FL *)afl_t_peak_doa_powers_2f,					/* [in] */

		ps4_a_pair_num_2f,										/* [out] */
		ast_a_normal_2f											/* [out] */
	);

	fn_bsm_2f_set_object(
		(const S4 *)ps4_a_pair_num_2f,
		ast_a_normal_2f											/* [out] S4 values of NORMAL_BSM structure */
	);

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memset(afl_g_peak_2f, 0x00, sizeof(afl_g_peak_2f));
	for(i=0; i<s4_t_peak_num_2f_doa; i++)
	{
		afl_g_peak_2f[(int)(afl_t_peak_bins_intpl_2f[i]+0.5F)] = afl_t_peak_doa_powers_2f[i];
	}
#endif /*VI 表示用*/

	*ps4_a_pair_num_2f = s4_bsm_2f_compare_with_FMCW(					/* [return] */
		*ps4_a_pair_num_2f,							/* [in] */
		ast_a_normal_2f,							/* [in/out] */
		(const S4 *)as4_t_peak_wave_num,			/* [in] */
		(const FL (*)[CORRE_SIZE_4CH])afl_g_cvw_lfm_ryy_matrix[0],				/* [in] self correlation (up) */
		(const FL (*)[CORRE_SIZE_4CH])afl_g_cvw_lfm_ryy_matrix[1],				/* [in] self correlation (down) */
		u1_a_alarming_flag
	);


	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_2f_init_data										*/
/*--------------------------------------------------------------------------*/
/* 機能			: 初期化													*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: 															*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_2f_init_data(
	S4 *ps4_a_peak_num_2f,
	S4 as4_a_peak_bin_2f[AUX_BUFFSIZE],
	FL afl_a_peak_power_2f[AUX_BUFFSIZE],
	FL afl_a_thres_2f[NB_FFT_PT_2F],

	S4 *ps4_a_peak_num_2f_doa,
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]
)
{
	S4 s4_t_lp_i;

	*ps4_a_peak_num_2f = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < AUX_BUFFSIZE; s4_t_lp_i++) {
		as4_a_peak_bin_2f[s4_t_lp_i] = (S4)-1;
		afl_a_peak_power_2f[s4_t_lp_i] = 0.0F;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < NB_FFT_PT_2F; s4_t_lp_i++) {
		afl_a_thres_2f[s4_t_lp_i] = 0.0F;
	}

	*ps4_a_peak_num_2f_doa = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < (AUX_BUFFSIZE * (S4)2); s4_t_lp_i++) {
		afl_a_peak_bins_intpl_2f[s4_t_lp_i] = 0.0F;
		afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i] = (FL)-1.0F;
		afl_a_peak_powers_2f[s4_t_lp_i] = 0.0F;
		afl_a_peak_doa_powers_2f[s4_t_lp_i] = 0.0F;
		as4_a_peak_wave_num[s4_t_lp_i] = (S4)0;
	}
	
	return;
}


/****************************************************************************/
/* 関数名		: s4_search_freq_peak_fsk_IQ								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-2)-(i)接近側・離脱側のピークの検出					*/
/*				: 「2-2. 通常物標認識処理 (2)通常ピークサーチ処理			*/
/*				:	2)周波数スペクトラムのピークサーチ」を実施				*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (2)-2)-(i)接近側・離脱側のピークの検出					*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
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

/****************************************************************************/
/* 関数名		: s4_search_freq_peak_fsk									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-2)-(ii)接近側のピークの検出							*/
/*				: 「2-2. 通常物標認識処理 (2)通常ピークサーチ処理			*/
/*				:	2)周波数スペクトラムのピークサーチ」を実施				*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (2)-2)-(ii)接近側のピークの検出							*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
S4 s4_search_freq_peak_fsk(
	const FL afl_a_power_2f[NB_FFT_PT_2F],		/* [in] */
	S4 as4_a_bin_2f[AUX_BUFFSIZE],				/* [out] */
	FL afl_a_bin_power_2f[AUX_BUFFSIZE],		/* [out] */
	const FL afl_a_thres_2f[NB_FFT_PT_2F]		/* [in] */
)
{	
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	S4 s4_t_peak_num = 0;

	FL fl_t_temp = 0;

	s4_t_lp_k = 0;

	/* 接近側(I) */
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

	s4_t_peak_num = s4_t_lp_k;

	return (s4_t_peak_num);

}

/****************************************************************************/
/* 関数名		: fn_bsm_2f_estimate_doa									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3)方向推定処理											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)方向推定処理											*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_2f_estimate_doa(
	S4 s4_a_DOA_mode,												/* [in] method 0:MUSIC, 1:beamformer, 2(N/A):capon, 3(N/A):linear prediction */
	FL afl_a_Ryy_2f[NB_FFT_PT_2F][CORRE_SIZE_4CH],					/* [in] */

	S4 s4_a_peak_num_2f,											/* [in] */
	const S4 as4_a_peak_bin_2f[AUX_BUFFSIZE],						/* [in] */
	const FL afl_a_peak_power_2f[AUX_BUFFSIZE],						/* [in] */

	S4 *ps4_a_doa_peak_num_2f,										/* [out] */
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [out] */
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],						/* [out] */
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],				/* [out] */
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],					/* [out] */
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]						/* [out] */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	S4 as4_t_doa_num_2f[AUX_BUFFSIZE];
	FL afl_t_selected_doa_bins_intpl_2f[AUX_BUFFSIZE][2];
	FL afl_t_selected_doa_powers_2f[AUX_BUFFSIZE][2];
	FL afl_t_selected_bins_intpl_2f[AUX_BUFFSIZE][2];

	/* 初期化 */
	for (s4_t_lp_i = 0; s4_t_lp_i < AUX_BUFFSIZE; s4_t_lp_i++) {
		as4_t_doa_num_2f[s4_t_lp_i] = 0;
		for (s4_t_lp_k = 0; s4_t_lp_k < 2; s4_t_lp_k++) {
			afl_t_selected_doa_bins_intpl_2f[s4_t_lp_i][s4_t_lp_k] = (FL)-1.0F;
			afl_t_selected_doa_powers_2f[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_bins_intpl_2f[s4_t_lp_i][s4_t_lp_k] = (FL)-1.0F;
		}
	}

    /******************************************/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_2f; s4_t_lp_i++) {
		fn_bsm_2f_cal_doa(
			s4_a_DOA_mode,
			(const FL (*)[CORRE_SIZE_4CH])afl_a_Ryy_2f,

			as4_a_peak_bin_2f[s4_t_lp_i],
			
			&as4_t_doa_num_2f[s4_t_lp_i],
			afl_t_selected_doa_bins_intpl_2f[s4_t_lp_i],
			afl_t_selected_doa_powers_2f[s4_t_lp_i]
		);

		fn_bsm_2f_cal_interpolate_freq_peak(
			as4_a_peak_bin_2f[s4_t_lp_i],
			as4_t_doa_num_2f[s4_t_lp_i],
			afl_t_selected_bins_intpl_2f[s4_t_lp_i]
		);

		/* LCAとの共有ピーク情報へ格納 */
		fn_cmn_shareMUSIC_set_finished_music_data_main( (U1)2,
														(U1)as4_t_doa_num_2f[s4_t_lp_i],
														(U2)as4_a_peak_bin_2f[s4_t_lp_i],
														afl_t_selected_bins_intpl_2f[s4_t_lp_i][0],
														afl_t_selected_doa_bins_intpl_2f[s4_t_lp_i],
														afl_t_selected_doa_powers_2f[s4_t_lp_i]);
	}

	*ps4_a_doa_peak_num_2f = 0;
	fn_bsm_2f_store_doa(
		(const FL *)afl_a_peak_power_2f,

		(const S4 *)as4_t_doa_num_2f,
		(const FL (*)[2])afl_t_selected_doa_bins_intpl_2f,
		(const FL (*)[2])afl_t_selected_doa_powers_2f,
		(const FL (*)[2])afl_t_selected_bins_intpl_2f,

		ps4_a_doa_peak_num_2f,
		afl_a_peak_bins_intpl_2f,				/* [out] peak frequency */
		afl_a_peak_powers_2f,					/* [out] peak afl_a_power */
		afl_a_peak_doa_bins_intpl_2f,			/* [out] peak doa bin */
		afl_a_peak_doa_powers_2f,				/* [out] peak doa afl_a_power */
		as4_a_peak_wave_num						/* [out] wave number */
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_2f_cal_doa											*/
/*--------------------------------------------------------------------------*/
/* 機能			: 方位推定													*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)方位推定処理											*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_2f_cal_doa(
	S4 s4_a_DOA_mode,											/* [in] method 0:MUSIC, 1:beamformer, 2(N/A):capon, 3(N/A):linear prediction */
	const FL afl_a_Ryy_2f[NB_FFT_PT_2F][CORRE_SIZE_4CH],		/* [in] */

	S4 s4_a_peak_bin_2f,										/* [in] frequency of peak */

	S4 *ps4_a_doa_num,											/* [out] */
	FL afl_a_selected_doa_bins_intpl_2f[2],						/* [out] doa-bin */
	FL afl_a_selected_doa_powers_2f[2]							/* [out] doa-pow */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	FL afl_t_spec_bf[N_DOA_2F];
	FL afl_t_spec_music[N_DOA_2F];
	S4 as4_t_selected_doa_bins[2];

	S4 s4_t_wave_num = 1;

	for (s4_t_lp_i = 0; s4_t_lp_i < N_DOA_2F; s4_t_lp_i++) {
		afl_t_spec_bf[s4_t_lp_i] = 0.0F;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < N_DOA_2F; s4_t_lp_i++) {
		afl_t_spec_music[s4_t_lp_i] = 0.0F;
	}

	as4_t_selected_doa_bins[0] = (S4)-1;
	as4_t_selected_doa_bins[1] = (S4)-1;

	switch (s4_a_DOA_mode) {
		case 1:
			fn_calc_spec_bf_4ch_2f(
				afl_a_Ryy_2f[s4_a_peak_bin_2f],		/*  [in] */
				afl_t_spec_bf,						/*  [out] */
				1,									/*  [in] */
				s4_a_peak_bin_2f
			);
			*ps4_a_doa_num = s4_search_peak_bf(
				(const FL *)afl_t_spec_bf,				/*  [in] */
				as4_t_selected_doa_bins,				/*  [out] [2] DOA of bf peak */
				afl_a_selected_doa_powers_2f,			/*  [out] [2] afl_a_power of bf peak */
				1										/*  [in] */
			);
			for(s4_t_lp_k=0; s4_t_lp_k<2; s4_t_lp_k++) {
				afl_a_selected_doa_bins_intpl_2f[s4_t_lp_k] = (FL)as4_t_selected_doa_bins[s4_t_lp_k];
			}
			break;
		default:
			/* calculate MUSIC for 0-180 deg */
			s4_t_wave_num = s4_calc_spec_music_4ch_all(
				afl_a_Ryy_2f[s4_a_peak_bin_2f],	/*  [in] */
				afl_t_spec_music,				/*  [out] */
				2,								/*  [in] */
				1								/*  [in] */
			);
			*ps4_a_doa_num = s4_peak_search_music_fsk(
				(const FL *)afl_t_spec_music,
				as4_t_selected_doa_bins,
				afl_a_selected_doa_powers_2f,
				s4_t_wave_num
			);
			for(s4_t_lp_k=0; s4_t_lp_k<*ps4_a_doa_num; s4_t_lp_k++) {
				if(as4_t_selected_doa_bins[s4_t_lp_k]>0) {
					afl_a_selected_doa_bins_intpl_2f[s4_t_lp_k] = fl_interpolate_music_peak(
						(const FL *)afl_t_spec_music,
						as4_t_selected_doa_bins[s4_t_lp_k],
						(const FL *)FL_BSM_FLSH_YOMIKAE_TBL_2F
					);
				}
				else {
					afl_a_selected_doa_bins_intpl_2f[s4_t_lp_k] = -1.0F;
				}
			}
		break;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < *ps4_a_doa_num; s4_t_lp_i++) {
		if(as4_t_selected_doa_bins[s4_t_lp_i] > 0) {
			afl_a_selected_doa_powers_2f[s4_t_lp_i] = fl_calc_spec_bf_4ch_2f_of_specified_doa(
				afl_a_Ryy_2f[s4_a_peak_bin_2f],
				s4_a_peak_bin_2f,
				as4_t_selected_doa_bins[s4_t_lp_i]
			);
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_2f_cal_interpolate_freq_peak						*/
/*--------------------------------------------------------------------------*/
/* 機能			: 角度ピーク補間											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)方向推定処理											*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static VD fn_bsm_2f_cal_interpolate_freq_peak(
	S4 s4_a_peak_bin_2f,									/* [in] frequency of peak */
	S4 s4_a_doa_num_2f,										/* [in] */
	FL afl_a_selected_bins_intpl_2f[2]						/* [out] interpolated freq-bin */
)
{
	S4 s4_t_i;

	for(s4_t_i=0; s4_t_i<s4_a_doa_num_2f; s4_t_i++)
	{
		if( (FL)s4_a_peak_bin_2f != -1.0F )
		{
			afl_a_selected_bins_intpl_2f[s4_t_i] = fl_interpolate_freq_peak_fsk(
				(const FL *)afl_g_cvw_fcw_ftt_power,
				(S4)s4_a_peak_bin_2f
			);
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_2f_store_doa										*/
/*--------------------------------------------------------------------------*/
/* 機能			: 方位推定結果の格納										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)方向推定処理											*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_2f_store_doa(
	const FL afl_a_peak_power_2f[AUX_BUFFSIZE],						/* [in] */

	const S4 as4_a_doa_num_2f[AUX_BUFFSIZE],						/* [in] */
	const FL afl_a_selected_doa_bins_intpl_2f[AUX_BUFFSIZE][2],		/* [in] interpolated doa-bin */
	const FL afl_a_selected_doa_powers_2f[AUX_BUFFSIZE][2],			/* [in] doa-pow */
	const FL afl_a_selected_bins_intpl_2f[AUX_BUFFSIZE][2],			/* [in] interpolated freq-bin */

	S4 *ps4_a_doa_peak_num_2f,										/* [out] */
	FL afl_a_peak_bins_intpl_2f[AUX_BUFFSIZE * 2],					/* [out] */
	FL afl_a_peak_powers_2f[AUX_BUFFSIZE * 2],						/* [out] */
	FL afl_a_peak_doa_bins_intpl_2f[AUX_BUFFSIZE * 2],				/* [out] */
	FL afl_a_peak_doa_powers_2f[AUX_BUFFSIZE * 2],					/* [out] */
	S4 as4_a_peak_wave_num[AUX_BUFFSIZE * 2]						/* [out] */
)
{
	S4 s4_t_iRet;

	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	/* ペアマッチ用の方位推定結果を格納 */
	s4_t_iRet = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < AUX_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < as4_a_doa_num_2f[s4_t_lp_i]; s4_t_lp_k++) {
			afl_a_peak_bins_intpl_2f[s4_t_iRet] = afl_a_selected_bins_intpl_2f[s4_t_lp_i][s4_t_lp_k];
			afl_a_peak_powers_2f[s4_t_iRet] = afl_a_peak_power_2f[s4_t_lp_i];
			afl_a_peak_doa_bins_intpl_2f[s4_t_iRet] = afl_a_selected_doa_bins_intpl_2f[s4_t_lp_i][s4_t_lp_k];
			afl_a_peak_doa_powers_2f[s4_t_iRet] = afl_a_selected_doa_powers_2f[s4_t_lp_i][s4_t_lp_k];

			as4_a_peak_wave_num[s4_t_iRet] = as4_a_doa_num_2f[s4_t_lp_i];
			s4_t_iRet++;
		}
	}
	*ps4_a_doa_peak_num_2f = s4_t_iRet;

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_2f_make_pair										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)物標情報算出処理（２FCW)								*/
/*				:	補助ピークサチ処理により得られた2FCW周波数スペクトラム	*/
/*				:	のピーク情報、及び方向推定処理により得られた方位情報に	*/
/*				:	基づき、物標の位置・速度情報を算出する。				*/
/*				:	1)推定方向を車座標系に変換								*/
/*				:	2)距離の算出											*/
/*				:	3)速度の算出											*/
/*				:	4)FMCWピーク周波数の算出								*/
/*				:	5)ピーク補間											*/
/*				:	6)物標情報の保存										*/
/*				:	7)物標フラグ情報の保存									*/
/*				:	8)バッファあふれ対策									*/
/*				:	9)方位推定結果の格納									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (4)物標情報算出処理（２FCW)								*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
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


/****************************************************************************/
/* 関数名		: fn_bsm_2f_set_object										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)-7)-③ 物標種別を設定									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (4)-7)-③ 物標種別を設定									*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
VD fn_bsm_2f_set_object(
	const S4 *ps4_a_pair_num_2f,
	NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;

	for (s4_t_lp_i = 0; s4_t_lp_i < *ps4_a_pair_num_2f; s4_t_lp_i++) {
		ast_a_normal_2f[s4_t_lp_i].s4_flg_dc = OBJECT_TYPE_2F;
	}

	return;
}


/****************************************************************************/
/* 関数名		: s4_bsm_2f_compare_with_FMCW								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)FMCM比較・除去処理										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (5)FMCM比較・除去処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
S4 s4_bsm_2f_compare_with_FMCW(						/* [return] */
	S4 peak_num_2f,									/* [in] */
	NORMAL_BSM normal_2f[AUX_BUFFSIZE],				/* [in/out] */
	const S4 peak_wave_num[AUX_BUFFSIZE*2],			/* [in] */
	const FL Ryy_up[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (up) */
	const FL Ryy_dn[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (down) */
	U1 u1_a_alarming_flag
)
{
	S4 iret = peak_num_2f;

	S4 i, j;
	S4 tmp_erase_flg = 0;
	FL tmp_doa_spec[N_DOA];
	S4 tmp_wave_num_up = 0;
	S4 tmp_doa_up[2];
	FL tmp_peak_power_up[2];
	S4 tmp_wave_num_dn = 0;
	S4 tmp_doa_dn[2];
	FL tmp_peak_power_dn[2];
	U1 u1_t_lp_n_doa;
	U1 u1_t_jdg_b10_flg;
	U1 u1_t_jdg_a3_flg;

	/* ローカル変数初期化 */
	for (u1_t_lp_n_doa = (U1)0; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		tmp_doa_spec[u1_t_lp_n_doa] = (FL)0.0F;
	}
	tmp_doa_up[0] = (S4)-1;
	tmp_doa_up[1] = (S4)-1;
	tmp_peak_power_up[0] = (FL)0.0F;
	tmp_peak_power_up[1] = (FL)0.0F;
	tmp_doa_dn[0] = (S4)-1;
	tmp_doa_dn[1] = (S4)-1;
	tmp_peak_power_dn[0] = (FL)0.0F;
	tmp_peak_power_dn[1] = (FL)0.0F;

	for(i=0; i<peak_num_2f; i++)
	{
		/* 条件b10の判定関数コール 仕様書の記述より条件b10の定義部分にコンパイルスイッチが入るため、	*/
		/* 条件b10の判定用関数を作り、判定結果を条件確認箇所で使用する									*/
		/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない				*/
		u1_t_jdg_b10_flg = u1_bsm_2f_compare_with_FMCW_b10(normal_2f[i].fl_Ryobs);

		if (((peak_wave_num[i] > (S4)0)													/* COND.b1 */
		&&   (fl_g_v_self_bsm_for_base < (FL)12.0F))									/* COND.b3 */
		||  ((peak_wave_num[i] > (S4)1)													/* COND.b2 */
		&&   (!(fl_g_v_self_bsm_for_base < (FL)12.0F)))									/* COND.!b3 */
		||  ((normal_2f[i].s4_bin_up_music > (S4)CU1_COMPARE_FM2F_DOA_LOWER_LIMIT)		/* COND.b4 */
		&&   (normal_2f[i].s4_bin_up_music < (S4)CU1_COMPARE_FM2F_DOA_UPPER_LIMIT)		/* COND.b5 */
		&&   (normal_2f[i].s4_bin_dn_music > (S4)CU1_COMPARE_FM2F_DOA_LOWER_LIMIT)		/* COND.b6 */
		&&   (normal_2f[i].s4_bin_dn_music < (S4)CU1_COMPARE_FM2F_DOA_UPPER_LIMIT)		/* COND.b7 */
		&&   (st_g_bsm_loop_data.as4_fast_sot_flg[0] != (S4)0))							/* COND.b8 */
		||  ((normal_2f[i].s4_bin_up_music > (S4)CU1_COMPARE_FM2F_DOA_LOWER_LIMIT)		/* COND.b4 */
		&&   (normal_2f[i].s4_bin_up_music < (S4)CU1_COMPARE_FM2F_DOA_UPPER_LIMIT)		/* COND.b5 */
		&&   (normal_2f[i].s4_bin_dn_music > (S4)CU1_COMPARE_FM2F_DOA_LOWER_LIMIT)		/* COND.b6 */
		&&   (normal_2f[i].s4_bin_dn_music < (S4)CU1_COMPARE_FM2F_DOA_UPPER_LIMIT)		/* COND.b7 */
		&&   (u1_a_alarming_flag == (U1)0)												/* COND.b9 */
		&&   (u1_t_jdg_b10_flg == CU1_TRUE)												/* COND.b10 */
		&&   (normal_2f[i].fl_Ryobs > (FL)-9.0F))) {									/* COND.b11 */
			tmp_erase_flg = 0;
			/***** 1) Calculates DOA of FMCW peak ( *****/
			/* UP */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)Ryy_up[normal_2f[i].s4_bin_up],	/* [in] */
				tmp_doa_spec,								/* [out] */
				0,											/* [in] up */
				normal_2f[i].s4_bin_up						/* [in] */
			);
			tmp_wave_num_up = s4_search_peak_bf(
				(const FL *)tmp_doa_spec,		/* [in] */
				tmp_doa_up,						/* [out] */
				tmp_peak_power_up,				/* [out] */
				1								/* [in] */
			);
			for( j=0; j<tmp_wave_num_up; j++ )
			{
				/* 条件a3の判定関数コール 仕様書の記述より条件a3の定義部分にコンパイルスイッチが入るため、	*/
				/* 条件a3の判定用関数を作り、判定結果を条件確認箇所で使用する								*/
				/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない			*/
				u1_t_jdg_a3_flg = u1_bsm_2f_compare_with_FMCW_a3(normal_2f[i].fl_power_up_music, tmp_peak_power_up[j]);

				if ((normal_2f[i].fl_Robs != CFL_UNKNOWN_VALUE)												/* COND.a1 */
				&&  (s4_abs(normal_2f[i].s4_bin_up_music - tmp_doa_up[j]) > (S4)CU1_DOA_DIFF_FM_2F)			/* COND.a2 */
				&&  (u1_t_jdg_a3_flg == CU1_TRUE)) {														/* COND.a3 */
					tmp_erase_flg = 1;
				}
			}
			if( tmp_erase_flg == 0 )
			{
				/* DOWN */
				fn_calc_spec_bf_4ch_fm(
					(const FL *)Ryy_dn[normal_2f[i].s4_bin_dn],	/* [in] */
					tmp_doa_spec,								/* [out] */
					1,											/* [in] dn */
					normal_2f[i].s4_bin_dn						/* [in] */
				);
				tmp_wave_num_dn = s4_search_peak_bf(
					(const FL *)tmp_doa_spec,		/* [in] */
					tmp_doa_dn,						/* [out] */
					tmp_peak_power_dn,				/* [out] */
					1								/* [in] */
				);
				for( j=0; j<tmp_wave_num_dn; j++ )
				{
					if ((normal_2f[i].fl_Robs != CFL_UNKNOWN_VALUE)												/* COND.a1' */
					&&  (s4_abs(normal_2f[i].s4_bin_dn_music - tmp_doa_dn[j]) > (S4)CU1_DOA_DIFF_FM_2F)) {		/* COND.a2' */
						tmp_erase_flg = 1;
					}
				}
			}
			/* erase */
			if( tmp_erase_flg==1 )
			{
				fn_init(&normal_2f[i], 1);
			}
		}
	}

	iret = s4_trim_normal_2f(normal_2f);

	return iret;
}

/****************************************************************************/
/* 関数名		: u1_bsm_2f_compare_with_FMCW_b10							*/
/*--------------------------------------------------------------------------*/
/* 機能			: FMCM比較・除去処理の条件b10判定関数						*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_Ryobs			: 現在物標のY方向距離観測値[in]		*/
/* 戻り値		: u1_t_jdg_b10_flag		: 条件b10の判定結果格納変数			*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-010								*/
/*				: (5) FMCW 比較・除去処理の条件b10							*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_2f_compare_with_FMCW_b10(FL fl_a_Ryobs)
{
	/* 条件b10が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_b10_flag;				/* 条件b10判定結果格納変数 */

	/* FALSEで初期化 */
	u1_t_jdg_b10_flag = CU1_FALSE;

	/* 条件b10の判定 */
#if (BSM_OPTION_SW_RECOG_04 == TYPE_A)
	/* 搭載角度50degのとき */
	if (fl_a_Ryobs < (FL)-5.0F) {
		u1_t_jdg_b10_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b10_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_04 == TYPE_B)
	/* 搭載角度20degのとき */
	if (fl_a_Ryobs < (FL)-3.5F) {
		u1_t_jdg_b10_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b10_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_04 */

	return u1_t_jdg_b10_flag;
}

/****************************************************************************/
/* 関数名		: u1_bsm_2f_compare_with_FMCW_a3							*/
/*--------------------------------------------------------------------------*/
/* 機能			: FMCM比較・除去処理の条件a3判定関数						*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_power_up_music	: 現在物標の上り方位電力	[in]	*/
/*				: fl_a_peak_power_up	: FMCWピーク上り方位電力	[in]	*/
/* 戻り値		: u1_t_jdg_a3_flag		: 条件a3の判定結果格納変数			*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-04-010								*/
/*				: (5) FMCW 比較・除去処理の条件a3							*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_2f_compare_with_FMCW_a3(FL fl_a_power_up_music, FL fl_a_peak_power_up)
{
	/* 条件a3が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_a3_flag;				/* 条件a3判定結果格納変数 */

	/* FALSEで初期化 */
	u1_t_jdg_a3_flag = CU1_FALSE;

	/* 条件a3の判定 */
#if (BSM_OPTION_SW_RECOG_04 == TYPE_A)
	/* 搭載角度50degのとき */
	if (fl_abs(fl_a_power_up_music - fl_a_peak_power_up) > (FL)3.0F) {
		u1_t_jdg_a3_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a3_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_04 == TYPE_B)
	/* 搭載角度20degのとき */
	if (fl_a_power_up_music < (FL)45.0F) {
		u1_t_jdg_a3_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a3_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_04 */

	return u1_t_jdg_a3_flag;
}



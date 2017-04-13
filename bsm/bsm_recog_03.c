/****************************************************************************/
/* ファイル名	: BSM_RECOG_03.c											*/
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
/*	BSM AS巻替 int→S4,float→FLに変更,ワーニング対応,不要関数削除			*/
/*	t05					15.02.27			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 _ALWAYS_CHECK_FR_SOTの#ifdef削除								*/
/*	t06					15.02.27			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 インデント修正 //コメント変更(OBJ変更なし)					*/
/*	t07					15.03.13			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 変数初期化処理追加											*/
/*	t08					15.03.23			走安技2 1技室 G.Jomori			*/
/*	BSM一致確認で発見したバグ修正											*/
/*	t11					15.05.25			走安技2 1技室 G.Jomori			*/
/*	残課題No482～486対応													*/
/*	t12					15.05.25			走安技2 1技室 G.Jomori			*/
/*	残課題No484対応(OBJ変更なし)											*/
/*	t13					15.05.26			走安技2 1技室 G.Jomori			*/
/*	残課題No492対応															*/
/*	t14					15.06.01			走安技2 1技室 G.Jomori			*/
/*	残課題No483修正															*/
/*	t15					15.06.02			走安技2 1技室 G.Jomori			*/
/*	残課題No438,443,444対応													*/
/*	t19					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t20					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t21					15.08.07			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 一致確認中に発見したバグ修正							*/
/*	t22					15.08.19			走安技2 1技室 G.Jomori			*/
/*	一致確認中に発見したバグ修正 自動軸調整のDBF展開結果を流用する			*/
/*	t23					15.08.31			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1458,1496～1501,1555～1563,1579～1582,1599対応				*/
/*	t24					15.09.11			走安技2 1技室 G.Jomori			*/
/*	MWR-RECO-24G-BSM-RECOG-03-008対応										*/
/*	t25					15.10.27			走安技2 1技室 Y.Nishioka		*/
/*	関数ヘッダの追加 ※OBJ変更なし											*/
/*	t26					15.11.17			走安技2 1技室 G.Jomori			*/
/*	BSM CV対応																*/
/*	t27					15.11.18			走安技2 1技室 G.Jomori			*/
/*	残課題No970対応(OBJ変更なし)											*/
/*	t28					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t29					15.11.25			走安技2 1技室 G.Jomori			*/
/*	仕様確認No.1722,1756,1757,1763,1774,1790対応							*/
/*	t30					15.11.26			走安技2 1技室 G.Jomori			*/
/*	仕様確認No.1744対応(OBJ変更なし)										*/
/*	t31					15.12.04			走安技2 1技室 G.Jomori			*/
/*	BSM 机上クロス指摘対応													*/
/*	t32					16.01.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM BSM評価用仕様対応												*/
/*	t33					16.01.26			走安技2 1技室 G.Jomori			*/
/*	291B BSM BSM評価用仕様対応(OBJ変更なし)									*/
/*	t34					16.01.27			走安技2 1技室 G.Jomori			*/
/*	291B BSM 机上セルフ対応													*/
/*	t36					16.01.29			走安技2 1技室 G.Jomori			*/
/*	t247マージ																*/
/*	t37					16.03.01			走安技2 1技室 G.Jomori			*/
/*	010B BSM CV-R仕様対応													*/
/*	t38					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1198対応(ローカル配列変数の宣言と同時に実施の初期化分離)		*/
/*	t39					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1098,1193対応(下限ガード、不要処理削除)							*/
/*	t40					16.03.07			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1707対応(配列数変更)											*/
/*	t41					16.03.11			走安技2 1技室 G.Jomori			*/
/*	010B CV-R 3/8発行 MWR-RECO-24G-BSM-RECOG-03-013対応						*/
/*	t42					16.03.25			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様対応														*/
/*	t43					16.03.28			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 机上セルフ対応(OBJ変更なし)								*/
/*	t44					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応(OBJ変更なし)						*/
/*	t45					16.03.30			走安技2 1技室 G.Jomori			*/
/*	291B BSM 20degのときのみ使用する変数・関数をコンパイルオプションで囲む(OBJ変更なし)*/
/*	t46					16.04.01			走安技2 1技室 G.Jomori			*/
/*	010B 291B MWR-RECO-24G-BSM-RECOG-03-014対応								*/
/*	t47					16.04.07			走安技2 1技室 G.Jomori			*/
/*	BSM QAC 指摘対応														*/
/*	t48					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t50					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t51					16.06.20			走安技2 1技室 H.Nonogaki		*/
/*	QAC 指摘対応(OBJ変更無し)												*/
/*	t52					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t53					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM 残課題No1336対応 OBJ変更なし										*/
/*	t54					16.06.21			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t55					16.06.22			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t64					16.07.18			走安技2 1技室 G.Jomori			*/
/*	291B開発用ソフトに010Bソフトをマージ(010B 1Aをベースに0024_t822マージ)	*/
/*	t71					16.08.22			走安技2 1技室 G.Jomori			*/
/*	残課題No1411,1412,1413対応(S4,FL,VDに変更 OBJ変更なし)					*/
/*	t72					16.08.22			走安技2 1技室 G.Jomori			*/
/*	残課題No1414,1415対応(関数定義移動)										*/
/*	t74					16.09.15			走安技2 1技室 G.Jomori			*/
/*	010B 2A 認識部分(BSM,RCTA,AUDR)マージ									*/
/*	t75					16.09.23			走安技2 1技室 G.Jomori			*/
/*	291B CV-R仕様対応														*/
/*	t76					16.09.26			走安技2 1技室 G.Jomori			*/
/*	291B CV-R BSM 机上セルフ対応(OBJ変更なし)								*/
/*	t77					16.09.26			走安技2 1技室 G.Jomori			*/
/*	291B CV-R BSM 読み合わせ指摘と仕様確認No2781対応						*/
/*	t78					16.09.27			走安技2 1技室 G.Jomori			*/
/*	仕様確認No2783,2784対応													*/
/*	t79					16.09.28			走安技2 1技室 G.Jomori			*/
/*	一致確認で発見したバグ修正 												*/
/*	t80					16.09.29			走安技2 1技室 G.Jomori			*/
/*	仕様確認No2812対応														*/
/*	t81					16.09.29			走安技2 1技室 G.Jomori			*/
/*	一致確認で発見したバグ修正 												*/
/****************************************************************************/

/****************************************************************************/
/*							インクルードファイル							*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../parameter_adj.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "init_cvw.h"
#include "func_fmcw.h"
#include "func_fsk.h"
#include "bsm_connect_01.h"
#include "../bsm_public_inc.h"
#include "../../common/cmn_autoaxis_mwr.h"
#include "../../common/cmn_slipjdg_mwr.h"

#include "bsm_recog_03.h"

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
S4 s4_peak_search_music_fsk_all_doa(
	FL music_spec[N_DOA_2F],			/* [in] */
	S4 bin_music[2],					/* [out] */
	FL power_music[2],					/* [out] */
	S4 wave_num_in						/* [in] */
);

static S4 s4_bsm_side_check_fm_approaching_object(
	const FL afl_a_sot_thres_up[NB_FFT_PT],
	const FL afl_a_sot_thres_dn[NB_FFT_PT],
	const S4 as4_a_wall_check_up[3],
	const S4 as4_a_wall_check_dn[3],
	const S4 as4_a_wall_bin_up[3],
	const S4 as4_a_wall_bin_dn[3],
	const FL afl_a_wall_pow_up[3],
	const FL afl_a_wall_pow_dn[3]
);

S4 check_fm_object(									/* [return] object flag */
	const NORMAL_BSM ast_a_normal_sot_prev[1],		/* [in] object data */
	S4 s4_a_leading_flg,							/* [in] leading car flag */
	NORMAL_BSM ast_a_normal_sot[1]					/* [out] object data */
);

S4 check_fm_spectrum(								/* [return] approaching object flag */
	FL sot_thres_up[NB_FFT_PT],						/* [out](for debug) threashold for wall estimation（FM up) */
	FL sot_thres_dn[NB_FFT_PT]						/* [out](for debug) threashold for wall estimation（FM dn) */
);

VD set_freq_threshold_without_center_mask(
	const FL power[NB_FFT_PT],	/* [in] power of beat signal */
	FL thres[NB_FFT_PT]			/* [out] threshold for peak detection */
);

S4 set_wall_freq_threshold(					/* [return](not used) number of steps */
	const FL thres[NB_FFT_PT],				/* [in] threshold for peak detection */
	FL wall_thres[NB_FFT_PT],				/* [out] threshold for peak detection */
	S4 wall_check[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 wall_bin[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	FL wall_pow[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 freq_start,							/* [in] */
	S4 freq_end								/* [in] */
);

S4 seek_freq_step(				/* [return] 0:no more step, 1:have next step */
	const FL thres[NB_FFT_PT],	/* [in] threshold for peak detection */
	S4 end_index,				/* [in] end point of freq-bin */
	FL pow_range,				/* [in] range of freq-power to treat as the same step  */
	FL pow[1],					/* [in/out] freq-pow of this step */
	S4 index[1],				/* [in/out] start point of this step */
	S4 count[1],				/* [out] number of freq-bin of this step  */
	S4 next_index[1]			/* [out] end point of this step(start point of next step) */
);

VD set_stationary_doa_line_2f(
	S4 stationary_doa_line[N_DOA],				/* [out] 停止物のDOA/FREQ */
	S4 v0_doa_def,								/* [in] 検出した速度‐方向の近似線から車の方向を推定(やりかけ) */
	S4 v0_doa									/* [in] 検出した速度‐方向の近似線から車の方向を推定(やりかけ) */
);

VD set_sot_limit_doa_line_2f(
	S4 sot_limit_doa_line[N_DOA],				/* [out] SoTのDOA/FREQ */
	S4 v0_doa_def,								/* [in] */
	S4 v0_doa,									/* [in] */
	FL v_sot_offset								/* [in] */
);

U1 calc_nearfield_doa_2f_I(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 130-144binのDOAピーク(最大1個/1bin) */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] 上記各binのDOAピーク数(最大1個) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 calc_nearfield_doa_2f_Q(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 126-112binのDOAピーク(最大1個/1bin) */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] 上記各binのDOAピーク数(最大1個) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 compare_forward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 compare_backward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	S4 stationary_doa_line[N_DOA],									/* [in] */
	S4 sot_limit_doa_line_backward[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	FL v_sot_offset,												/* [in] */
	const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
);

S4 check_sot_start(											/* [return] */
	FL dev[2],												/* [in] */
	U1 u1_a_alarming_flag
);

static U1 u1_check_sot_start_h84(S4 s4_a_fwd_peak_val, S4 s4_a_bwd_peak_val);

S4 check_sot_stop(											/* [return] */
	const FL dev[2]											/* [in] */
);

S4 check_sot_on(											/* [return] */
	const FL dev[2]											/* [in] */
);

S4 check_sot_off(											/* [return] */
	const FL dev[2]											/* [in] */
);

VD fn_bsm_low_judge_check_sot_doa(FL* pfl_a_fast_sot_pow);

FL calc_deviation_of_doa_freq_line_stationary_2(					/* [return] deviation of ovserved doa-freq points */
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] 130-145binのDOAピーク */
	S4 start_freq_bin,												/* [in]	start freq-bin */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 mode															/* [in] 0:I, 1:Q */
	,S4 *backward_priod												/* [out] use backward dev */
	,S4 v0_doa														/* [in] */
	,S4 *fast_sot_num												/* [out] */
	,S4 *not_fast_sot_num											/* [out] */
	,S4 fast_sot_limit_line[N_DOA]									/* [out] */
	,const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4]
);

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
);

static VD fn_bsm_low_judge_sot(
	S4 as4_stationary_doa_line[N_DOA],
	S4 as4_sot_limit_doa_line_forward[N_DOA],
	S4 as4_sot_limit_doa_line_backward[N_DOA],
	const S4 as4_a_nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_a_nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 s4_a_forward_priod,
	S4 s4_a_backward_priod,
	FL afl_a_buf_dev[2],
	FL *pfl_a_dev,
	S4 v0_doa,
	U1 u1_a_alarming_flag,
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
	U1* pu1_a_num_forward,
	U1* pu1_a_num_backward
);
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは関数定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
VD fn_bsm_low_judge_check_tos(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
							  FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
							  U1* pu1_a_tos_end_flg,
							  U1* pu1_a_num_i,
							  U1* pu1_a_num_q,
							  U1* pu1_a_tos_flg);

static S4 s4_bsm_low_judge_sot_jdg_noise_flg(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
											 FL afl_a_buf_dev[2],
											 S4 s4_a_slow_sot_find1_pre,
											 FL* pfl_a_ave_i_y,
											 U1* pu1_a_noise_flg);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

static VD fn_bsm_low_judge_wall(
	const FL afl_a_buf_dev[2],
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	U1 u1_a_num_forward,
	U1 u1_a_num_backward
);

static VD fn_bsm_low_judge_wall_forward_deviation_small(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	S4 s4_a_backward_point
);

static VD fn_bsm_low_judge_wall_forward_deviation_big(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
);

static VD fn_bsm_low_judge_wall_when_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_backward_point
);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
);
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	U1* pu1_a_wall_checked_flag
);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは関数定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static S4 s4_bsm_low_judge_wall_proc8(S4 s4_a_sot_find_1);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

static VD fn_bsm_low_judge_fast_sot(
	S4 s4_a_fast_sot_num,
	S4 s4_a_not_fast_sot_num,
	U1 u1_a_alarming_flag
);


static VD fn_bsm_low_judge_exist_leading_car_main(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
												  const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]);

static VD fn_bsm_low_judge_exist_leading_car_set_jdg_area(FL* pfl_a_area_x_near,
														  FL* pfl_a_area_x_far,
														  FL* pfl_a_area_y_forward,
														  FL* pfl_a_area_y_backward);

static VD fn_bsm_low_judge_exist_leading_car_calc_char(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL fl_a_area_x_near,
													   const FL fl_a_area_x_far,
													   const FL fl_a_area_y_forward,
													   const FL fl_a_area_y_backward,
													   U1* pu1_a_Ni,
													   U1* pu1_a_Nq,
													   FL* pfl_a_ave_theta_i,
													   FL* pfl_a_ave_theta_q,
													   FL* pfl_a_var_theta_i,
													   FL* pfl_a_var_theta_q,
													   U1* pu1_a_flg_point_many,
													   U1* pu1_a_flg_point_bias);

static VD fn_exist_leading_car_calc_char_iq(const S4 as4_a_nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],
											const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4],
											const FL fl_a_area_x_near,
											const FL fl_a_area_x_far,
											const FL fl_a_area_y_forward,
											const FL fl_a_area_y_backward,
											U1* pu1_a_N,
											FL* pfl_a_ave_theta,
											FL* pfl_a_var_theta);

static VD fn_bsm_low_judge_exist_leading_car_jdg(const U1 u1_a_Ni,
												 const U1 u1_a_Nq,
												 const FL fl_a_ave_theta_i,
												 const FL fl_a_ave_theta_q,
												 const FL fl_a_var_theta_i,
												 const FL fl_a_var_theta_q,
												 const U1 u1_a_flg_point_many,
												 const U1 u1_a_flg_point_bias);

static VD fn_bsm_low_judge_exist_leading_car_mediation(VD);



static FL fl_bsm_side_cal_fm_nearfield_power( VD );

static VD fn_bsm_side_check_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_wall_reject_th
);

static VD fn_bsm_side_check1_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_wall_reject_th
);

static VD fn_bsm_side_check2_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle
);

static VD fn_bsm_side_set_leading_object(
	S4 s4_a_leading_flg2,						/* [in] */
	const NORMAL_BSM ast_a_normal_fm[1],		/* [in] */
	NORMAL_BSM ast_a_normal_heisou[1]			/* [out] */
);

static VD fn_bsm_side_check_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 *ps4_a_wall_flg,
	NORMAL_BSM ast_a_normal_wall[1],
	S4 s4_a_wall_reject_th
);

static VD fn_bsm_side_check1_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	S4 *ps4_a_wall_flg,
	S4 s4_a_wall_reject_th
);

static VD fn_bsm_side_set_wall_object(
	S4 s4_a_wall_flg,
	const NORMAL_BSM ast_a_normal_fm[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_tracking_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_wall_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_tracking_wall_with_obs(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_intpl_cur_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],			/* [in]  */
	NORMAL_BSM ast_a_normal_wall[1]						/* [out] */
);

static VD fn_bsm_side_tracking_wall_without_obs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_guard_wall_rxfil(
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_confirm_prev_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	FL *pfl_a_wall_pos
);

static VD fn_bsm_side_cal1_next_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static FL fl_bsm_side_cal1_cal_wall_rxobs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1]
);

static VD fn_bsm_side_cal2_next_wall_object(
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_cal3_next_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_guard_wall_xpred(
	NORMAL_BSM ast_a_normal_wall[1]
);

static S4 s4_bsm_side_tracking_heisou(
	FL fl_a_fm_nearfield_power,
	S4 s4_a_fm_obj_flg,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static S4 s4_bsm_side_tracking_heisou_with_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static S4 s4_bsm_side_tracking_heisou_without_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static VD fn_bsm_side_check_tracking_heisou_range(
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot[1]
);

VD fn_bsm_side_check_wall_for_erase_fa_seg(const NORMAL_BSM ast_a_normal_sot_ena[1], S4 s4_a_fm_obj_flg);

/****************************************************************************/
/* 関数名		: s4_seek_sidewinder										*/
/*--------------------------------------------------------------------------*/
/* 機能			: 前側方物体認識											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 s4_seek_sidewinder(										/* [return] number of detected objects(0 or 1) */
	NORMAL_BSM ast_a_normal_wall[1],						/* [in/out] S4 values of NORMAL_BSM structure */
	NORMAL_BSM ast_a_normal_sot[1]							/* [in/out] S4 values of NORMAL_BSM structure */
)
{
	/************** 変数宣言 **************/
	S4 object_num = 0;

	S4 tmp_fm_obj_flg = 0;												/* FM物標フラグ */
	S4 tmp_fm_flg = 0;													/* FM接近判定フラグ */
	S4 tmp_wall_flg = 0;												/* 壁フラグ */
	S4 tmp_leading_flg1 = st_g_bsm_loop_data.as4_flg_leading[0];		/* 併走車フラグ１ */
	S4 tmp_leading_flg2 = st_g_bsm_loop_data.as4_flg_leading[0];		/* 併走車フラグ２ */

	/* スタック容量削減対策で一部変数削除	*/
	/* 更なる検討必要					*/
	/* 物標候補 */
	NORMAL_BSM tmp_normal[1];

	/* 壁候補 */
	NORMAL_BSM normal_wall[1];
	NORMAL_BSM normal_wall_prev[1];

	/* 車候補 */
	NORMAL_BSM tmp_normal_sot[1];
	NORMAL_BSM normal_sot[1];
	NORMAL_BSM normal_sot_prev[1];

	/* 物標トラッキング */
	FL tmp_cos = 0.0F;

	FL sot_thres_up[NB_FFT_PT];						/* [out](for debug) threashold for wall estimation（FM up) */
	FL sot_thres_dn[NB_FFT_PT];						/* [out](for debug) threashold for wall estimation（FM dn) */

	/*** ブロックの途中で宣言されている変数群をブロックの先頭へ移動 *******************/
	/* FM近接電力 for SoT */
	FL tmp_fm_nearfield_power;

	/* 併走車判定(2) */
	FL tmp_sot_wall_angle;
	FL tmp_sot_real_angle;

	S4 tmp_wall_reject_th = WALL_REJECT_TH3;

	fn_initialize_wall_data(
		tmp_normal
	);
	fn_move(
		normal_wall,			/* [out] */
		tmp_normal,				/* [in] */
		1
	);
	fn_move(
		normal_wall_prev,		/* [out] */
		ast_a_normal_wall,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		tmp_normal_sot,			/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		normal_sot_prev,		/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		normal_sot,				/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);

/****************************************************************************/
/* (1)	ＦＭＣＷ前側方物標判定処理											*/
/****************************************************************************/
	/***** 1) FMCW近接電力の算出. *****/
	tmp_fm_nearfield_power = fl_bsm_side_cal_fm_nearfield_power();

	/************** FM物標判定(tmp_fm_obj_flg) **************/
	tmp_fm_obj_flg = check_fm_object(	/* [return] */
		(const NORMAL_BSM *)normal_sot_prev,	/* [in] */
		tmp_leading_flg1,						/* [in]	 */
		tmp_normal								/* [out] */
	);
/****************************************************************************/
/* (2)	ＦＭＣＷ物標接近判定処理											*/
/****************************************************************************/
	/************** FMスペクトラム判定(tmp_fm_flg) **************/
	tmp_fm_flg = 0;
	tmp_fm_flg = check_fm_spectrum(
		sot_thres_up,
		sot_thres_dn
	);

/****************************************************************************/
/* (3)	併走車判定処理														*/
/****************************************************************************/
	fn_bsm_side_check_leading_object(
		(const NORMAL_BSM *)tmp_normal,
		tmp_fm_obj_flg,
		tmp_fm_flg,
		&tmp_wall_flg,
		&tmp_leading_flg1,
		&tmp_leading_flg2,
		&tmp_sot_wall_angle,
		&tmp_sot_real_angle,
		tmp_normal_sot,
		&tmp_wall_reject_th
	);

/****************************************************************************/
/* (4)	壁判定処理															*/
/****************************************************************************/
	fn_bsm_side_check_wall(
		tmp_fm_obj_flg,
		tmp_leading_flg1,
		tmp_sot_wall_angle,
		tmp_sot_real_angle,
		(const NORMAL_BSM *)tmp_normal,
		&tmp_wall_flg,
		normal_wall,
		tmp_wall_reject_th
	);


/****************************************************************************/
/* (6)	壁トラッキング処理													*/
/****************************************************************************/
	fn_bsm_side_tracking_wall(
		tmp_fm_obj_flg,
		tmp_wall_flg,
		tmp_leading_flg1,
		tmp_leading_flg2,
		(const NORMAL_BSM *)tmp_normal,
		(const NORMAL_BSM *)normal_wall_prev,
		normal_wall
	);

/****************************************************************************/
/* (5)	併走車トラッキング処理												*/
/****************************************************************************/
	object_num = s4_bsm_side_tracking_heisou(
		tmp_fm_nearfield_power,
		tmp_fm_obj_flg,
		&tmp_leading_flg2,
		(const NORMAL_BSM *)normal_sot_prev,
		(const NORMAL_BSM *)tmp_normal_sot,
		normal_sot
	);

	/* 出力データをコピー */
	/* 壁 */
	fn_move(										/* PROC.4 of(6)4) */
		ast_a_normal_wall,
		normal_wall,
		1
	);
	st_g_bsm_loop_data.afl_wall_width[0] = ast_a_normal_wall[0].fl_Rxfil;		/* PROC.3 of(6)4) */

	/* 併走車 */
	if(st_g_bsm_loop_data.as4_slow_sot_find[1] > tmp_wall_reject_th)			/* COND.e12 */
	{
		fn_init(&normal_sot[0], 1 );				/* PROC.5 of(5)6) */
		object_num = 0;								/* PROC.6 of(5)6) */
	}
	fn_move(										/* PROC.4 of(5)6) */
		ast_a_normal_sot,
		normal_sot,
		1
	);

	st_g_bsm_loop_data.as4_flg_leading[0] = tmp_leading_flg2;				/* PROC.3 of(5)6) */

	/****************************************************************************/
	/* (8)  壁判定(FA 削除用)													*/
	/****************************************************************************/
	fn_bsm_side_check_wall_for_erase_fa_seg((const NORMAL_BSM *)tmp_normal, tmp_fm_obj_flg);

	return object_num;
}


/****************************************************************************/
/* 関数名		: fl_bsm_side_cal_fm_nearfield_power						*/
/*--------------------------------------------------------------------------*/
/* 機能			: FMCW信号（上り）の周波数スペクトルから、近接部の電力を算出*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (1)FMCW前側方物標判定処理 								*/
/*				:  1)FMCW近接電力の算出		 								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static FL fl_bsm_side_cal_fm_nearfield_power( VD )
{
	S4 i;
	FL fl_t_fm_nearfield_power;

	/***** 1) FMCW近接電力の算出. *****/
	fl_t_fm_nearfield_power = 0.0F;
	for(i = VI_TOS_END_FREQ_BIN; i < (VI_TOS_END_FREQ_BIN + SOT_FMPEAK_RANGE); i++)
	{
		fl_t_fm_nearfield_power += afl_g_cvw_lfm_ftt_power[0][i];
	}
	fl_t_fm_nearfield_power = fl_t_fm_nearfield_power/SOT_FMPEAK_RANGE;

	return fl_t_fm_nearfield_power;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check_leading_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3)	併走車判定処理										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)	併走車判定処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_wall_reject_th
)
{
	/***** 1) 併走車判定 1 *****/
	fn_bsm_side_check1_leading_object(
		(const NORMAL_BSM *)ast_a_normal_fm,
		s4_a_fm_obj_flg,
		s4_a_fm_flg,
		ps4_a_wall_flg,
		ps4_a_leading_flg1,
		ps4_a_wall_reject_th
	);

	/***** 2) 併走車判定 2 *****/
	fn_bsm_side_check2_leading_object(
		(const NORMAL_BSM *)ast_a_normal_fm,
		s4_a_fm_obj_flg,
		s4_a_fm_flg,
		ps4_a_wall_flg,
		ps4_a_leading_flg1,
		ps4_a_leading_flg2,
		pfl_a_sot_wall_angle,
		pfl_sot_real_angle
	);

	/***** 3) 併走車物標情報の設定 *****/
	fn_bsm_side_set_leading_object(
		*ps4_a_leading_flg2,
		(const NORMAL_BSM *)ast_a_normal_fm,
		ast_a_normal_sot
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check1_leading_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3)-1)併走車判定 1										*/
/*				:	前回併走車がいた場合は、そのまま併走車ありとし、		*/
/*				:	前回併走車がいなかった場合は、今回接近してきた併走車が	*/
/*				:	いるかを判定する。										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)併走車判定処理											*/
/*				:  1)併走車判定 1											*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check1_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_wall_reject_th
)
{
	FL tmp_sot_wall_diff;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if(st_g_bsm_loop_data.as4_low_speed_flg[0]==1)															/* COND.c15 */
	{
		*ps4_a_wall_reject_th = 3;																			/* PROC.5 */
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	/***** 1) 併走車判定 1 *****/
	if( *ps4_a_leading_flg1 == 0 ) {																		/* COND.c1 */
		/* FM物標 */
		if ((s4_a_fm_obj_flg != 0)																			/* COND.c2 */
		&&  (s4_a_fm_flg != 0)) {																			/* COND.c3 */
			if(st_g_bsm_loop_data.afl_wall_width[0]!=WALL_MAX) {											/* COND.c4 */
				tmp_sot_wall_diff = CFL_SOT_WALL_DIFF + st_g_bsm_loop_data.afl_installed_angle[1];			/* PROC.1 */
			} else {
				tmp_sot_wall_diff = SOT_WALL_DIFF_DEFAULT;													/* PROC.2 */
			}

			if (((st_g_bsm_loop_data.afl_wall_width[0] - ast_a_normal_fm[0].fl_Rxobs) > tmp_sot_wall_diff)	/* COND.c5 */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < *ps4_a_wall_reject_th)) {						/* COND.c6 */
				/* → 壁ではない */
				*ps4_a_wall_flg = 0;																		/* PROC.3 */
				*ps4_a_leading_flg1 = 1;																	/* PROC.4 */
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check2_leading_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3)-2)併走車判定 2										*/
/*				:	今回併走車がいると判定された場合は、壁か否かの判別により*/
/*				:	併走車の判定を行う。									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)併走車判定処理											*/
/*				:  2)併走車判定 2											*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check2_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle
)
{
	FL tmp_t_wall_diff_th;

	/***** 2) 併走車判定 2 *****/
	*pfl_a_sot_wall_angle = SOT_WALL_ANGLE_TH;												/* PROC.1 */
	tmp_t_wall_diff_th  = SOT_WALL_DIFF_FAST;												/* PROC.2 */
	if( fl_g_v_self_bsm_for_base < WALL_TRK_LOW_VSELF_TH ) {								/* COND.c7 */
		*pfl_a_sot_wall_angle = SOT_WALL_ANGLE_TH_FORWARD;									/* PROC.3 */
		tmp_t_wall_diff_th = SOT_WALL_DIFF_SLOW;											/* PROC.4 */
	}
	*pfl_sot_real_angle = 180.0F/PI*0.5F*(ast_a_normal_fm[0].fl_theta_up + ast_a_normal_fm[0].fl_theta_dn);		/* PROC.5 */

	if ((st_g_bsm_loop_data.as4_slow_sot_find[0] > 0)															/* COND.c8 */
	&&  (st_g_bsm_loop_data.afl_wall_width[0] != WALL_MAX)) {													/* COND.c4 */
		if (s4_a_fm_obj_flg != 0) {																				/* COND.c2 */
			/********* 壁より内側→壁ではない **********/
			if ((st_g_bsm_loop_data.afl_wall_width[0] - ast_a_normal_fm[0].fl_Rxobs) > tmp_t_wall_diff_th) {	/* COND.c9 */
				/* → 壁ではない & 併走車あり  */
				*ps4_a_wall_flg = 0;																			/* PROC.6 */
				*ps4_a_leading_flg1 = 1;																		/* PROC.7 */
				*ps4_a_leading_flg2 = 1;																		/* PROC.8 */
			} else {
				/********* 壁付近か外側→壁である可能性あり *********/
				if ((*pfl_sot_real_angle > *pfl_a_sot_wall_angle)												/* COND.c10 */
				&&  (*pfl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD)											/* COND.c11 */
				&&  (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN)) {										/* COND.c12 */
					/* → 壁 */
					*ps4_a_wall_flg = 1;																		/* PROC.9 */
					*ps4_a_leading_flg1 = 0;																	/* PROC.10 */
					*ps4_a_leading_flg2 = 0;																	/* PROC.11 */
				}

				if(st_g_bsm_loop_data.as4_slow_sot_find[1]==0) {												/* COND.c13 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = WALL_REJECT_TH3;									/* PROC.12 */
				}
			}
		}
	}

	/* (7)低速SoT判定処理 8)並走車存在判定で並走車ありと判定されている場合は、	*/
	/* 併走車判定結果を書き換え、強制的に併走車ありとする						*/
	if ((st_g_bsm_loop_data.u1_flg_heisou_car == (U1)1)		/* COND.c18 */
	&&	(s4_a_fm_obj_flg != (S4)0)) {						/* COND.c2 */
		*ps4_a_wall_flg = (S4)0;							/* PROC.6 */
		*ps4_a_leading_flg1 = (S4)1;						/* PROC.7 */
		*ps4_a_leading_flg2 = (S4)1;						/* PROC.8 */
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_set_leading_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3)-3)併走車物標情報の設定								*/
/*				:	併走車であると判定された場合は、前側方物標情報を		*/
/*				:	併走車物標情報にコピーする。							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)併走車判定処理											*/
/*				:  3)併走車物標情報の設定									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_set_leading_object(
	S4 s4_a_leading_flg2,						/* [in] */
	const NORMAL_BSM ast_a_normal_fm[1],		/* [in] */
	NORMAL_BSM ast_a_normal_heisou[1]			/* [out] */
)
{
	/***** 3) 併走車物標情報の設定 *****/
	if (s4_a_leading_flg2 != 0) {															/* COND.c14 */
		if (((ast_a_normal_fm[0].s4_bin_up < FREQ_BIN_LOWER_LIMIT)							/* COND.c16_up */
		&&   (ast_a_normal_fm[0].fl_power_up < PEAK_POW_TH_AROUND_CENTER))					/* COND.c17_up */
		||  ((ast_a_normal_fm[0].s4_bin_dn < FREQ_BIN_LOWER_LIMIT)							/* COND.c16_dn */
		&&   (ast_a_normal_fm[0].fl_power_dn < PEAK_POW_TH_AROUND_CENTER))) {				/* COND.c17_dn */
			/* 何もしない */
		} else {
			/* 候補データを併走車NORMAL_BSMにコピー */
			fn_move(																		/* PROC.1 */
				ast_a_normal_heisou,
				ast_a_normal_fm,
				1
			);
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check_wall									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)壁判定処理												*/
/*				:	前側方物標判定処理、物標接近判定処理、併走車判定処理の	*/
/*				:	結果から、車両前側方の物標が車であるかの判定を行う。	*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)壁判定処理												*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 *ps4_a_wall_flg,
	NORMAL_BSM ast_a_normal_wall[1],
	S4 s4_a_wall_reject_th
)
{

	/***** 1) 壁判定 *****/
	fn_bsm_side_check1_wall(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		fl_a_sot_wall_angle,
		fl_sot_real_angle,
		ps4_a_wall_flg,
		s4_a_wall_reject_th
	);
	
	/***** 2) 壁物標情報の設定 *****/
	fn_bsm_side_set_wall_object(
		*ps4_a_wall_flg,
		(const NORMAL_BSM *)ast_a_normal_fm,
		ast_a_normal_wall
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check1_wall									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)-1) 壁判定												*/
/*				:	今回併走車がいなと判定され、前回追越車もいなかった場合は*/
/*				:	検出された前側方物標は壁である可能性があるため、		*/
/*				:	今回検出した前側方物標が壁か否かの判定を行う。			*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)-1) 壁判定												*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check1_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	S4 *ps4_a_wall_flg,
	S4 s4_a_wall_reject_th
)
{
	/***** 1) 壁判定 *****/
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((s4_a_leading_flg1 == 0)													/* COND.c1 */
	&&  (st_g_bsm_loop_data.as4_flg_passing[0] <= PASSING_COUNT_MIN)				/* COND.d1 */
	&&  (s4_a_fm_obj_flg != 0)														/* COND.c2 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > s4_a_wall_reject_th)) {			/* COND.d2 */
		if (fl_sot_real_angle > fl_a_sot_wall_angle) {								/* COND.c10 */
			*ps4_a_wall_flg = 1;													/* PROC.1 */
		}
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((s4_a_leading_flg1 == (S4)0)												/* COND.c1 */
	&&  (s4_a_fm_obj_flg != (S4)0)													/* COND.c2 */
	&&  (fl_sot_real_angle > fl_a_sot_wall_angle)									/* COND.c10 */
	&&  ((st_g_bsm_loop_data.as4_flg_passing[0] <= (S4)PASSING_COUNT_MIN)			/* COND.d1 */
	||   ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] < (S4)CFL_WALL_DEV_TH12)	/* COND.d100 */
	&&    (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] < (S4)WALL_DEV_TH1)))	/* COND.d101 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > s4_a_wall_reject_th)) {			/* COND.d2 */
		if ((!(st_g_bsm_loop_data.as4_low_speed_flg[0] == (S4)1))					/* COND.!c15 */
		&&  (st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)) {				/* COND.g53 */
			if ((fl_sot_real_angle > fl_a_sot_wall_angle)							/* COND.c10 */
			&&  (fl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD)) {					/* COND.c11 */
				*ps4_a_wall_flg = (S4)1;												/* PROC.1 */
			}
		} else {
			if (fl_sot_real_angle > fl_a_sot_wall_angle) {							/* COND.c10 */
				*ps4_a_wall_flg = (S4)1;												/* PROC.1 */
			}
		}
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	if ((s4_a_leading_flg1 == 0)											/* COND.c1 */
	&&  (fl_g_v_self_bsm_for_base < WALL_TRK_LOW_VSELF_TH)					/* COND.d12 */
	&&  (s4_a_fm_obj_flg != 0)												/* COND.c2 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > 1)) {					/* COND.d13 */
		if (fl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD) {				/* COND.c11 car coord. */
			*ps4_a_wall_flg = 1;
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_set_wall_object								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (4)-2) 壁物標情報の設定									*/
/*				:	壁であると判定された場合、前側方物標情報を壁物標情報に	*/
/*				:	コピーする。また、ピーク検出限界以下に近接している場合の*/
/*				:	壁距離の補正を行う。									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)-2) 壁物標情報の設定									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_set_wall_object(
	S4 s4_a_wall_flg,
	const NORMAL_BSM ast_a_normal_fm[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 2) 壁物標情報の設定 *****/
	if (s4_a_wall_flg != 0) {												/* COND.d3 */
		/* 候補データを壁NORMAL_BSMにコピー */
		fn_move(															/* PROC.1 */
			ast_a_normal_wall,
			ast_a_normal_fm,
			1
		);

		/* より近い壁対応 */
		if ((ast_a_normal_wall[0].s4_bin_up <= ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1 + 1))						/* COND.d4 */
		&&  (ast_a_normal_wall[0].s4_bin_dn <= ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1 + 1))) {					/* COND.d5 */
			if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH1)								/* COND.d6 */
			&&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH1)) {								/* COND.d7 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN;			/* PROC.2 */
			} else if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH2)							/* COND.d8 */
				   &&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH2)) {						/* COND.d9 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN + 0.5F;	/* PROC.3 */
			} else if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH3)							/* COND.d10 */
				   &&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH3)) {						/* COND.d11 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN + 1.0F;	/* PROC.4 */
			} else {
				/* 何もしない */
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_tracking_wall									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)壁トラッキング処理										*/
/*				:	壁判定処理の結果に基づき、壁物標のトラッキング処理を行い*/
/*				:	壁物標情報を更新する。									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)壁トラッキング処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_wall_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 1) 今回の壁判定処理結果の判定 *****/
	if (s4_a_wall_flg != 0) {																/* COND.d4 */
		/***** 2) 今回の観測値ありのトラッキング *****/
		fn_bsm_side_tracking_wall_with_obs(
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	} else {
		/***** 3) 今回の観測値なしのトラッキング *****/
		fn_bsm_side_tracking_wall_without_obs(
			s4_a_fm_obj_flg,
			s4_a_leading_flg1,
			s4_a_leading_flg2,
			(const NORMAL_BSM *)ast_a_normal_fm,
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	}

	/***** 4) 壁距離上限・下限の確認 *****/
	fn_bsm_side_guard_wall_rxfil(
		ast_a_normal_wall
	);

	st_g_bsm_loop_data.afl_wall_width[0] = ast_a_normal_wall[0].fl_Rxfil;					/* PROC.3 */

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_tracking_wall_with_obs						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-2)今回の観測値ありのトラッキング						*/
/*				:	(ⅰ)今回の壁物標情報の補正								*/
/*				:	(ⅱ)次回の予測値を算出									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-2)今回の観測値ありのトラッキング						*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall_with_obs(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 2) 今回の観測値ありのトラッキング *****/
	/* ■■■■■ (ⅰ)今回の壁物標情報の補正 ■■■■■ */
	fn_bsm_side_intpl_cur_wall_object(
		(const NORMAL_BSM *)ast_a_normal_wall_prev,
		ast_a_normal_wall
	);

	/* ■■■■■ (ⅱ)次回の予測値を算出1 ■■■■■ */
	/* トラッキング(αβトラッカ) */
	fn_ab_track_wall(													/* SEC.3-1(7)6) */
		&ast_a_normal_wall_prev[0],
		&ast_a_normal_wall[0],
		0
	);
	fn_calc_prediction_of_normaldata(
		&ast_a_normal_wall[0]
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_intpl_cur_wall_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-2)-(ⅰ)今回の壁物標情報の補正							*/
/*				:	壁の突起物や路側停止帯などによる、突発的な壁までの距離の*/
/*				:	範囲の変化の影響を軽減するため、以下の処理を行う。		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-2)-(ⅰ)今回の壁物標情報の補正							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_intpl_cur_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],			/* [in]  */
	NORMAL_BSM ast_a_normal_wall[1]						/* [out] */
)
{
	/* 大きく広がるときは小さくする */
	if ((ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) > SOT_WALL_WIDEN_DIFF_TH) {		/* COND.f1 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_WIDEN_COEF*(ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil)+ast_a_normal_wall_prev[0].fl_Rxfil;	/* PROC.1 */
		ast_a_normal_wall[0].fl_Vxobs = SOT_WALL_WIDEN_COEF*ast_a_normal_wall[0].fl_Vxobs;				/* PROC.2 */
	}

	/* 大きく狭まるときは少し小さくする */
	if ((ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) < SOT_WALL_NARROW_DIFF_TH) {		/* COND.f2 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_NARROW_COEF*(ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) + ast_a_normal_wall_prev[0].fl_Rxfil;	/* PROC.3 */
		ast_a_normal_wall[0].fl_Vxobs = SOT_WALL_NARROW_COEF*ast_a_normal_wall[0].fl_Vxobs;					/* PROC.4 */
	}

	/* 上限・下限チェック */
	if (ast_a_normal_wall[0].fl_Rxobs > SOT_WALL_MAX ) {									/* COND.f3 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_MAX;										/* PROC.5 */
	}
	if (ast_a_normal_wall[0].fl_Rxobs < WALL_MIN ) {										/* COND.f4 */
		ast_a_normal_wall[0].fl_Rxobs = WALL_MIN;											/* PROC.6 */
	}

	ast_a_normal_wall[0].fl_Vyobs = 0.0F;															/* PROC.7 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up_music;			/* PROC.8 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn_music;			/* PROC.9 */

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_tracking_wall_without_obs						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)今回の観測値なしのトラッキング						*/
/*				:	(ⅰ)前回の壁物標情報の確認								*/
/*				:	(ⅱ)次回の予測値を算出1									*/
/*				:	(ⅲ)次回の予測値を算出２								*/
/*				:	(ⅳ)次回の予測値を算出３								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)今回の観測値なしのトラッキング						*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall_without_obs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	FL fl_t_wall_pos;

	fl_t_wall_pos = 0.0F;

	/* ■■■■■ (ⅰ)前回の壁物標情報の確認 ■■■■■ */
	fn_bsm_side_confirm_prev_wall_object(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		s4_a_leading_flg2,
		(const NORMAL_BSM *)ast_a_normal_fm,
		&fl_t_wall_pos
	);
	
	if( ast_a_normal_wall_prev[0].fl_Rxpred < fl_t_wall_pos ) {
		/* ■■■■■ (ⅱ)次回の予測値を算出1 ■■■■■ */
		fn_bsm_side_cal1_next_wall_object(
			s4_a_fm_obj_flg,
			s4_a_leading_flg1,
			s4_a_leading_flg2,
			fl_t_wall_pos,
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	} else {
		if( s4_a_fm_obj_flg != 0 ) {													/* COND.c2 */
			/* ■■■■■ (ⅲ)次回の予測値を算出２ ■■■■■ */
			fn_bsm_side_cal2_next_wall_object(
				fl_t_wall_pos,
				(const NORMAL_BSM *)ast_a_normal_wall_prev,
				ast_a_normal_wall
			);
		} else {
			/* ■■■■■ (ⅳ)次回の予測値を算出３ ■■■■■ */
			fn_bsm_side_cal3_next_wall_object(
				(const NORMAL_BSM *)ast_a_normal_wall_prev,
				ast_a_normal_wall
			);
		}
		
		/* 壁最大距離 */
		fn_bsm_side_guard_wall_xpred(
			ast_a_normal_wall
		);
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_confirm_prev_wall_object						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)-(ⅰ)前回の壁物標情報の確認							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(ⅰ)前回の壁物標情報の確認							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_confirm_prev_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	FL *pfl_a_wall_pos
)
{
	/* ->前回予測値から次回値を予測 */
	/* ■■■■■ (ⅰ)前回の壁物標情報の確認 ■■■■■ */
	if (s4_a_fm_obj_flg != 0 ) {														/* COND.c2 */
		*pfl_a_wall_pos = ast_a_normal_fm[0].fl_Rxobs;									/* PROC.1 */
	} else {
		*pfl_a_wall_pos = WALL_MAX;														/* PROC.2 */
	}

	if ((s4_a_leading_flg1 != 0)														/* COND.c1 */
	||  (s4_a_leading_flg2 != 0)														/* COND.c14 */
	||  (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN)						/* COND.!d1 */
	||  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] > 0)) {					 	/* COND.f5 */
		if (*pfl_a_wall_pos < WALL_MAX) {												/* COND.f6 */
			*pfl_a_wall_pos = WALL_MAX;													/* PROC.2 */
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_cal1_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)-(ⅱ)次回の予測値を算出1							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(ⅱ)次回の予測値を算出1							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal1_next_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	fn_init(&ast_a_normal_wall[0], 1);													/* PROC.3 */
	ast_a_normal_wall[0].fl_Ryobs = 0.0F;												/* PROC.4-1 */
	ast_a_normal_wall[0].fl_Ryfil = 0.0F;												/* PROC.4-2 */
	ast_a_normal_wall[0].fl_Rypred = 0.0F;												/* PROC.4-3 */

	ast_a_normal_wall[0].fl_Rxobs = fl_bsm_side_cal1_cal_wall_rxobs(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		s4_a_leading_flg2,
		fl_a_wall_pos,
		(const NORMAL_BSM *)ast_a_normal_wall_prev
	);

	ast_a_normal_wall[0].fl_Rxfil = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-1 */
	ast_a_normal_wall[0].fl_Rxpred = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-2 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-3 */
	ast_a_normal_wall[0].fl_Robs_pred = ast_a_normal_wall[0].fl_Rxpred;																			/* PROC.11-4 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up_music;														/* PROC.11-5 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn_music;														/* PROC.11-6 */
	ast_a_normal_wall[0].fl_doa_up_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_up_music_pred;											/* PROC.11-7 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_dn_music_pred;											/* PROC.11-8 */
	ast_a_normal_wall[0].fl_bin_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up;															/* PROC.11-9 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn;															/* PROC.11-10 */
	ast_a_normal_wall[0].fl_bin_up_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_up_pred;													/* PROC.11-11 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_dn_pred;													/* PROC.11-12 */

	return;
}


/****************************************************************************/
/* 関数名		: fl_bsm_side_cal1_cal_wall_rxobs							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)-(ⅱ)次回の予測値を算出1							*/
/*				:	壁物標情報のX方向距離観測値の設定や更新					*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(6)-3)-(ⅱ)次回の予測値を算出1 							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static FL fl_bsm_side_cal1_cal_wall_rxobs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1]
)
{
	FL fl_t_rxobs;

	if (s4_a_leading_flg1 == 0) {																									/* COND.c1 */
		if (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN) {															/* COND.!d1 */
			/* 壁の距離を元に戻す(ゆっくり) */
			fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA) + WALL_LOST_ALPHA*fl_a_wall_pos;					/* PROC.8 */
		} else {
			if (fl_g_v_self_bsm_for_base > WALL_RET_LOW_VSELF_TH) {																	/* COND.f8 */
				if (s4_a_fm_obj_flg != 0) {																							/* COND.c2 */
					/* 壁の距離を元に戻す(ちょっとはやめ) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				} else {
					/* 壁の距離を元に戻す(ちょっとはやめ) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				}
			} else {
				if (s4_a_fm_obj_flg != 0) {																							/* COND.c2 */
					/* 壁の距離を元に戻す(ちょっとはやめ) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				} else {
					/* 壁の距離はそのまま */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil;																/* PROC.6 */
				}
			}
		}
	} else {
		/* 並走車あり */
		if (fl_g_v_self_bsm_for_base > WALL_RET_LOW_VSELF_TH) {																		/* COND.f8 */
			/* 壁の距離を元に戻す（はやめ） */
			fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_FAST) + WALL_LOST_ALPHA_FAST*fl_a_wall_pos;			/* PROC.7 */
		} else {
			if ((s4_a_fm_obj_flg != 0)																								/* COND.c2 */
			&&  (s4_a_leading_flg2 == 0)) {																							/* COND.!c1 */
				/* 壁の距離を元に戻す(ちょっとはやめ) */
				fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;		/* PROC.5 */
			} else {
				/* 壁の距離はそのまま */
				fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil;																	/* PROC.6 */
			}
		}
	}
	if (fl_t_rxobs > fl_a_wall_pos) {										/* COND.f9 */
		fl_t_rxobs = fl_a_wall_pos;											/* PROC.9 */
	}
	if (fl_t_rxobs < WALL_MIN) {											/* COND.f10 */
		fl_t_rxobs = WALL_MIN;												/* PROC.10 */
	}

	return fl_t_rxobs;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_cal2_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)-(ⅲ)次回の予測値を算出２							*/
/*				:	⑤壁物標情報のX方向距離観測値を更新						*/
/*				:	⑫壁物標情報の情報を更新								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(ⅲ)次回の予測値を算出２							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal2_next_wall_object(
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* 壁の距離を元に戻す(ちょっとはやめ) */
	ast_a_normal_wall[0].fl_Rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;			/* PROC.5 */
	ast_a_normal_wall[0].fl_Rxfil = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-1 */
	ast_a_normal_wall[0].fl_Rxpred = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-2 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-3 */
	ast_a_normal_wall[0].fl_Robs_pred = ast_a_normal_wall[0].fl_Rxpred;																		/* PROC.12-4 */

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_cal3_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)-(ⅳ)次回の予測値を算出３							*/
/*				:	⑬今回の壁物標情報に前回の壁物標情報の予測値をコピー	*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(ⅳ)次回の予測値を算出３							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal3_next_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* 前回の予測値を今回の計測値としてコピー */
	ast_a_normal_wall[0].s4_bin_up = ast_a_normal_wall_prev[0].s4_bin_up_pred;																/* PROC.13-1 */
	ast_a_normal_wall[0].s4_bin_dn = ast_a_normal_wall_prev[0].s4_bin_dn_pred;																/* PROC.13-2 */
	ast_a_normal_wall[0].fl_bin_up_interpolate = ast_a_normal_wall_prev[0].fl_bin_up_interpolate_pred;										/* PROC.13-3 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate = ast_a_normal_wall_prev[0].fl_bin_dn_interpolate_pred;										/* PROC.13-4 */
	ast_a_normal_wall[0].s4_bin_up_music = ast_a_normal_wall_prev[0].s4_bin_up_music_pred;													/* PROC.13-5 */
	ast_a_normal_wall[0].s4_bin_dn_music = ast_a_normal_wall_prev[0].s4_bin_dn_music_pred;													/* PROC.13-6 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = ast_a_normal_wall_prev[0].fl_doa_up_interpolate_pred;										/* PROC.13-7 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = ast_a_normal_wall_prev[0].fl_doa_dn_interpolate_pred;										/* PROC.13-8 */
	ast_a_normal_wall[0].fl_theta_up = ast_a_normal_wall_prev[0].fl_theta_up_pred;															/* PROC.13-9 */
	ast_a_normal_wall[0].fl_theta_dn = ast_a_normal_wall_prev[0].fl_theta_dn_pred;															/* PROC.13-10 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall_prev[0].fl_Robs_pred;																	/* PROC.13-11 */
	ast_a_normal_wall[0].fl_Vobs = ast_a_normal_wall_prev[0].fl_Vobs_pred;																	/* PROC.13-12 */
	ast_a_normal_wall[0].fl_Rxobs = ast_a_normal_wall_prev[0].fl_Rxpred;																	/* PROC.13-13 */
	ast_a_normal_wall[0].fl_Vxobs = ast_a_normal_wall_prev[0].fl_Vxpred;																	/* PROC.13-14 */
	ast_a_normal_wall[0].fl_Ryobs = ast_a_normal_wall_prev[0].fl_Rypred*(1-WALL_LOST_ALPHA_FAST) + WALL_LOST_ALPHA_FAST*0.0F;				/* PROC.13-15 */
	ast_a_normal_wall[0].fl_Vyobs = 0.0F;																									/* PROC.13-16 */
	/* トラッキング(αβトラッカ) */
	fn_ab_track_wall(																							/* SEC.3-1(7)6) */
		&ast_a_normal_wall_prev[0],
		&ast_a_normal_wall[0],
		0
	);
	fn_calc_prediction_of_normaldata(
		&ast_a_normal_wall[0]
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_guard_wall_xpred								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-3)壁最大距離											*/
/*				:	⑭今回の壁物標情報のX方向距離予測値を上限に設定			*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)壁最大距離											*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_guard_wall_xpred(
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* 壁最大距離 */
	if( ast_a_normal_wall[0].fl_Rxpred > SOT_WALL_MAX ) {								/* COND.f11 */
		ast_a_normal_wall[0].fl_Rxpred = SOT_WALL_MAX;									/* PROC.14 */
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_guard_wall_rxfil								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (6)-4) 壁距離上限・下限の確認								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-4) 壁距離上限・下限の確認								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_guard_wall_rxfil(
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 4) 壁距離上限・下限の確認 *****/
	if (ast_a_normal_wall[0].fl_Rxfil > SOT_WALL_MAX) {										/* COND.f12 */
		ast_a_normal_wall[0].fl_Rxfil = SOT_WALL_MAX;										/* PROC.1 */
	}
	if (ast_a_normal_wall[0].fl_Rxfil < WALL_MIN) {											/* COND.f13 */
		ast_a_normal_wall[0].fl_Rxfil = WALL_MIN;											/* PROC.2 */
	}

	return;
}


/****************************************************************************/
/* 関数名		: s4_bsm_side_tracking_heisou								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)併走車トラッキング処理									*/
/*				:	併走車判定処理の結果に基き、併走車物標のトラッキング処理*/
/*				:	を行い、併走車物標情報を更新する。						*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)併走車トラッキング処理									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou(
	FL fl_a_fm_nearfield_power,
	S4 s4_a_fm_obj_flg,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4	s4_t_object_num;

	s4_t_object_num = 0;

	/***** 1) 今回の併走車判定処理結果の判定 *****/
	ast_a_normal_sot[0].s4_flg_new = 0;

	/* 併走車がありと判定 */
	if (*ps4_a_leading_flg2 != 0) {														/* COND.c14 */
		/* 今回の観測値がある */
		if (s4_a_fm_obj_flg != 0) {														/* COND.c2  */
			s4_t_object_num = s4_bsm_side_tracking_heisou_with_obs(
				fl_a_fm_nearfield_power,
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot_prev,
				(const NORMAL_BSM *)ast_a_normal_sot_heisou,
				ast_a_normal_sot
			);
		/* 今回の観測値がない */
		} else {
			/***** 4) 今回の観測値なし，前回の予測値ありのトラッキング *****/
			s4_t_object_num = s4_bsm_side_tracking_heisou_without_obs(
				fl_a_fm_nearfield_power,
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot_prev,
				ast_a_normal_sot
			);
		}
		
		if (*ps4_a_leading_flg2 != 0) {													/* COND.c14 */
			/***** 6) トラッキング範囲の判定. *****/
			fn_bsm_side_check_tracking_heisou_range(
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot
			);
		}
	/* 前回も今回も併走車なし */
	} else {
		/***** 5) 今回の観測値なし，前回の予測値なしのトラッキング *****/
		/* -> リセット */
		fn_init(&ast_a_normal_sot[0], 1);												/* PROC.1 */
		*ps4_a_leading_flg2 = 0;														/* PROC.2 */
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* 関数名		: s4_bsm_side_tracking_heisou_with_obs						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)-2)今回の観測値あり、前回の観測値ありのトラッキング	*/
/*				: (5)-3)今回の観測値あり、前回の観測値なしのトラッキング	*/
/*				:	今回の観測値がある場合のトラッキング					*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)-2)今回の観測値あり、前回の観測値ありのトラッキング	*/
/*				: (5)-3)今回の観測値あり、前回の観測値なしのトラッキング	*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou_with_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 s4_t_object_num;

	s4_t_object_num = 0;

	/* 今回の観測値をNORMAL_BSMデータセット */
	fn_move(
		ast_a_normal_sot,
		ast_a_normal_sot_heisou,
		1
	);
	ast_a_normal_sot[0].s4_flg_heiso_up = 1;													/* PROC.1-1 */
	ast_a_normal_sot[0].s4_flg_heiso_dn = 1;													/* PROC.1-2 */
	ast_a_normal_sot[0].s4_flg_dc = OBJECT_TYPE_SOT;											/* PROC.2 */

	if ((ast_a_normal_sot_prev[0].fl_Rxpred != CFL_UNKNOWN_VALUE)								/* COND.e1 */
	&&  (ast_a_normal_sot_prev[0].fl_Rypred != CFL_UNKNOWN_VALUE)) {							/* COND.e2 */
		/***** 2) 今回の観測値あり，前回の予測値ありのトラッキング *****/
		/* ->αβトラッキング */
		/* トラッキング(αβトラッカ) */
		fn_ab_track(												/* SEC.3-1(7)6) */
			&ast_a_normal_sot_prev[0],
			&ast_a_normal_sot[0],
			0
		);
		fn_calc_prediction_of_normaldata(
			&ast_a_normal_sot[0]
		);

		if (ast_a_normal_sot[0].s4_flg_track == CS4_S4MAX) {
			/* S4の最大値であるため加算しない */
		} else {
			ast_a_normal_sot[0].s4_flg_track = ast_a_normal_sot_prev[0].s4_flg_track +1;		/* PROC.1 */
		}

		ast_a_normal_sot[0].s4_flg_lost = 0;													/* PROC.2 */
		s4_t_object_num = 1;																	/* PROC.3 */
	} else {
		if (fl_a_fm_nearfield_power > CFL_SLOW_SOT_POW_TH) {									/* COND.e3 */
			/***** 3) 今回の観測値あり，前回の予測値なしのトラッキング *****/
			/* ->新規物標：今回値から次回値を予測 */
			S4 tmptmp_erased_num = 0;
			/* トラッカ情報生成 */
			S4 tmptmp_passing_flg[1];
			S4 tmptmp_leading_flg[1];
			tmptmp_passing_flg[0] = (S4)0;
			tmptmp_leading_flg[0] = *ps4_a_leading_flg2;
			tmptmp_erased_num = s4_start_prediction(								/* SEC.3-1(6) */
				ast_a_normal_sot,				/* [in/out] */
				1,						/* [in] */
				1,						/* [in] */
				(const S4 (*))tmptmp_passing_flg,		/* [in] */
				(const S4 (*))tmptmp_leading_flg		/* [in] */
			);
			/* trim normal data */
			s4_t_object_num = s4_copy_prediction_to_filtered_data(
				ast_a_normal_sot,
				1
			);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			if (tmptmp_erased_num==1)			/* 不具合ではないか？ leading_flg2 の初期化がない */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_t_object_num == (S4)0)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			{
				fn_init(&ast_a_normal_sot[0], 1);
			} else {																/* (=COND.e12) */
				/* 無理やり優先物標化 */
				ast_a_normal_sot[0].s4_flg_new = 1;										/* PROC.2 */
				ast_a_normal_sot[0].s4_flg_track = PRIOR_TRK_NUM+1;						/* PROC.3 */
			}
		} else {
			/***** 5) 今回の観測値なし，前回の予測値なしのトラッキング *****/
			fn_init(&ast_a_normal_sot[0], 1);								/* PROC.1 */
			*ps4_a_leading_flg2 = 0;										/* PROC.2 */
		}
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* 関数名		: s4_bsm_side_tracking_heisou_without_obs					*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)-4) 今回の観測値なし、前回の予測値ありのトラッキング	*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)-4) 今回の観測値なし、前回の予測値ありのトラッキング	*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou_without_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 s4_t_object_num;
	
	s4_t_object_num = 0;

	/***** 4) 今回の観測値なし，前回の予測値ありのトラッキング *****/
	/* ->外挿：前回予測値から次回値を予測 */
	if ((ast_a_normal_sot_prev[0].fl_Rxpred != CFL_UNKNOWN_VALUE)								/* COND.e1 */
	&&  (ast_a_normal_sot_prev[0].fl_Rypred != CFL_UNKNOWN_VALUE)								/* COND.e2 */
	&&  (fl_a_fm_nearfield_power > CFL_SLOW_SOT_POW_TH2)										/* COND.e3' */
	&&  (ast_a_normal_sot_prev[0].s4_flg_lost < SOT_LOST_NUM_MAX)) {							/* COND.e4 */
		/* 前回の予測値を今回の計測値としてコピー */
		ast_a_normal_sot[0].s4_bin_up = ast_a_normal_sot_prev[0].s4_bin_up_pred;							/* PROC.1-1 */
		ast_a_normal_sot[0].s4_bin_dn = ast_a_normal_sot_prev[0].s4_bin_dn_pred;							/* PROC.1-2 */
		ast_a_normal_sot[0].fl_bin_up_interpolate = ast_a_normal_sot_prev[0].fl_bin_up_interpolate_pred;	/* PROC.1-3 */
		ast_a_normal_sot[0].fl_bin_dn_interpolate = ast_a_normal_sot_prev[0].fl_bin_dn_interpolate_pred;	/* PROC.1-4 */
		ast_a_normal_sot[0].s4_bin_up_music = ast_a_normal_sot_prev[0].s4_bin_up_music_pred;				/* PROC.1-5 */
		ast_a_normal_sot[0].s4_bin_dn_music = ast_a_normal_sot_prev[0].s4_bin_dn_music_pred;				/* PROC.1-6 */
		ast_a_normal_sot[0].fl_doa_up_interpolate = ast_a_normal_sot_prev[0].fl_doa_up_interpolate_pred;	/* PROC.1-7 */
		ast_a_normal_sot[0].fl_doa_dn_interpolate = ast_a_normal_sot_prev[0].fl_doa_dn_interpolate_pred;	/* PROC.1-8 */
		ast_a_normal_sot[0].fl_theta_up = ast_a_normal_sot_prev[0].fl_theta_up_pred;						/* PROC.1-9 */
		ast_a_normal_sot[0].fl_theta_dn = ast_a_normal_sot_prev[0].fl_theta_dn_pred;						/* PROC.1-10 */
		ast_a_normal_sot[0].fl_Robs = ast_a_normal_sot_prev[0].fl_Robs_pred;								/* PROC.1-11 */
		ast_a_normal_sot[0].fl_Rxobs = ast_a_normal_sot_prev[0].fl_Rxpred;									/* PROC.1-12 */
		ast_a_normal_sot[0].fl_Ryobs = ast_a_normal_sot_prev[0].fl_Rypred;									/* PROC.1-13 */
		ast_a_normal_sot[0].fl_Vobs = ast_a_normal_sot_prev[0].fl_Vobs_pred;								/* PROC.1-14 */
		ast_a_normal_sot[0].fl_Vxobs = ast_a_normal_sot_prev[0].fl_Vxpred;									/* PROC.1-15 */
		ast_a_normal_sot[0].fl_Vyobs = ast_a_normal_sot_prev[0].fl_Vypred;									/* PROC.1-16 */

		/* トラッキング(αβトラッカ) */
		fn_ab_track(												/* SEC.3-1(7)6) */
			&ast_a_normal_sot_prev[0],
			&ast_a_normal_sot[0],
			0
		);
		fn_calc_prediction_of_normaldata(
			&ast_a_normal_sot[0]
		);

		if (ast_a_normal_sot[0].s4_flg_track == CS4_S4MAX) {
			/* S4の最大値であるため加算しない */
		} else {
			ast_a_normal_sot[0].s4_flg_track = ast_a_normal_sot_prev[0].s4_flg_track +1;					/* PROC.1 */
		}

		ast_a_normal_sot[0].s4_flg_lost = ast_a_normal_sot_prev[0].s4_flg_lost + 1;						/* PROC.2 */
		s4_t_object_num = 1;																			/* PROC.3 */

	} else {
	/***** 5) 今回の観測値なし，前回の予測値なしのトラッキング *****/
	/* ->リセット */
		fn_init(ast_a_normal_sot, 1);												/* PROC.1 */
		*ps4_a_leading_flg2 = 0;													/* PROC.2 */
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check_tracking_heisou_range					*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)-6)トラッキング範囲の判定								*/
/*				:	併走車物標が追跡条件を満たすか確認し、条件を満たさない	*/
/*				:	ときは併走車フラグをオフにする。						*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(5)-6)トラッキング範囲の判定							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_tracking_heisou_range(
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot[1]
)
{
	FL tmp_Rxmax;

	/***** 6) トラッキング範囲の判定. *****/
	/* 予測値の確認 */
	if (*ps4_a_leading_flg2 != 0) {															/* COND.c14 */
		/* トラッキング範囲の判定（外に出たらフラグオフ） */
		tmp_Rxmax = WALL_MAX;
		if (st_g_bsm_loop_data.afl_wall_width[0] < WALL_MAX) {								/* COND.e5 */
			tmp_Rxmax = st_g_bsm_loop_data.afl_wall_width[0];								/* PROC.1 */
		}

		if ((ast_a_normal_sot[0].fl_Rxpred < SOT_TRACK_XMIN)								/* COND.e6 */
		||  (ast_a_normal_sot[0].fl_Rxpred > tmp_Rxmax)										/* COND.e7 */
		||  (ast_a_normal_sot[0].fl_Rypred > SOT_TRACK_YMAX)								/* COND.e8 */
		||  (ast_a_normal_sot[0].fl_Rypred < SOT_TRACK_YMIN)) {								/* COND.e9 */
			*ps4_a_leading_flg2 = 0;														/* PROC.2 */
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_side_check_wall_for_erase_fa_seg					*/
/*--------------------------------------------------------------------------*/
/* 機能			: 壁判定(FA 削除用)											*/
/*--------------------------------------------------------------------------*/
/* 引数			: ast_a_normal_sot_ena[1]		: 前側方物標情報 [in]		*/
/*				  s4_a_fm_obj_flg				: 前側方物標存在フラグ [in]	*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-009 (8)壁判定(FA 削除用)		*/
/****************************************************************************/
VD fn_bsm_side_check_wall_for_erase_fa_seg(const NORMAL_BSM ast_a_normal_sot_ena[1], S4 s4_a_fm_obj_flg)
{
	FL fl_t_diff_x;

	/**** 1)FMCW 物標 安定検出判定 ****/
	/* (i) 前提条件の判定 */
	if ((!(fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN))			/* COND.not(m1) */
	||  (s4_a_fm_obj_flg != (S4)1)) {									/* COND.m2 */
		/* 実施条件にそぐわない場合はデータ初期化し、2)壁判定 へ */
		st_g_bsm_loop_data.fl_fm_obj_x_pre = CFL_UNKNOWN_VALUE;
		/* ↓fl_fm_obj_x_preをCFL_UNKNOWN_VALUE(無効値)にしたので、合わせてセットする有効フラグもOFFにする */
		/* ↓fl_fm_obj_x_preとu1_flg_fm_obj_x_pre_enableは必ず連動させること */
		st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable = CU1_DF_OFF;
		st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)0;
	} else {
		/* (ii) FM 物標横位置確認 */
		/* 条件m3は仕様書ではfm_obj_x_pre != CFL_UNKNOWN_VALUEであるが、浮動小数同士の等式は禁止されている。 */
		/* そのため、FM物標横位置有効フラグu1_flg_fm_obj_x_pre_enableを用意し、そちらを確認するようにしている */
		/* やりたいことは実現できているので問題なし */
		/* Proc.1 */
		if (st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable == CU1_DF_ON) {			/* COND.m3の代わりに有効フラグを見ている */
			/* 条件 m3 成立時、FM 物標横位置変化量を算出する */
			/* なお、横位置はフィルタ値ではなく観測値を使用する */
			fl_t_diff_x = fl_abs(ast_a_normal_sot_ena[0].fl_Rxobs - st_g_bsm_loop_data.fl_fm_obj_x_pre);

			/* Proc.2 */
			/* FM物標横位置変化量が小さいとき、FM物標安定カウンタをカウントアップする */
			if (fl_t_diff_x < (FL)0.5F) {			/* COND.m4 */
				st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_fm_object_stable_count, (S2)1, (U2)100, (U2)0);	/* PROC.1 */
			} else {
				/* FM物標横位置変化量が大きいとき、FM物標安定カウンタを初期化する */
				st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)0;																						/* PROC.2 */
			}
		}
		
		/* Proc.3 */
		/* 今回のFM物標横位置を保存する */
		st_g_bsm_loop_data.fl_fm_obj_x_pre = ast_a_normal_sot_ena[0].fl_Rxobs;			/* PROC.3 */
		/* ↓fl_fm_obj_x_preに今回の横位置の値(有効値)を設定したので、合わせてセットする有効フラグもONにする */
		/* ↓fl_fm_obj_x_preとu1_flg_fm_obj_x_pre_enableは必ず連動させること */
		st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable = CU1_DF_ON;
	}

	/**** 2)壁判定 ****/
	/* 2FCWの壁判定結果と、1)のFM物標安定検出結果から、真横が壁か判定する */
	if (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN) {							/* COND.m1 */
		if (st_g_bsm_loop_data.as4_slow_sot_find[1] > (S4)WALL_REJECT_TH3) {		/* COND.m5 */
			/* 2FCWでの壁判定結果が壁っぽい → 壁フラグON */
			st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)1;					/* PROC.4 */
		} else if (st_g_bsm_loop_data.u1_fm_object_stable_count >= (U1)38) {		/* COND.m6 */
			/* FM物標位置が壁付近で安定 → 壁判定結果保持するので何もしない */
		} else {
			/* いずれでもない → 壁フラグOFF */
			st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)0;					/* PROC.5 */
		}
	} else {
		st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)0;						/* PROC.5 */
	}

	return;
}


/****************************************************************************/
/* 関数名		: fl_seek_low_speed_sot										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)低速SoT判定処理										*/
/*				:	2FCW信号から求めた速度・方位情報から、自車側方より前方の*/
/*				:	物標が停止物か接近物かの判定を行う。					*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)低速SoT判定処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
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


/****************************************************************************/
/* 関数名		: fn_bsm_low_calc_deviation									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-4)低速方位と停止物方位曲線の分散算出処理				*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-4)低速方位と停止物方位曲線の分散算出処理			*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
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


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_sot										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)低速SoT判定処理										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)低速SoT判定処理									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_sot(
	S4 as4_stationary_doa_line[N_DOA],
	S4 as4_sot_limit_doa_line_forward[N_DOA],
	S4 as4_sot_limit_doa_line_backward[N_DOA],
	const S4 as4_a_nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_a_nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 s4_a_forward_priod,
	S4 s4_a_backward_priod,
	FL afl_a_buf_dev[2],
	FL *pfl_a_dev,
	S4 v0_doa,
	U1 u1_a_alarming_flag,
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
	U1* pu1_a_num_forward,
	U1* pu1_a_num_backward
)
{
	S4 i;
	S4 j;
	S4 k;

	S4 sot_stop;

	FL fl_t_fast_sot_pow;
	U1 u1_t_lp_front_back;
	U1 u1_t_lp_sot;
	S1 s1_t_lp_data;
	U4 u4_t_lp_target;
	U1 u1_t_flg_exist_object;
	U4 u4_t_lp_max_target_num;		/* ターゲット物標のループの上限値 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは何も定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	U1 u1_t_tos_flg;				/* ToS status flag */
	U1 u1_t_num_i;					/* Number of SoT objects(approaching) */
	U1 u1_t_num_q;					/* Number of SoT objects(leaving) */
	U1 u1_t_tos_end_flg;			/* ToS end flag (local) */
	FL fl_t_ave_i_y;				/* Average of Ry of nearfield point */
	U1 u1_t_noise_flg;				/* Noise flag */

	fl_t_ave_i_y = (FL)10000.0F;
	u1_t_noise_flg = (U1)0;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	u1_t_flg_exist_object = CU1_DF_OFF;

	/* ■■■■■ (ⅰ)入力データセット ■■■■■ */
	/* 分散値の設定 */
	if(s4_a_backward_priod==0)					/* COND.g24 */
	{
		*pfl_a_dev = afl_a_buf_dev[0];
	}
	else
	{
		*pfl_a_dev = afl_a_buf_dev[1];
	}
	st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] = (S4)afl_a_buf_dev[0];
	st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] = (S4)afl_a_buf_dev[1];

	/* ターゲット物標のループの上限値を設定(ソフト観点による上限ガード処理) */
	/* ターゲット個数がTARGET_BUFFSIZEを超えていないか判定 超えている場合はTARGET_BUFFSIZEを上限値とする */
	if (st_g_bsm_loop_data.as4_buf_pair_num[1] > (S4)TARGET_BUFFSIZE) {
		u4_t_lp_max_target_num = (U4)TARGET_BUFFSIZE;
	} else {
		/* ターゲット個数は負の値にならないため、U4キャストしても問題なし */
		u4_t_lp_max_target_num = (U4)st_g_bsm_loop_data.as4_buf_pair_num[1];
	}

	/* 隣車線ありカウンタの設定 */
	/* 隣車線の有無を前回のターゲット物標位置を使って判定する */
	/* SoT ON 判定パラメータ切替に使用するための簡易的な判定であり、流用時は注意。(仕様書そのまま) */
	for (u4_t_lp_target = (U4)0; u4_t_lp_target < u4_t_lp_max_target_num; u4_t_lp_target++) {
		if ((st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > (FL)-20.0F)			/* COND.g62 */
		&&	(st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Rxfil > (FL)1.75F)) {			/* COND.g63 */
			u1_t_flg_exist_object = CU1_DF_ON;
			break;
		}
	}

	if (u1_t_flg_exist_object == CU1_DF_ON) {
		/* 前回ターゲット物標で条件を満たす物標が一つでもあれば隣車線ありカウンタインクリメント PROC.4 */
		/* 上下限ガードは0～20である */
		st_g_bsm_loop_data.u1_count_adjacent_lane_exist = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_count_adjacent_lane_exist, (S2)1, (U2)20, (U2)0);
	} else {
		/* 前回ターゲット物標で条件を満たす物標が一つもない場合は隣車線ありカウンタデクリメント PROC.5 */
		/* 上下限ガードは0～20である */
		st_g_bsm_loop_data.u1_count_adjacent_lane_exist = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_count_adjacent_lane_exist, (S2)-1, (U2)20, (U2)0);
	}

	/* ■■■■■ (ⅱ) check condition ■■■■■ */
	/* shift buffer */
	for (u1_t_lp_front_back = (U1)0; u1_t_lp_front_back < (U1)2; u1_t_lp_front_back++) {
		for (u1_t_lp_sot = (U1)0; u1_t_lp_sot < (U1)3; u1_t_lp_sot++) {
			for (s1_t_lp_data = (S1)10; s1_t_lp_data >= (S1)0; s1_t_lp_data--) {
				st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data + 1] = st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data];
				st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data + 1] = st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data];
			}
			st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][0] = (S4)0;
			st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][0] = (S4)0;
		}
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* Check variance of detected nearfield point(SoT object) and set noise flag when the points. */
	st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_sot_jdg_noise_flg(afl_a_sot_check_object_i,
																				 afl_a_buf_dev,
																				 st_g_bsm_loop_data.as4_slow_sot_find[1],
																				 &fl_t_ave_i_y,
																				 &u1_t_noise_flg);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((afl_a_buf_dev[0] > CFL_SOT_DEV_TH)										/* COND.g25 */
	||  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3))			/* COND.g28 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((afl_a_buf_dev[0] > CFL_SOT_DEV_TH)										/* COND.g25 */
	||  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3)				/* COND.g28 */
	||  ((st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH1)			/* COND.g65 */
	&&   (u1_a_alarming_flag != (U1)0)))										/* COND.h86 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	{
		if ((fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN)					/* COND.g29 */
		&&  (s4_abs( s2_g_curvr_for_base ) > (S4)CU1_CANOUT_CURVER_MIN_SOT)		/* COND.g30 */
		&&  (u1_a_num_nearfield_doa_2f_i > (U1)3)								/* COND.k1 */
		&&  (u1_a_num_nearfield_doa_2f_q > (U1)3)) {							/* COND.k2 */
			/* ■■■■■ (ⅲ)SoT judgement ■■■■■ */

			/* ■■■■■ (ⅳ)check SoT-stationary(limit) difference (forward) ■■■■■ */
			*pu1_a_num_forward = compare_forward_always_2(
				(const S4 (*)[1])as4_a_nearfield_doa_i,			/* [in] */
				(const S4 *)as4_a_nearfield_doa_peak_num_i,		/* [in] */
				(const S4 *)as4_stationary_doa_line,			/* [in] */
				v0_doa,
				(const FL (*)[4])afl_a_sot_check_object_i
			);
			/* ■■■■■ (ⅴ)check SoT-stationary(limit) difference (backward) ■■■■■ */
			*pu1_a_num_backward = compare_backward_always_2(
				(const S4 (*)[1])as4_a_nearfield_doa_q,			/* [in] */
				(const S4 *)as4_a_nearfield_doa_peak_num_q,		/* [in] */
				as4_stationary_doa_line,						/* [in] */
				as4_sot_limit_doa_line_backward,				/* [in] */
				v0_doa,
				CFL_SoT_V_TH_BWD,
				(const FL (*)[4])afl_a_sot_check_object_q
			);
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] :sot_start  */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] :sot_on */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] :sot_off */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] :timer */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			/* 搭載角度20deg用の処理 ※010-1の関数コール */
			fn_bsm_low_judge_check_tos(afl_a_sot_check_object_i,
									   afl_a_sot_check_object_q,
									   &u1_t_tos_end_flg,
									   &u1_t_num_i,
									   &u1_t_num_q,
									   &u1_t_tos_flg);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

			if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0) {								/* COND.g31 */
				if (st_g_bsm_loop_data.as4_slow_sot_find[0] == 0 ) {								/* COND.g32 */
					/* ■■■■■ (ⅵ)check SoT start ■■■■■ */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
					if ((st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)				/* COND.g53 */
					&&  (afl_a_buf_dev[0] > WALL_DEV_TH2)									/* COND.k3 */
					&&  (afl_a_buf_dev[1] > WALL_DEV_TH2)									/* COND.k4 */
					&&  ((*pu1_a_num_forward > (U1)2)										/* COND.k5 */
					||   (*pu1_a_num_backward > (U1)2))) {									/* COND.k6 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
					if ((st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)				/* COND.g53 */
					&&  (afl_a_buf_dev[0] > WALL_DEV_TH2)									/* COND.k3 */
					&&  (afl_a_buf_dev[1] > WALL_DEV_TH2)									/* COND.k4 */
					&&  ((*pu1_a_num_forward > (U1)2)										/* COND.k5 */
					||   (*pu1_a_num_backward > (U1)2))										/* COND.k6 */
					&&  (u1_t_tos_end_flg == (U1)0)											/* COND.g400 */
					&&  (u1_t_noise_flg == (U1)0)) {										/* COND.g401 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = check_sot_start(
							afl_a_buf_dev, u1_a_alarming_flag
						);
						if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] == 1) {			/* COND.g33 */
							/*■■■■■ (x)Check SoT DOA ■■■■■*/
							fn_bsm_low_judge_check_sot_doa(&fl_t_fast_sot_pow);
						} else {
							fl_t_fast_sot_pow = (FL)0.0F;
						}
					}
				}
				else
				{
					/* ■■■■■ (ⅶ) check SoT ON->OFF ■■■■■ */
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = check_sot_off(
						(const FL *)afl_a_buf_dev
					);
					
					if ((u1_a_num_nearfield_doa_2f_i < (U1)3)								/* COND.k7 */
					||  (u1_a_num_nearfield_doa_2f_q < (U1)3)) {							/* COND.k8 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
					}
					
					if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] == 1)				/* COND.g34 */
					||  (st_g_bsm_loop_data.as4_slow_sot_find[1] > WALL_REJECT_TH1)) {		/* COND.g35 */
						/* turn off sot flag */
						st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;						/* PROC.2 */
						
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
						
						fl_t_fast_sot_pow = (FL)0.0F;
					}
				}
			} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (u1_a_alarming_flag == (U1)0) {												/* COND.k9 */
					/* 何もしない */
				} else {
					/* ※010-3 */
					if (((u1_t_num_i > (U1)9)													/* COND.g321 */
					&&   (u1_t_num_q > (U1)9)													/* COND.g322 */
					&&   (u1_t_tos_flg == (U1)1))												/* COND.g324 */
					||  ((fl_t_ave_i_y < (FL)10000.0F)											/* COND.g411 */
					&&   (fl_t_ave_i_y > (FL)2.0F))) {											/* COND.g411 */
						st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)0;							/* PROC.p400 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;					/* PROC.p401 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;					/* PROC.p402 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;					/* PROC.p403 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;					/* PROC.p404 */
					}
				}
			}
			
			if(st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == (S4)0) {							/* COND.g31 */
				/* 何もしない */
			} else {
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

				/* ■■■■■ (ⅷ)check SoT stop ■■■■■ */
				sot_stop = check_sot_stop(	
					(const FL *)afl_a_buf_dev
				);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (u1_t_noise_flg == (U1)1) {							/* COND.g402 */
					sot_stop = (S4)1;									/* PROC.9 */
				}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

				if (sot_stop == 0) {									/* COND.g36 */
					if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == CS4_S4MIN) {
						/* S4の最小値であるため減算しない */
					} else {
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3]--;							/* PROC.3 */
					}
				} else {
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;							/* PROC.4 */
				}

				if (((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)							/* COND.g31 */
				&&   (sot_stop == 0))																/* COND.g36 */
				||  ((fl_g_v_self_bsm_for_base < CFL_SoT_V_TH_BWD)									/* COND.g39 */
				&&   (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0)							/* COND.!g31 */
				&&   (sot_stop == 0))) {															/* COND.g36 */
					/* ■■■■■ (ⅸ)check SoT OFF->ON ■■■■■ */
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = check_sot_on(
						(const FL *)afl_a_buf_dev
					);
					
					if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0)						/* COND.!g31 */
					&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] == 1)) {					/* COND.g37 */
						st_g_bsm_loop_data.as4_sot_check_points[1][2][0] = st_g_bsm_loop_data.as4_sot_check_points[1][2][1] + 1;	/* PROC.6 */
					} else {
						st_g_bsm_loop_data.as4_sot_check_points[1][2][0] = st_g_bsm_loop_data.as4_sot_check_points[1][2][1];		/* PROC.7 */
					}
					
					if (fl_g_v_self_bsm_for_base < CFL_SoT_V_TH_BWD) {								/* COND.g39 */
						if ((st_g_bsm_loop_data.as4_sot_check_points[1][2][0] > 5)			/* COND.g38	 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3)		/* COND.g40 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)) {		/* COND.g31 */
							st_g_bsm_loop_data.as4_slow_sot_find[0] = 1;					/* PROC.5 */
						}
					} else {
						if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)				/* COND.g31 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] == 1)) {			/* COND.g37 */
							/* turn on sot flag */
							st_g_bsm_loop_data.as4_slow_sot_find[0] = 1;						/* PROC.5 */
						}
					}
					if (st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)0) {
						st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)0;
						
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
						
						fl_t_fast_sot_pow = (FL)0.0F;
					}
				}
			}
		}
		else
		{
			st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;								/* PROC.1 of 5)(ⅱ) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = 0;						/* PROC.2-1 of 5)(ⅱ) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = 0;						/* PROC.2-1 of 5)(ⅱ) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = 0;						/* PROC.2-1 of 5)(ⅱ) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;						/* PROC.2-1 of 5)(ⅱ) */

		for(i=0; i<12; i++)
			{
				for(j=0; j<3; j++)
				{
					for(k=0; k<2; k++)
					{
						st_g_bsm_loop_data.as4_sot_check_sum[k][j][i] = 0;		/* PROC.3 of 5)(ⅱ) */
						st_g_bsm_loop_data.as4_sot_check_points[k][j][i] = 0;	/* PROC.4 of 5)(ⅱ) */
					}
				}
			}
		}
	}
	else	/* else of COND.(g25 and g28) */
	{
		st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;
		fl_t_fast_sot_pow = (FL)0.0F;
	}

	return;
}


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは関数定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_check_tos								*/
/*--------------------------------------------------------------------------*/
/* 機能			: 警報ToS物標調査											*/
/*--------------------------------------------------------------------------*/
/* 引数			: afl_a_sot_check_object_i[][]	: SoT物標情報(接近側) [in]	*/
/*				: afl_a_sot_check_object_q[][]	: SoT物標情報(離脱側) [in]	*/
/*				: pu1_a_tos_end_flg				: ToS終了フラグ(ローカル) [out]*/
/*				: pu1_a_num_i					: SoT物標個数(接近側) [out]	*/
/*				: pu1_a_num_q					: SoT物標個数(離脱側) [out]	*/
/*				: pu1_a_tos_flg					: ToS状態フラグ [out]		*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: st_g_bsm_alarm_data.afl_alarmed_target[]	: 警報ターゲット情報*/
/*				: st_g_bsm_loop_data.as4_flg_tos_end[]		: ToS終了フラグ	*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)低速SoT判定処理 (iii) SoT 判定 ※010-1 			*/
/*--------------------------------------------------------------------------*/
/* 作成者		: G.Jomori													*/
/****************************************************************************/
VD fn_bsm_low_judge_check_tos(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
							  FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
							  U1* pu1_a_tos_end_flg,
							  U1* pu1_a_num_i,
							  U1* pu1_a_num_q,
							  U1* pu1_a_tos_flg)
{
	U1 u1_t_lp_target_num;					/* ターゲット物標のループ変数 仕様書ではi */
	U1 u1_t_lp_slow_sot_freq_bin_range;		/* SoT判定周波数範囲のループ変数 仕様書ではi */

	/* STEP 1: check ToS status (whether there is alarming ToS target or not) */
	*pu1_a_tos_flg = (U1)0;				/* PROC.p100 */

	for (u1_t_lp_target_num = (U1)0; u1_t_lp_target_num < TARGET_BUFFSIZE; u1_t_lp_target_num++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[u1_t_lp_target_num][4] == (FL)1.0F) {		/* COND.g300 */
			*pu1_a_tos_flg = (U1)1;																	/* PROC.p101 */
			break;
		}
	}

	/* STEP 2: count forward objects in SoT objects */
	*pu1_a_num_i = (U1)0;					/* PROC.p110 */
	*pu1_a_num_q = (U1)0;					/* PROC.p111 */
	*pu1_a_tos_end_flg = (U1)0;				/* PROC.p112 */

	for (u1_t_lp_slow_sot_freq_bin_range = (U1)0; u1_t_lp_slow_sot_freq_bin_range < SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_slow_sot_freq_bin_range++) {
		if ((afl_a_sot_check_object_i[u1_t_lp_slow_sot_freq_bin_range][0] != CFL_UNKNOWN_VALUE)			/* COND.g310 */
		&&  (afl_a_sot_check_object_i[u1_t_lp_slow_sot_freq_bin_range][1] > (FL)0.5F)) {				/* COND.g311 */
			(*pu1_a_num_i)++;																				/* PROC.p113 */
		}

		if ((afl_a_sot_check_object_q[u1_t_lp_slow_sot_freq_bin_range][0] != CFL_UNKNOWN_VALUE)			/* COND.g312 */
		&&  (afl_a_sot_check_object_q[u1_t_lp_slow_sot_freq_bin_range][1] > (FL)0.5F)) {				/* COND.g313 */
			(*pu1_a_num_q)++;																				/* PROC.p114 */
		}
	}

	/* STEP 3: check ToS-end */
	if ((*pu1_a_num_i > (U1)9)									/* COND.g321 */
	&&  (*pu1_a_num_q > (U1)9)									/* COND.g322 */
	&&  ((st_g_bsm_loop_data.as4_flg_tos_end[0] != (U1)0)		/* COND.g323 */
	||   (*pu1_a_tos_flg == (U1)1))) {							/* COND.g324 */
		*pu1_a_tos_end_flg = (U1)1;									/* PROC.p120 */
	}

	return;
}

/****************************************************************************/
/* 関数名		: s4_bsm_low_judge_sot_jdg_noise_flg						*/
/*--------------------------------------------------------------------------*/
/* 機能			: SoT物標の平均・分散算出とノイズフラグ設定					*/
/*--------------------------------------------------------------------------*/
/* 引数			: afl_a_sot_check_object_i[][]	: SoT物標情報(接近側) [in]	*/
/*				: afl_a_buf_dev[]				: 低速方位と停止物方位曲線の分散 [in]*/
/*				: s4_a_slow_sot_find1_pre		: 壁フラグ(前回値) [in]		*/
/*				: pfl_a_ave_i_y					: SoT物標のRyの平均 [out]	*/
/*				: pu1_a_noise_flg				: ノイズフラグ [out]		*/
/* 戻り値		: s4_t_flg_sot_find1			: 壁フラグ					*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: s2_g_curvr_for_base					: 推定R [m]			*/
/*				: fl_g_v_self_bsm_for_base				: 自車速 [km/h]		*/
/*				: st_g_bsm_loop_data.s4_flg_alarm 		: 警報フラグ		*/
/*				: st_g_bsm_loop_data.as4_flg_leading[]	: 併走車フラグ		*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-018(291BCVR).pdf				*/
/*				:	(7)-5)低速SoT判定処理 (ii)  判定条件の確認 				*/
/****************************************************************************/
static S4 s4_bsm_low_judge_sot_jdg_noise_flg(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
											 FL afl_a_buf_dev[2],
											 S4 s4_a_slow_sot_find1_pre,
											 FL* pfl_a_ave_i_y,
											 U1* pu1_a_noise_flg)
{

	FL fl_t_sum_i_y;				/* Sum of Ry of nearfield point */
	FL fl_t_sum_i_y2;				/* Sum of squares of Ry of nearfield point */
	FL fl_t_ave_i_y;				/* Average of Ry of nearfield point */
	FL fl_t_var_i_y;				/* Varidence of Ry of nearfield point */
	U1 u1_t_n_i;					/* Number of detected nearfield point */
	U1 u1_t_noise_flg;				/* Noise flag */
	S4 s4_t_flg_sot_find1;			/* 壁フラグ(戻り値用) */
	U1 u1_t_lp_bin_range;			/* SLOW_SOT_FREQ_BIN_RANGEのループ変数 仕様書ではループ変数のi */
	S4 s4_t_curvr_for_base_abs;		/* 推定Rの絶対値ラッチ変数 */

	/* 変数初期化 */
	fl_t_sum_i_y		= (FL)0.0F;
	fl_t_sum_i_y2		= (FL)0.0F;
	fl_t_ave_i_y		= (FL)10000.0F;
	fl_t_var_i_y		= (FL)10000.0F;
	u1_t_n_i			= (U1)0;
	u1_t_noise_flg		= (U1)0;
	s4_t_flg_sot_find1	= s4_a_slow_sot_find1_pre;

	/* 推定Rの絶対値を設定 */
	s4_t_curvr_for_base_abs = s4_abs((S4)s2_g_curvr_for_base);

	if ((CFL_CANOUT_VSELF_MIN <= fl_g_v_self_bsm_for_base)			/* COND.p1 */
	&&  (fl_g_v_self_bsm_for_base < (FL)CU1_HEISOU_VSELF_MAX)		/* COND.p1 */
	&&  (s4_t_curvr_for_base_abs >= (S4)CANOUT_CURVER_MIN)) {		/* COND.p2 */
		for (u1_t_lp_bin_range = (U1)0; u1_t_lp_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_bin_range++) {
			if (afl_a_sot_check_object_i[u1_t_lp_bin_range][0] != CFL_UNKNOWN_VALUE) {			/* COND.p3 */
				u1_t_n_i++;																												/* PROC.1 */
				fl_t_sum_i_y += afl_a_sot_check_object_i[u1_t_lp_bin_range][1];															/* PROC.2 */
				fl_t_sum_i_y2 += (afl_a_sot_check_object_i[u1_t_lp_bin_range][1] * afl_a_sot_check_object_i[u1_t_lp_bin_range][1]);		/* PROC.3 */
			} else {
				break;
			}
		}

		if (u1_t_n_i > (U1)0) {			/* COND.p4 */
			fl_t_ave_i_y = fl_t_sum_i_y / (FL)u1_t_n_i;											/* PROC.4 */
			fl_t_var_i_y = (fl_t_sum_i_y2 / (FL)u1_t_n_i) - (fl_t_ave_i_y * fl_t_ave_i_y);		/* PROC.5 */
		}

		if ((afl_a_buf_dev[0] > (FL)WALL_DEV_TH7)			/* COND.p5 */
		&&  (afl_a_buf_dev[0] != (FL)999.9F)) {				/* COND.p5 */
			if ((fl_t_var_i_y > (FL)5.0F)					/* COND.p6 */
			&&  (fl_t_ave_i_y < (FL)2.0F)) {				/* COND.p7 */
				 u1_t_noise_flg = (U1)1;					/* PROC.6 */
			}
		} else {
			if ((fl_t_ave_i_y > (FL)0.5F)								/* COND.p8 */
			&&  (fl_t_ave_i_y < (FL)2.0F)								/* COND.p8 */
			&&  (st_g_bsm_loop_data.s4_flg_alarm != (S4)0)				/* COND.p9 */
			&&  (st_g_bsm_loop_data.as4_flg_leading[0] != (S4)0)) {		/* COND.p10 */
				s4_t_flg_sot_find1 = (S4)0;								/* PROC.7 */
			}
		}
	}

	/* 最終結果を出力 */
	*pfl_a_ave_i_y = fl_t_ave_i_y;
	*pu1_a_noise_flg = u1_t_noise_flg;

	return s4_t_flg_sot_find1;
}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_wall										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)壁判定処理											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)壁判定処理										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall(
	const FL afl_a_buf_dev[2],
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	U1 u1_a_num_forward,
	U1 u1_a_num_backward
)
{

	S4 i;
	S4 j;
	S4 backward_point = 0;		/*_20141007_3 */
	S4 backward_point_th = 3;
	S4 forward_point = 0;
	S4 s4_t_point_num;
	U1 u1_t_tos_flag;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	U1 u1_t_wall_checked_flag;

	u1_t_wall_checked_flag = (U1)0;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	u1_t_tos_flag = (U1)0;

	if( fl_g_v_self_bsm_for_base < 15.0F )																								/* COND.i12 */
	{
		backward_point_th = 1;																											/* PROC.1 */
	}
	for( i=0; i<12; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > backward_point_th)														/* COND.i15 */
		||  (st_g_bsm_loop_data.as4_sot_check_points[1][1][i] > backward_point_th))														/* COND.i15' */
		{
			backward_point++;																											/* PROC.2 */
		}
	}

	for (i = (S4)0; i < (S4)12; i++) {
		s4_t_point_num = st_g_bsm_loop_data.as4_sot_check_points[0][0][i] + st_g_bsm_loop_data.as4_sot_check_points[0][1][i] + st_g_bsm_loop_data.as4_sot_check_points[0][2][i];
		
		if (s4_t_point_num != (S4)0) {
			if (((FL)st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] / (FL)s4_t_point_num) > (FL)3.0F) {
				forward_point++;
			}
		}
	}

	if ((afl_a_buf_dev[0] < WALL_DEV_TH5)						/* COND.i3 */
	&&  ((afl_a_buf_dev[1] != (FL)999.9F)						/* COND.i8 */
	||   (backward_point == (S4)0))) {							/* COND.i33 */
		/* (i) When forward deviation is small実施 */
		fn_bsm_low_judge_wall_forward_deviation_small((const FL *)afl_a_buf_dev, forward_point, backward_point);
	} else {
		if (afl_a_buf_dev[0] != (FL)999.9F) {						/* COND.i4 */
			/* (ii) When forward deviation is big実施 */
			fn_bsm_low_judge_wall_forward_deviation_big((const FL *)afl_a_buf_dev, forward_point);
		} else {
			if (fl_g_v_self_bsm_for_base < (FL)20.0F) {				/* COND.i13 */
				/* (iii) When in low speed実施 */
				fn_bsm_low_judge_wall_when_low_speed((const FL *)afl_a_buf_dev, backward_point);
			} else {
				/* (iv) When not in low speed実施 */
				/* 引数の数が異なるため、搭載角度により分割する */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				fn_bsm_low_judge_wall_when_not_low_speed((const FL *)afl_a_buf_dev, forward_point);
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				fn_bsm_low_judge_wall_when_not_low_speed((const FL *)afl_a_buf_dev, forward_point, &u1_t_wall_checked_flag);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
	}

	/* Set the maximum value of sot_find[1] if it reaches to the upper limit */
	if(st_g_bsm_loop_data.as4_slow_sot_find[1] > (S4)128) {									/* COND.i20 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)128;									/* PROC.4 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if (u1_t_wall_checked_flag == (U1)0) {
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* Reset the wall flag if there are enough points be detected and SoT flag is on */
	if ((afl_a_buf_dev[0] == (FL)999.9F)										/* COND.!i4 */
	&&  (afl_a_buf_dev[1] == (FL)999.9F)										/* COND.!i8 */
	&&  (u1_a_num_nearfield_doa_2f_i > (U1)5)									/* COND.i37 */
	&&  (u1_a_num_nearfield_doa_2f_q > (U1)5)									/* COND.i38 */
	&&  (u1_a_num_forward > (U1)2)												/* COND.k5 */
	&&  (u1_a_num_backward > (U1)2)												/* COND.k6 */
	&&  ((st_g_bsm_loop_data.as4_slow_sot_find[0] != (S4)0)						/* COND.!g32 */
	||   (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != (S4)0))) {			/* COND.g23 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
		} else {
			st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
		}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	}		/* if (u1_t_wall_checked_flag == (U1)0)の終わり */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* Reset the wall flag if there is a ToS */
	for (i = (S4)0; i < TARGET_BUFFSIZE; i++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[i][4] == ALARM_TYPE_TOS) {	/* COND.i39 */
			u1_t_tos_flag = (U1)1;
			break;
		}
	}
	
	if ((afl_a_buf_dev[0] == (FL)999.9F)										/* COND.!i4 */
	&&  (afl_a_buf_dev[1] == (FL)999.9F)										/* COND.!i8 */
	&&  (u1_t_tos_flag == (U1)1)												/* COND.i40 */
    &&  ((u1_a_num_forward != (U1)0)											/* COND.i41 */
    ||   (u1_a_num_backward != (U1)0))) {										/* COND.i42 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
	}


	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_wall_forward_deviation_small				*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)-(ⅰ)When forward deviation is small				*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-ⅰ)When forward deviation is small				*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_forward_deviation_small(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	S4 s4_a_backward_point
)
{

	/* ■■■■■ (ⅰ) When forward deviation is small ■■■■■ */
	if ((afl_a_buf_dev[0] < WALL_DEV_TH2)							/* COND.g18 */
	&&  ((afl_a_buf_dev[1] != (FL)999.9F)							/* COND.i8 */
	||   (s4_a_backward_point == (S4)0))) {							/* COND.i33 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] += 10;			/* PROC.1 */
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH8)					/* COND.i1 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if (s4_a_forward_point < (S4)5) {							/* COND.i9 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=5;		/* PROC.2 */
		}
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH3)					/* COND.g19 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if(afl_a_buf_dev[1]<WALL_DEV_TH2)					/* COND.g21 */
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=5;	/* PROC.2 */
		}
		else
		{

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* 搭載角度50degでは条件i47はなし */
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;	/* PROC.3 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_a_backward_point < (S4)4) {		/* COND.i47 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;	/* PROC.3 */
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

		}
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH5)					/* COND.i3 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if (afl_a_buf_dev[1] < WALL_DEV_TH8) {						/* COND.i5 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)5;		/* PROC.2 */
		} else if ( afl_a_buf_dev[1] < WALL_DEV_TH10) {				/* COND.i6 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* 搭載角度50degでは条件i47はなし */
			st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;		/* PROC.3 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_a_backward_point < (S4)4) {		/* COND.i47 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;	/* PROC.3 */
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

		} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;		/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			/* 搭載角度20degでは処理なし */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
		}
	} else {
		/* 何もしない */
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_wall_forward_deviation_big				*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)-(ⅱ) When forward deviation is big					*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(ⅱ) When forward deviation is big				*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_forward_deviation_big(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
)
{

	/* ■■■■■ (ⅱ) When forward deviation is big ■■■■■ */
	if( st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0 )				/* COND.g23 */
	{
		if( afl_a_buf_dev[1]<WALL_DEV_TH1)									/* COND.g22 */
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;					/* PROC.3 */
		}
		else
		{
			if ((afl_a_buf_dev[0] > CFL_WALL_DEV_TH9)							/* COND.i2 */
			||  ((afl_a_buf_dev[1] > WALL_DEV_TH7)								/* COND.i7 */
			&&   (afl_a_buf_dev[0] > (CFL_SOT_DEV_TH + (FL)5.0F)))) {			/* COND.i34 */
				if (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)) {	/* COND.!i18 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
					st_g_bsm_loop_data.as4_slow_sot_find[1] =0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
					if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
						st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
					} else {
						st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
					}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
				}
			}
		}
	}
	else
	{
		if ((afl_a_buf_dev[0] > CFL_WALL_DEV_TH9)							/* COND.i2 */
		||  ((afl_a_buf_dev[1] > WALL_DEV_TH7)								/* COND.i7 */
		&&   (afl_a_buf_dev[0] > (CFL_SOT_DEV_TH + (FL)5.0F)))) {			/* COND.i34 */
			if ((st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)		/* COND.i18 */
			||  (s4_a_forward_point < (S4)3)) {								/* COND.i35 */
				/* 壁フラグの値保持 */
			} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] =0;					/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		} else {
			if ((afl_a_buf_dev[0] < WALL_DEV_TH1)								/* COND.i36 */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)) {			/* COND.g32 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;				/* PROC.3 */
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_wall_when_low_speed						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)-(ⅲ) When in low speed								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(ⅲ) When in low speed							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_when_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_backward_point
)
{

	/* ■■■■■ (ⅲ) When in low speed ■■■■■ */
	if( st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0 )					/* COND.g23 */
	{
		if( s4_a_backward_point < 4 )											/* COND.i11 */
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH1)									/* COND.g22 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;					/* PROC.3 */
			}
			else
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] =0;						/* PROC.5 */
			}
		}
		else
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] =0;							/* PROC.5 */
		}
	}
	else
	{
		if( s4_a_backward_point < 4 )											/* COND.i11 */
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH1 )									/* COND.g22 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;					/* PROC.3 */
			}
			else if( afl_a_buf_dev[1]<WALL_DEV_TH8 )							/* COND.i5 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1]+=1;						/* PROC.4 */
			}
			else
			{
				if (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN) {				/* COND.i14 */
					if (fl_g_v_self_bsm_for_base < 15.0F) {							/* COND.i12 */
						if (st_g_bsm_loop_data.afl_wall_width[0] > 3.0F) {			/* COND.i19 */
							st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;			/* PROC.5 */
						}
					} else {
						if ((!(s4_a_backward_point == (S4)0))								/* COND.!i33 */
						&&  (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH))) {	/* COND.!i18 */
							st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;			/* PROC.5 */
						} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
							/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
							st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)1;			/* PROC.4 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
						}
					}
				}
			}
		}
		else
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH2)									/* COND.g21 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;					/* PROC.3 */
			}
			else
			{
				if (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)) {	/* COND.i18 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;					/* PROC.5 */
				}
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_wall_when_not_low_speed					*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)-(ⅳ) When not in low speed							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(ⅳ) When not in low speed						*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
)
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	U1* pu1_a_wall_checked_flag
)
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
{

	/* ■■■■■ (ⅳ) When not in low speed ■■■■■ */
	if( afl_a_buf_dev[1]<WALL_DEV_TH2 )										/* COND.g21 */
	{
		st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;						/* PROC.3 */
	}
	else if (afl_a_buf_dev[1] < (CFL_SOT_DEV_TH + (FL)10.0F))				/* COND.g22 */
	{
		/* nothing */
	}
	else
	{
		if( afl_a_buf_dev[1] != 999.9F )									/* COND.i8 */
		{
			if( st_g_bsm_loop_data.afl_wall_width[0]<WALL_WIDTH_TH)			/* COND.i18 */
			{
				/* nothing */
			}
			else
			{
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
		else
		{
			if ((s4_a_forward_point > (S4)5)											/* COND.i10 */
			&&  (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH))) {	/* COND.i18 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
					*pu1_a_wall_checked_flag = CU1_DF_ON;
				} else {
					st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
				}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
	}

	return;
}


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
/****************************************************************************/
/* 関数名		: s4_bsm_low_judge_wall_proc8								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-6)壁判定処理の処理⑧									*/
/*--------------------------------------------------------------------------*/
/* 引数			: s4_a_sot_find_1				: 壁フラグ [in]				*/
/* 戻り値		: s4_t_calc_sot_find_1			: 演算結果の壁フラグ		*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-012								*/
/*				:	(7)-6)壁判定処理の処理⑧								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static S4 s4_bsm_low_judge_wall_proc8(S4 s4_a_sot_find_1)
{
	/* ※012-2の処理の中で処理⑧のみが共通化出来るため	*/
	/* 処理⑧を関数化し、実施箇所でコールする			*/

	S4 s4_t_calc_sot_find_1;

	s4_t_calc_sot_find_1 = s4_a_sot_find_1 - (S4)CFL_WALL_OFF_GAIN;

	/* 0で下限ガード */
	if (s4_t_calc_sot_find_1 < (S4)0) {
		s4_t_calc_sot_find_1 = (S4)0;
	}

	return s4_t_calc_sot_find_1;
}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_fast_sot									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-7)Fast-SoT 判定処理									*/
/*				:	(7)-4)-(ⅲ)fast-SoTの判定結果に従って、Fast-SoTフラグ	*/
/*				:	を設定する												*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-7)Fast-SoT 判定処理									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_fast_sot(
	S4 s4_a_fast_sot_num,
	S4 s4_a_not_fast_sot_num,
	U1 u1_a_alarming_flag
)
{
	U1 u1_t_tos_flg;
	S2 s2_t_fwd_peak_val;
	S2 s2_t_bwd_peak_val;
	U1 u1_t_lp_check_sum;
	
	s2_t_fwd_peak_val = (S2)0;
	s2_t_bwd_peak_val = (S2)0;
	u1_t_tos_flg = (U1)0;
	
	for (u1_t_lp_check_sum = (U1)0; u1_t_lp_check_sum < (U1)12; u1_t_lp_check_sum++) {
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][1][u1_t_lp_check_sum] > s2_t_fwd_peak_val) {
			s2_t_fwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[0][1][u1_t_lp_check_sum];
		}
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][1][u1_t_lp_check_sum] > s2_t_bwd_peak_val) {
			s2_t_bwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[1][1][u1_t_lp_check_sum];
		}
	}
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((s2_t_fwd_peak_val > (S2)800)													/* COND.i43 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((s2_t_fwd_peak_val > (S2)380)													/* COND.i43 搭載角度20deg用の条件 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	&&  (s2_t_bwd_peak_val < (S2)100)) {												/* COND.i44 */
		u1_t_tos_flg = (U1)1;
	}
	
	if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)								/* COND.i21 */
	&&  (fl_g_v_self_bsm_for_base >= (FL)30.0F)											/* COND.i24 */
	&&  (s4_a_fast_sot_num != (S4)0)) {													/* COND.i25 */
		if ((s4_a_fast_sot_num > (S4)7)													/* COND.i26 */
		&&  (s4_a_fast_sot_num > (s4_a_not_fast_sot_num + (S4)1))) {					/* COND.i27 */
			if (st_g_bsm_loop_data.as4_fast_sot_flg[0] == (S4)0) {						/* COND.i23 */
				if (u1_t_tos_flg == (U1)0) {											/* COND.i46 */
					st_g_bsm_loop_data.as4_fast_sot_flg[0]++;							/* PROC.1 */
				}
			} else {
				st_g_bsm_loop_data.as4_fast_sot_flg[0]++;								/* PROC.1 */
			}
		} else if ((s4_a_fast_sot_num <= (S4)7)											/* COND.i28 */
			   ||  (s4_a_fast_sot_num < s4_a_not_fast_sot_num)) {						/* COND.i29 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			st_g_bsm_loop_data.as4_fast_sot_flg[0]--;									/* PROC.2 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if ((s4_a_fast_sot_num <= (S4)7)											/* COND.i28 */
			&&  (s4_a_fast_sot_num <= (S4)((FL)s4_a_not_fast_sot_num * (FL)0.5F))) {	/* COND.i32 */
				st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;							/* PROC.3 */
			} else {
				st_g_bsm_loop_data.as4_fast_sot_flg[0]--;								/* PROC.2 */
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
		} else {
			/* 値保持 */
		}
	} else {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;									/* PROC.3 */
	}
	
	/* 0～5で上下限ガード */
	if (st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)5) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)5;
	} else if (st_g_bsm_loop_data.as4_fast_sot_flg[0] < (S4)0) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;
	} else {
		/* 値保持 */
	}
	
	if (u1_a_alarming_flag == (U1)1) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;
	}
	
	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_exist_leading_car_main					*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 メイン関数									*/
/*--------------------------------------------------------------------------*/
/* 引数			: as4_a_nearfield_doa_i[][]		: 低速方位バッファ(接近側)	*/
/* 				: as4_a_nearfield_doa_q[][]		: 低速方位バッファ(離脱側)	*/
/* 				: afl_a_sot_check_object_i[][]	: SoT物標(接近側)			*/
/* 				: afl_a_sot_check_object_q[][]	: SoT物標(離脱側)			*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: fn_bsm_low_judge_exist_leading_car_set_jdg_area,			*/
/* 				: fn_bsm_low_judge_exist_leading_car_calc_char,				*/
/* 				: fn_bsm_low_judge_exist_leading_car_jdg,					*/
/* 				: fn_bsm_low_judge_exist_leading_car_mediation				*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定						*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_main(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
												  const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4])
{
	FL fl_t_area_x_near;			/* 観測点の抽出範囲(x座標の内側) */
	FL fl_t_area_x_far;				/* 観測点の抽出範囲(x座標の外側) */
	FL fl_t_area_y_forward;			/* 観測点の抽出範囲(y座標の前側) */
	FL fl_t_area_y_backward;		/* 観測点の抽出範囲(y座標の後側) */

	U1 u1_t_Ni;						/* エリア内観測点数(接近側) */
	U1 u1_t_Nq;						/* エリア内観測点数(離脱側) */
	FL fl_t_ave_theta_i;			/* エリア内観測点方位の平均(接近側) */
	FL fl_t_ave_theta_q;			/* エリア内観測点方位の平均(離脱側) */
	FL fl_t_var_theta_i;			/* エリア内観測点方位の分散(接近側) */
	FL fl_t_var_theta_q;			/* エリア内観測点方位の分散(離脱側) */
	U1 u1_t_flg_point_many;			/* 観測点数大フラグ */
	U1 u1_t_flg_point_bias;			/* 観測点数偏りフラグ */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((st_g_bsm_loop_data.s4_flg_alarm == (S4)0)
	||  (st_g_bsm_loop_data.s1_ctr_heisou_car != (S1)0)) {
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

		/* ⅰ)判定エリア設定 */
		fn_bsm_low_judge_exist_leading_car_set_jdg_area(&fl_t_area_x_near, &fl_t_area_x_far, &fl_t_area_y_forward, &fl_t_area_y_backward);

		/* ⅱ)特徴量の算出 */
		fn_bsm_low_judge_exist_leading_car_calc_char(as4_a_nearfield_doa_i,
													 as4_a_nearfield_doa_q,
													 afl_a_sot_check_object_i,
													 afl_a_sot_check_object_q,
													 fl_t_area_x_near,
													 fl_t_area_x_far,
													 fl_t_area_y_forward,
													 fl_t_area_y_backward,
													 &u1_t_Ni,
													 &u1_t_Nq,
													 &fl_t_ave_theta_i,
													 &fl_t_ave_theta_q,
													 &fl_t_var_theta_i,
													 &fl_t_var_theta_q,
													 &u1_t_flg_point_many,
													 &u1_t_flg_point_bias);

		/* ⅲ)並走車判定 */
		fn_bsm_low_judge_exist_leading_car_jdg(u1_t_Ni,
											   u1_t_Nq,
											   fl_t_ave_theta_i,
											   fl_t_ave_theta_q,
											   fl_t_var_theta_i,
											   fl_t_var_theta_q,
											   u1_t_flg_point_many,
											   u1_t_flg_point_bias);

		/* ⅳ)調停処理 */
		fn_bsm_low_judge_exist_leading_car_mediation();

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	}					/* 条件o1 or o2のEND部 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	return;
}

/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_exist_leading_car_set_jdg_area			*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 判定エリア設定								*/
/*--------------------------------------------------------------------------*/
/* 引数			: pfl_a_area_x_near		: 判定エリア(x座標の内側)			*/
/* 				: pfl_a_area_x_far		: 判定エリア(x座標の外側)			*/
/* 				: pfl_a_area_y_forward	: 判定エリア(y座標の手前側)			*/
/* 				: pfl_a_area_y_backward	: 判定エリア(y座標の後ろ側)			*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定 ⅰ)判定エリア設定	*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_set_jdg_area(FL* pfl_a_area_x_near,
														  FL* pfl_a_area_x_far,
														  FL* pfl_a_area_y_forward,
														  FL* pfl_a_area_y_backward)
{
	/* ⅰ)判定エリア設定 */
	*pfl_a_area_x_near     = (FL)ALARM_X_IN;
	*pfl_a_area_x_far      = (FL)ALARM_X_OUT + (FL)2.0F;
	*pfl_a_area_y_forward  = (FL)ALARM_Y_FORWARD + (FL)1.0F;
	*pfl_a_area_y_backward = CFL_ALARM_Y_BACKWARD;

	return;
}

/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_exist_leading_car_calc_char				*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 特徴量の算出								*/
/*--------------------------------------------------------------------------*/
/* 引数			: as4_a_nearfield_doa_i[][]		: 低速方位バッファ(接近側)	*/
/* 				: as4_a_nearfield_doa_q[][]		: 低速方位バッファ(離脱側)	*/
/* 				: afl_a_sot_check_object_i[][]	: SoT物標(接近側)			*/
/* 				: afl_a_sot_check_object_q[][]	: SoT物標(離脱側)			*/
/* 				: fl_a_area_x_near				: 判定エリア(x座標の内側)	*/
/* 				: fl_a_area_x_far				: 判定エリア(x座標の外側)	*/
/* 				: fl_a_area_y_forward			: 判定エリア(y座標の手前側)	*/
/* 				: fl_a_area_y_backward			: 判定エリア(y座標の後ろ側)	*/
/* 				: pu1_a_Ni						: エリア内観測点数(接近側)	*/
/* 				: pu1_a_Nq						: エリア内観測点数(離脱側)	*/
/* 				: pfl_a_ave_theta_i				: エリア内観測点方位の平均(接近側)*/
/* 				: pfl_a_ave_theta_q				: エリア内観測点方位の平均(離脱側)*/
/* 				: pfl_a_var_theta_i				: エリア内観測点方位の分散(接近側)*/
/* 				: pfl_a_var_theta_q				: エリア内観測点方位の分散(離脱側)*/
/* 				: pu1_a_flg_point_many			: 観測点数大フラグ			*/
/* 				: pu1_a_flg_point_bias			: 観測点数偏りフラグ		*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定 ⅱ)特徴量の算出		*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_calc_char(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL fl_a_area_x_near,
													   const FL fl_a_area_x_far,
													   const FL fl_a_area_y_forward,
													   const FL fl_a_area_y_backward,
													   U1* pu1_a_Ni,
													   U1* pu1_a_Nq,
													   FL* pfl_a_ave_theta_i,
													   FL* pfl_a_ave_theta_q,
													   FL* pfl_a_var_theta_i,
													   FL* pfl_a_var_theta_q,
													   U1* pu1_a_flg_point_many,
													   U1* pu1_a_flg_point_bias)
{
	U1 u1_t_Ni;						/* エリア内観測点数(接近側) */
	U1 u1_t_Nq;						/* エリア内観測点数(離脱側) */
	FL fl_t_ave_theta_i;			/* エリア内観測点方位の平均(接近側) */
	FL fl_t_ave_theta_q;			/* エリア内観測点方位の平均(離脱側) */
	FL fl_t_var_theta_i;			/* エリア内観測点方位の分散(接近側) */
	FL fl_t_var_theta_q;			/* エリア内観測点方位の分散(離脱側) */
	U1 u1_t_flg_point_many;			/* 観測点数大フラグ */
	U1 u1_t_flg_point_bias;			/* 観測点数偏りフラグ */


	/***** 接近側 *****/
	fn_exist_leading_car_calc_char_iq(as4_a_nearfield_doa_i,
									  afl_a_sot_check_object_i,
									  fl_a_area_x_near,
									  fl_a_area_x_far,
									  fl_a_area_y_forward,
									  fl_a_area_y_backward,
									  &u1_t_Ni,
									  &fl_t_ave_theta_i,
									  &fl_t_var_theta_i);

	/***** 離脱側 *****/
	fn_exist_leading_car_calc_char_iq(as4_a_nearfield_doa_q,
									  afl_a_sot_check_object_q,
									  fl_a_area_x_near,
									  fl_a_area_x_far,
									  fl_a_area_y_forward,
									  fl_a_area_y_backward,
									  &u1_t_Nq,
									  &fl_t_ave_theta_q,
									  &fl_t_var_theta_q);

	/***** 特徴量を算出 *****/
	/* 変数初期化 */
	u1_t_flg_point_many = (U1)0;
	u1_t_flg_point_bias = (U1)0;

	/* 観測点数大フラグ */
	if ((u1_t_Ni > (U1)7)				/* COND.n4 */
	&&  (u1_t_Nq > (U1)7)) {			/* COND.n4 */
		u1_t_flg_point_many = (U1)1;
	}

	/* 観測点数偏りフラグ */
	if ((((S4)u1_t_Nq - (S4)u1_t_Ni) > (S4)5)	/* COND.n5 */
	&&  (u1_t_Ni <= (U1)3)) {					/* COND.n5 */
		u1_t_flg_point_bias = (U1)1;
	}

	/* 最終結果を出力 */
	*pu1_a_Ni = u1_t_Ni;
	*pu1_a_Nq = u1_t_Nq;
	*pfl_a_ave_theta_i = fl_t_ave_theta_i;
	*pfl_a_ave_theta_q = fl_t_ave_theta_q;
	*pfl_a_var_theta_i = fl_t_var_theta_i;
	*pfl_a_var_theta_q = fl_t_var_theta_q;
	*pu1_a_flg_point_many = u1_t_flg_point_many;
	*pu1_a_flg_point_bias = u1_t_flg_point_bias;

	return;
}

/****************************************************************************/
/* 関数名		: fn_exist_leading_car_calc_char_iq							*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 特徴量の算出 共通部分						*/
/*--------------------------------------------------------------------------*/
/* 引数			: as4_a_nearfield_doa[][]		: 低速方位バッファ			*/
/* 				: afl_a_sot_check_object[][]	: SoT物標					*/
/* 				: fl_a_area_x_near				: 判定エリア(x座標の内側)	*/
/* 				: fl_a_area_x_far				: 判定エリア(x座標の外側)	*/
/* 				: fl_a_area_y_forward			: 判定エリア(y座標の手前側)	*/
/* 				: fl_a_area_y_backward			: 判定エリア(y座標の後ろ側)	*/
/* 				: pu1_a_N						: エリア内観測点数			*/
/* 				: pfl_a_ave_theta				: エリア内観測点方位の平均	*/
/* 				: pfl_a_var_theta				: エリア内観測点方位の分散	*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定 ⅱ)特徴量の算出		*/
/****************************************************************************/
static VD fn_exist_leading_car_calc_char_iq(const S4 as4_a_nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],
											const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4],
											const FL fl_a_area_x_near,
											const FL fl_a_area_x_far,
											const FL fl_a_area_y_forward,
											const FL fl_a_area_y_backward,
											U1* pu1_a_N,
											FL* pfl_a_ave_theta,
											FL* pfl_a_var_theta)
{
	U1 u1_t_lp_freq_bin_range;		/* nearfield_doaとsot_check_objectのforループ(仕様書ではi) */
	FL fl_t_min_x;					/* エリア内の観測点のうち、最も自車寄りの点のX方向距離 */
	U1 u1_t_N;						/* エリア内観測点数 */
	FL fl_t_ave_theta;				/* エリア内観測点方位の平均 */
	S4 s4_t_ave_theta_sum;			/* エリア内観測点方位の加算値 */
	FL fl_t_var_theta;				/* エリア内観測点方位の分散 */
	S4 s4_t_var_theta_sum;			/* エリア内観測点方位の二乗の加算値 */

	/* 変数初期化 */
	fl_t_min_x = CFL_FLMAX;
	u1_t_N = (U1)0;
	fl_t_ave_theta = (FL)0.0F;
	s4_t_ave_theta_sum = (S4)0;
	fl_t_var_theta = (FL)0.0F;
	s4_t_var_theta_sum = (S4)0;

	/* エリア内の観測点のうち、最も自車寄りの点の X 方向距離を算出 */
	for (u1_t_lp_freq_bin_range = (U1)0; u1_t_lp_freq_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_freq_bin_range++) {
		if ((afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] > fl_a_area_x_near)					/* COND.n2_x */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < fl_a_area_x_far)					/* COND.n2_x */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] < fl_a_area_y_forward)				/* COND.n2_y */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] > fl_a_area_y_backward)) {			/* COND.n2_y */
			if (fl_t_min_x > afl_a_sot_check_object[u1_t_lp_freq_bin_range][0]) {
				fl_t_min_x = afl_a_sot_check_object[u1_t_lp_freq_bin_range][0];
			}
		}
	}

	for (u1_t_lp_freq_bin_range = (U1)0; u1_t_lp_freq_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_freq_bin_range++) {
		if (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] != (FL)CFL_UNKNOWN_VALUE) {				/* COND.n1 */
			if ((afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] > fl_a_area_x_near)					/* COND.n2_x */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < fl_a_area_x_far)					/* COND.n2_x */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] < fl_a_area_y_forward)				/* COND.n2_y */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] > fl_a_area_y_backward)) {			/* COND.n2_y */
				/* fl_t_min_xがFL_MAXのままこの処理に到達しても条件n2で弾かれるため、オーバーフローしない */
				if (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < (fl_t_min_x + (FL)3.0F)) {		/* COND.n3 */
					u1_t_N++;
					s4_t_ave_theta_sum +=  as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0];
					s4_t_var_theta_sum += (as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0] * as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0]);
				}
			}
		}
	}

	if (u1_t_N != (U1)0) {
		fl_t_ave_theta = (FL)s4_t_ave_theta_sum / (FL)u1_t_N;												/* PROC.1 */
		fl_t_var_theta = ((FL)s4_t_var_theta_sum / (FL)u1_t_N) - (fl_t_ave_theta * fl_t_ave_theta);			/* PROC.2 */
	} else {
		/* Ni or Nq=0 のときは①②はおこなわず、aveθi or aveθq = varθi or aveθq = 10000 とする */
		fl_t_ave_theta = (FL)10000.0F;
		fl_t_var_theta = (FL)10000.0F;
	}

	/* 最終結果を出力 */
	*pu1_a_N = u1_t_N;
	*pfl_a_ave_theta = fl_t_ave_theta;
	*pfl_a_var_theta = fl_t_var_theta;

	return;
}

/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_exist_leading_car_jdg					*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 並走車判定									*/
/*--------------------------------------------------------------------------*/
/* 引数			: u1_a_Ni					: エリア内観測点数(接近側)		*/
/* 				: u1_a_Nq					: エリア内観測点数(離脱側)		*/
/* 				: fl_a_ave_theta_i			: エリア内観測点方位の平均(接近側)*/
/* 				: fl_a_ave_theta_q			: エリア内観測点方位の平均(離脱側)*/
/* 				: fl_a_var_theta_i			: エリア内観測点方位の分散(接近側)*/
/* 				: fl_a_var_theta_q			: エリア内観測点方位の分散(離脱側)*/
/* 				: u1_a_flg_point_many		: 観測点数大フラグ				*/
/* 				: u1_a_flg_point_bias		: 観測点数偏りフラグ			*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: s2_g_curvr_for_base		: 推定R [m]						*/
/*				: fl_g_v_self_bsm_for_base	: 自車速 [km/h]					*/
/*				: afl_g_cvw_fcw_ftt_power[]	: 2FCWスペクトラム				*/
/*				: st_g_bsm_loop_data.s1_ctr_heisou_car	: 並走車存在カウンタ*/
/* <output>		: st_g_bsm_loop_data.s1_ctr_heisou_car	: 並走車存在カウンタ*/
/*				: st_g_bsm_loop_data.u1_flg_heisou_car	: 並走車存在フラグ	*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: s4_abs, u1_slipjdg_get_noise_floor,						*/
/* 				: u1_cmn_autoaxis_aac_road_ref_bin_calc, fl_abs				*/
/*				: fl_slipjdg_calc_average_of_2fcw_noise_floor				*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定 ⅲ)並走車判定		*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_jdg(const U1 u1_a_Ni,
												 const U1 u1_a_Nq,
												 const FL fl_a_ave_theta_i,
												 const FL fl_a_ave_theta_q,
												 const FL fl_a_var_theta_i,
												 const FL fl_a_var_theta_q,
												 const U1 u1_a_flg_point_many,
												 const U1 u1_a_flg_point_bias)
{
	S4 s4_t_curvr_for_base_abs;			/* 推定Rの絶対値ラッチ変数 */
	U1 u1_t_counter_vehicle_flg;		/* 対向車存在フラグ */
	U1 u1_t_continue_flg;				/* 対向車平均電力算出処理実行フラグ */
	U1 u1_t_noise_floor_calc_flg;		/* 今周期ノイズフロア計算を実施したか否かのフラグ */
	FL fl_t_noise_floor;				/* 2FCWの今サイクルノイズフロア */
	FL fl_t_v_self_bin_w_margin_dummy;	/* 路面反射bin 路面反射bin算出関数を使用するためのダミー変数 */
	U1 u1_t_v_self_bin_w_margin;		/* 路面反射bin */
	U2 u2_t_lp_fcw_fft_data;			/* 2FCWスペクトラムのループ変数(仕様書ではi) */
	FL fl_t_diff_ave_iq_abs;			/* ave_theta_iとave_theta_qの差の絶対値 */

	/* 推定Rの絶対値を設定 */
	s4_t_curvr_for_base_abs = s4_abs((S4)s2_g_curvr_for_base);

	/* 低速走行時、かつ、急旋回中でない場合のみ判定を実施する */
	if ((CFL_CANOUT_VSELF_MIN <= fl_g_v_self_bsm_for_base)			/* COND.n6 */
	&&  (fl_g_v_self_bsm_for_base < (FL)CU1_HEISOU_VSELF_MAX)		/* COND.n6 */
	&&  (s4_t_curvr_for_base_abs >= (S4)CANOUT_CURVER_MIN)) {		/* COND.n7 */
		/***** ⅲ-1）対向車存在判定 *****/
		/* 2FCWのノイズフロアが今周期算出されているか確認 */
		u1_t_noise_floor_calc_flg = u1_slipjdg_get_noise_floor(&fl_t_noise_floor);

		/* 今周期ノイズフロアが算出されていない場合は算出処理を実施 */
		if (u1_t_noise_floor_calc_flg == CU1_DF_OFF) {
			fl_t_noise_floor = fl_slipjdg_calc_average_of_2fcw_noise_floor(afl_g_cvw_fcw_ftt_power, (U2)20);
		}

		/* 路面反射binの算出 */
		u1_t_continue_flg = u1_cmn_autoaxis_aac_road_ref_bin_calc(fl_g_v_self_bsm_for_base, &fl_t_v_self_bin_w_margin_dummy, &u1_t_v_self_bin_w_margin);

		u1_t_counter_vehicle_flg = (U1)0;
		if (u1_t_continue_flg == (U1)1) {
			/* 0～路面反射binの2FCW FFT電力を確認し、閾値を超える電力値があれば、対向車ありとする */
			for (u2_t_lp_fcw_fft_data = (U2)0; u2_t_lp_fcw_fft_data < (U2)u1_t_v_self_bin_w_margin; u2_t_lp_fcw_fft_data++) {
				if (afl_g_cvw_fcw_ftt_power[u2_t_lp_fcw_fft_data] > (fl_t_noise_floor + (FL)15.0F)) {	/* COND.n8 */
					u1_t_counter_vehicle_flg = (U1)1;
				}
			}
		}

		/***** ⅲ-2）並走車存在カウンタ処理 *****/
		if ((u1_a_Ni >= (U1)2)							/* COND.n9 */
		&&  (u1_a_Nq >= (U1)2)							/* COND.n9 */
		&&  (u1_t_counter_vehicle_flg == (U1)0)) {		/* COND.n10 */
			/* 条件n11で使用する絶対値を設定 */
			fl_t_diff_ave_iq_abs = fl_abs(fl_a_ave_theta_i - fl_a_ave_theta_q);
			if (fl_t_diff_ave_iq_abs < (FL)15.0F) {		/* COND.n11 */
				if ((fl_a_var_theta_i < (FL)100)			/* COND.n12 */
				&&  (fl_a_var_theta_q < (FL)100)) {			/* COND.n12 */
					if (((s4_t_curvr_for_base_abs > (S4)CU1_HEISOU_CURVER_MIN)		/* COND.n13 */
					||   (u1_a_flg_point_many == (U1)1))							/* COND.n14 */
					&&  (u1_a_flg_point_bias == (U1)0)) {							/* COND.n15 */
						st_g_bsm_loop_data.s1_ctr_heisou_car += (S1)1;				/* PROC.3 */
					}
				} else {
					/* 並走車存在カウンタ保持（何もしない）*/
				}
			} else {
				if (u1_a_flg_point_many == (U1)1) {							/* COND.n14 */
					st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)2;				/* PROC.4b */
				} else {
					st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)1;				/* PROC.4a */
				}
			}
		} else {
			st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)1;						/* PROC.4a */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if ((u1_a_flg_point_bias == (U1)1)											/* COND.n15' */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < (S4)WALL_REJECT_TH3)) {		/* COND.n18 */
				 st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)WALL_REJECT_TH3;			/* PROC.8 */
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
		}
	} else {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)0;
	}

	/* 0～18で上下限ガード */
	if (st_g_bsm_loop_data.s1_ctr_heisou_car > (S1)18) {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)18;
	} else if (st_g_bsm_loop_data.s1_ctr_heisou_car < (S1)0) {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)0;
	} else {
		/* カウンタの値保持 */
	}

	/***** ⅲ-3）並走車存在フラグ処理 *****/
	if (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)0) {
		if (st_g_bsm_loop_data.s1_ctr_heisou_car >= (S1)12) {		/* COND.n16 */
			st_g_bsm_loop_data.u1_flg_heisou_car = (U1)1;			/* PROC.5 */
		}
	}

	if (st_g_bsm_loop_data.u1_flg_heisou_car != (U1)0) {
		if (st_g_bsm_loop_data.s1_ctr_heisou_car <= (S1)6) {		/* COND.n17 */
			st_g_bsm_loop_data.u1_flg_heisou_car = (U1)0;			/* PROC.6 */
		}
	}

	return;
}

/****************************************************************************/
/* 関数名		: fn_bsm_low_judge_exist_leading_car_mediation				*/
/*--------------------------------------------------------------------------*/
/* 機能			: 並走車存在判定 調停処理									*/
/*--------------------------------------------------------------------------*/
/* 引数			: なし														*/
/* 戻り値		: なし														*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: st_g_bsm_loop_data.u1_flg_heisou_car	: 並走車存在フラグ	*/
/* <output>		: st_g_bsm_loop_data.as4_slow_sot_find	: 低速SoTフラグ		*/
/*				: st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum : 低速SoT判定評価値*/
/*--------------------------------------------------------------------------*/
/* 参照関数		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)低速 SoT 判定処理 8)並走車存在判定 ⅳ)調停処理			*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_mediation(VD)
{
	/* 並走車存在フラグが1のとき、壁判定結果とSoT判定結果を書き換える */
	if (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)1) {
		/* SoTフラグ */
		st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)1;
		/* 低速SoT判定評価値 */
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)1;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)1;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
		/* 壁フラグ */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
	}

	return;
}


 /****************************************************************************/
/* 関数名		: check_fm_object											*/
/*--------------------------------------------------------------------------*/
/* 機能			: (1)FMCW前側方物標判定処理									*/
/*				:	2) FMCW信号の周波数ピークの検出							*/
/*				:	3) 周波数ピーク周辺の反射波の到来方向の推定				*/
/*				:	4) 周波数ピーク周辺の反射波の到来方向の分散の算出		*/
/*				:	5) 前側方物標の有無判定									*/
/*				:	6) 物標情報の算出										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:  (1)-2)FMCW信号の周波数ピークの検出						*/
/*				:～(1)-6)物標情報の算出										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_fm_object(								/* [return] object flag */
	const NORMAL_BSM ast_a_normal_sot_prev[1],	/* [in] object data */
	S4 s4_a_leading_flg,						/* [in] leading car flag */
	NORMAL_BSM ast_a_normal_sot[1]				/* [out] object data */
)
{
	S4 tmp_fm_obj_flg = 0;

	/* 変数宣言 */
	S4 i,j;
	S4 tmp_peak_num_up = 0;
	S4 tmp_peak_num_dn = 0;
	FL tmp_wall_thres_up[NB_FFT_PT];
	FL tmp_wall_thres_dn[NB_FFT_PT];
	S4 start_bin;
	S4 end_bin;
	S4 tmp_freq_peak_bin_up[PEAK_BUFFSIZE];
	S4 tmp_freq_peak_bin_dn[PEAK_BUFFSIZE];
	FL tmp_freq_peak_power_up[PEAK_BUFFSIZE];
	FL tmp_freq_peak_power_dn[PEAK_BUFFSIZE];
	FL tmp_doa_spec_up[SOT_FMPEAK_RANGE][N_DOA];
	FL tmp_doa_spec_dn[SOT_FMPEAK_RANGE][N_DOA];
	S4 tmp_doa_peak_bin_up[SOT_FMPEAK_RANGE][1];
	S4 tmp_doa_peak_bin_dn[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_peak_pow_up[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_peak_pow_dn[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_ave_up = 0;
	FL tmp_doa_ave_dn = 0;
	FL tmp_doa_pow_ave_up = 0;
	FL tmp_doa_pow_ave_dn = 0;
	FL tmp_angle_ave_up = 0;
	FL tmp_angle_ave_dn = 0;

	S4 s4_t_sample_num_up_for_ave = 0;
	S4 s4_t_sample_num_dn_for_ave = 0;
	S4 s4_t_sample_num_up_for_dev;
	S4 s4_t_sample_num_dn_for_dev;
	FL tmp_doa_dev_up = 0;
	FL tmp_doa_dev_dn = 0;

	S4 tmp_peak_index_dn = -1;
	S4 tmp_peak_index_up = -1;
	FL tmp_peak_power_diff_min = TH_TT_MAX;
	FL tmp_doa_diff = 180.0F;
	FL tmptmp_peak_power_diff = 0.0F;
	FL tmp_peak_power_up_max = 0.0F;
	FL tmp_peak_power_dn_max = 0.0F;

	FL tmp_fm_theta = 0.0F;
	FL tmp_fm_v = 0.0F;
	FL tmp_fm_vx = 0.0F;
	FL tmp_fm_vy = 0.0F;

	U4 u4_t_lp_fft_pt;
	U4 u4_t_lp_peak_buffsize;
	U4 u4_t_lp_sot_fmpeak_range;
	U4 u4_t_lp_n_doa;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	FL fl_t_diff_doa_ave_up_dn_abs;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* ローカル変数初期化 */
	for (u4_t_lp_fft_pt = (U4)0; u4_t_lp_fft_pt < (U4)NB_FFT_PT; u4_t_lp_fft_pt++) {
		tmp_wall_thres_up[u4_t_lp_fft_pt] = (FL)0.0F;
		tmp_wall_thres_dn[u4_t_lp_fft_pt] = (FL)0.0F;
	}

	for (u4_t_lp_peak_buffsize = (U4)0; u4_t_lp_peak_buffsize < (U4)PEAK_BUFFSIZE; u4_t_lp_peak_buffsize++) {
		tmp_freq_peak_bin_up[u4_t_lp_peak_buffsize] = (S4)0;
		tmp_freq_peak_bin_dn[u4_t_lp_peak_buffsize] = (S4)0;
		tmp_freq_peak_power_up[u4_t_lp_peak_buffsize] = (FL)0.0F;
		tmp_freq_peak_power_dn[u4_t_lp_peak_buffsize] = (FL)0.0F;
	}

	for (u4_t_lp_sot_fmpeak_range = (U4)0; u4_t_lp_sot_fmpeak_range < (U4)SOT_FMPEAK_RANGE; u4_t_lp_sot_fmpeak_range++) {
		for (u4_t_lp_n_doa = (U4)0; u4_t_lp_n_doa < (U4)N_DOA; u4_t_lp_n_doa++) {
			tmp_doa_spec_up[u4_t_lp_sot_fmpeak_range][u4_t_lp_n_doa] = (FL)0.0F;
			tmp_doa_spec_dn[u4_t_lp_sot_fmpeak_range][u4_t_lp_n_doa] = (FL)0.0F;
		}
		tmp_doa_peak_bin_up[u4_t_lp_sot_fmpeak_range][0] = (S4)-1;
		tmp_doa_peak_bin_dn[u4_t_lp_sot_fmpeak_range][0] = (S4)-1;
		tmp_doa_peak_pow_up[u4_t_lp_sot_fmpeak_range][0] = (FL)0.0F;
		tmp_doa_peak_pow_dn[u4_t_lp_sot_fmpeak_range][0] = (FL)0.0F;
	}

	/***** 2) FMCW信号の周波数ピークの検出 *****/
	/* ■■■■■ (ⅰ)ピークサーチ範囲の設定 ■■■■■ */
	tmp_peak_index_dn = -1;
	tmp_peak_index_up = -1;
	start_bin = NB_FFT_PT/2+2;																							/* PROC.1 */
	end_bin = NB_FFT_PT/2+(S4)(SOT_WALL_MAX/RCOF*0.5F)+SOT_FMPEAK_RANGE;												/* PROC.2 */
	if(st_g_bsm_loop_data.afl_wall_width[0]!= WALL_MAX)																	/* COND.a1 */
	{
		end_bin = NB_FFT_PT/2+(S4)((st_g_bsm_loop_data.afl_wall_width[0]+SOT_WALL_OFFSET)/RCOF*0.5F)+SOT_FMPEAK_RANGE;	/* PROC.3 */
	}
	if(s4_a_leading_flg == 0)											/* COND.a2 */
	{
		/* ■■■■■ (ⅱ)下りピークサーチ ■■■■■ */
		tmp_peak_num_dn = s4_search_freq_peaks_within_freq_range(		/* SEC.2-2(2) */
			(const FL *)afl_g_cvw_lfm_ftt_power[1],						/* [in] */
			tmp_freq_peak_bin_dn,										/* [out] */
			tmp_freq_peak_power_dn,										/* [out] */
			(const FL *)tmp_wall_thres_dn,								/* [in] */
			0,
			start_bin,													/* [in] FREQ BIN START */
			end_bin														/* [in] FREQ BIN END */
		);
		/* ■■■■■ (ⅲ)上りピークサーチ ■■■■■ */
		tmp_peak_num_up = s4_search_freq_peaks_within_freq_range(		/* SEC.2-2(2) */
			(const FL *)afl_g_cvw_lfm_ftt_power[0],						/* [in] */
			tmp_freq_peak_bin_up,										/* [out] */
			tmp_freq_peak_power_up,										/* [out] */
			(const FL *)tmp_wall_thres_up,								/* [in] */
			0,
			start_bin,													/* [in] FREQ BIN START */
			end_bin														/* [in] FREQ BIN END */
		);

		/* ■■■■■ (ⅳ)ピークペアの選択 ■■■■■ */
		for(i=0; i<tmp_peak_num_up; i++)
		{
			for(j=0; j<tmp_peak_num_dn; j++)
			{
				tmptmp_peak_power_diff =  fl_abs(tmp_freq_peak_power_up[i] - tmp_freq_peak_power_dn[j]);/* PROC.1 */
				if ((tmp_freq_peak_power_up[i] >= tmp_peak_power_up_max)								/* COND.a4 */
				&&  (tmp_freq_peak_power_dn[j] >= tmp_peak_power_dn_max)								/* COND.a5 */
				&&  ((tmp_peak_power_diff_min > tmptmp_peak_power_diff)									/* COND.a8 */
				||   ((tmp_freq_peak_power_up[i] >= (tmp_peak_power_up_max + (FL)10.0F))				/* COND.a30 */
				&&    (tmp_freq_peak_power_dn[j] >= (tmp_peak_power_dn_max + (FL)10.0F))				/* COND.a31 */
				&&    ((tmp_peak_power_diff_min + (FL)5.0F) > tmptmp_peak_power_diff)))) {				/* COND.a32 */
					tmp_peak_power_diff_min = tmptmp_peak_power_diff;									/* PROC.2 */
					tmp_peak_power_up_max = tmp_freq_peak_power_up[i];									/* PROC.3 */
					tmp_peak_power_dn_max = tmp_freq_peak_power_dn[j];									/* PROC.4 */
					tmp_peak_index_up = i;																/* PROC.5 */
					tmp_peak_index_dn = j;																/* PROC.6 */
				}
			}
		}
	}
	else
	{
		if( ast_a_normal_sot_prev[0].fl_Robs != CFL_UNKNOWN_VALUE )											/* COND.a3 */
		{
			tmp_peak_index_up = 0;																			/* PROC.1(ⅲ) */
			tmp_peak_index_dn = 0;																			/* PROC.1(ⅱ) */
			tmp_freq_peak_bin_up[tmp_peak_index_up] = ast_a_normal_sot_prev[0].s4_bin_up;					/* PROC.2(ⅲ) */
			tmp_freq_peak_bin_dn[tmp_peak_index_dn] = ast_a_normal_sot_prev[0].s4_bin_dn;					/* PROC.2(ⅱ) */
			tmp_freq_peak_power_up[tmp_peak_index_up] = ast_a_normal_sot_prev[0].fl_power_up;				/* PROC.3(ⅲ) */
			tmp_freq_peak_power_dn[tmp_peak_index_dn] = ast_a_normal_sot_prev[0].fl_power_dn;				/* PROC.3(ⅱ) */
		}
	}

	/***** 3) 周波数ピーク周辺の反射波の到来方向の推定 *****/
	if ((tmp_peak_index_dn != -1)																		/* COND.a9 */
	&&  (tmp_peak_index_up != -1)) {																	/* COND.a10 */
		/* ■■■■■ (ⅰ)角度スペクトラムの算出 ■■■■■ */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			/* DOWN */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(afl_g_cvw_lfm_ryy_matrix[1][tmp_freq_peak_bin_dn[tmp_peak_index_dn]-2 + i]),	/* [in] */
				tmp_doa_spec_dn[i],																			/* [out] */
				1,																							/* [in] dn */
				tmp_freq_peak_bin_dn[tmp_peak_index_dn]-2 + i
			);
			/* UP */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(afl_g_cvw_lfm_ryy_matrix[0][tmp_freq_peak_bin_up[tmp_peak_index_up]-2 + i]),	/* [in] */
				tmp_doa_spec_up[i],																			/* [out] */
				0,																							/* [in] up */
				tmp_freq_peak_bin_up[tmp_peak_index_up]-2 + i
			);
		}

		/* ■■■■■ (ⅱ)角度スペクトラムのピークサーチ ■■■■■ */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			/* DOWN */
			s4_search_peak_bf(
				(const FL *)tmp_doa_spec_dn[i],		/* [in] */
				tmp_doa_peak_bin_dn[i],				/* [out] */
				tmp_doa_peak_pow_dn[i],				/* [out] */
				1									/* [in] */
			);
			/* UP */
			s4_search_peak_bf(
				(const FL *)tmp_doa_spec_up[i],		/* [in] */
				tmp_doa_peak_bin_up[i],				/* [out] */
				tmp_doa_peak_pow_up[i],				/* [out] */
				1									/* [in] */
			);
		}

		/***** 4) 周波数ピーク周辺の反射波の到来方向の分散の算出 *****/
		s4_t_sample_num_up_for_ave = (S4)0;
		s4_t_sample_num_dn_for_ave = (S4)0;
		s4_t_sample_num_up_for_dev = (S4)0;
		s4_t_sample_num_dn_for_dev = (S4)0;
		/* ■■■■■ (ⅰ)平均値の算出 ■■■■■ */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			if ((tmp_doa_peak_bin_dn[i][0] != (S4)-1)					/* COND.a11 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			&&  (tmp_doa_peak_bin_dn[i][0] > (S4)53)) {					/* COND.a33 搭載角度50deg用の条件 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			&&  (tmp_doa_peak_bin_dn[i][0] > (S4)90 - (S4)AXIS_DEFAULT + (S4)3)) {                 /* COND.a33 搭載角度20deg用の条件 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
				tmp_doa_ave_dn += (FL)tmp_doa_peak_bin_dn[i][0];
				tmp_doa_pow_ave_dn += tmp_doa_peak_pow_dn[i][0];
				s4_t_sample_num_dn_for_ave++;
			}
			if ((tmp_doa_peak_bin_up[i][0] != (S4)-1)					/* COND.a11 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			&&  (tmp_doa_peak_bin_up[i][0] > (S4)53)) {					/* COND.a33 搭載角度50deg用の条件 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			&&  (tmp_doa_peak_bin_up[i][0] > (S4)90 - (S4)AXIS_DEFAULT + (S4)3)) {                 /* COND.a33 搭載角度20deg用の条件 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
				tmp_doa_ave_up += (FL)tmp_doa_peak_bin_up[i][0];
				tmp_doa_pow_ave_up += tmp_doa_peak_pow_up[i][0];
				s4_t_sample_num_up_for_ave++;
			}
		}
		
		if (s4_t_sample_num_dn_for_ave != (S4)0) {
			tmp_doa_ave_dn = tmp_doa_ave_dn / (FL)s4_t_sample_num_dn_for_ave;
			tmp_doa_pow_ave_dn = tmp_doa_pow_ave_dn / (FL)s4_t_sample_num_dn_for_ave;
		} else {
			/* ピークがないときは平均値を算出できないため0を入れる */
			tmp_doa_ave_dn = (FL)0.0F;
			tmp_doa_pow_ave_dn = (FL)0.0F;
		}
		
		if (s4_t_sample_num_up_for_ave != (S4)0) {
			tmp_doa_ave_up = tmp_doa_ave_up / (FL)s4_t_sample_num_up_for_ave;
			tmp_doa_pow_ave_up = tmp_doa_pow_ave_up / (FL)s4_t_sample_num_up_for_ave;
		} else {
			/* ピークがないときは平均値を算出できないため0を入れる */
			tmp_doa_ave_up = (FL)0.0F;
			tmp_doa_pow_ave_up = (FL)0.0F;
		}

		/* ■■■■■ (ⅱ)分散値の算出 ■■■■■ */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			if(	tmp_doa_peak_bin_dn[i][0] != -1 )						/* COND.a11 */
			{
				tmp_doa_dev_dn += ((FL)tmp_doa_peak_bin_dn[i][0] - tmp_doa_ave_dn) * ((FL)tmp_doa_peak_bin_dn[i][0] - tmp_doa_ave_dn);
				s4_t_sample_num_dn_for_dev++;
			}
			if(	tmp_doa_peak_bin_up[i][0] != -1 )						/* COND.a11 */
			{
				tmp_doa_dev_up += ((FL)tmp_doa_peak_bin_up[i][0] - tmp_doa_ave_up) * ((FL)tmp_doa_peak_bin_up[i][0] - tmp_doa_ave_up);
				s4_t_sample_num_up_for_dev++;
			}
		}
		if (s4_t_sample_num_dn_for_dev != (S4)0) {
			tmp_doa_dev_dn = tmp_doa_dev_dn / (FL)s4_t_sample_num_dn_for_dev;
		} else {
			/* ピークがないときは分散を算出できないため不定値を示す999.9を入れる */
			tmp_doa_dev_dn = (FL)999.9F;
		}
		
		if (s4_t_sample_num_up_for_dev != (S4)0) {
			tmp_doa_dev_up = tmp_doa_dev_up / (FL)s4_t_sample_num_up_for_dev;
		} else {
			/* ピークがないときは分散を算出できないため不定値を示す999.9を入れる */
			tmp_doa_dev_up = (FL)999.9F;
		}
	}

	/***** 5) 前側方物標の有無判定 *****/
	/* DOAを車座標系に変換 */
	/* DOWN */
	tmp_angle_ave_dn = -(st_g_bsm_loop_data.afl_installed_angle[0] + DOA_ANG_PER_BIN*tmp_doa_ave_dn + DOA_BIN_START_ANG);
	/* UP */
	tmp_angle_ave_up = -(st_g_bsm_loop_data.afl_installed_angle[0] + DOA_ANG_PER_BIN*tmp_doa_ave_up + DOA_BIN_START_ANG);
	tmp_fm_obj_flg = 0;
	if ((tmp_peak_index_dn != -1)													/* COND.a9 */
	&&  (tmp_peak_index_up != -1)) {												/* COND.a10 */
		if ((tmp_freq_peak_power_up[tmp_peak_index_up] > WALL_OBJECT_POW_TH)		/* COND.a12 */
		&&  (tmp_freq_peak_power_dn[tmp_peak_index_dn] > WALL_OBJECT_POW_TH)) {		/* COND.a13 */
			/* 条件2(併走車がいるとき) */
			if ((s4_a_leading_flg != 0)												/* COND.a28 */
			&&  ((s4_t_sample_num_up_for_ave > (SOT_FMPEAK_RANGE - (S4)1))			/* COND.a14 */
			||   (s4_t_sample_num_dn_for_ave > (SOT_FMPEAK_RANGE - (S4)1)))			/* COND.a15 */
			&&  (tmp_angle_ave_up < WALL_ANGLE_TH_BACKWARD_WITHCAR)					/* COND.a16 */
			&&  (tmp_angle_ave_dn < WALL_ANGLE_TH_BACKWARD_WITHCAR)					/* COND.a17 */
			&&  (tmp_angle_ave_up > WALL_ANGLE_TH_FORWARD_WITHCAR)					/* COND.a18 */
			&&  (tmp_angle_ave_dn > WALL_ANGLE_TH_FORWARD_WITHCAR)					/* COND.a19 */
			&&  (tmp_doa_dev_dn < WALL_ANGLE_TH_DIV_WITHCAR)						/* COND.a20 */
			&&  (tmp_doa_dev_up < WALL_ANGLE_TH_DIV_WITHCAR)) {						/* COND.a21 */
				tmp_fm_obj_flg = 1;
			} else if (((s4_t_sample_num_up_for_ave > (SOT_FMPEAK_RANGE - (S4)1))	/* COND.a14 */
				   ||   (s4_t_sample_num_dn_for_ave > (SOT_FMPEAK_RANGE - (S4)1)))	/* COND.a15 */
				   &&  (tmp_angle_ave_up < WALL_ANGLE_TH_BACKWARD_NOCAR)			/* COND.a22 */
				   &&  (tmp_angle_ave_dn < WALL_ANGLE_TH_BACKWARD_NOCAR)			/* COND.a23 */
				   &&  (tmp_angle_ave_up > WALL_ANGLE_TH_FORWARD_NOCAR)				/* COND.a24 */
				   &&  (tmp_angle_ave_dn > WALL_ANGLE_TH_FORWARD_NOCAR)				/* COND.a25 */
				   &&  (tmp_doa_dev_dn < WALL_ANGLE_TH_DIV_NOCAR)					/* COND.a26 */
				   &&  (tmp_doa_dev_up < WALL_ANGLE_TH_DIV_NOCAR)) {				/* COND.a27 */
				/* 条件1(併走車がいないとき=壁) */
				tmp_fm_obj_flg = 1;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				/* Reset fm object flag if the doa difference between up and dn is too large and peak power is small */
				fl_t_diff_doa_ave_up_dn_abs = fl_abs(tmp_doa_ave_up - tmp_doa_ave_dn);

				if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (U1)1)				/* COND.a50 */
				&&  (st_g_bsm_loop_data.s4_flg_alarm == (U1)0)						/* COND.a51 */
				&&  (fl_t_diff_doa_ave_up_dn_abs > (FL)20.0F)						/* COND.a52 */
				&&  (tmp_freq_peak_power_up[tmp_peak_index_up] < (FL)60.0F)			/* COND.a53_up */
				&&  (tmp_freq_peak_power_dn[tmp_peak_index_dn] < (FL)60.0F)) {		/* COND.a53_dn */
					tmp_fm_obj_flg = (S4)0;
				}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
			} else {
				/* 何もしない */
			}
		}
	}

	/***** 6) 物標情報の算出 *****/
	if(tmp_fm_obj_flg == 1)													/* COND. a29 */
	{
		/* NORMAL_BSMデータセット */
		/* S4 */
		ast_a_normal_sot[0].s4_bin_up = tmp_freq_peak_bin_up[tmp_peak_index_up];
		ast_a_normal_sot[0].s4_bin_dn = tmp_freq_peak_bin_dn[tmp_peak_index_dn];
		ast_a_normal_sot[0].fl_bin_up_interpolate = (FL)tmp_freq_peak_bin_up[tmp_peak_index_up];
		ast_a_normal_sot[0].fl_bin_dn_interpolate = (FL)tmp_freq_peak_bin_dn[tmp_peak_index_dn];

		ast_a_normal_sot[0].s4_bin_up_music = (S4)tmp_doa_ave_up;
		ast_a_normal_sot[0].s4_bin_dn_music = (S4)tmp_doa_ave_dn;
		ast_a_normal_sot[0].fl_doa_up_interpolate = tmp_doa_ave_up;
		ast_a_normal_sot[0].fl_doa_dn_interpolate = tmp_doa_ave_dn;

		/* FL */
		ast_a_normal_sot[0].fl_power_up = tmp_freq_peak_power_up[tmp_peak_index_up];
		ast_a_normal_sot[0].fl_power_dn = tmp_freq_peak_power_dn[tmp_peak_index_dn];
		ast_a_normal_sot[0].fl_power_up_music = tmp_doa_pow_ave_up;
		ast_a_normal_sot[0].fl_power_dn_music = tmp_doa_pow_ave_dn;
		ast_a_normal_sot[0].fl_theta_up = fl_transform_doabin_to_rad(	/* DBF(S4) */
			ast_a_normal_sot[0].s4_bin_up_music,
			0
		);
		ast_a_normal_sot[0].fl_theta_dn = fl_transform_doabin_to_rad(	/* DBF(S4) */
			ast_a_normal_sot[0].s4_bin_dn_music,
			1
		);
		ast_a_normal_sot[0].fl_Robs	=  -RCOF * (FL)(ast_a_normal_sot[0].s4_bin_up + ast_a_normal_sot[0].s4_bin_dn - NB_FFT_PT);
		ast_a_normal_sot[0].fl_Rxobs = (FL)(ast_a_normal_sot[0].fl_Robs*(FL)fl_sin( DOA_ANG_PER_BIN*0.5F*(ast_a_normal_sot[0].fl_theta_up+ast_a_normal_sot[0].fl_theta_dn) )+ st_g_bsm_loop_data.afl_installed_angle[1]);
		ast_a_normal_sot[0].fl_Ryobs = (FL)(ast_a_normal_sot[0].fl_Robs*(FL)fl_cos( DOA_ANG_PER_BIN*0.5F*(ast_a_normal_sot[0].fl_theta_up+ast_a_normal_sot[0].fl_theta_dn) ) );
		tmp_fm_theta = 0.0F;
		tmp_fm_v = 0.0F;
		tmp_fm_vx = 0.0F;
		tmp_fm_vy = 0.0F;
		tmp_fm_theta = 0.5F*(ast_a_normal_sot[0].fl_theta_up + ast_a_normal_sot[0].fl_theta_dn);
		tmp_fm_v = -VCOF * (FL)(ast_a_normal_sot[0].s4_bin_up - ast_a_normal_sot[0].s4_bin_dn);
		tmp_fm_vx = 0.0F;
		tmp_fm_vy = tmp_fm_v;

		tmp_fm_vy = fl_get_vy(tmp_fm_v, fl_cos(tmp_fm_theta), ast_a_normal_sot[0].fl_Ryobs, fl_g_v_self_bsm_for_base);

		ast_a_normal_sot[0].fl_Vobs = tmp_fm_v;
		ast_a_normal_sot[0].fl_Vxobs = tmp_fm_vx;
		ast_a_normal_sot[0].fl_Vyobs = tmp_fm_vy;
	}

	return tmp_fm_obj_flg;
}


 /****************************************************************************/
/* 関数名		: check_fm_spectrum											*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)ＦＭＣＷ物標接近判定処理								*/
/*				:	FMCW 信号の周波数スペクトラムの形状の特徴から，			*/
/*				:	接近する物標の有無の判定を行う．						*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)ＦＭＣＷ物標接近判定処理								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_fm_spectrum(								/* [return] approaching object flag */
	FL sot_thres_up[NB_FFT_PT],						/* [out](for debug) threashold for wall estimation（FM up) */
	FL sot_thres_dn[NB_FFT_PT]						/* [out](for debug) threashold for wall estimation（FM dn) */
)
{
	/* 変数宣言 */
	S4 tmp_fm_flg = 0;

	S4 wall_check_up[3];
	S4 wall_check_dn[3];
	S4 wall_bin_up[3];
	S4 wall_bin_dn[3];
	FL wall_pow_up[3];
	FL wall_pow_dn[3];
	S4 ret_up;	/* (not used) */
	S4 ret_dn;	/* (not used) */

	/* 三値化															*/
	/*        ___														*/
	/*       |   |          ↑											*/
	/*       |   |          | WALL_FREQ_POW_DIFF 以上上昇(または下降)	*/
	/*     __|   |_____ ....↓											*/
	/*    |            |    ↑											*/
	/*    |            |    | WALL_FREQ_POW_DIFF 以上上昇(または下降)	*/
	/* ___|            |___ ↓											*/
	/*																	*/

	/* UP */
	/***** 1) 平均化スペクトラムの算出 *****/
	set_freq_threshold_without_center_mask(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],		/* [in] */
		sot_thres_up								/* [out] */
	);
	/***** 2) ベース電力の算出 *****/
	/***** 3) 接近判定用特徴量の算出 *****/
	/***** 4) 接近判定 *****/
	ret_up = set_wall_freq_threshold(
		(const FL *)sot_thres_up,		/* [in] */
		sot_thres_up,					/* [out] */
		wall_check_up,					/* [out] */
		wall_bin_up,					/* [out] */
		wall_pow_up,					/* [out] */
		WALL_UP_FREQ_BIN_TH_LOWER_LIMIT,/* [in] */
		WALL_UP_FREQ_BIN_TH_UPPER_LIMIT /* [in] */
	);

	/* DOWN */
	/***** 1) 平均化スペクトラムの算出 *****/
	set_freq_threshold_without_center_mask(
		(const FL *)afl_g_cvw_lfm_ftt_power[1],		/* [in] */
		sot_thres_dn								/* [out] */
	);
	/***** 2) ベース電力の算出 *****/
	/***** 3) 接近判定用特徴量の算出 *****/
	ret_dn = set_wall_freq_threshold(
		(const FL *)sot_thres_dn,		/* [in] */
		sot_thres_dn,					/* [out] */
		wall_check_dn,					/* [out] */
		wall_bin_dn,					/* [out] */
		wall_pow_dn,					/* [out] */
		WALL_DN_FREQ_BIN_TH_LOWER_LIMIT,/* [in] */
		WALL_DN_FREQ_BIN_TH_UPPER_LIMIT /* [in] */
	);

	/***** 4) 接近判定 *****/
	tmp_fm_flg = s4_bsm_side_check_fm_approaching_object(
		(const FL *)sot_thres_up,			/* [in] */
		(const FL *)sot_thres_dn,			/* [in] */
		(const S4 *)wall_check_up,			/* [in] */
		(const S4 *)wall_check_dn,			/* [in] */
		(const S4 *)wall_bin_up,			/* [in] */
		(const S4 *)wall_bin_dn,			/* [in] */
		(const FL *)wall_pow_up,			/* [in] */
		(const FL *)wall_pow_dn				/* [in] */
	);

	return tmp_fm_flg;
}


/****************************************************************************/
/* 関数名		: s4_bsm_side_check_fm_approaching_object					*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-4)接近判定											*/
/*				:	FMCWの上り信号と下り信号の接近判定用の特徴量に基づき、	*/
/*				:	接近する物標があるか否かの判定を行う。自車が他車を追い	*/
/*				:	越す場合には、他車は自車のすぐ隣に存在することとなり、	*/
/*				:	中心bin付近の電力は大きく増大する。そのため、少なくとも	*/
/*				:	第2変化点までは観測されることとなる。そこで、第2変化点、*/
/*				:	または、第3変化点が所定の範囲内にあり、変化量が所定の値	*/
/*				:	よりも大きいとき、接近する物標があると判定する。		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-4)接近判定											*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_check_fm_approaching_object(
	const FL afl_a_sot_thres_up[NB_FFT_PT],
	const FL afl_a_sot_thres_dn[NB_FFT_PT],
	const S4 as4_a_wall_check_up[3],
	const S4 as4_a_wall_check_dn[3],
	const S4 as4_a_wall_bin_up[3],
	const S4 as4_a_wall_bin_dn[3],
	const FL afl_a_wall_pow_up[3],
	const FL afl_a_wall_pow_dn[3]
)
{
	S4 i;
	S4 s4_t_fm_flg;
	S4 tmp_up_flg = 0;
	S4 tmp_dn_flg = 0;

	s4_t_fm_flg = 0;

	/***** 4) 接近判定 *****/
	/* ３変化点判定の考え方														*/
	/* base-><-0-><-1-><-2----> (:wall_check_** … ステップがあれば1)			*/
	/*                  _______													*/
	/*                 |														*/
	/*            _____|														*/
	/*           |																*/
	/*       ____|																*/
	/*      |																	*/
	/* _____|																	*/
	/*           +     +    +													*/
	/*          [1]   [2]  [3]  (:wall_bin_** … 始まりのbin)					*/
	/*  <-3->のステップがあって													*/
	/*  [2]が WALL_FREQ_BIN_LOWER_STEP1 ～ WALL_FREQ_BIN_UPPER_STEP1 の間		*/
	/*  [3]が WALL_FREQ_BIN_LOWER_STEP2 ～ WALL_FREQ_BIN_UPPER_STEP2 の間		*/

	/* ■■■■■ (ⅰ)下り信号の判定 ■■■■■ */
	tmp_dn_flg = 0;
	for (i = 1; i < WALL_FREQ_BIN_TH_STEPS; i++) {
		if ((as4_a_wall_check_dn[i] == 1)										/* COND.b9 */
		||  ((afl_a_wall_pow_dn[i] - afl_a_sot_thres_dn[0]) >= WALL_PEAK_TH)) {	/* COND.b10 */
			if ((as4_a_wall_bin_dn[i] > WALL_FREQ_BIN_LOWER_STEP1_DN)			/* COND.b11 */
			&&  (as4_a_wall_bin_dn[i] <= WALL_FREQ_BIN_UPPER_STEP1_DN)) {		/* COND.b12 */
				tmp_dn_flg = 1;													/* PROC.1 */
				break;
			}
		}
	}
	/* ■■■■■ (ⅱ)上り信号の判定 ■■■■■ */
	tmp_up_flg = 0;
	for (i = 1; i < WALL_FREQ_BIN_TH_STEPS; i++) {
		if ((as4_a_wall_check_up[i] == 1)										/* COND.b13 */
		&&  ((afl_a_wall_pow_up[i] - afl_a_sot_thres_up[0]) >= WALL_PEAK_TH)) {	/* COND.b14	 */
			if (as4_a_wall_bin_up[i] >= as4_a_wall_bin_dn[1]) {					/* COND.b15 */
				tmp_up_flg = 1;													/* PROC.1 */
				break;
			}
		}
	}
	/* ■■■■■ (ⅲ)統合判定 ■■■■■ */
	if ((tmp_dn_flg != 0)											/* COND.b16 */
	&&  (tmp_up_flg != 0)) {										/* COND.b17 */
		s4_t_fm_flg = 1;											/* PROC.1 */
	}

	return s4_t_fm_flg;
}


/****************************************************************************/
/* 関数名		: set_stationary_doa_line_2f								*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-2)停止物曲線の算出処理								*/
/*				:	レーダにて検出される速度は、レーダに向かう方向の成分のみ*/
/*				:	となるため、自車が速度v_self[km/h]で走行しているときに	*/
/*				:	方位θxにある停止物の検出速度Vxは、距離にかかわらず、	*/
/*				:	関数内の式で求められる。従って、自車速v_self[km/h]で走行*/
/*				:	しているときの、各方位binにおける停止物の検出速度に相当	*/
/*				:	する2FCWの周波数binは下記の速度方位曲線として求められる	*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-2)停止物曲線の算出処理								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD set_stationary_doa_line_2f(
	S4 stationary_doa_line[N_DOA],		/* [out] 停止物のDOA/FREQ */
	S4 v0_doa_def,						/* [in] */
	S4 v0_doa							/* [in] */
)
{
	S4 i;
	S4 car_dir = v0_doa - v0_doa_def;	/* => 0 */
	for(i=0; i<N_DOA; i++)
	{
		stationary_doa_line[i] = NB_FFT_PT_2F / 2 + (S4)(fl_g_v_self_bsm_for_base
												  * fl_cos(PI / (FL)180.0F * (FL)car_dir) / 3.6F
												  * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa))
												  / VCOF_2F);
	}
}


/****************************************************************************/
/* 関数名		: set_sot_limit_doa_line_2f									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-3)SoT検出速度限界曲線の算出処理						*/
/*				:	(7)-2)と同様に、自車との相対速度がSoTの検出限界			*/
/*				:	SoT_V_TH_BWD[km/h]の物体の速度方位曲線を求める。		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-3)SoT検出速度限界曲線の算出処理						*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD set_sot_limit_doa_line_2f(
	S4 sot_limit_doa_line[N_DOA],		/* [out] SoTのDOA/FREQ */
	S4 v0_doa_def,						/* [in] */
	S4 v0_doa,							/* [in] */
	FL v_sot_offset						/* [in] */
)
{
	S4 i;
	S4 car_dir = v0_doa - v0_doa_def;	/* =>0 */
	S4 tmp_doa = 0;
	for (i = 0; i < N_DOA; i++) {
		tmp_doa = NB_FFT_PT_2F / 2 + (S4)((v_sot_offset)
								   * fl_cos(PI / (FL)180.0F * (FL)car_dir) / 3.6F
								   * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa))
								   / VCOF_2F);

		if (tmp_doa > 0) {				/* COND.!g3	 */
			sot_limit_doa_line[i] = tmp_doa;
		} else {
			sot_limit_doa_line[i] = 0;
		}
	}
}


/****************************************************************************/
/* 関数名		: calc_nearfield_doa_2f_I									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-1)2FCW低速方位推定処理								*/
/*				:	2FCW信号の中心周波数周辺の反射波の到来方向の推定を行う。*/
/*				:	本処理では、近距離で比較的狭い検出範囲内で最も反射強度の*/
/*				:	強い物標を検出することを目的としているため、複数の物標を*/
/*				:	分離する必要性は高くない。そこで、BF(Beam forming）方式	*/
/*				:	による方向推定を行う。									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-1)2FCW低速方位推定処理								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
U1 calc_nearfield_doa_2f_I(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 130-144binのDOAピーク(最大1個/1bin), */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] 上記各binのDOAピーク数(最大1個) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[WAVE_NUMBER_MAX];
	FL tmp_peak_power[WAVE_NUMBER_MAX];
	U1 u1_t_num_nearfield_doa_2f_i;
	U2 u2_t_lp_martrix_2f;
	U1 u1_t_lp_sot_check;
	FL afl_t_tmp_Ryy[CU2_PCS_FCW_RYY_MATRIX_2F];
	FL fl_t_tmp_theta;
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Vobs;
	U1 u1_t_exist_flag;
	U1 u1_t_lp_wave;
	AUTOAXIS_DATA_FORMAT st_t_auto_axis_data;
	
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	u1_t_num_nearfield_doa_2f_i = (U1)0;
	u1_t_exist_flag = CU1_FALSE;

	st_t_auto_axis_data.s2_freq_bin = (S2)-1;
	for (u1_t_lp_wave = (U1)0; u1_t_lp_wave < WAVE_NUMBER_MAX; u1_t_lp_wave++) {
		st_t_auto_axis_data.s4_doa_bin[u1_t_lp_wave] = (S4)-1;
		st_t_auto_axis_data.fl_doa_pow[u1_t_lp_wave] = (FL)-1.0F;
	}

	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			nearfield_doa[i][j] = -1;
		}
		nearfield_doa_peak_num[i] = 0;
	}

	for (i = start_freq_bin; i < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		nearfield_doa_peak_num[i-start_freq_bin] = 0;
#ifdef _USE_MUSIC_FOR_SLOW_SOT
		s4_calc_spec_music_4ch_all(
			afl_g_cvw_fcw_ryy_matrix[i],			/* [in] */
			spec_doa,								/* [out] */
			2,										/* [in] */
			1										/* [in] */
		);
		nearfield_doa_peak_num[i-start_freq_bin] = s4_peak_search_music_fsk_all_doa(
			spec_doa,
			tmp_doa,
			tmp_peak_power,
			1
		);
#else
		 /* 自動軸調整で該当binが方位展開済か確認 */
		u1_t_exist_flag = u1_cmn_autoaxis_get_already_2f_dbf_data((U2)i, &st_t_auto_axis_data);
		
		if (u1_t_exist_flag == CU1_FALSE) {
			/* 展開されていなければ方位展開を実施する */
			/* DBF DOA */
			fn_calc_spec_bf_4ch_2f(
				(const FL *)(afl_g_cvw_fcw_ryy_matrix[i]),
				spec_doa,
				1,
				i
			);

			/* DOA peaks */
			nearfield_doa_peak_num[i-start_freq_bin] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);
		} else {
			/* 展開済の場合は方位展開結果を流用する */
			tmp_doa[0] = st_t_auto_axis_data.s4_doa_bin[0];
			tmp_peak_power[0] = st_t_auto_axis_data.fl_doa_pow[0];
			nearfield_doa_peak_num[i - start_freq_bin] = WAVE_NUMBER_MAX;
		}
#endif
		for(j=0; j<nearfield_doa_peak_num[i-start_freq_bin]; j++ )
		{
			nearfield_doa[i-start_freq_bin][j] = tmp_doa[j];
		}
	}

	for (i = start_freq_bin; i < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (afl_g_cvw_fcw_ftt_power[i] < (CFL_SLOW_SOT_FFT_POW_TH - (FL)5.0F)) {		/* COND.g1' */
			for (j = 0; j < nearfield_doa_peak_num[i - start_freq_bin]; j++ ) {
				nearfield_doa[i - start_freq_bin][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[i - start_freq_bin] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_i++;
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (afl_g_cvw_fcw_ftt_power[i] < CFL_SLOW_SOT_FFT_POW_TH) {					/* COND.g1 */
			for (j = 0; j < nearfield_doa_peak_num[i - start_freq_bin]; j++ ) {
				nearfield_doa[i - start_freq_bin][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[i - start_freq_bin] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_i++;
		}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	}
	
	for (i = (S4)0; i < SLOW_SOT_FREQ_BIN_RANGE; i++) {
		if (nearfield_doa[i][0] != (S4)-1) {
			/* 補助物標認識処理の(4)物標情報算出処理(2FCW) 1) 推定方向を車座標系に変換,	*/
			/* 2)距離の算出, 3)速度の算出を実施している									*/
			/* 上述の処理が変更された場合はこちらも変更すること							*/
			for (u2_t_lp_martrix_2f = (U2)0; u2_t_lp_martrix_2f < CU2_PCS_FCW_RYY_MATRIX_2F; u2_t_lp_martrix_2f++) {
				afl_t_tmp_Ryy[u2_t_lp_martrix_2f] = afl_g_cvw_fcw_ryy_matrix_2f[SLOW_SOT_FREQ_BIN_START_I + i][u2_t_lp_martrix_2f];
			}
			
			fl_t_tmp_theta = -(PI / (FL)180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + (FL)nearfield_doa[i][0] + (FL)DOA_BIN_START_ANG));
			fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
			
			/* rx */
			afl_a_sot_check_object_i[i][0] = (fl_t_tmp_Robs * fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
			/* ry */
			afl_a_sot_check_object_i[i][1] = fl_t_tmp_Robs * fl_cos(fl_t_tmp_theta);
			
			fl_t_tmp_Vobs = VCOF_2F * ((FL)(SLOW_SOT_FREQ_BIN_START_I + i) - (FL)NB_FFT_PT_2F / (FL)2.0F);
			
			/* Vx */
			if (fl_sin(fl_t_tmp_theta) != (FL)0.0F) {
				/* 補助物標認識処理と処理が異なる（3.6を掛けている） */
				afl_a_sot_check_object_i[i][2] = (fl_t_tmp_Vobs / fl_sin(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_i[i][2] = fl_t_tmp_Vobs;
			}
			
			/* Vy */
			if (fl_cos(fl_t_tmp_theta) != (FL)0.0F) {
				/* 補助物標認識処理と処理が異なる（3.6を掛けている） */
				afl_a_sot_check_object_i[i][3] = (fl_t_tmp_Vobs / fl_cos(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_i[i][3] = fl_t_tmp_Vobs;
			}
		} else {
			for (u1_t_lp_sot_check = (U1)0; u1_t_lp_sot_check < (U1)4; u1_t_lp_sot_check++) {
				afl_a_sot_check_object_i[i][u1_t_lp_sot_check] = CFL_UNKNOWN_VALUE;
			}
		}
	}
	
	return u1_t_num_nearfield_doa_2f_i;
}


/****************************************************************************/
/* 関数名		: calc_nearfield_doa_2f_Q									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-1)2FCW低速方位推定処理								*/
/*				:	2FCW信号の中心周波数周辺の反射波の到来方向の推定を行う。*/
/*				:	本処理では、近距離で比較的狭い検出範囲内で最も反射強度の*/
/*				:	強い物標を検出することを目的としているため、複数の物標を*/
/*				:	分離する必要性は高くない。そこで、BF(Beam forming）方式	*/
/*				:	による方向推定を行う。									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-1)2FCW低速方位推定処理								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
U1 calc_nearfield_doa_2f_Q(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 126-112binのDOAピーク(最大1個/1bin), */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] 上記各binのDOAピーク数(最大1個) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[WAVE_NUMBER_MAX];
	FL tmp_peak_power[WAVE_NUMBER_MAX];
	U1 u1_t_num_nearfield_doa_2f_q;
	U2 u2_t_lp_martrix_2f;
	U1 u1_t_lp_sot_check;
	FL afl_t_tmp_Ryy[CU2_PCS_FCW_RYY_MATRIX_2F];
	FL fl_t_tmp_theta;
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Vobs;
	U1 u1_t_exist_flag;
	U1 u1_t_lp_wave;
	AUTOAXIS_DATA_FORMAT st_t_auto_axis_data;
	
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	u1_t_num_nearfield_doa_2f_q = (U1)0;
	u1_t_exist_flag = CU1_FALSE;

	st_t_auto_axis_data.s2_freq_bin = (S2)-1;
	for (u1_t_lp_wave = (U1)0; u1_t_lp_wave < WAVE_NUMBER_MAX; u1_t_lp_wave++) {
		st_t_auto_axis_data.s4_doa_bin[u1_t_lp_wave] = (S4)-1;
		st_t_auto_axis_data.fl_doa_pow[u1_t_lp_wave] = (FL)-1.0F;
	}

	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			nearfield_doa[i][j] = -1;
		}
		nearfield_doa_peak_num[i] = 0;
	}

	for (i = start_freq_bin; i > (start_freq_bin - SLOW_SOT_FREQ_BIN_RANGE); i--) {
		nearfield_doa_peak_num[start_freq_bin-i] = 0;
#ifdef _USE_MUSIC_FOR_SLOW_SOT
		calc_spec_music_4ch_all(
			afl_g_cvw_fcw_ryy_matrix[i],			/* [in] */
			spec_doa,								/* [out] */
			2,										/* [in]	 */
			1										/* [in] */
		);
		nearfield_doa_peak_num[start_freq_bin-i] = s4_peak_search_music_fsk_all_doa(
			spec_doa,
			tmp_doa,
			tmp_peak_power,
			1
		);
#else
		 /* 自動軸調整で該当binが方位展開済か確認 */
		u1_t_exist_flag = u1_cmn_autoaxis_get_already_2f_dbf_data((U2)i, &st_t_auto_axis_data);
		
		if (u1_t_exist_flag == CU1_FALSE) {
			/* 展開されていなければ方位展開を実施する */
			fn_calc_spec_bf_4ch_2f(
				(const FL *)(afl_g_cvw_fcw_ryy_matrix[i]),
				spec_doa,
				1,
				i
			);

			/* DOA peaks */
			nearfield_doa_peak_num[start_freq_bin-i] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);
		} else {
			/* 展開済の場合は方位展開結果を流用する */
			tmp_doa[0] = st_t_auto_axis_data.s4_doa_bin[0];
			tmp_peak_power[0] = st_t_auto_axis_data.fl_doa_pow[0];
			nearfield_doa_peak_num[start_freq_bin - i] = WAVE_NUMBER_MAX;
		}
#endif
		for(j=0; j<nearfield_doa_peak_num[start_freq_bin-i]; j++ )
		{
			nearfield_doa[start_freq_bin-i][j] = tmp_doa[j];
		}
	}

	for (i = start_freq_bin; i > (start_freq_bin - SLOW_SOT_FREQ_BIN_RANGE); i--) {
		if (afl_g_cvw_fcw_ftt_power[i] < CFL_SLOW_SOT_FFT_POW_TH) {						/* COND.g1 */
			for (j = 0; j < nearfield_doa_peak_num[start_freq_bin - i]; j++) {
				nearfield_doa[start_freq_bin - i][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[start_freq_bin - i] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_q++;
		}
	}

	for (i = (S4)0; i < SLOW_SOT_FREQ_BIN_RANGE; i++) {
		if (nearfield_doa[i][0] != (S4)-1) {
			/* 補助物標認識処理の(4)物標情報算出処理(2FCW) 1) 推定方向を車座標系に変換,	*/
			/* 2)距離の算出, 3)速度の算出を実施している									*/
			/* 上述の処理が変更された場合はこちらも変更すること							*/
			for (u2_t_lp_martrix_2f = (U2)0; u2_t_lp_martrix_2f < CU2_PCS_FCW_RYY_MATRIX_2F; u2_t_lp_martrix_2f++) {
				afl_t_tmp_Ryy[u2_t_lp_martrix_2f] = afl_g_cvw_fcw_ryy_matrix_2f[SLOW_SOT_FREQ_BIN_START_Q - i][u2_t_lp_martrix_2f];
			}
			
			fl_t_tmp_theta = -(PI / (FL)180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + (FL)nearfield_doa[i][0] + (FL)DOA_BIN_START_ANG));
			fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
			
			/* rx */
			afl_a_sot_check_object_q[i][0] = (fl_t_tmp_Robs * fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
			/* ry */
			afl_a_sot_check_object_q[i][1] = fl_t_tmp_Robs * fl_cos(fl_t_tmp_theta);
			
			fl_t_tmp_Vobs = VCOF_2F * ((FL)(SLOW_SOT_FREQ_BIN_START_Q - i) - (FL)NB_FFT_PT_2F / (FL)2.0F);
			
			/* Vx */
			if (fl_sin(fl_t_tmp_theta) != (FL)0.0F) {
				/* 補助物標認識処理と処理が異なる（3.6を掛けている） */
				afl_a_sot_check_object_q[i][2] = (fl_t_tmp_Vobs / fl_sin(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_q[i][2] = fl_t_tmp_Vobs;
			}
			
			/* Vy */
			if (fl_cos(fl_t_tmp_theta) != (FL)0.0F) {
				/* 補助物標認識処理と処理が異なる（3.6を掛けている） */
				afl_a_sot_check_object_q[i][3] = (fl_t_tmp_Vobs / fl_cos(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_q[i][3] = fl_t_tmp_Vobs;
			}
		} else {
			for (u1_t_lp_sot_check = (U1)0; u1_t_lp_sot_check < (U1)4; u1_t_lp_sot_check++) {
				afl_a_sot_check_object_q[i][u1_t_lp_sot_check] = CFL_UNKNOWN_VALUE;
			}
		}
	}

	return u1_t_num_nearfield_doa_2f_q;
}


/****************************************************************************/
/* 関数名		: compare_forward_always_2									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)-(ⅳ)低速方位と停止物曲線の誤差算出（前方）			*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-5)-(ⅳ)低速方位と停止物曲線の誤差算出（前方）			*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
U1 compare_forward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, k;
	S4 start_bin;
	S4 end_bin;
	S4 doa_dif_sotlimit_forward = 0;
	FL tmp_vsin;
	FL doa_stationary;
	FL doa_nearfield;
	S4 end_doa;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;

	/* set freq bin range */
	start_bin = SLOW_SOT_FREQ_BIN_START_I;												/* PROC.5 */
	end_bin = stationary_doa_line[N_DOA - 1];											/* PROC.6 */
	if (end_bin > SLOW_SOT_FREQ_BIN_MAX) {												/* COND.g40 */
		end_bin = SLOW_SOT_FREQ_BIN_MAX;												/* PROC.7 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	end_doa = N_DOA;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)40;									/* PROC.17 搭載角度20deg用の処理 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	if( fl_g_v_self_bsm_for_base < 20.0F)
	{
		end_doa = N_DOA - AXIS_DEFAULT + 30;
	}
	if( fl_g_v_self_bsm_for_base < 13.0F)
	{
		end_doa = N_DOA - AXIS_DEFAULT + 20;
	}

	/* ■■■■■ (NEW) 周波数範囲の算出 ■■■■■ */
	for (i = SLOW_SOT_FREQ_BIN_START_I; i < (SLOW_SOT_FREQ_BIN_START_I + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		/* この関数はfl_g_v_self_bsm_for_baseが0のときはコールされないので0割はない */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;
		if( tmp_vsin > 1.0F)
		{
			tmp_vsin = 1.0F;
		}
		if( tmp_vsin < -1.0F)
		{
			tmp_vsin = -1.0F;
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;
		if(doa_stationary > N_DOA )
		{
			doa_stationary = N_DOA;
			end_bin = i - 1;
			break;
		}
		if(doa_stationary < 0 )
		{
			doa_stationary = 0;
			start_bin = i + 1;
			break;
		}
	}

	/* check difference from stationary line */
	for(k=0; k<SLOW_SOT_FREQ_BIN_RANGE; k++)
	{
		if (((SLOW_SOT_FREQ_BIN_START_I + k) >= start_bin)																	/* COND.g41 */
		&&  ((SLOW_SOT_FREQ_BIN_START_I + k) < end_bin)																		/* COND.g42 */
		&&  (afl_a_sot_check_object_i[k][0] != CFL_UNKNOWN_VALUE)															/* COND.g27 */
		&&  (afl_a_sot_check_object_i[k][0] > (FL)0.0F)																		/* COND.g28 */
		&&  (afl_a_sot_check_object_i[k][0] < (st_g_bsm_loop_data.afl_wall_width[0] * (FL)1.5F))							/* COND.g29 */
		&&  ((afl_a_sot_check_object_i[k][3] / (FL)3.6F) > (((FL)-1.0F * fl_g_v_self_bsm_for_base / (FL)3.6F) - (FL)10.0F))	/* COND.g30 */
		&&  (afl_a_sot_check_object_i[k][1] > (FL)-20.0F)) {																/* COND.g31 */
			for (i = 0; i < nearfield_doa_peak_num[k]; i++) {	/* i：各freq_binにおけるdoa peak数(=1) */
				if (fl_g_v_self_bsm_for_base != 0.0F) {																			/* COND.g56 */
					tmp_vsin = (FL)(SLOW_SOT_FREQ_BIN_START_I + k - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;	/* PROC.20 */
					if (tmp_vsin > 1.0F) {
						tmp_vsin = 1.0F;
					}
					
					if (tmp_vsin < -1.0F) {
						tmp_vsin = -1.0F;
					}
					
					doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.21 */
					doa_nearfield = (FL)nearfield_doa[k][i];													/* PROC.22 */
					if (doa_nearfield < (FL)end_doa) {															/* COND.g57 */
						/* difference between detected points and stationary line */
						doa_dif_sotlimit_forward = (S4)(doa_stationary - doa_nearfield);
						
						if (doa_dif_sotlimit_forward < (S4)0) {									/* COND.k32 */
							u1_t_num_forward++;
							
							if (doa_dif_sotlimit_forward < SoT_DIFF_TH3) {
								st_g_bsm_loop_data.as4_sot_check_sum[0][0][0] += (-doa_dif_sotlimit_forward);
							}
							
							/* number of points under stationary */
							if (doa_dif_sotlimit_forward < SoT_DIFF_TH1) {										/* COND.g43 slow */
								st_g_bsm_loop_data.as4_sot_check_points[0][0][0]++;								/* PROC.10 */
							} else if (doa_dif_sotlimit_forward < SoT_DIFF_TH2) {								/* COND.g44 mid */
								st_g_bsm_loop_data.as4_sot_check_points[0][1][0]++;								/* PROC.12 */
							} else if (doa_dif_sotlimit_forward < SoT_DIFF_TH3) {								/* COND.g45 fast */
								st_g_bsm_loop_data.as4_sot_check_points[0][2][0]++;								/* PROC.14 */
							} else {
								/* 何もしない */
							}
						} else {
							u1_t_num_backward++;
							
							if ((FL)doa_dif_sotlimit_forward > (SLOW_SOT_V0_DOA - (FL)SoT_DIFF_TH3)) {					/* COND.k33 */
								st_g_bsm_loop_data.as4_sot_check_sum[0][1][0] += doa_dif_sotlimit_forward;
							}
						}
					}
				}
			}
		}
	}

	return u1_t_num_forward;
}


/****************************************************************************/
/* 関数名		: compare_backward_always_2									*/
/*--------------------------------------------------------------------------*/
/* 機能			:  (7)-5)-(ⅴ)低速方位と停止物曲線の誤差算出（後方）		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(ⅴ)低速方位と停止物曲線の誤差算出（後方）		*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
U1 compare_backward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	S4 stationary_doa_line[N_DOA],									/* [in] */
	S4 sot_limit_doa_line_backward[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	FL v_sot_offset,												/* [in] */
	const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, k;
	S4 start_bin;
	S4 end_bin;
	S4 doa_dif_sotlimit_backward = 0;
	S4 s4_t_doa_dif_sotlimit_forward;

	S4 start_doa;
	S4 end_doa;
	S4 diff_th;
	FL tmp_vsin;
	FL fl_t_vsin2;
	FL doa_stationary;
	FL doa_sot_limit;
	FL fl_t_doa_sot_limit2;
	FL doa_nearfield;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;
	s4_t_doa_dif_sotlimit_forward = (S4)0;

	/* set freq bin range */
	start_bin = SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE+1;					/* PROC.5' */
	end_bin = SLOW_SOT_FREQ_BIN_START_Q;												/* PROC.6' */

	/* ■■■■■ (NEW) 周波数範囲の算出 ■■■■■ */
	for(i = SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE + 1; i<  SLOW_SOT_FREQ_BIN_START_Q; i++) {
		/* この関数はfl_g_v_self_bsm_for_baseが0のときはコールされないので0割はない */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;
		if( tmp_vsin > 1.0F)
		{
			tmp_vsin = 1.0F;
		}
		if( tmp_vsin < -1.0F)
		{
			tmp_vsin = -1.0F;
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;
		if(doa_stationary > N_DOA )
		{
			doa_stationary = N_DOA;
			end_bin = i - 1;
			break;
		}
		if(doa_stationary < 0 )
		{
			doa_stationary = 0;
			start_bin = i + 1;
			break;
		}
	}

	start_doa = N_DOA - AXIS_DEFAULT - 60;												/* PROC.17 */
	if (fl_g_v_self_bsm_for_base > 80.0F) {												/* COND.g58 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 35;											/* PROC.21 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)30;								/* PROC.21 搭載角度20deg用の処理 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (fl_g_v_self_bsm_for_base < 20.0F) {												/* COND.g54' */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 50;											/* PROC.22 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)60;								/* PROC.22 搭載角度20deg用の処理 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (fl_g_v_self_bsm_for_base < 13.0F) {														/* COND.g55' */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 40;											/* PROC.23 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)60;								/* PROC.23 搭載角度20deg用の処理 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	end_doa = N_DOA;																	/* PROC.18 */
	
	if (fl_g_v_self_bsm_for_base < (FL)20.0F) {											/* COND.k54' */
		end_doa = N_DOA - AXIS_DEFAULT + (S4)30;
	}
	if (fl_g_v_self_bsm_for_base < (FL)13.0F) {											/* COND.k55' */
		end_doa = N_DOA - AXIS_DEFAULT + (S4)20;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)50;									/* PROC.18 搭載角度20deg用の処理 */

	if (fl_g_v_self_bsm_for_base < (FL)30.0F) {											/* COND.k54'' */
		end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)30;									/* PROC.C */
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* check difference from sot-limit line */
	for (k = 0; k < SLOW_SOT_FREQ_BIN_RANGE; k++) {
		if (((SLOW_SOT_FREQ_BIN_START_Q - k) >= start_bin)																		/* COND.g41' */
		&&  ((SLOW_SOT_FREQ_BIN_START_Q - k) <= end_bin)																		/* COND.g42' */
		&&  (afl_a_sot_check_object_q[k][0] != CFL_UNKNOWN_VALUE)																/* COND.g27' */
		&&  (afl_a_sot_check_object_q[k][0] > (FL)0.0F)																			/* COND.g28' */
		&&  (afl_a_sot_check_object_q[k][0] < (st_g_bsm_loop_data.afl_wall_width[0] * (FL)1.5F))								/* COND.g29' */
		&&  ((afl_a_sot_check_object_q[k][3] / (FL)3.6F) > (((FL)-1.0F * fl_g_v_self_bsm_for_base / (FL)3.6F) - (FL)10.0F))		/* COND.g30' */
		&&  (afl_a_sot_check_object_q[k][1] > (FL)-20.0F)) {																	/* COND.g31' */
			for( i = 0; i < nearfield_doa_peak_num[k]; i++ )
			{
				diff_th = (S4)999;
				if ((nearfield_doa[k][i] > start_doa)										/* COND.g50 */
				&&  (nearfield_doa[k][i] < end_doa)) {										/* COND.g51 */
					doa_nearfield = (FL)nearfield_doa[k][i];							/* PROC.12 */
					
					/* difference between detected points and sot limit line */
					if (fl_g_v_self_bsm_for_base > CFL_SoT_V_TH_FWD) {									/* COND.g52 */
						if (afl_a_sot_check_object_q[k][1] < (FL)0.0F) {								/* COND.k35 */
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / v_sot_offset;				/* PROC.g */
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							doa_sot_limit = (FL)v0_doa - (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;		/* PROC.h */
							u1_t_num_backward++;															/* PROC.j */
							doa_dif_sotlimit_backward = (S4)(doa_sot_limit - doa_nearfield);				/* PROC.13 */
						} else {
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;			/* PROC.g' */
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							doa_sot_limit = (FL)v0_doa - (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;		/* PROC.h */
							u1_t_num_forward++;																/* PROC.i */
							s4_t_doa_dif_sotlimit_forward = (S4)(doa_sot_limit - doa_nearfield);			/* PROC.13' */
						}
						diff_th = CS4_SoT_DIFF_TH;															/* PROC.19 */
					}
					/* difference between detected points and stationary line (when subject is slow) */
					else if (fl_g_v_self_bsm_for_base > (FL)5.0F) {										/* COND.k26 */
						if (afl_a_sot_check_object_q[k][1] < (FL)0.0F) {								/* COND.k35 */
							fl_t_doa_sot_limit2 = (FL)0.0F;												/* PROC.l */
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							fl_t_vsin2 = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (S4)1 - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
							if (fl_t_vsin2 > 1.0F) {
								fl_t_vsin2 = 1.0F;
							}
							
							if (fl_t_vsin2 < -1.0F) {
								fl_t_vsin2 = -1.0F;
							}
							
							doa_sot_limit =  (FL)v0_doa - fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;				/* PROC.h */
							fl_t_doa_sot_limit2 = (FL)v0_doa - fl_cal_asin(fl_t_vsin2) * (FL)180.0F / PI;		/* PROC.h' */
							doa_dif_sotlimit_backward = (S4)(doa_sot_limit - doa_nearfield);					/* PROC.13 */
							
							if ((FL)doa_dif_sotlimit_backward < (doa_sot_limit - fl_t_doa_sot_limit2)) {		/* COND.k36 */
								doa_dif_sotlimit_backward = (S4)0;
							} else {
								diff_th = -CS4_SoT_DIFF_TH_SLOW;												/* PROC.20 */
								u1_t_num_backward++;															/* PROC.j */
							}
						}
					} else {
						/* 何もしない */
					}
					
					if ((doa_dif_sotlimit_backward > diff_th)													/* COND.k37 */
					&&  (diff_th != (S4)999)) {																	/* COND.k38 */
						st_g_bsm_loop_data.as4_sot_check_sum[1][0][0] += doa_dif_sotlimit_backward;				/* PROC.9' */
						st_g_bsm_loop_data.as4_sot_check_points[1][0][0]++;										/* PROC.10' */
					}
					
					if ((diff_th != (S4)999)																		/* COND.k38 */
					&&  (s4_t_doa_dif_sotlimit_forward < -diff_th)													/* COND.k39 */
					&&  (afl_a_sot_check_object_q[k][1] > (FL)0.0F)) {												/* COND.k40 */
						st_g_bsm_loop_data.as4_sot_check_sum[1][1][0] += s4_abs(s4_t_doa_dif_sotlimit_forward);		/* PROC.9'' */
						st_g_bsm_loop_data.as4_sot_check_points[1][1][0]++;											/* PROC.10'' */
					}
				}
			}
		}
	}

	return u1_t_num_backward;
}


/****************************************************************************/
/* 関数名		: check_sot_start											*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)-(ⅵ)SoT判定開始判定								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(ⅵ)SoT判定開始判定								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_sot_start(											/* [return] */
	FL dev[2],												/* [in] */
	U1 u1_a_alarming_flag
)
{
	S4 iRes = 0;
	S4 i;
	S4 count_backward = 0;
	S4 count_backward_sum = 0;
	S4 count_forward_fast = 0;
	S4 count_forward_mid = 0;
	S4 count_forward_slow = 0;
	S4 fwd_fast_th = 0;
	S4 fwd_mid_th = 0;
	S4 fwd_slow_th = 1;
	S4 fwd_fast_diff_th = 2;
	
	S4 s4_t_fwd_peak_pos;
	S4 s4_t_bwd_peak_pos;
	S4 s4_t_fwd_peak_val;
	S4 s4_t_bwd_peak_val;
	
	U1 u1_t_jdg_h84_flg;
	
	s4_t_fwd_peak_pos = (S4)-1;
	s4_t_bwd_peak_pos = (S4)-1;
	s4_t_fwd_peak_val = (S4)0;
	s4_t_bwd_peak_val = (S4)0;
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if (fl_g_v_self_bsm_for_base > (FL)30.0F) {
		fwd_fast_diff_th = (S4)50;
	}
#else
    マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	for (i = 0; i <= (CS4_SOT_CHECK_CYCLE_FWD + CS4_SOT_CHECK_CYCLE_BWD); i++)
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	for(i = (S4)0; i < CS4_SOT_CHECK_CYCLE_FWD; i++)
#else
    マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	{
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > s4_t_fwd_peak_val) {
			s4_t_fwd_peak_pos = i;
			s4_t_fwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[0][0][i];
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > s4_t_bwd_peak_val) {
			s4_t_bwd_peak_pos = i;
			s4_t_bwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[1][0][i];
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > fwd_fast_diff_th) {				/* COND.h4 */
			/* check fast point(Green) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][2][i] > fwd_fast_th) {			/* COND.h3 */
				count_forward_fast++;														/* PROC.3 */
			}
			/* check mid point (Yellow) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][1][i] > fwd_mid_th) {			/* COND.h5 */
				count_forward_mid++;														/* PROC.4 */
			}
			/* check slow point (Red) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][0][i] > fwd_slow_th) {			/* COND.h7 */
				count_forward_slow++;														/* PROC.5 */
			}
		}
		
		/* check backward point */
		if (st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > 2) {							/* COND.h9 */
			if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > (S4)0) {
				count_backward++;															/* PROC.6 */
			}
		}
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD) {	/* COND.h10 */
			count_backward_sum++;															/* PROC.7 */
		}
	}
	
	/* 条件h84の判定関数コール 仕様書の記述より条件h84の定義部分にコンパイルスイッチが入るため、	*/
	/* 条件h84の判定用関数を作り、判定結果を条件確認箇所で使用する									*/
	/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない				*/
	u1_t_jdg_h84_flg = u1_check_sot_start_h84(s4_t_fwd_peak_val, s4_t_bwd_peak_val);
	
	if ((((s4_t_fwd_peak_pos != (S4)-1)										/* COND.h82 */
	&&    (s4_t_fwd_peak_pos > s4_t_bwd_peak_pos))							/* COND.h83 */
	||   (u1_t_jdg_h84_flg == CU1_TRUE))									/* COND.h84 */
	&&  ((st_g_bsm_loop_data.as4_sot_check_sum[0][1][0] < (S4)400)			/* COND.h85 */
	||   (u1_a_alarming_flag != (U1)0))) {									/* COND.h86 */
		if ((count_forward_mid == (S4)0)						/* COND.h15 */
		&&  (count_forward_slow == (S4)0)) {					/* COND.h17 */
			if (count_forward_fast > 2) {						/* COND.g65 */
				iRes = 1;										/* PROC.8 */
			} else if (count_backward > 4) {					/* COND.g67 */
				iRes = 1;										/* PROC.8 */
			} else if ((fl_g_v_self_bsm_for_base < (FL)20.0F)	/* COND.h1 */
				   &&  (count_forward_fast != (S4)0)			/* COND.h11 */
				   &&  (count_backward_sum > (S4)2)) {			/* COND.h22 */
				iRes = 1;										/* PROC.8 */
			} else {
				/* 何もしない */
			}
		} else if ((count_forward_fast > 0)							/* COND.g71 */
			   ||  (count_forward_mid > 1)							/* COND.g72 */
			   ||  (count_forward_slow > 2)) {							/* COND.g73 */
			iRes = 1;											/* PROC.8 */
		} else {
			/* 何もしない */
		}
		
		if (fl_g_v_self_bsm_for_base < 20.0F) {					/* COND.g53 */
			if (count_backward > 6) {							/* COND.g75 */
				iRes = 1;										/* PROC.8 */
			}
		}
	}

	return iRes;
}

/****************************************************************************/
/* 関数名		: u1_check_sot_start_h84									*/
/*--------------------------------------------------------------------------*/
/* 機能			: SoT判定開始判定の条件h84判定関数							*/
/*--------------------------------------------------------------------------*/
/* 引数			: s4_a_fwd_peak_val		: （前方）SoT-停止物の差分 [in]		*/
/*				: s4_a_bwd_peak_val		: （後方）SoT-停止物の差分 [in]		*/
/* 戻り値		: u1_t_jdg_h84_flag		: 条件h84の判定結果格納変数			*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-015(291BCV)						*/
/*				: (7)低速SoT判定処理 5)低速ＳｏＴ判定処理					*/
/*				: (vi)SoT判定開始判定の条件h84								*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_check_sot_start_h84(S4 s4_a_fwd_peak_val, S4 s4_a_bwd_peak_val)
{
	/* 条件h84が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_h84_flag;				/* 条件h84判定結果格納変数 */

	/* FALSEで初期化 */
	u1_t_jdg_h84_flag = CU1_FALSE;

	/* 条件h84の判定 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degのとき */
	if (s4_a_fwd_peak_val > s4_a_bwd_peak_val) {
		u1_t_jdg_h84_flag = CU1_TRUE;
	} else {
		u1_t_jdg_h84_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* 搭載角度20degのとき */
	if (s4_a_fwd_peak_val > (s4_a_bwd_peak_val + (S4)30)) {
		u1_t_jdg_h84_flag = CU1_TRUE;
	} else {
		u1_t_jdg_h84_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	return u1_t_jdg_h84_flag;
}

/****************************************************************************/
/* 関数名		: check_sot_stop											*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)-(ⅷ)SoT判定終了判定								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(ⅷ)SoT判定終了判定								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_sot_stop(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
	S4 iRes = 0;
	S4 i,j;
	S4 count_backward = 0;
	S4 count_forward = 0;

	/* check forward point */
	for(i=0; i<6; i++)	
	{
		for(j=0; j<3; j++)
		{
			if (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] != 0) {		/* COND.h23' */
				count_forward++;												/* PROC.1 */
			}
		}
	}
	/* check backward point */
	for(i=0; i<6; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != 0)				/* COND.h26' */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > (S4)0)) {			/* COND.h81 */
			count_backward++;								/* PROC.2 */
		}
	}
	
	if ((count_forward < 1)									/* COND.h36 */
	&&  (count_backward < 1)) {								/* COND.h37 */
		iRes = 1;											/* PROC.3 */
	} else if (((dev[0] < CFL_SOT_DEV_TH)					/* COND.h38 */
		   ||   (count_forward < 1))						/* COND.h36 */
		   &&  (dev[1] < CFL_SOT_DEV_TH)) {					/* COND.h33' */
		iRes = 1;											/* PROC.3 */
	} else {
		/* 何もしない */
	}
		
	return iRes;
}


/****************************************************************************/
/* 関数名		: check_sot_on												*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)-(ⅸ)SoT ON 判定									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(ⅸ)SoT ON 判定									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_sot_on(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
/* sot_check_sum[0][0][*]	slow [red] */
/* sot_check_sum[0][1][*]	mid  [yellow]] */
/* sot_check_sum[0][2][*]	fast [green] */
/* sot_check_sum[1][0][*]	backward */

	S4 iRes = 0;
	S4 i;
	S4 count_backward = 0;
	S4 count_fast_sot4 = 0;
	S4 count_fast_sot5 = 0;
	S4 count_forward_fast = 0;
	S4 count_forward_mid = 0;
	S4 count_forward_slow = 0;
	S4 count_forward = 0;
	S4 wall = 0;
	
	S4 s4_t_count_fast_sot;
	S4 s4_t_count_fast_sot_bwd;
	
	S4 s4_t_th_point_sum;
	S4 s4_t_fwd_point_sum;
	U1 u1_t_lp_data;
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	S4 s4_t_fwd_check_sum_ave;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* 搭載角度20degでは定義なし */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	
	s4_t_count_fast_sot = (S4)0;
	s4_t_count_fast_sot_bwd = (S4)0;
	
	/* Check forward sot-stationary point */
	for(i=0; i<12; i++) 
	{
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > -SoT_DIFF_TH3) {		/* COND.h40 */
			/* low relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][0][i] != (S4)0) {		/* COND.h39 */
				count_forward_slow++;												/* PROC.1 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][0][i] > (S4)1)		/* COND.h41 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* mid. relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][1][i] != (S4)0) {		/* COND.h45 */
				count_forward_mid++;												/* PROC.6 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][1][i] > (S4)1)		/* COND.h47 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* fast relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][2][i] != (S4)0) {		/* COND.h50 */
				count_forward_fast++;												/* PROC.10 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][2][i] > (S4)1)		/* COND.h52 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* Fast-SoT checking */
			if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > (S4)115) {			/* COND.h42 */
				s4_t_count_fast_sot++;
			}
		}
	}
	
	/* Check backward sot-stationary point */
	for (i = (S4)0; i < (S4)CU1_SOT_CHECK_CYCLE; i++) {
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != (S4)0)											/* COND.h26'' */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD)) {					/* COND.h10 */
			count_fast_sot4++;
			
			if (i < CS4_SOT_CHECK_CYCLE_BWD) {																	/* COND.h53 */
				count_fast_sot5++;
			}
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_points[1][1][i] > (S4)1) {												/* COND.h43 */
			s4_t_count_fast_sot_bwd++;
		}
	}

	/* Set the wall flag on if the detection meets the following conditions */
	if ((count_forward_fast + count_forward_mid + count_forward_slow) < ((S4)CU1_SOT_CHECK_CYCLE * (S4)2)) {				/* COND.h70 (h70-1 + h70-2 +h70-3) */
		if (((count_forward_fast + count_forward_mid + count_forward_slow) <= (S4)((FL)CU1_SOT_CHECK_CYCLE * (FL)1.5F))			/* COND.h71 */
		&&  (count_fast_sot4 < (S4)3)																							/* COND.h72 */
		&&  (s4_t_count_fast_sot_bwd < (S4)3)) {																				/* COND.h56 */
			wall = (S4)1;																											/* PROC.13 */
		}
		
		if ((count_fast_sot4 < (S4)3)																		/* COND.h72 */
		&&  (count_forward < (S4)1)) {																		/* COND.h73 */
			wall = (S4)1;																					/* PROC.13 */
		}
		
		if ((dev[1] < WALL_DEV_TH4)																		/* COND.h75 */
		&&  (count_fast_sot4 < (S4)5)) {																/* COND.h76 */
			wall = (S4)1;																					/* PROC.13 */
		}
	} else {
		if ((dev[1] < WALL_DEV_TH4)																		/* COND.h75 */
		&&  (count_forward < (S4)4)																		/* COND.h57 */
		&&  (count_fast_sot4 < (S4)4)) {																/* COND.h58 */
			wall = (S4)1;																					/* PROC.13 */
		}
		
		if ((s4_t_count_fast_sot_bwd < (S4)3)															/* COND.h56 */
		&&  (count_forward < (S4)2)																		/* COND.h77 */
		&&  (count_fast_sot4 < (S4)1)) {																/* COND.h66 */
			wall = (S4)1;																					/* PROC.13 */
		}
	}
	
	if (wall == (S4)0) {																				/* COND.h78 */
		iRes = (S4)1;																						/* PROC.14 */
	}
	
	/**** 前方点総数確認 ***/
	/* 隣車線の有無に応じて判定閾値を設定する */
	if (st_g_bsm_loop_data.u1_count_adjacent_lane_exist > (U1)10) {										/* COND.h87 */
		s4_t_th_point_sum = (S4)3;
	} else {
		s4_t_th_point_sum = (S4)10;
	}


	/* 1s間の前方点数総和(低相対速、中相対速の前方点数)を算出。総和が少なすぎる場合は、SoT ON 判定=OFFとする*/
	s4_t_fwd_point_sum = (S4)0;
	for (u1_t_lp_data = (U1)0; u1_t_lp_data < (U1)12; u1_t_lp_data++) {
		s4_t_fwd_point_sum += (st_g_bsm_loop_data.as4_sot_check_points[0][0][u1_t_lp_data] + st_g_bsm_loop_data.as4_sot_check_points[0][1][u1_t_lp_data]);
	}

	/* SoT ON 判定 */
	if (s4_t_fwd_point_sum < s4_t_th_point_sum) {
		iRes = (S4)0;				/* PROC.15 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((st_g_bsm_loop_data.as4_sot_check_sum[0][0][11] - st_g_bsm_loop_data.as4_sot_check_sum[0][0][0] > (S4)100)	/* COND.h88 */
	&&  (st_g_bsm_loop_data.as4_sot_check_points[0][0][0] < (S4)3)													/* COND.h89 */
	&&  (count_fast_sot5 < (S4)3)) {																				/* COND.h90 */
		iRes = (S4)0;														/* PROC.15 */
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/*** 前方点のばらつき確認 ***/
	/* 1s間に観測されるSoT-停止物の差分平均値が小さすぎる場合は、									*/
	/* SoT車両でない可能性が高いため、SoT ON判定をキャンセルする。本判定は自車高速時のみ実施する	*/
	/* （前方）SoT-停止物の差分1s平均算出 */
	s4_t_fwd_check_sum_ave = (S4)0;
	for (u1_t_lp_data = (U1)0; u1_t_lp_data < (U1)12; u1_t_lp_data++) {
		s4_t_fwd_check_sum_ave += st_g_bsm_loop_data.as4_sot_check_sum[0][0][u1_t_lp_data];
	}
	s4_t_fwd_check_sum_ave /= (S4)12;

	/* SoT ONキャンセル判定 */
	if ((s4_t_fwd_check_sum_ave < CS4_SOT_ON_CANCEL_CHECK_SUM_TH)		/* COND.h91 */
	&&  (fl_g_v_self_bsm_for_base >= (FL)CS4_SOT_ON_CANCEL_VN_TH)) {	/* COND.h92 */
		iRes = (S4)0;														/* PROC.15 */
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* 搭載角度20degでは処理なし */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */


	return iRes;
}


/****************************************************************************/
/* 関数名		: check_sot_off												*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-5)-(ⅶ)SoT Off判定									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	 (7)-5)-(ⅶ)SoT Off判定									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 check_sot_off(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
	S4 iRes = 0;
	S4 i,j;

	S4 count_backward1 = 0;
	S4 count_backward2 = 0;
	S4 count_forward1 = 0;
	S4 count_forward2 = 0;

	/* forward points */
	for(i=0; i<12; i++)
	{
		for(j=0; j<3; j++)
		{
			if (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] != 0) {			/* COND.h23 */
				count_forward1++;													/* PROC.1 */
				if ((i < CS4_SOT_CHECK_CYCLE_FWD)									/* COND.h24 */
				&&  (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] > 1)) {		/* COND.h25 */
					count_forward2++;												/* PROC.2 */
				}
			}
		}
	}

	/* backward points */
	for(i=0; i<12; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != 0)								/* COND.h26 */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD)) {	/* COND.h10 */
			count_backward1++;																	/* PROC.3 */
			if ((i < CS4_SOT_CHECK_CYCLE_FWD)													/* COND.h24  */
			&&  (st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > 1)) {						/* COND.h27 */
				count_backward2++;																/* PROC.4 */
			}
		}
	}

	if ((count_backward1 < 2)														/* COND.h28 */
	&&  (count_forward1 < 2)) {														/* COND.h29 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward1 < 2)													/* COND.h29 */
		   &&  (count_forward2 < 1)													/* COND.h30 */
		   &&  (count_backward1 < 6)) {												/* COND.h31 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward2 < 2)													/* COND.h32 */
		   &&  ((dev[1] < CFL_SOT_DEV_TH)											/* COND.h33 */
		   ||   (count_backward1 < 2))) {											/* COND.h28 */
		iRes = 1;																	/* PROC.5 */
	} else if (count_forward1 < 2) {												/* COND.h29 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward2 < 1)													/* COND.h30 */
		   &&  ((count_backward2 < 1)												/* COND.h34 */
		   ||   (st_g_bsm_loop_data.as4_slow_sot_find[1] >= WALL_REJECT_TH3))) {	/* COND.h35 */
		iRes = 1;																	/* PROC.5 */
	} else {
		/* 何もしない */
	}

	return iRes;
}

/********************************************************************************************/
/* 関数名		: fn_bsm_low_judge_check_sot_doa											*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: Check SoT DOA	 															*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: pfl_a_fast_sot_pow					: Fast-SoT power [in]				*/
/* 戻り値		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	: afl_g_cvw_lfm_ftt_power : FMCW FFT平均電力								*/
/*				: afl_g_cvw_lfm_ryy_matrix: FMCW 自己相関行列								*/
/* <output>		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: fn_calc_spec_bf_4ch_fm(), s4_search_peak_bf()								*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-007												*/
/*				  (7)低速 SoT 判定処理 5)低速ＳｏＴ判定処理 (x)Check SoT DOA    			*/
/********************************************************************************************/
VD fn_bsm_low_judge_check_sot_doa(FL* pfl_a_fast_sot_pow)
{
	U2 u2_t_lp_fft_data;
	FL fl_t_max_peak_pow;
	S2 s2_t_fast_sot_check_bin;
	FL fl_t_fast_sot_check_doa_spec[N_DOA];
	S4 s4_t_fast_sot_check_doa[1];
	FL fl_t_fast_sot_check_doapow[1];
	FL fl_t_sot_direction;
	
	/* 変数初期化 */
	fl_t_max_peak_pow = (FL)0.0F;
	s2_t_fast_sot_check_bin = (S2)-1;
	
	for (u2_t_lp_fft_data = (U2)0; u2_t_lp_fft_data < N_DOA; u2_t_lp_fft_data++) {
		fl_t_fast_sot_check_doa_spec[u2_t_lp_fft_data] = (FL)0.0F;
	}
	
	s4_t_fast_sot_check_doa[0] = (S4)-1;
	fl_t_fast_sot_check_doapow[0] = (FL)0.0F;
	fl_t_sot_direction = (FL)180.0F - st_g_bsm_loop_data.afl_installed_angle[0];
	
	/* 最大電力のピークbinを抽出する */
	for (u2_t_lp_fft_data = (U2)257; u2_t_lp_fft_data < (U2)265; u2_t_lp_fft_data++) {
		if (afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data] > fl_t_max_peak_pow) {
			fl_t_max_peak_pow = afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data];
			s2_t_fast_sot_check_bin = (S2)u2_t_lp_fft_data;
		}
	}
	
	if ((s2_t_fast_sot_check_bin != (S2)-1)
	&&  (fl_t_max_peak_pow > (FL)53.0F)) {
		fn_calc_spec_bf_4ch_fm((const FL *)(&afl_g_cvw_lfm_ryy_matrix[0][s2_t_fast_sot_check_bin][0]), fl_t_fast_sot_check_doa_spec, (S4)0, (S4)s2_t_fast_sot_check_bin);
		
		s4_search_peak_bf((const FL *)fl_t_fast_sot_check_doa_spec, s4_t_fast_sot_check_doa, fl_t_fast_sot_check_doapow, (S4)1);
	}
	
	if ((FL)s4_t_fast_sot_check_doa[0] > fl_t_sot_direction) {
		*pfl_a_fast_sot_pow = fl_t_fast_sot_check_doapow[0];
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = CU1_SOT_CHECK_CYCLE + (S4)1;
	}
	
	return;
}


/****************************************************************************/
/* 関数名		: calc_deviation_of_doa_freq_line_stationary_2				*/
/*--------------------------------------------------------------------------*/
/* 機能			: (7)-4)低速方位と停止物方位曲線の分散算出処理				*/
/*				:	(7)-4)-(ⅰ)方位範囲の算出								*/
/*				:	(7)-4)-(ⅱ)周波数範囲の算出								*/
/*				:	(7)-4)-(ⅲ)fast-SoTの判定								*/
/*				:	(7)-4)-(iV)分散の算出									*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-4)-(ⅰ)方位範囲の算出								*/
/*				:	(7)-4)-(ⅱ)周波数範囲の算出								*/
/*				:	(7)-4)-(ⅲ)fast-SoTの判定								*/
/*				:	(7)-4)-(iV)分散の算出									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
FL calc_deviation_of_doa_freq_line_stationary_2(					/* [return] deviation of ovserved doa-freq points */
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] 130-145binのDOAピーク */
	S4 start_freq_bin,												/* [in]	start freq-bin */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 mode															/* [in] 0:I, 1:Q */
	,S4 *backward_priod												/* [out] use backward dev */
	,S4 v0_doa														/* [in] */
	,S4 *fast_sot_num												/* [out] */
	,S4 *not_fast_sot_num											/* [out] */
	,S4 fast_sot_limit_line[N_DOA]									/* [out] */
	,const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i;
	FL dev = 0.0F;
	S4 index = 0;
	S4 num = 0;
	S4 doa_min = 0;
	S4 doa_max = N_DOA;
	FL tmp_min = (FL)N_DOA;													/* PROC.3 */
	FL tmp_vsin;
	FL doa_stationary;
	S4 bin_min = 0;
	S4 bin_max = NB_FFT_PT_2F;
	S4 tmptmp_max;
	S4 tmptmp_min;

	S4 freq;
	FL v_limit;
	FL tmp = (FL)(NB_FFT_PT_2F / 2 - (S4)(CFL_SoT_V_TH_BWD / 3.6F / VCOF_2F));		/* PROC.1 */
	FL doa_limit; 
	FL diff1, diff2;

	S4 num_th = (S4)(SLOW_SOT_FREQ_BIN_RANGE*0.6F);							/* 60%で初期化 */
	*backward_priod = 0;

	if (fl_g_v_self_bsm_for_base == 0.0F) {																/* COND.j16 */
		dev = 999.9F;																					/* PROC.1 */
		return dev;
	}

	/* ■■■■■ (ⅰ)方位範囲の算出 ■■■■■ */
	tmp_min = (FL)N_DOA;																				/* PROC.3 */
	for (i = (S4)(((FL)N_DOA * 0.5F) - (FL)AXIS_DEFAULT); i < N_DOA; i++) {
		if (fl_abs((FL)(stationary_doa_line[i] - start_freq_bin)) < tmp_min) {							/* COND.g4 */
			tmp_min = fl_abs((FL)(stationary_doa_line[i]-start_freq_bin));								/* PROC.4 */
			doa_min = i;																				/* PROC.5 */
		}
	}
	tmp_min = (FL)N_DOA;																					/* PROC.3 */
	for (i = (S4)(((FL)N_DOA * 0.5F) - (FL)AXIS_DEFAULT); i < N_DOA; i++) {
		if (fl_abs((FL)(stationary_doa_line[i] - (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE))) < tmp_min) {	/* COND.g5 */
			tmp_min = fl_abs((FL)(stationary_doa_line[i]-(start_freq_bin+SLOW_SOT_FREQ_BIN_RANGE)));		/* PROC.6 */
			doa_max = i;																					/* PROC.7 */
		}
	}
	if (mode == 0) {
		doa_min -= 5;																					/* PROC.8' */
	} else {
		doa_min -= 10;																					/* PROC.8 */
	}

	if ((fl_g_v_self_bsm_for_base < 20.0F)																/* COND.g7 */
	&&  (mode == 1)) {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		doa_min = 65;																					/* PROC.10 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		doa_min = (S4)55;																				/* PROC.10 搭載角度20deg用の処理 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (doa_min < 0) {																					/* COND.g6 */
		doa_min = 0;																					/* PROC.9 */
	}

	doa_max += 10;																						/* PROC.11 */
	if (doa_max > N_DOA) {																				/* COND.g8 */
		doa_max = N_DOA;																				/* PROC.12 */
	}
	if (fl_g_v_self_bsm_for_base < 20.0F) {																/* COND.g7 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (doa_max > (N_DOA - AXIS_DEFAULT + 35)) {													/* COND.j2 */
			doa_max = N_DOA - AXIS_DEFAULT + 35;														/* PROC.13 */
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (doa_max > (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)65) {											/* COND.j2 搭載角度20deg用の条件 */
			doa_max = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)65;											/* PROC.13 搭載角度20deg用の処理 */
		}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}
	if (fl_g_v_self_bsm_for_base < 13.0F) {																/* COND.j1 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (doa_max > (N_DOA - AXIS_DEFAULT + 30)) {													/* COND.j3 */
			doa_max = N_DOA - AXIS_DEFAULT + 30;														/* PROC.14 */
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (doa_max > (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)60) {											/* COND.j3 搭載角度20deg用の条件 */
			doa_max = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)60;											/* PROC.14 搭載角度20deg用の処理 */
		}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	/* ■■■■■ (ⅱ) 周波数範囲の算出 ■■■■■ */
	for (i = (SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE + 1); i < (SLOW_SOT_FREQ_BIN_START_I + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		/* この関数はfl_g_v_self_bsm_for_baseが0のときはコールされないので0割はない */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;		/* PROC.1 */
		if( tmp_vsin > 1.0F)												/* COND.j4 */
		{
			tmp_vsin = 1.0F;												/* PROC.2 */
		}
		if( tmp_vsin < -1.0F)												/* COND.j5 */
		{
			tmp_vsin = -1.0F;												/* PROC.3 */
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI + (FL)v0_doa;		/* PROC.5 */
		if(doa_stationary > N_DOA )											/* COND.j6 */
		{
			doa_stationary = N_DOA;											/* PROC.6 */
			bin_max = i - 1;												/* PROC.7 */
			break;
		}
		if(doa_stationary < 0 )												/* COND.j7 */
		{
			doa_stationary = 0;												/* PROC.8 */
			bin_min = i + 1;												/* PROC.4 */
			break;
		}
	}
	if( bin_max < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE))				/* COND.j8 */
	{
		tmptmp_max = bin_max;												/* PROC.9 */
	}
	else
	{
		tmptmp_max = start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE - 1;			/* PROC.10 */
	}
	if( bin_min > start_freq_bin)											/* COND.j9 */
	{
		tmptmp_min = bin_min;												/* PROC.11 */
	}
	else
	{
		tmptmp_min = start_freq_bin;										/* PROC.12 */

	}
	num_th = (S4)( (FL)(tmptmp_max - tmptmp_min + 1)*0.6F );				/* PROC.13 60% of range */

	/* ■■■■■ (ⅲ)fast-SoTの判定 ■■■■■ */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memset(as4_g_fast_sot_limit_line_diam, 0, sizeof(as4_g_fast_sot_limit_line_diam));
#endif /*VI 表示用*/

	if ((mode == 1)
	&&  (fl_g_v_self_bsm_for_base >= 30.0F)) {															/* COND.j16 */
		if( fl_g_v_self_bsm_for_base < 35.0F ){															/* COND.j17 */
			v_limit = fl_g_v_self_bsm_for_base*0.8F;														/* PROC.2 */
		}else if( fl_g_v_self_bsm_for_base < 40.0F ){														/* COND.j18 */
			v_limit = fl_g_v_self_bsm_for_base*0.75F;														/* PROC.3 */
		}else if( fl_g_v_self_bsm_for_base < 45.0F ){														/* COND.j19 */
			v_limit = fl_g_v_self_bsm_for_base*0.7F;														/* PROC.4 */
		}else if( fl_g_v_self_bsm_for_base < 50.0F ){														/* COND.j20 */
			v_limit = fl_g_v_self_bsm_for_base*0.65F;														/* PROC.5 */
		}else if( fl_g_v_self_bsm_for_base < 55.0F ){														/* COND.j21 */
			v_limit = fl_g_v_self_bsm_for_base*0.6F;														/* PROC.6 */
		}else if( fl_g_v_self_bsm_for_base < 60.0F ){														/* COND.j22 */
			v_limit = fl_g_v_self_bsm_for_base*0.55F;														/* PROC.7 */
		}else if( fl_g_v_self_bsm_for_base < 65.0F ){														/* COND.j23 */
			v_limit = fl_g_v_self_bsm_for_base*0.5F;														/* PROC.8 */
		}else if( fl_g_v_self_bsm_for_base < 70.0F ){														/* COND.j24 */
			v_limit = fl_g_v_self_bsm_for_base*0.45F;														/* PROC.9 */
		}else{
			v_limit = fl_g_v_self_bsm_for_base*0.4F;														/* PROC.10 */
		}

		for(i = (start_freq_bin + 1); i <= (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {	/* i=112,113, ... ,126 [freq_bin] */
			tmp_vsin = (FL)(i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / v_limit;
			if (tmp_vsin > 1.0F) {
				tmp_vsin = 1.0F;
			}
			if (tmp_vsin < -1.0F) {
				tmp_vsin = -1.0F;
			}
			
			doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;														/* PROC.11 v0_doa = 140 */
			diff1 = doa_stationary - (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index];								/* PROC.12 */

			if (i <= (S4)tmp) {																											/* COND.j25 */
				if ((diff1 >= 0.0F)																										/* COND.j26 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - (i - start_freq_bin)][index] != -1)) {										/* COND.j27 */
					*fast_sot_num += 1;																									/* PROC.13 */
				}
			} else {
				tmp_vsin = (FL)(i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / CFL_SoT_V_TH_BWD;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_limit = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;														/* PROC.14 v0_doa = 140 */
				diff2 = (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] - doa_limit;								/* PROC.15 */
				if ((diff1 >= 0.0F)																										/* COND.j26 */
				&&  (diff2 >= 0.0F)																										/* COND.j28 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] != -1)) {											/* COND.j27 */
					*fast_sot_num += 1;																									/* PROC.13 */
				}

				if ((diff2 < 0.0F)																										/* COND.!j26 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] != -1)) {											/* COND.j27 */
					*not_fast_sot_num += 1;																								/* PROC.16 */
				}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if ((diff1 < (FL)-10.0F)																	/* COND.j31 */
				&&  (diff2 > (FL)30.0F)																		/* COND.j32 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - (i - start_freq_bin)][index] != (S4)-1)) {		/* COND.j27 */
					*not_fast_sot_num += 1;																	/* PROC.16 */
				}
#else
    マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

			}
		}

		for(i=0; i<N_DOA; i++)
		{
			freq = NB_FFT_PT_2F / 2 + (S4)((v_limit) / 3.6F * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa)) / VCOF_2F);				/* PROC.17 */
	
			if ((freq >= 0)																					/* COND.j29 */
			&&  (freq < NB_FFT_PT_2F)) {																	/* COND.j30 */
				fast_sot_limit_line[i] = freq;																/* PROC.18 */
			} else {
				fast_sot_limit_line[i] = 0;																	/* PROC.19 */
			}
		}
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
		memcpy(as4_g_fast_sot_limit_line_diam, fast_sot_limit_line, sizeof(S4)*N_DOA);
#endif /*VI 表示用*/
	}

	/* ■■■■■ (iV)分散の算出 ■■■■■ */
	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		index = 0;
		if (mode == 0) {
			if ((nearfield_doa[i][index] > doa_min)															/* COND.g9 */
			&&  (nearfield_doa[i][index] < doa_max)															/* COND.g10 */
			&&  (nearfield_doa[i][index] != -1)																/* COND.g12 */
			&&  ((start_freq_bin + i) >= bin_min)															/* COND.j10 */
			&&  ((start_freq_bin + i) <= bin_max)															/* COND.j11 */
			&&  (afl_a_sot_check_object[i][0] != CFL_UNKNOWN_VALUE)											/* COND.k19 */
			&&  (afl_a_sot_check_object[i][0] > (FL)0.0F)													/* COND.k20 */
			&&  (afl_a_sot_check_object[i][1] > (FL)-0.2F)) {												/* COND.k21 */
				/* この関数はfl_g_v_self_bsm_for_baseが0のときにはコールされないので0割はない */
				tmp_vsin = (FL)(start_freq_bin + i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.1' */
				tmp = doa_stationary - (FL)nearfield_doa[i][index];											/* PROC.1 */
				dev += tmp*tmp;																				/* PROC.3 */
				num++;																						/* PROC.4 */
			}
		} else {
			if ((nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] > doa_min)							/* COND.g13 */
			&& (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] < doa_max)							/* COND.g14 */
			&& (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] != -1)								/* COND.g15 */
			&& ((start_freq_bin + i + 1) >= bin_min)														/* COND.j10 */
			&& ((start_freq_bin + i + 1) <= bin_max)														/* COND.j11 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][0] != CFL_UNKNOWN_VALUE)			/* COND.k22 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][0] > (FL)0.0F)						/* COND.k23 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][1] < (FL)0.2F)) {					/* COND.k24 */
				/* この関数はfl_g_v_self_bsm_for_baseが0のときにはコールされないので0割はない */
				tmp_vsin = (FL)(start_freq_bin + i + (S4)1 - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.2' */
				tmp = doa_stationary - (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-i-1][index];				/* PROC.2 */
				dev += tmp*tmp;																				/* PROC.3 */
				num++;																						/* PROC.4 */
			}
		}

	}

	if (mode == 0) {
		if (fl_g_v_self_bsm_for_base < 20.0F) {																/* COND.j12 */
			num_th = num_th - 1;																			/* PROC.13 */
			if (num_th < 1) {																				/* COND.j13 */
				num_th = 1;																					/* PROC.14 */
			}
		} else {
			if (num != (S4)0) {
				if ((dev / (FL)num) > WALL_DEV_TH5) {														/* COND.j14 */
					return dev / (FL)num;																	/* PROC.11 */
				}
			} else {
				/* numが0のときは分散が算出されていないため不定値を示す値を入れる */
				dev = (FL)999.9F;
				*backward_priod = (S4)1;
				return dev;
			}
		}
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* 離脱側のみ実施 */
	if (mode == (S4)1) {
		if (fl_g_v_self_bsm_for_base < (FL)20.0F) {															/* COND.j12 */
			num_th = num_th - (S4)3;																		/* PROC.p500 */
			if (num_th < (S4)1) {																			/* COND.j13 */
				num_th = (S4)1;																				/* PROC.14 */
			}
		}
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_03 */

	if (num > num_th) {																						/* COND.j15 */
		dev = dev / (FL)num;																				/* PROC.8 */
	} else {
		dev = 999.9F;																						/* PROC.9 */
	}

	if ((mode == 0)
	&&  (dev == 999.9F)) {																					/* COND.g16 */
		*backward_priod = 1;																				/* PROC.10 */
	}

	return dev;
}


/****************************************************************************/
/* 関数名		: calc_line_doa_fm											*/
/*--------------------------------------------------------------------------*/
/* 機能			: 															*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
FL calc_line_doa_fm(
	const FL Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (fm) */
	FL power[NB_FFT_PT],								/* [in] power (fm) */
	S4 start_bin,										/* [in] */
	S4 end_bin,
	FL pow_th,											/* [in] */
	S4 line_doa[LINE_FREQ_BIN_RANGE][1],				/* [out] start_bin～start_bin+LINE_FREQ_BIN_RANGEbinのDOAピーク(最大1個/1bin) */
	S4 line_doa_peak_num[LINE_FREQ_BIN_RANGE],			/* [out] 上記各binのDOAピーク数(最大1個) */
	S4 updn												/* [in] direction of beat-signal */
)
{
	FL ave_pow_dbf = 0.0F;
	S4 ave_num_dbf = 0;
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[1];
	FL tmp_peak_power[1];
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			line_doa[i][j] = 0;
		}
		line_doa_peak_num[i] = 0;
	}

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		if ((start_bin + i) < end_bin) {
			/* DBF DOA */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(Ryy[start_bin+i]),
				spec_doa,
				updn,
				start_bin+i
			);
			/*DOA peaks */
			line_doa_peak_num[i] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);

			for(j=0; j<line_doa_peak_num[i]; j++ )
			{
				line_doa[i][j] = tmp_doa[j];
				ave_pow_dbf += tmp_peak_power[j];
				ave_num_dbf++;
			}
		}
		else
		{
			break;
		}
	}

	if(ave_num_dbf!=0)
	{
		ave_pow_dbf = ave_pow_dbf / (FL)ave_num_dbf;
	}

	return ave_pow_dbf;
}


/****************************************************************************/
/* 関数名		: set_freq_threshold_without_center_mask					*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-1)平均化スペクトラムの算出							*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-1)平均化スペクトラムの算出							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD set_freq_threshold_without_center_mask(
	const FL power[NB_FFT_PT],	/* [in] power of beat signal */
	FL thres[NB_FFT_PT]			/* [out] threshold for peak detection */
)
{
	S4 i, j;
	S4 ave_range = AVE_BIN_WIDTH;
	FL ave_power[NB_FFT_PT/AVE_BIN_WIDTH];
	FL clearance = AVE_POW_CLEARANCE;

	S4 loop_max;
	loop_max = NB_FFT_PT / ave_range;

	/* AVE_BIN_WIDTH freq-bin毎の平均電力 */
	for(i=0; i<loop_max; i++)
	{
		ave_power[i] = 0.0F;
		for( j=0; j<ave_range; j++ )
		{
			ave_power[i] = ave_power[i] + power[i*ave_range+j];
		}
		ave_power[i] = ave_power[i] / (FL)ave_range;

		if(ave_power[i]<PEAK_POW_TH_MIN)		/* COND.b1 */
		{
			ave_power[i] = PEAK_POW_TH_MIN;
		}

		for( j=0; j<ave_range; j++ )
		{
			thres[i*ave_range+j] = ave_power[i] + clearance;
		}
	}
}


/****************************************************************************/
/* 関数名		: set_wall_freq_threshold									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-2) ベース電力の算出									*/
/*				:	周波数スペクトラムの周波数binが小さい範囲の平均化スペク	*/
/*				:	トラムの平均値をベース電力として算出する。ただし、この	*/
/*				:	区間にピークが発生する場合を考慮して、一定量以上の外れ値*/
/*				:	は除外する．											*/
/*				: (2)-3) 接近判定用特徴量の算出								*/
/*				:	物標が接近しているか否の判定は、平均化スペクトラムの形状*/
/*				:	の特徴量を用いて行う。特徴量には、所定の範囲内で平均化	*/
/*				:	スペクトラムが一定以上変化した変化点の情報を用いる。	*/
/*				:	変化点は最大3点まで求める。								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-2) ベース電力の算出									*/
/*				:	(2)-3) 接近判定用特徴量の算出							*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 set_wall_freq_threshold(					/* [return](not used) number of steps */
	const FL thres[NB_FFT_PT],				/* [in] threshold for peak detection */
	FL wall_thres[NB_FFT_PT],				/* [out] threshold for peak detection */
	S4 wall_check[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 wall_bin[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	FL wall_pow[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 freq_start,							/* [in] */
	S4 freq_end								/* [in] */
)
{
	S4 iret = 0;
	S4 i, j;
	FL base_pow = 0.0F;
	FL tmp_pow = 0.0F;
	S4 tmp_count = 0;
	S4 tmp_wall_check[WALL_FREQ_BIN_TH_STEPS];
	S4 index[WALL_FREQ_BIN_TH_STEPS+1];
	FL pow[WALL_FREQ_BIN_TH_STEPS+1];
	S4 count[WALL_FREQ_BIN_TH_STEPS];
	S4 tmp_ret = 1;
	U1 u1_t_lp_freq_bin_th_steps;

	/* ローカル変数初期化 */
	for (u1_t_lp_freq_bin_th_steps = (U1)0; u1_t_lp_freq_bin_th_steps < (U1)WALL_FREQ_BIN_TH_STEPS; u1_t_lp_freq_bin_th_steps++) {
		tmp_wall_check[u1_t_lp_freq_bin_th_steps] = (S4)0;
		count[u1_t_lp_freq_bin_th_steps] = (S4)0;
	}

	for (u1_t_lp_freq_bin_th_steps = (U1)0; u1_t_lp_freq_bin_th_steps < ((U1)WALL_FREQ_BIN_TH_STEPS + (U1)1); u1_t_lp_freq_bin_th_steps++) {
		index[u1_t_lp_freq_bin_th_steps] = (S4)0;
		pow[u1_t_lp_freq_bin_th_steps] = (FL)0.0F;
	}

	/***** 2) ベース電力の算出 *****/
	base_pow = thres[BASE_FREQ_BIN_LOWER_LIMIT];
	tmp_count = 1;
	for(i=BASE_FREQ_BIN_LOWER_LIMIT; i<BASE_FREQ_BIN_UPPER_LIMIT; i++)
	{
		tmp_pow = thres[i+1] - base_pow;
		if( fl_abs(tmp_pow) < BASE_FREQ_POW_RANGE)			/* COND.b2 */
		{
			tmp_count++;
			base_pow += tmp_pow / (FL)tmp_count;
		}
	}

	/***** 3) 接近判定用特徴量の算出 *****/
	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		pow[i] = base_pow;						/* PROC.1 */
	}
	index[0] = freq_start;						/* PROC.2 */
	index[WALL_FREQ_BIN_TH_STEPS] = freq_end;	/* PROC.3 */
	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		if(tmp_ret!=0)							/* COND.b3 */
		{
			tmp_ret = seek_freq_step(
				(const FL *)thres,		/* [in] */
				freq_end,				/* [in] */
				WALL_FREQ_POW_RANGE,	/* [in] */
				&pow[i],				/* [in/out] */
				&index[i],				/* [out] */
				&count[i],				/* [out] */
				&index[i+1]				/* [out] (available when return value is 1) */
			);
			pow[i+1] = pow[i];					/* PROC.13 */
			if(count[i]!=0)						/* COND.b7 */
			{
				iret++;							/* PROC.14 */
			}
		}
		else
		{
			break;
		}
	}

	for(i=0; i<NB_FFT_PT; i++)
	{
		wall_thres[i] = base_pow;					/* PROC.15 */
	}
	for(j=0; j<iret; j++)
	{
		if (count[j] >= (0.5 * (index[j+1]-index[j]))) {	/* COND.b8 */
			for(i=index[j]; i<NB_FFT_PT; i++)
			{
				wall_thres[i] = pow[j];				/* PROC.16 */
				tmp_wall_check[j] = 1;				/* PROC.17 */
			}
		}
		else
		{
			tmp_wall_check[j] = 0;					/* PROC.18 */
		}
	}

	for(i=freq_end; i<NB_FFT_PT; i++)
	{
		wall_thres[i] = base_pow;					/* PROC.15 */
	}

	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		wall_check[i] = tmp_wall_check[i];
		wall_bin[i] = index[i];
		wall_pow[i] = pow[i];
	}
	return iret;
}


 /****************************************************************************/
/* 関数名		: seek_freq_step											*/
/*--------------------------------------------------------------------------*/
/* 機能			: seek freq-power for stepped-threshold for leading vehicle */
/*				:	estimation												*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-3)条件b3成立時（変更点あり）						*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 seek_freq_step(				/* [return] 0:no more step, 1:have next step */
	const FL thres[NB_FFT_PT],	/* [in] threshold for peak detection */
	S4 end_index,				/* [in] end point of freq-bin */
	FL pow_range,				/* [in] range of freq-power to treat as the same step  */
	FL pow[1],					/* [in/out] freq-pow of this step */
	S4 index[1],				/* [in/out] start point of this step */
	S4 count[1],				/* [out] number of freq-bin of this step  */
	S4 next_index[1]			/* [out] end point of this step(start point of next step) */
)
{
	S4 iret = 0;

	S4 i;
	FL tmp_pow_diff = 0.0F;
	S4 start_index = index[0];
	S4 tmp_next_index = next_index[0];
	S4 tmp_index = index[0];
	S4 tmp_count = count[0];
	FL tmp_pow = pow[0];							/* PROC.4 */

	/* 変化ポイント（上昇 or 下降ポイント） */
	for(i=start_index; i<end_index; i++)
	{
		tmp_pow_diff = thres[i] - tmp_pow;			/* PROC.5 */
		/*    __    */
		/* __|      */
		if( tmp_pow_diff > WALL_POW_TH )			/* COND.b4 */
		{
			tmp_pow = thres[i];						/* PROC.6 */
			tmp_index = i;							/* PROC.7 */
			break;
		}
		/* __      */
		/*   |__   */
		else if( tmp_pow_diff < -WALL_POW_TH )		/* COND.b5 */
		{
			tmp_pow = thres[i];						/* PROC.6 */
			tmp_index = i;							/* PROC.7 */
			break;
		} else {
			/* 何もしない */
		}
	}

	for(i=tmp_index; i<end_index; i++)
	{
		tmp_pow_diff = thres[i] - tmp_pow;				/* PROC.5 */
		/* ______  */
		/*         */
		if( fl_abs(tmp_pow_diff) < pow_range )			/* COND.b6 */
		{
			tmp_count++;								/* PROC.8 */
			tmp_pow += tmp_pow_diff / (FL)tmp_count;	/* PROC.9 */
		}
		else
		{
			/*    __  */
			/* __|    */
			if(tmp_pow_diff > WALL_POW_TH)			/* COND.b4 */
			{
				iret = 1;							/* PROC.10 */
				tmp_next_index = i+1;				/* PROC.12 */
				break;
			}
			/* __     */
			/*   |__  */
			else
			{
				iret = -1;							/* PROC.11 */
				tmp_next_index = i+1;				/* PROC.12 */
				break;
			}
		}
	}

	pow[0] = tmp_pow;
	index[0] = tmp_index; 
	count[0] = tmp_count;
	next_index[0] = tmp_next_index;

	return iret;
}


/****************************************************************************/
/* 関数名		: peak_search_music_fsk_all_doa								*/
/*--------------------------------------------------------------------------*/
/* 機能			: 															*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
S4 peak_search_music_fsk_all_doa(
	const FL music_spec[N_DOA_2F],		/* [in] */
	S4 bin_music[2],					/* [out] */
	FL power_music[2],					/* [out] */
	S4 wave_num_in						/* [in] */
)
{
	S4 i,j;
	S4 tmp_bin_music[4];
	FL tmp_power_music[4];
	S4 peak_num_music = 0;
	S4 tmp_int;
	FL tmp_float;
	S4 wave_num = wave_num_in;
	U1 u1_t_lp_peak_num;

	/* ローカル変数初期化 */
	for (u1_t_lp_peak_num = (U1)0; u1_t_lp_peak_num < (U1)4; u1_t_lp_peak_num++) {
		tmp_bin_music[u1_t_lp_peak_num] = (S4)0;
		tmp_power_music[u1_t_lp_peak_num] = (FL)0.0F;
	}

	/*********** music_spec_peak_search ***************/
	j = 0;
	for( i=0; i<N_DOA; i++ )
	{
		if ((music_spec[i] < music_spec[i+1])
		&&  (music_spec[i+1] > music_spec[i+2])
		&&  (j < 4)) {
			if (music_spec[i+1] > 5) {
				tmp_bin_music[j] = i + 1;
				tmp_power_music[j] = music_spec[i+1];
				j++;
			}
		}
	}
	peak_num_music = j;

	/***********ピークがより多かった場合の処理*****************/
	if ( wave_num >= peak_num_music )
	{
		wave_num = peak_num_music;
		for ( i = 0; i < wave_num; i++ )
		{
			bin_music[i] = tmp_bin_music[i];
			power_music[i] = tmp_power_music[i];
		}
	}
	else
	{
		/***********電力順にならべかえ*****************/
		for ( i = 0; i < peak_num_music; i++ )
		{
			for ( j = i+1; j < peak_num_music; j++ )
			{
				if ( tmp_power_music[i] < tmp_power_music[j] )
				{
					tmp_float = tmp_power_music[i];
					tmp_power_music[i] = tmp_power_music[j];
					tmp_power_music[j] = tmp_float;

					tmp_int = tmp_bin_music[i];
					tmp_bin_music[i] = tmp_bin_music[j];
					tmp_bin_music[j] = tmp_int;
				}
			}
		}

		for ( i = 0; i < wave_num; i++ )
		{
			bin_music[i] = tmp_bin_music[i];
			power_music[i] = tmp_power_music[i];
		}
	}

	/***********bin順にならべかえ*****************/
	for ( i = 0; i < wave_num; i++ )
	{
		for ( j = i+1; j < wave_num; j++ )
		{
			if ( bin_music[i] > bin_music[j] )
			{
				tmp_int = bin_music[i];
				bin_music[i] = bin_music[j];
				bin_music[j] = tmp_int;

				tmp_float = power_music[i];
				power_music[i] = power_music[j];
				power_music[j] = tmp_float;
			}
		}
	}

	return wave_num;
}



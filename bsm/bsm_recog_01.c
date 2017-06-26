/****************************************************************************/
/* ファイル名	: BSM_RECOG_01.c											*/
/*--------------------------------------------------------------------------*/
/* モジュール名	:															*/
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
/*	BSM AS巻替 インデント修正 //コメント変更(OBJ変更なし)					*/
/*	t06					15.03.23			走安技2 1技室 G.Jomori			*/
/*	仕様確認No984対応														*/
/*	t07					15.05.25			走安技2 1技室 G.Jomori			*/
/*	残課題No487～489対応													*/
/*	t08					15.06.02			走安技2 1技室 G.Jomori			*/
/*	残課題No436対応															*/
/*	t11					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t12					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(コードクロスで良い分)									*/
/*	t13					15.08.31			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1503対応														*/
/*	t14					15.10.27			走安技2 1技室 Y.Nishioka		*/
/*	関数ヘッダの追加 ※OBJ変更なし											*/
/*	t15					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t16					16.03.03			走安技2 1技室 G.Jomori			*/
/*	残課題No1198対応(ローカル配列変数の宣言と同時に実施の初期化分離)		*/
/*	t17					16.03.29			走安技2 1技室 G.Jomori			*/
/*	残課題No1124対応(条件文修正)											*/
/*	t18					16.03.29			走安技2 1技室 G.Jomori			*/
/*	291B BSM CV仕様 読み合わせ指摘事項対応(OBJ変更なし)						*/
/*	t19					16.04.07			走安技2 1技室 Y.Yamada			*/
/*	処理負荷計測用変数の初期化処理追加										*/
/*	t20					16.04.12			走安技2 1技室 K.Hanabata		*/
/*	QAC指摘修正																*/
/*	t21					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t22					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t23					16.06.20			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t24					16.06.21			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	t25					16.06.22			走安技2 1技室 G.Jomori			*/
/*	BSM QAC指摘事項修正 OBJ変更なし											*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t32					16.07.18			走安技2 1技室 G.Jomori			*/
/*	291B開発用ソフトに010Bソフトをマージ(010B 1Aをベースに0024_t822マージ)	*/
/*	t37					16.08.10			走安技2 1技室 Y.Nishioka		*/
/*	関数名変更(shareMUSIC_を追加) ※オブジェクト変更なし					*/
/*	t40					16.08.22			走安技2 1技室 G.Jomori			*/
/*	残課題No1411,1412,1413対応(S4,FL,VDに変更 OBJ変更なし)					*/
/*	t42					16.09.15			走安技2 1技室 G.Jomori			*/
/*	010B 2A 認識部分(BSM,RCTA,AUDR)マージ									*/
/*	t43					16.09.23			走安技2 1技室 G.Jomori			*/
/*	291B CV-R仕様対応														*/
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
#include "../../common/cmn_shareMUSIC_mwr.h"

#include "bsm_recog_01.h"

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
VD fn_bsm_prior_init_data(
	S4 *ps4_a_peak_num_prior,
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],
	FL afl_a_peak_powers[PRIOR_RANGE][2],
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]
);

VD fn_bsm_prior_set_peak(
	S4  s4_a_focus_bin,											/* [in] focus bin */
	FL fl_a_Ayfil,												/* [in] fl_a_Ayfil  */
	U2 u2_a_flg_undn,											/* [in] up/dn_flg	*/
	S4 *ps4_a_start_bin											/* [out] start_bin */
);

VD fn_bsm_prior_estimate_doa(
	S4 s4_a_flg_updn,												/* [in] s4_a_flg_updn */
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],								/* [in] power */

	S4 s4_a_start_bin,												/* [in] focus bin */
	FL fl_a_focus_power,											/* [in] focus afl_a_power */
	FL fl_a_focus_doa_bin_intpl,									/* [in] focus doa */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],						/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],							/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]						/* [out] peak doa afl_a_power */
);

static VD fn_bsm_prior_estimate_doa_around_dc(
	S4 s4_a_flg_updn,												/* [in] s4_a_flg_updn */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],					/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],								/* [in] raw data */

	S4 s4_a_focus_bin,												/* [in] */
	S4 s4_a_bin_pred,												/* [in] */
	FL fl_a_bin_interpolate_pred,									/* [in] */
	FL fl_a_doa_interpolate_pred,									/* [in] */
	FL fl_a_power_music,											/* [in] */
	S4 s4_a_bin_music_pred,											/* [in] */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],						/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],							/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]						/* [out] peak doa afl_a_power */
);

VD fn_bsm_prior_cal_doa(
	S4 s4_a_flg_updn,											/* [in] s4_a_flg_updn */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],				/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],							/* [in] raw data */

	S4 s4_a_focus_bin,											/* [in] */
	FL fl_a_focus_power,										/* [in] focus afl_a_power */
	FL fl_a_focus_doa_bin_intpl,								/* [in] focus doa */
	S4 *ps4_a_doa_diff,											/* [in] doa diff */

	S4 *ps4_a_doa_num,											/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],						/* [out] */
	FL afl_a_selected_doa_powers[2],							/* [out] */
	FL afl_a_selected_bins_intpl[2]								/* [out] */
);

VD fn_bsm_prior_store_doa(
	const FL afl_a_focus_power[PRIOR_RANGE],					/* [in] power */

	const S4 as4_a_doa_num[PRIOR_RANGE],
	const FL afl_a_selected_doa_bins_intpl[PRIOR_RANGE][2],		/* [in]  */
	const FL afl_a_selected_doa_powers[PRIOR_RANGE][2],			/* [in]  */
	const FL afl_a_selected_bins_intpl[PRIOR_RANGE][2],			/* [in]  */

	S4 *ps4_a_doa_peak_num,										/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],				/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]					/* [out] peak doa afl_a_power */
);

U1 u1_bsm_prior_make_pair(
	FL fl_a_focus_doa_bin_intpl_up,									/* [in] focus doa */
	FL fl_a_focus_doa_bin_intpl_dn,									/* [in] focus doa */
	FL fl_a_power_up_music,										/* [in] */
	FL fl_a_power_dn_music,										/* [in] */

	S4 s4_a_peak_num_prior_up,									/* [in] */
	FL afl_a_peak_bins_intpl_up[PRIOR_RANGE][2],				/* [in] peak doa bin */
	FL afl_a_peak_powers_up[PRIOR_RANGE][2],					/* [in] peak doa afl_a_power */
	FL afl_a_peak_doa_bins_intpl_up[PRIOR_RANGE][2],			/* [in] peak doa bin */
	FL afl_a_peak_doa_powers_up[PRIOR_RANGE][2],				/* [in] peak doa afl_a_power */

	S4 s4_a_peak_num_prior_dn,									/* [in] */
	FL afl_a_peak_bins_intpl_dn[PRIOR_RANGE][2],				/* [in] peak doa bin */
	FL afl_a_peak_powers_dn[PRIOR_RANGE][2],					/* [in] peak doa afl_a_power */
	FL afl_a_peak_doa_bins_intpl_dn[PRIOR_RANGE][2],			/* [in] peak doa bin */
	FL afl_a_peak_doa_powers_dn[PRIOR_RANGE][2],				/* [in] peak doa afl_a_power */

	S4 s4_a_normal_prior_num,
	NORMAL_BSM *pst_a_normal_prior								/* [in / out] */
);

static U1 u1_bsm_prior_make_pair_a2(FL fl_a_peak_doa_bins_intpl, FL fl_a_focus_doa_bin_intpl, FL fl_a_doa_diff_predict);
static U1 u1_bsm_prior_make_pair_a6(FL fl_a_peak_doa_powers_up, FL fl_a_power_up_music);
static U1 u1_bsm_prior_make_pair_a7(FL fl_a_peak_doa_powers_dn, FL fl_a_power_dn_music);
static U1 u1_bsm_prior_make_pair_a8(FL fl_a_peak_bins_intpl_up, FL fl_a_peak_bins_intpl_dn);

VD fn_bsm_prior_delete_same_object(
	const S4 as4_a_prev_index[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal[PRIOR_BUFFSIZE],
	const NORMAL_BSM ast_a_ast_normal_copy[NORMAL_BUFFSIZE]
);

VD fn_bsm_prior_set_object(
	S4 *ps4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],				/* [out] S4 values of NORMAL_BSM structure */

	S4 s4_a_buf_normal_num,
	const NORMAL_BSM ast_a_buf_normal[PRIOR_BUFFSIZE]
);


/****************************************************************************/
/* 関数名		: fn_bsm_seek_prior_object									*/
/*--------------------------------------------------------------------------*/
/* 機能			: 優先物標認識処理											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (1)優先ピークサーチ処理 ～ (5)出力データ保存				*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_seek_prior_object(
	/***** OUTPUT (OBJECT) *****/
	S4		   *ps4_a_pair_num_prior,							/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_normal_num;
	NORMAL_BSM ast_t_normal[PRIOR_BUFFSIZE];
	NORMAL_BSM st_t_buf_normal;
	NORMAL_BSM ast_t_ast_normal_copy[NORMAL_BUFFSIZE];

	S4 s4_t_lp_i;

	S4 s4_t_start_bin;

	S4 as4_t_prev_index[PRIOR_BUFFSIZE];
	
	S4 s4_t_peak_num_prior_up = 0;
	FL afl_t_peak_bins_intpl_up[PRIOR_RANGE][2];
	FL afl_t_peak_powers_up[PRIOR_RANGE][2];
	FL afl_t_peak_doa_bins_intpl_up[PRIOR_RANGE][2];
	FL afl_t_peak_doa_powers_up[PRIOR_RANGE][2];

	S4 s4_t_peak_num_prior_dn = 0;
	FL afl_t_peak_bins_intpl_dn[PRIOR_RANGE][2];
	FL afl_t_peak_powers_dn[PRIOR_RANGE][2];
	FL afl_t_peak_doa_bins_intpl_dn[PRIOR_RANGE][2];
	FL afl_t_peak_doa_powers_dn[PRIOR_RANGE][2];

	U1 u1_make_pair_result;

	U1 u1_t_up_peak_num_of_search;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */
	U1 u1_t_dn_peak_num_of_search;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */
	
	S4 s4_t_lower_limit_th;

	U1 u1_t_flg_near_target_exist;		/* 近距離にターゲット物標存在フラグ */
	S4 s4_t_lp_target_num;				/* ターゲット物標のforループ変数 */

	fn_init(ast_t_normal, PRIOR_BUFFSIZE);

	/* 物標情報を並び替えるため、コピー用変数に退避 */
	for (s4_t_lp_i = (S4)0; s4_t_lp_i < (S4)NORMAL_BUFFSIZE; s4_t_lp_i++) {
		ast_t_ast_normal_copy[s4_t_lp_i] = st_g_bsm_loop_data.ast_normal[s4_t_lp_i];
	}

	fn_sort_normal_by_power(ast_t_ast_normal_copy);

	*ps4_a_pair_num_prior = 0;

#if (MODE_ECU_SIM == ECU_MODE)
	/* 処理時間計測用。実際にmusicを掛けた基本ピークの数の初期化 */
	u1_g_bsm_prior_music_up_peak_num = (U1)0;		/* CheckPoint BSM_優先物標探索基準ピーク数up */
	u1_g_bsm_prior_music_dn_peak_num = (U1)0;		/* CheckPoint BSM_優先物標探索基準ピーク数dn */
#endif /* MODE_ECU_SIM */

	
/****************************************************************************/
/* (1)  優先ピークサーチ処理                                               */
/****************************************************************************/
	/***** (1) 2) 優先ピークサーチ作動条件の確認 *****/
	if (
	   (fl_abs(fl_g_v_self_bsm_for_base) < CFL_CANOUT_VSELF_MIN)									/* COND. a1 */
	|| (s4_abs(s2_g_curvr_for_base) < CANOUT_CURVER_MIN)								/* COND. a2 */
	) {
		fn_init(ast_a_normal_prior,  PRIOR_BUFFSIZE);
		return;
	}

	u1_t_up_peak_num_of_search = 0;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */
	u1_t_dn_peak_num_of_search = 0;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */

	/* 前回 cycle のターゲット物標が自車周辺に存在するかをチェックする */
	/* 存在しない場合は、警報エリア内の優先物標作成を制限する */
	u1_t_flg_near_target_exist = (U1)0;
	for (s4_t_lp_target_num = (S4)0; s4_t_lp_target_num < st_g_bsm_loop_data.as4_buf_pair_num[1]; s4_t_lp_target_num++) {
		if (st_g_bsm_loop_data.ast_target[s4_t_lp_target_num].fl_Ryfil > (FL)-15.0F) {		/* COND.a3 */
			u1_t_flg_near_target_exist = (U1)1;
			break;
		}
	}

	s4_t_normal_num = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < st_g_bsm_loop_data.as4_buf_pair_num[0]; s4_t_lp_i++) {
		if (s4_t_lp_i >= PRIOR_BUFFSIZE) {												/* COND.b1 */
			break;
		}
		
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
		if ((u1_t_flg_near_target_exist == (U1)0)																/* COND.b9 */
		&&  (st_g_bsm_loop_data.s4_flg_alarm == (S4)0)															/* COND.b10 */
		&&  ((CFL_ALARM_Y_BACKWARD - (FL)ALARM_Y_OFFSET) < ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred)			/* COND.b11 */
		&&  (ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred  < (FL)-EKF_RY_SIDE))									/* COND.b11 */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
		if ((u1_t_flg_near_target_exist == (U1)0)																/* COND.b9 */
		&&  (st_g_bsm_loop_data.s4_flg_alarm == (S4)0)															/* COND.b10 */
		&&  ((CFL_ALARM_Y_BACKWARD - (FL)ALARM_Y_OFFSET) < ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred)			/* COND.b11 */
		&&  (ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred  < (FL)-EKF_RY_SIDE)									/* COND.b11 */
		&&  (st_g_bsm_loop_data.as4_low_speed_flg[0] == (S4)0))													/* COND.b12 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */
		{
			/* 条件成立時はi番目の物標で以降の処理を実施しない（i+1番目の処理へ）*/
		} else {
			s4_t_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR;

			if ((ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred < FREQ_EXPAND_R_TH)
			&&  (ast_t_ast_normal_copy[s4_t_lp_i].fl_Vypred > FREQ_EXPAND_V_TH)) {
				s4_t_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR_EX;
			}
			
			/***** (1) 3) 前回の物標情報の確認 *****/
			if (
				(ast_t_ast_normal_copy[s4_t_lp_i].s4_flg_track > PRIOR_TRK_NUM)		/* COND b2 接続回数一定回以上を優先扱い */
			 || (ast_t_ast_normal_copy[s4_t_lp_i].s4_flg_dc == OBJECT_TYPE_PRIOR)	/* COND b3 前回優先扱い */
			) {

				/* UP */
				s4_t_peak_num_prior_up = 0;
				if (ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred > FREQ_BIN_LOWER_LIMIT) {	/* COND. b4 */

					u1_t_up_peak_num_of_search++;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */

					fn_bsm_prior_init_data(
						&s4_t_peak_num_prior_up,
						afl_t_peak_bins_intpl_up,
						afl_t_peak_powers_up,
						afl_t_peak_doa_bins_intpl_up,
						afl_t_peak_doa_powers_up
					);

					/***** (1) 4) 周波数binの探索範囲の設定 *****/
					fn_bsm_prior_set_peak(
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_Ayfil,
						CU2_LFM_MOD_UP,
						&s4_t_start_bin
					);

					/***** (2) 1) 方位推定処理済みピークの確認 *****/
					/***** (2) 2) MUSICによる角度スペクトラムの算出 *****/
					/***** (2) 3) MUSIC角度スペクトラムのピークサーチ *****/
					/***** (2) 4) BF (Beam forming) による角度スペクトラムの算出（電力推定）*****/
					/***** (2) 6) 路面反射の除外*****/
					/***** (2) 7) 角度ピーク補間 *****/
					/***** (2) 8) 方位推定結果の格納 *****/
					fn_bsm_prior_estimate_doa(
						0,																/* [in] */
						afl_g_cvw_lfm_ryy_matrix[0],
						(const FL *)(afl_g_cvw_lfm_ftt_power[0]),

						s4_t_start_bin,														/* [in] */
						ast_t_ast_normal_copy[s4_t_lp_i].fl_power_up,				/* [in] */
						ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_up_interpolate_pred,/* [in] */

						&s4_t_peak_num_prior_up,											/* [out] */
						afl_t_peak_bins_intpl_up,											/* [out] */
						afl_t_peak_powers_up,												/* [out] */
						afl_t_peak_doa_bins_intpl_up,										/* [out] */
						afl_t_peak_doa_powers_up											/* [out] */
					);
				} else if(ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred > s4_t_lower_limit_th) {									/* COND.b5 */
					u1_t_up_peak_num_of_search++;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */

					fn_bsm_prior_estimate_doa_around_dc(
						0,																/* [in] */
						(const FL (*)[CORRE_SIZE_4CH])afl_g_cvw_lfm_ryy_matrix[0],
						(const FL *)afl_g_cvw_lfm_ftt_power[0],

						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_bin_up_interpolate_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_dn_interpolate_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_power_dn_music,
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_music_pred,


						&s4_t_peak_num_prior_up,											/* [out] */
						afl_t_peak_bins_intpl_up,											/* [out] */
						afl_t_peak_powers_up,												/* [out] */
						afl_t_peak_doa_bins_intpl_up,										/* [out] */
						afl_t_peak_doa_powers_up											/* [out] */
					);
				} else {
					/* 何もしない */
				}

				/* DOWN */
				s4_t_peak_num_prior_dn = 0;
				if (ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred > FREQ_BIN_LOWER_LIMIT) {		/* COND. b4' */

					u1_t_dn_peak_num_of_search++;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */

					fn_bsm_prior_init_data(
						&s4_t_peak_num_prior_dn,
						afl_t_peak_bins_intpl_dn,
						afl_t_peak_powers_dn,
						afl_t_peak_doa_bins_intpl_dn,
						afl_t_peak_doa_powers_dn
					);

					/* (1)優先ピークサーチ処理 - DN */
					fn_bsm_prior_set_peak(
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_Ayfil,
						CU2_LFM_MOD_DN,
						&s4_t_start_bin
					);

					/* (2) 方向推定処理 - DN */
					fn_bsm_prior_estimate_doa(
						1,																	/* [in] */
						afl_g_cvw_lfm_ryy_matrix[1],
						(const FL *)(afl_g_cvw_lfm_ftt_power[1]),

						s4_t_start_bin,														/* [in] */
						ast_t_ast_normal_copy[s4_t_lp_i].fl_power_dn,				/* [in] */
						ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_dn_interpolate_pred,/* [in] */

						&s4_t_peak_num_prior_dn,											/* [out] */
						afl_t_peak_bins_intpl_dn,											/* [out] */
						afl_t_peak_powers_dn,												/* [out] */
						afl_t_peak_doa_bins_intpl_dn,										/* [out] */
						afl_t_peak_doa_powers_dn											/* [out] */
					);
				}
				else if(ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred > s4_t_lower_limit_th ) {							/* COND.b5' */
					u1_t_dn_peak_num_of_search++;		/* 処理時間計測用。実際にmusicを掛けた基本ピークの数 */

					fn_bsm_prior_estimate_doa_around_dc(
						1,																	/* [in] */
						(const FL (*)[CORRE_SIZE_4CH])afl_g_cvw_lfm_ryy_matrix[1],
						(const FL *)afl_g_cvw_lfm_ftt_power[1],

						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_bin_dn_interpolate_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_up_interpolate_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_power_up_music,
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_music_pred,


						&s4_t_peak_num_prior_dn,											/* [out] */
						afl_t_peak_bins_intpl_dn,											/* [out] */
						afl_t_peak_powers_dn,												/* [out] */
						afl_t_peak_doa_bins_intpl_dn,										/* [out] */
						afl_t_peak_doa_powers_dn											/* [out] */
					);
				} else {
					/* 何もしない */
				}

				fn_init(&st_t_buf_normal, 1);

				/* (6), (7) ペアマッチ */
				u1_make_pair_result = u1_bsm_prior_make_pair(
					ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_up_interpolate_pred,	/* [in] */
					ast_t_ast_normal_copy[s4_t_lp_i].fl_doa_dn_interpolate_pred,	/* [in] */
					ast_t_ast_normal_copy[s4_t_lp_i].fl_power_up_music,				/* [in] */
					ast_t_ast_normal_copy[s4_t_lp_i].fl_power_dn_music,				/* [in] */
					
					s4_t_peak_num_prior_up,											/* [in] */
					afl_t_peak_bins_intpl_up,										/* [in] */
					afl_t_peak_powers_up,											/* [in] */
					afl_t_peak_doa_bins_intpl_up,									/* [in] */
					afl_t_peak_doa_powers_up,										/* [in] */

					s4_t_peak_num_prior_dn,											/* [in] */
					afl_t_peak_bins_intpl_dn,										/* [in] */
					afl_t_peak_powers_dn,											/* [in] */
					afl_t_peak_doa_bins_intpl_dn,									/* [in] */
					afl_t_peak_doa_powers_dn,										/* [in] */

					s4_t_normal_num,
					&st_t_buf_normal
				);

				if( u1_make_pair_result == CU1_TRUE ) {
					ast_t_normal[s4_t_normal_num] = st_t_buf_normal;
					as4_t_prev_index[s4_t_normal_num] = s4_t_lp_i;					/* PROC.1 */
					s4_t_normal_num++;												/* PROC.2 */
				}
			}
		}		/* 50deg:条件b9 & b10 & b11のEND部 */
				/* 20deg:条件b9 & b10 & b11 & b12のEND部 */
	}

#if (MODE_ECU_SIM == ECU_MODE)
	/* 処理時間計測用。実際にmusicを掛けた基本ピークの数を保存 */
	u1_g_bsm_prior_music_up_peak_num = u1_t_up_peak_num_of_search;		/* CheckPoint BSM_優先物標探索基準ピーク数up */
	u1_g_bsm_prior_music_dn_peak_num = u1_t_dn_peak_num_of_search;		/* CheckPoint BSM_優先物標探索基準ピーク数dn */
#endif /* MODE_ECU_SIM */

	
	/***** (3) 4) 同一物標情報の削除*****/
	fn_bsm_prior_delete_same_object(
		(const S4 *)as4_t_prev_index,
		s4_t_normal_num,
		ast_t_normal,
		(const NORMAL_BSM *)ast_t_ast_normal_copy
	);

/****************************************************************************/
/* (5)   出力データ保存                                                     */
/****************************************************************************/
	fn_bsm_prior_set_object(
		ps4_a_pair_num_prior,
		ast_a_normal_prior,

		s4_t_normal_num,
		(const NORMAL_BSM *)ast_t_normal
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_init_data									*/
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
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (1) 3)前回の物標情報の確認								*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_init_data(
	S4 *ps4_a_peak_num_prior,
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],
	FL afl_a_peak_powers[PRIOR_RANGE][2],
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	
	*ps4_a_peak_num_prior = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < (S4)PRIOR_RANGE; s4_t_lp_i++ ) {
		for(s4_t_lp_j = 0; s4_t_lp_j < (S4)2; s4_t_lp_j++ ) {
			afl_a_peak_bins_intpl[s4_t_lp_i][s4_t_lp_j]		= 0.0F;
			afl_a_peak_powers[s4_t_lp_i][s4_t_lp_j]			= 0.0F;
			afl_a_peak_doa_bins_intpl[s4_t_lp_i][s4_t_lp_j]	= 0.0F;
			afl_a_peak_doa_powers[s4_t_lp_i][s4_t_lp_j]		= 0.0F;
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_set_peak										*/
/*--------------------------------------------------------------------------*/
/* 機能			:  (1) 4) 周波数binの探索範囲の設定 						*/
/*				:	予測binの周辺PRIOR_RANGE bin分の周波数binを調べるための	*/
/*				:	範囲の設定												*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_set_peak(
	S4  s4_a_focus_bin,											/* [in] focus bin */
	FL fl_a_Ayfil,												/* [in] fl_a_Ayfil  */
	U2 u2_a_flg_undn,											/* [in] up/dn_flg	*/
	S4 *ps4_a_start_bin											/* [out] start_bin */
)
{
	/************** 探索範囲 *************************/
	/* 通常時 [focus_bin-2 ～ focus_bin + 2]         */
	/* -2 -1 0 +1 +2                                 */
	/*  x  x o x  x                                  */
	/*  <----|---->                                  */
	/*       ^focus bin                              */
	/*                                               */
	/* Ay > TH (加速時) [focus bin-4 ～ focus_bin]   */
	/* -4 -3 -2 -1 0                                 */
	/*  x  x  x  o x                                 */
	/* <---------|--								 */
	/*           ^focus bin							 */
	/*                                               */
	/* Ay > TH (減速時) [focus bin ～ focus_bin + 4] */
	/* 0 +1 +2 +3 +4                                 */
	/* x  o  x  x  x                                 */
	/* ---|-------->                                 */
	/*    ^focus bin                                 */
	/*************************************************/

	/* UP */
	if( u2_a_flg_undn == CU2_LFM_MOD_UP)
	{
		/* 加速時 */
		if (fl_a_Ayfil > AY_TH_NT) {											/* COND.c1 */
			*ps4_a_start_bin = s4_a_focus_bin - (PRIOR_RANGE - 2);				/* PROC.1 */
		} else if (fl_a_Ayfil < -AY_TH_NT) {		/* 減速時 */				/* COND.c2 */
			*ps4_a_start_bin = s4_a_focus_bin - 1;									/* PROC.2 */
		} else {	/* それ以外 */
			*ps4_a_start_bin = s4_a_focus_bin - ((((S4)PRIOR_RANGE + (S4)1) / (S4)2) - (S4)1);	/* PROC.3 */
		}
	}
	/* DOWN */
	else
	{
		/* speed-up */
		if(fl_a_Ayfil > AY_TH_NT)												/* COND.c1 */
		{
			*ps4_a_start_bin = s4_a_focus_bin - 1;								/* PROC.2 */
		}
		/* speed-down */
		else if(fl_a_Ayfil < -AY_TH_NT)											/* COND.c2 */
		{
			*ps4_a_start_bin = s4_a_focus_bin - (PRIOR_RANGE - 2);				/* PROC.1 */
		}
		/* default */
		else
		{
			*ps4_a_start_bin = s4_a_focus_bin - ((((S4)PRIOR_RANGE + (S4)1) / (S4)2) - (S4)1);	/* PROC.3 */
		}
	}

	if (*ps4_a_start_bin < ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1)) {
		*ps4_a_start_bin = (NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1;
	}
	if (*ps4_a_start_bin < ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1)) {		/* COND.c3 */
		*ps4_a_start_bin = NB_FFT_PT/2+CENTER_FREQ_RANGE+1;					/* PROC.4 */
	}
	if ((*ps4_a_start_bin + (PRIOR_RANGE - 1)) > (NB_FFT_PT - 1)) {			/* COND.c4 */
		*ps4_a_start_bin = NB_FFT_PT - PRIOR_RANGE;							/* PROC.5 */
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_estimate_doa									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)方位推定												*/
/*				:	FMCWの周波数スペクトラムのピーク周波数における反射波の	*/
/*				:	到来方向の推定を行う．									*/
/*				: 1) MUSICによる角度スペクトラムの算出						*/
/*				: 2) MUSIC角度スペクトラムのピークサーチ					*/
/*				: 3) BF(Beam forming)による角度スペクトラムの算出(電力推定)	*/
/*				: 4) BF(Beam forming)角度のピークサーチ						*/
/*				: 5) 方位の選択												*/
/*				: 6) 路面反射の除外											*/
/*				: 7) 角度ピーク補間											*/
/*				: 8) 方位推定結果の格納										*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)方位推定												*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_estimate_doa(
	S4 s4_a_flg_updn,												/* [in] s4_a_flg_updn */
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],								/* [in] power */

	S4 s4_a_start_bin,												/* [in] focus bin */
	FL fl_a_focus_power,											/* [in] focus afl_a_power */
	FL fl_a_focus_doa_bin_intpl,									/* [in] focus doa */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],						/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],							/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]						/* [out] peak doa afl_a_power */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;

	S4 as4_t_focus_bin[PRIOR_RANGE];
	FL afl_t_focus_power[PRIOR_RANGE];
	S4 as4_t_doa_num[PRIOR_RANGE];

	FL afl_t_selected_doa_bins_intpl[PRIOR_RANGE][2];
	FL afl_t_selected_doa_powers[PRIOR_RANGE][2];
	FL afl_t_selected_bins_intpl[PRIOR_RANGE][2];

	S4 s4_t_doa_diff;

	s4_t_doa_diff = N_DOA;

	/* 初期化 */
	for (s4_t_lp_i = 0; s4_t_lp_i < PRIOR_RANGE; s4_t_lp_i++) {
		as4_t_doa_num[s4_t_lp_i] = 0;
		for (s4_t_lp_j = 0; s4_t_lp_j < 2; s4_t_lp_j++) {
			afl_t_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_j] = 0.0F;
			afl_t_selected_doa_powers[s4_t_lp_i][s4_t_lp_j] = 0.0F;
			afl_t_selected_bins_intpl[s4_t_lp_i][s4_t_lp_j] = 0.0F;
		}
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < PRIOR_RANGE; s4_t_lp_i++) {
		as4_t_focus_bin[s4_t_lp_i] = s4_a_start_bin + s4_t_lp_i;
		afl_t_focus_power[s4_t_lp_i] = afl_a_power[ as4_t_focus_bin[s4_t_lp_i] ];

		/* (3) - 2)～7) 方位推定 */
		fn_bsm_prior_cal_doa(
			s4_a_flg_updn,
			(const FL (*)[CORRE_SIZE_4CH])afl_a_Ryy,
			(const FL *)afl_a_power,

			as4_t_focus_bin[s4_t_lp_i],
			fl_a_focus_power,
			fl_a_focus_doa_bin_intpl,
			&s4_t_doa_diff,

			&as4_t_doa_num[s4_t_lp_i],
			afl_t_selected_doa_bins_intpl[s4_t_lp_i],
			afl_t_selected_doa_powers[s4_t_lp_i],
			afl_t_selected_bins_intpl[s4_t_lp_i]
		);


	}

	*ps4_a_doa_peak_num = 0;
	/* (2) - 9) 方位推定結果の格納 */
	fn_bsm_prior_store_doa(
		(const FL *)afl_t_focus_power,

		(const S4 *)as4_t_doa_num,
		(const FL (*)[2])afl_t_selected_doa_bins_intpl,
		(const FL (*)[2])afl_t_selected_doa_powers,
		(const FL (*)[2])afl_t_selected_bins_intpl,

		ps4_a_doa_peak_num,
		afl_a_peak_bins_intpl,					/* [out] peak interpolated frequency */
		afl_a_peak_powers,						/* [out] peak afl_a_power */
		afl_a_peak_doa_bins_intpl,				/* [out] peak interpolated doa bin */
		afl_a_peak_doa_powers					/* [out] peak doa afl_a_power */
	);

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_cal_doa										*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2) 1)～7) 方位推定の計算									*/
/*				: 1) MUSICによる角度スペクトラムの算出						*/
/*				: 2) MUSIC角度スペクトラムのピークサーチ					*/
/*				: 3) BF(Beam forming)による角度スペクトラムの算出(電力推定)	*/
/*				: 4) BF(Beam forming)角度のピークサーチ						*/
/*				: 5) 方位の選択												*/
/*				: 6) 路面反射の除外											*/
/*				: 7) 角度ピーク補間											*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-1)MUSICによる角度スペクトラムの算出 ～				*/
/*				: (2)-7) 角度ピーク補間										*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_cal_doa(
	S4 s4_a_flg_updn,											/* [in] s4_a_flg_updn */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],				/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],							/* [in] raw data */

	S4 s4_a_focus_bin,											/* [in] */
	FL fl_a_focus_power,										/* [in] focus afl_a_power */
	FL fl_a_focus_doa_bin_intpl,								/* [in] focus doa */
	S4 *ps4_a_doa_diff,											/* [in] doa diff */

	S4 *ps4_a_doa_num,											/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],						/* [out] */
	FL afl_a_selected_doa_powers[2],							/* [out] */
	FL afl_a_selected_bins_intpl[2]								/* [out] */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	S4 s4_t_wave_num;
	FL afl_t_spec_doa[N_DOA];
	S4 as4_t_selected_doa_bins[2];

	S4 s4_t_wall_bin;
	S4 s4_a_exceptional_bin;

	S4 s4_t_tmp_doa_num = 0;

	as4_t_selected_doa_bins[0] = (S4)0;
	as4_t_selected_doa_bins[1] = (S4)0;

	if( st_g_bsm_loop_data.afl_wall_width[0] == WALL_MAX ) {
		s4_t_wall_bin = -1;
	} else {
		s4_t_wall_bin = (S4)(st_g_bsm_loop_data.afl_wall_width[0] / RCOF * 0.5F) + NB_FFT_PT / 2 -1;
	}
	if ( s4_a_flg_updn == 0) {
		s4_a_exceptional_bin = (S4)(NB_FFT_PT * 0.5F + fl_g_v_self_bsm_for_base / 3.6F / VCOF * 0.5F) + ROAD_REF_FREQ_BIN_OFFSET;	/* up */
	} else {
		s4_a_exceptional_bin = (S4)(NB_FFT_PT * 0.5F - fl_g_v_self_bsm_for_base / 3.6F / VCOF * 0.5F) + ROAD_REF_FREQ_BIN_OFFSET;	/* dn */
	}

	if ((s4_t_wall_bin != -1)														/* COND.a1 */
	&&  (( fl_abs( (FL)(s4_a_focus_bin - s4_t_wall_bin) )) < 3)) {					/* COND.a2 */
		s4_t_wave_num = s4_calc_spec_music_4ch_all_2wavefix(
			afl_a_Ryy[s4_a_focus_bin],		/* [in] */
			afl_t_spec_doa,					/* [out] */
			s4_a_flg_updn					/* [in] */
		);

		*ps4_a_doa_num = s4_search_peak_music(
			(const FL *)afl_t_spec_doa,		/* [in] */
			as4_t_selected_doa_bins,		/* [out] [2] DOA peak bin */
			afl_a_selected_doa_powers,		/* [out] [2] afl_a_power of DOA peak */
			s4_t_wave_num
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_DOA_RANGE_T)
			,OBJECT_TYPE_PRIOR				/* [in] object type: prior object */
#endif
		);

		for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
			if (as4_t_selected_doa_bins[s4_t_lp_i]>0) {
				afl_a_selected_doa_powers[s4_t_lp_i] = fl_calc_spec_bf_4ch_fm_of_specified_doa(
					afl_a_Ryy[s4_a_focus_bin],
					s4_a_flg_updn,
					s4_a_focus_bin,
					as4_t_selected_doa_bins[s4_t_lp_i]
				);
			}
		}

		/***** (2) 6) 方位の選択 *****/
		s4_t_tmp_doa_num = *ps4_a_doa_num;
		if(*ps4_a_doa_num > 1)
		{
			for(s4_t_lp_k=0; s4_t_lp_k<*ps4_a_doa_num; s4_t_lp_k++)
			{
				if ((as4_t_selected_doa_bins[s4_t_lp_k] < (N_DOA - (S4)st_g_bsm_loop_data.afl_installed_angle[0] - DOA_RANGE_FORWARD))				/* COND.d1 */
				&&  (as4_t_selected_doa_bins[s4_t_lp_k] > (N_DOA - (S4)st_g_bsm_loop_data.afl_installed_angle[0] - (S4)CU1_DOA_RANGE_BACKWARD))		/* COND.d2 */
				&&  (*ps4_a_doa_diff > fl_abs((FL)as4_t_selected_doa_bins[s4_t_lp_k] - (FL)fl_a_focus_doa_bin_intpl))) {							/* COND.d3 */
					*ps4_a_doa_diff = (S4)fl_abs(as4_t_selected_doa_bins[s4_t_lp_k]-fl_a_focus_doa_bin_intpl);			/* PROC.1 */
				}
				else
				{
					as4_t_selected_doa_bins[s4_t_lp_k] = 0;																/* PROC.2 */
					afl_a_selected_doa_powers[s4_t_lp_k] = 0.0F;														/* PROC.3 */
					if ((s4_t_lp_k==0)																					/* COND.d4 */
					&&  (*ps4_a_doa_num==2)) {																				/* COND.d5 */
						as4_t_selected_doa_bins[0] = as4_t_selected_doa_bins[1];										/* PROC.4 */
						afl_a_selected_doa_powers[0] = afl_a_selected_doa_powers[1];									/* PROC.5 */
						as4_t_selected_doa_bins[1] = 0;																	/* PROC.6 */
						afl_a_selected_doa_powers[1]  = 0.0F;															/* PROC.7 */
					}
					s4_t_tmp_doa_num--;																					/* PROC.8 */
				}
			}
			*ps4_a_doa_num = s4_t_tmp_doa_num;
		}
	} else {
		/***** (2) 2) MUSICによる角度スペクトラムの算出 *****/
		s4_t_wave_num = s4_calc_spec_music_4ch_all(
			afl_a_Ryy[s4_a_focus_bin],		/* [in] */
			afl_t_spec_doa,					/* [out] */
			2,								/* [in] */
			s4_a_flg_updn					/* [in] */
		);
		/***** (2) 3) MUSIC角度スペクトラムのピークサーチ *****/
		/***** (ii) 角度スペクトラムのピークサーチ *****/
		*ps4_a_doa_num = s4_search_peak_music(
			(const FL *)afl_t_spec_doa,		/* [in] */
			as4_t_selected_doa_bins,		/* [out] [2] DOA peak bin */
			afl_a_selected_doa_powers,		/* [out] [2] afl_a_power of DOA peak */
			s4_t_wave_num
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_DOA_RANGE_T)
			,OBJECT_TYPE_PRIOR
#endif
		);
		/***** (2) 4) BF (Beam forming) による角度スペクトラムの算出（電力推定）*****/
		for(s4_t_lp_k=0; s4_t_lp_k<2; s4_t_lp_k++)
		{
			if(as4_t_selected_doa_bins[s4_t_lp_k]>0)
			{
				afl_a_selected_doa_powers[s4_t_lp_k] = fl_calc_spec_bf_4ch_fm_of_specified_doa(
					afl_a_Ryy[s4_a_focus_bin],			/* [in] */
					s4_a_flg_updn,
					s4_a_focus_bin,
					as4_t_selected_doa_bins[s4_t_lp_k]
				);
			}
		}
	}

	/***** (2) 8) 角度ピーク補間 *****/
	for(s4_t_lp_k=0; s4_t_lp_k<2; s4_t_lp_k++)
	{
		if(as4_t_selected_doa_bins[s4_t_lp_k]>0)
		{
			afl_a_selected_doa_bins_intpl[s4_t_lp_k] = fl_interpolate_music_peak(
				(const FL *)afl_t_spec_doa,
				as4_t_selected_doa_bins[s4_t_lp_k],
				(const FL *)FL_BSM_FLSH_YOMIKAE_TBL_FM
			);
			afl_a_selected_bins_intpl[s4_t_lp_k] = fl_interpolate_freq_peak(
				(const FL *)afl_a_power,
				s4_a_focus_bin
			);
		}
	}
	
	/***** (2) 9) 方位推定結果の格納(LCAとの共有ピーク情報へ格納) *****/
	fn_cmn_shareMUSIC_set_finished_music_data_main( (U1)s4_a_flg_updn,
													(U1)*ps4_a_doa_num,
													(U2)s4_a_focus_bin,
													afl_a_selected_bins_intpl[0],
													afl_a_selected_doa_bins_intpl,
													afl_a_selected_doa_powers);

	/* 路面反射付近のfreq binでdoaが真後付近の場合は前回値を引き継いで補完する */
	if (
		(s4_a_focus_bin > (s4_a_exceptional_bin - ROAD_REF_FREQ_BIN_RANGE))			/* COND.c1 */
	 && (s4_a_focus_bin < (s4_a_exceptional_bin + ROAD_REF_FREQ_BIN_RANGE))			/* COND.c2 */
	) {
		for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
			if (
				(afl_a_selected_doa_bins_intpl[s4_t_lp_i] > ((((FL)N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0]) - (FL)ROAD_REF_DOA_BIN_RANGE))	/* COND.c4 */
			 && (afl_a_selected_doa_bins_intpl[s4_t_lp_i] < ((((FL)N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0]) + (FL)ROAD_REF_DOA_BIN_RANGE))	/* COND.c5 */
			 && (fl_a_focus_doa_bin_intpl > ((((FL)N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0]) + (FL)ROAD_REF_DOA_BIN_RANGE))					/* COND.c3 */
			) {
				*ps4_a_doa_num = 1;												/* PROC.3 */
				afl_a_selected_doa_bins_intpl[0] = fl_a_focus_doa_bin_intpl;	/* PROC.1 */
				afl_a_selected_doa_bins_intpl[1] = 0;							/* PROC.1 */
				afl_a_selected_doa_powers[0] = fl_a_focus_power;				/* PROC.2 */
				afl_a_selected_doa_powers[1] = 0.0F;							/* PROC.2 */
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_store_doa									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-9)方位推定結果の格納									*/
/*				: MUSIC方位展開処理を実施した場合、LCAとのピーク情報共有	*/
/*				: バッファに結果を格納する。								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-9)方位推定結果の格納									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_store_doa(
	const FL afl_a_focus_power[PRIOR_RANGE],					/* [in] power */

	const S4 as4_a_doa_num[PRIOR_RANGE],
	const FL afl_a_selected_doa_bins_intpl[PRIOR_RANGE][2],		/* [in]  */
	const FL afl_a_selected_doa_powers[PRIOR_RANGE][2],			/* [in]  */
	const FL afl_a_selected_bins_intpl[PRIOR_RANGE][2],			/* [in]  */

	S4 *ps4_a_doa_peak_num,										/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],				/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]					/* [out] peak doa afl_a_power */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_iRet;

	U1 au1_t_copy[PRIOR_RANGE][2];
	FL afl_t_peak_bins_intpl[PRIOR_RANGE][2];					/* [out] peak interpolated frequency */
	FL afl_t_peak_powers[PRIOR_RANGE][2];						/* [out] peak afl_a_power */
	FL afl_t_peak_doa_bins_intpl[PRIOR_RANGE][2];				/* [out] peak interpolated doa bin */
	FL afl_t_peak_doa_powers[PRIOR_RANGE][2];					/* [out] peak doa afl_a_power */

	for (s4_t_lp_i = 0; s4_t_lp_i < PRIOR_RANGE; s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < 2; s4_t_lp_k++) {
			au1_t_copy[s4_t_lp_i][s4_t_lp_k] = CU1_DF_NG;
			afl_t_peak_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_peak_powers[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_peak_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_peak_doa_powers[s4_t_lp_i][s4_t_lp_k] = 0.0F;
		}
	}
	/* ペアマッチ用の方位推定結果を格納 */
	for (s4_t_lp_i = 0; s4_t_lp_i < PRIOR_RANGE; s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < as4_a_doa_num[s4_t_lp_i]; s4_t_lp_k++) {
			if (
				(afl_a_selected_doa_powers[s4_t_lp_i][s4_t_lp_k] > DOA_POW_THRESHOLD_BF)
				&& (afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] < ((FL)N_DOA - st_g_bsm_loop_data.afl_installed_angle[0] - (FL)DOA_RANGE_FORWARD))
			) {
				au1_t_copy[s4_t_lp_i][s4_t_lp_k] = CU1_DF_OK;
				afl_t_peak_bins_intpl[s4_t_lp_i][s4_t_lp_k] = afl_a_selected_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_t_peak_powers[s4_t_lp_i][s4_t_lp_k] = afl_a_focus_power[s4_t_lp_i];
				afl_t_peak_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] = afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_t_peak_doa_powers[s4_t_lp_i][s4_t_lp_k] = afl_a_selected_doa_powers[s4_t_lp_i][s4_t_lp_k];
			}
		}
	}

	s4_t_iRet = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < PRIOR_RANGE; s4_t_lp_i++) {
		if (au1_t_copy[s4_t_lp_i][0] == CU1_DF_OK) {
			for (s4_t_lp_k = 0; s4_t_lp_k < 2; s4_t_lp_k++) {
				if( afl_t_peak_bins_intpl[s4_t_lp_i][s4_t_lp_k] != 0.0F ) {
					afl_a_peak_bins_intpl[s4_t_iRet][s4_t_lp_k] = afl_t_peak_bins_intpl[s4_t_lp_i][s4_t_lp_k];
					afl_a_peak_powers[s4_t_iRet][s4_t_lp_k] = afl_t_peak_powers[s4_t_lp_i][s4_t_lp_k];
					afl_a_peak_doa_bins_intpl[s4_t_iRet][s4_t_lp_k] = afl_t_peak_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k];
					afl_a_peak_doa_powers[s4_t_iRet][s4_t_lp_k] = afl_t_peak_doa_powers[s4_t_lp_i][s4_t_lp_k];
				}
			}
			s4_t_iRet++;
		}
	}

	*ps4_a_doa_peak_num = s4_t_iRet;

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_estimate_doa_around_dc						*/
/*--------------------------------------------------------------------------*/
/* 機能			: (2)-4)～5) BF(Beam forming)による角度推定					*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-4)～5) BF(Beam forming)による角度推定					*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
static VD fn_bsm_prior_estimate_doa_around_dc(
	S4 s4_a_flg_updn,												/* [in] s4_a_flg_updn */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],					/* [in] self correlation */
	const FL afl_a_power[NB_FFT_PT],								/* [in] raw data */

	S4 s4_a_focus_bin,												/* [in] */
	S4 s4_a_bin_pred,												/* [in] */
	FL fl_a_bin_interpolate_pred,									/* [in] */
	FL fl_a_doa_interpolate_pred,									/* [in] */
	FL fl_a_power_music,											/* [in] */
	S4 s4_a_bin_music_pred,											/* [in] */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[PRIOR_RANGE][2],						/* [out] peak interpolated frequency */
	FL afl_a_peak_powers[PRIOR_RANGE][2],							/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[PRIOR_RANGE][2],					/* [out] peak interpolated doa bin */
	FL afl_a_peak_doa_powers[PRIOR_RANGE][2]						/* [out] peak doa afl_a_power */
)
{
	FL afl_t_doa_spec[N_DOA];
	S4 s4_t_doa[1];
	FL fl_t_peak_power[1];
	U1 u1_t_lp_n_doa;

	/* ローカル変数初期化 */
	for (u1_t_lp_n_doa = (U1)0; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		afl_t_doa_spec[u1_t_lp_n_doa] = (FL)0.0F;
	}
	s4_t_doa[0] = (S4)0;
	fl_t_peak_power[0] = (FL)0.0F;

	/***** (2) 4) BF (Beam forming) による角度スペクトラムの算出（電力推定） *****/
	fn_calc_spec_bf_4ch_fm(
		(const FL *)(afl_a_Ryy[s4_a_focus_bin]),	/* [in] */
		afl_t_doa_spec,								/* [out] */
		s4_a_flg_updn,								/* [in] */
		s4_a_focus_bin								/* [in] */
	);
	/***** (2) 5)BF (Beam forming) 角度のピークサーチ *****/
	s4_search_peak_bf(
		(const FL *)afl_t_doa_spec,		/* [in] */
		s4_t_doa,						/* [out] */
		fl_t_peak_power,				/* [out] */
		1								/* [in] */
	);
	if ((!( s4_abs(s4_t_doa[0] - (N_DOA-AXIS_DEFAULT)) < PRIOR_WALL_DOA_DIFF_TH ))		/* COND.b7 */
	&&  (s4_abs( s4_t_doa[0] - s4_a_bin_music_pred ) < DOA_DIFF_FM_SINGLEPEAK)) {		/* COND.b8 */
		*ps4_a_doa_peak_num = 1;
		afl_a_peak_bins_intpl[0][0] 	= fl_a_bin_interpolate_pred;
		afl_a_peak_powers[0][0] 		= afl_a_power[s4_a_focus_bin];
		afl_a_peak_doa_bins_intpl[0][0] = fl_a_doa_interpolate_pred;
		afl_a_peak_doa_powers[0][0] 	= fl_t_peak_power[0];
	}

	return;
}


/****************************************************************************/
/* 関数名		: u1_bsm_prior_make_pair									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (0) 移動物ペアマッチ処理 & (3)物標情報算出処理（移動物）	*/
/*				: (0)-1)予測方位との差が一定範囲内で電力最大のものを選択	*/
/*				: (3)-1)自車速相当の上り/下りの周波数bin差を算出			*/
/*				: (3)-2)角度差の許容範囲の設定								*/
/*				: (3)-3)物標情報の算出と保存								*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (0)移動物ペアマッチ処理 & (3)物標情報算出処理（移動物)	*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
U1 u1_bsm_prior_make_pair(
	FL fl_a_focus_doa_bin_intpl_up,									/* [in] focus doa */
	FL fl_a_focus_doa_bin_intpl_dn,									/* [in] focus doa */
	FL fl_a_power_up_music,										/* [in] */
	FL fl_a_power_dn_music,										/* [in] */

	S4 s4_a_peak_num_prior_up,									/* [in] */
	FL afl_a_peak_bins_intpl_up[PRIOR_RANGE][2],				/* [in] peak doa bin */
	FL afl_a_peak_powers_up[PRIOR_RANGE][2],					/* [in] peak doa afl_a_power */
	FL afl_a_peak_doa_bins_intpl_up[PRIOR_RANGE][2],			/* [in] peak doa bin */
	FL afl_a_peak_doa_powers_up[PRIOR_RANGE][2],				/* [in] peak doa afl_a_power */

	S4 s4_a_peak_num_prior_dn,									/* [in] */
	FL afl_a_peak_bins_intpl_dn[PRIOR_RANGE][2],				/* [in] peak doa bin */
	FL afl_a_peak_powers_dn[PRIOR_RANGE][2],					/* [in] peak doa afl_a_power */
	FL afl_a_peak_doa_bins_intpl_dn[PRIOR_RANGE][2],			/* [in] peak doa bin */
	FL afl_a_peak_doa_powers_dn[PRIOR_RANGE][2],				/* [in] peak doa afl_a_power */

	S4 s4_a_normal_prior_num,
	NORMAL_BSM *pst_a_normal_prior								/* [in / out] */
)
{
	U1 u1_make_pair_result;

	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	S4 s4_t_shift;

	FL fl_t_buf_comp;
	S4 s4_t_index_up1;
	S4 s4_t_index_dn1;
	S4 s4_t_index_up2;
	S4 s4_t_index_dn2;
	U1 u1_t_jdg_a2_flg;
	U1 u1_t_jdg_a6_flg;
	U1 u1_t_jdg_a7_flg;
	U1 u1_t_jdg_a8_flg;

#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	S4 s4_t_doa_diff_predict;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	/****************************************************************************/
	/* (3)	移動物ペアマッチ処理												*/
	/****************************************************************************/
	/***** (3) 1) 予測方位との差が一定範囲内で電力最大のものを選択 *****/
	/* make pair */
	s4_t_index_up1 = -1;
	s4_t_index_dn1 = -1;
	s4_t_index_up2 = -1;
	s4_t_index_dn2 = -1;

	/* Set the threshold of DOA difference between predicted DOA and detected DOA */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT;
	if (fl_g_v_self_bsm_for_base < (FL)CANOUT_VSELF_SLOW) {			/* COND.a30 */
		s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT - (S4)2;		/* PROC.5 */
	}

	if (st_g_bsm_loop_data.s4_flg_alarm == (S4)1) {					/* COND.a31 */
		s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT + (S4)2;		/* PROC.6 */
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	fl_t_buf_comp = 0.0F;							/* PROC.1 */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_prior_up; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 2; s4_t_lp_j++) {
			/* 条件a2の判定関数コール 仕様書の記述より条件a2の定義部分にコンパイルスイッチが入るため、	*/
			/* 条件a2の判定用関数を作り、判定結果を条件確認箇所で使用する								*/
			/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない			*/
			u1_t_jdg_a2_flg = u1_bsm_prior_make_pair_a2(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i][s4_t_lp_j], fl_a_focus_doa_bin_intpl_up, (FL)s4_t_doa_diff_predict);
			if (
				(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i][s4_t_lp_j] != 0.0F)		/* COND.a1 */
			 && (u1_t_jdg_a2_flg == CU1_TRUE)										/* COND.a2 */
			 && (afl_a_peak_doa_powers_up[s4_t_lp_i][s4_t_lp_j] > fl_t_buf_comp)	/* COND.a3 */
			) {
				fl_t_buf_comp = afl_a_peak_doa_powers_up[s4_t_lp_i][s4_t_lp_j];		/* PROC.2 */
				s4_t_index_up1 = s4_t_lp_i;											/* PROC.3 */
				s4_t_index_up2 = s4_t_lp_j;											/* PROC.4 */
			}
		}
	}

	/* Erase the selected index if the peak power is small */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	if ((s4_t_index_up1 >= (S4)0)
	&&  (s4_t_index_up2 >= (S4)0)) {
		if ((afl_a_peak_powers_up[s4_t_index_up1][s4_t_index_up2] < (FL)50.0F)		/* COND.a32 */
		&&  (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1))) {						/* COND.!a31 */
			s4_t_index_up1 = (S4)-1;
			s4_t_index_up2 = (S4)-1;
		}
	} else {
		/* s4_t_index_up1,s4_t_index_up2のどちらかが初期値の場合は条件a32の判定を行わずTRUEとみなす */
		if (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1)) {							/* COND.!a31 */
			s4_t_index_up1 = (S4)-1;
			s4_t_index_up2 = (S4)-1;
		}
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	fl_t_buf_comp = 0.0F;							/* PROC.1' */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_prior_dn; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 2; s4_t_lp_j++) {
			/* 条件a2の判定関数コール 仕様書の記述より条件a2の定義部分にコンパイルスイッチが入るため、	*/
			/* 条件a2の判定用関数を作り、判定結果を条件確認箇所で使用する								*/
			/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない			*/
			u1_t_jdg_a2_flg = u1_bsm_prior_make_pair_a2(afl_a_peak_doa_bins_intpl_dn[s4_t_lp_i][s4_t_lp_j], fl_a_focus_doa_bin_intpl_dn, (FL)s4_t_doa_diff_predict);
			if (
				(afl_a_peak_doa_bins_intpl_dn[s4_t_lp_i][s4_t_lp_j] != 0.0F)		/* COND.a1' */
			 && (fl_t_buf_comp < afl_a_peak_doa_powers_dn[s4_t_lp_i][s4_t_lp_j])	/* COND.a3' */
			 && (u1_t_jdg_a2_flg == CU1_TRUE)										/* COND.a2' */
			) {
				fl_t_buf_comp = afl_a_peak_doa_powers_dn[s4_t_lp_i][s4_t_lp_j];		/* PROC.2' */
				s4_t_index_dn1 = s4_t_lp_i;											/* PROC.3' */
				s4_t_index_dn2 = s4_t_lp_j;											/* PROC.4' */
			}
		}
	}

	/* Erase the selected index if the peak power is small */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	if ((s4_t_index_dn1 >= (S4)0)
	&&  (s4_t_index_dn2 >= (S4)0)) {
		if ((afl_a_peak_powers_dn[s4_t_index_dn1][s4_t_index_dn2] < (FL)50.0F)		/* COND.a32 */
		&&  (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1))) {						/* COND.!a31 */
			s4_t_index_dn1 = (S4)-1;
			s4_t_index_dn2 = (S4)-1;
		}
	} else {
		/* s4_t_index_up1,s4_t_index_up2のどちらかが初期値の場合は条件a32の判定を行わずTRUEとみなす */
		if (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1)) {							/* COND.!a31 */
			s4_t_index_dn1 = (S4)-1;
			s4_t_index_dn2 = (S4)-1;
		}
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */


	/****************************************************************************/
	/* (3)	物標情報算出処理（移動物）											*/
	/****************************************************************************/
	u1_make_pair_result = CU1_FALSE;
	/***** (3) 1) 自車速相当の上り/下りの周波数bin差を算出 *****/
	s4_t_shift = (S4)((fl_g_v_self_bsm_for_base / 3.60F / VCOF) + 0.50F);
	if ((s4_t_index_up1 >= 0)
	&&  (s4_t_index_up2 >= 0)
	&&  (s4_t_index_dn1 >= 0)
	&&  (s4_t_index_dn2 >= 0)) {
		/* 条件a6,a7,a8の判定関数コール 仕様書の記述より条件a6,a7,a8の定義部分にコンパイルスイッチが入るため、	*/
		/* 条件a6,a7,a8の判定用関数を作り、判定結果を条件確認箇所で使用する										*/
		/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない						*/
		/* 配列外参照を防ぐため、条件判定関数は条件a1～a4成立時のみコールする									*/
		u1_t_jdg_a6_flg = u1_bsm_prior_make_pair_a6(afl_a_peak_doa_powers_up[s4_t_index_up1][s4_t_index_up2], fl_a_power_up_music);
		u1_t_jdg_a7_flg = u1_bsm_prior_make_pair_a7(afl_a_peak_doa_powers_dn[s4_t_index_dn1][s4_t_index_dn2], fl_a_power_dn_music);
		u1_t_jdg_a8_flg = u1_bsm_prior_make_pair_a8(afl_a_peak_bins_intpl_up[s4_t_index_up1][s4_t_index_up2], afl_a_peak_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2]);

		if (((afl_a_peak_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])  < (FL)(s4_t_shift - 3))		/* COND.a5 */
		&&  (u1_t_jdg_a6_flg == CU1_TRUE)																														/* COND.a6 */
		&&  (u1_t_jdg_a7_flg == CU1_TRUE)) {																													/* COND.a7 */
		/***** (3) 2) 角度差の許容範囲の設定*****/
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			S4 s4_t_doa_diff_up_down = DOA_DIFF_UP_DOWN;		/* PROC.1 */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			S4 s4_t_doa_diff_up_down = (S4)CU1_DOA_DIFF_UP_DOWN_PRIOR;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */
			if ((fl_g_v_self_bsm_for_base < CANOUT_VSELF_SLOW)		/* COND.a9 */
			&&  (u1_t_jdg_a8_flg == CU1_TRUE)) {					/* COND.a8 */
				s4_t_doa_diff_up_down = DOA_DIFF_UP_DOWN_SLOW;		/* PROC.1 */
			}

#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			/* 搭載角度50degでは処理なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			if (st_g_bsm_loop_data.u1_truck_flg != (U1)0) {			/* COND.a33 */
				s4_t_doa_diff_up_down += (S4)2;						/* PROC.2 */
			}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

			/***** (3) 3) 物標情報の算出と保存*****/
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			if ((s4_a_normal_prior_num < (S4)PRIOR_BUFFSIZE) 																															/* CONT.b1 */
			&&  (s4_abs((S4)(afl_a_peak_doa_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])) < s4_t_doa_diff_up_down)		/* COND.b2 */
			&&  (fl_abs(afl_a_peak_doa_powers_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_powers_dn[s4_t_index_dn1][s4_t_index_dn2]) < POW_DIFF_UP_DOWN_DOA))					/* COND.b3 */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			if ((s4_a_normal_prior_num < (S4)PRIOR_BUFFSIZE) 																															/* CONT.b1 */
			&&  (s4_abs((S4)(afl_a_peak_doa_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])) < s4_t_doa_diff_up_down))	/* COND.b2 */
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */
			{
				fn_set_normal_data(
					pst_a_normal_prior,												/* [out] */
					afl_a_peak_bins_intpl_up[s4_t_index_up1][s4_t_index_up2],		/* [in] */
					afl_a_peak_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2],		/* [in] */
					afl_a_peak_doa_bins_intpl_up[s4_t_index_up1][s4_t_index_up2],	/* [in] */
					afl_a_peak_doa_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2],	/* [in] */
					afl_a_peak_powers_up[s4_t_index_up1][s4_t_index_up2],			/* [in] */
					afl_a_peak_powers_dn[s4_t_index_dn1][s4_t_index_dn2],			/* [in] */
					afl_a_peak_doa_powers_up[s4_t_index_up1][s4_t_index_up2],		/* [in] */
					afl_a_peak_doa_powers_dn[s4_t_index_dn1][s4_t_index_dn2],		/* [in] */
					0,																/* 停止物フラグ */
					0																/* 片ピークフラグ */
				);
				u1_make_pair_result = CU1_TRUE;
			}
		}
	}

	return (u1_make_pair_result);
}

/****************************************************************************/
/* 関数名		: u1_bsm_prior_make_pair_a2									*/
/*--------------------------------------------------------------------------*/
/* 機能			: 移動物ペアマッチ処理の条件a2判定関数						*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_peak_doa_bins_intpl	: 方位補間bin [in]				*/
/*				: fl_a_focus_doa_bin_intpl	: 前回の予測方位bin [in]		*/
/*				: fl_a_doa_diff_predict		: 判定閾値 [in]					*/
/* 戻り値		: u1_t_jdg_a2_flag		: 条件a2の判定結果格納変数			*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (3) 移動物ペアマッチ処理の条件a2							*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a2(FL fl_a_peak_doa_bins_intpl, FL fl_a_focus_doa_bin_intpl, FL fl_a_doa_diff_predict)
{
	/* 条件a2が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_a2_flag;				/* 条件a2判定結果格納変数 */
	FL fl_t_diff_doa_bin_intpl_abs;		/* 方位補間binと前回の予測方位binの差の絶対値 */

	/* FALSEで初期化 */
	u1_t_jdg_a2_flag = CU1_FALSE;

	fl_t_diff_doa_bin_intpl_abs = fl_abs(fl_a_peak_doa_bins_intpl - fl_a_focus_doa_bin_intpl);

	/* 条件a2の判定 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degのとき */
	if (fl_t_diff_doa_bin_intpl_abs < (FL)DOA_DIFF_PREDICT) {
		u1_t_jdg_a2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a2_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* 搭載角度20degのとき */
	if (fl_t_diff_doa_bin_intpl_abs < fl_a_doa_diff_predict) {
		u1_t_jdg_a2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a2_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a2_flag;
}

/****************************************************************************/
/* 関数名		: u1_bsm_prior_make_pair_a6									*/
/*--------------------------------------------------------------------------*/
/* 機能			: 物標情報算出処理（移動物） の条件a6判定関数				*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_peak_doa_powers_up	: 上り方位電力 [in]				*/
/*				: fl_a_power_up_music		: 前回の上りmusic電力 [in]		*/
/* 戻り値		: u1_t_jdg_a6_flag			: 条件a6の判定結果格納変数		*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  物標情報算出処理（移動物） の条件a6					*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a6(FL fl_a_peak_doa_powers_up, FL fl_a_power_up_music)
{
	/* 条件a6が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_a6_flag;				/* 条件a6判定結果格納変数 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_doa_power_up_abs;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSEで初期化 */
	u1_t_jdg_a6_flag = CU1_FALSE;

	/* 条件a6の判定 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degのとき */
	if ((fl_a_peak_doa_powers_up - fl_a_power_up_music) > PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a6_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* 搭載角度20degのとき */
	fl_t_diff_doa_power_up_abs = fl_abs(fl_a_peak_doa_powers_up - fl_a_power_up_music);

	if (fl_t_diff_doa_power_up_abs < PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a6_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a6_flag;
}

/****************************************************************************/
/* 関数名		: u1_bsm_prior_make_pair_a7									*/
/*--------------------------------------------------------------------------*/
/* 機能			: 物標情報算出処理（移動物） の条件a7判定関数				*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_peak_doa_powers_dn	: 下り方位電力 [in]				*/
/*				: fl_a_power_dn_music		: 前回の下りmusic電力 [in]		*/
/* 戻り値		: u1_t_jdg_a7_flag			: 条件a7の判定結果格納変数		*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  物標情報算出処理（移動物） の条件a7					*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a7(FL fl_a_peak_doa_powers_dn, FL fl_a_power_dn_music)
{
	/* 条件a7が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_a7_flag;				/* 条件a7判定結果格納変数 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_doa_power_dn_abs;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSEで初期化 */
	u1_t_jdg_a7_flag = CU1_FALSE;

	/* 条件a7の判定 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degのとき */
	if ((fl_a_peak_doa_powers_dn - fl_a_power_dn_music) > PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a7_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a7_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* 搭載角度20degのとき */
	fl_t_diff_doa_power_dn_abs = fl_abs(fl_a_peak_doa_powers_dn - fl_a_power_dn_music);

	if (fl_t_diff_doa_power_dn_abs < PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a7_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a7_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a7_flag;
}

/****************************************************************************/
/* 関数名		: u1_bsm_prior_make_pair_a8									*/
/*--------------------------------------------------------------------------*/
/* 機能			: 物標情報算出処理（移動物） の条件a8判定関数				*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_peak_bins_intpl_up	: 上り周波数補間bin [in]		*/
/*				: fl_a_peak_bins_intpl_dn	: 下り周波数補間bin [in]		*/
/* 戻り値		: u1_t_jdg_a8_flag			: 条件a8の判定結果格納変数		*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  物標情報算出処理（移動物） の条件a8					*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a8(FL fl_a_peak_bins_intpl_up, FL fl_a_peak_bins_intpl_dn)
{
	/* 条件a8が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_a8_flag;				/* 条件a8判定結果格納変数 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degでは定義なし */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_peak_bin_intpl_abs;
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSEで初期化 */
	u1_t_jdg_a8_flag = CU1_FALSE;

	/* 条件a8の判定 */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* 搭載角度50degのとき */
	if ((fl_a_peak_bins_intpl_up - fl_a_peak_bins_intpl_dn) > (FL)1.0F) {
		u1_t_jdg_a8_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a8_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* 搭載角度20degのとき */
	fl_t_diff_peak_bin_intpl_abs = fl_abs(fl_a_peak_bins_intpl_up - fl_a_peak_bins_intpl_dn);

	if (fl_t_diff_peak_bin_intpl_abs > (FL)1.0F) {
		u1_t_jdg_a8_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a8_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a8_flag;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_delete_same_object							*/
/*--------------------------------------------------------------------------*/
/* 機能			: (3) 4) 同一物標情報の削除									*/
/*				: 今回更新した物標情報の中で同一のピークを持つものがある場合*/
/*				: 前回の予測位置・速度にもっとも近いものを選択する。		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (3) 4) 同一物標情報の削除									*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_delete_same_object(
	const S4 as4_a_prev_index[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal[PRIOR_BUFFSIZE],
	const NORMAL_BSM ast_a_ast_normal_copy[NORMAL_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;

	FL fl_t_buf_comp;
	FL fl_t_rx_diff;
	FL fl_t_ry_diff;
	FL fl_t_vx_diff;
	FL fl_t_vy_diff;

	fl_t_buf_comp = 120.0F * 4;
	fl_t_rx_diff = CFL_UNKNOWN_VALUE;
	fl_t_ry_diff = CFL_UNKNOWN_VALUE;
	fl_t_vx_diff = CFL_UNKNOWN_VALUE;
	fl_t_vy_diff = CFL_UNKNOWN_VALUE;

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_pair_num_prior; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < s4_a_pair_num_prior; s4_t_lp_j++) {
			if (
				(s4_t_lp_i != s4_t_lp_j)															/* COND.c1 */
			 && (ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE)                                  /* COND.c2 */
			 && (ast_a_normal[s4_t_lp_j].fl_Robs != CFL_UNKNOWN_VALUE)                                  /* COND.c2 */
			 && ((ast_a_normal[s4_t_lp_i].s4_bin_up - ast_a_normal[s4_t_lp_j].s4_bin_up) == 0)      /* COND.c3 */
			 && ((ast_a_normal[s4_t_lp_i].s4_bin_dn - ast_a_normal[s4_t_lp_j].s4_bin_dn) == 0)      /* COND.c4 */
			) {
				fl_t_rx_diff = fl_abs(ast_a_normal[s4_t_lp_i].fl_Rxobs - ast_a_ast_normal_copy[as4_a_prev_index[s4_t_lp_i]].fl_Rxpred);		/* PROC.1 */
				fl_t_ry_diff = fl_abs(ast_a_normal[s4_t_lp_i].fl_Ryobs - ast_a_ast_normal_copy[as4_a_prev_index[s4_t_lp_i]].fl_Rypred);     /* PROC.2 */
				fl_t_vx_diff = fl_abs(ast_a_normal[s4_t_lp_i].fl_Vxobs - ast_a_ast_normal_copy[as4_a_prev_index[s4_t_lp_i]].fl_Vxpred);     /* PROC.3 */
				fl_t_vy_diff = fl_abs(ast_a_normal[s4_t_lp_i].fl_Vyobs - ast_a_ast_normal_copy[as4_a_prev_index[s4_t_lp_i]].fl_Vypred);     /* PROC.4 */
				if (fl_t_buf_comp > (fl_t_rx_diff + fl_t_ry_diff + fl_t_vx_diff + fl_t_vy_diff)) {                                                  /* COND.c5 */
					fl_t_buf_comp = fl_t_rx_diff + fl_t_ry_diff + fl_t_vx_diff + fl_t_vy_diff;														/* PROC.5 */
				} else {
					fn_init(&ast_a_normal[s4_t_lp_i], 1);																							/* PROC.6 */
				}
			}
		}
	}

	return;
}


/****************************************************************************/
/* 関数名		: fn_bsm_prior_set_object									*/
/*--------------------------------------------------------------------------*/
/* 機能			: (5)出力データ保存											*/
/*				: 前項までの処理にて算出した結果より、優先物標情報（整数値）*/
/*				: 優先物標情報（浮動小数値）、優先物標数を出力する。		*/
/*--------------------------------------------------------------------------*/
/* 引数			: 															*/
/* 戻り値		: 															*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (5)出力データ保存											*/
/*--------------------------------------------------------------------------*/
/* 作成者		: 															*/
/****************************************************************************/
VD fn_bsm_prior_set_object(
	S4 *ps4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],				/* [out] S4 values of NORMAL_BSM structure */

	S4 s4_a_buf_normal_num,
	const NORMAL_BSM ast_a_buf_normal[PRIOR_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_pair_num_prior;

	/****************************************************************************/
	/* (5)   出力データ保存                                                     */
	/****************************************************************************/
	s4_t_pair_num_prior = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_buf_normal_num; s4_t_lp_i++) {
		if (ast_a_buf_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {
			ast_a_normal_prior[s4_t_pair_num_prior] = ast_a_buf_normal[s4_t_lp_i];
			ast_a_normal_prior[s4_t_pair_num_prior].s4_flg_dc = OBJECT_TYPE_PRIOR;
			s4_t_pair_num_prior++;
		}
	}
	*ps4_a_pair_num_prior = s4_t_pair_num_prior;

	return;
}

S4 s4_search_prior_freq_peak_org(
	FL afl_a_power[NB_FFT_PT],									/* [in] raw data */
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],					/* [in] self correlation */
	S4 as4_a_peak_bin[PRIOR_RANGE][2],							/* [out] peak frequency */
	FL afl_a_peak_power[PRIOR_RANGE][2],						/* [out] peak afl_a_power */
	S4 as4_a_peak_doa[PRIOR_RANGE][2],							/* [out] peak doa bin */
	FL afl_a_peak_doa_power[PRIOR_RANGE][2],					/* [out] peak doa afl_a_power */
	S4 s4_a_focus_bin,											/* [in] focus bin */
	FL fl_a_focus_pow,											/* [in] focus afl_a_power */
	S4 s4_a_focus_doa,											/* [in] focus doa */
	FL fl_a_Ay,													/* [in]	  $$$ 2013.09.08-2  */
	S4 s4_a_wall_bin,											/* [in]	  $$$ 2013.09.04-1 */
	S4 s4_a_exceptional_bin,									/* [in] estimated bin of road refrection */
	S4 s4_a_flg_updn,											/* [in] s4_a_flg_updn */
	FL afl_a_peak_and_doa[COMMON_PEAKBUFF_SIZE_FM][2][2],		/* [in / out] */
	FL fl_a_installed_angle										/* _20140108_1 */
);


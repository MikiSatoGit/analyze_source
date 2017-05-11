/****************************************************************************/
/* ファイル名	: init_CVW.c												*/
/*--------------------------------------------------------------------------*/
/* モジュール名	: BSM初期化モジュール										*/
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
/*  t300 リファクタリング													*/
/*	t02					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替対応															*/
/*	t03					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 仕様確認項目対応												*/
/*	t04					15.02.26			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 int→S4,float→FLに変更,ワーニング対応						*/
/*	t05					15.02.27			走安技2 1技室 G.Jomori			*/
/*	BSM AS巻替 インデント修正 //コメント変更 引数名変更(OBJ変更なし)		*/
/*	t07					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応(DR実施分)												*/
/*	t08					15.08.06			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 スタックオーバー対策									*/
/*	t09					15.08.19			走安技2 1技室 G.Jomori			*/
/*	BSM 認識巻替対応 一致確認中に発見したバグ修正							*/
/*	t10					15.08.31			走安技2 1技室 G.Jomori			*/
/*	仕様確認No1501,1504対応													*/
/*	t11					15.08.31			走安技2 1技室 M.Tanaka			*/
/*	残課題No.849対応(暗黙のキャストを修正)									*/
/*	t12					15.11.17			走安技2 1技室 G.Jomori			*/
/*	BSM CV対応																*/
/*	t13					15.11.20			走安技2 1技室 G.Jomori			*/
/*	読み合わせ指摘事項対応(OBJ変更なし)										*/
/*	t14					16.03.01			走安技2 1技室 G.Jomori			*/
/*	010B BSM CV-R仕様対応													*/
/*	t15					16.03.30			走安技2 1技室 G.Jomori			*/
/*	残課題No1030対応(OBJ変更なし)											*/
/*	t16					16.04.12			走安技2 1技室 G.Jomori			*/
/*	QAC 指摘対応(OBJ変更なし)												*/
/*	t17					16.06.03			走安技2 1技室 Y.Hosoi			*/
/*	残課題No202対応															*/
/*	t18					16.06.17			走安技2 1技室 Y.Hosoi			*/
/*	QAC指摘事項修正 OBJ変更なし												*/
/*	p00					16.07.06			走安技2 1技室 Y.Nishioka		*/
/*	010B 1A納入のためP化を実施												*/
/*	t21					16.07.18			走安技2 1技室 G.Jomori			*/
/*	291B開発用ソフトに010Bソフトをマージ(010B 1Aをベースに0024_t822マージ)	*/
/*	t23					16.08.22			走安技2 1技室 G.Jomori			*/
/*	残課題No1411,1412,1413対応(S4,FL,VDに変更 OBJ変更なし)					*/
/*  p02                 16.12.06            走安技2 1技室 H.Nakamichi       */
/*  291B 1A納入のためP化を実施                                              */
/****************************************************************************/
#include "../inc_bsm.h"

#include "init_cvw.h"
#include "../bsm_main.h"

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
static U1 u1_get_vy_c2(FL fl_a_Ryobs);

VD fn_init(
	NORMAL_BSM *pst_a_normal,
	S4 s4_a_data_len
)
{
	S4 s4_t_lp_i;
	
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_data_len; s4_t_lp_i++) {

		pst_a_normal[s4_t_lp_i].s4_bin_up = 0;
		pst_a_normal[s4_t_lp_i].s4_bin_dn = 0;

		pst_a_normal[s4_t_lp_i].s4_bin_up_music = 0;
		pst_a_normal[s4_t_lp_i].s4_bin_dn_music = 0;

		pst_a_normal[s4_t_lp_i].s4_bin_up_pred = 0;
		pst_a_normal[s4_t_lp_i].s4_bin_dn_pred = 0;

		pst_a_normal[s4_t_lp_i].s4_bin_up_music_pred = 0;
		pst_a_normal[s4_t_lp_i].s4_bin_dn_music_pred = 0;

		pst_a_normal[s4_t_lp_i].s4_flg_stop = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_track = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_lost = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_new = 0;
		pst_a_normal[s4_t_lp_i].s4_ctr_sot_cut = 0;

		pst_a_normal[s4_t_lp_i].s4_ID_num = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_used = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_dc = 0;

		pst_a_normal[s4_t_lp_i].s4_flg_single_peak_up = 0;
		pst_a_normal[s4_t_lp_i].u4_ctr_fa = 0;

		pst_a_normal[s4_t_lp_i].s4_flg_reliable = 0;
		pst_a_normal[s4_t_lp_i].s4_ctr_tos = 0;

		pst_a_normal[s4_t_lp_i].s4_flg_heiso_up = 0;
		pst_a_normal[s4_t_lp_i].s4_flg_heiso_dn = 0;

		pst_a_normal[s4_t_lp_i].s4_tracked = 0;	/* $$$ 2013.1Q NORMAL_BSM情報に履歴接続回数を追加 */

		/*****************************************************/
		pst_a_normal[s4_t_lp_i].fl_power_up = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_power_dn = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_power_up_music = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_power_dn_music = 0.0F;

		
		pst_a_normal[s4_t_lp_i].fl_theta_up = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_theta_dn = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_theta_up_pred = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_theta_dn_pred = 0.0F;
	
		pst_a_normal[s4_t_lp_i].fl_Robs = CFL_UNKNOWN_VALUE;
		pst_a_normal[s4_t_lp_i].fl_Robs_pred = CFL_UNKNOWN_VALUE;

		pst_a_normal[s4_t_lp_i].fl_Rxobs = CFL_UNKNOWN_VALUE;
		pst_a_normal[s4_t_lp_i].fl_Ryobs = CFL_UNKNOWN_VALUE;

		pst_a_normal[s4_t_lp_i].fl_Rxfil = CFL_UNKNOWN_VALUE;
		pst_a_normal[s4_t_lp_i].fl_Ryfil = CFL_UNKNOWN_VALUE;

		pst_a_normal[s4_t_lp_i].fl_Rxpred = CFL_UNKNOWN_VALUE;
		pst_a_normal[s4_t_lp_i].fl_Rypred = CFL_UNKNOWN_VALUE;

		pst_a_normal[s4_t_lp_i].fl_Vobs = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_Vobs_pred = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_Vxobs = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_Vyobs = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_Vxfil = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_Vyfil = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_Vxpred = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_Vypred = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_Axfil = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_Ayfil = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_prob = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_track_prob = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_doa_up_interpolate = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_doa_dn_interpolate = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_doa_up_interpolate_pred = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_doa_dn_interpolate_pred = 0.0F;

		pst_a_normal[s4_t_lp_i].fl_bin_up_interpolate = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_bin_dn_interpolate = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_bin_up_interpolate_pred = 0.0F;
		pst_a_normal[s4_t_lp_i].fl_bin_dn_interpolate_pred = 0.0F;
	}

	return;

}

//#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161209_BTT_ATD_TRACKING)
VD fn_init_btt(
	NORMAL_BSM pst_a_normal_total[BTT_OBJ_HISTORY_CYCLE][TRAILER_BUFFSIZE],
	S4 pst_a_normal_num[BTT_OBJ_HISTORY_CYCLE],
	S4 s4_a_data_len,
	S4 s4_a_cycle
)
{
	S4 s4_t_lp_j;

	for (s4_t_lp_j = 0; s4_t_lp_j < s4_a_cycle; s4_t_lp_j++) {
		pst_a_normal_num[s4_t_lp_j] = (S4)0;
		fn_init(pst_a_normal_total[s4_t_lp_j], TRAILER_BUFFSIZE);
	}

	return;
}
//#endif

/*******************入力値***********************/

/*******************データ移動***********************/
VD fn_move(
	NORMAL_BSM *pst_a_normal_out,					/*  [out] */
	const NORMAL_BSM *pst_a_normal_in,				/*  [in] */
	S4 s4_a_data_len								/*  [in] */
)
{
	S4 s4_t_lp_i;

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_data_len; s4_t_lp_i++) {
		pst_a_normal_out[s4_t_lp_i].s4_bin_up					= pst_a_normal_in[s4_t_lp_i].s4_bin_up;
		pst_a_normal_out[s4_t_lp_i].s4_bin_dn					= pst_a_normal_in[s4_t_lp_i].s4_bin_dn;

		pst_a_normal_out[s4_t_lp_i].s4_bin_up_music				= pst_a_normal_in[s4_t_lp_i].s4_bin_up_music;
		pst_a_normal_out[s4_t_lp_i].s4_bin_dn_music				= pst_a_normal_in[s4_t_lp_i].s4_bin_dn_music;

		pst_a_normal_out[s4_t_lp_i].s4_bin_up_pred				= pst_a_normal_in[s4_t_lp_i].s4_bin_up_pred;
		pst_a_normal_out[s4_t_lp_i].s4_bin_dn_pred				= pst_a_normal_in[s4_t_lp_i].s4_bin_dn_pred;

		pst_a_normal_out[s4_t_lp_i].s4_bin_up_music_pred		= pst_a_normal_in[s4_t_lp_i].s4_bin_up_music_pred;
		pst_a_normal_out[s4_t_lp_i].s4_bin_dn_music_pred		= pst_a_normal_in[s4_t_lp_i].s4_bin_dn_music_pred;	

		pst_a_normal_out[s4_t_lp_i].s4_flg_stop					= pst_a_normal_in[s4_t_lp_i].s4_flg_stop;
		pst_a_normal_out[s4_t_lp_i].s4_flg_track				= pst_a_normal_in[s4_t_lp_i].s4_flg_track;
		pst_a_normal_out[s4_t_lp_i].s4_flg_lost					= pst_a_normal_in[s4_t_lp_i].s4_flg_lost;
		pst_a_normal_out[s4_t_lp_i].s4_flg_new					= pst_a_normal_in[s4_t_lp_i].s4_flg_new;
		pst_a_normal_out[s4_t_lp_i].s4_ctr_sot_cut				= pst_a_normal_in[s4_t_lp_i].s4_ctr_sot_cut;

		pst_a_normal_out[s4_t_lp_i].s4_ID_num					= pst_a_normal_in[s4_t_lp_i].s4_ID_num;
		pst_a_normal_out[s4_t_lp_i].s4_flg_used					= pst_a_normal_in[s4_t_lp_i].s4_flg_used;
		pst_a_normal_out[s4_t_lp_i].s4_flg_dc					= pst_a_normal_in[s4_t_lp_i].s4_flg_dc;

		pst_a_normal_out[s4_t_lp_i].s4_flg_single_peak_up		= pst_a_normal_in[s4_t_lp_i].s4_flg_single_peak_up;
		pst_a_normal_out[s4_t_lp_i].u4_ctr_fa					= pst_a_normal_in[s4_t_lp_i].u4_ctr_fa;

		pst_a_normal_out[s4_t_lp_i].s4_flg_reliable				= pst_a_normal_in[s4_t_lp_i].s4_flg_reliable;
		pst_a_normal_out[s4_t_lp_i].s4_ctr_tos					= pst_a_normal_in[s4_t_lp_i].s4_ctr_tos;

		pst_a_normal_out[s4_t_lp_i].s4_flg_heiso_up				= pst_a_normal_in[s4_t_lp_i].s4_flg_heiso_up;
		pst_a_normal_out[s4_t_lp_i].s4_flg_heiso_dn				= pst_a_normal_in[s4_t_lp_i].s4_flg_heiso_dn;

		pst_a_normal_out[s4_t_lp_i].s4_tracked					= pst_a_normal_in[s4_t_lp_i].s4_tracked;	/* $$$ 2013.1Q NORMAL_BSM情報に履歴接続回数を追加 */

		/*****************************************************/
		pst_a_normal_out[s4_t_lp_i].fl_power_up					= pst_a_normal_in[s4_t_lp_i].fl_power_up;
		pst_a_normal_out[s4_t_lp_i].fl_power_dn					= pst_a_normal_in[s4_t_lp_i].fl_power_dn;

		pst_a_normal_out[s4_t_lp_i].fl_power_up_music			= pst_a_normal_in[s4_t_lp_i].fl_power_up_music;
		pst_a_normal_out[s4_t_lp_i].fl_power_dn_music			= pst_a_normal_in[s4_t_lp_i].fl_power_dn_music;

		pst_a_normal_out[s4_t_lp_i].fl_theta_up					= pst_a_normal_in[s4_t_lp_i].fl_theta_up;
		pst_a_normal_out[s4_t_lp_i].fl_theta_dn					= pst_a_normal_in[s4_t_lp_i].fl_theta_dn;

		pst_a_normal_out[s4_t_lp_i].fl_theta_up_pred			= pst_a_normal_in[s4_t_lp_i].fl_theta_up_pred;
		pst_a_normal_out[s4_t_lp_i].fl_theta_dn_pred			= pst_a_normal_in[s4_t_lp_i].fl_theta_dn_pred;

		pst_a_normal_out[s4_t_lp_i].fl_Robs						= pst_a_normal_in[s4_t_lp_i].fl_Robs;
		pst_a_normal_out[s4_t_lp_i].fl_Robs_pred				= pst_a_normal_in[s4_t_lp_i].fl_Robs_pred;

		pst_a_normal_out[s4_t_lp_i].fl_Rxobs					= pst_a_normal_in[s4_t_lp_i].fl_Rxobs;
		pst_a_normal_out[s4_t_lp_i].fl_Ryobs					= pst_a_normal_in[s4_t_lp_i].fl_Ryobs;

		pst_a_normal_out[s4_t_lp_i].fl_Rxfil					= pst_a_normal_in[s4_t_lp_i].fl_Rxfil;
		pst_a_normal_out[s4_t_lp_i].fl_Ryfil					= pst_a_normal_in[s4_t_lp_i].fl_Ryfil;	
		
		pst_a_normal_out[s4_t_lp_i].fl_Rxpred					= pst_a_normal_in[s4_t_lp_i].fl_Rxpred;
		pst_a_normal_out[s4_t_lp_i].fl_Rypred					= pst_a_normal_in[s4_t_lp_i].fl_Rypred;

		pst_a_normal_out[s4_t_lp_i].fl_Vobs						= pst_a_normal_in[s4_t_lp_i].fl_Vobs;
		pst_a_normal_out[s4_t_lp_i].fl_Vobs_pred				= pst_a_normal_in[s4_t_lp_i].fl_Vobs_pred;

		pst_a_normal_out[s4_t_lp_i].fl_Vxobs					= pst_a_normal_in[s4_t_lp_i].fl_Vxobs;
		pst_a_normal_out[s4_t_lp_i].fl_Vyobs					= pst_a_normal_in[s4_t_lp_i].fl_Vyobs;

		pst_a_normal_out[s4_t_lp_i].fl_Vxfil					= pst_a_normal_in[s4_t_lp_i].fl_Vxfil;
		pst_a_normal_out[s4_t_lp_i].fl_Vyfil					= pst_a_normal_in[s4_t_lp_i].fl_Vyfil;

		pst_a_normal_out[s4_t_lp_i].fl_Vxpred					= pst_a_normal_in[s4_t_lp_i].fl_Vxpred;
		pst_a_normal_out[s4_t_lp_i].fl_Vypred					= pst_a_normal_in[s4_t_lp_i].fl_Vypred;

		pst_a_normal_out[s4_t_lp_i].fl_Axfil					= pst_a_normal_in[s4_t_lp_i].fl_Axfil;	
		pst_a_normal_out[s4_t_lp_i].fl_Ayfil					= pst_a_normal_in[s4_t_lp_i].fl_Ayfil;

		pst_a_normal_out[s4_t_lp_i].fl_prob						= pst_a_normal_in[s4_t_lp_i].fl_prob;	
		pst_a_normal_out[s4_t_lp_i].fl_track_prob				= pst_a_normal_in[s4_t_lp_i].fl_track_prob;

		pst_a_normal_out[s4_t_lp_i].fl_doa_up_interpolate		= pst_a_normal_in[s4_t_lp_i].fl_doa_up_interpolate;
		pst_a_normal_out[s4_t_lp_i].fl_doa_dn_interpolate		= pst_a_normal_in[s4_t_lp_i].fl_doa_dn_interpolate;
		pst_a_normal_out[s4_t_lp_i].fl_doa_up_interpolate_pred	= pst_a_normal_in[s4_t_lp_i].fl_doa_up_interpolate_pred;
		pst_a_normal_out[s4_t_lp_i].fl_doa_dn_interpolate_pred	= pst_a_normal_in[s4_t_lp_i].fl_doa_dn_interpolate_pred;

		pst_a_normal_out[s4_t_lp_i].fl_bin_up_interpolate		= pst_a_normal_in[s4_t_lp_i].fl_bin_up_interpolate;
		pst_a_normal_out[s4_t_lp_i].fl_bin_dn_interpolate		= pst_a_normal_in[s4_t_lp_i].fl_bin_dn_interpolate;
		pst_a_normal_out[s4_t_lp_i].fl_bin_up_interpolate_pred	= pst_a_normal_in[s4_t_lp_i].fl_bin_up_interpolate_pred;
		pst_a_normal_out[s4_t_lp_i].fl_bin_dn_interpolate_pred	= pst_a_normal_in[s4_t_lp_i].fl_bin_dn_interpolate_pred;
	}

	return;

}

/* initialize wall target data */
/* @param :see below */
VD fn_initialize_wall_data(
	NORMAL_BSM ast_a_normal_wall[1]			/* [in / out] NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;
	for (s4_t_lp_i = 0; s4_t_lp_i < 1; s4_t_lp_i++) {
		fn_init(&ast_a_normal_wall[s4_t_lp_i], 1);
		ast_a_normal_wall[s4_t_lp_i].fl_Robs = WALL_MAX;
		ast_a_normal_wall[s4_t_lp_i].fl_Robs_pred = WALL_MAX;
		ast_a_normal_wall[s4_t_lp_i].fl_Rxobs = WALL_MAX;
		ast_a_normal_wall[s4_t_lp_i].fl_Ryobs = 0.0F;
		ast_a_normal_wall[s4_t_lp_i].fl_Rxfil = WALL_MAX;
		ast_a_normal_wall[s4_t_lp_i].fl_Ryfil = 0.0F;
		ast_a_normal_wall[s4_t_lp_i].fl_Rxpred = WALL_MAX;
		ast_a_normal_wall[s4_t_lp_i].fl_Rypred = 0.0F;
	}

	return;

}

/*******************データ追加***********************/

VD fn_sort_normal(
	NORMAL_BSM ast_a_normal[NORMAL_BUFFSIZE]		/*  [in/out] */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	S4 s4_t_count1 = 0;
	S4 s4_t_count2 = 0;

	NORMAL_BSM ast_t_buf_normal[NORMAL_BUFFSIZE];

	fn_init(ast_t_buf_normal, NORMAL_BUFFSIZE);

	fn_move(ast_t_buf_normal, ast_a_normal, NORMAL_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < NORMAL_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < NORMAL_BUFFSIZE; s4_t_lp_j++) {
			if (s4_t_lp_i < s4_t_lp_j) {
				if (	/* 中身が入っているかどうかの確認用 */
					(ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE)
					 && (ast_a_normal[s4_t_lp_j].fl_Robs != CFL_UNKNOWN_VALUE)
				) {
					if (ast_t_buf_normal[s4_t_lp_i].fl_Ryfil < ast_t_buf_normal[s4_t_lp_j].fl_Ryfil) {
						ast_t_buf_normal[s4_t_lp_i] = ast_a_normal[s4_t_lp_j];
						ast_t_buf_normal[s4_t_lp_j] = ast_a_normal[s4_t_lp_i];
						ast_a_normal[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
						ast_a_normal[s4_t_lp_j] = ast_t_buf_normal[s4_t_lp_j];
					}
				}
			}
		}
	}

	/* 補助を後ろの方に置く(前から順にサーチするときに優先順位が下がるように) */
	fn_init(ast_t_buf_normal, NORMAL_BUFFSIZE);
	s4_t_count1 = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < NORMAL_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_normal[s4_t_lp_i].s4_flg_dc >= OBJECT_TYPE_2F) {		/* 4:補助 5:追越 */
			ast_t_buf_normal[s4_t_count1] = ast_a_normal[s4_t_lp_i];
			fn_init(&ast_a_normal[s4_t_lp_i], 1);
			s4_t_count1++;
		}
	}
	s4_t_count2 = s4_trim_normal(ast_a_normal);
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_count1; s4_t_lp_i++) {
		ast_a_normal[s4_t_count2 + s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
	}

	return;

}

VD fn_sort_normal_by_power(
	NORMAL_BSM ast_a_normal[NORMAL_BUFFSIZE]		/* [in/out] */
)
{
	S4 i, j;
	S4 tmp_count1 = 0;
	S4 tmp_count2 = 0;
	NORMAL_BSM tmp_normal_buff[NORMAL_BUFFSIZE];
	fn_init(tmp_normal_buff, NORMAL_BUFFSIZE);
	fn_move( tmp_normal_buff, ast_a_normal, NORMAL_BUFFSIZE);
	for( i = 0; i < NORMAL_BUFFSIZE; i++ )
	{
		for( j = 0; j < NORMAL_BUFFSIZE; j++ )
		{
			if(i<j)												/* COND.d1 */
			{
				/* 中身が入っているかどうかの確認用 */
				if ((ast_a_normal[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND.d2 */
				&&  (ast_a_normal[j].fl_Robs != CFL_UNKNOWN_VALUE)) {			/* COND.d3 */
					if( (tmp_normal_buff[i].fl_power_up + tmp_normal_buff[i].fl_power_dn) 
						< (tmp_normal_buff[j].fl_power_up + tmp_normal_buff[j].fl_power_dn)	/* COND.d4 */
					)
					{
						tmp_normal_buff[i] = ast_a_normal[j];
						tmp_normal_buff[j] = ast_a_normal[i];
						ast_a_normal[i] = tmp_normal_buff[i];
						ast_a_normal[j] = tmp_normal_buff[j];
					}
				}
			}
		}
	}

	/* 補助を後ろの方に置く(前から順にサーチするときに優先順位が下がるように) */
	fn_init(tmp_normal_buff, NORMAL_BUFFSIZE);
	tmp_count1 = 0;
	for( i = 0; i < NORMAL_BUFFSIZE; i++ )
	{
		if( ast_a_normal[i].s4_flg_dc >= OBJECT_TYPE_2F)				/* COND.j5 */
		{
			tmp_normal_buff[tmp_count1] = ast_a_normal[i];
			fn_init(&ast_a_normal[i], 1);
			tmp_count1++;
		}
	}
	tmp_count2 = s4_trim_normal(ast_a_normal);
	for( i = 0; i < tmp_count1; i++ )
	{
		ast_a_normal[tmp_count2+i] = tmp_normal_buff[i];
	}
}

VD fn_sort_peak_by_power(
	const S4 as4_a_peak_bin[PEAK_BUFFSIZE],					/* [in] */
	const FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],			/* [in] */
	const FL afl_a_peak_power[PEAK_BUFFSIZE],				/* [in] */
	S4 as4_a_peak_bin_ordinary[ORDINARY_BUFFSIZE],			/* [out] */
	FL afl_a_peak_bin_intpl_ordinary[ORDINARY_BUFFSIZE],	/* [out] */
	FL afl_a_peak_power_ordinary[ORDINARY_BUFFSIZE]			/* [out] */
)
{
	U2 u2_t_lp_sorted_num;			/* 選択ソート：ソート済みの数 */
	U2 u2_t_lp_data;
	U2 u2_t_lp_search_index;		/* 選択ソート：検索中のインデックス */
	U2 u2_t_max_index;				/* 選択ソート：検索中の中で最大値となるインデックス */
	S4 s4_t_max_bin_buf;			/* 選択ソート：データ入れ替え用のバッファ */
	FL fl_t_max_bin_intpl_buf;		/* 選択ソート：データ入れ替え用のバッファ */
	FL fl_t_max_power_buf;			/* 選択ソート：データ入れ替え用のバッファ */
	S4 as4_t_peak_bin_sorted[PEAK_BUFFSIZE];
	FL afl_t_peak_bin_intpl_sorted[PEAK_BUFFSIZE];
	FL afl_t_peak_power_sorted[PEAK_BUFFSIZE];
	
	u2_t_max_index = (U2)0;
	s4_t_max_bin_buf = (S4)0;
	fl_t_max_bin_intpl_buf = (FL)0.0F;
	fl_t_max_power_buf = (FL)0.0F;
	
	for (u2_t_lp_data = (U2)0; u2_t_lp_data < PEAK_BUFFSIZE; u2_t_lp_data++ ) {
		/*4) proc.1 */
		as4_t_peak_bin_sorted[u2_t_lp_data] = as4_a_peak_bin[u2_t_lp_data];
		afl_t_peak_bin_intpl_sorted[u2_t_lp_data] = afl_a_peak_bin_intpl[u2_t_lp_data];
		afl_t_peak_power_sorted[u2_t_lp_data] = afl_a_peak_power[u2_t_lp_data];
	}
	
	/* 選択ソート実施 */
	for (u2_t_lp_sorted_num = (U2)0; u2_t_lp_sorted_num < ORDINARY_BUFFSIZE; u2_t_lp_sorted_num++) {
		u2_t_max_index = u2_t_lp_sorted_num;
		for (u2_t_lp_search_index = (u2_t_lp_sorted_num + (U2)1); u2_t_lp_search_index < PEAK_BUFFSIZE; u2_t_lp_search_index++) {
			if (afl_t_peak_power_sorted[u2_t_lp_search_index] > afl_t_peak_power_sorted[u2_t_max_index]) {
				u2_t_max_index = u2_t_lp_search_index;
			}
		}
		
		s4_t_max_bin_buf = as4_t_peak_bin_sorted[u2_t_max_index];
		as4_t_peak_bin_sorted[u2_t_max_index] = as4_t_peak_bin_sorted[u2_t_lp_sorted_num];
		as4_t_peak_bin_sorted[u2_t_lp_sorted_num] = s4_t_max_bin_buf;
		
		fl_t_max_bin_intpl_buf = afl_t_peak_bin_intpl_sorted[u2_t_max_index];
		afl_t_peak_bin_intpl_sorted[u2_t_max_index] = afl_t_peak_bin_intpl_sorted[u2_t_lp_sorted_num];
		afl_t_peak_bin_intpl_sorted[u2_t_lp_sorted_num] = fl_t_max_bin_intpl_buf;
		
		fl_t_max_power_buf = afl_t_peak_power_sorted[u2_t_max_index];
		afl_t_peak_power_sorted[u2_t_max_index] = afl_t_peak_power_sorted[u2_t_lp_sorted_num];
		afl_t_peak_power_sorted[u2_t_lp_sorted_num] = fl_t_max_power_buf;
	}
	
	for (u2_t_lp_data = (U2)0; u2_t_lp_data < ORDINARY_BUFFSIZE; u2_t_lp_data++ ) {
		as4_a_peak_bin_ordinary[u2_t_lp_data] = as4_t_peak_bin_sorted[u2_t_lp_data];
		afl_a_peak_bin_intpl_ordinary[u2_t_lp_data] = afl_t_peak_bin_intpl_sorted[u2_t_lp_data];
		afl_a_peak_power_ordinary[u2_t_lp_data] = afl_t_peak_power_sorted[u2_t_lp_data];
	}
	
	return;
}


//#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
VD fn_sort_peak_by_power_trailer(
	const S4 as4_a_peak_bin[PEAK_BUFFSIZE],						/* [in] */
	const FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],					/* [in] */
	const FL afl_a_peak_power[PEAK_BUFFSIZE],						/* [in] */
	S4 as4_a_peak_bin_trailer[TRAILER_BUFFSIZE],			/* [out] */
	FL afl_a_peak_bin_intpl_trailer[TRAILER_BUFFSIZE],	/* [out] */
	FL afl_a_peak_power_trailer[TRAILER_BUFFSIZE]			/* [out] */
)
{
	U2 u2_t_lp_sorted_num;			/* 選択ソート：ソート済みの数 */
	U2 u2_t_lp_data;
	U2 u2_t_lp_search_index;		/* 選択ソート：検索中のインデックス */
	U2 u2_t_max_index;				/* 選択ソート：検索中の中で最大値となるインデックス */
	S4 s4_t_max_bin_buf;			/* 選択ソート：データ入れ替え用のバッファ */
	FL fl_t_max_bin_intpl_buf;		/* 選択ソート：データ入れ替え用のバッファ */
	FL fl_t_max_power_buf;			/* 選択ソート：データ入れ替え用のバッファ */
	S4 as4_t_peak_bin_sorted[PEAK_BUFFSIZE];
	FL afl_t_peak_bin_intpl_sorted[PEAK_BUFFSIZE];
	FL afl_t_peak_power_sorted[PEAK_BUFFSIZE];
	
	u2_t_max_index = (U2)0;
	s4_t_max_bin_buf = (S4)0;
	fl_t_max_bin_intpl_buf = (FL)0.0F;
	fl_t_max_power_buf = (FL)0.0F;
	
	for (u2_t_lp_data = (U2)0; u2_t_lp_data < PEAK_BUFFSIZE; u2_t_lp_data++ ) {
		/*4) proc.1 */
		as4_t_peak_bin_sorted[u2_t_lp_data] = as4_a_peak_bin[u2_t_lp_data];
		afl_t_peak_bin_intpl_sorted[u2_t_lp_data] = afl_a_peak_bin_intpl[u2_t_lp_data];
		afl_t_peak_power_sorted[u2_t_lp_data] = afl_a_peak_power[u2_t_lp_data];
	}
	
	/* 選択ソート実施 */
	for (u2_t_lp_sorted_num = (U2)0; u2_t_lp_sorted_num < TRAILER_BUFFSIZE; u2_t_lp_sorted_num++) {
		u2_t_max_index = u2_t_lp_sorted_num;
		for (u2_t_lp_search_index = (u2_t_lp_sorted_num + (U2)1); u2_t_lp_search_index < PEAK_BUFFSIZE; u2_t_lp_search_index++) {
			if (afl_t_peak_power_sorted[u2_t_lp_search_index] > afl_t_peak_power_sorted[u2_t_max_index]) {
				u2_t_max_index = u2_t_lp_search_index;
			}
		}

		s4_t_max_bin_buf = as4_t_peak_bin_sorted[u2_t_max_index];
		as4_t_peak_bin_sorted[u2_t_max_index] = as4_t_peak_bin_sorted[u2_t_lp_sorted_num];
		as4_t_peak_bin_sorted[u2_t_lp_sorted_num] = s4_t_max_bin_buf;
		
		fl_t_max_bin_intpl_buf = afl_t_peak_bin_intpl_sorted[u2_t_max_index];
		afl_t_peak_bin_intpl_sorted[u2_t_max_index] = afl_t_peak_bin_intpl_sorted[u2_t_lp_sorted_num];
		afl_t_peak_bin_intpl_sorted[u2_t_lp_sorted_num] = fl_t_max_bin_intpl_buf;
		
		fl_t_max_power_buf = afl_t_peak_power_sorted[u2_t_max_index];
		afl_t_peak_power_sorted[u2_t_max_index] = afl_t_peak_power_sorted[u2_t_lp_sorted_num];
		afl_t_peak_power_sorted[u2_t_lp_sorted_num] = fl_t_max_power_buf;
	}
	
	for (u2_t_lp_data = (U2)0; u2_t_lp_data < TRAILER_BUFFSIZE; u2_t_lp_data++ ) {
		as4_a_peak_bin_trailer[u2_t_lp_data] = as4_t_peak_bin_sorted[u2_t_lp_data];
		afl_a_peak_bin_intpl_trailer[u2_t_lp_data] = afl_t_peak_bin_intpl_sorted[u2_t_lp_data];
		afl_a_peak_power_trailer[u2_t_lp_data] = afl_t_peak_power_sorted[u2_t_lp_data];
	}
	
	return;
}
//#endif

VD fn_sort_target(
	NORMAL_BSM ast_a_target[TARGET_BUFFSIZE]		/*  [in/out] */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	S4 s4_t_count1 = 0;
	S4 s4_t_count2 = 0;

	NORMAL_BSM ast_t_buf_normal[TARGET_BUFFSIZE];

	fn_init(ast_t_buf_normal, TARGET_BUFFSIZE);

	fn_move(ast_t_buf_normal, ast_a_target, TARGET_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < TARGET_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < TARGET_BUFFSIZE; s4_t_lp_j++) {
			if (s4_t_lp_i < s4_t_lp_j) {
				if (	/* 中身が入っているかどうかの確認用 */
					(ast_a_target[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE)
				 	&& (ast_a_target[s4_t_lp_j].fl_Robs != CFL_UNKNOWN_VALUE)
				) {
					if (ast_t_buf_normal[s4_t_lp_i].fl_Ryfil < ast_t_buf_normal[s4_t_lp_j].fl_Ryfil) {
						ast_t_buf_normal[s4_t_lp_i] = ast_a_target[s4_t_lp_j];
						ast_t_buf_normal[s4_t_lp_j] = ast_a_target[s4_t_lp_i];
						ast_a_target[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
						ast_a_target[s4_t_lp_j] = ast_t_buf_normal[s4_t_lp_j];
					}
				}
			}
		}
	}

	/* 補助を後ろの方に置く(前から順にサーチするときに優先順位が下がるように) */
	fn_init(ast_t_buf_normal, TARGET_BUFFSIZE);
	s4_t_count1 = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < TARGET_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_target[s4_t_lp_i].s4_flg_dc >= OBJECT_TYPE_2F) {		/* 4:補助 5:追越 */
			ast_t_buf_normal[s4_t_count1] = ast_a_target[s4_t_lp_i];
			fn_init(&ast_a_target[s4_t_lp_i], 1);
			s4_t_count1++;
		}
	}
	s4_t_count2 = s4_trim_target(ast_a_target);
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_count1; s4_t_lp_i++) {
		ast_a_target[s4_t_count2 + s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
	}

	return;

}

S4 s4_trim_normal(
	NORMAL_BSM ast_a_normal[NORMAL_BUFFSIZE]							/*  [in/out] NORMAL_BSM structure */
)
{
	S4 s4_t_iret = 0;
	S4 s4_t_lp_i;

	NORMAL_BSM ast_t_buf_normal[NORMAL_BUFFSIZE];

	fn_init(ast_t_buf_normal, NORMAL_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < NORMAL_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_normal[s4_t_lp_i];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_normal, NORMAL_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iret; s4_t_lp_i++) {
		ast_a_normal[s4_t_lp_i] =	ast_t_buf_normal[s4_t_lp_i];
	}

	return (s4_t_iret);

}

/********************************************************************************************/
/* 関数名		: s4_trim_prior																*/
/*------------------------------------------------------------------------------------------*/
/* 機能			: 物標情報を前詰め(優先物標版)												*/
/*------------------------------------------------------------------------------------------*/
/* 引数			: ast_a_normal_prior[]					: 優先物標情報 [in/out]				*/
/* 戻り値		: s4_t_iret								: 優先物標個数						*/
/*------------------------------------------------------------------------------------------*/
/* グローバル変数アクセス																	*/
/* <input>  	: なし																		*/
/* <output>		: なし																		*/
/*------------------------------------------------------------------------------------------*/
/* 参照関数		: fn_init()																	*/
/*------------------------------------------------------------------------------------------*/
/* 対応仕様		: FS認識巻替時点では記載なし 												*/
/********************************************************************************************/
S4 s4_trim_prior(NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE])
{
	S4 s4_t_iret;
	S4 s4_t_lp_num_prior;
	NORMAL_BSM ast_t_buf_normal[PRIOR_BUFFSIZE];

	s4_t_iret = (S4)0;
	fn_init(ast_t_buf_normal, PRIOR_BUFFSIZE);

	for (s4_t_lp_num_prior = (S4)0; s4_t_lp_num_prior < PRIOR_BUFFSIZE; s4_t_lp_num_prior++) {
		if (ast_a_normal_prior[s4_t_lp_num_prior].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_normal_prior[s4_t_lp_num_prior];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_normal_prior, PRIOR_BUFFSIZE);

	for (s4_t_lp_num_prior = (S4)0; s4_t_lp_num_prior < s4_t_iret; s4_t_lp_num_prior++) {
		ast_a_normal_prior[s4_t_lp_num_prior] =	ast_t_buf_normal[s4_t_lp_num_prior];
	}

	return (s4_t_iret);

}

S4 s4_trim_ordinary(
	NORMAL_BSM ast_a_normal[ORDINARY_BUFFSIZE]							/*  [in/out] NORMAL_BSM structure */
)
{
	S4 s4_t_iret = 0;
	S4 s4_t_lp_i;

	NORMAL_BSM ast_t_buf_normal[ORDINARY_BUFFSIZE];

	fn_init(ast_t_buf_normal, ORDINARY_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < ORDINARY_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_normal[s4_t_lp_i];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_normal, ORDINARY_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iret; s4_t_lp_i++) {
		ast_a_normal[s4_t_lp_i] =	ast_t_buf_normal[s4_t_lp_i];
	}

	return (s4_t_iret);

}

//#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20170220_BTT_TRAILEROBJ_ERASE_OUTLIER)
S4 s4_trim_trailer(
	NORMAL_BSM ast_a_normal[TRAILER_BUFFSIZE]							/*  [in/out] NORMAL_BSM structure */
)
{
	S4 s4_t_iret = 0;
	S4 s4_t_lp_i;

	NORMAL_BSM ast_t_buf_normal[TRAILER_BUFFSIZE];

	fn_init(ast_t_buf_normal, TRAILER_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_normal[s4_t_lp_i];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_normal, TRAILER_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iret; s4_t_lp_i++) {
		ast_a_normal[s4_t_lp_i] =	ast_t_buf_normal[s4_t_lp_i];
	}

	return (s4_t_iret);

}
//#endif

S4 s4_trim_normal_2f(
	NORMAL_BSM ast_a_normal[AUX_BUFFSIZE]							/*  [in/out] NORMAL_BSM structure */
)
{
	S4 s4_t_iret = 0;
	S4 s4_t_lp_i;

	NORMAL_BSM ast_t_buf_normal[AUX_BUFFSIZE];

	fn_init(ast_t_buf_normal, AUX_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < AUX_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_normal[s4_t_lp_i];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_normal, AUX_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iret; s4_t_lp_i++) {
		ast_a_normal[s4_t_lp_i] =	ast_t_buf_normal[s4_t_lp_i];
	}

	return (s4_t_iret);

}

S4 s4_trim_target(
	NORMAL_BSM ast_a_target[TARGET_BUFFSIZE]							/*  [in/out] NORMAL_BSM structure */
)
{
	S4 s4_t_iret = 0;
	S4 s4_t_lp_i;

	NORMAL_BSM ast_t_buf_normal[TARGET_BUFFSIZE];

	fn_init(ast_t_buf_normal, TARGET_BUFFSIZE);
	for (s4_t_lp_i = 0; s4_t_lp_i < TARGET_BUFFSIZE; s4_t_lp_i++) {
		if (ast_a_target[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {	/*  fl_Robs */
			ast_t_buf_normal[s4_t_iret] = ast_a_target[s4_t_lp_i];
			s4_t_iret++;
		}
	}

	fn_init(ast_a_target, TARGET_BUFFSIZE);
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iret; s4_t_lp_i++) {
		ast_a_target[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
	}

	return (s4_t_iret);

}

/* initialize Tx data */
/* @param :see below */
VD fn_initialize_Tx_data(
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [in / out] S4 values of Tx structure */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]			/* [in / out] FL values of Tx structure */
)
{
	S4 s4_t_lp_i;
	for (s4_t_lp_i = 0; s4_t_lp_i < TARGET_BUFFSIZE; s4_t_lp_i++) {
		s4_initialize_specified_Tx_data(
			as4_a_Tx_int,
			afl_a_Tx_float,
			s4_t_lp_i
		);
	}

	return;

}



S4 s4_initialize_specified_Tx_data(
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [in / out] S4 values of Tx structure */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],		/* [in / out] FL values of Tx structure */
	S4 s4_t_index
)
{
	S4 s4_t_iRet = 0;
	S4 s4_t_lp_j;
	if ((s4_t_index < 0) || (s4_t_index > (S4)(TARGET_BUFFSIZE - 1))) {
		return (s4_t_iRet);
	}

	for (s4_t_lp_j = 0; s4_t_lp_j < NORM_INT; s4_t_lp_j++) {
		as4_a_Tx_int[s4_t_index][s4_t_lp_j] = 0;
	}
	for (s4_t_lp_j = 0; s4_t_lp_j < TGT_FLT; s4_t_lp_j++) {
		if ((s4_t_lp_j > 3) && (s4_t_lp_j < 11)) {
			afl_a_Tx_float[s4_t_index][s4_t_lp_j] = CFL_UNKNOWN_VALUE;
		} else {
			afl_a_Tx_float[s4_t_index][s4_t_lp_j] = 0.0F;
		}
	}
	s4_t_iRet = 1;

	return (s4_t_iRet);

}

S4 s4_trim_Tx_data(
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [in / out] S4 values of Tx structure */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]				/* [in / out] FL values of Tx structure */
)
{
	S4 s4_t_iRet = 0;
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	S4 as4_t_Tx_int[TARGET_BUFFSIZE][NORM_INT];
	FL afl_t_Tx_float[TARGET_BUFFSIZE][TGT_FLT];

	fn_initialize_Tx_data(
		as4_t_Tx_int,
		afl_t_Tx_float
	);

	for (s4_t_lp_i = 0; s4_t_lp_i < TARGET_BUFFSIZE; s4_t_lp_i++) {
		if (afl_a_Tx_float[s4_t_lp_i][4] != CFL_UNKNOWN_VALUE) {
			for (s4_t_lp_j = 0; s4_t_lp_j < NORM_INT; s4_t_lp_j++) {
				as4_t_Tx_int[s4_t_iRet][s4_t_lp_j] = as4_a_Tx_int[s4_t_lp_i][s4_t_lp_j];
			}
			for (s4_t_lp_j = 0; s4_t_lp_j < TGT_FLT; s4_t_lp_j++) {
				afl_t_Tx_float[s4_t_iRet][s4_t_lp_j] = afl_a_Tx_float[s4_t_lp_i][s4_t_lp_j];
			}
			s4_t_iRet++;
		}
	}

	fn_initialize_Tx_data(
		as4_a_Tx_int,
		afl_a_Tx_float
	);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_iRet; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < NORM_INT; s4_t_lp_j++) {
			as4_a_Tx_int[s4_t_lp_i][s4_t_lp_j] = as4_t_Tx_int[s4_t_lp_i][s4_t_lp_j];
		}
		for (s4_t_lp_j = 0; s4_t_lp_j < TGT_FLT; s4_t_lp_j++) {
			afl_a_Tx_float[s4_t_lp_i][s4_t_lp_j] = afl_t_Tx_float[s4_t_lp_i][s4_t_lp_j];
		}
	}

	return (s4_t_iRet);

}

/* set data to NORMAL_BSM structure */
/* @param :see below */
VD fn_set_normal_data(
	NORMAL_BSM *pst_a_normal_current,				/*  [in / out] */
	FL fl_a_peak_bin_intpl_up,							/*  [in] freq-bin of music peak (up) */
	FL fl_a_peak_bin_intpl_dn,							/*  [in] freq-bin of music peak (down) */
	FL fl_a_peak_doa_bin_intpl_up,						/*  [in] doa-bin of music peak (up) */
	FL fl_a_peak_doa_bin_intpl_dn,						/*  [in] doa-bin of music peak (down) */
	FL fl_a_peak_freq_power_up,						/*  [in] freq-power of music peak (up) */
	FL fl_a_peak_freq_power_dn,						/*  [in] freq-power of music peak (down) */
	FL fl_a_peak_doa_power_up,						/*  [in] doa-power of music peak (up)	$$$ 2013.09.18-0 */
	FL fl_a_peak_doa_power_dn,						/*  [in] doa-power of music peak (down)	$$$ 2013.09.18-0 */
	S4 s4_a_stationary_flg,							/*  [in] 停止物フラグ */
	S4 s4_a_single_peak_flg							/*  [in] 片ピークフラグ */
)
{
	/* freq. bin */
	pst_a_normal_current->s4_bin_up = (S4)(fl_a_peak_bin_intpl_up + (FL)0.5F);
	pst_a_normal_current->s4_bin_dn = (S4)(fl_a_peak_bin_intpl_dn + (FL)0.5F);
	pst_a_normal_current->fl_bin_up_interpolate = fl_a_peak_bin_intpl_up;
	pst_a_normal_current->fl_bin_dn_interpolate = fl_a_peak_bin_intpl_dn;

	/* freq. pow */
	pst_a_normal_current->fl_power_up = fl_a_peak_freq_power_up;
	pst_a_normal_current->fl_power_dn = fl_a_peak_freq_power_dn;

	/* doa bin */
	pst_a_normal_current->s4_bin_up_music = (S4)(fl_a_peak_doa_bin_intpl_up + (FL)0.5F);
	pst_a_normal_current->s4_bin_dn_music = (S4)(fl_a_peak_doa_bin_intpl_dn + (FL)0.5F);
	pst_a_normal_current->fl_doa_up_interpolate = fl_a_peak_doa_bin_intpl_up;
	pst_a_normal_current->fl_doa_dn_interpolate = fl_a_peak_doa_bin_intpl_dn;

	/* doa pow */
	pst_a_normal_current->fl_power_up_music = fl_a_peak_doa_power_up;
	pst_a_normal_current->fl_power_dn_music = fl_a_peak_doa_power_dn;

	/* direction [rad] */
	/* doa[bin] -> doa [rad] */
	pst_a_normal_current->fl_theta_up = fl_transform_doabin_to_rad_float(
		fl_a_peak_doa_bin_intpl_up,
		0
	);
	pst_a_normal_current->fl_theta_dn = fl_transform_doabin_to_rad_float(
		fl_a_peak_doa_bin_intpl_dn,
		1
	);
	/* distance [m] */
	pst_a_normal_current->fl_Robs = -RCOF * ((pst_a_normal_current->fl_bin_up_interpolate + pst_a_normal_current->fl_bin_dn_interpolate) - (FL)NB_FFT_PT);
										/*   =(s4_bin_up - s4_t_center_bin) + (s4_bin_dn - s4_t_center_bin) */
	/* X/Y distance [m] */
	pst_a_normal_current->fl_Rxobs
					 = (pst_a_normal_current->fl_Robs * (FL)fl_sin(0.50F * (pst_a_normal_current->fl_theta_up + pst_a_normal_current->fl_theta_dn))) + st_g_bsm_loop_data.afl_installed_angle[1];
	pst_a_normal_current->fl_Ryobs
					 = pst_a_normal_current->fl_Robs * (FL)fl_cos(0.50F * (pst_a_normal_current->fl_theta_up + pst_a_normal_current->fl_theta_dn));

	/* velocity [m/s] */
	pst_a_normal_current->fl_Vobs  = -VCOF * (pst_a_normal_current->fl_bin_up_interpolate - pst_a_normal_current->fl_bin_dn_interpolate);
										/*    = (s4_bin_up - s4_t_center_bin)-(s4_bin_dn - s4_t_center_bin) */

	/* X/Y velocity [m/s] */
	pst_a_normal_current->fl_Vxobs = 0.0F;	/* fl_Vxobs = 0.0F としておく */
	pst_a_normal_current->fl_Vyobs = fl_get_vy(
		pst_a_normal_current->fl_Vobs,
		(FL)fl_cos(0.50F * (pst_a_normal_current->fl_theta_up + pst_a_normal_current->fl_theta_dn)),
		pst_a_normal_current->fl_Ryobs,
		fl_g_v_self_bsm_for_base
	);
	/*  停止物判定 */
	pst_a_normal_current->s4_flg_stop = s4_a_stationary_flg;
	/*  片ピークフラグ */
	pst_a_normal_current->s4_flg_single_peak_up = s4_a_single_peak_flg;

	return;

}


/* convert estimated DOA to direction based on the car coordinate */
/* @return :direction [rad] */
/* @param :see below */
FL fl_transform_doabin_to_rad(
	S4 s4_a_angle_bin,				/*  [in] estimated DOA [bin] */
	S4 s4_a_flg_updn				/*  [in]	$$$ 2013.08.23-7 */
)
{
	FL fl_t_degree;
	fl_t_degree = (FL)(st_g_bsm_loop_data.afl_installed_angle[0] + (DOA_ANG_PER_BIN * (FL)s4_a_angle_bin) + DOA_BIN_START_ANG);

	return (-fl_t_degree * PI / 180.0F);		/*  [rad] */
}

FL fl_transform_doabin_to_rad_float(
	FL fl_a_angle,				/* [in] interpolated DOA */
	S4 s4_a_flg_updn			/* [in] */
)
{
	FL fl_t_degree;
	fl_t_degree = st_g_bsm_loop_data.afl_installed_angle[0] + (DOA_ANG_PER_BIN * fl_a_angle) + DOA_BIN_START_ANG;

	return (-fl_t_degree * PI / 180.0F);		/* [rad] */
}

/****************************************************************************/
/* 関数名		: fl_get_vy													*/
/*--------------------------------------------------------------------------*/
/* 機能			: Y方向相対速度[m/s]算出									*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_Vobs				: 物標情報の速度観測値Vobs [in][1m/s]*/
/*				: fl_a_cos_theta		: cos(tmp_angle) [in][LSBなし]		*/
/*				: fl_a_Ry				: 物標情報のY方向距離 [in][1m]		*/
/*				: fl_a_v_self			: 自車速 [in][1km/h]				*/
/* 戻り値		: fl_t_Vy				: Y方向相対速度 [1m/s]				*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-017								*/
/*				: (5)物標情報算出処理（低速 SoT）2)物標情報の算出 			*/
/*				: Y方向相対速度算出部分										*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
FL fl_get_vy(
	FL fl_a_Vobs,
	FL fl_a_cos_theta,		/* cos(tmp_angle)を引数として受け取るので注意 */
	FL fl_a_Ry,
	FL fl_a_v_self
)
{
	FL fl_t_Vy = 0.0F;
	U1 u1_t_jdg_c2_flg;

	/* 条件c2の判定関数コール 仕様書の記述より条件c2の定義部分にコンパイルスイッチが入るため、	*/
	/* 条件c2の判定用関数を作り、判定結果を条件確認箇所で使用する								*/
	/* 関数内ではグローバル変数は触らないので、このタイミングで関数コールしても問題ない			*/
	u1_t_jdg_c2_flg = u1_get_vy_c2(fl_a_Ry);

	if (
		(fl_abs(fl_a_Ry) < VY_CALC_BORDER_RY)
	&&  (fl_a_v_self < VY_CALC_BORDER_V)
	&&  (u1_t_jdg_c2_flg == CU1_TRUE)
	&&  (fl_a_cos_theta != (FL)0.0F)
	) {
		fl_t_Vy = fl_a_Vobs / fl_a_cos_theta;
	} else {
		fl_t_Vy = fl_a_Vobs;
	}

	/*  停滞防止 */
	if (fl_t_Vy == 0.0F) {
		fl_t_Vy = 0.1F;
	}
	if ( fl_a_Ry > 0.0F ) {
		fl_t_Vy = - fl_t_Vy;
	}
	return (fl_t_Vy);

}

/****************************************************************************/
/* 関数名		: u1_get_vy_c2												*/
/*--------------------------------------------------------------------------*/
/* 機能			: 物標情報の算出 相対速度算出部分の条件c2判定関数			*/
/*--------------------------------------------------------------------------*/
/* 引数			: fl_a_Ryobs				: Y方向距離 [in]				*/
/* 戻り値		: u1_t_jdg_c2_flag			: 条件c2の判定結果格納変数		*/
/*--------------------------------------------------------------------------*/
/* グローバル変数アクセス													*/
/* <input>		: なし														*/
/* <output>		: なし														*/
/*--------------------------------------------------------------------------*/
/* 対応仕様		: MWR-RECO-24G-BSM-RECOG-02-019(291BCV).pdf					*/
/*				: (5)物標情報算出処理（低速 SoT） 2)物標情報の算出の条件c2	*/
/*--------------------------------------------------------------------------*/
/* 作成者		:															*/
/****************************************************************************/
static U1 u1_get_vy_c2(FL fl_a_Ryobs)
{
	/* 条件c2が仕様上で搭載角度により分割されていること、							*/
	/* 判定文に直接コンパイルオプションを記述すると&&や||の対応が分かりにくくなり	*/
	/* 可読性が低下するため、条件判定用関数を作成しその結果を条件文に使用する		*/

	U1 u1_t_jdg_c2_flag;				/* 条件c2判定結果格納変数 */
	FL fl_t_ryobs_abs;					/* Y方向距離の絶対値 */

	/* FALSEで初期化 */
	u1_t_jdg_c2_flag = CU1_FALSE;

	fl_t_ryobs_abs = fl_abs(fl_a_Ryobs);

	/* 条件c2の判定 */
#if (BSM_OPTION_SW_RECOG_02 == TYPE_A)
	/* 搭載角度50degのとき */
	if (fl_t_ryobs_abs > (FL)EKF_RY_SIDE) {
		u1_t_jdg_c2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c2_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_02 == TYPE_B)
	/* 搭載角度20degのとき */
	if (fl_t_ryobs_abs > CFL_VY_CALC_BORDER_RY2) {
		u1_t_jdg_c2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c2_flag = CU1_FALSE;
	}
#else
	マクロ未定義の場合は、コンパイルエラーとする
#endif /* BSM_OPTION_SW_RECOG_02 */

	return u1_t_jdg_c2_flag;
}

/****************************************************************************/
/* �t�@�C����	: BSM_CONNECT_01.c											*/
/*--------------------------------------------------------------------------*/
/* ���W���[����	:															*/
/*--------------------------------------------------------------------------*/
/* �@�\			: 															*/
/*--------------------------------------------------------------------------*/
/* ���l			:															*/
/*--------------------------------------------------------------------------*/
/* �\���֐�		: 															*/
/*--------------------------------------------------------------------------*/
/* �ύX����		:															*/
/* Version				date				name							*/
/*	t01					14.10.28			�����Z1 1�Z�� K.Kato			*/
/*  t300 ���t�@�N�^�����O �y�сA9/17�� BSM�ŐV�d�l�}�[�W					*/
/*	t02					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���֑Ή�															*/
/*	t03					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �d�l�m�F���ڑΉ�												*/
/*	t04					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� int��S4,float��FL�ɕύX,���[�j���O�Ή�						*/
/*	t05					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t06					15.03.23			�����Z2 1�Z�� G.Jomori			*/
/*	BSM��v�m�F�Ŕ��������o�O�C��											*/
/*	t07					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No492�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t08					15.06.01			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No490,491�Ή�														*/
/*	t09					15.06.02			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No443,444�Ή�														*/
/*	t12					15.07.17			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No627�`630�Ή�													*/
/*	t15					15.08.19			�����Z2 1�Z�� G.Jomori			*/
/*	t848�}�[�W																*/
/*	t16					15.08.19			�����Z2 1�Z�� G.Jomori			*/
/*	BSM��v�m�F�Ŕ��������o�O�C��											*/
/*	t17					15.08.25			�����Z2 1�Z�� G.Jomori			*/
/*	BSM��v�m�F�Ŕ��������o�O�C��											*/
/*	t18					15.08.31			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1501,1507,1564�`1566,1583�`1585�Ή�							*/
/*	t19					15.09.11			�����Z2 1�Z�� G.Jomori			*/
/*	MWR-RECO-24G-BSM-CONNECT-01-012�Ή�										*/
/*	t20					15.10.23			�����Z2 1�Z�� M.Tanaka			*/
/*	�c�ۑ�No.849�Ή�(�Öق̃L���X�g���C��)									*/
/*	t21					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV�Ή�																*/
/*	t22					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)										*/
/*	t23					15.11.25			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo.1824,1842,1860,1861,1876,1879,1896�Ή�						*/
/*	t24					16.01.15			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1055�Ή�(Rx_right���g�p����悤�ɂ���)							*/
/*	t27					16.01.27			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1061�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t28					16.01.29			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1104,1105�Ή�													*/
/*	t30					16.02.24			�����Z2 1�Z�� G.Jomori			*/
/*	291B �J�����C����t248�}�[�W												*/
/*	t31					16.03.01			�����Z2 1�Z�� G.Jomori			*/
/*	010B BSM CV-R�d�l�Ή�													*/
/*	t32					16.03.02			�����Z2 1�Z�� G.Jomori			*/
/*	010B BSM CV-R �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t33					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)		*/
/*	t34					16.03.07			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo2274�Ή�(���W�������Ă��邱�Ƃ��m�F��������ύX)				*/
/*	t35					16.03.07			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1137�Ή�(�l�̌ܓ��ǉ�)											*/
/*	t36					16.03.11			�����Z2 1�Z�� G.Jomori			*/
/*	010B CV-R 3/8���s MWR-RECO-24G-BSM-CONNECT-01-017�Ή�					*/
/*	t37					16.03.11			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo2402�Ή�														*/
/*	t38					16.03.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l�Ή�														*/
/*	t39					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t40					16.03.30			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1136�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t41					16.04.07			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC �w�E�Ή�														*/
/*	t42					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t44					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t45					16.06.20			�����Z2 1�Z�� H.Nonogaki		*/
/*	QAC �w�E�Ή�(OBJ�ύX����)												*/
/*	t46					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t47					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �c�ۑ�No1336�Ή� OBJ�ύX�Ȃ�										*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t52					16.07.18			�����Z2 1�Z�� G.Jomori			*/
/*	291B�J���p�\�t�g��010B�\�t�g���}�[�W(010B 1A���x�[�X��0024_t822�}�[�W)	*/
/*	t56					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1411,1412,1413�Ή�(S4,FL,VD�ɕύX)								*/
/*	t57					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1414,1415�Ή�(�֐���`�ړ�)										*/
/*	t59					16.09.15			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �F������(BSM,RCTA,AUDR)�}�[�W									*/
/*	t60					16.09.16			�����Z2 1�Z�� G.Jomori			*/
/*	�R�����g�폜�A�L���X�g�t�^(OBJ�ύX�Ȃ�)									*/
/*	t61					16.09.23			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R�d�l�Ή�														*/
/*	t62					16.09.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R BSM ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/****************************************************************************/

/****************************************************************************/
/*							�C���N���[�h�t�@�C��							*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "init_cvw.h"

#include "bsm_connect_01.h"

#ifndef _291B_DEV_20161005_BTT_TEST
#include "../btt/bsm_btt.h"
#endif

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif /*VI �\���p*/

/****************************************************************************/
/*							�}�N����`										*/
/****************************************************************************/
#define CU2_MAP_EXOBJ_POWER_INDEX		((U2)8)

/****************************************************************************/
/*						  �����֐��v���g�^�C�v								*/
/****************************************************************************/
U1 u1_check_long_truck(U1 u1_a_alarming_flg);

U1 u1_jdg_truck_on_to_off(U1 u1_a_alarming_flg);

U1 u1_jdg_truck_off_to_on(VD);

static VD fn_bsm_con_check_passing_pre(
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
);

static VD fn_bsm_con_integ_object(
	S4 s4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_ordinary,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_2f,
	const NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM ast_a_normal2[NORMAL_BUFFSIZE]
);

static VD fn_bsm_con_check_prior_ordinary(S4 *ps4_a_pair_num_prior,
										  NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
										  S4 *ps4_a_pair_num_ordinary,
										  NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE]);

static VD fn_bsm_con_copy_ordinay_to_sot(
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1]
);

static S4 s4_bsm_con_check_near_ordinary(
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	const NORMAL_BSM ast_a_normal_sot[1]
);

static VD fn_bsm_con_add_sot_object_to_normal2(
	const NORMAL_BSM *pst_a_normal_ordinary,
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1]
);

static VD fn_bsm_con_add_object_to_normal2(
	S4 s4_a_pair_num_prior,
	const NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_2f,
	const NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	const NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM ast_a_normal2[NORMAL_BUFFSIZE]
);

static VD fn_bsm_con_tracking(
	S4 s4_a_pair_num_connected,
	const S4 *ps4_pair_connect_prev,
	const S4 *ps4_pair_connect_current,
	S4 s4_a_pair_num_normal1,
	NORMAL_BSM *pst_a_normal1,
	S4 s4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
);

static VD fn_bsm_con_add_new_object(
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
);

static VD fn_bsm_con_pack_object(
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
);

VD fn_bsm_con_jdg_object_probability(NORMAL_BSM* past_a_normal2);

U1 u1_bsm_con_jdg_obj_probability_m2(FL fl_a_Ryfil);

U1 u1_bsm_con_jdg_obj_probability_m8(FL fl_a_power_doa);

S4 select_target(
	S4 target_num_prev,					/* [in] */
	const NORMAL_BSM* target_prev,			/* [in] */

	S4* target_num,						/* [out] [1] number of target */
	NORMAL_BSM* target_current,			/* [out] */

	const S4* normal_num,						/* [in/out] [0] current number of pair */
	const NORMAL_BSM* normal_current,			/* [in] */

	U1 u1_a_alarming_flag
);

S4 cluster_target(
	S4 target_num,
	NORMAL_BSM* target,
	S4* used_ID
);

static U1 u1_start_prediction_c5(S4 s4_a_slow_sot_doa_diff_sum4);

static U1 u1_start_prediction_c6(S4 s4_a_slow_sot_doa_diff_sum5);

static VD fn_bsm_sel_exclude_object(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_reset_stop_flg(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_same_peaks(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_stationary(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_around_mycar(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_outside_load(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_outside_to_fr(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_like_wall(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_stag_just_beside(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_outside(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_non_sot_obj(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_exobj_bumper_reflection(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

#if !defined(_291B_DEV_20161005_BTT_TEST) &&  !defined(_20170224_BTT_TFLAG_FA)
static VD fn_bsm_sel_exobj_incor_trailer_obj(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);
#endif


static S4 s4_bsm_sel_empty_buf_trimming(
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_connect_target(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_search_sample(
	S4 s4_a_pair_num_current,
	const NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_prev_index,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 *ps4_a_sample_num,
	S4 as4_a_sample_indexs[NORMAL_BUFFSIZE],
	S4 as4_a_sample_indexs_prev[NORMAL_BUFFSIZE]
);

static VD fn_bsm_sel_set_search_area(
	const NORMAL_BSM ast_a_normal_current[1],
	const NORMAL_BSM ast_a_target_prev[1],
	FL *pfl_a_rx_th,
	FL *pfl_a_ry_th,
	FL *pfl_a_vx_th,
	FL *pfl_a_vy_th
);

static S4 s4_bsm_sel_check_condition(
	const NORMAL_BSM ast_a_normal_current[1],
	const NORMAL_BSM ast_a_target_prev[1],
	FL fl_a_rx_th,
	FL fl_a_ry_th,
	FL fl_a_vx_th,
	FL fl_a_vy_th
);

static S4 s4_bsm_sel_select_sample(
	S4 s4_a_pair_num_current,
	const NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_prev_index,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 s4_a_sample_num,
	const S4 as4_a_sample_indexs[NORMAL_BUFFSIZE],
	const S4 as4_a_sample_indexs_prev[NORMAL_BUFFSIZE]
);

static VD fn_bsm_tracking_target(
	NORMAL_BSM ast_a_normal_current[1],						/* [in]		*/
	NORMAL_BSM ast_a_target_prev[1],						/* [in]		*/
	S4 as4_a_used_ID[TARGET_BUFFSIZE],					/* [out]	*/
	NORMAL_BSM ast_a_target_current[1]						/* [in/out] */
);

static VD fn_bsm_sel_extrapolate_target(
	S4 s4_a_target_num_prev,
	NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_add_target(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_exclude_target(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_lot_exp(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_stationary(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_no_rel_spd(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_stag_just_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_just_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_around_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_opst_sns_area(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_around_mycar(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_extrgt_outside_load(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_empty_buf_trgt_trimming(
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
);

static VD fn_bsm_sel_target_marking(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE], U1 u1_a_alarming_flag);

static VD fn_bsm_sel_check_sot_target(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE], U1 u1_a_alarming_flag);

static VD fn_bsm_sel_check_tos_target(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]);

S4 connect_previous_object(							/* [return] number of connected pairs */
	NORMAL_BSM normal_prev[NORMAL_BUFFSIZE],		/* [in] */
	NORMAL_BSM normal_current[NORMAL_BUFFSIZE],		/* [in/out] */
	S4 pair_num_current,							/* [in] */
	S4* pair_res_prev,								/* [out] */
	S4* pair_res_current,							/* [out] */
	S4 size											/* [in] */
);

VD predict_object_trajectory_simple(
	NORMAL_BSM* normal_current,			/* [in/out] */
	S4 pair_num							/* [in] */
);

S4 prediction_with_connected_data(		/* [return] */
	NORMAL_BSM* normal_prev,			/* [in/out] current normal */
	NORMAL_BSM* normal_current,			/* [in/out] current normal */
	const S4* data_id_prev,					/* [in] buffer id of previous normal (= id os previous tracker) */
	const S4* data_id_current,				/* [in] buffer id of current normal */
	S4 paired_num						/* [in] connected data size */
);

VD predict_object_trajectory_nearfield(
	NORMAL_BSM* normal_prev,				/* [in] */
	NORMAL_BSM* normal_current,				/* [in/out] */
	S4 pair_num,							/* [in] */
	S4 LR,									/* [in] */
	FL sensor_position[3]					/* [in] */
);

S4 prediction_with_connected_data(		/* [return] */
	NORMAL_BSM* normal_prev,			/* [in/out] current normal */
	NORMAL_BSM* normal_current,			/* [in/out] current normal */
	const S4* data_id_prev,					/* [in] buffer id of previous normal (= id os previous tracker) */
	const S4* data_id_current,				/* [in] buffer id of current normal */
	S4 paired_num						/* [in] connected data size */
);

S4 prediction_without_connected_data(			/* [return] */
	NORMAL_BSM* normal_prev,					/* [in] previous normal */
	NORMAL_BSM* normal_current,					/* [in/out] current normal */
	S4 pair_num_current							/* [in] */
);

VD predict_target(
	const NORMAL_BSM *target_prev,				/* [in] */
	NORMAL_BSM *target_current				/* [in/out] */
);

VD copy_normal_data(
	const NORMAL_BSM *normal_in,					/* [in] */
	NORMAL_BSM *normal_out,					/* [out] */
	S4 size									/* [in] */
);

S4 copy_observation_to_filtered_data(
	NORMAL_BSM *normal,				/* [in] */
	S4 size							/* [in] */
);

VD calc_prediction_of_normaldata(
	NORMAL_BSM* normal				/* [in/out] */
);

VD fn_transform_xy_to_polar(
	FL x,				/* [in] */
	FL y,				/* [in] */
	FL* r,				/* [out] */
	FL* theta			/* [out] */
);

VD fn_transform_rad_to_doabin(
	FL angle,			/* [in] */
	S4* doa_bin			/* [out] */
);

VD fn_transform_rad_to_doabin_interpolate(
	FL angle,			/* [in] */
	FL* doa_bin			/* [out] */
);

VD fn_transform_rv_to_freqbin(
	FL r,			/* [in] */
	FL v,			/* [in] */
	S4* freqbin,	/* [out] */
	S4 updn			/* [in] 0:UP / 1:DN */
);

VD fn_transform_rv_to_freqbin_interpolate(
	FL r,			/* [in] */
	FL v,			/* [in] */
	FL* freqbin,	/* [out] */
	S4 updn			/* [in] 0:UP / 1:DN */
);


VD fn_transform_vxvy_to_vr(
	FL vx,		/* [in] */
	FL vy,		/* [in] */
	FL theta,	/* [in] rad */
	FL* vr		/* [out] */
);

S4 s4_check_passing_car(
	const NORMAL_BSM* pst_a_target,		/* [in] */
	S4 s4_a_prev_passing_flg			/* [in] */
);

VD fn_send_to_can(
	const NORMAL_BSM ast_a_target[TARGET_BUFFSIZE],			/* [in] */
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [out] */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]			/* [out] */
);

/* main processing for FM signal */
/* @param :see below */
S4 s4_bsm_connect(
	S4 pair_num_prior,										/* [in] number of objects */
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],			/* [in] S4 values of NORMAL_BSM structure */
	S4 pair_num_ordinary,									/* [in] number of objects */
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],	/* [in] S4 values of NORMAL_BSM structure */
	S4 pair_num_2f,											/* [in] number of objects */
	const NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],				/* [in] S4 values of NORMAL_BSM structure */
	S4 pair_num_sot,										/* [in/out] number of objects */
	NORMAL_BSM ast_a_normal_sot[1],							/* [in/out] S4 values of NORMAL_BSM structure */
	S4 Tx_int[TARGET_BUFFSIZE][NORM_INT],					/* [out] */
	FL Tx_float[TARGET_BUFFSIZE][TGT_FLT],					/* [out] */
	U1 u1_a_alarming_flag
)
{
/*********************************************************************************************/
/*********     �ϐ��錾       ****************************************************************/
/*********************************************************************************************/
	S4 i;
	S4 iRet = 0;

	NORMAL_BSM	normal1[NORMAL_BUFFSIZE],
			normal2[NORMAL_BUFFSIZE],
			target1[TARGET_BUFFSIZE],
			target2[TARGET_BUFFSIZE];
	S4		pair_num_current[2];

	S4 trk_num = 0;

	/*** �u���b�N�̓r���Ő錾����Ă���ϐ��Q���u���b�N�̐擪�ֈړ� *******************/

	/* ����4�̕ϐ��͏����������l������� */
	S4		pair_connect_prev[NORMAL_BUFFSIZE],
			pair_connect_current[NORMAL_BUFFSIZE];
	/* �����ő�p�\�ƍl������ */

	S4		pair_num_total = 0;
	S4		pair_num_connected = 0;
	S4		pair_num_lost = 0;
	S4 s4_t_pair_num_selected = 0;

/*********************************************************************************************/
/*********     �z�񏉊���     ****************************************************************/
/*********************************************************************************************/
	fn_init(normal2, NORMAL_BUFFSIZE);
	fn_init(target2, TARGET_BUFFSIZE);
	fn_move(normal1, st_g_bsm_loop_data.ast_normal, NORMAL_BUFFSIZE);
	fn_move(target1, st_g_bsm_loop_data.ast_target, TARGET_BUFFSIZE);
	pair_num_current[0] = (S4)0;
	pair_num_current[1] = (S4)0;

	for(i=0; i<NORMAL_BUFFSIZE; i++)
	{
		pair_connect_prev[i] = -1;
		pair_connect_current[i] = -1;
	}

/****************************************************************************/
/* (11) �g���b�N���菈��													*/
/****************************************************************************/
	st_g_bsm_loop_data.u1_truck_flg = u1_check_long_truck(u1_a_alarming_flag);

/****************************************************************************/
/* (1)	���H�`�󐄒菈��													*/
/****************************************************************************/
	/* road shape estimation */
	fn_estimate_road_shape(
		st_g_bsm_loop_data.afl_Rx_right
	);

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy (afl_g_Rx_right, st_g_bsm_loop_data.afl_Rx_right, sizeof(FL)*70);			//���H�`��
	for(i=0; i<70; i++){
		afl_g_Ry_right[i] = -(float)i;
	}
#endif /*VI �\���p*/


/****************************************************************************/
/* (9)	�ǉz���菈��(pre)													*/
/****************************************************************************/
	fn_bsm_con_check_passing_pre(
		(const NORMAL_BSM (*))target1
	);

/****************************************************************************/
/* (2)	���W��񓝍�����													*/
/****************************************************************************/
/*********     ���W�܂Ƃ�     **************************************************************/
	fn_bsm_con_integ_object(
		pair_num_prior,
		ast_a_normal_prior,
		pair_num_ordinary,
		ast_a_normal_ordinary,
		pair_num_2f,
		ast_a_normal_2f,
		pair_num_sot,
		ast_a_normal_sot,
		&pair_num_total,
		normal2
	);

#if (MODE_ECU_SIM == ECU_MODE)
	/* S4��U1�̃_�E���L���X�g�ł��邪�Apair_num_total�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_connect_in_pair_num = (U1)pair_num_total;			/* CheckPoint BSM_�F���������͕��W�� */
#endif /* MODE_ECU_SIM */

/****************************************************************************/
/* (3)	����ڑ�����														*/
/****************************************************************************/
	/* �O��̕��W���̐����`�F�b�N */
	trk_num = st_g_bsm_loop_data.as4_buf_pair_num[0];
	/* �O��̕��W��񂪂Ȃ��Ƃ��͌��ݒl�݂̂ɂ��P���\�� */
	if(trk_num==0)
	{
		predict_object_trajectory_simple(
			normal2,				/* [in/out] */
			pair_num_total			/* [in] */
		);
	}
	else
	{
/*********     ����ڑ�     ******************************************************************/
		pair_num_connected = connect_previous_object(
			normal1,				/* [in] previous */
			normal2,				/* [in/out] current */
			pair_num_total,			/* [in] */
			pair_connect_prev,		/* [out] */
			pair_connect_current,	/* [out] */
			NORMAL_BUFFSIZE			/* [in] */
		);

/****************************************************************************/
/* (4)	�g���b�L���O����													*/
/****************************************************************************/
		fn_bsm_con_tracking(
			pair_num_connected,
			(const S4 (*))pair_connect_prev,
			(const S4 (*))pair_connect_current,
			st_g_bsm_loop_data.as4_buf_pair_num[0],
			normal1,
			pair_num_total,
			normal2
		);
	}
/****************************************************************************/
/*(5)	�O�}����															*/
/****************************************************************************/
	/* ���X�g���W�Đ�(�O�}����) */
	/* �����g���b�J�i�ڑ��Ȃ����ϑ��Ȃ��j */
	if( trk_num > 0 )
	{
		pair_num_lost = prediction_without_connected_data(
			normal1,				/* [in] */
			normal2,				/* [in/out] */
			pair_num_total			/* [in] */
		);
	}
	pair_num_total = pair_num_total + pair_num_lost;	/* number of current objects */

/****************************************************************************/
/* (6)	�V�K���W�ǉ�����													*/
/****************************************************************************/
	/* �V�K���W�ǉ�/�s�v���W�폜 */
	fn_bsm_con_add_new_object(
		&pair_num_total,
		normal2
	);

/****************************************************************************/
/* (7)   ���W�̎��̔���														*/
/****************************************************************************/
	fn_bsm_con_jdg_object_probability(normal2);


#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	s4_g_pair_num = pair_num_total;
	memcpy (ast_g_normal, normal2, sizeof(NORMAL_BSM)*NORMAL_BUFFSIZE);
#endif /*VI �\���p*/

/****************************************************************************/
/* (8)	�^�[�Q�b�g�I������													*/
/****************************************************************************/
	s4_t_pair_num_selected = select_target(
		/* previous target */
		st_g_bsm_loop_data.as4_buf_pair_num[1],		/* [in] */
		(const NORMAL_BSM (*))target1,							/* [in] */

		/* current target */
		&pair_num_current[1],	/* [out] */
		target2,				/* [out] */

		/* current object */
		(const S4 (*))&pair_num_total,		/* [in/out] */
		(const NORMAL_BSM (*))normal2,				/* [in] */

		u1_a_alarming_flag
	);

#if (MODE_ECU_SIM == ECU_MODE)
	/* S4��U1�̃_�E���L���X�g�ł��邪�As4_t_pair_num_selected�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_connect_target_num = (U1)s4_t_pair_num_selected;			/* CheckPoint BSM_�F�������^�[�Q�b�g�� */
#endif /* MODE_ECU_SIM */

/*********************************************************************************************/
/********* 12) Output target data  ***********************************************************/
/*********     �o�͏��̃Z�b�g    ***********************************************************/
/*********************************************************************************************/
	st_g_bsm_loop_data.as4_buf_pair_num[0] = pair_num_total;
	st_g_bsm_loop_data.as4_buf_pair_num[1] = pair_num_current[1];

	/* copy: normal2 -> normal1 */
	fn_move(
		normal1,			/* [out] */
		normal2,			/* [in] */
		NORMAL_BUFFSIZE		/* [in] */
	);

	/* copy: target2 -> target1 */
	fn_move(
		target1,			/* [out] */
		target2,			/* [in] */
		TARGET_BUFFSIZE		/* [in] */
	);

	fn_move(st_g_bsm_loop_data.ast_normal, normal1, NORMAL_BUFFSIZE);
	fn_move(st_g_bsm_loop_data.ast_target, target1, TARGET_BUFFSIZE);

/****************************************************************************/
/* (10)	�ǉz���菈��(post)													*/
/****************************************************************************/
	{
		if(st_g_bsm_loop_data.as4_buf_pair_num[1]==0)
		{
			st_g_bsm_loop_data.as4_flg_passing[0] = 0;
		}
		else
		{
			st_g_bsm_loop_data.as4_flg_passing[0] = s4_check_passing_car(
				(const NORMAL_BSM *)(&target1[0]),
				st_g_bsm_loop_data.as4_flg_passing[0]
			);
		}
		
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
		if ((fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN)			/* cond.g1 */
		&&  (st_g_bsm_loop_data.s4_flg_alarm == (S4)0)) {				/* cond.g2 */
			st_g_bsm_loop_data.as4_flg_passing[0] = 0;
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
	}

/*********************************************************************************************/
/*********     CAN�o�̓f�[�^�쐬    **********************************************************/
/*********************************************************************************************/
	fn_send_to_can(
		(const NORMAL_BSM (*))target1,	/* [in] */
		Tx_int,		/* [out] */
		Tx_float	/* [out] */
	);
	iRet = st_g_bsm_loop_data.as4_buf_pair_num[1];

	/* ���W�ԍ����Ȃ����̂ɔԍ������� */
	{
		S4 as4_t_used_ID[TARGET_BUFFSIZE];
		S4 s4_t_lp_target_num;
		S4 s4_t_lp_used_id;
		for(s4_t_lp_target_num=0; s4_t_lp_target_num<TARGET_BUFFSIZE; s4_t_lp_target_num++)
		{
			as4_t_used_ID[s4_t_lp_target_num] = 0;
		}
		/* �g�p���̔ԍ����m�F */
		for(s4_t_lp_target_num=0; s4_t_lp_target_num<TARGET_BUFFSIZE; s4_t_lp_target_num++)
		{
			if ((Tx_int[s4_t_lp_target_num][11] != 0)						/* num */
			&&  (Tx_float[s4_t_lp_target_num][7] != CFL_UNKNOWN_VALUE)
			&&  (Tx_float[s4_t_lp_target_num][8] != CFL_UNKNOWN_VALUE)) {
				as4_t_used_ID[Tx_int[s4_t_lp_target_num][11]-1] = 1;
			}
		}
		/* �ԍ��̂Ȃ����W�ɋ󂢂Ă���ԍ������� */
		for(s4_t_lp_target_num=0; s4_t_lp_target_num<TARGET_BUFFSIZE; s4_t_lp_target_num++)
		{
			if ((Tx_int[s4_t_lp_target_num][11] == 0)						/* num */
			&&  (Tx_float[s4_t_lp_target_num][7] != CFL_UNKNOWN_VALUE)
			&&  (Tx_float[s4_t_lp_target_num][8] != CFL_UNKNOWN_VALUE)) {
				for(s4_t_lp_used_id=0; s4_t_lp_used_id<TARGET_BUFFSIZE; s4_t_lp_used_id++)
				{
					if(as4_t_used_ID[s4_t_lp_used_id]==0)
					{
						Tx_int[s4_t_lp_target_num][11] = s4_t_lp_used_id+1;
						as4_t_used_ID[s4_t_lp_used_id] = 1;
						break;
					}
				}
			}
		}
	}

	return iRet;
}

/********************************************************************************************/
/* �֐���		: u1_check_long_truck														*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �g���b�N����				 												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: u1_a_alarming_flg					: �x�񒆃t���O [in]						*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_loop_data.as4_fast_sot_flg[] : fast-SoT�t���O [in]				*/
/*				: st_g_bsm_loop_data.as4_flg_truck		: �g���b�N�t���O [in]				*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: u1_jdg_truck_on_to_off(), u1_jdg_truck_off_to_on()						*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011 (11) �g���b�N���菈��						*/
/********************************************************************************************/
U1 u1_check_long_truck(U1 u1_a_alarming_flg)
{
	U1 u1_t_jdg_truck_flg;
	
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	u1_t_jdg_truck_flg = (U1)0;
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	/* �O��l�ێ��̂��߁A�t���O�ŏ����� */
	u1_t_jdg_truck_flg = st_g_bsm_loop_data.u1_truck_flg;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

	if (st_g_bsm_loop_data.as4_low_speed_flg[0] == (U1)0) {						/* COND.a100 */
		if (st_g_bsm_loop_data.u1_truck_flg != (U1)0) {
			/* ON��OFF ���� */
			u1_t_jdg_truck_flg = u1_jdg_truck_on_to_off(u1_a_alarming_flg);
		}
		else if ((st_g_bsm_loop_data.as4_slow_sot_find[0] != (S4)0)
			 &&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3)
			 &&  (u1_a_alarming_flg == (U1)1)) {
			u1_t_jdg_truck_flg = u1_jdg_truck_off_to_on();
		} else {
			/* �������Ȃ� */
		}
	} else {
		u1_t_jdg_truck_flg = (U1)0;
	}

	return u1_t_jdg_truck_flg;
}

/********************************************************************************************/
/* �֐���		: u1_jdg_truck_on_to_off													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �g���b�N�t���OON��OFF����	 												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: u1_a_alarming_flg					: �x�񒆃t���O [in]						*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: afl_g_cvw_lfm_ftt_power : FMCW FFT���ϓd��								*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011											*/
/*				  (11) �g���b�N���菈�� 1) ON��OFF Judgement  								*/
/********************************************************************************************/
U1 u1_jdg_truck_on_to_off(U1 u1_a_alarming_flg)
{
	U1 u1_t_jdg_truck_flg;
	U2 u2_t_lp_fft_data;
	U1 u1_t_count_up;

#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	U4 u4_t_count_up2;

	u4_t_count_up2 = (U4)0;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

	u1_t_jdg_truck_flg = (U1)1;				/* ON��OFF����Ȃ̂�1�ŏ��������� */
	u1_t_count_up = (U1)0;

	/* ON��OFF ���� */
	for (u2_t_lp_fft_data = CU2_TRUCK_BIN_START_OFF; u2_t_lp_fft_data < CU2_TRUCK_BIN_END_OFF; u2_t_lp_fft_data++) {
		if (afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data] < CFL_TRUCK_POW_TH_OFF) {
			u1_t_count_up++;
		}
	}
	
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	if (u1_t_count_up > CU2_TRUCK_CNT_TH_OFF) {
		u1_t_jdg_truck_flg = (U1)0;
	} else if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)
		   &&  (u1_a_alarming_flg == (S4)0)) {
		u1_t_jdg_truck_flg = (U1)0;
	} else {
		/* �g���b�N�t���OON�̂܂� */
	}
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	for (u2_t_lp_fft_data = (U2)TRUCK_BIN_START; u2_t_lp_fft_data < CU2_TRUCK_BIN_START_OFF; u2_t_lp_fft_data++) {
		if (afl_g_cvw_lfm_ftt_power[1][u2_t_lp_fft_data] < (FL)55.0F) {			/* COND.a15 */
			u4_t_count_up2++;
		}
	}
	
	if ((u1_t_count_up > CU2_TRUCK_CNT_TH_OFF)							/* COND.a6 */
	||  (u4_t_count_up2 > (U4)8)) {										/* COND.a16 */
		u1_t_jdg_truck_flg = (U1)0;										/* PROC.3 */
	} else if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)		/* COND.a7 */
		   &&  (u1_a_alarming_flg == (S4)0)) {							/* COND.a8 */
#ifndef _291B_1A_US_20160909_TRUCK_MOD_1
		if( u1_jdg_truck_off_to_on()==(U1)0 ){							/* COND.a301 */
			u1_t_jdg_truck_flg = (U1)0;									/* PROC.3 */
		}
#else
		u1_t_jdg_truck_flg = (U1)0;										/* PROC.3 */
#endif
	} else {
		/* �g���b�N�t���OON�̂܂� */
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

	return u1_t_jdg_truck_flg;
}

/********************************************************************************************/
/* �֐���		: u1_jdg_truck_off_to_on													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �g���b�N�t���OOFF��ON����	 												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: afl_g_cvw_lfm_ftt_power : FMCW FFT���ϓd��								*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011											*/
/*				  (11) �g���b�N���菈�� 2) OFF��ON Judgement  								*/
/********************************************************************************************/
U1 u1_jdg_truck_off_to_on(VD)
{
	U1 u1_t_jdg_truck_flg;
	U2 u2_t_lp_fft_data;
	U1 u1_t_count_up;
	U1 u1_t_count_dn;
	
	u1_t_jdg_truck_flg = (U1)0;
	u1_t_count_up = (U1)0;
	u1_t_count_dn = (U1)0;
	
	/* OFF��ON ���� */
	for (u2_t_lp_fft_data = TRUCK_BIN_START; u2_t_lp_fft_data < TRUCK_BIN_END; u2_t_lp_fft_data++) {
		if (afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data] > TRUCK_POW_TH) {
			u1_t_count_up++;
		}
		if (afl_g_cvw_lfm_ftt_power[1][u2_t_lp_fft_data] > TRUCK_POW_TH) {
			u1_t_count_dn++;
		}
	}
	
#ifndef _291B_1A_US_20160901_TRUCK_FOR_TEST
		u1_t_jdg_truck_flg = (U1)0;	//always off
#else
	if ((u1_t_count_up > (U1)((FL)(TRUCK_BIN_END - TRUCK_BIN_START) * CFL_TRUCK_RANGE_TH + (FL)0.5F))
	||  (u1_t_count_dn > (U1)((FL)(TRUCK_BIN_END - TRUCK_BIN_START) * CFL_TRUCK_RANGE_TH + (FL)0.5F))) {
		u1_t_jdg_truck_flg = (U1)1;
	}
#endif
	return u1_t_jdg_truck_flg;
}

static VD fn_bsm_con_check_passing_pre(
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ��s�ԕ��W���c���Ă���Ԃ͒ǉz�ԃt���OTRUE  */
	for(i=0;i<st_g_bsm_loop_data.as4_buf_pair_num[1];i++)
	{
		if (((ast_a_target_prev[i].s4_flg_heiso_up == 1)
		&&   (ast_a_target_prev[i].s4_flg_heiso_dn == 1))
		||  ((ast_a_target_prev[i].fl_Rxfil < (ALARM_X_OUT          + ALARM_X_OFFSET_OUT))			/* �s��ł͂Ȃ����H�@�z��O�Q�Ƃ��Ă���\�������� */
		&&   (ast_a_target_prev[i].fl_Rxfil > (ALARM_X_IN           + ALARM_X_OFFSET_IN))
		&&   (ast_a_target_prev[i].fl_Ryfil < (ALARM_Y_FORWARD))
		&&   (ast_a_target_prev[i].fl_Ryfil > (CFL_ALARM_Y_BACKWARD - ALARM_Y_OFFSET)))
		)
		{
			st_g_bsm_loop_data.as4_flg_passing[0] += (S4)1;
		}
	}
	
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	if ((fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN)					/* cond.c2 */
	&&  (st_g_bsm_loop_data.s4_flg_alarm == (S4)0)) {						/* cond.c3 */
		st_g_bsm_loop_data.as4_flg_passing[0] = 0;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

}

static VD fn_bsm_con_integ_object(
	S4 s4_a_pair_num_prior,
	NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_ordinary,
	NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_2f,
	const NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM ast_a_normal2[NORMAL_BUFFSIZE]
)
{
	/* �D�敨�W�ƒʏ함�W�ŏ�艺��ǂ��炩�̎��g��bin�ƕ���bin����v������̂����邩�m�F */
	fn_bsm_con_check_prior_ordinary(&s4_a_pair_num_prior, ast_a_normal_prior, &s4_a_pair_num_ordinary, ast_a_normal_ordinary);

	fn_bsm_con_copy_ordinay_to_sot(
		s4_a_pair_num_ordinary,
		(const NORMAL_BSM (*))ast_a_normal_ordinary,
		s4_a_pair_num_sot,
		ast_a_normal_sot
	);

	fn_bsm_con_add_object_to_normal2(
		s4_a_pair_num_prior,
		(const NORMAL_BSM (*))ast_a_normal_prior,
		s4_a_pair_num_ordinary,
		(const NORMAL_BSM (*))ast_a_normal_ordinary,
		s4_a_pair_num_2f,
		ast_a_normal_2f,
		s4_a_pair_num_sot,
		(const NORMAL_BSM (*))ast_a_normal_sot,
		ps4_a_pair_num_total,
		ast_a_normal2
	);
}

/********************************************************************************************/
/* �֐���		: fn_bsm_con_check_prior_ordinary											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �D�敨�W�ƒʏ함�W�̓�����g��bin�ƕ���bin���Ȃ�������					*/
/*------------------------------------------------------------------------------------------*/
/* ����			: ps4_a_pair_num_prior					: �D�敨�W�� [in/out]				*/
/*				: ast_a_normal_prior[]					: �D�敨�W��� [in/out]				*/
/*				: ps4_a_pair_num_ordinary				: �ʏ함�W�� [in/out]				*/
/*				: ast_a_normal_ordinary[]				: �ʏ함�W��� [in/out]				*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fl_abs(), fn_init(), s4_trim_ordinary(), s4_trim_prior()					*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: FS�F�����֎��_�ł͋L�ڂȂ� ���W�I������ (2)���W��񓝍������ɋL�ڗ\��		*/
/********************************************************************************************/
static VD fn_bsm_con_check_prior_ordinary(S4 *ps4_a_pair_num_prior,
										  NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
										  S4 *ps4_a_pair_num_ordinary,
										  NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE])
{
	S4 s4_t_lp_num_ordi;
	S4 s4_t_lp_num_prior;

	for (s4_t_lp_num_ordi = (S4)0; s4_t_lp_num_ordi < *ps4_a_pair_num_ordinary; s4_t_lp_num_ordi++) {
		if (ast_a_normal_ordinary[s4_t_lp_num_ordi].fl_Robs != CFL_UNKNOWN_VALUE) {
			for (s4_t_lp_num_prior = (S4)0; s4_t_lp_num_prior < *ps4_a_pair_num_prior; s4_t_lp_num_prior++) {
				if (ast_a_normal_prior[s4_t_lp_num_prior].fl_Robs != CFL_UNKNOWN_VALUE) {
					/* up�܂���down�ǂ��炩�Ŏ��g��bin�ƕ���bin����v���镨�W��T�� */
					if (((ast_a_normal_ordinary[s4_t_lp_num_ordi].s4_bin_up       == ast_a_normal_prior[s4_t_lp_num_prior].s4_bin_up)
					&&   (ast_a_normal_ordinary[s4_t_lp_num_ordi].s4_bin_up_music == ast_a_normal_prior[s4_t_lp_num_prior].s4_bin_up_music))
					||  ((ast_a_normal_ordinary[s4_t_lp_num_ordi].s4_bin_dn       == ast_a_normal_prior[s4_t_lp_num_prior].s4_bin_dn)
					&&   (ast_a_normal_ordinary[s4_t_lp_num_ordi].s4_bin_dn_music == ast_a_normal_prior[s4_t_lp_num_prior].s4_bin_dn_music))) {
						/* up - down�̕��ʓd�͍����Z�o */
						if (fl_abs(ast_a_normal_prior[s4_t_lp_num_prior].fl_power_up_music - ast_a_normal_prior[s4_t_lp_num_prior].fl_power_dn_music) > 
						    fl_abs(ast_a_normal_ordinary[s4_t_lp_num_ordi].fl_power_up_music - ast_a_normal_ordinary[s4_t_lp_num_ordi].fl_power_dn_music)) {
							/* �D��̕����傫���̂ŗD������� */
							fn_init(&ast_a_normal_prior[s4_t_lp_num_prior], (S4)1);
						} else {
							/* �ʏ�̕����傫���̂Œʏ������ */
							fn_init(&ast_a_normal_ordinary[s4_t_lp_num_ordi], (S4)1);
						}
					}
				}
			}
		}
	}

	*ps4_a_pair_num_ordinary = s4_trim_ordinary(ast_a_normal_ordinary);
	*ps4_a_pair_num_prior = s4_trim_prior(ast_a_normal_prior);

	return;
}

static VD fn_bsm_con_copy_ordinay_to_sot(
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 tmp_sot_others_index;

	tmp_sot_others_index = s4_bsm_con_check_near_ordinary(
		s4_a_pair_num_ordinary,
		ast_a_normal_ordinary,
		s4_a_pair_num_sot,
		(const NORMAL_BSM (*))ast_a_normal_sot
	);

	if(tmp_sot_others_index!=-1) {
		fn_bsm_con_add_sot_object_to_normal2(
			&ast_a_normal_ordinary[tmp_sot_others_index],
			s4_a_pair_num_sot,
			ast_a_normal_sot
		);
	}

	return;
}

static S4 s4_bsm_con_check_near_ordinary(
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	const NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 i;

	/* copy ordinary obeject to sot object in bsm_main() (SoT) */
	FL tmp_sot_others_diff_min = fl_abs(CFL_UNKNOWN_VALUE*2);
	FL tmp_sot_truck_x_min = fl_abs(CFL_UNKNOWN_VALUE);
	S4 tmp_sot_others_index = -1;

	for(i=0; i<s4_a_pair_num_ordinary; i++)
	{
		if( s4_a_pair_num_sot != 0 )
		{
			if (((fl_abs(ast_a_normal_sot[0].fl_Rxfil - ast_a_normal_ordinary[i].fl_Rxobs)) < 2.5F)
			&&  ((fl_abs(ast_a_normal_sot[0].fl_Ryfil - ast_a_normal_ordinary[i].fl_Ryobs)) < 0.5F)
			&&  (ast_a_normal_sot[0].fl_Rxfil > ast_a_normal_ordinary[i].fl_Rxobs)
			&&  (tmp_sot_others_diff_min > (fl_abs(ast_a_normal_sot[0].fl_Rxfil - ast_a_normal_ordinary[i].fl_Rxobs)
										 +  fl_abs(ast_a_normal_sot[0].fl_Ryfil - ast_a_normal_ordinary[i].fl_Ryobs)))) {
				tmp_sot_others_diff_min = fl_abs(ast_a_normal_sot[0].fl_Rxfil-ast_a_normal_ordinary[i].fl_Rxobs)
										  +fl_abs(ast_a_normal_sot[0].fl_Ryfil-ast_a_normal_ordinary[i].fl_Ryobs);
				tmp_sot_others_index = i;
			}
		} else if ((st_g_bsm_loop_data.u1_truck_flg != 0)
			   &&  (st_g_bsm_loop_data.as4_flg_passing[0] > 0)
			   &&  (st_g_bsm_loop_data.as4_slow_sot_find[0] != 0)) {
			/* copy ordinary obeject to sot object in bsm_main() (Truck) */
			if ((fl_abs(ast_a_normal_ordinary[i].fl_Ryobs) < 0.5F)
			&&  (ast_a_normal_ordinary[i].fl_Rxobs < st_g_bsm_loop_data.afl_wall_width[0])
			&&  (tmp_sot_truck_x_min > fl_abs(ast_a_normal_ordinary[i].fl_Rxobs))) {
				tmp_sot_truck_x_min = fl_abs(ast_a_normal_ordinary[i].fl_Rxobs);
				tmp_sot_others_index = i;
				st_g_bsm_loop_data.as4_flg_leading[0] = 1;
			}
		} else {
			/* �������Ȃ� */
		}

#if (BSM_OPTION_SW_CONNECT == TYPE_A)
		if ((st_g_bsm_loop_data.as4_low_speed_flg[0] == 1)										/*(2) cond.g1 */
		&&  (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)0)) {									/*(2) cond.g2 */
			st_g_bsm_loop_data.as4_flg_leading[0] = 0;											/*(2) proc.10 */
		}
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
		if ((fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN)									/*(2) cond.g3 */
		&&  (st_g_bsm_loop_data.s4_flg_alarm == (S4)0)) {										/*(2) cond.g4 */
			st_g_bsm_loop_data.as4_flg_leading[0] = 0;											/*(2) proc.10 */
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

	}

	return tmp_sot_others_index;
}

static VD fn_bsm_con_add_sot_object_to_normal2(
	const NORMAL_BSM *pst_a_normal_ordinary,
	S4 s4_a_pair_num_sot,
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 tmptmp_passing_flg[1];
	S4 tmptmp_leading_flg[1];
	S4 tmptmp_erased_num = 0;

	tmptmp_passing_flg[0] = (S4)0;
	tmptmp_leading_flg[0] = (S4)0;

	copy_normal_data( pst_a_normal_ordinary, &ast_a_normal_sot[0], 1);
	ast_a_normal_sot[0].s4_flg_heiso_up = 1;
	ast_a_normal_sot[0].s4_flg_heiso_dn = 1;
	ast_a_normal_sot[0].s4_flg_dc = OBJECT_TYPE_SOT;

	tmptmp_erased_num = s4_start_prediction(	
		ast_a_normal_sot,		/* [in/out] */
		1,						/* [in] */
		1,						/* [in] */
		(const S4 (*))tmptmp_passing_flg,		/* [in] */
		(const S4 (*))tmptmp_leading_flg		/* [in] */
	);

	if(tmptmp_erased_num==1)
	{
		fn_init(&ast_a_normal_sot[0], 1);
	}
	else
	{
		ast_a_normal_sot[0].s4_flg_new = 1;
		ast_a_normal_sot[0].s4_flg_track = (S4)(PRIOR_TRK_NUM+1);
	}
	/* trim normal data */
	s4_copy_prediction_to_filtered_data(
		ast_a_normal_sot,
		1
	);

	return;
}

static VD fn_bsm_con_add_object_to_normal2(
	S4 s4_a_pair_num_prior,
	const NORMAL_BSM ast_a_normal_prior[PRIOR_BUFFSIZE],
	S4 s4_a_pair_num_ordinary,
	const NORMAL_BSM ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4 s4_a_pair_num_2f,
	const NORMAL_BSM ast_a_normal_2f[AUX_BUFFSIZE],
	S4 s4_a_pair_num_sot,
	const NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM ast_a_normal2[NORMAL_BUFFSIZE]
)
{
	S4 i;
	S4 index = 0;

	/* �O�������W */
	if ((st_g_bsm_loop_data.as4_flg_leading[0] != 0)
	&&  (ast_a_normal_sot[0].s4_bin_up != 0)
	&&  (ast_a_normal_sot[0].s4_bin_dn != 0)) {
		ast_a_normal2[index] = ast_a_normal_sot[0];
		index++;
	}

	/* �D�敨�W */
	for(i=0; i<s4_a_pair_num_prior; i++)
	{
		if(index>(S4)(NORMAL_BUFFSIZE-1))
		{
			break;
		}
		ast_a_normal2[index] = ast_a_normal_prior[i];
		index++;
	}
	/* �ʏ함�W */
	for(i=0; i<s4_a_pair_num_ordinary; i++)
	{
		if(index>(S4)(NORMAL_BUFFSIZE-1))
		{
			break;
		}
		ast_a_normal2[index] = ast_a_normal_ordinary[i];
		index++;
	}
	/* 2FCW���W */
	for(i=0; i<s4_a_pair_num_2f; i++)
	{
		if(index>(S4)(NORMAL_BUFFSIZE-1))
		{
			break;
		}
		ast_a_normal2[index] = ast_a_normal_2f[i];
		index++;
	}

	*ps4_a_pair_num_total = index;

	return;
}

static VD fn_bsm_con_tracking(
	S4 s4_a_pair_num_connected,
	const S4 *ps4_pair_connect_prev,
	const S4 *ps4_pair_connect_current,
	S4 s4_a_pair_num_normal1,
	NORMAL_BSM *pst_a_normal1,
	S4 s4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
)
{
	S4 i;

	/* �g���b�L���O�t���O������ */
	for( i = 0; i < st_g_bsm_loop_data.as4_buf_pair_num[0]; i++ ) /* s4_a_pair_num_normal1 �͈�������폜�B���l�ɁAnormal1���폜���� */
	{
		pst_a_normal1[i].s4_flg_used = 0;
		pst_a_normal1[i].s4_tracked = 0;
	}
	for( i = 0; i < s4_a_pair_num_total; i++ )
	{
		pst_a_normal2[i].s4_flg_used = 0;
		pst_a_normal2[i].s4_tracked = 0;
	}

	/* �g���b�L���O�i�ڑ����聁�ϑ�����j */
	if ((s4_a_pair_num_connected > 0)
	&&  (st_g_bsm_loop_data.as4_buf_pair_num[0] > 0)) {
		prediction_with_connected_data(
			pst_a_normal1,				/* [in/out] */
			pst_a_normal2,				/* [in/out] */
			ps4_pair_connect_prev,		/* [in] */
			ps4_pair_connect_current,	/* [in] */
			s4_a_pair_num_connected		/* [in] */
		);
	}

	return;
}

static VD fn_bsm_con_add_new_object(
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
)
{
	S4 i;
	S4 s4_t_pair_num_erased;

	/* �V�K���W�ǉ�/�s�v���W�폜 */
	s4_t_pair_num_erased = s4_start_prediction(
		pst_a_normal2,				/* [in/out] */
		*ps4_a_pair_num_total,		/* [in] */
		NORMAL_BUFFSIZE,			/* [in] */
		(const S4 (*))st_g_bsm_loop_data.as4_flg_passing,
		(const S4 (*))st_g_bsm_loop_data.as4_flg_leading
	);
	*ps4_a_pair_num_total = *ps4_a_pair_num_total - s4_t_pair_num_erased;	/* number of current objects */

		/* �g���b�J�\�������o�\�͈͂���O�ꂽ�烊�Z�b�g���� */
	for(i=0; i<NORMAL_BUFFSIZE; i++)
	{
		if ((pst_a_normal2[i].s4_bin_up_pred > NB_FFT_PT)
		||  (pst_a_normal2[i].s4_bin_dn_pred > NB_FFT_PT)) {
			fn_init(&pst_a_normal2[i], 1);
			(*ps4_a_pair_num_total)--;
		}
	}

	/* ��X���b�g���l�߂� */
	fn_bsm_con_pack_object(
		ps4_a_pair_num_total,
		pst_a_normal2
	);

	return;
}

static VD fn_bsm_con_pack_object(
	S4 *ps4_a_pair_num_total,
	NORMAL_BSM *pst_a_normal2
)
{
	/* ��X���b�g�������ǂ̂��߂̕ϐ� */
	S4 s2_t_in[NORMAL_BUFFSIZE];
	S4 s2_t_loop;
	S4 s2_t_num;

	/* ��X���b�g���l�߂� */
	s2_t_num = 0;
	for (s2_t_loop = 0; s2_t_loop < NORMAL_BUFFSIZE; s2_t_loop++) {
		if (
			/* ���g�������Ă��邩�ǂ����̊m�F�p */
			pst_a_normal2[s2_t_loop].fl_Robs != CFL_UNKNOWN_VALUE
		)
		{
			s2_t_in[s2_t_num] = s2_t_loop;
			s2_t_num++;
		}
	}

	if (s2_t_num > 0) {
		for (s2_t_loop = 0; s2_t_loop < s2_t_num; s2_t_loop++) {
			pst_a_normal2[s2_t_loop] = pst_a_normal2[s2_t_in[s2_t_loop]];
		}

		/* �s�v�ƂȂ������͏��������� */
		for (s2_t_loop = s2_t_num; s2_t_loop < NORMAL_BUFFSIZE; s2_t_loop++) {
			fn_init(&pst_a_normal2[s2_t_loop], 1);
		}
	}

	/* trim normal data */
	*ps4_a_pair_num_total = s4_copy_prediction_to_filtered_data(
		pst_a_normal2,
		NORMAL_BUFFSIZE
	);

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_con_jdg_object_probability()										*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�̎��̔���															*/
/*------------------------------------------------------------------------------------------*/
/* ����			: past_a_normal_2 					: ���ݕ��W��� [in/out]					*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fl_abs()																	*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011 (7)   ���W�̎��̔��� 						*/
/********************************************************************************************/
VD fn_bsm_con_jdg_object_probability(NORMAL_BSM* past_a_normal2)
{
	U1 u1_t_lp_num_normal;
	U1 u1_t_lp_num_normal2;
	FL fl_t_power_bin;
	FL fl_t_power_doa;
	U1 u1_t_num_around;
	U1 u1_t_jdg_m2_flg;
	U1 u1_t_jdg_m8_flg;

	for (u1_t_lp_num_normal = (U1)0; u1_t_lp_num_normal < NORMAL_BUFFSIZE; u1_t_lp_num_normal ++) {
		if (past_a_normal2[u1_t_lp_num_normal].fl_Robs != CFL_UNKNOWN_VALUE) {
			/*  ����ΏۃG���A�����𔻒肷��B�i�x��G���A�t�߂̕��W�ɍi��j */
			/* ����m2�̔���֐��R�[�� ����m2�����֐�������Ă���̂͂��ē��ڊp�x�ɂ���������������Ă�������	*/
			/* �����͓��ꂳ�ꂽ���A�����g�p����ύX�������Ȃ����߁A�֐��͂��̂܂܂Ƃ���								*/
			/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�						*/
			u1_t_jdg_m2_flg = u1_bsm_con_jdg_obj_probability_m2(past_a_normal2[u1_t_lp_num_normal].fl_Ryfil);
			
			if ((u1_t_jdg_m2_flg == CU1_TRUE)																															/* COND.m2 */
			&&  ((past_a_normal2[u1_t_lp_num_normal].fl_Ryfil + past_a_normal2[u1_t_lp_num_normal].fl_Vyfil) >= ((CFL_ALARM_Y_BACKWARD - ALARM_Y_OFFSET) - (FL)3.0F))	/* COND.m4 */
			&&	(past_a_normal2[u1_t_lp_num_normal].s4_flg_dc != OBJECT_TYPE_SOT)) {																					/* COND.m5 */
				/* FFT �d�͂ƕ��ʓd�͂��Z�o���� (���̎��_�œ����g���⓯��bin�̏�񂪂Ȃ����ߏ�L�ő�p) */
				fl_t_power_bin = (FL)0.5F * (past_a_normal2[u1_t_lp_num_normal].fl_power_up + past_a_normal2[u1_t_lp_num_normal].fl_power_dn);
				fl_t_power_doa = (FL)0.5F * (past_a_normal2[u1_t_lp_num_normal].fl_power_up_music + past_a_normal2[u1_t_lp_num_normal].fl_power_dn_music);
				
				/* a)  �d�͂ɂ�锻�� */
				/* ����m8�̔���֐��R�[�� ����m8�����֐�������Ă���̂͂��ē��ڊp�x�ɂ���������������Ă�������	*/
				/* �����͓��ꂳ�ꂽ���A�����g�p����ύX�������Ȃ����߁A�֐��͂��̂܂܂Ƃ���								*/
				/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�						*/
				u1_t_jdg_m8_flg = u1_bsm_con_jdg_obj_probability_m8(fl_t_power_doa);

				if ((fl_t_power_doa > (fl_t_power_bin - (FL)5.0F))									/* COND.m7 */
				||	(u1_t_jdg_m8_flg == CU1_TRUE)) {												/* COND.m8 */
					past_a_normal2[u1_t_lp_num_normal].s4_flg_reliable = (S4)1;
				}
				
				/* b)  �O�}�ɂ�锻�� */
				if (past_a_normal2[u1_t_lp_num_normal].s4_flg_lost >= (S4)5) {						/* COND.m9 */
					past_a_normal2[u1_t_lp_num_normal].s4_flg_reliable = (S4)0;
				}
				
				/* c)  ���W���x�ɂ�锻�� */
				if (past_a_normal2[u1_t_lp_num_normal].s4_flg_reliable == (S4)0) {
					u1_t_num_around = (U1)0;
					for (u1_t_lp_num_normal2 = (U1)0; u1_t_lp_num_normal2 < NORMAL_BUFFSIZE; u1_t_lp_num_normal2++) {
						if ((u1_t_lp_num_normal != u1_t_lp_num_normal2)
						&&	(fl_abs(past_a_normal2[u1_t_lp_num_normal].fl_Ryfil - past_a_normal2[u1_t_lp_num_normal2].fl_Ryfil) < (FL)2.0F)			/* COND.m11 */
						&&	(fl_abs(past_a_normal2[u1_t_lp_num_normal].fl_Rxfil - past_a_normal2[u1_t_lp_num_normal2].fl_Rxfil) < (FL)2.0F)) {		/* COND.m12 */
							u1_t_num_around++;
						}
						
						if (u1_t_num_around >= (U1)3) {
							past_a_normal2[u1_t_lp_num_normal].s4_flg_reliable = (S4)1;
						}
					}
				}
			} else {
				past_a_normal2[u1_t_lp_num_normal].s4_flg_reliable = (S4)1;
			}
		}
	}
	
	return;
}

/********************************************************************************************/
/* �֐���		: u1_bsm_con_jdg_obj_probability_m2()										*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�̎��̔���̏���m2����֐�											*/
/*------------------------------------------------------------------------------------------*/
/* ����			: fl_a_Ryfil					: ���ݕ��W��Y���������o�͒l [in]			*/
/* �߂�l		: u1_t_jdg_m2_flag				: ����m2�̔��茋�ʊi�[�ϐ�					*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fl_abs()																	*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-015 (7)   ���W�̎��̔��� ����m2				*/
/********************************************************************************************/
U1 u1_bsm_con_jdg_obj_probability_m2(FL fl_a_Ryfil)
{
	/* ����m2���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_m2_flag;				/* ����m2���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_m2_flag = CU1_FALSE;

	/* ����m2�̔��� */
	if (fl_abs(fl_a_Ryfil) > EKF_RY_SIDE) {
		u1_t_jdg_m2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_m2_flag = CU1_FALSE;
	}

	return u1_t_jdg_m2_flag;
}

/********************************************************************************************/
/* �֐���		: u1_bsm_con_jdg_obj_probability_m8()										*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�̎��̔���̏���m8����֐�											*/
/*------------------------------------------------------------------------------------------*/
/* ����			: fl_a_power_doa				: ���W�̎��̔���ō쐬���ꂽ���ʓd�� [in]	*/
/* �߂�l		: u1_t_jdg_m8_flag				: ����m8�̔��茋�ʊi�[�ϐ�					*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-015 (7)   ���W�̎��̔��� ����m8				*/
/********************************************************************************************/
U1 u1_bsm_con_jdg_obj_probability_m8(FL fl_a_power_doa)
{
	/* ����m8���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_m8_flag;				/* ����m8���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_m8_flag = CU1_FALSE;

	/* ����m8�̔��� */
	if (fl_a_power_doa > (FL)50.0F) {
		u1_t_jdg_m8_flag = CU1_TRUE;
	} else {
		u1_t_jdg_m8_flag = CU1_FALSE;
	}

	return u1_t_jdg_m8_flag;
}


/* select target objects from detected objects */
/* @return :number of selected objects */
/* @param :see below */
S4 select_target(
	S4 target_num_prev,				/* [in] */
	const NORMAL_BSM* target_prev,		/* [in] */

	S4* target_num,					/* [out] [1] number of target */
	NORMAL_BSM* target_current,		/* [out] */

	const S4* normal_num,					/* [in/out] [0] current number of pair */
	const NORMAL_BSM* normal_current,		/* [in] */

	U1 u1_a_alarming_flag
)
{
	S4 i;
	NORMAL_BSM copy_target_prev[TARGET_BUFFSIZE];
	NORMAL_BSM copy_normal_current[NORMAL_BUFFSIZE];
	NORMAL_BSM tmp_normal_buff[NORMAL_BUFFSIZE];
	S4 tmp_normal_num[1];
	S4 tmp_target_num[1];

	S4 object_num;
	S4 used_ID[TARGET_BUFFSIZE];

	S4 tmptmp_target_num = 0;

	S4 wall_bin = 270;


	/* ���������������������������������������� (�@)����ڑ����̊m�F */
	copy_normal_data(target_prev, copy_target_prev, TARGET_BUFFSIZE);
	copy_normal_data(normal_current, copy_normal_current, NORMAL_BUFFSIZE);
	fn_init(tmp_normal_buff, NORMAL_BUFFSIZE);

	/* ���������������������������������������� (�A)����ڑ����̊m�F */
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
		copy_target_prev[i].s4_flg_used = 0;	/*�g�p�ς݃t���O���Z�b�g */
		used_ID[i] = 0;
	}

	tmp_normal_num[0] = *normal_num;
	tmp_target_num[0] = 0;

/*********************************************************************************************/
/*********  1) Garbage object removal ********************************************************/
/*********     �s�v���W�̍폜         ********************************************************/
/*********************************************************************************************/
	fn_bsm_sel_exclude_object(
		tmp_normal_num[0],
		copy_normal_current,
		target_num_prev,
		(const NORMAL_BSM (*))copy_target_prev
	);

/*********************************************************************************************/
/********* 2) Empty buffer trimming **********************************************************/
/*********    �󂫃o�b�t�@���l�߂�  **********************************************************/
/*********************************************************************************************/
	/*  ��X���b�g���l�߂Ďg�p�ς݃t���O�����Z�b�g*/
	object_num = s4_bsm_sel_empty_buf_trimming(
		copy_normal_current
	);

/*********************************************************************************************/
/********* 3) Sorting in distance order ******************************************************/
/*********    �������ɕ��בւ�          ******************************************************/
/*********************************************************************************************/
	/* �c�������̂��������ɕ��ёւ� */
	fn_sort_normal(copy_normal_current);

	/* �^�[�Q�b�g���������ɕ��ёւ� */
	fn_sort_target(copy_target_prev);

/*********************************************************************************************/
/*********  �I�𕨕W�̃g���b�L���O  **********************************************************/
/*********************************************************************************************/
	/* �O���TARGET�̗\���l�Ɣ�r */
	tmp_target_num[0] = 0;
	wall_bin = (S4)(st_g_bsm_loop_data.afl_wall_width[0]/RCOF*0.5F)+NB_FFT_PT/2 - 1;
	
	fn_bsm_sel_connect_target(
		object_num,
		copy_normal_current,
		target_num_prev,
		copy_target_prev,
		used_ID,
		&tmp_target_num[0],
		target_current
	);

	/* trim target data */
	tmptmp_target_num = 0;
	tmptmp_target_num = s4_copy_prediction_to_filtered_data(
		target_current,
		TARGET_BUFFSIZE
	);
	tmp_target_num[0] = tmptmp_target_num;

/*********************************************************************************************/
/********* 7) Target extrapolation ***********************************************************/
/*********    �^�[�Q�b�g�O�}       ***********************************************************/
/*********************************************************************************************/
	fn_bsm_sel_extrapolate_target(
		target_num_prev,
		copy_target_prev,
		&tmp_target_num[0],
		target_current,
		used_ID
	);

	/* trim target data */
	tmptmp_target_num = s4_copy_prediction_to_filtered_data(
		target_current,
		TARGET_BUFFSIZE
	);
	tmp_target_num[0] = tmptmp_target_num;

/*********************************************************************************************/
/********* 8) New target addition ************************************************************/
/*********    �V�K�^�[�Q�b�g�ǉ�  ************************************************************/
/*********************************************************************************************/
	fn_bsm_sel_add_target(
		object_num,
		copy_normal_current,
		&tmp_target_num[0],
		target_current,
		used_ID
	);

	/* trim target data */
	tmptmp_target_num = s4_copy_prediction_to_filtered_data(
		target_current,
		TARGET_BUFFSIZE
	);
	tmp_target_num[0] = tmptmp_target_num;

/*********************************************************************************************/
/********* 9) Target clustering       ********************************************************/
/*********    ����^�[�Q�b�g�̊m�F    ********************************************************/
/*********************************************************************************************/
	tmp_target_num[0] = cluster_target(
		tmp_target_num[0],
		target_current,
		used_ID
	);

/*********************************************************************************************/
/********* 10) Garbage target removal ********************************************************/
/*********     �s�v�^�[�Q�b�g�̍폜   ********************************************************/
/*********************************************************************************************/
	fn_bsm_sel_exclude_target(
		tmp_target_num[0],
		target_current
	);

/*********************************************************************************************/
/********* 11) Empty buffer trimming *********************************************************/
/*********     �󂫃o�b�t�@���l�߂�  *********************************************************/
/*********************************************************************************************/
	fn_bsm_sel_empty_buf_trgt_trimming(
		&tmp_target_num[0],
		target_current
	);

/*********************************************************************************************/
/******** 12) �^�[�Q�b�g���̃}�[�L���O *****************************************************/
/*********************************************************************************************/
	fn_bsm_sel_target_marking(tmp_target_num[0], target_current, u1_a_alarming_flag);

	*target_num = tmp_target_num[0];
	object_num = tmp_target_num[0];
	return object_num;
}

static VD fn_bsm_sel_exclude_object(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
)
{
	fn_bsm_sel_reset_stop_flg(
		s4_a_pair_num_current,
		ast_a_normal_current,
		s4_a_target_num_prev,
		ast_a_target_prev
	);
	
	fn_bsm_sel_exobj_same_peaks(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
	
	fn_bsm_sel_exobj_stationary(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
	
	fn_bsm_sel_exobj_around_mycar(
		s4_a_pair_num_current,
		ast_a_normal_current
	);

	fn_bsm_sel_exobj_outside_load(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
	
	fn_bsm_sel_exobj_outside_to_fr(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
	
	fn_bsm_sel_exobj_like_wall(
		s4_a_pair_num_current,
		ast_a_normal_current
	);

	fn_bsm_sel_exobj_stag_just_beside(
		s4_a_pair_num_current,
		ast_a_normal_current,
		s4_a_target_num_prev,
		ast_a_target_prev
	);
	
	fn_bsm_sel_exobj_outside(
		s4_a_pair_num_current,
		ast_a_normal_current,
		s4_a_target_num_prev,
		ast_a_target_prev
	);
	
	fn_bsm_sel_exobj_non_sot_obj(
		s4_a_pair_num_current,
		ast_a_normal_current
	);

#ifndef _010B_2A_JP_20170125_REINFORCE
	fn_bsm_sel_exobj_bumper_reflection(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
#endif

#if !defined(_291B_DEV_20161005_BTT_TEST) &&  !defined(_20170224_BTT_TFLAG_FA)
	fn_bsm_sel_exobj_incor_trailer_obj(
		s4_a_pair_num_current,
		ast_a_normal_current
	);
	//st_g_btt_stat.BTT_drv
#endif

	return;
}

static VD fn_bsm_sel_reset_stop_flg(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 j;

	/* ���������������������������������������� (�B)reset stop_flag of potential connectable object */
	for(i=0; i<s4_a_target_num_prev; i++)
	{
		for(j=0; j<s4_a_pair_num_current; j++)
		{
			if ((fl_abs(ast_a_target_prev[i].fl_Rxfil-ast_a_normal_current[j].fl_Rxfil) < RX_TH_TT)		/* COND. a1 */
			&&  (fl_abs(ast_a_target_prev[i].fl_Ryfil-ast_a_normal_current[j].fl_Ryfil) < RY_TH_TT)) {	/* COND. a2 */
				ast_a_normal_current[j].s4_flg_stop = 0;
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_same_peaks(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;
	S4 j;

	/* ���������������������������������������� (�C)erase object based on same peaks */
	for( i=0; i<s4_a_pair_num_current; i++ )
	{
		for( j=0; j<s4_a_pair_num_current; j++ )
		{
			if ((i!= j)																						/* COND.b1 */
			&&  (ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)										/* COND.b2 */
			&&  (ast_a_normal_current[j].fl_Robs != CFL_UNKNOWN_VALUE)										/* COND.b3 */
			&&  (ast_a_normal_current[i].s4_bin_up == ast_a_normal_current[j].s4_bin_up)					/* COND.b4 */
			&&  (ast_a_normal_current[i].s4_bin_dn == ast_a_normal_current[j].s4_bin_dn)					/* COND.b5 */
			&&  (ast_a_normal_current[i].s4_bin_up_music == ast_a_normal_current[j].s4_bin_up_music)		/* COND.b6 */
			&&  (ast_a_normal_current[i].s4_bin_dn_music == ast_a_normal_current[j].s4_bin_dn_music)) {		/* COND.b7 */
				if ((ast_a_normal_current[i].s4_flg_dc != OBJECT_TYPE_PRIOR)								/* COND.!b8 */
				&&  (ast_a_normal_current[j].s4_flg_dc == OBJECT_TYPE_PRIOR)) {								/* COND.b9 */
					if (ast_a_normal_current[j].s4_flg_track > ast_a_normal_current[i].s4_flg_track) {		/* COND.b10 */
						ast_a_normal_current[i].s4_flg_track = ast_a_normal_current[j].s4_flg_track;
					}
					fn_init( &ast_a_normal_current[j], 1 );
				}

				if ((ast_a_normal_current[i].s4_flg_dc == OBJECT_TYPE_PRIOR)								/* COND.b8 */
				&&  (ast_a_normal_current[j].s4_flg_dc != OBJECT_TYPE_PRIOR)) {								/* COND.!b9 */
					if (ast_a_normal_current[i].s4_flg_track > ast_a_normal_current[j].s4_flg_track) {		/* COND.!b10 */
						ast_a_normal_current[j].s4_flg_track = ast_a_normal_current[i].s4_flg_track;
					}
					fn_init( &ast_a_normal_current[i], 1 );
				}
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_stationary(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�D)��~�����폜 */
	for( i=0; i<s4_a_pair_num_current; i++ )
	{
		if( ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE )			/* COND.b2 */
		{
			if(	ast_a_normal_current[i].s4_flg_stop ==1 )					/* COND.c1 */
			{
				fn_init( &ast_a_normal_current[i], 1 );
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_around_mycar(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�E)���Ԃ̋߂��̂��̂��폜 */
	for( i=0; i<s4_a_pair_num_current; i++ )
	{
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND.b2 */
		&&  (ast_a_normal_current[i].s4_flg_track <= PRIOR_TRK_NUM)				/* COND.d1 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_up == 0)						/* COND.d2 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_dn == 0)) {					/* COND.d3 */
			if ((ast_a_normal_current[i].fl_Rxfil < RX_AROUND_TH_TT)			/* COND.d4 */
			&&  (ast_a_normal_current[i].fl_Ryfil > RY_AROUND_TH_TT)) {			/* COND.d5 */
				fn_init( &ast_a_normal_current[i], 1 );
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_outside_load(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	S4 tmp_Rx_i;
	FL tmp_tmp_Rx;

	/* ���������������������������������������� (�F)���H�̊O���̂��̂��폜 */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)			/* COND.b2 */
		&&  (ast_a_normal_current[i].s4_flg_track <= PRIOR_TRK_NUM)			/* COND.d1 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_up == 0)					/* COND.d2 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_dn == 0)) {				/* COND.d3 */
			/* ���̕��͍폜���Ȃ��ł��� */
			if (ast_a_normal_current[i].fl_Ryfil > RY_WALL_LIMIT_TT) {		/* COND.e1 */
				tmp_Rx_i = (S4)(-ast_a_normal_current[i].fl_Ryfil);
				if(tmp_Rx_i < 0)
				{
					tmp_Rx_i = 0;
				}
				if(tmp_Rx_i > 69)
				{
					tmp_Rx_i = 69;
				}
				tmp_tmp_Rx = st_g_bsm_loop_data.afl_Rx_right[tmp_Rx_i];
				if ((tmp_tmp_Rx - 0.5F) <= ast_a_normal_current[i].fl_Rxfil) {	/* COND.e2 */
					fn_init( &ast_a_normal_current[i], 1 );
				}
			}
		} else if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)		/* COND.b2 */
			   &&  (ast_a_normal_current[i].s4_flg_track > PRIOR_TRK_NUM)) {	/* COND.!d1 */
			/* �D�敨�W�ł��ǂ��炩�Ȃ藣��Ă������ */
			/* ���̕��͍폜���Ȃ��ł��� */
			if (ast_a_normal_current[i].fl_Ryfil > RY_WALL_LIMIT_TT) {			/* COND.e1 */
				tmp_Rx_i = (S4)(-ast_a_normal_current[i].fl_Ryfil);
				if(tmp_Rx_i < 0)
				{
					tmp_Rx_i = 0;
				}
				if(tmp_Rx_i > 69)
				{
					tmp_Rx_i = 69;
				}
				tmp_tmp_Rx = st_g_bsm_loop_data.afl_Rx_right[tmp_Rx_i];
				if ((tmp_tmp_Rx + 1.5F) <= ast_a_normal_current[i].fl_Rxfil) {	/* COND.e3 */
					fn_init( &ast_a_normal_current[i], 1 );
				}
			}
		} else {
			/* �������Ȃ� */
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_outside_to_fr(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�G)���o�����O�i�O���j�ɏo�čs�����̂��폜 */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if (ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {				/* COND.b2 */
			if ((ast_a_normal_current[i].fl_Vyfil >= 0.0F)						/* COND.f1 */
			&&  (ast_a_normal_current[i].fl_Ryfil > CANOUT_Y_MAX_TOS)) {		/* COND.f2 */
				fn_init( &ast_a_normal_current[i], 1 );
			} else if (ast_a_normal_current[i].fl_Ryfil > CANOUT_Y_MAX_SOT) {	/* COND.f3 */
				fn_init( &ast_a_normal_current[i], 1 );
			} else {
				/* �������Ȃ� */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_like_wall(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�H)�ǂƎv�������̂��폜 */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)						/* COND.b2 */
		&&  (ast_a_normal_current[i].s4_flg_track <= PRIOR_TRK_NUM)						/* COND.d1 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_up == 0)								/* COND.d2 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_dn == 0)) {							/* COND.d3 */
			/* ���̕��͍폜���Ȃ��ł��� */
			if (ast_a_normal_current[i].fl_Ryfil > RY_WALL_LIMIT_TT) {					/* COND.e1 */
				/* �ǂ�����������(������ƃN���A�����X����������) */
				if ((ast_a_normal_current[i].fl_Rxfil >= (st_g_bsm_loop_data.afl_wall_width[0] - 0.3F))		/* COND.g1 */
				&&  (ast_a_normal_current[i].fl_Ryfil < 0)													/* COND.g2 */
				&&  (ast_a_normal_current[i].fl_Vyfil <= 0)) {												/* COND.g3 */
					fn_init( &ast_a_normal_current[i], 1 );
				}
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_stag_just_beside(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 j;

	/* ���������������������������������������� (�I)�^���ɒ�؂��镨�W�̍폜 */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)										/* COND.b2 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_up == 0)												/* COND.d2 */
		&&  (ast_a_normal_current[i].s4_flg_heiso_dn == 0)) {											/* COND.d3 */
			if ((fl_abs(ast_a_normal_current[i].fl_Ryobs) < 0.5F)											/* COND.h1 */
			&&  (fl_abs(ast_a_normal_current[i].fl_Rypred) < 1.0F)											/* COND.h2 */
			&&  (ast_a_normal_current[i].fl_Rxfil > (st_g_bsm_loop_data.afl_wall_width[0] - 1.0F))) {		/* COND.h3 */
				if ((st_g_bsm_loop_data.as4_flg_leading[0] == 0)											/* COND.h4 */
				&&  (st_g_bsm_loop_data.as4_flg_passing[0] < PASSING_COUNT_MIN)) {							/* COND.h5 */
					fn_init( &ast_a_normal_current[i], 1 );
				} else {
					/* �����^�[�Q�b�g�̋߂����m�F */
					for( j = 0; j < TARGET_BUFFSIZE; j++ )					/* �s��ł͂Ȃ����H s4_a_target_num_prev ���g���Ă��Ȃ� */
					{
						if (ast_a_target_prev[j].fl_Robs != CFL_UNKNOWN_VALUE) {	/* COND.h6 */
							if ((fl_abs(ast_a_target_prev[j].fl_Rxpred - ast_a_normal_current[i].fl_Rxfil) > TOS_SIDE_RX_DIFF)		/* COND.h7 */
							||  (fl_abs(ast_a_target_prev[j].fl_Rypred - ast_a_normal_current[i].fl_Ryfil) > TOS_SIDE_RY_DIFF)) {	/* COND.h8 */
								fn_init( &ast_a_normal_current[i], 1 );
								break;
							}
						}
					}
				}
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_outside(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 tmp_side_passing_flg;
	
	tmp_side_passing_flg = 0;

	/* ���������������������������������������� (�I�@)erase side object */
	if (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN) {				/* COND.i1 */
		for (i = 0; i < s4_a_target_num_prev; i++) {
			if ((ast_a_target_prev[i].fl_Rypred + RY_TH_TT) > -EKF_RY_SIDE) {	/* COND.i2 */
				tmp_side_passing_flg = 1;
			}
		}
	}
	for (i = 0; i < s4_a_pair_num_current; i++) {
		if (ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {				/* COND.b2 */
			if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == 0)					/* COND.i3 */
			&&  (tmp_side_passing_flg == 0)										/* COND.i4 */
			&&  (st_g_bsm_loop_data.as4_flg_leading[0] == 0)					/* COND.i5 */
			&&  (fl_abs(ast_a_normal_current[i].fl_Ryfil) < EKF_RY_SIDE)) {		/* COND.i6 */
				fn_init( &ast_a_normal_current[i], 1 );
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exobj_non_sot_obj(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 i;

	S4 tmp_Rx_i;
	FL tmp_tmp_Rx;

	/* ���������������������������������������� (xii)erase non-sot object */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if (ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {				/* COND.b2 */
			tmp_Rx_i = (S4)(-ast_a_normal_current[i].fl_Ryfil);
			if(tmp_Rx_i < 0)
			{
				tmp_Rx_i = 0;
			}
			if(tmp_Rx_i > 69)
			{
				tmp_Rx_i = 69;
			}
			tmp_tmp_Rx = st_g_bsm_loop_data.afl_Rx_right[tmp_Rx_i];


			if (st_g_bsm_loop_data.as4_slow_sot_find[1] >= WALL_REJECT_TH3) {		/* COND.i7 */
				if ((ast_a_normal_current[i].fl_Rxobs >= (tmp_tmp_Rx - 1.5F))		/* COND.i8 */
				&&  (fl_abs(ast_a_normal_current[i].fl_Ryfil) > EKF_RY_SIDE)) {		/* COND.i9 */
					fn_init( &ast_a_normal_current[i], 1 );
				} else if ((ast_a_normal_current[i].fl_Rxobs >= (tmp_tmp_Rx - 0.5F))		/* COND.i10 */
					   &&  (ast_a_normal_current[i].fl_Ryfil > RY_WALL_LIMIT_TT)) {			/* COND.i11 */
					fn_init( &ast_a_normal_current[i], 1 );
				} else {
					/* �������Ȃ� */
				}
			}
		}
	}

	return;
}

/****************************************************************************/
/* �֐���		: fn_bsm_sel_exobj_bumper_reflection()						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: Erase �o���p����  object									*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_pair_num_current			: NORMAL���W�� [in]		*/
/*				: ast_a_normal_current[]		: NORMAL���W��� [in/out]	*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>  	: st_g_bsm_loop_data.as4_slow_sot_find[1]	: �ǃt���O		*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fl_smap_new, fl_abs, fn_init								*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-023 (8)�^�[�Q�b�g�I������ 	*/
/*				  1)���O���镨�W�̔��� (xiii)Erase �o���p����  object		*/
/****************************************************************************/
static VD fn_bsm_sel_exobj_bumper_reflection(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	S4 s4_t_lp_normal;			/* NORMAL���W�̃��[�v�ϐ� �d�l���ł�i */
	FL fl_t_thd_exobj_range;	/* ���W����臒l�i�����j [m] */
	FL fl_t_thd_exobj_power;	/* ���W����臒l�i�d�́j [dB] */
	FL fl_t_obj_power;			/* ����n6�̕��ϕ��ʓd�͊i�[�ϐ� */
	FL fl_t_abs_robs;			/* Robs�̐�Βl�i�[�ϐ� */
	FL fl_t_abs_vobs;			/* Vobs�̐�Βl�i�[�ϐ� */

	const FL CFL_D_MAP_EXOBJ_POWER[CU2_MAP_EXOBJ_POWER_INDEX][2] = {
		/* ��������[m]  �d��臒l[dB] */
		{(FL)1.0,		(FL)72.0},
		{(FL)2.0,		(FL)65.0},
		{(FL)2.5,		(FL)62.5},
		{(FL)3.0,		(FL)57.7},
		{(FL)4.0,		(FL)52.7},
		{(FL)5.0,		(FL)48.9},
		{(FL)6.0,		(FL)45.7},
		{(FL)9.0,		(FL)38.6}
	};

	for (s4_t_lp_normal = (S4)0; s4_t_lp_normal < s4_a_pair_num_current; s4_t_lp_normal++) {
		if (ast_a_normal_current[s4_t_lp_normal].fl_Robs != CFL_UNKNOWN_VALUE) {			/* COND.b2 */
			/* �����`�F�b�N�p�Ɋe����ϊ� */
			fl_t_obj_power = (ast_a_normal_current[s4_t_lp_normal].fl_power_up_music + ast_a_normal_current[s4_t_lp_normal].fl_power_dn_music) * (FL)0.5;
			fl_t_abs_robs = fl_abs(ast_a_normal_current[s4_t_lp_normal].fl_Robs);
			fl_t_abs_vobs = fl_abs(ast_a_normal_current[s4_t_lp_normal].fl_Vobs);

			/* 臒l��ݒ� */
			fl_t_thd_exobj_range = (FL)9.0;
			fl_t_thd_exobj_power = fl_smap_new(CFL_D_MAP_EXOBJ_POWER, CU2_MAP_EXOBJ_POWER_INDEX, fl_t_abs_robs);

			/* �s�v���W���폜 */
			if ((ast_a_normal_current[s4_t_lp_normal].s4_flg_dc != (S4)OBJECT_TYPE_2F)		/* COND.n2 */
			&&	(fl_t_abs_robs < fl_t_thd_exobj_range)										/* COND.n3 */
			&&	(ast_a_normal_current[s4_t_lp_normal].fl_Ryobs < (FL)-EKF_RY_SIDE)			/* COND.n4 */
			&&	(fl_t_abs_vobs < ((FL)5.0 * (FL)VCOF))										/* COND.n5 */
			&&	(fl_t_obj_power < fl_t_thd_exobj_power)) {									/* COND.n6 */
				fn_init(&ast_a_normal_current[s4_t_lp_normal], (S4)1);
			}
		}
	}

	return;
}

#if !defined(_291B_DEV_20161005_BTT_TEST) &&  !defined(_20170224_BTT_TFLAG_FA)
static VD fn_bsm_sel_exobj_incor_trailer_obj(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	st_g_btt_stat.BTT_drv;
	return;
}
#endif

static S4 s4_bsm_sel_empty_buf_trimming(
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE]
)
{
	/* ��X���b�g�������ǂ̂��߂̕ϐ� */
	S4 s2_t_in[NORMAL_BUFFSIZE];
	S4 s2_t_loop;
	S4 s2_t_num;

	S4 s4_t_object_num;

	/* ��X���b�g���l�߂Ďg�p�ς݃t���O�����Z�b�g */
	s4_t_object_num = 0;
	s2_t_num = 0;
	for (s2_t_loop = 0; s2_t_loop < NORMAL_BUFFSIZE; s2_t_loop++) {
		if (ast_a_normal_current[s2_t_loop].fl_Robs != CFL_UNKNOWN_VALUE) {		/*���g�������Ă��邩�ǂ����̊m�F�p */
			s2_t_in[s2_t_num] = s2_t_loop;
			ast_a_normal_current[s2_t_loop].s4_flg_used = 0;	/* �g�p�ς݃t���O���Z�b�g */
			s2_t_num++;
		}
	}

	s4_t_object_num = s2_t_num;

	if (s2_t_num > 0) {
		for (s2_t_loop = 0; s2_t_loop < s2_t_num; s2_t_loop++) {
			ast_a_normal_current[s2_t_loop] = ast_a_normal_current[s2_t_in[s2_t_loop]];
		}

		/* �s�v�ƂȂ������͏��������� */
		for (s2_t_loop = s2_t_num; s2_t_loop < NORMAL_BUFFSIZE; s2_t_loop++) {
			fn_init(&ast_a_normal_current[s2_t_loop], 1);
		}
	}

	return s4_t_object_num;
}

static VD fn_bsm_sel_connect_target(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_num_prev,
	NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 k;

	S4 s4_t_sample_num;
	S4 as4_t_sample_indexs[NORMAL_BUFFSIZE];
	S4 as4_t_sample_indexs_prev[NORMAL_BUFFSIZE];

	S4 s4_t_select_index;

	for( i = 0; i < s4_a_target_num_prev; i++ )
	{

		s4_t_sample_num = 0;
		for( k = 0; k < NORMAL_BUFFSIZE; k++ )
		{
			as4_t_sample_indexs[k]=-1;
			as4_t_sample_indexs_prev[k]=-1;
		}

		if ((ast_a_target_prev[i].fl_Vypred > 5.0F)							/* COND.k40 */
		&&  (ast_a_target_prev[i].fl_Rypred > -1.5F)) {						/* COND.k41 */
			ast_a_target_prev[i].s4_flg_single_peak_up = 1;					/* PROC.16 */
		}

		/* ���������������������������������������� (�@)����ڑ����̊m�F */
		fn_bsm_sel_search_sample(
			s4_a_pair_num_current,
			(const NORMAL_BSM (*))ast_a_normal_current,
			i,
			(const NORMAL_BSM (*))ast_a_target_prev,
			&s4_t_sample_num,
			as4_t_sample_indexs,
			as4_t_sample_indexs_prev
		);

		/* ���������������������������������������� (�A)����ڑ����̊m�F */
		s4_t_select_index = s4_bsm_sel_select_sample(
			s4_a_pair_num_current,
			(const NORMAL_BSM (*))ast_a_normal_current,
			s4_a_target_num_prev,
			(const NORMAL_BSM (*))ast_a_target_prev,
			s4_t_sample_num,
			(const S4 (*))as4_t_sample_indexs,
			(const S4 (*))as4_t_sample_indexs_prev
		);

		if( s4_t_select_index != -1 ) {
/********* 5) Data copy from object to target ************************************************/
/*********    ���W���̃R�s�[                ************************************************/
/********* 6) Target tracking    *************************************************************/
/*********    �g���b�L���O       *************************************************************/
		fn_bsm_tracking_target(
				&ast_a_normal_current[s4_t_select_index],				/* [in]		*/
				&ast_a_target_prev[i],									/* [in]		*/
				as4_t_used_ID,											/* [out]	*/
				&ast_a_target_current[*ps4_a_target_num_current]		/* [in/out] */
			);
			(*ps4_a_target_num_current)++;			/* �s��ł͂Ȃ����H �ő�K�[�h�������Ȃ� */

		}
	}

	return;
}

static VD fn_bsm_sel_search_sample(
	S4 s4_a_pair_num_current,
	const NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_prev_index,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 *ps4_a_sample_num,
	S4 as4_a_sample_indexs[NORMAL_BUFFSIZE],
	S4 as4_a_sample_indexs_prev[NORMAL_BUFFSIZE]
)
{
	S4 i;
	S4 s4_t_wall_bin = 270;

	S4 s4_t_connect;
	FL fl_t_rx_th;
	FL fl_t_ry_th;
	FL fl_t_vx_th;
	FL fl_t_vy_th;

	s4_t_wall_bin = (S4)(st_g_bsm_loop_data.afl_wall_width[0]/RCOF*0.5F)+NB_FFT_PT/2 - 1;

		/* ���������������������������������������� (�@)����ڑ����̊m�F */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)												/* COND.k1 */
		&&  (ast_a_normal_current[i].s4_flg_used == 0)															/* COND.k2 */
		&&  ((ast_a_normal_current[i].s4_flg_lost <= 1)															/* COND.k3 */
		||   (fl_abs( (FL)(ast_a_normal_current[i].s4_bin_up - s4_t_wall_bin) ) < TARGET_LOST_WALL_BIN_DIFF)	/* COND.k4 */
		||   (fl_abs( (FL)(ast_a_normal_current[i].s4_bin_dn - s4_t_wall_bin) ) < TARGET_LOST_WALL_BIN_DIFF))	/* COND.k5 */
		&&  (ast_a_target_prev[s4_a_target_prev_index].fl_Robs != CFL_UNKNOWN_VALUE)							/* COND.k6 */
		&&  (ast_a_target_prev[s4_a_target_prev_index].s4_flg_used == 0)) {										/* COND.k7 */
			s4_t_connect = 0;

			/********* POSITION *********/
			/********* VELOCITY *********/
			fn_bsm_sel_set_search_area(
				&ast_a_normal_current[i],
				&ast_a_target_prev[s4_a_target_prev_index],
				&fl_t_rx_th,
				&fl_t_ry_th,
				&fl_t_vx_th,
				&fl_t_vy_th
			);

			/* check conditions */
			s4_t_connect = s4_bsm_sel_check_condition(
				&ast_a_normal_current[i],
				&ast_a_target_prev[s4_a_target_prev_index],
				fl_t_rx_th,
				fl_t_ry_th,
				fl_t_vx_th,
				fl_t_vy_th
			);

			if(s4_t_connect==1)					/* COND.k18 */
			{
				as4_a_sample_indexs[*ps4_a_sample_num] = i;
				as4_a_sample_indexs_prev[*ps4_a_sample_num] = s4_a_target_prev_index;
				(*ps4_a_sample_num)++;
			}
		}
	}

	return;
}

static VD fn_bsm_sel_set_search_area(
	const NORMAL_BSM ast_a_normal_current[1],
	const NORMAL_BSM ast_a_target_prev[1],
	FL *pfl_a_rx_th,
	FL *pfl_a_ry_th,
	FL *pfl_a_vx_th,
	FL *pfl_a_vy_th
)
{
	/********* POSITION *********/
	/* wider range in the distance */
	*pfl_a_rx_th = RX_TH_TT;
	*pfl_a_ry_th = RY_TH_TT;
	if(ast_a_normal_current[0].fl_Ryfil < RY_WALL_LIMIT_TT)				/* COND.k8 */
	{
		*pfl_a_rx_th = RX_TH_TT + 1.0F;
		*pfl_a_ry_th = RY_TH_TT + 1.0F;
	}

	/********* VELOCITY *********/
	/* higher range in the nearfield */
	*pfl_a_vx_th = VX_TH_TT;
	*pfl_a_vy_th = VY_TH_TT;
	if (fl_abs(ast_a_target_prev[0].fl_Rypred) < RY_CONNECT_WO_VY) {		/* COND.k9 */
		*pfl_a_vx_th = TH_TT_MAX;
		*pfl_a_vy_th = TH_TT_MAX;
	}
	if ((ast_a_target_prev[0].s4_flg_dc == OBJECT_TYPE_SOT)					/* COND.k10 */
	&&  (fl_abs(ast_a_target_prev[0].fl_Rypred) < EKF_RY_SIDE)) {			/* COND.k11 */
		*pfl_a_rx_th = RX_TH_TT_SOT;
		*pfl_a_ry_th = RY_TH_TT_SOT;
		*pfl_a_vy_th = TH_TT_MAX;
	}
	
	if (s4_abs((S4)s2_g_curvr_for_base) < (S4)130) {
		*pfl_a_rx_th = CFL_RX_TH_TT_CURVE;
		*pfl_a_ry_th = CFL_RY_TH_TT_CURVE;
	}

	return;
}

static S4 s4_bsm_sel_check_condition(
	const NORMAL_BSM ast_a_normal_current[1],
	const NORMAL_BSM ast_a_target_prev[1],
	FL fl_a_rx_th,
	FL fl_a_ry_th,
	FL fl_a_vx_th,
	FL fl_a_vy_th
)
{
	S4 s4_t_connect;
	
	s4_t_connect = 0;

	/* check conditions */
	if ((fl_abs(ast_a_target_prev[0].fl_Rxpred - ast_a_normal_current[0].fl_Rxfil) < fl_a_rx_th)					/* COND.k12 */
	&&  (fl_abs(ast_a_target_prev[0].fl_Rypred - ast_a_normal_current[0].fl_Ryfil) < fl_a_ry_th)) {					/* COND.k13 */
		if ((ast_a_target_prev[0].s4_flg_dc != OBJECT_TYPE_2F)														/* COND.k14 */
		&&  (ast_a_normal_current[0].s4_flg_dc != OBJECT_TYPE_2F)) {												/* COND.k15 */
			if ((fl_abs(ast_a_target_prev[0].fl_Vxpred - ast_a_normal_current[0].fl_Vxfil) < fl_a_vx_th)			/* COND.k16 */
			&&  (fl_abs(ast_a_target_prev[0].fl_Vypred - ast_a_normal_current[0].fl_Vyfil) < fl_a_vy_th)) {			/* COND.k17 */
				s4_t_connect=1;
			}
		}
		else
		{
			s4_t_connect=1;
		}
	}
	
	return s4_t_connect;

}

static S4 s4_bsm_sel_select_sample(
	S4 s4_a_pair_num_current,
	const NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 s4_a_target_prev_index,
	const NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 s4_a_sample_num,
	const S4 as4_a_sample_indexs[NORMAL_BUFFSIZE],
	const S4 as4_a_sample_indexs_prev[NORMAL_BUFFSIZE]
)
{
	S4 k;

	S4 s4_t_select_index;
	FL fl_t_min;
	FL fl_t_diff;
	FL fl_t_diff_x = TH_TT_MAX;
	FL fl_t_diff_y = TH_TT_MAX;
	
	/* ���������������������������������������� (�A)����ڑ����̊m�F */
	s4_t_select_index = -1;
	if(s4_a_sample_num!=0)																/* COND.k19 */
	{
		/* ��ԋ߂��̕��W������ */
		fl_t_min = RX_TH_TT + RY_TH_TT+3.1F;
		for(k=0; k<s4_a_sample_num; k++)
		{
			{
				fl_t_diff_x = (FL) (fl_abs(ast_a_normal_current[as4_a_sample_indexs[k]].fl_Rxfil - ast_a_target_prev[as4_a_sample_indexs_prev[k]].fl_Rxpred) );
				fl_t_diff_y = (FL) (fl_abs(ast_a_normal_current[as4_a_sample_indexs[k]].fl_Ryfil - ast_a_target_prev[as4_a_sample_indexs_prev[k]].fl_Rypred) );
			}
			fl_t_diff = fl_t_diff_x + fl_t_diff_y;										/* PROC.4 */
			if(fl_t_diff < fl_t_min)													/* COND.k28 */
			{
				fl_t_min = fl_t_diff;													/* PROC.1 */
				s4_t_select_index = as4_a_sample_indexs[k];								/* PROC.2 */
			}
		}
	}

	return s4_t_select_index;
}

static VD fn_bsm_tracking_target(
	NORMAL_BSM ast_a_normal_current[1],						/* [in] */
	NORMAL_BSM ast_a_target_prev[1],						/* [in] */
	S4 as4_a_used_ID[TARGET_BUFFSIZE],						/* [out] */
	NORMAL_BSM ast_a_target_current[1]						/* [in/out] */
)
{

/*********************************************************************************************/
/********* 5) Data copy from object to target  ***********************************************/
/*********    ���W���̃R�s�[                 ***********************************************/
/*********************************************************************************************/
	ast_a_normal_current[0].s4_flg_used = 1;

	ast_a_target_current[0] = ast_a_normal_current[0];
	if ((ast_a_target_current[0].s4_flg_dc == OBJECT_TYPE_2F)			/* COND.l2 */
	&&  (ast_a_target_prev[0].s4_flg_dc != OBJECT_TYPE_2F)) {			/* COND.!l3 */
		ast_a_target_current[0].fl_Vobs = ast_a_target_prev[0].fl_Vobs_pred;
		ast_a_target_current[0].fl_Vxobs = ast_a_target_prev[0].fl_Vxpred;
		ast_a_target_current[0].fl_Vyobs = ast_a_target_prev[0].fl_Vypred;
		ast_a_target_current[0].fl_Vxfil = ast_a_target_prev[0].fl_Vxpred;
		ast_a_target_current[0].fl_Vyfil = ast_a_target_prev[0].fl_Vypred;
	}
	if ((ast_a_target_current[0].s4_flg_dc != OBJECT_TYPE_2F)			/* COND.!l2 */
	&&  (ast_a_target_prev[0].s4_flg_dc == OBJECT_TYPE_2F)) {			/* COND.l3 */
		ast_a_target_prev[0].fl_Vxpred = ast_a_target_current[0].fl_Vxfil;
		ast_a_target_prev[0].fl_Vypred = ast_a_target_current[0].fl_Vyfil;
	}
	
	if ((st_g_bsm_loop_data.u1_truck_flg != (U1)0)											/* COND.i4 */
	&&  (ast_a_target_current[0].fl_Ryfil > CFL_TRUCK_RY_MIN)								/* COND.i5 */
	&&  ((ast_a_target_current[0].fl_Rxfil - ast_a_target_prev[0].fl_Rxpred) > (FL)0.0F)	/* COND.i6 */
	&&  (ast_a_target_current[0].fl_Rxfil > CFL_TRUCK_RX_MIN)								/* COND.i7 */
	&&  (ast_a_target_current[0].fl_Rxfil < CFL_TRUCK_RX_MAX)) {							/* COND.i8 */
		ast_a_target_current[0].fl_Rxfil -= CFL_TRUCK_WIDTH;								/* PROC.4 */
		ast_a_target_current[0].fl_Vxfil = (FL)0.0F;										/* PROC.5 */
	}

/*********************************************************************************************/
/********* 6) Target tracking      ***********************************************************/
/*********    �g���b�L���O         ***********************************************************/
/*********************************************************************************************/
	/* �����g���b�J */
	ast_a_target_prev[0].s4_flg_used = 1;	/*sample_indexs_prev[0�`sample_num]=i ������ [i]��OK */
	fn_ab_track(
		&ast_a_target_prev[0],
		&ast_a_target_current[0],
		1
	);
	calc_prediction_of_normaldata(
		&ast_a_target_current[0]
	);

	/* �t���O�ݒ� */
	if (ast_a_target_current[0].s4_flg_track == CS4_S4MAX) {
		/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
	} else {
		ast_a_target_current[0].s4_flg_track = ast_a_target_prev[0].s4_flg_track+(S4)1;
	}

	ast_a_target_current[0].s4_flg_new = 0;
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	if ((ast_a_target_current[0].fl_Ryfil > -EKF_RY_SIDE)
	&&  (ast_a_normal_current[0].s4_flg_dc == OBJECT_TYPE_2F)) {
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	if (((S2)s4_abs(s2_g_curvr_for_base) < (S2)2200)
	&&  (ast_a_normal_current[0].s4_flg_dc == OBJECT_TYPE_2F)) {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
		ast_a_target_current[0].s4_flg_new = ast_a_normal_current[0].s4_flg_new;
	}
	
	ast_a_target_current[0].s4_flg_lost = 0;
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	if (ast_a_normal_current[0].s4_flg_dc == OBJECT_TYPE_2F) {
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	if (((S2)s4_abs(s2_g_curvr_for_base) < (S2)2200)
	&&  (ast_a_normal_current[0].s4_flg_dc == OBJECT_TYPE_2F)) {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
		ast_a_target_current[0].s4_flg_lost = ast_a_normal_current[0].s4_flg_lost;
	}
	
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	ast_a_target_current[0].s4_tracked = (S4)1;
	ast_a_target_prev[0].s4_tracked = (S4)1;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
	
	ast_a_target_current[0].s4_flg_used = 1;
	ast_a_target_current[0].s4_flg_single_peak_up = ast_a_target_prev[0].s4_flg_single_peak_up;
	ast_a_target_current[0].u4_ctr_fa = ast_a_target_prev[0].u4_ctr_fa;
	ast_a_target_current[0].s4_ctr_sot_cut = ast_a_target_prev[0].s4_ctr_sot_cut;
	
	/* �M���t���O */
	/* i)  �ϑ��l�A�O��l�̈����ON�ł���΁AON��ݒ肷��B  */
	if ((ast_a_normal_current[0].s4_flg_reliable == (S4)1)
	||  (ast_a_target_prev[0].s4_flg_reliable == (S4)1)) {
		ast_a_target_current[0].s4_flg_reliable = (S4)1;
	}
	
	/* ii)  �ϑ��l���A���O�}���Ă���ꍇ��OFF�ɖ߂��i����ڑ��񐔂����Ȃ��ꍇ�j�B  */
	if ((ast_a_normal_current[0].s4_flg_lost >= (S4)5)
	&&  (ast_a_normal_current[0].s4_flg_track < (S4)36)) {
		ast_a_target_current[0].s4_flg_reliable = (S4)0;
	}
	
	ast_a_target_current[0].s4_ctr_tos = ast_a_target_prev[0].s4_ctr_tos;

	/* ���W�ԍ��ݒ� */
	ast_a_target_current[0].s4_ID_num = ast_a_target_prev[0].s4_ID_num;
	as4_a_used_ID[ast_a_target_prev[0].s4_ID_num-1] = 1;

	return;
}

static VD fn_bsm_sel_extrapolate_target(
	S4 s4_a_target_num_prev,
	NORMAL_BSM ast_a_target_prev[TARGET_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE]
)
{
	S4 i;

	S4 tmp_connect_num = TARGET_CONNECT_NUM;
	S4 tmp_lost_max = TARGET_LOST_MAX;
	S4 s4_t_wall_bin;

	FL fl_t_tmp_alarm_x_min = ALARM_X_IN       + ALARM_X_OFFSET_IN;
	FL fl_t_tmp_alarm_x_max = ALARM_X_OUT      + ALARM_X_OFFSET_OUT;
	FL fl_t_tmp_alarm_y_min = CFL_ALARM_Y_BACKWARD - ALARM_Y_OFFSET;
	FL fl_t_tmp_alarm_y_max = ALARM_Y_FORWARD;

	s4_t_wall_bin = (S4)(st_g_bsm_loop_data.afl_wall_width[0]/RCOF*0.5F)+NB_FFT_PT/2 - 1;

/*********************************************************************************************/
/********* 7) Target extrapolation ***********************************************************/
/*********    �^�[�Q�b�g�O�}       ***********************************************************/
/*********************************************************************************************/
	for(i=0; i<s4_a_target_num_prev; i++ )
	{
		/* set lost max */
		tmp_connect_num = TARGET_CONNECT_NUM;
		tmp_lost_max = TARGET_LOST_MAX;
		if ((st_g_bsm_loop_data.as4_flg_leading[0] != 0)												/* COND.s1 �ǔ��ԗ������� */
		||  (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN)) {								/* COND.s2 �ǉz�ԗ������� */
			/* �x��G���A�ɎԂ�����Ƃ��͌x��G���A���̕��W�͂��߂ɍĐ� */
			if ((ast_a_target_prev[i].fl_Rxpred > fl_t_tmp_alarm_x_min)				/* COND. t1 */
			&&  (ast_a_target_prev[i].fl_Rxpred < fl_t_tmp_alarm_x_max)				/* COND. t2 */
			&&  (ast_a_target_prev[i].fl_Rypred > fl_t_tmp_alarm_y_min)				/* COND. t3 */
			&&  (ast_a_target_prev[i].fl_Rypred < fl_t_tmp_alarm_y_max)) {			/* COND. t4 */
				tmp_connect_num = TARGET_CONNECT_NUM_SIDE;
				/* �^���͂��߂� */
				if (fl_abs(ast_a_target_prev[i].fl_Rypred) < EKF_RY_SIDE) {			/* COND. t5 */
					tmp_lost_max = TARGET_LOST_MAX_SIDE;
					if (ast_a_target_prev[i].s4_flg_single_peak_up == 1) {			/* COND.t24 */
						tmp_lost_max = 0;
					}
				} else if ((ast_a_target_prev[i].fl_Rxpred > (fl_t_tmp_alarm_x_min + 1.0F))		/* COND. t6 */
					   &&  (ast_a_target_prev[i].fl_Rxpred < (fl_t_tmp_alarm_x_max - 1.0F))		/* COND. t7 */
					   &&  (ast_a_target_prev[i].fl_Rypred > (fl_t_tmp_alarm_y_min + 2.0F))		/* COND. t8 */
					   &&  (ast_a_target_prev[i].fl_Rypred < (fl_t_tmp_alarm_y_max - 2.0F))) {	/* COND. t9 */
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
					tmp_lost_max = TARGET_LOST_MAX_INAREA;
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
					if (st_g_bsm_loop_data.as4_fast_sot_flg[0] != (S4)0) {
						/* �����A��t1 and t2 and t3 and t4��������� */
						/* ���{���Ă���̂ł����ł͎��{���Ȃ� */
						tmp_lost_max = (S4)0;
					} else {
						/* �����A��t1 and t2 and t3 and t4��������� */
						/* ���{���Ă���̂ł����ł͎��{���Ȃ� */
						tmp_lost_max = TARGET_LOST_MAX_INAREA;
					}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
				} else {
					tmp_lost_max = TARGET_LOST_MAX_SOT;
				}
			} else {
				if (ast_a_target_prev[i].s4_flg_dc == OBJECT_TYPE_2F) {
					tmp_lost_max = TARGET_LOST_MAX_2F_OUTAREA;
				}
				if ((st_g_bsm_loop_data.afl_wall_width[0] - ast_a_target_prev[i].fl_Rxpred) < CFL_WALL_RANGE) {	/* COND.t25 */
					tmp_lost_max = TARGET_LOST_MAX_SIDE;
				}

				/* ��014-1 Add extrapolationcycle reset when no target. */
				if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)											/* COND.i3 */
				&&  (st_g_bsm_loop_data.as4_flg_leading[0] == (S4)0)											/* COND.i5 */
				&&  (ast_a_target_prev[i].fl_Rypred > (FL)ALARM_Y_FORWARD)) {									/* COND.t101 */
					tmp_lost_max = (S4)0;
				}
			}
		}
		/* extrapolation */
		if ((ast_a_target_prev[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND. u1 */
		&&  (ast_a_target_prev[i].s4_flg_used == 0)							/* COND. u2 */
		&&  (ast_a_target_prev[i].s4_flg_track > tmp_connect_num)			/* COND. u3 */
		&&  (ast_a_target_prev[i].s4_flg_lost < tmp_lost_max)				/* COND. u4 */
		&&  (*ps4_a_target_num_current < TARGET_BUFFSIZE)) {
			predict_target(
				(const NORMAL_BSM (*))&ast_a_target_prev[i],
				&ast_a_target_current[*ps4_a_target_num_current]
			);

			/* not count lost cycle when the peak are around wall peak */
			/* �e�����ŉ������Ă��邩 */
			/* v1  or  v2  :fm bin is same as wall bin */
			/* v3  and v4  :doa is not same as wall doa */
			/* v5  and v6  :fm pow is greater than wall pow */
			/* v7  and v8  :do not keep same position(same distance) */
			/* v9  and v10 :do not keep same position(same direction) */
			/* v11 and v12 :total fm pow is greater than target doa pow (= there are both object and wall) */
			if (((fl_abs((FL)(ast_a_target_current[*ps4_a_target_num_current].s4_bin_up - s4_t_wall_bin)) < TARGET_LOST_WALL_BIN_DIFF)							/* COND. v1 */
			||   (fl_abs((FL)(ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn - s4_t_wall_bin)) < TARGET_LOST_WALL_BIN_DIFF))							/* COND. v2 */
			&&  (fl_abs((FL)(ast_a_target_current[*ps4_a_target_num_current].s4_bin_up_music)
						  - (180.0F - st_g_bsm_loop_data.afl_installed_angle[0])) > TARGET_LOST_WALL_DOA_DIFF)	/* COND. v3 */
			&&  (fl_abs((FL)(ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn_music)
						  - (180.0F - st_g_bsm_loop_data.afl_installed_angle[0])) > TARGET_LOST_WALL_DOA_DIFF)	/* COND. v4 */
			&&  (ast_a_target_current[*ps4_a_target_num_current].fl_power_up > WALL_OBJECT_POW_TH)																/* COND. v5 */
			&&  (ast_a_target_current[*ps4_a_target_num_current].fl_power_dn > WALL_OBJECT_POW_TH)																/* COND. v6 */
			&&  (!((ast_a_target_current[*ps4_a_target_num_current].s4_bin_up_pred == ast_a_target_current[*ps4_a_target_num_current].s4_bin_up)				/* COND. v7 */
			&&     (ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn_pred == ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn)				/* COND. v8 */
			&&     (ast_a_target_current[*ps4_a_target_num_current].s4_bin_up_music_pred == ast_a_target_current[*ps4_a_target_num_current].s4_bin_up_music)	/* COND. v9 */
			&&     (ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn_music_pred == ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn_music)))	/* COND. v10 */
			&&  ((afl_g_cvw_lfm_ftt_power[0][ast_a_target_current[*ps4_a_target_num_current].s4_bin_up]
				- ast_a_target_current[*ps4_a_target_num_current].fl_power_up_music) > 0.0F)					/* COND. v11 */
			&&  ((afl_g_cvw_lfm_ftt_power[1][ast_a_target_current[*ps4_a_target_num_current].s4_bin_dn] 
				- ast_a_target_current[*ps4_a_target_num_current].fl_power_dn_music) > 0.0F)) {					/* COND. v12 */
				/* nothing */
			} else {
				ast_a_target_current[*ps4_a_target_num_current].s4_flg_lost++;
			}

			as4_t_used_ID[ast_a_target_prev[i].s4_ID_num-1] = 1;
			ast_a_target_prev[i].s4_flg_used = 1;
			(*ps4_a_target_num_current)++;
		}
	}

	return;
}

static VD fn_bsm_sel_add_target(
	S4 s4_a_pair_num_current,
	NORMAL_BSM ast_a_normal_current[NORMAL_BUFFSIZE],
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE],
	S4 as4_t_used_ID[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 j;

	S4 tmp_connect_th = CANOUT_TRK_MIN;
	FL tmp_r_max;
	S4 index;

	/* �O��Ƃ̔�r�Ŏg��ꂸ�ɏ����ɍ���object������ΐV�KTARGET�Ƃ��Ēǉ� */
	for( i = 0; i < s4_a_pair_num_current; i++ )
	{
		tmp_connect_th = CANOUT_TRK_MIN;
		/* ���Ԃ��ᑬ���͌�ނ��镨�W�̐ڑ��񐔏��������������� */
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND. w1 */
		&&  (ast_a_normal_current[i].fl_Vyfil < 0.0F)							/* COND. w2 */
		&&  (fl_g_v_self_bsm_for_base < CANOUT_VSELF_SLOW)) {					/* COND. w7 */
			tmp_connect_th = CANOUT_TRK_MIN_SLOW;
		}
		/* �⏕���W(2FCW)�̐ڑ��񐔏��������������� */
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)					/* COND. w1 */
		&&  (ast_a_normal_current[i].s4_flg_dc == OBJECT_TYPE_2F)					/* COND. w3 */
		&&  (ast_a_normal_current[i].fl_Ryfil > (CFL_ALARM_Y_BACKWARD + 3.0F))) {	/* COND. w4 */
			tmp_connect_th = CANOUT_TRK_MIN_2FCW;
		}
		/* for sidewinder */
		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)							/* COND. w1 */
		&&  (ast_a_normal_current[i].s4_flg_dc == OBJECT_TYPE_SOT)							/* COND. w5 */
		&&  (ast_a_normal_current[i].fl_Rxfil < st_g_bsm_loop_data.afl_wall_width[0])) {	/* COND. w6 */
			tmp_connect_th = CANOUT_TRK_MIN_SOT;
		}

		if ((ast_a_normal_current[i].fl_Robs != CFL_UNKNOWN_VALUE)			/* COND. w1 */
		&&  (ast_a_normal_current[i].s4_flg_used == 0)						/* COND. w10 */
		&&  (ast_a_normal_current[i].s4_flg_stop == 0)						/* COND. w11 */
		&&  (ast_a_normal_current[i].s4_flg_track > tmp_connect_th)			/* COND. w12 */
		&&  (ast_a_normal_current[i].s4_flg_lost == 0)						/* COND. w13 */
		&&  ((S4)fl_abs( (FL)s2_g_curvr_for_base ) > CANOUT_CURVER_MIN)		/* COND. w9 */
		&&  (fl_abs(fl_g_v_self_bsm_for_base) > CFL_CANOUT_VSELF_MIN)) {	/* COND. w8 */
			if ((*ps4_a_target_num_current) < TARGET_BUFFSIZE) {				/* COND. w15 */
				/* �����R�s�[ */
				ast_a_target_current[(*ps4_a_target_num_current)] = ast_a_normal_current[i];
				ast_a_normal_current[i].s4_flg_used = 1;

				/* NORMAL_BSM�ŗ\�����Ă��邩��TARGET�̏���\���͂���Ȃ��H */
				predict_object_trajectory_simple(
					&ast_a_target_current[(*ps4_a_target_num_current)],		/* [in/out] */
					1										/* [in] */
				);

				/* ����ڑ��� */
				if ((ast_a_normal_current[i].s4_flg_heiso_up != 0)
				&&  (ast_a_normal_current[i].s4_flg_heiso_dn != 0)) {
					/* ��s�Ԃ͈��񐔐ڑ��ς݂Ƃ��� */
					ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_track = (S4)(PRIOR_TRK_NUM+1);
				} else {
					ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_track = 1;
				}

				/* �O�}�� */
				ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_lost = 0;
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
				if (ast_a_normal_current[i].s4_flg_dc == OBJECT_TYPE_2F) {
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
				if (((S2)s4_abs(s2_g_curvr_for_base) < (S2)2200)
				&&  (ast_a_normal_current[i].s4_flg_dc == OBJECT_TYPE_2F)) {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
					ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_lost = ast_a_normal_current[i].s4_flg_lost;
				}

				/* �V�K���̃t���O */
				if ((ast_a_normal_current[i].s4_flg_heiso_up != 0)
				&&  (ast_a_normal_current[i].s4_flg_heiso_dn != 0)) {
					ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_new = 0;
				} else {
					ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_new = 1;
				}

				/* �g�p�ς݃t���O */
				ast_a_target_current[(*ps4_a_target_num_current)].s4_flg_used = 1;

				/* ���W�ԍ��ݒ� */
				for (j = 0; j < TARGET_BUFFSIZE; j++) {
					if (as4_t_used_ID[j] == 0) {
						ast_a_target_current[(*ps4_a_target_num_current)].s4_ID_num = j+(S4)1;
						as4_t_used_ID[j] = 1;
						break;
					}
				}
				(*ps4_a_target_num_current)++;
			} else {
				tmp_r_max = 0.0F;
				index = -1;
				for (j = 0; j < (*ps4_a_target_num_current); j++) {
					if ((fl_abs(ast_a_normal_current[i].fl_Robs) < fl_abs(ast_a_target_current[j].fl_Robs))
					&&  (tmp_r_max <  fl_abs(ast_a_target_current[j].fl_Robs))) {
						tmp_r_max =  fl_abs(ast_a_target_current[j].fl_Robs);
						index = j;
					}
				}

				if (index != -1) {
					as4_t_used_ID[ast_a_target_current[index].s4_ID_num-1] = 0;
					fn_init(&ast_a_target_current[index], 1);
					s4_trim_target(ast_a_target_current);
					(*ps4_a_target_num_current)--;
					i--;
					if (i < -1) {
						i = -1;
					}
				}
			}
		}
	}

	return;
}

static VD fn_bsm_sel_exclude_target(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	/* ���������������������������������������� (�@)�O�}�񐔂��������̂��폜 */
	fn_bsm_sel_extrgt_lot_exp(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�A)��~�����폜 */
	fn_bsm_sel_extrgt_stationary(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�B)���x�Ȃ����폜 */
	fn_bsm_sel_extrgt_no_rel_spd(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�C)�^���ɒ�؂��镨�W�̍폜 */
	fn_bsm_sel_extrgt_stag_just_beside(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�D)�Ƃ������^���͍폜 */
	fn_bsm_sel_extrgt_just_beside(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�E)�^���̕��W�͈�ԓ����ȊO�폜 */
	fn_bsm_sel_extrgt_around_beside(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�F)���Α��̃Z���T�̗̈�ɓ����Ă������̂��폜 */
	fn_bsm_sel_extrgt_opst_sns_area(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�G)���Ԃ̋߂��̂��̂��폜 */
	fn_bsm_sel_extrgt_around_mycar(
		s4_a_target_num_current,
		ast_a_target_current
	);

	/* ���������������������������������������� (�H)�ǂ̊O�����폜 */
	fn_bsm_sel_extrgt_outside_load(
		s4_a_target_num_current,
		ast_a_target_current
	);

	return;
}

static VD fn_bsm_sel_extrgt_lot_exp(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 tmp_lost_max = TARGET_LOST_MAX;

	/* ���������������������������������������� (�@)�O�}�񐔂��������̂��폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if (ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {			/* COND.x1 */
			/*�^���͂��߂� */
			if (fl_abs(ast_a_target_current[i].fl_Rypred) < EKF_RY_SIDE) {	/* COND.x2 */
				tmp_lost_max = TARGET_LOST_MAX_SIDE;						/* PROC.4 */
			} else {
				tmp_lost_max = TARGET_LOST_MAX;								/* PROC.5 */
			}

			if (ast_a_target_current[i].s4_flg_lost > tmp_lost_max) {		/* COND.x3 */
				fn_init(&ast_a_target_current[i], 1);						/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_stationary(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;
	FL tmp_alarm_x_min = ALARM_X_IN       + ALARM_X_OFFSET_IN;

	/* ���������������������������������������� (�A)��~�����폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if (ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {									/* COND.x1 */
			if (((ast_a_target_current[i].fl_Vyfil < ((-fl_g_v_self_bsm_for_base / 3.6F) + 1.0F))	/* COND.x4 */
			||   (ast_a_target_current[i].s4_flg_stop == 1))										/* COND.x5 */
			&&  ((ast_a_target_current[i].fl_Rxfil > tmp_alarm_x_min)								/* COND.x6 */
			||   (ast_a_target_current[i].fl_Rxfil < st_g_bsm_loop_data.afl_wall_width[0]))) {		/* COND.x7 */
				fn_init(&ast_a_target_current[i], 1);												/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_no_rel_spd(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�B)���x�Ȃ����폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND.x1 */
		&&  (ast_a_target_current[i].s4_flg_track <= PRIOR_TRK_NUM)) {			/* COND.x8 */
			if ((st_g_bsm_loop_data.as4_flg_leading[0] == 0)					/* COND.x11 */
			&&  (st_g_bsm_loop_data.as4_flg_passing[0] < PASSING_COUNT_MIN)		/* COND.x12 */
			&&  (ast_a_target_current[i].fl_Vyfil == 0.0F)) {					/* COND.x14 */
				fn_init(&ast_a_target_current[i], 1);							/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_stag_just_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�C)�^���ɒ�؂��镨�W�̍폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND.x1 */
		&&  (ast_a_target_current[i].s4_flg_track <= PRIOR_TRK_NUM)) {			/* COND.x8 */
			if ((st_g_bsm_loop_data.as4_flg_leading[0] == 0)					/* COND.x11 */
			&&  (st_g_bsm_loop_data.as4_flg_passing[0] < PASSING_COUNT_MIN)		/* COND.x12 */
			&&  (fl_abs(ast_a_target_current[i].fl_Ryfil) < 0.5F)				/* COND.x15 */
			&&  (fl_abs(ast_a_target_current[i].fl_Rypred) < 1.0F)				/* COND.x16 */
			&&  (fl_abs(ast_a_target_current[i].fl_Vyfil) < 0.5F)				/* COND.x17 */
			&&  (fl_abs(ast_a_target_current[i].fl_Vypred) < 0.5F)) {			/* COND.x18 */
				fn_init(&ast_a_target_current[i], 1);							/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_just_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�D)�Ƃ������^���͍폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)				/* COND.x1 */
		&&  (ast_a_target_current[i].s4_flg_track <= PRIOR_TRK_NUM)) {			/* COND.x8 */
			if ((st_g_bsm_loop_data.as4_flg_leading[0] == 0)					/* COND.x11 */
			&&  (st_g_bsm_loop_data.as4_flg_passing[0] < PASSING_COUNT_MIN)		/* COND.x12 */
			&&  (ast_a_target_current[i].fl_Ryfil > RY_WALL_LIMIT)) {			/* COND.x19 */
				fn_init(&ast_a_target_current[i], 1);							/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_around_beside(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	FL min_x = TH_TT_MAX;													/* PROC.7 */
	S4 min_index = -1;														/* PROC.8 */
	S4 side_num = 0;														/* PROC.9 */

#if (BSM_OPTION_SW_CONNECT == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
	FL fl_t_rxfil_abs;
	FL fl_t_rxfil_diff_min_abs;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

	/* ���������������������������������������� (�E)�^���̕��W�͈�ԓ����ȊO�폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)			/* COND.x1 */
		&&  (fl_abs(ast_a_target_current[i].fl_Ryfil) < EKF_RY_SIDE)) {		/* COND.x2 */
			side_num++;														/* PROC.12 */
			if (ast_a_target_current[i].fl_Rxfil < min_x) {					/* COND.x20 */
				min_x = ast_a_target_current[i].fl_Rxfil;					/* PROC.10 */
				min_index = i;												/* PROC.11 */
			}
		}
	}

	if (side_num > 1) {															/* COND.x21 */
		for (i = 0; i < s4_a_target_num_current; i++) {
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
			if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)			/* COND.x1 */
			&&  (fl_abs(ast_a_target_current[i].fl_Ryfil) < EKF_RY_SIDE)		/* COND.x2 */
			&&  (i != min_index))												/* COND.x22 */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
			fl_t_rxfil_abs = fl_abs(ast_a_target_current[i].fl_Ryfil);
			fl_t_rxfil_diff_min_abs = fl_abs(ast_a_target_current[i].fl_Rxfil - ast_a_target_current[min_index].fl_Rxfil);

			if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)		/* COND.x1 */
			&&  (fl_t_rxfil_abs < EKF_RY_SIDE)								/* COND.x2 */
			&&  (i != min_index)											/* COND.x22 */
			&&  (fl_t_rxfil_diff_min_abs > (FL)0.5F))						/* COND.x30 */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
			{
				fn_init(&ast_a_target_current[i], 1);							/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_opst_sns_area(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�F)���Α��̃Z���T�̗̈�ɓ����Ă������̂��폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if (ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {											/* COND.x1 */
			if (ast_a_target_current[i].fl_Rxfil <= (-st_g_bsm_loop_data.afl_installed_angle[1] - 1.5F)) {	/* COND.x23 */
				fn_init(&ast_a_target_current[i], 1);														/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_around_mycar(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;

	/* ���������������������������������������� (�G)���Ԃ̋߂��̂��̂��폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		if (ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE) {				/* COND.x1 */
			if ((ast_a_target_current[i].fl_Rxfil < RX_AROUND_TH_TT)			/* COND.x24 */
			&&  (ast_a_target_current[i].fl_Ryfil > RY_AROUND_TH_TT)) {			/* COND.x25 */
				fn_init(&ast_a_target_current[i], 1);							/* PROC.3 */
			}
		}
	}

	return;
}

static VD fn_bsm_sel_extrgt_outside_load(
	S4 s4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	S4 i;
	S4 tmp_Rx_index = 0;

	/* ���������������������������������������� (�H)�ǂ̊O�����폜 */
	for (i = 0; i < s4_a_target_num_current; i++) {
		tmp_Rx_index = (S4) ast_a_target_current[i].fl_Ryfil;
		if (tmp_Rx_index < 0) {
			tmp_Rx_index = 0;
		}
		if (tmp_Rx_index > 69) {
			tmp_Rx_index = 69;
		}

		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)														/* COND.x1 */
		&&  (ast_a_target_current[i].fl_Rxfil >= fl_abs(st_g_bsm_loop_data.afl_Rx_right[tmp_Rx_index] - (FL)0.5F))		/* COND.x26 */
		&&  (st_g_bsm_loop_data.as4_flg_leading[0] == 0)																/* COND.x11 */
		&&  (st_g_bsm_loop_data.as4_flg_passing[0] < PASSING_COUNT_MIN)) {												/* COND.x12 */
			fn_init(&ast_a_target_current[i], 1);																		/* PROC.3 */
		}

#if (BSM_OPTION_SW_CONNECT == TYPE_A)
		/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
		if ((ast_a_target_current[i].fl_Robs != CFL_UNKNOWN_VALUE)											/* COND.x1 */
		&&  (st_g_bsm_loop_data.as4_flg_leading[0] == (S4)0)												/* COND.x11 */
		&&  (st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)												/* COND.x13 */
		&&  (st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement == (U1)1)										/* COND.x27 */
		&&  (st_g_bsm_loop_data.afl_wall_width[0] - ast_a_target_current[i].fl_Rxfil < (FL)0.5F)) {			/* COND.x28 */
			fn_init(&ast_a_target_current[i], (S4)1);					/* PROC.3 */
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
	}

	return;
}

static VD fn_bsm_sel_empty_buf_trgt_trimming(
	S4 *ps4_a_target_num_current,
	NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE]
)
{
	/* ��X���b�g�������ǂ̂��߂̕ϐ� */
	S4 s2_t_in[TARGET_BUFFSIZE];
	S4 s2_t_loop;
	S4 s2_t_num;

	s2_t_num = 0;
	for (s2_t_loop = 0; s2_t_loop < TARGET_BUFFSIZE; s2_t_loop++) {
		/*���g�������Ă��邩�ǂ����̊m�F�p */
		if (ast_a_target_current[s2_t_loop].fl_Robs != CFL_UNKNOWN_VALUE) {
			s2_t_in[s2_t_num] = s2_t_loop;
			s2_t_num++;
		}
	}
	*ps4_a_target_num_current = s2_t_num;
	if (s2_t_num > 0) {
		for (s2_t_loop = 0; s2_t_loop < s2_t_num; s2_t_loop++) {
			ast_a_target_current[s2_t_loop] = ast_a_target_current[s2_t_in[s2_t_loop]];
		}
	
		/* �s�v�ƂȂ������͏��������� */
		for (s2_t_loop = s2_t_num; s2_t_loop < TARGET_BUFFSIZE; s2_t_loop++) {
			fn_init(&ast_a_target_current[s2_t_loop], 1);
		}
	}

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_sel_target_marking													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �^�[�Q�b�g���̃}�[�L���O 												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: s4_a_target_num_current			: ���݃^�[�Q�b�g�� [in]					*/
/*				: ast_a_target_current 				: ���݃^�[�Q�b�g��� [in/out]			*/
/*				: u1_a_alarming_flag				: �x�񒆃t���O [in]						*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011											*/
/*				  (8)�^�[�Q�b�g�I������ 12)  �^�[�Q�b�g���̃}�[�L���O  					*/
/********************************************************************************************/
static VD fn_bsm_sel_target_marking(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE], U1 u1_a_alarming_flag)
{
	/* (i)SoT�J�b�g���ꂽ�^�[�Q�b�g�̊m�F */
	fn_bsm_sel_check_sot_target(s4_a_target_num_current, ast_a_target_current, u1_a_alarming_flag);
	
	/* (ii)Tos�^�[�Q�b�g�̊m�F */
	fn_bsm_sel_check_tos_target(s4_a_target_num_current, ast_a_target_current);
	
	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_sel_check_sot_target												*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: SoT�J�b�g���ꂽ�^�[�Q�b�g�̊m�F 											*/
/*------------------------------------------------------------------------------------------*/
/* ����			: s4_a_target_num_current			: ���݃^�[�Q�b�g�� [in]					*/
/*				: ast_a_target_current 				: ���݃^�[�Q�b�g��� [in/out]			*/
/*				: u1_a_alarming_flag				: �x�񒆃t���O [in]						*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_loop_data.as4_fast_sot_flg[] : fast-SoT �t���O					*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fl_abs(), fl_cos()														*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011											*/
/*				  (8)�^�[�Q�b�g�I������														*/
/*				  12)  �^�[�Q�b�g���̃}�[�L���O (i)SoT�J�b�g���ꂽ�^�[�Q�b�g�̊m�F		*/
/********************************************************************************************/
static VD fn_bsm_sel_check_sot_target(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE], U1 u1_a_alarming_flag)
{
	U1 u1_t_lp_trgt_num;
	FL fl_t_cos;
	FL fl_t_vy;
	
	/* (i)SoT�J�b�g���ꂽ�^�[�Q�b�g�̊m�F */
	if ((st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)0)															/* COND.y1 */
	&&  (u1_a_alarming_flag == (U1)0)) {																			/* COND.y2 */
		for (u1_t_lp_trgt_num = (U1)0; u1_t_lp_trgt_num < s4_a_target_num_current; u1_t_lp_trgt_num++) {
			if (ast_a_target_current[u1_t_lp_trgt_num].s4_ID_num > (S4)0) {											/* COND.z1 */
				fl_t_cos = fl_cos((FL)0.5F * (ast_a_target_current[u1_t_lp_trgt_num].fl_theta_up + ast_a_target_current[u1_t_lp_trgt_num].fl_theta_dn));
				
				if (fl_abs(fl_t_cos) > (FL)0.1F) {
					fl_t_vy = ast_a_target_current[u1_t_lp_trgt_num].fl_Vobs / fl_t_cos;
				} else {
					fl_t_vy = ast_a_target_current[u1_t_lp_trgt_num].fl_Vobs;
				}
				
				if ((ast_a_target_current[u1_t_lp_trgt_num].fl_Rxfil < (ALARM_X_OUT + ALARM_X_OFFSET_OUT))				/* COND.z2 */
				&&  (ast_a_target_current[u1_t_lp_trgt_num].fl_Rxfil > (ALARM_X_IN + ALARM_X_OFFSET_IN))				/* COND.z3 */
				&&  (ast_a_target_current[u1_t_lp_trgt_num].fl_Ryfil < ((FL)-3.0F - ALARM_Y_OFFSET))					/* COND.z4 */
				&&  (ast_a_target_current[u1_t_lp_trgt_num].fl_Ryfil > (CFL_ALARM_Y_BACKWARD - ALARM_Y_OFFSET))			/* COND.z5 */
				&&  (fl_t_vy < (FL)-2.78F)) {																			/* COND.z6 */
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_sot_cut = (S4)3;
				}
			}
		}
	} else {
		for (u1_t_lp_trgt_num = (U1)0; u1_t_lp_trgt_num < s4_a_target_num_current; u1_t_lp_trgt_num++) {
			if ((ast_a_target_current[u1_t_lp_trgt_num].s4_ID_num > (S4)0)									/* COND.z1 */
			&&  (ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_sot_cut > (S4)0)) {							/* COND.z7 */
				fl_t_cos = fl_cos((FL)0.5F * (ast_a_target_current[u1_t_lp_trgt_num].fl_theta_up + ast_a_target_current[u1_t_lp_trgt_num].fl_theta_dn));
				
				if (fl_abs(fl_t_cos) > (FL)0.1F) {
					fl_t_vy = ast_a_target_current[u1_t_lp_trgt_num].fl_Vobs / fl_t_cos;
				} else {
					fl_t_vy = ast_a_target_current[u1_t_lp_trgt_num].fl_Vobs;
				}
				
				if ((ast_a_target_current[u1_t_lp_trgt_num].fl_Ryfil >= (FL)-3.0)			/* COND.z8 */
				||  (fl_t_vy > (FL)-1.39F)) {												/* COND.z9 */
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_sot_cut -= (S4)1;
				}
			}
		}
	}
	
	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_sel_check_sot_target												*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: Tos�^�[�Q�b�g�̊m�F 														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: s4_a_target_num_current			: ���݃^�[�Q�b�g�� [in]					*/
/*				: ast_a_target_current 				: ���݃^�[�Q�b�g��� [in/out]			*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-011											*/
/*				  (8)�^�[�Q�b�g�I������														*/
/*				  12)  �^�[�Q�b�g���̃}�[�L���O (ii)Tos�^�[�Q�b�g�̊m�F					*/
/********************************************************************************************/
static VD fn_bsm_sel_check_tos_target(S4 s4_a_target_num_current, NORMAL_BSM ast_a_target_current[TARGET_BUFFSIZE])
{
	U1 u1_t_lp_trgt_num;
	
	/* (ii)Tos�^�[�Q�b�g�̊m�F */
	for (u1_t_lp_trgt_num = (U1)0; u1_t_lp_trgt_num < s4_a_target_num_current; u1_t_lp_trgt_num++) {
		if (ast_a_target_current[u1_t_lp_trgt_num].s4_ID_num > (S4)0) {										/* COND.z1 */
			if (ast_a_target_current[u1_t_lp_trgt_num].fl_Ryfil < (CFL_ALARM_Y_BACKWARD - ALARM_Y_OFFSET)) {	/* COND.z11 */
				if (ast_a_target_current[u1_t_lp_trgt_num].fl_Vyfil > (FL)3.0F) {							/* COND.z12 */
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos += (S4)2;
				} else if (ast_a_target_current[u1_t_lp_trgt_num].fl_Vyfil > (FL)0.0F) {					/* COND.z13 */
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos += (S4)1;
				} else {
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos -= (S4)1;
				}
				
				/* 0�`10�ŏ㉺���K�[�h */
				if (ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos > (S4)10) {
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos = (S4)10;
				} else if (ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos < (S4)0) {
					ast_a_target_current[u1_t_lp_trgt_num].s4_ctr_tos = (S4)0;
				} else {
					/* �l�ێ� */
				}
			}
		}
	}
	
	return;
}


S4 cluster_target(
	S4 target_num,
	NORMAL_BSM* target,
	S4* used_ID
)
{
	S4 iret = 0;
	S4 i, j;
	S4 tmp_index_valid = -1;
	S4 tmp_index_invalid = -1;
	NORMAL_BSM tmp_target_buf[TARGET_BUFFSIZE];
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
		fn_init(&tmp_target_buf[i], 1);
	}
	for(i=0; i<target_num; i++)
	{
		tmp_target_buf[i] = target[i];
	}

	for(i=0; i<target_num; i++)
	{
		for(j=0; j<target_num; j++)
		{
			/* �g���b�L���O���ʓ��m�̋߂����̂��m�F */
			if ((i != j)										/* COND. v1 */
			&&  (tmp_target_buf[i].s4_flg_used != 0)			/* COND. v2 */
			&&  (tmp_target_buf[j].s4_flg_used != 0)			/* COND. v2 */
			&&  ((tmp_target_buf[i].s4_flg_track < (S4)5)		/* COND. v13 */
			||   (tmp_target_buf[j].s4_flg_track < (S4)5))) {	/* COND. v13 */
				tmp_index_valid=-1;
				tmp_index_invalid=-1;

				if ((fl_abs(tmp_target_buf[i].fl_Rxfil - tmp_target_buf[j].fl_Rxfil) < RX_TH_TT2)		/* COND. v6 */
				&&  (fl_abs(tmp_target_buf[i].fl_Ryfil - tmp_target_buf[j].fl_Ryfil) < RY_TH_TT2)) {	/* COND. v7 */
					/* longest */
					if (tmp_target_buf[i].s4_flg_track < tmp_target_buf[j].s4_flg_track) {				/* COND. v5 */
						tmp_index_valid = j;
						tmp_index_invalid = i;
					} else {
						tmp_index_valid = i;
						tmp_index_invalid = j;
					}
					used_ID[tmp_target_buf[tmp_index_invalid].s4_ID_num-1] = 0;
				} else if ((fl_abs(tmp_target_buf[i].fl_Rxfil - tmp_target_buf[j].fl_Rxfil) < RX_TH_TT)				/* COND.v3 */
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
					   &&  (fl_abs(tmp_target_buf[i].fl_Ryfil - tmp_target_buf[j].fl_Ryfil) < RY_TH_TT)				/* COND.v4 */
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
					   &&  (fl_abs(tmp_target_buf[i].fl_Ryfil - tmp_target_buf[j].fl_Ryfil) < RY_TH_TT - (FL)1.3F)	/* COND.v4 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
				)
				{
					/* nearest -> longest */
					if (tmp_target_buf[i].s4_flg_track < tmp_target_buf[j].s4_flg_track) {	/* COND. v5 */
						tmp_index_valid = j;
						tmp_index_invalid = i;
					} else {
						tmp_index_valid = i;
						tmp_index_invalid = j;
					}
					used_ID[tmp_target_buf[tmp_index_invalid].s4_ID_num-1] = 0;
				} else {
					/* �������Ȃ� */
				}

				if ((tmp_index_valid != -1)						/* COND. v8 */
				&&  (tmp_index_invalid != -1)) {				/* COND. v9 */
					/* �O���񐔂͏��Ȃ��ق��ɍ��킹�� */
					if (tmp_target_buf[tmp_index_invalid].s4_flg_lost < tmp_target_buf[tmp_index_valid].s4_flg_lost) {	/* COND. v10 */
						tmp_target_buf[tmp_index_valid].s4_flg_lost = tmp_target_buf[tmp_index_invalid].s4_flg_lost;
					}
					/* heiso flag */
					if ((tmp_target_buf[i].s4_flg_heiso_up == 1)		/* COND. v11 */
					||  (tmp_target_buf[j].s4_flg_heiso_up == 1)) {		/* COND. v12 */
						tmp_target_buf[tmp_index_valid].s4_flg_heiso_up = 1;
						tmp_target_buf[tmp_index_valid].s4_flg_heiso_dn = 1;
					}
					/* �폜���鑤�̏������Z�b�g */
					fn_init( &tmp_target_buf[tmp_index_invalid], 1 );
				}
			}
		}
	}

	/* �󂫃o�b�t�@���l�߂� */
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
		fn_init(&target[i], 1);
		if( tmp_target_buf[i].fl_Robs != CFL_UNKNOWN_VALUE )
		{
			target[iret] = tmp_target_buf[i];
			iret++;
		}
	}
	return iret;
}

/* predict new object */
/* @return :number of new objects */
/* @param :see below */
S4 s4_start_prediction(						/* [return] */
	NORMAL_BSM* pst_a_normal_current,		/* [in / out] current normal */
	S4 s4_a_pair_num_current,				/* [in] */
	S4 s4_a_size,							/* [in] buffer s4_a_size (generally NORMAL_BUFFSIZE) */
	const S4 as4_a_flg_passing[1],
	const S4 as4_a_flg_leading[1]
)
{
	S4 s4_t_iRet = 0;
	S4 s4_t_lp_i;
	S4 s4_t_new_num = 0;
	S4 s4_t_tmp_Rx_index = 0;
	S4 s4_t_erased;
	S4 s4_t_tmp_erased_num = 0;

	/* ��X���b�g�������ǂ̂��߂̕ϐ� */
	S4 as4_t_in[NORMAL_BUFFSIZE];
	S4 s4_t_loop;
	S4 s4_t_num;

	FL fl_t_Ryobs_abs;							/* fl_Ryobs�̐�Βl */
	U1 u1_t_jdg_c5_flg;
	U1 u1_t_jdg_c6_flg;

	u1_t_jdg_c5_flg = CU1_DF_OFF;
    u1_t_jdg_c6_flg = CU1_DF_OFF;

	/* �V�K���W�m�F */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_pair_num_current; s4_t_lp_i++) {
		s4_t_erased = 0;
		if (
			(pst_a_normal_current[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE)		/* COND. a1 */
		 && (pst_a_normal_current[s4_t_lp_i].s4_tracked == 0)				/* COND. a2 */
		 && (pst_a_normal_current[s4_t_lp_i].s4_flg_track == 0)				/* COND. a3 */
		) {
			/* �����m�F */
			if (pst_a_normal_current[s4_t_lp_i].fl_Rxobs < (st_g_bsm_loop_data.afl_installed_angle[1] + RX_LIMIT_INSIDE)) {	/* COND. b1 */
				s4_t_erased = 1;
			}

			/* �Ԃ̂����^��Ŕ������镨�W���폜�i�H�ʔ��ˁH�j */
			if (
				(pst_a_normal_current[s4_t_lp_i].fl_Rxobs < ROAD_NOISE_X_MAX)		/* COND. b2 */
			 && (pst_a_normal_current[s4_t_lp_i].fl_Ryobs > ROAD_NOISE_Y_MIN)
			 && (pst_a_normal_current[s4_t_lp_i].fl_Ryobs < ROAD_NOISE_Y_MAX)
			) {
				s4_t_erased = 1;
			}

			/* ���H���m�F */
			s4_t_tmp_Rx_index = (S4)(-pst_a_normal_current[s4_t_lp_i].fl_Ryobs);	/* COND. e2 */
			if (s4_t_tmp_Rx_index < 0) {
				s4_t_tmp_Rx_index = 0;
			}
			if (s4_t_tmp_Rx_index > 69) {
				s4_t_tmp_Rx_index = 69;
			}

			/* �^���t�߂̕��W�̏����m�F */
			if (
				(pst_a_normal_current[s4_t_lp_i].fl_Ryobs > RY_WALL_LIMIT)			/* COND. f1 */
			 && (st_g_bsm_loop_data.as4_slow_sot_find[0] == 0)						/* COND. c1 */
			) {
				/* ���H�̊O���̓g���b�L���O���Ȃ� */
				if (pst_a_normal_current[s4_t_lp_i].fl_Rxobs > (st_g_bsm_loop_data.afl_Rx_right[s4_t_tmp_Rx_index] - RXTH_FROM_WALL)) {		/* COND. f2 */
					s4_t_erased = 1;
				} else {
					/* �����ԁE�ǉz�Ԃ����Ȃ��Ƃ��͓��H�̂��������������g���b�L���O���Ȃ� */
					if (
						(as4_a_flg_leading[0] == 0) 	/* COND. c2 */
					&&  (as4_a_flg_passing[0] == 0)) {	/* COND. c3 */
						if (
						 (
							 (pst_a_normal_current[s4_t_lp_i].s4_flg_heiso_up == 0)		/* COND. f4 */
						  && (pst_a_normal_current[s4_t_lp_i].s4_flg_heiso_dn == 0)
						)
						 ||
						 (fl_abs(st_g_bsm_loop_data.afl_Rx_right[s4_t_tmp_Rx_index] - pst_a_normal_current[s4_t_lp_i].fl_Rxobs) < 2.0F)
						) {
							s4_t_erased = 1;
						}
					}
				}
			}

			/* ����c5,c6�̔���֐��R�[�� �d�l���̋L�q������c5,c6�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
			/* ����c5,c6�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����									*/
			/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�					*/
			u1_t_jdg_c5_flg = u1_start_prediction_c5(st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4]);
			u1_t_jdg_c6_flg = u1_start_prediction_c6(st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5]);

			/* (iv) �^���̕��W�폜 */
			/*  2FCW�ŕǂ̓����������Ɍ���Ă���Ƃ��́A�^���t�߂ŐV�K���W�����Ȃ� */
			fl_t_Ryobs_abs = fl_abs(pst_a_normal_current[s4_t_lp_i].fl_Ryobs);
			if ((u1_t_jdg_c5_flg == CU1_TRUE)						/* COND. c5 */
			&&  (u1_t_jdg_c6_flg == CU1_TRUE)						/* COND. c6 */
			&&  (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)0)		/* COND. c7 */
			&&  (fl_t_Ryobs_abs < (FL)EKF_RY_SIDE)) {				/* COND. f5 */
				s4_t_erased = (S4)1;
			}

			/* �����𖞂����Ȃ����W���폜 */
			if (s4_t_erased == 1) {
				s4_t_tmp_erased_num++;
				/* normal�������Z�b�g */
				fn_init(&pst_a_normal_current[s4_t_lp_i], 1);
			} else {	/* �����𖞂������W�̓g���b�L���O���J�n */
				predict_object_trajectory_simple(
					&pst_a_normal_current[s4_t_lp_i],	/* [in / out] */
					1									/* [in] */
				);
				pst_a_normal_current[s4_t_lp_i].s4_tracked = 1;
				/* �t���O�ݒ� */
				pst_a_normal_current[s4_t_lp_i].s4_flg_track = 1;
				pst_a_normal_current[s4_t_lp_i].s4_flg_lost  = 0;
				pst_a_normal_current[s4_t_lp_i].s4_flg_new   = 1;
				s4_t_new_num++;
			}
		}
	}

	/* ��X���b�g���l�߂� */
	s4_t_num = 0;
	for (s4_t_loop = 0; s4_t_loop < s4_a_size; s4_t_loop++) {
		if (pst_a_normal_current[s4_t_loop].fl_Robs != CFL_UNKNOWN_VALUE) {			/* ���g�������Ă��邩�ǂ����̊m�F�p */
			as4_t_in[s4_t_num] = s4_t_loop;
			s4_t_num++;
		}
	}
	if (s4_t_num > 0) {
		for (s4_t_loop = 0; s4_t_loop < s4_t_num; s4_t_loop++) {
			pst_a_normal_current[s4_t_loop] = pst_a_normal_current[as4_t_in[s4_t_loop]];
		}
		/* �s�v�ƂȂ������͏��������� */
		for (s4_t_loop = s4_t_num; s4_t_loop < s4_a_size; s4_t_loop++) {
			fn_init(&pst_a_normal_current[s4_t_loop], 1);
		}
	}

	s4_t_iRet = s4_t_tmp_erased_num;

	return (s4_t_iRet);

}

/****************************************************************************/
/* �֐���		: u1_start_prediction_c5									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �V�K���W�ǉ������̏���c5����֐�							*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_slow_sot_doa_diff_sum4	: �ᑬ���ʂƒ�~�����ʋȐ���*/
/*												  ���U(�ڋߑ�) [in]			*/
/* �߂�l		: u1_t_jdg_c5_flag				: ����c5�̔��茋�ʊi�[�ϐ�	*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-021(291BCVR)					*/
/*				: (6)�V�K���W�ǉ����� 1)�V�K�ǉ������̔��� 					*/
/*				: (iv)�^���̕��W�폜�̏���c5								*/
/****************************************************************************/
static U1 u1_start_prediction_c5(S4 s4_a_slow_sot_doa_diff_sum4)
{
	/* ����c5���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_c5_flag;				/* ����c5���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_c5_flag = CU1_FALSE;

	/* ����c5�̔��� */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (s4_a_slow_sot_doa_diff_sum4 < (S4)80) {
		u1_t_jdg_c5_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c5_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (s4_a_slow_sot_doa_diff_sum4 < (S4)CFL_WALL_DEV_TH12) {
		u1_t_jdg_c5_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c5_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	return u1_t_jdg_c5_flag;
}

/****************************************************************************/
/* �֐���		: u1_start_prediction_c6									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �V�K���W�ǉ������̏���c6����֐�							*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_slow_sot_doa_diff_sum5	: �ᑬ���ʂƒ�~�����ʋȐ���*/
/*												  ���U(���E��) [in]			*/
/* �߂�l		: u1_t_jdg_c6_flag				: ����c6�̔��茋�ʊi�[�ϐ�	*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-021(291BCVR)					*/
/*				: (6)�V�K���W�ǉ����� 1)�V�K�ǉ������̔��� 					*/
/*				: (iv)�^���̕��W�폜�̏���c6								*/
/****************************************************************************/
static U1 u1_start_prediction_c6(S4 s4_a_slow_sot_doa_diff_sum5)
{
	/* ����c6���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_c6_flag;				/* ����c6���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_c6_flag = CU1_FALSE;

	/* ����c6�̔��� */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (s4_a_slow_sot_doa_diff_sum5 < (S4)80) {
		u1_t_jdg_c6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c6_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (s4_a_slow_sot_doa_diff_sum5 < (S4)WALL_DEV_TH1) {
		u1_t_jdg_c6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_c6_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	return u1_t_jdg_c6_flag;
}

/* copy prediction results to filtered results */
/* @param :see below */
S4 s4_copy_prediction_to_filtered_data(
	NORMAL_BSM *pst_a_normal,						/* [in] */
	S4 s4_a_size									/* [in] */
)
{
	S4 s4_t_lp_i;
	S4 s4_t_object_num = 0;

	NORMAL_BSM ast_t_buf_normal[NORMAL_BUFFSIZE];

	fn_init(ast_t_buf_normal, NORMAL_BUFFSIZE);

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_size; s4_t_lp_i++) {
		if (
			(pst_a_normal[s4_t_lp_i].fl_Rxobs != CFL_UNKNOWN_VALUE)
		 && (pst_a_normal[s4_t_lp_i].fl_Ryobs != CFL_UNKNOWN_VALUE)
		 && (pst_a_normal[s4_t_lp_i].fl_Rxpred != CFL_UNKNOWN_VALUE)
		 && (pst_a_normal[s4_t_lp_i].fl_Rypred != CFL_UNKNOWN_VALUE)
		) {
		} else {
			fn_init(&pst_a_normal[s4_t_lp_i], 1);
		}
	}

	/* trim empty buffer */
	s4_t_object_num = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_size; s4_t_lp_i++) {
		if (pst_a_normal[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE) {			/* ���g�������Ă��邩�ǂ����̊m�F�p */
			ast_t_buf_normal[s4_t_object_num] = pst_a_normal[s4_t_lp_i];
			s4_t_object_num++;
		}
	}
	if (s4_t_object_num > 0) {
		for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_size; s4_t_lp_i++) {
			pst_a_normal[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
		}
	}

	return (s4_t_object_num);
}

VD fn_calc_prediction_of_normaldata(
	NORMAL_BSM* pst_a_normal			/* [in / out] */
)
{
	/* �ɍ��W�v�Z */
	fn_transform_xy_to_polar(
		pst_a_normal[0].fl_Rxpred,			/* [in] */
		pst_a_normal[0].fl_Rypred,			/* [in] */
		&pst_a_normal[0].fl_Robs_pred,		/* [out] */
		&pst_a_normal[0].fl_theta_up_pred	/* [out] */
	);
	pst_a_normal[0].fl_theta_dn_pred = pst_a_normal[0].fl_theta_up_pred;

	/* ���x�v�Z */
	fn_transform_vxvy_to_vr(
		pst_a_normal[0].fl_Vxpred,			/* [in] */
		pst_a_normal[0].fl_Vypred,			/* [in] */
		pst_a_normal[0].fl_theta_dn_pred,	/* [in] */
		&pst_a_normal[0].fl_Vobs_pred		/* [out] */
	);

	/* freq-bin�v�Z */
	fn_transform_rv_to_freqbin(
		pst_a_normal[0].fl_Robs_pred,		/* [in] */
		pst_a_normal[0].fl_Vobs_pred,		/* [in] */
		&pst_a_normal[0].s4_bin_up_pred,	/* [out] */
		0									/* [in] */
	);
	fn_transform_rv_to_freqbin(
		pst_a_normal[0].fl_Robs_pred,		/* [in] */
		pst_a_normal[0].fl_Vobs_pred,		/* [in] */
		&pst_a_normal[0].s4_bin_dn_pred,	/* [out] */
		1									/* [in] */
	);
	fn_transform_rv_to_freqbin_interpolate(
		pst_a_normal[0].fl_Robs_pred,					/* [in] */
		pst_a_normal[0].fl_Vobs_pred,					/* [in] */
		&pst_a_normal[0].fl_bin_up_interpolate_pred,	/* [out] */
		0													/* [in] */
	);
	fn_transform_rv_to_freqbin_interpolate(
		pst_a_normal[0].fl_Robs_pred,					/* [in] */
		pst_a_normal[0].fl_Vobs_pred,					/* [in] */
		&pst_a_normal[0].fl_bin_dn_interpolate_pred,	/* [out] */
		1												/* [in] */
	);

	/* doa-bin�v�Z */
	fn_transform_rad_to_doabin(
		pst_a_normal[0].fl_theta_dn_pred,		/* [in] */
		&pst_a_normal[0].s4_bin_up_music_pred	/* [out] */
	);
	pst_a_normal[0].s4_bin_dn_music_pred  = pst_a_normal[0].s4_bin_up_music_pred;
	fn_transform_rad_to_doabin_interpolate(
		pst_a_normal[0].fl_theta_up_pred,
		&pst_a_normal[0].fl_doa_up_interpolate_pred
	);
	pst_a_normal[0].fl_doa_dn_interpolate_pred  = pst_a_normal[0].fl_doa_up_interpolate_pred;

}

/* estimate road shape */
/* @param :see below */
VD fn_estimate_road_shape(
	FL afl_a_Rx_right[70]					/* [out] */
)
{
	S4 i;
	for( i = 0; i < 70; i++ )
	{
		afl_a_Rx_right[i] = fl_get_road_width(s2_g_curvr_for_base, (FL)(-i)) + st_g_bsm_loop_data.afl_wall_width[0];
	}
}

/****************************************************************************/
/* �֐���		: fl_get_road_width()										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���H�`�󐄒菈�� ��������									*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_curve_r 					: ����R [in]				*/
/*				: fl_a_Ry						: �ԗ���[����̋��� [in]	*/
/* �߂�l		: fl_t_fret						: ���H�`�󐄒茋��			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>  	: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-014 (1)���H�`�󐄒菈�� 		*/
/*--------------------------------------------------------------------------*/
/* ���l			: �e�֐���fn_estimate_road_shape�������d�l���Q�Ƃ���		*/
/****************************************************************************/
FL fl_get_road_width(S4 s4_a_curve_r, FL fl_a_Ry)
{
	FL fl_t_fret;
	FL fl_t_tmp_Ry = fl_a_Ry;

	if (fl_t_tmp_Ry > (FL)0.0F) {
		fl_t_tmp_Ry = (FL)0.0F;
	}

	if (s4_a_curve_r == (S4)0) {
		fl_t_fret = (FL)0.0F;
	} else {
		fl_t_fret = ((FL)0.5F / (FL)s4_a_curve_r) * fl_t_tmp_Ry * fl_t_tmp_Ry;
	}

	return fl_t_fret;
}


/* connect previous object and current object */
/* @return :number of connected pairs */
/* @param :see below */
S4 connect_previous_object(						/* [return] number of connected pairs */
	NORMAL_BSM normal_prev[NORMAL_BUFFSIZE],	/* [in] */
	NORMAL_BSM normal_current[NORMAL_BUFFSIZE],	/* [in/out] */
	S4 pair_num_current,						/* [in] */
	S4* pair_res_prev,							/* [out] */
	S4* pair_res_current,						/* [out] */
	S4 size										/* [in] */
)
{
	S4 iRet = 0;
	S4 i, j, k;
	FL compare[NORMAL_BUFFSIZE][NORMAL_BUFFSIZE];
	FL min;
	S4 found;
	S4 tmp_pair_prev;
	S4 tmp_pair_current;

	FL rx_th = RX_TH_NT;
	FL ry_th = RY_TH_NT;
	FL vx_th = VX_TH_NT;
	FL vy_th = VY_TH_NT;

	/* ������ */
	for( i = 0; i < size; i++ )
	{
		normal_prev[i].s4_flg_used = 0;
		normal_current[i].s4_flg_used = 0;
	}
	for( i = 0; i < NORMAL_BUFFSIZE; i++ )
	{
		for( j = 0; j < NORMAL_BUFFSIZE; j++ )
		{
			compare[i][j] = 1000.0F;
		}
	}

	/* �O��ƍ���̃y�A�Ԃ̕]���l�v�Z */
	for( i = 0; i < pair_num_current; i++ )
	{
		for( j = 0; j < st_g_bsm_loop_data.as4_buf_pair_num[0]; j++ )
		{
			rx_th = RX_TH_NT + fl_abs(normal_prev[j].fl_Vxpred * CFL_SAMPLING_TIME);
			ry_th = RY_TH_NT + fl_abs(normal_prev[j].fl_Vypred * CFL_SAMPLING_TIME);

			if ((normal_current[i].s4_flg_stop == 0)	/* moving object only */
			&&  (fl_abs(normal_current[i].fl_Rxobs - normal_prev[j].fl_Rxpred) < rx_th)								/* COND a : Rx */
			&&  (fl_abs(normal_current[i].fl_Ryobs - normal_prev[j].fl_Rypred) < ry_th)								/* COND b : Ry */
			&&  ((S4)(fl_abs( (FL)(normal_current[i].s4_bin_up - normal_prev[j].s4_bin_up_pred))) < FREQ_TH_NT)		/* COND c : bin(up) */
			&&  ((S4)(fl_abs( (FL)(normal_current[i].s4_bin_dn - normal_prev[j].s4_bin_dn_pred))) < FREQ_TH_NT)		/* COND d : bin(down) */
			&&  (fl_abs(normal_current[i].fl_Vxobs - normal_prev[j].fl_Vxpred) < vx_th)								/* COND e : Vx */
			&&  (fl_abs(normal_current[i].fl_Vyobs - normal_prev[j].fl_Vypred) < vy_th)) {							/* COND f : Vy */
				/* side area -> small value */
				if ((fl_abs(normal_current[i].fl_Ryobs) < EKF_RY_SIDE)
				||  (fl_abs(normal_prev[j].fl_Rypred) < EKF_RY_SIDE)) {
					compare[i][j] = (FL)fl_abs( normal_current[i].fl_Rxobs - normal_prev[j].fl_Rxpred )		/* Rx */
								  + (FL)fl_abs( normal_current[i].fl_Ryobs - normal_prev[j].fl_Rypred );	/* Ry */
				} else {
					/* not side area */
					compare[i][j] = (FL)fl_abs( normal_current[i].fl_Rxobs - normal_prev[j].fl_Rxpred )		/* Rx */
								+ (FL)fl_abs( normal_current[i].fl_Ryobs - normal_prev[j].fl_Rypred )		/* Ry */
								+ (FL)fl_abs( normal_current[i].fl_Vxobs - normal_prev[j].fl_Vxpred )		/* Vx */
								+ (FL)fl_abs( normal_current[i].fl_Vyobs - normal_prev[j].fl_Vypred );		/* Vy */
				}
			}
		}
	}

	/* �y�A�`���� */
	iRet = 0;
	for (k = 0; k < pair_num_current; k++) {
		min = 1000.0F;
		found = 0;
		for (i = 0; i < pair_num_current; i++) {								/* ����̃y�A�� */
			for (j = 0; j < st_g_bsm_loop_data.as4_buf_pair_num[0]; j++) {		/* �O��̃y�A�� */
				/* ���g�p�̌��ʂ̒��ŕ]���l���ŏ��ƂȂ���� */
				if ((compare[i][j] < min)
				&&  (normal_prev[j].s4_flg_used == 0)
				&&  (normal_current[i].s4_flg_used == 0)
				&&  (iRet < NORMAL_BUFFSIZE)) {
					min = compare[i][j];
					found = 1;
					tmp_pair_current = i;
					tmp_pair_prev = j;
				}
			}
		}
		/* �]���l���ŏ��𖞂����y�A������� */
		if( found == 1 )
		{
			*(pair_res_current + iRet) = tmp_pair_current;
			*(pair_res_prev + iRet) = tmp_pair_prev;
			iRet++;
			normal_prev[tmp_pair_prev].s4_flg_used = 1;
			normal_current[tmp_pair_current].s4_flg_used = 1;
		}
	}

	return iRet;
}

/* predict object using current estimated position */
/* @param :see below */
VD predict_object_trajectory_simple(
	NORMAL_BSM* normal_current,					/* [in/out] */
	S4 pair_num									/* [in] */
)
{
	S4 i;
	for(i=0; i<pair_num; i++)
	{
		/* �Ƃ肠�������x���Ƃ��Č��݂̑��x���玟�̒P���\������ */
		/* �c���x */
		normal_current[i].fl_Vypred = normal_current[i].fl_Vyobs;
		/* �c�ʒu */
		normal_current[i].fl_Rypred = normal_current[i].fl_Ryobs + normal_current[i].fl_Vyobs*CFL_SAMPLING_TIME;
		/* �����x */
		normal_current[i].fl_Vxpred = normal_current[i].fl_Vxobs;
		/* ���ʒu */
		normal_current[i].fl_Rxpred = normal_current[i].fl_Rxobs + normal_current[i].fl_Vxobs*CFL_SAMPLING_TIME;
		/* �ɍ��W�v�Z */
		fn_transform_xy_to_polar(
			normal_current[i].fl_Rxpred,			/* [in] */
			normal_current[i].fl_Rypred,			/* [in] */
			&normal_current[i].fl_Robs_pred,		/* [out] */
			&normal_current[i].fl_theta_up_pred		/* [out] */
		);
		normal_current[i].fl_theta_dn_pred = normal_current[i].fl_theta_up_pred;
		/* ���x�v�Z */
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
		if( normal_current[i].fl_Ryobs > 0.0F )
		{
			normal_current[i].fl_Vypred = - normal_current[i].fl_Vypred;
		}
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
		/* ���ڊp�x20deg�ł͏����Ȃ� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

		fn_transform_vxvy_to_vr(
			normal_current[i].fl_Vxpred,		/* [in] */
			normal_current[i].fl_Vypred,		/* [in] */
			normal_current[i].fl_theta_dn_pred,	/* [in] */
			&normal_current[i].fl_Vobs_pred		/* [out] */
		);

#if (BSM_OPTION_SW_CONNECT == TYPE_A)
		if( normal_current[i].fl_Ryobs > 0.0F )
		{
			normal_current[i].fl_Vypred = - normal_current[i].fl_Vypred;
		}
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
		/* ���ڊp�x20deg�ł͏����Ȃ� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */

		/* freq-bin�v�Z */
		fn_transform_rv_to_freqbin(
			normal_current[i].fl_Robs_pred,		/* [in] */
			normal_current[i].fl_Vobs_pred,		/* [in] */
			&normal_current[i].s4_bin_up_pred,	/* [out] */
			0									/* [in] */
		);
		fn_transform_rv_to_freqbin(
			normal_current[i].fl_Robs_pred,		/* [in] */
			normal_current[i].fl_Vobs_pred,		/* [in] */
			&normal_current[i].s4_bin_dn_pred,	/* [out] */
			1									/* [in] */
		);
		fn_transform_rv_to_freqbin_interpolate(
			normal_current[i].fl_Robs_pred,					/* [in] */
			normal_current[i].fl_Vobs_pred,					/* [in] */
			&normal_current[i].fl_bin_up_interpolate_pred,	/* [out] */
			0												/* [in] */
		);
		fn_transform_rv_to_freqbin_interpolate(
			normal_current[i].fl_Robs_pred,					/* [in] */
			normal_current[i].fl_Vobs_pred,					/* [in] */
			&normal_current[i].fl_bin_dn_interpolate_pred,	/* [out] */
			1												/* [in] */
		);
		/* doa-bin�v�Z */
		fn_transform_rad_to_doabin(
			normal_current[i].fl_theta_up_pred,		/* [in] */
			&normal_current[i].s4_bin_up_music_pred	/* [out] */
		);
		normal_current[i].s4_bin_dn_music_pred  = normal_current[i].s4_bin_up_music_pred;
		fn_transform_rad_to_doabin_interpolate(
			normal_current[i].fl_theta_up_pred,
			&normal_current[i].fl_doa_up_interpolate_pred
		);
		normal_current[i].fl_doa_dn_interpolate_pred = normal_current[i].fl_doa_up_interpolate_pred;

		normal_current[i].fl_Rxfil=normal_current[i].fl_Rxobs;
		normal_current[i].fl_Ryfil=normal_current[i].fl_Ryobs;
		normal_current[i].fl_Vxfil=normal_current[i].fl_Vxobs;
		normal_current[i].fl_Vyfil=normal_current[i].fl_Vyobs;
	}

	return;
}


/* predict object using connected data */
/* @return :number of object */
/* @param :see below */
S4 prediction_with_connected_data(		/* [return] */
	NORMAL_BSM* normal_prev,			/* [in/out] current normal */
	NORMAL_BSM* normal_current,			/* [in/out] current normal */
	const S4* data_id_prev,					/* [in] buffer id of previous normal (= id os previous tracker) */
	const S4* data_id_current,				/* [in] buffer id of current normal */
	S4 paired_num						/* [in] connected data size */
)
{
	S4 iRet = 0;
	S4 i;
	S4 predict_num = 0;
	S4 tmp_id_prev[NORMAL_BUFFSIZE];
	S4 tmp_id_current[NORMAL_BUFFSIZE];

	for(i=0; i<paired_num; i++)
	{
		tmp_id_prev[i] = *data_id_prev;
		tmp_id_current[i] = *data_id_current;
		data_id_prev++;
		data_id_current++;
		
		if ((st_g_bsm_loop_data.u1_truck_flg != (U1)0)																	/* COND.a1 */
		&&  (normal_current[tmp_id_current[i]].fl_Ryobs > CFL_TRUCK_RY_MIN)												/* COND.a2 */
		&&  ((normal_current[tmp_id_current[i]].fl_Rxobs - normal_prev[tmp_id_prev[i]].fl_Rxpred) > (FL)0.0F)			/* COND.a3 */
		&&  (normal_current[tmp_id_current[i]].fl_Rxobs > CFL_TRUCK_RX_MIN)												/* COND.a4 */
		&&  (normal_current[tmp_id_current[i]].fl_Rxobs < CFL_TRUCK_RX_MAX)) {											/* COND.a5 */
#if (BSM_OPTION_SW_CONNECT == TYPE_A)
			normal_current[tmp_id_current[i]].fl_Rxobs =  normal_prev[tmp_id_prev[i]].fl_Rxpred - CFL_TRUCK_WIDTH;
#elif (BSM_OPTION_SW_CONNECT == TYPE_B)
			normal_current[tmp_id_current[i]].fl_Rxobs =  normal_current[tmp_id_current[i]].fl_Rxobs - CFL_TRUCK_WIDTH;
#ifndef _291B_1A_US_20160909_TRUCK_MOD_12
			if( normal_current[tmp_id_current[i]].fl_Ryobs < (FL)-7.0 )
			{
				normal_current[tmp_id_current[i]].fl_Ryobs =  normal_current[tmp_id_current[i]].fl_Ryobs + (FL)2.0;
			}
#endif
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_CONNECT */
			normal_current[tmp_id_current[i]].fl_Vxobs =  (FL)0.0F;
		}
	}

	for(i=0; i<paired_num; i++)
	{
		fn_ab_track(
			&normal_prev[tmp_id_prev[i]],
			&normal_current[tmp_id_current[i]],
			0
		);
		calc_prediction_of_normaldata(
			&normal_current[tmp_id_current[i]]
		);
		/* �t���O�ݒ� */
		if (normal_current[tmp_id_current[i]].s4_flg_track == CS4_S4MAX) {
			/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
		} else {
			normal_current[tmp_id_current[i]].s4_flg_track = (S4)normal_prev[tmp_id_prev[i]].s4_flg_track + 1;
		}

		normal_current[tmp_id_current[i]].s4_flg_lost  = 0;
		normal_current[tmp_id_current[i]].s4_flg_new   = 0;
		normal_current[tmp_id_current[i]].s4_tracked = 1;
		normal_prev[tmp_id_prev[i]].s4_tracked = 1;
		normal_current[tmp_id_current[i]].s4_ctr_sot_cut = normal_prev[tmp_id_prev[i]].s4_ctr_sot_cut;
		normal_current[tmp_id_current[i]].s4_flg_reliable = normal_prev[tmp_id_prev[i]].s4_flg_reliable;
		normal_current[tmp_id_current[i]].s4_ctr_tos = normal_prev[tmp_id_prev[i]].s4_ctr_tos;
		predict_num++;
	}

	iRet = predict_num;
	return iRet;
}

/* predict object without connected data */
/*  or clear data */
/* @return :number of predicted objects */
/* @param :see below */
S4 prediction_without_connected_data(			/* [return] */
	NORMAL_BSM* normal_prev,					/* [in] previous normal */
	NORMAL_BSM* normal_current,					/* [in/out] current normal */
	S4 pair_num_current							/* [in] */
)
{
	S4 iRet = 0;
	S4 i, j;
	S4 lost_num = 0;
	NORMAL_BSM tmptmp_normal_current[NORMAL_BUFFSIZE];
	NORMAL_BSM tmp_normal_buff[NORMAL_BUFFSIZE];
	S4 tmp_connect_num = EKF_CONNECT_NUM;
	S4 tmp_lost_max = EKF_LOST_MAX;

	fn_init(tmptmp_normal_current,NORMAL_BUFFSIZE);
	fn_init(tmp_normal_buff,NORMAL_BUFFSIZE);

	/* remove object near the already connected object */
	for (i = 0; i < st_g_bsm_loop_data.as4_buf_pair_num[0]; i++) {
		if ((normal_prev[i].fl_Robs != CFL_UNKNOWN_VALUE)
		&&  (normal_prev[i].s4_tracked != 0)) {				/* already traked */
			for (j = 0; j < st_g_bsm_loop_data.as4_buf_pair_num[0]; j++) {
				if ((normal_prev[j].fl_Robs != CFL_UNKNOWN_VALUE)
				&&  (normal_prev[j].s4_tracked == 0)					/* not yet tracked */
				&&  (fl_abs(normal_prev[i].fl_Rxpred - normal_prev[j].fl_Rxpred) < RX_TH_NT)
				&&  (fl_abs(normal_prev[i].fl_Rypred - normal_prev[j].fl_Rypred) < RY_TH_NT)) {
					/* reset normal data */
					fn_init(&normal_prev[j], 1);
				}
			}
		}
	}

	/* check condition for extrapolation */
	for (i = 0; i < st_g_bsm_loop_data.as4_buf_pair_num[0]; i++) {
		/* side area */
		if (fl_abs(normal_prev[i].fl_Rypred) < EKF_RY_SIDE) {
			tmp_connect_num = EKF_CONNECT_NUM_SIDE;
			tmp_lost_max = EKF_LOST_MAX_SIDE;
		} else if (normal_prev[i].fl_Rypred > CFL_ALARM_Y_BACKWARD) {
			/* bsm area */
			tmp_connect_num = EKF_CONNECT_NUM_SIDE;
			tmp_lost_max = EKF_LOST_MAX_INAREA;
		} else {
			/* out of area */
			tmp_connect_num = EKF_CONNECT_NUM;
			tmp_lost_max = EKF_LOST_MAX;
		}
		if (fl_abs(normal_prev[i].fl_Robs - st_g_bsm_loop_data.afl_wall_width[0]) < 1.0F) {
			tmp_lost_max = EKF_LOST_MAX_WALL_DIST;
		}
		
		if (st_g_bsm_loop_data.as4_fast_sot_flg[0] != (S4)0) {
			tmp_lost_max = (S4)0;
		}



		/* object extrapolation */
		if ((normal_prev[i].fl_Robs != CFL_UNKNOWN_VALUE)
		&&  (normal_prev[i].s4_tracked == 0)					/* not yet tracked */
		&&  (normal_prev[i].s4_flg_track > tmp_connect_num)		/* already connected more than threshold */
		&&  (i < NORMAL_BUFFSIZE)) {
			/* extrapolation cycle is less than threshold */
			if (normal_prev[i].s4_flg_lost < tmp_lost_max) {
				/* copy previous prediction value to current value */
				tmptmp_normal_current[lost_num].s4_bin_up = normal_prev[i].s4_bin_up_pred;
				tmptmp_normal_current[lost_num].s4_bin_dn = normal_prev[i].s4_bin_dn_pred;
				tmptmp_normal_current[lost_num].fl_bin_up_interpolate = normal_prev[i].fl_bin_up_interpolate_pred;
				tmptmp_normal_current[lost_num].fl_bin_dn_interpolate = normal_prev[i].fl_bin_dn_interpolate_pred;
				tmptmp_normal_current[lost_num].s4_bin_up_music = normal_prev[i].s4_bin_up_music_pred;
				tmptmp_normal_current[lost_num].s4_bin_dn_music = normal_prev[i].s4_bin_dn_music_pred;
				tmptmp_normal_current[lost_num].fl_doa_up_interpolate = normal_prev[i].fl_doa_up_interpolate_pred;
				tmptmp_normal_current[lost_num].fl_doa_dn_interpolate = normal_prev[i].fl_doa_dn_interpolate_pred;
				tmptmp_normal_current[lost_num].fl_power_up = normal_prev[i].fl_power_up;
				tmptmp_normal_current[lost_num].fl_power_dn = normal_prev[i].fl_power_dn;
				tmptmp_normal_current[lost_num].fl_power_up_music = normal_prev[i].fl_power_up_music;
				tmptmp_normal_current[lost_num].fl_power_dn_music = normal_prev[i].fl_power_dn_music;
				tmptmp_normal_current[lost_num].fl_theta_up = normal_prev[i].fl_theta_up_pred;
				tmptmp_normal_current[lost_num].fl_theta_dn = normal_prev[i].fl_theta_dn_pred;
				tmptmp_normal_current[lost_num].fl_Robs = normal_prev[i].fl_Robs_pred;
				tmptmp_normal_current[lost_num].fl_Rxobs = normal_prev[i].fl_Rxpred;
				tmptmp_normal_current[lost_num].fl_Ryobs = normal_prev[i].fl_Rypred;
				tmptmp_normal_current[lost_num].fl_Vobs = normal_prev[i].fl_Vobs_pred;
				tmptmp_normal_current[lost_num].fl_Vxobs = normal_prev[i].fl_Vxpred;
				tmptmp_normal_current[lost_num].fl_Vyobs = normal_prev[i].fl_Vypred;

				/* copy previous prediction value(flags) to current value(flags) */
				tmptmp_normal_current[lost_num].s4_flg_stop  = normal_prev[i].s4_flg_stop;
				tmptmp_normal_current[lost_num].s4_flg_track = normal_prev[i].s4_flg_track;
				tmptmp_normal_current[lost_num].s4_flg_lost  = normal_prev[i].s4_flg_lost;
				tmptmp_normal_current[lost_num].s4_ID_num  = normal_prev[i].s4_ID_num;
				tmptmp_normal_current[lost_num].s4_flg_single_peak_up = normal_prev[i].s4_flg_single_peak_up;
				tmptmp_normal_current[lost_num].u4_ctr_fa = normal_prev[i].u4_ctr_fa;
				tmptmp_normal_current[lost_num].s4_flg_reliable = normal_prev[i].s4_flg_reliable;
				tmptmp_normal_current[lost_num].s4_ctr_tos = normal_prev[i].s4_ctr_tos;
				tmptmp_normal_current[lost_num].s4_flg_heiso_up = normal_prev[i].s4_flg_heiso_up;
				tmptmp_normal_current[lost_num].s4_flg_heiso_dn = normal_prev[i].s4_flg_heiso_dn;
				tmptmp_normal_current[lost_num].s4_flg_dc  = normal_prev[i].s4_flg_dc;
				tmptmp_normal_current[lost_num].s4_ctr_sot_cut  = normal_prev[i].s4_ctr_sot_cut;
				tmptmp_normal_current[lost_num].s4_flg_reliable  = normal_prev[i].s4_flg_reliable;
				tmptmp_normal_current[lost_num].s4_ctr_tos  = normal_prev[i].s4_ctr_tos;

				fn_ab_track(
					&normal_prev[i],
					&tmptmp_normal_current[lost_num],
					0
				);
				calc_prediction_of_normaldata(
					&tmptmp_normal_current[lost_num]
				);

				if (tmptmp_normal_current[lost_num].s4_flg_track == CS4_S4MAX) {
					/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
				} else {
					tmptmp_normal_current[lost_num].s4_flg_track++;
				}

				tmptmp_normal_current[lost_num].s4_flg_lost++;
				tmptmp_normal_current[lost_num].s4_flg_new = 0;
				tmptmp_normal_current[lost_num].s4_tracked = (S4)1;
				normal_prev[i].s4_flg_used = 1;
				lost_num++;
			} else {
				/* too long extrapolation */
				/* reset normal data */
				fn_init(&normal_prev[i], 1);
			}
		}
	}

	for (i = 0; i < lost_num; i++) {
		if ((pair_num_current + i) < NORMAL_BUFFSIZE ) {
			copy_normal_data(
				(const NORMAL_BSM (*))&tmptmp_normal_current[i],				/* [in] */
				&normal_current[pair_num_current+i],	/* [out] */
				1
			);
		} else {
			break;
		}
	}

	iRet = i;
	return iRet;
}

VD predict_target(
	const NORMAL_BSM *target_prev,				/* [in] */
	NORMAL_BSM *target_current				/* [in/out] */
)
{
	/* copy previous prediction value to current value */
	target_current[0].s4_bin_up = target_prev[0].s4_bin_up_pred;
	target_current[0].s4_bin_dn = target_prev[0].s4_bin_dn_pred;
	target_current[0].fl_bin_up_interpolate = target_prev[0].fl_bin_up_interpolate_pred;
	target_current[0].fl_bin_dn_interpolate = target_prev[0].fl_bin_dn_interpolate_pred;
	target_current[0].s4_bin_up_music = target_prev[0].s4_bin_up_music_pred;
	target_current[0].s4_bin_dn_music = target_prev[0].s4_bin_dn_music_pred;
	target_current[0].fl_doa_up_interpolate = target_prev[0].fl_doa_up_interpolate_pred;
	target_current[0].fl_doa_dn_interpolate = target_prev[0].fl_doa_dn_interpolate_pred;
	target_current[0].fl_power_up = target_prev[0].fl_power_up;
	target_current[0].fl_power_dn = target_prev[0].fl_power_dn;
	target_current[0].fl_power_up_music = target_prev[0].fl_power_up_music;
	target_current[0].fl_power_dn_music = target_prev[0].fl_power_dn_music;
	target_current[0].fl_theta_up = target_prev[0].fl_theta_up_pred;
	target_current[0].fl_theta_dn = target_prev[0].fl_theta_dn_pred;
	target_current[0].fl_Robs = target_prev[0].fl_Robs_pred;
	target_current[0].fl_Rxobs = target_prev[0].fl_Rxpred;
	target_current[0].fl_Ryobs = target_prev[0].fl_Rypred;
	target_current[0].fl_Vobs = target_prev[0].fl_Vobs_pred;
	target_current[0].fl_Vxobs = target_prev[0].fl_Vxpred;
	target_current[0].fl_Vyobs = target_prev[0].fl_Vypred;

	target_current[0].fl_Rxfil = target_prev[0].fl_Rxpred;
	target_current[0].fl_Ryfil = target_prev[0].fl_Rypred;
	target_current[0].fl_Vxfil = target_prev[0].fl_Vxpred;
	target_current[0].fl_Vyfil = target_prev[0].fl_Vypred;
	target_current[0].fl_Axfil = target_prev[0].fl_Axfil;
	target_current[0].fl_Ayfil = target_prev[0].fl_Ayfil;


	/* copy previous prediction value(flags) to current value(flags) */
	target_current[0].s4_flg_stop = target_prev[0].s4_flg_stop;
	target_current[0].s4_flg_track = target_prev[0].s4_flg_track;
	target_current[0].s4_flg_lost  = target_prev[0].s4_flg_lost;
	target_current[0].s4_ID_num = target_prev[0].s4_ID_num;
	target_current[0].s4_flg_single_peak_up = target_prev[0].s4_flg_single_peak_up;
	target_current[0].u4_ctr_fa = target_prev[0].u4_ctr_fa;
	target_current[0].s4_flg_reliable = target_prev[0].s4_flg_reliable;
	target_current[0].s4_ctr_tos = target_prev[0].s4_ctr_tos;
	target_current[0].s4_flg_heiso_up = target_prev[0].s4_flg_heiso_up;
	target_current[0].s4_flg_heiso_dn = target_prev[0].s4_flg_heiso_dn;
	target_current[0].s4_flg_dc = target_prev[0].s4_flg_dc;
	target_current[0].s4_ctr_sot_cut = target_prev[0].s4_ctr_sot_cut;
	target_current[0].s4_flg_reliable = target_prev[0].s4_flg_reliable;
	target_current[0].s4_ctr_tos = target_prev[0].s4_ctr_tos;

	fn_ab_track(
		&target_prev[0],
		&target_current[0],
		1
	);
	calc_prediction_of_normaldata(
		target_current
	);

	if (target_current[0].s4_flg_track == CS4_S4MAX) {
		/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
	} else {
		target_current[0].s4_flg_track++;
	}

/*	target_current[0].lost_flag++; */
	target_current[0].s4_flg_new = 0;
	target_current[0].s4_tracked = 1;
	target_current[0].s4_flg_used = 1;
}


/* copy specified number of normal data from arg1 to arg2 */
/* @param :see below */
VD copy_normal_data(
	const NORMAL_BSM *normal_in,						/* [in] */
	NORMAL_BSM *normal_out,						/* [out] */
	S4 size										/* [in] */
)
{
	S4 i;
	for(i=0; i<size; i++)
	{
		*normal_out = *normal_in;
		normal_in++;
		normal_out++;
	}
	return;
}

VD calc_prediction_of_normaldata(
	NORMAL_BSM* normal				/* [in/out] */
)
{
	/* �ɍ��W�v�Z */
	fn_transform_xy_to_polar(
		normal[0].fl_Rxpred,			/* [in] */
		normal[0].fl_Rypred,			/* [in] */
		&normal[0].fl_Robs_pred,		/* [out] */
		&normal[0].fl_theta_up_pred		/* [out] */
	);
	normal[0].fl_theta_dn_pred = normal[0].fl_theta_up_pred;

	/* ���x�v�Z */
	fn_transform_vxvy_to_vr(
		normal[0].fl_Vxpred,			/* [in] */
		normal[0].fl_Vypred,			/* [in] */
		normal[0].fl_theta_dn_pred,		/* [in] */
		&normal[0].fl_Vobs_pred			/* [out] */
	);

	/* freq-bin�v�Z */
	fn_transform_rv_to_freqbin(
		normal[0].fl_Robs_pred,			/* [in] */
		normal[0].fl_Vobs_pred,			/* [in] */
		&normal[0].s4_bin_up_pred,		/* [out] */
		0								/* [in] */
	);
	fn_transform_rv_to_freqbin(
		normal[0].fl_Robs_pred,			/* [in] */
		normal[0].fl_Vobs_pred,			/* [in] */
		&normal[0].s4_bin_dn_pred,		/* [out] */
		1								/* [in] */
	);
	fn_transform_rv_to_freqbin_interpolate(
		normal[0].fl_Robs_pred,						/* [in] */
		normal[0].fl_Vobs_pred,						/* [in] */
		&normal[0].fl_bin_up_interpolate_pred,		/* [out] */
		0											/* [in] */
	);
	fn_transform_rv_to_freqbin_interpolate(
		normal[0].fl_Robs_pred,						/* [in] */
		normal[0].fl_Vobs_pred,						/* [in] */
		&normal[0].fl_bin_dn_interpolate_pred,		/* [out] */
		1											/* [in] */
	);
	/* doa-bin�v�Z */
	fn_transform_rad_to_doabin(
		normal[0].fl_theta_up_pred,		/* [in] */
		&normal[0].s4_bin_up_music_pred	/* [out] */
	);
	normal[0].s4_bin_dn_music_pred  = normal[0].s4_bin_up_music_pred;
	fn_transform_rad_to_doabin_interpolate(
		normal[0].fl_theta_up_pred,
		&normal[0].fl_doa_up_interpolate_pred
	);
	normal[0].fl_doa_dn_interpolate_pred  = normal[0].fl_doa_up_interpolate_pred;
}



/********* for data transform *******************************************************/
/****************************************************************************/
/* �֐���		: fn_transform_xy_to_polar									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �ɍ��W�̎Z�o												*/
/*--------------------------------------------------------------------------*/
/* ����			: x					: X���������\���l	[in][1m]			*/
/*				: y					: Y���������\���l	[in][1m]			*/
/*				: *r				: �����\���l		[out][1m]			*/
/*				: *theta			: ���ʗ\���l		[out][rad]			*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-017 (8)�^�[�Q�b�g�I������		*/
/*				: 6)�^�[�Q�b�g�̃g���b�L���O���� (ii)�ɍ��W�̎Z�o			*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
VD fn_transform_xy_to_polar(
	FL x,
	FL y,
	FL* r,
	FL* theta
)
{
	FL sensor_pos_x = st_g_bsm_loop_data.afl_installed_angle[1];
	/* r : �O���͐��C����͕� */
	/* theta : ���v��肪�� */
	if(y<0.0)
	{
		*r = -(FL)fl_sqrt( (x - sensor_pos_x)*(x - sensor_pos_x) + y*y );
		*theta = (FL)fl_atan( (x-sensor_pos_x) / y ,(FL)1.0F );
	}
	else if(y>0.0)
	{
		*r = (FL)fl_sqrt( (x - sensor_pos_x)*(x - sensor_pos_x) + y*y );

		/* 0���K�[�h */
		if (fl_abs(x - sensor_pos_x) > (FL)0.0F) {
			*theta = -(FL)(0.5F*PI + fl_atan( y / (x-sensor_pos_x) ,(FL)1.0F) );
		} else {
			*theta = (FL)0.0F;
		}
	}
	else
	{
		*r = x - sensor_pos_x;
		*theta = 90.0F*PI/180.0F;
	}
}

/* transform angle[rad] to doa-bin */
/* @param :see below */
VD fn_transform_rad_to_doabin(
	FL angle,			/* [in] */
	S4* doa_bin			/* [out] */
)
{
	S4 tmp_doabin;

	tmp_doabin = (S4)( ((-180.0F/PI*angle - DOA_BIN_START_ANG - st_g_bsm_loop_data.afl_installed_angle[0]) / DOA_ANG_PER_BIN) + (FL)0.5F );

	if ( tmp_doabin < 0 )
	{
		tmp_doabin = 0;
	}
	else if ( tmp_doabin > N_DOA )
	{
		tmp_doabin = N_DOA;
	} else {
		/* �������Ȃ� */
	}

	*doa_bin = tmp_doabin;
}

VD fn_transform_rad_to_doabin_interpolate(
	FL angle,			/* [in] */
	FL* doa_bin			/* [out] */
)
{
	FL tmp_doabin;

	tmp_doabin = (-180.0F/PI*angle - DOA_BIN_START_ANG - st_g_bsm_loop_data.afl_installed_angle[0]) / DOA_ANG_PER_BIN;
	if ( tmp_doabin < 0.0F )
	{
		tmp_doabin = 0.0F;
	}
	else if ( tmp_doabin > (FL)N_DOA )
	{
		tmp_doabin = (FL)N_DOA;
	} else {
		/* �������Ȃ� */
	}

	*doa_bin = tmp_doabin;
}

/* transform R[m]&V[m/s] to freq-bin */
/* @param :see below */
VD fn_transform_rv_to_freqbin(
	FL r,			/* [in] */
	FL v,			/* [in] */
	S4* freqbin,	/* [out] */
	S4 updn			/* [in] 0:UP / 1:DN */
)
{

	S4 tmp_lower_limit_th = FREQ_BIN_LOWER_LIMIT;

	if ((r < FREQ_EXPAND_R_TH)
	&&  (v > FREQ_EXPAND_V_TH)) {
		tmp_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR_EX;
	}

	if(updn==CU2_LFM_MOD_UP)
	{
		if(r<0)
		{
			*freqbin = (S4)( 0.50F*( -r/RCOF - v/VCOF ) + 0.50F ) + NB_FFT_PT/2;
		}
		else
		{
			*freqbin = (S4)( 0.50F*( r/RCOF - v/VCOF ) + 0.50F ) + NB_FFT_PT/2;
		}
	}
	else if(updn==CU2_LFM_MOD_DN)
	{
		if(r<0)
		{
			*freqbin = (S4)( 0.50F*( -r/RCOF + v/VCOF ) + 0.50F ) + NB_FFT_PT/2;
		}
		else
		{
			*freqbin = (S4)( 0.50F*( r/RCOF + v/VCOF ) + 0.50F ) + NB_FFT_PT/2;
		}
	}
	else
	{
		/* UP,DN�����Ȃ����߂����ɂ͗��Ȃ� */
	}
	if(*freqbin<tmp_lower_limit_th)
	{
		*freqbin = tmp_lower_limit_th;
	}
	return;
}

VD fn_transform_rv_to_freqbin_interpolate(
	FL r,			/* [in] */
	FL v,			/* [in] */
	FL* freqbin,	/* [out] */
	S4 updn			/* [in] 0:UP / 1:DN */
)
{

	S4 tmp_lower_limit_th = FREQ_BIN_LOWER_LIMIT;

	if ((r < FREQ_EXPAND_R_TH)
	&&  (v > FREQ_EXPAND_V_TH)) {
		tmp_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR_EX;
	}

	if(updn==CU2_LFM_MOD_UP)
	{
		if(r<0.0F)
		{
			*freqbin = ( 0.50F*( -r/RCOF - v/VCOF ) + 0.50F ) + (FL)NB_FFT_PT/2.0F;
		}
		else
		{
			*freqbin = ( 0.50F*( r/RCOF - v/VCOF ) + 0.50F ) + (FL)NB_FFT_PT/2.0F;
		}
	}
	else if(updn==CU2_LFM_MOD_DN)
	{
		if(r<0.0F)
		{
			*freqbin = ( 0.50F*( -r/RCOF + v/VCOF ) + 0.50F ) + (FL)NB_FFT_PT/2.0F;
		}
		else
		{
			*freqbin = ( 0.50F*( r/RCOF + v/VCOF ) + 0.50F ) + (FL)NB_FFT_PT/2.0F;
		}
	}
	else
	{
		/* UP,DN�����Ȃ����߂����ɂ͗��Ȃ� */
	}
	if (*freqbin < (FL)tmp_lower_limit_th) {
		*freqbin = (FL)tmp_lower_limit_th;
	}
	return;
}

/* transform Vx[m/s]&Vy[m/s] to Vr[m/s] */
/* @param :see below */
VD fn_transform_vxvy_to_vr(
	FL vx,		/* [in] */
	FL vy,		/* [in] */
	FL theta,	/* [in] rad */
	FL* vr		/* [out] */
)
{
	FL tmp_vr;

	if ( vy > 0.0 )
	{
		tmp_vr = (FL)fl_sqrt( vx*vx + vy*vy );
		if ( tmp_vr > V_PREDICT_MAX )
		{
			tmp_vr = V_PREDICT_MAX;
		}
	}
	else if ( vy < 0.0 )
	{
		tmp_vr = -(FL)fl_sqrt( vx*vx + vy*vy );
		if ( tmp_vr < -(FL)V_PREDICT_MAX )
		{
			tmp_vr = -(FL)V_PREDICT_MAX;
		}
	}
	else
	{
		tmp_vr = 0.0;
	}

	*vr = tmp_vr;
}
/******************���� �g���b�J�[****************************************************/
VD fn_ab_track(
	const NORMAL_BSM* st_a_normal_prev,		/* [in] */
	NORMAL_BSM* st_a_normal_current,		/* [out] */
	S4 s4_a_ab_filt_cof						/* [in] */
)
{
	FL alpha1, alpha2, alpha3, alpha4;
	FL beta1, beta2, beta3, beta4;
	FL prev_Vy;
	FL prev_Ry;
	FL prev_Vx;
	FL prev_Rx;
	FL current_Vy;
	FL current_Ry;
	FL current_Vx;
	FL current_Rx;

	if ( s4_a_ab_filt_cof == 1 )	/* TARGET */
	{
		prev_Vy = st_a_normal_prev->fl_Vypred;
		prev_Ry = st_a_normal_prev->fl_Rypred;
		prev_Vx = st_a_normal_prev->fl_Vxpred;
		prev_Rx = st_a_normal_prev->fl_Rxpred;
		current_Vy = st_a_normal_current->fl_Vyfil;
		current_Ry = st_a_normal_current->fl_Ryfil;
		current_Vx = st_a_normal_current->fl_Vxfil;
		current_Rx = st_a_normal_current->fl_Rxfil;

		/* ============ �c���x ============== */
		alpha1	= 0.1F;
		beta1	= 0.0014F;
		/* ============ �c�ʒu ============== */
		alpha2	= 0.1F;
		beta2	= 0.0529F;
		/* ============ �����x ============== */
		alpha3	= 0.1F;
		beta3	= 0.001F;
		/* ============ ���ʒu ============== */
		alpha4	= 0.2F;
		beta4	= 0.01F;
	}
	else					/* NORMAL_BSM */
	{
		prev_Vy = st_a_normal_prev->fl_Vypred;
		prev_Ry = st_a_normal_prev->fl_Rypred;
		prev_Vx = st_a_normal_prev->fl_Vxpred;
		prev_Rx = st_a_normal_prev->fl_Rxpred;
		current_Vy = st_a_normal_current->fl_Vyobs;
		current_Ry = st_a_normal_current->fl_Ryobs;
		current_Vx = st_a_normal_current->fl_Vxobs;
		current_Rx = st_a_normal_current->fl_Rxobs;

		/* ============ �c���x ============== */
		alpha1	= 0.2F;
		beta1	= 0.0014F;
		/* ============ �c�ʒu ============== */
		alpha2	= 0.2F;
		beta2	= 0.0529F;
		/* ============ �����x ============== */
		alpha3	= 0.06F;
		beta3	= 0.0F;
		/* ============ ���ʒu ============== */
		alpha4	= 0.06F;
		beta4	= 0.0014F;
	}
	/* ============ �c���x ============== */
	st_a_normal_current->fl_Ayfil  = st_a_normal_prev->fl_Ayfil		+  beta1*( current_Vy - prev_Vy )/CFL_SAMPLING_TIME;
	st_a_normal_current->fl_Vyfil  = prev_Vy					+ alpha1*( current_Vy - prev_Vy );
	st_a_normal_current->fl_Vypred = st_a_normal_current->fl_Vyfil	+ st_a_normal_current->fl_Ayfil*CFL_SAMPLING_TIME;
	/* ============ �c�ʒu ============== */
	st_a_normal_current->fl_Vyfil  = prev_Vy					+  beta2*( current_Ry - prev_Ry )/CFL_SAMPLING_TIME;
	st_a_normal_current->fl_Ryfil  = prev_Ry					+ alpha2*( current_Ry - prev_Ry );
	st_a_normal_current->fl_Rypred = st_a_normal_current->fl_Ryfil	+ st_a_normal_current->fl_Vyfil*CFL_SAMPLING_TIME;
	/* ============ �����x ============== */
	st_a_normal_current->fl_Axfil  = st_a_normal_prev->fl_Axfil		+  beta3*( current_Vx - prev_Vx )/CFL_SAMPLING_TIME;
	st_a_normal_current->fl_Vxfil  = prev_Vx					+ alpha3*( current_Vx - prev_Vx );
	st_a_normal_current->fl_Vxpred = st_a_normal_current->fl_Vxfil    + st_a_normal_current->fl_Axfil*CFL_SAMPLING_TIME;
	/* ============ ���ʒu ============== */
	st_a_normal_current->fl_Vxfil  = prev_Vx					+  beta4*( current_Rx - prev_Rx )/CFL_SAMPLING_TIME;
	st_a_normal_current->fl_Rxfil  = prev_Rx					+ alpha4*( current_Rx - prev_Rx );
	st_a_normal_current->fl_Rxpred = st_a_normal_current->fl_Rxfil	+ st_a_normal_current->fl_Vxfil*CFL_SAMPLING_TIME;

	return;
}

/******************���� �g���b�J�[****************************************************/
VD fn_ab_track_wall(
	const NORMAL_BSM* st_a_normal_prev,		/* [in] */
	NORMAL_BSM* st_a_normal_current, 		/* [out] */
	S4 s4_a_ab_filt_cof						/* [in] */
)
{
	FL alpha1, alpha2;
	FL beta1, beta2;
	FL sensor_pos_x = st_g_bsm_loop_data.afl_installed_angle[1];

	if ( s4_a_ab_filt_cof == 1 )
	{
		/* ============ �����x ============== */
		alpha1	= 0.85F;
		beta1	= 0.0014F;
		/* ============ ���ʒu ============== */
		alpha2	= 0.80F;
		beta2	= 0.0529F;
	}
	else
	{
		/* ============ �����x ============== */
		alpha1	= 0.35F;
		beta1	= 0.0014F;
		/* ============ ���ʒu ============== */
		alpha2	= 0.30F;
		beta2	= 0.0529F;
	}
	/* ============ �����x ============== */
	st_a_normal_current->fl_Axfil  = st_a_normal_prev->fl_Axfil		+  beta1*( st_a_normal_current->fl_Vxobs - st_a_normal_prev->fl_Vxpred )/CFL_SAMPLING_TIME;
	st_a_normal_current->fl_Vxfil  = st_a_normal_prev->fl_Vxpred		+ alpha1*( st_a_normal_current->fl_Vxobs - st_a_normal_prev->fl_Vxpred );
	st_a_normal_current->fl_Vxpred = st_a_normal_current->fl_Vxfil	+ st_a_normal_current->fl_Axfil*CFL_SAMPLING_TIME;

	/* ============ ���ʒu ============== */
	st_a_normal_current->fl_Rxfil  = st_a_normal_prev->fl_Rxpred		+ alpha2*( st_a_normal_current->fl_Rxobs - st_a_normal_prev->fl_Rxpred );
	st_a_normal_current->fl_Rxpred = st_a_normal_current->fl_Rxfil	+ st_a_normal_current->fl_Vxfil*CFL_SAMPLING_TIME;

	/* ============ �c���x ============== */
	st_a_normal_current->fl_Ayfil  = 0.0F;
	st_a_normal_current->fl_Vyfil  = 0.0F;
	st_a_normal_current->fl_Vypred = 0.0F;

	/* ============ �c�ʒu ============== */
	st_a_normal_current->fl_Ryfil  = 0.0F;
	st_a_normal_current->fl_Rypred = 0.0F;
	/* ============ ����ɍ��W ============== */
	st_a_normal_current->fl_Robs_pred  = -(FL)fl_sqrt(
									( st_a_normal_current->fl_Rxpred - sensor_pos_x )*( st_a_normal_current->fl_Rxpred - sensor_pos_x )
									+ st_a_normal_current->fl_Rypred*st_a_normal_current->fl_Rypred
								);
	st_a_normal_current->fl_theta_up_pred  = PI / (FL)2.0F;
	st_a_normal_current->fl_theta_dn_pred  = st_a_normal_current->fl_theta_up_pred;

	st_a_normal_current->fl_Vobs_pred = (FL)(
		  st_a_normal_current->fl_Vxpred*fl_sin( 0.5F*(st_a_normal_current->fl_theta_up_pred + st_a_normal_current->fl_theta_up_pred) )
		+ st_a_normal_current->fl_Vypred*fl_cos( 0.5F*(st_a_normal_current->fl_theta_up_pred + st_a_normal_current->fl_theta_up_pred) )
	);

	return;

}

/****************************************************************************/
/* �֐���		: s4_check_passing_car										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: check presence of passing car								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-CONNECT-01-018A(291BCV).pdf				*/
/*				: (10) �ǉz���菈��  (post) 								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 s4_check_passing_car(
	const NORMAL_BSM* pst_a_target,		/* [in] */
	S4 s4_a_prev_passing_flg		/* [in] */
)
{
	/* �ϐ��錾 */
	S4 bRes = 0;
	S4 tmp_passing_flg = 0;
	S4 i;

	if ((fl_abs((FL)s2_g_curvr_for_base) > CANOUT_CURVER_MIN)
	&&  (fl_abs(fl_g_v_self_bsm_for_base) > CFL_CANOUT_VSELF_MIN)) {
		for (i = 0; i < st_g_bsm_loop_data.as4_buf_pair_num[1]; i++) {
			if ((pst_a_target->s4_ID_num > 0)
			&&  (pst_a_target->fl_Rxfil > PASSING_XMIN)
			&&  (pst_a_target->fl_Rxfil < PASSING_XMAX)
			&&  (pst_a_target->fl_Ryfil > PASSING_YMIN)
			&&  (pst_a_target->fl_Ryfil < PASSING_YMAX)) {
				if ((pst_a_target->fl_Rxfil < (PASSING_XMIN + 1.0F))
				&&  (pst_a_target->fl_Ryfil < (PASSING_YMIN + 3.0F))
				&&  (pst_a_target->fl_Vxfil < 0.0F)
				&&  (pst_a_target->fl_Vyfil < -0.8F)
				&&  (fl_abs((FL)s2_g_curvr_for_base) < 300.0F)) {
					tmp_passing_flg = 0;
				} else {
					tmp_passing_flg = 1;
					break;
				}
			}
			pst_a_target++;
		}
	}
	if (tmp_passing_flg == 0) {
		bRes = 0;
	} else {
		bRes = s4_a_prev_passing_flg + tmp_passing_flg;
	}
	return bRes;
}

VD fn_send_to_can(
	const NORMAL_BSM ast_a_target[TARGET_BUFFSIZE],			/* [in] */
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [out] */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]			/* [out] */
)
{
	S4 i;
	for (i = (S4)0; i < TARGET_BUFFSIZE; i++) {
		if (ast_a_target[i].s4_ID_num > 0) {
			as4_a_Tx_int[i][0]   =  ast_a_target[i].s4_bin_up;				/* bin_up */
			as4_a_Tx_int[i][1]   =  ast_a_target[i].s4_bin_up_music;		/* music_bin_up */
			as4_a_Tx_int[i][2]   =  ast_a_target[i].s4_bin_dn;				/* bin_dn */
			as4_a_Tx_int[i][3]   =  ast_a_target[i].s4_bin_dn_music;		/* music_bin_dn */
			as4_a_Tx_int[i][4]   =  ast_a_target[i].s4_bin_up_pred;			/* bin_up_pred */
			as4_a_Tx_int[i][5]   =  ast_a_target[i].s4_bin_dn_pred;			/* bin_dn_pred */
			as4_a_Tx_int[i][6]   =  ast_a_target[i].s4_bin_up_music_pred;	/* music_peak_bin_up_pred */
			as4_a_Tx_int[i][7]   =  ast_a_target[i].s4_bin_dn_music_pred;	/* music_bin_dn_pred */
			as4_a_Tx_int[i][8]   =  ast_a_target[i].s4_flg_stop;			/* stop_flag */
			as4_a_Tx_int[i][9]   =  ast_a_target[i].s4_flg_track;			/* track_flag */
			as4_a_Tx_int[i][10]   =  ast_a_target[i].s4_flg_lost;			/* lost_flag */
			as4_a_Tx_int[i][11]   =  ast_a_target[i].s4_ID_num;				/* num */
			as4_a_Tx_int[i][12]   =  ast_a_target[i].s4_flg_new;			/* new_flag */
			as4_a_Tx_int[i][13]   =  ast_a_target[i].s4_flg_used;			/* used_flg */
			as4_a_Tx_int[i][14]   =  ast_a_target[i].s4_flg_dc;				/* dc_flag(type) */
			as4_a_Tx_int[i][15]   =  ast_a_target[i].s4_ctr_sot_cut;		/* SoT�J�b�g�J�E���^ */
			as4_a_Tx_int[i][16]   =  ast_a_target[i].s4_flg_reliable;		/* �M���t���O */
			as4_a_Tx_int[i][17]   =  ast_a_target[i].s4_ctr_tos;			/* ToS�t���O */
			as4_a_Tx_int[i][18]   =  0;
			as4_a_Tx_int[i][19]   =  0;
			as4_a_Tx_int[i][20]   =  0;
			as4_a_Tx_int[i][21]   =  0;
			as4_a_Tx_int[i][22]   =  0;

			if(u1_g_sns_pos==SENSOR_RIGHT)	/* �E */
			{
				afl_a_Tx_float[i][0]    =  ast_a_target[i].fl_power_up_music;	/* music_power_up */
				afl_a_Tx_float[i][1]    =  ast_a_target[i].fl_power_dn_music;	/* music_power_dn */
				afl_a_Tx_float[i][2]    =  ast_a_target[i].fl_theta_up;			/* theta_up */
				afl_a_Tx_float[i][3]    =  ast_a_target[i].fl_theta_dn;			/* theta_dn */

				afl_a_Tx_float[i][4]    =  ast_a_target[i].fl_Robs;				/* Robs */
				afl_a_Tx_float[i][5]    =  ast_a_target[i].fl_Rxobs;			/* Rx */
				afl_a_Tx_float[i][6]    =  ast_a_target[i].fl_Ryobs;			/* Ry */
				afl_a_Tx_float[i][7]    =  ast_a_target[i].fl_Ryfil;			/* ���ӁFCAN�ł͂����炪X */
				afl_a_Tx_float[i][8]    =  ast_a_target[i].fl_Rxfil;			/* ���ӁFCAN�ł͂����炪Y */
				afl_a_Tx_float[i][9]    =  ast_a_target[i].fl_Rxpred;			/* Rxpred */
				afl_a_Tx_float[i][10]   =  ast_a_target[i].fl_Rypred;			/* Rypred */

				afl_a_Tx_float[i][11]   =  ast_a_target[i].fl_Vobs;				/* Vobs */
				afl_a_Tx_float[i][12]   =  0;									/* Vx */
				afl_a_Tx_float[i][13]   =  ast_a_target[i].fl_Vyfil;			/* Vyfil */
				afl_a_Tx_float[i][14]   =  ast_a_target[i].fl_Vxfil;			/* Vxfil */
				afl_a_Tx_float[i][15]   =  ast_a_target[i].fl_Vxpred;			/* Vxpred */
				afl_a_Tx_float[i][16]   =  ast_a_target[i].fl_Vypred;			/* Vypred */
				afl_a_Tx_float[i][17]   =  ast_a_target[i].fl_Ayfil;			/* Ayfil */
				afl_a_Tx_float[i][18]   =  ast_a_target[i].fl_Axfil;			/* Axfil */
				afl_a_Tx_float[i][19]   =  ast_a_target[i].fl_prob;				/* prob */
				afl_a_Tx_float[i][20]   =  ast_a_target[i].fl_track_prob;		/* track_prob */
			}
			else	/* �� */
			{
				afl_a_Tx_float[i][0]    =  ast_a_target[i].fl_power_up_music;	/* music_power_up */
				afl_a_Tx_float[i][1]    =  ast_a_target[i].fl_power_dn_music;	/* music_power_dn */
				afl_a_Tx_float[i][2]    =  - ast_a_target[i].fl_theta_up;		/* theta_up */
				afl_a_Tx_float[i][3]    =  - ast_a_target[i].fl_theta_dn;		/* theta_dn */

				afl_a_Tx_float[i][4]    =  ast_a_target[i].fl_Robs;				/* Robs */
				afl_a_Tx_float[i][5]    =  - ast_a_target[i].fl_Rxobs;			/* Rx */
				afl_a_Tx_float[i][6]    =  ast_a_target[i].fl_Ryobs;			/* Ry */
				afl_a_Tx_float[i][7]    =  ast_a_target[i].fl_Ryfil;			/* ���ӁFCAN�ł͂����炪X */
				afl_a_Tx_float[i][8]    =  - ast_a_target[i].fl_Rxfil;			/* ���ӁFCAN�ł͂����炪Y */
				afl_a_Tx_float[i][9]    =  - ast_a_target[i].fl_Rxpred;			/* Rxpred */
				afl_a_Tx_float[i][10]   =  ast_a_target[i].fl_Rypred;			/* Rypred */

				afl_a_Tx_float[i][11]   =  ast_a_target[i].fl_Vobs;				/* Vobs */
				afl_a_Tx_float[i][12]   =  0;									/* Vx */
				afl_a_Tx_float[i][13]   =  ast_a_target[i].fl_Vyfil;			/* Vxfil */
				afl_a_Tx_float[i][14]   =  - ast_a_target[i].fl_Vxfil;			/* Vyfil */
				afl_a_Tx_float[i][15]   =  - ast_a_target[i].fl_Vxpred;			/* Vxpred */
				afl_a_Tx_float[i][16]   =  ast_a_target[i].fl_Vypred;			/* Vypred */
				afl_a_Tx_float[i][17]   =  0;									/* Ayfil */
				afl_a_Tx_float[i][18]   =  0;									/* Aypred */
				afl_a_Tx_float[i][19]   =  ast_a_target[i].fl_prob;				/* prob */
				afl_a_Tx_float[i][20]   =  ast_a_target[i].fl_track_prob;		/* track_prob */
			}
			afl_a_Tx_float[i][21]   =  0;									/* lamda_up[0] */
			afl_a_Tx_float[i][22]   =  0;									/* lamda_up[1] */
			afl_a_Tx_float[i][23]   =  0;									/* lamda_up[2] */
			afl_a_Tx_float[i][24]   =  0;									/* lamda_up[3] */
			afl_a_Tx_float[i][25]   =  0;									/* lamda_up[4] */
			afl_a_Tx_float[i][26]   =  0;									/* lamda_dn[0] */
			afl_a_Tx_float[i][27]   =  0;									/* lamda_dn[1] */
			afl_a_Tx_float[i][28]   =  0;									/* lamda_dn[2] */
			afl_a_Tx_float[i][29]   =  0;									/* lamda_dn[3] */
			afl_a_Tx_float[i][30]   =  0;									/* lamda_dn[4] */

			afl_a_Tx_float[i][31]   =  ast_a_target[i].fl_doa_up_interpolate;			/* music_bin_up */
			afl_a_Tx_float[i][32]   =  ast_a_target[i].fl_doa_dn_interpolate;			/* music_bin_dn */
			afl_a_Tx_float[i][33]   =  ast_a_target[i].fl_doa_up_interpolate_pred;		/* music_bin_up_pred */
			afl_a_Tx_float[i][34]   =  ast_a_target[i].fl_doa_dn_interpolate_pred;		/* music_bin_dn_pred */

			afl_a_Tx_float[i][35]   =  ast_a_target[i].fl_bin_up_interpolate;			/* bin_up */
			afl_a_Tx_float[i][36]   =  ast_a_target[i].fl_bin_dn_interpolate;			/* bin_dn */
			afl_a_Tx_float[i][37]   =  ast_a_target[i].fl_bin_up_interpolate_pred;		/* bin_up_pred */
			afl_a_Tx_float[i][38]   =  ast_a_target[i].fl_bin_dn_interpolate_pred;		/* bin_dn_pred */
		}
	}
}

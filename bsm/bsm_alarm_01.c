/****************************************************************************/
/* �t�@�C����	: BSM_ALARM_01.c											*/
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
/*	t02					14.11.03			�����Z1 1�Z�� K.Kato			*/
/*	MWR-RECO-24G-BSM-ABST-00-009 �K���f�[�^�������Ή�						*/
/*	t03					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���֑Ή�															*/
/*	t04					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �d�l�m�F���ڑΉ�												*/
/*	t05					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� int��S4,float��FL�ɕύX										*/
/*	t06					15.02.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �d�l�m�F���ڍđΉ�											*/
/*	t07					15.03.12			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�Ή�(OBJ�ύX����)												*/
/*	t08					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No492�Ή�															*/
/*	t11					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t12					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t13					15.08.19			�����Z2 1�Z�� G.Jomori			*/
/*	�x�񔻒�ŃX���b�v�t���O���g���悤�ɂ���								*/
/*	t14					15.08.25			�����Z2 1�Z�� G.Jomori			*/
/*	BSM��v�m�F�Ŕ��������o�O�C��											*/
/*	t15					15.08.31			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1567,1568,1587�Ή�											*/
/*	t16					15.09.11			�����Z2 1�Z�� G.Jomori			*/
/*	MWR-RECO-24G-BSM-ALART-01-008�ƔF�����֏C�����ڋ��L���X�gNo5�Ή�		*/
/*	t17					15.10.23			�����Z2 1�Z�� M.Tanaka			*/
/*	�c�ۑ�No.849�Ή�(�Öق̃L���X�g���C��)									*/
/*	t18					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV�Ή�																*/
/*	t19					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �x�񔻒菈����S�Čx�񔻒�̃��C���֐�����R�[������				*/
/*	t20					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �x�񔻒菈����S�Čx�񔻒�̃��C���֐�����R�[������(OBJ�ύX�Ȃ�)	*/
/*	t21					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�													*/
/*	t22					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή� ����Z���t�w�E�Ή�(OBJ�ύX�Ȃ�)					*/
/*	t23					15.11.23			�����Z2 1�Z�� G.Jomori			*/
/*	����Z���t�w�E�Ή�														*/
/*	t24					15.11.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV(��2�e)�Ή�														*/
/*	t25					15.12.04			�����Z2 1�Z�� G.Jomori			*/
/*	BSM ����N���X�w�E�Ή�													*/
/*	t26					15.12.04			�����Z2 1�Z�� G.Jomori			*/
/*	BSM ����N���X�w�E�Ή�(OBJ�ύX�Ȃ�)										*/
/*	t27					15.12.04			�����Z2 1�Z�� G.Jomori			*/
/*	BSM ����Z���t�w�E�Ή�(OBJ�ύX�Ȃ�)										*/
/*	t28					15.12.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV(��3�e)�Ή�														*/
/*	t29					16.01.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�												*/
/*	t30					16.01.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�(OBJ�ύX�Ȃ�)									*/
/*	t31					16.03.01			�����Z2 1�Z�� G.Jomori			*/
/*	010B BSM CV-R�d�l�Ή�													*/
/*	t32					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)		*/
/*	t33					16.03.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l�Ή�														*/
/*	t34					16.03.28			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l ����Z���t�Ή�											*/
/*	t35					16.03.28			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/*	t36					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo2432�Ή�(�T���v���\�[�X�Ə������킹��)						*/
/*	t37					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t38					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t39					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(�d����`�֘A OBJ�ύX�Ȃ�)									*/
/*	t40					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t41					16.06.20			�����Z2 1�Z�� H.Nonogaki		*/
/*	QAC �w�E�Ή�(OBJ�ύX����)												*/
/*	t42					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t43					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �c�ۑ�No1336�Ή� OBJ�ύX�Ȃ�										*/
/*	t44					16.06.21			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t49					16.07.18			�����Z2 1�Z�� G.Jomori			*/
/*	291B�J���p�\�t�g��010B�\�t�g���}�[�W(010B 1A���x�[�X��0024_t822�}�[�W)	*/
/*	t51					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1411,1412,1413�Ή�(S4,FL,VD�ɕύX OBJ�ύX�Ȃ�)					*/
/*	t52					16.09.15			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �F������(BSM,RCTA,AUDR)�}�[�W									*/
/*	t53					16.09.23			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R�d�l�Ή�														*/
/****************************************************************************/

/****************************************************************************/
/*							�C���N���[�h�t�@�C��							*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "../target/init_cvw.h"
#include "../target/bsm_connect_01.h"
#include "../target/bsm_recog_03.h"
#include "../target/func_fmcw.h"
#include "../../../../app/defcom_sns.h"
#include "../../common/cmn_slipjdg_mwr.h"
#include "../../../common/inc_mwr.h"

#include "bsm_alarm_01.h"

#ifndef _20170123_AAZ_CHECK
#include "../btt/bsm_btt.h"
#endif

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif /*VI �\���p*/

BSM_ALARM_DATA st_g_bsm_alarm_data;

/****************************************************************************/
/*							�}�N����`										*/
/****************************************************************************/

/****************************************************************************/
/*							�\���̒�`										*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�ϐ��錾							*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�֐��錾							*/
/****************************************************************************/
S4 s4_check_front_1m_line(									/* [return] ToS End Flag */
	const FL tos_end_param[TOS_END_PARAM_SIZE],					/* [in] */
	FL tmp_frontline_pow,
	S4 frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE]
);

static VD fn_bsm_chkfr_check_alart_max_cycle(
	S4 *ps4_a_tos_cycle_max,
	S4 *ps4_a_sot_cycle_max
);

static S4 s4_bsm_chkfr_check_tos_alart_sts(
	S4 s4_a_tos_cycle_max,
	S4 s4_a_sot_cycle_max
);

static VD fn_bsm_chkfr_check_detect_objsts(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	S4 *ps4_a_tos_line_count,
	S4 *ps4_a_flontline_dn_num,
	FL *pfl_a_pow_th,
	FL *pfl_a_frontline_pow_current,
	S4   as4_a_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE],
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
);

static VD fn_bsm_chkfr_calc_power(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	FL *pfl_a_pow_th
);

static VD fn_bsm_chkfr_check_distance(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	const S4 as4_a_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE],
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
);

static VD fn_bsm_chkfr_sort(
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
);

static VD fn_bsm_chkfr_count_tos_line(
	const FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2],
	S4 *ps4_a_flontline_dn_num,
	S4 *ps4_a_tos_line_count
);

static VD fn_bsm_chkfr_check_frontline_flg(
	FL fl_a_frontline_pow_current,
	FL fl_a_pow_th,
	S4 s4_a_flontline_dn_num,
	S4 s4_a_tos_line_count,
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2],
	S4 *ps4_a_frontline_flag
);

static VD fn_bsm_chkfr_check_tos_end_flg(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	FL fl_a_frontline_pow_current,
	S4 *ps4_a_tos_end_flag
);

S4 s4_delete_tos_end(
	S4 target_num,									/* [in/out] */
	S4 Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [in/out] */
	FL Tx_float[TARGET_BUFFSIZE][TGT_FLT],			/* [in/out] */
	const FL tos_end_param[TOS_END_PARAM_SIZE]			/* [in] */
);

static U1 u1_delete_tos_end_g13(S4 s4_a_passing_flg);

static VD fn_bsm_deltos_delete_tx(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	S4 *ps4_a_final_target_num,
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]	
);

static VD fn_bsm_deltos_delete_normal(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE]
);

static VD fn_bsm_deltos_delete_target(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE]
);

VD fn_bsm_alart_long_fa_cancel_main(U1 u1_a_alarming_flg,
									S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
									FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]);

VD fn_bsm_alart_long_fa_monitoring_target(U1 u1_a_alarming_flg);

VD fn_bsm_alart_long_fa_set_delete_area(FL* pfl_a_delete_area, U1* pu1_a_flg_obj_delete);

VD fn_bsm_alart_long_fa_delete_obj(FL fl_a_delete_area,
								   U1 u1_a_flg_obj_delete,
								   S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
								   FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]);

static VD fn_bsm_alart_check_active(
	S4 *ps4_t_not_alarm,
	FL *pfl_a_alarm_area_y_min,
	const S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	const FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]
);

static VD fn_bsm_alart_set_reliable_jdg_mask_count(const S4 *ps4_a_not_alarm);

static VD fn_bsm_alart_set_backward_line_of_alarm_area(FL *pfl_a_alarm_area_y_min);

static VD fn_bsm_alart_check_cont_altobj(
	S4 s4_final_a_target_num,
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_tos_flg,
	S4 *ps4_a_alarm_flg
);

static VD fn_bsm_alart_check_tos_status(
	S4 *ps4_a_tos_flg
);

static VD fn_bsm_alart_cont_altobj(
	S4 s4_final_a_target_num,
	signed long as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
);

static VD fn_bsm_alart_select_altobj_prev(
	signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	S4 *ps4_a_selected_alarmed_target_index
);

static VD fn_bsm_alart_set_altobj_cur(
	const FL afl_a_Tx_float[1][TGT_FLT],
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	const S4 as4_a_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_index
);

static VD fn_bsm_alart_store_cont_altobj(
	const signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
);

static VD fn_bsm_alart_check_exp_altobj(
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
);

static S4 s4_bsm_alart_set_exp_altobj(
	FL afl_a_alarmed_target[1][ALARM_INFO_SIZE]
);

static S4 s4_bsm_alart_check_exp_sot(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
);

static S4 s4_bsm_alart_check_exp_tos(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
);

static U1 u1_bsm_alart_check_exp_tos_b25(FL fl_a_alarmed_y, FL fl_a_alarm_area_ymax);

static S4 s4_bsm_alart_check_exp_other(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
);

static VD fn_bsm_alart_store_exp_altobj(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE]
);

static VD fn_bsm_alart_check_new_altobj(
	S4 s4_final_a_target_num,
	signed long as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	const S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 s4_a_tos_flg,
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	FL fl_a_alarm_area_y_min,
	S4 *ps4_a_alarm_flg
);

static VD fn_bsm_alart_get_alart_area(
	const FL afl_a_Tx_float[1][TGT_FLT],
	FL *pfl_a_object_x,
	FL *pfl_a_object_y,
	FL *pfl_a_object_vy,
	FL *pfl_a_x_min,
	FL *pfl_a_x_max,
	FL *pfl_a_y_min
);

static VD fn_bsm_alart_get_store_index(
	const signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	const S4 as4_a_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	FL fl_a_object_x,
	FL fl_a_object_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max,
	FL *pfl_a_erased_type,
	S4 *ps4_a_index,
	FL fl_a_alarm_area_y_min
);

static VD fn_bsm_alart_store_new_altobj(
	signed long as4_a_Tx_int[1][NORM_INT],
	FL afl_a_Tx_float[1][TGT_FLT],
	FL fl_a_object_x,
	FL fl_a_object_y,
	S4 s4_a_tos_flg,
	FL fl_a_erased_type,
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg,
	FL fl_a_alarm_area_y_min
);

static FL fl_bsm_alart_check_alart_type(
	FL fl_a_object_x,
	FL fl_a_object_y,
	S4 s4_a_tos_flg,
	FL fl_a_erased_type,
	FL fl_a_alarm_area_y_min
);

static VD fn_bsm_alart_set_alart_target(
	const S4 as4_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE]
);

static VD fn_bsm_alart_extend_alart(
	S4 s4_a_tos_flg,
	S4 s4_a_not_alarm,
	S4 *ps4_a_alarm_flg
);


VD get_hysteresis_area(
	FL ry,			/* [in] */
	FL type,		/* [in] */
	FL area[4],		/* [in/out] 0:x_min, 1:x_max, 2:y_min, 3:y_max */
	FL offset[3]	/* [in]	0:x_offset_out, 1:y:offset, 2:x_offset_in */
);

FL get_time_offset_area(								/* [return] */
	FL r,												/* [in] m */
	FL v,												/* [in]	m/sec */
	FL time												/* [in] sec */
);

VD fn_initialize_alarm_info(
	FL alarmed_target[TARGET_BUFFSIZE][ALARM_INFO_SIZE]	/* [in/out] �x��Ώۏ�� */
);

FL get_fmpower_of_specified_interval(
	const FL power[NB_FFT_PT],
	S4 start_bin,
	S4 end_bin
);

S4 s4_check_front_1m_line(								/* [return] ToS End Flag */
	const FL tos_end_param[TOS_END_PARAM_SIZE],				/* [in] */
	FL tmp_frontline_pow,
	S4 frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE]
)
{
/****************************************************************************/
/* (6) �x��G���A�O�[�Ď�����												*/
/****************************************************************************/
	S4 i,j;
	S4 current_tos_end_flag = 0;

	S4 tmp_tos_flag = 0;

	FL frontline_up[LINE_FREQ_BIN_RANGE][2];
	FL frontline_dn[LINE_FREQ_BIN_RANGE][2];

	/*** �u���b�N�̓r���Ő錾����Ă���ϐ��Q���u���b�N�̐擪�ֈړ� *******************/
	/* ���ʕ��z(FM DN) */
	FL pow_th;

	/* count point */
	S4 tmp_flontline_dn_num = 0;
	S4 tos_line_count;
	S4 tmp_frontline_flag;

	/***** 1) ����p�����[�^�̏����� *****/
	S4 tos_cycle_max = 0;
	S4 sot_cycle_max = 0;
	/* clear frontline */
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<2; j++)
		{
			frontline_up[i][j] = CFL_UNKNOWN_VALUE;
			frontline_dn[i][j] = CFL_UNKNOWN_VALUE;
		}
	}
	if ((st_g_bsm_loop_data.as4_flg_tos_frontline[0]==0)						/* COND.f3 */
	&&  (st_g_bsm_loop_data.as4_flg_tos_end[0]==0)) {							/* COND.f4 */
		st_g_bsm_loop_data.afl_tos_frontline_pow[0] = 0.0F;
	}

	/***** 2) ToS�x��񐔂̊m�F *****/
	/***** 3) SoT�x��񐔂̊m�F *****/
	fn_bsm_chkfr_check_alart_max_cycle(
		&tos_cycle_max,
		&sot_cycle_max
	);


	/***** 4) ToS�x���Ԃ̊m�F *****/
	if( s4_bsm_chkfr_check_tos_alart_sts( tos_cycle_max, sot_cycle_max ) != 0 ) {
		return current_tos_end_flag;
	}

	/***** 5) �x��G���A�O�[�̕��W���o��Ԃ̊m�F *****/
	fn_bsm_chkfr_check_detect_objsts(
		tos_end_param,
		&tos_line_count,
		&tmp_flontline_dn_num,
		&pow_th,
		&tmp_frontline_pow,
		frontline_doa_dn,
		froneline_doa_peak_num_dn,
		frontline_dn
	);

	/***** 6) �ԗ���[ON���� *****/
	fn_bsm_chkfr_check_frontline_flg(
		tmp_frontline_pow,
		pow_th,
		tmp_flontline_dn_num,
		tos_line_count,
		frontline_dn,
		&tmp_frontline_flag
	);

	/***** 7) �ԗ���[OFF���� *****/
	fn_bsm_chkfr_check_tos_end_flg(
		tos_end_param,
		tmp_frontline_pow,
		&current_tos_end_flag
	);

	st_g_bsm_loop_data.as4_flg_tos_frontline[0] = tmp_frontline_flag;
	return current_tos_end_flag;
}

VD calc_front_1m_line(
	FL *frontline_pow_dn,								/* [in/out] frontline Power */
	const FL tos_end_param[TOS_END_PARAM_SIZE],				/* [in] */
	S4 frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	S4 froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE]
)
{
	/* DOWN */
	/* (ii) �x��G���A�O�[���C���i�ԗ���[����bin�j�̕��ʊm�F */
	*frontline_pow_dn = calc_line_doa_fm(
		(const FL (*)[CORRE_SIZE_4CH])(afl_g_cvw_lfm_ryy_matrix[1]),
		afl_g_cvw_lfm_ftt_power[1],
		(S4)tos_end_param[0],
		(S4)tos_end_param[0] + LINE_FREQ_BIN_RANGE,
		(FL)0.0F,												/* ����g�p����Ă��Ȃ�����0.0��n�� */
		frontline_doa_dn,
		froneline_doa_peak_num_dn,
		CU2_LFM_MOD_DN
	);

}


static VD fn_bsm_chkfr_check_alart_max_cycle(
	S4 *ps4_a_tos_cycle_max,
	S4 *ps4_a_sot_cycle_max
)
{
	S4 i;

	/***** 2) ToS�x��񐔂̊m�F *****/
	/***** 3) SoT�x��񐔂̊m�F *****/
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
#if (BSM_OPTION_SW_ALART == TYPE_A)
		if(st_g_bsm_alarm_data.afl_alarmed_target[i][0] != CFL_UNKNOWN_VALUE)				/* COND.f5 */
		{
			/* check ToS event */
			if(
				(st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_TOS) 			/* COND.f6 */
			||  (st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_MERGEIN) 		/* COND.f7 */
			)
			{
				if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_tos_cycle_max)	/* COND.f8 */
				{
					*ps4_a_tos_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
#elif (BSM_OPTION_SW_ALART == TYPE_B)
		if (st_g_bsm_alarm_data.afl_alarmed_target[i][0] != CFL_UNKNOWN_VALUE) {					/* COND.f5 */
			if (st_g_bsm_alarm_data.afl_alarmed_target[i][4] == ALARM_TYPE_TOS) { 					/* COND.f6 */
				if ((S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_tos_cycle_max) {		/* COND.f8 */
					*ps4_a_tos_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */
			/* check SoT event */
			if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_SOT )		/* COND.f9 */
			{
				if( (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3] > *ps4_a_sot_cycle_max )	/* COND.f10 */
				{
					*ps4_a_sot_cycle_max = (S4)st_g_bsm_alarm_data.afl_alarmed_target[i][3];
				}
			}
		}
	}

	return;
}

static S4 s4_bsm_chkfr_check_tos_alart_sts(
	S4 s4_a_tos_cycle_max,
	S4 s4_a_sot_cycle_max
)
{
	S4 s4_t_tmp_tos_flag;

	S4 s4_t_exit;

	s4_t_exit = 0;
	s4_t_tmp_tos_flag = 0;

	/***** 4) ToS�x���Ԃ̊m�F *****/
	if(s4_a_tos_cycle_max > s4_a_sot_cycle_max)							/* COND.f11 */
	{
			s4_t_tmp_tos_flag = 1;
	}
	/* NOT ToS */
	if ((s4_t_tmp_tos_flag==0)										/* COND.f12 NOT ToS in current frame */
	&&  (st_g_bsm_loop_data.as4_flg_tos_frontline[0]==0)			/* COND.f3  NOT ToS in previous frame */
	&&  (st_g_bsm_loop_data.as4_flg_tos_end[0] == 0)) {				/* COND.f4 */
		s4_t_exit = 1;
	}

	return s4_t_exit;
}

static VD fn_bsm_chkfr_check_detect_objsts(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	S4 *ps4_a_tos_line_count,
	S4 *ps4_a_flontline_dn_num,
	FL *pfl_a_pow_th,
	FL *pfl_a_frontline_pow_current,
	S4   as4_a_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE],
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
)
{
	/***** 5) �x��G���A�O�[�̕��W���o��Ԃ̊m�F *****/

	/* (i) �d��臒l�̎Z�o */
	fn_bsm_chkfr_calc_power(
		afl_a_tos_end_param,
		pfl_a_pow_th
	);

	/* (ii) �x��G���A�O�[���C���i�ԗ���[����bin�j�̕��ʊm�F�� */
	/* BSM�F�������̐擪�Ŏ��{���Ă���							*/

	/* (iii) �x��G���A�O�[���C���i�ԗ���[����bin�j�̋����m�F */
	fn_bsm_chkfr_check_distance(
		afl_a_tos_end_param,
		(const S4 (*)[1])as4_a_frontline_doa_dn,
		as4_a_froneline_doa_peak_num_dn,
		afl_a_frontline_dn
	);

	/* (iv) �ԗ���[���_��X���������̋߂����ɕ��ёւ� */
	fn_bsm_chkfr_sort(
		afl_a_frontline_dn
	);


	/* (v) �x��G���A�O�[�͈͓̔��̎ԗ���[���_���J�E���g */
	fn_bsm_chkfr_count_tos_line(
		(const FL (*)[2])afl_a_frontline_dn,
		ps4_a_flontline_dn_num,
		ps4_a_tos_line_count
	);
}

static VD fn_bsm_chkfr_calc_power(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	FL *pfl_a_pow_th
)
{
	*pfl_a_pow_th = afl_a_tos_end_param[4];

	if( st_g_bsm_loop_data.afl_tos_frontline_pow[0] != 0.0F )								/* COND.!f3 */
	{
		if (*pfl_a_pow_th < (st_g_bsm_loop_data.afl_tos_frontline_pow[0] - afl_a_tos_end_param[5]))		/* COND.f13 */
		{
			*pfl_a_pow_th = st_g_bsm_loop_data.afl_tos_frontline_pow[0] - afl_a_tos_end_param[5];
			if( *pfl_a_pow_th < afl_a_tos_end_param[1] )						/* COND.f14 */
			{
				*pfl_a_pow_th = afl_a_tos_end_param[1];
			}
		}
	}

	return;
}

static VD fn_bsm_chkfr_check_distance(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	const S4 as4_a_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE],
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
)
{
	S4 i;
	S4 j;

	FL tmp_r = 0.0F;
	FL tmp_rx = CFL_UNKNOWN_VALUE;
	FL tmp_ry = CFL_UNKNOWN_VALUE;
	FL tmp_theta = 0.0F;

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<as4_a_froneline_doa_peak_num_dn[i]; j++)
		{
			tmp_r = - RCOF * 2.0F * (FL)(((S4)afl_a_tos_end_param[0] + i) - (FL)NB_FFT_PT * 0.5F);
			tmp_theta = fl_transform_doabin_to_rad(	/*DBF(S4) */
				as4_a_frontline_doa_dn[i][j],
				1
			);
			tmp_rx = tmp_r * fl_sin( tmp_theta ) + st_g_bsm_loop_data.afl_installed_angle[1];
			tmp_ry = tmp_r * fl_cos( tmp_theta );
			afl_a_frontline_dn[i][0] = tmp_rx;
			afl_a_frontline_dn[i][1] = tmp_ry;
		}
	}

	return;
}

static VD fn_bsm_chkfr_sort(
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2]
)
{
	S4 i;
	S4 j;

	FL tmp_frontline_dn[LINE_FREQ_BIN_RANGE][2];
	U4 sort_count;
	
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for( j = 0; j < LINE_FREQ_BIN_RANGE; j++ )
		{
			if ((afl_a_frontline_dn[i][0] != CFL_UNKNOWN_VALUE)				/* COND.f15 */
			&&  (afl_a_frontline_dn[j][0] != CFL_UNKNOWN_VALUE)) {			/* COND.f16 */
				if( afl_a_frontline_dn[i][0] < afl_a_frontline_dn[j][0] )	/* COND.f17 */
				{
					tmp_frontline_dn[i][0] = afl_a_frontline_dn[j][0];
					tmp_frontline_dn[i][1] = afl_a_frontline_dn[j][1];

					tmp_frontline_dn[j][0] = afl_a_frontline_dn[i][0];
					tmp_frontline_dn[j][1] = afl_a_frontline_dn[i][1];

					afl_a_frontline_dn[i][0] = tmp_frontline_dn[i][0];
					afl_a_frontline_dn[i][1] = tmp_frontline_dn[i][1];

					afl_a_frontline_dn[j][0] = tmp_frontline_dn[j][0];
					afl_a_frontline_dn[j][1] = tmp_frontline_dn[j][1];
				}
			}
		}
	}

	/* ��o�b�t�@���l�߂� */
	sort_count = (U4)0;
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		tmp_frontline_dn[i][0] = CFL_UNKNOWN_VALUE;
		tmp_frontline_dn[i][1] = CFL_UNKNOWN_VALUE;
	}
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		if( afl_a_frontline_dn[i][0] != CFL_UNKNOWN_VALUE )
		{
			tmp_frontline_dn[sort_count][0] = afl_a_frontline_dn[i][0];
			tmp_frontline_dn[sort_count][1] = afl_a_frontline_dn[i][1];
			sort_count++;
		}
	}
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		afl_a_frontline_dn[i][0] = tmp_frontline_dn[i][0];
		afl_a_frontline_dn[i][1] = tmp_frontline_dn[i][1];
	}

	return;
}

static VD fn_bsm_chkfr_count_tos_line(
	const FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2],
	S4 *ps4_a_flontline_dn_num,
	S4 *ps4_a_tos_line_count
)
{
	S4 i;

	*ps4_a_flontline_dn_num = 0;
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		if( afl_a_frontline_dn[i][0] != CFL_UNKNOWN_VALUE )				/* COND.f15 */
		{
			(*ps4_a_flontline_dn_num)++;
		}
	}
	*ps4_a_tos_line_count = 0;
	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		if ((afl_a_frontline_dn[i][1] > -0.5F)							/* COND.f18 RY */
		&&  (afl_a_frontline_dn[i][1] < 1.0F)) {						/* COND.f19 RY */
			(*ps4_a_tos_line_count)++;
		}
	}

	return;
}

static VD fn_bsm_chkfr_check_frontline_flg(
	FL fl_a_frontline_pow_current,
	FL fl_a_pow_th,
	S4 s4_a_flontline_dn_num,
	S4 s4_a_tos_line_count,
	FL afl_a_frontline_dn[LINE_FREQ_BIN_RANGE][2],
	S4 *ps4_a_frontline_flag
)
{
	/* to check whether face or tail */
	*ps4_a_frontline_flag = 0;
	if(	s4_a_tos_line_count >= 3 )															/* COND.f20 */
	{
		if ((st_g_bsm_loop_data.as4_flg_tos_end[0]==0)													/* COND.f4 */
		&&  ((afl_a_frontline_dn[0][1] - afl_a_frontline_dn[s4_a_flontline_dn_num-1][1]) >= -2.0F)) {	/* COND.f21 */
			if( fl_a_frontline_pow_current > fl_a_pow_th )												/* COND.f22 */
			{
				st_g_bsm_loop_data.afl_tos_frontline_pow[0] = fl_a_frontline_pow_current;	/*set current power */
			}
			*ps4_a_frontline_flag = (S4)CU1_TOS_END_MASK_CYCLE;
		}
	}
	else
	{
		/* �ԗ���[���o�̃}�X�N(�ǃg���b�L���O���Z�b�g�p) */
		if( st_g_bsm_loop_data.as4_flg_tos_frontline[0]!=0 )								/* COND.!f12 */
		{
			*ps4_a_frontline_flag = st_g_bsm_loop_data.as4_flg_tos_frontline[0] - (S4)1;
		}
	}

	return;
}

static VD fn_bsm_chkfr_check_tos_end_flg(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	FL fl_a_frontline_pow_current,
	S4 *ps4_a_tos_end_flag
)
{
	if( st_g_bsm_loop_data.as4_flg_tos_end[0] == 0 )										/* COND.f4 */
	{
		if( st_g_bsm_loop_data.afl_tos_frontline_pow[0] != 0.0F )							/* COND.f23 */
		{
			/* �d�͂����������OFF */
			if ((st_g_bsm_loop_data.afl_tos_frontline_pow[0] - fl_a_frontline_pow_current) > afl_a_tos_end_param[2]) {	/* COND.f24 */
				*ps4_a_tos_end_flag = 1;
			}
		}
	}
	else
	{
		/* TOS�I�����o�}�X�N���ԎZ�o�����Z�b�g */
		*ps4_a_tos_end_flag = st_g_bsm_loop_data.as4_flg_tos_end[0] + (S4)1;
	}
	if( *ps4_a_tos_end_flag > (S4)CU1_TOS_END_MASK_CYCLE )				/* COND.25 */
	{
		*ps4_a_tos_end_flag = 0;
		st_g_bsm_loop_data.afl_tos_frontline_pow[0] = 0.0F;
	}

	return;
}

S4 s4_delete_tos_end(
	S4 target_num,									/* [in/out] */
	S4 Tx_int[TARGET_BUFFSIZE][NORM_INT],			/* [in/out] */
	FL Tx_float[TARGET_BUFFSIZE][TGT_FLT],			/* [in/out] */
	const FL tos_end_param[TOS_END_PARAM_SIZE]			/* [in] */
)
{
/****************************************************************************/
/* (7) �x��G���A�O�[���W��������											*/
/****************************************************************************/
	S4 iret = target_num;
	U1 u1_t_jdg_g13_flg;

	/* ����g13�̔���֐��R�[�� �d�l���̋L�q������g13�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A*/
	/* ����g13�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����								*/
	/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�			*/
	u1_t_jdg_g13_flg = u1_delete_tos_end_g13(st_g_bsm_loop_data.as4_flg_passing[0]);

	if ((st_g_bsm_loop_data.as4_flg_tos_end[0] > 1)									/* COND.g1 */
	||  ((st_g_bsm_loop_data.as4_slow_sot_find[1] > WALL_REJECT_TH1)				/* COND.g2 */
	&&   (st_g_bsm_loop_data.as4_flg_passing[0] <= PASSING_COUNT_MIN))				/* COND.g3 */
	||  ((st_g_bsm_loop_data.as4_slow_sot_find[1] > (S4)CU1_WALL_REJECT_TH2)		/* COND.g4 */
	&&   (u1_t_jdg_g13_flg == CU1_TRUE))) {
		/**** Tx(should be removed or combined with target) ****/
		fn_bsm_deltos_delete_tx(
			tos_end_param,
			&iret,
			Tx_int,
			Tx_float
		);

		/**** NORMAL ****/
		fn_bsm_deltos_delete_normal(tos_end_param);

		/**** TARGET ****/
		fn_bsm_deltos_delete_target(tos_end_param);

		/**** NORMAL(SoT) ****/
		fn_init(&st_g_bsm_loop_data.ast_normal_sot[0], 1);
	}
	return iret;
}

/****************************************************************************/
/* �֐���		: u1_delete_tos_end_g13										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �x��G���A�O�[���W���������̏���g13����֐�				*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_passing_flg		: �ǉz�ԃt���O	[in]				*/
/* �߂�l		: u1_t_jdg_g13_flag		: ����g13�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-014								*/
/*				: (7)   �x��G���A�O�[���W���������̏���g13					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_delete_tos_end_g13(S4 s4_a_passing_flg)
{
	/* ����g13���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_g13_flag;				/* ����g13���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_g13_flag = CU1_FALSE;

	/* ����g13�̔��� */
#if (BSM_OPTION_SW_ALART == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (s4_a_passing_flg <= (S4)100) {
		u1_t_jdg_g13_flag = CU1_TRUE;
	} else {
		u1_t_jdg_g13_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_ALART == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (s4_a_passing_flg <= (S4)50) {
		u1_t_jdg_g13_flag = CU1_TRUE;
	} else {
		u1_t_jdg_g13_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */

	return u1_t_jdg_g13_flag;
}

static VD fn_bsm_deltos_delete_tx(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	S4 *ps4_a_final_target_num,
	S4  as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]	
)
{
	S4 i;

	/**** Tx(should be removed or combined with target) ****/
	for(i=0; i<*ps4_a_final_target_num; i++)
	{
		if( afl_a_Tx_float[i][7] > afl_a_tos_end_param[3] )
		{
			s4_initialize_specified_Tx_data(
				as4_a_Tx_int,
				afl_a_Tx_float,
				i
			);
		}
		/* �⏕���W�͂��������L�߂ɍ폜 */
		if ((afl_a_Tx_float[i][7] > (afl_a_tos_end_param[3] - TOS_END_ADDITIONAL_RANGE_2F_TGT))
		&&  (as4_a_Tx_int[i][14] == OBJECT_TYPE_2F)) {
			s4_initialize_specified_Tx_data(
				as4_a_Tx_int,
				afl_a_Tx_float,
				i
			);
		}
	}
	*ps4_a_final_target_num = s4_trim_Tx_data(
		as4_a_Tx_int,
		afl_a_Tx_float
	);

	return;
}

static VD fn_bsm_deltos_delete_normal(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE]
)
{
	S4 i;

	/**** NORMAL ****/
	for(i=0; i<st_g_bsm_loop_data.as4_buf_pair_num[0]; i++)
	{
		if(	st_g_bsm_loop_data.ast_normal[i].fl_Ryfil > afl_a_tos_end_param[3] )								/* COND.g5 */
		{
			fn_init(&st_g_bsm_loop_data.ast_normal[i], 1);
		}
		/* �⏕���W�͂��������L�߂ɍ폜 */
		if ((st_g_bsm_loop_data.ast_normal[i].fl_Ryfil > (afl_a_tos_end_param[3] - TOS_END_ADDITIONAL_RANGE_2F_NRM))	/* COND.g6 */
		&&  (st_g_bsm_loop_data.ast_normal[i].s4_flg_dc == OBJECT_TYPE_2F)) {											/* COND.g7 */
			fn_init(&st_g_bsm_loop_data.ast_normal[i], 1);
		}
		/* �O�}�͂��������L�߂ɍ폜 */
		if ((st_g_bsm_loop_data.ast_normal[i].fl_Ryfil > (afl_a_tos_end_param[3] - 1.0F))								/* COND.g8 */
		&&  (st_g_bsm_loop_data.ast_normal[i].s4_flg_lost != 0)) {														/* COND.g9 */
			fn_init(&st_g_bsm_loop_data.ast_normal[i], 1);
		}
	}
	st_g_bsm_loop_data.as4_buf_pair_num[0] = s4_trim_normal(st_g_bsm_loop_data.ast_normal);

	return;
}

static VD fn_bsm_deltos_delete_target(
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE]
)
{
	S4 i;

	for(i=0; i<st_g_bsm_loop_data.as4_buf_pair_num[1]; i++)
	{
		if(	st_g_bsm_loop_data.ast_target[i].fl_Ryfil > afl_a_tos_end_param[3] )									/* COND.g10 */
		{
			fn_init(&st_g_bsm_loop_data.ast_target[i], 1);
		}
		/* �⏕���W�͂��������L�߂ɍ폜 */
		if ((st_g_bsm_loop_data.ast_target[i].fl_Ryfil > (afl_a_tos_end_param[3] - TOS_END_ADDITIONAL_RANGE_2F_TGT))	/* COND.g11 */
		&&  (st_g_bsm_loop_data.ast_target[i].s4_flg_dc == OBJECT_TYPE_2F)) {											/* COND.g12 */
			fn_init(&st_g_bsm_loop_data.ast_target[i], 1);
		}
	}
	st_g_bsm_loop_data.as4_buf_pair_num[1] = s4_trim_target(st_g_bsm_loop_data.ast_target);

	return;
}

/* judge alarm for BSM */
/* @param :see below */
S4 s4_alarm_bsm2(												/* [return] 0:no alarm, 1:alarm */
	S4 s4_a_final_target_num,									/* [in] */
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],					/* [in] */
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],				/* [in] */
	U1 u1_a_alarming_flg,
	const FL afl_a_tos_end_param[TOS_END_PARAM_SIZE],
	FL fl_a_frontline_pow,
	S4 as4_a_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1],
	const S4 as4_a_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE]
)
{
	S4 iret = 0;
	S4 not_alarm = 0;	/* ��x���Ԏ����x�񔻒肾���͑����� */

	/*** �u���b�N�̓r���Ő錾����Ă���ϐ��Q���u���b�N�̐擪�ֈړ� *******************/
	/* �x��Ώۏ��̏����� */
	FL tmp_alarmed_target[TARGET_BUFFSIZE][ALARM_INFO_SIZE];
	S4 tmp_alarmed_num[1];
	S4 tmp_checked_target[TARGET_BUFFSIZE];
	S4 tmp_checked_alarmed[TARGET_BUFFSIZE];

	/* ���x��Ώۂ̊m�F(�x��p��) */
	S4 tos_flg;	/* ToS�����邩�m�F���ŏ��ɍs�� */
	
	FL fl_t_alarm_area_y_min;

	U1 u1_t_lp_num_target;

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	S4 i;
#endif /*VI �\���p*/

	/* �J�[�uR ���E�ϊ� */
	/* ���p�̏o�̓J�[�u�̍��E��VI�Ŕ��] */

	/* �x��Ώۏ��̏����� */
	fn_initialize_alarm_info(tmp_alarmed_target);
	tmp_alarmed_num[0] = 0;

	for (u1_t_lp_num_target = (U1)0; u1_t_lp_num_target < (U1)TARGET_BUFFSIZE; u1_t_lp_num_target++) {
		tmp_checked_target[u1_t_lp_num_target] = (S4)0;
		tmp_checked_alarmed[u1_t_lp_num_target] = (S4)0;
	}

	fl_t_alarm_area_y_min = CFL_ALARM_Y_BACKWARD;

	/****************************************************************************/
	/* (6) �x��G���A�O�[�Ď�����												*/
	/****************************************************************************/
	/* Before start check_front_1m_line, check the condition of ToS alarm */
	if ((u1_a_alarming_flg == (U1)0)
	&&  (st_g_bsm_loop_data.as4_flg_tos_end[0] == (S4)0)) {
		st_g_bsm_loop_data.as4_flg_tos_frontline[0] = (S4)0;
		st_g_bsm_loop_data.afl_tos_frontline_pow[0] = (FL)0.0F;
	}

	if ((st_g_bsm_loop_data.u1_truck_flg == (U1)0)						/* COND.f1 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)) {			/* COND.f2 */
		st_g_bsm_loop_data.as4_flg_tos_end[0] = s4_check_front_1m_line(afl_a_tos_end_param,
																	   fl_a_frontline_pow,
																	   as4_a_frontline_doa_dn,
																	   as4_a_froneline_doa_peak_num_dn);
	}

	/****************************************************************************/
	/* (7) �x��G���A�O�[���W��������											*/
	/****************************************************************************/
	st_g_bsm_loop_data.s4_final_target_num = s4_delete_tos_end(st_g_bsm_loop_data.s4_final_target_num, 
															   as4_a_Tx_int,
															   afl_a_Tx_float,
															   afl_a_tos_end_param);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(34, &au2_g_bsm_check_tmr[34]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

	/****************************************************************************/
	/* (8)�� FA �L�����Z������													*/
	/****************************************************************************/
	fn_bsm_alart_long_fa_cancel_main(u1_a_alarming_flg, as4_a_Tx_int, afl_a_Tx_float);

/****************************************************************************/
/* (1)	�x��A�N�e�B�u���菈��												*/
/****************************************************************************/
	fn_bsm_alart_check_active(
		&not_alarm, &fl_t_alarm_area_y_min, (const S4 (*)[NORM_INT])as4_a_Tx_int, (const FL (*)[TGT_FLT])afl_a_Tx_float
	);

/****************************************************************************/
/* (2)	�x��p�����W���菈��												*/
/****************************************************************************/
	/* (B) �x��p�� */
	fn_bsm_alart_check_cont_altobj(
		s4_a_final_target_num,
		as4_a_Tx_int,
		afl_a_Tx_float,
		tmp_checked_target,
		tmp_checked_alarmed,
		tmp_alarmed_num,
		tmp_alarmed_target,
		&tos_flg,
		&iret
	);


	/* (C) �x��O�} */
	/***** 4) �x��O�}�^�[�Q�b�g�̊m�F *****/
	fn_bsm_alart_check_exp_altobj(
		tmp_checked_alarmed,
		tmp_alarmed_num,
		tmp_alarmed_target,
		&iret
	);

/****************************************************************************/
/* (4)	�ʏ�x��̈�����菈���i�V�K�x�񕨕W���菈���j						*/
/****************************************************************************/
	/* (C) �V�K�x�� */
	fn_bsm_alart_check_new_altobj(
		s4_a_final_target_num,
		as4_a_Tx_int,
		afl_a_Tx_float,
		(const S4 (*))tmp_checked_target,
		tos_flg,
		tmp_alarmed_num,
		tmp_alarmed_target,
		fl_t_alarm_area_y_min,
		&iret
	);

	/* �x��Ώۏ����R�s�[ */
	fn_bsm_alart_set_alart_target(
		(const S4 (*))tmp_alarmed_num,
		(const FL (*)[ALARM_INFO_SIZE])tmp_alarmed_target
	);

/****************************************************************************/
/* (5)	�x�񏈗�															*/
/****************************************************************************/
	fn_bsm_alart_extend_alart(
		tos_flg,
		not_alarm,
		&iret
	);

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	for(i=0; i<TARGET_BUFFSIZE; i++){
		afl_g_alarmed_target_position[i][0] = tmp_alarmed_target[i][0];
		afl_g_alarmed_target_position[i][1] = tmp_alarmed_target[i][1];
	}
#endif /*VI �\���p*/

	return iret;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_alart_long_fa_cancel_main											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ��FA�L�����Z���������C���֐�												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: u1_a_alarming_flg					: �x�񒆃t���O [in]						*/
/*				  as4_a_Tx_int[][]					: Tx���W(�������) [in/out]				*/
/*				  afl_a_Tx_float[][]				: Tx���W(�����������) [in/out]			*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: �Ȃ�																		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fn_bsm_alart_long_fa_monitoring_target(),									*/
/*				  fn_bsm_alart_long_fa_set_delete_area(), fn_bsm_alart_long_fa_delete_obj()	*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-009	(8)��FA�L�����Z������						*/
/********************************************************************************************/
VD fn_bsm_alart_long_fa_cancel_main(U1 u1_a_alarming_flg,
									S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
									FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT])
{
	FL fl_t_delete_area;		/* ���W�폜�G���A */
	U1 u1_t_flg_obj_delete;		/* ���W�폜�t���O OFF:���W�폜���Ȃ� ON;���W�폜���� */

	/* �^�[�Q�b�g���W�Ď� */
	fn_bsm_alart_long_fa_monitoring_target(u1_a_alarming_flg);

	/* ���W�폜�G���A�ݒ� */
	fn_bsm_alart_long_fa_set_delete_area(&fl_t_delete_area, &u1_t_flg_obj_delete);

	/* ���W�폜��FA���W�폜���J�E���^�ݒ� */
	fn_bsm_alart_long_fa_delete_obj(fl_t_delete_area, u1_t_flg_obj_delete, as4_a_Tx_int, afl_a_Tx_float);

	return;
}


/********************************************************************************************/
/* �֐���		: fn_bsm_alart_long_fa_monitoring_target									*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �^�[�Q�b�g���W�Ď� 														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: u1_a_alarming_flg					: �x�񒆃t���O [in]						*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement	: �ǃt���O(FA�폜�p)	*/
/*				  st_g_bsm_loop_data.as4_buf_pair_num[]				: ���W���ƃ^�[�Q�b�g��	*/
/*				  st_g_bsm_loop_data.ast_target[]					: �^�[�Q�b�g���		*/
/*				  st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[]	: �ᑬ SoT ����]���l	*/
/* <output>		: st_g_bsm_loop_data.ast_target[]					: �^�[�Q�b�g���		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-009	(8)��FA�L�����Z������ �^�[�Q�b�g���W�Ď�	*/
/********************************************************************************************/
VD fn_bsm_alart_long_fa_monitoring_target(U1 u1_a_alarming_flg)
{
	U4 u4_t_lp_target;			/* �^�[�Q�b�g���W�̃��[�v�ϐ� */
	U4 u4_t_lp_max_target_num;	/* �^�[�Q�b�g���W�̃��[�v�̏���l */

	/* �^�[�Q�b�g���W�̃��[�v�̏���l��ݒ�(�\�t�g�ϓ_�ɂ�����K�[�h����) */
	/* �^�[�Q�b�g����TARGET_BUFFSIZE�𒴂��Ă��Ȃ������� �����Ă���ꍇ��TARGET_BUFFSIZE������l�Ƃ��� */
	if (st_g_bsm_loop_data.as4_buf_pair_num[1] > (S4)TARGET_BUFFSIZE) {
		u4_t_lp_max_target_num = (U4)TARGET_BUFFSIZE;
	} else {
		/* �^�[�Q�b�g���͕��̒l�ɂȂ�Ȃ����߁AU4�L���X�g���Ă����Ȃ� */
		u4_t_lp_max_target_num = (U4)st_g_bsm_loop_data.as4_buf_pair_num[1];
	}

	/* �^�[�Q�b�g���W�Ď� */
	/* �Ď��G���A���ɂ���^�[�Q�b�g���W�̊Ď��J�E���^���J�E���g�A�b�v���� */
	if ((u1_a_alarming_flg == (U1)1)																					/* COND.h1 */
	&&	(st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement == (U1)1)) {													/* COND.h2 */
		for (u4_t_lp_target = (U4)0; u4_t_lp_target < u4_t_lp_max_target_num; u4_t_lp_target++) {
			if (((st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > CFL_FA_MONITORING_AREA)							/* COND.h3 */
			&&	 (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] < (S4)80)													/* COND.h4 */
			&&	 (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] < (S4)80))												/* COND.h5 */
			||	(st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > (FL)200.0F)) {									/* COND.h6 ���������� */
				/* 125�ŏ���K�[�h */
				if (st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa >= (U4)125) {
					st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa = (U4)125;
				} else {
					st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa++;				/* PROC.1 */
				}
			} else if ((st_g_bsm_loop_data.u1_flg_heisou_car == (U1)0)												/* COND.h8 */
				   &&  (st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > CFL_FA_MONITORING_AREA)			/* COND.h3 */
				   &&  ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] < (S4)80)									/* COND.h4 */
				   ||   (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] < (S4)80))) {								/* COND.h5 */
				/* 0�ŉ����K�[�h */
				if (st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa > (U4)0) {
					st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa--;				/* PROC.5 */
				}
			} else {
				st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa = (U4)0;			/* PROC.2 */
			}
		}
	} else {
		/* �S�^�[�Q�b�g���W�̊Ď��J�E���^�����Z�b�g���� */
		for (u4_t_lp_target = (U4)0; u4_t_lp_target < (U4)TARGET_BUFFSIZE; u4_t_lp_target++) {
			st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa = (U4)0;		/* PROC.2 */
		}
	}

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_alart_long_fa_set_delete_area										*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�폜�G���A�ݒ� 														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: pfl_a_delete_area					: ���W�폜�G���A [in/out]				*/
/*				  pu1_a_flg_obj_delete				: ���W�폜�t���O [in/out]				*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_loop_data.ast_target[]					: �^�[�Q�b�g���		*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-009	(8)��FA�L�����Z������ 1)���W�폜�G���A�ݒ�	*/
/********************************************************************************************/
VD fn_bsm_alart_long_fa_set_delete_area(FL* pfl_a_delete_area, U1* pu1_a_flg_obj_delete)
{
	U4 u4_t_lp_target;			/* �^�[�Q�b�g���W�̃��[�v�ϐ� */
	U4 u4_t_ctr_fa_max;			/* FA�Ď��J�E���^�ő�l */
	FL fl_t_delete_area;		/* ���W�폜�G���A */
	U1 u1_t_flg_obj_delete;		/* ���W�폜�t���O OFF:���W�폜���Ȃ� ON;���W�폜���� */

	u1_t_flg_obj_delete = CU1_DF_OFF;

	/* �^�[�Q�b�g���W�̊Ď��J�E���^�l����A���W�폜�G���A��ݒ肷�� */
	/** 1)���W�폜�G���A�ݒ� **/
	/* Proc.1 �S�^�[�Q�b�g���W�̒��ōő�̊Ď��J�E���^�l���Z�o���� */
	u4_t_ctr_fa_max = (U4)0;
	for (u4_t_lp_target = (U4)0; u4_t_lp_target < (U4)TARGET_BUFFSIZE; u4_t_lp_target++) {
		if (st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa > u4_t_ctr_fa_max) {
			u4_t_ctr_fa_max = st_g_bsm_loop_data.ast_target[u4_t_lp_target].u4_ctr_fa;
		}
	}

	/* Proc.2 */
	/*  �ő�J�E���g�l���畨�W�폜����G���A�����߂� */
	if (u4_t_ctr_fa_max > (U4)CU1_TH_FA_DELETE_CYCLE) {			/* COND.h7 */
		/* ��fl_t_delete_area�ɕ��W�폜�����l��ݒ肵���̂ŁA���킹�ăZ�b�g���镨�W�폜�t���O��ON�ɂ��� */
		/* ��fl_t_delete_area��u1_t_flg_obj_delete�͕K���A�������邱�� */
		fl_t_delete_area = CFL_FA_DELETE_AREA;
		u1_t_flg_obj_delete = CU1_DF_ON;
	} else {
		/* �폜���Ȃ� */
		/* ��fl_t_delete_area�ɕ��W�폜����Ȃ��l(�����l)��ݒ肵���̂ŁA���킹�ăZ�b�g���镨�W�폜�t���O��OFF�ɂ��� */
		/* ��fl_t_delete_area��u1_t_flg_obj_delete�͕K���A�������邱�� */
		fl_t_delete_area = (FL)100.0F;
		u1_t_flg_obj_delete = CU1_DF_OFF;
	}

	/* �����ɕ��W�폜�G���A�ƕ��W�폜�t���O���Z�b�g */
	*pfl_a_delete_area = fl_t_delete_area;
	*pu1_a_flg_obj_delete = u1_t_flg_obj_delete;

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_alart_long_fa_delete_obj											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�폜��FA���W�폜���J�E���^�ݒ� 										*/
/*------------------------------------------------------------------------------------------*/
/* ����			: fl_a_delete_area					: ���W�폜�G���A [in]					*/
/*				  u1_a_flg_obj_delete				: ���W�폜�t���O [in]					*/
/*				  as4_a_Tx_int[][]					: Tx���W(�������) [in/out]				*/
/*				  afl_a_Tx_float[][]				: Tx���W(�����������) [in/out]			*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_loop_data.as4_buf_pair_num[]				: ���W���ƃ^�[�Q�b�g��	*/
/*				  st_g_bsm_loop_data.ast_target[]					: �^�[�Q�b�g���		*/
/*				  st_g_bsm_loop_data.ast_normal[]					: ���W���				*/
/*				  st_g_bsm_loop_data.s4_final_target_num			: Tx���W��			*/
/*				  st_g_bsm_loop_data.ast_normal_sot[]				: �O�������W���		*/
/* <output>		: st_g_bsm_loop_data.as4_buf_pair_num[]				: ���W���ƃ^�[�Q�b�g��	*/
/*				  st_g_bsm_loop_data.ast_target[]					: �^�[�Q�b�g���		*/
/*				  st_g_bsm_loop_data.ast_normal[]					: ���W���				*/
/*				  st_g_bsm_loop_data.s4_final_target_num			: Tx���W��			*/
/*				  st_g_bsm_loop_data.ast_normal_sot[]				: �O�������W���		*/
/*				  st_g_bsm_loop_data.u1_fa_delete_count				: FA���W�폜���J�E���^	*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fn_init(), s4_trim_target(), s4_initialize_specified_Tx_data(),			*/
/*				  s4_trim_Tx_data(), s4_trim_normal(), u2_data_add()						*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-009	(8)��FA�L�����Z������ 2)���W�폜 3)�㏈��	*/
/********************************************************************************************/
VD fn_bsm_alart_long_fa_delete_obj(FL fl_a_delete_area,
								   U1 u1_a_flg_obj_delete,
								   S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
								   FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT])
{
	U4 u4_t_lp_target;						/* �^�[�Q�b�g���W�̃��[�v�ϐ� */
	U4 u4_t_lp_final_target;				/* Tx���W�̃��[�v�ϐ� */
	U4 u4_t_lp_normal;						/* NORMAL���W�̃��[�v�ϐ� */
	U4 u4_t_lp_max_target_num;				/* �^�[�Q�b�g���W�̃��[�v�̏���l */
	U4 u4_t_lp_max_final_target_num;		/* Tx���W�̃��[�v�̏���l */
	U4 u4_t_lp_max_normal_num;				/* NORMAL���W�̃��[�v�̏���l */

	/* �^�[�Q�b�g���W�̃��[�v�̏���l��ݒ�(�\�t�g�ϓ_�ɂ�����K�[�h����) */
	/* �^�[�Q�b�g����TARGET_BUFFSIZE�𒴂��Ă��Ȃ������� �����Ă���ꍇ��TARGET_BUFFSIZE������l�Ƃ��� */
	if (st_g_bsm_loop_data.as4_buf_pair_num[1] > (S4)TARGET_BUFFSIZE) {
		u4_t_lp_max_target_num = (U4)TARGET_BUFFSIZE;
	} else {
		/* �^�[�Q�b�g���͕��̒l�ɂȂ�Ȃ����߁AU4�L���X�g���Ă����Ȃ� */
		u4_t_lp_max_target_num = (U4)st_g_bsm_loop_data.as4_buf_pair_num[1];
	}

	/* Tx���W�̃��[�v�̏���l��ݒ�(�\�t�g�ϓ_�ɂ�����K�[�h����) */
	/* Tx���W����TARGET_BUFFSIZE�𒴂��Ă��Ȃ������� �����Ă���ꍇ��TARGET_BUFFSIZE������l�Ƃ��� */
	if (st_g_bsm_loop_data.s4_final_target_num > (S4)TARGET_BUFFSIZE) {
		u4_t_lp_max_final_target_num = (U4)TARGET_BUFFSIZE;
	} else {
		/* Tx���W�̌��͕��̒l�ɂȂ�Ȃ����߁AU4�L���X�g���Ă����Ȃ� */
		u4_t_lp_max_final_target_num = (U4)st_g_bsm_loop_data.s4_final_target_num;
	}

	/* NORMAL���W�̃��[�v�̏���l��ݒ�(�\�t�g�ϓ_�ɂ�����K�[�h����) */
	/* NORMAL���W����NORMAL_BUFFSIZE�𒴂��Ă��Ȃ������� �����Ă���ꍇ��NORMAL_BUFFSIZE������l�Ƃ��� */
	if (st_g_bsm_loop_data.as4_buf_pair_num[0] > (S4)NORMAL_BUFFSIZE) {
		u4_t_lp_max_normal_num = (U4)NORMAL_BUFFSIZE;
	} else {
		/* NORMAL���W�̌��͕��̒l�ɂȂ�Ȃ����߁AU4�L���X�g���Ă����Ȃ� */
		u4_t_lp_max_normal_num = (U4)st_g_bsm_loop_data.as4_buf_pair_num[0];
	}


	/** 2)���W�폜 **/
	/* delete_area ���O���ɂ��镨�W�����ׂč폜���� */
	/* Proc.1�̏����͎d�l���ł�delete_area != 100.0�ł��邪�A�����������m�̓����͋֎~����Ă���B */
	/* ���̂��߁A���W�폜�t���Ou1_t_flg_obj_delete��p�ӂ��A��������m�F����悤�ɂ��Ă��� */
	/* ��肽�����Ƃ͎����ł��Ă���̂Ŗ��Ȃ� */
	/* Proc.1 */
	if (u1_a_flg_obj_delete == CU1_DF_ON) {
		/* (i) Y ���������o�͒l > delete_area �𖞂����A�^�[�Q�b�g���W�����ׂč폜 */
		for (u4_t_lp_target = (U4)0; u4_t_lp_target < u4_t_lp_max_target_num; u4_t_lp_target++) {
			if (st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > fl_a_delete_area){
				fn_init(&st_g_bsm_loop_data.ast_target[u4_t_lp_target], (S4)1);
			}
		}
		/* (v) ���W�폜�����ꍇ�́A��o�b�t�@���l�߁A���W�����f�N�������g���� */
		st_g_bsm_loop_data.as4_buf_pair_num[1] = s4_trim_target(st_g_bsm_loop_data.ast_target);

		/* (ii) Y ���������o�͒l > delete_area �𖞂����ATx ���W�����ׂč폜 */
		for (u4_t_lp_final_target = (U4)0; u4_t_lp_final_target < u4_t_lp_max_final_target_num; u4_t_lp_final_target++) {
			if (afl_a_Tx_float[u4_t_lp_final_target][7] > fl_a_delete_area) {
				s4_initialize_specified_Tx_data(as4_a_Tx_int, afl_a_Tx_float, u4_t_lp_final_target);
			}
		}
		/* (v) ���W�폜�����ꍇ�́A��o�b�t�@���l�߁A���W�����f�N�������g���� */
		st_g_bsm_loop_data.s4_final_target_num = s4_trim_Tx_data(as4_a_Tx_int, afl_a_Tx_float);
		
		/* Tx = Target �Ȃ̂ŁA�폜���������킹�Ȃ��ƕs������������B */
		/* (�o�̓��O�ŕ��W���ƕ��W��񂪍��킸,�X�R�A�v���ł��Ȃ� �Ȃ�) */

		/* (iii) Y ���������o�͒l > delete_area �𖞂����ANormal ���W�����ׂč폜 */
		for (u4_t_lp_normal = (U4)0; u4_t_lp_normal < u4_t_lp_max_normal_num; u4_t_lp_normal++) {
			if (st_g_bsm_loop_data.ast_normal[u4_t_lp_normal].fl_Ryfil > fl_a_delete_area) {
				fn_init(&st_g_bsm_loop_data.ast_normal[u4_t_lp_normal], (S4)1);
			}
		}
		/* (v) ���W�폜�����ꍇ�́A��o�b�t�@���l�߁A���W�����f�N�������g���� */
		st_g_bsm_loop_data.as4_buf_pair_num[0] = s4_trim_normal(st_g_bsm_loop_data.ast_normal);

		/* (iv) Y ���������o�͒l > delete_area �𖞂����ANormal(SoT)���W�����ׂč폜 */
		if (st_g_bsm_loop_data.ast_normal_sot[0].fl_Ryfil > fl_a_delete_area) {
			fn_init(&st_g_bsm_loop_data.ast_normal_sot[0], (S4)1);
		}

		/* Normal(SoT)���W��1�݂̂ł���̂ŁA��o�b�t�@���l�߁A���W�����f�N�������g���鏈���͎��{���Ȃ��B */
		/* ���㕡���L������悤�ɂȂ����ꍇ�́A��o�b�t�@���l�߁A���W�����f�N�������g���鏈�������{����B */

		/* (vi) FA ���W�폜���J�E���^���Z�b�g���� */
		/* ������Ńf�N�������g����̂� +1 ���Ă��� */
		st_g_bsm_loop_data.u1_fa_delete_count = (U1)10 + (U1)1;					/* PROC.3 */
	}

	/* 3)�㏈�� */
	/* FA ���W�폜���J�E���^���J�E���g�_�E������B���̃J�E���^�͕��W���폜�����Ƃ��ɃZ�b�g����A */
	/* 0�ɂȂ�܂ł͌x�񕨕W�̊O�}�͋֎~�ƂȂ� */
	/* 0�ŉ����K�[�h */
	st_g_bsm_loop_data.u1_fa_delete_count = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_fa_delete_count, (S2)-1, (U2)CU1_U1MAX, (U2)0);		/* PROC.4 */

	return;
}

static VD fn_bsm_alart_check_active(
	S4 *ps4_t_not_alarm,
	FL *pfl_a_alarm_area_y_min,
	const S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	const FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT]
)
{
	FL fl_t_th_canout_curvr;		/* �x���~臒l(FL) */
	S2 s2_t_th_canout_curvr;		/* �x���~臒l(S2) */
	S4 s4_t_lp_tx_num;				/* Tx���W�̃��[�v�ϐ� */
	U1 u1_t_flg_tos_target_in;		/* ToS�^�[�Q�b�g���݃t���O OFF:ToS�^�[�Q�b�g���� ON:ToS�^�[�Q�b�g���� */

/****************************************************************************/
/* (1)	�x��A�N�e�B�u���菈��												*/
/****************************************************************************/
	/* �x��A�N�e�B�u���� */
	/* 1)��x���Ԃ̊m�F(���x) */
	if (st_g_bsm_alarm_data.s4_alarm_prev != (S4)0) {					/* COND.a13 */
		if (fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN_OFF) {		/* COND.a12 */
			st_g_bsm_alarm_data.as4_alarm_off_count[0] = (S4)0;
			*ps4_t_not_alarm = (S4)1;
		}
	} else {
		if (fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN) {			/* COND.a1 */
			st_g_bsm_alarm_data.as4_alarm_off_count[0] = (S4)0;
			*ps4_t_not_alarm = (S4)1;
		}
	}
	
	/* 2)��x���Ԃ̊m�F�i���x�A�X���b�v����j */
	/* ToS�^�[�Q�b�g���G���A���ɑ��݂���ꍇ�������A��x���ԂƂ��� */
	u1_t_flg_tos_target_in = (U1)0;
	/* �S�Ă̌x��^�[�Q�b�g�̒��ŁAToS�^�[�Q�b�g�����邩�T�� */
	for (s4_t_lp_tx_num = (S4)0; s4_t_lp_tx_num < st_g_bsm_loop_data.s4_final_target_num; s4_t_lp_tx_num++) {
		if ((as4_a_Tx_int[s4_t_lp_tx_num][17] >= (S4)5)												/* COND.a17 */
		&&  (afl_a_Tx_float[s4_t_lp_tx_num][10] > (CFL_ALARM_Y_BACKWARD + ALARM_Y_OFFSET))) {		/* COND.a18 */
			u1_t_flg_tos_target_in = (U1)1;
			break;
		}
	}

	/* �X���b�v���Ōx��G���A����ToS�^�[�Q�b�g������Ȃ��ꍇ�ɔ�x���ԂƂ��� */
	if ((u1_slipjdg_get_slip_flag() == (U1)1)
	&&  (u1_t_flg_tos_target_in == (U1)0)) {
		st_g_bsm_alarm_data.as4_alarm_off_count[0] = (S4)0;
		*ps4_t_not_alarm = (S4)1;
	}

	/* 3)��x���Ԃ̊m�F�i�J�[�u�q�j*/
	/* ���H�ȗ�(����R)��臒l�ȉ��̂Ƃ��͐V�K�x����~���� */
	/* �x���~臒l�Z�o */
	fl_t_th_canout_curvr = (FL)CANOUT_CURVER_MIN;

	/* FL��S2�ɕϊ� */
	s2_t_th_canout_curvr = s2_cast_from_fl(fl_t_th_canout_curvr);
	
	/* �V�K�x����֎~���邩���� */
	if ((s4_abs((S4)s2_g_curvr_for_base) < (S4)s2_t_th_canout_curvr)	/* COND.a2 */
	&&	(st_g_bsm_alarm_data.s4_alarm_prev == (S4)0)) {					/* COND.a4 */
		*ps4_t_not_alarm = (S4)1;
	}

	/* 4)���W�M������}�X�N���Ԑݒ�  */
	fn_bsm_alart_set_reliable_jdg_mask_count((const S4 (*))ps4_t_not_alarm);
	
	/* 5)�x��G���A��[�̐ݒ� */
	fn_bsm_alart_set_backward_line_of_alarm_area(pfl_a_alarm_area_y_min);

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_alart_set_reliable_jdg_mask_count									*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: ���W�M������}�X�N���Ԑݒ� 												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: ps4_a_not_alarm					: ��x���ԃt���O [in]					*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_alarm_data.s4_alarm_prev				: �O��x��t���O [in]		*/
/*				  st_g_bsm_loop_data.u1_reliable_jdg_mask_count	: ���W�M������}�X�N�J�E���^*/
/* <output>		: st_g_bsm_loop_data.u1_reliable_jdg_mask_count	: ���W�M������}�X�N�J�E���^*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: u2_data_add()																*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-007												*/
/*				  (1)�x��A�N�e�B�u���菈�� 4)���W�M������}�X�N���Ԑݒ�					*/
/********************************************************************************************/
static VD fn_bsm_alart_set_reliable_jdg_mask_count(const S4 *ps4_a_not_alarm)
{
	/* 4)���W�M������}�X�N���Ԑݒ�  */
	if ((st_g_bsm_alarm_data.s4_alarm_prev == (S4)1)					/* COND.a6 */
	||  (*ps4_a_not_alarm == (S4)1)) {									/* COND.a7 */
		st_g_bsm_loop_data.u1_reliable_jdg_mask_count = (U1)12;
	} else {
		st_g_bsm_loop_data.u1_reliable_jdg_mask_count = (U1)u2_data_add(st_g_bsm_loop_data.u1_reliable_jdg_mask_count, (S2)-1, (U2)CU1_U1MAX, (U2)0);
	}
	
	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_alart_set_backward_line_of_alarm_area								*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �x��G���A��[�̐ݒ� 														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: pfl_a_alarm_area_y_min			: �x��G���A��[ [in]					*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: fl_g_v_self_bsm_for_base					: ���ԑ� [km/h]					*/
/*				  s2_g_curvr_for_base						: ����R [m]						*/
/*				  st_g_bsm_loop_data.u1_shrink_on_count		: �x��G���A�k������ [cycle]	*/
/*				  st_g_bsm_loop_data.u1_shrink_keep_count	: �k���p���J�E���^ [cycle]		*/
/* <output>		: st_g_bsm_loop_data.u1_shrink_on_count		: �x��G���A�k������ [cycle]	*/
/*				  st_g_bsm_loop_data.u1_shrink_keep_count	: �k���p���J�E���^ [cycle]		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: u2_data_add(), u1_cast_from_fl()											*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-007												*/
/*				  (1)�x��A�N�e�B�u���菈�� 5)�x��G���A��[�̐ݒ�							*/
/********************************************************************************************/
static VD fn_bsm_alart_set_backward_line_of_alarm_area(FL *pfl_a_alarm_area_y_min)
{
	FL fl_t_shrink_keep_count_sec;			/* �k���p���J�E���^ �P��:1s */
	FL fl_t_alarm_area_y_min;				/* �x��G���A��[ �ݒ�p�ϐ� */

	/* �����l�ł���CFL_ALARM_Y_BACKWARD�ŏ����� */
	fl_t_alarm_area_y_min = CFL_ALARM_Y_BACKWARD;

	/* �ii�j�x��G���A�k�����Ԃ��J�E���g */
	/* �E�Z���T�͉E�J�[�u�A���Z���T�͍��J�[�u�̂ݎ��{ */
	if ((fl_g_v_self_bsm_for_base >= CFL_CANOUT_VSELF_MIN)		/* COND.a10 */
	&&	((s2_g_curvr_for_base > (S4)0)					/* COND.a11 */	/* 24G�ł͍��E���ʉ��̂��߂ɃJ�[�uR�͉E�Z���T�͉E�܂����A���Z���T�͍��܂����ƂȂ�B */
	&&   (s2_g_curvr_for_base < (S4)30))) {								/* �]���āA����a11�ŉE�Z���T�͉E�J�[�u�A���Z���T�͍��J�[�u�̏����ƂȂ� 				*/
		st_g_bsm_loop_data.u1_shrink_on_count = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_shrink_on_count, (S2)1, (U2)12, (U2)0);		/* PROC.9 */
	} else {
		st_g_bsm_loop_data.u1_shrink_on_count = (U1)0;																					/* PROC.10 */
	}

	/* �iii�j�x��G���A�k���p���J�E���^�ݒ� */
	/* �ii�j�ŃJ�E���g�����x��G���A�k�����Ԃ����ɒB������A�ԑ��ɉ������k���p���J�E���^��ݒ肷�� */
	if (st_g_bsm_loop_data.u1_shrink_on_count >= (U1)12) {									/* COND.a14 */
		/* �P��sec�̏k���p���J�E���^�Z�o */
		fl_t_shrink_keep_count_sec = ((FL)7.0F / (fl_g_v_self_bsm_for_base / (FL)3.6F)) + (FL)0.3F;		/* PROC.11 */
		/* 2.5s�ŏ���K�[�h */
		if (fl_t_shrink_keep_count_sec > (FL)2.5F) {
			fl_t_shrink_keep_count_sec = (FL)2.5F;
		}
		/* �P�ʂ�sec��cycle�֒P�ʕϊ� */
		st_g_bsm_loop_data.u1_shrink_keep_count = u1_cast_from_fl(fl_t_shrink_keep_count_sec / CFL_SAMPLING_TIME);		/* PROC.11 */
	}

	/* �ԑ�����x������ƂȂ����ꍇ�A�k���p���J�E���^�����Z�b�g���� */
	if (fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN) {		/* COND.a1 */
		st_g_bsm_loop_data.u1_shrink_keep_count = (U1)0;		/* PROC.12 */
	}

	/*�iiii�j�x��G���A��[�ݒ�  */
	/* �J�[�u�q�ƁA�iii�j�ł��Ƃ߂��k���p���J�E���^�l�ɉ����āA�x��G���A��[��ݒ肷�� */
	if (s4_abs(s2_g_curvr_for_base) < (S4)30) {
		fl_t_alarm_area_y_min = (FL)-1.0F;
	} else if (s4_abs(s2_g_curvr_for_base) < (S4)55) {
		fl_t_alarm_area_y_min = (FL)-4.0F;
	} else {
		if (st_g_bsm_loop_data.u1_shrink_keep_count > (U1)0) {
			/* �G���A�k�ނ���莞�Ԍp������(�E���ܑ΍�) */
			fl_t_alarm_area_y_min = (FL)-4.0F;
			/* �G���A�ݒ��A�x��G���A�p���J�E���^�l���f�N�������g */
			st_g_bsm_loop_data.u1_shrink_keep_count = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_shrink_keep_count, (S2)-1, (U2)31, (U2)0);
		} else {
			/* fl_t_alarm_area_y_min = CFL_ALARM_Y_BACKWARD�̂܂� */
		}
	}

	/* �����Ɍx��G���A��[���Z�b�g */
	*pfl_a_alarm_area_y_min = fl_t_alarm_area_y_min;

	return;
}


static VD fn_bsm_alart_check_cont_altobj(
	S4 s4_final_a_target_num,
	S4 as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_tos_flg,
	S4 *ps4_a_alarm_flg
)
{
	/* 1) ToS�x���Ԃ̊m�F */
	fn_bsm_alart_check_tos_status(
		ps4_a_tos_flg
	);

	/* (B) �x��p�� */
	fn_bsm_alart_cont_altobj(
		s4_final_a_target_num,
		as4_a_Tx_int,
		afl_a_Tx_float,
		as4_a_checked_target,
		as4_a_checked_alarmed,
		as4_a_alarmed_target_num_current,
		afl_a_alarmed_target_current,
		ps4_a_alarm_flg
	);

	return;
}

static VD fn_bsm_alart_check_tos_status(
	S4 *ps4_a_tos_flg
)
{
	S4 i;

	/***** 1) ToS��Ԃ̊m�F *****/
	*ps4_a_tos_flg = 0;
	for(i=0; i<st_g_bsm_alarm_data.as4_alarmed_num[0]; i++)
	{
		if(st_g_bsm_alarm_data.afl_alarmed_target[i][4]==ALARM_TYPE_TOS) {	/* COND.b1 */
			*ps4_a_tos_flg = 1;
			break;
		}
	}

	return;
}

static VD fn_bsm_alart_cont_altobj(
	S4 s4_final_a_target_num,
	signed long as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
)
{
	S4 i;

	S4 s4_t_index;
	S4 s4_t_selected_alarmed_target_index;

	/***** 2) �x��p���^�[�Q�b�g�̊m�F *****/
	for(i=0; i<s4_final_a_target_num; i++)
	{
		s4_t_index = -1;																			/* PROC.3 */
		s4_t_selected_alarmed_target_index = -1;													/* PROC.4 */

		/* �O��x�񕨕W��I������(��ԋ߂�) */
		fn_bsm_alart_select_altobj_prev(
			&as4_a_Tx_int[i],
			(const FL (*)[TGT_FLT])&afl_a_Tx_float[i],
			&s4_t_selected_alarmed_target_index
		);

		/* ����x�񕨕W�m�� */
		if(s4_t_selected_alarmed_target_index != -1) {												/* COND.b6 */
			fn_bsm_alart_set_altobj_cur(
				(const FL (*)[TGT_FLT])&afl_a_Tx_float[i],
				(const FL (*)[ALARM_INFO_SIZE])&st_g_bsm_alarm_data.afl_alarmed_target[s4_t_selected_alarmed_target_index],
				(const S4 (*))as4_a_alarmed_target_num_current,
				(const FL (*)[ALARM_INFO_SIZE])afl_a_alarmed_target_current,
				&s4_t_index
			);

			as4_a_checked_target[i] = 1;															/* PROC.17 */
			as4_a_checked_alarmed[s4_t_selected_alarmed_target_index] = 1;							/* PROC.18 */
		}

		/* 3) �x��p���^�[�Q�b�g���̕ۑ� */
		if(	s4_t_index != -1 ) {																	/* COND.b13 */
			fn_bsm_alart_store_cont_altobj(
				(const signed long (*)[NORM_INT])&as4_a_Tx_int[i],
				(const FL (*)[TGT_FLT])&afl_a_Tx_float[i],
				(const FL (*)[ALARM_INFO_SIZE])&st_g_bsm_alarm_data.afl_alarmed_target[s4_t_selected_alarmed_target_index],
				&afl_a_alarmed_target_current[as4_a_alarmed_target_num_current[0]],
				ps4_a_alarm_flg
			);
			as4_a_alarmed_target_num_current[0]++;
		}
	}

	return;
}

static VD fn_bsm_alart_select_altobj_prev(
	signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	S4 *ps4_a_selected_alarmed_target_index
)
{
	S4 j;

	FL object_x;
	FL object_y;
	FL alarmed_x;
	FL alarmed_y;

	FL tmp_xydiff_min = fl_abs(CFL_UNKNOWN_VALUE*2);

	object_x = afl_a_Tx_float[0][9];															/* PROC.1 Rxpred */
	object_y = afl_a_Tx_float[0][10];															/* PROC.1/2 Rypred */
	if(u1_g_sns_pos==SENSOR_LEFT) {																/* COND.b2 */
		object_x = -object_x;																	/* PROC.2 */
	}

	*ps4_a_selected_alarmed_target_index = -1;													/* PROC.4 */
	tmp_xydiff_min = fl_abs(CFL_UNKNOWN_VALUE*2.0F);											/* PROC.5 */
	for(j=0; j<st_g_bsm_alarm_data.as4_alarmed_num[0]; j++)
	{
		alarmed_x = st_g_bsm_alarm_data.afl_alarmed_target[j][0];								/* PROC.6 */
		if(u1_g_sns_pos==SENSOR_LEFT) {															/* COND.b2 */
			alarmed_x = - alarmed_x;															/* PROC.7 */
		}
		alarmed_y = st_g_bsm_alarm_data.afl_alarmed_target[j][1];								/* PROC.6/7 */
		if ((fl_abs(object_x - alarmed_x) < RX_TH_ALM)											/* COND.b3 */
		&&  (fl_abs(object_y - alarmed_y) < RY_TH_ALM)											/* COND.b4 */
		&&  (tmp_xydiff_min > (fl_abs(object_x - alarmed_x) + fl_abs(object_y - alarmed_y)))) {	/* COND.b5 */
			tmp_xydiff_min = fl_abs(object_x - alarmed_x) + fl_abs(object_y - alarmed_y);		/* PROC.8 */
			*ps4_a_selected_alarmed_target_index = j;											/* PROC.9 */
		}
	}

	return;
}

static VD fn_bsm_alart_set_altobj_cur(
	const FL afl_a_Tx_float[1][TGT_FLT],
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	const S4 as4_a_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_index
)
{
	S4 k;

	FL object_x;
	FL object_y;

	FL tmp_x_min;
	FL tmp_x_max;
	FL tmp_y_min;
	FL tmp_y_max;
	FL tmp_alarm_area[4];
	FL tmp_offset[3];

	FL tmp_comp;
	FL tmp_min;

	object_x = afl_a_Tx_float[0][9];																/* PROC.1 Rxpred */
	object_y = afl_a_Tx_float[0][10];																/* PROC.1/2 Rypred */

	if(u1_g_sns_pos==SENSOR_LEFT)																	/* COND.b2 */
	{
		object_x = -object_x;																		/* PROC.2 */
	}

	/* calculate hysteresis area */
	/* use start line */
	tmp_alarm_area[0] = afl_a_alarmed_target[0][12];												/* PROC.10 xmin */
	tmp_alarm_area[1] = afl_a_alarmed_target[0][13];												/* PROC.10 xmax */
	tmp_alarm_area[2] = afl_a_alarmed_target[0][14];												/* PROC.10 ymin */
	tmp_alarm_area[3] = afl_a_alarmed_target[0][15];												/* PROC.10 ymax */

	tmp_offset[0] = ALARM_X_OFFSET_OUT;
	tmp_offset[1] = ALARM_Y_OFFSET;
	tmp_offset[2] = ALARM_X_OFFSET_IN;

	get_hysteresis_area(																			/* SEC.4-(3) */
		object_y,
		afl_a_alarmed_target[0][4],
		tmp_alarm_area,
		tmp_offset
	);
	tmp_x_min = tmp_alarm_area[0];
	tmp_x_max = tmp_alarm_area[1];
	tmp_y_min = tmp_alarm_area[2];
	tmp_y_max = tmp_alarm_area[3];

#if (BSM_OPTION_SW_ALART == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_ALART == TYPE_B)
	/* Expend alarm area if there is a alarmed target and		*/
	/* the predicted lateral relative speed of target is small	*/
	if (afl_a_Tx_float[0][15] < (FL)0.1F) {
		tmp_x_max += (FL)0.1F;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */

	/* check if the target is in alarm area */
	if ((object_x > tmp_x_min)																		/* COND.b7 */
	&&  (object_x < tmp_x_max)																		/* COND.b8 */
	&&  (object_y < tmp_y_max)																		/* COND.b9 */
	&&  (object_y > tmp_y_min)) {																	/* COND.b10 */
		if( as4_a_alarmed_target_num_current[0] < (S4)(TARGET_BUFFSIZE-1) )							/* COND.b11 */
		{
			*ps4_a_index = as4_a_alarmed_target_num_current[0];										/* PROC.11 */
		}
		/* when output buffer is full */
		else
		{
			tmp_min = 1000.0F;																		/* PROC.13 */
			tmp_comp = 0.0F;																		/* PROC.14 */
			/* erase the nearest one and save the new one */
			for(k=0; k<TARGET_BUFFSIZE; k++)
			{
				tmp_comp = fl_abs(afl_a_alarmed_target_current[k][0]-afl_a_Tx_float[0][8])	 		/* PROC.15 Rxfil + Ryfil */
							+ fl_abs(afl_a_alarmed_target_current[k][1]-afl_a_Tx_float[0][7]);
				if(tmp_comp < tmp_min)																/* COND.b12 */
				{
					*ps4_a_index = k;																/* PROC.12 */
					tmp_min = tmp_comp;																/* PROC.16 */
				}
			}
		}
	}

	return;
}

static VD fn_bsm_alart_store_cont_altobj(
	const signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
)
{
	S4 tmp_peak_bin_up;
	S4 tmp_peak_bin_dn;
	S4 tmp_start;
	S4 tmp_end;

	FL tmp_power_up;
	FL tmp_power_dn;

	*ps4_a_alarm_flg = 1;

	afl_a_alarmed_target_current[0][0] = afl_a_Tx_float[0][9];			/* Rxpred */
	afl_a_alarmed_target_current[0][1] = afl_a_Tx_float[0][10];			/* Rypred */
	afl_a_alarmed_target_current[0][2] = (FL)as4_a_Tx_int[0][11];		/* ID */
	afl_a_alarmed_target_current[0][3] = afl_a_alarmed_target[0][3] + 1.0F;
	afl_a_alarmed_target_current[0][4] = afl_a_alarmed_target[0][4];
	afl_a_alarmed_target_current[0][5] = afl_a_alarmed_target[0][5];
	afl_a_alarmed_target_current[0][6] = afl_a_alarmed_target[0][6];

	/***** 4) �d�͍����̎Z�o *****/
	/* calculate power diff from initial status */
	tmp_peak_bin_up =as4_a_Tx_int[0][4];												/* bin_up_pred */
	tmp_peak_bin_dn =as4_a_Tx_int[0][5];												/* bin_dn_pred */
	/* check difference between the initial and the current power(average of 5bin around the current peak) */
	tmp_start = tmp_peak_bin_up-5;
	tmp_end = tmp_peak_bin_up+5;
	tmp_power_up = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[0],
		tmp_start,
		tmp_end
	);
	tmp_start = tmp_peak_bin_dn-5;
	tmp_end = tmp_peak_bin_dn+5;
	tmp_power_dn = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[1],
		tmp_start,
		tmp_end
	);
	afl_a_alarmed_target_current[0][7] = (tmp_power_up+tmp_power_dn)*0.5F - afl_a_alarmed_target_current[0][6];

	afl_a_alarmed_target_current[0][8] = afl_a_Tx_float[0][15];	/* Vxpred */
	afl_a_alarmed_target_current[0][9] = afl_a_Tx_float[0][16];	/* Vypred */
	afl_a_alarmed_target_current[0][10] = afl_a_alarmed_target[0][10];
	afl_a_alarmed_target_current[0][11] = afl_a_alarmed_target[0][11];
	afl_a_alarmed_target_current[0][12] = afl_a_alarmed_target[0][12];
	afl_a_alarmed_target_current[0][13] = afl_a_alarmed_target[0][13];
	afl_a_alarmed_target_current[0][14] = afl_a_alarmed_target[0][14];
	afl_a_alarmed_target_current[0][15] = afl_a_alarmed_target[0][15];

	return;
}

static VD fn_bsm_alart_check_exp_altobj(
	S4 as4_a_checked_alarmed[TARGET_BUFFSIZE],
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg
)
{
	S4 i;
	/* �O��x�񂳂ꂽ������x�񂳂�Ȃ��������̂̊m�F(�x��O�}) */
	S4 s4_t_lost;

	/* (C) �x��O�} */
	/***** 4) �x��O�}�^�[�Q�b�g�̊m�F *****/
	for(i=0; i<st_g_bsm_alarm_data.as4_alarmed_num[0]; i++) {
		if(as4_a_checked_alarmed[i]==0)													/* COND.b14 */
		{
			s4_t_lost = 0;																/* PROC.1 */
			/* ����O�}���W�m�� */
			s4_t_lost = s4_bsm_alart_set_exp_altobj(
				&st_g_bsm_alarm_data.afl_alarmed_target[i]
			);
			
			/* 6) �x��O�}�^�[�Q�b�g���̕ۑ� */
			if( s4_t_lost != 0 ) {
				if( as4_a_alarmed_target_num_current[0] < (S4)(TARGET_BUFFSIZE-1) ) {			/* COND.b11 */		/* �s��ł͂Ȃ����H �^�[�Q�b�g������Ȃ� */

					*ps4_a_alarm_flg = 1;
					fn_bsm_alart_store_exp_altobj(
						(const FL (*)[ALARM_INFO_SIZE])&st_g_bsm_alarm_data.afl_alarmed_target[i],
						&afl_a_alarmed_target_current[as4_a_alarmed_target_num_current[0]]
					);

					as4_a_checked_alarmed[i] = 1;
					as4_a_alarmed_target_num_current[0]++;
				}
			}
		}
	}

	return;
}

static S4 s4_bsm_alart_set_exp_altobj(
	FL afl_a_alarmed_target[1][ALARM_INFO_SIZE]
)
{
	S4 s4_t_lost;

	FL alarmed_x;
	FL alarmed_y;

	FL tmp_x_min;
	FL tmp_x_max;
	FL tmp_y_min;
	FL tmp_y_max;
	FL tmp_alarm_area[4];
	FL tmp_offset[3];

	tmp_offset[0] = ALARM_X_OFFSET_OUT;
	tmp_offset[1] = ALARM_Y_OFFSET;
	tmp_offset[2] = ALARM_X_OFFSET_IN;

	s4_t_lost = 0;															/* PROC.1 */
	alarmed_x = afl_a_alarmed_target[0][0];									/* PROC.2 */
	alarmed_y = afl_a_alarmed_target[0][1];									/* PROC.2/3 */
	if(u1_g_sns_pos==SENSOR_LEFT)											/* COND.b2 */
	{
		alarmed_x = - alarmed_x;											/* PROC.3 */
	}

	/* calculate hysteresis area */
	/* use start line */
	tmp_alarm_area[0] = afl_a_alarmed_target[0][12];						/* PROC.4 */
	tmp_alarm_area[1] = afl_a_alarmed_target[0][13];						/* PROC.4 */
	tmp_alarm_area[2] = afl_a_alarmed_target[0][14];						/* PROC.4 */
	tmp_alarm_area[3] = afl_a_alarmed_target[0][15];						/* PROC.4 */
	get_hysteresis_area(													/* SEC.4-(3) */
		alarmed_y,
		afl_a_alarmed_target[0][4],
		tmp_alarm_area,
		tmp_offset
	);
	tmp_x_min = tmp_alarm_area[0];
	tmp_x_max = tmp_alarm_area[1];
	tmp_y_min = tmp_alarm_area[2];
	tmp_y_max = tmp_alarm_area[3];

	if( afl_a_alarmed_target[0][4]==ALARM_TYPE_SOT ) {						/* COND.b15 */
		/**** SoT ****/
		s4_t_lost = s4_bsm_alart_check_exp_sot(
			(const FL (*)[ALARM_INFO_SIZE])&afl_a_alarmed_target[0],
			alarmed_x,
			alarmed_y,
			tmp_x_min,
			tmp_x_max,
			tmp_y_min,
			tmp_y_max
		);
	}
	else if( afl_a_alarmed_target[0][4]==ALARM_TYPE_TOS ) {					/* COND.b16 */
		/**** ToS ****/
		s4_t_lost = s4_bsm_alart_check_exp_tos(
			(const FL (*)[ALARM_INFO_SIZE])&afl_a_alarmed_target[0],
			alarmed_x,
			alarmed_y,
			tmp_x_min,
			tmp_x_max,
			tmp_y_min,
			tmp_y_max
		);
	}
	else {
		/**** except for ToS/SoT ****/
		s4_t_lost = s4_bsm_alart_check_exp_other(
			(const FL (*)[ALARM_INFO_SIZE])&afl_a_alarmed_target[0],
			alarmed_x,
			alarmed_y,
			tmp_x_min,
			tmp_x_max,
			tmp_y_min,
			tmp_y_max
		);
	}

	return s4_t_lost;
}

static S4 s4_bsm_alart_check_exp_sot(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
)
{
	S4 s4_t_lost;
	S4 s4_t_lost_max;

	/**** SoT ****/
	/* check */
	/* - position */
	/* - extrapolation cycles */
	s4_t_lost = 0;
	s4_t_lost_max = ALARM_SOT_LOST_MAX;								/* PROC.6 */
	if( st_g_bsm_loop_data.as4_flg_tos_end[0] > 1 )					/* COND.b18 */
	{
		s4_t_lost_max = ALARM_TOS_END_LOST_MAX;						/* PROC.7 */
	}
	if(st_g_bsm_loop_data.u1_truck_flg != (U1)0)					/* COND.b19 */
	{
		s4_t_lost_max += ALARM_LOST_TRK_EXTEND;						/* PROC.8 */
	}

	/* ��FA�L�����Z�������ŕ��W���폜���ꂽ�Ƃ��́A�O�}�ɂ�镨�W�o����h�~���邽�� */
	/* �����Ԍx�񕨕W�̊O�}���֎~���� */
	if ((st_g_bsm_loop_data.u1_fa_delete_count > (U1)0)						/* COND.b31 */
	&&  (fl_a_alarmed_y > CFL_FA_DELETE_AREA)) {							/* COND.b32 */
		s4_t_lost_max = (S4)0;												/* PROC.14 */
	}

	if ((fl_a_alarmed_x > fl_a_x_min)									/* COND.b20 */
	&&  (fl_a_alarmed_x < fl_a_x_max)									/* COND.b21 */
	&&  (fl_a_alarmed_y > fl_a_y_min)									/* COND.b22 */
	&&  (fl_a_alarmed_y < fl_a_y_max)									/* COND.b23 */
	&&  (afl_a_alarmed_target[0][5] < (FL)s4_t_lost_max)) {				/* COND.b24 */
		s4_t_lost = 1;												/* PROC.13 */
	}

	return s4_t_lost;
}

static S4 s4_bsm_alart_check_exp_tos(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
)
{
	S4 s4_t_lost;
	S4 s4_t_lost_max;
	U1 u1_t_jdg_b25_flg;

	/**** ToS ****/
	/* check */
	/* - position */
	/* - extrapolation cycles */
	/* - freq-power */
	/* - tos_end_flag */
	s4_t_lost = 0;

	/* ����b25�̔���֐��R�[�� �d�l���̋L�q������b25�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
	/* ����b25�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����								*/
	/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�			*/
	u1_t_jdg_b25_flg = u1_bsm_alart_check_exp_tos_b25(fl_a_alarmed_y, fl_a_y_max);

	if(u1_t_jdg_b25_flg == CU1_TRUE)								/* COND.b25 */
	{
		s4_t_lost_max = (S4)CU1_ALARM_TOS_LOST_MAX_FWD;				/* PROC.9 */
	}
	else
	{
		s4_t_lost_max = (S4)CU1_ALARM_TOS_LOST_MAX;					/* PROC.10 */
	}
	if( st_g_bsm_loop_data.as4_flg_tos_end[0] > 1 )					/* COND.b18 */
	{
		s4_t_lost_max = ALARM_TOS_END_LOST_MAX;						/* PROC.11 */
	}

	/* ��FA�L�����Z�������ŕ��W���폜���ꂽ�Ƃ��́A�O�}�ɂ�镨�W�o����h�~���邽�� */
	/* �����Ԍx�񕨕W�̊O�}���֎~���� */
	if ((st_g_bsm_loop_data.u1_fa_delete_count > (U1)0)						/* COND.b31 */
	&&  (fl_a_alarmed_y > CFL_FA_DELETE_AREA)) {							/* COND.b32 */
		s4_t_lost_max = (S4)0;												/* PROC.14 */
	}

	if ((fl_a_alarmed_x > fl_a_x_min)									/* COND.b20 */
	&&  (fl_a_alarmed_x < fl_a_x_max)									/* COND.b21 */
	&&  (fl_a_alarmed_y > fl_a_y_min)									/* COND.b22 */
	&&  (fl_a_alarmed_y < fl_a_y_max)									/* COND.b23 */
	&&  (afl_a_alarmed_target[0][5] < (FL)s4_t_lost_max)				/* COND.b24 */
	&&  (afl_a_alarmed_target[0][7] > ALARM_POWER_TOS_TH)) {			/* COND.b26 */
		s4_t_lost = 1;												/* PROC.13 */
	}

	return s4_t_lost;
}

/****************************************************************************/
/* �֐���		: u1_bsm_alart_check_exp_tos_b25							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �x��O�}�^�[�Q�b�g�̊m�F�̏���b25����֐�					*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_alarmed_y		: �x��^�[�Q�b�gY��������	[in]	*/
/*				: fl_a_alarm_area_ymax	: �x��G���A�O�[			[in]	*/
/* �߂�l		: u1_t_jdg_b25_flag		: ����b25�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ALART-01-014								*/
/*				: (2)-10)�x��O�}�^�[�Q�b�g�̊m�F�̏���b25					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_alart_check_exp_tos_b25(FL fl_a_alarmed_y, FL fl_a_alarm_area_ymax)
{
	/* ����b25���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_b25_flag;				/* ����b25���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_b25_flag = CU1_FALSE;

	/* ����b25�̔��� */
#if (BSM_OPTION_SW_ALART == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (fl_a_alarmed_y >= (fl_a_alarm_area_ymax - (FL)1.0F)) {
		u1_t_jdg_b25_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b25_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_ALART == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (fl_a_alarmed_y > fl_a_alarm_area_ymax - (FL)1.8F) {
		u1_t_jdg_b25_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b25_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */

	return u1_t_jdg_b25_flag;
}

static S4 s4_bsm_alart_check_exp_other(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL fl_a_alarmed_x,
	FL fl_a_alarmed_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max
)
{
	S4 s4_t_lost;
	S4 s4_t_lost_max;

	/**** except for ToS/SoT ****/
	/* check */
	/* - position */

	/* check if target disappeaerd in the middle area(the area marked "XXX")	*/
	/* if so keep alarm															*/
	/*	+-------+																*/
	/*	|	  |	|																*/
	/*	|-------|3/4															*/
	/*	|XXXXX|	|																*/
	/*	|XXXXX|	|																*/
	/*	|-------|1/4															*/
	/*	|	  |	|																*/
	/*	+-------+																*/
	/*	     3/4																*/
	/* RY > CFL_ALARM_Y_BACKWARD + (ALARM_Y_FORWARD-ALARM_Y_FORWARD)*0.25F		*/
	/* RY < ALARM_Y_FORWARD - (ALARM_Y_FORWARD-ALARM_Y_FORWARD)*0.25F			*/
	/* RX < ALARM_X_OUT - (ALARM_X_OUT-ALARM_X_IN)*0.25F						*/
	s4_t_lost = 0;
	s4_t_lost_max = (S4)CU1_ALARM_MID_LOST_MAX;								/* PROC.12 */

	/* ��FA�L�����Z�������ŕ��W���폜���ꂽ�Ƃ��́A�O�}�ɂ�镨�W�o����h�~���邽�� */
	/* �����Ԍx�񕨕W�̊O�}���֎~���� */
	if ((st_g_bsm_loop_data.u1_fa_delete_count > (U1)0)						/* COND.b31 */
	&&  (fl_a_alarmed_y > CFL_FA_DELETE_AREA)) {							/* COND.b32 */
		s4_t_lost_max = (S4)0;												/* PROC.14 */
	}

	if ((fl_a_alarmed_x >  fl_a_x_min)											/* COND.b20 */
	&&  (fl_a_alarmed_x < (fl_a_x_max - ((fl_a_x_max - fl_a_x_min) * 0.25F)))	/* COND.b27 */
	&&  (fl_a_alarmed_y > (fl_a_y_min + ((fl_a_y_max - fl_a_y_min) * 0.25F)))	/* COND.b28 */
	&&  (fl_a_alarmed_y < (fl_a_y_max - ((fl_a_y_max - fl_a_y_min) * 0.25F)))	/* COND.b29 */
	&&  (afl_a_alarmed_target[0][5] < (FL)s4_t_lost_max)) {						/* COND.b24 */
		s4_t_lost = 1;														/* PROC.13 */
	}

	return s4_t_lost;
}

static VD fn_bsm_alart_store_exp_altobj(
	const FL afl_a_alarmed_target[1][ALARM_INFO_SIZE],
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE]
)
{
	S4 tmp_peak_bin;
	S4 tmp_peak_bin_up;
	S4 tmp_peak_bin_dn;
	S4 tmp_start;
	S4 tmp_end;

	FL tmp_power_up;
	FL tmp_power_dn;

	afl_a_alarmed_target_current[0][0] = afl_a_alarmed_target[0][0]+afl_a_alarmed_target[0][8]*CFL_SAMPLING_TIME;
	afl_a_alarmed_target_current[0][1] = afl_a_alarmed_target[0][1]+afl_a_alarmed_target[0][9]*CFL_SAMPLING_TIME;
	afl_a_alarmed_target_current[0][2] = afl_a_alarmed_target[0][2];
	afl_a_alarmed_target_current[0][3] = afl_a_alarmed_target[0][3] + 1.0F;
	afl_a_alarmed_target_current[0][4] = afl_a_alarmed_target[0][4];
	afl_a_alarmed_target_current[0][5] = afl_a_alarmed_target[0][5] + 1.0F;
	afl_a_alarmed_target_current[0][6] = afl_a_alarmed_target[0][6];

	/* calculate power diff from initial status */
	tmp_peak_bin = (S4)( fl_abs(fl_sqrt(afl_a_alarmed_target[0][0]*afl_a_alarmed_target[0][0]+afl_a_alarmed_target[0][1]*afl_a_alarmed_target[0][1]))/RCOF*0.5F
					+ NB_FFT_PT*0.5F);
	tmp_peak_bin_up = tmp_peak_bin + (S4)( 0.5*(-afl_a_alarmed_target[0][9])/VCOF);
	tmp_peak_bin_dn = tmp_peak_bin - (S4)( 0.5*(-afl_a_alarmed_target[0][9])/VCOF);
	tmp_start = tmp_peak_bin_up-5;
	tmp_end = tmp_peak_bin_up+5;
	tmp_power_up = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[0],
		tmp_start,
		tmp_end
	);
	tmp_start = tmp_peak_bin_dn-5;
	tmp_end = tmp_peak_bin_dn+5;
	tmp_power_dn = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[1],
		tmp_start,
		tmp_end
	);
	afl_a_alarmed_target_current[0][7] = (tmp_power_up+tmp_power_dn)*0.5F-afl_a_alarmed_target_current[0][6];

	afl_a_alarmed_target_current[0][8] = afl_a_alarmed_target[0][8];
	afl_a_alarmed_target_current[0][9] = afl_a_alarmed_target[0][9];
	afl_a_alarmed_target_current[0][10] = afl_a_alarmed_target[0][10];
	afl_a_alarmed_target_current[0][11] = afl_a_alarmed_target[0][11];
	afl_a_alarmed_target_current[0][12] = afl_a_alarmed_target[0][12];
	afl_a_alarmed_target_current[0][13] = afl_a_alarmed_target[0][13];
	afl_a_alarmed_target_current[0][14] = afl_a_alarmed_target[0][14];
	afl_a_alarmed_target_current[0][15] = afl_a_alarmed_target[0][15];

	return;
}

static VD fn_bsm_alart_check_new_altobj(
	S4 s4_final_a_target_num,
	signed long as4_a_Tx_int[TARGET_BUFFSIZE][NORM_INT],
	FL afl_a_Tx_float[TARGET_BUFFSIZE][TGT_FLT],
	const S4 as4_a_checked_target[TARGET_BUFFSIZE],
	S4 s4_a_tos_flg,
	S4 as4_a_alarmed_target_num_current[1],
	FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	FL fl_a_alarm_area_y_min,
	S4 *ps4_a_alarm_flg
)
{
	S4 i;

	S4 s4_t_index;
	FL fl_t_erased_type;

	FL fl_t_object_x;
	FL fl_t_object_y;
	FL fl_t_object_vy;
	FL fl_t_x_min;
	FL fl_t_x_max;
	FL fl_t_y_min;
	FL fl_t_y_max;

	fl_t_object_x = 0.0F;
	fl_t_object_y = 0.0F;
	fl_t_object_vy = 0.0F;

/****************************************************************************/
/* (4)	�ʏ�x��̈�����菈���i�V�K�x�񕨕W���菈���j						*/
/****************************************************************************/
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	for(i=0; i<10; i++){
		afl_g_alarm_x_min[i] = fl_get_road_width(s2_g_curvr_for_base, -(float)i) + ALARM_X_IN + ALARM_X_OFFSET_IN;
		afl_g_alarm_x_max[i] = fl_get_road_width(s2_g_curvr_for_base, -(float)i) + ALARM_X_OUT + ALARM_X_OFFSET_OUT;
		afl_g_alarm_y[i] = -(float)i;
	}
#endif /*VI �\���p*/

	/* (C) �V�K�x�� */

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20170123_AAZ_CHECK)
	/* Change alarm area (ymin) only when TFlag = CONNECT, and TLength = valid value */
	if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.CONNECT ){
		fl_a_alarm_area_y_min -= st_g_btt_alertarea.rear.VarY;
	}
#endif
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T)
	afl_g_btt_aaz_area[3] = fl_a_alarm_area_y_min;
#endif

	for(i=0; i<s4_final_a_target_num; i++)
	{
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20170303_AAZ_TWE)
		fl_t_x_min = ALARM_X_IN + ALARM_X_OFFSET_IN + st_g_btt_alertarea.side.VarXin;		/* PROC.1 */
		fl_t_x_max = ALARM_X_OUT + ALARM_X_OFFSET_OUT + st_g_btt_alertarea.side.VarXout;	/* PROC.1 */
#else
		fl_t_x_min = ALARM_X_IN + ALARM_X_OFFSET_IN;									/* PROC.1 */
		fl_t_x_max = ALARM_X_OUT + ALARM_X_OFFSET_OUT;									/* PROC.1 */
#endif
		fl_t_y_min = fl_a_alarm_area_y_min - ALARM_Y_OFFSET;							/* PROC.1 */
#if (BSM_OPTION_SW_ALART == TYPE_A)
		fl_t_y_max = ALARM_Y_FORWARD;													/* PROC.1 ���ڊp�x50deg�̏��� */
#elif (BSM_OPTION_SW_ALART == TYPE_B)
		fl_t_y_max = ALARM_Y_FORWARD - ALARM_Y_OFFSET;									/* PROC.1 ���ڊp�x20deg�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */
		
		/***** 1) �V�K�x��^�[�Q�b�g�̊m�F *****/
		if( as4_a_checked_target[i]==0 )												/* COND.d1 */
		{
			/* �V�K�x��^�[�Q�b�g�p�̌x��G���A�擾 */
			fn_bsm_alart_get_alart_area(
				(const FL (*)[TGT_FLT])&afl_a_Tx_float[i],
				&fl_t_object_x,
				&fl_t_object_y,
				&fl_t_object_vy,
				&fl_t_x_min,
				&fl_t_x_max,
				&fl_t_y_min
			);

			/* check if the target is in alarm area */
			/* ����x�񕨕W�i�[�ʒu�擾 */
			s4_t_index = -1;														/* PROC.5 */
			fl_t_erased_type = -1.0F;												/* PROC.6 */
			fn_bsm_alart_get_store_index(
				(const signed long (*)[NORM_INT])&as4_a_Tx_int[i],
				(const FL (*)[TGT_FLT])&afl_a_Tx_float[i],
				(const S4 (*))as4_a_alarmed_target_num_current,
				(const FL (*)[ALARM_INFO_SIZE])afl_a_alarmed_target_current,
				fl_t_object_x,
				fl_t_object_y,
				fl_t_x_min,
				fl_t_x_max,
				fl_t_y_min,
				fl_t_y_max,
				&fl_t_erased_type,
				&s4_t_index,
				fl_a_alarm_area_y_min
			);
			
			if( s4_t_index != -1 ) {
				/***** 2) �V�K�x��^�[�Q�b�g���̕ۑ� *****/
				fn_bsm_alart_store_new_altobj(
					&as4_a_Tx_int[i],
					&afl_a_Tx_float[i],
					fl_t_object_x,
					fl_t_object_y,
					s4_a_tos_flg,
					fl_t_erased_type,
					&afl_a_alarmed_target_current[s4_t_index],
					ps4_a_alarm_flg,
					fl_a_alarm_area_y_min
				);
				as4_a_alarmed_target_num_current[0]++;
			}
		}
	}

	return;
}

static VD fn_bsm_alart_get_alart_area(
	const FL afl_a_Tx_float[1][TGT_FLT],
	FL *pfl_a_object_x,
	FL *pfl_a_object_y,
	FL *pfl_a_object_vy,
	FL *pfl_a_x_min,
	FL *pfl_a_x_max,
	FL *pfl_a_y_min
)
{
	*pfl_a_object_x = afl_a_Tx_float[0][9];										/* PROC.2 Rxpred */
	*pfl_a_object_y = afl_a_Tx_float[0][10];									/* PROC.2/3 Rypred */
	if(u1_g_sns_pos==SENSOR_LEFT)												/* COND.d2 ���Z���T�̂Ƃ� */
	{
		*pfl_a_object_x = - *pfl_a_object_x;									/* PROC.3 */
	}
	*pfl_a_object_vy = afl_a_Tx_float[0][16];									/* PROC.2/3 Vypred */


	/* �x��G���A�̃J�[�u�␳ SEC.4(3)4) */
	if(*pfl_a_object_y < 0.0F)
	{
		*pfl_a_x_min = fl_get_road_width(s2_g_curvr_for_base, *pfl_a_object_y) + *pfl_a_x_min;
		*pfl_a_x_max = fl_get_road_width(s2_g_curvr_for_base, *pfl_a_object_y) + *pfl_a_x_max;
	} else {
		/* �O���̓J�[�u�␳�Ȃ� ���͒l���̂܂� */
	}

	/* calculate time offset area */
	*pfl_a_y_min = get_time_offset_area( *pfl_a_y_min, *pfl_a_object_vy, ALARM_OFFSET_TIME );	/* (PROC.4) */

	return;
}

static VD fn_bsm_alart_get_store_index(
	const signed long as4_a_Tx_int[1][NORM_INT],
	const FL afl_a_Tx_float[1][TGT_FLT],
	const S4 as4_a_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE],
	FL fl_a_object_x,
	FL fl_a_object_y,
	FL fl_a_x_min,
	FL fl_a_x_max,
	FL fl_a_y_min,
	FL fl_a_y_max,
	FL *pfl_a_erased_type,
	S4 *ps4_a_index,
	FL fl_a_alarm_area_y_min
)
{
	S4 j;

	FL fl_t_comp;
	FL fl_t_min;

	/* check if the target is in alarm area */
	if ((fl_a_object_x > fl_a_x_min)												/* COND.d4 */
	&&  (fl_a_object_x < fl_a_x_max)												/* COND.d5 */
	&&  (fl_a_object_y < fl_a_y_max)												/* COND.d6 */
	&&  (fl_a_object_y > fl_a_y_min)												/* COND.d7 */
	&&  (as4_a_Tx_int[0][10] == 0)													/* COND.d8 */
	&&  (!((as4_a_Tx_int[0][14] == OBJECT_TYPE_2F)									/* COND.d26 */
	&&     (as4_a_Tx_int[0][12] == (S4)1)))) {										/* COND.d27 */
		if ((afl_a_Tx_float[0][13]  < ((FL)-10.0F / (FL)3.6F))						/* COND.d28 */
		||  ((afl_a_Tx_float[0][13] < ((FL)-8.5F / (FL)3.6F))						/* COND.d29 */
		&&   (afl_a_Tx_float[0][7]  < (fl_a_alarm_area_y_min + (FL)1.0F)))) {		/* COND.d30 */
			*ps4_a_index = (S4)-1;
		} else if ((st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)0)				/* COND.d21 */
			   &&  (as4_a_Tx_int[0][17] < (S4)5)) {								/* COND.d22 */
			*ps4_a_index = (S4)-1;
		} else if ((as4_a_Tx_int[0][15] > (S4)0)								/* COND.d23 */
			   &&  (as4_a_Tx_int[0][17] < (S4)5)) {								/* COND.d22 */
			*ps4_a_index = (S4)-1;
		} else if ((as4_a_Tx_int[0][16] == (S4)0)								/* COND.d24 */
			   &&  (st_g_bsm_loop_data.u1_reliable_jdg_mask_count == (U1)0)) {			/* COND.d25 */
			*ps4_a_index = (S4)-1;
#if (BSM_OPTION_SW_ALART == TYPE_A)
		} else
#elif (BSM_OPTION_SW_ALART == TYPE_B)
		} else if ((fl_g_v_self_bsm_for_base < (FL)35.0F)			/* COND.d31 */
			   &&  (fl_a_object_y < (FL)-3.5F)						/* COND.d32 */
			   &&  (fl_a_object_y > (FL)-7.5F)) {					/* COND.d33 */
			if (fl_a_object_x < fl_a_x_min + (FL)0.1F) {			/* COND.d34 */
				*ps4_a_index = (S4)-1;
			} else if (fl_a_object_x < fl_a_x_min + (FL)0.4F) {			/* COND.d35 */
				if (afl_a_Tx_float[0][13] * (FL)3.6F < (FL)2.6F) {		/* COND.d36 */
					*ps4_a_index = (S4)-1;
				} else {
					*ps4_a_index = (S4)1;
				}
			} else if (fl_a_object_x < fl_a_x_min + (FL)0.8F) {			/* COND.d37 */
				if (afl_a_Tx_float[0][13] * (FL)3.6F < (FL)3.5F) {		/* COND.d38 */
					*ps4_a_index = (S4)-1;
				} else {
					*ps4_a_index = (S4)1;
				}
			} else {
				*ps4_a_index = (S4)1;
			}
		} else {
			*ps4_a_index = (S4)1;
		}

		if (*ps4_a_index != (S4)-1)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */
		{
			if( as4_a_alarmed_target_num_current[0] < (S4)(TARGET_BUFFSIZE-1) )					/* COND.d9 */		/* �s��ł͂Ȃ����H */
			{
				*ps4_a_index = as4_a_alarmed_target_num_current[0];								/* PROC.7 */
			}
			/* when output buffer is full */
			else
			{
				fl_t_min = 1000.0F;																/* PROC.9 */
				fl_t_comp = 0.0F;																/* PROC.10 */
				/* erase the nearest one and save the new one */
				for(j=0; j<TARGET_BUFFSIZE; j++)													/* �s��ł͂Ȃ����H */
				{
					fl_t_comp = fl_abs(afl_a_alarmed_target_current[j][0]-afl_a_Tx_float[0][8])
					         + fl_abs(afl_a_alarmed_target_current[j][1]-afl_a_Tx_float[0][7]);
					if(fl_t_comp < fl_t_min)													/* COND.d10 */
					{
						*ps4_a_index = j;														/* PROC.8 */
						fl_t_min = fl_t_comp;													/* PROC.12 */
						*pfl_a_erased_type = afl_a_alarmed_target_current[j][4];				/* PROC.13 */
					}
				}
			}
		}
	}

	return;
}

static VD fn_bsm_alart_store_new_altobj(
	signed long as4_a_Tx_int[1][NORM_INT],
	FL afl_a_Tx_float[1][TGT_FLT],
	FL fl_a_object_x,
	FL fl_a_object_y,
	S4 s4_a_tos_flg,
	FL fl_a_erased_type,
	FL afl_a_alarmed_target_current[1][ALARM_INFO_SIZE],
	S4 *ps4_a_alarm_flg,
	FL fl_a_alarm_area_y_min
)
{
	S4 tmp_peak_bin_up;
	S4 tmp_peak_bin_dn;
	S4 tmp_start;
	S4 tmp_end;

	FL tmp_power_up;
	FL tmp_power_dn;

	*ps4_a_alarm_flg = 1;

	afl_a_alarmed_target_current[0][0] = afl_a_Tx_float[0][9];			/* Rxpred */
	afl_a_alarmed_target_current[0][1] = afl_a_Tx_float[0][10];			/* Rypred */
	afl_a_alarmed_target_current[0][2] = (FL)as4_a_Tx_int[0][11];		/* ID */
	afl_a_alarmed_target_current[0][3] = 1.0F;

	/***** 3) �x���ʂ̔��� *****/
	/* alarm type */
	afl_a_alarmed_target_current[0][4] = fl_bsm_alart_check_alart_type(
		fl_a_object_x,
		fl_a_object_y,
		s4_a_tos_flg,
		fl_a_erased_type,
		fl_a_alarm_area_y_min
	);
	afl_a_alarmed_target_current[0][5] = 0.0F;

	/***** 4) �x��J�n���d�͂̎Z�o *****/
	/* calculate power diff from initial status */
	tmp_peak_bin_up =as4_a_Tx_int[0][4];												/* bin_up_pred */
	tmp_peak_bin_dn =as4_a_Tx_int[0][5];												/* bin_dn_pred */
	/* check difference between the initial and the current power(average of 5bin around the current peak) */
	tmp_start = tmp_peak_bin_up-5;
	tmp_end = tmp_peak_bin_up+5;
	tmp_power_up = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[0],
		tmp_start,
		tmp_end
	);
	tmp_start = tmp_peak_bin_dn-5;
	tmp_end = tmp_peak_bin_dn+5;
	tmp_power_dn = get_fmpower_of_specified_interval(
		(const FL (*))afl_g_cvw_lfm_ftt_power[1],
		tmp_start,
		tmp_end
	);
	afl_a_alarmed_target_current[0][6] = (tmp_power_up+tmp_power_dn)*0.5F;

	afl_a_alarmed_target_current[0][7] = 0.0F;
	afl_a_alarmed_target_current[0][8] = afl_a_Tx_float[0][15];							/* Vxpred */
	afl_a_alarmed_target_current[0][9] = afl_a_Tx_float[0][16];							/* Vypred */
	afl_a_alarmed_target_current[0][10] = afl_a_Tx_float[0][9];							/* Rxpred */
	afl_a_alarmed_target_current[0][11] = afl_a_Tx_float[0][10];						/* Rypred */
	afl_a_alarmed_target_current[0][12] = ALARM_X_IN + ALARM_X_OFFSET_IN;
	afl_a_alarmed_target_current[0][13] = ALARM_X_OUT + ALARM_X_OFFSET_OUT;
	afl_a_alarmed_target_current[0][14] = fl_a_alarm_area_y_min - ALARM_Y_OFFSET;
#if (BSM_OPTION_SW_ALART == TYPE_A)
	afl_a_alarmed_target_current[0][15] = ALARM_Y_FORWARD;
#elif (BSM_OPTION_SW_ALART == TYPE_B)
	afl_a_alarmed_target_current[0][15] = ALARM_Y_FORWARD - ALARM_Y_OFFSET;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ALART */

	return;
}

static FL fl_bsm_alart_check_alart_type(
	FL fl_a_object_x,
	FL fl_a_object_y,
	S4 s4_a_tos_flg,
	FL fl_a_erased_type,
	FL fl_a_alarm_area_y_min
)
{
	FL fl_a_alart_type;

	/***** 3) �x���ʂ̔��� *****/
	/* alarm type */
	if(fl_a_erased_type != -1.0F)											/* COND.d12 */
	{
		fl_a_alart_type = fl_a_erased_type;									/* PROC.1 */
	}
	else
	{
		/* ToS(when previous target include ToS) */
		if( s4_a_tos_flg == 1 )												/* COND.d13 */
		{
			fl_a_alart_type = ALARM_TYPE_TOS;								/* PROC.2 */
		}

		/* ToS(�G���A�̌�����3m�ȓ�����J�n) */
		else if (fl_a_object_y <= (fl_a_alarm_area_y_min + (FL)3.0F))		/* COND.d14 */
		{
			fl_a_alart_type = ALARM_TYPE_TOS;								/* PROC.2 */
		}

		/* SoT(�G���A�̑O�����2.5m�ȓ�����J�n) */
		else if (fl_a_object_y >= (ALARM_Y_FORWARD - (FL)2.5F))				/* COND.d15 */
		{
			fl_a_alart_type = ALARM_TYPE_SOT;								/* PROC.3 */
		}

		/* Marge-in(�G���A�̊O�����1.0m�ȓ�����J�n) */
		else if (fl_a_object_x > (ALARM_X_OUT - (FL)1.0F))					/* COND.d16 */
		{
			fl_a_alart_type = ALARM_TYPE_MERGEIN;							/* PROC.4 */
		}

		/* UNKNOWN */
		else
		{
			fl_a_alart_type = ALARM_TYPE_OTHER;								/* PROC.5 */
		}
	}

	return fl_a_alart_type;
}

static VD fn_bsm_alart_set_alart_target(
	const S4 as4_alarmed_target_num_current[1],
	const FL afl_a_alarmed_target_current[TARGET_BUFFSIZE][ALARM_INFO_SIZE]
)
{
	S4 i;
	S4 j;

	/* �x��Ώۏ����R�s�[ */
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
		for(j=0; j<ALARM_INFO_SIZE; j++)
		{
			st_g_bsm_alarm_data.afl_alarmed_target[i][j] = afl_a_alarmed_target_current[i][j];
		}
	}
	st_g_bsm_alarm_data.as4_alarmed_num[0] = as4_alarmed_target_num_current[0];

	return;
}

static VD fn_bsm_alart_extend_alart(
	S4 s4_a_tos_flg,
	S4 s4_a_not_alarm,
	S4 *ps4_a_alarm_flg
)
{
	if(*ps4_a_alarm_flg==0)													/* COND.e1 */
	{
		if(st_g_bsm_alarm_data.as4_alarm_off_count[0] > 0)					/* COND.e2 */
		{
			if(s4_a_tos_flg==1)												/* COND.e3 */
			{
				st_g_bsm_alarm_data.as4_alarm_off_count[0]=0;				/* PROC.1 */
			}
			else
			{
				st_g_bsm_alarm_data.as4_alarm_off_count[0]--;				/* PROC.2 */
			}
			if(st_g_bsm_alarm_data.as4_alarm_off_count[0]==0)				/* COND.e4 */
			{
				*ps4_a_alarm_flg = 0;										/* PROC.4 */
			}
			else
			{
				*ps4_a_alarm_flg = 1;										/* PROC.5 */
			}
		}
	}
	else
	{
		st_g_bsm_alarm_data.as4_alarm_off_count[0] = ALARM_OFF_COUNT;		/* PROC.3 */
	}

	if( s4_a_not_alarm==1 )													/* COND.e5 */
	{
		*ps4_a_alarm_flg = 0;												/* PROC.4 */
	}

	return;
}

/* calculate BSM alarm-area with hysterisis */
/* @param :see below */
VD get_hysteresis_area(
	FL ry,			/* [in] */
	FL type,		/* [in] */
	FL area[4],		/* [in/out] 0:x_min, 1:x_max, 2:y_min, 3:y_max */
	FL offset[3]	/* [in]	0:x_offset_out, 1:y:offset, 2:x_offset_in */
)
{
/****************************************************************************/
/* (3)	�q�X�e���V�X�̈�Z�o����											*/
/****************************************************************************/
	FL x_min = area[0];
	FL x_max = area[1];
	FL y_min = area[2];
	FL y_max = area[3];
	FL tmp_x_min = x_min;
	FL tmp_x_max = x_max;
	FL tmp_y_min = y_min;
	FL tmp_y_max = y_max;

	/**** �O�� ****/
	tmp_y_max = y_max + ALARM_HYS_MARGIN_FWD;

	/**** ��� ****/
	tmp_y_min = y_min - ALARM_HYS_MARGIN_BWD;

	/**** ���� ****/
	tmp_x_max = tmp_x_max + ALARM_HYS_MARGIN_SIDE;
	tmp_x_min = tmp_x_min - ALARM_HYS_MARGIN_SIDE;

	/* �x��G���A�̃J�[�u�␳(�q�X�e���V�X�Ȃ�) */
	if(ry < 0.0F)					/* COND.c3 */
	{
		tmp_x_min = fl_get_road_width(s2_g_curvr_for_base, ry) + tmp_x_min;
		tmp_x_max = fl_get_road_width(s2_g_curvr_for_base, ry) + tmp_x_max;
	}
	else	/* �O���̓J�[�u�␳�Ȃ� */
	{
		tmp_x_min = tmp_x_min;
		tmp_x_max = tmp_x_max;
	}

	area[0] = tmp_x_min;
	area[1] = tmp_x_max;
	area[2] = tmp_y_min;
	area[3] = tmp_y_max;

	return;
}



/* calculate BSM alarm-area with time offset */
/* @param :see below */
FL get_time_offset_area(								/* [return] */
	FL r,												/* [in] m */
	FL v,												/* [in]	m/sec */
	FL time												/* [in] sec */
)
{
	FL fret = r;
	if( v > 0.0F )			/* COND.d101 */
	{
		fret = r - v*time;	/* PROC.4 */
	}
	return fret;
}

FL get_fmpower_of_specified_interval(
	const FL power[NB_FFT_PT],
	S4 start_bin,
	S4 end_bin
)
{
	FL tmp_power = 0.0F;
	S4 tmp_num = 0;
	S4 i;
	for(i=start_bin; i<end_bin; i++)
	{
		/* �z��O�Q�Ƃ�h������0�`NB_FFT_PT�ŏ㉺���K�[�h�������� */
		if (((S4)0 <= i) && (i < NB_FFT_PT)) {
			tmp_power += power[i];
			tmp_num++;
		}
	}
	tmp_power = tmp_power / (FL)tmp_num;
	return tmp_power;
}

VD fn_alarm_data_initialize(BSM_ALARM_DATA *pst_a_alarm_data){

	S4 s4_t_lp_i = 0;

	pst_a_alarm_data->s4_alarm_prev = 0;
	pst_a_alarm_data->as4_alarm_off_count[0] = 0;
	pst_a_alarm_data->as4_alarmed_num[0] = 0;

	fn_initialize_alarm_info(pst_a_alarm_data->afl_alarmed_target);

	return;

}

VD fn_initialize_alarm_info(
	FL alarmed_target[TARGET_BUFFSIZE][ALARM_INFO_SIZE]		/* [in/out] �x��Ώۏ�� */
)
{
	S4 i;
	for(i=0; i<TARGET_BUFFSIZE; i++)
	{
		alarmed_target[i][0] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][1] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][2] = -1.0F;
		alarmed_target[i][3] = 0.0F;
		alarmed_target[i][4] = ALARM_TYPE_UNKNOWN;
		alarmed_target[i][5] = 0.0F;
		alarmed_target[i][6] = 0.0F;
		alarmed_target[i][7] = -100.0F;
		alarmed_target[i][8] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][9] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][10] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][11] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][12] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][13] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][14] = CFL_UNKNOWN_VALUE;
		alarmed_target[i][15] = CFL_UNKNOWN_VALUE;
	}
}

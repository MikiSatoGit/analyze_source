
/****************************************************************************/
/* �t�@�C����	: lca_main.c												*/
/*--------------------------------------------------------------------------*/
/* ���W���[����	: 															*/
/*--------------------------------------------------------------------------*/
/* �@�\			: 															*/
/*--------------------------------------------------------------------------*/
/* ���l			:															*/
/*--------------------------------------------------------------------------*/
/* �\���֐�		: 															*/
/* 				: 															*/
/*--------------------------------------------------------------------------*/
/* �ύX����		:															*/
/* Version				date				name							*/
/*	t01					14.02.17			�����Z1 1�Z�� H.Nonogaki		*/
/*	�V�K�쐬																*/
/*	t03					14.04.02			�����Z1 1�Z�� H.Nonogaki		*/
/*	�t�@�C�����̂̕ύX														*/
/*	�Z�p�w�b�_�̕ύX														*/
/*	�����V�~�����[�^���̑Ή�												*/
/*	�f�o�b�O�p�����E�ϐ��̍폜												*/
/*	���p���f�[�^�̏����l������												*/
/*	t04					14.04.09			�����Z1 1�Z�� H.Nonogaki		*/
/*	STEP2�Ή�																*/
/*	t05					14.05.06			�����Z1 1�Z�� Y.Yamada			*/
/*	BSM�F��������STEP2�Ή�													*/
/*	t06					14.10.15			�����Z1 1�Z�� H.Nonogaki		*/
/*	LCA���t�@�N�^�����O														*/
/*	t07					14.10.21			�����Z1 1�Z�� H.Nonogaki		*/
/*	�x�񐧌�̂��߂̌x��t���O���O���[�o��RAM��								*/
/*	t09					16.08.02			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B�����ɐV�K�쐬														*/
/*	t10					16.08.03			�����Z2 1�Z�� Y.Nishioka		*/
/*	�݌vDR�w�E�����Ή��@OBJ�ύX�Ȃ�											*/
/*	t11					16.08.29			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B �c�ۑ�1422�Ή��@�O���[�o���ϐ��̏������ǉ�							*/
/*	t12					16.10.05			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B LCA�\���ύX�ɔ����A�w�b�_�ǂݍ��ݕύX								*/
/*	t13					16.12.05			�����Z2 1�Z�� M.Tanaka			*/
/*	�d�l�m�FNo.2897 �s�v�O���[�o���ϐ����폜								*/
/*	t14					16.12.07			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B �c�ۑ�1475 �d��臒l�C��											*/
/*	tos35				16.12.27			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@��OBJ�ύX����					*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-ABST-002B						*/
/*	tos36				16.12.27			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@��OBJ�ύX����					*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-ABST-002B	No.23				*/
/*	tos39				17.01.06			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@QA�V�[�g No.39�̑Ή�						*/
/*	tos55				17.01.12			����DME M.Nakamura				*/
/*	�s��̏C��(�f���\�[�l�C���R�[�h�̃}�[�W)								*/
/*	tos56				17.01.13			����DME M.Nakamura				*/
/*	�`���̏C���iGrep�ɂ�鑍�_���j											*/
/*	t15					17.01.19			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa �R�[�h���r���[�S�w�E�����̏C��									*/
/*	tos59				17.01.19			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�C���R��Ή��@�`���̏C���@��OBJ�ύX����	*/
/*	t16					17.01.22			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa �����w�E�����̏C��												*/
/*	t17					17.01.22			�����Z2 1�Z�� Y.Nishioka		*/
/*	�R�����g�̏C���@��OBJ�ύX�Ȃ�											*/
/*	t18					17.01.30			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B_���}�������_�T���v���R�[�h�}�[�W									*/
/*	t19					17.02.03			����Z2 1�Z�� Y.Nishioka		*/
/*	310B_���}���쎞_�\�t�gGr�w�E�ɂ��d�l���̏C���𔽉f					*/
/*	t20					17.02.08			����Z2 1�Z�� Y.Nishioka		*/
/*	����Z���t�w�E�����Ή�(310B_t081��t083)									*/
/*	t21					17.02.17			����Z2 1�Z�� Y.Yamada			*/
/*	LDA�A�g���胍�W�b�N�ǉ�													*/
/*	t23					17.03.03			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa���}��������C�����e���}�[�W ��OBJ�ύX�Ȃ�						*/
/****************************************************************************/

/****************************************************************************/
/*							�w�b�_�C���N���[�h								*/
/****************************************************************************/
/***** ���ʃw�b�_ *****/
#include "../../../app/type.h"
#include "../../../app/config/config_sns.h"

/***** �}�N����`�w�b�_ *****/
#include "lca_parameter_def.h"

/***** �\���̒�`�w�b�_ *****/
#include "lca_normal_def.h"

/***** �萔��`�w�b�_ *****/

/***** �Q�Ɗ֐��w�b�_ *****/
#include "lca_main.h"		/* �O�����J�p��API������Ŏg�p���Ă���b�菈�u */
#include "lca_core.h"
#include "target/lca_map_01.h"
#include "target/lca_init_cvw.h"
#include "target/lca_recog_01_03_07_08.h"
#include "target/lca_recog_03_04_05_06_10.h"
#include "app_alart/lca_alarm_01.h"

/***** �}�N���֐���`�w�b�_ *****/

/***** �O���Q�ƃw�b�_ *****/
#include "../../common/defcom_mwr.h"
#include "../bsm/bsm_main.h"		/* �w�b�_�t�@�C���v������ */
#include "../../../app/config/inc_config.h"


/****************************************************************************/
/*								�}�N����`									*/
/****************************************************************************/

/****************************************************************************/
/*								�萔��`									*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�ϐ��錾							*/
/****************************************************************************/

/****************************************************************************/
/*								�X�^�e�B�b�N�֐�							*/
/****************************************************************************/
/* ======================================================================== */
/* 	�O�����JAPI 															*/
/* ======================================================================== */

/****************************************************************************/
/* �֐���	: fn_lca_main													*/
/*--------------------------------------------------------------------------*/
/* �@�\		: 																*/
/*--------------------------------------------------------------------------*/
/* ����		: �Ȃ�															*/
/* �߂�l	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* [in]  	: �Ȃ�															*/
/* [out] 	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �d�l��	: 																*/
/****************************************************************************/
VD fn_lca_main(VD)
{
	fn_lca_core_main();

	return;
}

/****************************************************************************/
/* �֐���	: fn_lca_cmn_initialize_loop_data								*/
/*--------------------------------------------------------------------------*/
/* �@�\		: �O���[�o���ϐ��錾��������									*/
/*--------------------------------------------------------------------------*/
/* ����		: �Ȃ�															*/
/* �߂�l	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* [in]  	: �Ȃ�															*/
/* [out] 	: st_g_lca_ecu_loop_data							: ���T�C�N���Ɏ����z��LCA/FHL���[�v�f�[�^	*/
/* [out] 	: afl_g_lca_ecu_lfm_up_side_dft_pow[]				: ���Ԑ^��DFT�X�y�N�g��(UP)	*/
/* [out] 	: afl_g_lca_ecu_lfm_dn_side_dft_pow[]				: ���Ԑ^��DFT�X�y�N�g��(DN)	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_zero_point_error			: ���[���[�g��_�ُ�*/
/* [out] 	: s2_g_lca_ecu_yaw_rate_1_zero_point				: ���[���[�g1��_�l		*/
/* [out] 	: s2_g_lca_ecu_yaw_rate_2_zero_point				: ���[���[�g2��_�l		*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_zero_point_update_info		: ���[���[�g��_�X�V���	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_sensor_1_validation			: ���[���[�g�Z���T�P����/�L��	*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_sensor_2_validation			: ���[���[�g�Z���T�P����/�L��	*/
/* [out] 	: u1_g_lca_ecu_sensor_pow_supply_voltage_validation	: ���Z���T�d���d��(IG) ����/�L��	*/
/* [out] 	: u2_g_lca_ecu_yaw_rate_sensor_signal				: ���[���[�g�Z���T�M��	*/
/* [out] 	: u1_g_lca_ecu_yaw_diff_value						: ���[���[�g�����l		*/
/* [out] 	: u1_g_lca_ecu_yaw_rate_id							: ���[���[�g�Z���T���ʒl*/
/* [out] 	: s2_g_lca_ecu_curv_r								: LCA �p�J�[�uR						*/
/* [out] 	: fl_g_lca_ecu_2f_ave_standard_pow					: 2FCW FFT �X�y�N�g���̃x�[�X臒l	*/
/* [out] 	: afl_g_lca_ecu_2f_thre								: 2FCW FFT �X�y�N�g���̕ϓ�臒l		*/
/* [out] 	: fl_g_lca_ecu_noise_floor_fm						: FMCW FFT �X�y�N�g���̕ϓ�臒l	*/
/* [out] 	: afl_g_lca_ecu_2f_rear_dft_ryy_matrix				: 2FCW ���DFT �̋������֍s��	*/
/* [out] 	: u1_g_lca_ecu_2f_peak_num							: 2FCW ���DFT �X�y�N�g���̃s�[�N��	*/
/* [out] 	: au2_g_lca_ecu_2f_peak_bin							: 2FCW ���DFT �X�y�N�g���̃s�[�N���g���r��	*/
/* [out] 	: afl_g_lca_ecu_2f_peak_pow							: 2FCW ���DFT �X�y�N�g���̃s�[�N�d��	*/
/* [out] 	: afl_g_lca_ecu_2f_rear_dft_pow						: 2FCW ���DFT �X�y�N�g��		*/
/* [out] 	: afl_g_lca_ecu_up_rear_dft_pow						: FMCW(up)���DFT�X�y�N�g��		*/
/* [out] 	: afl_g_lca_ecu_2f_peak_pow							: LCA �x��J�nTTC�ݒ�l			*/
/*--------------------------------------------------------------------------*/
/* �d�l��	: MWR-RECO-24G-LCA-ABST-002B							 		*/
/*			: 9.1 �O���[�o���ϐ��錾��������<fn_lca_cmn_initialize_loop_data()>	*/
/****************************************************************************/
VD fn_lca_cmn_initialize_loop_data(VD)
{
	S4	s4_t_i;
	S4	s4_t_m;
	S4	s4_t_k;


	/*****************************************/
	/***** �������炪LCA_LOOP_DATA�\���� *****/
	/*****************************************/

	/***** LCA�x�񌋉� *****/
	st_g_lca_ecu_loop_data.u1_alm_flg	 = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_hazard_flg = CU1_DF_OFF;

	/***** �J�[�uR�Z�o�p�ϐ� *****/
	for (s4_t_i = (S4)0; s4_t_i < (S4)CS1_LCA_MAP_CURVR_BUFF; s4_t_i++) {
		st_g_lca_ecu_loop_data.s4_yaw_curv_r_archives[s4_t_i] = CS4_LCA_MAP_CURVR_MAX;
	}

	/***** �O�T�C�N�����玝�z���O�Ճ}�b�v����ϐ� *****/
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

	/***** �O�T�C�N�����玝�z�����W�f�[�^ *****/
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

	/***** �O�T�C�N�����玝�z�����̑��̃f�[�^ *****/
	st_g_lca_ecu_loop_data.u1_up_useless_flg = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_dn_useless_flg = CU1_DF_OFF;
	st_g_lca_ecu_loop_data.u1_2f_useless_flg = CU1_DF_OFF;

	/***** DFT�ɂ��ǌ��o�f�[�^ *****/
	st_g_lca_ecu_loop_data.fl_wall_dist				 = CFL_LCA_WALL_WALL_MAX_DIST_X;
	st_g_lca_ecu_loop_data.u1_cal_wall_flg			 = CU1_DF_ON;
	st_g_lca_ecu_loop_data.u1_cal_wall_ctr			 = CU1_LCA_CMN_ZERO_VALUE;
	st_g_lca_ecu_loop_data.u1_past_wall_ext_ctr		 = CU1_LCA_CMN_ZERO_VALUE;
	st_g_lca_ecu_loop_data.u1_use_prev_wall_dist_ctr = CU1_LCA_CMN_ZERO_VALUE;

	/*****************************************/
	/***** �����܂ł�LCA_LOOP_DATA�\���� *****/
	/*****************************************/


	/* ���Ԑ^��DFT�X�y�N�g�� */
	for (s4_t_i = (S4)0; s4_t_i < (S4)CU2_LCA_WALL_PEAK_SEARCH_DFT_BIN_NUM; s4_t_i++) {
		afl_g_lca_ecu_lfm_up_side_dft_pow[s4_t_i] = (FL)0;
		afl_g_lca_ecu_lfm_dn_side_dft_pow[s4_t_i] = (FL)0;
	}
	
	/* ���[���[�g */
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

	/* LCA�p�J�[�uR */
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
	
	/* ���F�� */
	for (s4_t_i = (S4)0; s4_t_i < (S4)3; s4_t_i++) {
		au1_g_lca_ecu_env_recog_peak_num[s4_t_i] = (U1)0;		/* 0:up 1:dn 2:2f */
		afl_g_lca_ecu_env_recog_ave_pow[s4_t_i]  = (FL)0;		/* 0:up 1:dn 2:2f */
	}
	
	/* LCA�x��J�nTTC�ݒ�l */
	fl_g_lca_ecu_ttc_thre = (FL)5;
	
	return;
}

/* ======================================================================== */
/* 	�������JAPI 															*/
/* ======================================================================== */

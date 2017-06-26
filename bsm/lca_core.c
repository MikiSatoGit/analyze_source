
/****************************************************************************/
/* �t�@�C����	: lca_core.c												*/
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
/*	t02					14.04.02			�����Z1 1�Z�� H.Nonogaki		*/
/*	�t�@�C�����̂̕ύX														*/
/*	�Z�p�w�b�_�̕ύX														*/
/*	�����V�~�����[�^���̑Ή�												*/
/*	�f�o�b�O�p�����̍폜													*/
/*	t03					14.04.09			�����Z1 1�Z�� H.Nonogaki		*/
/*	STEP2�Ή�																*/
/*	t04					14.05.06			�����Z1 1�Z�� Y.Yamada			*/
/*	BSM�F��������STEP2�Ή�													*/
/*	t05					14.10.15			�����Z1 1�Z�� H.Nonogaki		*/
/*	LCA���t�@�N�^�����O														*/
/*	t06					14.10.21			�����Z1 1�Z�� H.Nonogaki		*/
/*	�x�񐧌�̂��߂̌x��t���O���O���[�o��RAM��								*/
/*	t07 				14.10.30			�����Z1 1�Z�� K.Kato			*/
/*	AUDR BSM�F���f�[�^���b�`�\���̒ǉ��ɔ����w�b�_�C���N���[�h�ǉ�			*/
/*	t08					14.11.11			�����Z1 1�Z�� H.Nonogaki		*/
/*	���E�̒�`��define�l���g�p����悤�ύX��obj�ύX�Ȃ�						*/
/*	t11					16.08.02			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B�����ɐV�K�쐬														*/
/*	t12					16.08.03			�����Z2 1�Z�� Y.Nishioka		*/
/*	�݌vDR�w�E�����Ή��@OBJ�ύX�Ȃ�											*/
/*	t13					16.08.07			�����Z2 1�Z�� Y.Nishioka		*/
/*	AUDR�̂P�����b�`�ϐ��폜												*/
/*	t14					16.08.08			�����Z2 1�Z�� Y.Nishioka		*/
/*	�h���C�o�[�ɂ��TTC�J�X�^�}�C�Y�ݒ� ���쐬								*/
/*	t15					16.08.22			�����Z2 1�Z�� Y.Nishioka		*/
/*	Normal���W�ATarget���W��SIM_MODE�ɂ����Ă��L���� ���n�a�i�ύX�Ȃ�		*/
/*	t16					16.08.29			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B �c�ۑ�1420�Ή��@AUDR�C��											*/
/*	t17					16.08.31			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B LCA_TTC �J�X�^�}�C�Y�X�C�b�`�C��									*/
/*	t18					16.10.05			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B LCA�\���ύX�ɔ����A�w�b�_�ǂݍ��ݕύX								*/
/*	t19					16.10.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	�d�l�m�FNo.2776, 2777�Ή� ��OBJ�ύX�Ȃ�									*/
/*	tos26				16.12.27			����DME T.Azuma					*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�݌v�����̏C��							*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-RECOG-10-003 No.1				*/
/*	tos27				16.12.27			����DME M.Ejiri					*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@�i��OBJ�ύX����j				*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-RECOG-15-001A					*/
/*	tos34				16.12.27			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�݌v�����̏C��							*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-ABST-002B	No.57-65			*/
/*	tos35				16.12.27			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@��OBJ�ύX����					*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-ABST-002B No.1-11, 13-19		*/
/*	tos51				17.01.10			����DME T.Azuma					*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@��OBJ�ύX����					*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-RECOG-02-002					*/
/*	tos53				17.01.12			����DME Y.Sekine				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�`���̏C���@��OBJ�ύX����					*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-RECOG-09-003A					*/
/*	tos56				17.01.13			����DME M.Nakamura				*/
/*	�`���̏C���iGrep�ɂ�鑍�_���j											*/
/*	t22					17.01.19			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa �R�[�h���r���[�S�w�E�����̏C��									*/
/*	tos59				17.01.19			����DME M.Nakamura				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�C���R��Ή�								*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-ABST-002B No.1-10				*/
/*	tos61				17.01.19			����DME S.Fukuda				*/
/*	���ŃR�[�h���r���[�w�E�̔��f�@�C���R��Ή�								*/
/*	�g���[�T�r���B�e�B�V�[�g_MWR-RECO-24G-LCA-RECOG-15-001A No.3,4			*/
/*	t23					17.01.22			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa �����w�E�����̏C��												*/
/*	t24					17.01.22			�����Z2 1�Z�� Y.Nishioka		*/
/*	�R�����g�̏C���@��OBJ�ύX�Ȃ�											*/
/*	t25					17.01.23			�����Z2 1�Z�� Y.Nishioka		*/
/*	���Z���Ԋi�[�p�ϐ��̔z�u������ ��OBJ�ύX�Ȃ�							*/
/*	t26					17.01.23			�����Z2 1�Z�� Y.Nishioka		*/
/*	LCA NBD���b�`�p�ϐ����C��												*/
/*	t27					17.01.30			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B_���}�������_�T���v���R�[�h�}�[�W									*/
/*	t28					17.02.03			����Z2 1�Z�� Y.Nishioka		*/
/*	MWR-RECO-24G-LCA-ABST-004�i��4�j�Ή�									*/
/*	t29					17.02.08			����Z2 1�Z�� Y.Nishioka		*/
/*	����Z���t�w�E�����Ή�(310B_t081��t083)									*/
/*	t30					17.02.17			����Z2 1�Z�� Y.Yamada			*/
/*	LDA�A�g���胍�W�b�N�ǉ�													*/
/*	t32					17.03.03			�����Z2 1�Z�� Y.Nishioka		*/
/*	���œa���}��������C�����e���}�[�W�@��OBJ�ύX�Ȃ�						*/
/*	t33					17.03.10			�����Z2 1�Z�� Y.Nishioka		*/
/*	�O���Ԑ��I�t�Z�b�g�Ή�													*/
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

/***** �}�N���֐���`�w�b�_ *****/

/***** �O���Q�ƃw�b�_ *****/
#include "../../common/defcom_mwr.h"
#include "../../common/distance_ram_nbd_bsm.h"	/* NBD�̔F���f�[�^�p�\���� */
#include "../../common/distance_ram_mwr.h"
#include "../../system/system_mwr.h"			/* LCA TTC �J�X�^�}�C�Y�X�C�b�`�̒萔�Q�� */
#include "../../system/vehicle_spec_mwr.h"		/* �O���Ԑ��I�t�Z�b�g�ʂ̎d�����ؑ֗p */
#include "../../../app/config/inc_config.h"

/****************************************************************************/
/*								�}�N����`									*/
/****************************************************************************/
VD fn_lca_abst_read_data_by_bsmdest(VD);

/****************************************************************************/
/*								�萔��`									*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�ϐ��錾							*/
/****************************************************************************/
LCA_LOOP_DATA	st_g_lca_ecu_loop_data;			/* ��{�f�[�^ */
S2	s2_g_lca_ecu_curv_r;						/* LCA�p�J�[�uR */

/* �O���Ԑ��I�t�Z�b�g�� */
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA;
FL FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA;


#if (SIM_VI_OUTPUT==LCA_VI_ON)	/* For Labview */
//NORMAL���W
U1 u1_g_lca_sim_nml_pre_num;													// �O�T�C�N����NORMAL���W��
U1 u1_g_lca_sim_nml_crn_num;													// ���T�C�N����NORMAL���W��
U1 u1_g_lca_sim_nml_crn_num2;													// ���T�C�N����NORMAL���W��(����ڑ���)
U1 u1_g_lca_sim_tgt_pre_num;													// �O�T�C�N����TARGET���W��
U1 u1_g_lca_sim_tgt_crn_num;													// ���T�C�N����TARGET���W��(�N���X�^�����O�O)
U1 u1_g_lca_sim_tgt_crn_num2;													// ���T�C�N����TARGET���W��(�N���X�^�����O��)
U1 u1_g_lca_sim_tgt_crn_num3;													// ���T�C�N����TARGET���W��(�x��Ώ�)
NORMAL_LCA ast_g_lca_sim_nml_pre[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// �O�T�C�N����NORMAL���W�\����
NORMAL_LCA ast_g_lca_sim_nml_crn[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// ���T�C�N����NORMAL���W�\����
NORMAL_LCA ast_g_lca_sim_nml_crn2[CU1_LCA_CMN_NORMAL_BUFFSIZE];					// ���T�C�N����NORMAL���W�\����(����ڑ���)
NORMAL_LCA ast_g_lca_sim_tgt_pre[CU1_LCA_CMN_TGT_BUFFSIZE];						// �O�T�C�N����TARGET���W�\����
NORMAL_LCA ast_g_lca_sim_tgt_crn[CU1_LCA_CMN_TGT_BUFFSIZE];						// ���T�C�N����TARGET���W�\����(�N���X�^�����O�O)
NORMAL_LCA ast_g_lca_sim_tgt_crn2[CU1_LCA_CMN_TGT_BUFFSIZE];					// ���T�C�N����TARGET���W�\����(�N���X�^�����O��)
NORMAL_LCA ast_g_lca_sim_tgt_crn3[CU1_LCA_CMN_TGT_BUFFSIZE];					// ���T�C�N����TARGET���W�\����(�x��Ώ�)
#endif




/****************************************************************************/
/*								�X�^�e�B�b�N�֐�							*/
/****************************************************************************/

/* ======================================================================== */
/* 	�O�����JAPI 															*/
/* ======================================================================== */

/****************************************************************************/
/* �֐���	: fn_lca_core_main												*/
/*--------------------------------------------------------------------------*/
/* �@�\		: LCA/FHL�F������												*/
/*--------------------------------------------------------------------------*/
/* ����		: �Ȃ�															*/
/* �߂�l	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* [in]  	: st_g_bsm_loop_data.afl_installed_angle[0]	:					*/
/* [out] 	: st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg	: ���w�K�p�x(BSM�Ə�ɓ���)	*/
/* [in]  	: fl_g_lca_ecu_ttc_thre	: LCA �x��J�nTTC�ݒ�l					*/
/*--------------------------------------------------------------------------*/
/* �d�l��	: MWR-RECO-24G-LCA-ABST-005								 		*/
/*			: 4 LCA/FHL�F�������T�v											*/
/****************************************************************************/
VD fn_lca_core_main(VD)
{
	/****************************/
	/***** ���[�J���ϐ��錾 *****/
	/****************************/
	U1 u1_t_i;
	U2 u2_t_i;

	/* 2FCW���W */
	U1 u1_t_peak_music_num_2f;																	/* 2FCW freq-doa�}�b�v��̑����o�s�[�N�� */
	U1 au1_t_used_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];										/* 2FCW freq-doa�}�b�v��̃s�[�N�̎g�p�σt���O */
	FL afl_t_music_doa_pow_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
	FL afl_t_music_bin_intpl_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
	FL afl_t_music_doa_bin_intpl_2f[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];							/* 2FCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
	U1 au1_t_2f_dft_peak_flg[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];								/* 2FCW freq-doa�}�b�v��̃s�[�N��DFT�ɂ�蔭�������s�[�N�ł��邱�Ƃ̃t���O */
	U1 au1_t_2f_sharp_dftpeak_flg[CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE];							/* 2FCW freq-doa�}�b�v��̃s�[�N���s�����Ƃ̃t���O */
	/* �ʏ함�W */
	U1 u1_t_peak_music_num_up;																	/* FMCW freq-doa�}�b�v��̑����o�s�[�N�� */
	FL afl_t_music_doa_pow_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
	FL afl_t_music_bin_intpl_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
	FL afl_t_music_doa_bin_intpl_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];							/* FMCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
	U1 au1_t_used_up[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];										/* FMCW(up) freq-doa�}�b�v��̃s�[�N�̎g�p�σt���O */
	U1 u1_t_peak_music_num_dn;																	/* FMCW freq-doa�}�b�v��̑����o�s�[�N�� */
	FL afl_t_music_doa_pow_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
	FL afl_t_music_bin_intpl_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];								/* FMCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
	FL afl_t_music_doa_bin_intpl_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];							/* FMCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
	U1 au1_t_used_dn[CU1_LCA_CMN_LFM_DOA_PEAK_BUFFSIZE];										/* FMCW(dn) freq-doa�}�b�v��̃s�[�N�̎g�p�σt���O */
	/* NORMAL���W */
	U1 u1_t_nml_crn_num;																		/* ���T�C�N����NORMAL���W�� */
	NORMAL_LCA ast_t_nml_crn[CU1_LCA_CMN_NORMAL_BUFFSIZE];										/* ���T�C�N����NORMAL���W�\���� */
	/* TARGET���W */
	U1 u1_t_tgt_crn_num;																		/* ���T�C�N����TARGET���W�� */
	NORMAL_LCA ast_t_tgt_crn[CU1_LCA_CMN_TGT_BUFFSIZE];											/* ���T�C�N����TARGET���W�\���� */
	/* �x�񔻒� */
	U1 u1_t_alm_flg;
	U1 u1_t_hazard_flg;

	/******************************/
	/***** ���[�J���ϐ������� *****/
	/******************************/
	/* 2FCW���W */
	u1_t_peak_music_num_2f = (U1)0;
	for (u1_t_i = (U1)0; u1_t_i < CU1_LCA_CMN_FSK_DOA_PEAK_BUFFSIZE; u1_t_i++) {
		au1_t_used_2f[u1_t_i] 					= (U1)0;
		afl_t_music_doa_pow_2f	[u1_t_i]		= (FL)0;
		afl_t_music_bin_intpl_2f	[u1_t_i]	= (FL)0;
		afl_t_music_doa_bin_intpl_2f[u1_t_i]	= (FL)0;
		au1_t_2f_dft_peak_flg		[u1_t_i]	= CU1_DF_OFF;
		au1_t_2f_sharp_dftpeak_flg	[u1_t_i]	= CU1_DF_OFF;
	}
	/* �ʏ함�W */
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
	/* NORMAL���W */
	u1_t_nml_crn_num = (U1)0;
	/* TARGET���W */
	u1_t_tgt_crn_num = (U1)0;
	/* �x�񔻒� */
	u1_t_alm_flg	= CU1_DF_OFF;
	u1_t_hazard_flg = CU1_DF_OFF;

#ifdef _LCA_AUDR_INPUT	/* LCA���Z���Ԋm�F�p��AUDR�o�͕ϐ� */
	u1_g_lca_ecu_2f_peak_num_nbd_tmp	= (U1)0;				/* LCA_2���g���W���DFT�s�[�N�� */
	u1_g_lca_tgt_pre_num_nbd_tmp		= (U1)0;				/* LCA_�D�敨�W�T���� */
	u1_g_lca_music_ctr_2f_nbd_tmp		= (U1)0;				/* LCA�ŐV�K�ɍs����2F_MUSIC�� */
	for (u1_t_i = (U1)0; u1_t_i < (U1)2; u1_t_i++){
		u1_g_lca_music_ctr_fm_nbd_tmp[u1_t_i]		= (U1)0;	/* LCA�ŐV�K�ɍs����FM_MUSIC�� */
		u1_g_lca_share_peak_num_fm_nbd_tmp[u1_t_i]	= (U1)0;	/* FM_BSM�Ƃ̋��L�s�[�N�� */
	}
	u1_g_lca_share_peak_num_2f_nbd_tmp			= (U1)0;		/* 2F_BSM�Ƃ̋��L�s�[�N�� */
	u2_g_lca_make_pair_ctr_up_dn_nbd_tmp		= (U2)0;		/* �ʏ�up/dn�̃y�A�}�b�`�� */
	u2_g_lca_make_pair_ctr_up_dn_2f_nbd_tmp		= (U2)0;		/* �ʏ�up/dn/2f�̃y�A�}�b�`�� */
	u2_g_lca_make_pair_up_single_ctr_nbd_tmp	= (U2)0;		/* �ʏ�up/2f�̃y�A�}�b�`�� */
	u2_g_lca_make_pair_dn_single_ctr_nbd_tmp	= (U2)0;		/* �ʏ�dn/2f�̃y�A�}�b�`�� */
	u2_g_lca_nml_trk_ctr_nbd_tmp				= (U2)0;		/* �ʏ�g���b�L���O�̃��[�v�� */
	u2_g_lca_tgt_trk_ctr_nbd_tmp				= (U2)0;		/* target�g���b�L���O�̃��[�v�� */
#endif

	/**************************************/
	/***** ���[�J���ϐ�������(�\����) *****/
	/**************************************/
	/* NORMAL���W */
	fn_lca_cmn_init(
		ast_t_nml_crn,
		CU1_LCA_CMN_NORMAL_BUFFSIZE
	);
	/* TARGET���W */
	fn_lca_cmn_init(
		ast_t_tgt_crn,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);

	#if (SIM_VI_OUTPUT==LCA_VI_ON)	/* For Labview */
	// �O�T�C�N����TARGET���W
	fn_lca_cmn_init(
		ast_g_lca_sim_tgt_pre,
		CU1_LCA_CMN_TGT_BUFFSIZE
	);
	u1_g_lca_sim_tgt_pre_num = st_g_lca_ecu_loop_data.u1_tgt_pre_num;
	fn_lca_cmn_nml_output(
		ast_g_lca_sim_tgt_pre,					/* TARGET���W���̃R�s�[�� */
		st_g_lca_ecu_loop_data.ast_tgt_pre,		/* TARGET���W���̃R�s�[�� */
		(U2)CU1_LCA_CMN_TGT_BUFFSIZE			/* TARGET���W���̃R�s�[�� */
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
	/***** �O���[�o���ϐ��X�V *****/
	/******************************/
	/* LCA&FHL ���ڊp�x�̍X�V */
	st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = st_g_bsm_loop_data.afl_installed_angle[0];

	/* 0�`(LCA_DEG_MAX/2) �ŃK�[�h���|���� */
	if (st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg < (FL)0) {
		st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = (FL)0;
	} else if (st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg > (FL)(LCA_DEG_MAX) / (FL)2) {
		st_g_lca_ecu_loop_data.fl_lca_installed_angle_deg = (FL)(LCA_DEG_MAX) / (FL)2;
	} else {
		/* �������Ȃ� */
	}
	
	/* LCA �x��J�n TTC �̍X�V */
	/*  LCA �x��J�n TTC �̐ݒ�l g_lca_ecu_ttc_thre �𖈃T�C�N���ݒ肷�� */
	switch (u1_g_lca_ttc_table_custom_for_base) {			/* lca_ttc_table_custom */
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_OFF:			/* 0�FOFF */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_SHORT:		/* 1�FSHORT */
		fl_g_lca_ecu_ttc_thre = (FL)3;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_MIDDLE:		/* 2�FMIDDLE */
		fl_g_lca_ecu_ttc_thre = (FL)4;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_LONG:		/* 3�FLONG */
		fl_g_lca_ecu_ttc_thre = (FL)5;
		break;
	case CU1_SYSTEM_LCA_TTC_CUSTOMIZE_LCA_MODE_INIT:		/* �s��̏ꍇ */
		/* �s��̏ꍇ�͓��삳���Ȃ����� 0�FOFF �Ɠ�������������� */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	default:												/* ���̑��B�ʏ�͂��蓾�Ȃ� */
		/* ���蓾�Ȃ��f�[�^�̏ꍇ�͓��삳���Ȃ����� 0�FOFF �Ɠ�������������� */
		fl_g_lca_ecu_ttc_thre = (FL)0;
		break;
	}

	/*************************************/
	/***** 2FCW/FMCW�ϓ�臒l�Z�o���� *****/
	/*************************************/
	fn_lca_recg03_set_freq_threshold_2fcw();
	fn_lca_recg03_set_freq_threshold_fmcw();

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_3 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 3, &au2_g_lca_check_tmr[3]);	/* CheckPoint chk lca */
#endif 
#endif

	/**************************/
	/***** �ǋ����Z�o���� *****/
	/**************************/
	fn_lca_recg01_cal_wall_dist(
		&u1_t_peak_music_num_up,		/* [out] FMCW(up) freq-doa�}�b�v��̑����o�s�[�N�� */
		afl_t_music_doa_pow_up,			/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
		afl_t_music_bin_intpl_up,		/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
		afl_t_music_doa_bin_intpl_up,	/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
		&u1_t_peak_music_num_dn,		/* [out] FMCW(dn) freq-doa�}�b�v��̑����o�s�[�N�� */
		afl_t_music_doa_pow_dn,			/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
		afl_t_music_bin_intpl_dn,		/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
		afl_t_music_doa_bin_intpl_dn,	/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
		au1_t_used_up,					/* [out] �g�p�s�t���O(up) 0:�g�p�� 1:�g�p�s�� */
		au1_t_used_dn					/* [out] �g�p�s�t���O(dn) 0:�g�p�� 1:�g�p�s�� */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_4 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 4, &au2_g_lca_check_tmr[4]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************************************/
	/***** ���s�O�ՁE�אڎԐ��m���}�b�v�Z�o���� *****/
	/************************************************/
	if (fl_g_v_self_bsm_for_base > CFL_LCA_CMN_FHL_ON_SELF_VELOCITY_KMPH) {		/* MWR-RECO-24G-LCA-RECOG-02-002 ���� 4.a */
		fn_lca_recg02_one_side_vehicle_map();
	}

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_5 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 5, &au2_g_lca_check_tmr[5]);	/* CheckPoint chk lca */
#endif 
#endif

	/*********************************************/
	/***** 2FCW���DFT�̋������֍s��Z�o���� *****/
	/*********************************************/
	fn_lca_recg04_calc_fcw_dft_ryy_matrix();

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_6 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 6, &au2_g_lca_check_tmr[6]);	/* CheckPoint chk lca */
#endif 
#endif

	/***********************************************/
	/****** 2FCW���DFT��2D�s�[�N���Z�o���� ******/
	/***********************************************/
	fn_lca_recg05_seak_dft_2f_peak(
		&u1_t_peak_music_num_2f,		/* [out] 2FCW��2�����}�b�v��̑����o�s�[�N�� */
		au1_t_2f_dft_peak_flg,			/* [out] 2FCW��2�����}�b�v��̃s�[�N�����DFT�X�y�N�g���Ŕ��������s�[�N�ł���t���O */
		au1_t_2f_sharp_dftpeak_flg,		/* [out] 2FCW��2�����}�b�v��̃s�[�N���s���ł���t���O */
		afl_t_music_doa_pow_2f,			/* [out] 2FCW��2�����}�b�v��̃s�[�N��DBF�d�� */
		afl_t_music_bin_intpl_2f,		/* [out] 2FCW��2�����}�b�v��̃s�[�N�̎��g���r��(���) */
		afl_t_music_doa_bin_intpl_2f	/* [out] 2FCW��2�����}�b�v��̃s�[�N�̕��ʃr��(���) */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_8 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 8, &au2_g_lca_check_tmr[8]);	/* CheckPoint chk lca */
#endif 
#endif

	/***********************************/
	/***** 2FCW���DFT���ꔻ�菈�� *****/
	/***********************************/
	fn_lca_recg06_calc_2f_useless_flg();


#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_9 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 9, &au2_g_lca_check_tmr[9]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************************/
	/****** FMCW(UP)���DFT��2D�s�[�N���Z�o���� ******/
	/***************************************************/
	fn_lca_recg07_seak_dft_fmcw_up_peak(
		&u1_t_peak_music_num_up,		/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N�� */
		afl_t_music_doa_pow_up,			/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DBF-pow��� */
		afl_t_music_bin_intpl_up,		/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
		afl_t_music_doa_bin_intpl_up	/* [out] FMCW freq-doa�}�b�v��̑����o�s�[�N DOA-bin���(���) */
	);

	/************************/
	/***** ���F������ *****/
	/************************/
	fn_lca_cmn_environ_judgement();

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_11 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 11, &au2_g_lca_check_tmr[11]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************/
	/***** �D�敨�W���� *****/
	/************************/
	fn_lca_recg08_seek_prior_obj(
		&u1_t_nml_crn_num,		/* [out] ���T�C�N����NORMAL���W�� */
		ast_t_nml_crn			/* [out] ���T�C�N����NORMAL���W�\���� */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_13 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 13, &au2_g_lca_check_tmr[13]);	/* CheckPoint chk lca */
#endif 
#endif

	/************************/
	/***** �ʏ함�W���� *****/
	/************************/
	fn_lca_recg09_seek_ordinary_obj(
		u1_t_peak_music_num_2f,			/* [in] 2FCW��2�����s�[�N�� */
		afl_t_music_doa_pow_2f,			/* [in] 2FCW��2�����s�[�N��DBF�d�� */
		afl_t_music_bin_intpl_2f,		/* [in] 2FCW��2�����s�[�N�̎��g��bin(���) */
		afl_t_music_doa_bin_intpl_2f,	/* [in] 2FCW��2�����s�[�N�̕���bin(���) */
		au1_t_2f_dft_peak_flg,			/* [in] 2FCW��2�����s�[�N��DFT���o�t���O */
		u1_t_peak_music_num_up,			/* [in] FMCW(up)��2�����s�[�N�� */
		afl_t_music_doa_pow_up,			/* [in] FMCW(up)��2�����s�[�N��DBF�d�� */
		afl_t_music_bin_intpl_up,		/* [in] FMCW(up)��2�����s�[�N�̎��g��bin(���) */
		afl_t_music_doa_bin_intpl_up,	/* [in] FMCW(up)��2�����s�[�N�̕���bin(���) */
		&u1_t_peak_music_num_dn,		/* [in/out] FMCW(dn)��2�����s�[�N�� */
		afl_t_music_doa_pow_dn,			/* [in/out] FMCW(dn)��2�����s�[�N��DBF�d�� */
		afl_t_music_bin_intpl_dn,		/* [in/out] FMCW(dn)��2�����s�[�N�̎��g��bin(���) */
		afl_t_music_doa_bin_intpl_dn,	/* [in/out] FMCW(dn)��2�����s�[�N�̕���bin(���) */
		au1_t_used_up,					/* [in/out] FMCW(up) �s�[�N�g�p�σt���O */
		au1_t_used_dn,					/* [in/out] FMCW(dn) �s�[�N�g�p�σt���O */
		au1_t_used_2f,					/* [out] 2FCW �s�[�N�g�p�σt���O */
		&u1_t_nml_crn_num,				/* [in/out] ���T�C�N����NORMAL���W�� */
		ast_t_nml_crn					/* [out] ���T�C�N����NORMAL���W��� */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_22 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 22, &au2_g_lca_check_tmr[22]);	/* CheckPoint chk lca */
#endif 
#endif

	/*******************************/
	/***** �ߋ���2���g���W���� *****/
	/*******************************/
	fn_lca_recg10_seek_2f_obj(
		au1_t_used_2f,					/* [in/out] 2FCW 2�����s�[�N�̎g�p�ς݃t���O */
		u1_t_peak_music_num_2f,			/* [in] 2FCW 2�����s�[�N�̃s�[�N�� */
		afl_t_music_doa_pow_2f,			/* [in] 2FCW 2�����s�[�N��DBF�d�� */
		afl_t_music_bin_intpl_2f,		/* [in] 2FCW 2�����s�[�N�̎��g���r��(���) */
		afl_t_music_doa_bin_intpl_2f,	/* [in] 2FCW 2�����s�[�N�̕��ʃr��(���) */
		au1_t_2f_sharp_dftpeak_flg,		/* [in] 2FCW 2�����s�[�N���s���ł���t���O */
		&u1_t_nml_crn_num,				/* [in/out] ���T�C�N����NORMAL���W�� */
		ast_t_nml_crn					/* [in/out] ���T�C�N����NORMAL���W��� */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_24 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 24, &au2_g_lca_check_tmr[24]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************************/
	/*** BSM����p����Normal���W�̒ǉ��ƍ폜 *********/
	/***************************************************/
	fn_lca_recg17_normal_erase_and_add(
		&u1_t_nml_crn_num,				/* [in/out] ���T�C�N����NORMAL���W�� */
		ast_t_nml_crn					/* [in/out] ���T�C�N����NORMAL���W�\���� */
	);

	/**********************************/
	/***** NORMAL���W����ڑ����� *****/
	/**********************************/
	fn_lca_recg11_nml_connect(
		&u1_t_nml_crn_num,		/* [in/out] Normal���W�� */
		ast_t_nml_crn			/* [in/out] Normal���W��� */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_27 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 27, &au2_g_lca_check_tmr[27]);	/* CheckPoint chk lca */
#endif 
#endif

#ifdef _LCA_AUDR_INPUT	/* LCA���Z���Ԋm�F�p��AUDR�o�͕ϐ� */
	/* ��AUDR ABST_15 */
	/*********************************/
	/*** Normal���W��NBD�i�[�����p ***/
	/*********************************/
	for(u1_t_i = 0; u1_t_i < CU1_LCA_CMN_NORMAL_BUFFSIZE; u1_t_i++ ){
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_stop_flg			= ast_t_nml_crn[u1_t_i].u1_stop_flg;			/*	��~���t���O	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_trk_num				= ast_t_nml_crn[u1_t_i].u1_trk_num;				/*	�g���b�L���O��	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_lost_num			= ast_t_nml_crn[u1_t_i].u1_lost_num;			/*	�O�}��	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_new_flg				= ast_t_nml_crn[u1_t_i].u1_new_flg;				/*	�V�K���W�t���O	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_num					= ast_t_nml_crn[u1_t_i].u1_num;					/*	���W�ԍ�	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_used				= ast_t_nml_crn[u1_t_i].u1_used;				/*	�̂ăt���O	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_dc_flg				= ast_t_nml_crn[u1_t_i].u1_dc_flg;				/*	���W�^�C�v���	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_up_flg	= ast_t_nml_crn[u1_t_i].u1_single_peak_up_flg;	/*	�Ѓs�[�N�t���O(up�̂ݔ���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_dn_flg	= ast_t_nml_crn[u1_t_i].u1_single_peak_dn_flg;	/*	�Ѓs�[�N�t���O(dn�̂ݔ���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_trked_flg			= ast_t_nml_crn[u1_t_i].u1_trked_flg;			/*	NORMAL���W�̃g���b�L���O�t���O	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_single_peak_trk_num	= ast_t_nml_crn[u1_t_i].u1_single_peak_trk_num;	/*	�Ѓs�[�N�A���ڑ���	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_side_runner_flg		= ast_t_nml_crn[u1_t_i].u1_side_runner_flg;		/*	�����O�}�t���O(TARGET���W�Ŏg�p)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_car_type			= ast_t_nml_crn[u1_t_i].u1_car_type;			/*	CAR�^�C�v	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].u1_truck_index			= ast_t_nml_crn[u1_t_i].u1_truck_index;			/*	�Z�O�����gindex(�g���b�N����p)	*/

		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_up_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_up_intpl;		/*	���g��up�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_dn_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_dn_intpl;		/*	���g��dn�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_2f_intpl		= ast_t_nml_crn[u1_t_i].fl_bin_2f_intpl;		/*	���g��2f�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_up_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_up_music_intpl;	/*	����up�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_dn_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_dn_music_intpl;	/*	����dn�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_bin_2f_music_intpl	= ast_t_nml_crn[u1_t_i].fl_bin_2f_music_intpl;	/*	����2f�r��(���)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_up				= ast_t_nml_crn[u1_t_i].fl_pow_up;				/*	FFT pow (up)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_dn				= ast_t_nml_crn[u1_t_i].fl_pow_dn;				/*	FFT pow (down)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_2f				= ast_t_nml_crn[u1_t_i].fl_pow_2f;				/*	FFT pow (2f)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_up_music		= ast_t_nml_crn[u1_t_i].fl_pow_up_music;		/*	DBF pow (up)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_dn_music		= ast_t_nml_crn[u1_t_i].fl_pow_dn_music;		/*	DBF pow (dn)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_pow_2f_music		= ast_t_nml_crn[u1_t_i].fl_pow_2f_music;		/*	DBF pow (2f)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Rxobs				= ast_t_nml_crn[u1_t_i].fl_Rxobs;				/*	X	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Ryobs				= ast_t_nml_crn[u1_t_i].fl_Ryobs;				/*	Y	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Rxfil				= ast_t_nml_crn[u1_t_i].fl_Rxfil;				/*	X(̨���l)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Ryfil				= ast_t_nml_crn[u1_t_i].fl_Ryfil;				/*	Y(̨���l)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vxobs_mps			= ast_t_nml_crn[u1_t_i].fl_Vxobs_mps;			/*	VX	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vyobs_mps			= ast_t_nml_crn[u1_t_i].fl_Vyobs_mps;			/*	VY	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vxfil_mps			= ast_t_nml_crn[u1_t_i].fl_Vxfil_mps;			/*	VX(̨���l)	*/
		ast_g_lca_normal_nbd_tmp[u1_t_i].fl_Vyfil_mps			= ast_t_nml_crn[u1_t_i].fl_Vyfil_mps;			/*	VY(̨���l)	*/
	}
#endif


	/**********************************/
	/***** TARGET���W����ڑ����� *****/
	/**********************************/
	fn_lca_recg12_tgt_connect(
		u1_t_nml_crn_num,				/* [in]  Normal���W�� */
		ast_t_nml_crn,					/* [in]  Normal���W��� */
		&u1_t_tgt_crn_num,				/* [out] Target���W�� */
		ast_t_tgt_crn,					/* [out] Target���W��� */
		u1_t_peak_music_num_2f,			/* [in]  2FCW freq-doa�}�b�v��̑����o�s�[�N�� */
		afl_t_music_bin_intpl_2f,		/* [in]  2FCW freq-doa�}�b�v��̑����o�s�[�N freq-bin���(���) */
		au1_t_2f_sharp_dftpeak_flg		/* [in]  2FCW freq-doa�}�b�v��̃s�[�N���s�����Ƃ̃t���O */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_30 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 30, &au2_g_lca_check_tmr[30]);	/* CheckPoint chk lca */
#endif 
#endif

	/***************************************/
	/***** TARGET���W��LCA�x�񔻒菈�� *****/
	/***************************************/
	fn_lca_recg13_lca_alm(
		u1_t_tgt_crn_num,		/* [in]     ���T�C�N����TARGET���W�� */
		ast_t_tgt_crn,			/* [in/out] ���T�C�N����Target���W��� ([out] ������(Ryfil��)�Ƀ\�[�g��) */
		&u1_t_alm_flg			/* [out]    LCA�x��t���O */
	);

	/***************************************/
	/***** TARGET���W��FHL�x�񔻒菈�� *****/
	/***************************************/
	fn_lca_recg14_fhl_alm(
		u1_t_tgt_crn_num,		/* [in]     ���T�C�N����TARGET���W�� */
		ast_t_tgt_crn,			/* [in/out] ���T�C�N����Target���W��� */
		&u1_t_hazard_flg		/* [out]    FHL�x��t���O */
	);

#ifdef _LCA_CHECK_TIMER	/* LCA���Z���Ԋi�[_31 */
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk( 31, &au2_g_lca_check_tmr[31]);	/* CheckPoint chk lca */
#endif 
#endif

#ifdef _LCA_AUDR_INPUT	/* LCA���Z���Ԋm�F�p��AUDR�o�͕ϐ� */
	/* ��AUDR ABST_16 */
	/*********************************/
	/*** Target���W��NBD�i�[�����p ***/
	/*********************************/
	for(u1_t_i = 0; u1_t_i < CU1_LCA_CMN_TGT_BUFFSIZE; u1_t_i++ ){
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_stop_flg			= ast_t_tgt_crn[u1_t_i].u1_stop_flg;			/*	��~���t���O	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_trk_num				= ast_t_tgt_crn[u1_t_i].u1_trk_num;				/*	�g���b�L���O��	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_lost_num			= ast_t_tgt_crn[u1_t_i].u1_lost_num;			/*	�O�}��	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_new_flg				= ast_t_tgt_crn[u1_t_i].u1_new_flg;				/*	�V�K���W�t���O	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_num					= ast_t_tgt_crn[u1_t_i].u1_num;					/*	���W�ԍ�	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_used				= ast_t_tgt_crn[u1_t_i].u1_used;				/*	�̂ăt���O	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_dc_flg				= ast_t_tgt_crn[u1_t_i].u1_dc_flg;				/*	���W�^�C�v���	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_up_flg	= ast_t_tgt_crn[u1_t_i].u1_single_peak_up_flg;	/*	�Ѓs�[�N�t���O(up�̂ݔ���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_dn_flg	= ast_t_tgt_crn[u1_t_i].u1_single_peak_dn_flg;	/*	�Ѓs�[�N�t���O(dn�̂ݔ���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_trked_flg			= ast_t_tgt_crn[u1_t_i].u1_trked_flg;			/*	TARGET���W�̃g���b�L���O�t���O	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_alm_flg				= ast_t_tgt_crn[u1_t_i].u1_alm_flg;				/*	LCA�x�񕨕W�t���O(���T�C�N��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_pre_alm_flg			= ast_t_tgt_crn[u1_t_i].u1_pre_alm_flg;			/*	LCA�x�񕨕W�t���O(�O�T�C�N��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_single_peak_trk_num	= ast_t_tgt_crn[u1_t_i].u1_single_peak_trk_num;	/*	�Ѓs�[�N�A���ڑ���	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_side_runner_flg		= ast_t_tgt_crn[u1_t_i].u1_side_runner_flg;		/*	�����O�}�t���O(TARGET���W�Ŏg�p)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_car_type			= ast_t_tgt_crn[u1_t_i].u1_car_type;			/*	CAR�^�C�v	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_truck_index			= ast_t_tgt_crn[u1_t_i].u1_truck_index;			/*	�Z�O�����gindex(�g���b�N����p)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_hazard_flg			= ast_t_tgt_crn[u1_t_i].u1_hazard_flg;			/*	FHL�x�񕨕W�t���O(���T�C�N��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_pre_hazard_flg		= ast_t_tgt_crn[u1_t_i].u1_pre_hazard_flg;		/*	FHL�x�񕨕W�t���O(�O�T�C�N��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].u1_fhl_on_cnt			= ast_t_tgt_crn[u1_t_i].u1_fhl_on_cnt;			/*	FHL�x��ON�J�E���^	*/
        
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_up_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_up_intpl;		/*	���g��up�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_dn_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_dn_intpl;		/*	���g��dn�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_2f_intpl		= ast_t_tgt_crn[u1_t_i].fl_bin_2f_intpl;		/*	���g��2f�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_up_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_up_music_intpl;	/*	����up�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_dn_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_dn_music_intpl;	/*	����dn�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_bin_2f_music_intpl	= ast_t_tgt_crn[u1_t_i].fl_bin_2f_music_intpl;	/*	����2f�r��(���)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Rxobs				= ast_t_tgt_crn[u1_t_i].fl_Rxobs;				/*	X	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Ryobs				= ast_t_tgt_crn[u1_t_i].fl_Ryobs;				/*	Y	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Rxfil				= ast_t_tgt_crn[u1_t_i].fl_Rxfil;				/*	X(̨���l)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Ryfil				= ast_t_tgt_crn[u1_t_i].fl_Ryfil;				/*	Y(̨���l)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vxobs_mps			= ast_t_tgt_crn[u1_t_i].fl_Vxobs_mps;			/*	VX	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vyobs_mps			= ast_t_tgt_crn[u1_t_i].fl_Vyobs_mps;			/*	VY	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vxfil_mps			= ast_t_tgt_crn[u1_t_i].fl_Vxfil_mps;			/*	VX(̨���l)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_Vyfil_mps			= ast_t_tgt_crn[u1_t_i].fl_Vyfil_mps;			/*	VY(̨���l)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_prob				= ast_t_tgt_crn[u1_t_i].fl_prob;				/*	�אڎԐ��m��(TARGET���W��Rfil�ɂ��m��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_trk_prob			= ast_t_tgt_crn[u1_t_i].fl_trk_prob;			/*	�אڎԐ��m��(TARGET���W�̃g���b�L���O��̊m��)	*/
		ast_g_lca_target_nbd_tmp[u1_t_i].fl_ttc					= ast_t_tgt_crn[u1_t_i].fl_ttc;					/*	TTC	*/
	}
#endif

	/**************************************/
	/***** ���W�������T�C�N���Ɏ��z�� ***/
	/**************************************/
	fn_lca_recg15_loop_data_trim(
		u1_t_nml_crn_num,		/* [in]     ���T�C�N����NORMAL���W�� */
		ast_t_nml_crn,			/* [in/out] ���T�C�N����NORMAL���W��� */
		u1_t_tgt_crn_num,		/* [in]     ���T�C�N����TARGET���W�� */
		ast_t_tgt_crn,			/* [in/out] ���T�C�N����TARGET���W��� */
		u1_t_alm_flg,			/* [in]     LCA�x��t���O */
		u1_t_hazard_flg			/* [in]     FHL�x��t���O */
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
		u1_t_tgt_crn_num,		// [in] ���T�C�N����TARGET���W��
		ast_t_tgt_crn			// [in] ���T�C�N����TARGET���W�\����
	);
	#endif

#ifdef _LCA_AUDR_INPUT	/* LCA���Z���Ԋm�F�p��AUDR�o�͕ϐ� */
#if (MODE_ECU_SIM == ECU_MODE)
	/* ��AUDR	NBDinput_ABST_01 �` 14 */
	/* �d�l���ł́A������AUDR�p�ɕϐ������b�`����Ƃ��邪�A		*/
	/* 1)RAM�̈�팸�̂��߁A2)�o�͕ϐ�������ȍ~�ω����Ȃ����߁A*/
	/* �����ł̃��b�`�͍s�킸�A�F��������ɒ���_NBD�ɏo�͂���B	*/
#endif
#endif
	return;
}



/****************************************************************************/
/* �֐���	: fn_lca_abst_init_data											*/
/*--------------------------------------------------------------------------*/
/* �@�\		: LCA_ABST�̐ݒ肪�K�v�Ȃ��̂�ݒ肷��							*/
/*--------------------------------------------------------------------------*/
/* ����		: �Ȃ�															*/
/* �߂�l	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* [in]  	: �Ȃ�															*/
/* [out] 	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �d�l��	: MWR-RECO-24G-LCA-ABST-006								 		*/
/*			: 6.2.1 LCA/FHL �ŐV�K��`����K���l							*/
/****************************************************************************/
VD fn_lca_abst_init_data(VD)
{
	/* �d�������ؑփf�[�^�̐ݒ� */
	fn_lca_abst_read_data_by_bsmdest();
	
	return;
}




/* ======================================================================== */
/* 	�������JAPI 															*/
/* ======================================================================== */

/****************************************************************************/
/* �֐���	: fn_lca_abst_read_data_by_bsmdest								*/
/*--------------------------------------------------------------------------*/
/* �@�\		: BSM_DEST�ɂ���āA�؂�ւ���l��ݒ肷��						*/
/*--------------------------------------------------------------------------*/
/* ����		: �Ȃ�															*/
/* �߂�l	: �Ȃ�															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* [in]  	: CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone; */
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA							*/
/* [out] 	: FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA						*/
/*--------------------------------------------------------------------------*/
/* �d�l��	: MWR-RECO-24G-LCA-ABST-006								 		*/
/*			: 6.2.1 LCA/FHL �ŐV�K��`����K���l							*/
/****************************************************************************/
VD fn_lca_abst_read_data_by_bsmdest(VD)
{
	U1 u1_t_bsm_bsd_zone_y_max;
	
	/* BSD_ZONE_Y_MAX�𐮐��l�Ŕ�r���邽�߂�LSB�ϊ��O�Ƀ��[�J���ϐ��Ɉ�U���b�`���� */
	u1_t_bsm_bsd_zone_y_max = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone;
	
	if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_WIDE) {
		/* BSM�x��̈�ݒ蕝��Wide�ȏꍇ�́ALCA�̊O���I�t�Z�b�g�ʂ�Wide�ɐݒ肷�� */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)6.2;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.95;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.7;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.45;
	} else if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_NARROW) {
		/* BSM�x��̈�ݒ蕝��Narrow�ȏꍇ�́ALCA�̊O���I�t�Z�b�g�ʂ�Narrow�ɐݒ肷�� */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)5.75;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.5;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.25;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.0;
	} else {
		/* �s��l�̏ꍇ�́Au1_Warning_zone�̕s��l�ɍ��킹�āAWide�ɐݒ肷�� */
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_3SIGMA	= (FL)6.2;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_2SIGMA	= (FL)5.95;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_1SIGMA	= (FL)5.7;
		FL_LCA_CMN_OUTSIDE_HENI_OFFSET_05SIGMA	= (FL)5.45;
	}

	return;
}
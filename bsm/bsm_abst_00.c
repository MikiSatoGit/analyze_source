/****************************************************************************/
/* �t�@�C����	: BSM_ABST_00.c												*/
/*--------------------------------------------------------------------------*/
/* ���W���[����	: BSM�ŗp����d�������ňقȂ�K���萔�̓Ǎ��E�Z�o			*/
/*--------------------------------------------------------------------------*/
/* �@�\			: 															*/
/*--------------------------------------------------------------------------*/
/* ���l			:															*/
/*--------------------------------------------------------------------------*/
/* �\���֐�		: 															*/
/*--------------------------------------------------------------------------*/
/* �ύX����		:															*/
/* Version				date				name							*/
/*	t01					14.11.03			�����Z1 1�Z�� K.Kato			*/
/*	�V�K�쐬	MWR-RECO-24G-BSM-ABST-00-009 �K���f�[�^�������Ή�			*/
/*	t02					14.11.03			�����Z1 1�Z�� K.Kato			*/
/*	�d�lQ&A No.697, 698�Ή�													*/
/*	t03					14.11.04			�����Z1 1�Z�� K.Kato			*/
/*	�c�ۑ� No.148�Ή�														*/
/*	t04					14.11.07			�����Z1 1�Z�� K.Kato			*/
/*	�c�ۑ� No.153, 154�Ή�													*/
/*	t05					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���֑Ή�															*/
/*	t06					15.02.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� _ALWAYS_CHECK_FR_SOT��#ifdef�폜								*/
/*	t07					15.03.02			�����Z2 1�Z�� Y.Hosoi			*/
/*	MWR-FLASH-24�f-09-A�Ή�													*/
/*	t08					15.03.20			�����Z2 1�Z�� Y.Hosoi			*/
/*	�H�������� ID 49 BSMBSM�p�x�Ǒփe�[�u�����E�Ή����ؗp�\�t�g				*/
/*	t10					15.06.26			�����Z2 1�Z�� G.Jomori			*/
/*	t715�}�[�W																*/
/*	t11					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t12					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t13					15.09.11			�����Z2 1�Z�� G.Jomori			*/
/*	MWR-RECO-24G-BSM-ABST-00-013�Ή�										*/
/*	t14					16.01.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�												*/
/*	t15					16.01.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�(OBJ�ύX�Ȃ�)									*/
/*	t16					16.03.11			�����Z2 1�Z�� G.Jomori			*/
/*	010B CV-R 3/8���s MWR-RECO-24G-BSM-ABST-00-017�Ή�						*/
/*	t17					16.03.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l�Ή�														*/
/*	t18					16.03.28			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/*	t19					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t20					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �c�ۑ�No1336�Ή� OBJ�ύX�Ȃ�										*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t21					16.07.19			�����Z2 1�Z�� Y.Hosoi			*/
/*	�Ԏ�W�J�Ή�															*/
/*  p01                 16.12.06            �����Z2 1�Z�� H.Nakamichi       */
/*  291B 1A�[���̂���P�������{                                              */
/*	t24					17.02.02			����Z2 1�Z�� G.Jomori			*/
/*	310B BSM ���}����d�l�Ή�(h�t�@�C�����ύX)								*/
/*	t25					17.02.02			����Z2 1�Z�� G.Jomori			*/
/*	BSM ����Z���t�w�E�Ή�(OBJ�ύX�Ȃ�)										*/
/****************************************************************************/

/****************************************************************************/
/*							�C���N���[�h�t�@�C��							*/
/****************************************************************************/
#include "inc_bsm.h"


#include "../../../app/config/adjust_table_sns.h"
#include "parameter_sig.h"

#include "bsm_abst_00.h"

#include "../../system/vehicle_spec_mwr.h"

/****************************************************************************/
/*							�}�N����`										*/
/****************************************************************************/
/* �x��̈�I�t�Z�b�g (���[) */
#define CFL_D_BSM_ALARM_X_OFFSET_IN_NARROW	(0.0F)
#define CFL_D_BSM_ALARM_X_OFFSET_IN_WIDE	(0.0F)

/* �x��̈�I�t�Z�b�g (�O�[) */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW	(0.35F)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE	(0.05F)	//2017.03.15 Miki 0.25->0.05
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW	(0.2F)
#define CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE	(0.0F)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */


/* �x��̈�I�t�Z�b�g (��[) */
#define CFL_D_BSM_ALARM_Y_OFFSET_NARROW		(0.0F)
#define CFL_D_BSM_ALARM_Y_OFFSET_WIDE		(0.0F)

/* �x�񎞊ԃI�t�Z�b�g */
#define CFL_D_BSM_ALARM_OFFSET_TIME_NARROW	(0.0F)
#define CFL_D_BSM_ALARM_OFFSET_TIME_WIDE	(0.0F)

/* �^������͈� */
#define CFL_D_BSM_EKF_RY_SIDE_NARROW		(1.0F)
#define CFL_D_BSM_EKF_RY_SIDE_WIDE			(1.5F)

/* AXIS_DEFAULT == 70 */
/* for Sequoia */
#define CS4_D_SOT_CHECK_CYCLE_FWD2_70		(2)				/* �� [cycle] */
#define CS4_D_SOT_DELAY_CYCLE_70			(SOT_CHECK_CYCLE_FWD_70+SOT_CHECK_CYCLE_BWD_70+SOT_CHECK_CYCLE_FWD2_70+1)
#define CS4_D_SOT_FIND_CYCLE_70				(1)				/* [cycle] */

#define	CS4_D_SOT_CYCLE_TH_FWD_70			(4)				/* ��  [cycle] smaller than SOT_CHECK_CYCLE_FWD */
#define	CS4_D_SOT_CYCLE_TH_BWD_70			(5)				/* ��  [cycle]smaller than SOT_CHECK_CYCLE_BWD */
#define	CS4_D_SOT_CYCLE_TH_FWD2_70			(1)				/* ��  [cycle]smaller than SOT_CHECK_CYCLE_FWD2 */

#define	CS4_D_SOT_POINT_TH_FWD_70			(3)				/* ��  [-] */
#define	CS4_D_SOT_POINT_TH_BWD_70			(3)				/* ��  [-] */

/* AXIS_DEFAULT != 70 */
/* for Camry */
#define CS4_D_SOT_CHECK_CYCLE_FWD2_OTH		(1)				/* [cycle] */
#define CS4_D_SOT_DELAY_CYCLE_OTH			(SOT_CHECK_CYCLE_FWD_OTH+SOT_CHECK_CYCLE_BWD_OTH+SOT_CHECK_CYCLE_FWD2_OTH+1)	/* [cycle] */
#define CS4_D_SOT_FIND_CYCLE_OTH			(1)				/* [cycle] */

#define	CS4_D_SOT_CYCLE_TH_FWD_OTH			(2)				/* [cycle] smaller than SOT_CHECK_CYCLE_FWD */
#define	CS4_D_SOT_CYCLE_TH_BWD_OTH			(3)				/* [cycle] smaller than SOT_CHECK_CYCLE_BWD */
#define	CS4_D_SOT_CYCLE_TH_FWD2_OTH			(1)				/* [cycle] smaller than SOT_CHECK_CYCLE_FWD2 */

#define	CS4_D_SOT_POINT_TH_FWD_OTH			(2)				/* [-] */
#define	CS4_D_SOT_POINT_TH_BWD_OTH			(2)				/* [-] */


/* �ԗ���[�d��臒l */
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH_NARROW		(50.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH_WIDE		(50.0F)

/* �ԗ���[�d�͍�臒l */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW	(15.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE		(15.0F)
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW    (12.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE      (12.0F)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */

/* ToS �����͈� */
#if (BSM_OPTION_SW_ABST == TYPE_A)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW		(0.0F)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE		(-0.5F)
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW     (0.0F)
#define CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE       (0.0F)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */


/* �ԗ���[�d��臒l�Q */
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_NARROW		(54.0F)
#define CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_WIDE		(54.0F)

/* �ׯ���ċ���(X ����) */
#define CFL_D_BSM_TRUCK_WIDTH_NARROW				(0.0F)
#define CFL_D_BSM_TRUCK_WIDTH_WIDE					(2.6F * 0.5F)

/* �����ԁ|�Ǌԋ���臒l */
#define CFL_D_BSM_SOT_WALL_DIFF_NARROW				(1.4F)
#define CFL_D_BSM_SOT_WALL_DIFF_WIDE				(1.8F)

/* Gain of wall flag reset */
#if (BSM_OPTION_SW_ABST == TYPE_A)
/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
#define CFL_D_BSM_WALL_OFF_GAIN_NARROW				(32.0F)
#define CFL_D_BSM_WALL_OFF_GAIN_WIDE				(8.0F)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */

/****************************************************************************/
/*							�\���̒�`										*/
/****************************************************************************/

/****************************************************************************/
/*							�O���[�o���ϐ��錾								*/
/****************************************************************************/
U2 U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH;						/* �ԕ�	1mm */
U4 U4_BSM_FLSH_DELTA_W;										/* ���t���ʒu�̾�ă�W	1mm	�ԕ��`BSM���h�����S */
U4 U4_BSM_FLSH_FLASH_ANGLE;									/* ���t���p�x	0.1deg	�ԗ����ʂƃZ���T�̂Ȃ��p */
FL FL_BSM_FLSH_BSD_ZONE_Y_MAX;
FL FL_BSM_FLSH_ALARM_X_IN;									/* �x��͈� (���[) */
FL FL_BSM_FLSH_ALARM_X_OUT;									/* �x��̈� (�O�[) */
FL FL_BSM_FLSH_ALARM_X_OFFSET_IN;							/* �x��̈�I�t�Z�b�g (���[) */
FL FL_BSM_FLSH_ALARM_X_OFFSET_OUT;							/* �x��̈�I�t�Z�b�g (�O�[) */
FL FL_BSM_FLSH_ALARM_Y_OFFSET;								/* �x��̈�I�t�Z�b�g (��[) */
FL FL_BSM_FLSH_ALARM_OFFSET_TIME;							/* �x�񎞊ԃI�t�Z�b�g */
FL FL_BSM_FLSH_EKF_RY_SIDE;									/* �^������͈� */
S4 S4_BSM_FLSH_AXIS_DEFAULT;								/* �Z���T��t�p�x�ݒ� �l�̌ܓ���̃f�[�^ */
FL FL_BSM_FLSH_AXIS_DEFAULT;								/* �Z���T��t�p�x�ݒ� */
U4 U4_BSM_FLSH_DELTA_L;										/* ���t���ʒu�̾�ă�L	1mm	Rr�o���p��[�`BSM���h�����S */

S4 S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2;
S4 S4_BSM_FLSH_SOT_FIND_CYCLE;

S4 S4_BSM_FLSH_SOT_CYCLE_TH_FWD;
S4 S4_BSM_FLSH_SOT_CYCLE_TH_BWD;
S4 S4_BSM_FLSH_SOT_CYCLE_TH_FWD2;

S4 S4_BSM_FLSH_SOT_POINT_TH_FWD;
S4 S4_BSM_FLSH_SOT_POINT_TH_BWD;

FL FL_BSM_FLSH_YOMIKAE_TBL_FM[YOMIKAE_TABLE_SIZE];
FL FL_BSM_FLSH_YOMIKAE_TBL_2F[YOMIKAE_TABLE_SIZE];

FL FL_BSM_ALT_ON_SPEED;
FL FL_BSM_ALT_OFF_SPEED;

FL FL_BSM_VI_TOS_END_FFT_POW_TH;							/* �ԗ���[�d��臒l */
FL FL_BSM_VI_TOS_END_FFT_POW_DIFF;							/* �ԗ���[�d�͍�臒l */
FL FL_BSM_VI_TOS_END_ERASE_LIMIT;							/* ToS �����͈� */
FL FL_BSM_VI_TOS_END_FFT_POW_TH2;							/* �ԗ���[�d��臒l�Q */
FL FL_BSM_TRUCK_WIDTH;										/* �ׯ���ċ���(X ����) */
FL FL_BSM_SOT_WALL_DIFF;									/* �����ԁ|�Ǌԋ���臒l */
#if (BSM_OPTION_SW_ABST == TYPE_A)
/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
FL FL_BSM_WALL_OFF_GAIN;									/* Gain of wall flag reset */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */


/****************************************************************************/
/*							�X�^�e�B�b�N�ϐ��錾							*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�֐��錾							*/
/****************************************************************************/
VD fn_bsm_abst_read_yomikae_table( U1 u1_a_sns_pos );		/* ���ʓǂݑւ��e�[�u����ݒ肷�� */
VD fn_bsm_abst_read_data_by_bsmdest( VD );		/* �d�������ؑփf�[�^�̐ݒ� */
VD fn_bsm_abst_read_dataA_by_bsmdest( VD );		/* ����a���̒l��ݒ肷�� */
VD fn_bsm_abst_read_dataB_by_bsmdest( VD );		/* ����b���̒l��ݒ肷�� */

VD fn_bsm_abst_cal_data( VD );					/* �t���b�V���l�A�d�������f�[�^���g���ăf�[�^�l�Z�o */

/****************************************************************************/
/*									���ӎ���								*/
/****************************************************************************/
/* �x�񒆃t���O�̐ݒ�֐�u1_bsm_set_alarming_flag�͊֐��̌��ʂ����悭���邽�� */
/* bsm_main.c�ɒ�`���Ă���													  */

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_init_data														*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			:																			*/
/*																							*/
/* ����			: �{�֐��́AEEPROM�̃f�[�^���g�p���邽�߁Afn_init_eeprom()�̌�ɌĂяo����	*/
/*				  u1_g_eep_bsm_dest �̊m���ł��悢�B										*/
/*------------------------------------------------------------------------------------------*/
/* ����			: 																			*/
/* �߂�l		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_init_data( VD )
{
	/* 1. �t���b�V���l�̓ǂݍ��� */
	fn_bsm_abst_read_flashdata(u1_g_sns_pos);

	/* 2. �d�������ؑփf�[�^�̐ݒ� */
	fn_bsm_abst_read_data_by_bsmdest();

	/* 1. �t���b�V���l�A2. �d�������f�[�^ �̐ݒ�l���g���ăf�[�^���Z�o���� */
	fn_bsm_abst_cal_data();

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_read_flashdata												*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* ����			: 																			*/
/* �߂�l		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_flashdata( U1 u1_a_sns_pos )
{
	U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH = CU2_D_CAR_WIDTH;						/* �ԕ�	1mm */

	if (u1_a_sns_pos == SENSOR_RIGHT) { 	/* RIGHT */
		U4_BSM_FLSH_DELTA_W		= CU4_D_RIGHT_MOUNT_OFFSET_W;				/* �E�p���t���ʒu�̾�ă�W	1mm	�ԕ��`BSM���h�����S */
		U4_BSM_FLSH_FLASH_ANGLE	= CU4_D_RIGHT_MOUNT_OFFSET_ANG;				/* �E�p���t���p�x	0.1deg	�ԗ����ʂƃZ���T�̂Ȃ��p */
		U4_BSM_FLSH_DELTA_L		= CU4_D_RIGHT_MOUNT_OFFSET_L;				/* �E�p���t���ʒu�̾�ă�L 1mm Rr�o���p��[�`BSM���h�����S */
	}

	else {									/* LEFT */
		U4_BSM_FLSH_DELTA_W		= CU4_D_LEFT_MOUNT_OFFSET_W;				/* ���p���t���ʒu�̾�ă�W	1mm	�ԕ��`BSM���h�����S */
		U4_BSM_FLSH_FLASH_ANGLE	= CU4_D_LEFT_MOUNT_OFFSET_ANG;				/* ���p���t���p�x	0.1deg	�ԗ����ʂƃZ���T�̂Ȃ��p */
		U4_BSM_FLSH_DELTA_L		= CU4_D_LEFT_MOUNT_OFFSET_L;				/* ���p���t���ʒu�̾�ă�L 1mm Rr�o���p��[�`BSM���h�����S */
	}

	FL_BSM_FLSH_AXIS_DEFAULT	= 90.0F - ((FL)U4_BSM_FLSH_FLASH_ANGLE/10.0F);												/* �Z���T��t�p�x�ݒ� */
	/* �d�l Q&A No.697, 698 */
	/* �l�̌ܓ�(0.5 ���Z��ɁAS4�փL���X�g)���� */
	S4_BSM_FLSH_AXIS_DEFAULT	= s4_cast_from_fl(FL_BSM_FLSH_AXIS_DEFAULT + 0.5F);

	 /* ���ʓǂݑւ��e�[�u���ǂݏo�� */
	fn_bsm_abst_read_yomikae_table(u1_a_sns_pos);

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_read_yomikae_table											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* ����			: 																			*/
/* �߂�l		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_yomikae_table( U1 u1_a_sns_pos )
{
	U1 u1_t_lp_yomikae_table;
	
	if (u1_a_sns_pos == SENSOR_LEFT) { 	/* LEFT */
		for (u1_t_lp_yomikae_table = (U1)0; u1_t_lp_yomikae_table < (U1)YOMIKAE_TABLE_SIZE; u1_t_lp_yomikae_table++) {
			FL_BSM_FLSH_YOMIKAE_TBL_FM[YOMIKAE_TABLE_SIZE - u1_t_lp_yomikae_table - (U1)1] = (FL)180.0 - CAFL_D_YOMIKAE_TABLE_FM[u1_t_lp_yomikae_table];
			FL_BSM_FLSH_YOMIKAE_TBL_2F[YOMIKAE_TABLE_SIZE - u1_t_lp_yomikae_table - (U1)1] = (FL)180.0 - CAFL_D_YOMIKAE_TABLE_2F[u1_t_lp_yomikae_table];
		}
	} else {
		for (u1_t_lp_yomikae_table = (U1)0; u1_t_lp_yomikae_table < (U1)YOMIKAE_TABLE_SIZE; u1_t_lp_yomikae_table++) {
			FL_BSM_FLSH_YOMIKAE_TBL_FM[u1_t_lp_yomikae_table] = CAFL_D_YOMIKAE_TABLE_FM[u1_t_lp_yomikae_table];
			FL_BSM_FLSH_YOMIKAE_TBL_2F[u1_t_lp_yomikae_table] = CAFL_D_YOMIKAE_TABLE_2F[u1_t_lp_yomikae_table];
		}
	}
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_read_data_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			:																			*/
/*																							*/
/*------------------------------------------------------------------------------------------*/
/* ����			: 																			*/
/* �߂�l		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_read_data_by_bsmdest( VD )
{
	U1 u1_t_bsm_bsd_zone_y_max;
	
	/* EEPROM�i�[�l BSM_DEST �ɂ���Đݒ�l��؂�ւ��� */
	FL_BSM_ALT_ON_SPEED = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].fl_ON_ACT_SPEED_BSM;
	FL_BSM_ALT_OFF_SPEED = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].fl_OFF_ACT_SPEED_BSM;
	
	/* BSD_ZONE_Y_MAX�𐮐��l�Ŕ�r���邽�߂�LSB�ϊ��O�Ƀ��[�J���ϐ��Ɉ�U���b�`���� */
	u1_t_bsm_bsd_zone_y_max = CAST_D_DEST_PARAMETER[CU1_DF_VEHICLE_SELECT][u1_g_eep_bsm_dest].u1_Warning_zone;
	
	if (u1_t_bsm_bsd_zone_y_max == CU1_DF_BSD_ZONE_WIDE) {
		/* ����a �̒l��ݒ肷�� */
		fn_bsm_abst_read_dataA_by_bsmdest();
	} else {
		/* ����b �̒l��ݒ肷�� */
		fn_bsm_abst_read_dataB_by_bsmdest();
	}
	
	/* BSD_ZONE_Y_MAX��LSB�ϊ� */
	FL_BSM_FLSH_BSD_ZONE_Y_MAX = (FL)u1_t_bsm_bsd_zone_y_max * (FL)0.1F;

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_read_dataA_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �d�����ɂ���Đݒ肳���p�����[�^�̒l�ݒ�(����a)							*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>		: �Ȃ�																		*/
/* <output>		: FL_BSM_FLSH_ALARM_X_OFFSET_IN				: �x��̈�I�t�Z�b�g (���[) 	*/
/*				: FL_BSM_FLSH_ALARM_X_OFFSET_OUT			: �x��̈�I�t�Z�b�g (�O�[)		*/
/*				: FL_BSM_FLSH_ALARM_Y_OFFSET				: �x��̈�I�t�Z�b�g (��[)		*/
/*				: FL_BSM_FLSH_ALARM_OFFSET_TIME				: �x�񎞊ԃI�t�Z�b�g			*/
/*				: FL_BSM_FLSH_EKF_RY_SIDE					: �^������͈�					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH				: �ԗ���[�d��臒l				*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_DIFF			: �ԗ���[�d�͍�臒l			*/
/*				: FL_BSM_VI_TOS_END_ERASE_LIMIT				: ToS �����͈�					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH2				: �ԗ���[�d��臒l�Q			*/
/*				: FL_BSM_TRUCK_WIDTH						: �ׯ���ċ���(X ����)			*/
/*				: FL_BSM_SOT_WALL_DIFF						: �����ԁ|�Ǌԋ���臒l			*/
/*				: FL_BSM_WALL_OFF_GAIN						: Gain of wall flag reset		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: G.Jomori																	*/
/*------------------------------------------------------------------------------------------*/
/* ���ӁF���̊֐���ύX�����ꍇ��fn_bsm_abst_read_dataB_by_bsmdest�֐����ύX���邱��		*/
/********************************************************************************************/
VD fn_bsm_abst_read_dataA_by_bsmdest( VD )
{
	FL_BSM_FLSH_ALARM_X_OFFSET_IN	= CFL_D_BSM_ALARM_X_OFFSET_IN_WIDE;			/* �x��̈�I�t�Z�b�g (���[) */
	FL_BSM_FLSH_ALARM_X_OFFSET_OUT	= CFL_D_BSM_ALARM_X_OFFSET_OUT_WIDE;		/* �x��̈�I�t�Z�b�g (�O�[) */
	FL_BSM_FLSH_ALARM_Y_OFFSET		= CFL_D_BSM_ALARM_Y_OFFSET_WIDE;			/* �x��̈�I�t�Z�b�g (��[) */
	FL_BSM_FLSH_ALARM_OFFSET_TIME	= CFL_D_BSM_ALARM_OFFSET_TIME_WIDE;			/* �x�񎞊ԃI�t�Z�b�g */
	FL_BSM_FLSH_EKF_RY_SIDE			= CFL_D_BSM_EKF_RY_SIDE_WIDE;				/* �^������͈� */
	FL_BSM_VI_TOS_END_FFT_POW_TH	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH_WIDE;		/* �ԗ���[�d��臒l */
	FL_BSM_VI_TOS_END_FFT_POW_DIFF	= CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_WIDE;	/* �ԗ���[�d�͍�臒l */
	FL_BSM_VI_TOS_END_ERASE_LIMIT	= CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_WIDE;	/* ToS �����͈� */
	FL_BSM_VI_TOS_END_FFT_POW_TH2	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_WIDE;	/* �ԗ���[�d��臒l�Q */
	FL_BSM_TRUCK_WIDTH				= CFL_D_BSM_TRUCK_WIDTH_WIDE;				/* �ׯ���ċ���(X ����) */
	FL_BSM_SOT_WALL_DIFF			= CFL_D_BSM_SOT_WALL_DIFF_WIDE;				/* �����ԁ|�Ǌԋ���臒l */
#if (BSM_OPTION_SW_ABST == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
	FL_BSM_WALL_OFF_GAIN			= CFL_D_BSM_WALL_OFF_GAIN_WIDE;				/* Gain of wall flag reset */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_read_dataB_by_bsmdest											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �d�����ɂ���Đݒ肳���p�����[�^�̒l�ݒ�(����b)							*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>		: �Ȃ�																		*/
/* <output>		: FL_BSM_FLSH_ALARM_X_OFFSET_IN				: �x��̈�I�t�Z�b�g (���[) 	*/
/*				: FL_BSM_FLSH_ALARM_X_OFFSET_OUT			: �x��̈�I�t�Z�b�g (�O�[)		*/
/*				: FL_BSM_FLSH_ALARM_Y_OFFSET				: �x��̈�I�t�Z�b�g (��[)		*/
/*				: FL_BSM_FLSH_ALARM_OFFSET_TIME				: �x�񎞊ԃI�t�Z�b�g			*/
/*				: FL_BSM_FLSH_EKF_RY_SIDE					: �^������͈�					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH				: �ԗ���[�d��臒l				*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_DIFF			: �ԗ���[�d�͍�臒l			*/
/*				: FL_BSM_VI_TOS_END_ERASE_LIMIT				: ToS �����͈�					*/
/*				: FL_BSM_VI_TOS_END_FFT_POW_TH2				: �ԗ���[�d��臒l�Q			*/
/*				: FL_BSM_TRUCK_WIDTH						: �ׯ���ċ���(X ����)			*/
/*				: FL_BSM_SOT_WALL_DIFF						: �����ԁ|�Ǌԋ���臒l			*/
/*				: FL_BSM_WALL_OFF_GAIN						: Gain of wall flag reset		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: G.Jomori																	*/
/*------------------------------------------------------------------------------------------*/
/* ���ӁF���̊֐���ύX�����ꍇ��fn_bsm_abst_read_dataA_by_bsmdest�֐����ύX���邱��		*/
/********************************************************************************************/
VD fn_bsm_abst_read_dataB_by_bsmdest( VD )
{
	FL_BSM_FLSH_ALARM_X_OFFSET_IN	= CFL_D_BSM_ALARM_X_OFFSET_IN_NARROW;			/* �x��̈�I�t�Z�b�g (���[) */
	FL_BSM_FLSH_ALARM_X_OFFSET_OUT	= CFL_D_BSM_ALARM_X_OFFSET_OUT_NARROW;			/* �x��̈�I�t�Z�b�g (�O�[) */
	FL_BSM_FLSH_ALARM_Y_OFFSET		= CFL_D_BSM_ALARM_Y_OFFSET_NARROW;				/* �x��̈�I�t�Z�b�g (��[) */
	FL_BSM_FLSH_ALARM_OFFSET_TIME	= CFL_D_BSM_ALARM_OFFSET_TIME_NARROW;			/* �x�񎞊ԃI�t�Z�b�g */
	FL_BSM_FLSH_EKF_RY_SIDE			= CFL_D_BSM_EKF_RY_SIDE_NARROW;					/* �^������͈� */
	FL_BSM_VI_TOS_END_FFT_POW_TH	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH_NARROW;		/* �ԗ���[�d��臒l */
	FL_BSM_VI_TOS_END_FFT_POW_DIFF	= CFL_D_BSM_VI_TOS_END_FFT_POW_DIFF_NARROW;		/* �ԗ���[�d�͍�臒l */
	FL_BSM_VI_TOS_END_ERASE_LIMIT	= CFL_D_BSM_VI_TOS_END_ERASE_LIMIT_NARROW;		/* ToS �����͈� */
	FL_BSM_VI_TOS_END_FFT_POW_TH2	= CFL_D_BSM_VI_TOS_END_FFT_POW_TH2_NARROW;		/* �ԗ���[�d��臒l�Q */
	FL_BSM_TRUCK_WIDTH				= CFL_D_BSM_TRUCK_WIDTH_NARROW;					/* �ׯ���ċ���(X ����) */
	FL_BSM_SOT_WALL_DIFF			= CFL_D_BSM_SOT_WALL_DIFF_NARROW;				/* �����ԁ|�Ǌԋ���臒l */
#if (BSM_OPTION_SW_ABST == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_ABST == TYPE_B)
	FL_BSM_WALL_OFF_GAIN			= CFL_D_BSM_WALL_OFF_GAIN_NARROW;				/* Gain of wall flag reset */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_ABST */

	return;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_abst_cal_data														*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			:																			*/
/*																							*/
/*																							*/
/* ����			: �{�֐��́A���L�֐��𗼎҂Ƃ��Ăяo������ɃR�[�����鎖					*/
/*				  fn_bsm_abst_read_flashdata,  fn_bsm_abst_read_data_by_bsmdest				*/
/*------------------------------------------------------------------------------------------*/
/* ����			: 																			*/
/* �߂�l		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>																					*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �쐬��		: 																			*/
/********************************************************************************************/
VD fn_bsm_abst_cal_data( VD )
{
	FL_BSM_FLSH_ALARM_X_IN		= ((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH / 1000.0F) / (FL)2 + 0.5F;							/* �x��͈� (���[) */
	FL_BSM_FLSH_ALARM_X_OUT		= ((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH / 1000.0F) / (FL)2 + FL_BSM_FLSH_BSD_ZONE_Y_MAX;	/* �x��̈� (�O�[) */


	if (S4_BSM_FLSH_AXIS_DEFAULT  == (S4)70) {
		S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2	= CS4_D_SOT_CHECK_CYCLE_FWD2_70;
		S4_BSM_FLSH_SOT_FIND_CYCLE			= CS4_D_SOT_FIND_CYCLE_70;

		S4_BSM_FLSH_SOT_CYCLE_TH_FWD		= CS4_D_SOT_CYCLE_TH_FWD_70;
		S4_BSM_FLSH_SOT_CYCLE_TH_BWD		= CS4_D_SOT_CYCLE_TH_BWD_70;
		S4_BSM_FLSH_SOT_CYCLE_TH_FWD2		= CS4_D_SOT_CYCLE_TH_FWD2_70;

		S4_BSM_FLSH_SOT_POINT_TH_FWD		= CS4_D_SOT_POINT_TH_FWD_70;
		S4_BSM_FLSH_SOT_POINT_TH_BWD		= CS4_D_SOT_POINT_TH_BWD_70;
	} else {
		S4_BSM_FLSH_SOT_CHECK_CYCLE_FWD2	= CS4_D_SOT_CHECK_CYCLE_FWD2_OTH;
		S4_BSM_FLSH_SOT_FIND_CYCLE			= CS4_D_SOT_FIND_CYCLE_OTH;

		S4_BSM_FLSH_SOT_CYCLE_TH_FWD		= CS4_D_SOT_CYCLE_TH_FWD_OTH;
		S4_BSM_FLSH_SOT_CYCLE_TH_BWD		= CS4_D_SOT_CYCLE_TH_BWD_OTH;
		S4_BSM_FLSH_SOT_CYCLE_TH_FWD2		= CS4_D_SOT_CYCLE_TH_FWD2_OTH;

		S4_BSM_FLSH_SOT_POINT_TH_FWD		= CS4_D_SOT_POINT_TH_FWD_OTH;
		S4_BSM_FLSH_SOT_POINT_TH_BWD		= CS4_D_SOT_POINT_TH_BWD_OTH;
	}

	return;
}

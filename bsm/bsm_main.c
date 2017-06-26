/****************************************************************************/
/* �t�@�C����	: BSM_MAIN.c												*/
/*--------------------------------------------------------------------------*/
/* ���W���[����	: BSM���C�����[�`��											*/
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
/*  9/17�� BSM�ŐV�d�l�}�[�W�A�y�� ���t�@�N�^�����O							*/
/*	t02					14.10.29			�����Z1 1�Z�� D.Saburi			*/
/*  ����A���Y�������ǉ�													*/
/*	t03 				14.10.30			�����Z1 1�Z�� K.Kato			*/
/*	AUDR BSM�F���f�[�^���b�`�����ǉ�										*/
/*	t04 				14.10.30			�����Z1 1�Z�� D.Saburi			*/
/*	�w�E�����A�d�l�񓚏C��													*/
/*	t05 				14.10.31			�����Z1 1�Z�� D.Saburi			*/
/*	�b��t�@�C���̍폜�Ή�													*/
/*	t06 				14.11.03			�����Z1 1�Z�� K.Kato			*/
/*	MWR-RECO-24G-BSM-ABST-00-009 �K���f�[�^�������Ή�						*/
/*	t07 				14.11.03			�����Z1 1�Z�� D.Saburi			*/
/*	DR�w�E�����C��															*/
/*	t08					14.11.03			�����Z1 1�Z�� K.Kato			*/
/*	�d�lQ&A No.697, 698�Ή�													*/
/*	t09					14.11.07			�����Z1 1�Z�� K.Kato			*/
/*	�c�ۑ� No.153�Ή�														*/
/*	t10					15.01.09			�����Z2 1�Z�� G.Jomori			*/
/*	���g�΍� MWR-RECO-24G-INTERFERENCE-REDUCTION-01-003�Ή�				*/
/*	t11					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���֑Ή�															*/
/*	t12					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �d�l�m�F���ڑΉ�												*/
/*	t13					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�Ή�(OBJ�ύX����)												*/
/*	t14					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t15					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�đΉ�(OBJ�ύX�Ȃ�)												*/
/*	t16					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No164�Ή�															*/
/*	t19					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t20					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t21					15.08.19			�����Z2 1�Z�� G.Jomori			*/
/*	AUDR BSM�������q����													*/
/*	t22					15.08.31			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1501�Ή�														*/
/*	t23					15.10.23			�����Z2 1�Z�� M.Tanaka			*/
/*	�c�ۑ�No.849�Ή�(�Öق̃L���X�g���C��)									*/
/*	t24					15.11.16			�����Z2 1�Z�� Y.Nishioka		*/
/*	�c�ۑ�No.235�Ή�(�C���f���g�C��)		��OBJ�ύX�Ȃ�					*/
/*	t25					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV�Ή�																*/
/*	t26					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �x�񔻒菈����S�Čx�񔻒�̃��C���֐�����R�[������				*/
/*	t27					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)										*/
/*	t28					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)		*/
/*	t29					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t30					16.04.07			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC �w�E�Ή�														*/
/*	t31					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t32					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t33					16.06.20			�����Z2 1�Z�� H.Nonogaki		*/
/*	QAC �w�E�Ή�(OBJ�ύX����)												*/
/*	t34					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t38					16.08.01			�����Z2 1�Z�� Y.Nishioka		*/
/*	310B_CV LCA��ǉ�														*/
/*	t41					16.08.24			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �F������(BSM,RCTA,AUDR)�}�[�W									*/
/*	t43					17.02.02			����Z2 1�Z�� G.Jomori			*/
/*	310B BSM ���}����d�l�Ή�												*/
/*	t44					17.03.02			����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1480�Ή�(�萔�̐��������Ɋ��ʕt�^ OBJ�ύX�Ȃ� h�t�@�C���ύX)	*/
//****************************************************************************/

/****************************************************************************/
/*							�C���N���[�h�t�@�C��							*/
/****************************************************************************/
#include "inc_bsm.h"				/* �O���[�o���ϐ��pdefine�Q�� */
//#include "parameter_def.h"
#include "parameter_adj.h"
//#include "normal_def.h"

#include "../common/cmn_signal.h"
#include "target/init_cvw.h"
#include "target/bsm_recog_01.h"
#include "target/bsm_recog_02.h"
#include "target/bsm_recog_03.h"
#include "target/bsm_recog_04.h"
#include "target/bsm_connect_01.h"
#include "app_alarm/bsm_alarm_01.h"

#if !defined( _291B_DEV_20161005_BTT_TEST)
#include "btt/bsm_btt.h"
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
#include "target/bsm_recog_05.h"
#endif

#include "bsm_main.h"

#include "../../common/inc_mwr.h"

#ifdef _DIRECTIVITY_TEST	// for directivity check
#include "../../recog/bsm\target\func_fmcw.h"
#endif


#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif /*VI �\���p*/

/****************************************************************************/
/*							�}�N����`										*/
/****************************************************************************/

/****************************************************************************/
/*							�\���̒�`										*/
/****************************************************************************/

/****************************************************************************/
/*							�X�^�e�B�b�N�ϐ��錾							*/
/****************************************************************************/
BSM_LOOP_DATA st_g_bsm_loop_data;			/* ��{�f�[�^ */

/****************************************************************************/
/* �Q�ƃO���[�o���ϐ�(�b��)													*/
/****************************************************************************/

#if (MODE_ECU_SIM == SIM_MODE)
FL fl_g_wall_dev;											/* SIM�o�͗p�f�[�^ */
FL afl_g_Tx_float[TARGET_BUFFSIZE][4];						/* SIM�o�͗p�f�[�^ */
#endif

#if (MODE_ECU_SIM == SIM_MODE)
extern FL fl_g_simm_bsm_auto_axis;
#endif


/****************************************************************************/
/*							�X�^�e�B�b�N�֐��錾							*/
/****************************************************************************/

VD fn_bsm_nbd_input_recog_data( 
	BSM_OUT_DATA *pst_a_out_data,
	S4 s4_a_pair_num_sot,
	S4 s4_a_truck_flg
);

VD fn_bsm_set_low_speed_flg(VD);
U1 u1_bsm_set_alarming_flag(VD);


/********************************************************************************************/
/* �֐���		: fn_bsm_main()																*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: BSM���C���֐�																*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	:								 											*/
/* <output>		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/

VD fn_bsm_main(VD)
{

/****************************************************************************/
/* �f�[�^�錾																*/
/****************************************************************************/
	/***** �g�p����f�[�^�\�� ***************************************************/
	BSM_OUT_DATA st_t_out_data;

	S4 s4_t_pair_num_sot = 0;

	/***** �p�����[�^�ݒ�ϐ� ***************************************************/
	FL afl_t_sot_detect_param[9];
	FL afl_t_tos_end_param[6];

	/***** CAN�o�͗p�ϐ� ********************************************************/
	U1 u1_t_1byte_data[2];
	S2 s2_t_2byte_data;

	/***** �⏕���W�F�������p�ϐ� ***********************************************/
	FL afl_t_wall_width[1];

	S4 s4_t_flg_bsm_map;
	
	FL fl_t_tmp_frontline_pow_dn;
	S4 as4_t_frontline_doa_dn[LINE_FREQ_BIN_RANGE][1];
	S4 as4_t_froneline_doa_peak_num_dn[LINE_FREQ_BIN_RANGE];

	U1 u1_t_alarming_flag;

#ifdef _DIRECTIVITY_TEST	// for directivity check
	S4 i,j;
	S4 s4_t_target_bin = 280;//68;
	FL fl_t_spec_bf[2][N_DOA] = {0.0F};
	S4 s4_t_peak_bin[2][WAVE_NUMBER_MAX]= {0};
	FL fl_t_peak_power[2][WAVE_NUMBER_MAX]= {0.0F};
	FL fl_t_peak_bin[2][WAVE_NUMBER_MAX]= {0.0F};
#endif

#if !defined( _291B_DEV_20161005_BTT_TEST)
	/* for test */
	U1 u1_t_btt_alarm_flag_for_test;
	NORMAL_BSM ast_t_btt_target_for_test[TARGET_BUFFSIZE];
	S4 s4_t_btt_target_size;
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20170119_ATD_DOADBF_CHECK)
	FL fl_t_doa_pow_ave[2][3];
	FL fl_t_doa_pow_dev[2][3];
	S4 s4_t_doa_bf_peak_bin;
	FL fl_t_doa_bf_peak_pow;
#endif
/****************************************************************************/
/* �f�[�^������																*/
/****************************************************************************/
#if (MODE_ECU_SIM == ECU_MODE)
	/***** ���ԏ������Ԍv���p ***************************************************/
	/* S4��U1�̃_�E���L���X�g�ł��邪�A�l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_connect_pre_pair_num = (U1)st_g_bsm_loop_data.as4_buf_pair_num[0];			/* CheckPoint �O�����̕��W�� */
	u1_g_bsm_connect_pre_target_num = (U1)st_g_bsm_loop_data.as4_buf_pair_num[1];		/* CheckPoint �O�����̃^�[�Q�b�g�� */
#endif

	/***** �g�p����f�[�^�\�� ***************************************************/
	fn_out_data_initialize(&st_t_out_data);

	/***** �p�����[�^�ݒ�ϐ� ***************************************************/
	afl_t_sot_detect_param[0] = 0.0F;
	afl_t_sot_detect_param[1] = 0.0F;
	afl_t_sot_detect_param[2] = SLOW_SOT_V0_DOA;
	afl_t_sot_detect_param[3] = 0.0F;
	afl_t_sot_detect_param[4] = 0.0F;
	afl_t_sot_detect_param[5] = 0.0F;
	afl_t_sot_detect_param[6] = 0.0F;
	afl_t_sot_detect_param[7] = 0.0F;
	afl_t_sot_detect_param[8] = 0.0F;

	/*** ToS�I�����o�p�����[�^ ***/
	afl_t_tos_end_param[0] = VI_TOS_END_FREQ_BIN;
	afl_t_tos_end_param[1] = VI_TOS_END_FFT_POW_TH;
	afl_t_tos_end_param[2] = VI_TOS_END_FFT_POW_DIFF;
	afl_t_tos_end_param[3] = VI_TOS_END_ERASE_LIMIT;
	afl_t_tos_end_param[4] = VI_TOS_END_FFT_POW_TH2;		/* _20131214_3 */
	afl_t_tos_end_param[5] = CFL_VI_TOS_END_FFT_POW_DIFF2;	/* _20131214_3 */

	fl_t_tmp_frontline_pow_dn = (FL)0.0F;

	as4_t_frontline_doa_dn[0][0] = (S4)0;
	as4_t_frontline_doa_dn[1][0] = (S4)0;
	as4_t_frontline_doa_dn[2][0] = (S4)0;
	as4_t_frontline_doa_dn[3][0] = (S4)0;
	as4_t_frontline_doa_dn[4][0] = (S4)0;

	as4_t_froneline_doa_peak_num_dn[0] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[1] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[2] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[3] = (S4)0;
	as4_t_froneline_doa_peak_num_dn[4] = (S4)0;

	afl_t_wall_width[0] = (FL)0.0F;

	/* �ᑬ���s�t���O�ݒ� */
	fn_bsm_set_low_speed_flg();

	/* �x�񒆃t���O�̐ݒ� */
	u1_t_alarming_flag = u1_bsm_set_alarming_flag();

#ifdef _DIRECTIVITY_TEST	// for directivity check
	// UP
	fn_calc_spec_bf_4ch_fm(
		afl_g_cvw_lfm_ryy_matrix[0][s4_t_target_bin],
			fl_t_spec_bf[0],
			0,
			s4_t_target_bin
	);
	s4_search_peak_bf(
		fl_t_spec_bf[0],		// [in]
		s4_t_peak_bin[0],		// [out]
		fl_t_peak_power[0],		// [out]
		1						// [in]
	);
	fl_t_peak_bin[0][0] = fl_interpolate_music_peak(
		fl_t_spec_bf[0],
		s4_t_peak_bin[0][0],
		FL_BSM_FLSH_YOMIKAE_TBL_FM
	);
	// DN
	fn_calc_spec_bf_4ch_fm(
		afl_g_cvw_lfm_ryy_matrix[1][s4_t_target_bin],
			fl_t_spec_bf[1],
			1,
			s4_t_target_bin
	);
	s4_search_peak_bf(
		fl_t_spec_bf[1],		// [in]
		s4_t_peak_bin[1],		// [out]
		fl_t_peak_power[1],		// [out]
		1						// [in]
	);
	fl_t_peak_bin[1][0] = fl_interpolate_music_peak(
		fl_t_spec_bf[1],
		s4_t_peak_bin[1][0],
		FL_BSM_FLSH_YOMIKAE_TBL_FM
	);
	for(i=0; i<2; i++)
	{
		for(j=0; j<WAVE_NUMBER_MAX; j++)
		{
			afl_g_peak_power_directivity[i][j] = fl_t_peak_power[i][j];
			afl_g_peak_bin_directivity[i][j] = fl_t_peak_bin[i][j];
		};
	};
#else	// else of _DIRECTIVITY_TEST

#if !defined( _291B_DEV_20161005_BTT_TEST)
	/* for test */
	/* NOTE: These parameters should be set once at the beginning of the whole process ( out of bsm_main() ) */
	init_btt_configuration_parameter_dummy(
		&st_g_bsm_alertarea_for_test,
		&st_g_cluster_info_for_test,
		&st_g_aux_trailer_info_for_test,
		&st_g_hitch_angle_for_test
	);
	u1_t_btt_alarm_flag_for_test = (U1) 0;
	fn_init(ast_t_btt_target_for_test, TARGET_BUFFSIZE);
	s4_t_btt_target_size = (S4) 0;
#endif
#if !defined( _291B_DEV_20161005_BTT_TEST) && !defined(_20170119_ATD_DOADBF_CHECK)
	fl_t_doa_pow_ave[0][0] = (FL)0;
	fl_t_doa_pow_ave[0][1] = (FL)0;
	fl_t_doa_pow_ave[0][2] = (FL)0;
	fl_t_doa_pow_ave[1][0] = (FL)0;
	fl_t_doa_pow_ave[1][1] = (FL)0;
	fl_t_doa_pow_ave[1][2] = (FL)0;
	fl_t_doa_pow_dev[0][0] = (FL)0;
	fl_t_doa_pow_dev[0][1] = (FL)0;
	fl_t_doa_pow_dev[0][2] = (FL)0;
	fl_t_doa_pow_dev[1][0] = (FL)0;
	fl_t_doa_pow_dev[1][1] = (FL)0;
	fl_t_doa_pow_dev[1][2] = (FL)0;
	s4_t_doa_bf_peak_bin = (S4)-1;
	fl_t_doa_bf_peak_pow = (FL)0;
#endif

/****************************************************************************/
/* �F������																	*/
/****************************************************************************/

	/* MWR-RECO-24G-BSM-ALART-01-006��(6)�x��G���A�O�[�Ď�����		*/
	/* 5)�x��G���A�O�[�̕��W���o��Ԃ̊m�F��						*/
	/* (ii)�x��G���A�O�[���C���i�ԗ���[����bin�j�̕��ʊm�F���{	*/
	calc_front_1m_line(
		&fl_t_tmp_frontline_pow_dn,
		(const FL (*))afl_t_tos_end_param,
		as4_t_frontline_doa_dn,
		as4_t_froneline_doa_peak_num_dn
	);

/* FMCW�Ŋ��ߑ��ɂ�鍡�T�C�N���X�L�b�v������Ε��W���o���W�b�N�X�L�b�v */
#ifdef _USE_INTERFERENCE_SKIP
if(au4_g_interference_skipcount[0] == 0)
#endif
{	
/****************************************************************************/
/* �Q�|x�D �ᑬ�r���s(V0.3�Œǉ������@�\)                                 */
/****************************************************************************/
#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(24, &au2_g_bsm_check_tmr[24]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */
	/* [SEQ:2]���W���o�i�ᑬSoT�j */
#if (MODE_ECU_SIM == SIM_MODE)
	fl_g_wall_dev = fl_seek_low_speed_sot(
#else
					fl_seek_low_speed_sot(
#endif
						(const FL *)afl_t_sot_detect_param,		/* [in] */
						u1_t_alarming_flag
					);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(25, &au2_g_bsm_check_tmr[25]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

/****************************************************************************/
/* �Q�|�R�D �O�������W�F������                                              */
/****************************************************************************/
	/* [SEQ:3]���W���o�iSoT�j */
	s4_t_pair_num_sot = s4_seek_sidewinder(
							st_g_bsm_loop_data.ast_normal_wall,		/* [in/out] */
							st_g_bsm_loop_data.ast_normal_sot		/* [in/out] */
						);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(26, &au2_g_bsm_check_tmr[26]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

/****************************************************************************/
/* �Q�|�P�D �D�敨�W�F������                                                */
/****************************************************************************/
	/* [SEQ:4]���W���o�i�D��j */
	fn_bsm_seek_prior_object(
		&st_t_out_data.s4_pair_num_prior,
		st_t_out_data.ast_normal_prior						/* [in/out] */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(27, &au2_g_bsm_check_tmr[27]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* �Q�|�Q�D �ʏ함�W�F������                                                */
/****************************************************************************/
	/* [SEQ:5]���W���o�i�ʏ�j */
	fn_bsm_seek_ordinary_object(
		&st_t_out_data.s4_pair_num_ordinary,
	 	st_t_out_data.ast_normal_ordinary					/* [in/out] */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(30, &au2_g_bsm_check_tmr[30]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* �Q�|�S�D �⏕���W�F������                                                */
/****************************************************************************/
	/* [SEQ:6]���W���o�i2���g�j */
	afl_t_wall_width[0] = WALL_MAX + 4.0F;

	fn_bsm_seek_2f_object(
		&st_t_out_data.s4_pair_num_2f,
		st_t_out_data.ast_normal_2f,
		u1_t_alarming_flag
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(31, &au2_g_bsm_check_tmr[31]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

}	/* if(au4_g_interference_skipcount[0] == 0){ ��END�� */


#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
/****************************************************************************/
/* �Q�|�T�D Trailer Object Detection                                        */
/****************************************************************************/
#ifndef _20170220_BTT_TRAILEROBJ
	if( st_g_btt_stat.BTT_drv == BTT_RET_t.Drv_Stat.CONNECT
	||  st_g_btt_stat.ATD == BTT_RET_t.Func_Stat.ACTIVE ){
#endif
		fn_bsm_seek_trailer_object(
			&st_t_out_data.s4_pair_num_ordinary,
	 		st_t_out_data.ast_normal_ordinary,
			&st_t_out_data.s4_pair_num_trailer
			,st_t_out_data.ast_normal_trailer
#ifndef _20170119_ATD_DOADBF_CHECK
			,fl_t_doa_pow_ave
			,fl_t_doa_pow_dev
			,&s4_t_doa_bf_peak_bin
			,&fl_t_doa_bf_peak_pow
#endif
		);
#ifndef _20170220_BTT_TRAILEROBJ
	}
#endif
#endif


/****************************************************************************/
/* �R�|�P�D ���W�I������                                                    */
/****************************************************************************/
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	s4_g_pair_num_prior = st_t_out_data.s4_pair_num_prior;
	memcpy (ast_g_normal_prior, st_t_out_data.ast_normal_prior, sizeof(NORMAL_BSM)*PRIOR_BUFFSIZE);
	s4_g_pair_num_ordinary = st_t_out_data.s4_pair_num_ordinary;
	memcpy (ast_g_normal_ordinary, st_t_out_data.ast_normal_ordinary, sizeof(NORMAL_BSM)*ORDINARY_BUFFSIZE);
	s4_g_pair_num_2f = st_t_out_data.s4_pair_num_2f;
	memcpy (ast_g_normal_2f, st_t_out_data.ast_normal_2f, sizeof(NORMAL_BSM)*AUX_BUFFSIZE);
	memcpy (ast_g_normal_sot, st_g_bsm_loop_data.ast_normal_sot, sizeof(NORMAL_BSM)*1);
	memcpy (ast_g_normal_wall, st_g_bsm_loop_data.ast_normal_wall, sizeof(NORMAL_BSM)*1);
#endif /*VI �\���p*/

	/* [SEQ:7]�g���b�L���O�E���W�I�� */
	st_g_bsm_loop_data.s4_final_target_num = s4_bsm_connect(
		/* �D�敨�W */
		st_t_out_data.s4_pair_num_prior,
		st_t_out_data.ast_normal_prior,
		/* �ʏ함�W */
		st_t_out_data.s4_pair_num_ordinary,
		st_t_out_data.ast_normal_ordinary,
		/* �⏕���W */
		st_t_out_data.s4_pair_num_2f,
		(const NORMAL_BSM (*))st_t_out_data.ast_normal_2f,
		/* �O�������W */
		s4_t_pair_num_sot,
		st_g_bsm_loop_data.ast_normal_sot,

		st_t_out_data.as4_Tx_int,
		st_t_out_data.afl_Tx_float,

		u1_t_alarming_flag
/* $$$ 2013.11.1 �O�������W�����W��������Ă���̂ł����Œǉ�����K�v�͂Ȃ� */
	);

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(32, &au2_g_bsm_check_tmr[32]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */




#if !defined( _291B_DEV_20161005_BTT_TEST)
/****************************************************************************/
/* BTT				                                                        */
/****************************************************************************/
	/* for test */
	/* fn_btt_initialize() and fn_btt_main() should be called in proper step */
	/* just a note: may need "seek_trailer_object()" or something for input object data in the future */
	enter_btt_dummy(
		/********** input **********/
		fl_g_v_self_bsm_for_base,
		s2_g_curvr_for_base,
		1,									/* (tentative) Shift = not R */
#ifndef _20161116_BTT_TRAILER_OBJ_FUNC_T
		st_t_out_data.ast_normal_trailer,	/* (tentative) Ordinary object */
		st_t_out_data.s4_pair_num_trailer,	/* (tentative) Ordinary object */
#else
		st_t_out_data.ast_normal_ordinary,	/* (tentative) Ordinary object */
		st_t_out_data.s4_pair_num_ordinary,	/* (tentative) Ordinary object */
#endif
#ifndef _20170119_ATD_DOADBF_CHECK
		fl_t_doa_pow_ave,
		fl_t_doa_pow_dev,
		s4_t_doa_bf_peak_bin,
		fl_t_doa_bf_peak_pow,
#endif
		BTT_DRV_SW_ON,						/* BTT SW = ON */
		&st_g_cluster_info_for_test,		/* (dummy) Trailer info selected by driver */
		&st_g_aux_trailer_info_for_test,	/* (dummy) Additional trailer or object info from other system or module */
		&st_g_hitch_angle_for_test,			/* (dummy) Angle between subject vehicle and trailer */

		/********** output **********/
		&u1_t_btt_alarm_flag_for_test,
		&ast_t_btt_target_for_test,
		s4_t_btt_target_size,
		&st_g_btt_stat
	);
#endif

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
	s4_g_pair_num_trailer = st_t_out_data.s4_pair_num_trailer;
	memcpy (ast_g_normal_trailer, st_t_out_data.ast_normal_trailer, sizeof(NORMAL_BSM)*TRAILER_BUFFSIZE);
#endif

/****************************************************************************/
/* �S�D �x�񔻒菈��                                                        */
/****************************************************************************/

	st_g_bsm_loop_data.s4_flg_alarm = s4_alarm_bsm2(
		st_g_bsm_loop_data.s4_final_target_num,
		st_t_out_data.as4_Tx_int,
		st_t_out_data.afl_Tx_float,
		u1_t_alarming_flag,
		(const FL (*))afl_t_tos_end_param,
		fl_t_tmp_frontline_pow_dn,
		as4_t_frontline_doa_dn,
		(const S4 (*))as4_t_froneline_doa_peak_num_dn
	);

	st_g_bsm_alarm_data.s4_alarm_prev = st_g_bsm_loop_data.s4_flg_alarm;
#endif		// end of _DIRECTIVITY_TEST

#if (MODE_ECU_SIM == SIM_MODE)
	{
		S4 s4_t_lp_i;
		for(s4_t_lp_i=0; s4_t_lp_i<TARGET_BUFFSIZE; s4_t_lp_i++) {
			afl_g_Tx_float[s4_t_lp_i][0] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][1] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][2] = CFL_UNKNOWN_VALUE;
			afl_g_Tx_float[s4_t_lp_i][3] = CFL_UNKNOWN_VALUE;
		}
		for(s4_t_lp_i=0; s4_t_lp_i < st_g_bsm_loop_data.s4_final_target_num; s4_t_lp_i++) {
			if(	st_t_out_data.afl_Tx_float[s4_t_lp_i][8] != CFL_UNKNOWN_VALUE ) {
				afl_g_Tx_float[s4_t_lp_i][0] = st_t_out_data.afl_Tx_float[s4_t_lp_i][8];		/* Rxfil */
				afl_g_Tx_float[s4_t_lp_i][1] = st_t_out_data.afl_Tx_float[s4_t_lp_i][7];		/* Ryfil */
				afl_g_Tx_float[s4_t_lp_i][2] = st_t_out_data.afl_Tx_float[s4_t_lp_i][14]*3.6F;	/* Vxfil [m/s]��[km/h] */
				afl_g_Tx_float[s4_t_lp_i][3] = st_t_out_data.afl_Tx_float[s4_t_lp_i][13]*3.6F;	/* Vyfil */
			}
		}
	}
#endif

#if (MODE_ECU_SIM == ECU_MODE)
		fn_bsm_nbd_input_recog_data(&st_t_out_data, s4_t_pair_num_sot, st_g_bsm_loop_data.u1_truck_flg);
#endif

	return ;

}

/********************************************************************************************/
/* �֐���		: fn_bsm_set_low_speed_flg													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �ᑬ���s�t���O�l�ݒ�														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ABST-00-011												*/
/********************************************************************************************/
VD fn_bsm_set_low_speed_flg(VD)
{
	if (fl_g_v_self_bsm_for_base < CFL_CANOUT_VSELF_MIN) {
		st_g_bsm_loop_data.as4_low_speed_flg[0] = 1;
	}
	if ((st_g_bsm_loop_data.as4_low_speed_flg[0] == 1)
	&&  (fl_g_v_self_bsm_for_base > CANOUT_VSELF_SLOW)) {
		st_g_bsm_loop_data.as4_low_speed_flg[0] = 0;
	}

	return;
}

/********************************************************************************************/
/* �֐���		: u1_bsm_set_alarming_flag													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: �x�񒆃t���O�l�ݒ�														*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/* �߂�l		: u1_t_result_alarming_flag		: �x�񒆃t���O���茋��						*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: st_g_bsm_alarm_data.afl_alarmed_target	: �x��^�[�Q�b�g��� [in]		*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-ABST-00-011 (��8)�x�񒆃t���O�ɂ��� 					*/
/*------------------------------------------------------------------------------------------*/
/* ���l			: ���̏����̒�`��ABST�d�l���ɒ�`����Ă��邪�A�����̌��ʂ�����			*/
/*				  ������₷�����邽��bsm_main.c�ɒ�`���Ă���								*/
/********************************************************************************************/
U1 u1_bsm_set_alarming_flag(VD)
{
	U1 u1_t_result_alarming_flag;
	U1 u1_t_lp_target_num;
	
	u1_t_result_alarming_flag = (U1)0;
	
	for (u1_t_lp_target_num = (U1)0; u1_t_lp_target_num < TARGET_BUFFSIZE; u1_t_lp_target_num++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[u1_t_lp_target_num][0] != CFL_UNKNOWN_VALUE) {
			u1_t_result_alarming_flag = (U1)1;
			break;
		}
	}
	
	return u1_t_result_alarming_flag;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_nbd_input_recog_data												*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: NBD �F���f�[�^�̊i�[����													*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_bsm_nbd_input_recog_data( 
	BSM_OUT_DATA *pst_a_out_data,
	S4 s4_a_pair_num_sot,
	S4 s4_a_truck_flg
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_lp_g;

	/* �K�[�h�������͍���̃��t�@�N�^�����O�őΉ��\�� */

	/* �Z���T���t���ʒu */
	afl_g_bsm_sensor_position[0] = st_g_bsm_loop_data.afl_installed_angle[0];
	afl_g_bsm_sensor_position[1] = st_g_bsm_loop_data.afl_installed_angle[1];
	afl_g_bsm_sensor_position[2] = st_g_bsm_loop_data.afl_installed_angle[2];

	/* ���W�� */
	/* ��S4��U1�̃_�E���L���X�g�ł��邪�A�S�Ă̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
	au1_g_bsm_pair_num[0] = (U1)st_g_bsm_loop_data.as4_buf_pair_num[0];			/* ��╨�W�� */
	au1_g_bsm_pair_num[1] = (U1)st_g_bsm_loop_data.as4_buf_pair_num[1];			/* ���ޯĐ� */

	u1_g_bsm_pair_num_prior		= (U1)pst_a_out_data->s4_pair_num_prior;		/* �D�敨�W�� */
	u1_g_bsm_pair_num_ordinary	= (U1)pst_a_out_data->s4_pair_num_ordinary;		/* �ʏ함�W�� */
	u1_g_bsm_pair_num_2f		= (U1)pst_a_out_data->s4_pair_num_2f;			/* �⏕���W�� */
	u1_g_bsm_pair_num_side		= (U1)s4_a_pair_num_sot;						/* �O�������W�� */
	/* ��S4��U1�̃_�E���L���X�g�ł��邪�A�S�Ă̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
#if		(NBD_TYPE == CU1_DF_NBD_BSM_ONLY)
	for (s4_t_lp_i=0; s4_t_lp_i<20; s4_t_lp_i++ ){
		/* ��S4��S2�̃_�E���L���X�g�ł��邪�As4_flg_track�ȊO�̕ϐ��̒l�悪S2�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		/* s4_flg_track�͒l�悪S2�͈̔͂𒴂���\�������邪�A���b�`���ast_g_bsm_normal[]��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_up					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_up;						/* ����߰�bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_dn					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_dn;						/* �����߰�bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_up_music				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_up_music;					/* ������bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_bin_dn_music				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_bin_dn_music;					/* �������bin */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_stop					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_stop;						/* ��~���t���O */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_track				= s2_data_grd((S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_track, CS2_S2MAX, CS2_S2MIN);		/* ����ڑ��� */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_lost					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_lost;						/* �O�}�� */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_new					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_new;						/* �V�K���W�t���O */
		ast_g_bsm_normal[s4_t_lp_i].s2_ctr_sot_cut				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ctr_sot_cut;					/* fast-Sot�J�b�g�Ώۃt���O */
		ast_g_bsm_normal[s4_t_lp_i].s2_ID_num					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ID_num;						/* ���ޯ�ID */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_dc					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_dc;						/* ���W��� */
		ast_g_bsm_normal[s4_t_lp_i].s2_flg_reliable				= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_flg_reliable;					/* ���W�m��t���O */
		ast_g_bsm_normal[s4_t_lp_i].s2_ctr_tos					= (S2)st_g_bsm_loop_data.ast_normal[s4_t_lp_i].s4_ctr_tos;						/* Tos�炵���J�E���^ */
		/* ��S4��S2�̃_�E���L���X�g�ł��邪�As4_flg_track�ȊO�̒l�悪S2�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		/* s4_flg_track�͒l�悪S2�͈̔͂𒴂���\�������邪�A���b�`���ast_g_bsm_normal[]��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_up					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_up;						/* ����߰��d�� */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_dn					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_dn;						/* �����߰��d�� */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_up_music			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_up_music;				/* �����ʓd�� */
		ast_g_bsm_normal[s4_t_lp_i].fl_power_dn_music			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_power_dn_music;				/* ������ʓd�� */
		ast_g_bsm_normal[s4_t_lp_i].fl_theta_up_pred			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_theta_up_pred;				/* ����߰����o�p�x�\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_theta_dn_pred			= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_theta_dn_pred;				/* �����߰����o�p�x�\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxobs;						/* X���������ϑ��l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ryobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ryobs;						/* Y���������ϑ��l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxfil;						/* X���������o�͒l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ryfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ryfil;						/* Y���������o�͒l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rxpred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rxpred;						/* X���������\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Rypred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Rypred;						/* Y���������\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxobs;						/* X�������x�ϑ��l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vyobs					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vyobs;						/* Y�������x�ϑ��l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxfil;						/* X�������x�o�͒l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vyfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vyfil;						/* Y�������x�o�͒l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vxpred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vxpred;						/* X�������x�\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Vypred					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Vypred;						/* Y�������x�\���l */
		ast_g_bsm_normal[s4_t_lp_i].fl_Axfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Axfil;						/* X���������x */
		ast_g_bsm_normal[s4_t_lp_i].fl_Ayfil					= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_Ayfil;						/* Y���������x */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_up_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_up_interpolate;			/* ������bin[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_dn_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_dn_interpolate;			/* �������bin[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_up_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_up_interpolate_pred;		/* ������bin�\���l[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_doa_dn_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_doa_dn_interpolate_pred;		/* �������bin�\���l[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_up_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_up_interpolate;			/* ����߰�bin[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_dn_interpolate		= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_dn_interpolate;			/* �����߰�bin[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_up_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_up_interpolate_pred;		/* ����߰�bin�\���l[��Ԓl] */
		ast_g_bsm_normal[s4_t_lp_i].fl_bin_dn_interpolate_pred	= st_g_bsm_loop_data.ast_normal[s4_t_lp_i].fl_bin_dn_interpolate_pred;		/* �����߰�bin�\���l[��Ԓl] */
	}
#elif	(NBD_TYPE == CU1_DF_NBD_BSM_LCA)
	/* �������Ȃ� */
#else
	�R���p�C���G���[
#endif /* NBD_TYPE */
	

	fl_g_bsm_wall_width		= st_g_bsm_loop_data.afl_wall_width[0];			/* �ǐ��苗�� */
	/* S4��U1�̃_�E���L���X�g�ł��邪�Aas4_flg_passing[0]�ȊO�̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	/* as4_flg_passing[0]�͒l�悪U1�͈̔͂𒴂���\�������邪�A���b�`���u1_g_bsm_passing_flg��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
	u1_g_bsm_leading_flg	= (U1)st_g_bsm_loop_data.as4_flg_leading[0];		/* �����ԃt���O */
	u1_g_bsm_passing_flg	= (U1)u1_data_grd((U1)st_g_bsm_loop_data.as4_flg_passing[0], CU1_U1MAX, CU1_U1MIN);		/* �ǉz�ԃt���O */
	u1_g_bsm_truck_flg		= (U1)s4_a_truck_flg;								/* �g���b�N�t���O */

	/* �ᑬSoT����t���O */
	/* S4��U1�̃_�E���L���X�g�ł��邪�Aas4_slow_sot_find[0,1]�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	au1_g_bsm_sot_find[0] = (U1)st_g_bsm_loop_data.as4_slow_sot_find[0];	/* SoT����t���O */
	au1_g_bsm_sot_find[1] = (U1)st_g_bsm_loop_data.as4_slow_sot_find[1];	/* �ǔ���t���O */

	for (s4_t_lp_i=0; s4_t_lp_i<6; s4_t_lp_i++ ){
		/* S4��S2�̃_�E���L���X�g�ł��邪�Aas4_slow_sot_doa_diff_sum[]�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
		as2_g_bsm_doa_diff_sum[s4_t_lp_i] = (S2)st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[s4_t_lp_i];
	}

	for (s4_t_lp_i=0; s4_t_lp_i<2; s4_t_lp_i++ ){
		for (s4_t_lp_k=0; s4_t_lp_k<3; s4_t_lp_k++ ){
			for (s4_t_lp_g=0; s4_t_lp_g<12; s4_t_lp_g++ ){
				/* SoT-��~���̍������ޯ̧ */
				/* S4��S2�̃_�E���L���X�g�ł��邪�Aas2_g_bsm_sot_check_sum[][][]��NBD�o�͂ɂ����g�p����Ȃ����߁A���Ȃ� */
				as2_g_bsm_sot_check_sum[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g] 
					= s2_data_grd((S2)st_g_bsm_loop_data.as4_sot_check_sum[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g], CS2_S2MAX, CS2_S2MIN);
				
				/* SoT-��~���̍����_���ޯ̧ */
				/* S4��S2�̃_�E���L���X�g�ł��邪�Aas2_g_bsm_sot_check_points[][][]��NBD�o�͂ɂ����g�p����Ȃ����߁A���Ȃ� */
				as2_g_bsm_sot_check_points[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g]
					= s2_data_grd((S2)st_g_bsm_loop_data.as4_sot_check_points[s4_t_lp_i][s4_t_lp_k][s4_t_lp_g], CS2_S2MAX, CS2_S2MIN);
			}
		}
	}

	/* fast-SoT ����t���O */
	/* S4��U1�̃_�E���L���X�g�ł��邪�Aas4_fast_sot_flg[0]�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_fast_sot_flg = (U1)st_g_bsm_loop_data.as4_fast_sot_flg[0];

	for (s4_t_lp_i=0; s4_t_lp_i<TARGET_BUFFSIZE; s4_t_lp_i++ ){
		/* ��S4��S2�̃_�E���L���X�g�ł��邪�Aas4_Tx_int[][9]�ȊO�̕ϐ��̒l�悪S2�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		/* as4_Tx_int[][9]�͒l�悪S2�͈̔͂𒴂���\�������邪�A���b�`���ast_g_bsm_target[]��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_up						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][0];			/* ����߰�bin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_up_music					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][1];			/* ����߰��p�xbin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_dn						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][2];			/* �����߰�bin */
		ast_g_bsm_target[s4_t_lp_i].s2_bin_dn_music					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][3];			/* �����߰��p�xbin */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_stop						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][8];			/* ��~���t���O */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_track					= s2_data_grd((S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][9], CS2_S2MAX, CS2_S2MIN);			/* ����ڑ��� */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_lost						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][10];		/* �O�}�� */
		ast_g_bsm_target[s4_t_lp_i].s2_ID_num						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][11];		/* ���WID (1�`8) */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_new						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][12];		/* �V�K���W�t���O */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_dc						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][14];		/* ���W��ʁi�����P�j */
		ast_g_bsm_target[s4_t_lp_i].s2_ctr_sot_cut					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][15];		/* fast-Sot�J�b�g�Ώۃt���O */
		ast_g_bsm_target[s4_t_lp_i].s2_flg_reliable					= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][16];		/* ���W�m��t���O */
		ast_g_bsm_target[s4_t_lp_i].s2_ctr_tos						= (S2)pst_a_out_data->as4_Tx_int[s4_t_lp_i][17];		/* Tos�炵���J�E���^ */
		/* ��S4��S2�̃_�E���L���X�g�ł��邪�A as4_Tx_int[][9]�ȊO�̒l�悪S2�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		/* as4_Tx_int[][9]�͒l�悪S2�͈̔͂𒴂���\�������邪�A���b�`���ast_g_bsm_target[]��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
		ast_g_bsm_target[s4_t_lp_i].fl_power_up_music				= pst_a_out_data->afl_Tx_float[s4_t_lp_i][0];		/* ����߰��p�x�d�� */
		ast_g_bsm_target[s4_t_lp_i].fl_power_dn_music				= pst_a_out_data->afl_Tx_float[s4_t_lp_i][1];		/* �����߰��p�x�d�� */
		ast_g_bsm_target[s4_t_lp_i].fl_theta_up						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][2];		/* ����߰����� */
		ast_g_bsm_target[s4_t_lp_i].fl_theta_dn						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][3];		/* �����߰����� */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxobs						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][5];		/* X���������ϑ��l */
		ast_g_bsm_target[s4_t_lp_i].fl_Ryobs						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][6];		/* Y���������ϑ��l */
		ast_g_bsm_target[s4_t_lp_i].fl_Ryfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][7];		/* Y���������o�͒l */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][8];		/* X���������o�͒l */
		ast_g_bsm_target[s4_t_lp_i].fl_Rxpred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][9];		/* X���������\���l */
		ast_g_bsm_target[s4_t_lp_i].fl_Rypred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][10];		/* Y���������\���l */
		ast_g_bsm_target[s4_t_lp_i].fl_Vyfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][13];		/* Y�������x�o�͒l */
		ast_g_bsm_target[s4_t_lp_i].fl_Vxfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][14];		/* X�������x�o�͒l */
		ast_g_bsm_target[s4_t_lp_i].fl_Vxpred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][15];		/* X�������x�\���l */
		ast_g_bsm_target[s4_t_lp_i].fl_Vypred						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][16];		/* Y�������x�\���l */
		ast_g_bsm_target[s4_t_lp_i].fl_Ayfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][17];		/* Y���������x */
		ast_g_bsm_target[s4_t_lp_i].fl_Axfil						= pst_a_out_data->afl_Tx_float[s4_t_lp_i][18];		/* X���������x */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_up_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][31];		/* ������bin[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_dn_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][32];		/* �������bin[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_up_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][33];		/* ������bin�\���l[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_doa_dn_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][34];		/* �������bin�\���l[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_up_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][35];		/* ����߰�bin[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_dn_interpolate			= pst_a_out_data->afl_Tx_float[s4_t_lp_i][36];		/* �����߰�bin[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_up_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][37];		/* ����߰�bin�\���l[��Ԓl] */
		ast_g_bsm_target[s4_t_lp_i].fl_bin_dn_interpolate_pred		= pst_a_out_data->afl_Tx_float[s4_t_lp_i][38];		/* �����߰�bin�\���l[��Ԓl] */
	}

	for (s4_t_lp_i = (S4)0; s4_t_lp_i < (S4)6; s4_t_lp_i++) {
		afl_g_bsm_alarmed_target[s4_t_lp_i][0]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][0];				/* X�������� */
		afl_g_bsm_alarmed_target[s4_t_lp_i][1]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][1];				/* Y�������� */
		
		/* ��S4��U1�̃_�E���L���X�g�ł��邪�A�S�Ă̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		au1_g_bsm_alarmed_target[s4_t_lp_i][2]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][2];			/* ID */
		au1_g_bsm_alarmed_target[s4_t_lp_i][3]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][3];			/* �x��� */
		au1_g_bsm_alarmed_target[s4_t_lp_i][4]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][4];			/* �������̏�� */
		au1_g_bsm_alarmed_target[s4_t_lp_i][5]		= (U1)st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][5];			/* �O�}�� */
		/* ��S4��U1�̃_�E���L���X�g�ł��邪�A�S�Ă̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ��� */
		
		afl_g_bsm_alarmed_target[s4_t_lp_i][6]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][6];				/* �J�n���̓d�� */
		afl_g_bsm_alarmed_target[s4_t_lp_i][7]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][7];				/* �J�n���̓d�͂Ƃ̍��� */
		afl_g_bsm_alarmed_target[s4_t_lp_i][8]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][8];				/* X�������x */
		afl_g_bsm_alarmed_target[s4_t_lp_i][9]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][9];				/* Y�������x */
		afl_g_bsm_alarmed_target[s4_t_lp_i][10]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][10];			/* �J�n����X�������� */
		afl_g_bsm_alarmed_target[s4_t_lp_i][11]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][11];			/* �J�n����Y�������� */
		afl_g_bsm_alarmed_target[s4_t_lp_i][12]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][12];			/* �J�n���̌x��ر(Xmin) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][13]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][13];			/* �J�n���̌x��ر(Xmax) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][14]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][14];			/* �J�n���̌x��ر(Ymin) */
		afl_g_bsm_alarmed_target[s4_t_lp_i][15]		= st_g_bsm_alarm_data.afl_alarmed_target[s4_t_lp_i][15];			/* �J�n���̌x��ر(Ymax) */
	}

	/* S4��U1�̃_�E���L���X�g�ł��邪�Aas4_alarm_off_count[0]�ȊO�̕ϐ��̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	/* as4_alarm_off_count[0]�͒l�悪S2�͈̔͂𒴂���\�������邪�A���b�`���s2_g_bsm_alarm_off_count��NBD�o�͂ɂ����g�p����Ȃ����߁A�_�E���L���X�g���Ă����Ȃ� */
	u1_g_bsm_alarm_flg			= (U1)st_g_bsm_loop_data.s4_flg_alarm;					/* �x��t���O */
	s2_g_bsm_alarm_off_count	= s2_data_grd((S2)st_g_bsm_alarm_data.as4_alarm_off_count[0], CS2_S2MAX, CS2_S2MIN);		/* �x�񉄒��� */
	u1_g_bsm_alarmed_num		= (U1)st_g_bsm_alarm_data.as4_alarmed_num[0];			/* �x�񕨕W�� */
	u1_g_bsm_tos_end_flg		= (U1)st_g_bsm_loop_data.as4_flg_tos_end[0];			/* ToS�I���t���O */
	u1_g_bsm_tos_frontline_flag = (U1)st_g_bsm_loop_data.as4_flg_tos_frontline[0];		/* �ԗ���[�t���O */
	fl_g_bsm_tos_frontline_pow	= st_g_bsm_loop_data.afl_tos_frontline_pow[0];		/* �ԗ���[�d�� */
	s1_g_bsm_ctr_heisou_car		= st_g_bsm_loop_data.s1_ctr_heisou_car;				/* �����ԑ��݃J�E���^ */
	u1_g_bsm_flg_heisou_car		= st_g_bsm_loop_data.u1_flg_heisou_car;				/* �����ԑ��݃t���O */

	return;
}

/********************************************************************************************/
/* �֐���		: fn_loop_data_initialize()													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: st_g_bsm_loop_data�������֐�												*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_loop_data_initialize(BSM_LOOP_DATA *pst_a_loop_data){

	S4 s4_t_lp_i = 0;
	S4 s4_t_lp_j = 0;

	/***** INPUT *****/
	pst_a_loop_data->as4_flg_wall[0] = 0;
	pst_a_loop_data->afl_wall_width[0] = WALL_MAX;
	pst_a_loop_data->as4_flg_passing[0] = 0;
	pst_a_loop_data->as4_flg_leading[0] = 0;

	/***** FEEDBACK *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
		pst_a_loop_data->as4_buf_pair_num[s4_t_lp_i] = 0;
	}
	pst_a_loop_data->u1_truck_flg = (U1)0;
	fn_init(pst_a_loop_data->ast_normal, NORMAL_BUFFSIZE);
	fn_init(pst_a_loop_data->ast_target, TARGET_BUFFSIZE);


	/***** FEEDBACK (for wall estimation) *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 70; s4_t_lp_i++) {
		pst_a_loop_data->afl_Rx_right[s4_t_lp_i] = WALL_MAX;
	}

	pst_a_loop_data->fl_fm_obj_x_pre = CFL_UNKNOWN_VALUE;
	pst_a_loop_data->u1_flg_fm_obj_x_pre_enable = CU1_DF_OFF;
	pst_a_loop_data->u1_wall_flg_for_fa_judgement = (U1)0;
	pst_a_loop_data->u1_fm_object_stable_count = (U1)0;

	/***** FEEDBACK (for SoT) *****/
	fn_initialize_wall_data(pst_a_loop_data->ast_normal_wall);

	/***** FEEDBACK (for Slow-SoT) *****/
	for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
		pst_a_loop_data->as4_slow_sot_find[s4_t_lp_i] = 0;
	}
	for (s4_t_lp_i = 0; s4_t_lp_i < 6; s4_t_lp_i++) {
		pst_a_loop_data->as4_slow_sot_doa_diff_sum[s4_t_lp_i] = 0;
	}

	pst_a_loop_data->u1_count_adjacent_lane_exist = (U1)0;

	pst_a_loop_data->s1_ctr_heisou_car = (S1)0;
	pst_a_loop_data->u1_flg_heisou_car = (U1)0;

	/***** FEEDBACK (for ToS End) *****/
	pst_a_loop_data->as4_flg_tos_frontline[0] = 0;
	pst_a_loop_data->afl_tos_frontline_pow[0] = 0.0F;		/* $$$ 2013.08.27-2 */
	pst_a_loop_data->as4_flg_sot_backwardline[0] = 0;		/* $$$ 2013.07.29 TEST */
	pst_a_loop_data->as4_flg_tos_end[0] = 0;				/* $$$ 2013.08.06 */
	pst_a_loop_data->as4_flg_sot_end[0] = 0;				/* $$$ 2013.08.08-4 */
	pst_a_loop_data->as4_low_speed_flg[0] = 1;
	pst_a_loop_data->as4_fast_sot_flg[0] = 0;

	pst_a_loop_data->s4_final_target_num = 0;

	/***** �x�񔻒� *****/
	pst_a_loop_data->s4_flg_alarm = 0;
	pst_a_loop_data->u1_reliable_jdg_mask_count = (U1)0;
	pst_a_loop_data->u1_shrink_on_count = (U1)0;
	pst_a_loop_data->u1_shrink_keep_count = (U1)0;
	pst_a_loop_data->u1_fa_delete_count = (U1)0;

	return;

}

/********************************************************************************************/
/* �֐���		: fn_loop_data_initialize_sensor()											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: fn_loop_data_initialize_sensor�������֐�									*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_loop_data_initialize_sensor(BSM_LOOP_DATA *pst_a_loop_data)
{
	pst_a_loop_data->afl_installed_angle[0] = FL_BSM_FLSH_AXIS_DEFAULT;
	pst_a_loop_data->afl_installed_angle[1] = (((FL)U2_BSM_FLSH_SUBJECT_VEHICLE_WIDTH/1000.0F) / 2.0F) - ((FL)U4_BSM_FLSH_DELTA_W / 1000.0F);
	pst_a_loop_data->afl_installed_angle[2] = (FL)U4_BSM_FLSH_DELTA_L / 1000.0F;

	return;
}

/********************************************************************************************/
/* �֐���		: fn_out_data_initialize()														*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: outdata�������֐�															*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	  								: 											*/
/* <output>		  								: 											*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_out_data_initialize(BSM_OUT_DATA *pst_a_out_data){

	S4 s4_t_lp_i = 0;
	S4 s4_t_lp_j = 0;
	S4 s4_t_lp_k = 0;

	/***** OUTPUT (SoT) *****/
	pst_a_out_data->as4_flg_sot[0] = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < 4; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 7; s4_t_lp_j++) {
			pst_a_out_data->afl_sot_target_info[s4_t_lp_j][s4_t_lp_i] = CFL_UNKNOWN_VALUE;
		}
	}

	/***** OUTPUT (CAN) *****/
	fn_initialize_Tx_data(
		pst_a_out_data->as4_Tx_int,
		pst_a_out_data->afl_Tx_float
	);

	/***** OUTPUT (OBJECT) *****/
	pst_a_out_data->s4_pair_num_prior = 0;
	fn_init(pst_a_out_data->ast_normal_prior, PRIOR_BUFFSIZE);

	pst_a_out_data->s4_pair_num_ordinary = 0;
	fn_init(pst_a_out_data->ast_normal_ordinary, ORDINARY_BUFFSIZE);
	
	pst_a_out_data->s4_pair_num_2f = 0;
	fn_init(pst_a_out_data->ast_normal_2f, AUX_BUFFSIZE);

#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_TRAILER_OBJ_FUNC_T)
	pst_a_out_data->s4_pair_num_trailer = 0;
	fn_init(pst_a_out_data->ast_normal_trailer, TRAILER_BUFFSIZE);
#endif

	return;

}

/********************************************************************************************/
/* �֐���		: fn_bsm_can_data_init()													*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: BSM/LCA���쐬����CAN�f�[�^�̏�����										*/
/*------------------------------------------------------------------------------------------*/
/* ����			: �Ȃ�																		*/
/*																							*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  : 																				*/
/* <output>	: st_g_tx_noise_chk_fsk_bsm														*/
/* 			: st_g_tx_noise_chk_fm_bsm 														*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: 																			*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		:																			*/
/*																							*/
/********************************************************************************************/
VD fn_bsm_can_data_init(VD)
{
	/* CAN���b�`�f�[�^�������� */
	st_g_tx_noise_chk_fsk_bsm.u1_peak_num	= 0;
	st_g_tx_noise_chk_fsk_bsm.u2_thres1		= 0;
	st_g_tx_noise_chk_fsk_bsm.u2_thres2		= 0;

	st_g_tx_noise_chk_fm_bsm.u1_peak_num_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u1_peak_num_dn	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres1_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres1_dn	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres2_up	= 0;
	st_g_tx_noise_chk_fm_bsm.u2_thres2_dn	= 0;

	return;
}



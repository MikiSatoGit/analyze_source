/****************************************************************************/
/* �t�@�C����	: BSM_RECOG_04.c											*/
/*--------------------------------------------------------------------------*/
/* ���W���[����	: 															*/
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
/*	t04					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t05					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No492�Ή�															*/
/*	t06					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No492�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t08					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t09					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t10					15.10.23			�����Z2 1�Z�� M.Tanaka			*/
/*	�c�ۑ�No.849�Ή�(�Öق̃L���X�g���C��)									*/
/*	t11					15.10.27			�����Z2 1�Z�� Y.Nishioka		*/
/*	�֐��w�b�_�̒ǉ� ��OBJ�ύX�Ȃ�											*/
/*	t12					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)										*/
/*	t13					15.11.25			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo.1799�Ή�														*/
/*	t14					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1194,1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)	*/
/*	t15					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1109,1091,1092�Ή�(�n�������̏C���A�ϐ������������ǉ�)			*/
/*	t16					16.03.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l�Ή�														*/
/*	t17					16.03.28			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/*	t18					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t19					16.04.12			�����Z2 1�Z�� K.Hanabata		*/
/*	QAC�w�E�C��																*/
/*	t20					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t21					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t22					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t23					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �c�ۑ�No1336�Ή� OBJ�ύX�Ȃ�										*/
/*	t24					16.06.21			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t25					16.06.22			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t28					16.08.10			�����Z2 1�Z�� Y.Nishioka		*/
/*	�֐����ύX(shareMUSIC_��ǉ�) ���I�u�W�F�N�g�ύX�Ȃ�					*/
/*	p01					16.09.08			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �����[�X�p														*/
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
#include "func_fmcw.h"
#include "func_fsk.h"
#include "../../common/cmn_shareMUSIC_mwr.h"

#include "bsm_recog_04.h"

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

/****************************************************************************/
/*							�X�^�e�B�b�N�֐��錾							*/
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
/* �֐���		: fn_bsm_seek_2f_object										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �⏕���W�F������											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: 															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
#endif	/*VI �\���p*/

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
	/* (1)	�Q�e�b�v�s�[�N臒l�Z�o����											*/
	/****************************************************************************/
	fn_set_freq_threshold_fsk(
		(const FL *)afl_g_cvw_fcw_ftt_power,	/* [in] */
		afl_t_thres_2f,							/* [out] */
		fl_g_v_self_bsm_for_base				/* [in]	 */
	);

#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy(afl_g_thres_2f, afl_t_thres_2f, sizeof(FL)*NB_FFT_PT_2F);
#endif /*VI �\���p*/

	/* �m�C�Y�]���p���M�f�[�^���b�` LSB:0.01�ɕύX 臒l�̍ő�l��120.0F */
	st_g_tx_noise_chk_fsk_bsm.u2_thres1 = u2_cast_from_fl(afl_t_thres_2f[140] * (FL)100);
	st_g_tx_noise_chk_fsk_bsm.u2_thres2 = u2_cast_from_fl(afl_t_thres_2f[180] * (FL)100);


	/****************************************************************************/
	/* (2)	�Q�e�b�v�s�[�N�T�[�`����											*/
	/****************************************************************************/
	if (	/* �Ԃ����鎞��2���g�̗��E���̃s�[�N���T�� */
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

	st_g_tx_noise_chk_fsk_bsm.u1_peak_num = (U1)s4_t_peak_num_2f;		/* �m�C�Y�]���p���M�f�[�^���b�` */

#if (MODE_ECU_SIM == ECU_MODE)
	/* S4��U1�̃_�E���L���X�g�ł��邪�As4_t_peak_num_2f�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_2f_music_peak_num = (U1)s4_t_peak_num_2f;		/* CheckPoint BSM_�⏕���W�s�[�N�T�[�`���� */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* (3)	�������菈��														*/
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
	/* S4��U1�̃_�E���L���X�g�ł��邪�As4_t_peak_num_2f_doa�̒l�悪U1�͈̔͂Ɏ��܂邽�ߖ��Ȃ� */
	u1_g_bsm_2f_pair_num = (U1)s4_t_peak_num_2f_doa;		/* CheckPoint BSM_�⏕���W���W�� */
#endif /* MODE_ECU_SIM */


/****************************************************************************/
/* (4)	���W���Z�o�����i�QFCW�j											*/
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
#endif /*VI �\���p*/

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
/* �֐���		: fn_bsm_2f_init_data										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ������													*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: 															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
/* �֐���		: s4_search_freq_peak_fsk_IQ								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-2)-(i)�ڋߑ��E���E���̃s�[�N�̌��o					*/
/*				: �u2-2. �ʏ함�W�F������ (2)�ʏ�s�[�N�T�[�`����			*/
/*				:	2)���g���X�y�N�g�����̃s�[�N�T�[�`�v�����{				*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (2)-2)-(i)�ڋߑ��E���E���̃s�[�N�̌��o					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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

	/* �ڋߑ� */
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

	/* ���E�� */
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
/* �֐���		: s4_search_freq_peak_fsk									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-2)-(ii)�ڋߑ��̃s�[�N�̌��o							*/
/*				: �u2-2. �ʏ함�W�F������ (2)�ʏ�s�[�N�T�[�`����			*/
/*				:	2)���g���X�y�N�g�����̃s�[�N�T�[�`�v�����{				*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (2)-2)-(ii)�ڋߑ��̃s�[�N�̌��o							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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

	/* �ڋߑ�(I) */
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
/* �֐���		: fn_bsm_2f_estimate_doa									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3)�������菈��											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)�������菈��											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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

	/* ������ */
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

		/* LCA�Ƃ̋��L�s�[�N���֊i�[ */
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
/* �֐���		: fn_bsm_2f_cal_doa											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���ʐ���													*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)���ʐ��菈��											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
/* �֐���		: fn_bsm_2f_cal_interpolate_freq_peak						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �p�x�s�[�N���											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)�������菈��											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
/* �֐���		: fn_bsm_2f_store_doa										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���ʐ��茋�ʂ̊i�[										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (3)�������菈��											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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

	/* �y�A�}�b�`�p�̕��ʐ��茋�ʂ��i�[ */
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
/* �֐���		: fn_bsm_2f_make_pair										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (4)���W���Z�o�����i�QFCW)								*/
/*				:	�⏕�s�[�N�T�`�����ɂ�蓾��ꂽ2FCW���g���X�y�N�g����	*/
/*				:	�̃s�[�N���A�y�ѕ������菈���ɂ�蓾��ꂽ���ʏ���	*/
/*				:	��Â��A���W�̈ʒu�E���x�����Z�o����B				*/
/*				:	1)����������ԍ��W�n�ɕϊ�								*/
/*				:	2)�����̎Z�o											*/
/*				:	3)���x�̎Z�o											*/
/*				:	4)FMCW�s�[�N���g���̎Z�o								*/
/*				:	5)�s�[�N���											*/
/*				:	6)���W���̕ۑ�										*/
/*				:	7)���W�t���O���̕ۑ�									*/
/*				:	8)�o�b�t�@���ӂ�΍�									*/
/*				:	9)���ʐ��茋�ʂ̊i�[									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (4)���W���Z�o�����i�QFCW)								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
	/******************** �����v�Z ********************/
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_doa_peak_num_2f; s4_t_lp_i++) {

		/***** 1) ����������ԍ��W�n�ɕϊ� *****/
		fl_t_tmp_theta = -(PI / 180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_peak_doa_bins_intpl_2f[s4_t_lp_i] +  (FL)DOA_BIN_START_ANG));

		/***** 2) �����̎Z�o *****/
		for (s4_t_lp_k = 0 ; s4_t_lp_k < 3 ; s4_t_lp_k++) {
			afl_t_tmp_Ryy[s4_t_lp_k] = afl_g_cvw_fcw_ryy_matrix_2f[(S4)afl_a_peak_bins_intpl_2f[s4_t_lp_i]][s4_t_lp_k];
		}
		fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
		fl_t_tmp_Rxobs = (fl_t_tmp_Robs * (FL)fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
		fl_t_tmp_Ryobs = fl_t_tmp_Robs * (FL)fl_cos(fl_t_tmp_theta);

		fl_t_tmp_Vobs = VCOF_2F * (afl_a_peak_bins_intpl_2f[s4_t_lp_i] - (FL)(NB_FFT_PT_2F / 2));
		/* �^���t�߂�2F���W�̑��x���O��(�ԗփh�b�v���ŕ����̑��x�����o����邽��) */
		if (fl_abs(fl_t_tmp_Ryobs) < EKF_RY_SIDE) {		/* COND.d4 */
			fl_t_tmp_Vobs = 0.0F;
		}

		/******************** ����q����i-1.5m-fl_a_wall) ********************/
		if (s4_t_pair_num < AUX_BUFFSIZE) {											/* COND.d14 */
			if (
				(fl_t_tmp_Rxobs > st_g_bsm_loop_data.afl_installed_angle[1])		/* COND.d12 */
				 && (fl_t_tmp_Rxobs < RX_MAX_2F)									/* COND.d12 */
				 && (fl_t_tmp_Ryobs < RY_MIN_2F)									/* COND.d13 */
				 && (fl_t_tmp_Robs > R_MAX_2F)										/* COND.d11 */
				 && (fl_t_tmp_Robs < R_MIN_2F)										/* COND.d11 */
			) {
				/***** 4) FMCW�s�[�N���g���̎Z�o *****/
				/***** 5) �s�[�N��� *****/
				/* convert to FMCW peak (UP) */
				if (fl_t_tmp_Robs < 0) {											/* COND.d10 */
					ast_a_normal_2f[s4_t_pair_num].s4_bin_up = (S4)(( 0.50F * ((-fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);					/* PROC.1 */
					ast_a_normal_2f[s4_t_pair_num].fl_bin_up_interpolate = ((0.50F * ((-fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);		/* PROC.1 */
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_bin_up = (S4)(( 0.50F * ((fl_t_tmp_Robs / RCOF) - (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_up_interpolate = (( 0.50F * (fl_t_tmp_Robs / RCOF - fl_t_tmp_Vobs / VCOF)) + 0.50F) + (FL)(NB_FFT_PT / 2);
				}
				/***** 4) FMCW�s�[�N���g���̎Z�o *****/
				/***** 5) �s�[�N��� *****/
				if (fl_t_tmp_Robs < 0) {											/* COND.d10 */
					ast_a_normal_2f[s4_t_pair_num].s4_bin_dn = (S4)(( 0.50F * ((-fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF))) + 0.50F) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_dn_interpolate = (( 0.50F * (-fl_t_tmp_Robs / RCOF + fl_t_tmp_Vobs / VCOF)) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_bin_dn = (S4)((0.50F * ((fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF)) + 0.50F)) + (S4)(NB_FFT_PT / 2);
					ast_a_normal_2f[s4_t_pair_num].fl_bin_dn_interpolate = ((0.50F * ((fl_t_tmp_Robs / RCOF) + (fl_t_tmp_Vobs / VCOF))) + 0.50F) + ((FL)NB_FFT_PT / 2.0F);
				}

				/***** 6) ���W���̕ۑ� *****/
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

				/* �ϑ��ʒu */
				ast_a_normal_2f[s4_t_pair_num].fl_Robs	 			= fl_t_tmp_Robs;
				ast_a_normal_2f[s4_t_pair_num].fl_Rxobs				= fl_t_tmp_Rxobs;
				ast_a_normal_2f[s4_t_pair_num].fl_Ryobs				= fl_t_tmp_Ryobs;

				/*  �ϑ����x */
				ast_a_normal_2f[s4_t_pair_num].fl_Vobs				= fl_t_tmp_Vobs;

				/***** 3) ���x�̎Z�o *****/
				/* ���x��XY�������� */
				ast_a_normal_2f[s4_t_pair_num].fl_Vxobs = 0.0F;
				ast_a_normal_2f[s4_t_pair_num].fl_Vyobs = fl_get_vy(
					ast_a_normal_2f[s4_t_pair_num].fl_Vobs,
					fl_cos(ast_a_normal_2f[s4_t_pair_num].fl_theta_up),
					ast_a_normal_2f[s4_t_pair_num].fl_Ryobs,
					fl_g_v_self_bsm_for_base
				);

				/***** 7) ���W�t���O���̕ۑ� *****/
				/*  ��~������ */
				if (fl_abs(ast_a_normal_2f[s4_t_pair_num].fl_Vyobs + fl_g_v_self_bsm_for_base / 3.6F) < 0.5F) {		/* COND.d15 */
					ast_a_normal_2f[s4_t_pair_num].s4_flg_stop 		= 1;
				} else {
					ast_a_normal_2f[s4_t_pair_num].s4_flg_stop 		= 0;
				}
				s4_t_pair_num++;
			}
		} else {
			/***** 8) �o�b�t�@���ӂ�΍� *****/
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
/* �֐���		: fn_bsm_2f_set_object										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (4)-7)-�B ���W��ʂ�ݒ�									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (4)-7)-�B ���W��ʂ�ݒ�									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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
/* �֐���		: s4_bsm_2f_compare_with_FMCW								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)FMCM��r�E��������										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-007.pdf							*/
/*				: (5)FMCM��r�E��������										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
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

	/* ���[�J���ϐ������� */
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
		/* ����b10�̔���֐��R�[�� �d�l���̋L�q������b10�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
		/* ����b10�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����									*/
		/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�				*/
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
				/* ����a3�̔���֐��R�[�� �d�l���̋L�q������a3�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
				/* ����a3�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����								*/
				/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�			*/
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
/* �֐���		: u1_bsm_2f_compare_with_FMCW_b10							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: FMCM��r�E���������̏���b10����֐�						*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_Ryobs			: ���ݕ��W��Y���������ϑ��l[in]		*/
/* �߂�l		: u1_t_jdg_b10_flag		: ����b10�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-010								*/
/*				: (5) FMCW ��r�E���������̏���b10							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_2f_compare_with_FMCW_b10(FL fl_a_Ryobs)
{
	/* ����b10���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_b10_flag;				/* ����b10���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_b10_flag = CU1_FALSE;

	/* ����b10�̔��� */
#if (BSM_OPTION_SW_RECOG_04 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (fl_a_Ryobs < (FL)-5.0F) {
		u1_t_jdg_b10_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b10_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_04 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (fl_a_Ryobs < (FL)-3.5F) {
		u1_t_jdg_b10_flag = CU1_TRUE;
	} else {
		u1_t_jdg_b10_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_04 */

	return u1_t_jdg_b10_flag;
}

/****************************************************************************/
/* �֐���		: u1_bsm_2f_compare_with_FMCW_a3							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: FMCM��r�E���������̏���a3����֐�						*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_power_up_music	: ���ݕ��W�̏����ʓd��	[in]	*/
/*				: fl_a_peak_power_up	: FMCW�s�[�N�����ʓd��	[in]	*/
/* �߂�l		: u1_t_jdg_a3_flag		: ����a3�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-04-010								*/
/*				: (5) FMCW ��r�E���������̏���a3							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_2f_compare_with_FMCW_a3(FL fl_a_power_up_music, FL fl_a_peak_power_up)
{
	/* ����a3���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_a3_flag;				/* ����a3���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_a3_flag = CU1_FALSE;

	/* ����a3�̔��� */
#if (BSM_OPTION_SW_RECOG_04 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (fl_abs(fl_a_power_up_music - fl_a_peak_power_up) > (FL)3.0F) {
		u1_t_jdg_a3_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a3_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_04 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (fl_a_power_up_music < (FL)45.0F) {
		u1_t_jdg_a3_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a3_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_04 */

	return u1_t_jdg_a3_flag;
}



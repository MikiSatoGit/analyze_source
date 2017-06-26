/****************************************************************************/
/* �t�@�C����	: BSM_RECOG_01.c											*/
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
/*	BSM AS���� int��S4,float��FL�ɕύX										*/
/*	t05					15.02.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �C���f���g�C�� //�R�����g�ύX(OBJ�ύX�Ȃ�)					*/
/*	t06					15.03.23			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo984�Ή�														*/
/*	t07					15.05.25			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No487�`489�Ή�													*/
/*	t08					15.06.02			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No436�Ή�															*/
/*	t11					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t12					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t13					15.08.31			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1503�Ή�														*/
/*	t14					15.10.27			�����Z2 1�Z�� Y.Nishioka		*/
/*	�֐��w�b�_�̒ǉ� ��OBJ�ύX�Ȃ�											*/
/*	t15					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)										*/
/*	t16					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)		*/
/*	t17					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1124�Ή�(�������C��)											*/
/*	t18					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t19					16.04.07			�����Z2 1�Z�� Y.Yamada			*/
/*	�������׌v���p�ϐ��̏����������ǉ�										*/
/*	t20					16.04.12			�����Z2 1�Z�� K.Hanabata		*/
/*	QAC�w�E�C��																*/
/*	t21					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t22					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t23					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t24					16.06.21			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t25					16.06.22			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t32					16.07.18			�����Z2 1�Z�� G.Jomori			*/
/*	291B�J���p�\�t�g��010B�\�t�g���}�[�W(010B 1A���x�[�X��0024_t822�}�[�W)	*/
/*	t37					16.08.10			�����Z2 1�Z�� Y.Nishioka		*/
/*	�֐����ύX(shareMUSIC_��ǉ�) ���I�u�W�F�N�g�ύX�Ȃ�					*/
/*	t40					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1411,1412,1413�Ή�(S4,FL,VD�ɕύX OBJ�ύX�Ȃ�)					*/
/*	t42					16.09.15			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �F������(BSM,RCTA,AUDR)�}�[�W									*/
/*	t43					16.09.23			�����Z2 1�Z�� G.Jomori			*/
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
#include "init_cvw.h"
#include "func_fmcw.h"
#include "../../common/cmn_shareMUSIC_mwr.h"

#include "bsm_recog_01.h"

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
/* �֐���		: fn_bsm_seek_prior_object									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �D�敨�W�F������											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (1)�D��s�[�N�T�[�`���� �` (5)�o�̓f�[�^�ۑ�				*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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

	U1 u1_t_up_peak_num_of_search;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */
	U1 u1_t_dn_peak_num_of_search;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */
	
	S4 s4_t_lower_limit_th;

	U1 u1_t_flg_near_target_exist;		/* �ߋ����Ƀ^�[�Q�b�g���W���݃t���O */
	S4 s4_t_lp_target_num;				/* �^�[�Q�b�g���W��for���[�v�ϐ� */

	fn_init(ast_t_normal, PRIOR_BUFFSIZE);

	/* ���W������ёւ��邽�߁A�R�s�[�p�ϐ��ɑޔ� */
	for (s4_t_lp_i = (S4)0; s4_t_lp_i < (S4)NORMAL_BUFFSIZE; s4_t_lp_i++) {
		ast_t_ast_normal_copy[s4_t_lp_i] = st_g_bsm_loop_data.ast_normal[s4_t_lp_i];
	}

	fn_sort_normal_by_power(ast_t_ast_normal_copy);

	*ps4_a_pair_num_prior = 0;

#if (MODE_ECU_SIM == ECU_MODE)
	/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐��̏����� */
	u1_g_bsm_prior_music_up_peak_num = (U1)0;		/* CheckPoint BSM_�D�敨�W�T����s�[�N��up */
	u1_g_bsm_prior_music_dn_peak_num = (U1)0;		/* CheckPoint BSM_�D�敨�W�T����s�[�N��dn */
#endif /* MODE_ECU_SIM */

	
/****************************************************************************/
/* (1)  �D��s�[�N�T�[�`����                                               */
/****************************************************************************/
	/***** (1) 2) �D��s�[�N�T�[�`�쓮�����̊m�F *****/
	if (
	   (fl_abs(fl_g_v_self_bsm_for_base) < CFL_CANOUT_VSELF_MIN)									/* COND. a1 */
	|| (s4_abs(s2_g_curvr_for_base) < CANOUT_CURVER_MIN)								/* COND. a2 */
	) {
		fn_init(ast_a_normal_prior,  PRIOR_BUFFSIZE);
		return;
	}

	u1_t_up_peak_num_of_search = 0;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */
	u1_t_dn_peak_num_of_search = 0;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */

	/* �O�� cycle �̃^�[�Q�b�g���W�����Ԏ��ӂɑ��݂��邩���`�F�b�N���� */
	/* ���݂��Ȃ��ꍇ�́A�x��G���A���̗D�敨�W�쐬�𐧌����� */
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
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */
		{
			/* ������������i�Ԗڂ̕��W�ňȍ~�̏��������{���Ȃ��ii+1�Ԗڂ̏����ցj*/
		} else {
			s4_t_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR;

			if ((ast_t_ast_normal_copy[s4_t_lp_i].fl_Rypred < FREQ_EXPAND_R_TH)
			&&  (ast_t_ast_normal_copy[s4_t_lp_i].fl_Vypred > FREQ_EXPAND_V_TH)) {
				s4_t_lower_limit_th = FREQ_BIN_LOWER_LIMIT_PRIOR_EX;
			}
			
			/***** (1) 3) �O��̕��W���̊m�F *****/
			if (
				(ast_t_ast_normal_copy[s4_t_lp_i].s4_flg_track > PRIOR_TRK_NUM)		/* COND b2 �ڑ��񐔈���ȏ��D�戵�� */
			 || (ast_t_ast_normal_copy[s4_t_lp_i].s4_flg_dc == OBJECT_TYPE_PRIOR)	/* COND b3 �O��D�戵�� */
			) {

				/* UP */
				s4_t_peak_num_prior_up = 0;
				if (ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred > FREQ_BIN_LOWER_LIMIT) {	/* COND. b4 */

					u1_t_up_peak_num_of_search++;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */

					fn_bsm_prior_init_data(
						&s4_t_peak_num_prior_up,
						afl_t_peak_bins_intpl_up,
						afl_t_peak_powers_up,
						afl_t_peak_doa_bins_intpl_up,
						afl_t_peak_doa_powers_up
					);

					/***** (1) 4) ���g��bin�̒T���͈͂̐ݒ� *****/
					fn_bsm_prior_set_peak(
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_up_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_Ayfil,
						CU2_LFM_MOD_UP,
						&s4_t_start_bin
					);

					/***** (2) 1) ���ʐ��菈���ς݃s�[�N�̊m�F *****/
					/***** (2) 2) MUSIC�ɂ��p�x�X�y�N�g�����̎Z�o *****/
					/***** (2) 3) MUSIC�p�x�X�y�N�g�����̃s�[�N�T�[�` *****/
					/***** (2) 4) BF (Beam forming) �ɂ��p�x�X�y�N�g�����̎Z�o�i�d�͐���j*****/
					/***** (2) 6) �H�ʔ��˂̏��O*****/
					/***** (2) 7) �p�x�s�[�N��� *****/
					/***** (2) 8) ���ʐ��茋�ʂ̊i�[ *****/
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
					u1_t_up_peak_num_of_search++;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */

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
					/* �������Ȃ� */
				}

				/* DOWN */
				s4_t_peak_num_prior_dn = 0;
				if (ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred > FREQ_BIN_LOWER_LIMIT) {		/* COND. b4' */

					u1_t_dn_peak_num_of_search++;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */

					fn_bsm_prior_init_data(
						&s4_t_peak_num_prior_dn,
						afl_t_peak_bins_intpl_dn,
						afl_t_peak_powers_dn,
						afl_t_peak_doa_bins_intpl_dn,
						afl_t_peak_doa_powers_dn
					);

					/* (1)�D��s�[�N�T�[�`���� - DN */
					fn_bsm_prior_set_peak(
						ast_t_ast_normal_copy[s4_t_lp_i].s4_bin_dn_pred,
						ast_t_ast_normal_copy[s4_t_lp_i].fl_Ayfil,
						CU2_LFM_MOD_DN,
						&s4_t_start_bin
					);

					/* (2) �������菈�� - DN */
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
					u1_t_dn_peak_num_of_search++;		/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐� */

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
					/* �������Ȃ� */
				}

				fn_init(&st_t_buf_normal, 1);

				/* (6), (7) �y�A�}�b�` */
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
		}		/* 50deg:����b9 & b10 & b11��END�� */
				/* 20deg:����b9 & b10 & b11 & b12��END�� */
	}

#if (MODE_ECU_SIM == ECU_MODE)
	/* �������Ԍv���p�B���ۂ�music���|������{�s�[�N�̐���ۑ� */
	u1_g_bsm_prior_music_up_peak_num = u1_t_up_peak_num_of_search;		/* CheckPoint BSM_�D�敨�W�T����s�[�N��up */
	u1_g_bsm_prior_music_dn_peak_num = u1_t_dn_peak_num_of_search;		/* CheckPoint BSM_�D�敨�W�T����s�[�N��dn */
#endif /* MODE_ECU_SIM */

	
	/***** (3) 4) ���ꕨ�W���̍폜*****/
	fn_bsm_prior_delete_same_object(
		(const S4 *)as4_t_prev_index,
		s4_t_normal_num,
		ast_t_normal,
		(const NORMAL_BSM *)ast_t_ast_normal_copy
	);

/****************************************************************************/
/* (5)   �o�̓f�[�^�ۑ�                                                     */
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
/* �֐���		: fn_bsm_prior_init_data									*/
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
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (1) 3)�O��̕��W���̊m�F								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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
/* �֐���		: fn_bsm_prior_set_peak										*/
/*--------------------------------------------------------------------------*/
/* �@�\			:  (1) 4) ���g��bin�̒T���͈͂̐ݒ� 						*/
/*				:	�\��bin�̎���PRIOR_RANGE bin���̎��g��bin�𒲂ׂ邽�߂�	*/
/*				:	�͈͂̐ݒ�												*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
VD fn_bsm_prior_set_peak(
	S4  s4_a_focus_bin,											/* [in] focus bin */
	FL fl_a_Ayfil,												/* [in] fl_a_Ayfil  */
	U2 u2_a_flg_undn,											/* [in] up/dn_flg	*/
	S4 *ps4_a_start_bin											/* [out] start_bin */
)
{
	/************** �T���͈� *************************/
	/* �ʏ펞 [focus_bin-2 �` focus_bin + 2]         */
	/* -2 -1 0 +1 +2                                 */
	/*  x  x o x  x                                  */
	/*  <----|---->                                  */
	/*       ^focus bin                              */
	/*                                               */
	/* Ay > TH (������) [focus bin-4 �` focus_bin]   */
	/* -4 -3 -2 -1 0                                 */
	/*  x  x  x  o x                                 */
	/* <---------|--								 */
	/*           ^focus bin							 */
	/*                                               */
	/* Ay > TH (������) [focus bin �` focus_bin + 4] */
	/* 0 +1 +2 +3 +4                                 */
	/* x  o  x  x  x                                 */
	/* ---|-------->                                 */
	/*    ^focus bin                                 */
	/*************************************************/

	/* UP */
	if( u2_a_flg_undn == CU2_LFM_MOD_UP)
	{
		/* ������ */
		if (fl_a_Ayfil > AY_TH_NT) {											/* COND.c1 */
			*ps4_a_start_bin = s4_a_focus_bin - (PRIOR_RANGE - 2);				/* PROC.1 */
		} else if (fl_a_Ayfil < -AY_TH_NT) {		/* ������ */				/* COND.c2 */
			*ps4_a_start_bin = s4_a_focus_bin - 1;									/* PROC.2 */
		} else {	/* ����ȊO */
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
/* �֐���		: fn_bsm_prior_estimate_doa									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)���ʐ���												*/
/*				:	FMCW�̎��g���X�y�N�g�����̃s�[�N���g���ɂ����锽�˔g��	*/
/*				:	���������̐�����s���D									*/
/*				: 1) MUSIC�ɂ��p�x�X�y�N�g�����̎Z�o						*/
/*				: 2) MUSIC�p�x�X�y�N�g�����̃s�[�N�T�[�`					*/
/*				: 3) BF(Beam forming)�ɂ��p�x�X�y�N�g�����̎Z�o(�d�͐���)	*/
/*				: 4) BF(Beam forming)�p�x�̃s�[�N�T�[�`						*/
/*				: 5) ���ʂ̑I��												*/
/*				: 6) �H�ʔ��˂̏��O											*/
/*				: 7) �p�x�s�[�N���											*/
/*				: 8) ���ʐ��茋�ʂ̊i�[										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)���ʐ���												*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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

	/* ������ */
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

		/* (3) - 2)�`7) ���ʐ��� */
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
	/* (2) - 9) ���ʐ��茋�ʂ̊i�[ */
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
/* �֐���		: fn_bsm_prior_cal_doa										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2) 1)�`7) ���ʐ���̌v�Z									*/
/*				: 1) MUSIC�ɂ��p�x�X�y�N�g�����̎Z�o						*/
/*				: 2) MUSIC�p�x�X�y�N�g�����̃s�[�N�T�[�`					*/
/*				: 3) BF(Beam forming)�ɂ��p�x�X�y�N�g�����̎Z�o(�d�͐���)	*/
/*				: 4) BF(Beam forming)�p�x�̃s�[�N�T�[�`						*/
/*				: 5) ���ʂ̑I��												*/
/*				: 6) �H�ʔ��˂̏��O											*/
/*				: 7) �p�x�s�[�N���											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-1)MUSIC�ɂ��p�x�X�y�N�g�����̎Z�o �`				*/
/*				: (2)-7) �p�x�s�[�N���										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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

		/***** (2) 6) ���ʂ̑I�� *****/
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
		/***** (2) 2) MUSIC�ɂ��p�x�X�y�N�g�����̎Z�o *****/
		s4_t_wave_num = s4_calc_spec_music_4ch_all(
			afl_a_Ryy[s4_a_focus_bin],		/* [in] */
			afl_t_spec_doa,					/* [out] */
			2,								/* [in] */
			s4_a_flg_updn					/* [in] */
		);
		/***** (2) 3) MUSIC�p�x�X�y�N�g�����̃s�[�N�T�[�` *****/
		/***** (ii) �p�x�X�y�N�g�����̃s�[�N�T�[�` *****/
		*ps4_a_doa_num = s4_search_peak_music(
			(const FL *)afl_t_spec_doa,		/* [in] */
			as4_t_selected_doa_bins,		/* [out] [2] DOA peak bin */
			afl_a_selected_doa_powers,		/* [out] [2] afl_a_power of DOA peak */
			s4_t_wave_num
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_20161116_BTT_DOA_RANGE_T)
			,OBJECT_TYPE_PRIOR
#endif
		);
		/***** (2) 4) BF (Beam forming) �ɂ��p�x�X�y�N�g�����̎Z�o�i�d�͐���j*****/
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

	/***** (2) 8) �p�x�s�[�N��� *****/
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
	
	/***** (2) 9) ���ʐ��茋�ʂ̊i�[(LCA�Ƃ̋��L�s�[�N���֊i�[) *****/
	fn_cmn_shareMUSIC_set_finished_music_data_main( (U1)s4_a_flg_updn,
													(U1)*ps4_a_doa_num,
													(U2)s4_a_focus_bin,
													afl_a_selected_bins_intpl[0],
													afl_a_selected_doa_bins_intpl,
													afl_a_selected_doa_powers);

	/* �H�ʔ��˕t�߂�freq bin��doa���^��t�߂̏ꍇ�͑O��l�������p���ŕ⊮���� */
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
/* �֐���		: fn_bsm_prior_store_doa									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-9)���ʐ��茋�ʂ̊i�[									*/
/*				: MUSIC���ʓW�J���������{�����ꍇ�ALCA�Ƃ̃s�[�N��񋤗L	*/
/*				: �o�b�t�@�Ɍ��ʂ��i�[����B								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-9)���ʐ��茋�ʂ̊i�[									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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
	/* �y�A�}�b�`�p�̕��ʐ��茋�ʂ��i�[ */
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
/* �֐���		: fn_bsm_prior_estimate_doa_around_dc						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-4)�`5) BF(Beam forming)�ɂ��p�x����					*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (2)-4)�`5) BF(Beam forming)�ɂ��p�x����					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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

	/* ���[�J���ϐ������� */
	for (u1_t_lp_n_doa = (U1)0; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		afl_t_doa_spec[u1_t_lp_n_doa] = (FL)0.0F;
	}
	s4_t_doa[0] = (S4)0;
	fl_t_peak_power[0] = (FL)0.0F;

	/***** (2) 4) BF (Beam forming) �ɂ��p�x�X�y�N�g�����̎Z�o�i�d�͐���j *****/
	fn_calc_spec_bf_4ch_fm(
		(const FL *)(afl_a_Ryy[s4_a_focus_bin]),	/* [in] */
		afl_t_doa_spec,								/* [out] */
		s4_a_flg_updn,								/* [in] */
		s4_a_focus_bin								/* [in] */
	);
	/***** (2) 5)BF (Beam forming) �p�x�̃s�[�N�T�[�` *****/
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
/* �֐���		: u1_bsm_prior_make_pair									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (0) �ړ����y�A�}�b�`���� & (3)���W���Z�o�����i�ړ����j	*/
/*				: (0)-1)�\�����ʂƂ̍������͈͓��œd�͍ő�̂��̂�I��	*/
/*				: (3)-1)���ԑ������̏��/����̎��g��bin�����Z�o			*/
/*				: (3)-2)�p�x���̋��e�͈͂̐ݒ�								*/
/*				: (3)-3)���W���̎Z�o�ƕۑ�								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (0)�ړ����y�A�}�b�`���� & (3)���W���Z�o�����i�ړ���)	*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	S4 s4_t_doa_diff_predict;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	/****************************************************************************/
	/* (3)	�ړ����y�A�}�b�`����												*/
	/****************************************************************************/
	/***** (3) 1) �\�����ʂƂ̍������͈͓��œd�͍ő�̂��̂�I�� *****/
	/* make pair */
	s4_t_index_up1 = -1;
	s4_t_index_dn1 = -1;
	s4_t_index_up2 = -1;
	s4_t_index_dn2 = -1;

	/* Set the threshold of DOA difference between predicted DOA and detected DOA */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT;
	if (fl_g_v_self_bsm_for_base < (FL)CANOUT_VSELF_SLOW) {			/* COND.a30 */
		s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT - (S4)2;		/* PROC.5 */
	}

	if (st_g_bsm_loop_data.s4_flg_alarm == (S4)1) {					/* COND.a31 */
		s4_t_doa_diff_predict = (S4)DOA_DIFF_PREDICT + (S4)2;		/* PROC.6 */
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	fl_t_buf_comp = 0.0F;							/* PROC.1 */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_prior_up; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 2; s4_t_lp_j++) {
			/* ����a2�̔���֐��R�[�� �d�l���̋L�q������a2�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
			/* ����a2�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����								*/
			/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�			*/
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
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	if ((s4_t_index_up1 >= (S4)0)
	&&  (s4_t_index_up2 >= (S4)0)) {
		if ((afl_a_peak_powers_up[s4_t_index_up1][s4_t_index_up2] < (FL)50.0F)		/* COND.a32 */
		&&  (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1))) {						/* COND.!a31 */
			s4_t_index_up1 = (S4)-1;
			s4_t_index_up2 = (S4)-1;
		}
	} else {
		/* s4_t_index_up1,s4_t_index_up2�̂ǂ��炩�������l�̏ꍇ�͏���a32�̔�����s�킸TRUE�Ƃ݂Ȃ� */
		if (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1)) {							/* COND.!a31 */
			s4_t_index_up1 = (S4)-1;
			s4_t_index_up2 = (S4)-1;
		}
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	fl_t_buf_comp = 0.0F;							/* PROC.1' */
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_prior_dn; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < 2; s4_t_lp_j++) {
			/* ����a2�̔���֐��R�[�� �d�l���̋L�q������a2�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
			/* ����a2�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����								*/
			/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�			*/
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
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	if ((s4_t_index_dn1 >= (S4)0)
	&&  (s4_t_index_dn2 >= (S4)0)) {
		if ((afl_a_peak_powers_dn[s4_t_index_dn1][s4_t_index_dn2] < (FL)50.0F)		/* COND.a32 */
		&&  (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1))) {						/* COND.!a31 */
			s4_t_index_dn1 = (S4)-1;
			s4_t_index_dn2 = (S4)-1;
		}
	} else {
		/* s4_t_index_up1,s4_t_index_up2�̂ǂ��炩�������l�̏ꍇ�͏���a32�̔�����s�킸TRUE�Ƃ݂Ȃ� */
		if (!(st_g_bsm_loop_data.s4_flg_alarm == (U1)1)) {							/* COND.!a31 */
			s4_t_index_dn1 = (S4)-1;
			s4_t_index_dn2 = (S4)-1;
		}
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */


	/****************************************************************************/
	/* (3)	���W���Z�o�����i�ړ����j											*/
	/****************************************************************************/
	u1_make_pair_result = CU1_FALSE;
	/***** (3) 1) ���ԑ������̏��/����̎��g��bin�����Z�o *****/
	s4_t_shift = (S4)((fl_g_v_self_bsm_for_base / 3.60F / VCOF) + 0.50F);
	if ((s4_t_index_up1 >= 0)
	&&  (s4_t_index_up2 >= 0)
	&&  (s4_t_index_dn1 >= 0)
	&&  (s4_t_index_dn2 >= 0)) {
		/* ����a6,a7,a8�̔���֐��R�[�� �d�l���̋L�q������a6,a7,a8�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
		/* ����a6,a7,a8�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����										*/
		/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�						*/
		/* �z��O�Q�Ƃ�h�����߁A��������֐��͏���a1�`a4�������̂݃R�[������									*/
		u1_t_jdg_a6_flg = u1_bsm_prior_make_pair_a6(afl_a_peak_doa_powers_up[s4_t_index_up1][s4_t_index_up2], fl_a_power_up_music);
		u1_t_jdg_a7_flg = u1_bsm_prior_make_pair_a7(afl_a_peak_doa_powers_dn[s4_t_index_dn1][s4_t_index_dn2], fl_a_power_dn_music);
		u1_t_jdg_a8_flg = u1_bsm_prior_make_pair_a8(afl_a_peak_bins_intpl_up[s4_t_index_up1][s4_t_index_up2], afl_a_peak_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2]);

		if (((afl_a_peak_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])  < (FL)(s4_t_shift - 3))		/* COND.a5 */
		&&  (u1_t_jdg_a6_flg == CU1_TRUE)																														/* COND.a6 */
		&&  (u1_t_jdg_a7_flg == CU1_TRUE)) {																													/* COND.a7 */
		/***** (3) 2) �p�x���̋��e�͈͂̐ݒ�*****/
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			S4 s4_t_doa_diff_up_down = DOA_DIFF_UP_DOWN;		/* PROC.1 */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			S4 s4_t_doa_diff_up_down = (S4)CU1_DOA_DIFF_UP_DOWN_PRIOR;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */
			if ((fl_g_v_self_bsm_for_base < CANOUT_VSELF_SLOW)		/* COND.a9 */
			&&  (u1_t_jdg_a8_flg == CU1_TRUE)) {					/* COND.a8 */
				s4_t_doa_diff_up_down = DOA_DIFF_UP_DOWN_SLOW;		/* PROC.1 */
			}

#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			if (st_g_bsm_loop_data.u1_truck_flg != (U1)0) {			/* COND.a33 */
				s4_t_doa_diff_up_down += (S4)2;						/* PROC.2 */
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

			/***** (3) 3) ���W���̎Z�o�ƕۑ�*****/
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
			if ((s4_a_normal_prior_num < (S4)PRIOR_BUFFSIZE) 																															/* CONT.b1 */
			&&  (s4_abs((S4)(afl_a_peak_doa_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])) < s4_t_doa_diff_up_down)		/* COND.b2 */
			&&  (fl_abs(afl_a_peak_doa_powers_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_powers_dn[s4_t_index_dn1][s4_t_index_dn2]) < POW_DIFF_UP_DOWN_DOA))					/* COND.b3 */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
			if ((s4_a_normal_prior_num < (S4)PRIOR_BUFFSIZE) 																															/* CONT.b1 */
			&&  (s4_abs((S4)(afl_a_peak_doa_bins_intpl_up[s4_t_index_up1][s4_t_index_up2] - afl_a_peak_doa_bins_intpl_dn[s4_t_index_dn1][s4_t_index_dn2])) < s4_t_doa_diff_up_down))	/* COND.b2 */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
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
					0,																/* ��~���t���O */
					0																/* �Ѓs�[�N�t���O */
				);
				u1_make_pair_result = CU1_TRUE;
			}
		}
	}

	return (u1_make_pair_result);
}

/****************************************************************************/
/* �֐���		: u1_bsm_prior_make_pair_a2									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �ړ����y�A�}�b�`�����̏���a2����֐�						*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_peak_doa_bins_intpl	: ���ʕ��bin [in]				*/
/*				: fl_a_focus_doa_bin_intpl	: �O��̗\������bin [in]		*/
/*				: fl_a_doa_diff_predict		: ����臒l [in]					*/
/* �߂�l		: u1_t_jdg_a2_flag		: ����a2�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (3) �ړ����y�A�}�b�`�����̏���a2							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a2(FL fl_a_peak_doa_bins_intpl, FL fl_a_focus_doa_bin_intpl, FL fl_a_doa_diff_predict)
{
	/* ����a2���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_a2_flag;				/* ����a2���茋�ʊi�[�ϐ� */
	FL fl_t_diff_doa_bin_intpl_abs;		/* ���ʕ��bin�ƑO��̗\������bin�̍��̐�Βl */

	/* FALSE�ŏ����� */
	u1_t_jdg_a2_flag = CU1_FALSE;

	fl_t_diff_doa_bin_intpl_abs = fl_abs(fl_a_peak_doa_bins_intpl - fl_a_focus_doa_bin_intpl);

	/* ����a2�̔��� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (fl_t_diff_doa_bin_intpl_abs < (FL)DOA_DIFF_PREDICT) {
		u1_t_jdg_a2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a2_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (fl_t_diff_doa_bin_intpl_abs < fl_a_doa_diff_predict) {
		u1_t_jdg_a2_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a2_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a2_flag;
}

/****************************************************************************/
/* �֐���		: u1_bsm_prior_make_pair_a6									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���W���Z�o�����i�ړ����j �̏���a6����֐�				*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_peak_doa_powers_up	: �����ʓd�� [in]				*/
/*				: fl_a_power_up_music		: �O��̏��music�d�� [in]		*/
/* �߂�l		: u1_t_jdg_a6_flag			: ����a6�̔��茋�ʊi�[�ϐ�		*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  ���W���Z�o�����i�ړ����j �̏���a6					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a6(FL fl_a_peak_doa_powers_up, FL fl_a_power_up_music)
{
	/* ����a6���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_a6_flag;				/* ����a6���茋�ʊi�[�ϐ� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_doa_power_up_abs;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSE�ŏ����� */
	u1_t_jdg_a6_flag = CU1_FALSE;

	/* ����a6�̔��� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if ((fl_a_peak_doa_powers_up - fl_a_power_up_music) > PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a6_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	fl_t_diff_doa_power_up_abs = fl_abs(fl_a_peak_doa_powers_up - fl_a_power_up_music);

	if (fl_t_diff_doa_power_up_abs < PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a6_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a6_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a6_flag;
}

/****************************************************************************/
/* �֐���		: u1_bsm_prior_make_pair_a7									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���W���Z�o�����i�ړ����j �̏���a7����֐�				*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_peak_doa_powers_dn	: ������ʓd�� [in]				*/
/*				: fl_a_power_dn_music		: �O��̉���music�d�� [in]		*/
/* �߂�l		: u1_t_jdg_a7_flag			: ����a7�̔��茋�ʊi�[�ϐ�		*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  ���W���Z�o�����i�ړ����j �̏���a7					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a7(FL fl_a_peak_doa_powers_dn, FL fl_a_power_dn_music)
{
	/* ����a7���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_a7_flag;				/* ����a7���茋�ʊi�[�ϐ� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_doa_power_dn_abs;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSE�ŏ����� */
	u1_t_jdg_a7_flag = CU1_FALSE;

	/* ����a7�̔��� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if ((fl_a_peak_doa_powers_dn - fl_a_power_dn_music) > PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a7_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a7_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	fl_t_diff_doa_power_dn_abs = fl_abs(fl_a_peak_doa_powers_dn - fl_a_power_dn_music);

	if (fl_t_diff_doa_power_dn_abs < PRIOR_PEAK_POW_DIFF_TH) {
		u1_t_jdg_a7_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a7_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a7_flag;
}

/****************************************************************************/
/* �֐���		: u1_bsm_prior_make_pair_a8									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: ���W���Z�o�����i�ړ����j �̏���a8����֐�				*/
/*--------------------------------------------------------------------------*/
/* ����			: fl_a_peak_bins_intpl_up	: �����g�����bin [in]		*/
/*				: fl_a_peak_bins_intpl_dn	: ������g�����bin [in]		*/
/* �߂�l		: u1_t_jdg_a8_flag			: ����a8�̔��茋�ʊi�[�ϐ�		*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-013(291BCV)						*/
/*				: (4)  ���W���Z�o�����i�ړ����j �̏���a8					*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_bsm_prior_make_pair_a8(FL fl_a_peak_bins_intpl_up, FL fl_a_peak_bins_intpl_dn)
{
	/* ����a8���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_a8_flag;				/* ����a8���茋�ʊi�[�ϐ� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	FL fl_t_diff_peak_bin_intpl_abs;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	/* FALSE�ŏ����� */
	u1_t_jdg_a8_flag = CU1_FALSE;

	/* ����a8�̔��� */
#if (BSM_OPTION_SW_RECOG_01 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if ((fl_a_peak_bins_intpl_up - fl_a_peak_bins_intpl_dn) > (FL)1.0F) {
		u1_t_jdg_a8_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a8_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_01 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	fl_t_diff_peak_bin_intpl_abs = fl_abs(fl_a_peak_bins_intpl_up - fl_a_peak_bins_intpl_dn);

	if (fl_t_diff_peak_bin_intpl_abs > (FL)1.0F) {
		u1_t_jdg_a8_flag = CU1_TRUE;
	} else {
		u1_t_jdg_a8_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_01 */

	return u1_t_jdg_a8_flag;
}


/****************************************************************************/
/* �֐���		: fn_bsm_prior_delete_same_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3) 4) ���ꕨ�W���̍폜									*/
/*				: ����X�V�������W���̒��œ���̃s�[�N�������̂�����ꍇ*/
/*				: �O��̗\���ʒu�E���x�ɂ����Ƃ��߂����̂�I������B		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (3) 4) ���ꕨ�W���̍폜									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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
/* �֐���		: fn_bsm_prior_set_object									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)�o�̓f�[�^�ۑ�											*/
/*				: �O���܂ł̏����ɂĎZ�o�������ʂ��A�D�敨�W���i�����l�j*/
/*				: �D�敨�W���i���������l�j�A�D�敨�W�����o�͂���B		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-01-011.pdf							*/
/*				: (5)�o�̓f�[�^�ۑ�											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
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
	/* (5)   �o�̓f�[�^�ۑ�                                                     */
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


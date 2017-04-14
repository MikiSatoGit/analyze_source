/****************************************************************************/
/* �t�@�C����	: BSM_RECOG_03.c											*/
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
/*	t04					15.02.26			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� int��S4,float��FL�ɕύX,���[�j���O�Ή�,�s�v�֐��폜			*/
/*	t05					15.02.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� _ALWAYS_CHECK_FR_SOT��#ifdef�폜								*/
/*	t06					15.02.27			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �C���f���g�C�� //�R�����g�ύX(OBJ�ύX�Ȃ�)					*/
/*	t07					15.03.13			�����Z2 1�Z�� G.Jomori			*/
/*	BSM AS���� �ϐ������������ǉ�											*/
/*	t08					15.03.23			�����Z2 1�Z�� G.Jomori			*/
/*	BSM��v�m�F�Ŕ��������o�O�C��											*/
/*	t11					15.05.25			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No482�`486�Ή�													*/
/*	t12					15.05.25			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No484�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t13					15.05.26			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No492�Ή�															*/
/*	t14					15.06.01			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No483�C��															*/
/*	t15					15.06.02			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No438,443,444�Ή�													*/
/*	t19					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(DR���{��)												*/
/*	t20					15.08.06			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή�(�R�[�h�N���X�ŗǂ���)									*/
/*	t21					15.08.07			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �F�����֑Ή� ��v�m�F���ɔ��������o�O�C��							*/
/*	t22					15.08.19			�����Z2 1�Z�� G.Jomori			*/
/*	��v�m�F���ɔ��������o�O�C�� ������������DBF�W�J���ʂ𗬗p����			*/
/*	t23					15.08.31			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1458,1496�`1501,1555�`1563,1579�`1582,1599�Ή�				*/
/*	t24					15.09.11			�����Z2 1�Z�� G.Jomori			*/
/*	MWR-RECO-24G-BSM-RECOG-03-008�Ή�										*/
/*	t25					15.10.27			�����Z2 1�Z�� Y.Nishioka		*/
/*	�֐��w�b�_�̒ǉ� ��OBJ�ύX�Ȃ�											*/
/*	t26					15.11.17			�����Z2 1�Z�� G.Jomori			*/
/*	BSM CV�Ή�																*/
/*	t27					15.11.18			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No970�Ή�(OBJ�ύX�Ȃ�)											*/
/*	t28					15.11.20			�����Z2 1�Z�� G.Jomori			*/
/*	�ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)										*/
/*	t29					15.11.25			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo.1722,1756,1757,1763,1774,1790�Ή�							*/
/*	t30					15.11.26			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo.1744�Ή�(OBJ�ύX�Ȃ�)										*/
/*	t31					15.12.04			�����Z2 1�Z�� G.Jomori			*/
/*	BSM ����N���X�w�E�Ή�													*/
/*	t32					16.01.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�												*/
/*	t33					16.01.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM BSM�]���p�d�l�Ή�(OBJ�ύX�Ȃ�)									*/
/*	t34					16.01.27			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM ����Z���t�Ή�													*/
/*	t36					16.01.29			�����Z2 1�Z�� G.Jomori			*/
/*	t247�}�[�W																*/
/*	t37					16.03.01			�����Z2 1�Z�� G.Jomori			*/
/*	010B BSM CV-R�d�l�Ή�													*/
/*	t38					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1198�Ή�(���[�J���z��ϐ��̐錾�Ɠ����Ɏ��{�̏���������)		*/
/*	t39					16.03.03			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1098,1193�Ή�(�����K�[�h�A�s�v�����폜)							*/
/*	t40					16.03.07			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo1707�Ή�(�z�񐔕ύX)											*/
/*	t41					16.03.11			�����Z2 1�Z�� G.Jomori			*/
/*	010B CV-R 3/8���s MWR-RECO-24G-BSM-RECOG-03-013�Ή�						*/
/*	t42					16.03.25			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l�Ή�														*/
/*	t43					16.03.28			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/*	t44					16.03.29			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM CV�d�l �ǂݍ��킹�w�E�����Ή�(OBJ�ύX�Ȃ�)						*/
/*	t45					16.03.30			�����Z2 1�Z�� G.Jomori			*/
/*	291B BSM 20deg�̂Ƃ��̂ݎg�p����ϐ��E�֐����R���p�C���I�v�V�����ň͂�(OBJ�ύX�Ȃ�)*/
/*	t46					16.04.01			�����Z2 1�Z�� G.Jomori			*/
/*	010B 291B MWR-RECO-24G-BSM-RECOG-03-014�Ή�								*/
/*	t47					16.04.07			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC �w�E�Ή�														*/
/*	t48					16.04.12			�����Z2 1�Z�� G.Jomori			*/
/*	QAC �w�E�Ή�(OBJ�ύX�Ȃ�)												*/
/*	t50					16.06.03			�����Z2 1�Z�� Y.Hosoi			*/
/*	�c�ۑ�No202�Ή�															*/
/*	t51					16.06.20			�����Z2 1�Z�� H.Nonogaki		*/
/*	QAC �w�E�Ή�(OBJ�ύX����)												*/
/*	t52					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t53					16.06.20			�����Z2 1�Z�� G.Jomori			*/
/*	BSM �c�ۑ�No1336�Ή� OBJ�ύX�Ȃ�										*/
/*	t54					16.06.21			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	t55					16.06.22			�����Z2 1�Z�� G.Jomori			*/
/*	BSM QAC�w�E�����C�� OBJ�ύX�Ȃ�											*/
/*	p00					16.07.06			�����Z2 1�Z�� Y.Nishioka		*/
/*	010B 1A�[���̂���P�������{												*/
/*	t64					16.07.18			�����Z2 1�Z�� G.Jomori			*/
/*	291B�J���p�\�t�g��010B�\�t�g���}�[�W(010B 1A���x�[�X��0024_t822�}�[�W)	*/
/*	t71					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1411,1412,1413�Ή�(S4,FL,VD�ɕύX OBJ�ύX�Ȃ�)					*/
/*	t72					16.08.22			�����Z2 1�Z�� G.Jomori			*/
/*	�c�ۑ�No1414,1415�Ή�(�֐���`�ړ�)										*/
/*	t74					16.09.15			�����Z2 1�Z�� G.Jomori			*/
/*	010B 2A �F������(BSM,RCTA,AUDR)�}�[�W									*/
/*	t75					16.09.23			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R�d�l�Ή�														*/
/*	t76					16.09.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R BSM ����Z���t�Ή�(OBJ�ύX�Ȃ�)								*/
/*	t77					16.09.26			�����Z2 1�Z�� G.Jomori			*/
/*	291B CV-R BSM �ǂݍ��킹�w�E�Ǝd�l�m�FNo2781�Ή�						*/
/*	t78					16.09.27			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo2783,2784�Ή�													*/
/*	t79					16.09.28			�����Z2 1�Z�� G.Jomori			*/
/*	��v�m�F�Ŕ��������o�O�C�� 												*/
/*	t80					16.09.29			�����Z2 1�Z�� G.Jomori			*/
/*	�d�l�m�FNo2812�Ή�														*/
/*	t81					16.09.29			�����Z2 1�Z�� G.Jomori			*/
/*	��v�m�F�Ŕ��������o�O�C�� 												*/
/****************************************************************************/

/****************************************************************************/
/*							�C���N���[�h�t�@�C��							*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../parameter_adj.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "init_cvw.h"
#include "func_fmcw.h"
#include "func_fsk.h"
#include "bsm_connect_01.h"
#include "../bsm_public_inc.h"
#include "../../common/cmn_autoaxis_mwr.h"
#include "../../common/cmn_slipjdg_mwr.h"

#include "bsm_recog_03.h"

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
S4 s4_peak_search_music_fsk_all_doa(
	FL music_spec[N_DOA_2F],			/* [in] */
	S4 bin_music[2],					/* [out] */
	FL power_music[2],					/* [out] */
	S4 wave_num_in						/* [in] */
);

static S4 s4_bsm_side_check_fm_approaching_object(
	const FL afl_a_sot_thres_up[NB_FFT_PT],
	const FL afl_a_sot_thres_dn[NB_FFT_PT],
	const S4 as4_a_wall_check_up[3],
	const S4 as4_a_wall_check_dn[3],
	const S4 as4_a_wall_bin_up[3],
	const S4 as4_a_wall_bin_dn[3],
	const FL afl_a_wall_pow_up[3],
	const FL afl_a_wall_pow_dn[3]
);

S4 check_fm_object(									/* [return] object flag */
	const NORMAL_BSM ast_a_normal_sot_prev[1],		/* [in] object data */
	S4 s4_a_leading_flg,							/* [in] leading car flag */
	NORMAL_BSM ast_a_normal_sot[1]					/* [out] object data */
);

S4 check_fm_spectrum(								/* [return] approaching object flag */
	FL sot_thres_up[NB_FFT_PT],						/* [out](for debug) threashold for wall estimation�iFM up) */
	FL sot_thres_dn[NB_FFT_PT]						/* [out](for debug) threashold for wall estimation�iFM dn) */
);

VD set_freq_threshold_without_center_mask(
	const FL power[NB_FFT_PT],	/* [in] power of beat signal */
	FL thres[NB_FFT_PT]			/* [out] threshold for peak detection */
);

S4 set_wall_freq_threshold(					/* [return](not used) number of steps */
	const FL thres[NB_FFT_PT],				/* [in] threshold for peak detection */
	FL wall_thres[NB_FFT_PT],				/* [out] threshold for peak detection */
	S4 wall_check[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 wall_bin[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	FL wall_pow[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 freq_start,							/* [in] */
	S4 freq_end								/* [in] */
);

S4 seek_freq_step(				/* [return] 0:no more step, 1:have next step */
	const FL thres[NB_FFT_PT],	/* [in] threshold for peak detection */
	S4 end_index,				/* [in] end point of freq-bin */
	FL pow_range,				/* [in] range of freq-power to treat as the same step  */
	FL pow[1],					/* [in/out] freq-pow of this step */
	S4 index[1],				/* [in/out] start point of this step */
	S4 count[1],				/* [out] number of freq-bin of this step  */
	S4 next_index[1]			/* [out] end point of this step(start point of next step) */
);

VD set_stationary_doa_line_2f(
	S4 stationary_doa_line[N_DOA],				/* [out] ��~����DOA/FREQ */
	S4 v0_doa_def,								/* [in] ���o�������x�]�����̋ߎ�������Ԃ̕����𐄒�(��肩��) */
	S4 v0_doa									/* [in] ���o�������x�]�����̋ߎ�������Ԃ̕����𐄒�(��肩��) */
);

VD set_sot_limit_doa_line_2f(
	S4 sot_limit_doa_line[N_DOA],				/* [out] SoT��DOA/FREQ */
	S4 v0_doa_def,								/* [in] */
	S4 v0_doa,									/* [in] */
	FL v_sot_offset								/* [in] */
);

U1 calc_nearfield_doa_2f_I(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 130-144bin��DOA�s�[�N(�ő�1��/1bin) */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] ��L�ebin��DOA�s�[�N��(�ő�1��) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 calc_nearfield_doa_2f_Q(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 126-112bin��DOA�s�[�N(�ő�1��/1bin) */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] ��L�ebin��DOA�s�[�N��(�ő�1��) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 compare_forward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
);

U1 compare_backward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	S4 stationary_doa_line[N_DOA],									/* [in] */
	S4 sot_limit_doa_line_backward[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	FL v_sot_offset,												/* [in] */
	const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
);

S4 check_sot_start(											/* [return] */
	FL dev[2],												/* [in] */
	U1 u1_a_alarming_flag
);

static U1 u1_check_sot_start_h84(S4 s4_a_fwd_peak_val, S4 s4_a_bwd_peak_val);

S4 check_sot_stop(											/* [return] */
	const FL dev[2]											/* [in] */
);

S4 check_sot_on(											/* [return] */
	const FL dev[2]											/* [in] */
);

S4 check_sot_off(											/* [return] */
	const FL dev[2]											/* [in] */
);

VD fn_bsm_low_judge_check_sot_doa(FL* pfl_a_fast_sot_pow);

FL calc_deviation_of_doa_freq_line_stationary_2(					/* [return] deviation of ovserved doa-freq points */
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] 130-145bin��DOA�s�[�N */
	S4 start_freq_bin,												/* [in]	start freq-bin */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 mode															/* [in] 0:I, 1:Q */
	,S4 *backward_priod												/* [out] use backward dev */
	,S4 v0_doa														/* [in] */
	,S4 *fast_sot_num												/* [out] */
	,S4 *not_fast_sot_num											/* [out] */
	,S4 fast_sot_limit_line[N_DOA]									/* [out] */
	,const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4]
);

static VD fn_bsm_low_calc_deviation(
	S4 s4_a_forward_priod,
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_stationary_doa_line[N_DOA],
	S4 *ps4_a_backward_priod,
	FL afl_a_buf_dev[2],
    S4 s4_a_v0_doa,
    S4 *ps4_a_fast_sot_num,
    S4 *ps4_a_not_fast_sot_num,
    FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
    FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
);

static VD fn_bsm_low_judge_sot(
	S4 as4_stationary_doa_line[N_DOA],
	S4 as4_sot_limit_doa_line_forward[N_DOA],
	S4 as4_sot_limit_doa_line_backward[N_DOA],
	const S4 as4_a_nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_a_nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 s4_a_forward_priod,
	S4 s4_a_backward_priod,
	FL afl_a_buf_dev[2],
	FL *pfl_a_dev,
	S4 v0_doa,
	U1 u1_a_alarming_flag,
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
	U1* pu1_a_num_forward,
	U1* pu1_a_num_backward
);
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͊֐���`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
VD fn_bsm_low_judge_check_tos(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
							  FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
							  U1* pu1_a_tos_end_flg,
							  U1* pu1_a_num_i,
							  U1* pu1_a_num_q,
							  U1* pu1_a_tos_flg);

static S4 s4_bsm_low_judge_sot_jdg_noise_flg(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
											 FL afl_a_buf_dev[2],
											 S4 s4_a_slow_sot_find1_pre,
											 FL* pfl_a_ave_i_y,
											 U1* pu1_a_noise_flg);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

static VD fn_bsm_low_judge_wall(
	const FL afl_a_buf_dev[2],
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	U1 u1_a_num_forward,
	U1 u1_a_num_backward
);

static VD fn_bsm_low_judge_wall_forward_deviation_small(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	S4 s4_a_backward_point
);

static VD fn_bsm_low_judge_wall_forward_deviation_big(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
);

static VD fn_bsm_low_judge_wall_when_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_backward_point
);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
);
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	U1* pu1_a_wall_checked_flag
);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͊֐���`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static S4 s4_bsm_low_judge_wall_proc8(S4 s4_a_sot_find_1);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

static VD fn_bsm_low_judge_fast_sot(
	S4 s4_a_fast_sot_num,
	S4 s4_a_not_fast_sot_num,
	U1 u1_a_alarming_flag
);


static VD fn_bsm_low_judge_exist_leading_car_main(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
												  const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]);

static VD fn_bsm_low_judge_exist_leading_car_set_jdg_area(FL* pfl_a_area_x_near,
														  FL* pfl_a_area_x_far,
														  FL* pfl_a_area_y_forward,
														  FL* pfl_a_area_y_backward);

static VD fn_bsm_low_judge_exist_leading_car_calc_char(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL fl_a_area_x_near,
													   const FL fl_a_area_x_far,
													   const FL fl_a_area_y_forward,
													   const FL fl_a_area_y_backward,
													   U1* pu1_a_Ni,
													   U1* pu1_a_Nq,
													   FL* pfl_a_ave_theta_i,
													   FL* pfl_a_ave_theta_q,
													   FL* pfl_a_var_theta_i,
													   FL* pfl_a_var_theta_q,
													   U1* pu1_a_flg_point_many,
													   U1* pu1_a_flg_point_bias);

static VD fn_exist_leading_car_calc_char_iq(const S4 as4_a_nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],
											const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4],
											const FL fl_a_area_x_near,
											const FL fl_a_area_x_far,
											const FL fl_a_area_y_forward,
											const FL fl_a_area_y_backward,
											U1* pu1_a_N,
											FL* pfl_a_ave_theta,
											FL* pfl_a_var_theta);

static VD fn_bsm_low_judge_exist_leading_car_jdg(const U1 u1_a_Ni,
												 const U1 u1_a_Nq,
												 const FL fl_a_ave_theta_i,
												 const FL fl_a_ave_theta_q,
												 const FL fl_a_var_theta_i,
												 const FL fl_a_var_theta_q,
												 const U1 u1_a_flg_point_many,
												 const U1 u1_a_flg_point_bias);

static VD fn_bsm_low_judge_exist_leading_car_mediation(VD);



static FL fl_bsm_side_cal_fm_nearfield_power( VD );

static VD fn_bsm_side_check_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_wall_reject_th
);

static VD fn_bsm_side_check1_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_wall_reject_th
);

static VD fn_bsm_side_check2_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle
);

static VD fn_bsm_side_set_leading_object(
	S4 s4_a_leading_flg2,						/* [in] */
	const NORMAL_BSM ast_a_normal_fm[1],		/* [in] */
	NORMAL_BSM ast_a_normal_heisou[1]			/* [out] */
);

static VD fn_bsm_side_check_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 *ps4_a_wall_flg,
	NORMAL_BSM ast_a_normal_wall[1],
	S4 s4_a_wall_reject_th
);

static VD fn_bsm_side_check1_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	S4 *ps4_a_wall_flg,
	S4 s4_a_wall_reject_th
);

static VD fn_bsm_side_set_wall_object(
	S4 s4_a_wall_flg,
	const NORMAL_BSM ast_a_normal_fm[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_tracking_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_wall_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_tracking_wall_with_obs(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_intpl_cur_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],			/* [in]  */
	NORMAL_BSM ast_a_normal_wall[1]						/* [out] */
);

static VD fn_bsm_side_tracking_wall_without_obs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_guard_wall_rxfil(
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_confirm_prev_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	FL *pfl_a_wall_pos
);

static VD fn_bsm_side_cal1_next_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static FL fl_bsm_side_cal1_cal_wall_rxobs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1]
);

static VD fn_bsm_side_cal2_next_wall_object(
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_cal3_next_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
);

static VD fn_bsm_side_guard_wall_xpred(
	NORMAL_BSM ast_a_normal_wall[1]
);

static S4 s4_bsm_side_tracking_heisou(
	FL fl_a_fm_nearfield_power,
	S4 s4_a_fm_obj_flg,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static S4 s4_bsm_side_tracking_heisou_with_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static S4 s4_bsm_side_tracking_heisou_without_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	NORMAL_BSM ast_a_normal_sot[1]
);

static VD fn_bsm_side_check_tracking_heisou_range(
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot[1]
);

VD fn_bsm_side_check_wall_for_erase_fa_seg(const NORMAL_BSM ast_a_normal_sot_ena[1], S4 s4_a_fm_obj_flg);

/****************************************************************************/
/* �֐���		: s4_seek_sidewinder										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �O�������̔F��											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 s4_seek_sidewinder(										/* [return] number of detected objects(0 or 1) */
	NORMAL_BSM ast_a_normal_wall[1],						/* [in/out] S4 values of NORMAL_BSM structure */
	NORMAL_BSM ast_a_normal_sot[1]							/* [in/out] S4 values of NORMAL_BSM structure */
)
{
	/************** �ϐ��錾 **************/
	S4 object_num = 0;

	S4 tmp_fm_obj_flg = 0;												/* FM���W�t���O */
	S4 tmp_fm_flg = 0;													/* FM�ڋߔ���t���O */
	S4 tmp_wall_flg = 0;												/* �ǃt���O */
	S4 tmp_leading_flg1 = st_g_bsm_loop_data.as4_flg_leading[0];		/* �����ԃt���O�P */
	S4 tmp_leading_flg2 = st_g_bsm_loop_data.as4_flg_leading[0];		/* �����ԃt���O�Q */

	/* �X�^�b�N�e�ʍ팸�΍�ňꕔ�ϐ��폜	*/
	/* �X�Ȃ錟���K�v					*/
	/* ���W��� */
	NORMAL_BSM tmp_normal[1];

	/* �ǌ�� */
	NORMAL_BSM normal_wall[1];
	NORMAL_BSM normal_wall_prev[1];

	/* �Ԍ�� */
	NORMAL_BSM tmp_normal_sot[1];
	NORMAL_BSM normal_sot[1];
	NORMAL_BSM normal_sot_prev[1];

	/* ���W�g���b�L���O */
	FL tmp_cos = 0.0F;

	FL sot_thres_up[NB_FFT_PT];						/* [out](for debug) threashold for wall estimation�iFM up) */
	FL sot_thres_dn[NB_FFT_PT];						/* [out](for debug) threashold for wall estimation�iFM dn) */

	/*** �u���b�N�̓r���Ő錾����Ă���ϐ��Q���u���b�N�̐擪�ֈړ� *******************/
	/* FM�ߐړd�� for SoT */
	FL tmp_fm_nearfield_power;

	/* �����Ԕ���(2) */
	FL tmp_sot_wall_angle;
	FL tmp_sot_real_angle;

	S4 tmp_wall_reject_th = WALL_REJECT_TH3;

	fn_initialize_wall_data(
		tmp_normal
	);
	fn_move(
		normal_wall,			/* [out] */
		tmp_normal,				/* [in] */
		1
	);
	fn_move(
		normal_wall_prev,		/* [out] */
		ast_a_normal_wall,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		tmp_normal_sot,			/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		normal_sot_prev,		/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);
	fn_move(
		normal_sot,				/* [out] */
		ast_a_normal_sot,		/* [in] */
		1						/* [in] */
	);

/****************************************************************************/
/* (1)	�e�l�b�v�O�������W���菈��											*/
/****************************************************************************/
	/***** 1) FMCW�ߐړd�͂̎Z�o. *****/
	tmp_fm_nearfield_power = fl_bsm_side_cal_fm_nearfield_power();

	/************** FM���W����(tmp_fm_obj_flg) **************/
	tmp_fm_obj_flg = check_fm_object(	/* [return] */
		(const NORMAL_BSM *)normal_sot_prev,	/* [in] */
		tmp_leading_flg1,						/* [in]	 */
		tmp_normal								/* [out] */
	);
/****************************************************************************/
/* (2)	�e�l�b�v���W�ڋߔ��菈��											*/
/****************************************************************************/
	/************** FM�X�y�N�g��������(tmp_fm_flg) **************/
	tmp_fm_flg = 0;
	tmp_fm_flg = check_fm_spectrum(
		sot_thres_up,
		sot_thres_dn
	);

/****************************************************************************/
/* (3)	�����Ԕ��菈��														*/
/****************************************************************************/
	fn_bsm_side_check_leading_object(
		(const NORMAL_BSM *)tmp_normal,
		tmp_fm_obj_flg,
		tmp_fm_flg,
		&tmp_wall_flg,
		&tmp_leading_flg1,
		&tmp_leading_flg2,
		&tmp_sot_wall_angle,
		&tmp_sot_real_angle,
		tmp_normal_sot,
		&tmp_wall_reject_th
	);

/****************************************************************************/
/* (4)	�ǔ��菈��															*/
/****************************************************************************/
	fn_bsm_side_check_wall(
		tmp_fm_obj_flg,
		tmp_leading_flg1,
		tmp_sot_wall_angle,
		tmp_sot_real_angle,
		(const NORMAL_BSM *)tmp_normal,
		&tmp_wall_flg,
		normal_wall,
		tmp_wall_reject_th
	);


/****************************************************************************/
/* (6)	�ǃg���b�L���O����													*/
/****************************************************************************/
	fn_bsm_side_tracking_wall(
		tmp_fm_obj_flg,
		tmp_wall_flg,
		tmp_leading_flg1,
		tmp_leading_flg2,
		(const NORMAL_BSM *)tmp_normal,
		(const NORMAL_BSM *)normal_wall_prev,
		normal_wall
	);

/****************************************************************************/
/* (5)	�����ԃg���b�L���O����												*/
/****************************************************************************/
	object_num = s4_bsm_side_tracking_heisou(
		tmp_fm_nearfield_power,
		tmp_fm_obj_flg,
		&tmp_leading_flg2,
		(const NORMAL_BSM *)normal_sot_prev,
		(const NORMAL_BSM *)tmp_normal_sot,
		normal_sot
	);

	/* �o�̓f�[�^���R�s�[ */
	/* �� */
	fn_move(										/* PROC.4 of(6)4) */
		ast_a_normal_wall,
		normal_wall,
		1
	);
	st_g_bsm_loop_data.afl_wall_width[0] = ast_a_normal_wall[0].fl_Rxfil;		/* PROC.3 of(6)4) */

	/* ������ */
	if(st_g_bsm_loop_data.as4_slow_sot_find[1] > tmp_wall_reject_th)			/* COND.e12 */
	{
		fn_init(&normal_sot[0], 1 );				/* PROC.5 of(5)6) */
		object_num = 0;								/* PROC.6 of(5)6) */
	}
	fn_move(										/* PROC.4 of(5)6) */
		ast_a_normal_sot,
		normal_sot,
		1
	);

	st_g_bsm_loop_data.as4_flg_leading[0] = tmp_leading_flg2;				/* PROC.3 of(5)6) */

	/****************************************************************************/
	/* (8)  �ǔ���(FA �폜�p)													*/
	/****************************************************************************/
	fn_bsm_side_check_wall_for_erase_fa_seg((const NORMAL_BSM *)tmp_normal, tmp_fm_obj_flg);

	return object_num;
}


/****************************************************************************/
/* �֐���		: fl_bsm_side_cal_fm_nearfield_power						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: FMCW�M���i���j�̎��g���X�y�N�g������A�ߐڕ��̓d�͂��Z�o*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (1)FMCW�O�������W���菈�� 								*/
/*				:  1)FMCW�ߐړd�͂̎Z�o		 								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static FL fl_bsm_side_cal_fm_nearfield_power( VD )
{
	S4 i;
	FL fl_t_fm_nearfield_power;

	/***** 1) FMCW�ߐړd�͂̎Z�o. *****/
	fl_t_fm_nearfield_power = 0.0F;
	for(i = VI_TOS_END_FREQ_BIN; i < (VI_TOS_END_FREQ_BIN + SOT_FMPEAK_RANGE); i++)
	{
		fl_t_fm_nearfield_power += afl_g_cvw_lfm_ftt_power[0][i];
	}
	fl_t_fm_nearfield_power = fl_t_fm_nearfield_power/SOT_FMPEAK_RANGE;

	return fl_t_fm_nearfield_power;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check_leading_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3)	�����Ԕ��菈��										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)	�����Ԕ��菈��										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle,
	NORMAL_BSM ast_a_normal_sot[1],
	S4 *ps4_a_wall_reject_th
)
{
	/***** 1) �����Ԕ��� 1 *****/
	fn_bsm_side_check1_leading_object(
		(const NORMAL_BSM *)ast_a_normal_fm,
		s4_a_fm_obj_flg,
		s4_a_fm_flg,
		ps4_a_wall_flg,
		ps4_a_leading_flg1,
		ps4_a_wall_reject_th
	);

	/***** 2) �����Ԕ��� 2 *****/
	fn_bsm_side_check2_leading_object(
		(const NORMAL_BSM *)ast_a_normal_fm,
		s4_a_fm_obj_flg,
		s4_a_fm_flg,
		ps4_a_wall_flg,
		ps4_a_leading_flg1,
		ps4_a_leading_flg2,
		pfl_a_sot_wall_angle,
		pfl_sot_real_angle
	);

	/***** 3) �����ԕ��W���̐ݒ� *****/
	fn_bsm_side_set_leading_object(
		*ps4_a_leading_flg2,
		(const NORMAL_BSM *)ast_a_normal_fm,
		ast_a_normal_sot
	);

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check1_leading_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3)-1)�����Ԕ��� 1										*/
/*				:	�O�񕹑��Ԃ������ꍇ�́A���̂܂ܕ����Ԃ���Ƃ��A		*/
/*				:	�O�񕹑��Ԃ����Ȃ������ꍇ�́A����ڋ߂��Ă��������Ԃ�	*/
/*				:	���邩�𔻒肷��B										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)�����Ԕ��菈��											*/
/*				:  1)�����Ԕ��� 1											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check1_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_wall_reject_th
)
{
	FL tmp_sot_wall_diff;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if(st_g_bsm_loop_data.as4_low_speed_flg[0]==1)															/* COND.c15 */
	{
		*ps4_a_wall_reject_th = 3;																			/* PROC.5 */
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	/***** 1) �����Ԕ��� 1 *****/
	if( *ps4_a_leading_flg1 == 0 ) {																		/* COND.c1 */
		/* FM���W */
		if ((s4_a_fm_obj_flg != 0)																			/* COND.c2 */
		&&  (s4_a_fm_flg != 0)) {																			/* COND.c3 */
			if(st_g_bsm_loop_data.afl_wall_width[0]!=WALL_MAX) {											/* COND.c4 */
				tmp_sot_wall_diff = CFL_SOT_WALL_DIFF + st_g_bsm_loop_data.afl_installed_angle[1];			/* PROC.1 */
			} else {
				tmp_sot_wall_diff = SOT_WALL_DIFF_DEFAULT;													/* PROC.2 */
			}

			if (((st_g_bsm_loop_data.afl_wall_width[0] - ast_a_normal_fm[0].fl_Rxobs) > tmp_sot_wall_diff)	/* COND.c5 */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < *ps4_a_wall_reject_th)) {						/* COND.c6 */
				/* �� �ǂł͂Ȃ� */
				*ps4_a_wall_flg = 0;																		/* PROC.3 */
				*ps4_a_leading_flg1 = 1;																	/* PROC.4 */
			}
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check2_leading_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3)-2)�����Ԕ��� 2										*/
/*				:	���񕹑��Ԃ�����Ɣ��肳�ꂽ�ꍇ�́A�ǂ��ۂ��̔��ʂɂ��*/
/*				:	�����Ԃ̔�����s���B									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)�����Ԕ��菈��											*/
/*				:  2)�����Ԕ��� 2											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check2_leading_object(
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 s4_a_fm_obj_flg,
	S4 s4_a_fm_flg,
	S4 *ps4_a_wall_flg,
	S4 *ps4_a_leading_flg1,
	S4 *ps4_a_leading_flg2,
	FL *pfl_a_sot_wall_angle,
	FL *pfl_sot_real_angle
)
{
	FL tmp_t_wall_diff_th;

	/***** 2) �����Ԕ��� 2 *****/
	*pfl_a_sot_wall_angle = SOT_WALL_ANGLE_TH;												/* PROC.1 */
	tmp_t_wall_diff_th  = SOT_WALL_DIFF_FAST;												/* PROC.2 */
	if( fl_g_v_self_bsm_for_base < WALL_TRK_LOW_VSELF_TH ) {								/* COND.c7 */
		*pfl_a_sot_wall_angle = SOT_WALL_ANGLE_TH_FORWARD;									/* PROC.3 */
		tmp_t_wall_diff_th = SOT_WALL_DIFF_SLOW;											/* PROC.4 */
	}
	*pfl_sot_real_angle = 180.0F/PI*0.5F*(ast_a_normal_fm[0].fl_theta_up + ast_a_normal_fm[0].fl_theta_dn);		/* PROC.5 */

	if ((st_g_bsm_loop_data.as4_slow_sot_find[0] > 0)															/* COND.c8 */
	&&  (st_g_bsm_loop_data.afl_wall_width[0] != WALL_MAX)) {													/* COND.c4 */
		if (s4_a_fm_obj_flg != 0) {																				/* COND.c2 */
			/********* �ǂ��������ǂł͂Ȃ� **********/
			if ((st_g_bsm_loop_data.afl_wall_width[0] - ast_a_normal_fm[0].fl_Rxobs) > tmp_t_wall_diff_th) {	/* COND.c9 */
				/* �� �ǂł͂Ȃ� & �����Ԃ���  */
				*ps4_a_wall_flg = 0;																			/* PROC.6 */
				*ps4_a_leading_flg1 = 1;																		/* PROC.7 */
				*ps4_a_leading_flg2 = 1;																		/* PROC.8 */
			} else {
				/********* �Ǖt�߂��O�����ǂł���\������ *********/
				if ((*pfl_sot_real_angle > *pfl_a_sot_wall_angle)												/* COND.c10 */
				&&  (*pfl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD)											/* COND.c11 */
				&&  (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN)) {										/* COND.c12 */
					/* �� �� */
					*ps4_a_wall_flg = 1;																		/* PROC.9 */
					*ps4_a_leading_flg1 = 0;																	/* PROC.10 */
					*ps4_a_leading_flg2 = 0;																	/* PROC.11 */
				}

				if(st_g_bsm_loop_data.as4_slow_sot_find[1]==0) {												/* COND.c13 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = WALL_REJECT_TH3;									/* PROC.12 */
				}
			}
		}
	}

	/* (7)�ᑬSoT���菈�� 8)�����ԑ��ݔ���ŕ����Ԃ���Ɣ��肳��Ă���ꍇ�́A	*/
	/* �����Ԕ��茋�ʂ����������A�����I�ɕ����Ԃ���Ƃ���						*/
	if ((st_g_bsm_loop_data.u1_flg_heisou_car == (U1)1)		/* COND.c18 */
	&&	(s4_a_fm_obj_flg != (S4)0)) {						/* COND.c2 */
		*ps4_a_wall_flg = (S4)0;							/* PROC.6 */
		*ps4_a_leading_flg1 = (S4)1;						/* PROC.7 */
		*ps4_a_leading_flg2 = (S4)1;						/* PROC.8 */
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_set_leading_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (3)-3)�����ԕ��W���̐ݒ�								*/
/*				:	�����Ԃł���Ɣ��肳�ꂽ�ꍇ�́A�O�������W����		*/
/*				:	�����ԕ��W���ɃR�s�[����B							*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (3)�����Ԕ��菈��											*/
/*				:  3)�����ԕ��W���̐ݒ�									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_set_leading_object(
	S4 s4_a_leading_flg2,						/* [in] */
	const NORMAL_BSM ast_a_normal_fm[1],		/* [in] */
	NORMAL_BSM ast_a_normal_heisou[1]			/* [out] */
)
{
	/***** 3) �����ԕ��W���̐ݒ� *****/
	if (s4_a_leading_flg2 != 0) {															/* COND.c14 */
		if (((ast_a_normal_fm[0].s4_bin_up < FREQ_BIN_LOWER_LIMIT)							/* COND.c16_up */
		&&   (ast_a_normal_fm[0].fl_power_up < PEAK_POW_TH_AROUND_CENTER))					/* COND.c17_up */
		||  ((ast_a_normal_fm[0].s4_bin_dn < FREQ_BIN_LOWER_LIMIT)							/* COND.c16_dn */
		&&   (ast_a_normal_fm[0].fl_power_dn < PEAK_POW_TH_AROUND_CENTER))) {				/* COND.c17_dn */
			/* �������Ȃ� */
		} else {
			/* ���f�[�^�𕹑���NORMAL_BSM�ɃR�s�[ */
			fn_move(																		/* PROC.1 */
				ast_a_normal_heisou,
				ast_a_normal_fm,
				1
			);
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check_wall									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (4)�ǔ��菈��												*/
/*				:	�O�������W���菈���A���W�ڋߔ��菈���A�����Ԕ��菈����	*/
/*				:	���ʂ���A�ԗ��O�����̕��W���Ԃł��邩�̔�����s���B	*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)�ǔ��菈��												*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	const NORMAL_BSM ast_a_normal_fm[1],
	S4 *ps4_a_wall_flg,
	NORMAL_BSM ast_a_normal_wall[1],
	S4 s4_a_wall_reject_th
)
{

	/***** 1) �ǔ��� *****/
	fn_bsm_side_check1_wall(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		fl_a_sot_wall_angle,
		fl_sot_real_angle,
		ps4_a_wall_flg,
		s4_a_wall_reject_th
	);
	
	/***** 2) �Ǖ��W���̐ݒ� *****/
	fn_bsm_side_set_wall_object(
		*ps4_a_wall_flg,
		(const NORMAL_BSM *)ast_a_normal_fm,
		ast_a_normal_wall
	);

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check1_wall									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (4)-1) �ǔ���												*/
/*				:	���񕹑��Ԃ����ȂƔ��肳��A�O��ǉz�Ԃ����Ȃ������ꍇ��*/
/*				:	���o���ꂽ�O�������W�͕ǂł���\�������邽�߁A		*/
/*				:	���񌟏o�����O�������W���ǂ��ۂ��̔�����s���B			*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)-1) �ǔ���												*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check1_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	FL fl_a_sot_wall_angle,
	FL fl_sot_real_angle,
	S4 *ps4_a_wall_flg,
	S4 s4_a_wall_reject_th
)
{
	/***** 1) �ǔ��� *****/
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((s4_a_leading_flg1 == 0)													/* COND.c1 */
	&&  (st_g_bsm_loop_data.as4_flg_passing[0] <= PASSING_COUNT_MIN)				/* COND.d1 */
	&&  (s4_a_fm_obj_flg != 0)														/* COND.c2 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > s4_a_wall_reject_th)) {			/* COND.d2 */
		if (fl_sot_real_angle > fl_a_sot_wall_angle) {								/* COND.c10 */
			*ps4_a_wall_flg = 1;													/* PROC.1 */
		}
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((s4_a_leading_flg1 == (S4)0)												/* COND.c1 */
	&&  (s4_a_fm_obj_flg != (S4)0)													/* COND.c2 */
	&&  (fl_sot_real_angle > fl_a_sot_wall_angle)									/* COND.c10 */
	&&  ((st_g_bsm_loop_data.as4_flg_passing[0] <= (S4)PASSING_COUNT_MIN)			/* COND.d1 */
	||   ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] < (S4)CFL_WALL_DEV_TH12)	/* COND.d100 */
	&&    (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] < (S4)WALL_DEV_TH1)))	/* COND.d101 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > s4_a_wall_reject_th)) {			/* COND.d2 */
		if ((!(st_g_bsm_loop_data.as4_low_speed_flg[0] == (S4)1))					/* COND.!c15 */
		&&  (st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)) {				/* COND.g53 */
			if ((fl_sot_real_angle > fl_a_sot_wall_angle)							/* COND.c10 */
			&&  (fl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD)) {					/* COND.c11 */
				*ps4_a_wall_flg = (S4)1;												/* PROC.1 */
			}
		} else {
			if (fl_sot_real_angle > fl_a_sot_wall_angle) {							/* COND.c10 */
				*ps4_a_wall_flg = (S4)1;												/* PROC.1 */
			}
		}
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	if ((s4_a_leading_flg1 == 0)											/* COND.c1 */
	&&  (fl_g_v_self_bsm_for_base < WALL_TRK_LOW_VSELF_TH)					/* COND.d12 */
	&&  (s4_a_fm_obj_flg != 0)												/* COND.c2 */
	&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] > 1)) {					/* COND.d13 */
		if (fl_sot_real_angle < SOT_WALL_ANGLE_TH_BACKWARD) {				/* COND.c11 car coord. */
			*ps4_a_wall_flg = 1;
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_set_wall_object								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (4)-2) �Ǖ��W���̐ݒ�									*/
/*				:	�ǂł���Ɣ��肳�ꂽ�ꍇ�A�O�������W����Ǖ��W����	*/
/*				:	�R�s�[����B�܂��A�s�[�N���o���E�ȉ��ɋߐڂ��Ă���ꍇ��*/
/*				:	�ǋ����̕␳���s���B									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (4)-2) �Ǖ��W���̐ݒ�									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_set_wall_object(
	S4 s4_a_wall_flg,
	const NORMAL_BSM ast_a_normal_fm[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 2) �Ǖ��W���̐ݒ� *****/
	if (s4_a_wall_flg != 0) {												/* COND.d3 */
		/* ���f�[�^���NORMAL_BSM�ɃR�s�[ */
		fn_move(															/* PROC.1 */
			ast_a_normal_wall,
			ast_a_normal_fm,
			1
		);

		/* ���߂��ǑΉ� */
		if ((ast_a_normal_wall[0].s4_bin_up <= ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1 + 1))						/* COND.d4 */
		&&  (ast_a_normal_wall[0].s4_bin_dn <= ((NB_FFT_PT / 2) + CENTER_FREQ_RANGE + 1 + 1))) {					/* COND.d5 */
			if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH1)								/* COND.d6 */
			&&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH1)) {								/* COND.d7 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN;			/* PROC.2 */
			} else if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH2)							/* COND.d8 */
				   &&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH2)) {						/* COND.d9 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN + 0.5F;	/* PROC.3 */
			} else if ((ast_a_normal_wall[0].fl_power_up > CFL_SOT_WALL_NEAR_POWER_TH3)							/* COND.d10 */
				   &&  (ast_a_normal_wall[0].fl_power_dn > CFL_SOT_WALL_NEAR_POWER_TH3)) {						/* COND.d11 */
				ast_a_normal_wall[0].fl_Rxobs = st_g_bsm_loop_data.afl_installed_angle[1] + WALL_MIN + 1.0F;	/* PROC.4 */
			} else {
				/* �������Ȃ� */
			}
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_tracking_wall									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)�ǃg���b�L���O����										*/
/*				:	�ǔ��菈���̌��ʂɊ�Â��A�Ǖ��W�̃g���b�L���O�������s��*/
/*				:	�Ǖ��W�����X�V����B									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)�ǃg���b�L���O����										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_wall_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 1) ����̕ǔ��菈�����ʂ̔��� *****/
	if (s4_a_wall_flg != 0) {																/* COND.d4 */
		/***** 2) ����̊ϑ��l����̃g���b�L���O *****/
		fn_bsm_side_tracking_wall_with_obs(
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	} else {
		/***** 3) ����̊ϑ��l�Ȃ��̃g���b�L���O *****/
		fn_bsm_side_tracking_wall_without_obs(
			s4_a_fm_obj_flg,
			s4_a_leading_flg1,
			s4_a_leading_flg2,
			(const NORMAL_BSM *)ast_a_normal_fm,
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	}

	/***** 4) �ǋ�������E�����̊m�F *****/
	fn_bsm_side_guard_wall_rxfil(
		ast_a_normal_wall
	);

	st_g_bsm_loop_data.afl_wall_width[0] = ast_a_normal_wall[0].fl_Rxfil;					/* PROC.3 */

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_tracking_wall_with_obs						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-2)����̊ϑ��l����̃g���b�L���O						*/
/*				:	(�@)����̕Ǖ��W���̕␳								*/
/*				:	(�A)����̗\���l���Z�o									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-2)����̊ϑ��l����̃g���b�L���O						*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall_with_obs(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 2) ����̊ϑ��l����̃g���b�L���O *****/
	/* ���������� (�@)����̕Ǖ��W���̕␳ ���������� */
	fn_bsm_side_intpl_cur_wall_object(
		(const NORMAL_BSM *)ast_a_normal_wall_prev,
		ast_a_normal_wall
	);

	/* ���������� (�A)����̗\���l���Z�o1 ���������� */
	/* �g���b�L���O(�����g���b�J) */
	fn_ab_track_wall(													/* SEC.3-1(7)6) */
		&ast_a_normal_wall_prev[0],
		&ast_a_normal_wall[0],
		0
	);
	fn_calc_prediction_of_normaldata(
		&ast_a_normal_wall[0]
	);

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_intpl_cur_wall_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-2)-(�@)����̕Ǖ��W���̕␳							*/
/*				:	�ǂ̓ˋN����H����~�тȂǂɂ��A�˔��I�ȕǂ܂ł̋�����*/
/*				:	�͈͂̕ω��̉e�����y�����邽�߁A�ȉ��̏������s���B		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-2)-(�@)����̕Ǖ��W���̕␳							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_intpl_cur_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],			/* [in]  */
	NORMAL_BSM ast_a_normal_wall[1]						/* [out] */
)
{
	/* �傫���L����Ƃ��͏��������� */
	if ((ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) > SOT_WALL_WIDEN_DIFF_TH) {		/* COND.f1 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_WIDEN_COEF*(ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil)+ast_a_normal_wall_prev[0].fl_Rxfil;	/* PROC.1 */
		ast_a_normal_wall[0].fl_Vxobs = SOT_WALL_WIDEN_COEF*ast_a_normal_wall[0].fl_Vxobs;				/* PROC.2 */
	}

	/* �傫�����܂�Ƃ��͏������������� */
	if ((ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) < SOT_WALL_NARROW_DIFF_TH) {		/* COND.f2 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_NARROW_COEF*(ast_a_normal_wall[0].fl_Rxobs - ast_a_normal_wall_prev[0].fl_Rxfil) + ast_a_normal_wall_prev[0].fl_Rxfil;	/* PROC.3 */
		ast_a_normal_wall[0].fl_Vxobs = SOT_WALL_NARROW_COEF*ast_a_normal_wall[0].fl_Vxobs;					/* PROC.4 */
	}

	/* ����E�����`�F�b�N */
	if (ast_a_normal_wall[0].fl_Rxobs > SOT_WALL_MAX ) {									/* COND.f3 */
		ast_a_normal_wall[0].fl_Rxobs = SOT_WALL_MAX;										/* PROC.5 */
	}
	if (ast_a_normal_wall[0].fl_Rxobs < WALL_MIN ) {										/* COND.f4 */
		ast_a_normal_wall[0].fl_Rxobs = WALL_MIN;											/* PROC.6 */
	}

	ast_a_normal_wall[0].fl_Vyobs = 0.0F;															/* PROC.7 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up_music;			/* PROC.8 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn_music;			/* PROC.9 */

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_tracking_wall_without_obs						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)����̊ϑ��l�Ȃ��̃g���b�L���O						*/
/*				:	(�@)�O��̕Ǖ��W���̊m�F								*/
/*				:	(�A)����̗\���l���Z�o1									*/
/*				:	(�B)����̗\���l���Z�o�Q								*/
/*				:	(�C)����̗\���l���Z�o�R								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)����̊ϑ��l�Ȃ��̃g���b�L���O						*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_tracking_wall_without_obs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	FL fl_t_wall_pos;

	fl_t_wall_pos = 0.0F;

	/* ���������� (�@)�O��̕Ǖ��W���̊m�F ���������� */
	fn_bsm_side_confirm_prev_wall_object(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		s4_a_leading_flg2,
		(const NORMAL_BSM *)ast_a_normal_fm,
		&fl_t_wall_pos
	);
	
	if( ast_a_normal_wall_prev[0].fl_Rxpred < fl_t_wall_pos ) {
		/* ���������� (�A)����̗\���l���Z�o1 ���������� */
		fn_bsm_side_cal1_next_wall_object(
			s4_a_fm_obj_flg,
			s4_a_leading_flg1,
			s4_a_leading_flg2,
			fl_t_wall_pos,
			(const NORMAL_BSM *)ast_a_normal_wall_prev,
			ast_a_normal_wall
		);
	} else {
		if( s4_a_fm_obj_flg != 0 ) {													/* COND.c2 */
			/* ���������� (�B)����̗\���l���Z�o�Q ���������� */
			fn_bsm_side_cal2_next_wall_object(
				fl_t_wall_pos,
				(const NORMAL_BSM *)ast_a_normal_wall_prev,
				ast_a_normal_wall
			);
		} else {
			/* ���������� (�C)����̗\���l���Z�o�R ���������� */
			fn_bsm_side_cal3_next_wall_object(
				(const NORMAL_BSM *)ast_a_normal_wall_prev,
				ast_a_normal_wall
			);
		}
		
		/* �Ǎő勗�� */
		fn_bsm_side_guard_wall_xpred(
			ast_a_normal_wall
		);
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_confirm_prev_wall_object						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)-(�@)�O��̕Ǖ��W���̊m�F							*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(�@)�O��̕Ǖ��W���̊m�F							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_confirm_prev_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_fm[1],
	FL *pfl_a_wall_pos
)
{
	/* ->�O��\���l���玟��l��\�� */
	/* ���������� (�@)�O��̕Ǖ��W���̊m�F ���������� */
	if (s4_a_fm_obj_flg != 0 ) {														/* COND.c2 */
		*pfl_a_wall_pos = ast_a_normal_fm[0].fl_Rxobs;									/* PROC.1 */
	} else {
		*pfl_a_wall_pos = WALL_MAX;														/* PROC.2 */
	}

	if ((s4_a_leading_flg1 != 0)														/* COND.c1 */
	||  (s4_a_leading_flg2 != 0)														/* COND.c14 */
	||  (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN)						/* COND.!d1 */
	||  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] > 0)) {					 	/* COND.f5 */
		if (*pfl_a_wall_pos < WALL_MAX) {												/* COND.f6 */
			*pfl_a_wall_pos = WALL_MAX;													/* PROC.2 */
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_cal1_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)-(�A)����̗\���l���Z�o1							*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(�A)����̗\���l���Z�o1							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal1_next_wall_object(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	fn_init(&ast_a_normal_wall[0], 1);													/* PROC.3 */
	ast_a_normal_wall[0].fl_Ryobs = 0.0F;												/* PROC.4-1 */
	ast_a_normal_wall[0].fl_Ryfil = 0.0F;												/* PROC.4-2 */
	ast_a_normal_wall[0].fl_Rypred = 0.0F;												/* PROC.4-3 */

	ast_a_normal_wall[0].fl_Rxobs = fl_bsm_side_cal1_cal_wall_rxobs(
		s4_a_fm_obj_flg,
		s4_a_leading_flg1,
		s4_a_leading_flg2,
		fl_a_wall_pos,
		(const NORMAL_BSM *)ast_a_normal_wall_prev
	);

	ast_a_normal_wall[0].fl_Rxfil = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-1 */
	ast_a_normal_wall[0].fl_Rxpred = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-2 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall[0].fl_Rxobs;																				/* PROC.11-3 */
	ast_a_normal_wall[0].fl_Robs_pred = ast_a_normal_wall[0].fl_Rxpred;																			/* PROC.11-4 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up_music;														/* PROC.11-5 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn_music;														/* PROC.11-6 */
	ast_a_normal_wall[0].fl_doa_up_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_up_music_pred;											/* PROC.11-7 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_dn_music_pred;											/* PROC.11-8 */
	ast_a_normal_wall[0].fl_bin_up_interpolate = (FL)ast_a_normal_wall[0].s4_bin_up;															/* PROC.11-9 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate = (FL)ast_a_normal_wall[0].s4_bin_dn;															/* PROC.11-10 */
	ast_a_normal_wall[0].fl_bin_up_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_up_pred;													/* PROC.11-11 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate_pred = (FL)ast_a_normal_wall[0].s4_bin_dn_pred;													/* PROC.11-12 */

	return;
}


/****************************************************************************/
/* �֐���		: fl_bsm_side_cal1_cal_wall_rxobs							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)-(�A)����̗\���l���Z�o1							*/
/*				:	�Ǖ��W����X���������ϑ��l�̐ݒ��X�V					*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(6)-3)-(�A)����̗\���l���Z�o1 							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static FL fl_bsm_side_cal1_cal_wall_rxobs(
	S4 s4_a_fm_obj_flg,
	S4 s4_a_leading_flg1,
	S4 s4_a_leading_flg2,
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1]
)
{
	FL fl_t_rxobs;

	if (s4_a_leading_flg1 == 0) {																									/* COND.c1 */
		if (st_g_bsm_loop_data.as4_flg_passing[0] > PASSING_COUNT_MIN) {															/* COND.!d1 */
			/* �ǂ̋��������ɖ߂�(�������) */
			fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA) + WALL_LOST_ALPHA*fl_a_wall_pos;					/* PROC.8 */
		} else {
			if (fl_g_v_self_bsm_for_base > WALL_RET_LOW_VSELF_TH) {																	/* COND.f8 */
				if (s4_a_fm_obj_flg != 0) {																							/* COND.c2 */
					/* �ǂ̋��������ɖ߂�(������Ƃ͂��) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				} else {
					/* �ǂ̋��������ɖ߂�(������Ƃ͂��) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				}
			} else {
				if (s4_a_fm_obj_flg != 0) {																							/* COND.c2 */
					/* �ǂ̋��������ɖ߂�(������Ƃ͂��) */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;	/* PROC.5 */
				} else {
					/* �ǂ̋����͂��̂܂� */
					fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil;																/* PROC.6 */
				}
			}
		}
	} else {
		/* �����Ԃ��� */
		if (fl_g_v_self_bsm_for_base > WALL_RET_LOW_VSELF_TH) {																		/* COND.f8 */
			/* �ǂ̋��������ɖ߂��i�͂�߁j */
			fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_FAST) + WALL_LOST_ALPHA_FAST*fl_a_wall_pos;			/* PROC.7 */
		} else {
			if ((s4_a_fm_obj_flg != 0)																								/* COND.c2 */
			&&  (s4_a_leading_flg2 == 0)) {																							/* COND.!c1 */
				/* �ǂ̋��������ɖ߂�(������Ƃ͂��) */
				fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;		/* PROC.5 */
			} else {
				/* �ǂ̋����͂��̂܂� */
				fl_t_rxobs = ast_a_normal_wall_prev[0].fl_Rxfil;																	/* PROC.6 */
			}
		}
	}
	if (fl_t_rxobs > fl_a_wall_pos) {										/* COND.f9 */
		fl_t_rxobs = fl_a_wall_pos;											/* PROC.9 */
	}
	if (fl_t_rxobs < WALL_MIN) {											/* COND.f10 */
		fl_t_rxobs = WALL_MIN;												/* PROC.10 */
	}

	return fl_t_rxobs;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_cal2_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)-(�B)����̗\���l���Z�o�Q							*/
/*				:	�D�Ǖ��W����X���������ϑ��l���X�V						*/
/*				:	�K�Ǖ��W���̏����X�V								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(�B)����̗\���l���Z�o�Q							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal2_next_wall_object(
	FL fl_a_wall_pos,
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* �ǂ̋��������ɖ߂�(������Ƃ͂��) */
	ast_a_normal_wall[0].fl_Rxobs = ast_a_normal_wall_prev[0].fl_Rxfil*(1-WALL_LOST_ALPHA_MID) + WALL_LOST_ALPHA_MID*fl_a_wall_pos;			/* PROC.5 */
	ast_a_normal_wall[0].fl_Rxfil = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-1 */
	ast_a_normal_wall[0].fl_Rxpred = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-2 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall[0].fl_Rxobs;																			/* PROC.12-3 */
	ast_a_normal_wall[0].fl_Robs_pred = ast_a_normal_wall[0].fl_Rxpred;																		/* PROC.12-4 */

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_cal3_next_wall_object							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)-(�C)����̗\���l���Z�o�R							*/
/*				:	�L����̕Ǖ��W���ɑO��̕Ǖ��W���̗\���l���R�s�[	*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)-(�C)����̗\���l���Z�o�R							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_cal3_next_wall_object(
	const NORMAL_BSM ast_a_normal_wall_prev[1],
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* �O��̗\���l������̌v���l�Ƃ��ăR�s�[ */
	ast_a_normal_wall[0].s4_bin_up = ast_a_normal_wall_prev[0].s4_bin_up_pred;																/* PROC.13-1 */
	ast_a_normal_wall[0].s4_bin_dn = ast_a_normal_wall_prev[0].s4_bin_dn_pred;																/* PROC.13-2 */
	ast_a_normal_wall[0].fl_bin_up_interpolate = ast_a_normal_wall_prev[0].fl_bin_up_interpolate_pred;										/* PROC.13-3 */
	ast_a_normal_wall[0].fl_bin_dn_interpolate = ast_a_normal_wall_prev[0].fl_bin_dn_interpolate_pred;										/* PROC.13-4 */
	ast_a_normal_wall[0].s4_bin_up_music = ast_a_normal_wall_prev[0].s4_bin_up_music_pred;													/* PROC.13-5 */
	ast_a_normal_wall[0].s4_bin_dn_music = ast_a_normal_wall_prev[0].s4_bin_dn_music_pred;													/* PROC.13-6 */
	ast_a_normal_wall[0].fl_doa_up_interpolate = ast_a_normal_wall_prev[0].fl_doa_up_interpolate_pred;										/* PROC.13-7 */
	ast_a_normal_wall[0].fl_doa_dn_interpolate = ast_a_normal_wall_prev[0].fl_doa_dn_interpolate_pred;										/* PROC.13-8 */
	ast_a_normal_wall[0].fl_theta_up = ast_a_normal_wall_prev[0].fl_theta_up_pred;															/* PROC.13-9 */
	ast_a_normal_wall[0].fl_theta_dn = ast_a_normal_wall_prev[0].fl_theta_dn_pred;															/* PROC.13-10 */
	ast_a_normal_wall[0].fl_Robs = ast_a_normal_wall_prev[0].fl_Robs_pred;																	/* PROC.13-11 */
	ast_a_normal_wall[0].fl_Vobs = ast_a_normal_wall_prev[0].fl_Vobs_pred;																	/* PROC.13-12 */
	ast_a_normal_wall[0].fl_Rxobs = ast_a_normal_wall_prev[0].fl_Rxpred;																	/* PROC.13-13 */
	ast_a_normal_wall[0].fl_Vxobs = ast_a_normal_wall_prev[0].fl_Vxpred;																	/* PROC.13-14 */
	ast_a_normal_wall[0].fl_Ryobs = ast_a_normal_wall_prev[0].fl_Rypred*(1-WALL_LOST_ALPHA_FAST) + WALL_LOST_ALPHA_FAST*0.0F;				/* PROC.13-15 */
	ast_a_normal_wall[0].fl_Vyobs = 0.0F;																									/* PROC.13-16 */
	/* �g���b�L���O(�����g���b�J) */
	fn_ab_track_wall(																							/* SEC.3-1(7)6) */
		&ast_a_normal_wall_prev[0],
		&ast_a_normal_wall[0],
		0
	);
	fn_calc_prediction_of_normaldata(
		&ast_a_normal_wall[0]
	);

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_guard_wall_xpred								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-3)�Ǎő勗��											*/
/*				:	�M����̕Ǖ��W����X���������\���l������ɐݒ�			*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-3)�Ǎő勗��											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_guard_wall_xpred(
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/* �Ǎő勗�� */
	if( ast_a_normal_wall[0].fl_Rxpred > SOT_WALL_MAX ) {								/* COND.f11 */
		ast_a_normal_wall[0].fl_Rxpred = SOT_WALL_MAX;									/* PROC.14 */
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_guard_wall_rxfil								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (6)-4) �ǋ�������E�����̊m�F								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (6)-4) �ǋ�������E�����̊m�F								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_guard_wall_rxfil(
	NORMAL_BSM ast_a_normal_wall[1]
)
{
	/***** 4) �ǋ�������E�����̊m�F *****/
	if (ast_a_normal_wall[0].fl_Rxfil > SOT_WALL_MAX) {										/* COND.f12 */
		ast_a_normal_wall[0].fl_Rxfil = SOT_WALL_MAX;										/* PROC.1 */
	}
	if (ast_a_normal_wall[0].fl_Rxfil < WALL_MIN) {											/* COND.f13 */
		ast_a_normal_wall[0].fl_Rxfil = WALL_MIN;											/* PROC.2 */
	}

	return;
}


/****************************************************************************/
/* �֐���		: s4_bsm_side_tracking_heisou								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)�����ԃg���b�L���O����									*/
/*				:	�����Ԕ��菈���̌��ʂɊ�A�����ԕ��W�̃g���b�L���O����*/
/*				:	���s���A�����ԕ��W�����X�V����B						*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)�����ԃg���b�L���O����									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou(
	FL fl_a_fm_nearfield_power,
	S4 s4_a_fm_obj_flg,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4	s4_t_object_num;

	s4_t_object_num = 0;

	/***** 1) ����̕����Ԕ��菈�����ʂ̔��� *****/
	ast_a_normal_sot[0].s4_flg_new = 0;

	/* �����Ԃ�����Ɣ��� */
	if (*ps4_a_leading_flg2 != 0) {														/* COND.c14 */
		/* ����̊ϑ��l������ */
		if (s4_a_fm_obj_flg != 0) {														/* COND.c2  */
			s4_t_object_num = s4_bsm_side_tracking_heisou_with_obs(
				fl_a_fm_nearfield_power,
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot_prev,
				(const NORMAL_BSM *)ast_a_normal_sot_heisou,
				ast_a_normal_sot
			);
		/* ����̊ϑ��l���Ȃ� */
		} else {
			/***** 4) ����̊ϑ��l�Ȃ��C�O��̗\���l����̃g���b�L���O *****/
			s4_t_object_num = s4_bsm_side_tracking_heisou_without_obs(
				fl_a_fm_nearfield_power,
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot_prev,
				ast_a_normal_sot
			);
		}
		
		if (*ps4_a_leading_flg2 != 0) {													/* COND.c14 */
			/***** 6) �g���b�L���O�͈͂̔���. *****/
			fn_bsm_side_check_tracking_heisou_range(
				ps4_a_leading_flg2,
				(const NORMAL_BSM *)ast_a_normal_sot
			);
		}
	/* �O�������������ԂȂ� */
	} else {
		/***** 5) ����̊ϑ��l�Ȃ��C�O��̗\���l�Ȃ��̃g���b�L���O *****/
		/* -> ���Z�b�g */
		fn_init(&ast_a_normal_sot[0], 1);												/* PROC.1 */
		*ps4_a_leading_flg2 = 0;														/* PROC.2 */
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* �֐���		: s4_bsm_side_tracking_heisou_with_obs						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)-2)����̊ϑ��l����A�O��̊ϑ��l����̃g���b�L���O	*/
/*				: (5)-3)����̊ϑ��l����A�O��̊ϑ��l�Ȃ��̃g���b�L���O	*/
/*				:	����̊ϑ��l������ꍇ�̃g���b�L���O					*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)-2)����̊ϑ��l����A�O��̊ϑ��l����̃g���b�L���O	*/
/*				: (5)-3)����̊ϑ��l����A�O��̊ϑ��l�Ȃ��̃g���b�L���O	*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou_with_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	const NORMAL_BSM ast_a_normal_sot_heisou[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 s4_t_object_num;

	s4_t_object_num = 0;

	/* ����̊ϑ��l��NORMAL_BSM�f�[�^�Z�b�g */
	fn_move(
		ast_a_normal_sot,
		ast_a_normal_sot_heisou,
		1
	);
	ast_a_normal_sot[0].s4_flg_heiso_up = 1;													/* PROC.1-1 */
	ast_a_normal_sot[0].s4_flg_heiso_dn = 1;													/* PROC.1-2 */
	ast_a_normal_sot[0].s4_flg_dc = OBJECT_TYPE_SOT;											/* PROC.2 */

	if ((ast_a_normal_sot_prev[0].fl_Rxpred != CFL_UNKNOWN_VALUE)								/* COND.e1 */
	&&  (ast_a_normal_sot_prev[0].fl_Rypred != CFL_UNKNOWN_VALUE)) {							/* COND.e2 */
		/***** 2) ����̊ϑ��l����C�O��̗\���l����̃g���b�L���O *****/
		/* ->�����g���b�L���O */
		/* �g���b�L���O(�����g���b�J) */
		fn_ab_track(												/* SEC.3-1(7)6) */
			&ast_a_normal_sot_prev[0],
			&ast_a_normal_sot[0],
			0
		);
		fn_calc_prediction_of_normaldata(
			&ast_a_normal_sot[0]
		);

		if (ast_a_normal_sot[0].s4_flg_track == CS4_S4MAX) {
			/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
		} else {
			ast_a_normal_sot[0].s4_flg_track = ast_a_normal_sot_prev[0].s4_flg_track +1;		/* PROC.1 */
		}

		ast_a_normal_sot[0].s4_flg_lost = 0;													/* PROC.2 */
		s4_t_object_num = 1;																	/* PROC.3 */
	} else {
		if (fl_a_fm_nearfield_power > CFL_SLOW_SOT_POW_TH) {									/* COND.e3 */
			/***** 3) ����̊ϑ��l����C�O��̗\���l�Ȃ��̃g���b�L���O *****/
			/* ->�V�K���W�F����l���玟��l��\�� */
			S4 tmptmp_erased_num = 0;
			/* �g���b�J��񐶐� */
			S4 tmptmp_passing_flg[1];
			S4 tmptmp_leading_flg[1];
			tmptmp_passing_flg[0] = (S4)0;
			tmptmp_leading_flg[0] = *ps4_a_leading_flg2;
			tmptmp_erased_num = s4_start_prediction(								/* SEC.3-1(6) */
				ast_a_normal_sot,				/* [in/out] */
				1,						/* [in] */
				1,						/* [in] */
				(const S4 (*))tmptmp_passing_flg,		/* [in] */
				(const S4 (*))tmptmp_leading_flg		/* [in] */
			);
			/* trim normal data */
			s4_t_object_num = s4_copy_prediction_to_filtered_data(
				ast_a_normal_sot,
				1
			);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			if (tmptmp_erased_num==1)			/* �s��ł͂Ȃ����H leading_flg2 �̏��������Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_t_object_num == (S4)0)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			{
				fn_init(&ast_a_normal_sot[0], 1);
			} else {																/* (=COND.e12) */
				/* �������D�敨�W�� */
				ast_a_normal_sot[0].s4_flg_new = 1;										/* PROC.2 */
				ast_a_normal_sot[0].s4_flg_track = PRIOR_TRK_NUM+1;						/* PROC.3 */
			}
		} else {
			/***** 5) ����̊ϑ��l�Ȃ��C�O��̗\���l�Ȃ��̃g���b�L���O *****/
			fn_init(&ast_a_normal_sot[0], 1);								/* PROC.1 */
			*ps4_a_leading_flg2 = 0;										/* PROC.2 */
		}
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* �֐���		: s4_bsm_side_tracking_heisou_without_obs					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)-4) ����̊ϑ��l�Ȃ��A�O��̗\���l����̃g���b�L���O	*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (5)-4) ����̊ϑ��l�Ȃ��A�O��̗\���l����̃g���b�L���O	*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_tracking_heisou_without_obs(
	FL fl_a_fm_nearfield_power,
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot_prev[1],
	NORMAL_BSM ast_a_normal_sot[1]
)
{
	S4 s4_t_object_num;
	
	s4_t_object_num = 0;

	/***** 4) ����̊ϑ��l�Ȃ��C�O��̗\���l����̃g���b�L���O *****/
	/* ->�O�}�F�O��\���l���玟��l��\�� */
	if ((ast_a_normal_sot_prev[0].fl_Rxpred != CFL_UNKNOWN_VALUE)								/* COND.e1 */
	&&  (ast_a_normal_sot_prev[0].fl_Rypred != CFL_UNKNOWN_VALUE)								/* COND.e2 */
	&&  (fl_a_fm_nearfield_power > CFL_SLOW_SOT_POW_TH2)										/* COND.e3' */
	&&  (ast_a_normal_sot_prev[0].s4_flg_lost < SOT_LOST_NUM_MAX)) {							/* COND.e4 */
		/* �O��̗\���l������̌v���l�Ƃ��ăR�s�[ */
		ast_a_normal_sot[0].s4_bin_up = ast_a_normal_sot_prev[0].s4_bin_up_pred;							/* PROC.1-1 */
		ast_a_normal_sot[0].s4_bin_dn = ast_a_normal_sot_prev[0].s4_bin_dn_pred;							/* PROC.1-2 */
		ast_a_normal_sot[0].fl_bin_up_interpolate = ast_a_normal_sot_prev[0].fl_bin_up_interpolate_pred;	/* PROC.1-3 */
		ast_a_normal_sot[0].fl_bin_dn_interpolate = ast_a_normal_sot_prev[0].fl_bin_dn_interpolate_pred;	/* PROC.1-4 */
		ast_a_normal_sot[0].s4_bin_up_music = ast_a_normal_sot_prev[0].s4_bin_up_music_pred;				/* PROC.1-5 */
		ast_a_normal_sot[0].s4_bin_dn_music = ast_a_normal_sot_prev[0].s4_bin_dn_music_pred;				/* PROC.1-6 */
		ast_a_normal_sot[0].fl_doa_up_interpolate = ast_a_normal_sot_prev[0].fl_doa_up_interpolate_pred;	/* PROC.1-7 */
		ast_a_normal_sot[0].fl_doa_dn_interpolate = ast_a_normal_sot_prev[0].fl_doa_dn_interpolate_pred;	/* PROC.1-8 */
		ast_a_normal_sot[0].fl_theta_up = ast_a_normal_sot_prev[0].fl_theta_up_pred;						/* PROC.1-9 */
		ast_a_normal_sot[0].fl_theta_dn = ast_a_normal_sot_prev[0].fl_theta_dn_pred;						/* PROC.1-10 */
		ast_a_normal_sot[0].fl_Robs = ast_a_normal_sot_prev[0].fl_Robs_pred;								/* PROC.1-11 */
		ast_a_normal_sot[0].fl_Rxobs = ast_a_normal_sot_prev[0].fl_Rxpred;									/* PROC.1-12 */
		ast_a_normal_sot[0].fl_Ryobs = ast_a_normal_sot_prev[0].fl_Rypred;									/* PROC.1-13 */
		ast_a_normal_sot[0].fl_Vobs = ast_a_normal_sot_prev[0].fl_Vobs_pred;								/* PROC.1-14 */
		ast_a_normal_sot[0].fl_Vxobs = ast_a_normal_sot_prev[0].fl_Vxpred;									/* PROC.1-15 */
		ast_a_normal_sot[0].fl_Vyobs = ast_a_normal_sot_prev[0].fl_Vypred;									/* PROC.1-16 */

		/* �g���b�L���O(�����g���b�J) */
		fn_ab_track(												/* SEC.3-1(7)6) */
			&ast_a_normal_sot_prev[0],
			&ast_a_normal_sot[0],
			0
		);
		fn_calc_prediction_of_normaldata(
			&ast_a_normal_sot[0]
		);

		if (ast_a_normal_sot[0].s4_flg_track == CS4_S4MAX) {
			/* S4�̍ő�l�ł��邽�߉��Z���Ȃ� */
		} else {
			ast_a_normal_sot[0].s4_flg_track = ast_a_normal_sot_prev[0].s4_flg_track +1;					/* PROC.1 */
		}

		ast_a_normal_sot[0].s4_flg_lost = ast_a_normal_sot_prev[0].s4_flg_lost + 1;						/* PROC.2 */
		s4_t_object_num = 1;																			/* PROC.3 */

	} else {
	/***** 5) ����̊ϑ��l�Ȃ��C�O��̗\���l�Ȃ��̃g���b�L���O *****/
	/* ->���Z�b�g */
		fn_init(ast_a_normal_sot, 1);												/* PROC.1 */
		*ps4_a_leading_flg2 = 0;													/* PROC.2 */
	}

	return s4_t_object_num;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check_tracking_heisou_range					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (5)-6)�g���b�L���O�͈͂̔���								*/
/*				:	�����ԕ��W���ǐՏ����𖞂������m�F���A�����𖞂����Ȃ�	*/
/*				:	�Ƃ��͕����ԃt���O���I�t�ɂ���B						*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(5)-6)�g���b�L���O�͈͂̔���							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_side_check_tracking_heisou_range(
	S4 *ps4_a_leading_flg2,
	const NORMAL_BSM ast_a_normal_sot[1]
)
{
	FL tmp_Rxmax;

	/***** 6) �g���b�L���O�͈͂̔���. *****/
	/* �\���l�̊m�F */
	if (*ps4_a_leading_flg2 != 0) {															/* COND.c14 */
		/* �g���b�L���O�͈͂̔���i�O�ɏo����t���O�I�t�j */
		tmp_Rxmax = WALL_MAX;
		if (st_g_bsm_loop_data.afl_wall_width[0] < WALL_MAX) {								/* COND.e5 */
			tmp_Rxmax = st_g_bsm_loop_data.afl_wall_width[0];								/* PROC.1 */
		}

		if ((ast_a_normal_sot[0].fl_Rxpred < SOT_TRACK_XMIN)								/* COND.e6 */
		||  (ast_a_normal_sot[0].fl_Rxpred > tmp_Rxmax)										/* COND.e7 */
		||  (ast_a_normal_sot[0].fl_Rypred > SOT_TRACK_YMAX)								/* COND.e8 */
		||  (ast_a_normal_sot[0].fl_Rypred < SOT_TRACK_YMIN)) {								/* COND.e9 */
			*ps4_a_leading_flg2 = 0;														/* PROC.2 */
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_side_check_wall_for_erase_fa_seg					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �ǔ���(FA �폜�p)											*/
/*--------------------------------------------------------------------------*/
/* ����			: ast_a_normal_sot_ena[1]		: �O�������W��� [in]		*/
/*				  s4_a_fm_obj_flg				: �O�������W���݃t���O [in]	*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-009 (8)�ǔ���(FA �폜�p)		*/
/****************************************************************************/
VD fn_bsm_side_check_wall_for_erase_fa_seg(const NORMAL_BSM ast_a_normal_sot_ena[1], S4 s4_a_fm_obj_flg)
{
	FL fl_t_diff_x;

	/**** 1)FMCW ���W ���茟�o���� ****/
	/* (i) �O������̔��� */
	if ((!(fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN))			/* COND.not(m1) */
	||  (s4_a_fm_obj_flg != (S4)1)) {									/* COND.m2 */
		/* ���{�����ɂ�����Ȃ��ꍇ�̓f�[�^���������A2)�ǔ��� �� */
		st_g_bsm_loop_data.fl_fm_obj_x_pre = CFL_UNKNOWN_VALUE;
		/* ��fl_fm_obj_x_pre��CFL_UNKNOWN_VALUE(�����l)�ɂ����̂ŁA���킹�ăZ�b�g����L���t���O��OFF�ɂ��� */
		/* ��fl_fm_obj_x_pre��u1_flg_fm_obj_x_pre_enable�͕K���A�������邱�� */
		st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable = CU1_DF_OFF;
		st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)0;
	} else {
		/* (ii) FM ���W���ʒu�m�F */
		/* ����m3�͎d�l���ł�fm_obj_x_pre != CFL_UNKNOWN_VALUE�ł��邪�A�����������m�̓����͋֎~����Ă���B */
		/* ���̂��߁AFM���W���ʒu�L���t���Ou1_flg_fm_obj_x_pre_enable��p�ӂ��A��������m�F����悤�ɂ��Ă��� */
		/* ��肽�����Ƃ͎����ł��Ă���̂Ŗ��Ȃ� */
		/* Proc.1 */
		if (st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable == CU1_DF_ON) {			/* COND.m3�̑���ɗL���t���O�����Ă��� */
			/* ���� m3 �������AFM ���W���ʒu�ω��ʂ��Z�o���� */
			/* �Ȃ��A���ʒu�̓t�B���^�l�ł͂Ȃ��ϑ��l���g�p���� */
			fl_t_diff_x = fl_abs(ast_a_normal_sot_ena[0].fl_Rxobs - st_g_bsm_loop_data.fl_fm_obj_x_pre);

			/* Proc.2 */
			/* FM���W���ʒu�ω��ʂ��������Ƃ��AFM���W����J�E���^���J�E���g�A�b�v���� */
			if (fl_t_diff_x < (FL)0.5F) {			/* COND.m4 */
				st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_fm_object_stable_count, (S2)1, (U2)100, (U2)0);	/* PROC.1 */
			} else {
				/* FM���W���ʒu�ω��ʂ��傫���Ƃ��AFM���W����J�E���^������������ */
				st_g_bsm_loop_data.u1_fm_object_stable_count = (U1)0;																						/* PROC.2 */
			}
		}
		
		/* Proc.3 */
		/* �����FM���W���ʒu��ۑ����� */
		st_g_bsm_loop_data.fl_fm_obj_x_pre = ast_a_normal_sot_ena[0].fl_Rxobs;			/* PROC.3 */
		/* ��fl_fm_obj_x_pre�ɍ���̉��ʒu�̒l(�L���l)��ݒ肵���̂ŁA���킹�ăZ�b�g����L���t���O��ON�ɂ��� */
		/* ��fl_fm_obj_x_pre��u1_flg_fm_obj_x_pre_enable�͕K���A�������邱�� */
		st_g_bsm_loop_data.u1_flg_fm_obj_x_pre_enable = CU1_DF_ON;
	}

	/**** 2)�ǔ��� ****/
	/* 2FCW�̕ǔ��茋�ʂƁA1)��FM���W���茟�o���ʂ���A�^�����ǂ����肷�� */
	if (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN) {							/* COND.m1 */
		if (st_g_bsm_loop_data.as4_slow_sot_find[1] > (S4)WALL_REJECT_TH3) {		/* COND.m5 */
			/* 2FCW�ł̕ǔ��茋�ʂ��ǂ��ۂ� �� �ǃt���OON */
			st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)1;					/* PROC.4 */
		} else if (st_g_bsm_loop_data.u1_fm_object_stable_count >= (U1)38) {		/* COND.m6 */
			/* FM���W�ʒu���Ǖt�߂ň��� �� �ǔ��茋�ʕێ�����̂ŉ������Ȃ� */
		} else {
			/* ������ł��Ȃ� �� �ǃt���OOFF */
			st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)0;					/* PROC.5 */
		}
	} else {
		st_g_bsm_loop_data.u1_wall_flg_for_fa_judgement = (U1)0;						/* PROC.5 */
	}

	return;
}


/****************************************************************************/
/* �֐���		: fl_seek_low_speed_sot										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)�ᑬSoT���菈��										*/
/*				:	2FCW�M�����狁�߂����x�E���ʏ�񂩂�A���ԑ������O����*/
/*				:	���W����~�����ڋߕ����̔�����s���B					*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)�ᑬSoT���菈��										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
FL fl_seek_low_speed_sot(
	const FL afl_a_sot_detect_param[9],			/* [in] */
	U1 u1_a_alarming_flag
)
{
	/*for�����[�v�ϐ� */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	S4 i;
#endif	/* VI �\���p */
	S4 j, k;

	/*** �u���b�N�̓r���Ő錾����Ă���ϐ��Q���u���b�N�̐擪�ֈړ� *******************/

	/* for DOA-Velocity line(2FCW I) */
	S4 nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1];
	S4 nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE];

	/* for DOA-Velocity line(2FCW Q) */
	S4 nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1];
	S4 nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE];

	/* for DOA of v=0�iside direction�j */
	S4 v0_doa_def;
	S4 v0_doa;

	/* for appox. line of stationary object line */
	FL dev;
	FL power_ave = 0.0F;

	S4 stationary_doa_line[N_DOA];
	S4 sot_limit_doa_line_forward[N_DOA];
	S4 sot_limit_doa_line_backward[N_DOA];

	FL afl_t_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4];
	FL afl_t_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4];

	S4 fast_sot_num;
	S4 not_fast_sot_num;

	S4 backward_priod = 0;
	S4 forward_point = 0;
	FL tmp_dev[2];
	S4 sot_stop;
	S4 forward_priod = 1;
	U1 u1_t_alarming_flag_local;
	U1 u1_t_num_nearfield_doa_2f_i;
	U1 u1_t_num_nearfield_doa_2f_q;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	tmp_dev[0] = 999.9F;
	tmp_dev[1] = 999.9F;

	fast_sot_num = (S4)0;
	not_fast_sot_num = (S4)0;
	
	u1_t_alarming_flag_local = (U1)0;
	u1_t_num_nearfield_doa_2f_i = (U1)0;
	u1_t_num_nearfield_doa_2f_q = (U1)0;
	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;

	for(j=0; j<N_DOA; j++)
	{
		stationary_doa_line[j] = 0;
	}

	for (j = (S4)0; j < SLOW_SOT_FREQ_BIN_RANGE; j++) {
		for (k = (S4)0; k < (S4)4; k++) {
			afl_t_sot_check_object_i[j][k] = CFL_UNKNOWN_VALUE;
			afl_t_sot_check_object_q[j][k] = CFL_UNKNOWN_VALUE;
		}
	}

	for (j = (S4)0; j < SLOW_SOT_FREQ_BIN_RANGE; j++) {
		nearfield_doa_i[j][0] = (S4)-1;
		nearfield_doa_q[j][0] = (S4)-1;
		nearfield_doa_peak_num_i[j] = (S4)0;
		nearfield_doa_peak_num_q[j] = (S4)0;
	}

/****************************************************************************/
/* (7)	�ᑬSoT���菈��														*/
/****************************************************************************/
/************************************************/
/* 1)	low-speed 2FCW-DOA calculation			*/
/************************************************/
	{
		/* DOA-Velocity line(2FCW I) */
		u1_t_num_nearfield_doa_2f_i = calc_nearfield_doa_2f_I(
			nearfield_doa_i,			/* [out] */
			nearfield_doa_peak_num_i,	/* [out] */
			SLOW_SOT_FREQ_BIN_START_I,	/* [in] */
			afl_t_sot_check_object_i
		);
	}

	{
		/* DOA-Velocity line(2FCW Q) */
		u1_t_num_nearfield_doa_2f_q = calc_nearfield_doa_2f_Q(
			nearfield_doa_q,			/* [out] */
			nearfield_doa_peak_num_q,	/* [out] */
			SLOW_SOT_FREQ_BIN_START_Q,	/* [in] */
			afl_t_sot_check_object_q
		);
	}

/************************************************/
/* 2)	stationary DOA line	calculation			*/
/************************************************/
	/* ideal DOA of v=0�iside direction�j */
	v0_doa_def = (S4)(180.0 - st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_sot_detect_param[2]);
	v0_doa     = (S4)(180.0 - st_g_bsm_loop_data.afl_installed_angle[0] + afl_a_sot_detect_param[2]);

	/* stationary object line(DOA-Velocity line) */
	set_stationary_doa_line_2f(
		stationary_doa_line,		/* [out] */
		v0_doa_def,					/* [in] */
		v0_doa						/* [in] */
	);

	/* ���������� NO NEED TO CALCULATE EVERY CYCLE ���������� */
/************************************************/
/* 3)	SoT limit DOA line	calculation			*/
/************************************************/
	set_sot_limit_doa_line_2f(
		sot_limit_doa_line_backward,
		v0_doa_def,
		v0_doa,
		CFL_SoT_V_TH_BWD
	);
	/* ���������� NO NEED TO CALCULATE EVERY CYCLE ���������� */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memcpy(as4_g_stationary_doa_line, stationary_doa_line, sizeof(S4)*N_DOA);
	memcpy(as4_g_sot_limit_doa_line_backward, sot_limit_doa_line_backward, sizeof(S4)*N_DOA);
	memset(as4_g_nearfield_doa, 0x00, sizeof(as4_g_nearfield_doa));
	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		if(nearfield_doa_i[i][0]!=-1)
		{
			as4_g_nearfield_doa[nearfield_doa_i[i][0]] = SLOW_SOT_FREQ_BIN_START_I+i;
		}
		if(nearfield_doa_q[i][0]!=-1)
		{
			as4_g_nearfield_doa[nearfield_doa_q[i][0]] = SLOW_SOT_FREQ_BIN_START_Q-i;
		}
	}
#endif /*VI �\���p*/


/****************************************************/
/* 4) deviation calulation							*/
/****************************************************/

	fn_bsm_low_calc_deviation(
		forward_priod,
		nearfield_doa_i,
		nearfield_doa_q,
		(const S4 *)stationary_doa_line,
		&backward_priod,
		tmp_dev,
		v0_doa,
		&fast_sot_num,
		&not_fast_sot_num,
		afl_t_sot_check_object_i,
		afl_t_sot_check_object_q
	);


/************************************************/
/* 5)	low-speed SoT judgment					*/
/************************************************/

	fn_bsm_low_judge_sot(
		stationary_doa_line,
		sot_limit_doa_line_forward,
		sot_limit_doa_line_backward,
		(const S4 *)nearfield_doa_peak_num_i,
		nearfield_doa_i,
		(const S4 *)nearfield_doa_peak_num_q,
		nearfield_doa_q,
		forward_priod,
		backward_priod,
		tmp_dev,
		&dev,
		v0_doa,
		u1_a_alarming_flag,
		u1_t_num_nearfield_doa_2f_i,
		u1_t_num_nearfield_doa_2f_q,
		afl_t_sot_check_object_i,
		afl_t_sot_check_object_q,
		&u1_t_num_forward,
		&u1_t_num_backward
	);

/************************************************/
/* 6)	wall judgment							*/
/************************************************/
	fn_bsm_low_judge_wall(
		(const FL *)tmp_dev,
		u1_t_num_nearfield_doa_2f_i,
		u1_t_num_nearfield_doa_2f_q,
		u1_t_num_forward,
		u1_t_num_backward
	);

/************************************************/
/* 7)	fast-SoT judgment						*/
/************************************************/
	fn_bsm_low_judge_fast_sot(
		fast_sot_num,
		not_fast_sot_num,
		u1_a_alarming_flag
	);

/************************************************/
/* 8)	�����ԑ��ݔ���							*/
/************************************************/
	fn_bsm_low_judge_exist_leading_car_main((const S4 (*)[1])nearfield_doa_i,
											(const S4 (*)[1])nearfield_doa_q,
											(const FL (*)[4])afl_t_sot_check_object_i,
											(const FL (*)[4])afl_t_sot_check_object_q);


	return dev;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_calc_deviation									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-4)�ᑬ���ʂƒ�~�����ʋȐ��̕��U�Z�o����				*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-4)�ᑬ���ʂƒ�~�����ʋȐ��̕��U�Z�o����			*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_calc_deviation(
	S4 s4_a_forward_priod,
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_stationary_doa_line[N_DOA],
	S4 *ps4_a_backward_priod,
	FL afl_a_buf_dev[2],
    S4 s4_a_v0_doa,
    S4 *ps4_a_fast_sot_num,
    S4 *ps4_a_not_fast_sot_num,
    FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
    FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{

	S4 fast_sot_limit_line[N_DOA];


	afl_a_buf_dev[0] = 999.9F;
	afl_a_buf_dev[1] = 999.9F;

	if(
		fl_g_v_self_bsm_for_base>5.0F
	)
	{
		{
			afl_a_buf_dev[0] = calc_deviation_of_doa_freq_line_stationary_2(
				(const S4 (*)[1])as4_a_nearfield_doa_i,
				SLOW_SOT_FREQ_BIN_START_I,
				(const S4 *)as4_stationary_doa_line,
				0
				,ps4_a_backward_priod
				,s4_a_v0_doa
				,ps4_a_fast_sot_num
				,ps4_a_not_fast_sot_num
				,fast_sot_limit_line
				,(const FL (*)[4])afl_a_sot_check_object_i
			);
		}

		{
			afl_a_buf_dev[1] = calc_deviation_of_doa_freq_line_stationary_2(
				(const S4 (*)[1])as4_a_nearfield_doa_q,
				SLOW_SOT_FREQ_BIN_START_Q-SLOW_SOT_FREQ_BIN_RANGE,
				(const S4 *)as4_stationary_doa_line,
				1
				,ps4_a_backward_priod
				,s4_a_v0_doa
				,ps4_a_fast_sot_num
				,ps4_a_not_fast_sot_num
				,fast_sot_limit_line
				,(const FL (*)[4])afl_a_sot_check_object_q
			);
		}
	}
	
	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_sot										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)�ᑬSoT���菈��										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)�ᑬSoT���菈��									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_sot(
	S4 as4_stationary_doa_line[N_DOA],
	S4 as4_sot_limit_doa_line_forward[N_DOA],
	S4 as4_sot_limit_doa_line_backward[N_DOA],
	const S4 as4_a_nearfield_doa_peak_num_i[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
	const S4 as4_a_nearfield_doa_peak_num_q[SLOW_SOT_FREQ_BIN_RANGE],
	S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
	S4 s4_a_forward_priod,
	S4 s4_a_backward_priod,
	FL afl_a_buf_dev[2],
	FL *pfl_a_dev,
	S4 v0_doa,
	U1 u1_a_alarming_flag,
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
	U1* pu1_a_num_forward,
	U1* pu1_a_num_backward
)
{
	S4 i;
	S4 j;
	S4 k;

	S4 sot_stop;

	FL fl_t_fast_sot_pow;
	U1 u1_t_lp_front_back;
	U1 u1_t_lp_sot;
	S1 s1_t_lp_data;
	U4 u4_t_lp_target;
	U1 u1_t_flg_exist_object;
	U4 u4_t_lp_max_target_num;		/* �^�[�Q�b�g���W�̃��[�v�̏���l */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͉�����`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	U1 u1_t_tos_flg;				/* ToS status flag */
	U1 u1_t_num_i;					/* Number of SoT objects(approaching) */
	U1 u1_t_num_q;					/* Number of SoT objects(leaving) */
	U1 u1_t_tos_end_flg;			/* ToS end flag (local) */
	FL fl_t_ave_i_y;				/* Average of Ry of nearfield point */
	U1 u1_t_noise_flg;				/* Noise flag */

	fl_t_ave_i_y = (FL)10000.0F;
	u1_t_noise_flg = (U1)0;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	u1_t_flg_exist_object = CU1_DF_OFF;

	/* ���������� (�@)���̓f�[�^�Z�b�g ���������� */
	/* ���U�l�̐ݒ� */
	if(s4_a_backward_priod==0)					/* COND.g24 */
	{
		*pfl_a_dev = afl_a_buf_dev[0];
	}
	else
	{
		*pfl_a_dev = afl_a_buf_dev[1];
	}
	st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[4] = (S4)afl_a_buf_dev[0];
	st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[5] = (S4)afl_a_buf_dev[1];

	/* �^�[�Q�b�g���W�̃��[�v�̏���l��ݒ�(�\�t�g�ϓ_�ɂ�����K�[�h����) */
	/* �^�[�Q�b�g����TARGET_BUFFSIZE�𒴂��Ă��Ȃ������� �����Ă���ꍇ��TARGET_BUFFSIZE������l�Ƃ��� */
	if (st_g_bsm_loop_data.as4_buf_pair_num[1] > (S4)TARGET_BUFFSIZE) {
		u4_t_lp_max_target_num = (U4)TARGET_BUFFSIZE;
	} else {
		/* �^�[�Q�b�g���͕��̒l�ɂȂ�Ȃ����߁AU4�L���X�g���Ă����Ȃ� */
		u4_t_lp_max_target_num = (U4)st_g_bsm_loop_data.as4_buf_pair_num[1];
	}

	/* �׎Ԑ�����J�E���^�̐ݒ� */
	/* �׎Ԑ��̗L����O��̃^�[�Q�b�g���W�ʒu���g���Ĕ��肷�� */
	/* SoT ON ����p�����[�^�ؑւɎg�p���邽�߂̊ȈՓI�Ȕ���ł���A���p���͒��ӁB(�d�l�����̂܂�) */
	for (u4_t_lp_target = (U4)0; u4_t_lp_target < u4_t_lp_max_target_num; u4_t_lp_target++) {
		if ((st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Ryfil > (FL)-20.0F)			/* COND.g62 */
		&&	(st_g_bsm_loop_data.ast_target[u4_t_lp_target].fl_Rxfil > (FL)1.75F)) {			/* COND.g63 */
			u1_t_flg_exist_object = CU1_DF_ON;
			break;
		}
	}

	if (u1_t_flg_exist_object == CU1_DF_ON) {
		/* �O��^�[�Q�b�g���W�ŏ����𖞂������W����ł�����Η׎Ԑ�����J�E���^�C���N�������g PROC.4 */
		/* �㉺���K�[�h��0�`20�ł��� */
		st_g_bsm_loop_data.u1_count_adjacent_lane_exist = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_count_adjacent_lane_exist, (S2)1, (U2)20, (U2)0);
	} else {
		/* �O��^�[�Q�b�g���W�ŏ����𖞂������W������Ȃ��ꍇ�͗׎Ԑ�����J�E���^�f�N�������g PROC.5 */
		/* �㉺���K�[�h��0�`20�ł��� */
		st_g_bsm_loop_data.u1_count_adjacent_lane_exist = (U1)u2_data_add((U2)st_g_bsm_loop_data.u1_count_adjacent_lane_exist, (S2)-1, (U2)20, (U2)0);
	}

	/* ���������� (�A) check condition ���������� */
	/* shift buffer */
	for (u1_t_lp_front_back = (U1)0; u1_t_lp_front_back < (U1)2; u1_t_lp_front_back++) {
		for (u1_t_lp_sot = (U1)0; u1_t_lp_sot < (U1)3; u1_t_lp_sot++) {
			for (s1_t_lp_data = (S1)10; s1_t_lp_data >= (S1)0; s1_t_lp_data--) {
				st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data + 1] = st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data];
				st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data + 1] = st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][s1_t_lp_data];
			}
			st_g_bsm_loop_data.as4_sot_check_sum[u1_t_lp_front_back][u1_t_lp_sot][0] = (S4)0;
			st_g_bsm_loop_data.as4_sot_check_points[u1_t_lp_front_back][u1_t_lp_sot][0] = (S4)0;
		}
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* Check variance of detected nearfield point(SoT object) and set noise flag when the points. */
	st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_sot_jdg_noise_flg(afl_a_sot_check_object_i,
																				 afl_a_buf_dev,
																				 st_g_bsm_loop_data.as4_slow_sot_find[1],
																				 &fl_t_ave_i_y,
																				 &u1_t_noise_flg);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((afl_a_buf_dev[0] > CFL_SOT_DEV_TH)										/* COND.g25 */
	||  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3))			/* COND.g28 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((afl_a_buf_dev[0] > CFL_SOT_DEV_TH)										/* COND.g25 */
	||  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3)				/* COND.g28 */
	||  ((st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH1)			/* COND.g65 */
	&&   (u1_a_alarming_flag != (U1)0)))										/* COND.h86 */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	{
		if ((fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN)					/* COND.g29 */
		&&  (s4_abs( s2_g_curvr_for_base ) > (S4)CU1_CANOUT_CURVER_MIN_SOT)		/* COND.g30 */
		&&  (u1_a_num_nearfield_doa_2f_i > (U1)3)								/* COND.k1 */
		&&  (u1_a_num_nearfield_doa_2f_q > (U1)3)) {							/* COND.k2 */
			/* ���������� (�B)SoT judgement ���������� */

			/* ���������� (�C)check SoT-stationary(limit) difference (forward) ���������� */
			*pu1_a_num_forward = compare_forward_always_2(
				(const S4 (*)[1])as4_a_nearfield_doa_i,			/* [in] */
				(const S4 *)as4_a_nearfield_doa_peak_num_i,		/* [in] */
				(const S4 *)as4_stationary_doa_line,			/* [in] */
				v0_doa,
				(const FL (*)[4])afl_a_sot_check_object_i
			);
			/* ���������� (�D)check SoT-stationary(limit) difference (backward) ���������� */
			*pu1_a_num_backward = compare_backward_always_2(
				(const S4 (*)[1])as4_a_nearfield_doa_q,			/* [in] */
				(const S4 *)as4_a_nearfield_doa_peak_num_q,		/* [in] */
				as4_stationary_doa_line,						/* [in] */
				as4_sot_limit_doa_line_backward,				/* [in] */
				v0_doa,
				CFL_SoT_V_TH_BWD,
				(const FL (*)[4])afl_a_sot_check_object_q
			);
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] :sot_start  */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] :sot_on */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] :sot_off */
			/* st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] :timer */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			/* ���ڊp�x20deg�p�̏��� ��010-1�̊֐��R�[�� */
			fn_bsm_low_judge_check_tos(afl_a_sot_check_object_i,
									   afl_a_sot_check_object_q,
									   &u1_t_tos_end_flg,
									   &u1_t_num_i,
									   &u1_t_num_q,
									   &u1_t_tos_flg);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

			if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0) {								/* COND.g31 */
				if (st_g_bsm_loop_data.as4_slow_sot_find[0] == 0 ) {								/* COND.g32 */
					/* ���������� (�E)check SoT start ���������� */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
					if ((st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)				/* COND.g53 */
					&&  (afl_a_buf_dev[0] > WALL_DEV_TH2)									/* COND.k3 */
					&&  (afl_a_buf_dev[1] > WALL_DEV_TH2)									/* COND.k4 */
					&&  ((*pu1_a_num_forward > (U1)2)										/* COND.k5 */
					||   (*pu1_a_num_backward > (U1)2))) {									/* COND.k6 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
					if ((st_g_bsm_loop_data.afl_wall_width[0] > WALL_WIDTH_TH)				/* COND.g53 */
					&&  (afl_a_buf_dev[0] > WALL_DEV_TH2)									/* COND.k3 */
					&&  (afl_a_buf_dev[1] > WALL_DEV_TH2)									/* COND.k4 */
					&&  ((*pu1_a_num_forward > (U1)2)										/* COND.k5 */
					||   (*pu1_a_num_backward > (U1)2))										/* COND.k6 */
					&&  (u1_t_tos_end_flg == (U1)0)											/* COND.g400 */
					&&  (u1_t_noise_flg == (U1)0)) {										/* COND.g401 */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = check_sot_start(
							afl_a_buf_dev, u1_a_alarming_flag
						);
						if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] == 1) {			/* COND.g33 */
							/*���������� (x)Check SoT DOA ����������*/
							fn_bsm_low_judge_check_sot_doa(&fl_t_fast_sot_pow);
						} else {
							fl_t_fast_sot_pow = (FL)0.0F;
						}
					}
				}
				else
				{
					/* ���������� (�F) check SoT ON->OFF ���������� */
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = check_sot_off(
						(const FL *)afl_a_buf_dev
					);
					
					if ((u1_a_num_nearfield_doa_2f_i < (U1)3)								/* COND.k7 */
					||  (u1_a_num_nearfield_doa_2f_q < (U1)3)) {							/* COND.k8 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
					}
					
					if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] == 1)				/* COND.g34 */
					||  (st_g_bsm_loop_data.as4_slow_sot_find[1] > WALL_REJECT_TH1)) {		/* COND.g35 */
						/* turn off sot flag */
						st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;						/* PROC.2 */
						
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
						
						fl_t_fast_sot_pow = (FL)0.0F;
					}
				}
			} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (u1_a_alarming_flag == (U1)0) {												/* COND.k9 */
					/* �������Ȃ� */
				} else {
					/* ��010-3 */
					if (((u1_t_num_i > (U1)9)													/* COND.g321 */
					&&   (u1_t_num_q > (U1)9)													/* COND.g322 */
					&&   (u1_t_tos_flg == (U1)1))												/* COND.g324 */
					||  ((fl_t_ave_i_y < (FL)10000.0F)											/* COND.g411 */
					&&   (fl_t_ave_i_y > (FL)2.0F))) {											/* COND.g411 */
						st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)0;							/* PROC.p400 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;					/* PROC.p401 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;					/* PROC.p402 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;					/* PROC.p403 */
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;					/* PROC.p404 */
					}
				}
			}
			
			if(st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == (S4)0) {							/* COND.g31 */
				/* �������Ȃ� */
			} else {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

				/* ���������� (�G)check SoT stop ���������� */
				sot_stop = check_sot_stop(	
					(const FL *)afl_a_buf_dev
				);

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (u1_t_noise_flg == (U1)1) {							/* COND.g402 */
					sot_stop = (S4)1;									/* PROC.9 */
				}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

				if (sot_stop == 0) {									/* COND.g36 */
					if (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == CS4_S4MIN) {
						/* S4�̍ŏ��l�ł��邽�ߌ��Z���Ȃ� */
					} else {
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3]--;							/* PROC.3 */
					}
				} else {
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;							/* PROC.4 */
				}

				if (((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)							/* COND.g31 */
				&&   (sot_stop == 0))																/* COND.g36 */
				||  ((fl_g_v_self_bsm_for_base < CFL_SoT_V_TH_BWD)									/* COND.g39 */
				&&   (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0)							/* COND.!g31 */
				&&   (sot_stop == 0))) {															/* COND.g36 */
					/* ���������� (�H)check SoT OFF->ON ���������� */
					st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = check_sot_on(
						(const FL *)afl_a_buf_dev
					);
					
					if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0)						/* COND.!g31 */
					&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] == 1)) {					/* COND.g37 */
						st_g_bsm_loop_data.as4_sot_check_points[1][2][0] = st_g_bsm_loop_data.as4_sot_check_points[1][2][1] + 1;	/* PROC.6 */
					} else {
						st_g_bsm_loop_data.as4_sot_check_points[1][2][0] = st_g_bsm_loop_data.as4_sot_check_points[1][2][1];		/* PROC.7 */
					}
					
					if (fl_g_v_self_bsm_for_base < CFL_SoT_V_TH_BWD) {								/* COND.g39 */
						if ((st_g_bsm_loop_data.as4_sot_check_points[1][2][0] > 5)			/* COND.g38	 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < WALL_REJECT_TH3)		/* COND.g40 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)) {		/* COND.g31 */
							st_g_bsm_loop_data.as4_slow_sot_find[0] = 1;					/* PROC.5 */
						}
					} else {
						if ((st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] == 0)				/* COND.g31 */
						&&  (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] == 1)) {			/* COND.g37 */
							/* turn on sot flag */
							st_g_bsm_loop_data.as4_slow_sot_find[0] = 1;						/* PROC.5 */
						}
					}
					if (st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)0) {
						st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)0;
						
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
						st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
						
						fl_t_fast_sot_pow = (FL)0.0F;
					}
				}
			}
		}
		else
		{
			st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;								/* PROC.1 of 5)(�A) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = 0;						/* PROC.2-1 of 5)(�A) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = 0;						/* PROC.2-1 of 5)(�A) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = 0;						/* PROC.2-1 of 5)(�A) */
			st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;						/* PROC.2-1 of 5)(�A) */

		for(i=0; i<12; i++)
			{
				for(j=0; j<3; j++)
				{
					for(k=0; k<2; k++)
					{
						st_g_bsm_loop_data.as4_sot_check_sum[k][j][i] = 0;		/* PROC.3 of 5)(�A) */
						st_g_bsm_loop_data.as4_sot_check_points[k][j][i] = 0;	/* PROC.4 of 5)(�A) */
					}
				}
			}
		}
	}
	else	/* else of COND.(g25 and g28) */
	{
		st_g_bsm_loop_data.as4_slow_sot_find[0] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = 0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = 0;
		fl_t_fast_sot_pow = (FL)0.0F;
	}

	return;
}


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͊֐���`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_check_tos								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �x��ToS���W����											*/
/*--------------------------------------------------------------------------*/
/* ����			: afl_a_sot_check_object_i[][]	: SoT���W���(�ڋߑ�) [in]	*/
/*				: afl_a_sot_check_object_q[][]	: SoT���W���(���E��) [in]	*/
/*				: pu1_a_tos_end_flg				: ToS�I���t���O(���[�J��) [out]*/
/*				: pu1_a_num_i					: SoT���W��(�ڋߑ�) [out]	*/
/*				: pu1_a_num_q					: SoT���W��(���E��) [out]	*/
/*				: pu1_a_tos_flg					: ToS��ԃt���O [out]		*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: st_g_bsm_alarm_data.afl_alarmed_target[]	: �x��^�[�Q�b�g���*/
/*				: st_g_bsm_loop_data.as4_flg_tos_end[]		: ToS�I���t���O	*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)�ᑬSoT���菈�� (iii) SoT ���� ��010-1 			*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: G.Jomori													*/
/****************************************************************************/
VD fn_bsm_low_judge_check_tos(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
							  FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
							  U1* pu1_a_tos_end_flg,
							  U1* pu1_a_num_i,
							  U1* pu1_a_num_q,
							  U1* pu1_a_tos_flg)
{
	U1 u1_t_lp_target_num;					/* �^�[�Q�b�g���W�̃��[�v�ϐ� �d�l���ł�i */
	U1 u1_t_lp_slow_sot_freq_bin_range;		/* SoT������g���͈͂̃��[�v�ϐ� �d�l���ł�i */

	/* STEP 1: check ToS status (whether there is alarming ToS target or not) */
	*pu1_a_tos_flg = (U1)0;				/* PROC.p100 */

	for (u1_t_lp_target_num = (U1)0; u1_t_lp_target_num < TARGET_BUFFSIZE; u1_t_lp_target_num++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[u1_t_lp_target_num][4] == (FL)1.0F) {		/* COND.g300 */
			*pu1_a_tos_flg = (U1)1;																	/* PROC.p101 */
			break;
		}
	}

	/* STEP 2: count forward objects in SoT objects */
	*pu1_a_num_i = (U1)0;					/* PROC.p110 */
	*pu1_a_num_q = (U1)0;					/* PROC.p111 */
	*pu1_a_tos_end_flg = (U1)0;				/* PROC.p112 */

	for (u1_t_lp_slow_sot_freq_bin_range = (U1)0; u1_t_lp_slow_sot_freq_bin_range < SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_slow_sot_freq_bin_range++) {
		if ((afl_a_sot_check_object_i[u1_t_lp_slow_sot_freq_bin_range][0] != CFL_UNKNOWN_VALUE)			/* COND.g310 */
		&&  (afl_a_sot_check_object_i[u1_t_lp_slow_sot_freq_bin_range][1] > (FL)0.5F)) {				/* COND.g311 */
			(*pu1_a_num_i)++;																				/* PROC.p113 */
		}

		if ((afl_a_sot_check_object_q[u1_t_lp_slow_sot_freq_bin_range][0] != CFL_UNKNOWN_VALUE)			/* COND.g312 */
		&&  (afl_a_sot_check_object_q[u1_t_lp_slow_sot_freq_bin_range][1] > (FL)0.5F)) {				/* COND.g313 */
			(*pu1_a_num_q)++;																				/* PROC.p114 */
		}
	}

	/* STEP 3: check ToS-end */
	if ((*pu1_a_num_i > (U1)9)									/* COND.g321 */
	&&  (*pu1_a_num_q > (U1)9)									/* COND.g322 */
	&&  ((st_g_bsm_loop_data.as4_flg_tos_end[0] != (U1)0)		/* COND.g323 */
	||   (*pu1_a_tos_flg == (U1)1))) {							/* COND.g324 */
		*pu1_a_tos_end_flg = (U1)1;									/* PROC.p120 */
	}

	return;
}

/****************************************************************************/
/* �֐���		: s4_bsm_low_judge_sot_jdg_noise_flg						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: SoT���W�̕��ρE���U�Z�o�ƃm�C�Y�t���O�ݒ�					*/
/*--------------------------------------------------------------------------*/
/* ����			: afl_a_sot_check_object_i[][]	: SoT���W���(�ڋߑ�) [in]	*/
/*				: afl_a_buf_dev[]				: �ᑬ���ʂƒ�~�����ʋȐ��̕��U [in]*/
/*				: s4_a_slow_sot_find1_pre		: �ǃt���O(�O��l) [in]		*/
/*				: pfl_a_ave_i_y					: SoT���W��Ry�̕��� [out]	*/
/*				: pu1_a_noise_flg				: �m�C�Y�t���O [out]		*/
/* �߂�l		: s4_t_flg_sot_find1			: �ǃt���O					*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: s2_g_curvr_for_base					: ����R [m]			*/
/*				: fl_g_v_self_bsm_for_base				: ���ԑ� [km/h]		*/
/*				: st_g_bsm_loop_data.s4_flg_alarm 		: �x��t���O		*/
/*				: st_g_bsm_loop_data.as4_flg_leading[]	: �����ԃt���O		*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-018(291BCVR).pdf				*/
/*				:	(7)-5)�ᑬSoT���菈�� (ii)  ��������̊m�F 				*/
/****************************************************************************/
static S4 s4_bsm_low_judge_sot_jdg_noise_flg(FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
											 FL afl_a_buf_dev[2],
											 S4 s4_a_slow_sot_find1_pre,
											 FL* pfl_a_ave_i_y,
											 U1* pu1_a_noise_flg)
{

	FL fl_t_sum_i_y;				/* Sum of Ry of nearfield point */
	FL fl_t_sum_i_y2;				/* Sum of squares of Ry of nearfield point */
	FL fl_t_ave_i_y;				/* Average of Ry of nearfield point */
	FL fl_t_var_i_y;				/* Varidence of Ry of nearfield point */
	U1 u1_t_n_i;					/* Number of detected nearfield point */
	U1 u1_t_noise_flg;				/* Noise flag */
	S4 s4_t_flg_sot_find1;			/* �ǃt���O(�߂�l�p) */
	U1 u1_t_lp_bin_range;			/* SLOW_SOT_FREQ_BIN_RANGE�̃��[�v�ϐ� �d�l���ł̓��[�v�ϐ���i */
	S4 s4_t_curvr_for_base_abs;		/* ����R�̐�Βl���b�`�ϐ� */

	/* �ϐ������� */
	fl_t_sum_i_y		= (FL)0.0F;
	fl_t_sum_i_y2		= (FL)0.0F;
	fl_t_ave_i_y		= (FL)10000.0F;
	fl_t_var_i_y		= (FL)10000.0F;
	u1_t_n_i			= (U1)0;
	u1_t_noise_flg		= (U1)0;
	s4_t_flg_sot_find1	= s4_a_slow_sot_find1_pre;

	/* ����R�̐�Βl��ݒ� */
	s4_t_curvr_for_base_abs = s4_abs((S4)s2_g_curvr_for_base);

	if ((CFL_CANOUT_VSELF_MIN <= fl_g_v_self_bsm_for_base)			/* COND.p1 */
	&&  (fl_g_v_self_bsm_for_base < (FL)CU1_HEISOU_VSELF_MAX)		/* COND.p1 */
	&&  (s4_t_curvr_for_base_abs >= (S4)CANOUT_CURVER_MIN)) {		/* COND.p2 */
		for (u1_t_lp_bin_range = (U1)0; u1_t_lp_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_bin_range++) {
			if (afl_a_sot_check_object_i[u1_t_lp_bin_range][0] != CFL_UNKNOWN_VALUE) {			/* COND.p3 */
				u1_t_n_i++;																												/* PROC.1 */
				fl_t_sum_i_y += afl_a_sot_check_object_i[u1_t_lp_bin_range][1];															/* PROC.2 */
				fl_t_sum_i_y2 += (afl_a_sot_check_object_i[u1_t_lp_bin_range][1] * afl_a_sot_check_object_i[u1_t_lp_bin_range][1]);		/* PROC.3 */
			} else {
				break;
			}
		}

		if (u1_t_n_i > (U1)0) {			/* COND.p4 */
			fl_t_ave_i_y = fl_t_sum_i_y / (FL)u1_t_n_i;											/* PROC.4 */
			fl_t_var_i_y = (fl_t_sum_i_y2 / (FL)u1_t_n_i) - (fl_t_ave_i_y * fl_t_ave_i_y);		/* PROC.5 */
		}

		if ((afl_a_buf_dev[0] > (FL)WALL_DEV_TH7)			/* COND.p5 */
		&&  (afl_a_buf_dev[0] != (FL)999.9F)) {				/* COND.p5 */
			if ((fl_t_var_i_y > (FL)5.0F)					/* COND.p6 */
			&&  (fl_t_ave_i_y < (FL)2.0F)) {				/* COND.p7 */
				 u1_t_noise_flg = (U1)1;					/* PROC.6 */
			}
		} else {
			if ((fl_t_ave_i_y > (FL)0.5F)								/* COND.p8 */
			&&  (fl_t_ave_i_y < (FL)2.0F)								/* COND.p8 */
			&&  (st_g_bsm_loop_data.s4_flg_alarm != (S4)0)				/* COND.p9 */
			&&  (st_g_bsm_loop_data.as4_flg_leading[0] != (S4)0)) {		/* COND.p10 */
				s4_t_flg_sot_find1 = (S4)0;								/* PROC.7 */
			}
		}
	}

	/* �ŏI���ʂ��o�� */
	*pfl_a_ave_i_y = fl_t_ave_i_y;
	*pu1_a_noise_flg = u1_t_noise_flg;

	return s4_t_flg_sot_find1;
}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_wall										*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)�ǔ��菈��											*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)�ǔ��菈��										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall(
	const FL afl_a_buf_dev[2],
	U1 u1_a_num_nearfield_doa_2f_i,
	U1 u1_a_num_nearfield_doa_2f_q,
	U1 u1_a_num_forward,
	U1 u1_a_num_backward
)
{

	S4 i;
	S4 j;
	S4 backward_point = 0;		/*_20141007_3 */
	S4 backward_point_th = 3;
	S4 forward_point = 0;
	S4 s4_t_point_num;
	U1 u1_t_tos_flag;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	U1 u1_t_wall_checked_flag;

	u1_t_wall_checked_flag = (U1)0;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	u1_t_tos_flag = (U1)0;

	if( fl_g_v_self_bsm_for_base < 15.0F )																								/* COND.i12 */
	{
		backward_point_th = 1;																											/* PROC.1 */
	}
	for( i=0; i<12; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > backward_point_th)														/* COND.i15 */
		||  (st_g_bsm_loop_data.as4_sot_check_points[1][1][i] > backward_point_th))														/* COND.i15' */
		{
			backward_point++;																											/* PROC.2 */
		}
	}

	for (i = (S4)0; i < (S4)12; i++) {
		s4_t_point_num = st_g_bsm_loop_data.as4_sot_check_points[0][0][i] + st_g_bsm_loop_data.as4_sot_check_points[0][1][i] + st_g_bsm_loop_data.as4_sot_check_points[0][2][i];
		
		if (s4_t_point_num != (S4)0) {
			if (((FL)st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] / (FL)s4_t_point_num) > (FL)3.0F) {
				forward_point++;
			}
		}
	}

	if ((afl_a_buf_dev[0] < WALL_DEV_TH5)						/* COND.i3 */
	&&  ((afl_a_buf_dev[1] != (FL)999.9F)						/* COND.i8 */
	||   (backward_point == (S4)0))) {							/* COND.i33 */
		/* (i) When forward deviation is small���{ */
		fn_bsm_low_judge_wall_forward_deviation_small((const FL *)afl_a_buf_dev, forward_point, backward_point);
	} else {
		if (afl_a_buf_dev[0] != (FL)999.9F) {						/* COND.i4 */
			/* (ii) When forward deviation is big���{ */
			fn_bsm_low_judge_wall_forward_deviation_big((const FL *)afl_a_buf_dev, forward_point);
		} else {
			if (fl_g_v_self_bsm_for_base < (FL)20.0F) {				/* COND.i13 */
				/* (iii) When in low speed���{ */
				fn_bsm_low_judge_wall_when_low_speed((const FL *)afl_a_buf_dev, backward_point);
			} else {
				/* (iv) When not in low speed���{ */
				/* �����̐����قȂ邽�߁A���ڊp�x�ɂ�蕪������ */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				fn_bsm_low_judge_wall_when_not_low_speed((const FL *)afl_a_buf_dev, forward_point);
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				fn_bsm_low_judge_wall_when_not_low_speed((const FL *)afl_a_buf_dev, forward_point, &u1_t_wall_checked_flag);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
	}

	/* Set the maximum value of sot_find[1] if it reaches to the upper limit */
	if(st_g_bsm_loop_data.as4_slow_sot_find[1] > (S4)128) {									/* COND.i20 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)128;									/* PROC.4 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if (u1_t_wall_checked_flag == (U1)0) {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* Reset the wall flag if there are enough points be detected and SoT flag is on */
	if ((afl_a_buf_dev[0] == (FL)999.9F)										/* COND.!i4 */
	&&  (afl_a_buf_dev[1] == (FL)999.9F)										/* COND.!i8 */
	&&  (u1_a_num_nearfield_doa_2f_i > (U1)5)									/* COND.i37 */
	&&  (u1_a_num_nearfield_doa_2f_q > (U1)5)									/* COND.i38 */
	&&  (u1_a_num_forward > (U1)2)												/* COND.k5 */
	&&  (u1_a_num_backward > (U1)2)												/* COND.k6 */
	&&  ((st_g_bsm_loop_data.as4_slow_sot_find[0] != (S4)0)						/* COND.!g32 */
	||   (st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != (S4)0))) {			/* COND.g23 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
		} else {
			st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	}		/* if (u1_t_wall_checked_flag == (U1)0)�̏I��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* Reset the wall flag if there is a ToS */
	for (i = (S4)0; i < TARGET_BUFFSIZE; i++) {
		if (st_g_bsm_alarm_data.afl_alarmed_target[i][4] == ALARM_TYPE_TOS) {	/* COND.i39 */
			u1_t_tos_flag = (U1)1;
			break;
		}
	}
	
	if ((afl_a_buf_dev[0] == (FL)999.9F)										/* COND.!i4 */
	&&  (afl_a_buf_dev[1] == (FL)999.9F)										/* COND.!i8 */
	&&  (u1_t_tos_flag == (U1)1)												/* COND.i40 */
    &&  ((u1_a_num_forward != (U1)0)											/* COND.i41 */
    ||   (u1_a_num_backward != (U1)0))) {										/* COND.i42 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
	}


	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_wall_forward_deviation_small				*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)-(�@)When forward deviation is small				*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-�@)When forward deviation is small				*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_forward_deviation_small(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	S4 s4_a_backward_point
)
{

	/* ���������� (�@) When forward deviation is small ���������� */
	if ((afl_a_buf_dev[0] < WALL_DEV_TH2)							/* COND.g18 */
	&&  ((afl_a_buf_dev[1] != (FL)999.9F)							/* COND.i8 */
	||   (s4_a_backward_point == (S4)0))) {							/* COND.i33 */
		st_g_bsm_loop_data.as4_slow_sot_find[1] += 10;			/* PROC.1 */
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH8)					/* COND.i1 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if (s4_a_forward_point < (S4)5) {							/* COND.i9 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=5;		/* PROC.2 */
		}
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH3)					/* COND.g19 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if(afl_a_buf_dev[1]<WALL_DEV_TH2)					/* COND.g21 */
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=5;	/* PROC.2 */
		}
		else
		{

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* ���ڊp�x50deg�ł͏���i47�͂Ȃ� */
			st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;	/* PROC.3 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_a_backward_point < (S4)4) {		/* COND.i47 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;	/* PROC.3 */
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

		}
	} else if ((afl_a_buf_dev[0] < WALL_DEV_TH5)					/* COND.i3 */
		   &&  ((afl_a_buf_dev[1] != (FL)999.9F)					/* COND.i8 */
		   ||   (s4_a_backward_point == (S4)0))) {					/* COND.i33 */
		if (afl_a_buf_dev[1] < WALL_DEV_TH8) {						/* COND.i5 */
			st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)5;		/* PROC.2 */
		} else if ( afl_a_buf_dev[1] < WALL_DEV_TH10) {				/* COND.i6 */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* ���ڊp�x50deg�ł͏���i47�͂Ȃ� */
			st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;		/* PROC.3 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if (s4_a_backward_point < (S4)4) {		/* COND.i47 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;	/* PROC.3 */
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

		} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;		/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			/* ���ڊp�x20deg�ł͏����Ȃ� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
		}
	} else {
		/* �������Ȃ� */
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_wall_forward_deviation_big				*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)-(�A) When forward deviation is big					*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(�A) When forward deviation is big				*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_forward_deviation_big(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
)
{

	/* ���������� (�A) When forward deviation is big ���������� */
	if( st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0 )				/* COND.g23 */
	{
		if( afl_a_buf_dev[1]<WALL_DEV_TH1)									/* COND.g22 */
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;					/* PROC.3 */
		}
		else
		{
			if ((afl_a_buf_dev[0] > CFL_WALL_DEV_TH9)							/* COND.i2 */
			||  ((afl_a_buf_dev[1] > WALL_DEV_TH7)								/* COND.i7 */
			&&   (afl_a_buf_dev[0] > (CFL_SOT_DEV_TH + (FL)5.0F)))) {			/* COND.i34 */
				if (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)) {	/* COND.!i18 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
					st_g_bsm_loop_data.as4_slow_sot_find[1] =0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
					if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
						st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
					} else {
						st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
					}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
				}
			}
		}
	}
	else
	{
		if ((afl_a_buf_dev[0] > CFL_WALL_DEV_TH9)							/* COND.i2 */
		||  ((afl_a_buf_dev[1] > WALL_DEV_TH7)								/* COND.i7 */
		&&   (afl_a_buf_dev[0] > (CFL_SOT_DEV_TH + (FL)5.0F)))) {			/* COND.i34 */
			if ((st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)		/* COND.i18 */
			||  (s4_a_forward_point < (S4)3)) {								/* COND.i35 */
				/* �ǃt���O�̒l�ێ� */
			} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] =0;					/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		} else {
			if ((afl_a_buf_dev[0] < WALL_DEV_TH1)								/* COND.i36 */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)) {			/* COND.g32 */
				st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)2;				/* PROC.3 */
			}
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_wall_when_low_speed						*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)-(�B) When in low speed								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(�B) When in low speed							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_wall_when_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_backward_point
)
{

	/* ���������� (�B) When in low speed ���������� */
	if( st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] != 0 )					/* COND.g23 */
	{
		if( s4_a_backward_point < 4 )											/* COND.i11 */
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH1)									/* COND.g22 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;					/* PROC.3 */
			}
			else
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] =0;						/* PROC.5 */
			}
		}
		else
		{
			st_g_bsm_loop_data.as4_slow_sot_find[1] =0;							/* PROC.5 */
		}
	}
	else
	{
		if( s4_a_backward_point < 4 )											/* COND.i11 */
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH1 )									/* COND.g22 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] +=2;					/* PROC.3 */
			}
			else if( afl_a_buf_dev[1]<WALL_DEV_TH8 )							/* COND.i5 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1]+=1;						/* PROC.4 */
			}
			else
			{
				if (fl_g_v_self_bsm_for_base > CFL_CANOUT_VSELF_MIN) {				/* COND.i14 */
					if (fl_g_v_self_bsm_for_base < 15.0F) {							/* COND.i12 */
						if (st_g_bsm_loop_data.afl_wall_width[0] > 3.0F) {			/* COND.i19 */
							st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;			/* PROC.5 */
						}
					} else {
						if ((!(s4_a_backward_point == (S4)0))								/* COND.!i33 */
						&&  (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH))) {	/* COND.!i18 */
							st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;			/* PROC.5 */
						} else {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
							/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
							st_g_bsm_loop_data.as4_slow_sot_find[1] += (S4)1;			/* PROC.4 */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
						}
					}
				}
			}
		}
		else
		{
			if( afl_a_buf_dev[1]<WALL_DEV_TH2)									/* COND.g21 */
			{
				st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;					/* PROC.3 */
			}
			else
			{
				if (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH)) {	/* COND.i18 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;					/* PROC.5 */
				}
			}
		}
	}

	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_wall_when_not_low_speed					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)-(�C) When not in low speed							*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-6)-(�C) When not in low speed						*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point
)
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
static VD fn_bsm_low_judge_wall_when_not_low_speed(
	const FL afl_a_buf_dev[2],
	S4 s4_a_forward_point,
	U1* pu1_a_wall_checked_flag
)
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
{

	/* ���������� (�C) When not in low speed ���������� */
	if( afl_a_buf_dev[1]<WALL_DEV_TH2 )										/* COND.g21 */
	{
		st_g_bsm_loop_data.as4_slow_sot_find[1] += 2;						/* PROC.3 */
	}
	else if (afl_a_buf_dev[1] < (CFL_SOT_DEV_TH + (FL)10.0F))				/* COND.g22 */
	{
		/* nothing */
	}
	else
	{
		if( afl_a_buf_dev[1] != 999.9F )									/* COND.i8 */
		{
			if( st_g_bsm_loop_data.afl_wall_width[0]<WALL_WIDTH_TH)			/* COND.i18 */
			{
				/* nothing */
			}
			else
			{
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
		else
		{
			if ((s4_a_forward_point > (S4)5)											/* COND.i10 */
			&&  (!(st_g_bsm_loop_data.afl_wall_width[0] < WALL_WIDTH_TH))) {	/* COND.i18 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				st_g_bsm_loop_data.as4_slow_sot_find[1] = 0;				/* PROC.5 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if (st_g_bsm_loop_data.afl_wall_width[0] < (FL)WALL_MAX - (FL)0.3F) {	/* COND.i45 */
					st_g_bsm_loop_data.as4_slow_sot_find[1] = s4_bsm_low_judge_wall_proc8(st_g_bsm_loop_data.as4_slow_sot_find[1]);
					*pu1_a_wall_checked_flag = CU1_DF_ON;
				} else {
					st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
				}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			}
		}
	}

	return;
}


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
/****************************************************************************/
/* �֐���		: s4_bsm_low_judge_wall_proc8								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-6)�ǔ��菈���̏����G									*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_sot_find_1				: �ǃt���O [in]				*/
/* �߂�l		: s4_t_calc_sot_find_1			: ���Z���ʂ̕ǃt���O		*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-012								*/
/*				:	(7)-6)�ǔ��菈���̏����G								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static S4 s4_bsm_low_judge_wall_proc8(S4 s4_a_sot_find_1)
{
	/* ��012-2�̏����̒��ŏ����G�݂̂����ʉ��o���邽��	*/
	/* �����G���֐������A���{�ӏ��ŃR�[������			*/

	S4 s4_t_calc_sot_find_1;

	s4_t_calc_sot_find_1 = s4_a_sot_find_1 - (S4)CFL_WALL_OFF_GAIN;

	/* 0�ŉ����K�[�h */
	if (s4_t_calc_sot_find_1 < (S4)0) {
		s4_t_calc_sot_find_1 = (S4)0;
	}

	return s4_t_calc_sot_find_1;
}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_fast_sot									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-7)Fast-SoT ���菈��									*/
/*				:	(7)-4)-(�B)fast-SoT�̔��茋�ʂɏ]���āAFast-SoT�t���O	*/
/*				:	��ݒ肷��												*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-7)Fast-SoT ���菈��									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static VD fn_bsm_low_judge_fast_sot(
	S4 s4_a_fast_sot_num,
	S4 s4_a_not_fast_sot_num,
	U1 u1_a_alarming_flag
)
{
	U1 u1_t_tos_flg;
	S2 s2_t_fwd_peak_val;
	S2 s2_t_bwd_peak_val;
	U1 u1_t_lp_check_sum;
	
	s2_t_fwd_peak_val = (S2)0;
	s2_t_bwd_peak_val = (S2)0;
	u1_t_tos_flg = (U1)0;
	
	for (u1_t_lp_check_sum = (U1)0; u1_t_lp_check_sum < (U1)12; u1_t_lp_check_sum++) {
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][1][u1_t_lp_check_sum] > s2_t_fwd_peak_val) {
			s2_t_fwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[0][1][u1_t_lp_check_sum];
		}
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][1][u1_t_lp_check_sum] > s2_t_bwd_peak_val) {
			s2_t_bwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[1][1][u1_t_lp_check_sum];
		}
	}
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	if ((s2_t_fwd_peak_val > (S2)800)													/* COND.i43 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((s2_t_fwd_peak_val > (S2)380)													/* COND.i43 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	&&  (s2_t_bwd_peak_val < (S2)100)) {												/* COND.i44 */
		u1_t_tos_flg = (U1)1;
	}
	
	if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (S4)0)								/* COND.i21 */
	&&  (fl_g_v_self_bsm_for_base >= (FL)30.0F)											/* COND.i24 */
	&&  (s4_a_fast_sot_num != (S4)0)) {													/* COND.i25 */
		if ((s4_a_fast_sot_num > (S4)7)													/* COND.i26 */
		&&  (s4_a_fast_sot_num > (s4_a_not_fast_sot_num + (S4)1))) {					/* COND.i27 */
			if (st_g_bsm_loop_data.as4_fast_sot_flg[0] == (S4)0) {						/* COND.i23 */
				if (u1_t_tos_flg == (U1)0) {											/* COND.i46 */
					st_g_bsm_loop_data.as4_fast_sot_flg[0]++;							/* PROC.1 */
				}
			} else {
				st_g_bsm_loop_data.as4_fast_sot_flg[0]++;								/* PROC.1 */
			}
		} else if ((s4_a_fast_sot_num <= (S4)7)											/* COND.i28 */
			   ||  (s4_a_fast_sot_num < s4_a_not_fast_sot_num)) {						/* COND.i29 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			st_g_bsm_loop_data.as4_fast_sot_flg[0]--;									/* PROC.2 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if ((s4_a_fast_sot_num <= (S4)7)											/* COND.i28 */
			&&  (s4_a_fast_sot_num <= (S4)((FL)s4_a_not_fast_sot_num * (FL)0.5F))) {	/* COND.i32 */
				st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;							/* PROC.3 */
			} else {
				st_g_bsm_loop_data.as4_fast_sot_flg[0]--;								/* PROC.2 */
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
		} else {
			/* �l�ێ� */
		}
	} else {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;									/* PROC.3 */
	}
	
	/* 0�`5�ŏ㉺���K�[�h */
	if (st_g_bsm_loop_data.as4_fast_sot_flg[0] > (S4)5) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)5;
	} else if (st_g_bsm_loop_data.as4_fast_sot_flg[0] < (S4)0) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;
	} else {
		/* �l�ێ� */
	}
	
	if (u1_a_alarming_flag == (U1)1) {
		st_g_bsm_loop_data.as4_fast_sot_flg[0] = (S4)0;
	}
	
	return;
}


/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_exist_leading_car_main					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� ���C���֐�									*/
/*--------------------------------------------------------------------------*/
/* ����			: as4_a_nearfield_doa_i[][]		: �ᑬ���ʃo�b�t�@(�ڋߑ�)	*/
/* 				: as4_a_nearfield_doa_q[][]		: �ᑬ���ʃo�b�t�@(���E��)	*/
/* 				: afl_a_sot_check_object_i[][]	: SoT���W(�ڋߑ�)			*/
/* 				: afl_a_sot_check_object_q[][]	: SoT���W(���E��)			*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fn_bsm_low_judge_exist_leading_car_set_jdg_area,			*/
/* 				: fn_bsm_low_judge_exist_leading_car_calc_char,				*/
/* 				: fn_bsm_low_judge_exist_leading_car_jdg,					*/
/* 				: fn_bsm_low_judge_exist_leading_car_mediation				*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ���						*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_main(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
												  const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
												  const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4])
{
	FL fl_t_area_x_near;			/* �ϑ��_�̒��o�͈�(x���W�̓���) */
	FL fl_t_area_x_far;				/* �ϑ��_�̒��o�͈�(x���W�̊O��) */
	FL fl_t_area_y_forward;			/* �ϑ��_�̒��o�͈�(y���W�̑O��) */
	FL fl_t_area_y_backward;		/* �ϑ��_�̒��o�͈�(y���W�̌㑤) */

	U1 u1_t_Ni;						/* �G���A���ϑ��_��(�ڋߑ�) */
	U1 u1_t_Nq;						/* �G���A���ϑ��_��(���E��) */
	FL fl_t_ave_theta_i;			/* �G���A���ϑ��_���ʂ̕���(�ڋߑ�) */
	FL fl_t_ave_theta_q;			/* �G���A���ϑ��_���ʂ̕���(���E��) */
	FL fl_t_var_theta_i;			/* �G���A���ϑ��_���ʂ̕��U(�ڋߑ�) */
	FL fl_t_var_theta_q;			/* �G���A���ϑ��_���ʂ̕��U(���E��) */
	U1 u1_t_flg_point_many;			/* �ϑ��_����t���O */
	U1 u1_t_flg_point_bias;			/* �ϑ��_���΂�t���O */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((st_g_bsm_loop_data.s4_flg_alarm == (S4)0)
	||  (st_g_bsm_loop_data.s1_ctr_heisou_car != (S1)0)) {
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

		/* �@)����G���A�ݒ� */
		fn_bsm_low_judge_exist_leading_car_set_jdg_area(&fl_t_area_x_near, &fl_t_area_x_far, &fl_t_area_y_forward, &fl_t_area_y_backward);

		/* �A)�����ʂ̎Z�o */
		fn_bsm_low_judge_exist_leading_car_calc_char(as4_a_nearfield_doa_i,
													 as4_a_nearfield_doa_q,
													 afl_a_sot_check_object_i,
													 afl_a_sot_check_object_q,
													 fl_t_area_x_near,
													 fl_t_area_x_far,
													 fl_t_area_y_forward,
													 fl_t_area_y_backward,
													 &u1_t_Ni,
													 &u1_t_Nq,
													 &fl_t_ave_theta_i,
													 &fl_t_ave_theta_q,
													 &fl_t_var_theta_i,
													 &fl_t_var_theta_q,
													 &u1_t_flg_point_many,
													 &u1_t_flg_point_bias);

		/* �B)�����Ԕ��� */
		fn_bsm_low_judge_exist_leading_car_jdg(u1_t_Ni,
											   u1_t_Nq,
											   fl_t_ave_theta_i,
											   fl_t_ave_theta_q,
											   fl_t_var_theta_i,
											   fl_t_var_theta_q,
											   u1_t_flg_point_many,
											   u1_t_flg_point_bias);

		/* �C)���⏈�� */
		fn_bsm_low_judge_exist_leading_car_mediation();

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	}					/* ����o1 or o2��END�� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	return;
}

/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_exist_leading_car_set_jdg_area			*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� ����G���A�ݒ�								*/
/*--------------------------------------------------------------------------*/
/* ����			: pfl_a_area_x_near		: ����G���A(x���W�̓���)			*/
/* 				: pfl_a_area_x_far		: ����G���A(x���W�̊O��)			*/
/* 				: pfl_a_area_y_forward	: ����G���A(y���W�̎�O��)			*/
/* 				: pfl_a_area_y_backward	: ����G���A(y���W�̌�둤)			*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ��� �@)����G���A�ݒ�	*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_set_jdg_area(FL* pfl_a_area_x_near,
														  FL* pfl_a_area_x_far,
														  FL* pfl_a_area_y_forward,
														  FL* pfl_a_area_y_backward)
{
	/* �@)����G���A�ݒ� */
	*pfl_a_area_x_near     = (FL)ALARM_X_IN;
	*pfl_a_area_x_far      = (FL)ALARM_X_OUT + (FL)2.0F;
	*pfl_a_area_y_forward  = (FL)ALARM_Y_FORWARD + (FL)1.0F;
	*pfl_a_area_y_backward = CFL_ALARM_Y_BACKWARD;

	return;
}

/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_exist_leading_car_calc_char				*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� �����ʂ̎Z�o								*/
/*--------------------------------------------------------------------------*/
/* ����			: as4_a_nearfield_doa_i[][]		: �ᑬ���ʃo�b�t�@(�ڋߑ�)	*/
/* 				: as4_a_nearfield_doa_q[][]		: �ᑬ���ʃo�b�t�@(���E��)	*/
/* 				: afl_a_sot_check_object_i[][]	: SoT���W(�ڋߑ�)			*/
/* 				: afl_a_sot_check_object_q[][]	: SoT���W(���E��)			*/
/* 				: fl_a_area_x_near				: ����G���A(x���W�̓���)	*/
/* 				: fl_a_area_x_far				: ����G���A(x���W�̊O��)	*/
/* 				: fl_a_area_y_forward			: ����G���A(y���W�̎�O��)	*/
/* 				: fl_a_area_y_backward			: ����G���A(y���W�̌�둤)	*/
/* 				: pu1_a_Ni						: �G���A���ϑ��_��(�ڋߑ�)	*/
/* 				: pu1_a_Nq						: �G���A���ϑ��_��(���E��)	*/
/* 				: pfl_a_ave_theta_i				: �G���A���ϑ��_���ʂ̕���(�ڋߑ�)*/
/* 				: pfl_a_ave_theta_q				: �G���A���ϑ��_���ʂ̕���(���E��)*/
/* 				: pfl_a_var_theta_i				: �G���A���ϑ��_���ʂ̕��U(�ڋߑ�)*/
/* 				: pfl_a_var_theta_q				: �G���A���ϑ��_���ʂ̕��U(���E��)*/
/* 				: pu1_a_flg_point_many			: �ϑ��_����t���O			*/
/* 				: pu1_a_flg_point_bias			: �ϑ��_���΂�t���O		*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ��� �A)�����ʂ̎Z�o		*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_calc_char(const S4 as4_a_nearfield_doa_i[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const S4 as4_a_nearfield_doa_q[SLOW_SOT_FREQ_BIN_RANGE][1],
													   const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4],
													   const FL fl_a_area_x_near,
													   const FL fl_a_area_x_far,
													   const FL fl_a_area_y_forward,
													   const FL fl_a_area_y_backward,
													   U1* pu1_a_Ni,
													   U1* pu1_a_Nq,
													   FL* pfl_a_ave_theta_i,
													   FL* pfl_a_ave_theta_q,
													   FL* pfl_a_var_theta_i,
													   FL* pfl_a_var_theta_q,
													   U1* pu1_a_flg_point_many,
													   U1* pu1_a_flg_point_bias)
{
	U1 u1_t_Ni;						/* �G���A���ϑ��_��(�ڋߑ�) */
	U1 u1_t_Nq;						/* �G���A���ϑ��_��(���E��) */
	FL fl_t_ave_theta_i;			/* �G���A���ϑ��_���ʂ̕���(�ڋߑ�) */
	FL fl_t_ave_theta_q;			/* �G���A���ϑ��_���ʂ̕���(���E��) */
	FL fl_t_var_theta_i;			/* �G���A���ϑ��_���ʂ̕��U(�ڋߑ�) */
	FL fl_t_var_theta_q;			/* �G���A���ϑ��_���ʂ̕��U(���E��) */
	U1 u1_t_flg_point_many;			/* �ϑ��_����t���O */
	U1 u1_t_flg_point_bias;			/* �ϑ��_���΂�t���O */


	/***** �ڋߑ� *****/
	fn_exist_leading_car_calc_char_iq(as4_a_nearfield_doa_i,
									  afl_a_sot_check_object_i,
									  fl_a_area_x_near,
									  fl_a_area_x_far,
									  fl_a_area_y_forward,
									  fl_a_area_y_backward,
									  &u1_t_Ni,
									  &fl_t_ave_theta_i,
									  &fl_t_var_theta_i);

	/***** ���E�� *****/
	fn_exist_leading_car_calc_char_iq(as4_a_nearfield_doa_q,
									  afl_a_sot_check_object_q,
									  fl_a_area_x_near,
									  fl_a_area_x_far,
									  fl_a_area_y_forward,
									  fl_a_area_y_backward,
									  &u1_t_Nq,
									  &fl_t_ave_theta_q,
									  &fl_t_var_theta_q);

	/***** �����ʂ��Z�o *****/
	/* �ϐ������� */
	u1_t_flg_point_many = (U1)0;
	u1_t_flg_point_bias = (U1)0;

	/* �ϑ��_����t���O */
	if ((u1_t_Ni > (U1)7)				/* COND.n4 */
	&&  (u1_t_Nq > (U1)7)) {			/* COND.n4 */
		u1_t_flg_point_many = (U1)1;
	}

	/* �ϑ��_���΂�t���O */
	if ((((S4)u1_t_Nq - (S4)u1_t_Ni) > (S4)5)	/* COND.n5 */
	&&  (u1_t_Ni <= (U1)3)) {					/* COND.n5 */
		u1_t_flg_point_bias = (U1)1;
	}

	/* �ŏI���ʂ��o�� */
	*pu1_a_Ni = u1_t_Ni;
	*pu1_a_Nq = u1_t_Nq;
	*pfl_a_ave_theta_i = fl_t_ave_theta_i;
	*pfl_a_ave_theta_q = fl_t_ave_theta_q;
	*pfl_a_var_theta_i = fl_t_var_theta_i;
	*pfl_a_var_theta_q = fl_t_var_theta_q;
	*pu1_a_flg_point_many = u1_t_flg_point_many;
	*pu1_a_flg_point_bias = u1_t_flg_point_bias;

	return;
}

/****************************************************************************/
/* �֐���		: fn_exist_leading_car_calc_char_iq							*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� �����ʂ̎Z�o ���ʕ���						*/
/*--------------------------------------------------------------------------*/
/* ����			: as4_a_nearfield_doa[][]		: �ᑬ���ʃo�b�t�@			*/
/* 				: afl_a_sot_check_object[][]	: SoT���W					*/
/* 				: fl_a_area_x_near				: ����G���A(x���W�̓���)	*/
/* 				: fl_a_area_x_far				: ����G���A(x���W�̊O��)	*/
/* 				: fl_a_area_y_forward			: ����G���A(y���W�̎�O��)	*/
/* 				: fl_a_area_y_backward			: ����G���A(y���W�̌�둤)	*/
/* 				: pu1_a_N						: �G���A���ϑ��_��			*/
/* 				: pfl_a_ave_theta				: �G���A���ϑ��_���ʂ̕���	*/
/* 				: pfl_a_var_theta				: �G���A���ϑ��_���ʂ̕��U	*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ��� �A)�����ʂ̎Z�o		*/
/****************************************************************************/
static VD fn_exist_leading_car_calc_char_iq(const S4 as4_a_nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],
											const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4],
											const FL fl_a_area_x_near,
											const FL fl_a_area_x_far,
											const FL fl_a_area_y_forward,
											const FL fl_a_area_y_backward,
											U1* pu1_a_N,
											FL* pfl_a_ave_theta,
											FL* pfl_a_var_theta)
{
	U1 u1_t_lp_freq_bin_range;		/* nearfield_doa��sot_check_object��for���[�v(�d�l���ł�i) */
	FL fl_t_min_x;					/* �G���A���̊ϑ��_�̂����A�ł����Ԋ��̓_��X�������� */
	U1 u1_t_N;						/* �G���A���ϑ��_�� */
	FL fl_t_ave_theta;				/* �G���A���ϑ��_���ʂ̕��� */
	S4 s4_t_ave_theta_sum;			/* �G���A���ϑ��_���ʂ̉��Z�l */
	FL fl_t_var_theta;				/* �G���A���ϑ��_���ʂ̕��U */
	S4 s4_t_var_theta_sum;			/* �G���A���ϑ��_���ʂ̓��̉��Z�l */

	/* �ϐ������� */
	fl_t_min_x = CFL_FLMAX;
	u1_t_N = (U1)0;
	fl_t_ave_theta = (FL)0.0F;
	s4_t_ave_theta_sum = (S4)0;
	fl_t_var_theta = (FL)0.0F;
	s4_t_var_theta_sum = (S4)0;

	/* �G���A���̊ϑ��_�̂����A�ł����Ԋ��̓_�� X �����������Z�o */
	for (u1_t_lp_freq_bin_range = (U1)0; u1_t_lp_freq_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_freq_bin_range++) {
		if ((afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] > fl_a_area_x_near)					/* COND.n2_x */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < fl_a_area_x_far)					/* COND.n2_x */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] < fl_a_area_y_forward)				/* COND.n2_y */
		&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] > fl_a_area_y_backward)) {			/* COND.n2_y */
			if (fl_t_min_x > afl_a_sot_check_object[u1_t_lp_freq_bin_range][0]) {
				fl_t_min_x = afl_a_sot_check_object[u1_t_lp_freq_bin_range][0];
			}
		}
	}

	for (u1_t_lp_freq_bin_range = (U1)0; u1_t_lp_freq_bin_range < (U1)SLOW_SOT_FREQ_BIN_RANGE; u1_t_lp_freq_bin_range++) {
		if (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] != (FL)CFL_UNKNOWN_VALUE) {				/* COND.n1 */
			if ((afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] > fl_a_area_x_near)					/* COND.n2_x */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < fl_a_area_x_far)					/* COND.n2_x */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] < fl_a_area_y_forward)				/* COND.n2_y */
			&&  (afl_a_sot_check_object[u1_t_lp_freq_bin_range][1] > fl_a_area_y_backward)) {			/* COND.n2_y */
				/* fl_t_min_x��FL_MAX�̂܂܂��̏����ɓ��B���Ă�����n2�Œe����邽�߁A�I�[�o�[�t���[���Ȃ� */
				if (afl_a_sot_check_object[u1_t_lp_freq_bin_range][0] < (fl_t_min_x + (FL)3.0F)) {		/* COND.n3 */
					u1_t_N++;
					s4_t_ave_theta_sum +=  as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0];
					s4_t_var_theta_sum += (as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0] * as4_a_nearfield_doa[u1_t_lp_freq_bin_range][0]);
				}
			}
		}
	}

	if (u1_t_N != (U1)0) {
		fl_t_ave_theta = (FL)s4_t_ave_theta_sum / (FL)u1_t_N;												/* PROC.1 */
		fl_t_var_theta = ((FL)s4_t_var_theta_sum / (FL)u1_t_N) - (fl_t_ave_theta * fl_t_ave_theta);			/* PROC.2 */
	} else {
		/* Ni or Nq=0 �̂Ƃ��͇@�A�͂����Ȃ킸�Aave��i or ave��q = var��i or ave��q = 10000 �Ƃ��� */
		fl_t_ave_theta = (FL)10000.0F;
		fl_t_var_theta = (FL)10000.0F;
	}

	/* �ŏI���ʂ��o�� */
	*pu1_a_N = u1_t_N;
	*pfl_a_ave_theta = fl_t_ave_theta;
	*pfl_a_var_theta = fl_t_var_theta;

	return;
}

/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_exist_leading_car_jdg					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� �����Ԕ���									*/
/*--------------------------------------------------------------------------*/
/* ����			: u1_a_Ni					: �G���A���ϑ��_��(�ڋߑ�)		*/
/* 				: u1_a_Nq					: �G���A���ϑ��_��(���E��)		*/
/* 				: fl_a_ave_theta_i			: �G���A���ϑ��_���ʂ̕���(�ڋߑ�)*/
/* 				: fl_a_ave_theta_q			: �G���A���ϑ��_���ʂ̕���(���E��)*/
/* 				: fl_a_var_theta_i			: �G���A���ϑ��_���ʂ̕��U(�ڋߑ�)*/
/* 				: fl_a_var_theta_q			: �G���A���ϑ��_���ʂ̕��U(���E��)*/
/* 				: u1_a_flg_point_many		: �ϑ��_����t���O				*/
/* 				: u1_a_flg_point_bias		: �ϑ��_���΂�t���O			*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: s2_g_curvr_for_base		: ����R [m]						*/
/*				: fl_g_v_self_bsm_for_base	: ���ԑ� [km/h]					*/
/*				: afl_g_cvw_fcw_ftt_power[]	: 2FCW�X�y�N�g����				*/
/*				: st_g_bsm_loop_data.s1_ctr_heisou_car	: �����ԑ��݃J�E���^*/
/* <output>		: st_g_bsm_loop_data.s1_ctr_heisou_car	: �����ԑ��݃J�E���^*/
/*				: st_g_bsm_loop_data.u1_flg_heisou_car	: �����ԑ��݃t���O	*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: s4_abs, u1_slipjdg_get_noise_floor,						*/
/* 				: u1_cmn_autoaxis_aac_road_ref_bin_calc, fl_abs				*/
/*				: fl_slipjdg_calc_average_of_2fcw_noise_floor				*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ��� �B)�����Ԕ���		*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_jdg(const U1 u1_a_Ni,
												 const U1 u1_a_Nq,
												 const FL fl_a_ave_theta_i,
												 const FL fl_a_ave_theta_q,
												 const FL fl_a_var_theta_i,
												 const FL fl_a_var_theta_q,
												 const U1 u1_a_flg_point_many,
												 const U1 u1_a_flg_point_bias)
{
	S4 s4_t_curvr_for_base_abs;			/* ����R�̐�Βl���b�`�ϐ� */
	U1 u1_t_counter_vehicle_flg;		/* �Ό��ԑ��݃t���O */
	U1 u1_t_continue_flg;				/* �Ό��ԕ��ϓd�͎Z�o�������s�t���O */
	U1 u1_t_noise_floor_calc_flg;		/* �������m�C�Y�t���A�v�Z�����{�������ۂ��̃t���O */
	FL fl_t_noise_floor;				/* 2FCW�̍��T�C�N���m�C�Y�t���A */
	FL fl_t_v_self_bin_w_margin_dummy;	/* �H�ʔ���bin �H�ʔ���bin�Z�o�֐����g�p���邽�߂̃_�~�[�ϐ� */
	U1 u1_t_v_self_bin_w_margin;		/* �H�ʔ���bin */
	U2 u2_t_lp_fcw_fft_data;			/* 2FCW�X�y�N�g�����̃��[�v�ϐ�(�d�l���ł�i) */
	FL fl_t_diff_ave_iq_abs;			/* ave_theta_i��ave_theta_q�̍��̐�Βl */

	/* ����R�̐�Βl��ݒ� */
	s4_t_curvr_for_base_abs = s4_abs((S4)s2_g_curvr_for_base);

	/* �ᑬ���s���A���A�}���񒆂łȂ��ꍇ�̂ݔ�������{���� */
	if ((CFL_CANOUT_VSELF_MIN <= fl_g_v_self_bsm_for_base)			/* COND.n6 */
	&&  (fl_g_v_self_bsm_for_base < (FL)CU1_HEISOU_VSELF_MAX)		/* COND.n6 */
	&&  (s4_t_curvr_for_base_abs >= (S4)CANOUT_CURVER_MIN)) {		/* COND.n7 */
		/***** �B-1�j�Ό��ԑ��ݔ��� *****/
		/* 2FCW�̃m�C�Y�t���A���������Z�o����Ă��邩�m�F */
		u1_t_noise_floor_calc_flg = u1_slipjdg_get_noise_floor(&fl_t_noise_floor);

		/* �������m�C�Y�t���A���Z�o����Ă��Ȃ��ꍇ�͎Z�o���������{ */
		if (u1_t_noise_floor_calc_flg == CU1_DF_OFF) {
			fl_t_noise_floor = fl_slipjdg_calc_average_of_2fcw_noise_floor(afl_g_cvw_fcw_ftt_power, (U2)20);
		}

		/* �H�ʔ���bin�̎Z�o */
		u1_t_continue_flg = u1_cmn_autoaxis_aac_road_ref_bin_calc(fl_g_v_self_bsm_for_base, &fl_t_v_self_bin_w_margin_dummy, &u1_t_v_self_bin_w_margin);

		u1_t_counter_vehicle_flg = (U1)0;
		if (u1_t_continue_flg == (U1)1) {
			/* 0�`�H�ʔ���bin��2FCW FFT�d�͂��m�F���A臒l�𒴂���d�͒l������΁A�Ό��Ԃ���Ƃ��� */
			for (u2_t_lp_fcw_fft_data = (U2)0; u2_t_lp_fcw_fft_data < (U2)u1_t_v_self_bin_w_margin; u2_t_lp_fcw_fft_data++) {
				if (afl_g_cvw_fcw_ftt_power[u2_t_lp_fcw_fft_data] > (fl_t_noise_floor + (FL)15.0F)) {	/* COND.n8 */
					u1_t_counter_vehicle_flg = (U1)1;
				}
			}
		}

		/***** �B-2�j�����ԑ��݃J�E���^���� *****/
		if ((u1_a_Ni >= (U1)2)							/* COND.n9 */
		&&  (u1_a_Nq >= (U1)2)							/* COND.n9 */
		&&  (u1_t_counter_vehicle_flg == (U1)0)) {		/* COND.n10 */
			/* ����n11�Ŏg�p�����Βl��ݒ� */
			fl_t_diff_ave_iq_abs = fl_abs(fl_a_ave_theta_i - fl_a_ave_theta_q);
			if (fl_t_diff_ave_iq_abs < (FL)15.0F) {		/* COND.n11 */
				if ((fl_a_var_theta_i < (FL)100)			/* COND.n12 */
				&&  (fl_a_var_theta_q < (FL)100)) {			/* COND.n12 */
					if (((s4_t_curvr_for_base_abs > (S4)CU1_HEISOU_CURVER_MIN)		/* COND.n13 */
					||   (u1_a_flg_point_many == (U1)1))							/* COND.n14 */
					&&  (u1_a_flg_point_bias == (U1)0)) {							/* COND.n15 */
						st_g_bsm_loop_data.s1_ctr_heisou_car += (S1)1;				/* PROC.3 */
					}
				} else {
					/* �����ԑ��݃J�E���^�ێ��i�������Ȃ��j*/
				}
			} else {
				if (u1_a_flg_point_many == (U1)1) {							/* COND.n14 */
					st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)2;				/* PROC.4b */
				} else {
					st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)1;				/* PROC.4a */
				}
			}
		} else {
			st_g_bsm_loop_data.s1_ctr_heisou_car -= (S1)1;						/* PROC.4a */

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			if ((u1_a_flg_point_bias == (U1)1)											/* COND.n15' */
			&&  (st_g_bsm_loop_data.as4_slow_sot_find[1] < (S4)WALL_REJECT_TH3)) {		/* COND.n18 */
				 st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)WALL_REJECT_TH3;			/* PROC.8 */
			}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
		}
	} else {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)0;
	}

	/* 0�`18�ŏ㉺���K�[�h */
	if (st_g_bsm_loop_data.s1_ctr_heisou_car > (S1)18) {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)18;
	} else if (st_g_bsm_loop_data.s1_ctr_heisou_car < (S1)0) {
		st_g_bsm_loop_data.s1_ctr_heisou_car = (S1)0;
	} else {
		/* �J�E���^�̒l�ێ� */
	}

	/***** �B-3�j�����ԑ��݃t���O���� *****/
	if (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)0) {
		if (st_g_bsm_loop_data.s1_ctr_heisou_car >= (S1)12) {		/* COND.n16 */
			st_g_bsm_loop_data.u1_flg_heisou_car = (U1)1;			/* PROC.5 */
		}
	}

	if (st_g_bsm_loop_data.u1_flg_heisou_car != (U1)0) {
		if (st_g_bsm_loop_data.s1_ctr_heisou_car <= (S1)6) {		/* COND.n17 */
			st_g_bsm_loop_data.u1_flg_heisou_car = (U1)0;			/* PROC.6 */
		}
	}

	return;
}

/****************************************************************************/
/* �֐���		: fn_bsm_low_judge_exist_leading_car_mediation				*/
/*--------------------------------------------------------------------------*/
/* �@�\			: �����ԑ��ݔ��� ���⏈��									*/
/*--------------------------------------------------------------------------*/
/* ����			: �Ȃ�														*/
/* �߂�l		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: st_g_bsm_loop_data.u1_flg_heisou_car	: �����ԑ��݃t���O	*/
/* <output>		: st_g_bsm_loop_data.as4_slow_sot_find	: �ᑬSoT�t���O		*/
/*				: st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum : �ᑬSoT����]���l*/
/*--------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-016								*/
/*				: (7)�ᑬ SoT ���菈�� 8)�����ԑ��ݔ��� �C)���⏈��			*/
/****************************************************************************/
static VD fn_bsm_low_judge_exist_leading_car_mediation(VD)
{
	/* �����ԑ��݃t���O��1�̂Ƃ��A�ǔ��茋�ʂ�SoT���茋�ʂ����������� */
	if (st_g_bsm_loop_data.u1_flg_heisou_car == (U1)1) {
		/* SoT�t���O */
		st_g_bsm_loop_data.as4_slow_sot_find[0] = (S4)1;
		/* �ᑬSoT����]���l */
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[0] = (S4)1;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[1] = (S4)1;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[2] = (S4)0;
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = (S4)0;
		/* �ǃt���O */
		st_g_bsm_loop_data.as4_slow_sot_find[1] = (S4)0;
	}

	return;
}


 /****************************************************************************/
/* �֐���		: check_fm_object											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (1)FMCW�O�������W���菈��									*/
/*				:	2) FMCW�M���̎��g���s�[�N�̌��o							*/
/*				:	3) ���g���s�[�N���ӂ̔��˔g�̓��������̐���				*/
/*				:	4) ���g���s�[�N���ӂ̔��˔g�̓��������̕��U�̎Z�o		*/
/*				:	5) �O�������W�̗L������									*/
/*				:	6) ���W���̎Z�o										*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:  (1)-2)FMCW�M���̎��g���s�[�N�̌��o						*/
/*				:�`(1)-6)���W���̎Z�o										*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_fm_object(								/* [return] object flag */
	const NORMAL_BSM ast_a_normal_sot_prev[1],	/* [in] object data */
	S4 s4_a_leading_flg,						/* [in] leading car flag */
	NORMAL_BSM ast_a_normal_sot[1]				/* [out] object data */
)
{
	S4 tmp_fm_obj_flg = 0;

	/* �ϐ��錾 */
	S4 i,j;
	S4 tmp_peak_num_up = 0;
	S4 tmp_peak_num_dn = 0;
	FL tmp_wall_thres_up[NB_FFT_PT];
	FL tmp_wall_thres_dn[NB_FFT_PT];
	S4 start_bin;
	S4 end_bin;
	S4 tmp_freq_peak_bin_up[PEAK_BUFFSIZE];
	S4 tmp_freq_peak_bin_dn[PEAK_BUFFSIZE];
	FL tmp_freq_peak_power_up[PEAK_BUFFSIZE];
	FL tmp_freq_peak_power_dn[PEAK_BUFFSIZE];
	FL tmp_doa_spec_up[SOT_FMPEAK_RANGE][N_DOA];
	FL tmp_doa_spec_dn[SOT_FMPEAK_RANGE][N_DOA];
	S4 tmp_doa_peak_bin_up[SOT_FMPEAK_RANGE][1];
	S4 tmp_doa_peak_bin_dn[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_peak_pow_up[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_peak_pow_dn[SOT_FMPEAK_RANGE][1];
	FL tmp_doa_ave_up = 0;
	FL tmp_doa_ave_dn = 0;
	FL tmp_doa_pow_ave_up = 0;
	FL tmp_doa_pow_ave_dn = 0;
	FL tmp_angle_ave_up = 0;
	FL tmp_angle_ave_dn = 0;

	S4 s4_t_sample_num_up_for_ave = 0;
	S4 s4_t_sample_num_dn_for_ave = 0;
	S4 s4_t_sample_num_up_for_dev;
	S4 s4_t_sample_num_dn_for_dev;
	FL tmp_doa_dev_up = 0;
	FL tmp_doa_dev_dn = 0;

	S4 tmp_peak_index_dn = -1;
	S4 tmp_peak_index_up = -1;
	FL tmp_peak_power_diff_min = TH_TT_MAX;
	FL tmp_doa_diff = 180.0F;
	FL tmptmp_peak_power_diff = 0.0F;
	FL tmp_peak_power_up_max = 0.0F;
	FL tmp_peak_power_dn_max = 0.0F;

	FL tmp_fm_theta = 0.0F;
	FL tmp_fm_v = 0.0F;
	FL tmp_fm_vx = 0.0F;
	FL tmp_fm_vy = 0.0F;

	U4 u4_t_lp_fft_pt;
	U4 u4_t_lp_peak_buffsize;
	U4 u4_t_lp_sot_fmpeak_range;
	U4 u4_t_lp_n_doa;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͒�`�Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	FL fl_t_diff_doa_ave_up_dn_abs;
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* ���[�J���ϐ������� */
	for (u4_t_lp_fft_pt = (U4)0; u4_t_lp_fft_pt < (U4)NB_FFT_PT; u4_t_lp_fft_pt++) {
		tmp_wall_thres_up[u4_t_lp_fft_pt] = (FL)0.0F;
		tmp_wall_thres_dn[u4_t_lp_fft_pt] = (FL)0.0F;
	}

	for (u4_t_lp_peak_buffsize = (U4)0; u4_t_lp_peak_buffsize < (U4)PEAK_BUFFSIZE; u4_t_lp_peak_buffsize++) {
		tmp_freq_peak_bin_up[u4_t_lp_peak_buffsize] = (S4)0;
		tmp_freq_peak_bin_dn[u4_t_lp_peak_buffsize] = (S4)0;
		tmp_freq_peak_power_up[u4_t_lp_peak_buffsize] = (FL)0.0F;
		tmp_freq_peak_power_dn[u4_t_lp_peak_buffsize] = (FL)0.0F;
	}

	for (u4_t_lp_sot_fmpeak_range = (U4)0; u4_t_lp_sot_fmpeak_range < (U4)SOT_FMPEAK_RANGE; u4_t_lp_sot_fmpeak_range++) {
		for (u4_t_lp_n_doa = (U4)0; u4_t_lp_n_doa < (U4)N_DOA; u4_t_lp_n_doa++) {
			tmp_doa_spec_up[u4_t_lp_sot_fmpeak_range][u4_t_lp_n_doa] = (FL)0.0F;
			tmp_doa_spec_dn[u4_t_lp_sot_fmpeak_range][u4_t_lp_n_doa] = (FL)0.0F;
		}
		tmp_doa_peak_bin_up[u4_t_lp_sot_fmpeak_range][0] = (S4)-1;
		tmp_doa_peak_bin_dn[u4_t_lp_sot_fmpeak_range][0] = (S4)-1;
		tmp_doa_peak_pow_up[u4_t_lp_sot_fmpeak_range][0] = (FL)0.0F;
		tmp_doa_peak_pow_dn[u4_t_lp_sot_fmpeak_range][0] = (FL)0.0F;
	}

	/***** 2) FMCW�M���̎��g���s�[�N�̌��o *****/
	/* ���������� (�@)�s�[�N�T�[�`�͈͂̐ݒ� ���������� */
	tmp_peak_index_dn = -1;
	tmp_peak_index_up = -1;
	start_bin = NB_FFT_PT/2+2;																							/* PROC.1 */
	end_bin = NB_FFT_PT/2+(S4)(SOT_WALL_MAX/RCOF*0.5F)+SOT_FMPEAK_RANGE;												/* PROC.2 */
	if(st_g_bsm_loop_data.afl_wall_width[0]!= WALL_MAX)																	/* COND.a1 */
	{
		end_bin = NB_FFT_PT/2+(S4)((st_g_bsm_loop_data.afl_wall_width[0]+SOT_WALL_OFFSET)/RCOF*0.5F)+SOT_FMPEAK_RANGE;	/* PROC.3 */
	}
	if(s4_a_leading_flg == 0)											/* COND.a2 */
	{
		/* ���������� (�A)����s�[�N�T�[�` ���������� */
		tmp_peak_num_dn = s4_search_freq_peaks_within_freq_range(		/* SEC.2-2(2) */
			(const FL *)afl_g_cvw_lfm_ftt_power[1],						/* [in] */
			tmp_freq_peak_bin_dn,										/* [out] */
			tmp_freq_peak_power_dn,										/* [out] */
			(const FL *)tmp_wall_thres_dn,								/* [in] */
			0,
			start_bin,													/* [in] FREQ BIN START */
			end_bin														/* [in] FREQ BIN END */
		);
		/* ���������� (�B)���s�[�N�T�[�` ���������� */
		tmp_peak_num_up = s4_search_freq_peaks_within_freq_range(		/* SEC.2-2(2) */
			(const FL *)afl_g_cvw_lfm_ftt_power[0],						/* [in] */
			tmp_freq_peak_bin_up,										/* [out] */
			tmp_freq_peak_power_up,										/* [out] */
			(const FL *)tmp_wall_thres_up,								/* [in] */
			0,
			start_bin,													/* [in] FREQ BIN START */
			end_bin														/* [in] FREQ BIN END */
		);

		/* ���������� (�C)�s�[�N�y�A�̑I�� ���������� */
		for(i=0; i<tmp_peak_num_up; i++)
		{
			for(j=0; j<tmp_peak_num_dn; j++)
			{
				tmptmp_peak_power_diff =  fl_abs(tmp_freq_peak_power_up[i] - tmp_freq_peak_power_dn[j]);/* PROC.1 */
				if ((tmp_freq_peak_power_up[i] >= tmp_peak_power_up_max)								/* COND.a4 */
				&&  (tmp_freq_peak_power_dn[j] >= tmp_peak_power_dn_max)								/* COND.a5 */
				&&  ((tmp_peak_power_diff_min > tmptmp_peak_power_diff)									/* COND.a8 */
				||   ((tmp_freq_peak_power_up[i] >= (tmp_peak_power_up_max + (FL)10.0F))				/* COND.a30 */
				&&    (tmp_freq_peak_power_dn[j] >= (tmp_peak_power_dn_max + (FL)10.0F))				/* COND.a31 */
				&&    ((tmp_peak_power_diff_min + (FL)5.0F) > tmptmp_peak_power_diff)))) {				/* COND.a32 */
					tmp_peak_power_diff_min = tmptmp_peak_power_diff;									/* PROC.2 */
					tmp_peak_power_up_max = tmp_freq_peak_power_up[i];									/* PROC.3 */
					tmp_peak_power_dn_max = tmp_freq_peak_power_dn[j];									/* PROC.4 */
					tmp_peak_index_up = i;																/* PROC.5 */
					tmp_peak_index_dn = j;																/* PROC.6 */
				}
			}
		}
	}
	else
	{
		if( ast_a_normal_sot_prev[0].fl_Robs != CFL_UNKNOWN_VALUE )											/* COND.a3 */
		{
			tmp_peak_index_up = 0;																			/* PROC.1(�B) */
			tmp_peak_index_dn = 0;																			/* PROC.1(�A) */
			tmp_freq_peak_bin_up[tmp_peak_index_up] = ast_a_normal_sot_prev[0].s4_bin_up;					/* PROC.2(�B) */
			tmp_freq_peak_bin_dn[tmp_peak_index_dn] = ast_a_normal_sot_prev[0].s4_bin_dn;					/* PROC.2(�A) */
			tmp_freq_peak_power_up[tmp_peak_index_up] = ast_a_normal_sot_prev[0].fl_power_up;				/* PROC.3(�B) */
			tmp_freq_peak_power_dn[tmp_peak_index_dn] = ast_a_normal_sot_prev[0].fl_power_dn;				/* PROC.3(�A) */
		}
	}

	/***** 3) ���g���s�[�N���ӂ̔��˔g�̓��������̐��� *****/
	if ((tmp_peak_index_dn != -1)																		/* COND.a9 */
	&&  (tmp_peak_index_up != -1)) {																	/* COND.a10 */
		/* ���������� (�@)�p�x�X�y�N�g�����̎Z�o ���������� */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			/* DOWN */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(afl_g_cvw_lfm_ryy_matrix[1][tmp_freq_peak_bin_dn[tmp_peak_index_dn]-2 + i]),	/* [in] */
				tmp_doa_spec_dn[i],																			/* [out] */
				1,																							/* [in] dn */
				tmp_freq_peak_bin_dn[tmp_peak_index_dn]-2 + i
			);
			/* UP */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(afl_g_cvw_lfm_ryy_matrix[0][tmp_freq_peak_bin_up[tmp_peak_index_up]-2 + i]),	/* [in] */
				tmp_doa_spec_up[i],																			/* [out] */
				0,																							/* [in] up */
				tmp_freq_peak_bin_up[tmp_peak_index_up]-2 + i
			);
		}

		/* ���������� (�A)�p�x�X�y�N�g�����̃s�[�N�T�[�` ���������� */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			/* DOWN */
			s4_search_peak_bf(
				(const FL *)tmp_doa_spec_dn[i],		/* [in] */
				tmp_doa_peak_bin_dn[i],				/* [out] */
				tmp_doa_peak_pow_dn[i],				/* [out] */
				1									/* [in] */
			);
			/* UP */
			s4_search_peak_bf(
				(const FL *)tmp_doa_spec_up[i],		/* [in] */
				tmp_doa_peak_bin_up[i],				/* [out] */
				tmp_doa_peak_pow_up[i],				/* [out] */
				1									/* [in] */
			);
		}

		/***** 4) ���g���s�[�N���ӂ̔��˔g�̓��������̕��U�̎Z�o *****/
		s4_t_sample_num_up_for_ave = (S4)0;
		s4_t_sample_num_dn_for_ave = (S4)0;
		s4_t_sample_num_up_for_dev = (S4)0;
		s4_t_sample_num_dn_for_dev = (S4)0;
		/* ���������� (�@)���ϒl�̎Z�o ���������� */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			if ((tmp_doa_peak_bin_dn[i][0] != (S4)-1)					/* COND.a11 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			&&  (tmp_doa_peak_bin_dn[i][0] > (S4)53)) {					/* COND.a33 ���ڊp�x50deg�p�̏��� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			&&  (tmp_doa_peak_bin_dn[i][0] > (S4)90 - (S4)AXIS_DEFAULT + (S4)3)) {                 /* COND.a33 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
				tmp_doa_ave_dn += (FL)tmp_doa_peak_bin_dn[i][0];
				tmp_doa_pow_ave_dn += tmp_doa_peak_pow_dn[i][0];
				s4_t_sample_num_dn_for_ave++;
			}
			if ((tmp_doa_peak_bin_up[i][0] != (S4)-1)					/* COND.a11 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
			&&  (tmp_doa_peak_bin_up[i][0] > (S4)53)) {					/* COND.a33 ���ڊp�x50deg�p�̏��� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
			&&  (tmp_doa_peak_bin_up[i][0] > (S4)90 - (S4)AXIS_DEFAULT + (S4)3)) {                 /* COND.a33 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
				tmp_doa_ave_up += (FL)tmp_doa_peak_bin_up[i][0];
				tmp_doa_pow_ave_up += tmp_doa_peak_pow_up[i][0];
				s4_t_sample_num_up_for_ave++;
			}
		}
		
		if (s4_t_sample_num_dn_for_ave != (S4)0) {
			tmp_doa_ave_dn = tmp_doa_ave_dn / (FL)s4_t_sample_num_dn_for_ave;
			tmp_doa_pow_ave_dn = tmp_doa_pow_ave_dn / (FL)s4_t_sample_num_dn_for_ave;
		} else {
			/* �s�[�N���Ȃ��Ƃ��͕��ϒl���Z�o�ł��Ȃ�����0������ */
			tmp_doa_ave_dn = (FL)0.0F;
			tmp_doa_pow_ave_dn = (FL)0.0F;
		}
		
		if (s4_t_sample_num_up_for_ave != (S4)0) {
			tmp_doa_ave_up = tmp_doa_ave_up / (FL)s4_t_sample_num_up_for_ave;
			tmp_doa_pow_ave_up = tmp_doa_pow_ave_up / (FL)s4_t_sample_num_up_for_ave;
		} else {
			/* �s�[�N���Ȃ��Ƃ��͕��ϒl���Z�o�ł��Ȃ�����0������ */
			tmp_doa_ave_up = (FL)0.0F;
			tmp_doa_pow_ave_up = (FL)0.0F;
		}

		/* ���������� (�A)���U�l�̎Z�o ���������� */
		for (i = (S4)0; i < SOT_FMPEAK_RANGE; i++) {
			if(	tmp_doa_peak_bin_dn[i][0] != -1 )						/* COND.a11 */
			{
				tmp_doa_dev_dn += ((FL)tmp_doa_peak_bin_dn[i][0] - tmp_doa_ave_dn) * ((FL)tmp_doa_peak_bin_dn[i][0] - tmp_doa_ave_dn);
				s4_t_sample_num_dn_for_dev++;
			}
			if(	tmp_doa_peak_bin_up[i][0] != -1 )						/* COND.a11 */
			{
				tmp_doa_dev_up += ((FL)tmp_doa_peak_bin_up[i][0] - tmp_doa_ave_up) * ((FL)tmp_doa_peak_bin_up[i][0] - tmp_doa_ave_up);
				s4_t_sample_num_up_for_dev++;
			}
		}
		if (s4_t_sample_num_dn_for_dev != (S4)0) {
			tmp_doa_dev_dn = tmp_doa_dev_dn / (FL)s4_t_sample_num_dn_for_dev;
		} else {
			/* �s�[�N���Ȃ��Ƃ��͕��U���Z�o�ł��Ȃ����ߕs��l������999.9������ */
			tmp_doa_dev_dn = (FL)999.9F;
		}
		
		if (s4_t_sample_num_up_for_dev != (S4)0) {
			tmp_doa_dev_up = tmp_doa_dev_up / (FL)s4_t_sample_num_up_for_dev;
		} else {
			/* �s�[�N���Ȃ��Ƃ��͕��U���Z�o�ł��Ȃ����ߕs��l������999.9������ */
			tmp_doa_dev_up = (FL)999.9F;
		}
	}

	/***** 5) �O�������W�̗L������ *****/
	/* DOA���ԍ��W�n�ɕϊ� */
	/* DOWN */
	tmp_angle_ave_dn = -(st_g_bsm_loop_data.afl_installed_angle[0] + DOA_ANG_PER_BIN*tmp_doa_ave_dn + DOA_BIN_START_ANG);
	/* UP */
	tmp_angle_ave_up = -(st_g_bsm_loop_data.afl_installed_angle[0] + DOA_ANG_PER_BIN*tmp_doa_ave_up + DOA_BIN_START_ANG);
	tmp_fm_obj_flg = 0;
	if ((tmp_peak_index_dn != -1)													/* COND.a9 */
	&&  (tmp_peak_index_up != -1)) {												/* COND.a10 */
		if ((tmp_freq_peak_power_up[tmp_peak_index_up] > WALL_OBJECT_POW_TH)		/* COND.a12 */
		&&  (tmp_freq_peak_power_dn[tmp_peak_index_dn] > WALL_OBJECT_POW_TH)) {		/* COND.a13 */
			/* ����2(�����Ԃ�����Ƃ�) */
			if ((s4_a_leading_flg != 0)												/* COND.a28 */
			&&  ((s4_t_sample_num_up_for_ave > (SOT_FMPEAK_RANGE - (S4)1))			/* COND.a14 */
			||   (s4_t_sample_num_dn_for_ave > (SOT_FMPEAK_RANGE - (S4)1)))			/* COND.a15 */
			&&  (tmp_angle_ave_up < WALL_ANGLE_TH_BACKWARD_WITHCAR)					/* COND.a16 */
			&&  (tmp_angle_ave_dn < WALL_ANGLE_TH_BACKWARD_WITHCAR)					/* COND.a17 */
			&&  (tmp_angle_ave_up > WALL_ANGLE_TH_FORWARD_WITHCAR)					/* COND.a18 */
			&&  (tmp_angle_ave_dn > WALL_ANGLE_TH_FORWARD_WITHCAR)					/* COND.a19 */
			&&  (tmp_doa_dev_dn < WALL_ANGLE_TH_DIV_WITHCAR)						/* COND.a20 */
			&&  (tmp_doa_dev_up < WALL_ANGLE_TH_DIV_WITHCAR)) {						/* COND.a21 */
				tmp_fm_obj_flg = 1;
			} else if (((s4_t_sample_num_up_for_ave > (SOT_FMPEAK_RANGE - (S4)1))	/* COND.a14 */
				   ||   (s4_t_sample_num_dn_for_ave > (SOT_FMPEAK_RANGE - (S4)1)))	/* COND.a15 */
				   &&  (tmp_angle_ave_up < WALL_ANGLE_TH_BACKWARD_NOCAR)			/* COND.a22 */
				   &&  (tmp_angle_ave_dn < WALL_ANGLE_TH_BACKWARD_NOCAR)			/* COND.a23 */
				   &&  (tmp_angle_ave_up > WALL_ANGLE_TH_FORWARD_NOCAR)				/* COND.a24 */
				   &&  (tmp_angle_ave_dn > WALL_ANGLE_TH_FORWARD_NOCAR)				/* COND.a25 */
				   &&  (tmp_doa_dev_dn < WALL_ANGLE_TH_DIV_NOCAR)					/* COND.a26 */
				   &&  (tmp_doa_dev_up < WALL_ANGLE_TH_DIV_NOCAR)) {				/* COND.a27 */
				/* ����1(�����Ԃ����Ȃ��Ƃ�=��) */
				tmp_fm_obj_flg = 1;

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				/* Reset fm object flag if the doa difference between up and dn is too large and peak power is small */
				fl_t_diff_doa_ave_up_dn_abs = fl_abs(tmp_doa_ave_up - tmp_doa_ave_dn);

				if ((st_g_bsm_loop_data.as4_slow_sot_find[0] == (U1)1)				/* COND.a50 */
				&&  (st_g_bsm_loop_data.s4_flg_alarm == (U1)0)						/* COND.a51 */
				&&  (fl_t_diff_doa_ave_up_dn_abs > (FL)20.0F)						/* COND.a52 */
				&&  (tmp_freq_peak_power_up[tmp_peak_index_up] < (FL)60.0F)			/* COND.a53_up */
				&&  (tmp_freq_peak_power_dn[tmp_peak_index_dn] < (FL)60.0F)) {		/* COND.a53_dn */
					tmp_fm_obj_flg = (S4)0;
				}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
			} else {
				/* �������Ȃ� */
			}
		}
	}

	/***** 6) ���W���̎Z�o *****/
	if(tmp_fm_obj_flg == 1)													/* COND. a29 */
	{
		/* NORMAL_BSM�f�[�^�Z�b�g */
		/* S4 */
		ast_a_normal_sot[0].s4_bin_up = tmp_freq_peak_bin_up[tmp_peak_index_up];
		ast_a_normal_sot[0].s4_bin_dn = tmp_freq_peak_bin_dn[tmp_peak_index_dn];
		ast_a_normal_sot[0].fl_bin_up_interpolate = (FL)tmp_freq_peak_bin_up[tmp_peak_index_up];
		ast_a_normal_sot[0].fl_bin_dn_interpolate = (FL)tmp_freq_peak_bin_dn[tmp_peak_index_dn];

		ast_a_normal_sot[0].s4_bin_up_music = (S4)tmp_doa_ave_up;
		ast_a_normal_sot[0].s4_bin_dn_music = (S4)tmp_doa_ave_dn;
		ast_a_normal_sot[0].fl_doa_up_interpolate = tmp_doa_ave_up;
		ast_a_normal_sot[0].fl_doa_dn_interpolate = tmp_doa_ave_dn;

		/* FL */
		ast_a_normal_sot[0].fl_power_up = tmp_freq_peak_power_up[tmp_peak_index_up];
		ast_a_normal_sot[0].fl_power_dn = tmp_freq_peak_power_dn[tmp_peak_index_dn];
		ast_a_normal_sot[0].fl_power_up_music = tmp_doa_pow_ave_up;
		ast_a_normal_sot[0].fl_power_dn_music = tmp_doa_pow_ave_dn;
		ast_a_normal_sot[0].fl_theta_up = fl_transform_doabin_to_rad(	/* DBF(S4) */
			ast_a_normal_sot[0].s4_bin_up_music,
			0
		);
		ast_a_normal_sot[0].fl_theta_dn = fl_transform_doabin_to_rad(	/* DBF(S4) */
			ast_a_normal_sot[0].s4_bin_dn_music,
			1
		);
		ast_a_normal_sot[0].fl_Robs	=  -RCOF * (FL)(ast_a_normal_sot[0].s4_bin_up + ast_a_normal_sot[0].s4_bin_dn - NB_FFT_PT);
		ast_a_normal_sot[0].fl_Rxobs = (FL)(ast_a_normal_sot[0].fl_Robs*(FL)fl_sin( DOA_ANG_PER_BIN*0.5F*(ast_a_normal_sot[0].fl_theta_up+ast_a_normal_sot[0].fl_theta_dn) )+ st_g_bsm_loop_data.afl_installed_angle[1]);
		ast_a_normal_sot[0].fl_Ryobs = (FL)(ast_a_normal_sot[0].fl_Robs*(FL)fl_cos( DOA_ANG_PER_BIN*0.5F*(ast_a_normal_sot[0].fl_theta_up+ast_a_normal_sot[0].fl_theta_dn) ) );
		tmp_fm_theta = 0.0F;
		tmp_fm_v = 0.0F;
		tmp_fm_vx = 0.0F;
		tmp_fm_vy = 0.0F;
		tmp_fm_theta = 0.5F*(ast_a_normal_sot[0].fl_theta_up + ast_a_normal_sot[0].fl_theta_dn);
		tmp_fm_v = -VCOF * (FL)(ast_a_normal_sot[0].s4_bin_up - ast_a_normal_sot[0].s4_bin_dn);
		tmp_fm_vx = 0.0F;
		tmp_fm_vy = tmp_fm_v;

		tmp_fm_vy = fl_get_vy(tmp_fm_v, fl_cos(tmp_fm_theta), ast_a_normal_sot[0].fl_Ryobs, fl_g_v_self_bsm_for_base);

		ast_a_normal_sot[0].fl_Vobs = tmp_fm_v;
		ast_a_normal_sot[0].fl_Vxobs = tmp_fm_vx;
		ast_a_normal_sot[0].fl_Vyobs = tmp_fm_vy;
	}

	return tmp_fm_obj_flg;
}


 /****************************************************************************/
/* �֐���		: check_fm_spectrum											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)�e�l�b�v���W�ڋߔ��菈��								*/
/*				:	FMCW �M���̎��g���X�y�N�g�����̌`��̓�������C			*/
/*				:	�ڋ߂��镨�W�̗L���̔�����s���D						*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)�e�l�b�v���W�ڋߔ��菈��								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_fm_spectrum(								/* [return] approaching object flag */
	FL sot_thres_up[NB_FFT_PT],						/* [out](for debug) threashold for wall estimation�iFM up) */
	FL sot_thres_dn[NB_FFT_PT]						/* [out](for debug) threashold for wall estimation�iFM dn) */
)
{
	/* �ϐ��錾 */
	S4 tmp_fm_flg = 0;

	S4 wall_check_up[3];
	S4 wall_check_dn[3];
	S4 wall_bin_up[3];
	S4 wall_bin_dn[3];
	FL wall_pow_up[3];
	FL wall_pow_dn[3];
	S4 ret_up;	/* (not used) */
	S4 ret_dn;	/* (not used) */

	/* �O�l��															*/
	/*        ___														*/
	/*       |   |          ��											*/
	/*       |   |          | WALL_FREQ_POW_DIFF �ȏ�㏸(�܂��͉��~)	*/
	/*     __|   |_____ ....��											*/
	/*    |            |    ��											*/
	/*    |            |    | WALL_FREQ_POW_DIFF �ȏ�㏸(�܂��͉��~)	*/
	/* ___|            |___ ��											*/
	/*																	*/

	/* UP */
	/***** 1) ���ω��X�y�N�g�����̎Z�o *****/
	set_freq_threshold_without_center_mask(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],		/* [in] */
		sot_thres_up								/* [out] */
	);
	/***** 2) �x�[�X�d�͂̎Z�o *****/
	/***** 3) �ڋߔ���p�����ʂ̎Z�o *****/
	/***** 4) �ڋߔ��� *****/
	ret_up = set_wall_freq_threshold(
		(const FL *)sot_thres_up,		/* [in] */
		sot_thres_up,					/* [out] */
		wall_check_up,					/* [out] */
		wall_bin_up,					/* [out] */
		wall_pow_up,					/* [out] */
		WALL_UP_FREQ_BIN_TH_LOWER_LIMIT,/* [in] */
		WALL_UP_FREQ_BIN_TH_UPPER_LIMIT /* [in] */
	);

	/* DOWN */
	/***** 1) ���ω��X�y�N�g�����̎Z�o *****/
	set_freq_threshold_without_center_mask(
		(const FL *)afl_g_cvw_lfm_ftt_power[1],		/* [in] */
		sot_thres_dn								/* [out] */
	);
	/***** 2) �x�[�X�d�͂̎Z�o *****/
	/***** 3) �ڋߔ���p�����ʂ̎Z�o *****/
	ret_dn = set_wall_freq_threshold(
		(const FL *)sot_thres_dn,		/* [in] */
		sot_thres_dn,					/* [out] */
		wall_check_dn,					/* [out] */
		wall_bin_dn,					/* [out] */
		wall_pow_dn,					/* [out] */
		WALL_DN_FREQ_BIN_TH_LOWER_LIMIT,/* [in] */
		WALL_DN_FREQ_BIN_TH_UPPER_LIMIT /* [in] */
	);

	/***** 4) �ڋߔ��� *****/
	tmp_fm_flg = s4_bsm_side_check_fm_approaching_object(
		(const FL *)sot_thres_up,			/* [in] */
		(const FL *)sot_thres_dn,			/* [in] */
		(const S4 *)wall_check_up,			/* [in] */
		(const S4 *)wall_check_dn,			/* [in] */
		(const S4 *)wall_bin_up,			/* [in] */
		(const S4 *)wall_bin_dn,			/* [in] */
		(const FL *)wall_pow_up,			/* [in] */
		(const FL *)wall_pow_dn				/* [in] */
	);

	return tmp_fm_flg;
}


/****************************************************************************/
/* �֐���		: s4_bsm_side_check_fm_approaching_object					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-4)�ڋߔ���											*/
/*				:	FMCW�̏��M���Ɖ���M���̐ڋߔ���p�̓����ʂɊ�Â��A	*/
/*				:	�ڋ߂��镨�W�����邩�ۂ��̔�����s���B���Ԃ����Ԃ�ǂ�	*/
/*				:	�z���ꍇ�ɂ́A���Ԃ͎��Ԃ̂����ׂɑ��݂��邱�ƂƂȂ�A	*/
/*				:	���Sbin�t�߂̓d�͂͑傫�����傷��B���̂��߁A���Ȃ��Ƃ�	*/
/*				:	��2�ω��_�܂ł͊ϑ�����邱�ƂƂȂ�B�����ŁA��2�ω��_�A*/
/*				:	�܂��́A��3�ω��_������͈͓̔��ɂ���A�ω��ʂ�����̒l	*/
/*				:	�����傫���Ƃ��A�ڋ߂��镨�W������Ɣ��肷��B		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-4)�ڋߔ���											*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
static S4 s4_bsm_side_check_fm_approaching_object(
	const FL afl_a_sot_thres_up[NB_FFT_PT],
	const FL afl_a_sot_thres_dn[NB_FFT_PT],
	const S4 as4_a_wall_check_up[3],
	const S4 as4_a_wall_check_dn[3],
	const S4 as4_a_wall_bin_up[3],
	const S4 as4_a_wall_bin_dn[3],
	const FL afl_a_wall_pow_up[3],
	const FL afl_a_wall_pow_dn[3]
)
{
	S4 i;
	S4 s4_t_fm_flg;
	S4 tmp_up_flg = 0;
	S4 tmp_dn_flg = 0;

	s4_t_fm_flg = 0;

	/***** 4) �ڋߔ��� *****/
	/* �R�ω��_����̍l����														*/
	/* base-><-0-><-1-><-2----> (:wall_check_** �c �X�e�b�v�������1)			*/
	/*                  _______													*/
	/*                 |														*/
	/*            _____|														*/
	/*           |																*/
	/*       ____|																*/
	/*      |																	*/
	/* _____|																	*/
	/*           +     +    +													*/
	/*          [1]   [2]  [3]  (:wall_bin_** �c �n�܂��bin)					*/
	/*  <-3->�̃X�e�b�v��������													*/
	/*  [2]�� WALL_FREQ_BIN_LOWER_STEP1 �` WALL_FREQ_BIN_UPPER_STEP1 �̊�		*/
	/*  [3]�� WALL_FREQ_BIN_LOWER_STEP2 �` WALL_FREQ_BIN_UPPER_STEP2 �̊�		*/

	/* ���������� (�@)����M���̔��� ���������� */
	tmp_dn_flg = 0;
	for (i = 1; i < WALL_FREQ_BIN_TH_STEPS; i++) {
		if ((as4_a_wall_check_dn[i] == 1)										/* COND.b9 */
		||  ((afl_a_wall_pow_dn[i] - afl_a_sot_thres_dn[0]) >= WALL_PEAK_TH)) {	/* COND.b10 */
			if ((as4_a_wall_bin_dn[i] > WALL_FREQ_BIN_LOWER_STEP1_DN)			/* COND.b11 */
			&&  (as4_a_wall_bin_dn[i] <= WALL_FREQ_BIN_UPPER_STEP1_DN)) {		/* COND.b12 */
				tmp_dn_flg = 1;													/* PROC.1 */
				break;
			}
		}
	}
	/* ���������� (�A)���M���̔��� ���������� */
	tmp_up_flg = 0;
	for (i = 1; i < WALL_FREQ_BIN_TH_STEPS; i++) {
		if ((as4_a_wall_check_up[i] == 1)										/* COND.b13 */
		&&  ((afl_a_wall_pow_up[i] - afl_a_sot_thres_up[0]) >= WALL_PEAK_TH)) {	/* COND.b14	 */
			if (as4_a_wall_bin_up[i] >= as4_a_wall_bin_dn[1]) {					/* COND.b15 */
				tmp_up_flg = 1;													/* PROC.1 */
				break;
			}
		}
	}
	/* ���������� (�B)�������� ���������� */
	if ((tmp_dn_flg != 0)											/* COND.b16 */
	&&  (tmp_up_flg != 0)) {										/* COND.b17 */
		s4_t_fm_flg = 1;											/* PROC.1 */
	}

	return s4_t_fm_flg;
}


/****************************************************************************/
/* �֐���		: set_stationary_doa_line_2f								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-2)��~���Ȑ��̎Z�o����								*/
/*				:	���[�_�ɂČ��o����鑬�x�́A���[�_�Ɍ����������̐����̂�*/
/*				:	�ƂȂ邽�߁A���Ԃ����xv_self[km/h]�ő��s���Ă���Ƃ���	*/
/*				:	���ʃ�x�ɂ����~���̌��o���xVx�́A�����ɂ�����炸�A	*/
/*				:	�֐����̎��ŋ��߂���B�]���āA���ԑ�v_self[km/h]�ő��s*/
/*				:	���Ă���Ƃ��́A�e����bin�ɂ������~���̌��o���x�ɑ���	*/
/*				:	����2FCW�̎��g��bin�͉��L�̑��x���ʋȐ��Ƃ��ċ��߂���	*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-2)��~���Ȑ��̎Z�o����								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
VD set_stationary_doa_line_2f(
	S4 stationary_doa_line[N_DOA],		/* [out] ��~����DOA/FREQ */
	S4 v0_doa_def,						/* [in] */
	S4 v0_doa							/* [in] */
)
{
	S4 i;
	S4 car_dir = v0_doa - v0_doa_def;	/* => 0 */
	for(i=0; i<N_DOA; i++)
	{
		stationary_doa_line[i] = NB_FFT_PT_2F / 2 + (S4)(fl_g_v_self_bsm_for_base
												  * fl_cos(PI / (FL)180.0F * (FL)car_dir) / 3.6F
												  * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa))
												  / VCOF_2F);
	}
}


/****************************************************************************/
/* �֐���		: set_sot_limit_doa_line_2f									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-3)SoT���o���x���E�Ȑ��̎Z�o����						*/
/*				:	(7)-2)�Ɠ��l�ɁA���ԂƂ̑��Α��x��SoT�̌��o���E			*/
/*				:	SoT_V_TH_BWD[km/h]�̕��̂̑��x���ʋȐ������߂�B		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-3)SoT���o���x���E�Ȑ��̎Z�o����						*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
VD set_sot_limit_doa_line_2f(
	S4 sot_limit_doa_line[N_DOA],		/* [out] SoT��DOA/FREQ */
	S4 v0_doa_def,						/* [in] */
	S4 v0_doa,							/* [in] */
	FL v_sot_offset						/* [in] */
)
{
	S4 i;
	S4 car_dir = v0_doa - v0_doa_def;	/* =>0 */
	S4 tmp_doa = 0;
	for (i = 0; i < N_DOA; i++) {
		tmp_doa = NB_FFT_PT_2F / 2 + (S4)((v_sot_offset)
								   * fl_cos(PI / (FL)180.0F * (FL)car_dir) / 3.6F
								   * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa))
								   / VCOF_2F);

		if (tmp_doa > 0) {				/* COND.!g3	 */
			sot_limit_doa_line[i] = tmp_doa;
		} else {
			sot_limit_doa_line[i] = 0;
		}
	}
}


/****************************************************************************/
/* �֐���		: calc_nearfield_doa_2f_I									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-1)2FCW�ᑬ���ʐ��菈��								*/
/*				:	2FCW�M���̒��S���g�����ӂ̔��˔g�̓��������̐�����s���B*/
/*				:	�{�����ł́A�ߋ����Ŕ�r�I�������o�͈͓��ōł����ˋ��x��*/
/*				:	�������W�����o���邱�Ƃ�ړI�Ƃ��Ă��邽�߁A�����̕��W��*/
/*				:	��������K�v���͍����Ȃ��B�����ŁABF(Beam forming�j����	*/
/*				:	�ɂ�����������s���B									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-1)2FCW�ᑬ���ʐ��菈��								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
U1 calc_nearfield_doa_2f_I(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 130-144bin��DOA�s�[�N(�ő�1��/1bin), */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] ��L�ebin��DOA�s�[�N��(�ő�1��) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[WAVE_NUMBER_MAX];
	FL tmp_peak_power[WAVE_NUMBER_MAX];
	U1 u1_t_num_nearfield_doa_2f_i;
	U2 u2_t_lp_martrix_2f;
	U1 u1_t_lp_sot_check;
	FL afl_t_tmp_Ryy[CU2_PCS_FCW_RYY_MATRIX_2F];
	FL fl_t_tmp_theta;
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Vobs;
	U1 u1_t_exist_flag;
	U1 u1_t_lp_wave;
	AUTOAXIS_DATA_FORMAT st_t_auto_axis_data;
	
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	u1_t_num_nearfield_doa_2f_i = (U1)0;
	u1_t_exist_flag = CU1_FALSE;

	st_t_auto_axis_data.s2_freq_bin = (S2)-1;
	for (u1_t_lp_wave = (U1)0; u1_t_lp_wave < WAVE_NUMBER_MAX; u1_t_lp_wave++) {
		st_t_auto_axis_data.s4_doa_bin[u1_t_lp_wave] = (S4)-1;
		st_t_auto_axis_data.fl_doa_pow[u1_t_lp_wave] = (FL)-1.0F;
	}

	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			nearfield_doa[i][j] = -1;
		}
		nearfield_doa_peak_num[i] = 0;
	}

	for (i = start_freq_bin; i < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		nearfield_doa_peak_num[i-start_freq_bin] = 0;
#ifdef _USE_MUSIC_FOR_SLOW_SOT
		s4_calc_spec_music_4ch_all(
			afl_g_cvw_fcw_ryy_matrix[i],			/* [in] */
			spec_doa,								/* [out] */
			2,										/* [in] */
			1										/* [in] */
		);
		nearfield_doa_peak_num[i-start_freq_bin] = s4_peak_search_music_fsk_all_doa(
			spec_doa,
			tmp_doa,
			tmp_peak_power,
			1
		);
#else
		 /* �����������ŊY��bin�����ʓW�J�ς��m�F */
		u1_t_exist_flag = u1_cmn_autoaxis_get_already_2f_dbf_data((U2)i, &st_t_auto_axis_data);
		
		if (u1_t_exist_flag == CU1_FALSE) {
			/* �W�J����Ă��Ȃ���Ε��ʓW�J�����{���� */
			/* DBF DOA */
			fn_calc_spec_bf_4ch_2f(
				(const FL *)(afl_g_cvw_fcw_ryy_matrix[i]),
				spec_doa,
				1,
				i
			);

			/* DOA peaks */
			nearfield_doa_peak_num[i-start_freq_bin] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);
		} else {
			/* �W�J�ς̏ꍇ�͕��ʓW�J���ʂ𗬗p���� */
			tmp_doa[0] = st_t_auto_axis_data.s4_doa_bin[0];
			tmp_peak_power[0] = st_t_auto_axis_data.fl_doa_pow[0];
			nearfield_doa_peak_num[i - start_freq_bin] = WAVE_NUMBER_MAX;
		}
#endif
		for(j=0; j<nearfield_doa_peak_num[i-start_freq_bin]; j++ )
		{
			nearfield_doa[i-start_freq_bin][j] = tmp_doa[j];
		}
	}

	for (i = start_freq_bin; i < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (afl_g_cvw_fcw_ftt_power[i] < (CFL_SLOW_SOT_FFT_POW_TH - (FL)5.0F)) {		/* COND.g1' */
			for (j = 0; j < nearfield_doa_peak_num[i - start_freq_bin]; j++ ) {
				nearfield_doa[i - start_freq_bin][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[i - start_freq_bin] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_i++;
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (afl_g_cvw_fcw_ftt_power[i] < CFL_SLOW_SOT_FFT_POW_TH) {					/* COND.g1 */
			for (j = 0; j < nearfield_doa_peak_num[i - start_freq_bin]; j++ ) {
				nearfield_doa[i - start_freq_bin][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[i - start_freq_bin] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_i++;
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	}
	
	for (i = (S4)0; i < SLOW_SOT_FREQ_BIN_RANGE; i++) {
		if (nearfield_doa[i][0] != (S4)-1) {
			/* �⏕���W�F��������(4)���W���Z�o����(2FCW) 1) ����������ԍ��W�n�ɕϊ�,	*/
			/* 2)�����̎Z�o, 3)���x�̎Z�o�����{���Ă���									*/
			/* ��q�̏������ύX���ꂽ�ꍇ�͂�������ύX���邱��							*/
			for (u2_t_lp_martrix_2f = (U2)0; u2_t_lp_martrix_2f < CU2_PCS_FCW_RYY_MATRIX_2F; u2_t_lp_martrix_2f++) {
				afl_t_tmp_Ryy[u2_t_lp_martrix_2f] = afl_g_cvw_fcw_ryy_matrix_2f[SLOW_SOT_FREQ_BIN_START_I + i][u2_t_lp_martrix_2f];
			}
			
			fl_t_tmp_theta = -(PI / (FL)180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + (FL)nearfield_doa[i][0] + (FL)DOA_BIN_START_ANG));
			fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
			
			/* rx */
			afl_a_sot_check_object_i[i][0] = (fl_t_tmp_Robs * fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
			/* ry */
			afl_a_sot_check_object_i[i][1] = fl_t_tmp_Robs * fl_cos(fl_t_tmp_theta);
			
			fl_t_tmp_Vobs = VCOF_2F * ((FL)(SLOW_SOT_FREQ_BIN_START_I + i) - (FL)NB_FFT_PT_2F / (FL)2.0F);
			
			/* Vx */
			if (fl_sin(fl_t_tmp_theta) != (FL)0.0F) {
				/* �⏕���W�F�������Ə������قȂ�i3.6���|���Ă���j */
				afl_a_sot_check_object_i[i][2] = (fl_t_tmp_Vobs / fl_sin(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_i[i][2] = fl_t_tmp_Vobs;
			}
			
			/* Vy */
			if (fl_cos(fl_t_tmp_theta) != (FL)0.0F) {
				/* �⏕���W�F�������Ə������قȂ�i3.6���|���Ă���j */
				afl_a_sot_check_object_i[i][3] = (fl_t_tmp_Vobs / fl_cos(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_i[i][3] = fl_t_tmp_Vobs;
			}
		} else {
			for (u1_t_lp_sot_check = (U1)0; u1_t_lp_sot_check < (U1)4; u1_t_lp_sot_check++) {
				afl_a_sot_check_object_i[i][u1_t_lp_sot_check] = CFL_UNKNOWN_VALUE;
			}
		}
	}
	
	return u1_t_num_nearfield_doa_2f_i;
}


/****************************************************************************/
/* �֐���		: calc_nearfield_doa_2f_Q									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-1)2FCW�ᑬ���ʐ��菈��								*/
/*				:	2FCW�M���̒��S���g�����ӂ̔��˔g�̓��������̐�����s���B*/
/*				:	�{�����ł́A�ߋ����Ŕ�r�I�������o�͈͓��ōł����ˋ��x��*/
/*				:	�������W�����o���邱�Ƃ�ړI�Ƃ��Ă��邽�߁A�����̕��W��*/
/*				:	��������K�v���͍����Ȃ��B�����ŁABF(Beam forming�j����	*/
/*				:	�ɂ�����������s���B									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-1)2FCW�ᑬ���ʐ��菈��								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
U1 calc_nearfield_doa_2f_Q(
	S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [out] 126-112bin��DOA�s�[�N(�ő�1��/1bin), */
	S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],			/* [out] ��L�ebin��DOA�s�[�N��(�ő�1��) */
	S4 start_freq_bin,											/* [in]	start freq-bin */
	FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[WAVE_NUMBER_MAX];
	FL tmp_peak_power[WAVE_NUMBER_MAX];
	U1 u1_t_num_nearfield_doa_2f_q;
	U2 u2_t_lp_martrix_2f;
	U1 u1_t_lp_sot_check;
	FL afl_t_tmp_Ryy[CU2_PCS_FCW_RYY_MATRIX_2F];
	FL fl_t_tmp_theta;
	FL fl_t_tmp_Robs;
	FL fl_t_tmp_Vobs;
	U1 u1_t_exist_flag;
	U1 u1_t_lp_wave;
	AUTOAXIS_DATA_FORMAT st_t_auto_axis_data;
	
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	u1_t_num_nearfield_doa_2f_q = (U1)0;
	u1_t_exist_flag = CU1_FALSE;

	st_t_auto_axis_data.s2_freq_bin = (S2)-1;
	for (u1_t_lp_wave = (U1)0; u1_t_lp_wave < WAVE_NUMBER_MAX; u1_t_lp_wave++) {
		st_t_auto_axis_data.s4_doa_bin[u1_t_lp_wave] = (S4)-1;
		st_t_auto_axis_data.fl_doa_pow[u1_t_lp_wave] = (FL)-1.0F;
	}

	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			nearfield_doa[i][j] = -1;
		}
		nearfield_doa_peak_num[i] = 0;
	}

	for (i = start_freq_bin; i > (start_freq_bin - SLOW_SOT_FREQ_BIN_RANGE); i--) {
		nearfield_doa_peak_num[start_freq_bin-i] = 0;
#ifdef _USE_MUSIC_FOR_SLOW_SOT
		calc_spec_music_4ch_all(
			afl_g_cvw_fcw_ryy_matrix[i],			/* [in] */
			spec_doa,								/* [out] */
			2,										/* [in]	 */
			1										/* [in] */
		);
		nearfield_doa_peak_num[start_freq_bin-i] = s4_peak_search_music_fsk_all_doa(
			spec_doa,
			tmp_doa,
			tmp_peak_power,
			1
		);
#else
		 /* �����������ŊY��bin�����ʓW�J�ς��m�F */
		u1_t_exist_flag = u1_cmn_autoaxis_get_already_2f_dbf_data((U2)i, &st_t_auto_axis_data);
		
		if (u1_t_exist_flag == CU1_FALSE) {
			/* �W�J����Ă��Ȃ���Ε��ʓW�J�����{���� */
			fn_calc_spec_bf_4ch_2f(
				(const FL *)(afl_g_cvw_fcw_ryy_matrix[i]),
				spec_doa,
				1,
				i
			);

			/* DOA peaks */
			nearfield_doa_peak_num[start_freq_bin-i] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);
		} else {
			/* �W�J�ς̏ꍇ�͕��ʓW�J���ʂ𗬗p���� */
			tmp_doa[0] = st_t_auto_axis_data.s4_doa_bin[0];
			tmp_peak_power[0] = st_t_auto_axis_data.fl_doa_pow[0];
			nearfield_doa_peak_num[start_freq_bin - i] = WAVE_NUMBER_MAX;
		}
#endif
		for(j=0; j<nearfield_doa_peak_num[start_freq_bin-i]; j++ )
		{
			nearfield_doa[start_freq_bin-i][j] = tmp_doa[j];
		}
	}

	for (i = start_freq_bin; i > (start_freq_bin - SLOW_SOT_FREQ_BIN_RANGE); i--) {
		if (afl_g_cvw_fcw_ftt_power[i] < CFL_SLOW_SOT_FFT_POW_TH) {						/* COND.g1 */
			for (j = 0; j < nearfield_doa_peak_num[start_freq_bin - i]; j++) {
				nearfield_doa[start_freq_bin - i][j] = -1;			/* PROC.1 */
			}
			nearfield_doa_peak_num[start_freq_bin - i] = 0;			/* PROC.2 */
		} else {
			u1_t_num_nearfield_doa_2f_q++;
		}
	}

	for (i = (S4)0; i < SLOW_SOT_FREQ_BIN_RANGE; i++) {
		if (nearfield_doa[i][0] != (S4)-1) {
			/* �⏕���W�F��������(4)���W���Z�o����(2FCW) 1) ����������ԍ��W�n�ɕϊ�,	*/
			/* 2)�����̎Z�o, 3)���x�̎Z�o�����{���Ă���									*/
			/* ��q�̏������ύX���ꂽ�ꍇ�͂�������ύX���邱��							*/
			for (u2_t_lp_martrix_2f = (U2)0; u2_t_lp_martrix_2f < CU2_PCS_FCW_RYY_MATRIX_2F; u2_t_lp_martrix_2f++) {
				afl_t_tmp_Ryy[u2_t_lp_martrix_2f] = afl_g_cvw_fcw_ryy_matrix_2f[SLOW_SOT_FREQ_BIN_START_Q - i][u2_t_lp_martrix_2f];
			}
			
			fl_t_tmp_theta = -(PI / (FL)180.0F * (st_g_bsm_loop_data.afl_installed_angle[0] + (FL)nearfield_doa[i][0] + (FL)DOA_BIN_START_ANG));
			fl_t_tmp_Robs = fl_cal_r_fsk((const FL *)afl_t_tmp_Ryy);
			
			/* rx */
			afl_a_sot_check_object_q[i][0] = (fl_t_tmp_Robs * fl_sin(fl_t_tmp_theta)) + st_g_bsm_loop_data.afl_installed_angle[1];
			/* ry */
			afl_a_sot_check_object_q[i][1] = fl_t_tmp_Robs * fl_cos(fl_t_tmp_theta);
			
			fl_t_tmp_Vobs = VCOF_2F * ((FL)(SLOW_SOT_FREQ_BIN_START_Q - i) - (FL)NB_FFT_PT_2F / (FL)2.0F);
			
			/* Vx */
			if (fl_sin(fl_t_tmp_theta) != (FL)0.0F) {
				/* �⏕���W�F�������Ə������قȂ�i3.6���|���Ă���j */
				afl_a_sot_check_object_q[i][2] = (fl_t_tmp_Vobs / fl_sin(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_q[i][2] = fl_t_tmp_Vobs;
			}
			
			/* Vy */
			if (fl_cos(fl_t_tmp_theta) != (FL)0.0F) {
				/* �⏕���W�F�������Ə������قȂ�i3.6���|���Ă���j */
				afl_a_sot_check_object_q[i][3] = (fl_t_tmp_Vobs / fl_cos(fl_t_tmp_theta)) * (FL)3.6F;
			} else {
				afl_a_sot_check_object_q[i][3] = fl_t_tmp_Vobs;
			}
		} else {
			for (u1_t_lp_sot_check = (U1)0; u1_t_lp_sot_check < (U1)4; u1_t_lp_sot_check++) {
				afl_a_sot_check_object_q[i][u1_t_lp_sot_check] = CFL_UNKNOWN_VALUE;
			}
		}
	}

	return u1_t_num_nearfield_doa_2f_q;
}


/****************************************************************************/
/* �֐���		: compare_forward_always_2									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)-(�C)�ᑬ���ʂƒ�~���Ȑ��̌덷�Z�o�i�O���j			*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				: (7)-5)-(�C)�ᑬ���ʂƒ�~���Ȑ��̌덷�Z�o�i�O���j			*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
U1 compare_forward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	const FL afl_a_sot_check_object_i[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, k;
	S4 start_bin;
	S4 end_bin;
	S4 doa_dif_sotlimit_forward = 0;
	FL tmp_vsin;
	FL doa_stationary;
	FL doa_nearfield;
	S4 end_doa;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;

	/* set freq bin range */
	start_bin = SLOW_SOT_FREQ_BIN_START_I;												/* PROC.5 */
	end_bin = stationary_doa_line[N_DOA - 1];											/* PROC.6 */
	if (end_bin > SLOW_SOT_FREQ_BIN_MAX) {												/* COND.g40 */
		end_bin = SLOW_SOT_FREQ_BIN_MAX;												/* PROC.7 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	end_doa = N_DOA;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)40;									/* PROC.17 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	if( fl_g_v_self_bsm_for_base < 20.0F)
	{
		end_doa = N_DOA - AXIS_DEFAULT + 30;
	}
	if( fl_g_v_self_bsm_for_base < 13.0F)
	{
		end_doa = N_DOA - AXIS_DEFAULT + 20;
	}

	/* ���������� (NEW) ���g���͈͂̎Z�o ���������� */
	for (i = SLOW_SOT_FREQ_BIN_START_I; i < (SLOW_SOT_FREQ_BIN_START_I + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		/* ���̊֐���fl_g_v_self_bsm_for_base��0�̂Ƃ��̓R�[������Ȃ��̂�0���͂Ȃ� */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;
		if( tmp_vsin > 1.0F)
		{
			tmp_vsin = 1.0F;
		}
		if( tmp_vsin < -1.0F)
		{
			tmp_vsin = -1.0F;
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;
		if(doa_stationary > N_DOA )
		{
			doa_stationary = N_DOA;
			end_bin = i - 1;
			break;
		}
		if(doa_stationary < 0 )
		{
			doa_stationary = 0;
			start_bin = i + 1;
			break;
		}
	}

	/* check difference from stationary line */
	for(k=0; k<SLOW_SOT_FREQ_BIN_RANGE; k++)
	{
		if (((SLOW_SOT_FREQ_BIN_START_I + k) >= start_bin)																	/* COND.g41 */
		&&  ((SLOW_SOT_FREQ_BIN_START_I + k) < end_bin)																		/* COND.g42 */
		&&  (afl_a_sot_check_object_i[k][0] != CFL_UNKNOWN_VALUE)															/* COND.g27 */
		&&  (afl_a_sot_check_object_i[k][0] > (FL)0.0F)																		/* COND.g28 */
		&&  (afl_a_sot_check_object_i[k][0] < (st_g_bsm_loop_data.afl_wall_width[0] * (FL)1.5F))							/* COND.g29 */
		&&  ((afl_a_sot_check_object_i[k][3] / (FL)3.6F) > (((FL)-1.0F * fl_g_v_self_bsm_for_base / (FL)3.6F) - (FL)10.0F))	/* COND.g30 */
		&&  (afl_a_sot_check_object_i[k][1] > (FL)-20.0F)) {																/* COND.g31 */
			for (i = 0; i < nearfield_doa_peak_num[k]; i++) {	/* i�F�efreq_bin�ɂ�����doa peak��(=1) */
				if (fl_g_v_self_bsm_for_base != 0.0F) {																			/* COND.g56 */
					tmp_vsin = (FL)(SLOW_SOT_FREQ_BIN_START_I + k - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;	/* PROC.20 */
					if (tmp_vsin > 1.0F) {
						tmp_vsin = 1.0F;
					}
					
					if (tmp_vsin < -1.0F) {
						tmp_vsin = -1.0F;
					}
					
					doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.21 */
					doa_nearfield = (FL)nearfield_doa[k][i];													/* PROC.22 */
					if (doa_nearfield < (FL)end_doa) {															/* COND.g57 */
						/* difference between detected points and stationary line */
						doa_dif_sotlimit_forward = (S4)(doa_stationary - doa_nearfield);
						
						if (doa_dif_sotlimit_forward < (S4)0) {									/* COND.k32 */
							u1_t_num_forward++;
							
							if (doa_dif_sotlimit_forward < SoT_DIFF_TH3) {
								st_g_bsm_loop_data.as4_sot_check_sum[0][0][0] += (-doa_dif_sotlimit_forward);
							}
							
							/* number of points under stationary */
							if (doa_dif_sotlimit_forward < SoT_DIFF_TH1) {										/* COND.g43 slow */
								st_g_bsm_loop_data.as4_sot_check_points[0][0][0]++;								/* PROC.10 */
							} else if (doa_dif_sotlimit_forward < SoT_DIFF_TH2) {								/* COND.g44 mid */
								st_g_bsm_loop_data.as4_sot_check_points[0][1][0]++;								/* PROC.12 */
							} else if (doa_dif_sotlimit_forward < SoT_DIFF_TH3) {								/* COND.g45 fast */
								st_g_bsm_loop_data.as4_sot_check_points[0][2][0]++;								/* PROC.14 */
							} else {
								/* �������Ȃ� */
							}
						} else {
							u1_t_num_backward++;
							
							if ((FL)doa_dif_sotlimit_forward > (SLOW_SOT_V0_DOA - (FL)SoT_DIFF_TH3)) {					/* COND.k33 */
								st_g_bsm_loop_data.as4_sot_check_sum[0][1][0] += doa_dif_sotlimit_forward;
							}
						}
					}
				}
			}
		}
	}

	return u1_t_num_forward;
}


/****************************************************************************/
/* �֐���		: compare_backward_always_2									*/
/*--------------------------------------------------------------------------*/
/* �@�\			:  (7)-5)-(�D)�ᑬ���ʂƒ�~���Ȑ��̌덷�Z�o�i����j		*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(�D)�ᑬ���ʂƒ�~���Ȑ��̌덷�Z�o�i����j		*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
U1 compare_backward_always_2(
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] */
	const S4 nearfield_doa_peak_num[SLOW_SOT_FREQ_BIN_RANGE],		/* [in] */
	S4 stationary_doa_line[N_DOA],									/* [in] */
	S4 sot_limit_doa_line_backward[N_DOA],							/* [in] */
	S4 v0_doa,														/* [in] */
	FL v_sot_offset,												/* [in] */
	const FL afl_a_sot_check_object_q[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i, k;
	S4 start_bin;
	S4 end_bin;
	S4 doa_dif_sotlimit_backward = 0;
	S4 s4_t_doa_dif_sotlimit_forward;

	S4 start_doa;
	S4 end_doa;
	S4 diff_th;
	FL tmp_vsin;
	FL fl_t_vsin2;
	FL doa_stationary;
	FL doa_sot_limit;
	FL fl_t_doa_sot_limit2;
	FL doa_nearfield;
	U1 u1_t_num_forward;
	U1 u1_t_num_backward;

	u1_t_num_forward = (U1)0;
	u1_t_num_backward = (U1)0;
	s4_t_doa_dif_sotlimit_forward = (S4)0;

	/* set freq bin range */
	start_bin = SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE+1;					/* PROC.5' */
	end_bin = SLOW_SOT_FREQ_BIN_START_Q;												/* PROC.6' */

	/* ���������� (NEW) ���g���͈͂̎Z�o ���������� */
	for(i = SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE + 1; i<  SLOW_SOT_FREQ_BIN_START_Q; i++) {
		/* ���̊֐���fl_g_v_self_bsm_for_base��0�̂Ƃ��̓R�[������Ȃ��̂�0���͂Ȃ� */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;
		if( tmp_vsin > 1.0F)
		{
			tmp_vsin = 1.0F;
		}
		if( tmp_vsin < -1.0F)
		{
			tmp_vsin = -1.0F;
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;
		if(doa_stationary > N_DOA )
		{
			doa_stationary = N_DOA;
			end_bin = i - 1;
			break;
		}
		if(doa_stationary < 0 )
		{
			doa_stationary = 0;
			start_bin = i + 1;
			break;
		}
	}

	start_doa = N_DOA - AXIS_DEFAULT - 60;												/* PROC.17 */
	if (fl_g_v_self_bsm_for_base > 80.0F) {												/* COND.g58 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 35;											/* PROC.21 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)30;								/* PROC.21 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (fl_g_v_self_bsm_for_base < 20.0F) {												/* COND.g54' */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 50;											/* PROC.22 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)60;								/* PROC.22 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (fl_g_v_self_bsm_for_base < 13.0F) {														/* COND.g55' */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		start_doa = N_DOA - AXIS_DEFAULT - 40;											/* PROC.23 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		start_doa = (S4)N_DOA - (S4)AXIS_DEFAULT - (S4)60;								/* PROC.23 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	end_doa = N_DOA;																	/* PROC.18 */
	
	if (fl_g_v_self_bsm_for_base < (FL)20.0F) {											/* COND.k54' */
		end_doa = N_DOA - AXIS_DEFAULT + (S4)30;
	}
	if (fl_g_v_self_bsm_for_base < (FL)13.0F) {											/* COND.k55' */
		end_doa = N_DOA - AXIS_DEFAULT + (S4)20;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)50;									/* PROC.18 ���ڊp�x20deg�p�̏��� */

	if (fl_g_v_self_bsm_for_base < (FL)30.0F) {											/* COND.k54'' */
		end_doa = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)30;									/* PROC.C */
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	/* check difference from sot-limit line */
	for (k = 0; k < SLOW_SOT_FREQ_BIN_RANGE; k++) {
		if (((SLOW_SOT_FREQ_BIN_START_Q - k) >= start_bin)																		/* COND.g41' */
		&&  ((SLOW_SOT_FREQ_BIN_START_Q - k) <= end_bin)																		/* COND.g42' */
		&&  (afl_a_sot_check_object_q[k][0] != CFL_UNKNOWN_VALUE)																/* COND.g27' */
		&&  (afl_a_sot_check_object_q[k][0] > (FL)0.0F)																			/* COND.g28' */
		&&  (afl_a_sot_check_object_q[k][0] < (st_g_bsm_loop_data.afl_wall_width[0] * (FL)1.5F))								/* COND.g29' */
		&&  ((afl_a_sot_check_object_q[k][3] / (FL)3.6F) > (((FL)-1.0F * fl_g_v_self_bsm_for_base / (FL)3.6F) - (FL)10.0F))		/* COND.g30' */
		&&  (afl_a_sot_check_object_q[k][1] > (FL)-20.0F)) {																	/* COND.g31' */
			for( i = 0; i < nearfield_doa_peak_num[k]; i++ )
			{
				diff_th = (S4)999;
				if ((nearfield_doa[k][i] > start_doa)										/* COND.g50 */
				&&  (nearfield_doa[k][i] < end_doa)) {										/* COND.g51 */
					doa_nearfield = (FL)nearfield_doa[k][i];							/* PROC.12 */
					
					/* difference between detected points and sot limit line */
					if (fl_g_v_self_bsm_for_base > CFL_SoT_V_TH_FWD) {									/* COND.g52 */
						if (afl_a_sot_check_object_q[k][1] < (FL)0.0F) {								/* COND.k35 */
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / v_sot_offset;				/* PROC.g */
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							doa_sot_limit = (FL)v0_doa - (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;		/* PROC.h */
							u1_t_num_backward++;															/* PROC.j */
							doa_dif_sotlimit_backward = (S4)(doa_sot_limit - doa_nearfield);				/* PROC.13 */
						} else {
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;			/* PROC.g' */
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							doa_sot_limit = (FL)v0_doa - (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;		/* PROC.h */
							u1_t_num_forward++;																/* PROC.i */
							s4_t_doa_dif_sotlimit_forward = (S4)(doa_sot_limit - doa_nearfield);			/* PROC.13' */
						}
						diff_th = CS4_SoT_DIFF_TH;															/* PROC.19 */
					}
					/* difference between detected points and stationary line (when subject is slow) */
					else if (fl_g_v_self_bsm_for_base > (FL)5.0F) {										/* COND.k26 */
						if (afl_a_sot_check_object_q[k][1] < (FL)0.0F) {								/* COND.k35 */
							fl_t_doa_sot_limit2 = (FL)0.0F;												/* PROC.l */
							tmp_vsin = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
							if (tmp_vsin > 1.0F) {
								tmp_vsin = 1.0F;
							}
							
							if (tmp_vsin < -1.0F) {
								tmp_vsin = -1.0F;
							}
							
							fl_t_vsin2 = (FL)(-(SLOW_SOT_FREQ_BIN_START_Q - k - (S4)1 - (NB_FFT_PT_2F / (S4)2))) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
							if (fl_t_vsin2 > 1.0F) {
								fl_t_vsin2 = 1.0F;
							}
							
							if (fl_t_vsin2 < -1.0F) {
								fl_t_vsin2 = -1.0F;
							}
							
							doa_sot_limit =  (FL)v0_doa - fl_cal_asin(tmp_vsin) * (FL)180.0F / PI;				/* PROC.h */
							fl_t_doa_sot_limit2 = (FL)v0_doa - fl_cal_asin(fl_t_vsin2) * (FL)180.0F / PI;		/* PROC.h' */
							doa_dif_sotlimit_backward = (S4)(doa_sot_limit - doa_nearfield);					/* PROC.13 */
							
							if ((FL)doa_dif_sotlimit_backward < (doa_sot_limit - fl_t_doa_sot_limit2)) {		/* COND.k36 */
								doa_dif_sotlimit_backward = (S4)0;
							} else {
								diff_th = -CS4_SoT_DIFF_TH_SLOW;												/* PROC.20 */
								u1_t_num_backward++;															/* PROC.j */
							}
						}
					} else {
						/* �������Ȃ� */
					}
					
					if ((doa_dif_sotlimit_backward > diff_th)													/* COND.k37 */
					&&  (diff_th != (S4)999)) {																	/* COND.k38 */
						st_g_bsm_loop_data.as4_sot_check_sum[1][0][0] += doa_dif_sotlimit_backward;				/* PROC.9' */
						st_g_bsm_loop_data.as4_sot_check_points[1][0][0]++;										/* PROC.10' */
					}
					
					if ((diff_th != (S4)999)																		/* COND.k38 */
					&&  (s4_t_doa_dif_sotlimit_forward < -diff_th)													/* COND.k39 */
					&&  (afl_a_sot_check_object_q[k][1] > (FL)0.0F)) {												/* COND.k40 */
						st_g_bsm_loop_data.as4_sot_check_sum[1][1][0] += s4_abs(s4_t_doa_dif_sotlimit_forward);		/* PROC.9'' */
						st_g_bsm_loop_data.as4_sot_check_points[1][1][0]++;											/* PROC.10'' */
					}
				}
			}
		}
	}

	return u1_t_num_backward;
}


/****************************************************************************/
/* �֐���		: check_sot_start											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)-(�E)SoT����J�n����								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(�E)SoT����J�n����								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_sot_start(											/* [return] */
	FL dev[2],												/* [in] */
	U1 u1_a_alarming_flag
)
{
	S4 iRes = 0;
	S4 i;
	S4 count_backward = 0;
	S4 count_backward_sum = 0;
	S4 count_forward_fast = 0;
	S4 count_forward_mid = 0;
	S4 count_forward_slow = 0;
	S4 fwd_fast_th = 0;
	S4 fwd_mid_th = 0;
	S4 fwd_slow_th = 1;
	S4 fwd_fast_diff_th = 2;
	
	S4 s4_t_fwd_peak_pos;
	S4 s4_t_bwd_peak_pos;
	S4 s4_t_fwd_peak_val;
	S4 s4_t_bwd_peak_val;
	
	U1 u1_t_jdg_h84_flg;
	
	s4_t_fwd_peak_pos = (S4)-1;
	s4_t_bwd_peak_pos = (S4)-1;
	s4_t_fwd_peak_val = (S4)0;
	s4_t_bwd_peak_val = (S4)0;
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if (fl_g_v_self_bsm_for_base > (FL)30.0F) {
		fwd_fast_diff_th = (S4)50;
	}
#else
    �}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	for (i = 0; i <= (CS4_SOT_CHECK_CYCLE_FWD + CS4_SOT_CHECK_CYCLE_BWD); i++)
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	for(i = (S4)0; i < CS4_SOT_CHECK_CYCLE_FWD; i++)
#else
    �}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	{
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > s4_t_fwd_peak_val) {
			s4_t_fwd_peak_pos = i;
			s4_t_fwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[0][0][i];
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > s4_t_bwd_peak_val) {
			s4_t_bwd_peak_pos = i;
			s4_t_bwd_peak_val = st_g_bsm_loop_data.as4_sot_check_sum[1][0][i];
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > fwd_fast_diff_th) {				/* COND.h4 */
			/* check fast point(Green) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][2][i] > fwd_fast_th) {			/* COND.h3 */
				count_forward_fast++;														/* PROC.3 */
			}
			/* check mid point (Yellow) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][1][i] > fwd_mid_th) {			/* COND.h5 */
				count_forward_mid++;														/* PROC.4 */
			}
			/* check slow point (Red) */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][0][i] > fwd_slow_th) {			/* COND.h7 */
				count_forward_slow++;														/* PROC.5 */
			}
		}
		
		/* check backward point */
		if (st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > 2) {							/* COND.h9 */
			if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > (S4)0) {
				count_backward++;															/* PROC.6 */
			}
		}
		if (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD) {	/* COND.h10 */
			count_backward_sum++;															/* PROC.7 */
		}
	}
	
	/* ����h84�̔���֐��R�[�� �d�l���̋L�q������h84�̒�`�����ɃR���p�C���X�C�b�`�����邽�߁A	*/
	/* ����h84�̔���p�֐������A���茋�ʂ������m�F�ӏ��Ŏg�p����									*/
	/* �֐����ł̓O���[�o���ϐ��͐G��Ȃ��̂ŁA���̃^�C�~���O�Ŋ֐��R�[�����Ă����Ȃ�				*/
	u1_t_jdg_h84_flg = u1_check_sot_start_h84(s4_t_fwd_peak_val, s4_t_bwd_peak_val);
	
	if ((((s4_t_fwd_peak_pos != (S4)-1)										/* COND.h82 */
	&&    (s4_t_fwd_peak_pos > s4_t_bwd_peak_pos))							/* COND.h83 */
	||   (u1_t_jdg_h84_flg == CU1_TRUE))									/* COND.h84 */
	&&  ((st_g_bsm_loop_data.as4_sot_check_sum[0][1][0] < (S4)400)			/* COND.h85 */
	||   (u1_a_alarming_flag != (U1)0))) {									/* COND.h86 */
		if ((count_forward_mid == (S4)0)						/* COND.h15 */
		&&  (count_forward_slow == (S4)0)) {					/* COND.h17 */
			if (count_forward_fast > 2) {						/* COND.g65 */
				iRes = 1;										/* PROC.8 */
			} else if (count_backward > 4) {					/* COND.g67 */
				iRes = 1;										/* PROC.8 */
			} else if ((fl_g_v_self_bsm_for_base < (FL)20.0F)	/* COND.h1 */
				   &&  (count_forward_fast != (S4)0)			/* COND.h11 */
				   &&  (count_backward_sum > (S4)2)) {			/* COND.h22 */
				iRes = 1;										/* PROC.8 */
			} else {
				/* �������Ȃ� */
			}
		} else if ((count_forward_fast > 0)							/* COND.g71 */
			   ||  (count_forward_mid > 1)							/* COND.g72 */
			   ||  (count_forward_slow > 2)) {							/* COND.g73 */
			iRes = 1;											/* PROC.8 */
		} else {
			/* �������Ȃ� */
		}
		
		if (fl_g_v_self_bsm_for_base < 20.0F) {					/* COND.g53 */
			if (count_backward > 6) {							/* COND.g75 */
				iRes = 1;										/* PROC.8 */
			}
		}
	}

	return iRes;
}

/****************************************************************************/
/* �֐���		: u1_check_sot_start_h84									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: SoT����J�n����̏���h84����֐�							*/
/*--------------------------------------------------------------------------*/
/* ����			: s4_a_fwd_peak_val		: �i�O���jSoT-��~���̍��� [in]		*/
/*				: s4_a_bwd_peak_val		: �i����jSoT-��~���̍��� [in]		*/
/* �߂�l		: u1_t_jdg_h84_flag		: ����h84�̔��茋�ʊi�[�ϐ�			*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		: �Ȃ�														*/
/* <output>		: �Ȃ�														*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-015(291BCV)						*/
/*				: (7)�ᑬSoT���菈�� 5)�ᑬ�r���s���菈��					*/
/*				: (vi)SoT����J�n����̏���h84								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		:															*/
/****************************************************************************/
static U1 u1_check_sot_start_h84(S4 s4_a_fwd_peak_val, S4 s4_a_bwd_peak_val)
{
	/* ����h84���d�l��œ��ڊp�x�ɂ�蕪������Ă��邱�ƁA							*/
	/* ���蕶�ɒ��ڃR���p�C���I�v�V�������L�q�����&&��||�̑Ή���������ɂ����Ȃ�	*/
	/* �ǐ����ቺ���邽�߁A��������p�֐����쐬�����̌��ʂ��������Ɏg�p����		*/

	U1 u1_t_jdg_h84_flag;				/* ����h84���茋�ʊi�[�ϐ� */

	/* FALSE�ŏ����� */
	u1_t_jdg_h84_flag = CU1_FALSE;

	/* ����h84�̔��� */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�̂Ƃ� */
	if (s4_a_fwd_peak_val > s4_a_bwd_peak_val) {
		u1_t_jdg_h84_flag = CU1_TRUE;
	} else {
		u1_t_jdg_h84_flag = CU1_FALSE;
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���ڊp�x20deg�̂Ƃ� */
	if (s4_a_fwd_peak_val > (s4_a_bwd_peak_val + (S4)30)) {
		u1_t_jdg_h84_flag = CU1_TRUE;
	} else {
		u1_t_jdg_h84_flag = CU1_FALSE;
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	return u1_t_jdg_h84_flag;
}

/****************************************************************************/
/* �֐���		: check_sot_stop											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)-(�G)SoT����I������								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(�G)SoT����I������								*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_sot_stop(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
	S4 iRes = 0;
	S4 i,j;
	S4 count_backward = 0;
	S4 count_forward = 0;

	/* check forward point */
	for(i=0; i<6; i++)	
	{
		for(j=0; j<3; j++)
		{
			if (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] != 0) {		/* COND.h23' */
				count_forward++;												/* PROC.1 */
			}
		}
	}
	/* check backward point */
	for(i=0; i<6; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != 0)				/* COND.h26' */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > (S4)0)) {			/* COND.h81 */
			count_backward++;								/* PROC.2 */
		}
	}
	
	if ((count_forward < 1)									/* COND.h36 */
	&&  (count_backward < 1)) {								/* COND.h37 */
		iRes = 1;											/* PROC.3 */
	} else if (((dev[0] < CFL_SOT_DEV_TH)					/* COND.h38 */
		   ||   (count_forward < 1))						/* COND.h36 */
		   &&  (dev[1] < CFL_SOT_DEV_TH)) {					/* COND.h33' */
		iRes = 1;											/* PROC.3 */
	} else {
		/* �������Ȃ� */
	}
		
	return iRes;
}


/****************************************************************************/
/* �֐���		: check_sot_on												*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)-(�H)SoT ON ����									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-5)-(�H)SoT ON ����									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_sot_on(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
/* sot_check_sum[0][0][*]	slow [red] */
/* sot_check_sum[0][1][*]	mid  [yellow]] */
/* sot_check_sum[0][2][*]	fast [green] */
/* sot_check_sum[1][0][*]	backward */

	S4 iRes = 0;
	S4 i;
	S4 count_backward = 0;
	S4 count_fast_sot4 = 0;
	S4 count_fast_sot5 = 0;
	S4 count_forward_fast = 0;
	S4 count_forward_mid = 0;
	S4 count_forward_slow = 0;
	S4 count_forward = 0;
	S4 wall = 0;
	
	S4 s4_t_count_fast_sot;
	S4 s4_t_count_fast_sot_bwd;
	
	S4 s4_t_th_point_sum;
	S4 s4_t_fwd_point_sum;
	U1 u1_t_lp_data;
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	S4 s4_t_fwd_check_sum_ave;
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���ڊp�x20deg�ł͒�`�Ȃ� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	
	s4_t_count_fast_sot = (S4)0;
	s4_t_count_fast_sot_bwd = (S4)0;
	
	/* Check forward sot-stationary point */
	for(i=0; i<12; i++) 
	{
		if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > -SoT_DIFF_TH3) {		/* COND.h40 */
			/* low relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][0][i] != (S4)0) {		/* COND.h39 */
				count_forward_slow++;												/* PROC.1 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][0][i] > (S4)1)		/* COND.h41 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* mid. relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][1][i] != (S4)0) {		/* COND.h45 */
				count_forward_mid++;												/* PROC.6 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][1][i] > (S4)1)		/* COND.h47 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* fast relative speed */
			if (st_g_bsm_loop_data.as4_sot_check_points[0][2][i] != (S4)0) {		/* COND.h50 */
				count_forward_fast++;												/* PROC.10 */
				
				if ((st_g_bsm_loop_data.as4_sot_check_points[0][2][i] > (S4)1)		/* COND.h52 */
				&&  (i < CS4_SOT_CHECK_CYCLE_FWD)) {								/* COND.h24' */
					count_forward++;												/* PROC.2 */
				}
			}
			
			/* Fast-SoT checking */
			if (st_g_bsm_loop_data.as4_sot_check_sum[0][0][i] > (S4)115) {			/* COND.h42 */
				s4_t_count_fast_sot++;
			}
		}
	}
	
	/* Check backward sot-stationary point */
	for (i = (S4)0; i < (S4)CU1_SOT_CHECK_CYCLE; i++) {
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != (S4)0)											/* COND.h26'' */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD)) {					/* COND.h10 */
			count_fast_sot4++;
			
			if (i < CS4_SOT_CHECK_CYCLE_BWD) {																	/* COND.h53 */
				count_fast_sot5++;
			}
		}
		
		if (st_g_bsm_loop_data.as4_sot_check_points[1][1][i] > (S4)1) {												/* COND.h43 */
			s4_t_count_fast_sot_bwd++;
		}
	}

	/* Set the wall flag on if the detection meets the following conditions */
	if ((count_forward_fast + count_forward_mid + count_forward_slow) < ((S4)CU1_SOT_CHECK_CYCLE * (S4)2)) {				/* COND.h70 (h70-1 + h70-2 +h70-3) */
		if (((count_forward_fast + count_forward_mid + count_forward_slow) <= (S4)((FL)CU1_SOT_CHECK_CYCLE * (FL)1.5F))			/* COND.h71 */
		&&  (count_fast_sot4 < (S4)3)																							/* COND.h72 */
		&&  (s4_t_count_fast_sot_bwd < (S4)3)) {																				/* COND.h56 */
			wall = (S4)1;																											/* PROC.13 */
		}
		
		if ((count_fast_sot4 < (S4)3)																		/* COND.h72 */
		&&  (count_forward < (S4)1)) {																		/* COND.h73 */
			wall = (S4)1;																					/* PROC.13 */
		}
		
		if ((dev[1] < WALL_DEV_TH4)																		/* COND.h75 */
		&&  (count_fast_sot4 < (S4)5)) {																/* COND.h76 */
			wall = (S4)1;																					/* PROC.13 */
		}
	} else {
		if ((dev[1] < WALL_DEV_TH4)																		/* COND.h75 */
		&&  (count_forward < (S4)4)																		/* COND.h57 */
		&&  (count_fast_sot4 < (S4)4)) {																/* COND.h58 */
			wall = (S4)1;																					/* PROC.13 */
		}
		
		if ((s4_t_count_fast_sot_bwd < (S4)3)															/* COND.h56 */
		&&  (count_forward < (S4)2)																		/* COND.h77 */
		&&  (count_fast_sot4 < (S4)1)) {																/* COND.h66 */
			wall = (S4)1;																					/* PROC.13 */
		}
	}
	
	if (wall == (S4)0) {																				/* COND.h78 */
		iRes = (S4)1;																						/* PROC.14 */
	}
	
	/**** �O���_�����m�F ***/
	/* �׎Ԑ��̗L���ɉ����Ĕ���臒l��ݒ肷�� */
	if (st_g_bsm_loop_data.u1_count_adjacent_lane_exist > (U1)10) {										/* COND.h87 */
		s4_t_th_point_sum = (S4)3;
	} else {
		s4_t_th_point_sum = (S4)10;
	}


	/* 1s�Ԃ̑O���_�����a(�ᑊ�Α��A�����Α��̑O���_��)���Z�o�B���a�����Ȃ�����ꍇ�́ASoT ON ����=OFF�Ƃ���*/
	s4_t_fwd_point_sum = (S4)0;
	for (u1_t_lp_data = (U1)0; u1_t_lp_data < (U1)12; u1_t_lp_data++) {
		s4_t_fwd_point_sum += (st_g_bsm_loop_data.as4_sot_check_points[0][0][u1_t_lp_data] + st_g_bsm_loop_data.as4_sot_check_points[0][1][u1_t_lp_data]);
	}

	/* SoT ON ���� */
	if (s4_t_fwd_point_sum < s4_t_th_point_sum) {
		iRes = (S4)0;				/* PROC.15 */
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	if ((st_g_bsm_loop_data.as4_sot_check_sum[0][0][11] - st_g_bsm_loop_data.as4_sot_check_sum[0][0][0] > (S4)100)	/* COND.h88 */
	&&  (st_g_bsm_loop_data.as4_sot_check_points[0][0][0] < (S4)3)													/* COND.h89 */
	&&  (count_fast_sot5 < (S4)3)) {																				/* COND.h90 */
		iRes = (S4)0;														/* PROC.15 */
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */


#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/*** �O���_�̂΂���m�F ***/
	/* 1s�ԂɊϑ������SoT-��~���̍������ϒl������������ꍇ�́A									*/
	/* SoT�ԗ��łȂ��\�����������߁ASoT ON������L�����Z������B�{����͎��ԍ������̂ݎ��{����	*/
	/* �i�O���jSoT-��~���̍���1s���ώZ�o */
	s4_t_fwd_check_sum_ave = (S4)0;
	for (u1_t_lp_data = (U1)0; u1_t_lp_data < (U1)12; u1_t_lp_data++) {
		s4_t_fwd_check_sum_ave += st_g_bsm_loop_data.as4_sot_check_sum[0][0][u1_t_lp_data];
	}
	s4_t_fwd_check_sum_ave /= (S4)12;

	/* SoT ON�L�����Z������ */
	if ((s4_t_fwd_check_sum_ave < CS4_SOT_ON_CANCEL_CHECK_SUM_TH)		/* COND.h91 */
	&&  (fl_g_v_self_bsm_for_base >= (FL)CS4_SOT_ON_CANCEL_VN_TH)) {	/* COND.h92 */
		iRes = (S4)0;														/* PROC.15 */
	}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���ڊp�x20deg�ł͏����Ȃ� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */


	return iRes;
}


/****************************************************************************/
/* �֐���		: check_sot_off												*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-5)-(�F)SoT Off����									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	 (7)-5)-(�F)SoT Off����									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 check_sot_off(											/* [return] */
	const FL dev[2]											/* [in] */
)
{
	S4 iRes = 0;
	S4 i,j;

	S4 count_backward1 = 0;
	S4 count_backward2 = 0;
	S4 count_forward1 = 0;
	S4 count_forward2 = 0;

	/* forward points */
	for(i=0; i<12; i++)
	{
		for(j=0; j<3; j++)
		{
			if (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] != 0) {			/* COND.h23 */
				count_forward1++;													/* PROC.1 */
				if ((i < CS4_SOT_CHECK_CYCLE_FWD)									/* COND.h24 */
				&&  (st_g_bsm_loop_data.as4_sot_check_points[0][j][i] > 1)) {		/* COND.h25 */
					count_forward2++;												/* PROC.2 */
				}
			}
		}
	}

	/* backward points */
	for(i=0; i<12; i++)
	{
		if ((st_g_bsm_loop_data.as4_sot_check_points[1][0][i] != 0)								/* COND.h26 */
		&&  (st_g_bsm_loop_data.as4_sot_check_sum[1][0][i] > CS4_SOT_WALL_DIFFSUM_TH_BWD)) {	/* COND.h10 */
			count_backward1++;																	/* PROC.3 */
			if ((i < CS4_SOT_CHECK_CYCLE_FWD)													/* COND.h24  */
			&&  (st_g_bsm_loop_data.as4_sot_check_points[1][0][i] > 1)) {						/* COND.h27 */
				count_backward2++;																/* PROC.4 */
			}
		}
	}

	if ((count_backward1 < 2)														/* COND.h28 */
	&&  (count_forward1 < 2)) {														/* COND.h29 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward1 < 2)													/* COND.h29 */
		   &&  (count_forward2 < 1)													/* COND.h30 */
		   &&  (count_backward1 < 6)) {												/* COND.h31 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward2 < 2)													/* COND.h32 */
		   &&  ((dev[1] < CFL_SOT_DEV_TH)											/* COND.h33 */
		   ||   (count_backward1 < 2))) {											/* COND.h28 */
		iRes = 1;																	/* PROC.5 */
	} else if (count_forward1 < 2) {												/* COND.h29 */
		iRes = 1;																	/* PROC.5 */
	} else if ((count_forward2 < 1)													/* COND.h30 */
		   &&  ((count_backward2 < 1)												/* COND.h34 */
		   ||   (st_g_bsm_loop_data.as4_slow_sot_find[1] >= WALL_REJECT_TH3))) {	/* COND.h35 */
		iRes = 1;																	/* PROC.5 */
	} else {
		/* �������Ȃ� */
	}

	return iRes;
}

/********************************************************************************************/
/* �֐���		: fn_bsm_low_judge_check_sot_doa											*/
/*------------------------------------------------------------------------------------------*/
/* �@�\			: Check SoT DOA	 															*/
/*------------------------------------------------------------------------------------------*/
/* ����			: pfl_a_fast_sot_pow					: Fast-SoT power [in]				*/
/* �߂�l		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X																	*/
/* <input>  	: afl_g_cvw_lfm_ftt_power : FMCW FFT���ϓd��								*/
/*				: afl_g_cvw_lfm_ryy_matrix: FMCW ���ȑ��֍s��								*/
/* <output>		: �Ȃ�																		*/
/*------------------------------------------------------------------------------------------*/
/* �Q�Ɗ֐�		: fn_calc_spec_bf_4ch_fm(), s4_search_peak_bf()								*/
/*------------------------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-007												*/
/*				  (7)�ᑬ SoT ���菈�� 5)�ᑬ�r���s���菈�� (x)Check SoT DOA    			*/
/********************************************************************************************/
VD fn_bsm_low_judge_check_sot_doa(FL* pfl_a_fast_sot_pow)
{
	U2 u2_t_lp_fft_data;
	FL fl_t_max_peak_pow;
	S2 s2_t_fast_sot_check_bin;
	FL fl_t_fast_sot_check_doa_spec[N_DOA];
	S4 s4_t_fast_sot_check_doa[1];
	FL fl_t_fast_sot_check_doapow[1];
	FL fl_t_sot_direction;
	
	/* �ϐ������� */
	fl_t_max_peak_pow = (FL)0.0F;
	s2_t_fast_sot_check_bin = (S2)-1;
	
	for (u2_t_lp_fft_data = (U2)0; u2_t_lp_fft_data < N_DOA; u2_t_lp_fft_data++) {
		fl_t_fast_sot_check_doa_spec[u2_t_lp_fft_data] = (FL)0.0F;
	}
	
	s4_t_fast_sot_check_doa[0] = (S4)-1;
	fl_t_fast_sot_check_doapow[0] = (FL)0.0F;
	fl_t_sot_direction = (FL)180.0F - st_g_bsm_loop_data.afl_installed_angle[0];
	
	/* �ő�d�͂̃s�[�Nbin�𒊏o���� */
	for (u2_t_lp_fft_data = (U2)257; u2_t_lp_fft_data < (U2)265; u2_t_lp_fft_data++) {
		if (afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data] > fl_t_max_peak_pow) {
			fl_t_max_peak_pow = afl_g_cvw_lfm_ftt_power[0][u2_t_lp_fft_data];
			s2_t_fast_sot_check_bin = (S2)u2_t_lp_fft_data;
		}
	}
	
	if ((s2_t_fast_sot_check_bin != (S2)-1)
	&&  (fl_t_max_peak_pow > (FL)53.0F)) {
		fn_calc_spec_bf_4ch_fm((const FL *)(&afl_g_cvw_lfm_ryy_matrix[0][s2_t_fast_sot_check_bin][0]), fl_t_fast_sot_check_doa_spec, (S4)0, (S4)s2_t_fast_sot_check_bin);
		
		s4_search_peak_bf((const FL *)fl_t_fast_sot_check_doa_spec, s4_t_fast_sot_check_doa, fl_t_fast_sot_check_doapow, (S4)1);
	}
	
	if ((FL)s4_t_fast_sot_check_doa[0] > fl_t_sot_direction) {
		*pfl_a_fast_sot_pow = fl_t_fast_sot_check_doapow[0];
		st_g_bsm_loop_data.as4_slow_sot_doa_diff_sum[3] = CU1_SOT_CHECK_CYCLE + (S4)1;
	}
	
	return;
}


/****************************************************************************/
/* �֐���		: calc_deviation_of_doa_freq_line_stationary_2				*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (7)-4)�ᑬ���ʂƒ�~�����ʋȐ��̕��U�Z�o����				*/
/*				:	(7)-4)-(�@)���ʔ͈͂̎Z�o								*/
/*				:	(7)-4)-(�A)���g���͈͂̎Z�o								*/
/*				:	(7)-4)-(�B)fast-SoT�̔���								*/
/*				:	(7)-4)-(iV)���U�̎Z�o									*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(7)-4)-(�@)���ʔ͈͂̎Z�o								*/
/*				:	(7)-4)-(�A)���g���͈͂̎Z�o								*/
/*				:	(7)-4)-(�B)fast-SoT�̔���								*/
/*				:	(7)-4)-(iV)���U�̎Z�o									*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
FL calc_deviation_of_doa_freq_line_stationary_2(					/* [return] deviation of ovserved doa-freq points */
	const S4 nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE][1],				/* [in] 130-145bin��DOA�s�[�N */
	S4 start_freq_bin,												/* [in]	start freq-bin */
	const S4 stationary_doa_line[N_DOA],							/* [in] */
	S4 mode															/* [in] 0:I, 1:Q */
	,S4 *backward_priod												/* [out] use backward dev */
	,S4 v0_doa														/* [in] */
	,S4 *fast_sot_num												/* [out] */
	,S4 *not_fast_sot_num											/* [out] */
	,S4 fast_sot_limit_line[N_DOA]									/* [out] */
	,const FL afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE][4]
)
{
	S4 i;
	FL dev = 0.0F;
	S4 index = 0;
	S4 num = 0;
	S4 doa_min = 0;
	S4 doa_max = N_DOA;
	FL tmp_min = (FL)N_DOA;													/* PROC.3 */
	FL tmp_vsin;
	FL doa_stationary;
	S4 bin_min = 0;
	S4 bin_max = NB_FFT_PT_2F;
	S4 tmptmp_max;
	S4 tmptmp_min;

	S4 freq;
	FL v_limit;
	FL tmp = (FL)(NB_FFT_PT_2F / 2 - (S4)(CFL_SoT_V_TH_BWD / 3.6F / VCOF_2F));		/* PROC.1 */
	FL doa_limit; 
	FL diff1, diff2;

	S4 num_th = (S4)(SLOW_SOT_FREQ_BIN_RANGE*0.6F);							/* 60%�ŏ����� */
	*backward_priod = 0;

	if (fl_g_v_self_bsm_for_base == 0.0F) {																/* COND.j16 */
		dev = 999.9F;																					/* PROC.1 */
		return dev;
	}

	/* ���������� (�@)���ʔ͈͂̎Z�o ���������� */
	tmp_min = (FL)N_DOA;																				/* PROC.3 */
	for (i = (S4)(((FL)N_DOA * 0.5F) - (FL)AXIS_DEFAULT); i < N_DOA; i++) {
		if (fl_abs((FL)(stationary_doa_line[i] - start_freq_bin)) < tmp_min) {							/* COND.g4 */
			tmp_min = fl_abs((FL)(stationary_doa_line[i]-start_freq_bin));								/* PROC.4 */
			doa_min = i;																				/* PROC.5 */
		}
	}
	tmp_min = (FL)N_DOA;																					/* PROC.3 */
	for (i = (S4)(((FL)N_DOA * 0.5F) - (FL)AXIS_DEFAULT); i < N_DOA; i++) {
		if (fl_abs((FL)(stationary_doa_line[i] - (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE))) < tmp_min) {	/* COND.g5 */
			tmp_min = fl_abs((FL)(stationary_doa_line[i]-(start_freq_bin+SLOW_SOT_FREQ_BIN_RANGE)));		/* PROC.6 */
			doa_max = i;																					/* PROC.7 */
		}
	}
	if (mode == 0) {
		doa_min -= 5;																					/* PROC.8' */
	} else {
		doa_min -= 10;																					/* PROC.8 */
	}

	if ((fl_g_v_self_bsm_for_base < 20.0F)																/* COND.g7 */
	&&  (mode == 1)) {
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		doa_min = 65;																					/* PROC.10 */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		doa_min = (S4)55;																				/* PROC.10 ���ڊp�x20deg�p�̏��� */
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	if (doa_min < 0) {																					/* COND.g6 */
		doa_min = 0;																					/* PROC.9 */
	}

	doa_max += 10;																						/* PROC.11 */
	if (doa_max > N_DOA) {																				/* COND.g8 */
		doa_max = N_DOA;																				/* PROC.12 */
	}
	if (fl_g_v_self_bsm_for_base < 20.0F) {																/* COND.g7 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (doa_max > (N_DOA - AXIS_DEFAULT + 35)) {													/* COND.j2 */
			doa_max = N_DOA - AXIS_DEFAULT + 35;														/* PROC.13 */
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (doa_max > (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)65) {											/* COND.j2 ���ڊp�x20deg�p�̏��� */
			doa_max = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)65;											/* PROC.13 ���ڊp�x20deg�p�̏��� */
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}
	if (fl_g_v_self_bsm_for_base < 13.0F) {																/* COND.j1 */
#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
		if (doa_max > (N_DOA - AXIS_DEFAULT + 30)) {													/* COND.j3 */
			doa_max = N_DOA - AXIS_DEFAULT + 30;														/* PROC.14 */
		}
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
		if (doa_max > (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)60) {											/* COND.j3 ���ڊp�x20deg�p�̏��� */
			doa_max = (S4)N_DOA - (S4)AXIS_DEFAULT + (S4)60;											/* PROC.14 ���ڊp�x20deg�p�̏��� */
		}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */
	}

	/* ���������� (�A) ���g���͈͂̎Z�o ���������� */
	for (i = (SLOW_SOT_FREQ_BIN_START_Q - SLOW_SOT_FREQ_BIN_RANGE + 1); i < (SLOW_SOT_FREQ_BIN_START_I + SLOW_SOT_FREQ_BIN_RANGE); i++) {
		/* ���̊֐���fl_g_v_self_bsm_for_base��0�̂Ƃ��̓R�[������Ȃ��̂�0���͂Ȃ� */
		tmp_vsin = (FL)(i - (NB_FFT_PT_2F/2))*3.6F*VCOF_2F/fl_g_v_self_bsm_for_base;		/* PROC.1 */
		if( tmp_vsin > 1.0F)												/* COND.j4 */
		{
			tmp_vsin = 1.0F;												/* PROC.2 */
		}
		if( tmp_vsin < -1.0F)												/* COND.j5 */
		{
			tmp_vsin = -1.0F;												/* PROC.3 */
		}
		doa_stationary = (FL)fl_cal_asin(tmp_vsin) * (FL)180.0F / PI + (FL)v0_doa;		/* PROC.5 */
		if(doa_stationary > N_DOA )											/* COND.j6 */
		{
			doa_stationary = N_DOA;											/* PROC.6 */
			bin_max = i - 1;												/* PROC.7 */
			break;
		}
		if(doa_stationary < 0 )												/* COND.j7 */
		{
			doa_stationary = 0;												/* PROC.8 */
			bin_min = i + 1;												/* PROC.4 */
			break;
		}
	}
	if( bin_max < (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE))				/* COND.j8 */
	{
		tmptmp_max = bin_max;												/* PROC.9 */
	}
	else
	{
		tmptmp_max = start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE - 1;			/* PROC.10 */
	}
	if( bin_min > start_freq_bin)											/* COND.j9 */
	{
		tmptmp_min = bin_min;												/* PROC.11 */
	}
	else
	{
		tmptmp_min = start_freq_bin;										/* PROC.12 */

	}
	num_th = (S4)( (FL)(tmptmp_max - tmptmp_min + 1)*0.6F );				/* PROC.13 60% of range */

	/* ���������� (�B)fast-SoT�̔��� ���������� */
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
	memset(as4_g_fast_sot_limit_line_diam, 0, sizeof(as4_g_fast_sot_limit_line_diam));
#endif /*VI �\���p*/

	if ((mode == 1)
	&&  (fl_g_v_self_bsm_for_base >= 30.0F)) {															/* COND.j16 */
		if( fl_g_v_self_bsm_for_base < 35.0F ){															/* COND.j17 */
			v_limit = fl_g_v_self_bsm_for_base*0.8F;														/* PROC.2 */
		}else if( fl_g_v_self_bsm_for_base < 40.0F ){														/* COND.j18 */
			v_limit = fl_g_v_self_bsm_for_base*0.75F;														/* PROC.3 */
		}else if( fl_g_v_self_bsm_for_base < 45.0F ){														/* COND.j19 */
			v_limit = fl_g_v_self_bsm_for_base*0.7F;														/* PROC.4 */
		}else if( fl_g_v_self_bsm_for_base < 50.0F ){														/* COND.j20 */
			v_limit = fl_g_v_self_bsm_for_base*0.65F;														/* PROC.5 */
		}else if( fl_g_v_self_bsm_for_base < 55.0F ){														/* COND.j21 */
			v_limit = fl_g_v_self_bsm_for_base*0.6F;														/* PROC.6 */
		}else if( fl_g_v_self_bsm_for_base < 60.0F ){														/* COND.j22 */
			v_limit = fl_g_v_self_bsm_for_base*0.55F;														/* PROC.7 */
		}else if( fl_g_v_self_bsm_for_base < 65.0F ){														/* COND.j23 */
			v_limit = fl_g_v_self_bsm_for_base*0.5F;														/* PROC.8 */
		}else if( fl_g_v_self_bsm_for_base < 70.0F ){														/* COND.j24 */
			v_limit = fl_g_v_self_bsm_for_base*0.45F;														/* PROC.9 */
		}else{
			v_limit = fl_g_v_self_bsm_for_base*0.4F;														/* PROC.10 */
		}

		for(i = (start_freq_bin + 1); i <= (start_freq_bin + SLOW_SOT_FREQ_BIN_RANGE); i++) {	/* i=112,113, ... ,126 [freq_bin] */
			tmp_vsin = (FL)(i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / v_limit;
			if (tmp_vsin > 1.0F) {
				tmp_vsin = 1.0F;
			}
			if (tmp_vsin < -1.0F) {
				tmp_vsin = -1.0F;
			}
			
			doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;														/* PROC.11 v0_doa = 140 */
			diff1 = doa_stationary - (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index];								/* PROC.12 */

			if (i <= (S4)tmp) {																											/* COND.j25 */
				if ((diff1 >= 0.0F)																										/* COND.j26 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - (i - start_freq_bin)][index] != -1)) {										/* COND.j27 */
					*fast_sot_num += 1;																									/* PROC.13 */
				}
			} else {
				tmp_vsin = (FL)(i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / CFL_SoT_V_TH_BWD;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_limit = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;														/* PROC.14 v0_doa = 140 */
				diff2 = (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] - doa_limit;								/* PROC.15 */
				if ((diff1 >= 0.0F)																										/* COND.j26 */
				&&  (diff2 >= 0.0F)																										/* COND.j28 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] != -1)) {											/* COND.j27 */
					*fast_sot_num += 1;																									/* PROC.13 */
				}

				if ((diff2 < 0.0F)																										/* COND.!j26 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-(i-start_freq_bin)][index] != -1)) {											/* COND.j27 */
					*not_fast_sot_num += 1;																								/* PROC.16 */
				}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
				/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
				if ((diff1 < (FL)-10.0F)																	/* COND.j31 */
				&&  (diff2 > (FL)30.0F)																		/* COND.j32 */
				&&  (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - (i - start_freq_bin)][index] != (S4)-1)) {		/* COND.j27 */
					*not_fast_sot_num += 1;																	/* PROC.16 */
				}
#else
    �}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

			}
		}

		for(i=0; i<N_DOA; i++)
		{
			freq = NB_FFT_PT_2F / 2 + (S4)((v_limit) / 3.6F * fl_sin(PI / (FL)180.0F * (FL)(i - v0_doa)) / VCOF_2F);				/* PROC.17 */
	
			if ((freq >= 0)																					/* COND.j29 */
			&&  (freq < NB_FFT_PT_2F)) {																	/* COND.j30 */
				fast_sot_limit_line[i] = freq;																/* PROC.18 */
			} else {
				fast_sot_limit_line[i] = 0;																	/* PROC.19 */
			}
		}
#ifndef _291B_FOR_TEST_20160408_1	//FOR_DIAM_BSM_DEBUG
		memcpy(as4_g_fast_sot_limit_line_diam, fast_sot_limit_line, sizeof(S4)*N_DOA);
#endif /*VI �\���p*/
	}

	/* ���������� (iV)���U�̎Z�o ���������� */
	for(i=0; i<SLOW_SOT_FREQ_BIN_RANGE; i++)
	{
		index = 0;
		if (mode == 0) {
			if ((nearfield_doa[i][index] > doa_min)															/* COND.g9 */
			&&  (nearfield_doa[i][index] < doa_max)															/* COND.g10 */
			&&  (nearfield_doa[i][index] != -1)																/* COND.g12 */
			&&  ((start_freq_bin + i) >= bin_min)															/* COND.j10 */
			&&  ((start_freq_bin + i) <= bin_max)															/* COND.j11 */
			&&  (afl_a_sot_check_object[i][0] != CFL_UNKNOWN_VALUE)											/* COND.k19 */
			&&  (afl_a_sot_check_object[i][0] > (FL)0.0F)													/* COND.k20 */
			&&  (afl_a_sot_check_object[i][1] > (FL)-0.2F)) {												/* COND.k21 */
				/* ���̊֐���fl_g_v_self_bsm_for_base��0�̂Ƃ��ɂ̓R�[������Ȃ��̂�0���͂Ȃ� */
				tmp_vsin = (FL)(start_freq_bin + i - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.1' */
				tmp = doa_stationary - (FL)nearfield_doa[i][index];											/* PROC.1 */
				dev += tmp*tmp;																				/* PROC.3 */
				num++;																						/* PROC.4 */
			}
		} else {
			if ((nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] > doa_min)							/* COND.g13 */
			&& (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] < doa_max)							/* COND.g14 */
			&& (nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE - i - 1][index] != -1)								/* COND.g15 */
			&& ((start_freq_bin + i + 1) >= bin_min)														/* COND.j10 */
			&& ((start_freq_bin + i + 1) <= bin_max)														/* COND.j11 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][0] != CFL_UNKNOWN_VALUE)			/* COND.k22 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][0] > (FL)0.0F)						/* COND.k23 */
			&& (afl_a_sot_check_object[SLOW_SOT_FREQ_BIN_RANGE - i - 1][1] < (FL)0.2F)) {					/* COND.k24 */
				/* ���̊֐���fl_g_v_self_bsm_for_base��0�̂Ƃ��ɂ̓R�[������Ȃ��̂�0���͂Ȃ� */
				tmp_vsin = (FL)(start_freq_bin + i + (S4)1 - (NB_FFT_PT_2F / (S4)2)) * (FL)3.6F * VCOF_2F / fl_g_v_self_bsm_for_base;
				if (tmp_vsin > 1.0F) {
					tmp_vsin = 1.0F;
				}
				if (tmp_vsin < -1.0F) {
					tmp_vsin = -1.0F;
				}
				
				doa_stationary = (FL)fl_cal_asin(tmp_vsin) * 180.0F / PI + (FL)v0_doa;						/* PROC.2' */
				tmp = doa_stationary - (FL)nearfield_doa[SLOW_SOT_FREQ_BIN_RANGE-i-1][index];				/* PROC.2 */
				dev += tmp*tmp;																				/* PROC.3 */
				num++;																						/* PROC.4 */
			}
		}

	}

	if (mode == 0) {
		if (fl_g_v_self_bsm_for_base < 20.0F) {																/* COND.j12 */
			num_th = num_th - 1;																			/* PROC.13 */
			if (num_th < 1) {																				/* COND.j13 */
				num_th = 1;																					/* PROC.14 */
			}
		} else {
			if (num != (S4)0) {
				if ((dev / (FL)num) > WALL_DEV_TH5) {														/* COND.j14 */
					return dev / (FL)num;																	/* PROC.11 */
				}
			} else {
				/* num��0�̂Ƃ��͕��U���Z�o����Ă��Ȃ����ߕs��l�������l������ */
				dev = (FL)999.9F;
				*backward_priod = (S4)1;
				return dev;
			}
		}
	}

#if (BSM_OPTION_SW_RECOG_03 == TYPE_A)
	/* ���ڊp�x50deg�ł͏����Ȃ� */
#elif (BSM_OPTION_SW_RECOG_03 == TYPE_B)
	/* ���E���̂ݎ��{ */
	if (mode == (S4)1) {
		if (fl_g_v_self_bsm_for_base < (FL)20.0F) {															/* COND.j12 */
			num_th = num_th - (S4)3;																		/* PROC.p500 */
			if (num_th < (S4)1) {																			/* COND.j13 */
				num_th = (S4)1;																				/* PROC.14 */
			}
		}
	}
#else
	�}�N������`�̏ꍇ�́A�R���p�C���G���[�Ƃ���
#endif /* BSM_OPTION_SW_RECOG_03 */

	if (num > num_th) {																						/* COND.j15 */
		dev = dev / (FL)num;																				/* PROC.8 */
	} else {
		dev = 999.9F;																						/* PROC.9 */
	}

	if ((mode == 0)
	&&  (dev == 999.9F)) {																					/* COND.g16 */
		*backward_priod = 1;																				/* PROC.10 */
	}

	return dev;
}


/****************************************************************************/
/* �֐���		: calc_line_doa_fm											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: 															*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
FL calc_line_doa_fm(
	const FL Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/* [in] self correlation (fm) */
	FL power[NB_FFT_PT],								/* [in] power (fm) */
	S4 start_bin,										/* [in] */
	S4 end_bin,
	FL pow_th,											/* [in] */
	S4 line_doa[LINE_FREQ_BIN_RANGE][1],				/* [out] start_bin�`start_bin+LINE_FREQ_BIN_RANGEbin��DOA�s�[�N(�ő�1��/1bin) */
	S4 line_doa_peak_num[LINE_FREQ_BIN_RANGE],			/* [out] ��L�ebin��DOA�s�[�N��(�ő�1��) */
	S4 updn												/* [in] direction of beat-signal */
)
{
	FL ave_pow_dbf = 0.0F;
	S4 ave_num_dbf = 0;
	S4 i, j;
	FL spec_doa[N_DOA];
	S4 tmp_doa[1];
	FL tmp_peak_power[1];
	for( i = 0; i < N_DOA; i++ )
	{
		spec_doa[i] = 0.0F;
	}

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		for(j=0; j<1; j++)
		{
			line_doa[i][j] = 0;
		}
		line_doa_peak_num[i] = 0;
	}

	for(i=0; i<LINE_FREQ_BIN_RANGE; i++)
	{
		if ((start_bin + i) < end_bin) {
			/* DBF DOA */
			fn_calc_spec_bf_4ch_fm(
				(const FL *)(Ryy[start_bin+i]),
				spec_doa,
				updn,
				start_bin+i
			);
			/*DOA peaks */
			line_doa_peak_num[i] = s4_search_peak_bf(
				(const FL *)spec_doa,
				tmp_doa,
				tmp_peak_power,
				1
			);

			for(j=0; j<line_doa_peak_num[i]; j++ )
			{
				line_doa[i][j] = tmp_doa[j];
				ave_pow_dbf += tmp_peak_power[j];
				ave_num_dbf++;
			}
		}
		else
		{
			break;
		}
	}

	if(ave_num_dbf!=0)
	{
		ave_pow_dbf = ave_pow_dbf / (FL)ave_num_dbf;
	}

	return ave_pow_dbf;
}


/****************************************************************************/
/* �֐���		: set_freq_threshold_without_center_mask					*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-1)���ω��X�y�N�g�����̎Z�o							*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-1)���ω��X�y�N�g�����̎Z�o							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
VD set_freq_threshold_without_center_mask(
	const FL power[NB_FFT_PT],	/* [in] power of beat signal */
	FL thres[NB_FFT_PT]			/* [out] threshold for peak detection */
)
{
	S4 i, j;
	S4 ave_range = AVE_BIN_WIDTH;
	FL ave_power[NB_FFT_PT/AVE_BIN_WIDTH];
	FL clearance = AVE_POW_CLEARANCE;

	S4 loop_max;
	loop_max = NB_FFT_PT / ave_range;

	/* AVE_BIN_WIDTH freq-bin���̕��ϓd�� */
	for(i=0; i<loop_max; i++)
	{
		ave_power[i] = 0.0F;
		for( j=0; j<ave_range; j++ )
		{
			ave_power[i] = ave_power[i] + power[i*ave_range+j];
		}
		ave_power[i] = ave_power[i] / (FL)ave_range;

		if(ave_power[i]<PEAK_POW_TH_MIN)		/* COND.b1 */
		{
			ave_power[i] = PEAK_POW_TH_MIN;
		}

		for( j=0; j<ave_range; j++ )
		{
			thres[i*ave_range+j] = ave_power[i] + clearance;
		}
	}
}


/****************************************************************************/
/* �֐���		: set_wall_freq_threshold									*/
/*--------------------------------------------------------------------------*/
/* �@�\			: (2)-2) �x�[�X�d�͂̎Z�o									*/
/*				:	���g���X�y�N�g�����̎��g��bin���������͈͂̕��ω��X�y�N	*/
/*				:	�g�����̕��ϒl���x�[�X�d�͂Ƃ��ĎZ�o����B�������A����	*/
/*				:	��ԂɃs�[�N����������ꍇ���l�����āA���ʈȏ�̊O��l*/
/*				:	�͏��O����D											*/
/*				: (2)-3) �ڋߔ���p�����ʂ̎Z�o								*/
/*				:	���W���ڋ߂��Ă��邩�ۂ̔���́A���ω��X�y�N�g�����̌`��*/
/*				:	�̓����ʂ�p���čs���B�����ʂɂ́A����͈͓̔��ŕ��ω�	*/
/*				:	�X�y�N�g���������ȏ�ω������ω��_�̏���p����B	*/
/*				:	�ω��_�͍ő�3�_�܂ŋ��߂�B								*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-2) �x�[�X�d�͂̎Z�o									*/
/*				:	(2)-3) �ڋߔ���p�����ʂ̎Z�o							*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 set_wall_freq_threshold(					/* [return](not used) number of steps */
	const FL thres[NB_FFT_PT],				/* [in] threshold for peak detection */
	FL wall_thres[NB_FFT_PT],				/* [out] threshold for peak detection */
	S4 wall_check[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 wall_bin[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	FL wall_pow[WALL_FREQ_BIN_TH_STEPS],	/* [out] */
	S4 freq_start,							/* [in] */
	S4 freq_end								/* [in] */
)
{
	S4 iret = 0;
	S4 i, j;
	FL base_pow = 0.0F;
	FL tmp_pow = 0.0F;
	S4 tmp_count = 0;
	S4 tmp_wall_check[WALL_FREQ_BIN_TH_STEPS];
	S4 index[WALL_FREQ_BIN_TH_STEPS+1];
	FL pow[WALL_FREQ_BIN_TH_STEPS+1];
	S4 count[WALL_FREQ_BIN_TH_STEPS];
	S4 tmp_ret = 1;
	U1 u1_t_lp_freq_bin_th_steps;

	/* ���[�J���ϐ������� */
	for (u1_t_lp_freq_bin_th_steps = (U1)0; u1_t_lp_freq_bin_th_steps < (U1)WALL_FREQ_BIN_TH_STEPS; u1_t_lp_freq_bin_th_steps++) {
		tmp_wall_check[u1_t_lp_freq_bin_th_steps] = (S4)0;
		count[u1_t_lp_freq_bin_th_steps] = (S4)0;
	}

	for (u1_t_lp_freq_bin_th_steps = (U1)0; u1_t_lp_freq_bin_th_steps < ((U1)WALL_FREQ_BIN_TH_STEPS + (U1)1); u1_t_lp_freq_bin_th_steps++) {
		index[u1_t_lp_freq_bin_th_steps] = (S4)0;
		pow[u1_t_lp_freq_bin_th_steps] = (FL)0.0F;
	}

	/***** 2) �x�[�X�d�͂̎Z�o *****/
	base_pow = thres[BASE_FREQ_BIN_LOWER_LIMIT];
	tmp_count = 1;
	for(i=BASE_FREQ_BIN_LOWER_LIMIT; i<BASE_FREQ_BIN_UPPER_LIMIT; i++)
	{
		tmp_pow = thres[i+1] - base_pow;
		if( fl_abs(tmp_pow) < BASE_FREQ_POW_RANGE)			/* COND.b2 */
		{
			tmp_count++;
			base_pow += tmp_pow / (FL)tmp_count;
		}
	}

	/***** 3) �ڋߔ���p�����ʂ̎Z�o *****/
	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		pow[i] = base_pow;						/* PROC.1 */
	}
	index[0] = freq_start;						/* PROC.2 */
	index[WALL_FREQ_BIN_TH_STEPS] = freq_end;	/* PROC.3 */
	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		if(tmp_ret!=0)							/* COND.b3 */
		{
			tmp_ret = seek_freq_step(
				(const FL *)thres,		/* [in] */
				freq_end,				/* [in] */
				WALL_FREQ_POW_RANGE,	/* [in] */
				&pow[i],				/* [in/out] */
				&index[i],				/* [out] */
				&count[i],				/* [out] */
				&index[i+1]				/* [out] (available when return value is 1) */
			);
			pow[i+1] = pow[i];					/* PROC.13 */
			if(count[i]!=0)						/* COND.b7 */
			{
				iret++;							/* PROC.14 */
			}
		}
		else
		{
			break;
		}
	}

	for(i=0; i<NB_FFT_PT; i++)
	{
		wall_thres[i] = base_pow;					/* PROC.15 */
	}
	for(j=0; j<iret; j++)
	{
		if (count[j] >= (0.5 * (index[j+1]-index[j]))) {	/* COND.b8 */
			for(i=index[j]; i<NB_FFT_PT; i++)
			{
				wall_thres[i] = pow[j];				/* PROC.16 */
				tmp_wall_check[j] = 1;				/* PROC.17 */
			}
		}
		else
		{
			tmp_wall_check[j] = 0;					/* PROC.18 */
		}
	}

	for(i=freq_end; i<NB_FFT_PT; i++)
	{
		wall_thres[i] = base_pow;					/* PROC.15 */
	}

	for(i=0; i<WALL_FREQ_BIN_TH_STEPS; i++)
	{
		wall_check[i] = tmp_wall_check[i];
		wall_bin[i] = index[i];
		wall_pow[i] = pow[i];
	}
	return iret;
}


 /****************************************************************************/
/* �֐���		: seek_freq_step											*/
/*--------------------------------------------------------------------------*/
/* �@�\			: seek freq-power for stepped-threshold for leading vehicle */
/*				:	estimation												*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:	(2)-3)����b3�������i�ύX�_����j						*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 seek_freq_step(				/* [return] 0:no more step, 1:have next step */
	const FL thres[NB_FFT_PT],	/* [in] threshold for peak detection */
	S4 end_index,				/* [in] end point of freq-bin */
	FL pow_range,				/* [in] range of freq-power to treat as the same step  */
	FL pow[1],					/* [in/out] freq-pow of this step */
	S4 index[1],				/* [in/out] start point of this step */
	S4 count[1],				/* [out] number of freq-bin of this step  */
	S4 next_index[1]			/* [out] end point of this step(start point of next step) */
)
{
	S4 iret = 0;

	S4 i;
	FL tmp_pow_diff = 0.0F;
	S4 start_index = index[0];
	S4 tmp_next_index = next_index[0];
	S4 tmp_index = index[0];
	S4 tmp_count = count[0];
	FL tmp_pow = pow[0];							/* PROC.4 */

	/* �ω��|�C���g�i�㏸ or ���~�|�C���g�j */
	for(i=start_index; i<end_index; i++)
	{
		tmp_pow_diff = thres[i] - tmp_pow;			/* PROC.5 */
		/*    __    */
		/* __|      */
		if( tmp_pow_diff > WALL_POW_TH )			/* COND.b4 */
		{
			tmp_pow = thres[i];						/* PROC.6 */
			tmp_index = i;							/* PROC.7 */
			break;
		}
		/* __      */
		/*   |__   */
		else if( tmp_pow_diff < -WALL_POW_TH )		/* COND.b5 */
		{
			tmp_pow = thres[i];						/* PROC.6 */
			tmp_index = i;							/* PROC.7 */
			break;
		} else {
			/* �������Ȃ� */
		}
	}

	for(i=tmp_index; i<end_index; i++)
	{
		tmp_pow_diff = thres[i] - tmp_pow;				/* PROC.5 */
		/* ______  */
		/*         */
		if( fl_abs(tmp_pow_diff) < pow_range )			/* COND.b6 */
		{
			tmp_count++;								/* PROC.8 */
			tmp_pow += tmp_pow_diff / (FL)tmp_count;	/* PROC.9 */
		}
		else
		{
			/*    __  */
			/* __|    */
			if(tmp_pow_diff > WALL_POW_TH)			/* COND.b4 */
			{
				iret = 1;							/* PROC.10 */
				tmp_next_index = i+1;				/* PROC.12 */
				break;
			}
			/* __     */
			/*   |__  */
			else
			{
				iret = -1;							/* PROC.11 */
				tmp_next_index = i+1;				/* PROC.12 */
				break;
			}
		}
	}

	pow[0] = tmp_pow;
	index[0] = tmp_index; 
	count[0] = tmp_count;
	next_index[0] = tmp_next_index;

	return iret;
}


/****************************************************************************/
/* �֐���		: peak_search_music_fsk_all_doa								*/
/*--------------------------------------------------------------------------*/
/* �@�\			: 															*/
/*--------------------------------------------------------------------------*/
/* ����			: 															*/
/* �߂�l		: 															*/
/*--------------------------------------------------------------------------*/
/* �O���[�o���ϐ��A�N�Z�X													*/
/* <input>		:															*/
/* <output>		:															*/
/*--------------------------------------------------------------------------*/
/* �Ή��d�l		: MWR-RECO-24G-BSM-RECOG-03-008.pdf							*/
/*				:															*/
/*--------------------------------------------------------------------------*/
/* �쐬��		: 															*/
/****************************************************************************/
S4 peak_search_music_fsk_all_doa(
	const FL music_spec[N_DOA_2F],		/* [in] */
	S4 bin_music[2],					/* [out] */
	FL power_music[2],					/* [out] */
	S4 wave_num_in						/* [in] */
)
{
	S4 i,j;
	S4 tmp_bin_music[4];
	FL tmp_power_music[4];
	S4 peak_num_music = 0;
	S4 tmp_int;
	FL tmp_float;
	S4 wave_num = wave_num_in;
	U1 u1_t_lp_peak_num;

	/* ���[�J���ϐ������� */
	for (u1_t_lp_peak_num = (U1)0; u1_t_lp_peak_num < (U1)4; u1_t_lp_peak_num++) {
		tmp_bin_music[u1_t_lp_peak_num] = (S4)0;
		tmp_power_music[u1_t_lp_peak_num] = (FL)0.0F;
	}

	/*********** music_spec_peak_search ***************/
	j = 0;
	for( i=0; i<N_DOA; i++ )
	{
		if ((music_spec[i] < music_spec[i+1])
		&&  (music_spec[i+1] > music_spec[i+2])
		&&  (j < 4)) {
			if (music_spec[i+1] > 5) {
				tmp_bin_music[j] = i + 1;
				tmp_power_music[j] = music_spec[i+1];
				j++;
			}
		}
	}
	peak_num_music = j;

	/***********�s�[�N����葽�������ꍇ�̏���*****************/
	if ( wave_num >= peak_num_music )
	{
		wave_num = peak_num_music;
		for ( i = 0; i < wave_num; i++ )
		{
			bin_music[i] = tmp_bin_music[i];
			power_music[i] = tmp_power_music[i];
		}
	}
	else
	{
		/***********�d�͏��ɂȂ�ׂ���*****************/
		for ( i = 0; i < peak_num_music; i++ )
		{
			for ( j = i+1; j < peak_num_music; j++ )
			{
				if ( tmp_power_music[i] < tmp_power_music[j] )
				{
					tmp_float = tmp_power_music[i];
					tmp_power_music[i] = tmp_power_music[j];
					tmp_power_music[j] = tmp_float;

					tmp_int = tmp_bin_music[i];
					tmp_bin_music[i] = tmp_bin_music[j];
					tmp_bin_music[j] = tmp_int;
				}
			}
		}

		for ( i = 0; i < wave_num; i++ )
		{
			bin_music[i] = tmp_bin_music[i];
			power_music[i] = tmp_power_music[i];
		}
	}

	/***********bin���ɂȂ�ׂ���*****************/
	for ( i = 0; i < wave_num; i++ )
	{
		for ( j = i+1; j < wave_num; j++ )
		{
			if ( bin_music[i] > bin_music[j] )
			{
				tmp_int = bin_music[i];
				bin_music[i] = bin_music[j];
				bin_music[j] = tmp_int;

				tmp_float = power_music[i];
				power_music[i] = power_music[j];
				power_music[j] = tmp_float;
			}
		}
	}

	return wave_num;
}



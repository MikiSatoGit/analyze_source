/**
 * @file BSM_RECOG_05.c
 * @brief Functions for searching trailer object based on ordinary object
 * @author DNJP 走安技2 1技室 T.Lai
 * date 16.11.28	t01
 */

/****************************************************************************/
/*							include											*/
/****************************************************************************/
#include "../inc_bsm.h"
#include "../parameter_def.h"
#include "../normal_def.h"

#include "../bsm_main.h"
#include "../../common/cmn_signal.h"
#include "init_cvw.h"
#include "bsm_connect_01.h"
#include "func_fmcw.h"
#include "func_fsk.h"
#include "../../common/cmn_shareMUSIC_mwr.h"
#include "../../../common/inc_mwr.h"

#include "bsm_recog_05.h"
#include "../btt/bsm_btt.h"

#ifndef _291B_DEV_20161005_BTT_TEST
#include "../../../../../simm/dll_export/user_main_sns_dllexp.h"
#endif

/****************************************************************************/
/*							Functions										*/
/****************************************************************************/
VD fn_bsm_trailer_init_data(
	S4 *ps4_a_peak_num_trailer,
	S4 as4_a_peak_bin[PEAK_BUFFSIZE],			/* selected peak freq - bin (up) */
	FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],	/*interpolated peak freq - bin (up) */
	FL afl_a_peak_power[PEAK_BUFFSIZE],

	S4 as4_a_peak_bin_trailer[TRAILER_BUFFSIZE],
	FL afl_a_peak_bin_intpl_trailer[TRAILER_BUFFSIZE],
	FL afl_a_peak_power_trailer[TRAILER_BUFFSIZE],

	S4 *ps4_a_peak_num_music,
	FL afl_a_peak_bins_intpl[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_powers[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl[PEAK_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers[PEAK_BUFFSIZE * 2]
);

VD fn_bsm_trailer_init_thres(
	FL afl_a_thres_trailer[NB_FFT_PT]
);

VD fn_bsm_trailer_estimate_doa(
	S4 s4_a_flg_updn,
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */

	S4 s4_a_peak_num,
	const S4 as4_a_peak_bin[TRAILER_BUFFSIZE],								/* [in] frequency of peak */
	const FL afl_a_peak_bin_intpl[TRAILER_BUFFSIZE],						/* [in] interpolated frequency of peak */
	const FL afl_a_peak_power[TRAILER_BUFFSIZE],							/* [in] afl_a_power of peak */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[TRAILER_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[TRAILER_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[TRAILER_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[TRAILER_BUFFSIZE * 2]						/* [out] peak doa afl_a_power */
#ifndef _20170119_ATD_DOADBF_CHECK
	,FL afl_a_doa_pow_ave[3]
	,FL afl_a_doa_pow_dev[3]
#endif
);

VD fn_bsm_trailer_cal_doa(
	S4 s4_a_updn_flg,										/*  [in] direction of beat-signal */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],				/*  [in] correlation matrix */

	S4 s4_a_peak_bin,										/*  [in] frequency of peak */
	FL fl_a_peak_bin_intpl,									/*  [in] interpolated frequency of peak */

	S4 *ps4_a_doa_num,										/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],					/* [out] */
	FL afl_a_selected_doa_powers[2],						/* [out] */
	FL afl_a_selected_bins_intpl[2]							/* [out] */
);

VD fn_bsm_trailer_store_doa(
	const FL afl_a_peak_power[TRAILER_BUFFSIZE],							/* [in] afl_a_power of peak */

	const S4 as4_a_doa_num[TRAILER_BUFFSIZE],
	FL afl_a_selected_doa_bins_intpl[TRAILER_BUFFSIZE][2],
	FL afl_a_selected_doa_powers[TRAILER_BUFFSIZE][2],
	FL afl_a_selected_bins_intpl[TRAILER_BUFFSIZE][2],

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[TRAILER_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[TRAILER_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[TRAILER_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[TRAILER_BUFFSIZE * 2]					/* [out] peak doa afl_a_power */
);

VD fn_bsm_trailer_make_pair(
	S4 s4_a_peak_num_up_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_up[TRAILER_BUFFSIZE * 2],					/* [in] */
	FL afl_a_peak_powers_up[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_up[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 s4_a_peak_num_dn_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_dn[TRAILER_BUFFSIZE * 2],					/* [in] */
	FL afl_a_peak_powers_dn[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_dn[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4*		   ps4_a_pair_num_trailer,									/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]					/* [out] S4 values of NORMAL_BSM structure */
);

VD fn_bsm_trailer_make_pair_moving(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[TRAILER_BUFFSIZE * 2],					/* [in] */
	const FL afl_a_peak_powers_up[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_up[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[TRAILER_BUFFSIZE * 2],					/* [in] */
	const FL afl_a_peak_powers_dn[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_dn[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 as4_a_used_peak_up[TRAILER_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[TRAILER_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[TRAILER_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[TRAILER_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]
);

static VD fn_bsm_trailer_check_minimum_pair(
	S4  s4_a_lp_peak_num_up,
	S4  s4_a_lp_peak_num_dn,
	FL  afl_a_compare[TRAILER_BUFFSIZE * 2][TRAILER_BUFFSIZE * 2],
	S4  as4_a_used_peak_up[TRAILER_BUFFSIZE * 2],
	S4  as4_a_used_peak_dn[TRAILER_BUFFSIZE * 2],
	S4  as4_a_pair_index_up[TRAILER_BUFFSIZE * 2],
	S4  as4_a_pair_index_dn[TRAILER_BUFFSIZE * 2],
	FL* pfl_a_min_comp,
	S4* ps4_a_found,
	S4* ps4_a_pair_index_up,
	S4* ps4_a_pair_index_dn,
	S4* ps4_a_pair_num
);

VD fn_bsm_trailer_set_object(
	const S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
);

VD fn_check_ordinary_trailer_obj(
	S4			*pair_num_ordinary,
	NORMAL_BSM	ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4			*pair_num_trailer,
	NORMAL_BSM	ast_a_normal_trailer[TRAILER_BUFFSIZE],
	FL			afl_t_thres_trailer[NB_FFT_PT]
);

#ifndef _20170119_ATD_DOADBF_CHECK
VD fn_check_bf_doa_power(
	S4* s4_a_doa_bf_peak_bin,			/* [out] */
	FL* fl_a_doa_bf_peak_pow			/* [out] */
);
#endif

/********************************************************************************************/
/*!
	@brief
	search trailer object

	@return void

	call function
	- fn_bsm_trailer_init_data()
	- fn_bsm_trailer_init_thres()
	- fn_set_freq_threshold()
	- s4_search_freq_peak()
	- fn_sort_peak_by_power_trailer()
	- fn_bsm_trailer_estimate_doa()
	- fn_bsm_trailer_make_pair()
	- fn_check_ordinary_trailer_obj()
	- fn_bsm_trailer_set_object()

	@detail
	This function is used for searching trailer objects within a specific range. \n

*********************************************************************************************/

VD fn_bsm_seek_trailer_object(
	S4*		ps4_a_pair_num_ordinary,
	NORMAL_BSM ast_a_normalordinary[ORDINARY_BUFFSIZE],
	S4*		ps4_a_pair_num_trailer,
	NORMAL_BSM ast_a_normaltrailer[TRAILER_BUFFSIZE]
#ifndef _20170119_ATD_DOADBF_CHECK
	,FL afl_t_doa_pow_ave[2][3]
	,FL afl_t_doa_pow_dev[2][3]
	,S4* s4_a_doa_bf_peak_bin
	,FL* fl_a_doa_bf_peak_pow
#endif
)
{
	S4 s4_t_peak_num_trailer_up;
	S4 as4_t_peak_bin_up[PEAK_BUFFSIZE];					/* selected peak freq - bin (up) */
	FL afl_t_peak_bin_intpl_up[PEAK_BUFFSIZE];				/* interpolated peak freq-bin (up) */
	FL afl_t_peak_power_up[PEAK_BUFFSIZE];
    FL afl_t_thres_trailer[NB_FFT_PT];						/* [out] threashold for spectrum power（up) */

	S4 s4_t_peak_num_trailer_dn;
	S4 as4_t_peak_bin_dn[PEAK_BUFFSIZE];					/* selected peak freq - bin (down) */
	FL afl_t_peak_bin_intpl_dn[PEAK_BUFFSIZE];				/* interpolated peak freq-bin (down) */
	FL afl_t_peak_power_dn[PEAK_BUFFSIZE];
 
	S4 as4_t_peak_bin_up_trailer[TRAILER_BUFFSIZE];			/* selected peak freq - bin (up) SIZE:TRAILER_BUFFSIZE */
	FL afl_t_peak_bin_intpl_up_trailer[TRAILER_BUFFSIZE];	/* interpolated peak freq-bin (up) SIZE:TRAILER_BUFFSIZE */
	FL afl_t_peak_power_up_trailer[TRAILER_BUFFSIZE];

	S4 as4_t_peak_bin_dn_trailer[TRAILER_BUFFSIZE];			/* selected peak freq - bin (down) SIZE:TRAILER_BUFFSIZE */
	FL afl_t_peak_bin_intpl_dn_trailer[TRAILER_BUFFSIZE];	/* interpolated peak freq-bin (down) SIZE:TRAILER_BUFFSIZE */
	FL afl_t_peak_power_dn_trailer[TRAILER_BUFFSIZE];

	S4 s4_t_peak_num_up_music;
	FL afl_t_peak_bins_intpl_up[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_powers_up[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_doa_bins_intpl_up[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_doa_powers_up[TRAILER_BUFFSIZE * 2];

	S4 s4_t_peak_num_dn_music;
	FL afl_t_peak_bins_intpl_dn[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_powers_dn[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_doa_bins_intpl_dn[TRAILER_BUFFSIZE * 2];
	FL afl_t_peak_doa_powers_dn[TRAILER_BUFFSIZE * 2];

	S4 s4_t_lp_peakbuff;

	S4 s4_t_lp_i;
	S4 s4_t_trailer_bin_range;
	S4 s4_t_ordinary_trailer_num = 0;

	/*! @note (1) initialize trailer object data */
	fn_bsm_trailer_init_data(
		&s4_t_peak_num_trailer_up,
		as4_t_peak_bin_up,
		afl_t_peak_bin_intpl_up,
		afl_t_peak_power_up,

		as4_t_peak_bin_up_trailer,
		afl_t_peak_bin_intpl_up_trailer,
		afl_t_peak_power_up_trailer,

		&s4_t_peak_num_up_music,
		afl_t_peak_bins_intpl_up,
		afl_t_peak_powers_up,
		afl_t_peak_doa_bins_intpl_up,
		afl_t_peak_doa_powers_up
	);

	fn_bsm_trailer_init_data(
		&s4_t_peak_num_trailer_dn,
		as4_t_peak_bin_dn,
		afl_t_peak_bin_intpl_dn,
		afl_t_peak_power_dn,

		as4_t_peak_bin_dn_trailer,
		afl_t_peak_bin_intpl_dn_trailer,
		afl_t_peak_power_dn_trailer,

		&s4_t_peak_num_dn_music,
		afl_t_peak_bins_intpl_dn,
		afl_t_peak_powers_dn,
		afl_t_peak_doa_bins_intpl_dn,
		afl_t_peak_doa_powers_dn
	);


	fn_bsm_trailer_init_thres(
		afl_t_thres_trailer
	);

	/*! @note (2) -1) Set different threshold for the range of trailer object */
	fn_set_freq_threshold(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],			/* [in] */
		afl_t_thres_trailer								/* [out] */
#ifndef _20161123_BTT_FM_THRES
		,OBJECT_TYPE_TRAILER							/* [in] object type: trailer object */
#endif
	);

#ifndef _20161222_FM_UP_ALLPEAK
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T) && !defined(_20170119_ATD_DOADBF_CHECK)
	afl_g_btt_atd_doa_pow_ave[0] = (FL)0;
	afl_g_btt_atd_doa_pow_ave[1] = (FL)0;
#endif
	/*! @note (2) -2) Peak Searching (UP): assume there are all peaks within freq. range = 256 - 263 (or 265?) */
	for (s4_t_lp_peakbuff = (S4)0; s4_t_lp_peakbuff < TRAILER_RANGE; s4_t_lp_peakbuff++) {
		if( s4_t_peak_num_trailer_up < PEAK_BUFFSIZE
		&&  afl_g_cvw_lfm_ftt_power[0][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff] > afl_t_thres_trailer[FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff] 
		){
			as4_t_peak_bin_up[s4_t_peak_num_trailer_up] = FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff;								
			afl_t_peak_bin_intpl_up[s4_t_peak_num_trailer_up] = (FL)(FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff);					
			afl_t_peak_power_up[s4_t_peak_num_trailer_up] = afl_g_cvw_lfm_ftt_power[1][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff];	
			s4_t_peak_num_trailer_up++;																		
		}
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T) && !defined(_20170119_ATD_DOADBF_CHECK)
		afl_g_btt_atd_doa_pow_ave[0] += afl_g_cvw_lfm_ftt_power[0][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff];
#endif
	}
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T) && !defined(_20170119_ATD_DOADBF_CHECK)
	afl_g_btt_atd_doa_pow_ave[0] = afl_g_btt_atd_doa_pow_ave[0] / (FL)TRAILER_RANGE;
#endif
#else
	/*! @note (2) -2) Peak Searching (UP): trailer object range = 256 - 263 (or 265?) */
	s4_t_peak_num_trailer_up = s4_search_freq_peak(
		(const FL *)afl_g_cvw_lfm_ftt_power[0],	/* [in] */
		as4_t_peak_bin_up,						/* [out] */
		afl_t_peak_bin_intpl_up,				/* [out] */
		afl_t_peak_power_up,					/* [out] */
		(const FL *)afl_t_thres_trailer,		/* [in] */
		FREQ_BIN_LOWER_LIMIT_T,
		FREQ_BIN_UPPER_LIMIT_DN_T
	);
#endif

	/*! @note (2) -3) Peak Searching (DN): assume there are all peaks within freq. range = 256 - 263 (or 265?) */
	for (s4_t_lp_peakbuff = (S4)0; s4_t_lp_peakbuff < TRAILER_RANGE; s4_t_lp_peakbuff++) {
		if( s4_t_peak_num_trailer_dn < PEAK_BUFFSIZE
		 && afl_g_cvw_lfm_ftt_power[1][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff] > afl_t_thres_trailer[FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff]
		) {														
			as4_t_peak_bin_dn[s4_t_peak_num_trailer_dn] = FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff;								
			afl_t_peak_bin_intpl_dn[s4_t_peak_num_trailer_dn] = (FL)(FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff);					
			afl_t_peak_power_dn[s4_t_peak_num_trailer_dn] = afl_g_cvw_lfm_ftt_power[1][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff];	
			s4_t_peak_num_trailer_dn++;																		
		}
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T) && !defined(_20170119_ATD_DOADBF_CHECK)
		afl_g_btt_atd_doa_pow_ave[1] += afl_g_cvw_lfm_ftt_power[1][FREQ_BIN_LOWER_LIMIT_T+s4_t_lp_peakbuff];
#endif
	}
#if !defined(_291B_DEV_20161005_BTT_TEST) && !defined(_291B_20161101_BTT_OUTPUT_T) && !defined(_20170119_ATD_DOADBF_CHECK)
	afl_g_btt_atd_doa_pow_ave[1] = afl_g_btt_atd_doa_pow_ave[1] / (FL)TRAILER_RANGE;
#endif

	/*! @note (2) -4) Sort peaks by peak power */
	fn_sort_peak_by_power_trailer(
		as4_t_peak_bin_up,					/* [in] */
		afl_t_peak_bin_intpl_up,			/* [in] */
		afl_t_peak_power_up,				/* [in] */
		as4_t_peak_bin_up_trailer,			/* [out] */
		afl_t_peak_bin_intpl_up_trailer,	/* [out] */
		afl_t_peak_power_up_trailer			/* [out] */
	);
	fn_sort_peak_by_power_trailer(
		as4_t_peak_bin_dn,					/* [in] */
		afl_t_peak_bin_intpl_dn,			/* [in] */
		afl_t_peak_power_dn,				/* [in] */
		as4_t_peak_bin_dn_trailer,			/* [out] */
		afl_t_peak_bin_intpl_dn_trailer,	/* [out] */
		afl_t_peak_power_dn_trailer			/* [out] */
	);

	/* ピーク個数をガード */
	if (s4_t_peak_num_trailer_up > TRAILER_BUFFSIZE) {
		s4_t_peak_num_trailer_up = TRAILER_BUFFSIZE;
	}
	if (s4_t_peak_num_trailer_dn > TRAILER_BUFFSIZE) {
		s4_t_peak_num_trailer_dn = TRAILER_BUFFSIZE;
	}

	/*! @note (3) Estimate DoA: focus on DoA range = (-22) - (+17) (0-37) [0 deg = side of SV]  3 - 35 (30-35) */
	fn_bsm_trailer_estimate_doa(
		0,
		afl_g_cvw_lfm_ryy_matrix[0],

		s4_t_peak_num_trailer_up,
		(const S4 *)as4_t_peak_bin_up_trailer,
		(const FL *)afl_t_peak_bin_intpl_up_trailer,
		(const FL *)afl_t_peak_power_up_trailer,

		&s4_t_peak_num_up_music,
		afl_t_peak_bins_intpl_up,
		afl_t_peak_powers_up,
		afl_t_peak_doa_bins_intpl_up,
		afl_t_peak_doa_powers_up
#ifndef _20170119_ATD_DOADBF_CHECK
		,afl_t_doa_pow_ave[0]
		,afl_t_doa_pow_dev[0]
#endif
	);

	fn_bsm_trailer_estimate_doa(
		1,
		afl_g_cvw_lfm_ryy_matrix[1],
		
		s4_t_peak_num_trailer_dn,
		(const S4 *)as4_t_peak_bin_dn_trailer,
		(const FL *)afl_t_peak_bin_intpl_dn_trailer,
		(const FL *)afl_t_peak_power_dn_trailer,

		&s4_t_peak_num_dn_music,
		afl_t_peak_bins_intpl_dn,
		afl_t_peak_powers_dn,
		afl_t_peak_doa_bins_intpl_dn,
		afl_t_peak_doa_powers_dn
#ifndef _20170119_ATD_DOADBF_CHECK
		,afl_t_doa_pow_ave[1]
		,afl_t_doa_pow_dev[1]
#endif
	);


#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(28, &au2_g_bsm_check_tmr[28]);				/* CheckPoint chk bsm */
	/* S4→U1のダウンキャストであるが、s4_t_peak_num_up/dn_musicの値域がU1の範囲に収まるため問題ない */
	u1_g_bsm_trailer_up_pair_num = (U1)s4_t_peak_num_up_music;		/* CheckPoint BSM_通常物標物標数up */
	u1_g_bsm_trailer_dn_pair_num = (U1)s4_t_peak_num_dn_music;		/* CheckPoint BSM_通常物標物標数dn */
#endif /* MODE_ECU_SIM */

	/*! @note (4) Pair Matching: based on ordinary object, but focus on moving object only */
	fn_bsm_trailer_make_pair(
		s4_t_peak_num_up_music,											/* [in] */
		(const FL *)afl_t_peak_bins_intpl_up,							/* [in] */
		afl_t_peak_powers_up,											/* [in] */
		(const FL *)afl_t_peak_doa_bins_intpl_up,						/* [in] */
		(const FL *)afl_t_peak_doa_powers_up,							/* [in] */

		s4_t_peak_num_dn_music,											/* [in] */
		(const FL *)afl_t_peak_bins_intpl_dn,							/* [in] */
		afl_t_peak_powers_dn,											/* [in] */
		(const FL *)afl_t_peak_doa_bins_intpl_dn,						/* [in] */
		(const FL *)afl_t_peak_doa_powers_dn,							/* [in] */

		ps4_a_pair_num_trailer,										/* [out] number of trailer object */
		ast_a_normaltrailer											/* [out] S4 values of NORMAL_BSM structure */
	);
	
	/*! @note (5) Check if there is a trailer object in ordinary object */
	fn_check_ordinary_trailer_obj(
		ps4_a_pair_num_ordinary,
		ast_a_normalordinary,
		ps4_a_pair_num_trailer,
		ast_a_normaltrailer,
		afl_t_thres_trailer
	);

#ifndef _20170119_ATD_DOADBF_CHECK
	fn_check_bf_doa_power(
		s4_a_doa_bf_peak_bin,			/* [out] */
		fl_a_doa_bf_peak_pow			/* [out] */
	);


#if !defined(_291B_DEV_20161005_BTT_TEST) && defined(_291B_20161101_BTT_OUTPUT_T)
	afl_g_btt_atd_doa_pow_ave[0] = *fl_a_doa_bf_peak_pow-afl_t_doa_pow_ave[0][1];
	afl_g_btt_atd_doa_pow_ave[1] = *fl_a_doa_bf_peak_pow;
#endif

#endif

#if (MODE_ECU_SIM == ECU_MODE)
	fn_drv_time_chk(29, &au2_g_bsm_check_tmr[29]);			/* CheckPoint chk bsm */
#endif /* MODE_ECU_SIM */

	/* 出力データ保存 */
	fn_bsm_trailer_set_object(
		(const S4 *)ps4_a_pair_num_trailer,
		ast_a_normaltrailer
	);

}


/********************************************************************************************/
/*!
	@brief
	initialize trailer object data

	@return void

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_init_data(
	S4 *ps4_a_peak_num_trailer,
	S4 as4_a_peak_bin[PEAK_BUFFSIZE],			/* selected peak freq - bin (up) */
	FL afl_a_peak_bin_intpl[PEAK_BUFFSIZE],	/*interpolated peak freq - bin (up) */
	FL afl_a_peak_power[PEAK_BUFFSIZE],
 
	S4 as4_a_peak_bin_trailer[TRAILER_BUFFSIZE],
	FL afl_a_peak_bin_intpl_trailer[TRAILER_BUFFSIZE],
	FL afl_a_peak_power_trailer[TRAILER_BUFFSIZE],

	S4 *ps4_a_peak_num_music,
	FL afl_a_peak_bins_intpl[TRAILER_BUFFSIZE * 2],
	FL afl_a_peak_powers[TRAILER_BUFFSIZE * 2],
	FL afl_a_peak_doa_bins_intpl[TRAILER_BUFFSIZE * 2],
	FL afl_a_peak_doa_powers[TRAILER_BUFFSIZE * 2]
)
{
	S4 s4_t_lp_i;

	*ps4_a_peak_num_trailer = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < PEAK_BUFFSIZE; s4_t_lp_i++) {
		as4_a_peak_bin[s4_t_lp_i] = 0;
		afl_a_peak_bin_intpl[s4_t_lp_i] = 0.0F;
		afl_a_peak_power[s4_t_lp_i] = 0.0F;
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		as4_a_peak_bin_trailer[s4_t_lp_i] = (S4)0;
		afl_a_peak_bin_intpl_trailer[s4_t_lp_i] = (FL)0.0F;
		afl_a_peak_power_trailer[s4_t_lp_i] = (FL)0.0F;
	}

	*ps4_a_peak_num_music = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < (TRAILER_BUFFSIZE * 2); s4_t_lp_i++) {
		afl_a_peak_bins_intpl[s4_t_lp_i] = 0;
		afl_a_peak_powers[s4_t_lp_i] = 0.0F;
		afl_a_peak_doa_bins_intpl[s4_t_lp_i] = 0;
		afl_a_peak_doa_powers[s4_t_lp_i] = 0.0F;
	}

	return;
}


VD fn_bsm_trailer_init_thres(
	FL afl_a_thres[NB_FFT_PT]
)
{
	S4 s4_t_lp_i;

	for (s4_t_lp_i = 0; s4_t_lp_i < NB_FFT_PT; s4_t_lp_i++) {
		afl_a_thres[s4_t_lp_i] = 0.0F;
	}
	return;
}

/********************************************************************************************/
/*!
	@brief
	estimate doa of trailer object

	@return void

	call function
	- fn_bsm_trailer_cal_doa()
	- fn_bsm_trailer_store_doa()

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_estimate_doa(
	S4 s4_a_flg_updn,
	FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],						/* [in] self correlation */

	S4 s4_a_peak_num,
	const S4 as4_a_peak_bin[TRAILER_BUFFSIZE],								/* [in] frequency of peak */
	const FL afl_a_peak_bin_intpl[TRAILER_BUFFSIZE],						/* [in] interpolated frequency of peak */
	const FL afl_a_peak_power[TRAILER_BUFFSIZE],							/* [in] afl_a_power of peak */

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[TRAILER_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[TRAILER_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[TRAILER_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[TRAILER_BUFFSIZE * 2]						/* [out] peak doa afl_a_power */
#ifndef _20170119_ATD_DOADBF_CHECK
	,FL afl_a_doa_pow_ave[3]
	,FL afl_a_doa_pow_dev[3]
#endif
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;
	S4 s4_t_doa_calc_num;

	S4 as4_t_doa_num[TRAILER_BUFFSIZE];
	FL afl_t_selected_doa_bins_intpl[TRAILER_BUFFSIZE][2];
	FL afl_t_selected_doa_powers[TRAILER_BUFFSIZE][2];
	FL afl_t_selected_bins_intpl[TRAILER_BUFFSIZE][2];
	FL afl_t_selected_doa_bins_intpl_copy[TRAILER_BUFFSIZE][2];	/* 該当FFTピークのMUSICピーク bin(補間値)コピー用変数 */
	FL afl_t_selected_doa_powers_copy[TRAILER_BUFFSIZE][2];		/* 該当FFTピークのMUSICピーク方位におけるDBF電力値コピー用変数 */
	FL afl_t_selected_bins_intpl_copy[TRAILER_BUFFSIZE];			/* 該当FFTピークのFFTピークbin(補間値)コピー用変数 */

	/* 初期化 */
	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		as4_t_doa_num[s4_t_lp_i] = 0;
		afl_t_selected_bins_intpl_copy[s4_t_lp_i] = (FL)0.0F;
		for (s4_t_lp_k = 0; s4_t_lp_k < 2; s4_t_lp_k++) {
			afl_t_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_doa_powers[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_bins_intpl[s4_t_lp_i][s4_t_lp_k] = 0.0F;
			afl_t_selected_doa_bins_intpl_copy[s4_t_lp_i][s4_t_lp_k] = (FL)0.0F;
			afl_t_selected_doa_powers_copy[s4_t_lp_i][s4_t_lp_k] = (FL)0.0F;
		}
	}

	s4_t_doa_calc_num = (S4)0;

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num; s4_t_lp_i++ ) {
		if (s4_t_doa_calc_num < TRAILER_BUFFSIZE-1)
		{
			s4_t_doa_calc_num++;

			/* (3) - 2)～5) 方位推定 */
			fn_bsm_trailer_cal_doa(
				s4_a_flg_updn,
				(const FL (*)[10])afl_a_Ryy,

				as4_a_peak_bin[s4_t_lp_i],
				afl_a_peak_bin_intpl[s4_t_lp_i],

				&as4_t_doa_num[s4_t_lp_i],
				afl_t_selected_doa_bins_intpl[s4_t_lp_i],
				afl_t_selected_doa_powers[s4_t_lp_i],
				afl_t_selected_bins_intpl[s4_t_lp_i]
			);
		}
	}

#ifndef _20170119_ATD_DOADBF_CHECK
	for (s4_t_lp_i = 0; s4_t_lp_i < 3; s4_t_lp_i++ ) {
		fn_bsm_cal_trailer_range_doa_ave(
			s4_a_flg_updn,
			(const FL (*)[10])afl_a_Ryy,
			(260+s4_t_lp_i),
			&afl_a_doa_pow_ave[s4_t_lp_i],
			&afl_a_doa_pow_dev[s4_t_lp_i]
		);
	}
#endif

	*ps4_a_doa_peak_num = 0;
	/* (3) - 6) 方位推定結果の格納 */
	fn_bsm_trailer_store_doa(
		(const FL *)afl_a_peak_power,

		(const S4 *)as4_t_doa_num,
		afl_t_selected_doa_bins_intpl,
		afl_t_selected_doa_powers,
		afl_t_selected_bins_intpl,

		ps4_a_doa_peak_num,
		afl_a_peak_bins_intpl,					/* [out] peak frequency */
		afl_a_peak_powers,						/* [out] peak afl_a_power */
		afl_a_peak_doa_bins_intpl,				/* [out] peak doa bin */
		afl_a_peak_doa_powers					/* [out] peak doa afl_a_power */
	);

	return;
}	


/********************************************************************************************/
/*!
	@brief
	calculate doa of trailer object by focusing on a specific doa range

	@return void

	call function
	- s4_calc_spec_music_4ch_all()
	- s4_search_peak_music()
	- fl_calc_spec_bf_4ch_fm_of_specified_doa()
	- fl_interpolate_music_peak()

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_cal_doa(
	S4 s4_a_updn_flg,										/*  [in] direction of beat-signal */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],				/*  [in] correlation matrix */

	S4 s4_a_peak_bin,										/*  [in] frequency of peak */
	FL fl_a_peak_bin_intpl,									/*  [in] interpolated frequency of peak */

	S4 *ps4_a_doa_num,										/* [out] */
	FL afl_a_selected_doa_bins_intpl[2],					/* [out] */
	FL afl_a_selected_doa_powers[2],						/* [out] */
	FL afl_a_selected_bins_intpl[2]							/* [out] */
)
{
	S4 s4_t_lp_i;

	FL afl_t_spec[N_DOA];
	S4 s4_t_wall_bin;

	S4 as4_t_selected_doa_bins[2];
	S4 s4_t_temp_wave_num = WAVE_NUMBER;
	U1 u1_t_lp_doa_num;

	S4 s4_t_tmp_doa_num = 0;

	for (s4_t_lp_i = 0; s4_t_lp_i < N_DOA; s4_t_lp_i++ ) {
		afl_t_spec[s4_t_lp_i] = 0;
	}

	for (u1_t_lp_doa_num = (U1)0; u1_t_lp_doa_num < (U1)2; u1_t_lp_doa_num++) {
		as4_t_selected_doa_bins[u1_t_lp_doa_num] = (S4)0;
	}

	/***** 2) MUSICによる角度スペクトラムの算出 *****/
	s4_t_temp_wave_num = s4_calc_spec_music_4ch_all(
		afl_a_Ryy[s4_a_peak_bin],						/*  [in] */
		afl_t_spec,										/*  [out] */
		2,												/*  [in] */
		s4_a_updn_flg									/*  [in] */
	);
	*ps4_a_doa_num = 0;
	*ps4_a_doa_num = s4_search_peak_music(
		(const FL *)afl_t_spec,							/*  [in] */
		as4_t_selected_doa_bins,						/*  [out] [2] DOA of MUSIC peak */
		afl_a_selected_doa_powers,						/*  [out] [2] afl_a_power of MUSIC peak */
		s4_t_temp_wave_num								/*  [in]  $$$ 2013.11.1 s4_t_wave_num(1) -> s4_t_temp_wave_num(推定到来波数) */
#ifndef _20161116_BTT_DOA_RANGE_T
		,OBJECT_TYPE_TRAILER							/*  [in] object type: trailer object */
#endif
	);

	for (s4_t_lp_i = 0; s4_t_lp_i < 2; s4_t_lp_i++) {
		if (as4_t_selected_doa_bins[s4_t_lp_i] > 0) {
			afl_a_selected_doa_powers[s4_t_lp_i] = fl_calc_spec_bf_4ch_fm_of_specified_doa(
				afl_a_Ryy[s4_a_peak_bin],
				s4_a_updn_flg,
				s4_a_peak_bin,
				as4_t_selected_doa_bins[s4_t_lp_i]
			);
		}
	}

	for(s4_t_lp_i=0; s4_t_lp_i<2; s4_t_lp_i++)
	{
		if(as4_t_selected_doa_bins[s4_t_lp_i]>0)
		{
			afl_a_selected_doa_bins_intpl[s4_t_lp_i] = fl_interpolate_music_peak(
				(const FL *)afl_t_spec,
				as4_t_selected_doa_bins[s4_t_lp_i],
				(const FL *)FL_BSM_FLSH_YOMIKAE_TBL_FM
			);
			afl_a_selected_bins_intpl[s4_t_lp_i] = fl_a_peak_bin_intpl;
		}
		else
		{
			afl_a_selected_doa_bins_intpl[s4_t_lp_i] = 0.0F;
			afl_a_selected_bins_intpl[s4_t_lp_i] = 0.0F;
		}
	}

	return;
}


#ifndef _20170119_ATD_DOADBF_CHECK
VD fn_bsm_cal_trailer_range_doa_ave(
	S4 s4_a_updn_flg,										/*  [in] direction of beat-signal */
	const FL afl_a_Ryy[NB_FFT_PT][CORRE_SIZE_4CH],			/*  [in] correlation matrix */

	S4 s4_a_peak_bin,										/*  [in] frequency of peak */
	FL *afl_t_doa_pow_ave,
	FL *afl_t_doa_pow_dev
)
{
	S4 s4_t_lp_i;

	FL fl_t_tmp_doa_power = (FL)0;
	FL fl_t_tmp_doa_power_ave = (FL)0;
	FL fl_t_tmp_doa_power_dev = (FL)0;
	FL fl_t_tmp_doa_power_sum1 = (FL)0;	
	FL fl_t_tmp_doa_power_sum2 = (FL)0;
	S4 s4_t_doa_range = (S4)((FL)(N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0] - (FL)CU1_DOA_BIN_LOWER_LIMIT_T + (FL)CU1_DOA_BIN_UPPER_LIMIT_T);//30;


	for (s4_t_lp_i = 0; s4_t_lp_i < s4_t_doa_range; s4_t_lp_i++) {
		fl_t_tmp_doa_power = fl_calc_spec_bf_4ch_fm_of_specified_doa(
			afl_a_Ryy[s4_a_peak_bin],
			s4_a_updn_flg,
			s4_a_peak_bin,
			(0 + s4_t_lp_i)
		);
		fl_t_tmp_doa_power_sum1 += fl_t_tmp_doa_power;
		fl_t_tmp_doa_power_sum2 += fl_t_tmp_doa_power * fl_t_tmp_doa_power;
	}
	fl_t_tmp_doa_power_ave = fl_t_tmp_doa_power_sum1 / (FL)s4_t_doa_range;
	fl_t_tmp_doa_power_dev = (fl_t_tmp_doa_power_sum2 / (FL)s4_t_doa_range) - (fl_t_tmp_doa_power_ave * fl_t_tmp_doa_power_ave);

	*afl_t_doa_pow_ave = fl_t_tmp_doa_power_ave;
	*afl_t_doa_pow_dev = fl_t_tmp_doa_power_dev;
	return;
}
#endif

/********************************************************************************************/
/*!
	@brief
	store doa data of trailer object

	@return void

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_store_doa(
	const FL afl_a_peak_power[TRAILER_BUFFSIZE],							/* [in] afl_a_power of peak */

	const S4 as4_a_doa_num[TRAILER_BUFFSIZE],
	FL afl_a_selected_doa_bins_intpl[TRAILER_BUFFSIZE][2],
	FL afl_a_selected_doa_powers[TRAILER_BUFFSIZE][2],
	FL afl_a_selected_bins_intpl[TRAILER_BUFFSIZE][2],

	S4 *ps4_a_doa_peak_num,											/* [out] */
	FL afl_a_peak_bins_intpl[TRAILER_BUFFSIZE * 2],					/* [out] peak frequency */
	FL afl_a_peak_powers[TRAILER_BUFFSIZE * 2],						/* [out] peak afl_a_power */
	FL afl_a_peak_doa_bins_intpl[TRAILER_BUFFSIZE * 2],				/* [out] peak doa bin */
	FL afl_a_peak_doa_powers[TRAILER_BUFFSIZE * 2]					/* [out] peak doa afl_a_power */
)
{
	S4 s4_t_iRet;

	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	/* ペアマッチ用の方位推定結果を格納 */
	s4_t_iRet = 0;
	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < as4_a_doa_num[s4_t_lp_i]; s4_t_lp_k++) {
			if( afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k] > 0 ) {
				afl_a_peak_bins_intpl[s4_t_iRet]	 = afl_a_selected_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_a_peak_powers[s4_t_iRet]		 = afl_a_peak_power[s4_t_lp_i];
				afl_a_peak_doa_bins_intpl[s4_t_iRet] = afl_a_selected_doa_bins_intpl[s4_t_lp_i][s4_t_lp_k];
				afl_a_peak_doa_powers[s4_t_iRet]	 = afl_a_selected_doa_powers[s4_t_lp_i][s4_t_lp_k];
				s4_t_iRet++;
			}
		}
	}
	*ps4_a_doa_peak_num = s4_t_iRet;

}

#ifndef _20170119_ATD_DOADBF_CHECK
VD fn_check_bf_doa_power(
	S4* s4_a_doa_bf_peak_bin,			/* [out] */
	FL* fl_a_doa_bf_peak_pow			/* [out] */
)
{
	FL tmp_doa_spec_up[N_DOA];
	S4 tmp_doa_peak_bin_up[1];
	FL tmp_doa_peak_pow_up[1];

	FL tmp_doa_spec_dn[N_DOA];
	S4 tmp_doa_peak_bin_dn[1];
	FL tmp_doa_peak_pow_dn[1];

	U1 u1_t_lp_n_doa;
	S4 s4_t_focus_bin;
	S4 s4_t_focus_doa;
	S4 s4_t_doa_range;

	for (u1_t_lp_n_doa = (U1)0; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		tmp_doa_spec_up[u1_t_lp_n_doa] = (FL)0.0F;
	}
	tmp_doa_peak_bin_up[0] = (S4)-1;
	tmp_doa_peak_bin_dn[0] = (S4)-1;
	tmp_doa_peak_pow_up[0] = (FL)0.0F;
	tmp_doa_peak_pow_dn[0] = (FL)0.0F;

	s4_t_focus_bin = BTT_DBF_FOCUS_BIN;	//2m
	s4_t_doa_range = (S4)((FL)(N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0] + BTT_DBF_DOA_RANGE); //70

	fn_calc_spec_bf_4ch_fm(
		afl_g_cvw_lfm_ryy_matrix[0][s4_t_focus_bin],
		tmp_doa_spec_up,
		0,
		s4_t_focus_bin
	);

	/* only search peak within the range of doa = 0 - s4_t_doa_range */
	for (u1_t_lp_n_doa = (U1)s4_t_doa_range; u1_t_lp_n_doa < (U1)N_DOA; u1_t_lp_n_doa++) {
		tmp_doa_spec_up[u1_t_lp_n_doa] = (FL)0.0F;
	}
	s4_search_peak_bf(
		(const FL *)tmp_doa_spec_up,		/* [in] */
		tmp_doa_peak_bin_up,				/* [out] */
		tmp_doa_peak_pow_up,				/* [out] */
		1									/* [in] */
	);
	if( tmp_doa_peak_bin_up[0] != (S4)-1 ){
		*s4_a_doa_bf_peak_bin = tmp_doa_peak_bin_up[0];
		*fl_a_doa_bf_peak_pow = tmp_doa_peak_pow_up[0];
	}
}
#endif

/********************************************************************************************/
/*!
	@brief
	pair matching of trailer object

	@return void

	call function
	- fn_bsm_trailer_make_pair_moving()

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_make_pair(
	S4 s4_a_peak_num_up_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_up[TRAILER_BUFFSIZE * 2],					/* [in] */
	FL afl_a_peak_powers_up[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_up[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 s4_a_peak_num_dn_music,											/* [in] */
	const FL afl_a_peak_bins_intpl_dn[TRAILER_BUFFSIZE * 2],					/* [in] */
	FL afl_a_peak_powers_dn[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_dn[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4*		   ps4_a_pair_num_trailer,									/* [out] number of prior object */
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]					/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;

	S4 as4_t_used_peak_up[TRAILER_BUFFSIZE * 2];
	S4 as4_t_used_peak_dn[TRAILER_BUFFSIZE * 2];
	S4 as4_t_pair_index_up[TRAILER_BUFFSIZE * 2];
	S4 as4_t_pair_index_dn[TRAILER_BUFFSIZE * 2];

	for (s4_t_lp_i = 0; s4_t_lp_i < (TRAILER_BUFFSIZE * 2); s4_t_lp_i++) {
		as4_t_used_peak_up[s4_t_lp_i] = 0;
		as4_t_used_peak_dn[s4_t_lp_i] = 0;
		as4_t_pair_index_up[s4_t_lp_i] = 0;
		as4_t_pair_index_dn[s4_t_lp_i] = 0;
	}

	fn_bsm_trailer_make_pair_moving(
		s4_a_peak_num_up_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_up,										/* [in] */
		afl_a_peak_powers_up,								/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_up,									/* [in] */
		(const FL *)afl_a_peak_doa_powers_up,										/* [in] */

		s4_a_peak_num_dn_music,											/* [in] */
		(const FL *)afl_a_peak_bins_intpl_dn,										/* [in] */
		afl_a_peak_powers_dn,											/* [in] */
		(const FL *)afl_a_peak_doa_bins_intpl_dn,									/* [in] */
		(const FL *)afl_a_peak_doa_powers_dn,										/* [in] */

		as4_t_used_peak_up,												/* [out] */
		as4_t_used_peak_dn,												/* [out] */
		as4_t_pair_index_up,											/* [out] */
		as4_t_pair_index_dn,											/* [out] */

		ps4_a_pair_num_trailer,										/* [out] */
		ast_a_normal_trailer											/* [out] */
	);

	return;
}


/********************************************************************************************/
/*!
	@brief
	pair matching of moving object (method is the same as ordinary object)

	@return void

	call function
	- fn_bsm_trailer_check_minimum_pair()
	- fn_set_normal_data()

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_make_pair_moving(
	S4 s4_a_peak_num_up,												/* [in] */
	const FL afl_a_peak_bins_intpl_up[TRAILER_BUFFSIZE * 2],					/* [in] */
	const FL afl_a_peak_powers_up[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_up[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_up[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 s4_a_peak_num_dn,												/* [in] */
	const FL afl_a_peak_bins_intpl_dn[TRAILER_BUFFSIZE * 2],					/* [in] */
	const FL afl_a_peak_powers_dn[TRAILER_BUFFSIZE * 2],						/* [in] */
	const FL afl_a_peak_doa_bins_intpl_dn[TRAILER_BUFFSIZE * 2],				/* [in] */
	const FL afl_a_peak_doa_powers_dn[TRAILER_BUFFSIZE * 2],					/* [in] */

	S4 as4_a_used_peak_up[TRAILER_BUFFSIZE * 2],
	S4 as4_a_used_peak_dn[TRAILER_BUFFSIZE * 2],
	S4 as4_a_pair_index_up[TRAILER_BUFFSIZE * 2],
	S4 as4_a_pair_index_dn[TRAILER_BUFFSIZE * 2],

	S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_k;

	FL afl_t_compare[TRAILER_BUFFSIZE * 2][TRAILER_BUFFSIZE * 2];
	S4 s4_t_tmp_doa_diff_up_down = DOA_DIFF_UP_DOWN;	/* $$$ 2013.08.07-3 */
	FL fl_t_tmp_pow_diff_up_down;
	U2 u2_t_tmp_freq_diff_up_down;

	S4 s4_t_found;
	FL fl_t_min_comp;
	S4 as4_t_tmp_pair_index_up = 0;
	S4 as4_t_tmp_pair_index_dn = 0;

	S4 s4_t_pair_num;
	S4 s4_t_tmp_pair_num;

	fl_t_tmp_pow_diff_up_down = POW_DIFF_UP_DOWN_DOA;
	u2_t_tmp_freq_diff_up_down = NB_FFT_PT;

/****************************************************************************/
/* (7)	移動物ペアマッチ処理												*/
/****************************************************************************/
	/* initialize comparsion param. */
	for (s4_t_lp_i = 0; s4_t_lp_i < (TRAILER_BUFFSIZE * 2); s4_t_lp_i++) {
		for (s4_t_lp_k = 0; s4_t_lp_k < (TRAILER_BUFFSIZE * 2); s4_t_lp_k++) {
			afl_t_compare[s4_t_lp_i][s4_t_lp_k] = 1000.0;
		}
	}

	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		if (as4_a_used_peak_up[s4_t_lp_i] == 0) {								/* COND a1/c1 */
			for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
				if (as4_a_used_peak_dn[s4_t_lp_k] == 0) {						/* COND a2/c2 */
					/***** 1) 角度差の許容範囲の設定 *****/
					s4_t_tmp_doa_diff_up_down = (S4)CU1_DOA_DIFF_UP_DOWN_VERYNEAR;

					/***** 2) 移動物ペアマッチの評価値の算出 *****/
					fl_t_tmp_pow_diff_up_down = POW_DIFF_UP_DOWN_DOA;											/* PROC.4 */
					u2_t_tmp_freq_diff_up_down = (U2)2;//3; //low relative speed //NB_FFT_PT;						/* PROC.5 */
					
					if ((fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]) < fl_t_tmp_pow_diff_up_down)							/*  COND. c3 */
					&&  ((S4)fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])) < s4_t_tmp_doa_diff_up_down)		/*  COND. c4 */
					&&  (afl_a_peak_bins_intpl_up[s4_t_lp_i] - afl_a_peak_bins_intpl_dn[s4_t_lp_k] < (FL)u2_t_tmp_freq_diff_up_down)) {								/*  COND. c5 */
						afl_t_compare[s4_t_lp_i][s4_t_lp_k] = (0.5F * fl_abs(afl_a_peak_doa_powers_up[s4_t_lp_i] - afl_a_peak_doa_powers_dn[s4_t_lp_k]))				/* DOA pow. 0.5F: weighting factor */
															+ (1.0F * fl_abs((FL)(afl_a_peak_doa_bins_intpl_up[s4_t_lp_i] - afl_a_peak_doa_bins_intpl_dn[s4_t_lp_k])))	/* DOA */
															+ (0.5F * fl_abs(afl_a_peak_powers_up[s4_t_lp_i] - afl_a_peak_powers_dn[s4_t_lp_k]));						/* FREQ  0.5F: weighting factor */
					}
				}
			}
		}
	}

	/***** 3) ペアマッチ評価値が最小となる上り／下りのピークペアを求める *****/
	s4_t_pair_num = *ps4_a_pair_num;
	for (s4_t_lp_i = 0; s4_t_lp_i < s4_a_peak_num_up; s4_t_lp_i++) {
		fl_t_min_comp = 1000.0;
		s4_t_found = 0;
		for (s4_t_lp_k = 0; s4_t_lp_k < s4_a_peak_num_dn; s4_t_lp_k++) {
			fn_bsm_trailer_check_minimum_pair(
				s4_t_lp_i,
				s4_t_lp_k,
				afl_t_compare,
				as4_a_used_peak_up,
				as4_a_used_peak_dn,
				as4_a_pair_index_up,
				as4_a_pair_index_dn,
				&fl_t_min_comp,
				&s4_t_found,
				&as4_t_tmp_pair_index_up,
				&as4_t_tmp_pair_index_dn,
				&s4_t_pair_num
			);
		}
		
		/*  出力データをセット */
		if (s4_t_found == 1)									/* COND. d4 */
		{
			as4_a_used_peak_up[as4_t_tmp_pair_index_up] = 1;
			as4_a_used_peak_dn[as4_t_tmp_pair_index_dn] = 1;
			as4_a_pair_index_up[s4_t_pair_num] = as4_t_tmp_pair_index_up;
			as4_a_pair_index_dn[s4_t_pair_num] = as4_t_tmp_pair_index_dn;
			s4_t_pair_num++;
		}
	}

	/*  物標情報算出 */
	/*  SoT&停止物:[0]～[s4_t_tmp_pair_num-1] */
	s4_t_tmp_pair_num = *ps4_a_pair_num;
	for (s4_t_lp_i = s4_t_tmp_pair_num; s4_t_lp_i < s4_t_pair_num; s4_t_lp_i++) {
		if ((s4_t_lp_i) < TRAILER_BUFFSIZE) {	/* $$$ バッファあふれ防止(30 -> 15なのでちゃんと優先順位をつけたほうがよい) */
			fn_set_normal_data(
				&ast_a_normal_trailer[s4_t_lp_i],
				afl_a_peak_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak freq-bin (up) */
				afl_a_peak_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak freq-bin (down) */
				afl_a_peak_doa_bins_intpl_up[as4_a_pair_index_up[s4_t_lp_i]],	/*  peak doa-bin (up) */
				afl_a_peak_doa_bins_intpl_dn[as4_a_pair_index_dn[s4_t_lp_i]],	/*  peak doa-bin (down) */
				afl_a_peak_powers_up[as4_a_pair_index_up[s4_t_lp_i]],			/*  peak freq-power (up) */
				afl_a_peak_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],			/*  peak freq-power (down) */
				afl_a_peak_doa_powers_up[as4_a_pair_index_up[s4_t_lp_i]],		/*  peak doa-power (up) */
				afl_a_peak_doa_powers_dn[as4_a_pair_index_dn[s4_t_lp_i]],		/*  peak doa-power (down) */
				0,																/*  停止物フラグ */
				0																/*  片ピークフラグ */
			);
		}
	}
	*ps4_a_pair_num = s4_t_pair_num;

	/* 後段の処理で配列外参照が発生しないように、TRAILER_BUFFSIZEで上限ガードをかける */
	if (*ps4_a_pair_num > TRAILER_BUFFSIZE) {
		*ps4_a_pair_num = TRAILER_BUFFSIZE;
	}
	
	return;
}

/********************************************************************************************/
/*!
	@brief
	compare the difference of pair (method is the same as ordinary object)

	@return void

	@detail
*********************************************************************************************/
static VD fn_bsm_trailer_check_minimum_pair(S4  s4_a_lp_peak_num_up,
											 S4  s4_a_lp_peak_num_dn,
											 FL  afl_a_compare[TRAILER_BUFFSIZE * 2][TRAILER_BUFFSIZE * 2],
											 S4  as4_a_used_peak_up[TRAILER_BUFFSIZE * 2],
											 S4  as4_a_used_peak_dn[TRAILER_BUFFSIZE * 2],
											 S4  as4_a_pair_index_up[TRAILER_BUFFSIZE * 2],
											 S4  as4_a_pair_index_dn[TRAILER_BUFFSIZE * 2],
											 FL* pfl_a_min_comp,
											 S4* ps4_a_found,
											 S4* ps4_a_pair_index_up,
											 S4* ps4_a_pair_index_dn,
											 S4* ps4_a_pair_num)
{
	FL fl_t_min_comp_prev;									/* ペアマッチ評価値の比較対象値の保存変数 */
	FL fl_t_min_comp_temp;									/* ペアマッチ評価値の仮保存変数 */
	S4 s4_t_pair_num_tmp;									/* ペアマッチ数カウント用変数 */
	S4 as4_t_pair_index_up[TRAILER_BUFFSIZE * 2];			/* ペアマッチインデックス並べ替え用バッファ(上り) */
	S4 as4_t_pair_index_dn[TRAILER_BUFFSIZE * 2];			/* ペアマッチインデックス並べ替え用バッファ(下り) */
	S4 s4_t_lp_pair_num;									/* ペア個数のループ変数 仕様書ではk,ii,jjが対象 3個の変数を統一している */
	S4 s4_t_lp_num_ordi_2;									/* TRAILER_BUFFSIZE * 2のループ変数 */

	/* 変数初期化 */
	for (s4_t_lp_num_ordi_2 = (S4)0; s4_t_lp_num_ordi_2 < ((S4)TRAILER_BUFFSIZE * (S4)2); s4_t_lp_num_ordi_2++) {
		as4_t_pair_index_up[s4_t_lp_num_ordi_2] = (S4)0;
		as4_t_pair_index_dn[s4_t_lp_num_ordi_2] = (S4)0;
	}

	/* ※017-1 <Comparing process> */
	/* 仕様のi = 0 ～ peak_num_up_doa-1とj = 0 ～ peak_num_dn_doa-1のforループは */
	/* 親関数に存在している */
	if (afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn] < *pfl_a_min_comp) {				/* COND. k1 */
		if ((as4_a_used_peak_up[s4_a_lp_peak_num_up] == (S4)0)										/* COND. k2 */
		&&  (as4_a_used_peak_dn[s4_a_lp_peak_num_dn] == (S4)0)) {									/* COND. k3 */
			*pfl_a_min_comp = afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn];
			*ps4_a_found = (S4)1;
			*ps4_a_pair_index_up = s4_a_lp_peak_num_up;
			*ps4_a_pair_index_dn = s4_a_lp_peak_num_dn;
		} else {
			/* Check already paired items */
			for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < *ps4_a_pair_num; s4_t_lp_pair_num++) {
				if (((!(as4_a_used_peak_up[s4_a_lp_peak_num_up] == (S4)0))						/* COND. !k2 */
				&&   (as4_a_pair_index_up[s4_t_lp_pair_num] == s4_a_lp_peak_num_up))			/* COND. k6 */
				||  ((!(as4_a_used_peak_dn[s4_a_lp_peak_num_dn] == (S4)0))						/* COND. !k3 */
				&&   (as4_a_pair_index_dn[s4_t_lp_pair_num] == s4_a_lp_peak_num_dn))) {		/* COND. k7 */
					fl_t_min_comp_temp = *pfl_a_min_comp;
					*pfl_a_min_comp = afl_a_compare[s4_a_lp_peak_num_up][s4_a_lp_peak_num_dn];
					fl_t_min_comp_prev = afl_a_compare[as4_a_pair_index_up[s4_t_lp_pair_num]][as4_a_pair_index_dn[s4_t_lp_pair_num]];
					if (*pfl_a_min_comp < fl_t_min_comp_prev) {				/* COND. k8 */
						/* Cancel previous pair */
						as4_a_used_peak_up[as4_a_pair_index_up[s4_t_lp_pair_num]] = (S4)0;
						as4_a_used_peak_dn[as4_a_pair_index_dn[s4_t_lp_pair_num]] = (S4)0;
						
						/*  Erase index of previous pair */
						as4_a_pair_index_up[s4_t_lp_pair_num] = (S4)-1;
						as4_a_pair_index_dn[s4_t_lp_pair_num] = (S4)-1;
						
						/* Set new pair */
						*ps4_a_found = (S4)1;
						*ps4_a_pair_index_up = s4_a_lp_peak_num_up;
						*ps4_a_pair_index_dn = s4_a_lp_peak_num_dn;
					} else {
						*pfl_a_min_comp = fl_t_min_comp_temp;
					}
				}
			}
		}
		/*  Trim pair_index_up/dn (trim cancelled items in the pair index buffer) */
		s4_t_pair_num_tmp = (S4)0;
		for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < *ps4_a_pair_num; s4_t_lp_pair_num++) {
			if (as4_a_pair_index_up[s4_t_lp_pair_num] != (S4)-1) {					/* COND. k9 */
				as4_t_pair_index_up[s4_t_pair_num_tmp] = as4_a_pair_index_up[s4_t_lp_pair_num];
				as4_t_pair_index_dn[s4_t_pair_num_tmp] = as4_a_pair_index_dn[s4_t_lp_pair_num];
				s4_t_pair_num_tmp++;
			}
		}
		
		if (s4_t_pair_num_tmp > (S4)0) {					/* COND. k10 */
			for (s4_t_lp_pair_num = (S4)0; s4_t_lp_pair_num < s4_t_pair_num_tmp; s4_t_lp_pair_num++) {
				as4_a_pair_index_up[s4_t_lp_pair_num] = as4_t_pair_index_up[s4_t_lp_pair_num];
				as4_a_pair_index_dn[s4_t_lp_pair_num] = as4_t_pair_index_dn[s4_t_lp_pair_num];
			}
		}
		
		*ps4_a_pair_num = s4_t_pair_num_tmp;
	}

	return;
}


/********************************************************************************************/
/*!
	@brief
	setup the object type of detected trailer object

	@return void

	@detail
*********************************************************************************************/
VD fn_bsm_trailer_set_object(
	const S4 *ps4_a_pair_num,
	NORMAL_BSM ast_a_normal_trailer[TRAILER_BUFFSIZE]				/* [out] S4 values of NORMAL_BSM structure */
)
{
	S4 s4_t_lp_i;

	/* set object type */
	for (s4_t_lp_i = 0; s4_t_lp_i < *ps4_a_pair_num; s4_t_lp_i++) {
		ast_a_normal_trailer[s4_t_lp_i].s4_flg_dc = OBJECT_TYPE_TRAILER;
	}

	return;
}


/********************************************************************************************/
/*!
	@brief
	check and compare ordinary object with trailer object

	@return void

	call function
	- fn_init()
	- copy_trailer_data()
	- fn_sort_trailer()
	- s4_trim_ordinary()

	@detail
	This function is to add ordinary object which meets the conditions to trailer object. \n
	Or, erase an ordinary object if it is the same as trailer object. \n

*********************************************************************************************/
VD fn_check_ordinary_trailer_obj(
	S4			*as4_pair_num_ordinary,
	NORMAL_BSM	ast_a_normal_ordinary[ORDINARY_BUFFSIZE],
	S4			*as4_pair_num_trailer,
	NORMAL_BSM	ast_a_normal_trailer[TRAILER_BUFFSIZE],
	FL			afl_t_thres_trailer[NB_FFT_PT]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;
	S4 s4_trailer_bin;
	FL fl_power_thres;
	S4 s4_t_erase_ordinary_flag;
	S4 s4_t_pair_num_trailer;
	FL fl_t_doa_upper_limit;

	NORMAL_BSM copy_tmp_normal_trailer[TRAILER_BUFFSIZE];
	fn_init(copy_tmp_normal_trailer, TRAILER_BUFFSIZE);

	copy_trailer_data(ast_a_normal_trailer, copy_tmp_normal_trailer, *as4_pair_num_trailer);

	s4_t_pair_num_trailer = *as4_pair_num_trailer;
	fl_t_doa_upper_limit = ((FL)(N_DOA * 0.5F) - st_g_bsm_loop_data.afl_installed_angle[0]  - (FL)CU1_DOA_BIN_LOWER_LIMIT_T + (FL)CU1_DOA_BIN_UPPER_LIMIT_T );

	for(s4_t_lp_i = 0; s4_t_lp_i < *as4_pair_num_ordinary; s4_t_lp_i++)
	{
		/*! @note (5) - 1) check the frequency bin, doa, and peak power of ordinary object */
		s4_trailer_bin = ast_a_normal_ordinary[s4_t_lp_i].s4_bin_up;
		fl_power_thres = afl_t_thres_trailer[s4_trailer_bin];
		if( ast_a_normal_ordinary[s4_t_lp_i].s4_bin_up < FREQ_BIN_UPPER_LIMIT_DN_T
		 && ast_a_normal_ordinary[s4_t_lp_i].s4_bin_dn < FREQ_BIN_UPPER_LIMIT_DN_T //FREQ_BIN_UPPER_LIMIT_T
		 && ast_a_normal_ordinary[s4_t_lp_i].fl_doa_up_interpolate < fl_t_doa_upper_limit
		 && ast_a_normal_ordinary[s4_t_lp_i].fl_doa_dn_interpolate < fl_t_doa_upper_limit
		 && ast_a_normal_ordinary[s4_t_lp_i].fl_power_up > fl_power_thres
		 && ast_a_normal_ordinary[s4_t_lp_i].fl_power_dn > fl_power_thres
		){
			s4_t_erase_ordinary_flag = (S4)0;
			for(s4_t_lp_j = 0; s4_t_lp_j < *as4_pair_num_trailer; s4_t_lp_j++)
			{
				/*! @note (5) - 1)-1 Erase ordinary object if it's the same as trailer object */
				if( ast_a_normal_ordinary[s4_t_lp_i].s4_bin_up == ast_a_normal_trailer[s4_t_lp_j].s4_bin_up
				 && ast_a_normal_ordinary[s4_t_lp_i].s4_bin_dn == ast_a_normal_trailer[s4_t_lp_j].s4_bin_dn
				 && ast_a_normal_ordinary[s4_t_lp_i].fl_power_up == ast_a_normal_trailer[s4_t_lp_j].fl_power_up
				 && ast_a_normal_ordinary[s4_t_lp_i].fl_power_dn == ast_a_normal_trailer[s4_t_lp_j].fl_power_dn
				){
					s4_t_erase_ordinary_flag = (S4)1;
				}
			}
			if( s4_t_erase_ordinary_flag == (S4)0)
			{
				/*! @note (5) - 1)-2 Add ordinary object to trailer object */
				copy_trailer_data(&ast_a_normal_ordinary[s4_t_lp_i], &copy_tmp_normal_trailer[s4_t_pair_num_trailer], (S4)1);
				fn_init(&ast_a_normal_ordinary[s4_t_lp_i], 1);
				s4_t_pair_num_trailer ++;
			} else{
				fn_init(&ast_a_normal_ordinary[s4_t_lp_i], 1);
			}
		}
	}

	if( s4_t_pair_num_trailer > TRAILER_BUFFSIZE )
	{
		s4_t_pair_num_trailer = TRAILER_BUFFSIZE;
	}
	*as4_pair_num_trailer = s4_t_pair_num_trailer;

	/*! @note (5) - 2) Sort trailer object by the sum of up & dn peak power */
	fn_sort_trailer(copy_tmp_normal_trailer, ast_a_normal_trailer);

	*as4_pair_num_ordinary = s4_trim_ordinary(ast_a_normal_ordinary);

	return;
}


/********************************************************************************************/
/*!
	@brief
	sort trailer object by the sum of up & dn peak power

	@return void

	call function
	- fn_init()
	- fn_move()

	@detail
*********************************************************************************************/
VD fn_sort_trailer(
	NORMAL_BSM  ast_a_copy_normal_trailer[TRAILER_BUFFSIZE],
	NORMAL_BSM  ast_a_normal_trailer[TRAILER_BUFFSIZE]
)
{
	S4 s4_t_lp_i;
	S4 s4_t_lp_j;

	NORMAL_BSM ast_t_buf_normal[TRAILER_BUFFSIZE];
#ifndef _20170221_BTT_TRAILEROBJ_SORTBYRANGE
	FL fl_a_range_1 = (FL)0;
	FL fl_a_range_2 = (FL)0;
#else
	FL fl_a_power_sum_1 = (FL)0;
	FL fl_a_power_sum_2 = (FL)0;
#endif
	fn_init(ast_t_buf_normal, TRAILER_BUFFSIZE);

	fn_move(ast_t_buf_normal, ast_a_copy_normal_trailer, TRAILER_BUFFSIZE);

#ifndef _20170221_BTT_TRAILEROBJ_SORTBYRANGE
	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < TRAILER_BUFFSIZE; s4_t_lp_j++) {
			if (s4_t_lp_i < s4_t_lp_j) {
				if (	/* 中身が入っているかどうかの確認用 */
					(ast_a_copy_normal_trailer[s4_t_lp_i].fl_Ryobs != CFL_UNKNOWN_VALUE)
				 && (ast_a_copy_normal_trailer[s4_t_lp_j].fl_Ryobs != CFL_UNKNOWN_VALUE)
				) {
					fl_a_range_1 = ast_a_copy_normal_trailer[s4_t_lp_i].fl_Ryobs;
					fl_a_range_2 = ast_a_copy_normal_trailer[s4_t_lp_j].fl_Ryobs;

					if (fl_a_range_1 < fl_a_range_2) {
						ast_t_buf_normal[s4_t_lp_i] = ast_a_copy_normal_trailer[s4_t_lp_j];
						ast_t_buf_normal[s4_t_lp_j] = ast_a_copy_normal_trailer[s4_t_lp_i];
						ast_a_copy_normal_trailer[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
						ast_a_copy_normal_trailer[s4_t_lp_j] = ast_t_buf_normal[s4_t_lp_j];
					}
				}
			}
		}
	}
#else
	for (s4_t_lp_i = 0; s4_t_lp_i < TRAILER_BUFFSIZE; s4_t_lp_i++) {
		for (s4_t_lp_j = 0; s4_t_lp_j < TRAILER_BUFFSIZE; s4_t_lp_j++) {
			if (s4_t_lp_i < s4_t_lp_j) {
				if (	/* 中身が入っているかどうかの確認用 */
					(ast_a_copy_normal_trailer[s4_t_lp_i].fl_Robs != CFL_UNKNOWN_VALUE)
				 && (ast_a_copy_normal_trailer[s4_t_lp_j].fl_Robs != CFL_UNKNOWN_VALUE)
				) {
					fl_a_power_sum_1 = ast_a_copy_normal_trailer[s4_t_lp_i].fl_power_up + ast_a_copy_normal_trailer[s4_t_lp_i].fl_power_dn;
					fl_a_power_sum_2 = ast_a_copy_normal_trailer[s4_t_lp_j].fl_power_up + ast_a_copy_normal_trailer[s4_t_lp_j].fl_power_dn;

					if (fl_a_power_sum_1 < fl_a_power_sum_2) {
						ast_t_buf_normal[s4_t_lp_i] = ast_a_copy_normal_trailer[s4_t_lp_j];
						ast_t_buf_normal[s4_t_lp_j] = ast_a_copy_normal_trailer[s4_t_lp_i];
						ast_a_copy_normal_trailer[s4_t_lp_i] = ast_t_buf_normal[s4_t_lp_i];
						ast_a_copy_normal_trailer[s4_t_lp_j] = ast_t_buf_normal[s4_t_lp_j];
					}
				}
			}
		}
	}
#endif
	copy_trailer_data(ast_a_copy_normal_trailer, ast_a_normal_trailer, TRAILER_BUFFSIZE);

	return;
}

/********************************************************************************************/
/*!
	@brief
	copy specified number of normal data from arg1 to arg2

	@return void

	@detail
*********************************************************************************************/
VD copy_trailer_data(
	const NORMAL_BSM *normal_in,				/* [in] */
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
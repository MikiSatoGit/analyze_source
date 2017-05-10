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


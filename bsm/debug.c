VD fn_btt_aaz_activate()
{
	/*! @note (1) set AAZ state to ACTIVE if AAZ is ENABLE */
	if( st_g_btt_stat.AAZ == BTT_RET_t.Func_Stat.ENABLE )
	{
		st_g_btt_stat.AAZ = BTT_RET_t.Func_Stat.ACTIVE;

		/* Based on RDD:Table.4.2.6.1-1 */
		/*! @note (2) initialize AAZ internal parameters to initial value */
		st_aaz_params.VarY = (FL) 0.0;
		st_aaz_params.First = BTT_RET_t.Bool.TRUE;
		st_aaz_params.TLength_AAZ = BTT_TRAILER_SIZE_UNKNOWN;
		st_aaz_params.TLength_valid_count = (S4) 0;
		st_aaz_params.TLength_invalid_count = (S4) 0;
		st_aaz_params.TLength_unknown_count = (S4) 0;
		st_aaz_params.TWidth_AAZ = BTT_TRAILER_SIZE_UNKNOWN;
		st_aaz_params.TWidth_valid_count = (S4) 0;
		st_aaz_params.TWidth_invalid_count = (S4) 0;
		st_aaz_params.TWidth_unknown_count = (S4) 0;
	}
	return;
}



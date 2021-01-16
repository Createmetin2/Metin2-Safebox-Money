//Find
	Set(HEADER_CG_SAFEBOX_CHECKIN, sizeof(TPacketCGSafeboxCheckin), "SafeboxCheckin", true);
	
///Add
#if defined(__BL_SAFEBOX_MONEY__)
	Set(HEADER_CG_SAFEBOX_MONEY, sizeof(TPacketCGSafeboxMoney), "SafeboxMoney", true);
#endif
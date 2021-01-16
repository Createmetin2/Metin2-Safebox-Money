//Find
	HEADER_CG_MESSENGER				= 67,
	
///Add
#if defined(__BL_SAFEBOX_MONEY__)
	HEADER_CG_SAFEBOX_MONEY			= 68,
#endif

//Find
	HEADER_GC_PARTY_PARAMETER			= 83,
	
///Add
#if defined(__BL_SAFEBOX_MONEY__)
	HEADER_GC_SAFEBOX_MONEY_CHANGE	= 84,
#endif

//Find in typedef struct command_safebox_money
	long		lMoney;
	
///Change
#if defined(__BL_SAFEBOX_MONEY__)
	DWORD		lMoney;
#else
	long		lMoney;
#endif

//Find in typedef struct packet_safebox_money_change
	long	lMoney;
	
///Change
#if defined(__BL_SAFEBOX_MONEY__)
	DWORD	lMoney;
#else
	long	lMoney;
#endif
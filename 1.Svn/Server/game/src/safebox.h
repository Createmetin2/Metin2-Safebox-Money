//Find
	bool			IsValidPosition(DWORD dwPos);
	
///Add
#if defined(__BL_SAFEBOX_MONEY__)
	DWORD			GetSafeboxMoney() const;
	void			SetSafeboxMoney(DWORD dGold);
#endif

//Find
	long		m_lGold;
	
///Change
#if defined(__BL_SAFEBOX_MONEY__)
	DWORD		m_lGold;
#else
	long		m_lGold;
#endif
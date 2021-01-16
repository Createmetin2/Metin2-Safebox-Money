//Find
	memset(m_pkItems, 0, sizeof(m_pkItems));
	
///Add
#if defined(__BL_SAFEBOX_MONEY__)
	SetSafeboxMoney(m_lGold); // Packet
#endif

//Find
void CSafebox::ChangeSize(int iSize)
{
	...
}

///Add
#if defined(__BL_SAFEBOX_MONEY__)
DWORD CSafebox::GetSafeboxMoney() const
{ 
	return m_lGold; 
}
void CSafebox::SetSafeboxMoney(DWORD dGold) 
{ 
	m_lGold = dGold;
	if (!m_pkChrOwner || !m_pkChrOwner->GetDesc())
		return;

	TPacketGCSafeboxMoneyChange pMoney;
	pMoney.bHeader = HEADER_GC_SAFEBOX_MONEY_CHANGE;
	pMoney.lMoney = m_lGold;
	m_pkChrOwner->GetDesc()->Packet(&pMoney, sizeof(TPacketGCSafeboxMoneyChange));
}
#endif
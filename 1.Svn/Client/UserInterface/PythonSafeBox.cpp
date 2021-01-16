//Find in void CPythonSafeBox::OpenSafeBox(int iSize)
	m_dwMoney = 0;
	
///Change
#if !defined(__BL_SAFEBOX_MONEY__)
	m_dwMoney = 0;
#endif
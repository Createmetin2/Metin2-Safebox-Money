//Find
bool CPythonNetworkStream::SendSafeBoxMoneyPacket(BYTE byState, DWORD dwMoney)
{
	...
}

///Change
bool CPythonNetworkStream::SendSafeBoxMoneyPacket(BYTE byState, DWORD dwMoney)
{
#if defined(__BL_SAFEBOX_MONEY__)
	TPacketCGSafeboxMoney kSafeboxMoney;
	kSafeboxMoney.bHeader = HEADER_CG_SAFEBOX_MONEY;
	kSafeboxMoney.bState = byState;
	kSafeboxMoney.dwMoney = dwMoney;
	if (!Send(sizeof(kSafeboxMoney), &kSafeboxMoney))
		return false;

	return SendSequence();
#else
	assert(!"CPythonNetworkStream::SendSafeBoxMoneyPacket - 사용하지 않는 함수");
	return false;
#endif
}
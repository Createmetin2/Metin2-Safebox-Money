//Find
void CInputMain::SafeboxItemMove(LPCHARACTER ch, const char * data)
{
	...
}

///Add
#if defined(__BL_SAFEBOX_MONEY__)
void CInputMain::SafeboxMoney(LPCHARACTER ch, const char* data)
{
	const TPacketCGSafeboxMoney* p = reinterpret_cast<const TPacketCGSafeboxMoney*>(data);

	if (!ch->CanHandleItem())
		return;

	CSafebox* pSafebox = ch->GetMall();
	if (pSafebox)
		return;

	pSafebox = ch->GetSafebox();
	if (!pSafebox)
		return;

	if (p->lMoney < 1 || p->lMoney >= GOLD_MAX)
		return;
	
	switch (p->bState)
	{
	case SAFEBOX_MONEY_STATE_SAVE:
		if (ch->GetGold() < static_cast<int>(p->lMoney))
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough gold.");
			return;
		}
		if (pSafebox->GetSafeboxMoney() + p->lMoney >= GOLD_MAX)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You cannot deposit anymore gold.");
			return;
		}
		pSafebox->SetSafeboxMoney(pSafebox->GetSafeboxMoney() + p->lMoney);
		ch->PointChange(POINT_GOLD, -static_cast<int>(p->lMoney));
		break;

	case SAFEBOX_MONEY_STATE_WITHDRAW:
		if (pSafebox->GetSafeboxMoney() < p->lMoney)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You don't have enough gold.");
			return;
		}
		if (ch->GetGold() + static_cast<int>(p->lMoney) >= GOLD_MAX)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "You cannot withdraw anymore gold.");
			return;
		}
		pSafebox->SetSafeboxMoney(pSafebox->GetSafeboxMoney() - p->lMoney);
		ch->PointChange(POINT_GOLD, static_cast<int>(p->lMoney));
		break;
	}
}
#endif

//Find
		case HEADER_CG_SAFEBOX_ITEM_MOVE:
			SafeboxItemMove(ch, c_pData);
			break;
			
///Add
#if defined(__BL_SAFEBOX_MONEY__)
		case HEADER_CG_SAFEBOX_MONEY:
			SafeboxMoney(ch, c_pData);
			break;
#endif
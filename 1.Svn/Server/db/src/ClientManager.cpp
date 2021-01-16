//Find
		"SELECT account_id, size, password FROM safebox%s WHERE account_id=%u",
		
///Change
#if defined(__BL_SAFEBOX_MONEY__)
		"SELECT account_id, size, password, gold FROM safebox%s WHERE account_id=%u",
#else
		"SELECT account_id, size, password FROM safebox%s WHERE account_id=%u",
#endif

//Find
			if (!row[0])
				pSafebox->dwID = 0;
			else
				str_to_number(pSafebox->dwID, row[0]);
				
///Add
#if defined(__BL_SAFEBOX_MONEY__)
			pSafebox->dwGold = (row[3] && pi->ip[0] == 0) ? atol(row[3]) : 0;
#endif
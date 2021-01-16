#Find
		dlgPickMoney.Hide()
		
#Add
		if app.__BL_SAFEBOX_MONEY__:
			dlgPickMoney.SetMax(9)
			self.wndMoney = self.GetChild("Money")
			self.wndMoneySlot = self.GetChild("Money_Slot")
			self.wndMoneySlot.SetEvent(ui.__mem_func__(self.OpenPickMoneyDialog))
			
#Find
		wnd_height = 130 + 32 * size
		
#Add
		if app.__BL_SAFEBOX_MONEY__:
			wnd_height += 20
			
#Find
	def RefreshSafeboxMoney(self):
		...
	
#Change
	def RefreshSafeboxMoney(self):
		if app.__BL_SAFEBOX_MONEY__:
			self.wndMoney.SetText(str(safebox.GetMoney()))
		else:
			pass
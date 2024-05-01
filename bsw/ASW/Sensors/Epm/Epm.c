volatile uint16 EngNmotLimitTh_Rpm_P = 6800;
volatile uint16 EngNmotLimitHys_P = 300;

void EngNmax(void)
{
	uint16 rpm = Get_Eng_Nmot_Rpm();
	boolean limh = Get_Eng_bNmotLimH();
	boolean new_lim;
	if (limh == STD_ACTIVE)
	{
		if (rpm < (EngNmotLimitTh_Rpm_P - EngNmotLimitHys_P))
		{
			new_lim = STD_IDLE;
		}
		else
		{
			new_lim = STD_ACTIVE;
		}
	}
	else
	{
		if (rpm > EngNmotLimitTh_Rpm_P)
		{
			new_lim = STD_ACTIVE;
		}
		else
		{
			new_lim = STD_IDLE;
		}
	}
	Set_Ign_bOffNMax(new_lim);
	Set_Inj_bOffNMax(new_lim);
	Set_Eng_bNmotLimH(new_lim);
}
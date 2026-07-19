class ActionLowerVisor : ActionMVSAltynVisorBase
{
	void ActionLowerVisor()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_SourcePrefix = "MVS_Altyn_Visor_Lifted_";
		m_ResultPrefix = "MVS_Altyn_Visor_";
	}

	override string GetText()
	{
		return "Lower Visor";
	}
};

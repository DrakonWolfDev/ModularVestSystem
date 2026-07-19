class ActionLiftVisor : ActionMVSAltynVisorBase
{
	void ActionLiftVisor()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_PICKUP_HANDS;
		m_SourcePrefix = "MVS_Altyn_Visor_";
		m_ResultPrefix = "MVS_Altyn_Visor_Lifted_";
	}

	override string GetText()
	{
		return "Lift Visor";
	}
};

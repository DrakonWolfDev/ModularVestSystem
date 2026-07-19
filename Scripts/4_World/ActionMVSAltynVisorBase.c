class ActionMVSAltynVisorBase : ActionSingleUseBase
{
	protected string m_SourcePrefix;
	protected string m_ResultPrefix;

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!player)
		{
			return false;
		}

		string resultType;
		return GetVisorResultType(item, resultType);
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		if (!action_data)
		{
			return false;
		}

		return ActionCondition(action_data.m_Player, action_data.m_Target, action_data.m_MainItem);
	}

	override void OnExecuteClient(ActionData action_data)
	{
		ClearMVSInventoryReservation(action_data);
	}

	override void OnExecuteServer(ActionData action_data)
	{
		if (!action_data || !action_data.m_Player)
		{
			return;
		}

		if (!GetGame().IsMultiplayer())
		{
			ClearMVSInventoryReservation(action_data);
		}

		string resultType;
		ItemBase oldItem = action_data.m_MainItem;
		if (!GetVisorResultType(oldItem, resultType))
		{
			return;
		}

		TurnItemIntoItemLambda lambda = new TurnItemIntoItemLambda(oldItem, resultType, action_data.m_Player);
		lambda.SetTransferParams(true, true, true);
		action_data.m_Player.ServerReplaceItemInHandsWithNew(lambda);
	}

	protected void ClearMVSInventoryReservation(ActionData action_data)
	{
		if (!action_data || !action_data.m_Player)
		{
			return;
		}

		ClearInventoryReservationEx(action_data);
	}

	protected bool GetVisorResultType(ItemBase item, out string resultType)
	{
		resultType = "";

		if (!item || item.IsDamageDestroyed())
		{
			return false;
		}

		if (m_SourcePrefix == "" || m_ResultPrefix == "")
		{
			return false;
		}

		if (!item.ConfigIsExisting("color"))
		{
			return false;
		}

		string color = item.ConfigGetString("color");
		if (!IsSupportedVisorColor(color))
		{
			return false;
		}

		if (item.GetType() != m_SourcePrefix + color)
		{
			return false;
		}

		resultType = m_ResultPrefix + color;
		return GetGame().ConfigIsExisting(CFG_VEHICLESPATH + " " + resultType);
	}

	protected bool IsSupportedVisorColor(string color)
	{
		return color == "OD" || color == "Tan" || color == "Black";
	}
};

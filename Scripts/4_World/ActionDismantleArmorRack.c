class ActionDismantleArmorRackCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_DECRAFT);
	}
};

class ActionDismantleArmorRack : ActionContinuousBase
{
	void ActionDismantleArmorRack()
	{
		m_CallbackClass = ActionDismantleArmorRackCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
		m_Text = "Dismantle armor rack";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTObject(UAMaxDistances.DEFAULT);
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!player || !target || !item || !item.IsKindOf("Screwdriver"))
		{
			return false;
		}

		Armor_Rack armorRack = GetArmorRack(target);
		if (!armorRack)
		{
			return false;
		}

		return IsArmorRackEmpty(armorRack);
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data || !action_data.m_Target || !action_data.m_MainItem)
		{
			return;
		}

		Armor_Rack armorRack = GetArmorRack(action_data.m_Target);
		if (!armorRack || !IsArmorRackEmpty(armorRack))
		{
			return;
		}

		EntityAI kit = EntityAI.Cast(GetGame().CreateObjectEx("ArmorRack_Kit", armorRack.GetPosition(), ECE_PLACE_ON_SURFACE));
		if (!kit)
		{
			ErrorEx("MVS: Failed to create ArmorRack_Kit while dismantling Armor_Rack");
			return;
		}

		kit.SetOrientation(armorRack.GetOrientation());
		action_data.m_MainItem.DecreaseHealth(UADamageApplied.DISMANTLE, false);
		GetGame().ObjectDelete(armorRack);
	}

	protected Armor_Rack GetArmorRack(ActionTarget target)
	{
		if (!target)
		{
			return null;
		}

		Armor_Rack armorRack = Armor_Rack.Cast(target.GetObject());
		if (armorRack)
		{
			return armorRack;
		}

		return Armor_Rack.Cast(target.GetParent());
	}

	protected bool IsArmorRackEmpty(Armor_Rack armorRack)
	{
		if (!armorRack)
		{
			return false;
		}

		if (!armorRack.GetInventory())
		{
			return true;
		}

		return armorRack.GetInventory().AttachmentCount() == 0 && armorRack.GetInventory().CountInventory() <= 1;
	}
};

modded class Screwdriver
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionDismantleArmorRack);
	}
};

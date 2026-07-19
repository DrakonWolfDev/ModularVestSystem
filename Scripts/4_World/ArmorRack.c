class ArmorRack_Kit : ItemBase
{
	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		if (!GetGame().IsServer())
			return;

		Armor_Rack armorRack = Armor_Rack.Cast(GetGame().CreateObjectEx("Armor_Rack", position, ECE_PLACE_ON_SURFACE));
		if (!armorRack)
		{
			ErrorEx("MVS: Failed to create Armor_Rack during kit placement");
			return;
		}

		armorRack.SetPosition(position);
		armorRack.SetOrientation(orientation);
		HideAllSelections();
	}
	
	override bool IsBasebuildingKit()
	{
		return true;
	}

	override bool IsDeployable()
	{
		return true;
	}

	override string GetPlaceSoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
};

class Armor_Rack : ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionDismantleArmorRack);
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}
};

class ArmorRack_Holo : Armor_Rack
{
};

class CfgPatches
{
	class ModularVestSystem_Compat_VanillaSlots
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Gear_Consumables",
			"DZ_Gear_Medical",
			"DZ_Gear_Tools",
			"ModularVestSystem"
		};
	};
};
class cfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Lockpick: Inventory_Base
	{
		inventorySlot[] += {"MVS_Lockpick"};
	};
	class Screwdriver: Inventory_Base
	{
		inventorySlot[] += {"Screwdriver1", "Screwdriver2"};
	};
	class Pliers: Inventory_Base
	{
		inventorySlot[] += {"Pliers1"};
	};
	class Morphine: Container_Base
	{
		inventorySlot[] += {"morphine", "epinephrine"};
	};
	class Battery9V: Inventory_Base
	{
		inventorySlot[] += {"MVSBattery1", "MVSBattery2"};
	};
	class Epinephrine: Container_Base
	{
		inventorySlot[] += {"epinephrine", "morphine"};
	};
	class BandageDressing: Inventory_Base
	{
		inventorySlot[] += {"MedicalBandage"};
	};
};

modded class PlayerBase
{
	override void Init()
	{
		super.Init();

		if (GetGame().IsDedicatedServer())
		{
			return;
		}

		DayzPlayerItemBehaviorCfg twoHanded = new DayzPlayerItemBehaviorCfg;
		twoHanded.SetTwoHanded();

		GetDayZPlayerType().AddItemInHandsProfileIK("MVS_Pack_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/mountain_g.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("MVS_WeaponBag_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/assault_g.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("MVS_WeaponBag_D_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/assault_g.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("MVS_RifleBag_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/assault_g.anm");
		GetDayZPlayerType().AddItemInHandsProfileIK("MVS_RifleBag_Diagonal_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_2h_extinguisher.asi", twoHanded, "dz/anims/anm/player/ik/two_handed/assault_g.anm");
	}
};

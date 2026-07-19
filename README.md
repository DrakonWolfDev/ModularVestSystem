# Modular Vest System

A maintained and modernized source release of the original **Modular Vest System** mod for DayZ.

This repository preserves the familiar MVS equipment system while repairing outdated scripts and configuration, improving Linux server compatibility, and bringing the mod forward for the DayZ PC Stable `1.29.163047` baseline.

## Current status

- Pre-1.0 stabilization release, currently around `v0.7`
- Targeting DayZ PC Stable `1.29.163047`
- Intended for source review, server packing, and continued development
- Existing public MVS classnames and asset paths are preserved wherever possible
- Broader persistence and runtime testing is still ongoing

## Included content

MVS provides a large collection of modular military equipment, including:

- Modular vests, chest rigs, belts, pouches, and packs
- Armor racks with deploy, storage, and safe dismantling behaviour
- Helmets, Altyn visor variants, radios, canteens, patches, and accessories
- Weapon-bag and rifle-bag variants with dedicated weapon attachment slots
- Player-facing attachment slot names and cleaned item descriptions

The stabilization work deliberately keeps the established MVS layout and balance familiar to existing players rather than redesigning the mod from scratch.

## Modernization and fixes

This version includes extensive maintenance of the original source, including:

- Updated armor-rack placement for the modern DayZ base-building kit lifecycle
- Safe screwdriver dismantling that requires racks to be empty
- Fixed recipe indices, null checks, visor replacement logic, and pack IK registration
- Restored complete custom canteen behaviour
- Corrected case-sensitive model, texture, material, and script paths for Linux servers
- Removed obsolete global overrides and unused template code
- Expanded static audits for config classes, attachment slots, proxies, recipes, paths, and addon dependencies
- Removed the base addon's DayZ Expansion-specific 40 mm patch from the vanilla baseline

See [`CHANGELOG.md`](CHANGELOG.md) for the detailed stabilization history.

## Requirements and compatibility

- Built against vanilla DayZ PC Stable `1.29.163047`
- The base addon does not require DayZ Expansion
- Existing MVS classnames are retained where possible for trader, types, and server configuration compatibility
- Some legacy MVS attachment behaviour depends on vanilla item slot bridges

The separately packable [`compat/VanillaSlotCompat`](compat/VanillaSlotCompat) addon contains those legacy vanilla slot bridges. Server owners should include it where existing MVS attachment layouts require them.

Because MVS touches a broad range of equipment and attachment slots, test it alongside other clothing, inventory, and slot-heavy mods before deploying it to a live server.

## Packing

The repository contains unpacked DayZ mod source rather than a ready-to-load Workshop package.

1. Mount the DayZ Tools work drive.
2. Place the source beneath the configured source prefix using the stable `ModularVestSystem` addon prefix.
3. Regenerate `texHeaders.bin` with DayZ Tools before a release build.
4. Pack the base addon with Addon Builder or Workbench.
5. Pack `compat/VanillaSlotCompat` separately when its legacy slot bridges are required.
6. Sign and deploy the resulting PBOs using your normal server workflow.

Do not publish local signing keys, generated PBOs, build output, or runtime logs back into the source repository.

## Server configuration

Existing MVS classnames can be used in `types.xml`, trader files, loadouts, events, and other server-side configuration.

When updating an established server:

- Keep a backup of the current packed mod and persistence data
- Compare any custom trader or economy files against the retained public classnames
- Smoke-test representative vests, pouches, bags, visors, canteens, and armor racks
- Confirm attachment visibility and inventory behaviour with your complete server mod set
- Test persistence across at least one restart before live deployment

## Credits

- Original Modular Vest System created and released by **Count Orlok**
- Original Steam Workshop item: **Modular Vest System**, ID `1962144102`
- DayZ 1.29 modernization and current maintenance by **Andrew Hodgson / DrakonWolfDev**

The original Workshop FAQ allowed repacking, retexturing, and monetization. This repository preserves that permissive intent for the included packable source assets. See [`CREDITS.md`](CREDITS.md) for the full attribution and provenance notes.

## License

MIT License — free to use, modify, and redistribute with attribution.

Asset provenance is documented as far as currently available, but not every historical asset has a fully verified individual origin. Review [`CREDITS.md`](CREDITS.md) and the repository documentation before redistribution.
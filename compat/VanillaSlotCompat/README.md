# MVS Vanilla Slot Compatibility Addon

This COMPAT-001 addon source owns the seven broad vanilla item slot bridges that were removed from the base `ModularVestSystem` PBO.

Status: source migration complete. User-reported COMPAT-001 runtime validation passed on 2026-07-07 before the base-addon bridge removal; this compatibility PBO should now be tested with the current base addon.

## Packing Target

Pack this folder as its own PBO after packing the base addon:

```text
Addon source directory: compat\VanillaSlotCompat
Destination directory: @ModularVestSystem\Addons
Addon prefix: ModularVestSystem_Compat_VanillaSlots
```

Suggested packed filename:

```text
ModularVestSystem_Compat_VanillaSlots.pbo
```

Load it after the base `ModularVestSystem` PBO.

## Expected Behavior

The base addon no longer patches these vanilla classes directly. Loading this compatibility PBO alongside the base addon should preserve the old vanilla tool, medical, and battery attachment behavior for legacy MVS slots.

The compatibility config uses `inventorySlot[] += {...}` to append MVS-owned slots without replacing vanilla slots already present on the item. Future vanilla item slot bridges should use the same append pattern unless a full replacement is being deliberately tested.

The affected vanilla classes are:

- `Lockpick`
- `Screwdriver`
- `Pliers`
- `Morphine`
- `Battery9V`
- `Epinephrine`
- `BandageDressing`

## Smoke Test

With base plus this compatibility PBO loaded, test that:

- `Lockpick`, `Screwdriver`, and `Pliers` attach to the raid pouch slots.
- `Morphine`, `Epinephrine`, and `BandageDressing` attach to the medical pouch slots.
- `Battery9V` attaches to the relevant MVS battery slots.
- All affected items detach cleanly.
- Attached items survive reconnect and server restart.

Also test base without this compatibility PBO once so the expected degraded vanilla item attachment behavior is understood and documented.

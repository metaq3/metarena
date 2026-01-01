# Metarena

#### CPM + Freeze OSP-like mod

This is an attempt to create an open-source server mod for freeze-tag with variety of physics and support for OSP and OSP2 clients.

Based on:

- baseq3a from Cyrax: https://github.com/ec-/baseq3a
- Unlagged mod by Nail Toronto ( included in baseq3a )
- Open Source Defrag: https://github.com/OpenQuake3/defrag
- Freeze Tag: https://github.com/dbircsak/freeze-tag

Also huge thanks to OSP2 contributors, especially snems. You can check out their work: https://github.com/snems/OSP2

## What have been done

- Support for OSP clients
- Full OSP2-BE support
- Support for vanilla, CPM, Q1 and CQ3 physics
- Freeze tag with common OSP features

## Quick commands guide

```c
// Set movement style:
//   0 - CPM
//   1 - Vanilla quake 1
//   3 - Vanilla quake 3
//   6 - CQ3: Quake 3 with CPM doublejumps and rampjumps
set phy_movetype 0

// Starting armor
set g_startArmor 100

// Grappling hook. In this version it just gives you small speed boost
set g_grapple 0

// Lightning gun and railgun damage
set g_lgDamage 7
set g_rgDamage 90

// All weapons except BFG are available from the start
set g_wpflags 127

// Rocket launcher configuration
set phy_rocket_speed 1000
set phy_rocket_damage 100
set phy_rocket_splashDamage 100
set phy_rocket_splashRadius 120

// Players joining match mid-game will spawn frozen
set g_frozenLateJoin 1

// Frozen players will automatically unfreeze after 4 minutes
set g_unfreezeTime 240

// Disable features for OSP2-BE. Current list:
//    1 - Team wallhack
//    2 - Model sound
//    4 - Alt grenades
//    8 - Enemy lightning
//    16 - Mark teammate
//    32 - Alt shadow
//    64 - Alt blood
//    128 - Player outline
//    256 - Team indicator
//    512 - Damage counter
//    1024 - Fullbright
//
set be_disabledFeatures 0  // None are disabled
```

## Build

Currently build is only available for linux, with QVM and \*.so the only
supported targets.

### QVM

Go into `build/linux-qvm` folder and run in the terminal:

```bash
make
```

Soon, `pak8a.pk3` will appear in the same folder. This is
your mod.

### Native libraries

Go to `build/linux` and run in the terminal:

```bash
make
```

Result will appear in the build directory.

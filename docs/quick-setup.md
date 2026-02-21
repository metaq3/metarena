## Quick setup

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

// May grenades only react to explosions
set g_grenadeKnockbackness 6
set g_rocketKnockbackness 0
set g_plasmaKnockbackness 0

// Players joining match mid-game will spawn frozen
set g_frozenLateJoin 1

// Give penalty to the players, so they don't abuse
// suicide midfight
set g_lavaRespawnTime 10
set g_suicideRespawnTime 15

// Only for fun setting
set g_killerGhost 0

// Provides higher accuracy for lg and rg beams
set g_snapVectors 0

// Frozen players will automatically unfreeze after 4 minutes
set g_unfreezeTime 240

// Spawn filter for items. Current list:
//    1 - Bad item ( unused )
//    2 - Weapons
//    4 - Ammo
//    8 - Armor
//    16 - Health
//    32 - Powerups ( quad, battle suit, etc. )
//    64 - Holdables
//    128 - Persistant powerups ( used only in Team Arena )
//    256 - Team items ( red and blue flags )
// ------------------------------------------------------------
// 504 is default for freeze ( no powerups, weapons and ammo )
set g_spawnItems 504

// Spawn filter for powerups specifically. Current list:
//    1 - Null ( unused )
//    2 - Quad
//    4 - Battle suit
//    8 - Haste ( speed )
//    16 - Invisibility
//    32 - Regeneration
//    64 - Flight
//    128 - Red flag
//    256 - Blue flag
// ------------------------------------------------------------
// 508 is default for freeze ( no quad )
set g_spawnPowerups 508

// Weapon filter for end-game OSP stats. Current list:
//    1 - Null weapon ( unused )
//    2 - Gauntlet
//    4 - Machinegun
//    8 - Shotgun
//    16 - Grenade launcher
//    32 - Rocket launcher
//    64 - Lightning gun
//    128 - Railgun
//    256 - Plasmagun
//    512 - BFG
//    1024 - Grappling hook
// ------------------------------------------------------------
// 511 is default ( no bfg and grapple )
set g_weaponMask 511

// Limits for cl_maxPackets
set g_maxPacketsLowerBound 125
set g_maxPacketsUpperBound 125

// Limits for cl_timeNudge
set g_timeNudgeLowerBound -12
set g_timeNudgeUpperBound 20

// Allow pmove_fixed
set g_allowPmove 1

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
set be_disabledFeatures 0  // None are disabled
```

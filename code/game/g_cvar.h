#include "q_shared.h"
#ifdef EXTERN_G_CVAR
#define G_CVAR(vmCvar, cvarName, defaultString, cvarFlags, modificationCount,  \
               trackChange, teamShader)                                        \
  extern vmCvar_t vmCvar;
#endif

#ifdef DECLARE_G_CVAR
#define G_CVAR(vmCvar, cvarName, defaultString, cvarFlags, modificationCount,  \
               trackChange, teamShader)                                        \
  vmCvar_t vmCvar;
#endif

#ifdef G_CVAR_LIST
#define G_CVAR(vmCvar, cvarName, defaultString, cvarFlags, modificationCount,  \
               trackChange, teamShader)                                        \
  {&vmCvar,           cvarName,    defaultString, cvarFlags,                   \
   modificationCount, trackChange, teamShader},
#endif

// don't override the cheat state set by the system
G_CVAR(g_cheats, "sv_cheats", "", 0, 0, qfalse, qfalse)

// G_CVAR( g_restarted, "g_restarted", "0", CVAR_ROM, 0, qfalse, qfalse )
G_CVAR(g_mapname, "mapname", "", CVAR_SERVERINFO | CVAR_ROM, 0, qfalse, qfalse)
G_CVAR(sv_fps, "sv_fps", "30", CVAR_ARCHIVE, 0, qfalse, qfalse)

// latched vars
G_CVAR(g_dropWeapons, "g_dropWeapons", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)
// latched vars
G_CVAR(g_gametype, "g_gametype", "0",
       CVAR_SERVERINFO | CVAR_USERINFO | CVAR_LATCH, 0, qfalse, qfalse)
G_CVAR(g_grenadeKnockbackness, "g_grenadeKnockbackness", "6", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_rocketKnockbackness, "g_rocketKnockbackness", "0", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_plasmaKnockbackness, "g_plasmaKnockbackness", "0", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_dampOversync, "g_dampOversync", "1", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_oversyncNudge, "g_oversyncNudge", "10", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_unlagWeaponSync, "g_unlagWeaponSync", "1", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_maxPredictionNudge, "g_maxPredictionNudge", "200", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_killerGhost, "g_killerGhost", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_unfreezeTime, "g_unfreezeTime", "240", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_ctfUnfreezeTime, "g_ctfUnfreezeTime", "2000", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_tdmUnfreezeTime, "g_tdmUnfreezeTime", "3000", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_unfreezeRadius, "g_unfreezeRadius", "100", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_frozenlatejoin, "g_frozenLateJoin", "0", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_maxPacketsLowerBound, "g_maxPacketsLowerBound", "125", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_maxPacketsUpperBound, "g_maxPacketsUpperBound", "125", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_timeNudgeLowerBound, "g_timeNudgeLowerBound", "-12", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_timeNudgeUpperBound, "g_timeNudgeUpperBound", "20", CVAR_ARCHIVE, 0,
       qfalse, qfalse)
G_CVAR(g_allowPmove, "g_allowPmove", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_weaponMask, "g_weaponMask", "510", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(be_disabledFeatures, "be_disabledFeatures", "0", CVAR_ARCHIVE, 0, qfalse,
       qfalse)
//::OSDF modded
G_CVAR(phy_knockback, "phy_knockback", "1000", 0, 0, qtrue, qfalse)
// New variables
G_CVAR(phy_movetype, "phy_movetype", "0", CVAR_SYSTEMINFO, 0, qtrue, qfalse)
G_CVAR(g_startArmor, "g_startArmor", "100", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_grapple, "g_grapple", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_lgDamage, "g_lgDamage", "7", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_rgDamage, "g_rgDamage", "90", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_wpflags, "g_wpflags", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_weaponlimit, "weaponlimit", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_doReady, "g_doReady", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_votelimit, "g_votelimit", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(phy_rocket_speed, "phy_rocket_speed", "1000", CVAR_ARCHIVE, 0, qtrue,
       qfalse)
G_CVAR(phy_rocket_damage, "phy_rocket_damage", "100", CVAR_ARCHIVE, 0, qtrue,
       qfalse)
G_CVAR(phy_rocket_splashDamage, "phy_rocket_splashDamage", "100", CVAR_ARCHIVE,
       0, qtrue, qfalse)
G_CVAR(phy_rocket_splashRadius, "phy_rocket_splashRadius", "120", CVAR_ARCHIVE,
       0, qtrue, qfalse)
G_CVAR(phy_overbounce_scale, "phy_overbounce_scale", "1.001", CVAR_ARCHIVE, 0,
       qtrue,
       qfalse) // When active, changes the flow of the player movement
               // code towards osdf_ code. 1=enabled, 0=disabled

//::OSDF end
G_CVAR(g_maxclients, "sv_maxclients", "8",
       CVAR_SERVERINFO | CVAR_LATCH | CVAR_ARCHIVE, 0, qfalse,
       qfalse) // allow this many total, including spectators
G_CVAR(g_maxGameClients, "g_maxGameClients", "0",
       CVAR_SERVERINFO | CVAR_LATCH | CVAR_ARCHIVE, 0, qfalse,
       qfalse) // allow this many active

// change anytime vars
G_CVAR(g_dmflags, "dmflags", "0", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qtrue,
       qfalse)
G_CVAR(g_fraglimit, "fraglimit", "20",
       CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue, qfalse)
G_CVAR(g_timelimit, "timelimit", "0",
       CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue, qfalse)
G_CVAR(g_capturelimit, "capturelimit", "8",
       CVAR_SERVERINFO | CVAR_ARCHIVE | CVAR_NORESTART, 0, qtrue, qfalse)

G_CVAR(g_synchronousClients, "g_synchronousClients", "0", CVAR_SYSTEMINFO, 0,
       qfalse, qfalse)

G_CVAR(g_friendlyFire, "g_friendlyFire", "0", CVAR_ARCHIVE, 0, qtrue, qfalse)

G_CVAR(g_autoJoin, "g_autoJoin", "1", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_teamForceBalance, "g_teamForceBalance", "0", CVAR_ARCHIVE, 0, qfalse,
       qfalse)

G_CVAR(g_warmup, "g_warmup", "20", CVAR_ARCHIVE, 0, qtrue, qfalse)
G_CVAR(g_log, "g_log", "games.log", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_logSync, "g_logSync", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)

G_CVAR(g_password, "g_password", "", CVAR_USERINFO, 0, qfalse, qfalse)

G_CVAR(g_banIPs, "g_banIPs", "", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_filterBan, "g_filterBan", "1", CVAR_ARCHIVE, 0, qfalse, qfalse)

G_CVAR(g_needpass, "g_needpass", "0", CVAR_SERVERINFO | CVAR_ROM, 0, qfalse,
       qfalse)

G_CVAR(g_dedicated, "dedicated", "0", 0, 0, qfalse, qfalse)

G_CVAR(g_speed, "g_speed", "320", 0, 0, qtrue, qfalse)
G_CVAR(g_gravity, "g_gravity", "800", 0, 0, qtrue, qfalse)
G_CVAR(g_knockback, "g_knockback", "1000", 0, 0, qtrue, qfalse)
G_CVAR(g_quadfactor, "g_quadfactor", "3", 0, 0, qtrue, qfalse)
G_CVAR(g_weaponRespawn, "g_weaponrespawn", "5", 0, 0, qtrue, qfalse)
G_CVAR(g_weaponTeamRespawn, "g_weaponTeamRespawn", "30", 0, 0, qtrue, qfalse)
G_CVAR(g_forcerespawn, "g_forcerespawn", "1", 0, 0, qtrue, qfalse)
G_CVAR(g_inactivity, "g_inactivity", "0", 0, 0, qtrue, qfalse)
G_CVAR(g_debugMove, "g_debugMove", "0", 0, 0, qfalse, qfalse)
G_CVAR(g_debugDamage, "g_debugDamage", "0", 0, 0, qfalse, qfalse)
G_CVAR(g_debugAlloc, "g_debugAlloc", "0", 0, 0, qfalse, qfalse)
G_CVAR(g_motd, "g_motd", "", 0, 0, qfalse, qfalse)
G_CVAR(g_blood, "com_blood", "1", 0, 0, qfalse, qfalse)

G_CVAR(g_podiumDist, "g_podiumDist", "80", 0, 0, qfalse, qfalse)
G_CVAR(g_podiumDrop, "g_podiumDrop", "70", 0, 0, qfalse, qfalse)

G_CVAR(g_allowVote, "g_allowVote", "1", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_listEntity, "g_listEntity", "0", 0, 0, qfalse, qfalse)

G_CVAR(g_unlagged, "g_unlagged", "1", CVAR_SERVERINFO | CVAR_ARCHIVE, 0, qfalse,
       qfalse)
G_CVAR(g_predictPVS, "g_predictPVS", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_spawnItems, "g_spawnItems", "472", CVAR_ARCHIVE, 0, qfalse, qfalse)
G_CVAR(g_spawnPowerups, "g_spawnPowerups", "508", CVAR_ARCHIVE, 0, qfalse,
       qfalse)

#ifdef MISSIONPACK
G_CVAR(g_obeliskHealth, "g_obeliskHealth", "2500", 0, 0, qfalse, qfalse)
G_CVAR(g_obeliskRegenPeriod, "g_obeliskRegenPeriod", "1", 0, 0, qfalse, qfalse)
G_CVAR(g_obeliskRegenAmount, "g_obeliskRegenAmount", "15", 0, 0, qfalse, qfalse)
G_CVAR(g_obeliskRespawnDelay, "g_obeliskRespawnDelay", "10", CVAR_SERVERINFO, 0,
       qfalse, qfalse)

G_CVAR(g_cubeTimeout, "g_cubeTimeout", "30", 0, 0, qfalse, qfalse)
G_CVAR(g_redteam, "g_redteam", "Stroggs",
       CVAR_ARCHIVE | CVAR_SERVERINFO | CVAR_USERINFO, 0, qtrue, qtrue)
G_CVAR(g_blueteam, "g_blueteam", "Pagans",
       CVAR_ARCHIVE | CVAR_SERVERINFO | CVAR_USERINFO, 0, qtrue, qtrue)
G_CVAR(g_singlePlayer, "ui_singlePlayerActive", "", 0, 0, qfalse, qfalse)

G_CVAR(g_enableDust, "g_enableDust", "0", CVAR_SERVERINFO, 0, qtrue, qfalse)
G_CVAR(g_enableBreath, "g_enableBreath", "0", CVAR_SERVERINFO, 0, qtrue, qfalse)
G_CVAR(g_proxMineTimeout, "g_proxMineTimeout", "20000", 0, 0, qfalse, qfalse)
#endif
G_CVAR(g_smoothClients, "g_smoothClients", "1", 0, 0, qfalse, qfalse)
G_CVAR(pmove_fixed, "pmove_fixed", "0", CVAR_SYSTEMINFO, 0, qfalse, qfalse)
G_CVAR(pmove_msec, "pmove_msec", "8", CVAR_SYSTEMINFO, 0, qfalse, qfalse)

G_CVAR(g_rotation, "g_rotation", "0", CVAR_ARCHIVE, 0, qfalse, qfalse)

#undef G_CVAR

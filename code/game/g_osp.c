#include "bg_public.h"
#include "g_local.h"
#include "q_shared.h"
#include "g_osp.h"

void G_OSPFillUpStats( int clientNum, int armor, int health ) {
  gclient_t* client = &level.clients[clientNum];

  client->pers.stats[OSP_STATS_MAGIC] = 1;
  client->pers.stats[OSP_STATS_SCORE] = client->ps.persistant[PERS_SCORE];
  client->pers.stats[OSP_STATS_TEAM] = client->ps.persistant[PERS_TEAM];
  client->pers.stats[OSP_STATS_WINS] = level.teamScores[client->sess.sessionTeam] | (armor << 0x10);
  client->pers.stats[OSP_STATS_LOSSES] = client->sess.wins | (health << 0x10);
  client->pers.stats[OSP_STATS_CAPS] = 0;
  client->pers.stats[OSP_STATS_ASSIST] = client->ps.persistant[PERS_ASSIST_COUNT];
  client->pers.stats[OSP_STATS_DEFENCES] = client->ps.persistant[PERS_DEFEND_COUNT];
  client->pers.stats[OSP_STATS_RETURNS] = client->ps.persistant[PERS_SPAWN_COUNT];
  client->pers.stats[OSP_STATS_FLAG_TIME] = 0;
}

void G_OSPSendXStatsInfo( int clientNum, int receiver, int weaponMask ) {
  static char buffer[1024];
  char stats[1024];
  char weaponStats[1024];
  int i;
  int armor, health;
  gclient_t* client = &level.clients[clientNum];

  if ( client->sess.sessionTeam == TEAM_SPECTATOR ) {
    return;
  }

  armor = client->pers.stats[OSP_STATS_GA] * 5 + client->pers.stats[OSP_STATS_YA] * 50 + client->pers.stats[OSP_STATS_RA] * 100;
  health = client->pers.stats[OSP_STATS_MH] * 100;

  G_OSPFillUpStats( clientNum, armor, health );

  memset(buffer, 0, sizeof(buffer));
  memset(stats, 0, sizeof(stats));
  memset(weaponStats, 0, sizeof(weaponStats));

  // Copy weapon stats
  for ( i = 1; i < WP_NUM_WEAPONS; ++i ) {
    if ( !(weaponMask & (1 << i)) ) {
      continue;
    }

    BG_sprintf(
      buffer, "%s %i %i %i %i",
      weaponStats,
      client->pers.accuracies[i].hits,
      client->pers.accuracies[i].attacks + (client->pers.accuracies[i].pickups << 0x10),
      client->pers.accuracies[i].kills,
      client->pers.accuracies[i].deaths
    );
    strcpy(weaponStats, buffer);

    // Clear buffer
    memset(buffer, 0, sizeof(buffer));
  }

  BG_sprintf(
    stats,
    " %i %i %i %i %i %i %i %i",
    armor, health,
    client->pers.stats[OSP_STATS_DMG_GIVEN],
    client->pers.stats[OSP_STATS_DMG_RCVD],
    client->pers.stats[OSP_STATS_MH],
    client->pers.stats[OSP_STATS_GA],
    client->pers.stats[OSP_STATS_RA],
    client->pers.stats[OSP_STATS_YA]
  );

  Com_sprintf(
    buffer, sizeof(buffer),
    "xstats1 %i %i%s%s", clientNum, weaponMask, weaponStats, stats
  );

  trap_SendServerCommand( receiver, buffer );
}

qboolean IsStatisticallySignificant(int weapon, accuracy_t accuracy) {
  static int minHits[WP_MAX_WEAPONS];

  // Hide this weapons
  minHits[WP_NONE] = -1;
  minHits[WP_GAUNTLET] = -1;
  minHits[WP_MACHINEGUN] = -1;

  minHits[WP_SHOTGUN] = 20;
  minHits[WP_GRENADE_LAUNCHER] = 5;
  minHits[WP_ROCKET_LAUNCHER] = 10;
  minHits[WP_LIGHTNING] = 25;
  minHits[WP_RAILGUN] = 10;
  minHits[WP_PLASMAGUN] = 50;
  minHits[WP_BFG] = 20;

  if ( weapon < WP_BFG && minHits[weapon] != -1 && accuracy.attacks >= minHits[weapon] ) {
    return qtrue;
  }

  return qfalse;
}

void CalculateStats( gclient_t** bestWeaponStats ) {
  int i;
  int wp;
  gclient_t *client;
  float bestAccuracy;
  float ourAccuracy;

  for ( i = 0; i < WP_MAX_WEAPONS; ++i ) {
    bestWeaponStats[i] = NULL;
  }

  // Calculate stats

  for ( i = 0; i < MAX_CLIENTS; ++i ) {
    client = g_entities[i].client;

    if ( !client ) {
      continue;
    }

    for (wp = 0; wp < WP_MAX_WEAPONS; ++wp) {
      if ( !IsStatisticallySignificant(wp, client->pers.accuracies[wp]) ) {
        continue;
      }

      if (bestWeaponStats[wp] == NULL) {
        bestWeaponStats[wp] = client;
        continue;
      }

      bestAccuracy = (float)bestWeaponStats[wp]->pers.accuracies[wp].hits /
                     (float)bestWeaponStats[wp]->pers.accuracies[wp].attacks;
      ourAccuracy = (float)client->pers.accuracies[wp].hits /
                    (float)client->pers.accuracies[wp].attacks;

      if (ourAccuracy > bestAccuracy) {
        bestWeaponStats[wp] = client;
      }
    }
  }
}

void G_OSPSendBestStatsInfo( int weaponMask ) {
  static gclient_t* bestWeaponStats[WP_MAX_WEAPONS];
  char stats[1024];
  char weaponstat[1024];
  int wp = 0;
  int numWeapons = 0;

  CalculateStats( bestWeaponStats );

  for (wp = 1; wp < WP_NUM_WEAPONS; ++wp) {
    if ( !(weaponMask & wp) || bestWeaponStats[wp] == NULL ) {
      continue;
    }

    numWeapons++;

    weaponstat[0] = 0;

    BG_sprintf( weaponstat, "%i %i %i %i %i %i ",
      wp,
      bestWeaponStats[wp] - level.clients,
      bestWeaponStats[wp]->pers.accuracies[wp].hits,
      bestWeaponStats[wp]->pers.accuracies[wp].attacks,
      bestWeaponStats[wp]->pers.accuracies[wp].kills,
      bestWeaponStats[wp]->pers.accuracies[wp].deaths
    );

    strcat(stats, weaponstat);
  }

  strcat(stats, "0");

  G_BroadcastServerCommand( -1, va( "bstats %s", stats ) );
}

void G_OSPShowStatsInfo( int clientNum, int weaponMask ) {
  static char buffer[1024];
  char stats[1024];
  char weaponStats[1024];
  int i;
  int armor, health;
  gclient_t* client = &level.clients[clientNum];

  if ( client->sess.sessionTeam == TEAM_SPECTATOR ) {
    return;
  }

  armor = client->pers.stats[OSP_STATS_GA] * 5 + client->pers.stats[OSP_STATS_YA] * 50 + client->pers.stats[OSP_STATS_RA] * 100;
  health = client->pers.stats[OSP_STATS_MH] * 100;

  G_OSPFillUpStats( clientNum, armor, health );

  client->pers.stats[OSP_STATS_WEAPON_MASK] = weaponMask;

  memset(buffer, 0, sizeof(buffer));
  memset(stats, 0, sizeof(stats));
  memset(weaponStats, 0, sizeof(weaponStats));

  // Copy general stats
  for ( i = 0; i < OSP_STATS_NUM; ++i ) {
    BG_sprintf(
      buffer, "%s %i",
      stats,
      client->pers.stats[i]
    );
    strcpy(stats, buffer);

    // Clear buffer
    memset(buffer, 0, sizeof(buffer));
  }


  // Copy weapon stats
  for ( i = 1; i < WP_NUM_WEAPONS; ++i ) {
    if ( !(weaponMask & (1 << i)) ) {
      continue;
    }

    BG_sprintf(
      buffer, "%s %i %i %i %i",
      weaponStats,
      client->pers.accuracies[i].hits,
      client->pers.accuracies[i].attacks + (client->pers.accuracies[i].pickups << 0x10),
      client->pers.accuracies[i].kills,
      client->pers.accuracies[i].deaths
    );
    strcpy(weaponStats, buffer);

    // Clear buffer
    memset(buffer, 0, sizeof(buffer));
  }

  Com_sprintf(
    buffer, sizeof(buffer),
    "statsinfo%s%s", stats, weaponStats
  );

  Com_Printf("DEBUG: sent statsinfo to %s:\n%s\n", level.clients[clientNum].pers.netname, buffer);

  trap_SendServerCommand( clientNum, buffer );
}
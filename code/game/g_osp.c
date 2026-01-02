#include "bg_public.h"
#include "g_local.h"
#include "q_shared.h"
#include "g_osp.h"

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

  trap_SendServerCommand( clientNum, buffer );
}
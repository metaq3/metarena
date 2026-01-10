#include "g_local.h"
#include "g_predict.h"

int G_BoundClientTime(gclient_t *client) {
  if ( client->lastCmdTime > level.time ) {
    return level.time;
  }

  if ( client->lastCmdTime < level.time - g_maxPredictionNudge.integer ) {
    return level.time - g_maxPredictionNudge.integer;
  }

  return client->lastCmdTime;
}

/*
================
G_MarkAssumed

Marks entity as assumed to "exist" by predictor, so clients know that it's not real one.
Later, it can be confirmed with real one by calling G_LinkWithConfirmed, or canceled
by calling G_CancelAssume. If it lasts for too long, it's canceled automatically.

"Assumed" entities do not have an impact unless opposite specified.
================
*/

void G_MarkAssumed(gentity_t *ent, qboolean canImpact) {
  ent->lastSync = level.time;
  ent->assumed = qtrue;
  ent->canImpact = qfalse;
}

void G_LinkWithConfirmed(gentity_t *assumed, gentity_t *real) {
  if ( !assumed->inuse ) {
    return;
  }

  G_CancelAssume( assumed );
}

void G_CancelAssume(gentity_t *ent) {
  G_FreeEntity( ent );
}
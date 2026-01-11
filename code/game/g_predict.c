#include "g_local.h"
#include "g_predict.h"

int G_Clamp(int value, int min, int max) {
  if ( value < min ) {
    return min;
  }

  if ( value > max ) {
    return max;
  }

  return value;
}

int G_BoundClientTime(gclient_t *client) {
  if ( client->lastCmdTime > level.time ) {
    return level.time;
  }

  if ( client->lastCmdTime < level.time - g_maxPredictionNudge.integer ) {
    return level.time - g_maxPredictionNudge.integer;
  }

  return client->lastCmdTime;
}

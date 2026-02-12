#ifndef G_OSP_H
#define G_OSP_H

#include "bg_local.h"

void G_OSPShowStatsInfo(int clientNum, int weaponMask);
void G_OSPSendBestStatsInfo(int weaponMask);
void G_OSPSendXStatsInfo(int clientNum, int receiver, int weaponMask);

#endif
#ifndef G_PREDICT_H
#define G_PREDICT_H

int G_BoundClientTime(gclient_t *client);
void G_MarkAssumed(gentity_t *ent, qboolean canImpact);
void G_LinkWithConfirmed(gentity_t *assumed, gentity_t *real);
void G_CancelAssume(gentity_t *ent);

#endif
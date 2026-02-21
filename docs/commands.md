# Commands guide

### phy_movetype

> Default: 0

Controls movement style. Mod reads this value on every level start
and applies effects on physics.
Available values:

- 0 - CPM
- 1 - Vanilla quake 1
- 3 - Vanilla quake 3
- 6 - CQ3, Vanilla quake 3 with CPM doublejumps and rampjumps

---

## Weapons

### g_grapple

> Default: 0

Enables grappling hook. Current version of hook is different from vanilla
one, but for testing purposes only.

---

### g_lgDamage

> Default: 7

Lightning gun damage per hit. Vanilla Quake 3has 8 as default.

---

### g_rgDamage

> Default: 90

Railgun damage per hit. Vanilla Quake 3 has 100 as default.

---

### phy_rocket_speed

> Default: 1000

Rocket speed value. Vanilla Quake 3 has 900 as default, while CPM has 1000 as default.

---

### phy_rocket_damage

> Default: 100

Rocket damage from direct hit. Default is same as vanilla Quake 3.

---

### phy_rocket_splashDamage

> Default: 100

Rocket's splash damage. Default is same as vanilla Quake 3.

---

### phy_rocket_splashRadius

> Default: 120

Rocket's splash radius. Default is same as vanilla Quake 3.

---

### g_grenadeKnockbackness, g_rocketKnockbackness, g_plasmaKnockbackness

> Defaults:
> g_grenadeKnockbackness: 6
> g_rocketKnockbackness: 0
> g_plasmaKnockbackness: 0

Coefficient for knockback that projectile gets from explosions. Zero is treated as no knockback
( vanilla behaviour )

---

### g_snapVectors

> Default: 0

Controls quake vector snapping. When 1, all vectors are "snapped", or, simply speaking, they loose accuracy
to save bandwith. Turning this off may help LG and RG.

---

## Spawning conditions

### g_startArmor

> Default: 100

Controls spawning player's start armor.

---

### g_wpflags

> Default: 127

Weapons available at start. It's a bitset value, so you'll need to add up
numbers to combine effect.

List of weapon values:

- 1 - _Machinegun_
- 2 - _Shotgun_
- 4 - _Grenade launcher_
- 8 - _Rocket launcher_
- 16 - _Lightning gun_
- 32 - _Railgun_
- 64 - _Plasma gun_
- 128 - _BFG_

---

### g_frozenLateJoin

> Default: 0

When set to 1, players joining match mid-game will spawn frozen. From
OSP Freeze.

---

### g_lavaRespawnTime

> Default: 30

### g_suicideRespawnTime

> Default: 30

_In seconds ( fractional values supported )._

Players, who die through lava or suicide will get respawn penalty, making them unable
to automatically unfreeze during that period. Used to avoid intentional suicide during
midfight.

> [!IMPORTANT]
> Your teammates are still able to unfreeze you even
> with penalty time. In that case, respawning is not
> restricted.

> [!NOTE]
> Death because of `trigger_hurt` is considered a suicide.
> Some maps can use it for custom lava, so beware
> of that.

---

## Level settings

### g_spawnItems

> Default: 472

Bitset of items that are allowed to spawn on map.

List of item values:

- 1 - _Bad item ( unused )_
- 2 - _Weapons_
- 4 - _Ammo_
- 8 - _Armor_
- 16 - _Health_
- 32 - _Powerups ( quad, battle suit, etc. )_
- 64 - _Holdables_
- 128 - _Persistant powerups ( used only in Team Arena )_
- 256 - _Team items ( red and blue flags )_

> [!NOTE]
> For controlling powerup spawn more precisely, please, look for `g_spawnPowerups`

---

### g_spawnPowerups

> Default: 508

Bitset of powerups that are allowed to spawn on map. Has no effect,
when `g_spawnItems` prohibits powerup spawn.

List of powerup values:

- 1 - _Null ( unused )_
- 2 - _Quad_
- 4 - _Battle suit_
- 8 - _Haste ( speed )_
- 16 - _Invisibility_
- 32 - _Regeneration_
- 64 - _Flight_
- 128 - _Red flag_
- 256 - _Blue flag_

---

## Unlagged

### g_maxPredictionNudge

> Default: 200

Value in milliseconds.

Unlagged projectile weapon behaviour control ( grenade launcher, rocket launcher, plasmagun ). When set to something >0, server will try to match projectile's current position with position that client "should" currently see. Simply speaking, server takes into account client's attack time, and this setting limits how many msec can server "nudge".

When set to 0, no delag is applied.

---

### g_unlagWeaponSync

> Default: 1

Works best when `g_maxPredictionNudge` is greater 0. `g_maxPredictionNudge` only delags projectiles ( rockets, grenades and plasmas ), but `g_unlagWeaponSync` syncs state with client's time, effectively subtracting reload time
for the second shot to match client's view of things. This makes all consequent shots not being nudged as they're
synced.

> [!TIP]
> It's recommended to use this option with `g_dampOversync` set to 1 and `g_oversyncNudge` set to positive value around 10. This prevents users from benifiting exploits of this system.

---

### g_dampOversync

> Default: 1

For technical reasons, it's possible to attack at higher rate or fire through thick walls because of the way synchronization works and how quake deals with delayed packets. This happens because of snapshots covering huge time segment ( basically greater than `1000 / sv_fps` ), making synchronized earlier state be oversynchronized.

Oversync damping prevents benefiting and abusing such exploits, forcing player to wait that oversynced time, making:

- Rockets not spawning behind the player and thus not firing through walls
- Weapon not reloading so fast

> [!NOTE]
> All mentioned above things happen only with really lossy connections or
> players who set `com_maxfps` really low. It almost does not affect normal players.

Paired with `g_oversyncNudge`.

---

### g_oversyncNudge

> Default: 10

Oversynchronization threshold, when server starts to actually make something to prevent it. Also subtracted from oversync penalty.

Values below `50` fit best.

---

## Other player related settings

### g_unfreezeTime

> Default: 240

How long ( in seconds ) can players stay freezed without help of their teammates.

---

### g_killerGhost

> Default: 0

When on, a "ghost" is left behind the player, who just got the frag. It will stand for some long time and then
evade.

---

### g_maxPacketsLowerBound

> Default: 125

### g_maxPacketsUpperBound

> Default: 125

Limits `cl_maxPackets`. Helps to fight against network issues on
client side.

_Default value is recommended for comfortable play_

---

### g_maxPacketsLowerBound

> Default: -12

### g_maxPacketsUpperBound

> Default: 20

Limits `cl_timeNudge`.

---

### g_allowPmove

> Default: 1

Allow `pmove_fixed 1` for enhanced client sampling.

---

## Client-specific settings

### be_disabledFeatures

> Default: 0

Bitset of OSP2-BE features which should be restricted on your server.

Current list:

- _1 - Team wallhack_
- _2 - Model sound_
- _4 - Alt grenades_
- _8 - Enemy lightning_
- _16 - Mark teammate_
- _32 - Alt shadow_
- _64 - Alt blood_
- _128 - Player outline_
- _256 - Team indicator_
- _512 - Damage counter_
- _1024 - Fullbright_

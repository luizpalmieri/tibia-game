# Changes from Original Implementation

This document tracks custom features and modifications made to the game server.

## Build Configuration

### Tibia 7.72 by Default

The Makefile now always builds for Tibia client version 7.72 instead of 7.70.

**Files modified:**
- `Makefile` - Added `-DTIBIA772=1` to CFLAGS

---

## Configurable Rates

### Experience Rate (Staged)

Configurable experience multiplier that can be staged based on player level.

**Config syntax:**
```
# Simple fixed rate for all levels
experiencerate = 50

# Staged rates (min_level, max_level, rate) - 0 means no upper limit
experiencerate = (1, 50, 50)
experiencerate = (51, 100, 25)
experiencerate = (101, 200, 10)
experiencerate = (201, 0, 5)
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added `TRateStage` struct and extern declarations
- `src/config.cc` - Added parsing and initialization
- `src/crcombat.cc` - Applied rate in `DistributeExperiencePoints()`

---

### Loot Rate

Global multiplier for item drop probability. Capped at 100% (1000).

**Config syntax:**
```
lootrate = 2
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added extern declaration
- `src/config.cc` - Added parsing and initialization
- `src/crnonpl.cc` - Applied rate in monster loot generation

---

### Magic Rate

Multiplier for magic level training (mana spent = skill points gained).

**Config syntax:**
```
magicrate = 10
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added extern declaration
- `src/config.cc` - Added parsing and initialization
- `src/magic.cc` - Applied rate in `CheckMana()`

---

### Melee Rate

Multiplier for melee skill training (sword, axe, club, fist).

**Config syntax:**
```
meleerate = 10
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added extern declaration
- `src/config.cc` - Added parsing and initialization
- `src/crcombat.cc` - Applied rate in `GetAttackDamage()`

---

### Distance Rate

Multiplier for distance/ranged skill training.

**Config syntax:**
```
distancerate = 10
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added extern declaration
- `src/config.cc` - Added parsing and initialization
- `src/crcombat.cc` - Applied rate in `DistanceAttack()`

---

### Shielding Rate

Multiplier for shielding skill training.

**Config syntax:**
```
shieldingrate = 10
```

**Default:** `1` (normal rate)

**Files modified:**
- `src/config.hh` - Added extern declaration
- `src/config.cc` - Added parsing and initialization
- `src/crcombat.cc` - Applied rate in `GetDefendDamage()`

---

## Death Penalty Settings

### Experience/Skill Loss

Configurable percentage of experience and skill points lost on death.

**Config syntax:**
```
deathpenalty = 10
deathpenaltypromoted = 7
```

**Default:** `10` for non-promoted, `7` for promoted players

**Notes:**
- Blessings still reduce the loss by 1% each (up to 5 blessings)
- Set to `0` to disable exp/skill loss entirely

**Files modified:**
- `src/config.hh` - Added extern declarations
- `src/config.cc` - Added parsing and initialization
- `src/crplayer.cc` - Applied config in `TPlayer::Death()`

---

### Item Drop on Death

Configurable item drop chance and container behavior on death.

**Config syntax:**
```
itemdropchance = 10
dropcontainersondeath = true
```

**Default:** `itemdropchance = 10` (10% chance per item), `dropcontainersondeath = true`

**Notes:**
- `itemdropchance` is "1 in N" chance (10 = 10% chance to drop each non-container item)
- Set `itemdropchance = 0` to disable random item drops
- Set `dropcontainersondeath = false` to keep backpacks on death
- Amulet of Loss and KEEP_INVENTORY right still prevent all item loss
- Playerkiller flag still forces all items to drop

**Files modified:**
- `src/config.hh` - Added extern declarations
- `src/config.cc` - Added parsing and initialization
- `src/crmain.cc` - Applied config in `TCreature::~TCreature()`

#ifndef PAL_PLAYER_ACTION_HISTORY_H
#define PAL_PLAYER_ACTION_HISTORY_H

#include "common.h"

typedef struct {
    u8 pad000[0x370];
    s32 currentDuration;
    u8 pad374[0x25EC - 0x374];
    s32 primaryActions[8];
    s32 secondaryActions[8];
    s32 durations[8];
    s32 count;
} PlayerActionHistory;

static inline s32 player_action_history_has_action(const PlayerActionHistory *history, s32 id, s32 maxAge, s32 useSecondary)
{
    s32 i;
    s32 age = history->currentDuration;

    for (i = 0; i < history->count; i++) {
        if (maxAge < age)
            return 0;
        if ((useSecondary ? history->secondaryActions[i] : history->primaryActions[i]) == id)
            return 1;
        age = (s32)((u32)age + (u32)history->durations[i]);
    }
    return 0;
}

#endif

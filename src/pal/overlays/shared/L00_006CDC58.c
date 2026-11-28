#include "common.h"
#include "pal/player_action_history.h"

s32 func_L00_006CDC58(const PlayerActionHistory *history, s32 id, s32 maxAge)
{
    return player_action_history_has_action(history, id, maxAge, 0);
}

s32 func_L00_006CDCC0(const PlayerActionHistory *history, s32 id, s32 maxAge)
{
    return player_action_history_has_action(history, id, maxAge, 1);
}

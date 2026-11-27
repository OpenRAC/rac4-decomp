#include "common.h"
#include "pal/player_action_history.h"

s32 func_005224B0(const PlayerActionHistory *history, s32 id, s32 maxAge)
{
    return player_action_history_has_action(history, id, maxAge, 0);
}

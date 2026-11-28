#include "common.h"
#include "pal/profile_001721E0.h"
#include "pal/l00_roster_001E0DF8.h"

s32 func_L00_0077FF40(s32 index)
{
    const Type4 *profile = &D_001721E0;

    if (profile->slotState[index] == 0)
        return D_001E0DF8.team[index];
    return profile->slotTeams[index];
}

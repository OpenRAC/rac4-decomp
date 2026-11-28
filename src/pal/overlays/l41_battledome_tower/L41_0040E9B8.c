/* cflags: -G16 */
#include "common.h"
#include "pal/profile_001721E0.h"

s32 D_L41_00221398[4] = {0};

s32 func_L41_0040E9B8(s32 index)
{
    s32 *entry = &D_L41_00221398[index];
    u32 clock = D_001721E0.region20.words.f218;
    s32 time = *entry;

    s32 elapsed = (s32)(clock - (u32)time);
    if (time == 0 || elapsed >= 2001)
        return 0;
    return 1;
}

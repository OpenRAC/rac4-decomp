/* cflags: -O2 -G8 */
#include "common.h"
f32 func_L02_004C54D0(void *actor)
{
    void *state = *(void **)((u8 *)actor + 172);
    return 1.0f - (*(f32 *)((u8 *)state + 80) / (f32)*(s32 *)((u8 *)state + 84));
}

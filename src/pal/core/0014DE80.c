/* cflags: -O2 -G8 -Wa,-G0 -Wuninitialized */
#include "common.h"

/* Test the two descriptor states and the input threshold. */
s32 func_0014DE80(void *record, s16 state_id, f32 value)
{
    s32 result;
    s8 state;

    state = *(s8 *)((u8 *)record + 0x14);
    result = 0;
    if (state == 1 && state_id == state &&
        *(s8 *)((u8 *)record + 0x15) == state_id && value >= 0.45f) {
        result = 1;
    }
    return result;
}

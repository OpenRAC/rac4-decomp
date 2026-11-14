#include "common.h"

typedef struct Detector Detector;

/* Updates the wrapped counter and its confirmation byte from ordered float tests. */
void func_0014DA78(s16 mode, Detector *state, f32 threshold, f32 level)
{
    f32 adjusted;
    f32 value;
    u32 count;

    if (*(s8 *)((u8 *)state + 0x13) != 0) {
        adjusted = level - 56.666668f;
        value = (f32)mode - 42.5f;
        if (value <= adjusted)
            value = adjusted;
        if (value <= threshold) {
            count = *(u16 *)((u8 *)state + 0xE) + 1;
            *(u16 *)((u8 *)state + 0xE) = (u16)count;
            if ((s16)count >= 2) {
                *(s8 *)((u8 *)state + 0x14) = 1;
                *(u16 *)((u8 *)state + 0xE) = 1;
                return;
            }
            *(s8 *)((u8 *)state + 0x14) = 0;
            return;
        }
    }
    *(u16 *)((u8 *)state + 0xE) = 0;
    *(s8 *)((u8 *)state + 0x14) = 0;
}

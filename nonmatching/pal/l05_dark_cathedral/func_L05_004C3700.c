/* Not matching yet on PAL: 14/17 positional words match (82.35%); 3 words differ, size 68/68 bytes (delta 0). */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
/* Relocation fields are masked.
 * Reproduce: tools/check_func.py --version pal func_L05_004C3700 nonmatching/pal/l05_dark_cathedral/func_L05_004C3700.c --diff
 * Store order differs; argument and object layouts remain inferred. */
#include "common.h"

s32 func_L05_004C3700(void *arg0, s32 arg1, s32 arg2)
{
    int value;
    void *state;

    state = *(void **)((u8 *)arg0 + 0xAC);
    if (*(s32 *)((u8 *)state + 0x20) != 0) {
        return 0;
    }
    value = 0xFF;
    *(s8 *)((u8 *)arg0 + 0x30) = value;
    *(s32 *)((u8 *)state + 0x20) = arg1;
    *(s32 *)((u8 *)state + 0x24) = arg2;
    *(s8 *)((u8 *)state + 0x2C) = 1;
    *(s8 *)((u8 *)state + 0x2E) = 0;
    *(s32 *)((u8 *)state + 0x28) = (*(s8 *)((u8 *)state + 0x2D) = 0);
    *(s8 *)((u8 *)state + 0x18) = 0;
    return 1;
}

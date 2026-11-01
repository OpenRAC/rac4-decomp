#include "common.h"

void func_004E2A78(void *object)
{
    u8 *mode = (u8 *)object + 0x10;
    if (*mode == 7) {
        *(u32 *)((u8 *)object + 0x1C) = 0;
        *(u32 *)((u8 *)object + 0x40) = 0;
        *mode = 0;
    } else if (*mode != 0 && *mode != 6) {
        *mode = 4;
    }
}

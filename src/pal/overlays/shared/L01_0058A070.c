/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern u8 D_00269FC0[];

/* Clear the two trailing fields in each of two records. */
void func_L01_0058A070(void)
{
    u8 *record = D_00269FC0;

    do {
        *(s32 *)(record + 0x104) = 0;
        *(s32 *)(record + 0x100) = 0;
        record += 0x110;
    } while ((s32)record < (s32)(D_00269FC0 + 0x220));
}

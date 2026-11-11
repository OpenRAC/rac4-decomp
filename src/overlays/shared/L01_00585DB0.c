/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

extern u8 D_00269EC0[];

void func_L01_00585DB0(void)
{
    u8 *record = D_00269EC0;

    do {
        *(s32 *)(record + 0x104) = 0;
        *(s32 *)(record + 0x100) = 0;
        record += 0x110;
    } while ((s32)record < (s32)(D_00269EC0 + 0x220));
}

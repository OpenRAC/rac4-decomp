#include "common.h"

extern s32 D_003284A0[][4];
extern s32 D_0021EE54;

s32 *func_0046DD08(s32 arg0, s32 arg1, s32 arg2);

void func_004EF188(void)
{
    s32 i;
    s32 j;
    s32 object;
    s32 *entry;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 4; j++) {
            object = D_003284A0[i][j];
            if (object != 0) {
                *(s32 *)(object + 0x98) = 0;
            }
        }
    }
    if (D_0021EE54 == 0) {
        entry = func_0046DD08(0x263B, 0, 0xC);
        if (entry != 0 && entry[1] != 0) {
            ((void (*)(void))entry[1])();
        }
    }
    if (D_0021EE54 == 1) {
        entry = func_0046DD08(0x265B, 0, 0x14);
        if (entry != 0 && entry[4] != 0) {
            ((void (*)(s32))entry[4])(-1);
        }
    }
}

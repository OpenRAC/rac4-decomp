#include "common.h"

extern s32 func_0046AAC0(s32 arg0, s32 arg1);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AA58(s32 arg0);
extern s32 func_0054AAD8(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);
extern u8 D_001F87F0[];

s32 func_004C0CD0(s32 arg0)
{
    s32 i = 0;
    s32 count = 0;
    s32 n = func_0054AA58(func_0054AAD8(arg0));

    for (; i < n; i++) {
        if (*(s32 *)((char *)func_0054A998(func_0054AB08(arg0, i)) + 0x14) == 1) {
            if (func_0046AAC0(arg0, i)) {
                if (D_001F87F0[((arg0 - 1) % 20) * 0x304 + i * 12 + 9]) {
                    count++;
                }
            }
        }
    }
    return count;
}

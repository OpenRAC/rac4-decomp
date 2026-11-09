#include "common.h"

extern s32 func_0011D9A8(void *, const char *, ...);
extern u8 D_004C1808[];
void func_L00_00775C40(s32 unused0, u8 *arg1, s32 unused2, u8 *arg3) {
    u32 a;
    u32 b;
    s32 v;
    (void)unused0;
    (void)unused2;
    if (arg1 != 0) {
        if ((func_0011D9A8(arg1, (const char *)D_004C1808, &a, &b) ^ 2) == 0 && b < 2 &&
            (*((u8 *)arg3 + 0x10) == 0 || *(u32 *)(arg1 + 0x98) > *(u32 *)(arg3 + 0x30))) {
            *(u32 *)(arg3 + 0x14) = b;
            *((u8 *)arg3 + 0x10) = 1;
            *(u32 *)(arg3 + 0x30) = *(u32 *)(arg1 + 0x98);
        }
    } else {
        if (*(s32 *)(arg3 + 0x14) == -1) {
            *(s32 *)(arg3 + 0x1C) = 1;
        } else {
            *(s32 *)(arg3 + 0x1C) = 3;
        }
    }
}

/* Not matching yet: SIZE ours 192 / retail 200 (tools/try_func.py func_L15_004DD590 --diff). Not part of the build. */
#include "common.h"

extern s32 D_0021E6D4;
extern s32 D_0021E6D8;
extern u8 *D_0021E6B8;
extern void *func_00633A10(s32);

void func_L15_004DD590(void *arg0) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0xAC);
    u8 *p0;
    u8 *p1;
    s32 a;

    if (D_0021E6D4 == 0 && D_0021E6D8 == 1) {
        if (*(u8 **)(s + 0x280) == func_00633A10(0)) {
            *(u8 **)(s + 0x280) = func_00633A10(1);
            a = 0;
        } else {
            *(u8 **)(s + 0x280) = func_00633A10(0);
            a = 1;
        }
        *(u8 **)(s + 0x284) = func_00633A10(a);
        p0 = *(u8 **)(s + 0x280);
        p1 = *(u8 **)(s + 0x284);
        *(s32 *)(s + 0x1C4) = *(s32 *)(p0 + 0x2EF0);
        *(s32 *)(s + 0x1C8) = *(s32 *)(p1 + 0x2EF0);
        return;
    }
    *(u8 **)(s + 0x280) = func_00633A10(0);
    *(u8 **)(s + 0x284) = 0;
    p1 = D_0021E6B8;
    *(s32 *)(s + 0x1C8) = 0;
    *(s32 *)(s + 0x1C4) = *(s32 *)(p1 + 0x2EF0);
}

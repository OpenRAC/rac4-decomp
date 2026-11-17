#include "common.h"

extern s32 func_L00_005BC9B8(void *);
extern s32 func_L00_00607768();
extern s32 func_L00_006D10E0();
extern s32 D_0021E6B4;

// Sets the +0x5F4 flag from the 0x1C0 mask test when func_L00_006D10E0 returns 0, otherwise hands +0x5F4 to func_L00_005BC9B8.
void func_L00_006BF048(u8 *arg0) {
    s32 v;
    s32 d;
    u8 *p;

    if (func_L00_006D10E0() != 0) {
        func_L00_005BC9B8(arg0 + 0x5F4);
    } else {
        v = func_L00_00607768(1, *(s32 *)(arg0 + 0x2F10));
        p = *(u8 **)(arg0 + 0x2F00);
        if (*(s32 *)(p + 0x1C0) & v) {
            *(s16 *)(arg0 + 0x5F4) = 1;
        } else {
            *(s16 *)(arg0 + 0x5F4) = 0;
        }
        d = D_0021E6B4;
        if (d == 1 && *(s32 *)(arg0 + 0x5F0) != 0) {
            *(s16 *)(arg0 + 0x5F4) = (s16) d;
        }
    }
}

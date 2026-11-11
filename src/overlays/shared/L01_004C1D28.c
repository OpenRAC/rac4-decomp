#include "common.h"

extern s32 func_L00_005E0B30(void *, s32, s32, s32, f32, s32, s32);
extern s32 func_L00_005EE1D8(void *, f32);
extern void func_L00_005EEA48(void *, s32, s32, s32);
extern s32 func_L01_004C6600(void *);

s32 func_L01_004C1D28(u8 *moby, s32 arg1) {
    u8 *vars;
    s32 v;
    s32 a;

    vars = *(u8 **)(moby + 0xAC);
    switch (arg1) {
    case 1:
        if (func_L00_005EE1D8(moby, 12.0f) != 0) {
            a = func_L01_004C6600(moby);
            *(s32 *)(vars + 0x4C8) = a;
            func_L00_005EEA48(moby, a, 3, 0);
            v = *(s16 *)(vars + 0x49E) << 16;
            *(s32 *)(vars + 0x49C) = v;
            *(s16 *)(moby + 0x74) = v >> 11;
            *(s8 *)(vars + 0x4BF) = arg1;
        }
        break;
    case 4:
        *(s32 *)(vars + 0x4C0) = func_L00_005E0B30(moby, *(s32 *)(*(u8 **)(moby + 0x24) + 0x74), 0xB, 5, 0.0f, 0xB, 0xFF);
        *(s32 *)(vars + 0x4C4) = func_L00_005E0B30(moby, *(s32 *)(*(u8 **)(moby + 0x24) + 0x74), 0xB, 5, 0.0f, 0xC, 0xFF);
        break;
    }
    return 1;
}

#include "common.h"

extern s32 func_0054B220(u8 *);
extern void func_00556700(u8 *, s32, s32, f32, s32);
extern void func_00556808(u8 *, s32, s32);
extern void func_0054B1C0(u8 *, s32);
extern void func_005EABA8(s32, s32, u8 *);

void func_L13_004BD628(u8 *moby) {
    switch (moby[0x20]) {
    case 0:
        if (func_0054B220(moby) != 0) {
            func_00556700(moby, 2, 0, 0.0f, 0);
            func_00556808(moby, 4, -1);
        } else {
            func_00556700(moby, 0, 0, 0.0f, 0);
            func_00556808(moby, 1, -1);
        }
        break;
    case 1:
        if (moby[0xBE] & 4) {
            func_0054B1C0(moby, 1);
            func_00556808(moby, 2, -1);
        }
        break;
    case 2:
        if (++*(u16 *)(moby + 0x6A) == 0x5A) {
            func_005EABA8(0, 0x130, moby);
            func_00556700(moby, 1, 0, 0.0f, 0);
            func_00556808(moby, 3, -1);
        }
        break;
    case 3:
        moby[0x55] |= 0x10;
        if (moby[0x55] & 2) {
            func_00556700(moby, 2, 0, 0.0f, 0);
            *(f32 *)(moby + 0x48) = 0.0f;
            func_00556808(moby, 4, -1);
        }
        break;
    case 4:
        *(s32 *)(moby + 0x98) = 0;
        *(u16 *)(moby + 0x34) |= 2;
        break;
    }
}

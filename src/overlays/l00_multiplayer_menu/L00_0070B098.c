#include "common.h"

extern s32 func_0011A9EC(void *, void *);
extern s32 func_L00_00709AC8();
extern s32 D_002233A4;
extern s32 D_003F3D60[];
s32 D_00220A4C = 0;
u8 D_00220A60 = 0;

/* Builds a 0x1A0-byte request from D_003F3D60[0], 1 and D_00220A4C, sends it, then clears D_00220A60 and sets D_00220A4C to -1. */
void func_L00_0070B098(void) {
    u8 frame[0x1A0];
    s32 flag = D_00220A4C;
    s32 val = D_003F3D60[0];
    s32 one = 1;

    *(s32 *)(frame + 8) = flag;
    *(s32 *)frame = val;
    *(s32 *)(frame + 4) = one;
    func_0011A9EC(frame + 0x1B, *(u8 **)((u8 *)D_002233A4 + 0x3C) + 4);
    func_L00_00709AC8(frame);
    D_00220A60 = 0;
    D_00220A4C = -1;
}

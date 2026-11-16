/* Not matching yet: SIZE ours 196 / retail 200 (tools/try_func.py func_004E4DF0 --diff) (tools/try_func.py func_004E4DF0 --diff). Not part of the build. */
#include "common.h"

extern void func_0045C8E8(void *q);
extern s32 func_004E2AF8(s32 arg0);
extern void func_004E4EB8(s32, s32, void *, s32, s32);
extern unsigned int D_00171C08[];
extern u8 D_00171DF5[];
extern u8 D_1C2040[];
extern s32 D_23A800[];
extern s32 D_00221E04;

void func_004E4DF0(s32 arg0) {
    s32 r;
    u8 *p;

    if (arg0 < 0) {
        D_00221E04 = 0;
        return;
    }
    r = func_004E2AF8(arg0);
    D_00171C08[(u32)arg0 >> 5] |= 1u << (arg0 & 0x1F);
    func_0045C8E8(D_23A800);
    p = D_1C2040 + 8 + r * 16;
    func_004E4EB8(*(s32 *)(p + 8) + *(s32 *)(D_1C2040 + 4),
                  *(s32 *)(p + 0xC), p,
                  D_23A800[0] ? 0 : D_00171DF5[0],
                  r == 0x18);
}

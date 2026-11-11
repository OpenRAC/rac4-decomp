#include "common.h"
/* Ported from rac3-decomp's func_L40_00422678 (src/levels/shared/L40_00420998.c, GPL-3.0), the same code in both games. */

extern void func_00473A88(u8 *, s32, s32);
extern void func_L41_004114D8(u8 *);
extern s32 func_L41_004114B8(u8 *);
extern void func_L41_00412DB8(u8 *);
void func_L41_004115A8(u8 *self) {
    u8 *v;
    if (self == 0) {
        return;
    }
    if (self[32] == 254) {
        return;
    }
    if (self[32] == 253) {
        return;
    }
    v = *(u8 **)(self + 0xAC);
    func_00473A88(self, 1, -1);
    *(u16 *)(self + 52) &= 0xFFBE;
    *(u16 *)(self + 52) |= *(u16 *)(*(u8 **)(self + 36) + 68) & 0x1000;
    *(s32 *)(self + 152) = *(s32 *)(*(u8 **)(self + 36) + 16);
    self[0x2C] = 255;
    func_L41_004114D8(self);
    *(f32 *)(v + 0x50) = 1.0f;
    *(u16 *)(self + 52) |= 0x1000;
    if (func_L41_004114B8(self) != 0) {
        func_L41_00412DB8(self);
    }
}

#include "common.h"

extern s32 func_00504F68(u32 id, s32 enabled);
extern s32 func_00505410(u32 id, f32 amount);
extern u8 D_307074[];
extern u8 D_307220[];

/* Sets the enable flag of entry arg0 and, when its amount is nonzero, sends the amount to its channels. */
void func_0049E478(s32 arg0) {
    u8 *p;
    s32 base;
    s32 i;

    if (arg0 == 4) {
        p = D_307074;
    } else {
        p = D_307220 + (arg0 << 9);
    }
    base = arg0 << 6;
    func_00504F68(base + 0x130002, *p);
    if (*(f32 *)(p + 4) != 0.0f) {
        func_00505410(base + 0x130004, *(f32 *)(p + 4));
        for (i = 0; i < *(s32 *)(p + 0x10); i++) {
            func_00505410(base + 0x130006 + i * 2, *(f32 *)(p + 4));
            func_00505410(base + 0x130005 + i * 2, *(f32 *)(p + 4));
        }
    }
}

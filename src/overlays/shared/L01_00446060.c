#include "common.h"

s32 func_L01_004460E0(u8 *);
extern void func_L01_00591BD8(u8 *object, s32 new_state, s32 param);
extern s32 D_0021E824;

/* Reset the object's linked record, set its flags and call func_L01_00591BD8 with state 1. */
void func_L01_00446060(u8 *arg0) {
    u8 *s1;

    s1 = *(u8 **)(arg0 + 0xAC);
    *(s32 *)(s1 + 0x8) = func_L01_004460E0(arg0);
    arg0[0x31] = 0;
    *(u16 *)(arg0 + 0x34) |= 1;
    if (D_0021E824 == 1) {
        arg0[0x30] = 0x80;
    }
    *(s32 *)(s1 + 0xC) = 0;
    func_L01_00591BD8(arg0, 1, -1);
    s1[0x16] = 1;
}

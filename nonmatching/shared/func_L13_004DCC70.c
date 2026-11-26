/* Not matching yet: BYTES 17/168 (tools/try_func.py func_L13_004DCC70 --diff). Not part of the build. */
#include "common.h"

typedef int s128 __attribute__((mode(TI)));

extern void func_L00_005E4118(void *);
extern void func_L01_00591BD8(void *, s32, s32);
extern u8 *D_22299C;
extern u8 *D_2229A0;

s32 func_L13_004DCC70(u8 *arg0) {
    u8 *vars = *(u8 **)(arg0 + 0xAC);
    s32 a;
    u8 *e1;
    u8 *e2;
    f32 f1;

    func_L01_00591BD8(arg0, 1, -1);
    *(s16 *)(arg0 + 0x6E) = -1;
    a = *(s32 *)(vars + 0xC);
    if (a != 0) {
        if (*(s32 *)(vars + 0x10) != 0) {
            a <<= 7;
            e1 = D_22299C + a;
            f1 = *(f32 *)(e1 + 0x38);
            *(s128 *)(arg0 + 0x10) = *(s128 *)(e1 + 0x30);
            e2 = D_2229A0 + (*(s32 *)(vars + 0x10) << 7);
            *(f32 *)(vars + 0x24) = *(f32 *)(e2 + 0x38) - f1;
            func_L00_005E4118(arg0);
            arg0[0x31] = 0;
            *(u16 *)(arg0 + 0x34) |= 0x105;
        }
    }
    return 1;
}

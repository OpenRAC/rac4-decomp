#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_0046D258(u8 *a0, s32 a1, u8 *a2);
extern void func_L01_0055E008(u128 *a0, s32 a1, s32 a2);
extern void func_L01_0055E4E0(u128 a0, u8 *a1, s32 a2, s32 a3, f32 f12, f32 f13);

/* PAL: from rac3-decomp's func_L13_003C5E20 */
void func_L01_00505AF8(u8 *a0) {
    u128 buf;
    u8 *s0;
    if (a0 != 0 && a0[32] != 254 && a0[32] != 253) {
        s0 = *(u8 **)(a0 + 172);
        if (s0 != 0) {
            func_0046D258(a0, 0, (u8 *)&buf);
            func_L01_0055E008(&buf, 0x103080, 0);
            func_L01_0055E4E0(buf, s0 + 48, 0x103080, 4, 0.0f, 0.25f);
        }
    }
}

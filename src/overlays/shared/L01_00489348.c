#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_L01_004892F0(void *arg0, u128 *arg1);
extern u128 func_L00_005E99B0(u128 a0, u128 a1, f32 a2);
extern s32 D_222DA0;

/* Returns the object's stored 128-bit value, or recomputes it from its table entry and keeps a copy. */
void func_L01_00489348(u8 *arg0, u128 *arg1) {
    u8 *s1 = *(u8 **)(arg0 + 0xAC);
    u8 *elem;
    u128 s0;
    u128 tmp;
    u128 r;

    if (*(s32 *)(s1 + 0x84) < 0) {
        *arg1 = *(u128 *)(s1 + 0xD0);
        return;
    }
    elem = (u8 *)((*(s32 *)(s1 + 0x84) << 7) + D_222DA0);
    s0 = *(u128 *)(elem + 0x30);
    func_L01_004892F0(arg0, &tmp);
    r = func_L00_005E99B0(tmp, s0, *(f32 *)(s1 + 0x90));
    *arg1 = r;
    *(u128 *)(s1 + 0xD0) = r;
}

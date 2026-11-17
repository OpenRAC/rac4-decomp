#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_L01_005A1B38(void *p);

/* Refresh the linked state's cached quads at +0x5D0/+0x5E0 from its current target. */
void func_L01_0045B258(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0xAC);
    u8 *t;
    s32 i;

    func_L01_005A1B38(obj);
    t = *(u8 **)(s + 0x320);
    if (t != 0) {
        *(u128 *)(s + 0x5D0) = *(u128 *)(s + 0x310);
        *(u128 *)(s + 0x5E0) = *(u128 *)(t + 0xF0);
        s[0x61B] = 1;
    } else {
        i = *(s32 *)(s + 0x334);
        if (i >= 0) {
            t = *(u8 **)((u32)s + (i << 2) + 0x360);
            if (t != 0) {
                *(u128 *)(s + 0x5D0) = *(u128 *)(t + 0x10);
                *(u128 *)(s + 0x5E0) = *(u128 *)(t + 0xF0);
                s[0x61B] = 1;
            }
        }
    }
}

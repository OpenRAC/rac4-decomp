#include "common.h"

typedef int s128 __attribute__((mode(TI)));
extern s32 func_L00_005F1208(s128, s32);
extern void *func_L00_005F2FB8(void);
extern u8 *D_3660F8[];

/* Check the linked object's two candidate sets against the +0xAC state. */
s32 func_L01_0047E5B0(u8 *arg0) {
    u8 *state = *(u8 **)(arg0 + 0xAC);
    s32 want;
    s32 i;
    u8 **p;
    u8 *object;
    u8 *other;

    if (*(s32 *)(state + 0x30) == -1) {
        return 1;
    }
    object = D_3660F8[0];
    p = D_3660F8;
    want = *(u8 *)(state + 0x3C) != 0;
    i = 0;
    do {
        if (object != 0) {
            s32 r = func_L00_005F1208(*(s128 *)(object + 0xA0), *(s32 *)(state + 0x30)) != 0;
            if (r != want) {
                return r;
            }
        }
        p++;
        i++;
        object = *p;
    } while (i < 10);

    i = 0;
    do {
        u8 *base = func_L00_005F2FB8();
        other = *(u8 **)(base + (i << 2) + 0x1D0);
        if (other != 0) {
            s32 r = func_L00_005F1208(*(s128 *)(other + 0x10), *(s32 *)(state + 0x30)) != 0;
            if (r != want) {
                return r;
            }
        }
        i++;
    } while (i < 4);
    return want;
}

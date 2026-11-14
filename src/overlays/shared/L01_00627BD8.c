#include "common.h"

extern void *func_L00_005BD3C0(s16);
extern void func_L00_0066CD78(s32);
extern u8 D_34CF60[];

/* Finds the entry for a0's index and id, clears its flag, and releases the handles it still holds that match. */
s32 func_L01_00627BD8(u32 a0) {
    u8 *s0;
    u8 *e;
    u32 idx;
    s32 t1;
    s32 t2;
    s32 t3;
    void *v1;
    void *v2;
    void *v3;

    idx = a0 >> 16;
    s0 = 0;
    if (idx < 12) {
        e = D_34CF60 + idx * 0x50;
        if (e[0x40] != 0 && *(u16 *)e == (a0 & 0xFFFF)) {
            s0 = e;
        }
    }
    if (s0 == 0) {
        return 0;
    }
    s0[0x40] = 0;
    t1 = *(s32 *)(s0 + 0x14);
    v1 = func_L00_005BD3C0(*(s16 *)(s0 + 0x2));
    if (v1 != 0 && t1 == *(s32 *)((u8 *)v1 + 0x1C) && *((u8 *)v1 + 0x10) != 0) {
        func_L00_0066CD78(*(s16 *)(s0 + 0x2));
        *(s16 *)(s0 + 0x2) = -1;
    }
    t2 = *(s32 *)(s0 + 0x14);
    v2 = func_L00_005BD3C0(*(s16 *)(s0 + 0x4));
    if (v2 != 0 && t2 == *(s32 *)((u8 *)v2 + 0x1C) && *((u8 *)v2 + 0x10) != 0) {
        func_L00_0066CD78(*(s16 *)(s0 + 0x4));
        *(s16 *)(s0 + 0x4) = -1;
    }
    t3 = *(s32 *)(s0 + 0x14);
    v3 = func_L00_005BD3C0(*(s16 *)(s0 + 0x6));
    if (v3 != 0 && t3 == *(s32 *)((u8 *)v3 + 0x1C) && *((u8 *)v3 + 0x10) != 0) {
        func_L00_0066CD78(*(s16 *)(s0 + 0x6));
        *(s16 *)(s0 + 0x6) = -1;
    }
    return 1;
}

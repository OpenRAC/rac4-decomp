/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct {
    u8 pad0[0x2E];
    s8 x2E;
    u8 pad2F;
    s16 x30;
    s16 x32;
    s16 x34;
    u8 pad36[0x10];
    u8 x46;
    u8 pad47[0x69];
} __attribute__((aligned(16))) Info;

typedef struct {
    u8 pad0[0x7E8];
    s32 slot[2];
} Slots;

extern s32 D_00220D90[];
extern Info *func_0054A290(s32, s32);
extern void func_00515B28(u8 *);
extern s32 func_00472E70(s32, s32);
extern void func_00524030(u8 *, s32, s32, s32, f32);
extern void func_0046FB00(void *, s32, s32);
extern s32 func_0046F9E0(u8 *, s32, s32, s32, f32, s32, s32);

// For entry w (or the player's entry at +0x2318 when w is -1): copies its 0xB0-byte
// record from func_0054A290, picks two values from it, and either calls func_00524030
// or creates (or, when the value from +0x32/+0x34 is -1, removes) up to two objects in
// the player's slots at +0x7E8.
void func_005176C8(u8 *p, s32 w) {
    Info info;
    s32 *slot;
    s32 *tbl;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 k;
    s32 i;
    s32 v;

    if (w == -1) {
        w = *(s32 *)(p + 0x2318);
    }
    if (w == -1 || w == 0) {
        return;
    }
    *(s32 *)(p + 0x2DD8) = w;
    info = *func_0054A290(w, 0);
    a = info.x30;
    if (*(s32 *)(p + 0x25D4) == 12 || p[0x2ECD] != 0) {
        b = info.x34;
    } else {
        b = info.x32;
    }
    v = info.x46;
    if (*(s32 *)(p + 0x25CC) != 2 || *(s32 *)(p + 0x2318) == 2) {
        p[0x265A] = 1;
    }
    p[0x2658] = v;
    k = 0;
    c = -1;
    if (info.x2E == 0) {
        c = 9;
        k = 7;
    } else if (a == 60 || w == 3) {
        c = 2;
    } else if (w == 2) {
        c = 7;
    }
    d = c;
    if (d <= -1) {
        d = 9;
    }
    func_00515B28(p);
    *(s32 *)(p + 0x1870) = func_00472E70(75, 100);
    if ((*(s32 *)(p + 0x25D4) == 0 || *(s32 *)(p + 0x25D4) == 6) && p[0x2660] == 0 && p[0x2ECD] == 0 &&
        *(s32 *)(p + 0x2318) != 2 && *(s32 *)(p + 0x2318) != 13 && *(s32 *)(p + 0x2318) != 6) {
        *(s32 *)(p + 0x2DD4) = a;
        func_00524030(p, a, k, 0, (f32)c);
        *(s32 *)(p + 0x7F4) = 1;
        return;
    }
    if (*(s32 *)(p + 0x25D4) == 15 && *(s32 *)(p + 0x2318) == 2) {
        return;
    }
    i = 0;
    if (b == -1) {
        slot = (s32 *)(p + 0x7E8);
        for (i = 1; i >= 0; i--) {
            if (*slot != 0) {
                func_0046FB00(*(void **)(p + 0x2EF0), *slot, 0);
                *slot = 0;
            }
            *(s32 *)(p + 0x7F4) = 0;
            slot++;
        }
        return;
    }
    tbl = D_00220D90;
    for (; i < 2; i++) {
        if (i == 1 && p[0x2671] != 2) {
            break;
        }
        v = *(s32 *)(p + 0x2318);
        if (v == 13 || v == 16) {
            b = 0x57;
        }
        if (((Slots *)p)->slot[i] == 0 && *(s32 *)(p + 0x2318) != 16) {
            u8 *m = *(u8 **)(p + 0x2EF0);

            ((Slots *)p)->slot[i] = func_0046F9E0(m, *(s32 *)((b << 2) + *(u8 **)(m + 0x24) + 0x48), b, d, 0.0f,
                                                   tbl[i], 0xFF);
        }
    }
}

/* Not matching yet: SIZE ours 2112 / retail 2064 -- but this is the best SHAPE the function has
   had: prologue byte-identical on the default SN profile, path 1 chains 1:1 at retail offset
   (+0x160/+0x1D0/+0x270), clamp bounds matching retail tests. The +48 is path 2`s arrangement: our
   second_mask: merges retail`s six blocks. $s5 is load-bearing: giving path 2 its own i2*8 drops the
   frame to -0x60, so any edit must keep the shared value. Detail in build/try/func_00487FA0/NOTES.md. */
#include "common.h"

typedef struct {
    u8 pad0[0x30];
    u8 f30;
    u8 f31;
    u8 f32;
    u8 f33;
    u8 pad34[4];
    void *f38;
    void *f3C;
    u8 pad40[0x1C];
    void *f5C;
    u8 pad60[0x140];
    u64 f1A0;
    u64 f1A8;
} Obj;

typedef struct {
    u8 pad0[0x24];
    u8 *base;
} Owner;

typedef struct {
    u8 pad0[0xC];
    f32 x0C;
    f32 x10;
} Ent3;

extern s32 func_00487B00(void *, f32, f32);
extern s32 func_00487F08(f32, f32, f32);

s32 func_00487FA0(Owner *owner, Obj *p, s32 arg2, s32 arg3, f32 f25, f32 f24) {
    u8 *t1, *p100, *p138, *p160, *p178, *p2A0;
    u64 mask, a3;
    s32 i0, i1, i2, i3;
    s32 n, j, h, k;
    s32 s31, s30, x2, x3;
    s32 best, idx;
    u8 *rec, *a0, *v0, *v2;
    Ent3 *e;
    f32 f1, f2;
    f32 scale, f0, f20, f21, bestRatio, bestVal;

    if (owner == (Owner *)p->f5C) {
        t1 = p->f3C;
    } else {
        t1 = p->f38;
    }
    if (t1 == 0) {
        return func_00487B00(owner, f25, f24);
    }

    i0 = p->f32;
    i1 = p->f33;
    i2 = p->f30;
    i3 = p->f31;

    if (owner == (Owner *)p->f5C) {
        mask = p->f1A8;
        goto first_mask;
    }
    if (p->f5C == 0) {
        mask = p->f1A0;
        goto first_mask;
    }
    if (i2 != 0) {
        goto second_mask;
    }
    mask = p->f1A0;

first_mask:
    p100 = t1 + 0x100;
    p138 = t1 + 0x138;
    p160 = t1 + 0x160;
    p178 = t1 + 0x178;
    p2A0 = t1 + 0x2A0;
    s31 = i2 * 8;
    s30 = i3 * 8;
    x2 = arg2 * 8;
    x3 = arg3 * 8;

    a3 = mask & *(u64 *)(p100 + i0 * 8);
    if (a3 == 0 && i0 > 0) {
        u8 *q = (u8 *)t1 + i1 * 8;
        do {
            q -= 8;
            a3 = mask & *(u64 *)q;
            i0--;
        } while (a3 == 0 && i0 > 0);
    }
    mask = a3;
    a3 = mask & *(u64 *)((u8 *)t1 + i1 * 8);
    if (a3 == 0) {
        a3 = mask & *(u64 *)t1;
        if (arg2 == 2) {
            goto scan_a2;
        }
        mask = a3;
    }
scan_a2:
    a3 = *(u64 *)(p138 + s31);
    if ((a3 & mask) == 0) {
        n = 0;
        do {
            n++;
            h = i2 + n;
            k = i2 - n;
            if (!(h < 5)) {
                h = 4;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p138 + h * 8) | *(u64 *)(p138 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        } while (n < 4);
    }
    mask &= a3;

    a3 = *(u64 *)(p160 + x2);
    if ((a3 & mask) == 0) {
        n = 0;
        do {
            n++;
            h = arg2 + n;
            k = arg2 - n;
            if (!(h < 5)) {
                h = 4;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p160 + h * 8) | *(u64 *)(p160 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        } while (n < 2);
    }
    mask &= a3;

    a3 = *(u64 *)(p178 + x3);
    a3 = mask & a3;
    if (a3 == 0) {
        a3 = mask & *(u64 *)(p2A0 + s30);
        if (a3 == 0) {
            a3 = mask & *(u64 *)t1;
        }
    }
    mask &= a3;

    a3 = *(u64 *)(p2A0 + s30);
    if ((a3 & mask) == 0) {
        n = 0;
        do {
            n++;
            h = i3 + n;
            k = i3 - n;
            if (!(h < 4)) {
                h = 3;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p2A0 + h * 8) | *(u64 *)(p2A0 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        } while (n < 3);
    }
    mask &= a3;
    bestVal = 0.0f;
    bestRatio = bestVal;
    best = -1;
    idx = 0;
    if (mask == 0) {
        return best;
    }
    do {
        if ((mask & 1) == 0) {
            goto next1;
        }
        rec = owner->base;
        f1 = *(f32 *)((u8 *)owner + 0x70);
        v0 = rec + idx * 4;
        f0 = *(f32 *)(rec + 0x24);
        a0 = *(u8 **)(v0 + 0x48);
        f1 = f1 / f0;
        v2 = *(u8 **)(a0 + 0x18);
        e = (Ent3 *)*(u8 **)(v2 + 4);
        f0 = e->x0C;
        f20 = e->x10;
        f21 = f0 * f1;
        if (best < 0) {
            goto accept1;
        }
        if (f21 == bestVal) {
            goto ratio1;
        }
        f0 = 0.0f;
        if (f25 != f0) {
            if (func_00487F08(f25, bestVal, f21) == 0) {
                goto next1;
            }
            bestRatio = f20;
            goto accept21;
        }
        if (f24 == f0) {
            goto next1;
        }
        if (bestRatio == f0) {
            goto next1;
        }
        if (!(f0 < f21)) {
            goto next1;
        }
        goto accept1;
    ratio1:
        if (f20 == bestRatio) {
            goto next1;
        }
        f2 = f20 * f24;
        f1 = 0.0f;
        if (f1 < f2) {
            f0 = bestRatio * f24;
            if (f0 <= f1) {
                bestRatio = f20;
                goto accept21;
            }
        }
    check31:
        if (f20 == 0.0f) {
            if (f24 == 0.0f) {
                if (bestRatio != 0.0f) {
                    bestRatio = f20;
                    goto accept21;
                }
            }
        }
    last1:
        if (!(f1 < f2)) {
            goto next1;
        }
        if (!((f24 - f20) / (bestRatio - f20) < 0.5f)) {
            goto next1;
        }
    accept1:
        bestRatio = f20;
    accept21:
        bestVal = f21;
        best = idx;
    next1:
        idx++;
        mask >>= 1;
    } while (mask != 0);
    return best;

second_mask:

    a3 = mask & *(u64 *)(p100 + i0 * 8);
    if (a3 == 0 && i0 > 0) {
        u8 *q = (u8 *)t1 + i1 * 8;
        do {
            q -= 8;
            a3 = mask & *(u64 *)q;
            i0--;
        } while (a3 == 0 && i0 > 0);
    }
    mask = a3;
    a3 = *(u64 *)(p160 + x2);
    if ((a3 & mask) == 0) {
        for (n = 1; n < 3; n++) {
            h = arg2 + n;
            k = arg2 - n;
            if (!(h < 5)) {
                h = 4;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p160 + h * 8) | *(u64 *)(p160 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        }
    }
    mask &= a3;

    a3 = *(u64 *)(p178 + x3);
    a3 = mask & a3;
    if (a3 != 0) {
        mask = a3;
    }
    a3 = *(u64 *)((u8 *)t1 + i1 * 8);
    a3 = mask & a3;
    if (a3 == 0) {
        a3 = mask & *(u64 *)t1;
        if (arg2 == 2) {
            mask = a3;
            goto pick;
        }
    }
    mask = a3;

    a3 = *(u64 *)(p138 + s31);
    if ((a3 & mask) == 0) {
        n = 0;
        do {
            n++;
            h = i2 + n;
            k = i2 - n;
            if (!(h < 5)) {
                h = 4;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p138 + h * 8) | *(u64 *)(p138 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        } while (n < 5);
    }
    mask &= a3;

    a3 = *(u64 *)(p2A0 + s30);
    if ((a3 & mask) == 0) {
        n = 0;
        do {
            n++;
            h = i3 + n;
            k = i3 - n;
            if (!(h < 4)) {
                h = 3;
            }
            if (!(-1 < k)) {
                k = 0;
            }
            a3 |= *(u64 *)(p2A0 + h * 8) | *(u64 *)(p2A0 + k * 8);
            if ((a3 & mask) != 0) {
                break;
            }
        } while (n < 4);
    }
    mask &= a3;

pick:
    bestVal = 0.0f;
    bestRatio = bestVal;
    best = -1;
    idx = 0;
    if (mask == 0) {
        return best;
    }
    do {
        if ((mask & 1) == 0) {
            goto next;
        }
        rec = owner->base;
        f1 = *(f32 *)((u8 *)owner + 0x70);
        v0 = rec + idx * 4;
        f0 = *(f32 *)(rec + 0x24);
        a0 = *(u8 **)(v0 + 0x48);
        f1 = f1 / f0;
        v2 = *(u8 **)(a0 + 0x18);
        e = (Ent3 *)*(u8 **)(v2 + 4);
        f0 = e->x0C;
        f20 = e->x10;
        f21 = f0 * f1;
        if (best < 0) {
            goto accept;
        }
        if (f21 == bestVal) {
            goto ratio;
        }
        f0 = 0.0f;
        if (f25 != f0) {
            if (func_00487F08(f25, bestVal, f21) == 0) {
                goto next;
            }
            bestRatio = f20;
            goto accept2;
        }
        if (f24 == f0) {
            goto next;
        }
        if (bestRatio == f0) {
            goto next;
        }
        if (!(f0 < f21)) {
            goto next;
        }
        goto accept;
    ratio:
        if (f20 == bestRatio) {
            goto next;
        }
        f2 = f20 * f24;
        f1 = 0.0f;
        if (f1 < f2) {
            f0 = bestRatio * f24;
            if (f0 <= f1) {
                bestRatio = f20;
                goto accept2;
            }
        }
    check3:
        if (f20 == 0.0f) {
            if (f24 == 0.0f) {
                if (bestRatio != 0.0f) {
                    bestRatio = f20;
                    goto accept2;
                }
            }
        }
    last:
        if (!(f1 < f2)) {
            goto next;
        }
        if (!((f24 - f20) / (bestRatio - f20) < 0.5f)) {
            goto next;
        }
    accept:
        bestRatio = f20;
    accept2:
        bestVal = f21;
        best = idx;
    next:
        idx++;
        mask >>= 1;
    } while (mask != 0);
    return best;
}

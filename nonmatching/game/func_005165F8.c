/* Not matching yet: BYTES 26/744 (tools/try_func.py func_005165F8 --diff). Not part of the build. */
typedef unsigned int u128 __attribute__((mode(TI)));

typedef struct {
    u8 pad0[0x2E];
    s8 b2E;
    u8 pad2F;
    s16 h30;
    s16 h32;
    s16 h34;
    u8 pad36[0x10];
    u8 b46;
    u8 pad47[0x69];
} Rec;

typedef union {
    Rec r;
    u128 q[11];
} RecU;

extern s32 func_0046F100(void *, s32, s32, s32, s32, s32, f32);
extern void func_0046F220(void *, s32, s32);
extern s32 func_00472590(s32 a0, s32 a1);
extern void func_00514A58(u8 *arg0);
extern void func_00522E38(void *, s32, s32, s32, f32);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 D_00220CF0[];

/* Loads the record for a mode, sets up timers and the two effect slots at 0x7E8 for it. */
void func_005165F8(u8 *p, s32 mode) {
    RecU rec;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 i;
    s32 *slot;
    s32 *tab;
    s32 v;
    u8 t;

    if (mode == -1) {
        mode = *(s32 *)(p + 0x2318);
    }
    if ((u32)(mode + 1) < 2U) {
        return;
    }
    *(s32 *)(p + 0x2DD8) = mode;
    rec = *(RecU *)func_00548D28(mode, 0);
    a = rec.r.h30;
    if (*(s32 *)(p + 0x25D4) == 0xC || *(u8 *)(p + 0x2ECD) != 0) {
        b = rec.r.h34;
    } else {
        b = rec.r.h32;
    }
    t = rec.r.b46;
    if (*(s32 *)(p + 0x25CC) != 2 || *(s32 *)(p + 0x2318) == 2) {
        *(u8 *)(p + 0x265A) = 1;
    }
    e = 0;
    *(u8 *)(p + 0x2658) = t;
    c = -1;
    if (rec.r.b2E == 0) {
        c = 0xB;
        e = 7;
    } else if (a == 0x3C || mode == 3) {
        c = 2;
    } else {
        if (mode == 2) {
            c = 8;
        }
    }
    d = c;
    if (d <= -1) {
        d = 0xB;
    }
    func_00514A58(p);
    *(s32 *)(p + 0x1870) = func_00472590(0x5A, 0x78);
    if ((*(s32 *)(p + 0x25D4) == 0 || *(s32 *)(p + 0x25D4) == 6) && *(u8 *)(p + 0x2660) == 0 &&
        *(u8 *)(p + 0x2ECD) == 0) {
        v = *(s32 *)(p + 0x2318);
        if (v != 2 && v != 0xD && v != 6) {
            *(s32 *)(p + 0x2DD4) = a;
            func_00522E38(p, a, e, 0, (f32)c);
            *(s32 *)(p + 0x7F4) = 1;
            return;
        }
    }
    if (*(s32 *)(p + 0x25D4) == 0xF && *(s32 *)(p + 0x2318) == 2) {
        return;
    }
    i = 0;
    if (b == -1) {
        slot = (s32 *)(p + 0x7E8);
        for (i = 1; i >= 0; i--) {
            if (*slot != 0) {
                func_0046F220(*(void **)(p + 0x2EF0), *slot, 0);
                *slot = 0;
            }
            *(s32 *)(p + 0x7F4) = 0;
            slot++;
        }
        return;
    }
    tab = D_00220CF0;
    slot = (s32 *)(p + 0x7E8);
    for (i = 0; i < 2; i++, tab++, slot++) {
        if (i == 1 && *(u8 *)(p + 0x2671) != 2) {
            break;
        }
        v = *(s32 *)(p + 0x2318);
        if (v == 0xD || v == 0x10) {
            b = 0x57;
        }
        if (*slot == 0 && v != 0x10) {
            u8 *o = *(u8 **)(p + 0x2EF0);
            *slot = func_0046F100(o, *(s32 *)(*(u8 **)(o + 0x24) + b * 4 + 0x48), b, d, *tab, 0xFF, 0.0f);
        }
    }
}

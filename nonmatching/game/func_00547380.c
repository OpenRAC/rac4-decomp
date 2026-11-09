/* Not matching yet: BYTES 21/752 (tools/try_func.py func_00547380 --diff). Not part of the build. */
typedef struct {
    u8 pad0[0x104];
    u8 slots[10];
    u8 pad10E[0x1A9 - 0x10E];
    u8 mode;
} Type1;

typedef struct {
    u8 pad0[0x18];
    s8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 pad1B[2];
    u8 unk1D;
    u8 pad1E[4];
    s8 unk22;
} Type2;

typedef struct {
    u8 pad0[0x266D];
    u8 unk266D;
    u8 pad266E[0x2F14 - 0x266E];
    s32 unk2F14;
} Type3;

extern void func_0011A518(void *, s32, s32);
extern void func_00496E78(s32, s32, s32);
extern void func_00496F78(s32, s32);
extern void func_00496FA0(s32);
extern s32 func_00512748(Type3 *arg0);

extern s32 *D_0021DDA4;
extern Type1 *D_0021DFE8;
extern Type2 *D_0021DFF0;
extern Type3 *D_003367B8[];

u8 D_00220E54 = 0;

void func_00547380(void) {
    union {
        s32 counts[10];
        u8 seen[10];
    } u;
    s32 flags;
    s32 i;
    u8 mode;

    if (D_00220E54 != 0) {
        return;
    }
    D_00220E54 = 1;
    mode = D_0021DFE8->mode;
    flags = 0x40;
    if (mode != 0) {
        flags = 0x200;
        if (mode == 3) {
            s32 b;
            s32 a;
            u8 t = D_0021DFF0->unk1D;
            if (t != 0) {
                b = 0x1E;
                a = (s8)t;
            } else if (D_0021DFF0->unk22 != 0) {
                s32 max = 1;
                s32 j;
                func_0011A518(&u, 0, 0x28);
                for (j = 0; j < 10; j++) {
                    if (D_0021DFE8->slots[j] != 0xFF && D_003367B8[j] != 0) {
                        s32 *c = &u.counts[D_003367B8[j]->unk2F14];
                        s32 n = *c + 1;
                        *c = n;
                        if (max < n) {
                            max = n;
                        }
                    }
                }
                a = max * 60;
                b = D_0021DFF0->unk18;
            } else {
                b = D_0021DFF0->unk18;
                a = 60;
            }
            a = b * a;
            func_00496FA0(a);
        } else if (D_0021DFF0->unk19 != 0) {
            func_00496FA0((s8)D_0021DFF0->unk19);
        } else if (D_0021DFF0->unk1A != 0) {
            func_00496FA0((s8)D_0021DFF0->unk1A);
        }
    }
    func_0011A518(&u, 0, 10);
    {
    s32 k;
    for (k = 0; k < 10; k++) {
        if (D_0021DFE8->slots[k] == 0xFF) continue;
        if (D_003367B8[k] == 0) continue;
        if (u.seen[func_00512748(D_003367B8[k])] != 0) continue;
        if (D_003367B8[k]->unk266D == 0) continue;
        func_00496F78(func_00512748(D_003367B8[k]), D_003367B8[k]->unk266D != 0);
        u.seen[func_00512748(D_003367B8[k])] = 1;
    }
    }
    {
    s32 m;
    for (m = 0; m < 10; m++) {
        if (D_0021DFE8->slots[m] == 0xFF) continue;
        if (D_003367B8[m] == 0) continue;
        if (u.seen[func_00512748(D_003367B8[m])] != 0) continue;
        func_00496F78(func_00512748(D_003367B8[m]), D_003367B8[m]->unk266D != 0);
        u.seen[func_00512748(D_003367B8[m])] = 1;
    }
    }
    for (i = 0; i < *D_0021DDA4; i++) {
        func_00496E78(i, flags, 1);
    }
}

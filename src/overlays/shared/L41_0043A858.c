#include "common.h"

typedef struct C_0043A858 {
    u8 pad0[0x24];
    f32 unk24;
} C_0043A858;

typedef struct M_0043A858 {
    u8 pad0[0x24];
    C_0043A858 *unk24;
    u8 pad28[0x38 - 0x28];
    s64 unk38;
    u8 pad40[0x64 - 0x40];
    u8 unk64;
    u8 unk65;
    u8 pad66[0x70 - 0x66];
    f32 unk70;
    u8 pad74[0xAC - 0x74];
    void *unkAC;
    u8 padB0[0xBC - 0xB0];
    s16 unkBC;
} M_0043A858;

typedef struct V_0043A858 {
    s32 unk0;
    M_0043A858 *unk4;
    u8 pad8[0x20 - 0x8];
    M_0043A858 *unk20;
    u8 pad24[0x40 - 0x24];
    f32 unk40;
} V_0043A858;

typedef struct W_0043A858 {
    u8 pad0[0x33C];
    M_0043A858 *unk33C;
} W_0043A858;

typedef struct A_0043A858 {
    u8 pad0[0xAC];
    V_0043A858 *unkAC;
} A_0043A858;

extern M_0043A858 *func_L00_005DD000(s32, s32);
extern void func_L00_005EEA48(M_0043A858 *, M_0043A858 *, s32, s32);
extern void func_L00_005F1180(M_0043A858 *, M_0043A858 *);
extern void func_L00_007011A8(M_0043A858 *, s32, s32);
extern s32 func_L01_004DE8B0(A_0043A858 *);
extern s32 func_L41_0043A5A8(s32);

void func_L41_0043A858(A_0043A858 *arg0) {
    V_0043A858 *v;
    M_0043A858 *target;
    M_0043A858 *m;
    W_0043A858 *w;
    s32 r;

    v = arg0->unkAC;
    target = v->unk4;
    if (func_L01_004DE8B0(arg0) != 0 || target == NULL) {
        return;
    }
    r = func_L41_0043A5A8(v->unk0);
    if (r == 0) {
        return;
    }
    if (target->unkBC == 0x2106) {
        v->unk20 = func_L00_005DD000(0x210B, 0);
        if (v->unk20 != NULL) {
            func_L00_005F1180(v->unk20, target);
            v->unk20->unk38 = target->unk38;
            v->unk20->unk64 = 0;
            v->unk20->unk65 = 10;
            w = target->unkAC;
            if (w != NULL) {
                w->unk33C = v->unk20;
            }
            m = v->unk20;
            m->unk70 = m->unk24->unk24 * (2.0f * v->unk40 * 1.375f);
            func_L00_005EEA48(target, v->unk20, 1, 0);
        }
    }
    func_L00_007011A8(target, r, 0);
}

#include "common.h"

typedef struct C_004484C8 {
    u8 pad0[0x24];
    f32 unk24;
} C_004484C8;

typedef struct M_004484C8 {
    u8 pad0[0x24];
    C_004484C8 *unk24;
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
} M_004484C8;

typedef struct V_004484C8 {
    u8 pad0[0x10];
    s32 unk10;
    u8 pad14[0x18 - 0x14];
    M_004484C8 *unk18;
    M_004484C8 *unk1C;
} V_004484C8;

typedef struct W_004484C8 {
    u8 pad0[0x33C];
    M_004484C8 *unk33C;
} W_004484C8;

typedef struct A_004484C8 {
    u8 pad0[0xAC];
    V_004484C8 *unkAC;
} A_004484C8;

extern s32 func_00446418(s32);
extern M_004484C8 *func_L00_005DD000(s32, s32);
extern void func_L00_005DD4A0(M_004484C8 *);
extern void func_L00_005EEA48(M_004484C8 *, M_004484C8 *, s32, s32);
extern void func_L00_005F1180(M_004484C8 *, M_004484C8 *);
extern void func_L00_007011A8(M_004484C8 *, s32, s32);

void func_L41_004484C8(A_004484C8 *arg0) {
    V_004484C8 *v;
    M_004484C8 *target;
    M_004484C8 *m;
    W_004484C8 *w;
    s32 r;

    v = arg0->unkAC;
    target = v->unk18;
    if (target == NULL) {
        return;
    }
    r = func_00446418(v->unk10);
    if (r == 0) {
        return;
    }
    if (target->unkBC == 0x2106) {
        if (v->unk1C != NULL) {
            func_L00_005DD4A0(v->unk1C);
        }
        v->unk1C = func_L00_005DD000(0x210B, 0);
        if (v->unk1C != NULL) {
            v->unk1C->unk64 = 0;
            v->unk1C->unk65 = 10;
            func_L00_005F1180(v->unk1C, target);
            v->unk1C->unk38 = target->unk38;
            w = target->unkAC;
            if (w != NULL) {
                w->unk33C = v->unk1C;
            }
            m = v->unk1C;
            m->unk70 = m->unk24->unk24 * 1.6500001f;
            func_L00_005EEA48(target, v->unk1C, 1, 0);
        }
    }
    func_L00_007011A8(target, r, 0);
}

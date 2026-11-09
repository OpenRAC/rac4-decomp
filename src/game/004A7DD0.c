#include "common.h"

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    s32 unk28;
    u8 pad2C[0x98 - 0x2C];
    s32 flags;
    u8 pad9C[0xB8 - 0x9C];
} Type308108;

typedef struct {
    u8 pad0[0x28];
    u8 unk28;
} Type548D28;

extern u8 func_00498100(s32 arg0);
extern s32 func_00498120(s32 arg0);
extern s32 func_004981F8(s32 a0, s32 a1);
extern void func_004A7D48(s32 arg0);
extern void func_004A81D0(s32 index, s32 count, s32 seed);
extern s32 func_004A8C28(s32 index);
extern s32 *func_004A8C68(s32 index);
extern void func_004A90A0(void);
extern void func_004AF168(void);
extern s32 func_00547AC8(s32);
extern Type548D28 *func_00548D28(s32 arg0, s32 arg1);

extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0020C690[][3];
extern Type308108 D_00308108[];

s32 func_004A7DD0(s32 arg0, s32 arg1, s32 arg2) {
    Type308108 *rec;
    Type308108 *other;
    s32 *cur;
    s32 *row;
    s32 i;
    s32 n;
    s32 mode;
    s32 o;

    rec = &D_00308108[arg0];
    cur = func_004A8C68(arg0);
    if (func_00547AC8(arg1) == 0) {
        return 0;
    }
    if (*cur != arg1 && func_00498100(arg0) == 0) {
        if (func_00548D28(arg1, 0)->unk28 == 0) {
            if (func_00548D28(*cur, 0)->unk28 != 0) {
                rec->unk28 = *cur;
                cur = &rec->unk28;
            }
        } else if (func_00548D28(*cur, 0)->unk28 != 0) {
            n = 2;
            row = D_0020C690[arg0];
            for (i = 0; i < 3; row++, i++) {
                if (*row == arg1 || *row == 0) {
                    n = i;
                    break;
                }
            }
            for (; n > 0; n--) {
                D_0020C690[arg0][n] = D_0020C690[arg0][n - 1];
            }
        }
    }
    *cur = arg1;
    D_00308108[arg0].flags |= 9;
    if (D_0021EDD4 == 0) {
        mode = D_0021EDD8;
        if (mode == 1) {
            other = arg0 == 0 ? &D_00308108[1] : &D_00308108[0];
            if (D_0020C690[arg0][0] == D_0020C690[arg0 == 0][0]) {
                o = arg0 == 0;
                func_004A81D0(o, func_004A8C28(o), 1);
                if (func_00498120(o) != mode && other->unk28 == 0 && other->unk24 == 0 && arg2 == 0) {
                    func_004981F8(o, *func_004A8C68(o));
                }
            } else if (rec->unk28 == other->unk28 && rec->unk28 != 0) {
                func_004A7D48(arg0 == 0);
            }
            func_004A90A0();
            func_004AF168();
        }
    }
    return 1;
}

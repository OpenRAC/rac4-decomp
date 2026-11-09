#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[0x12 - 0x4];
    u16 unk12;
    u8 pad14[0x18 - 0x14];
    s32 unk18;
    u16 unk1C;
    u8 pad1E[0x34 - 0x1E];
    u16 unk34;
} Struct_00171B40;

typedef struct {
    u8 pad0[0x26E4];
    s32 unk26E4;
} Struct_unk_26E4;

extern Struct_00171B40 D_00171B40;
extern Struct_unk_26E4 *D_0021EDB8;

extern void func_00461E08(s32 arg0);
extern void func_00461E48(s32 arg0);
extern void func_004692C8(s32, s32);
extern s32 func_0047D368(s32 arg0);
extern void func_0047D3A8(s32 arg0, s32 arg1);
extern void func_0047D448(s32 i, s32 mask);
extern s32 func_004E6FA0(s32 *arg0);
extern Struct_unk_26E4 *func_00510BE8(s32 arg0);
extern void func_00522868(void *arg0, s32 arg1);
extern void func_00547A40(s32 a0, s32 a1, s32 a2);
extern s32 func_00547E00(s32, s32);
extern s16 func_00547E30(s32 arg0, s32 arg1);
extern void func_00547F58(s32, s32, s32);
extern s32 func_00548018(s32 arg0);
extern s32 func_00548DA0(s32, s32);
extern void func_00548DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_00549100(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_00549430(s32 arg0, s32 arg1);
extern void func_00549D20(s32, s32, s32, s32);
extern void func_00549DC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00549F08(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

s32 func_004E7000(s32 *arg0, s32 arg1, s32 arg2) {
    Struct_unk_26E4 *obj;
    s32 s1;
    s32 i;
    s32 v;
    s32 w;
    s32 n;

    if (!func_004E6FA0(arg0)) {
        return 0;
    }
    if (arg0[0] == 0xC) {
        n = arg0[2];
        D_00171B40.unk1C += n;
    } else {
        D_00171B40.unk0 -= arg0[2];
    }
    obj = D_0021EDB8;
    if (arg1 >= 0) {
        obj = func_00510BE8(arg1);
    }
    s1 = D_0021EDB8->unk26E4;
    if (obj != NULL) {
        s1 = obj->unk26E4;
    }
    switch (arg0[0]) {
    case 1:
        if (arg0[1] < 0) {
            for (i = 0; i < 20; i++) {
                v = func_00547E30(s1, i);
                if (func_00548DA0(s1, i) && !func_00548018(i)) {
                    if (func_00547E00(s1, i) < v) {
                        func_00547F58(s1, i, v - func_00547E00(s1, i));
                    }
                }
            }
        } else {
            w = func_00547E30(s1, arg0[1]);
            func_00547F58(s1, arg0[1], w - func_00547E00(s1, arg0[1]));
        }
        break;
    case 2:
        func_00548DF8(s1, arg0[1], 0, 1, 1);
        if (obj != NULL) {
            func_00522868(obj, arg0[1]);
            func_00547A40(arg1, arg0[1], -1);
        }
        if (arg0[1] == 16) {
            func_0047D368(8);
        }
        break;
    case 3:
        func_00549100(s1, arg0[1], 0, 0, 0, 0);
        if (obj != NULL) {
            func_00522868(obj, arg0[1]);
        }
        break;
    case 4:
        func_00549D20(s1, arg0[1], -1, 0);
        break;
    case 5:
        func_00549DC0(s1, arg0[1], -1, 0);
        break;
    case 6:
        func_00549F08(s1, arg0[1], -1, 0);
        break;
    case 7:
        func_00549430(s1, 1);
        break;
    case 8:
    case 9:
        func_0047D368(arg0[1]);
        if (arg0[1] == 8 && s1 != 0) {
            func_00548DF8(s1, 16, 0, 1, 0);
        }
        break;
    case 10:
        func_0047D3A8(arg0[1], 3);
        break;
    case 11:
        func_0047D448(arg0[1], 3);
        break;
    case 12:
        D_00171B40.unk18 |= 1 << arg0[1];
        if (arg2 == 0) {
            D_00171B40.unk12 = arg0[1];
            func_00461E08(arg0[1]);
        } else if (arg2 == 1) {
            D_00171B40.unk34 = arg0[1];
            func_00461E48(arg0[1]);
        }
        break;
    }
    func_004692C8(0, -1);
    return 1;
}

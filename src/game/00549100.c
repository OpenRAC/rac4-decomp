#include "common.h"

typedef struct Type2 {
    u8 pad0[0x64];
    void *unk64;
} Type2;

typedef struct Type1 {
    u8 pad0[0xAC];
    Type2 *unkAC;
    u8 padB0[0xC];
    s16 unkBC;
} Type1;

typedef struct Type3 {
    u8 pad0[0x20];
    s32 unk20;
} Type3;

extern s32 D_0021EDCC;
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;
extern s32 D_0021F19C;
extern Type3 D_0023F430[];

extern void func_00429BE8(void *, s32);
extern void func_004EAB80(s32 a, s32 b);
extern s32 func_00547C10(s32 arg0);
extern void func_00547C90(s32 arg0, s32 arg1, s32 arg2);
extern s16 func_00547D58(s32 arg0, s32 arg1);
extern void func_00547DC8(s32, s32, s32);
extern s32 func_00547E00(s32, s32);
extern s16 func_00547E30(s32 arg0, s32 arg1);
extern void func_00548040(s32, s32, s32);
extern s32 func_00548078(s32 arg0, s32 arg1);
extern s32 func_005480A8(s32, s32);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern void func_00549038(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00549840(void *, s32, s32);
extern void func_00549D20(s32, s32, s32, s32);
extern s32 func_0054A268(s32 arg0, s32 arg1);

void func_00549100(s32 arg0, s32 arg1, Type1 *arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 cur;
    s32 next;
    s32 limit;
    s32 small;
    s32 value;
    s32 scaled;
    s32 sel;
    Type2 *sub;

    cur = func_00547D58(arg0, arg1);
    next = cur + 1;
    if (cur == func_00547C10(arg1)) {
        return;
    }
    limit = func_005480A8(arg1, cur);
    func_00547C90(arg0, arg1, next);
    if (next == 0) {
        func_00548040(arg0, arg1, 0);
    } else if (limit >= 0) {
        value = func_00548078(arg0, arg1);
        if (value < limit) {
            value = limit;
        }
        func_00548040(arg0, arg1, value);
    }
    small = next < 10;
    if (!small) {
        if ((next + 1) % 10 != 0) {
            arg5 = 0;
        }
    }
    if ((D_0021EDD4 != 0 || D_0021EDD8 != 1) && arg5 != 0 && arg1 >= 2 && D_0021F19C == 0) {
        D_0023F430[0].unk20 = 1;
        D_0021EDCC = 0;
        func_004EAB80(arg1, cur);
        D_0023F430[0].unk20 = 0;
        if (arg2 != NULL) {
            if (arg1 == 2 && arg2->unkBC == 0x1094 && arg3 != 0 && arg2->unkAC->unk64 != NULL) {
                func_00429BE8(arg2->unkAC->unk64, arg3);
            }
            if (arg3 != 0) {
                func_00429BE8(arg2, arg3);
            }
        }
    } else if (arg2 != NULL) {
        if (arg1 == 2 && arg2->unkBC == 0x1094 && arg3 != 0 && arg2->unkAC->unk64 != NULL) {
            func_00429BE8(arg2->unkAC->unk64, arg3);
        }
        func_00549038(arg1, arg4, 200, next);
        if (arg3 != 0) {
            func_00429BE8(arg2, arg3);
        }
    }
    if (small) {
        s32 index = func_0054A268(arg1, next);
        sel = -1;
        if (D_0021EDD4 == 0 && D_0021EDD8 == 1) {
            sel = arg4;
        }
        func_00549D20(arg0, index, sel, arg1);
    }
    scaled = func_00547E30(arg0, arg1) * 0.34f;
    if (*((u8 *)func_00548D28(arg1, 0) + 0x28) != 0) {
        s32 base = func_00547E00(arg0, arg1);
        func_00547DC8(arg0, arg1, scaled < base ? base : scaled);
    }
    if (arg2 != NULL) {
        func_00549840(arg2, arg1, func_00547D58(arg0, arg1));
        if (arg1 == 2 && arg2->unkBC == 0x1094) {
            sub = arg2->unkAC;
            if (sub->unk64 != NULL) {
                func_00549840(sub->unk64, 2, func_00547D58(arg0, 2));
            }
        }
    }
}

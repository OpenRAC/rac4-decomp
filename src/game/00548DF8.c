#include "common.h"

extern void func_00547C90(s32 arg0, s32 arg1, s32 arg2);
extern void func_00547DC8(s32, s32, s32);
extern s32 func_00547E00(s32, s32);
extern s16 func_00547E30(s32 arg0, s32 arg1);
extern void *func_00548D28(s32 arg0, s32 arg1);
extern s32 func_00548DA0();
extern u32 func_00549BB8(s32 p, s32 idx);
extern void func_00549D20(s32, s32, s32, s32);
extern s32 func_0054A268(s32 arg0, s32 arg1);
extern s32 func_0054A290(s32, s32, s32);
extern s32 func_0054A788(s32, s32, s32);
extern s32 D_0021EDD4;

/* Updates slot arg1 of arg0 unless busy; may release an entry and refresh it. */
void func_00548DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx;
    void *ent;

    if (func_00548DA0() != 0) {
        return;
    }
    func_00547C90(arg0, arg1, arg2);
    ent = func_00548D28(arg1, 0);
    idx = func_0054A268(arg1, 0);
    if (D_0021EDD4 != 1 && arg2 == 0 && func_0054A788(arg0, arg1, idx) == 0) {
        if (arg4 == 0 && func_00549BB8(arg0, idx) != 0) {
            func_0054A290(arg0, arg1, idx);
        } else {
            func_00549D20(arg0, idx, -1, arg1);
        }
    }
    if (*((u8 *)ent + 0x28) != 0) {
        if (func_00547E00(arg0, arg1) != 0 && arg3 == 0) {
            return;
        }
        func_00547DC8(arg0, arg1, func_00547E30(arg0, arg1));
    }
}

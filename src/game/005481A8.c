#include "common.h"

extern s16 func_00547D58(s32 arg0, s32 arg1);
extern void func_00548040(u8 *a0, s32 a1, s32 a2);
extern s32 func_00548078(u8 *a0, s32 a1);
extern s32 func_005480A8(s32 kind, s32 level);
extern void *func_00548D28(s32 arg0, s32 arg1);

/* Adds to a stat and reports whether it reached its threshold. */
s32 func_005481A8(u8 *a0, s32 a1, s32 a2) {
    s32 *new_var;
    s32 code;
    s32 sum;

    if (a1 >= 0x20) {
        a1 = 0x1F;
    }
    new_var = &a1;
    if ((*new_var) < 0) {
        a1 = 0;
    }
    if (func_00547D58((s32)a0, a1) < 0) {
        return 0;
    }
    if (*((u8 *)func_00548D28(a1, 0) + 0x28) == 0) {
        return 0;
    }
    code = func_00547D58((s32)a0, a1);
    if (code == 0x62 || code == 9) {
        return 0;
    }
    sum = func_00548078(a0, a1) + a2;
    func_00548040(a0, a1, sum);
    return sum >= func_005480A8(a1, code);
}

#include "common.h"

extern s32 func_0045CB50(void);
extern s32 func_00547C10(s32 arg0);
extern s16 func_00547D58(s32 arg0, s32 arg1);
extern void func_00548040(s32, s32, s32);
extern s32 func_005480A8(s32, s32);

// Clamps arg2 to func_00547C10(arg1), applies it through func_00548040 and stores it in the arg1 record.
void func_00547C90(s32 arg0, s32 arg1, s32 arg2) {
    s32 t;

    func_0045CB50();
    if (arg2 == -1) {
        func_00548040(arg0, arg1, 0);
        *(s16 *)(arg1 * 0x44 + arg0 + 0xA30) = arg2;
        return;
    }
    t = func_00547C10(arg1);
    if (t < arg2) {
        arg2 = t;
    }
    if (func_00547D58(arg0, arg1) == arg2) {
        *(s16 *)(arg1 * 0x44 + arg0 + 0xA30) = arg2;
        return;
    }
    if (arg2 > 0) {
        func_00548040(arg0, arg1, func_005480A8(arg1, arg2 - 1));
    } else {
        func_00548040(arg0, arg1, 0);
    }
    *(s16 *)(arg1 * 0x44 + arg0 + 0xA30) = arg2;
}

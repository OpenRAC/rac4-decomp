/* Not matching yet: BYTES 15/276 (tools/try_func.py func_00548280 --diff). Not part of the build. */
#include "common.h"

extern s32 func_00547C10(s32);
extern s32 func_00547D58(s32, s32);
extern s32 func_00547D98(s32, s32);
extern s32 func_00548078(s32, s32);
extern s32 func_005480A8(s32, s32);
extern u8 *func_00548D28(s32, s32);

f32 func_00548280(s32 arg0, s32 arg1) {
    s32 a;
    s32 b;
    s32 span;

    if (arg1 == 0) {
        goto zero;
    }
    if (arg1 > 0x1F) {
        arg1 = 0x1F;
    } else {
    }
    if (arg1 <= -1) {
        arg1 = 0;
    }
    if (func_00548D28(arg1, 0)[0x28] == 0) {
zero:
        return 0.0f;
    }
    a = func_00547D58(arg0, arg1);
    b = func_00547D98(arg0, arg1);
    if (a == func_00547C10(arg1) || a == 9) {
        return 1.0f;
    }
    if (a != 0) {
        b = func_005480A8(arg1, b);
    } else {
        b = 0;
    }
    span = func_005480A8(arg1, a) - b;
    return (f32)(func_00548078(arg0, arg1) - b) / (f32)span;
}

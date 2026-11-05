#include "common.h"

extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern void func_00504338(s32 arg0, f32 arg1);
extern f32 func_005044A8(s32 arg0);
extern s32 D_221768;

// Nudges entry 1's value up by 0.02 toward 0.5 and entry 11's down by 0.02 toward 0.5.
void func_004B56F8(void) {
    s32 obj;

    obj = func_004A1A60(&D_221768, 1);
    if (func_005044A8(obj) < 0.5f) {
        func_00504338(obj, func_005044A8(obj) + 0.02f);
    }
    obj = func_004A1A60(&D_221768, 11);
    if (func_005044A8(obj) > 0.5f) {
        func_00504338(obj, func_005044A8(obj) - 0.02f);
    }
}

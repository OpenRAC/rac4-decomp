#include "common.h"
s32 func_00506BB8(void);
void func_005026A8(s32 *arg0, s32 arg1, s32 arg2);
s32 func_00506C08(s32 arg0, s32 arg1);
s32 func_004984A0(s32 arg0);
s32 func_005027A0(s32 *arg0, s32 arg1, f32 arg2);
s32 func_004A2798(s32 *arg0, s32 arg1);
const char *func_0045E850(s32 arg0);
s32 func_005062D0(s32 arg0, const char *arg1);
s32 func_00507270(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
s32 func_005060D8(s32 arg0, s32 arg1);
s32 func_005074A0(s32 arg0, s32 arg1, s32 arg2, f32 arg3);
extern s32 D_00221A80;
void func_004D0C20(void)
{
    s32 index;
    s32 handle;
    index = func_00506BB8();
    func_005026A8(&D_00221A80, 0x23, -1);
    func_00506C08(0xF, D_00221A80);
    func_005027A0(&D_00221A80, -1, (f32)func_004984A0(index));
    handle = func_004A2798(&D_00221A80, 0xB);
    func_005062D0(handle, func_0045E850(0x2350));
    handle = func_004A2798(&D_00221A80, 0xC);
    func_005062D0(handle, func_0045E850(0x237D));
    handle = func_004A2798(&D_00221A80, 0xD);
    func_00507270(handle, 1, 1, 1, 0, 0, 0, 0, 0);
    handle = func_004A2798(&D_00221A80, 0xD);
    func_005060D8(handle, 1);
    handle = func_004A2798(&D_00221A80, 0xD);
    func_005074A0(handle, 0xB4, 0xA, 0.00031f);
}

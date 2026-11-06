#include "common.h"

extern s32 D_00221AC0;
extern s32 func_00506BB8(void);
extern s32 func_005026A8(s32 *, s32, s32);
extern s32 func_00506C08(s32, s32);
extern s32 func_004984A0(s32);
extern void func_005027A0(s32 *, s32, f32);
extern s32 func_004A2798(s32 *, s32);
extern char *func_0045E850(s32);
extern s32 func_005062D0(s32, const char *);
extern s32 func_00507270(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_005060D8(s32, s32);
extern s32 func_005074A0(s32, s32, s32, f32);

void func_004D2E08(void)
{
    s32 index = func_00506BB8();
    s32 handle;

    func_005026A8(&D_00221AC0, 0x33, -1);
    func_00506C08(0xF, D_00221AC0);
    func_005027A0(&D_00221AC0, -1, (f32)func_004984A0(index));
    handle = func_004A2798(&D_00221AC0, 0xE);
    func_005062D0(handle, func_0045E850(0x2350));
    handle = func_004A2798(&D_00221AC0, 0xF);
    func_005062D0(handle, func_0045E850(0x2387));
    func_00507270(func_004A2798(&D_00221AC0, 0x10), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221AC0, 0x10), 1);
    func_005074A0(func_004A2798(&D_00221AC0, 0x10), 0xB4, 10, 0.00031f);
}

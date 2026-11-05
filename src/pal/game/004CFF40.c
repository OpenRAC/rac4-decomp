#include "common.h"

extern s32 D_00221A60;
extern s32 func_00506BB8(void);
extern void func_005026A8(s32 *, s32, s32);
extern void func_00506C08(s32, s32);
extern s32 func_004984A0(s32);
extern void func_005027A0(s32 *, s32, f32);
extern s32 func_004A2798(s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(u32, const char *);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_005060D8(s32, s32);
extern void func_005074A0(s32, f32, s32, s32);

void func_004CFF40(void) {
    s32 index = func_00506BB8();
    s32 other;

    func_005026A8(&D_00221A60, 0x26, -1);
    func_00506C08(0xF, D_00221A60);
    func_005027A0(&D_00221A60, -1, (f32)func_004984A0(index));
    other = func_004A2798(&D_00221A60, 0xE);
    func_005062D0(other, func_0045E850(0x2350));
    other = func_004A2798(&D_00221A60, 0xF);
    func_005062D0(other, func_0045E850(0x2383));
    other = func_004A2798(&D_00221A60, 0x10);
    func_00507270(other, 1, 1, 1, 0, 0, 0, 0, 0);
    other = func_004A2798(&D_00221A60, 0x10);
    func_005060D8(other, 1);
    other = func_004A2798(&D_00221A60, 0x10);
    func_005074A0(other, 0.00031f, 0xB4, 0xA);
}

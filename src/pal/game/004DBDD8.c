#include "common.h"

extern s32 D_00221C78;
extern s32 D_0021EE54, D_0021EE58;
extern char D_00322F10[];
extern char D_00321B18[];
extern const char D_0021FD18[], D_0021FD28[];
extern s32 func_005026A8(s32 *, s32, s32);
extern s32 func_00506C08(s32, s32);
extern s32 func_004A2798(s32 *, s32);
extern const char *func_0045E850(s32);
extern s32 func_005062D0(s32, const char *);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_00506590(s32, u32);
extern s32 func_00507270(u32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_005060D8(u32, s32);
extern s32 func_005074A0(u32, s32, s32, f32);
extern s32 func_00506000(s32, s32);

void func_004DBDD8(void)
{
    s32 handle;
    func_005026A8(&D_00221C78, 0x2D, -1);
    func_00506C08(15, D_00221C78);
    handle = func_004A2798(&D_00221C78, 21);
    func_005062D0(handle, func_0045E850(0x139E));
    func_005062D0(func_004A2798(&D_00221C78, 19), D_00322F10);
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        const char *format = D_0021FD18;
        char *destination = D_00321B18;
        const char *first, *second, *third;
        first = func_0045E850(0x3468);
        second = func_0045E850(0x234F);
        third = func_0045E850(0x2350);
        func_0011D920(destination, format, first, second, third);
    } else {
        const char *format = D_0021FD28;
        char *destination = D_00321B18;
        const char *first, *second;
        first = func_0045E850(0x234F);
        second = func_0045E850(0x2350);
        func_0011D920(destination, format, first, second);
    }
    func_005062D0(func_004A2798(&D_00221C78, 20), D_00321B18);
    func_00506590(func_004A2798(&D_00221C78, 17), 0x7546);
    func_00507270(func_004A2798(&D_00221C78, 23), 1, 1, 1, 0, 0, 0, 0, 0);
    func_005060D8(func_004A2798(&D_00221C78, 23), 1);
    func_005074A0(func_004A2798(&D_00221C78, 23), 180, 10, 0.00031f);
    if (D_0021EE54 == 0 && D_0021EE58 == 1) {
        s32 label = func_004A2798(&D_00221C78, 24);
        func_005062D0(label, func_0045E850(0x301A));
        func_00506000(func_004A2798(&D_00221C78, 24), 1);
    }
}

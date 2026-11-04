#include "common.h"
extern s32 func_00499B00(void), func_0011D920(char *, const char *, ...);
extern s32 func_004A2798(s32 *, s32), func_005062D0(u32, const char *), func_00506000(u32, s32);
extern s32 D_00221828;
extern char D_00309764[];
extern const char D_0021F830[], D_0021F840[], D_0021F848[];
void func_004B2508(void)
{
    s32 time = func_00499B00();
    s32 minutes = time / 60000;
    s32 seconds = (time % 60000) / 1000;
    func_0011D920(D_00309764, D_0021F830, minutes < 10 ? D_0021F840 : D_0021F848, minutes, seconds < 10 ? D_0021F840 : D_0021F848, seconds);
    func_005062D0(func_004A2798(&D_00221828, 25), D_00309764);
    func_00506000(func_004A2798(&D_00221828, 25), time != -1);
}

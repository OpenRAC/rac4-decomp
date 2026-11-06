#include "common.h"
extern s32 func_00498DC8(void), func_0011D920(char *, const char *, ...);
extern s32 func_004A1A60(s32 *, s32), func_00505238(u32, const char *), func_00504F68(u32, s32);
extern s32 D_00221728;
extern char D_00309664[];
extern const char D_0021F790[], D_0021F7A0[], D_0021F7A8[];
void func_004B1678(void)
{
    s32 time = func_00498DC8();
    s32 minutes = time / 60000;
    s32 seconds = (time % 60000) / 1000;
    func_0011D920(D_00309664, D_0021F790, minutes < 10 ? D_0021F7A0 : D_0021F7A8, minutes, seconds < 10 ? D_0021F7A0 : D_0021F7A8, seconds);
    func_00505238(func_004A1A60(&D_00221728, 25), D_00309664);
    func_00504F68(func_004A1A60(&D_00221728, 25), time != -1);
}

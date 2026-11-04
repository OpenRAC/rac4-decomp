#include "common.h"
extern char D_0030B358[];
extern s32 D_00221860;
extern s32 func_0045DE00(void);
extern s32 func_00505B20(void);
extern void func_0049C4B0(s32, s32, s32, s32);
extern void func_004C1360(void);
void func_00497EB8(s32 arg0, s32 arg1);
void func_0049B0D8(s32 arg0);
void func_004BD6F0(void)
{
    char *p;
    s32 i;
    func_0045DE00();
    i = func_00505B20();
    p = D_0030B358 + i * 600;
    *(s32 *)(p + 4) = 0;
    func_0049C4B0(i, 0, D_00221860, 0);
    func_004C1360();
    if (*(u8 *)(p + 8))
        func_00497EB8(i, 0);
    else
        func_0049B0D8(i);
}

#include "common.h"
extern char D_0030B358[];
extern s32 D_00221960;
extern s32 func_0045E618(void);
extern s32 func_00506BB8(void);
extern void func_0049D1E8(s32, s32, s32, s32);
extern void func_004C2188(void);
extern void func_00498BF0(s32, s32);
extern void func_0049BE10(s32);
void func_004BE4F0(void)
{
    char *p;
    s32 i;
    func_0045E618();
    i = func_00506BB8();
    p = D_0030B358 + i * 600;
    *(s32 *)(p + 4) = 0;
    func_0049D1E8(i, 0, D_00221960, 0);
    func_004C2188();
    if (*(u8 *)(p + 8))
        func_00498BF0(i, 0);
    else
        func_0049BE10(i);
}

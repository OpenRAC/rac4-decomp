#include "common.h"
extern s32 func_00506BB8(void);
extern s32 func_00499120(s32);
extern void func_0049BF40(s32);
extern void func_004D2CB0(s32);
extern void func_004D2DD8(void);

void func_004D2D48(void)
{
    s32 enabled = 0;
    s32 context = func_00506BB8();
    switch (func_00499120(6)) {
    case 1:
    case 3:
    case 4:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        break;
    case 2:
        func_0049BF40(context);
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004D2CB0(enabled);
        break;
    case 13:
        func_004D2DD8();
        break;
    }
}

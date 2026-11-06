#include "common.h"

extern s32 func_00499120(s32 mode);
extern s32 func_00506BB8(void);
extern void func_0049BF40(s32 context);
extern void func_004B9A10(s32 forward);
extern void func_004B9998(s32 forward);
extern void func_004B9B10(void);

void func_004B9A78(void)
{
    s32 forward = 0;

    switch (func_00499120(6)) {
    case 2:
        func_0049BF40(func_00506BB8());
        break;
    case 7:
        forward = 1;
    case 1:
    case 8:
        func_004B9A10(forward);
        break;
    case 5:
        forward = 1;
    case 6:
        func_004B9998(forward);
        break;
    case 13:
        func_004B9B10();
        break;
    }
}

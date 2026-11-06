#include "common.h"
extern s32 func_00506BB8(void), func_00499120(s32);
extern void func_0049BF40(s32), func_004D0AC8(s32), func_004D0BF0(void);
void func_004D0B60(void)
{
    s32 flag = 0;
    s32 context = func_00506BB8();
    switch (func_00499120(6)) {
    case 1:
        break;
    case 2:
        func_0049BF40(context);
        break;
    case 5:
        flag = 1;
    case 6:
        func_004D0AC8(flag);
        break;
    case 13:
        func_004D0BF0();
        break;
    }
}

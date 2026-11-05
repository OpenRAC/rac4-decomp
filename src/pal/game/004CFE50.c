#include "common.h"

extern s32 func_00506BB8(void);
extern s32 func_00499120(s32 group);
extern void func_0049BF40(s32 context);
extern void func_004CFDB8(s32 forward);
extern void func_004CFEE0(void);

void func_004CFE50(void)
{
    s32 forward = 0;
    s32 context = func_00506BB8();

    switch (func_00499120(6)) {
    case 1:
        break;
    case 2:
        func_0049BF40(context);
        break;
    case 5:
        forward = 1;
    case 6:
        func_004CFDB8(forward);
        break;
    case 13:
        func_004CFEE0();
        break;
    }
}

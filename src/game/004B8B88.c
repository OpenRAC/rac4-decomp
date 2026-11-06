#include "common.h"

extern s32 func_004983E8(s32 mode);
extern s32 func_00505B20(void);
extern void func_0049B208(s32 context);
extern void func_004B8B20(s32 forward);
extern void func_004B8AA8(s32 forward);
extern void func_004B8C20(void);

void func_004B8B88(void)
{
    s32 forward = 0;

    switch (func_004983E8(6)) {
    case 2:
        func_0049B208(func_00505B20());
        break;
    case 7:
        forward = 1;
    case 1:
    case 8:
        func_004B8B20(forward);
        break;
    case 5:
        forward = 1;
    case 6:
        func_004B8AA8(forward);
        break;
    case 13:
        func_004B8C20();
        break;
    }
}

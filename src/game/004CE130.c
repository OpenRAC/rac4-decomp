#include "common.h"

extern s32 func_00505B20(void);
extern s32 func_004983E8(s32 group);
extern void func_0049B208(s32 context);
extern void func_004CE098(s32 forward);
extern void func_004CE2C8(void);
extern void func_004CE1D0(void);
void func_004CE130(void)
{
    s32 forward = 0;
    s32 context = func_00505B20();

    switch (func_004983E8(6)) {
    case 1:
        func_004CE1D0();
        break;
    case 2:
        func_0049B208(context);
        break;
    case 5:
        forward = 1;
    case 6:
        func_004CE098(forward);
        break;
    case 13:
        func_004CE2C8();
        break;
    }
}

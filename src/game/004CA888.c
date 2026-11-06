#include "common.h"
extern s32 func_00465C08(void);
extern void func_00465F10(s32);
void func_004CA888(void)
{
    switch (func_00465C08()) {
    case 8:
    case 15:
    case 31:
        func_00465F10(2);
        break;
    case 7:
    case 22:
        func_00465F10(3);
        break;
    }
}

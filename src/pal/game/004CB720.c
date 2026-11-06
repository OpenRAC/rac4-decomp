#include "common.h"
extern s32 func_00466450(void);
extern void func_00466758(s32);
void func_004CB720(void)
{
    switch (func_00466450()) {
    case 8:
    case 15:
    case 31:
        func_00466758(2);
        break;
    case 7:
    case 22:
        func_00466758(3);
        break;
    }
}

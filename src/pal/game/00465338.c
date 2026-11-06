#include "common.h"

s32 D_0021DB60 = 0;
extern u8 D_0021DDB4;
extern u8 D_002214E8;
extern void func_00466760(void);

void func_00465338(s32 state)
{
    D_0021DB60 = state;
    if (state == 3) {
        D_0021DDB4 = 1;
    }
    switch (state) {
    case 3:
    case 19:
    case 20:
    case 22:
    case 24:
    case 33:
        D_002214E8 = 1;
    case 8:
    case 15:
    case 26:
    case 27:
    case 31:
    case 32:
        func_00466760();
        break;
    }
}

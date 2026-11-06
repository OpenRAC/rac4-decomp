#include "common.h"

s32 D_0021DAE0 = 0;
extern u8 D_0021DD2C;
extern u8 D_002213E8;
extern void func_00465F18(void);

void func_00464AF8(s32 state)
{
    D_0021DAE0 = state;
    if (state == 3) {
        D_0021DD2C = 1;
    }
    switch (state) {
    case 3:
    case 19:
    case 20:
    case 22:
    case 24:
    case 33:
        D_002213E8 = 1;
    case 8:
    case 15:
    case 26:
    case 27:
    case 31:
    case 32:
        func_00465F18();
        break;
    }
}

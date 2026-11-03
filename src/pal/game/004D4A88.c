#include "common.h"

s32 D_0021FC2C = 0, D_0021FC34 = 0;
extern s32 func_00466450(void), func_00159C58(s32);
extern s32 func_00466458(s32, void *, s32 (*)(void), void (*)(void));
extern void func_004D4E08(void), func_004D5240(void), func_004D4E00(void);
void func_004D4A88(void)
{
    switch (D_0021FC2C) {
    case 0:
        func_00466458(1, 0, 0, 0);
        func_004D4E08();
        D_0021FC34 = 30;
        D_0021FC2C++;
        return;
    case 1: {
        s32 timer;
        func_004D4E08();
        timer = D_0021FC34;
        if (timer > 0) {
            timer--;
            D_0021FC34 = timer;
        }
        D_0021FC34 = timer;
        if (!timer)
            func_004D5240();
        break;
    }
    case 2:
        if (func_00466450() == 1 || func_00466450() == 18)
            func_00159C58(1);
        func_004D4E00();
        break;
    }
}

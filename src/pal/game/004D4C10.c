#include "common.h"
s32 D_0021FC2C = 0, D_0021FC38 = 0;
extern s32 func_00469978(void);
extern s32 func_00466458(s32, void *, s32 (*)(void), void (*)(void));
extern void func_004D4E08(void), func_004D5240(void), func_004D4E00(void);
void func_004D4C10(void)
{
    switch (D_0021FC2C) {
    case 0:
        func_00466458(3, 0, func_00469978, 0);
        func_004D4E08();
        D_0021FC38 = 30;
        D_0021FC2C++;
        break;
    case 1:
        func_004D4E08();
        {
            s32 count = D_0021FC38;
            if (count > 0) {
                count--;
                D_0021FC38 = count;
            }
            D_0021FC38 = count;
        }
        if (!D_0021FC38)
            func_004D5240();
        break;
    case 2:
        func_004D4E00();
        break;
    }
}

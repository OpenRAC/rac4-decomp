#include "common.h"
s32 D_0021FC2C = 0;
extern u8 D_002214E0;
extern s32 func_00466458(s32, void *, s32 (*)(void), void (*)(void));
extern s32 func_0047FEB0(s32, s32, s32, s32, u8 *);
extern void func_004D4E00(void);
void func_004D48B8(void)
{
    switch (D_0021FC2C) {
    case 0:
        func_00466458(6, 0, 0, 0);
        D_002214E0 = 1;
    case 1:
        func_0047FEB0(4, 1, 1, 0, 0);
        D_0021FC2C++;
        break;
    case 2:
        func_004D4E00();
        break;
    }
}

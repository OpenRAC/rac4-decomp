#include "common.h"
s32 D_0021FB84 = 0, D_0021FB90 = 0;
extern s32 func_004690E8(void);
extern s32 func_00465C10(s32, void *, s32 (*)(void), void (*)(void));
extern void func_004D3EF8(void), func_004D4328(void), func_004D3EF0(void);
void func_004D3D00(void)
{
    switch (D_0021FB84) {
    case 0:
        func_00465C10(3, 0, func_004690E8, 0);
        func_004D3EF8();
        D_0021FB90 = 30;
        D_0021FB84++;
        break;
    case 1:
        func_004D3EF8();
        {
            s32 count = D_0021FB90;
            if (count > 0) {
                count--;
                D_0021FB90 = count;
            }
            D_0021FB90 = count;
        }
        if (!D_0021FB90)
            func_004D4328();
        break;
    case 2:
        func_004D3EF0();
        break;
    }
}

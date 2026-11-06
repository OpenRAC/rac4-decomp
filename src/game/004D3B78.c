#include "common.h"

s32 D_0021FB84 = 0, D_0021FB8C = 0;
extern s32 func_00465C08(void), func_00159C28(s32);
extern s32 func_00465C10(s32, void *, s32 (*)(void), void (*)(void));
extern void func_004D3EF8(void), func_004D4328(void), func_004D3EF0(void);
void func_004D3B78(void)
{
    switch (D_0021FB84) {
    case 0:
        func_00465C10(1, 0, 0, 0);
        func_004D3EF8();
        D_0021FB8C = 30;
        D_0021FB84++;
        return;
    case 1: {
        s32 timer;
        func_004D3EF8();
        timer = D_0021FB8C;
        if (timer > 0) {
            timer--;
            D_0021FB8C = timer;
        }
        D_0021FB8C = timer;
        if (!timer)
            func_004D4328();
        break;
    }
    case 2:
        if (func_00465C08() == 1 || func_00465C08() == 18)
            func_00159C28(1);
        func_004D3EF0();
        break;
    }
}

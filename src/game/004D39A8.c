#include "common.h"
s32 D_0021FB84 = 0;
extern u8 D_002213E0;
extern s32 func_00465C10(s32, void *, s32 (*)(void), void (*)(void));
extern s32 func_0047F568(s32, s32, s32, s32, u8 *);
extern void func_004D3EF0(void);
void func_004D39A8(void)
{
    switch (D_0021FB84) {
    case 0:
        func_00465C10(6, 0, 0, 0);
        D_002213E0 = 1;
    case 1:
        func_0047F568(4, 1, 1, 0, 0);
        D_0021FB84++;
        break;
    case 2:
        func_004D3EF0();
        break;
    }
}

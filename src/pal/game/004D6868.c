#include "common.h"
extern s32 func_00499120(s32 mode);
extern void func_004D66D0(void);
extern void func_004D6790(void);
extern void func_004D67E8(s32 next);
extern void func_004D68F8(void);

void func_004D6868(void)
{
    s32 next = 0;

    switch (func_00499120(6)) {
    case 1:
        func_004D66D0();
        break;
    case 2:
        func_004D6790();
        break;
    case 5:
        next = 1;
    case 6:
        func_004D67E8(next);
        break;
    case 13:
        func_004D68F8();
        break;
    }
}

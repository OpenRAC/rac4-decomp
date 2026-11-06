#include "common.h"
extern s32 func_004983E8(s32);
extern void func_004DAB90(void);
extern void func_004DACA0(void);
extern void func_004DAD30(s32);
extern void func_004DAE88(void);
extern void func_004DB150(s32);

void func_004DADD8(void)
{
    s32 enabled = 0;
    switch (func_004983E8(6)) {
    case 1:
        func_004DAB90();
        break;
    case 2:
        func_004DACA0();
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004DAD30(enabled);
        break;
    case 13:
        func_004DAE88();
        break;
    case 9:
        func_004DB150(0);
        break;
    case 11:
        func_004DB150(1);
        break;
    }
}

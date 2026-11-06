#include "common.h"
extern s32 func_004983E8(s32);
extern void func_004C76A8(void);
extern void func_004C72E0(void);
extern void func_004C7168(s32);
extern void func_004C77E8(void);
extern void func_004C73E8(void);

void func_004C7240(void)
{
    s32 enabled = 0;
    switch (func_004983E8(6)) {
    case 1:
        func_004C76A8();
        break;
    case 2:
        func_004C72E0();
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004C7168(enabled);
        break;
    case 4:
        func_004C77E8();
        break;
    case 13:
        func_004C73E8();
        break;
    }
}

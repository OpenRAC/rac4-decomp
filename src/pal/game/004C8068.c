#include "common.h"
extern s32 func_00499120(s32);
extern void func_004C84D0(void);
extern void func_004C8108(void);
extern void func_004C7F90(s32);
extern void func_004C8610(void);
extern void func_004C8210(void);

void func_004C8068(void)
{
    s32 enabled = 0;
    switch (func_00499120(6)) {
    case 1:
        func_004C84D0();
        break;
    case 2:
        func_004C8108();
        break;
    case 5:
        enabled = 1;
    case 6:
        func_004C7F90(enabled);
        break;
    case 4:
        func_004C8610();
        break;
    case 13:
        func_004C8210();
        break;
    }
}

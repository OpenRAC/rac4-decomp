#include "common.h"

extern s32 func_004983E8(s32 mode);
extern void func_004BBB70(void);
extern void func_004BB9E8(s32 backward);
extern void func_004BB7B8(void);
extern void func_004BBA80(void);
extern void func_004BBBE8(void);

void func_L00_00643598(void)
{
    s32 backward = 1;

    switch (func_004983E8(6)) {
    case 2:
        func_004BBB70();
        break;
    case 5:
        backward = 0;
    case 6:
        func_004BB9E8(backward);
        break;
    case 1:
        func_004BB7B8();
        break;
    case 4:
        func_004BBA80();
        break;
    case 13:
        func_004BBBE8();
        break;
    }
}

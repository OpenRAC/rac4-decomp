#include "common.h"

extern s32 func_00499120(s32 mode);
extern void func_004BE780(void);
extern void func_004C2090(s32 backward);
extern void func_004BE808(void);
extern void func_004BEB10(void);
extern void func_004BE7C0(void);

void func_004BE6E0(void)
{
    s32 backward = 1;

    switch (func_00499120(6)) {
    case 2:
        func_004BE780();
        break;
    case 5:
        backward = 0;
    case 6:
        func_004C2090(backward);
        break;
    case 1:
        func_004BE808();
        break;
    case 4:
        func_004BEB10();
        break;
    case 13:
        func_004BE7C0();
        break;
    }
}

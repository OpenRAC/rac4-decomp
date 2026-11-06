#include "common.h"

extern s32 func_004983E8(s32 mode);
extern void func_004BD980(void);
extern void func_004C1268(s32 backward);
extern void func_004BDA08(void);
extern void func_004BDD10(void);
extern void func_004BD9C0(void);

void func_004BD8E0(void)
{
    s32 backward = 1;

    switch (func_004983E8(6)) {
    case 2:
        func_004BD980();
        break;
    case 5:
        backward = 0;
    case 6:
        func_004C1268(backward);
        break;
    case 1:
        func_004BDA08();
        break;
    case 4:
        func_004BDD10();
        break;
    case 13:
        func_004BD9C0();
        break;
    }
}

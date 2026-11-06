#include "common.h"
extern s32 func_004983E8(s32 mode);
extern void func_004D57B8(void);
extern void func_004D5878(void);
extern void func_004D58D0(s32 next);
extern void func_004D59E0(void);

void func_004D5950(void)
{
    s32 next = 0;

    switch (func_004983E8(6)) {
    case 1:
        func_004D57B8();
        break;
    case 2:
        func_004D5878();
        break;
    case 5:
        next = 1;
    case 6:
        func_004D58D0(next);
        break;
    case 13:
        func_004D59E0();
        break;
    }
}

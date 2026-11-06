#include "common.h"

extern s32 func_00499120(s32 mode);
extern void func_004C9EB8(void);
extern void func_004C9FC8(void);
extern void func_004CA068(s32 forward);

void func_004CA0E8(void)
{
    s32 forward = 0;

    switch (func_00499120(6)) {
    case 1:
        func_004C9EB8();
        break;
    case 2:
    case 13:
        func_004C9FC8();
        break;
    case 5:
        forward = 1;
    case 6:
        func_004CA068(forward);
        break;
    }
}

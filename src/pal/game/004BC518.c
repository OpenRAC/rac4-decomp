#include "common.h"

extern s32 func_00499120(s32 mode);
extern void func_004BC970(void);
extern void func_004BC7E8(s32 backward);
extern void func_004BC5B8(void);
extern void func_004BC880(void);
extern void func_004BC9E8(void);

void func_004BC518(void)
{
    s32 backward = 1;

    switch (func_00499120(6)) {
    case 2:
        func_004BC970();
        break;
    case 5:
        backward = 0;
    case 6:
        func_004BC7E8(backward);
        break;
    case 1:
        func_004BC5B8();
        break;
    case 4:
        func_004BC880();
        break;
    case 13:
        func_004BC9E8();
        break;
    }
}

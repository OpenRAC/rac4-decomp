#include "common.h"

extern s32 func_00499120(s32 mode);
extern void func_004DD4D0(s32 next);
extern void func_004DD908(s32 direction);
extern void func_004DCD78(void);
extern void func_004DCD98(void);

void func_004DCCB8(void)
{
    s32 next = 0;

    switch (func_00499120(6)) {
    case 7:
        next = 1;
    case 8:
        func_004DD4D0(next);
        break;
    case 5:
        func_004DD908(2);
        break;
    case 6:
        func_004DD908(1);
        break;
    case 1:
        func_004DD908(3);
        break;
    case 3:
        func_004DD908(4);
        break;
    case 2:
        func_004DCD78();
        break;
    case 13:
        func_004DCD98();
        break;
    }
}

#include "common.h"

extern s32 func_004983E8(s32 mode);
extern void func_004C9090(void);
extern void func_004C91A0(void);
extern void func_004C9240(s32 forward);

void func_004C92C0(void)
{
    s32 forward = 0;

    switch (func_004983E8(6)) {
    case 1:
        func_004C9090();
        break;
    case 2:
    case 13:
        func_004C91A0();
        break;
    case 5:
        forward = 1;
    case 6:
        func_004C9240(forward);
        break;
    }
}

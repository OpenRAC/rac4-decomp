#include "common.h"

s32 func_005210B0(void);
extern s32 func_00521078(void);
extern s32 func_005210B0(void);

/* from rac3-decomp's func_L01_004FF5D8, constants adapted */
s32 func_00521078(void) {
    s32 n = 12;
    s32 x = func_005210B0();
    goto test;
zero:
    n = 0;
    goto done;
test:
    if (x == 2)
        goto zero;
done:
    return n;
}

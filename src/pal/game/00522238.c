#include "common.h"

s32 func_005210B0(void);
extern s32 func_00522238(void);
extern s32 func_005210B0(void);

s32 func_00522238(void) {
    s32 n = 0xA;
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

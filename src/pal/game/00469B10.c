#include "pal/card_state_001719C8.h"

extern void func_00453E70(s32 *, s32);

/* Reads a handle after optional synchronization while ready. */
s32 func_00469B10(s32 *a)
{
    if (D_001719C8[0].f1C4 < 3) {
        if (D_001719C8[0].f1CC < 0) {
            if (D_001719C8[0].f1D4)
                func_00453E70(a, 64);
            return *a;
        }
        return -1;
    }
    return -1;
}

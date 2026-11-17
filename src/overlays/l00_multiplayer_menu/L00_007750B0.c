#include "common.h"

extern s32 func_0011D9A8(void *p, const char *fmt, ...);
extern u8 D_004C1610[];

/* parses a message and records it in the menu state */
s32 func_L00_007750B0(s32 *arg0, u8 *arg1) {
    s32 temp;

    if ((func_0011D9A8(arg1, D_004C1610, arg0 + 1, arg0 + 2, arg0 + 3) ^ 3) == 0) {
        temp = *(s32 *)(arg1 + 0x98);
        arg0[0] = 3;
        arg0[4] = temp;
    }
    return 0;
}

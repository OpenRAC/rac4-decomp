/* cflags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division */
#include "common.h"
extern s32 func_005015C8();
extern s32 func_004FFB70();
extern s32 func_00500818(s32);
extern s32 func_00501358();
s32 func_004FFD60(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x16;
        if (*q) func_005015C8(*q);
        *q = 0;
        for (i = 15; i >= 0; i--) {
            func_00501358(func_00500818(func_004FFB70(p)));
        }
        return 1;
    }
    return 0;
}

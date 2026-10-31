/* cflags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division */
#include "common.h"
extern s32 func_00502638();
extern s32 func_00500BE0();
extern s32 func_00501888(s32);
extern s32 func_005023C8();
s32 func_00500DD0(s32 *p, u32 idx) {
    s32 *q;
    s32 i;
    if (idx < 0x23) {
        q = (s32 *)((u8 *)(idx * 4) + *p);
        q += 0x16;
        if (*q) func_00502638(*q);
        *q = 0;
        for (i = 15; i >= 0; i--) {
            func_005023C8(func_00501888(func_00500BE0(p)));
        }
        return 1;
    }
    return 0;
}

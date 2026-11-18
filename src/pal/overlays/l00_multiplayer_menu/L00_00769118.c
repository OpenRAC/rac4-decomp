#include "pal/mask_state.h"
#include "pal/profile_001721E0.h"

/* Counts slots up to arg1 whose team byte equals the current team and says whether slot arg1 does */
s32 func_L00_00769118(s32 arg0, s32 arg1, s32 *arg2) {
    s32 i;

    *arg2 = -1;
    if (D_0021E070 != 0 && arg1 >= 0) {
        i = 0;
        do {
            if (*(u8 *)((u32)D_0021E070 + i + 0x104) == D_001721E0.f10) {
                *arg2 += 1;
            }
            i++;
        } while (i <= arg1);
    }
    return *(u8 *)((u32)D_0021E070 + arg1 + 0x104) == D_001721E0.f10;
}

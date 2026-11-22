/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00453608(s32, s32, s32);
extern s32 D_002220D0;
extern s32 D_002220D4;

void func_L00_005D28F8(s32 *arg0, s32 *arg1) {
    s32 i;
    f32 *dst;
    s32 n;

    n = arg0[0];
    D_002220D4 = n;
    D_002220D0 = *arg1;
    *arg1 += n << 5;
    arg0 += 4;
    if (D_002220D4 != 0) {
        func_00453608(D_002220D0, 0, D_002220D4 << 5);
    }
    *arg1 = (*arg1 + 0x3F) & 0xFFFFFFC0;
    i = 0;
    if (D_002220D4 > 0) {
        do {
            dst = (f32 *)(D_002220D0 + (i << 5));
            i++;
            *(s32 *)(dst + 3) = *arg0++;
            dst[0] = ((f32 *)arg0)[0];
            dst[1] = ((f32 *)arg0)[1];
            dst[2] = ((f32 *)arg0)[2];
            arg0 += 3;
            dst[4] = ((f32 *)arg0)[0];
            dst[5] = ((f32 *)arg0)[1];
            dst[6] = ((f32 *)arg0)[2];
            arg0 += 3;
            *(s32 *)(dst + 7) = *arg0++;
        } while (i < D_002220D4);
    }
}

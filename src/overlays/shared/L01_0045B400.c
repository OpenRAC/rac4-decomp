#include "common.h"

extern s32 func_L01_0045B378(void *);
extern s32 func_L01_0045B578(void *, s32);
extern f32 func_L00_005E6118(f32, f32);
extern f32 D_003A6BE0[];

// Picks a category from func_L01_0045B378, then sums the weights of the categories that test set and returns the first index whose weight the running total falls under.
s32 func_L01_0045B400(void *arg0)
{
    s32 s0;
    s32 i;
    u32 s3;
    f32 f21;
    f32 f1;

    s0 = -1;
    switch (func_L01_0045B378(arg0)) {
    case 5:
        s0 = 2;
        break;
    case 4:
        s0 = 1;
        break;
    case 6:
        s0 = 3;
        break;
    }
    if (s0 != -1 && func_L01_0045B578(arg0, s0) != 0) {
        return s0;
    }
    f21 = 0.0f;
    s3 = 0;
    s0 = 0;
    do {
        if (func_L01_0045B578(arg0, s0) != 0) {
            f21 += D_003A6BE0[s0 * 4 + 2];
            s3 |= 1 << s0;
        }
        s0++;
    } while (s0 < 6);
    f1 = func_L00_005E6118(0.0f, f21);
    i = 0;
    do {
        if (s3 & (1 << i)) {
            f1 -= D_003A6BE0[i * 4 + 2];
            if (f1 <= 0.0f) {
                return i;
            }
        }
        i++;
    } while (i < 6);
    return 0;
}

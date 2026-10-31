#include "common.h"

extern f32 D_001A0078_[];
#define D_001A0078 (D_001A0078_[0])

/* returns the index of the table entry nearest to the argument, scanning entries 1 to 63 */
s32 func_00148698(f32 arg0) {
    f32 best;
    f32 d;
    f32 *p;
    s32 idx = 0;
    s32 i = 1;

    best = arg0 - D_001A0078;
    best = best * best;
    p = &D_001A0078 + 1;
    do {
        d = arg0 - *p;
        d = d * d;
        if (d < best) {
            best = d;
            idx = i;
        }
        i++;
        p++;
    } while (i < 0x40);
    return idx;
}

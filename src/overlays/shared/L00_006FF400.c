#include "common.h"


/* Whether the byte at +2 + i is set, for i (as a byte) below 10; else 0. */
s32 func_L00_006FF400(u8 *o, s32 i) {
    u8 k = i;
    if (k >= 10) {
        return 0;
    }
    return (o + k)[2] != 0;
}

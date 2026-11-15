/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_00537F68(void *a0);

/* Writes the bytes of the bit set at arg0 into arg1, most significant block first; returns the byte count. */
s32 func_L00_005386D0(s32 *arg0, u8 *arg1) {
    s32 nbytes;
    s32 i;
    s32 k;

    nbytes = (func_L00_00537F68(arg0) + 7) / 8;
    i = nbytes - 1;
    if (nbytes > 0) {
        do {
            k = i;
            *arg1++ = *(u64 *)((u8 *)arg0[0] + (k / 8) * 8) >> ((k % 8) * 8);
            i--;
        } while (k > 0);
    }
    return nbytes;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

extern s32 func_L00_00537F68(BitSet_004FCA98 *);

unsigned long func_L00_00538478(BitSet_004FCA98 *a0) {
    unsigned long v = 0;
    s32 n;
    s32 i;

    n = func_L00_00537F68(a0);
    if ((n + 7) / 8 >= 9) {
        return -1;
    }
    i = a0->f4 - 1;
    while (i >= 0) {
        v = a0->f0[i];
        i--;
    }
    return v;
}

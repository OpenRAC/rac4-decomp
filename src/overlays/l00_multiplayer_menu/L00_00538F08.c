/* cflags: @ee29 -O2 -G0 */
#include "common.h"

s64 func_L00_00539520(s64 *, s64 *, s32, s64);
s64 func_L00_00539898(s64 *, s64 *, s32, s64);

/* Multi-word multiply: dst = a (na words) * b (nb words), row by row. */
void func_L00_00538F08(s64 *dst, s64 *a, s32 na, s64 *b, s32 nb) {
    s64 *row;

    if (na < nb) {
        s32 tn;
        s64 *tp;
        tn = na; na = nb; nb = tn;
        tp = a; a = b; b = tp;
    }
    row = &dst[na];
    row[0] = func_L00_00539898(dst, a, na, b[0]);
    for (;;) {
        if (--nb <= 0) return;
        row[1] = func_L00_00539520(&dst[1], a, na, b[1]);
        if (--nb <= 0) return;
        row[2] = func_L00_00539520(&dst[2], a, na, b[2]);
        if (--nb <= 0) return;
        row[3] = func_L00_00539520(&dst[3], a, na, b[3]);
        if (--nb <= 0) return;
        row[4] = func_L00_00539520(&dst[4], a, na, b[4]);
        row += 4;
        dst += 4;
        b += 4;
    }
}

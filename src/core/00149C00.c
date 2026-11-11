#include "common.h"

/* Dot product of each of ROWS rows of TAB (N floats per row) with A, into OUT. */
void func_00149C00(f32 *a, s32 n, f32 *tab, f32 *out, s32 rows)
{
    s32 i;
    s32 k;
    f32 sum;
    f32 *rp;
    f32 *ap;
    f32 *row;

    for (i = 0; i < rows; i++) {
        sum = 0.0f;
        row = tab + i * n;
        if (n > 0) {
            rp = row;
            ap = a;
            k = n;
            do {
                sum += *rp++ * *ap++;
            } while (--k != 0);
        }
        out[i] = sum;
    }
}

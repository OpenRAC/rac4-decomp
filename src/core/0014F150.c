#include "common.h"

extern f32 *D_0016F820[];

// Computes a 44-entry recurrence over the input coefficients and scales each result by a table.
void func_0014F150(f32 *a, f32 *out, f32 first) {
    s32 i;
    s32 j;
    s32 n = 12;
    f32 sum;

    out[0] = first;
    for (i = 1; n >= i; i++) {
        sum = -(f32)i * a[i];
        for (j = 1; j < i; j++) {
            sum -= a[j] * out[i - j];
        }
        out[i] = sum;
    }
    for (; i < 44; i++) {
        sum = 0.0f;
        for (j = 1; j <= 12; j++) {
            sum -= a[j] * out[i - j];
        }
        out[i] = sum;
    }
    for (i = 1; i < 44; i++) {
        out[i] = D_0016F820[0][i] * out[i];
    }
}

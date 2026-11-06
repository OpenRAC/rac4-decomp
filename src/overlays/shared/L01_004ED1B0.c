/* cflags: -O2 -G8 */
#include "common.h"

extern int D_0021E824;
extern int func_00665A28(int);

/* Clear the float result when a linked entry passes either retail test. */
float func_L01_004ED1B0(float a1, int unused, int a2)
{
    int v3;

    if (!*(int *)(a2 + 32)) return a1;
    v3 = *(int *)(a2 + 32);
    if (D_0021E824 == 1) return a1;
    while (v3) {
        if (func_00665A28(v3) || *(short *)(v3 + 188) == 9867) {
            a1 = 0.0f;
            break;
        }
        v3 = *(int *)(v3 + 184);
    }
    return a1;
}

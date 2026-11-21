/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_00498D94[];
extern s32 D_00498D98[];

// Busy-wait loops running D_00498D98 then D_00498D94 times.
void func_L00_004F7168(void) {
    s32 i;
    s32 j;
    s32 n;
    s32 m;

    n = D_00498D98[0];
    if (n > 0) {
        for (i = 0; i < n; i++) {
        }
    }
    m = D_00498D94[0];
    if (m > 0) {
        for (j = 0; j < m; j++) {
        }
    }
}

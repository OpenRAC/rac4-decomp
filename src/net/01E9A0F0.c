/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001AD1EC;
extern s32 D_001AD1E8;
extern s32 func_0012C888(s32, s32, s32, s32 *);
extern s32 func_0012CA90(s32);
s32 func_01E9A0F0(void) {
    s32 x;
    if (D_001AD1EC != 0) {
        if (func_0012C888(D_001AD1E8, 0, 0, &x) >= 0) {
            x = func_0012CA90(D_001AD1E8);
            if (x >= 0) {
                D_001AD1EC = 0;
                x = 0;
            }
        }
    }
    return x;
}

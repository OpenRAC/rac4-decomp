/* Not matching yet: BYTES 94/172 (tools/try_func.py func_01EAA708 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_00168B84;
extern s32 *D_00168B8C;
extern s32 D_00168B90;
extern u32 D_1B23BC;
extern u32 D_1B23C0;

s32 func_01EAA708(u32 *arg0, u32 arg1, s32 arg2) {
    s32 r = 5;
    u32 n;
    if (D_00168B84 == 1) {
        if (D_00168B8C != 0) {
            if (D_00168B90 != 0) {
                r = 2;
                if (arg0 != 0) {
                    if (arg1 < D_1B23C0) {
                        n = *(u32 *)(D_00168B90 + arg1 * 4);
                        r = 0x3EB;
                        if (n <= D_1B23BC) {
                            *(u32 *)(D_00168B90 + arg1 * 4) = n + 1;
                            r = 0;
                            *arg0 = n;
                            D_00168B8C[arg1 * D_1B23BC + n] = arg2;
                        }
                    }
                }
            }
        }
    }
    return r;
}

/* Not matching yet: SIZE ours 92 / retail 72 (tools/try_func.py func_L00_0073D9E8 --diff). Not part of the build. */
/* cflags: -O2 -G8 */
#include "common.h"

extern s32 func_0011D9A8(void *p, const char *fmt, ...);
extern s8 D_00221170[];
extern s32 D_00221100;
extern s32 D_00221104;
extern s8 D_00221109;

s32 func_L00_0073D9E8(s32 unused0, u8 *arg1) {
    (void)unused0;

    if (func_0011D9A8(arg1 + 0x1B, D_00221170, &D_00221100, &D_00221104) != 2) {
        D_00221104 = -1;
        D_00221100 = -1;
    }
    D_00221109 = 0;
    return 2;
}

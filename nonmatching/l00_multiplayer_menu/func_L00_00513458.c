/* Not matching yet: BYTES 27/88 (tools/try_func.py func_L00_00513458 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G8 -falign-loops=1 */
#include "common.h"

extern u8 D_004889E4[];
extern s32 func_L00_00509438(s32, s32, s32, s32, s32);

s32 func_L00_00513458(s32 arg0) {
    s32 base = (s32)D_004889E4;
    s32 r = func_L00_00509438(base, 0x10000 + base, 0x10130 + base, arg0,
                              0x10100 + base);
    if (r < 0) {
        return r;
    }
    return 0x90;
}

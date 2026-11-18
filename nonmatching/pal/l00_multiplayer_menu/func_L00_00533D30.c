/* Not matching yet: BYTES 13/216 (10 words differ). The loop allocates v0/v1 in the opposite order; signed nibble extraction, calls and size agree. Reproduce: python tools/check_func.py --version pal func_L00_00533D30 nonmatching/pal/l00_multiplayer_menu/func_L00_00533D30.c --diff. Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef void (*Codec)(s32, s32, s32, s32, s32);
extern s32 func_L00_00546148(s32);
extern Codec D_004A2FD0[];

s32 func_L00_00533D30(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 packed = func_L00_00546148(arg3);
    s32 count = (u32)packed >> 28;
    s32 i;
    for (i = 0; i < count; i++) {
        D_004A2FD0[(packed >> (i * 4)) & 0xF](arg0, arg1, arg2, arg4, arg5);
    }
    return 0;
}

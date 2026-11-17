/* Not matching yet: 10/18 (55.56%) relocation-masked positional words; 72/72 candidate/target bytes. Indirect callee and float/return ABI remain hypotheses. Reproduce: python tools/check_func.py --version pal func_01EECC40 nonmatching/pal/net/func_01EECC40.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
typedef s32 (*Method)(void **, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);
/* Calls the method at offset 0x44 with the default limit. */
s32 func_01EECC40(void **object, s32 first, s32 second, f32 a, f32 b, f32 c, f32 d)
{
    Method method = *(Method *)((u8 *)*object + 0x44);
    return method(object, 0, first, second, 1, 0, 0, 0, a, b, c, d, 200000.0f);
}

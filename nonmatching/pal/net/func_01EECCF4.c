/* Not matching yet: 14/17 (82.35%) relocation-masked positional words; 68/68 candidate/target bytes. Indirect method prototype and return type remain hypotheses. Reproduce: python tools/check_func.py --version pal func_01EECCF4 nonmatching/pal/net/func_01EECCF4.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -fno-schedule-insns2 -Wuninitialized */
#include "common.h"
typedef s32 (*Method)(void **, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);
void func_01EECCF4(void **arg0, s32 arg1, s32 arg2, s32 arg3, f32 a, f32 b, f32 c, f32 d, f32 e) {
    ((Method *)((u8 *)*arg0 + 0x44))[0](arg0, arg1, arg2, arg3, 1, 0, 0, 0, a, b, d, e, 100000.0f);
}

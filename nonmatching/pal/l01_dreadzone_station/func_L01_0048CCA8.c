/* Not matching yet: 11/18 (61.11%) relocation-masked positional words; 72/72 candidate/target bytes. Float-register caller/callee contract remains unresolved. Reproduce: python tools/check_func.py --version pal func_L01_0048CCA8 nonmatching/pal/l01_dreadzone_station/func_L01_0048CCA8.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
f32 func_L01_005DAE60(s32, f32, f32, s32, f32);
void func_L01_0048CCA8(void *a, void *b, f32 c) {
    if (*(u8 *)((u8 *)a + 0x20) != 4 || *(u8 *)((u8 *)b + 0x168) == 0) {
        func_L01_005DAE60(*(s32 *)((u8 *)b + 0x1b0), *(f32 *)((u8 *)b + 0xdac), *(f32 *)((u8 *)b + 0x1b4), 1, c);
    }
}

/* Not matching yet: 15/20 (75.00%) relocation-masked positional words; 80/80 candidate/target bytes. Global ownership and return ABI remain unproved. Reproduce: python tools/check_func.py --version pal func_L01_004BE7C0 nonmatching/pal/l01_dreadzone_station/func_L01_004BE7C0.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern s64 func_0045E0A0(s32);
extern u8 D_003AADF8[];
s32 func_L01_004BE7C0(void *arg0) {
    s32 *p = (s32 *)(D_003AADF8 + *(s32 *)(*(u8 **)((u8 *)arg0 + 0xAC) + 0xC) * 16);
    s64 result = 0;
    if (*p != -1) result = func_0045E0A0(*(s16 *)p) != 0;
    return result;
}

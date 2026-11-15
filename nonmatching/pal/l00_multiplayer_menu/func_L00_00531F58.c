/* Not matching yet: 7/19 (36.84%) relocation-masked positional words; 80/76 candidate/target bytes. One extra word; callee argument contract remains unresolved. Reproduce: python tools/check_func.py --version pal func_L00_00531F58 nonmatching/pal/l00_multiplayer_menu/func_L00_00531F58.c --diff. Not part of the build. */
/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
extern void func_L00_005337F8(s32, s32, s32);
extern void func_00403440();
s32 func_L00_00531F58(s32 *a1)
{
    s32 result = 0;
    if (a1) {
        result = *a1;
        if (result) {
            func_L00_005337F8(result, 0, a1[1]);
            func_00403440(*a1);
            result = 0;
        }
    }
    return result;
}

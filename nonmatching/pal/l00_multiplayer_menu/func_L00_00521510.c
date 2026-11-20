/* Not matching yet on PAL: 13/15 positional words match (86.67%); 2 differ, size 52/60 bytes (delta -8). */
/* cflags: @ee29 -O2 -G0 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_00521510 nonmatching/pal/l00_multiplayer_menu/func_L00_00521510.c --diff
 * Two catalogue words follow the return; their ownership is unresolved. The callback signature and data declaration are inferred. */
#include "common.h"

extern s32 (*D_004A1950)();

s32 func_L00_00521510(void)
{
    if (D_004A1950 != NULL) {
        return D_004A1950();
    }
    return 0;
}
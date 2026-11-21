/* Not matching yet on PAL: 18/18 positional words match (100.00%); 0 differ, size 72/72 bytes (delta 0). */
/* cflags: -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_00734A88 nonmatching/pal/l00_multiplayer_menu/func_L00_00734A88.c --diff
 * D_00221038 collides with existing logical owners; its PAL data binding needs reconciliation. */
#include "common.h"
#include "pal/profile_001721E0.h"
#include "pal/global_002234A4.h"
extern char D_00221038[];
extern s32 func_L00_00773AF8(u8 *, s32, char *, s32, s32, s32, s32);
s32 func_L00_00734A88(s32 unused, s32 id)
{
    u8 *state = *(u8 **)((u8 *)D_002234A4 + 0x48);
    D_001721E0.f14 = 1;
    return func_L00_00773AF8(state, id, D_00221038, 0, 0, 0, -1);
}

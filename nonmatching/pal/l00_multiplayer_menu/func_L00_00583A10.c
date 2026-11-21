/* Not matching yet on PAL: 20/20 positional words match (100.00%); 0 differ, size 80/80 bytes (delta 0). */
/* cflags: -O2 -G8 -Wuninitialized */
/* Relocation fields are masked. Reproduce: tools/check_func.py --version pal func_L00_00583A10 nonmatching/pal/l00_multiplayer_menu/func_L00_00583A10.c --diff
 * The PAL data name D_00222350 conflicts with an existing logical C owner; callee signatures remain unresolved. */
#include "pal/display_00206AC0.h"
extern s32 D_00222350;
extern void func_0044E528(s32, s32, s32, s32);
extern void func_0044A540(s32, s32, s32, s32, u64);

void func_L00_00583A10(void)
{
    func_0044E528((s32)&D_00222350, 66, 72, 0);
    func_0044A540(0, D_00206AC0.height, 0, D_00206AC0.width, -2139062144);
}

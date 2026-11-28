#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/multiplayer_menu.h"

extern s32 func_L00_007697C0(s32 identifier);

/* Pick a menu mode from the profile word at +0x3C and store it on the context. */
s32 func_L00_0072AC80(void) {
    s32 *profile = *(s32 **)((u8 *)D_002234A4 + 0x3C);

    if (*profile == -1) {
        func_L00_007697C0(0x3D);
        *(s32 *)((u8 *)D_00220DD4 + 0x118) = 7;
        return 1;
    }
    if (*((u8 *)profile + 0x30) != 0) {
        return 0;
    }
    func_L00_007697C0(0x3D);
    *(s32 *)((u8 *)D_00220DD4 + 0x118) = 5;
    return 1;
}

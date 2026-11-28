/* cflags: -Wuninitialized */
#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/multiplayer_menu.h"
#include "pal/profile_001721E0.h"

extern char D_L00_00221038[];

s32 func_L00_00734A88(PalMultiplayerMenu *menu, s32 id)
{
    u8 *state = *(u8 **)((u8 *)D_002234A4 + 0x48);

    D_001721E0.f14 = 1;
    return func_L00_00773AF8(state, id, D_L00_00221038, 0, 0, 0, -1);
}

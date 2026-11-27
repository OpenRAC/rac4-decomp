/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/multiplayer_menu.h"

extern void *D_00220DD4;

void func_L00_0074EFF8(PalMultiplayerMenu *menu)
{
    ((u8 *)D_00220DD4)[0x114] = ((u8 *)menu)[0x260];
    func_L00_0071F2E0(menu);
    func_L00_0071FCE8((s32)menu);
}

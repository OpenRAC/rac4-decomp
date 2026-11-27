/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/global_002234A4.h"
#include "pal/multiplayer_menu.h"

extern void *func_L00_0070DEB0(void *owner);
extern void *func_L00_0070DF20(void *owner);
extern u8 D_L00_00220AD0;
extern u8 D_L00_00220AD1;

void func_L00_00739470(PalMultiplayerMenu *menu)
{
    D_L00_00220AD0 = 0;
    D_L00_00220AD1 = 0;
    func_L00_0070DF20(NULL);
    func_L00_0070DEB0(NULL);
    (*(u8 **)((u8 *)D_002234A4 + 0x44))[0x14] = 0;
    func_L00_0071F2E0(menu);
    func_L00_0071FCE8((s32)menu);
}

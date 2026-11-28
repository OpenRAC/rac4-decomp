#ifndef PAL_MULTIPLAYER_MENU_H
#define PAL_MULTIPLAYER_MENU_H

#include "common.h"

typedef struct Type1 PalMultiplayerMenu;

extern struct Context *D_00220DD4;

void func_L00_0071F2E0(PalMultiplayerMenu *menu);
void func_L00_0071FCE8(s32 menu);
s32 func_L00_00773AF8(u8 *state, s32 id, char *name, s32 mode, s32 arg4, s32 arg5, s32 arg6);

#endif

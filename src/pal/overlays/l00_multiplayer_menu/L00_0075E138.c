#include "common.h"
#include "pal/menu_handoff.h"
#include "pal/multiplayer_menu.h"

typedef struct {
    u8 pad[0x2A8];
    PalMenuHandoffChild *child;
    u8 f2AC;
    u8 f2AD;
    u8 pad2AE[2];
    s32 f2B0;
    s32 f2B4;
} PalMenuHandoff;

void func_L00_0075E138(PalMultiplayerMenu *menu) {
    PalMenuHandoff *handoff = (PalMenuHandoff *)menu;
    PalMenuHandoffChild *child;
    u8 fA8;
    u8 fA9;

    D_00220AD1 = 0;
    D_00220AD0 = 0;
    child = handoff->child;
    child->methods->refresh(child);
    fA8 = handoff->f2AC;
    handoff->child->fA8 = fA8;
    fA9 = handoff->f2AD;
    handoff->child->fA9 = fA9;
    handoff->child->f250 = handoff->f2B0;
    handoff->child->f254 = handoff->f2B4;
    func_L00_0071F2E0(menu);
    func_L00_0071FCE8((s32)menu);
}

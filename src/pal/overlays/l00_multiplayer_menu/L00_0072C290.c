#include "common.h"
#include "pal/menu_handoff.h"
#include "pal/multiplayer_menu.h"

typedef struct {
    u8 pad[0x2870];
    PalMenuHandoffChild *child;
    u8 f2874;
    u8 f2875;
    u8 pad2876[2];
    s32 f2878;
    s32 f287C;
} PalHandoff;

extern void *func_L00_0070DEB0(void *);
extern void *func_L00_0070DF20(void *);
/* Clear the handoff flags, refresh the child, and copy its menu fields. */
void func_L00_0072C290(PalMultiplayerMenu *menu) {
    PalHandoff *handoff = (PalHandoff *)menu;
    PalMenuHandoffChild *child;
    u8 fA8;
    u8 fA9;

    D_00220AD0 = 0;
    D_00220AD1 = 0;
    func_L00_0070DEB0(NULL);
    func_L00_0070DF20(NULL);
    child = handoff->child;
    child->methods->refresh(child);
    handoff->child->f264 = 1;
    fA8 = handoff->f2874;
    handoff->child->fA8 = fA8;
    fA9 = handoff->f2875;
    handoff->child->fA9 = fA9;
    handoff->child->f250 = handoff->f2878;
    handoff->child->f254 = handoff->f287C;
    func_L00_0071F2E0(menu);
    func_L00_0071FCE8((s32)menu);
}

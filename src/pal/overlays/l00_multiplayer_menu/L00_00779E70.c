#include "common.h"
#include "pal/profile_001721E0.h"

typedef struct MenuState {
    u8 opaque00[0x11E];
    u8 f11E;
} MenuState;
typedef struct MenuContext {
    u8 opaque00[0x64];
    MenuState *state;
} MenuContext;

extern s32 func_L00_0077F558(MenuState *);
extern s32 func_01ED5D68(void);
extern s32 func_0015DA28(void);

s32 func_L00_00779E70(MenuContext *context);

s32 func_L00_00779E70(MenuContext *context) {
    MenuState *state;

    ((u8 *)&D_001721E0)[0x2D4] = 0;
    state = context->state;
    if (state->f11E != 0) {
        func_L00_0077F558(state);
    }
    func_01ED5D68();
    func_0015DA28();
    return 1;
}

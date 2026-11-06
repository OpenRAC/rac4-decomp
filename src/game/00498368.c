#include "common.h"

extern u8 D_0021EE18;
extern s32 *D_0021DDA4;
extern char *D_0021DDCC;
extern s32 func_00497458(s32 playerIndex, u32 previousState);
extern char *func_00510BE8(s32 playerIndex);
extern s32 func_004984B8(u32 mask);

s32 func_00498368(s32 playerIndex, u32 previousState)
{
    char *state = NULL;

    if (func_00497458(playerIndex, previousState)) {
        if (D_0021EE18) {
            state = D_0021DDCC;
        } else if (playerIndex < *D_0021DDA4) {
            state = *(char **)(func_00510BE8(playerIndex) + 0x2F00);
        }
    }
    if (state != NULL) {
        s32 result = func_004984B8(*(u32 *)(state + 0x1C4));
        *(u32 *)(state + 0x1C4) = 0;
        return result;
    }
    return 0;
}

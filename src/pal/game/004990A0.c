#include "common.h"

extern u8 D_0021EE98;
extern s32 *D_0021DE2C;
extern char *D_0021DE54;
extern s32 func_004980B0(s32 playerIndex, u32 previousState);
extern char *func_00511CC0(s32 playerIndex);
extern s32 func_004991F0(u32 mask);

s32 func_004990A0(s32 playerIndex, u32 previousState)
{
    char *state = NULL;

    if (func_004980B0(playerIndex, previousState)) {
        if (D_0021EE98) {
            state = D_0021DE54;
        } else if (playerIndex < *D_0021DE2C) {
            state = *(char **)(func_00511CC0(playerIndex) + 0x2F00);
        }
    }
    if (state != NULL) {
        s32 result = func_004991F0(*(u32 *)(state + 0x1C4));
        *(u32 *)(state + 0x1C4) = 0;
        return result;
    }
    return 0;
}

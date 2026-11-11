#include "common.h"
/* Ported from rac3-decomp's func_L39_004E2D20 (src/levels/39_multiplayer_menu/L39_004E2D20.c, GPL-3.0), the same code in both games. */

extern void *func_L00_004FACD8(s32);
extern u8 D_004A18B0[];
void *func_L00_0051EB20(void) {
    u8 *object = func_L00_004FACD8(0x10);
    if (object != 0) {
        *(s32 *)(object + 0xC) = 1;
        *(s32 *)object = (s32)D_004A18B0;
        *(s32 *)(object + 4) = 0;
        *(s32 *)(object + 8) = 0;
        return object;
    }
    return 0;
}

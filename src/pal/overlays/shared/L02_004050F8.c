#include "common.h"

extern s32 D_0021E774;
extern s32 D_0021E778;

s32 func_L02_004050F8(void *arg0) {
    void *temp_a0;

    temp_a0 = (*(void **)((s8 *)(arg0) + (0xAC)));
    if ((D_0021E774 == 0) && (D_0021E778 == 1) && ((*(s32 *)((s8 *)(temp_a0) + (0x58))) == 0x1F7)) {
        return 1;
    }
    return (*(s32 *)((s8 *)(temp_a0) + (4))) >= (*(s32 *)((s8 *)(temp_a0) + (0x54)));
}

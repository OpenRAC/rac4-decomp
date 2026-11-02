#include "common.h"

extern s32 D_00379F60[];

// Clear the 256-entry table.
void func_L41_0044C630(void) {
    s32 i;
    for (i = 0x3F; i >= 0; i--) {
        D_00379F60[i] = 0;
    }
}

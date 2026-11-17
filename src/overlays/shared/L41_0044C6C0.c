#include "common.h"

extern s32 D_379F60[];

// Clears the first slot of a 64-entry table that holds arg0; returns 1 if found.
s32 func_L41_0044C6C0(s32 arg0) {
    s32 i;
    s32 ok = 0;

    for (i = 0; i < 0x40; i++) {
        if (D_379F60[i] == arg0) {
            D_379F60[i] = 0;
            ok = 1;
            break;
        }
    }
    return ok;
}

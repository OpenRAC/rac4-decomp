#include "common.h"

extern s32 D_003D2708[];

/* Entry i of the word table D_003D2708, or -1 for i 8 and 9. */
s32 func_004CCFD8(s32 i) {
    if ((u32)(i - 8) < 2) {
        return -1;
    }
    return D_003D2708[i];
}

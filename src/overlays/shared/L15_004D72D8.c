#include "common.h"

extern s32 D_39FE50[];

// Test bit arg0 in the word table.
s32 func_L15_004D72D8(s32 arg0) {
    return D_39FE50[arg0 >> 5] & (1 << (arg0 & 0x1F));
}

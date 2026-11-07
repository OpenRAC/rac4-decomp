#include "common.h"

extern s32 func_00498540(s32, s32);
extern s32 D_003D8CF0[];

s32 func_004984B8(s32 arg0) {
    s32 i;

    for (i = 0; i < 15; i++) {
        if (func_00498540(arg0, i) != 0) {
            if (D_003D8CF0[i] != 0x100) {
                return i;
            }
            return 13;
        }
    }
    return 0;
}

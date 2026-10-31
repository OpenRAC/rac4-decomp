#include "common.h"

s32 func_004CC7A0();
extern s32 D_0021EDD4;
extern s32 D_0021EDD8;

// Call func_004CC7A0 unless the two flags are in their default state and arg0 is below 4.
s32 func_004CC0B8(s32 arg0) {
    if (D_0021EDD4 == 0 && D_0021EDD8 == 1 && arg0 < 4) {
        return 0;
    }
    return func_004CC7A0();
}

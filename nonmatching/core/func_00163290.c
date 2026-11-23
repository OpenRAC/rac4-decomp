/* Not matching yet: BYTES 60/112 (tools/try_func.py func_00163290 --diff). Not part of the build. */
#include "common.h"

extern u8 D_21DC18[];
extern u8 D_21DC20[];

s32 D_0021E0D8[2] = {0};

/* Returns whether slot arg0 is free, with a special case for marked slots. */
s32 func_00163290(s32 arg0) {
    if (D_0021E0D8[arg0] == 1) {
        if (D_21DC18[arg0] != 0 || D_21DC20[arg0] != 0) {
            return 0;
        }
        return 1;
    }
    return D_21DC18[arg0] == 0 ? 1 : 0;
}

#include "common.h"

extern s32 D_00385D10[];

// Look up arg0 in the 18-entry id/value table and return its value, else 0.
s32 func_L41_0043A5A8(s32 arg0) {
    s32 result = 0;
    s32 i;
    for (i = 0; i < 18; i++) {
        if (D_00385D10[i * 2] == arg0) {
            result = *(s32 *)((char *)D_00385D10 + (i << 3) + 4);
            break;
        }
    }
    return result;
}

#include "common.h"

extern s32 D_003860A0[];

// Look up arg0 in the 18-entry id/value table and return its value, else 0.
s32 func_L41_00447520(s32 arg0) {
    s32 result = 0;
    s32 i;
    for (i = 0; i < 17; i++) {
        if (D_003860A0[i * 2] == arg0) {
            result = *(s32 *)((char *)D_003860A0 + (i << 3) + 4);
            break;
        }
    }
    return result;
}

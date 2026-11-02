#include "common.h"

// Returns one of two constants depending on whether the byte at arg0 is nonzero.
s32 func_L00_00659C00(u8 *arg0) {
    s32 r = 0x80404040;

    if (*arg0 == 0) {
        r = 0x80808080;
    }
    return r;
}

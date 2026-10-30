#include "common.h"

// Stores the word arg1 at offset 0x70 of arg0; returns 0xD2F2 if arg0 is null, else 0.
s32 func_01EBDE60(u8 *arg0, s32 arg1) {
    s32 res = 0xD2F2;

    if (arg0) {
        *(s32 *)(arg0 + 0x70) = arg1;
        res = 0;
    }
    return res;
}

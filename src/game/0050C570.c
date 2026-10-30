#include "common.h"

extern s32 func_0050C568(void *object);

// Return the word at +0x40 of entry arg1 (4-byte entries from arg0) when arg1 is below the count from func_0050C568; otherwise return 0.
s32 func_0050C570(s32 arg0, s32 arg1) {
    if (arg1 < func_0050C568(arg0)) {
        return *(s32 *)(arg0 + arg1 * 4 + 0x40);
    }
    return 0;
}

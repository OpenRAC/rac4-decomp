/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_00409F88(s32, s32, s32);

// XOR each word from p up to end with a key, where the callee says the word is in range.
s32 func_00404E18(s32 p, s32 end, s32 base, s32 a3, s32 a4) {
    for (; p < end; p += 4) {
        if (func_00409F88(p - base, a3, a4) > 0) {
            *(s32 *)p = *(s32 *)p ^ 0xA95128C3;
        }
    }
    return 0;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01ED9B90(void *, void *, s32, s32, s32);
// Passes a fixed status and duration to the callback helper.
s32 func_01ED9BE8(void *object, void *state) {
    return func_01ED9B90(object, state, -0x3C6, 0x12C, 0);
}

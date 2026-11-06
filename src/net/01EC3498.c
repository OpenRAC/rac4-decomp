/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern u8 D_001B69C0[];
extern s32 func_01EA9ED8(void *, s32 *);
// Calls the context helper without requesting its optional output.
s32 func_01EC3498(void) {
    return func_01EA9ED8(D_001B69C0, NULL);
}

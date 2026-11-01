/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(const char *, s32);
extern char D_0019C2D8[];
/* Calls the handler with the fixed string and code, then returns zero. */
s32 func_01EED4D8(void) {
    func_01F0C090(D_0019C2D8, 0xE7);
    return 0;
}

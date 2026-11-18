/* PAL code and relocations match all 16 bytes. The native source name is already owned by src/net/01EED598.c. */
/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_0021DA30[];

// Returns the word stored at D_0021DA30.
s32 func_01EED598(void) {
    return D_0021DA30[0];
}

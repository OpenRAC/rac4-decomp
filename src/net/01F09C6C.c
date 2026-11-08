/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

s32 func_01F0C090(void *, s32);
extern s32 D_0019E5C0[];

s32 func_01F09C6C(s32 *arg0) {
    if (*arg0 == 0) {
        func_01F0C090(D_0019E5C0, 0x30);
    }
    return *arg0;
}

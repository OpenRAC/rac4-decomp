/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"

/* Store the state selected by the second argument. */
void func_L00_007833B0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        *(s32 *)((u8 *)arg0 + 0x3FC) = 4;
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x3FC) = 3;
}

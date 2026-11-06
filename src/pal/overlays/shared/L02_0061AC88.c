/* cflags: -O2 -G8 -fopt-stack -mno-check-zero-division -mno-split-addresses */
#include "common.h"
s32 func_L02_0061AC88(void *actor)
{
    void *state;
    if (actor == 0 || (state = *(void **)((u8 *)actor + 172)) == 0) {
        return 0;
    }
    return *(s32 *)((u8 *)state + 224);
}

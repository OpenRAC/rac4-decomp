#include "common.h"

extern s32 func_004776D8(void *);

/* Returns 0 or 1 from the state at +0xBC of arg1, a vtable call on arg2 and the flag at +0x2318 of arg0. */
s32 func_00526D38(void *arg0, void *arg1, void *arg2)
{
    s32 (*vfn)(void *, s32);

    if (((s16 *)arg1)[0x5E] == 0x109D) {
        vfn = (s32 (*)(void *, s32)) ((s32 *)((s32 *)arg2)[5])[7];
        if (vfn(arg2, -1) != 0) {
            return 1;
        }
    }
    if (func_004776D8(arg1) != 0) {
        return 1;
    }
    if (((s16 *)arg1)[0x5E] == 0x253A) {
        if (((s32 *)arg0)[0x8C6] != 0xD) {
            return 1;
        }
    }
    return 0;
}

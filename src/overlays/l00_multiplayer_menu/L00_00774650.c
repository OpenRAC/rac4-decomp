#include "common.h"

extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern s32 func_0015B558(void);

/* Starts the block at +0x10 and +0x14 when its checks pass: returns 0 then, else 1. */
s32 func_L00_00774650(u8 *arg0, s32 arg1)
{
    s32 ok;
    s32 v1;
    s32 r;
    s32 x;

    ok = 1;
    r = func_0015B558();
    if (arg1 != 0 && r != 0) {
        v1 = 8;
        goto block6;
    }
    if (arg0[0] != 0 && *(s32 *)(arg0 + 8) != 0 && *(s32 *)(arg0 + 0xC) > 0) {
        x = (s32)func_0012FEB0(func_0012E370(), 0x24000);
        if (*(s32 *)(arg0 + 0xC) < x - *(s32 *)(arg0 + 8)) {
            v1 = 2;
            goto block6;
        }
    }
    goto done;
block6:
    *(s32 *)(arg0 + 0x10) = v1;
    if (*(s32 *)(arg0 + 0x14) == 0) {
        *(s32 *)(arg0 + 0x14) = v1;
    }
    ok = 0;
done:
    return ok;
}

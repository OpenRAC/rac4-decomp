/* Not matching yet: BYTES 15/76; mask-before-store folds to the wrong slots (tools/try_func.py func_0048EC08 --diff). Not part of the build. */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_0048E670(u32 id, void *src, s32 arg);

/* Snapshot SRC into OBJ, look OBJ's id up, then patch the snapshot's last word. */
void func_0048EC08(u8 *arg0, u8 *arg1)
{
    u128 tmp;
    u32 w;
    s32 r;

    tmp = *(u128 *)arg1;
    w = *(volatile s32 *)(arg0 + 0xC) & 0xFFFF;
    *(u128 *)arg0 = tmp;
    r = func_0048E670(w, arg1, 0);
    tmp = *(u128 *)arg0;
    *(s32 *)((u8 *)&tmp + 0xC) = r;
    *(u128 *)arg0 = tmp;
}

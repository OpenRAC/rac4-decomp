#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern s32 func_0048D060(void *, s32);

// Copy 16 bytes from arg1 to arg0, call func_0048D060 on arg1, and store its result in the last word.
void func_0048EBC0(u8 *arg0, u8 *arg1) {
    u128 tmp;
    s32 r;

    *(u128 *)arg0 = *(u128 *)arg1;
    r = func_0048D060(arg1, 0);
    tmp = *(u128 *)arg0;
    *(s32 *)((u8 *)&tmp + 0xC) = r;
    *(u128 *)arg0 = tmp;
}

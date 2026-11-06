#include "common.h"

extern s32 func_0053CA40(s32 *, s32);
extern void *func_0053C920(s32 *, s32, s32, s32);
extern void func_0053CAA8(void *, void *, s32);

/* Creates an entry and writes two byte selectors. */
void func_005263E0(s32 *a, s32 b, s32 c)
{
    u8 x;
    void *p;
    if (!func_0053CA40(a, 6)) {
        p = func_0053C920(a, 6, 0, 0);
        x = b;
        func_0053CAA8(p, &x, 1);
        x = c;
        func_0053CAA8(p, &x, 1);
    }
}

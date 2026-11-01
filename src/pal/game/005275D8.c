#include "common.h"

extern s32 func_0053DDF0(s32 *, s32);
extern void *func_0053DCD0(s32 *, s32, s32, s32);
extern void func_0053DE58(void *, void *, s32);

/* Creates an entry and writes two byte selectors. */
void func_005275D8(s32 *a, s32 b, s32 c)
{
    u8 x;
    void *p;
    if (!func_0053DDF0(a, 6)) {
        p = func_0053DCD0(a, 6, 0, 0);
        x = b;
        func_0053DE58(p, &x, 1);
        x = c;
        func_0053DE58(p, &x, 1);
    }
}

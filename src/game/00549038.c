#include "common.h"

extern s32 func_0011D920(s8 *arg0, s8 *arg1, ...);
extern s32 func_0045E038(s32);
extern void func_00547B08(s8 *, s32, s32);
extern void *func_00548D28(s32, s32);
extern s8 D_00220EB8[];

// Formats a string from two looked-up names and a counter, then passes it to func_00547B08
void func_00549038(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s8 buf[0x80];
    s32 id;
    s8 *fmt;
    s32 a;

    if (arg2 > 0 && arg0 > 0 && arg1 >= 0 && arg3 >= 0) {
        id = (arg0 == 2) ? 0x25A5 : 0x2557;
        fmt = D_00220EB8;
        a = func_0045E038(*(s16 *)((u8 *)func_00548D28(arg0, 0) + 8));
        func_0011D920(buf, fmt, a, func_0045E038(id), arg3 + 1);
        func_00547B08(buf, arg1, arg2);
    }
}

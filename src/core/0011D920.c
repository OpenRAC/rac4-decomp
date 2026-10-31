#include "common.h"

extern s32 func_00122A28(void *, s8 *, s8 *);
extern s32 D_00163E74_[];
#define D_00163E74 (D_00163E74_[0])

/* Formats the varargs into arg0 with no size limit (fmt in arg1); writes a NUL at arg0 when done. */
s32 func_0011D920(s8 *arg0, s8 *arg1, ...) {
    u8 s[0x58];
    s8 *ap;
    s32 n;

    *(s32 *)(s + 0x8) = 0x7FFFFFFF;
    *(s32 *)(s + 0x14) = 0x7FFFFFFF;
    *(s16 *)(s + 0xC) = 0x208;
    *(s32 *)(s + 0x0) = (s32)arg0;
    *(s32 *)(s + 0x10) = (s32)arg0;
    *(s32 *)(s + 0x54) = D_00163E74;
    ap = (s8 *)__builtin_next_arg(arg1) - 0x30;
    n = func_00122A28(s, arg1, ap);
    **(s8 **)s = 0;
    return n;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

/* calls a stored callback with resolved register arguments, counting a use around the call */
s32 func_L00_00552648(u8 *a0, s32 a1, s32 a2, s32 a3, s32 t0) {
    s64 b, c, d;
    s32 fn;
    s32 idx, res;
    s32 flag;
    u8 *s0 = 0;

    fn = *(s32 *)(a0 + 0xC8);
    if (fn == 0) return 2;
    if (a2 & 0x80) d = *(s64 *)(a0 + 0x48 + ((a2 & 0xF) << 3)); else d = a2;
    if (a3 & 0x80) b = *(s64 *)(a0 + 0x48 + ((a3 & 0xF) << 3)); else b = a3;
    if (t0 & 0x80) c = *(s64 *)(a0 + 0x48 + ((t0 & 0xF) << 3)); else c = t0;
    idx = *(s32 *)(a0 + 0xD0);
    if (idx < 0) *(s32 *)(a0 + 0xD8) = 0;
    else *(s32 *)(a0 + 0xD8) = *(s32 *)(a0 + 0x10) + idx * 0x28;
    flag = a1 == 1;
    if (flag) {
        s0 = *(u8 **)(a0 + 0xD8);
        if (*(s64 *)s0 == 0) return 3;
        *(s32 *)(s0 + 8) = *(s32 *)(s0 + 8) + 1;
        *(s64 *)s0 = *(s64 *)s0 - 1;
        fn = *(s32 *)(a0 + 0xC8);
    }
    res = ((s32 (*)(u8 *, s32, u8 *, s64, s64, s64))fn)(a0, *(s32 *)(a0 + 0xCC), a0 + 0x48, d, b, c);
    if (flag) {
        *(s64 *)s0 = *(s64 *)s0 + 1;
        *(s32 *)(s0 + 8) = *(s32 *)(s0 + 8) - 1;
    }
    return res;
}

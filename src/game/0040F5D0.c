/* cflags: @ee296 -O2 -G0 */
#include "common.h"
typedef struct { s32 cap; s32 n; u64 *d; } S;
extern void func_00403308(void *, s32, s32);
extern void func_00403440(void *);
extern s32 func_0040EAE0(S *, S *);
extern s32 func_0040F0C0(S *);
extern s32 func_0040F728(S *, s32, s32, s32, s32, S *, u64, S *, s32);
extern s32 func_00410008(S *, S *, S *, S *, s32, s32);
extern s32 func_004101A0(S *, s32 *, s32 *, s32 *, s32 *);
extern s32 func_00410A40(S *, u64 *);
extern s32 func_00413B10(s32);
s32 func_0040F5D0(S *a, S *b, S *c, S *d, s32 q) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    u64 sp20;
    s32 r, n;
    sp18 = 0;
    sp1C = 0;
    sp14 = 0;
    for (;;) {
        r = func_00413B10(q);
        if (r != 0) break;
        if (func_0040EAE0(a, c) >= 0) { r = 0x108; break; }
        n = func_0040F0C0(b);
        if (n < 2) {
            return func_00410008(a, b, c, d, n, q);
        }
        r = func_00410A40(c, &sp20);
        if (r != 0) break;
        r = func_004101A0(b, &sp10, &sp14, &sp18, &sp1C);
        if (r == 0) {
            r = func_0040F728(a, sp14, sp18, sp10, sp1C, c, sp20, d, q);
        }
        break;
    }
    if (sp14 != 0) {
        func_00403308((void *)sp14, 0, sp18 * 4);
        func_00403440((void *)sp14);
    }
    return r;
}

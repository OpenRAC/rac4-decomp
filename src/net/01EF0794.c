/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_01EEDCD0(void *, const void *, s32);
extern s32 func_0011A8A0(void *, const u8 *);
extern s32 func_01EF09DC();
extern s8 *func_0011A700(void *, s32);

// Copies arg1 and func_01EF09DC(arg0) into two buffers, cuts each at its first 0x3F, and returns whether the two compare equal.
s32 func_01EF0794(s32 arg0, const void *arg1) {
    u8 a[0x110];
    u8 b[0x101];
    s8 *p;

    func_01EEDCD0(a, arg1, 0x101);
    func_01EEDCD0(b, (const void *)func_01EF09DC(arg0), 0x101);
    p = func_0011A700(a, 0x3F);
    if (p != 0) {
        *p = 0;
    }
    p = func_0011A700(b, 0x3F);
    if (p != 0) {
        *p = 0;
    }
    return func_0011A8A0(a, b) == 0;
}

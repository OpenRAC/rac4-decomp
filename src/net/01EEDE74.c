/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

typedef struct { char *f0; char *f4; } Type1;
extern char D_0019C3A8[];
extern void func_0011A518(void *, s32, s32);
extern s32 func_0011E948(u8 *str, s32 fmt, s32 ap);
extern void func_01F0C090(char *arg0, s32 arg1);

/* Formats into a buffer of limited size and logs when it did not fit. */
s32 func_01EEDE74(u8 *buf, s32 size, s32 fmt, ...)
{
    Type1 ap;
    s32 r;

    ap.f0 = (char *)__builtin_next_arg(fmt) - 40;
    if (!buf) func_01F0C090(D_0019C3A8, 0x71);
    func_0011A518(buf, 0, size);
    r = func_0011E948(buf, fmt, (s32)ap.f0);
    if (r == -1 || r >= size) func_01F0C090(D_0019C3A8, 0x76);
    return r;
}

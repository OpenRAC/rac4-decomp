/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(char *msg, s32 line);
extern s32 func_01EF370C(s32 size);
extern void func_01EF2700(void *p, s32 a, s32 b);
extern char D_0019C680[];

/* Allocate the 0x14C record, seed it from the two arguments and hand it back
   through OUT; a zero FLAG raises the 0x1B message first. */
void func_01EF2B9C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 *out = (s32 *)a2;
    void *p;

    if (a3 == 0) {
        func_01F0C090(D_0019C680, 0x1B);
    }
    p = (void *)func_01EF370C(0x14C);
    func_01EF2700(p, a1, a4);
    *out = (s32)p;
}

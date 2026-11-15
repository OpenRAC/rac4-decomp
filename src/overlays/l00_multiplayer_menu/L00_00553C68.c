/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    char pad[0x30];
    s32 f30;
    s32 f34;
    s64 *f38;
} Type1;
extern void *func_004FAD00(void *, s32, s32);

/* Grows a 64-bit value stack if needed, then pushes flagged entries from a list in reverse. */
s32 func_L00_00553C68(Type1 *arg0, s32 *arg1, s32 arg2) {
    void *p;
    s64 *dst;
    s32 i;
    s32 n;
    s64 v;

    if (arg0->f30 + arg2 >= arg0->f34) {
        n = arg0->f34 * 8;
        p = func_004FAD00(arg0->f38, n | 6, n);
        if (p == NULL) {
            return 3;
        }
        arg0->f38 = p;
        arg0->f34 += 6;
    }
    for (i = arg2 - 1; i >= 0; i--) {
        if (arg1[i] & 0x80) {
            dst = (s64 *)((arg0->f30++ << 3) + (u32)arg0->f38);
            if (arg1[i] & 0x80) {
                v = ((s64 *)arg0)[(arg1[i] & 0xF) + 9];
            } else {
                v = arg1[i];
            }
            *dst = v;
        }
    }
    return 0;
}

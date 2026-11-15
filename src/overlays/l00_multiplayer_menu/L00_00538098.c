/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern int func_L00_005382C8(int a1, int a2);

typedef struct {
    unsigned long *f0;
    s32 f4;
    s32 f8;
} Type1;

/* grows a bit set to n words and zeroes the new words */
void func_L00_00538098(Type1 *s, s32 n) {
    s32 i;
    if (s->f4 < n) {
        if (s->f8 < n) {
            func_L00_005382C8((int)s, n);
        }
        for (i = s->f4; i < n; i++) {
            s->f0[i] = 0;
        }
    }
}

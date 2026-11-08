/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

s32 func_01EF0A58(s32);
s32 func_01EF0C54(Type1 *);
s32 func_01EF0D24(Type1 *);

void func_01EF0BA8(Type1 *arg0) {
    s32 t = func_01EF0A58(arg0->fC);
    s32 d;
    if (func_01EF0D24(arg0) != 0) {
        d = t - arg0->f4;
        arg0->f0 += d;
        arg0->f8 += d;
        arg0->f4 = 0;
        return;
    }
    func_01EF0C54(arg0);
}

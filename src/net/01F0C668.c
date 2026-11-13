/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
} Type1;

extern s32 D_0019E918[];
extern void func_0011A518(void *, s32, s32);
extern s32 func_01EF04A4(s32, s32, s32, s32, void *);
extern void func_01F0C090(void *, s32);

s32 func_01F0C668(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 v;

    arg0->f10 = arg2;
    arg0->f4 = arg3;
    if (arg3 != 0x12E) {
        if (arg0->f8 != 0) {
            func_01F0C090(D_0019E918, 0xF1);
        }
        if (arg0->f14 != 0) {
            func_01F0C090(D_0019E918, 0xF2);
        }
        v = arg4;
        if (v == 0) {
            v = arg0->f1C;
        }
        arg0->fC = v;
        arg0->f8 = func_01EF04A4(arg0->f18, v, 4, 0xFA, D_0019E918);
        func_0011A518((void *)arg0->f8, 0, v);
    }
    arg0->f14 = 0;
    return 0;
}

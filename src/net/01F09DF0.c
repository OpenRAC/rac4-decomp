/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-gcse -fno-optimize-sibling-calls */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
} Type1;

extern s32 func_01EEE13C(void);
extern s32 func_01EF04A4(s32, s32, s32, s32, s32);
extern void func_01F0C090(s32 *, s32);
extern s32 D_0019E5C0[];

void func_01F09DF0(Type1 *arg0)
{
    s32 temp;

    if ((arg0->f0 != 0) || (arg0->f4 != 0)) {
        func_01F0C090(D_0019E5C0, 0x50);
    }
    temp = func_01EEE13C();
    arg0->f0 = func_01EF04A4(temp, 0x20, 0, 0x52, D_0019E5C0);
    arg0->f4 = func_01EF04A4(temp, 0x101, 0, 0x53, D_0019E5C0);
}

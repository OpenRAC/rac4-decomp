/* cflags: -mno-split-addresses */
#include "common.h"

typedef struct Type1 {
    s32 *f0;
    char _p4[0x204];
    s32 f208;
    s32 f20C;
    s32 f210;
} Type1;

extern s32 D_00170F58[];

void func_01F0A2FC(Type1 *arg0) {
    arg0->f0 = D_00170F58;
    arg0->f208 = 0;
    arg0->f20C = 0;
    arg0->f210 = 0;
}

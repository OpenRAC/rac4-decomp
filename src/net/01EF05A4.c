/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

typedef struct E_01EF05A4 {
    u8 pad[0x34];
} E_01EF05A4;

typedef struct Type1 {
    s32 f0;
    E_01EF05A4 f4[0x280];
    u8 pad8204[0x8200];
    s32 f10404;
} Type1;

extern s32 func_01EF0618(void *, s32, s32, void *);
extern s32 D_0019C578[];

void func_01EF05A4(Type1 *arg0) {
    E_01EF05A4 *p;
    s32 i;

    p = arg0->f4;
    arg0->f10404 = 0;
    for (i = 0x27F; i >= 0; i--) {
        func_01EF0618(p, 0, 0, D_0019C578);
        p++;
    }
}

/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

extern void func_01F0C090(char *arg0, s32 arg1);
extern s32 D_0019CB38[];

void func_01EF66E4(void *arg0) {
    u32 p;

    p = *(u32 *)((u8 *)arg0 + 0x80);
    p = *(u32 *)p;
    if (p == 0)
        func_01F0C090(D_0019CB38, 0x6C);
}

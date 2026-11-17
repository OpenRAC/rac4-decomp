/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct { u8 f0; char _p1[0x7F]; u8 f80[8]; s32 f88; } E;
extern void *func_0011A518(void *, s32, u32);
void func_01F08038(E *e) {
    s32 i;
    for (i = 7; i != -1; i--) {
        e->f0 = 0;
        func_0011A518(e->f80, 0, 8);
        e->f88 = -1;
        e++;
    }
}

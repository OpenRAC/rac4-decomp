/* cflags: @ee296 -O2 -G0 -mno-split-addresses -fno-optimize-sibling-calls */
#include "common.h"

extern u8 D_0019E8D8[];
extern void func_01EEDCD0(void *, void *, s32);

void func_01F0C19C(u8 *arg0) {
    func_01EEDCD0(arg0 + 0x38, D_0019E8D8, 0x40);
}

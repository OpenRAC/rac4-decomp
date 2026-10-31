#include "common.h"

extern void func_0050DE18(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* Call func_0050DE18 on arg0 with four 0x80808080 words, then store arg1 at +0x58 of arg0. */
void func_0050DDC0(void *arg0, s32 arg1) {
    func_0050DE18(arg0, 0x80808080, 0x80808080, 0x80808080, 0x80808080);
    *(s32 *)((u8 *)arg0 + 0x58) = arg1;
}

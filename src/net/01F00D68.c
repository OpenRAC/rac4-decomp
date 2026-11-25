/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u32 func_01EED8A4(s32, s32, s32);
extern void func_01F0C090(char *arg0, s32 arg1);
extern void func_01EF4188();
extern char D_0019DC20[];

void func_01F00D68(u8 *arg0, s32 arg1)
{
    s32 s0;
    s32 s1;

    s0 = *(u32 *)(*(u32 *)(arg0 + 0x80) + 4);
    if (func_01EED8A4(s0, 0x11, 0) != 0
        || func_01EED8A4(s0, 0x11, 1) != 0
        || func_01EED8A4(s0, 0x11, 3) != 0
        || func_01EED8A4(s0, 0x11, 2) != 0) {
        s1 = *(u32 *)(*(u32 *)(arg0 + 0x80));
        if (s1 == 0) {
            func_01F0C090(D_0019DC20, 0x16D);
        }
        func_01EF4188(arg0, s0, s1, *(s32 *)arg0, arg1);
    }
}

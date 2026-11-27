/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(char *arg0, s32 arg1);
extern u8 D_0019B460[];

s32 func_01EE7A2C(void *arg0) {
    s32 *p = (s32 *)(*(u32 *)((u8 *)arg0 + 0x635C) + 8);
    s32 i;

    for (i = 0; i < 0x100; i++, p++) {
        if (*p == 0) {
            return i;
        }
    }
    func_01F0C090((char *)D_0019B460, 0x5D5);
    return -1;
}

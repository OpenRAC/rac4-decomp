/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls -mno-split-addresses */
#include "common.h"

extern void func_01F0C090(void *, s32);
extern s32 func_01EEE13C(void);
extern void func_01EF0550(s32, s32);
extern char D_0019C7B8[];
void func_01EF3CF0(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x80) == 0) {
        func_01F0C090(D_0019C7B8, 0xE7);
    }
    func_01EF0550(func_01EEE13C(), *(s32 *)(arg0 + 0x80));
}

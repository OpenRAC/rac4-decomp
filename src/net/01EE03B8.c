/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EE0648(s32, s32, void *, s32);
extern void func_0011EAA0(void *, s32, void *);
extern void func_0011A2DC(s32, void *, s32);
extern char D_00199F28[];
extern char D_0019A2B0[];
void func_01EE03B8(s32 arg0, s32 arg1, s32 arg2) {
    u8 buf[0x24];
    u8 r = func_01EE0648(arg0, 0, buf, 0x24);
    if (r != arg2) {
        func_0011EAA0(D_00199F28, 0x423, D_0019A2B0);
    }
    func_0011A2DC(arg1, buf, r | arg2);
}

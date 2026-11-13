/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern void func_01EF308C(s32, void *, s32 *);
extern void func_01EF587C(s32);
extern u8 D_0019CBF0[];
void func_01EF697C(s32 *arg0) {
    s32 x = -1;
    func_01EF308C(*arg0, D_0019CBF0, &x);
    if (x != -1) {
        func_01EF587C(x);
    }
}

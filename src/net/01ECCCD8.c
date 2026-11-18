/* cflags: @ee296 -O2 -G0 -fno-optimize-sibling-calls */
#include "common.h"

extern void *func_01EC8EA8();
extern void *func_01EC8F68();
extern void func_01ECCE40();
extern u8 *D_00167F38;

// Find the group for the pair or create one, then stamp it with the context's field 0x100 and finish it.
void func_01ECCCD8(s32 a0, s32 a1) {
    u8 *g;
    s32 v;
    g = func_01EC8EA8(a0, a1);
    if (g == 0) {
        g = func_01EC8F68(a0, a1);
        if (g == 0) {
            return;
        }
    }
    v = *(s32 *)(D_00167F38 + 0x100);
    *(s32 *)(g + 4) = v;
    func_01ECCE40(g);
}

/* cflags: @ee296 -O2 -G0 -falign-loops=1 */
#include "common.h"

extern void *func_01EC8EA8(void *arg0, s32 arg1);
extern void func_01EC90E0(void *arg0, s32 arg1);
extern void *func_01EC98E8(u32 arg0);
extern void *D_1B7390;

s32 func_01ECD2D0(s32 arg0) {
    void *s0;
    void *s1;
    void *v1;

    s0 = D_1B7390;
    if (s0 == 0) {
        return 8;
    }
    s1 = func_01EC8EA8(s0, *(s32 *)((u32)s0 + 0x404));
    if (s1 == 0) {
        return 0x15;
    }
    v1 = func_01EC98E8(arg0);
    if (v1 == 0) {
        return 0x1E;
    }
    if (*(s32 *)((u32)v1 + 0xC) != *(s32 *)((u32)s0 + 0x404)) {
        return 8;
    }
    *(s32 *)((u32)s1 + 0x4) = arg0;
    func_01EC90E0(s0, -1);
    return 0;
}

/* cflags: -mno-split-addresses */
#include "common.h"

extern void func_00496D40(s32, s32, s32);
extern s32 func_00547A98(s32 arg0);
extern s32 func_00547C00(s32 arg0);
extern u8 *func_00548D28(s32 arg0, s32 arg1);
extern s32 D_0021EDD4[];
extern s32 D_0021EDD8[];

/* Register an entry on the object, notifying it when active. */
s32 func_00522868(u8 *p, s32 a)
{
    if (D_0021EDD4[0] == 0 && D_0021EDD8[0] == 0 && func_00547A98(a) != 0) {
        return 0;
    }
    if (func_00547C00(a) == 0) {
        return 0;
    }
    *(s32 *)(p + ((s8)func_00548D28(a, 0)[0x2C] << 2) + 0x2674) = a;
    if (p[0x266D] == 0) {
        return 1;
    }
    func_00496D40(((s32 (*)(void *))(*(void ***)(p + 0x14))[0x4C / 4])(p), a, 1);
    return 1;
}

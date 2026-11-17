/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAB288(s32);
extern void func_01EABA88(void);

extern u8 D_00168BA0_[];
extern s32 D_1B23E0_[];

s32 func_01EAB3C0(void)
{
    s32 r = 0x640;
    s32 t;

    if (D_00168BA0_[0] == 1) {
        return r;
    }
    func_01EABA88();
    t = func_01EAB288((s32)&D_1B23E0_);
    if (t == 0) {
        D_00168BA0_[0] = 1;
    }
    return t;
}

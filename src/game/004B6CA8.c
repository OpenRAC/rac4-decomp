#include "common.h"

extern void func_00497980(s32 arg0);
extern void func_0049B208(s32);
extern void func_0049B2F8(s32 arg0, s32 arg1);
extern s32 func_00505B20(void);

s8 D_0021F7E8 = 0;

/* With arg0 nonzero, passes func_00505B20() to func_0049B2F8 with -1; otherwise sets up func_00497980(8), func_0049B208 and flag D_0021F7E8. */
void func_004B6CA8(s32 arg0) {
    if (arg0 != 0) {
        func_0049B2F8(func_00505B20(), -1);
        return;
    }
    func_00497980(8);
    func_0049B208(func_00505B20());
    D_0021F7E8 = 1;
}

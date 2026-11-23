/* Not matching yet: EXACT only with volatile, which matched C forbids; without it SIZE ours 184 / retail 188 (tools/try_func.py func_001593C8 --diff). Not part of the build. */
#include "common.h"

extern void func_00126E20(s32);
extern s32 func_00137DD0(void);
extern void func_00158C60(s32, s32, void *, s32, s32);
extern s32 func_00159488(s32 arg0);
extern volatile s32 D_1C1F80[];

s32 D_0021DCB4 = 0;
s32 D_0021DCBC = 0;
s32 D_0021DCC0 = 0;

s32 func_001593C8(s32 arg0, s32 arg1, s32 arg2) {
    s32 buf[3];

    if (D_0021DCB4 == 0) {
        return func_00137DD0();
    }
    if (func_00159488(1) == 1) {
        return 0;
    }
    D_1C1F80[0] = 1;
    D_1C1F80[4] = 0;
    func_00126E20(0);
    buf[0] = arg0;
    buf[1] = arg1;
    buf[2] = arg2;
    D_0021DCBC = 1;
    D_0021DCC0 = 0;
    func_00158C60(0x38, 0xC, buf, 0, 0);
    return 1;
}

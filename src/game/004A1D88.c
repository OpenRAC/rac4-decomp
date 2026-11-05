#include "common.h"

extern s32 func_00501458(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_004A1E28(void);
extern u8 D_003078F0[];
s32 D_002215C0 = 0;
// Runs func_00501458 once (guarded by D_002215C0) and returns the address of D_003078F0.
void *func_004A1D88(void) {
    if (D_002215C0 == 0) {
        func_00501458((s32 *)D_003078F0, 0, 0, (s32)func_004A1E28, 0, 0);
        D_002215C0 = 1;
    }
    return D_003078F0;
}

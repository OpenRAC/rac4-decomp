#include "common.h"

extern s32 func_00501458(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void func_004A1E28(void);
extern u8 D_30D6F0[];
s32 D_00222650 = 0;
// Runs func_00501458 once (guarded by D_00222650) and returns the level table.
void *func_L00_00629808(void) {
    if (D_00222650 == 0) {
        func_00501458((s32 *)D_30D6F0, 0, 0, (s32)func_004A1E28, 0, 0);
        D_00222650 = 1;
    }
    return D_30D6F0;
}

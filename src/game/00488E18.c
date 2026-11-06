#include "common.h"

extern s32 func_001596D8();
extern void func_001582A8(s32, s32, void *, u64);
extern void D_00488E00();
extern s32 D_001C2040[];
extern u32 D_001D2200[];

void func_00488E18(void)
{
    s32 *p;

    func_001596D8();
    p = D_001C2040;
    p += 0x2000;
    D_001D2200[39] = 0xFFFFFFFFu;
    func_001582A8(p[0x12F4] + p[0x12ED], 0, D_00488E00,
                  (u64)(u32)&D_001D2200[39]);
}

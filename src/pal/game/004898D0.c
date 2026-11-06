#include "common.h"

extern s32 func_001596E8();
extern void func_001582B8(s32, s32, void *, u64);
extern void func_004898B8();
extern s32 D_001C20C0[];
extern u32 D_001D2280[];

void func_004898D0(void)
{
    s32 *p;

    func_001596E8();
    p = D_001C20C0;
    p += 0x2000;
    D_001D2280[39] = 0xFFFFFFFFu;
    func_001582B8(p[0x12F4] + p[0x12ED], 0, func_004898B8,
                  (u64)(u32)&D_001D2280[39]);
}

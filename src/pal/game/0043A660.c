#include "common.h"

extern u8 D_00229D80[];
extern f32 D_002373F0_[];
#define D_002373F0 (D_002373F0_[0])
extern f32 func_00454158(f32);
extern f32 func_00454140(f32);
extern void func_004481E8(void);

void func_0043A660(s32 arg0)
{
    u8 *item;
    f32 ratio;

    item = D_00229D80 + arg0 * 0x470;
    item[0x449] = 0;
    *(f32 *)(item + 0x434) = 1.11002934f;
    *(f32 *)(item + 0x438) = 1.11002934f;
    ratio = func_00454158(0.55501467f);
    ratio /= func_00454140(0.55501467f);
    D_002373F0 = ratio;
    func_004481E8();
    *(f32 *)(item + 0x43C) = 0.005f;
    *(f32 *)(item + 0x440) = 0.2f;
    *(s32 *)(item + 0x430) = 0;
    *(s32 *)(item + 0x444) = 0;
}

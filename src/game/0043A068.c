#include "common.h"

extern u8 D_00229C80[];
extern f32 D_002372F0[];
extern f32 func_00453940(f32);
extern f32 func_00453928(f32);
extern void func_00447BA8(void);

void func_0043A068(s32 arg0)
{
    u8 *item;
    f32 ratio;

    item = D_00229C80 + arg0 * 0x470;
    item[0x449] = 0;
    *(f32 *)(item + 0x434) = 1.11002934f;
    *(f32 *)(item + 0x438) = 1.11002934f;
    ratio = func_00453940(0.55501467f);
    ratio /= func_00453928(0.55501467f);
    D_002372F0[0] = ratio;
    func_00447BA8();
    *(f32 *)(item + 0x43C) = 0.005f;
    *(f32 *)(item + 0x440) = 0.2f;
    *(s32 *)(item + 0x430) = 0;
    *(s32 *)(item + 0x444) = 0;
}

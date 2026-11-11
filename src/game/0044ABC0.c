#include "common.h"

extern void func_00449E98(s32, s32, s32, s32, u64);
void func_0044ABC0(s32 x, s32 y, s32 width, s32 extent, s32 alpha, s32 rgb)
{
    s32 color = (s32)(((u32)alpha << 24) | (u32)rgb);
    func_00449E98(x, y, width, extent, color);
    func_00449E98(x + 1, y - 1, width - 2, width, color);
    func_00449E98(x + 2, y - 2, width - 3, width - 2, color);
    func_00449E98(x + 4, y - 4, width - 4, width - 3, color);
    func_00449E98(x + 1, y - 1, extent, extent + 2, color);
    func_00449E98(x + 2, y - 2, extent + 2, extent + 3, color);
    func_00449E98(x + 4, y - 4, extent + 3, extent + 4, color);
}

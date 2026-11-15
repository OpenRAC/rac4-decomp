/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
#include "pal/display_00206AC0.h"

extern s32 D_00222C10;
extern void func_0044E528(u64, s64, s64, u64);
extern void func_0044A540(s32, s32, s32, s32, u64);
void func_L01_00439E80(void)
{
    func_0044E528((u64)&D_00222C10, 66, 72, 0U);
    func_0044A540(0, D_00206AC0.height, 0, D_00206AC0.width, -2139062144);
}

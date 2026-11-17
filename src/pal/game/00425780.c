/* cflags: -O2 -G8 -Wuninitialized */
#include "pal/display_00206AC0.h"
extern s32 D_00221370;
extern void func_0044E528(s32, s32, s32, s32);
extern void func_0044A540(s32, s32, s32, s32, u64);

void func_00425780(void)
{
    func_0044E528((s32)&D_00221370, 66, 72, 0);
    func_0044A540(0, D_00206AC0.height, 0, D_00206AC0.width, -2139062144);
}

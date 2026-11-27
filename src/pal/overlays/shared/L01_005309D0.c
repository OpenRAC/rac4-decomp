/* cflags: -G0 */
#include "common.h"
#include "pal/level01_scene_data.h"

extern u8 D_003B3BD0[];

s32 func_L01_005309D0(void) {
    D_0022FFA0.f0 = D_003B3BD0;
    return (u32)D_003B3BD0;
}

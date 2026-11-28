/* cflags: -mno-split-addresses */
#include "common.h"

extern s32 D_L02_00222690;
extern s32 D_L02_0022269C;
extern s32 D_L02_00223830;
extern s32 D_L02_00223834;
extern void func_L02_00480250(u8 *moby, s32 count, f32 scale, f32 angle);

/* Reset the two level buffer addresses before running both passes. */
void func_L02_004801D8(u8 *moby) {
    D_L02_00223830 = D_L02_00222690;
    D_L02_00223834 = D_L02_0022269C;
    func_L02_00480250(moby, 8, 2.5f, 0.0f);
    func_L02_00480250(moby, 6, 1.2f, 0.5235988f);
}

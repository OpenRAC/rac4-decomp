#include "common.h"

/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * rac3-decomp/src/levels/shared/L01_00314158.c func_L01_00315800.
 * Independently reconstructed from RAC4 PAL retail. */

typedef struct {
    u8 *object;
    u32 color;
    s32 reserved;
    f32 fraction;
    u8 tail[16];
} Entry;
extern Entry D_00227A20[];
extern u8 **func_00476E90(void *);
extern u32 func_00454480(u32, u32, f32);
extern void func_00470990(void *, u32, u32, u32);
void func_0042BA60(s32 index, u32 color)
{
    s32 alpha;
    u8 **child;
    s32 mixed, red, green, blue;
    alpha = (s32)(D_00227A20[index].fraction * 96.0f);
    D_00227A20[index].object[35] = alpha;
    child = func_00476E90(D_00227A20[index].object);
    if (child != 0 && *child != 0)
        (*child)[35] = alpha;
    mixed = func_00454480(color, D_00227A20[index].color, D_00227A20[index].fraction);
    blue = (mixed >> 16) & 0xFF;
    green = (mixed >> 8) & 0xFF;
    red = mixed & 0xFF;
    func_00470990(D_00227A20[index].object, red, green, blue);
}

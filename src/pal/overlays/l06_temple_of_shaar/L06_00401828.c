#include "pal/object_data.h"

extern u8 *func_L06_00401898(u8 *);
extern void func_00474368(u8 *, s32, s32);

void func_L06_00401828(u8 *moby) {
    u8 *vars = (u8 *)((PalObject *)moby)->data;
    s32 index;

    *(f32 *)(vars + 4) = 1.0f;
    *(f32 *)(vars + 0) = *(f32 *)(moby + 0x18);
    index = *(s32 *)(vars + 0x10);
    *(s16 *)(vars + 0x18) = -1;
    if (index != -1) {
        *(u8 **)(vars + 0x14) = func_L06_00401898(moby);
    }
    func_00474368(moby, 1, -1);
}

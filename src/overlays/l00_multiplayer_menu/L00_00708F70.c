#include "common.h"

extern s32 D_002233A4;
extern u8 D_1DFD8D[];
void *func_L00_00776D08(s32, void *, s32);

/* Looks up the record for arg0 and returns 1 when its word at 0x18 has bit 31 clear, else 0 (0 when there is no record) */
u32 func_L00_00708F70(s32 arg0) {
    s32 *obj;
    s32 *temp_v0;
    s32 temp_a2;
    u32 var_v1;

    temp_a2 = arg0 * 0x1E0;
    obj = (s32 *)D_002233A4;
    temp_v0 = func_L00_00776D08(obj[0x5C / 4], (u8 *)D_1DFD8D + temp_a2, temp_a2);
    var_v1 = 0;
    if (temp_v0 != 0) {
        var_v1 = ((u32)~temp_v0[0x18 / 4]) >> 31;
    }
    return var_v1;
}

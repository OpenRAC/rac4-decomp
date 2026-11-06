#include "common.h"
s32 func_L01_00572650(f32, f32, f32);               /* extern */
s32 func_L01_005728A8(f32, f32, f32, f32);          /* extern */

s32 func_L01_00572A68(s32 arg0, void *arg1) {
    u8 temp_v1;

    if ((arg1 != NULL) && (arg0 != 0)) {
        temp_v1 = (*(u8 *)((u8 *)(arg1) + 0x1C));
        switch (temp_v1) {                          /* irregular */
        case 1:
            return func_L01_00572650((*(f32 *)((u8 *)(arg1) + 0)), (*(f32 *)((u8 *)(arg1) + 4)), (*(f32 *)((u8 *)(arg1) + 8)));
        case 2:
            return func_L01_005728A8((*(f32 *)((u8 *)(arg1) + 0)), (*(f32 *)((u8 *)(arg1) + 8)), (*(f32 *)((u8 *)(arg1) + 4)), (*(f32 *)((u8 *)(arg1) + 0xC)));
        default:
            return 1;
        }
    } else {
        return 1;
    }
}

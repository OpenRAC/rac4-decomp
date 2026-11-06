#include "common.h"
s32 func_00490AC8();                            /* extern */

void func_L00_006140B8(void *arg0) {
    (*(u8 *)((u8 *)(arg0) + 8)) = (u8) ((*(u8 *)((u8 *)(arg0) + 8)) + (*(u8 *)((u8 *)(arg0) + 0x38)));
    if ((*(f32 *)((u8 *)(arg0) + 0xC)) <= 0.0f) {
        (*(f32 *)((u8 *)(arg0) + 0xC)) = 0.0f;
        func_00490AC8();
    }
}

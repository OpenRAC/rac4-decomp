#include "common.h"
s32 func_L01_00405520(void *, s32, s32, void *, f32); /* extern */

void func_L01_004054E0(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((u8 *)(arg0) + 0xAC));
    func_L01_00405520(arg0 + 0x10, (*(s32 *)((u8 *)(temp_v0) + 0x40)), (*(s32 *)((u8 *)(temp_v0) + 0x44)), arg0, (*(f32 *)((u8 *)(arg0) + 0x70)) * 90.0f);
}

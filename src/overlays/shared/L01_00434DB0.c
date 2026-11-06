#include "common.h"
s32 func_L00_00582190(void *, f32);             /* extern */
s32 func_L01_00435AC0();                        /* extern */

void func_L01_00434DB0(void *arg0) {
    f32 temp_f20;

    temp_f20 = 1.0f - ((f32) ((*(s32 *)((u8 *)((*(void **)((u8 *)(arg0) + 0xAC))) + 0x14)) - 0x5A) / 10.0f);
    func_L01_00435AC0();
    func_L00_00582190(arg0, temp_f20);
}

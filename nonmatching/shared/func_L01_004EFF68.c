/* Not matching yet: BYTES 19/116 (tools/try_func.py func_L01_004EFF68 --diff). Not part of the build. */
#include "common.h"

extern s32 func_L00_005E9F38(void *, void *, f32, f32, f32);

s32 func_L01_004EFF68(void *arg0, void *arg1, f32 f12, f32 f13, f32 f14) {
    f32 t;

    if (f12 == *(f32 *)((u8 *)arg1 + 0x18)) {
        return 0;
    }
    func_L00_005E9F38((u8 *)arg1 + 0x18, (u8 *)arg1 + 0x20, f12, f14, f13);
    t = *(f32 *)((u8 *)arg1 + 0x14) + *(f32 *)((u8 *)arg1 + 0x18);
    if (t < *(f32 *)((u8 *)arg1 + 0x24)) {
        *(f32 *)((u8 *)arg1 + 0x24) = t;
    }
    return 1;
}

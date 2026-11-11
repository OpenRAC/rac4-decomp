#include "common.h"

extern u8 *func_006658C0(s32);

s32 func_L01_00426610(u8 *arg0) {
    s32 v = *(f32 *)(func_006658C0(*(s32 *)(*(u8 **)(arg0 + 0xAC) + 0x10)) + 0x2F24) * 0.1f;
    return v > 0 ? v : 1;
}

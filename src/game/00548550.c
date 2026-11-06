#include "common.h"

extern u8 *func_00548D28(void *, s32);

/* Float 0x48 of what func_00548D28(p, 0) returns, divided by 60. */
f32 func_00548550(void *p) {
    return *(f32 *)(func_00548D28(p, 0) + 0x48) * (1.0f / 60.0f);
}

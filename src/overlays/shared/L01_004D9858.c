#include "common.h"
extern f32 (**func_0046D428(s16, s32, s32))(void *);
f32 func_L01_004D9858(void *arg0) {
    f32 (**t)(void *);
    if (arg0 != NULL) {
        t = func_0046D428(*(s16 *)((u8 *)arg0 + 0xBC), 0x14, 8);
        if (t != NULL) {
            return (*t)(arg0);
        }
    }
    return -1.0f;
}

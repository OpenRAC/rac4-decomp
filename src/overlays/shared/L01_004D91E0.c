#include "common.h"
extern f32 (**func_0046D428(s16, s32, s32))(void *);
s32 func_L01_004D91E0(u8 *arg0) {
    u8 *e = *(u8 **)(arg0 + 0xAC);
    s32 i;
    for (i = 0; i < *(s32 *)(e + 0x8C); i++) {
        u8 **p = (u8 **)(e + 0x6C);
        if ((*func_0046D428(*(s16 *)(p[i] + 0xBC), 5, 0x10))(p[i]) < 1.0f) {
            return 0;
        }
    }
    return 1;
}

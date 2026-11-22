#include "common.h"

typedef struct { u8 pad[0x10]; f32 f10; u8 pad2[0x10]; } T3;
extern T3 D_003BD3C8[];
extern s32 D_0021DF64;
extern void *func_0053CC58(s32);

s32 func_L01_003D44E0(void *arg0) {
    s32 r;
    void *p = func_0053CC58(*(s16 *)(*(u8 **)(arg0 + 0xAC) + 2));
    r = *(f32 *)(p + 0x2EC) * D_003BD3C8[D_0021DF64].f10 * 0.5f;
    if (r <= 0) r = 1;
    return r;
}

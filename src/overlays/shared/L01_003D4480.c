#include "common.h"

typedef struct { u8 pad[0x10]; f32 f10; u8 pad2[0x10]; } T3;
extern T3 D_003BD3C8[];
extern s32 D_0021DF64;
extern void *func_00510BE8(s32);

s32 func_L01_003D4480(void *arg0) {
    s32 r;
    void *p = func_00510BE8(**(s16 **)(arg0 + 0xAC));
    r = *(f32 *)(p + 0x2F24) * D_003BD3C8[D_0021DF64].f10;
    if (r <= 0) r = 1;
    return r;
}

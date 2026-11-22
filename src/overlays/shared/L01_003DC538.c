#include "common.h"

typedef struct { u8 pad[0x14]; s32 f14; f32 f18; s16 f1C; s16 f1E; } B;

extern f32 func_00453B10(f32, f32);
extern s32 func_00453508(void *);
extern void func_0046BDD0(void *);

void func_L01_003DC538(void *arg0) {
    B *b = *(B **)(arg0 + 0xAC);
    s32 half;
    *(f32 *)(arg0 + 0x70) = (f32)(b->f14 - b->f1C) * b->f18 / (f32)b->f14;
    *(f32 *)(arg0 + 0xF0) = func_00453B10(*(f32 *)(arg0 + 0xF0), 0.052359883f);
    *(f32 *)(arg0 + 0xF4) = func_00453B10(*(f32 *)(arg0 + 0xF4), 0.052359883f);
    *(f32 *)(arg0 + 0xF8) = func_00453B10(*(f32 *)(arg0 + 0xF8), 0.052359883f);
    if (func_00453508(&b->f1C) != 0) {
        func_0046BDD0(arg0);
        return;
    }
    half = b->f14 / 2;
    if (b->f1C < half) {
        *(s8 *)(arg0 + 0x23) = b->f1C * b->f1E / half;
    }
}

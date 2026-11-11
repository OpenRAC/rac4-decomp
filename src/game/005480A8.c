#include "common.h"

typedef struct {
    s32 f0, value;
    u8 rest[24];
} __attribute__((packed)) Data;
typedef struct {
    f32 f0;
    u32 f4;
    s32 f8;
    u32 fC;
} Scale;
extern const Data *func_00548D68(s32, s32);
extern s32 func_0045CB50(void);
extern Scale D_003DE168[];
s32 func_005480A8(s32 kind, s32 level)
{
    s32 low = level < 9;
    Data data = *func_00548D68(kind, low ? level : 8);
    s32 value = data.value;
    if (func_0045CB50() && !low) {
        s32 excess = level - 8;
        s32 triangle = excess * (level - 7) / 2;
        f32 coefficient = *(f32 *)((u32)kind * 16 + (u32)D_003DE168);
        s32 step = *(s32 *)((u32)D_003DE168 + (u32)kind * 16 + 8);
        value += step * excess + (s32)(coefficient * (f32)triangle);
    }
    return value;
}

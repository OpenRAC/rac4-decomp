#include "common.h"

typedef struct {
    f32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

typedef struct {
    u8 pad0[0x3CA];
    s16 f3CA;
    u8 pad3CC[0x648 - 0x3CC];
    s32 f648;
    u8 pad64C[0x2318 - 0x64C];
    s32 f2318;
    u8 pad231C[0x265A - 0x231C];
    u8 f265A;
    u8 pad265B[0x2D7C - 0x265B];
    Type1 f2D7C[4];
} Type2;

extern f32 func_004725D8(f32 a0, f32 a1);
extern s32 func_00512610(Type2 *p);
extern s32 D_0021EDD4;

s32 func_005230A8(Type2 *p, s32 *out)
{
    s32 idx[20];
    s32 n;
    s32 i;
    f32 sum;
    f32 lim;

    n = 0;
    if (p->f3CA != 0) {
        return 0;
    }
    if (p->f265A != 0) {
        return 0;
    }
    if (p->f2318 == 2) {
        return 0;
    }
    if (D_0021EDD4 != 1) {
        if (func_00512610(p) != 0) {
            *out = 3;
            if (p->f2D7C[3].f8 != 0) {
                return 0;
            }
            if (!(p->f648 & 2)) {
                return 0;
            }
            return func_004725D8(0.0f, 1.0f) < 0.33f;
        }
    }
    for (i = 0; i < 4; i++) {
        if (p->f2D7C[i].f8 == 0 && p->f2D7C[i].f0 != 0.0f && (i != 2 && i != 3)) {
            idx[n++] = i;
        }
    }
    if (n == 0) {
        return 0;
    }
    sum = 0.0f;
    for (i = 0; i < n; i++) {
        sum += 1.0f / (f32)(s32)(p->f2D7C[idx[i]].f0 * 50.0f);
    }
    lim = func_004725D8(0.0f, 1.0f);
    if (lim < sum) {
        for (i = 0; i < n; i++) {
            *out = idx[i];
            sum -= 1.0f / (f32)(s32)(p->f2D7C[idx[i]].f0 * 50.0f);
            if (sum < lim) {
                break;
            }
        }
        return 1;
    }
    return 0;
}

#include "common.h"

extern s32 D_0021DE40;
extern s32 func_005136E8(void);
extern f32 func_00454158(f32);
extern s32 func_00453D20(s16 *);
extern s16 func_00472E70(s32, s32);

// Writes a pulsing value to +0x60 of the moby at +0x23E4 (cycle of 92 frames, adjusted by the countdown
// at +0x3D2), then runs a countdown at +0x177C that restarts +0x177E when the moby's +0x54 is 1.
void func_L00_006B0A90(u8 *p) {
    u8 *m;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 a;
    s32 b;
    s32 h;
    s32 x;
    s32 y;
    s32 c3 = 0x80;
    s32 u;
    s32 w;
    s32 k;
    s32 l;
    f32 s;
    f32 t;
    s32 period;
    s32 start = 0x11;
    s32 end = 0x25;
    s32 fade = 4;

    if (*(s16 *)(p + 0x2E2C) != 0) {
        return;
    }
    m = *(u8 **)(p + 0x23E4);
    if (m == NULL) {
        return;
    }
    c2 = 0x88;
    c0 = 0x38;
    *(u16 *)(m + 0x34) |= 0x10;
    if (func_005136E8()) {
        c0 = c2;
    }
    period = 92;
    s = func_00454158((f32)(D_0021DE40 % period) / (f32)period * 2.0f * 3.1415927f + -3.1415927f);
    a = (s32)(s * 24.0f);
    b = (s32)(s * 48.0f);
    x = a + 12;
    c1 = a + 0x4C;
    y = b + 0x18;
    c2 = b + 0xA0;
    c0 += x;
    h = *(s16 *)(p + 0x3D2);
    if (h != 0) {
        t = 1.0f;
        if (h > end - fade) {
            t = (f32)(end - h) / (f32)fade;
        }
        if (h < start) {
            t = (f32)h / (f32)start;
        }
        u = (s32)(x * t);
        w = (s32)(y * t);
        k = (s32)(t * 112.0f);
        l = (s32)(t * 72.0f);
        c0 -= u;
        c2 -= w;
        c1 -= u;
        c0 += k;
        c2 -= l;
    }
    *(u32 *)(m + 0x60) = (c3 << 24) | (c1 << 16) | (c2 << 8) | c0;
    if (*(s32 *)(p + 0x25CC) == 0x7E) {
        return;
    }
    if (func_00453D20((s16 *)(p + 0x177C))) {
        c2 = m[0x54];
        if (c2 == 1) {
            *(s16 *)(p + 0x177C) = func_00472E70(0x2A, 0xA7);
            *(s16 *)(p + 0x177E) = c2;
        }
    }
    if (*(s16 *)(p + 0x177E) != 0) {
        *(s16 *)(p + 0x177E) += 1;
        if (*(s16 *)(p + 0x177E) >= 0x16) {
            *(s16 *)(p + 0x177E) = 0;
        }
    }
}

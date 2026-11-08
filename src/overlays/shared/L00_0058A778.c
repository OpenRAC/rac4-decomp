#include "common.h"

typedef struct { u8 pad[0x120]; f32 x120[3]; } V_3E3730;
typedef struct { u8 pad[0x70]; V_3E3730 *x70; } O_3E3730;
void func_L00_0058A5F0(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d);
extern void func_L00_0058A5F0(O_3E3730 *a0, f32 *a1, f32 *a2, f32 b, f32 c, f32 d);
extern s32 func_005BC9B8(u8 *);
extern void func_0058A6C8(u8 *, s32, void *, s32);

/* from rac3-decomp's func_L01_003E5700 */
void func_L00_0058A778(u8 *a0, s32 a1) {
    u8 buf[16];
    u8 *q;
    u8 *s;
    f32 scale;
    f32 x;
    f32 y;
    u8 t;
    q = *(u8 **)(a0 + 0x70);
    s = q + 0x60;
    if (func_005BC9B8(q + 0x146) != 0) {
        s[0xE5] = s[0xE4];
    }
    scale = (f32)*(s16 *)(s + 0xE6) * *(f32 *)(s + 0xE8);
    func_0058A6C8(a0, a1, buf, s[0xE4]);
    t = s[0xE4];
    if (t == 3 || t == 5 || t == 6 || t == 7 || t == 1) {
        x = scale * -0.049999997f + 0.0599999987f;
        y = scale * -0.200000003f + 0.400000006f;
    } else {
        x = 0.00999999978f;
        y = 0.200000003f;
    }
    ((void (*)(u8 *, u8 *, void *, f32, f32, f32))func_L00_0058A5F0)(a0, s + 0xB0, buf, x, y, 0.0f);
}

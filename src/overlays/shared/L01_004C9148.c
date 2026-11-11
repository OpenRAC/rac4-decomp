/* cflags: -G0 */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

typedef struct Type1 {
    u8 pad0[0x22];
    u8 unk22;
} Type1;

typedef struct M_004C9148 {
    u8 pad0[0x10];
    u128 pos;
    u8 pad20[0xAC - 0x20];
    Type1 *unkAC;
    u8 padB0[0xC0 - 0xB0];
    u128 mtx[3];
} M_004C9148;

extern u8 D_003AB250[];
extern void func_004C8F08(M_004C9148 *, void *, s32, u128 *, s32, s32, s32, s32, s32,
                          f32, f32, f32, f32, f32, f32, f32);

void func_L01_004C9148(M_004C9148 *arg0) {
    u128 m[4];
    u128 *src;
    u128 *p = m;
    Type1 *s;
    s32 max;
    f32 t;

    src = arg0->mtx;
    s = arg0->unkAC;
    max = 40;
    p[0] = src[2];
    p[1] = arg0->mtx[0];
    p[2] = src[1];
    p[3] = arg0->pos;
    if (s->unk22 <= max) {
        t = (f32)s->unk22 / (f32)max;
    } else {
        t = 1.0f;
    }
    func_004C8F08(arg0, D_003AB250, 3, m, 0x45, 2, 0x597B98, 0x162A3C, 0x10,
                  0.7f, 2.5f, (f32)s->unk22 / 40.0f, t, 5.0f, 1.25f, 1.75f);
}

/* cflags: -ffast-math */
#include "common.h"

typedef struct Obj { u8 pad0[0x1780]; f32 f1780; u8 pad1784[0x25C4-0x1784]; f32 f25C4; u8 pad25C8[4]; s32 f25CC; u8 pad25D0[0x2E08-0x25D0]; f32 f2E08; u8 pad2E0C[0x2FC0-0x2E0C]; f32 f2FC0; } Obj;
extern void func_0051B168(void *, s32, f32);
extern f32 D_0021DDF4[1];
extern f32 D_003D3870[];

/* Refreshes the float at 0x1780 from several scale factors and clamps it up for state 0x72. */
void func_0051B668(Obj *arg0) {
    f32 v;
    func_0051B168(arg0, 0, 1.0f);
    if (arg0->f1780 > 0.0f) {
        arg0->f1780 = D_003D3870[0] * D_0021DDF4[0] * arg0->f25C4 * arg0->f2E08 * arg0->f2FC0;
    }
    if (arg0->f25CC == 0x72) {
        arg0->f1780 = arg0->f1780 * 0.8f;
        v = D_0021DDF4[0] * (arg0->f25C4 * 2.5f);
        arg0->f1780 = (v > arg0->f1780) ? v : arg0->f1780;
    }
}

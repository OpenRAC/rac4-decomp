#include "common.h"
typedef struct { u16 f0; u16 f2; u32 f4, f8; } Ent;
extern Ent D_001F1400[];
extern s32 D_0021DE10;
extern u32 D_0021DA70;
extern s32 func_0045D7B0(s16 id, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w);
s32 func_0045DB78(s16 a, s16 b, s32 c, s32 d) {
    s32 r = 0;
    Ent *e = &D_001F1400[b];
    if (e->f0 % c == 0) {
        r = func_0045D7B0(a, b, d, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    } else {
        u32 v;
        if (e->f0 <= 0xFFFE) {
            e->f0++;
        }
        v = D_0021DA70;
        if (e->f4 < v) {
            e->f4 = v;
        }
        e->f8 = e->f8 | (1 << ((D_0021DE10 - 1) % 20)) | 0x80000000;
    }
    return r;
}

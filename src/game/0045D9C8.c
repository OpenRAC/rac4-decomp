#include "common.h"
typedef struct { u16 f0; u16 f2; u32 f4, f8; } Ent;
extern Ent D_001F1400[];
extern s32 D_0021DE10;
extern s32 func_0045D7B0(s16 id, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w);
s32 func_0045D9C8(s16 a, s16 b, s32 c) {
    if ((D_001F1400[b].f8 & (1 << ((D_0021DE10 - 1) % 20))) == 0) {
        return func_0045D7B0(a, b, c, 0, 0.0f, 1.0f, 0.0f, 64.0f);
    }
    return 0;
}

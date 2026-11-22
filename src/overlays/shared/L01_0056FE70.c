/* cflags: @ee29 -O2 -G0 */
#include "common.h"
typedef struct { s32 a, b, c; } T;
extern T D_001F1400[];
extern s32 func_0045D7B0(s16 id, s16 a, s16 b, s32 c, f32 x, f32 y, f32 z, f32 w);
s32 func_L01_0056FE70(s16 a, s16 b, s32 c) {
    if (D_001F1400[(s16)b].c < 0) return 0;
    return func_0045D7B0(a, b, c, 0, 0.0f, 1.0f, 0.0f, 64.0f);
}

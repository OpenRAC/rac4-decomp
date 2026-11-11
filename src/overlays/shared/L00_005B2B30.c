#include "common.h"
/* Ported from rac3-decomp's func_L01_004078B0 (src/levels/shared/L01_004077C8.c, GPL-3.0), the same code in both games. */

extern char D_0023C030[];
extern char D_0023C030[];
extern char D_0023C030[];
typedef struct {
    u8 pad0[16];
    f32 *w16;
    u32 w20;
    u8 pad1[4];
    s32 w28;
    s16 h32;
    s16 h34;
    s16 h36;
    s16 h38;
    u8 pad2[8];
} S4054E0;
void func_L00_005B2B30(u32 *buf, s32 idx) {
    S4054E0 *s = &((S4054E0 *)&D_0023C030)[idx];
    s32 n = s->h36 * s->h38;
    s32 count = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        if (s->w20 < (buf[i] & 0xFFFFFF)) {
            count++;
        }
    }
    *(&((S4054E0 *)&D_0023C030)[idx])->w16 = (f32)(n - count) / (f32)n;
}

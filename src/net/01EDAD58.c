/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u16 f0; char _p2[6]; } Ent;
typedef struct { s32 f0; u32 f4; char _p8[4]; Ent e[32]; } Map;
u16 func_01EDAD58(Map *m, u16 id) {
    u32 x = m->f4 & (0xFFFFFFFF >> ~id);
    u32 c;
    s32 n;
    c = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    c = (c & 0x33333333) + ((c >> 2) & 0x33333333);
    c = (c & 0x0F0F0F0F) + ((c >> 4) & 0x0F0F0F0F);
    c = (c & 0x00FF00FF) + ((c >> 8) & 0x00FF00FF);
    c = (c & 0xFFFF) + (c >> 16);
    n = c - 1;
    if (n < 0) {
        n = 0;
    }
    return m->e[n].f0 == id ? n : 0xFFFF;
}

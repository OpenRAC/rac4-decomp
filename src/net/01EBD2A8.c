/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x4C]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; char _p188[0x14]; u16 f19C; char _p19E[4]; u16 f1A2; u16 f1A4; } Conn;
extern s32 func_01EBD068(Conn *, u16, s32);
s32 func_01EBD2A8(Conn *c) {
    u32 i;
    s32 n;
    s32 r;
    if (c == 0) {
        return 2;
    }
    if (c->f1A4 != 0xFFFE && c->f1A4 == c->f1A2) {
        n = ((u32)(c->f19C + 31) >> 5) + 1;
        r = func_01EBD068(c, c->f1A2, n);
        if (r != 0) {
            return r;
        }
        for (i = 0; i < c->f19C; i++) {
            Slot_50 *s = &c->slots[i];
            if (s->f0 != 0 && s->f0 != 9) {
                r = func_01EBD068(c, i, n);
                if (r != 0) {
                    return r;
                }
            }
        }
    }
    return 0;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; s32 f4; s32 f8; char _pC[0x44]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; char _p188[0x14]; u16 f19C; char _p19E[0x46]; s32 f1E4; } Conn_1e8;
extern void func_01EC2268(u32 *);
extern void func_01EC2280(s32, u32);
s32 func_01EBCEE0(Conn_1e8 *c) {
    u32 now;
    Slot_50 *s;
    s32 i = 0;
    if (c->f1E4 != 0) {
        func_01EC2268(&now);
        s = c->slots;
        now >>= 2;
        for (; i < c->f19C; i++, s++) {
            if (s->f4 != 0) {
                func_01EC2280(s->f4, now);
            } else if (s->f8 != 0) {
                func_01EC2280(s->f8, now);
            }
        }
    }
    return 0;
}

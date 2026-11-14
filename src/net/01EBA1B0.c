/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { char _p0[0x1C]; s32 f1C; char _p20[0x30]; } Slot_50;
typedef struct {
    char _p0[0x184];
    Slot_50 *slots;
    char _p188[0x16];
    u16 f19E;
    char _p1A0[0x5C];
    void (*f1FC)(u16, s32, s32);
    char _p200[0x18];
    s32 f218;
} Conn_21c;
extern void func_01EB9880(Conn_21c *, s32 *, u16 *);
s32 func_01EBA1B0(Conn_21c *c, u16 idx) {
    u16 tag = 0xFFFE;
    s32 st = 0;
    func_01EB9880(c, &st, &tag);
    c->f19E++;
    if (st == 8 || st == 9) {
        c->f1FC(idx, 0, c->f218);
    } else {
        c->slots[idx].f1C = 1;
    }
    return 0;
}

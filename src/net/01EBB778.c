/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x4C]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; } Conn_188;
extern void func_01EBB6D0(Conn_188 *, u16);
extern void func_01EBB618(Conn_188 *, u16, u16);
s32 func_01EBB778(s32 type, Conn_188 *c, s32 code, u16 x, u16 idx) {
    Slot_50 *s;
    if (type == 3 || type == 1) {
        func_01EBB6D0(c, idx);
    } else if (type == 2) {
        s = &c->slots[idx];
        if (code == 9 || s->f0 == 4) {
            func_01EBB6D0(c, idx);
        } else {
            func_01EBB618(c, x, idx);
        }
    }
    return 0;
}

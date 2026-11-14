/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 f0; char _p4[0x4C]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; char _p188[0x14]; u16 f19C; } Conn_19e;
extern s32 func_01EBB6D0(Conn_19e *, u16);
s32 func_01EBB818(Conn_19e *c, u16 a, u16 b) {
    s32 found = 0;
    u16 j = 0;
    if (a != 0) {
        if (b < a) {
            j = a - 1;
        }
    } else {
        j = c->f19C - 1;
    }
    while (b < j) {
        if (c->slots[j].f0 == 3) {
            found = 1;
        }
        if (c->slots[j].f0 == 4) {
            found = 1;
        }
        j--;
    }
    if (!found) {
        func_01EBB6D0(c, b);
    }
    return 0;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
typedef struct { u16 f0; u16 x; u16 idx; } Hdr6;
typedef struct { char _p0[0x50]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; char _p188[0x1A]; u16 f1A2; } Conn_1a4;
extern u16 func_01EB8E98(s32, s32);
extern s32 func_01EBAE58(Conn_1a4 *, Slot_50 *, u16, IovList *);
s32 func_01EBB618(Conn_1a4 *c, u16 x, u16 idx) {
    IovList l;
    Hdr6 h;
    if (c == 0) {
        return 2;
    }
    h.f0 = func_01EB8E98(13, 6);
    h.x = x;
    l.count = 0;
    h.idx = idx;
    l.v[l.count].p = &h;
    l.total = 0;
    l.v[l.count].n = sizeof(h);
    l.total += sizeof(h);
    l.count++;
    return func_01EBAE58(c, &c->slots[c->f1A2], 0xF000, &l);
}

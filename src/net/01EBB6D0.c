/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
typedef struct { u16 f0; u16 idx; u16 seq; } Hdr6;
typedef struct { char _p0[0x34]; u16 f34; char _p36[0x1A]; } Slot_50;
typedef struct { char _p0[0x184]; Slot_50 *slots; } Conn_188;
extern u16 func_01EB8E98(s32, s32);
extern s32 func_01EBAEE0(Conn_188 *, s32, s32, u16, IovList *);
s32 func_01EBB6D0(Conn_188 *c, u16 idx) {
    IovList l;
    Hdr6 h;
    h.f0 = func_01EB8E98(3, 6);
    l.count = 0;
    h.idx = idx;
    l.total = 0;
    h.seq = c->slots[idx].f34;
    l.v[l.count].p = &h;
    l.v[l.count].n = sizeof(h);
    l.total += sizeof(h);
    l.count++;
    func_01EBAEE0(c, 0, 0, 0xF000, &l);
    return 0;
}

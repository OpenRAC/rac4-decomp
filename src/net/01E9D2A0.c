/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 _p10[5]; } Msg_24;
typedef struct { char _p0[0x10]; s32 f10; } Sock;
extern void func_0011A518(void *, s32, s32);
extern s32 func_01E9D828(void *, s32, void *);
s32 func_01E9D2A0(void *a, s32 b, Sock *s, s32 x, void *buf, s32 len) {
    Msg_24 m;
    IovList l;
    func_0011A518(&m, 0, sizeof(m));
    m.f0 = 13;
    l.count = 0;
    m.f4 = s->f10;
    l.total = 0;
    m.fC = len;
    m.f8 = x;
    l.v[l.count].p = buf;
    l.v[l.count].n = len;
    l.total += len;
    l.count++;
    return func_01E9D828(&m, sizeof(m), &l);
}

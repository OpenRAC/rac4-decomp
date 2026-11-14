/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; s32 _p18[6]; } Msg_30;
typedef struct { char _p0[0x10]; s32 f10; } Sock;
extern void func_0011A518(void *, s32, s32);
extern s32 func_01E9D828(void *, s32, void *);
s32 func_01E9CFD0(void *a, s32 b, Sock *s, IovList *l, s32 *flags) {
    Msg_30 m;
    *flags = 0;
    func_0011A518(&m, 0, sizeof(m));
    m.f0 = 9;
    m.f4 = s->f10;
    m.f8 = l->total;
    m.f14 = *flags;
    return func_01E9D828(&m, sizeof(m), l) ? 0 : l->total;
}

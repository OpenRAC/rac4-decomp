/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { void *p; s32 n; } Iov;
typedef struct { Iov v[8]; s32 total; s32 count; } IovList;
typedef struct { s32 f0; char _p4[0x1A4]; u32 f1A8; s32 f1AC[4]; s32 f1BC; } Conn_1c0;
extern s32 func_01EAB2A0(s32 *, u32 *);
extern u16 func_01EB8E98(s32, s32);
extern s32 func_01EBEE20(s32, s32, IovList *);
extern void func_01EAB270(s32 *);
s32 func_01EBAD88(Conn_1c0 *c) {
    IovList l;
    u32 t[1];
    u16 h[1];
    if (c->f1BC != 0 && c->f1A8 < 10) {
        func_01EAB2A0(c->f1AC, t);
        if (t[0] > 500) {
            h[0] = func_01EB8E98(4, 2);
            l.count = 0;
            l.total = 0;
            l.v[l.count].p = h;
            l.v[l.count].n = sizeof(h);
            l.total += sizeof(h);
            l.count++;
            func_01EBEE20(c->f0, 0, &l);
            c->f1A8++;
            func_01EAB270(c->f1AC);
        }
    }
    return 0;
}

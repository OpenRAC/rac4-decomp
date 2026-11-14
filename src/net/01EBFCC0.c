/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u32 f0; u32 f4; u8 data[0x12]; } Pkt;
typedef struct { char _p0[0x40]; u16 f40; } Obj;
extern s32 func_01EB6510(s32, Pkt **, Obj *, s32);
extern s32 func_01EBFE28(Pkt *, u32);
s32 func_01EBFCC0(s32 unused, s32 a, u16 flags, Pkt *p, Obj *o) {
    Pkt *t = p;
    u16 *hp = (u16 *)((p ? p->data : 0) + 0x10);
    u16 len = *hp & 0x7FF;
    s32 r = func_01EB6510(a, &t, o, p ? p->f0 - 4 : -4);
    if (r != 0) {
        return r;
    }
    { Pkt *q = t; hp = (u16 *)((q ? q->data : 0) + 0x10);
    *hp = (*hp & 0xF800) | ((len + o->f40) & 0x7FF) | (flags & 0xF800);
    func_01EBFE28(q, 0); }
    return 0;
}

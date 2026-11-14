/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { char _p0[0x40]; s32 *f40; char _p44[8]; struct Node *f4C; } Node;
typedef struct { s32 f0; s32 f4; u32 f8; s32 fC; } Ev;
typedef struct { char _p0[0x148]; void (*f148)(Ev *); s32 f14C; } Ctx;
typedef struct { char _p0[0x10]; s32 f10; } Clock;
typedef struct { s32 f0; } Grp;
extern Ctx *D_00167F38;
extern Clock *D_00167EFC;
extern Node *D_001B7384;
extern Grp *func_01EC8EA8(s32, u32);
extern Grp *func_01EC8F68(s32, u32);
extern s32 func_01EA47E8(s32, u32);
extern void func_01ECCE40(Grp *);
extern void func_01EC90E0(s32, u32);
void func_01ECCD48(s32 a, u32 b) {
    Grp *g;
    Node *p;
    Ctx *c;
    if (b >= 256) {
        return;
    }
    if (a == 0) {
        return;
    }
    g = func_01EC8EA8(a, b);
    if (g == 0) {
        g = func_01EC8F68(a, b);
    }
    if (func_01EA47E8(a, b) == 0) {
        return;
    }
    g->f0 = D_00167EFC->f10;
    func_01ECCE40(g);
    for (p = D_001B7384; p != 0; p = p->f4C) {
        p->f40[b] = 0;
    }
    c = D_00167F38;
    if (c->f148 != 0) {
        Ev ev;
        ev.fC = c->f14C;
        ev.f0 = 0;
        ev.f4 = a;
        ev.f8 = b;
        c->f148(&ev);
    }
    func_01EC90E0(a, b);
}

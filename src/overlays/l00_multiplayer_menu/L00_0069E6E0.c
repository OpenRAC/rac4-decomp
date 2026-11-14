#include "common.h"

typedef struct Obj Obj;
typedef struct { int f0, f4, f8, fC, f10; int (*check)(Obj *, int); } VT;
struct Obj { int f0, f4; VT *vt; };
typedef struct { int f0, f4, f8, fC, f10, index; } Node;
typedef struct { int f0; Node *node; } Manager;

extern Obj *func_L00_00698288(int a0, int a1);
extern Manager *func_L00_00698D80();
extern void func_L00_006A6928(void *a0, f32 f12, f32 f13);
extern Manager D_00223148[];
extern int D_00220478;

// Looks up an entry by id in the manager's current node and applies two floats to it.
s32 func_L00_0069E6E0(int a, f32 x, f32 y) {
    Manager *r;
    Node *n;
    int value;
    Obj *o, *p;
    s32 result = 0;
    if (D_00223148->node) r = D_00223148; else r = func_L00_00698D80();
    n = r->node;
    value = n ? *(int *)((unsigned int)n + ((unsigned int)n->index << 2)) : 0;
    o = func_L00_00698288(value, a);
    if (o && o->vt->check(o, D_00220478)) p = o; else p = 0;
    if (p) { result = 1; func_L00_006A6928(p, x, y); }
    return result;
}

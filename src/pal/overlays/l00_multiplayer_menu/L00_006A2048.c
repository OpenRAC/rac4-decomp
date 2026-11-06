/* cflags: -O2 -G8 */
#include "common.h"
typedef struct Node { int x[5]; int index; } Node;
typedef struct Root { int pad; Node *node; } Root;
typedef struct Obj Obj;
typedef struct Vtable { int pad[5]; int (*check)(Obj *, int); } Vtable;
struct Obj { int pad[2]; Vtable *vt; };
extern Root D_00223248[];
extern int D_00220530;
extern void *func_00502150(void);
extern void *func_00501658(void *, u32);
extern void func_0050F488(void *, u8, s32);
int func_L00_006A2048(int a, int b)
{
    Root *r;
    Node *n;
    int value;
    Obj *o, *p;
    int result = 0;
    if (D_00223248->node) r = D_00223248; else r = func_00502150();
    n = r->node;
    value = n ? *(int *)((unsigned int)n + ((unsigned int)n->index << 2)) : 0;
    o = func_00501658((void *)value, a);
    if (o && o->vt->check(o, D_00220530)) p = o; else p = 0;
    if (p) { result = 1; func_0050F488(p, 2, b); }
    return result;
}

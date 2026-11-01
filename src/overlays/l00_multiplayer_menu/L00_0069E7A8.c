/* cflags: -O2 -G8 */
typedef struct Node { int x[5]; int index; } Node;
typedef struct Root { int pad; Node *node; } Root;
typedef struct Obj Obj;
typedef struct Vtable { int pad[5]; int (*check)(Obj *, int); } Vtable;
struct Obj { int pad[2]; Vtable *vt; };
extern Root D_00223148[];
extern int D_00220478;
extern Root *func_00698D80(void);
extern Obj *func_00698288(int, int);
extern void func_006A68E0(Obj *, int, int);
int func_L00_0069E7A8(int a, int b) {
    Root *r;
    Node *n;
    int value;
    Obj *o, *p;
    int result = 0;
    if (D_00223148->node) r = D_00223148; else r = func_00698D80();
    n = r->node;
    value = n ? *(int *)((unsigned int)n + ((unsigned int)n->index << 2)) : 0;
    o = func_00698288(value, a);
    if (o && o->vt->check(o, D_00220478)) p = o; else p = 0;
    if (p) { result = 1; func_006A68E0(p, 1, b); }
    return result;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node { struct Node *f0; struct Node *f4; char _p8[0xC]; u32 f14; char _p18[0x50]; s32 f68; } Node;
extern Node *D_0016AC18;
extern Node *D_0016AC1C;
extern Node *func_01EE1770(s32 *);
extern s32 func_01EE1690(Node *);
extern void func_01EE1A10(s32);
Node *func_01EE15D8(Node *o) {
    Node *f;
    Node **head;
    Node *h;
    if (o == 0) {
        return 0;
    }
    f = func_01EE1770(&o->f68);
    if (f != 0) {
        if (f->f14 & 0x80) {
            return 0;
        }
        func_01EE1A10(func_01EE1690(f));
    }
    if (o->f14 & 0x80) {
        head = &D_0016AC18;
    } else {
        head = &D_0016AC1C;
    }
    h = *head;
    if (h == 0) {
        *head = o;
        o->f0 = o;
        o->f4 = o;
    } else {
        Node *t = h->f0;
        o->f4 = h;
        o->f0 = t;
        t->f4 = o;
        o->f4->f0 = o;
    }
    return o;
}

#include "common.h"

typedef struct Node Node;

typedef struct {
    s32 f0;
    u32 f4;
} Msg;

typedef struct {
    u8 pad0[0x20];
    s32 (*f20)(Node *, Msg *);
    s32 (*f24)(Node *, Msg *);
} VTable;

struct Node {
    u8 pad0[8];
    VTable *f8;
    u32 fC;
    u8 pad10[0x30];
    Node *children[106];
    s32 f1E8;
};

extern s32 func_0050C100(Node *, Msg *);

s32 func_0050C638(Node *n, Msg *m) {
    s32 r = func_0050C100(n, m);
    s32 i;
    u64 flags;

    if (r != 0 && !(m->f4 & 0x10000)) {
        return r;
    }
    flags = n->fC;
    if (!((flags >> 1) & 1) && m->f0 == 0) {
        return r;
    }
    r = (r != 0) | (n->f8->f24(n, m) != 0);
    if ((m->f4 & 0x10000) && m->f0 == 0) {
        for (i = 0; i < n->f1E8; i++) {
            r = (r != 0) | (n->children[i]->f8->f20(n->children[i], m) != 0);
        }
    }
    return r;
}

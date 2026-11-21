#include "common.h"

extern s32 D_002233A4;

typedef struct Vt {
    u8 p0[0x24];
    void (*f24)(void *, s32, s32);
} Vt;

typedef struct Ctl {
    u8 p0[0x58];
    Vt *f58;
} Ctl;

typedef struct Ent {
    u8 p0[0x1C];
    s32 f1C;
} Ent;

typedef struct List {
    s32 f0;
    s32 f4;
    Ent **f8;
} List;

typedef struct St {
    u8 f0;
    u8 p1[3];
    s32 f4;
    u8 p8[8];
    s32 f10;
    u8 p14[0x14];
    List f28[1];
} St;

typedef struct G {
    u8 p0[0x34];
    s32 *f34;
    St *f38;
} G;

typedef struct Obj {
    u8 p0[0xFC];
    Ctl *fFC;
    Ctl *f100;
    Ctl *f104;
    u8 p108[0x158];
    s32 f260;
    u8 p264[0x1B];
    u8 f27F;
    s32 f280;
    u8 f284;
} Obj;

/* Refreshes the cached state at 0x280 and sets the modes of the controls at 0xFC, 0x100 and 0x104 to match it. */
void func_L00_00751208(Obj *arg0) {
    G *g = (G *)D_002233A4;
    St *st = g->f38;
    s32 cur;
    s32 want;
    s32 n;
    s32 i;
    s32 m;
    List *list;
    u8 found;
    Ctl *ctl;

    cur = st->f10;
    if (cur == arg0->f280) {
        return;
    }
    arg0->f280 = cur;
    want = arg0->f260;
    if (*g->f34 == want) {
        ctl = arg0->fFC;
        ctl->f58->f24(ctl, 3, 0);
        ctl = arg0->f100;
        ctl->f58->f24(ctl, 0, 0);
        return;
    }
    found = 0;
    list = 0;
    if (st->f0 != 0) {
        n = st->f4;
        if (n >= 0) {
            list = &st->f28[n];
        }
    }
    if (list != 0) {
        for (i = 0; i < list->f4; i++) {
            if (list->f8[i]->f1C == want) {
                found = 1;
                break;
            }
        }
    }
    arg0->f27F = found;
    if (arg0->f27F != 0) {
        ctl = arg0->fFC;
        ctl->f58->f24(ctl, 0, 0);
        ctl = arg0->f100;
        ctl->f58->f24(ctl, 4, 0);
    } else {
        ctl = arg0->fFC;
        m = 4;
        if (arg0->f284 != 0) {
            m = 3;
        }
        ctl->f58->f24(ctl, m, 0);
        ctl = arg0->f100;
        ctl->f58->f24(ctl, 0, 0);
    }
    if (arg0->f284 == 0) {
        ctl = arg0->f104;
        m = 4;
        if (arg0->f27F != 0) {
            m = 3;
        }
        ctl->f58->f24(ctl, m, 0);
    }
}

/* cflags: @ee296 -Os -G0 -mno-split-addresses */
#include "common.h"

typedef struct Item Item;
typedef struct { char _p0[0x20]; s32 (*f20)(Item *); char _p24[0x18]; s32 (*f3C)(Item *); } Vt;
struct Item { char _p0[0xB0]; Vt *vt; };
typedef struct { char _p0[8]; Item *items[0x100]; } List;
typedef struct { char _p0[0x6358]; List *list; } Mgr;
s32 func_01EE91E0(Mgr *m) {
    List *l = m->list;
    s32 i;
    for (i = 0; i < 0x100 && l->items[i] != 0; i++) {
        if (l->items[i]->vt->f20(l->items[i])) {
            return l->items[i]->vt->f3C(l->items[i]);
        }
    }
    return 0;
}

#include "common.h"

typedef struct Item {
    u8 pad0[0x4];
    s32 x4;
    s32 x8;
} Item;

typedef struct Row {
    u8 pad0[0x8];
    Item *x8;
    u8 padC[0xC];
} Row;

typedef struct List {
    u8 pad0[0x34];
    Row *rows;
    u8 pad38[0x18];
    s32 count;
    s32 cursor;
} List;

typedef struct Page {
    u8 pad0[0xAB4];
    List list;
    u8 padB0C[0x24];
} Page;

typedef struct Group {
    s32 x0;
    s32 count;
    s32 ids[11];
} Group;

typedef struct Slot {
    u8 pad0[0x9];
    u8 x9;
    u8 padA[0x2];
} Slot;

extern Page D_0030B9D8[];
extern Group D_0030D038[];
extern Slot D_001F8878[];
extern s32 D_0021F218;
extern s32 func_00506BB8(void);
extern s32 func_004C7690(void);
extern s32 func_004C7790(s32);

static inline Row *rowAt(List *l, s32 idx)
{
    if (idx < 0) {
        idx = l->cursor;
    }
    if (idx < 0) {
        return 0;
    }
    return &l->rows[idx];
}

// Returns the index of the menu row whose item is the target and does not
// have x8 == 1, or -1. The target is the first id of group k whose slot is
// free (x9 clear) when func_004C7790 accepts the current id, otherwise the
// current id itself.
s32 func_004C7798(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B9D8[ctx];
    s32 found = -1;
    s32 target = -1;
    s32 k;
    s32 cur;
    s32 first;
    s32 i;
    s32 j;
    List *list;
    Item *item;
    Group *g;
    Slot *sl;

    k = func_004C7690();
    cur = D_0021F218;
    if (func_004C7790(cur)) {
        g = &D_0030D038[k];
        first = 1;
        for (i = 0; i < g->count; i++) {
            if (first) {
                sl = &D_001F8878[g->ids[i]];
                if (sl->x9 == 0) {
                    target = g->ids[i];
                    first = 0;
                }
            }
        }
    } else {
        target = cur;
    }
    list = &p->list;
    for (j = 0; j < list->count; j++) {
        if (found != -1) {
            continue;
        }
        item = rowAt(list, j)->x8;
        if (item->x8 == 1) {
            continue;
        }
        if (item->x4 == target) {
            found = j;
        }
    }
    return found;
}

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
    u8 pad0[0x1EC];
    List list;
    u8 pad244[0x14];
} Page;

typedef struct Level {
    u8 pad0[0x300];
    u8 x300;
    u8 pad301[0x3];
} Level;

extern Page D_0030B358[];
extern Level D_001F8878[];
extern s32 D_0021DE98;
extern s32 D_0021EE54;
extern s32 D_0021EE58;
extern s32 func_00506BB8(void);

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

// Returns the index of the menu row whose item belongs to the current level
// (D_0021DE98, shifted by 0x14 in one mode) and has x8 clear, or -1.
// Returns -1 straight away if bit 3 of the level's flags is set.
s32 func_004C0600(void)
{
    s32 ctx = func_00506BB8();
    Page *p = &D_0030B358[ctx];
    List *list;
    Item *item;
    s32 found = -1;
    s32 i;
    s32 v;
    s32 f;
    Level *lv;

    lv = &D_001F8878[(D_0021DE98 - 1) % 20];
    f = lv->x300;
    if (!((f >> 3) & 1)) {
        list = &p->list;
        for (i = 0; i < list->count; i++) {
            item = rowAt(&p->list, i)->x8;
            v = item->x4;
            if (D_0021EE54 == 0 && D_0021EE58 == 1) {
                v += 0x14;
            }
            if (v == D_0021DE98 && item->x8 == 0) {
                found = i;
            }
        }
    }
    return found;
}

#include "common.h"

typedef struct Data {
    u8 a, locked, enabled, pad;
    s32 id, kind;
} Data;
typedef struct Item {
    u8 pad[8];
    Data *data;
    u8 tail[12];
} Item;
typedef struct List {
    u8 pad[0x34];
    Item *items;
    u8 pad2[0x18];
    s32 count, index;
    u8 tail[0x20];
} List;
typedef struct State {
    u8 pad[0xAB4];
    List list;
    s32 which;
} State;
extern State D_30B9D8[];
extern s32 D_0021F198;
extern s32 func_00505B20(void);
static inline s32 count(List *l)
{
    return l->count;
}
static inline Item *item(List *l, s32 index)
{
    if (index < 0) {
        index = l->index;
        if (index < 0)
            return 0;
    }
    return (Item *)((u32)l->items + (u32)index * 24);
}

/* Return the index of the first list entry whose data kind is not 1 and whose id matches D_0021F198, or -1. */
s32 func_004C6AE0(void)
{
    State *p = (State *)((u32)D_30B9D8 + (u32)func_00505B20() * 0xB30);
    s32 key = D_0021F198;
    s32 found = -1;
    s32 i = 0;
    for (; i < count(&p->list); i++) {
        if (found == -1) {
            Data *d = item(&p->list, i)->data;
            if (d->kind != 1) {
                if (d->id == key)
                    found = i;
            }
        }
    }
    return found;
}

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
typedef struct Descriptor {
    u8 pad[0x14];
    s32 available;
} Descriptor;
extern State D_0030B9D8[];
extern s32 func_00505B20(void), func_0054AB08(s32, s32);
extern Descriptor *func_0054A998(s32);
static inline s32 locked(Data *d)
{
    return d->locked;
}
static inline s32 enabled(Data *d)
{
    return d->enabled;
}
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
s32 func_004C6BA0(void)
{
    s32 i = 0, found = -1;
    State *p = (State *)((u32)D_0030B9D8 + (u32)func_00505B20() * 0xB30);
    for (; i < count(&p->list); i++) {
        if (found == -1) {
            Data *d = item(&p->list, i)->data;
            if (d->kind != 1) {
                Descriptor *desc = func_0054A998(func_0054AB08(p->which, d->id));
                if (desc->available && !locked(d) && !enabled(d))
                    found = i;
            }
        }
    }
    return found;
}

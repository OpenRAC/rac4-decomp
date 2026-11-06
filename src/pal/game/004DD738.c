#include "common.h"
typedef struct Data {
    u32 pad;
    s32 id;
} Data;
typedef struct Item {
    u8 pad[8];
    Data *data;
    u8 tail[12];
} Item;
typedef struct List {
    u8 pad[0x34];
    Item *items;
    u8 pad38[0x18];
    s32 count, index;
    u8 tail[0x20];
} List;
typedef struct State {
    u8 pad[0xE4];
    List list;
    u8 tail[0xC];
} State;
extern u8 D_00322FC8[];
extern s32 D_00220AC8;
extern s32 func_00506BB8(void);
static inline s32 count(List *l)
{
    return l->count;
}
static inline Item *item(List *l, s32 i)
{
    if (i < 0) {
        i = l->index;
        if (i < 0)
            return 0;
    }
    return (Item *)((u32)l->items + (u32)i * 24);
}
s32 func_004DD738(void)
{
    State *s = (State *)((u32)D_00322FC8 + (u32)func_00506BB8() * 0x168);
    s32 key = D_00220AC8;
    s32 i;
    for (i = 0; i < count(&s->list); i++)
        if (item(&s->list, i)->data->id == key)
            return i;
    return 0;
}

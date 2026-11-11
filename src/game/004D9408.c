#include "common.h"
typedef struct Data {
    const char *label;
    s32 icon;
} Data;
typedef struct Item {
    u8 pad[8];
    Data *data;
    u8 tail[12];
} Item;
typedef struct List {
    u8 pad[0x34];
    Item *items;
    u8 gap[0x18];
    s32 count, index;
} List;
typedef struct State {
    s32 a, b, flags, handle;
    u8 pad[0x98];
    List list;
    u8 tail[0x14];
} State;
extern State D_00321140[];
extern u8 D_001CE2F8[];
extern s32 D_00221B48;
extern s32 func_00505B20(void), func_00499CA0(const void *, s32), func_004A1A60(s32 *, s32), func_00506120(s32, s32), func_00505238(s32, const char *);
extern void func_00499CE0(s32);
static inline s32 count(List *l)
{
    return l->count;
}
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return (Item *)((u32)l->items + (u32)l->index * 24);
}
void func_004D9408(void)
{
    State *p = (State *)((u32)D_00321140 + (u32)func_00505B20() * 0x114);
    if (count(&p->list) > 0) {
        Data *d = selected(&p->list)->data;
        if (p->handle) {
            func_00499CE0(p->handle);
            p->handle = 0;
        }
        p->handle = func_00499CA0(D_001CE2F8 + d->icon * 8, -1);
        func_00506120(func_004A1A60(&D_00221B48, 2), p->handle);
        func_00505238(func_004A1A60(&D_00221B48, 6), d->label);
    }
    p->flags &= ~2;
}

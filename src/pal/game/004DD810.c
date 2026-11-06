#include "common.h"
typedef struct Object Object;
typedef struct Data {
    u8 pad[8];
    Object *object;
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
    u8 pad[0xE4];
    List list;
    u8 tail[0x2C];
} State;
extern State D_00322FC8[];
u32 D_002212CC = 0;
extern s32 func_00506BB8(void);
extern f32 func_00454158(f32);
extern void func_0046F008(Object *), func_0046F6B8(Object *), func_00470FD0(Object *);
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
void func_004DD810(void)
{
    State *p = (State *)((u32)D_00322FC8 + (u32)func_00506BB8() * 0x168);
    if (count(&p->list)) {
        Data *d = selected(&p->list)->data;
        if (d) {
            Object *o = d->object;
            if (o) {
                u32 shade = (s32)(func_00454158((f32)((s32)(D_002212CC & 63) - 32) * 0.09817477315664291f) * 32.0f + 96.0f);
                *(u32 *)((u32)o + 0x60) = (shade << 24) | (shade << 16) | (shade << 8) | 0x80;
                func_0046F008(o);
                func_0046F6B8(o);
                func_00470FD0(o);
            }
        }
    }
}

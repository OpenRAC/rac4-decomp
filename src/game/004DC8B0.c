#include "common.h"
typedef struct Obj {
    u8 pad[0x60];
    s32 color;
} Obj;
typedef struct Data {
    u8 pad[8];
    Obj *obj;
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
extern s32 D_002211CC;
extern s32 func_00505B20(void);
extern f32 func_00453940(f32);
extern void func_0046E728(Obj *);
extern void func_0046EDD8(Obj *);
extern void func_004706F0(Obj *);
static inline Item *current(List *l)
{
    s32 i = l->index;
    if (i < 0)
        return 0;
    return (Item *)((u32)l->items + (u32)i * 24);
}
void func_004DC8B0(void)
{
    State *s = (State *)((u32)D_00322FC8 + (u32)func_00505B20() * 0x168);
    List *l = &s->list;
    Data *d;
    Obj *o;
    s32 v;
    if (l->count == 0)
        return;
    d = current(l)->data;
    if (d == 0)
        return;
    o = d->obj;
    if (o == 0)
        return;
    v = func_00453940((f32)((D_002211CC & 0x3F) - 0x20) * 0.09817477f) * 32.0f + 96.0f;
    o->color = (v << 24) | (v << 16) | (v << 8) | 0x80;
    func_0046E728(o);
    func_0046EDD8(o);
    func_004706F0(o);
}

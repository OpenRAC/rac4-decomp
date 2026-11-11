#include "common.h"
typedef struct Obj {
    u8 pad[0x23];
    u8 f23;
} Obj;
typedef struct Data {
    u8 pad[8];
    Obj *obj;
    s32 fC;
    s32 f10, f14, f18, f1C, f20;
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
    u8 tail[0x1C];
} List;
typedef struct State {
    u32 f0;
    s32 f4;
    u8 pad[0xDC];
    List list;
    s32 f158;
    u8 tail[0xC];
} State;
typedef struct Slot {
    u8 pad[8];
    Obj *obj;
    u8 tail[0x18];
} Slot;
typedef struct Desc {
    s32 a, b;
} Desc;
extern u8 D_00322FC8[];
extern s32 D_00221B88;
extern Desc D_001CE328[];
extern Slot D_00323130[];
extern s32 func_00505B20(void);
extern void func_0046E728(Obj *);
extern void func_0046EDD8(Obj *);
extern void func_004706F0(Obj *);
extern u32 func_00499CA0(void *descriptor, s32 sectorBase);
extern void func_00499CE0(s32 arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00505238(u32, const char *);
extern s32 func_00506120(u32 id, u32 value);
static inline Item *current(List *l)
{
    s32 i = l->index;
    if (i < 0)
        return 0;
    return (Item *)((u32)l->items + (u32)i * 24);
}
void func_004DC5F8(void)
{
    State *s = (State *)((u32)D_00322FC8 + (u32)func_00505B20() * 0x168);
    List *l = &s->list;
    Data *d;
    s32 i;
    if (l->count > 0) {
        d = current(l)->data;
        func_00505238(func_004A1A60(&D_00221B88, 9), (const char *)d->f10);
        func_00505238(func_004A1A60(&D_00221B88, 0x10), (const char *)d->f14);
        func_00505238(func_004A1A60(&D_00221B88, 0xC), (const char *)d->f18);
        func_00505238(func_004A1A60(&D_00221B88, 0x11), (const char *)d->f1C);
        func_00505238(func_004A1A60(&D_00221B88, 0xA), (const char *)d->f20);
        if (s->f158 != 0) {
            func_00499CE0(s->f158);
            s->f158 = 0;
        }
        s->f158 = func_00499CA0(&D_001CE328[d->fC], -1);
        func_00506120(func_004A1A60(&D_00221B88, 4), s->f158);
        for (i = 0; i < 6; i++) {
            Obj *o = D_00323130[i].obj;
            o->f23 = 0;
            func_0046E728(o);
            func_0046EDD8(o);
            func_004706F0(o);
        }
        d->obj->f23 = 0x80;
        func_0046E728(d->obj);
        func_0046EDD8(d->obj);
        func_004706F0(d->obj);
    }
    s->f4 &= ~2;
}

#include "common.h"
typedef struct {
    char pad[0x30];
    s32 label;
} Data;
typedef struct {
    s32 a, b;
    Data *data;
    char tail[12];
} Item;
typedef struct {
    char pad[0x34];
    Item *items;
    char gap[0x18];
    s32 count, index;
} List;
typedef struct {
    s32 a, b, flags;
    char pad[0x968];
    List list;
    char tail[0x14];
} State;
extern State D_00316D00[];
extern s32 D_00221A80;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32), func_005062D0(s32, const char *), func_00506000(s32, s32);
extern const char *func_0045E850(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004D07F0(void)
{
    State *p = D_00316D00 + func_00506BB8();
    List *l = &p->list;
    if (l->count > 0) {
        Data *d = selected(l)->data;
        s32 handle = func_004A2798(&D_00221A80, 0xD);
        func_005062D0(handle, func_0045E850(d->label));
        func_00506000(func_004A2798(&D_00221A80, 0xD), 1);
    } else
        func_00506000(func_004A2798(&D_00221A80, 0xD), 0);
    p->flags &= ~2;
}

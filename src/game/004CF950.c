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
extern s32 D_00221980;
extern s32 func_00505B20(void), func_004A1A60(s32 *, s32), func_00505238(s32, const char *), func_00504F68(s32, s32);
extern const char *func_0045E038(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004CF950(void)
{
    State *p = D_00316D00 + func_00505B20();
    List *l = &p->list;
    if (l->count > 0) {
        Data *d = selected(l)->data;
        s32 handle = func_004A1A60(&D_00221980, 0xD);
        func_00505238(handle, func_0045E038(d->label));
        func_00504F68(func_004A1A60(&D_00221980, 0xD), 1);
    } else
        func_00504F68(func_004A1A60(&D_00221980, 0xD), 0);
    p->flags &= ~2;
}

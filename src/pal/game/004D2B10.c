#include "common.h"
typedef struct {
    s32 a, b, label, icon;
} Data;
typedef struct {
    s32 a, b;
    Data *data;
    u8 tail[12];
} Item;
typedef struct {
    u8 pad[0x34];
    Item *items;
    u8 gap[0x1C];
    s32 index;
} List;
typedef struct {
    s32 mode, a, flags;
    u8 gap[4];
    s32 handle;
    u8 pad[0xDC];
    List list;
    u8 tail[0x14];
} State;
extern State D_0031B050[];
extern s32 D_00221AC0;
extern u8 D_001CDF58[];
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32), func_005062D0(s32, const char *), func_0049A9D8(const void *, s32), func_005071B8(s32, s32);
extern const char *func_0045E850(s32);
extern void func_0049AA18(s32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004D2B10(void)
{
    State *p = D_0031B050 + func_00506BB8();
    Data *d = selected(&p->list)->data;
    s32 handle = func_004A2798(&D_00221AC0, 16);
    u8 *icon;
    func_005062D0(handle, func_0045E850(d->label));
    icon = D_001CDF58 + d->icon * 8;
    if (p->handle) {
        func_0049AA18(p->handle);
        p->handle = 0;
    }
    p->handle = func_0049A9D8(icon, -1);
    func_005071B8(func_004A2798(&D_00221AC0, 11), p->handle);
    p->flags &= ~2;
}

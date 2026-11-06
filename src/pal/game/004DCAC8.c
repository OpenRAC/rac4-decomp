#include "common.h"
typedef struct {
    s32 a, b;
    void *data;
    char tail[12];
} Item;
typedef struct {
    s32 mode, flags;
    char gap[4];
    Item items[9];
    char list[0x7C];
    f32 timer;
    char tail[4];
} State;
extern State D_00322FC8[];
extern s32 D_00221C88;
extern s32 func_00506BB8(void), func_004A2798(s32 *, s32);
extern void func_004DCDC0(void), func_004A1E78(void *, Item *, s32, void (*)(void *, Item *, s32), s32, s32), func_004A1EA8(void *), func_0049CF80(s32, s32), func_0049DEA8(s32, s32, s32), func_0049DFB8(s32, s32);
void func_004DCAC8(void)
{
    s32 index = func_00506BB8();
    State *p = D_00322FC8 + index;
    func_004DCDC0();
    p->mode = 0;
    func_004A1E78(p->list, p->items, 9, 0, 0, 0);
    p->timer = 0.024543693f;
    func_0049CF80(index, 0);
    func_0049DEA8(index, 0, func_004A2798(&D_00221C88, 0x12));
    func_0049DFB8(index, 1);
    func_004A1EA8(p->list);
    p->flags = 7;
}

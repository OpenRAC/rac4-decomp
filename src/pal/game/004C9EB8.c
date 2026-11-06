#include "common.h"
typedef struct {
    s32 kind, other, count;
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
extern List D_0030E494;
extern s32 func_004E7EC8(Data *), func_00506BB8(void);
extern const char *func_0045E850(s32);
extern void func_004C9DD8(s32), func_004985F0(s32), func_0049F4C8(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004C9EB8(void)
{
    if (D_0030E494.count) {
        Data *d = selected(&D_0030E494)->data;
        if (func_004E7EC8(d)) {
            if (d->count <= 0 || d->kind == 1)
                func_004C9DD8(1);
            else {
                s32 index = func_00506BB8();
                func_0049F4C8(index, func_0045E850(0x8D0), func_004C9DD8, 3, 0, 0, 0, -1.0f);
            }
        } else
            func_004985F0(4);
    }
}

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
extern s32 func_004E6FA0(Data *), func_00505B20(void);
extern const char *func_0045E038(s32);
extern void D_004C8FB0(s32), func_00497980(s32), func_0049E790(s32, const char *, void (*)(s32), s32, s32, s32, s32, f32);
static inline Item *selected(List *l)
{
    if (l->index < 0)
        return 0;
    return l->items + l->index;
}
void func_004C9090(void)
{
    if (D_0030E494.count) {
        Data *d = selected(&D_0030E494)->data;
        if (func_004E6FA0(d)) {
            if (d->count <= 0 || d->kind == 1)
                D_004C8FB0(1);
            else {
                s32 index = func_00505B20();
                func_0049E790(index, func_0045E038(0x8D0), D_004C8FB0, 3, 0, 0, 0, -1.0f);
            }
        } else
            func_00497980(4);
    }
}

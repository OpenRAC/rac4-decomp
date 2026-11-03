#include "common.h"
typedef struct {
    s32 f0, type, level, total;
} Data;
typedef struct {
    u8 pad[0x21];
    u8 a, b, c, d, e;
    u8 pad26[0x10];
    s16 total;
} State;
extern State D_00171BC0;
s32 func_0054C330(Data *p)
{
    if (p->type == 1 && D_00171BC0.a < p->level)
        return 0;
    if (p->type == 2 && D_00171BC0.b < p->level)
        return 0;
    if (p->type == 3 && D_00171BC0.c < p->level)
        return 0;
    if (p->type == 4 && D_00171BC0.d < p->level)
        return 0;
    if (p->type == 5 && D_00171BC0.e < p->level)
        return 0;
    return D_00171BC0.total >= p->total;
}

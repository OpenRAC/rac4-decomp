#include "common.h"
typedef struct { s32 a; s32 b; s8 c; } E3;
extern s32 D_00222C40;
extern E3 D_00267120[];
s32 func_L01_00573C00(s32 a, s32 b, s32 c)
{
    s32 i = D_00222C40;
    E3 *e;
    if (i >= 0x20) {
        return 0;
    }
    e = &D_00267120[i];
    D_00222C40 = i + 1;
    e->a = a;
    e->b = b;
    e->c = c;
    return 1;
}

#include "common.h"
extern s32 D_0021EE54;
typedef struct {
    char pad[0x18];
    f32 a, b;
} Object;
s32 func_004337F0(Object *p)
{
    if (D_0021EE54 == 1)
        return p->a >= 2.2f && p->b >= 1.2f;
    return p->a >= 3.5f && p->b >= 1.6f;
}

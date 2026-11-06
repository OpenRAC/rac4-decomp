#include "common.h"
typedef struct {
    char pad[0x38];
    s32 x;
    s32 y;
} Object;
extern Object *func_0048A970(u32);
s32 func_0048A3C0(f32 a, f32 b, void *unused, u32 index)
{
    s32 result = 0;
    Object *p = func_0048A970(index);
    if (p) {
        p->x = (s32)(a * 1024.0f);
        p->y = (s32)(b * 1024.0f);
        result = 1;
    }
    return result;
}

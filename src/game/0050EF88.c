#include "common.h"
typedef struct {
    char pad[0x44];
    u8 f44;
} Object;
extern void func_0050EF28(Object *, s32, s32);
s32 func_0050EF88(Object *a, s32 b, s32 c)
{
    s32 x = 0;
    s32 valid = 1;
    s32 y = 0;
    if (b == 0) {
    } else if (b == 1)
        x = 1;
    else
        valid = 0;
    if (c == 0)
        y = 1;
    else if (c != 1)
        valid = 0;
    func_0050EF28(a, 1, x);
    func_0050EF28(a, 2, y);
    a->f44 = 1;
    return valid;
}

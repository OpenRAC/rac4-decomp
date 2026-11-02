#include "common.h"

typedef struct Type2 {
    char pad[0x34];
    f32 f34, f38;
    char pad3C[0x12];
    s16 f4E;
    char pad50;
    u8 f51;
} Type2;
typedef struct Type1 {
    char pad[0x40];
    Type2 *f40;
    u8 f44;
} Type1;
/* Set the two values, reset the counter and mark the object changed. */
void func_0050FF50(Type1 *p, s32 flag, f32 a, f32 b)
{
    p->f40->f34 = a;
    p->f40->f38 = b;
    p->f40->f4E = 0;

    {
        Type2 *q = p->f40;
        if (flag)
            q->f51 = 0;
        else
            q->f51 = 1;
    }
    p->f44 = 1;
}

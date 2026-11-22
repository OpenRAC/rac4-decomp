#include "common.h"
typedef struct { s32 a; s16 b; s16 c; s32 d; s16 e; } S;
s32 func_L01_00572B08(S *p, u16 a, s32 b, u16 c)
{
    if (p == 0) {
        return 1;
    }
    p->a = b;
    p->c = c;
    p->e = a;
    return 1;
}

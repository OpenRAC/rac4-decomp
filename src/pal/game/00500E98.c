#include "common.h"

typedef struct Type1 {
    float f0, f4, f8, fC, f10, f14;
} Type1;
/* Reset the pointed rectangle parameters. */
void func_00500E98(Type1 **p)
{
    Type1 s;
    s.f0 = 0.0f;
    s.f4 = 0.0f;
    s.f8 = 1.0f;
    s.fC = 1.0f;
    s.f10 = 0.0f;
    s.f14 = 0.0f;
    **p = s;
}

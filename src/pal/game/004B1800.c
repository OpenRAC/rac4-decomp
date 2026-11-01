#include "common.h"

typedef struct Type1 {
    int f0;
    char p[8];
} Type1;
typedef struct Type2 {
    char p[12];
    int fC;
    int f10;
    void (*f14)(int);
} Type2;
extern Type1 D_003D1B70[];
extern Type2 D_003096B0[];
extern int D_00221818;
extern s32 func_004A2798(s32 *, s32);
extern s32 func_00506000(s32, s32);
/* Refresh the ten availability indicators and invoke the completion callback. */
void func_004B1800(void)
{
    int i;
    Type1 *p = D_003D1B70;
    for (i = 0; i < 10; i++, p++)
        func_00506000(func_004A2798(&D_00221818, p->f0), i < D_003096B0[0].fC);
    D_003096B0[0].f14(0);
}

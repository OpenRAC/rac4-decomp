#include "common.h"

typedef struct Type1 {
    int f0;
    char p[16];
} Type1;
typedef struct Type2 {
    char p[4];
    int f4;
    int f8;
    void (*fC)(int);
} Type2;
extern Type1 D_003D92D0[];
extern Type2 D_00309650[];
extern int D_00221728;
s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_00504F68(s32, s32);
/* Refresh four availability indicators and invoke the completion callback. */
void func_004B15E8(void)
{
    int i;
    Type1 *p = D_003D92D0;
    for (i = 0; i < 4; i++, p++)
        func_00504F68(func_004A1A60(&D_00221728, p->f0), i < D_00309650[0].f4);
    D_00309650[0].fC(0);
}

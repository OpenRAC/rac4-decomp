#include "common.h"

typedef struct Type1 {
    s32 f0;
    char *f4, *f8;
} Type1;
extern Type1 D_0023F530[];
extern void func_0045F020(void);

/* Allocate an aligned block from the initialized linear buffer. */
void *func_0045EFA8(s32 size)
{
    char *result;
    if (!D_0023F530[0].f4)
        func_0045F020();
    if (D_0023F530[0].f8 - D_0023F530[0].f4 < size)
        return 0;
    result = D_0023F530[0].f4;
    size = (size + 15) & ~15u;
    D_0023F530[0].f4 += size;
    return result;
}

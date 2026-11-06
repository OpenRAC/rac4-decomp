#include "common.h"

typedef struct Type1 {
    s32 f0;
    char *f4, *f8;
} Type1;
extern Type1 D_0023F430[];
extern void func_0045E808(void);

/* Allocate an aligned block from the initialized linear buffer. */
void *func_0045E790(s32 size)
{
    char *result;
    if (!D_0023F430[0].f4)
        func_0045E808();
    if (D_0023F430[0].f8 - D_0023F430[0].f4 < size)
        return 0;
    result = D_0023F430[0].f4;
    size = (size + 15) & ~15u;
    D_0023F430[0].f4 += size;
    return result;
}

#include "common.h"

int D_00220DA0 = 0;
typedef struct Type1 {
    int f0;
    char p[0x33C];
} Type1;
extern Type1 D_00345CC0[];
/* Find the first table entry with the requested identifier. */
void *func_0053E0D8(int a)
{
    int i;
    for (i = 0; i < D_00220DA0; i++) {
        Type1 *p = D_00345CC0 + i;
        if (p->f0 == a)
            return p;
    }
    return 0;
}

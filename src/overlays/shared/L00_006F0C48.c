#include "common.h"

int D_002206C4 = 0;
typedef struct Type1 {
    int f0;
    char p[0x33C];
} Type1;
extern Type1 D_00358FA0[];
/* Find the first table entry with the requested identifier. */
void *func_L00_006F0C48(int a)
{
    int i;
    for (i = 0; i < D_002206C4; i++) {
        Type1 *p = D_00358FA0 + i;
        if (p->f0 == a)
            return p;
    }
    return 0;
}

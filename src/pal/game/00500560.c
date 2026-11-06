#include "common.h"

extern int D_00220C08;
typedef struct Type1 {
    char p[20];
    int (*f14)(void *, int);
} Type1;
typedef struct Type2 {
    char p[8];
    Type1 *f8;
} Type2;
/* Return the object if its virtual predicate succeeds. */
void *func_00500560(Type2 *p)
{
    if (p && p->f8->f14(p, D_00220C08))
        return p;
    return 0;
}

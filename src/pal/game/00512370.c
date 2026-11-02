#include "common.h"
extern unsigned int *func_005123A0(void *);
/* Resolve the resource and read its identifier. */
unsigned int func_00512370(void *p)
{
    unsigned int *q = func_005123A0(p);
    if (q)
        return *q;
    return 0xFFFFFFFFu;
}

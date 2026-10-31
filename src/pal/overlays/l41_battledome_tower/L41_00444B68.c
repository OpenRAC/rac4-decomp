#include "common.h"

typedef struct {
    char pad0[0xA];
    short fA;
} Type1;

extern Type1 *func_004546C8(int);

/* Return the signed halfword at offset 0xA, or -1 for a failed lookup. */
long func_L41_00444B68(short a1)
{
    long result = -1;
    Type1 *p;

    if (a1 < 0) return -1;
    p = func_004546C8(a1);
    if (p) result = p->fA;
    return result;
}

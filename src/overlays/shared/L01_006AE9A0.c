#include "common.h"

int D_00220844 = 0;
typedef struct Type1 {
    int f0;
    char pad[0x2AC];
    int f2B0;
    char tail[0x8C];
} Type1;
extern Type1 D_0037B320[];
/* Find the first table entry with the requested identifier. */
void *func_L01_006AE9A0(int a)
{
    int i;
    for (i = 0; i < D_00220844; i++) {
        Type1 *p = D_0037B320 + i;
        if (p->f0 == a)
            return p;
    }
    return 0;
}

/* Looks up the identifier in the second field of each entry. */
void *func_L01_006AE9E8(int a)
{
    int i;
    for (i = 0; i < D_00220844; i++) {
        Type1 *p = D_0037B320 + i;
        if (p->f2B0 == a)
            return p;
    }
    return 0;
}

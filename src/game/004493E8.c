#include "common.h"
typedef struct Type1 {
    void (*f0)(void *);
    void *f4;
    struct Type1 *f8;
    struct Type1 *fC;
} Type1;
extern s32 D_00221254;
extern Type1 D_00238540[];

/* Appends a record from the fixed pool to the list. */
void func_004493E8(Type1 **a, void (*b)(void *), void *c)
{
    Type1 *p;
    s32 n = D_00221254;
    if (n < 256) {
        p = &D_00238540[n];
        D_00221254 = n + 1;
        p->f0 = b;
        p->f4 = c;
        if (*a)
            (*a)->fC->f8 = p;
        else
            *a = p;
        (*a)->fC = p;
    }
}

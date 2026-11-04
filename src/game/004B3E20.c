#include "common.h"
typedef struct {
    char p0[0x168];
    void *f168[3];
    void *f174;
    void *f178;
} Type1;
extern Type1 D_003096A8[];
void func_00499CE0(s32 arg0);

/* Releases two objects and three array slots, clearing each pointer. */
void func_004B3E20(void)
{
    Type1 *p = D_003096A8;
    void **q;
    s32 i;
    if (p->f178) {
        func_00499CE0(p->f178);
        p->f178 = 0;
    }
    if (p->f174) {
        func_00499CE0(p->f174);
        p->f174 = 0;
    }
    q = p->f168;
    i = 2;
    do {
        if (*q) {
            func_00499CE0(*q);
            *q = 0;
        }
        q++;
        i--;
    } while (i >= 0);
}

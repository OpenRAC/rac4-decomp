#include "common.h"

typedef struct Type1 {
    char pad[16];
    void (*f10)(void *);
} Type1;
extern Type1 D_003F0F00[];
/* Invoke the optional handler selected by the object. */
void func_0043B4F0(char *p)
{
    void (*f)(void *) = D_003F0F00[*(short *)(p + 0x8C)].f10;
    if (f)
        f(p);
}

/* cflags:  */
#include "common.h"

typedef struct Type1 {
    char pad[16];
    void (*f10)(void *);
} Type1;
extern Type1 D_004EF300[];
/* Invoke the optional handler selected by the object. */
void func_L00_0059D060(char *p)
{
    void (*f)(void *) = D_004EF300[*(short *)(p + 0x8C)].f10;
    if (f)
        f(p);
}

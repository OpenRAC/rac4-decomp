#include "common.h"

extern char D_00335E58[];
typedef struct Type1 {
    int f0;
    char *f4;
} Type1;
extern Type1 D_00222138[];
extern void func_00453E20(void *, int, int);
/* Initialize the shared buffer and return its descriptor. */
void *func_00502150(void)
{
    Type1 *p = D_00222138;
    p->f4 = D_00335E58;
    func_00453E20(D_00335E58 + 0x18, 0, 0x14);
    func_00453E20(p->f4, 0, 0x14);
    func_00453E20(p->f4 + 0x2C, 0, 0x30);
    func_00453E20(p->f4 + 0x5C, 0, 0x10);
    func_00453E20(p->f4 + 0x70, 0, 0x10);
    *(int *)(p->f4 + 0x6C) = 0;
    *(int *)(p->f4 + 0x80) = 0;
    *(int *)(p->f4 + 0x14) = 0;
    *(unsigned char *)(p->f4 + 0x84) = 0x3C;
    return p;
}

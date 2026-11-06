#include "common.h"
typedef struct {
    const void *a, *b, *c;
} Args;
extern unsigned char D_00239540[];
extern int D_002212F8;
extern void func_0044AD28(void), func_0044D1B8(void *), func_0044CE08(s32, const void *, const void *, const void *, s32, s32);
void func_0044DAB0(Args *p, int flags)
{
    if (!D_00239540[0])
        func_0044AD28();
    else if (D_002212F8 != 8) {
        func_0044AD28();
        func_0044D1B8(D_00239540);
    }
    func_0044CE08(4, p->a, p->b, p->c, flags, 1);
}

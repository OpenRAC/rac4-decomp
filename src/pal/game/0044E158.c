#include "common.h"
typedef struct {
    const void *a, *b, *c;
} Args;
extern unsigned char D_00239640[];
extern int D_002213F8;
extern void func_0044B3D0(void), func_0044D860(void *), func_0044D4B0(s32, const void *, const void *, const void *, s32, s32);
void func_0044E158(Args *p, int flags)
{
    if (!D_00239640[0])
        func_0044B3D0();
    else if (D_002213F8 != 8) {
        func_0044B3D0();
        func_0044D860(D_00239640);
    }
    func_0044D4B0(4, p->a, p->b, p->c, flags, 1);
}

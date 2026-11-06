#include "common.h"

/* Choose the packed color from the three state flags and the selection. */
typedef struct {
    u8 f0, f1, f2;
} Type1;
u32 func_004C70C0(Type1 *p, s32 a)
{
    if (p->f0)
        return 0x80404040;
    if (a)
        return 0x808080F0;
    if (p->f2)
        return 0x8080F0F0;
    {
        u32 result = 0x80808080;
        if (!p->f1)
            result = 0x80D0D0D0;
        return result;
    }
}

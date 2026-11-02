#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    u32 f0;
    s32 f4, f8;
    char padC[0x49];
    u8 f55;
    char pad56[2];
    Type1 *f58;
};
Type1 *D_00220E2C = 0;

/* Find the first linked entry matching its owner, category, and optional flag. */
Type1 *func_0053DDA0(s32 *owner, s32 category, s32 flagged)
{
    Type1 *p = D_00220E2C;
    s32 identifier = *owner;
    while (p) {
        if (p->f8 == identifier && (p->f0 & 15) == category && (!flagged || p->f55))
            break;
        p = p->f58;
    }
    return p;
}

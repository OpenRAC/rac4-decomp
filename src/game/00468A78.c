#include "common.h"

typedef struct {
    s32 type, size, offset, state;
} Descriptor;
extern Descriptor D_003D80F0[], D_003D82D0[];
extern s32 func_00468B40(const Descriptor *);
extern s32 func_00468C78(u8 *, s32, const Descriptor *);

void func_00468A78(u8 *dst)
{
    s32 i;
    *(s32 *)dst = func_00468B40(D_003D80F0);
    *(s32 *)(dst + 4) = func_00468B40(D_003D82D0);
    dst += 8;
    dst += func_00468C78(dst, 0, D_003D80F0);
    for (i = 0; i < 15; i++) {
        dst += func_00468C78(dst, i, D_003D82D0);
    }
}

#include "common.h"

extern u8 *D_002215D8;
extern void func_00453F30(void *, const void *, u32);
extern u8 *func_0048C2D0(u32, u8 **, const u8 *);

s32 func_0048C420(const u8 *source, u8 **cursor, const u8 *limit)
{
    s32 i;

    func_00453F30(D_002215D8 + 0x3014, source, 4);
    source += 4;
    (*(u8 **)(D_002215D8 + 0x3018)) = func_0048C2D0((u32)(*(s32 *)(D_002215D8 + 0x3014)) << 5, cursor, limit);
    if ((*(u8 **)(D_002215D8 + 0x3018)) == 0) {
        return 1;
    }
    for (i = 0; i < (*(s32 *)(D_002215D8 + 0x3014)); i++) {
        func_00453F30((*(u8 **)(D_002215D8 + 0x3018)) + (i << 5), source, 32);
        source += 32;
    }
    return 0;
}

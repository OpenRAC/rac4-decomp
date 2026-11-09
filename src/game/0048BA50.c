#include "common.h"

extern u8 *D_002214D8;
extern void func_00453718(void *, const void *, u32);
extern u32 func_0048B818(s32 arg0, u32 *arg1, u32 arg2);

/* reads a count then count 8-byte records from source into a buffer allocated from cursor */
s32 func_0048BA50(const u8 *source, u32 *cursor, u32 limit)
{
    s32 i;

    func_00453718(D_002214D8 + 0x301C, source, 4);
    source += 4;
    (*(u32 *)(D_002214D8 + 0x3020)) = func_0048B818(*(s32 *)(D_002214D8 + 0x301C) << 3, cursor, limit);
    if ((*(u8 **)(D_002214D8 + 0x3020)) == 0) {
        return 1;
    }
    for (i = 0; i < (*(s32 *)(D_002214D8 + 0x301C)); i++) {
        func_00453718((*(u8 **)(D_002214D8 + 0x3020)) + (i << 3), source, 8);
        source += 8;
    }
    return 0;
}

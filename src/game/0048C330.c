#include "common.h"

extern u8 *D_002214D8;
extern void func_00453718(void *, const void *, u32);
extern void *func_0048B818(u32, u8 **, const u8 *);
s32 func_0048C330(const u8 *source, u8 **cursor, const u8 *limit)
{
    s32 i;
    if (*(s32 *)(D_002214D8 + 0x3000) < 2) {
        *(u8 **)(D_002214D8 + 0x3038) = 0;
        *(s32 *)(D_002214D8 + 0x3034) = 0;
        return 0;
    }
    func_00453718(D_002214D8 + 0x3034, source, 4);
    source += 4;
    *(u8 **)(D_002214D8 + 0x3038) = func_0048B818((u32) * (s32 *)(D_002214D8 + 0x3034) << 2, cursor, limit);
    if (!*(u8 **)(D_002214D8 + 0x3038))
        return 1;
    for (i = 0; i < *(s32 *)(D_002214D8 + 0x3034); i++) {
        func_00453718(*(u8 **)(D_002214D8 + 0x3038) + i * 4, source, 4);
        source += 4;
    }
    return 0;
}

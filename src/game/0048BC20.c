#include "common.h"
extern u8 *D_002214D8;
extern void func_00453718(void *, const void *, u32);
extern void *func_0048B818(u32, u8 **, const u8 *);
static inline s32 count(void)
{
    return *(s32 *)(D_002214D8 + 0x303C);
}
static inline u8 *values(void)
{
    return (u8 *)*(u32 *)(D_002214D8 + 0x3040);
}
s32 func_0048BC20(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 i;
    func_00453718(D_002214D8 + 0x303C, input, 4);
    input += 4;
    *(u32 *)(D_002214D8 + 0x3040) = (u32)func_0048B818((u32)count() * 12u, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count(); i++) {
        func_00453718(values() + ((u32)i * 12u), input, 12);
        input += 12;
    }
    return 0;
}

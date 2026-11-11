#include "common.h"
extern u8 *D_00222550;
extern void func_00453718(void *, const void *, u32);
extern void *func_0048B818(u32, u8 **, const u8 *);
static inline s32 count(void)
{
    return *(s32 *)(D_00222550 + 0x301C);
}
static inline u8 *values(void)
{
    return (u8 *)*(u32 *)(D_00222550 + 0x3020);
}
s32 func_L00_006027E8(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 i;
    func_00453718(D_00222550 + 0x301C, input, 4);
    input += 4;
    *(u32 *)(D_00222550 + 0x3020) = (u32)func_0048B818((u32)count() << 3, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count(); i++) {
        func_00453718(values() + ((u32)i << 3), input, 8);
        input += 8;
    }
    return 0;
}

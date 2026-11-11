#include "common.h"
extern u8 *D_00222550;
extern void func_00453718(void *, const void *, u32);
extern void *func_0048B818(u32, u8 **, const u8 *);
static inline u32 *values(void)
{
    return (u32 *)*(u32 *)(D_00222550 + 0x3008);
}
s32 func_L00_00602C58(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 count;
    s32 i;
    func_00453718(&count, input, 4);
    input += 4;
    *(u32 *)(D_00222550 + 0x3008) = (u32)func_0048B818((u32)count << 2, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count; i++) {
        func_00453718(values() + i, input, 4);
        input += 4;
    }
    return 0;
}

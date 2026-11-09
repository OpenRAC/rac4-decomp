/* cflags:  */
#include "common.h"
extern u8 *D_00222650;
extern void func_00453F30(void *, const void *, u32);
extern void *func_0048C2D0(u32, u8 **, const u8 *);
static inline s32 count(void)
{
    return *(s32 *)(D_00222650 + 12356);
}
static inline u8 *values(void)
{
    return (u8 *)*(u32 *)(D_00222650 + 12360);
}
s32 func_L00_00605700(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 i;
    func_00453F30(D_00222650 + 12356, input, 4);
    input += 4;
    *(u32 *)(D_00222650 + 12360) = (u32)func_0048C2D0((u32)count() << 3, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count(); i++) {
        func_00453F30(values() + ((u32)i << 3), input, 8);
        input += 8;
    }
    return 0;
}

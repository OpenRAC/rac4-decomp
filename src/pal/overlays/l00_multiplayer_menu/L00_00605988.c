/* cflags:  */
#include "common.h"
extern u8 *D_00222650;
extern void func_00453F30(void *, const void *, u32);
extern void *func_0048C2D0(u32, u8 **, const u8 *);
static inline s32 count(void)
{
    return *(s32 *)(D_00222650 + 0x305C);
}
static inline u8 *values(void)
{
    return (u8 *)*(u32 *)(D_00222650 + 0x3060);
}
s32 func_L00_00605988(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 i;
    func_00453F30(D_00222650 + 0x305C, input, 4);
    input += 4;
    *(u32 *)(D_00222650 + 0x3060) = (u32)func_0048C2D0((u32)count() * 4u, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count(); i++) {
        func_00453F30(values() + ((u32)i * 4u), input, 4);
        input += 4;
    }
    return 0;
}

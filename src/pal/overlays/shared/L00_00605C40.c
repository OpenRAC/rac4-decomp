/* cflags:  */
#include "common.h"
extern s32 D_00222650;
extern void func_00453F30(void *, const void *, u32);
extern void *func_0048C2D0(u32, u8 **, const u8 *);
static inline s32 count(void)
{
    return *(s32 *)(((u8 *)D_00222650 + 12404));
}
static inline u8 *values(void)
{
    return (u8 *)*(u32 *)(((u8 *)D_00222650 + 12408));
}
s32 func_L00_00605C40(const u8 *input, u8 **cursor, const u8 *end)
{
    s32 i;
    func_00453F30(((u8 *)D_00222650 + 12404), input, 4);
    input += 4;
    *(u32 *)(((u8 *)D_00222650 + 12408)) = (u32)func_0048C2D0((u32)count() * 4u, cursor, end);
    if (!values())
        return 1;
    for (i = 0; i < count(); i++) {
        func_00453F30(values() + ((u32)i * 4u), input, 4);
        input += 4;
    }
    return 0;
}

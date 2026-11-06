/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_001710E0[];
extern void func_01EF382C(void *);
extern s32 func_01F0C19C(void *);

s32 func_01F0C1F8(u8 *obj)
{
    func_01EF382C(obj);
    *(u32 *)(obj + 0xB0) = (u32)D_001710E0;
    return func_01F0C19C(obj);
}

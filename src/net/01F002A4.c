/* cflags: @ee296 -O2 -G0 -mno-split-addresses */
#include "common.h"

extern u8 D_00170978[];
extern void func_01EF382C(void *);
extern s32 func_01F0026C(void *);

s32 func_01F002A4(u8 *obj)
{
    func_01EF382C(obj);
    *(u32 *)(obj + 0xB0) = (u32)D_00170978;
    return func_01F0026C(obj);
}

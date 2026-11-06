/* cflags: @ee296 -O2 -G0 -falign-jumps=1 -mno-split-addresses */
#include "common.h"

extern u8 D_00170088[];
extern u8 D_0016FF60[];
extern void func_01EF5C4C(void *);
extern void func_01EF3748(void *);

void func_01EF59AC(u8 *obj, s32 flag)
{
    *(u32 *)(obj + 0xB0) = (u32)D_00170088;
    func_01EF5C4C(obj);
    *(u32 *)(obj + 0xB0) = (u32)D_0016FF60;
    if (flag & 1) {
        func_01EF3748(obj);
    }
}

/* cflags: @ee29 */
#include "common.h"
extern u32 func_00139A58(u32);
extern void func_001399E0(void *);

void func_00139DA0(u8 *object, u32 address)
{
    u32 value = func_00139A58(address);
    s32 flags;
    func_001399E0((void *)object);
    if (*(u32 *)(object + 0x30) != 0xFFFFFFFFU)
        *(u32 *)(object + 0x30) = value;
    flags = *(s32 *)object;
    *(u32 *)(object + 0x20) = 0;
    *(s32 *)object = (flags & ~0xC) | 0x105;
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_00141108(void *decoder);
extern void func_00141140(void *decoder, s32 bits);

void func_001412A8(void *decoder)
{
    s32 bits;
    func_00141108(decoder);
    bits = (0U - (*(volatile u32 *)0x10002020 & 7U)) & 7U;
    if (bits != 0)
        func_00141140(decoder, bits);
}

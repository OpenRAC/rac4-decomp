/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0013EAE0(void *decoder);

void func_0013EFD8(void *decoder)
{
    if ((*(volatile u32 *)0x10002010 & 0x80004000U) == 0x80000000U)
        func_0013EAE0(decoder);
}

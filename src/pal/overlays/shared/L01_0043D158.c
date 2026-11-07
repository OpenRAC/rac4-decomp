/* cflags: -O2 -G8 -Wuninitialized */
#include "common.h"
typedef unsigned int QuadWord __attribute__((mode(TI)));
extern u32 D_00222E14;
QuadWord func_L01_0043D158(void *arg0)
{
    u8 *owner = *(u8 **)((u8 *)arg0 + 0xAC);
    u32 index = *(u32 *)(owner + 0x68);
    u32 address = D_00222E14 + (index << 8);
    return *(QuadWord *)(address + 0x10);
}

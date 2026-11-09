/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Clears two buffers and counters. */
void func_01EFBFB4(u8 *p)
{
  func_0011A518(p+0xb8,0,0x200); func_0011A518(p+0x2e4,0,0x200); *(s32*)(p+0x2c0)=0; *(s32*)(p+0x2dc)=0; *(s32*)(p+0x2e0)=0;
}

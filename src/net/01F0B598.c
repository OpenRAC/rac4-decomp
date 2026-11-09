/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *,s32,s32);
/* Clears the optional buffer and counters. */
void func_01F0B598(u8 *p)
{
 void *q=*(void**)(p+0xc0); if(q) func_0011A518(q,0,*(s32*)(p+0xc4)*4); *(s32*)(p+0xcc)=0; *(s32*)(p+0xd0)=0; *(s32*)(p+0xd4)=0;
}

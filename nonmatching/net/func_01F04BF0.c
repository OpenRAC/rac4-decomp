/* Not matching yet: SIZE ours 56 / retail 60 (tools/try_func.py func_01F04BF0 --diff). Not part of the build. */
/* cflags: @ee296 -Os -G0 -falign-loops=1 */
#include "common.h"
/* Reset the indexed records and their counters. */
void func_01F04BF0(u8 *p)
{
    s32 i, offset=0x480;
    for (i=31; i>=0; --i) {
        s32 *q=(s32 *)((u32)p+offset);
        offset+=8;
        q[1]=0;
        q[0]=-1;
    }
    *(s32 *)(p+0x588)=-1;
    *(s32 *)(p+0x584)=0;
    *(s32 *)(p+0x58c)=0;
    *(s32 *)(p+0x580)=0;
}

/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void *func_0011A518(void *, s32, s32);
/* Clears the embedded record and fields. */
void func_01F05FEC(u8 *p)
{
    func_0011A518(p + 0xc0, 0, 0x190);
    *(s32 *)(p+0x250)=0;
    *(s32 *)(p+0x254)=0;
    *(s32 *)(p+0x258)=0;
    *(s32 *)(p+0x25c)=0;
    *(s32 *)(p+0x260)=0;
    *(s32 *)(p+0x264)=0;
}

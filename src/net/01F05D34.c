/* cflags: @ee296 -Os -G0 -fno-schedule-insns */
#include "common.h"

extern u32 D_0016E3A8[];
u32 func_01F05D34(void *unused, u32 *p)
{
    u32 next = D_0016E3A8[0], old;
    p[0]=0;
    old = next++;
    p[1]=0; p[2]=0; p[3]=0; p[4]=0; p[5]=0;
    D_0016E3A8[0] = next;
    p[6] = old;
    return next;
}

/* Reference: OpenRAC/rac3-decomp@cd0e7c20fd8a93116566ba2e024fa2f3536bd30c
 * src/levels/shared/L01_0047DBB0.c func_L01_0047DE68.
 * Independently reconstructed from RAC4 PAL retail. */
#include "common.h"

typedef struct {
    s32 prefix[3];
    void *buffers[4];
} BufferGroup;
extern BufferGroup D_003D9C48;
extern void func_00453E20(void *, s32, s32);
void func_004D4058(void)
{
    s32 i;
    for (i = 0; i < 4; i++)
        func_00453E20(D_003D9C48.buffers[i], 0, 2048);
}

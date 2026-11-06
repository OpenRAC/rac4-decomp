#include "common.h"
extern u32 *D_00221E20;
extern void *D_0021DA7C;
extern s32 func_00138C88(const void *packet);
void func_00459430(void)
{
    if (D_00221E20 != NULL) {
        D_00221E20[0] = 0x30000009;
        D_00221E20[1] = ((u32)D_0021DA7C + 0x30) & 0x0FFFFFFF;
        D_00221E20[2] = 0;
        D_00221E20[3] = 0x50000009;
        D_00221E20 += 4;
    } else {
        func_00138C88((void *)((u32)D_0021DA7C + 0x30));
    }
}

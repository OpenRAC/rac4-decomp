#include "common.h"
extern u32 *D_00221F20;
extern void *D_0021DAFC;
extern s32 func_00138C88(const void *packet);
void func_00459C48(void)
{
    if (D_00221F20 != NULL) {
        D_00221F20[0] = 0x30000009;
        D_00221F20[1] = ((u32)D_0021DAFC + 0x30) & 0x0FFFFFFF;
        D_00221F20[2] = 0;
        D_00221F20[3] = 0x50000009;
        D_00221F20 += 4;
    } else {
        func_00138C88((void *)((u32)D_0021DAFC + 0x30));
    }
}

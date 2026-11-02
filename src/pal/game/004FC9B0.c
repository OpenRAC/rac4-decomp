#include "common.h"
extern s32 *D_00221F20;
/* Writes the command fields and advances the buffer by four words. */
void func_004FC9B0(void)
{
    D_00221F20[0] = 0x10000000;
    D_00221F20[2] = 0x20000000;
    D_00221F20[3] = 0;
    D_00221F20 += 4;
}

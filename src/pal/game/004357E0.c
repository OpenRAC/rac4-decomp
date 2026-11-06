#include "common.h"
extern u32 *D_00221374;

void func_004357E0(void *unused, u32 color)
{
    s32 i, j;
    u32 middle = color & 0xFFFFFF;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 2; j++) {
            D_00221374[i * 2 + j] = (i == 0 || i == 6) ? middle : color;
        }
    }
}

#include "common.h"
/* Update the two adjacent byte fields. */
void func_L00_00713288(s8 *p, s32 value)
{
    p[0x531] = value;
    if (value == 1)
        p[0x530] = value;
}

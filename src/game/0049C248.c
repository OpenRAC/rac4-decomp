#include "common.h"

extern char D_00306F2C[];
extern char D_003070D8[];

/* Clears the indexed record byte in the selected table. */
void func_0049C248(s32 a, s32 b)
{
    char *p = a == 4 ? b * 52 + D_00306F2C
                     : (a << 9) + D_003070D8 + b * 52;
    p[0x24] = 0;
}

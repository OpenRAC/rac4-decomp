#include "common.h"

extern char D_0030702C[];
extern char D_003071D8[];

/* Clears the indexed record byte in the selected table. */
void func_0049CF80(s32 a, s32 b)
{
    char *p = a == 4 ? b * 52 + D_0030702C
                     : (a << 9) + D_003071D8 + b * 52;
    p[0x24] = 0;
}

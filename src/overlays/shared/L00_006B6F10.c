#include "common.h"

/* from rac3-decomp's func_L39_006319D8 */
s32 func_L00_006B6F10(char *a0, s32 a1) {
    char *p = a0 + a1 * 80;
    s32 x = (*(s32 *)(p + 8980) == 2) ? *(s32 *)(p + 8984) : -1;
    return x == 17 || x == 18;
}

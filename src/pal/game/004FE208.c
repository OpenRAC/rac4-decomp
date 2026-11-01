#include "common.h"

extern s32 func_004FDEE8(s32, s32, s32 *);
/* Count the enabled resource flags. */
int func_004FE208(void)
{
    int n = 0;
    if (func_004FDEE8(0x26FA, 0, 0))
        n++;
    if (func_004FDEE8(0x26FB, 0, 0))
        n++;
    if (func_004FDEE8(0x26FC, 0, 0))
        n++;
    if (func_004FDEE8(0x26FD, 0, 0))
        n++;
    if (func_004FDEE8(0x26FE, 0, 0))
        n++;
    if (func_004FDEE8(0x2716, 0, 0))
        n++;
    return n;
}

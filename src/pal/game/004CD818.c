#include "common.h"

extern int func_00506BB8(void);
extern char *func_00511CC0(int);
extern s32 func_005492C0(void *, s32);
/* Choose the resource identifier from the current slot mode. */
int func_004CD818(void)
{
    int r = 0x75A9;
    int s = func_005492C0(*(void **)(func_00511CC0(func_00506BB8()) + 0x26E4), 1);
    switch (s) {
    case 0:
        break;
    case 1:
        r = 0x75AA;
        break;
    case 2:
        r = 0x75AB;
        break;
    case 3:
        r = 0x75AD;
        break;
    }
    return r;
}

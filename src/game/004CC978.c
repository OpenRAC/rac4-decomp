#include "common.h"

extern int func_00505B20(void);
extern char *func_00510BE8(int);
extern s32 func_00547D58(void *, s32);
/* Choose the resource identifier from the current slot mode. */
int func_004CC978(void)
{
    int r = 0x75A9;
    int s = func_00547D58(*(void **)(func_00510BE8(func_00505B20()) + 0x26E4), 1);
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

#include "common.h"
extern s32 func_00505B20(void);
extern char *func_00510BE8(s32);
extern const char *func_0045E038(s32);
extern s32 func_00547D58(void *, s32);
const char *func_004CCCD0(void)
{
    char *p = func_00510BE8(func_00505B20());
    const char *result = func_0045E038(-1);
    switch (func_00547D58(*(void **)(p + 0x26E4), 1)) {
    case 0:
        result = func_0045E038(0x33A9);
        break;
    case 1:
        result = func_0045E038(0x33AA);
        break;
    case 2:
        result = func_0045E038(0x33AB);
        break;
    case 3:
        result = func_0045E038(0x33AC);
        break;
    default:
        result = func_0045E038(0x33AD);
        break;
    }
    return result;
}

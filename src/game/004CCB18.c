#include "common.h"

extern s32 func_00505B20(void);
extern char *func_00510BE8(s32);
extern const char *func_0045E038(s32);
extern s32 func_00547D58(void *, s32);

/* Select the label associated with the current inventory state. */
const char *func_004CCB18(void)
{
    char *p = func_00510BE8(func_00505B20());
    const char *result = func_0045E038(-1);
    switch (func_00547D58(*(void **)(p + 0x26E4), 1)) {
    case 0:
        result = func_0045E038(0x33B1);
        break;
    case 1:
        result = func_0045E038(0x33B2);
        break;
    case 2:
        result = func_0045E038(0x33B3);
        break;
    case 3:
        result = func_0045E038(0x33B4);
        break;
    default:
        result = func_0045E038(0x33B5);
        break;
    }
    return result;
}

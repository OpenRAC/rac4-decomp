#include "common.h"

extern const char *func_0045E850(s32);

/* Select the localized string for the requested category. */
const char *func_004D90F0(s32 category)
{
    const char *result = func_0045E850(0x31DF);
    switch (category) {
    case 0:
        result = func_0045E850(0x31E0);
        break;
    case 1:
        result = func_0045E850(0x31E1);
        break;
    case 2:
        result = func_0045E850(0x31DF);
        break;
    }
    return result;
}

#include "common.h"
extern s32 func_00506BB8(void);
extern char *func_00511CC0(s32);
extern const char *func_0045E850(s32);
extern s32 func_005492C0(void *, s32);
const char *func_004CDB70(void)
{
    char *p = func_00511CC0(func_00506BB8());
    const char *result = func_0045E850(-1);
    switch (func_005492C0(*(void **)(p + 0x26E4), 1)) {
    case 0:
        result = func_0045E850(0x33A9);
        break;
    case 1:
        result = func_0045E850(0x33AA);
        break;
    case 2:
        result = func_0045E850(0x33AB);
        break;
    case 3:
        result = func_0045E850(0x33AC);
        break;
    default:
        result = func_0045E850(0x33AD);
        break;
    }
    return result;
}

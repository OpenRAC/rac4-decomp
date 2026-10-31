#include "common.h"

extern void *func_0054A980(s32 arg0);
extern void *func_0054A998(s32 arg0);

/* Looks up a record through two helpers, stores its first word through arg1 when non-null, and returns arg0 minus its word at +0x10. */
s32 func_0054AB98(s32 arg0, s32 *arg1) {
    u8 *temp;

    temp = func_0054A980(*(s32 *)func_0054A998(arg0));
    if (arg1 != 0) {
        *arg1 = *(s32 *)temp;
    }
    return arg0 - *(s32 *)(temp + 0x10);
}

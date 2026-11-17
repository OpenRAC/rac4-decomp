#include "common.h"

extern void *func_L00_005EAB50(void);
extern u8 func_L01_004E4358(void *arg0);

/* Returns whether the value at 0x75 of the linked object is zero, or the 004E4358 result when the flag at 0x10 is set */
s32 func_L01_004E4500(u8 *arg0) {
    u8 value;

    if (((u8 *)func_L00_005EAB50())[0x10] != 0) {
        return func_L01_004E4358(arg0) == 0;
    }
    value = (*(u8 **)(arg0 + 0xAC))[0x75];
    return value == 0;
}

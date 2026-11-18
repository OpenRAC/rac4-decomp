/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_003FE928(s32, s32 *, s32, s32);
extern s32 func_00408528(s32, s32, s32);
extern void func_003FE6F0(s32, const char *, s32);
extern char D_004A2FB0[];

/* Checks and stores a 0x18-byte record. */
void func_L00_00533368(s32 arg0, s32 arg1) {
    s32 slot;
    if (func_003FE928(arg0, &slot, arg1, 0x18) == 0 &&
        func_00408528(arg0, slot, 0x18) == 0) {
        func_003FE6F0(arg0, D_004A2FB0, slot);
    }
}

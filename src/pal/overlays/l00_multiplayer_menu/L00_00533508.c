/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_003FE928(s32, s32 *, s32, s32);
extern void func_00408598(s32);
extern s32 func_00408528(s32, s32, s32);
extern void func_003FE6F0(s32, const char *, s32);
extern char D_004A2FC0[];

/* Checks and stores an 8-byte record after preparing its slot. */
void func_L00_00533508(s32 arg0, s32 arg1) {
    s32 slot;
    if (func_003FE928(arg0, &slot, arg1, 8) == 0) {
        func_00408598(slot);
        if (func_00408528(arg0, slot, 8) == 0) {
            func_003FE6F0(arg0, D_004A2FC0, slot);
        }
    }
}

/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern int func_L00_00537888(void *r, void *a, void *b);
extern int func_L00_005379F8(void *r, void *a, void *b);
extern s32 func_L00_00538770();

// Signed add: same +0xC flags add the magnitudes, different flags subtract the smaller from the larger.
s32 func_L00_005377B0(u8 *arg0, u8 *arg1, u8 *arg2) {
    u8 *t;

    if (*(s32 *)(arg1 + 0xC) ^ *(s32 *)(arg2 + 0xC)) {
        if (*(s32 *)(arg1 + 0xC)) {
            t = arg1;
            arg1 = arg2;
            arg2 = t;
        }
        if (func_L00_00538770(arg1, arg2) < 0) {
            if (!func_L00_005379F8(arg0, arg2, arg1)) {
                return 0;
            }
            *(s32 *)(arg0 + 0xC) = 1;
        } else {
            if (!func_L00_005379F8(arg0, arg1, arg2)) {
                return 0;
            }
            *(s32 *)(arg0 + 0xC) = 0;
        }
        return 1;
    }
    if (*(s32 *)(arg1 + 0xC)) {
        *(s32 *)(arg0 + 0xC) = 1;
    } else {
        *(s32 *)(arg0 + 0xC) = 0;
    }
    if (!func_L00_00537888(arg0, arg1, arg2)) {
        return 0;
    }
    return 1;
}

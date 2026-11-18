#include "common.h"

extern s32 func_00453CE8(void *p);
extern void func_005179B0(void *);
extern s32 func_L00_006F0BE0(void *);
extern s32 func_L00_006F0CA8(u8 *arg0);
s32 D_00220764 = 0;

// Reset the counter to 12 unless all three object checks pass.
void func_L00_006F0D30(u8 *arg0) {
    if (func_L00_006F0CA8(arg0) != 0 && func_L00_006F0BE0(arg0) != 0 && (*(s32 *)(*(u8 **)(arg0 + 0x2F00) + 0x1A0) & 0x10) != 0) {
        func_00453CE8(&D_00220764);
        if (D_00220764 <= 0) {
            *(s16 *)(arg0 + 0x3BA) = 3;
            func_005179B0(arg0);
        }
    } else {
        D_00220764 = 12;
    }
}

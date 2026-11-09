/* cflags: @ee29 */
#include "common.h"

extern s32 func_L00_004F80B8(s32, void *, s32, s32, s32);
extern s32 D_004A1A2C[];
extern u8 D_004AE7C8[];

void func_L00_00528568(void) {
    if (D_004A1A2C[0] < 0) {
        D_004A1A2C[0] = func_L00_004F80B8(0, D_004AE7C8, 0, 0, 0);
    }
}

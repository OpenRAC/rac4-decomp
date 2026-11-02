/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 D_0021E5F0;
extern s32 D_0021E5F4;
extern s32 D_0021E5F8;
extern s8 D_0021E5FC;
/* Store four arguments into four adjacent globals, final field a byte. */

void func_L00_005C5550(s32 arg0, s32 arg1, s32 arg2, s8 arg3) {
    D_0021E5F0 = arg0;
    D_0021E5F4 = arg1;
    D_0021E5F8 = arg2;
    D_0021E5FC = arg3;
}

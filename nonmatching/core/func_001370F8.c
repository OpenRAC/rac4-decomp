/* Not matching yet: BYTES 17/128 (tools/try_func.py func_001370F8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern s32 func_0012D420();
extern s32 func_0012D470();
extern s32 func_001371D0(void);
extern s32 D_00166008[];
extern s32 D_1AD5C8[];
extern s32 D_1AD5CC[];
extern s32 D_1AD5D0[];

s32 D_1AD5B0 = 0;

s32 func_001370F8(s32 arg0, s32 arg1) {
    s32 old;
    s32 r;
    if (D_00166008[0] < 0) {
        func_001371D0();
    }
    r = func_0012D420();
    old = D_1AD5C8[0];
    D_1AD5D0[0] = arg1;
    D_1AD5C8[0] = arg0;
    D_1AD5CC[0] = (s32)&D_1AD5B0;
    if (r != 0) {
        func_0012D470();
    }
    return old;
}

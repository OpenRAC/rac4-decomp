/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F0420();
extern s32 func_L00_004F0500();
extern s32 func_L00_00509A00();
extern s32 D_00498C68[];

// Measures a string's encoded length via two helpers and checks it against arg1.
s32 func_L00_00514DD0(s32 arg0, s32 arg1) {
    s32 n = func_L00_00509A00();
    s32 p = arg0;
    s32 ret;
    if (n < 0) {
        return n;
    }
    if (n != 0 && (D_00498C68[0] & 1) == 0) {
        p = arg0 + func_L00_004F0420(arg0);
    }
    p += func_L00_004F0500(p);
    ret = p - arg0;
    ret = (arg1 ^ ret) ? -0x6A : ret;
    return ret;
}

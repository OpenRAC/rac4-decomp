/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011AB04(s32);
extern s32 func_L00_004F7448(s32, s32, s32);

s32 func_L00_004F7638(s32 arg0, s32 arg1) {
    return func_L00_004F7448(arg0, arg1, func_0011AB04(arg1));
}

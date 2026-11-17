/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_0011AB04(u8 *);
extern s32 func_L00_0053BFA8(void *arg0, s32 arg1, s32 arg2);

s32 func_L00_0053C2C0(void *arg0, s8 *arg1) {
    return func_L00_0053BFA8(arg0, (s32)arg1, func_0011AB04(arg1));
}

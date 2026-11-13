/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_0011AE00(void *, void *, s32);
extern void func_0011D878(s32, s32, s32, u8 *);
extern char D_001946A8[];
void func_01E9ACF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 *arg4) {
    u8 *s = arg4 + 0x10C;
    func_0011D878(arg0, arg1, arg2, func_0011AE00(s, D_001946A8, 5) == 0 ? arg4 + 0x112 : s);
}

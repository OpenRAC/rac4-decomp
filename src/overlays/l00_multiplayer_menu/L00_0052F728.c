/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_00534888(s32, void *);
extern void func_L00_00535E08(void *, s32, s32, s32, s32);
extern s32 func_L00_00535FB0(s32, s32, s32);
extern s32 func_L00_00542110(s32, void *);
s32 func_L00_0052F728(s32 *object, s32 *arg1) {
    s32 sp0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 result;
    if (object == 0) return 0;
    temp_s0 = func_L00_00542110(object[0], 0);
    temp_s0_2 = temp_s0 + func_L00_00534888(object[1], 0);
    result = func_L00_00535FB0(1, temp_s0_2, 0x10);
    if (arg1 == 0) return result;
    sp0 = *arg1;
    func_L00_00535E08(&sp0, 1, temp_s0_2, 0x10, 0);
    func_L00_00542110(object[0], &sp0);
    func_L00_00534888(object[1], &sp0);
    *arg1 = sp0;
    return result;
}

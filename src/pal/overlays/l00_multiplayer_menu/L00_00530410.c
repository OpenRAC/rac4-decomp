/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_00535E48(s32, void *);
extern void func_L00_00536308(void *, s32, s32, s32, s32);
extern s32 func_L00_005364B0(s32, s32, s32);
extern s32 func_L00_00535E48(s32, void *);
s32 func_L00_00530410(s32 *object, s32 *arg1) {
    s32 sp0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 result;
    if (object == 0) return 0;
    temp_s0 = func_L00_00535E48(object[0], 0);
    temp_s0_2 = temp_s0 + func_L00_00535E48(object[1], 0);
    result = func_L00_005364B0(1, temp_s0_2, 0x10);
    if (arg1 == 0) return result;
    sp0 = *arg1;
    func_L00_00536308(&sp0, 1, temp_s0_2, 0x10, 0);
    func_L00_00535E48(object[0], &sp0);
    func_L00_00535E48(object[1], &sp0);
    *arg1 = sp0;
    return result;
}

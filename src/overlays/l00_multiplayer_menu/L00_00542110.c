/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_005355D0(s32, void *);
extern void func_L00_00535E08(void *, s32, s32, s32, s32);
extern s32 func_L00_00535FB0(s32, s32, s32);
extern s32 func_L00_00536E60(s32, void *);
s32 func_L00_00542110(s32 *object, s32 *arg1) {
    s32 sp0;
    s32 value;
    s32 result;
    if (object == 0) return 0;
    value = func_L00_005355D0(object[0], 0);
    if (object[1] != 0) value += func_L00_00536E60(object[1], 0);
    result = func_L00_00535FB0(1, value, 0x10);
    if (arg1 == 0) return result;
    sp0 = *arg1;
    func_L00_00535E08(&sp0, 1, value, 0x10, 0);
    func_L00_005355D0(object[0], &sp0);
    if (object[1] != 0) func_L00_00536E60(object[1], &sp0);
    *arg1 = sp0;
    return result;
}

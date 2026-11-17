/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern void func_L00_0051A4D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

/* Copies data into the buffer at +0x4C, flushing through the handler when it wraps. */
void func_L00_005409A0(s32 *arg0, s32 arg1, s32 *arg2, u8 *arg3, s32 arg4) {
    s32 var_s5 = 0;
    s32 temp_s0;

    *arg2 = 0;
    if (arg4 != 0) {
        temp_s0 = ((s32 *)arg0[0])[1];
        if (temp_s0 >= 2 && (arg4 + arg0[2]) % temp_s0 == 0) {
            if (arg4 < temp_s0) {
                func_0011A370((u8 *)(arg0[2] + (s32)arg0 + 0x4C), arg3, arg4);
                arg0[2] = temp_s0;
                *arg2 = 0;
                return;
            }
            var_s5 = 1;
            arg4 -= temp_s0;
        }
        func_L00_0051A4D0((s32)arg0, arg1, (s32)arg2, (s32)arg3, arg4);
        if (var_s5 != 0) {
            func_0011A370((u8 *)arg0 + 0x4C, arg3 + arg4, temp_s0);
            arg0[2] = temp_s0;
        }
    }
}

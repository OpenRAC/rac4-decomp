/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_0011A518(void *, s32, s32);

// Compares the three-word keys at +8 of arg0 and arg1 (zero key for null) and stores -1, 0 or 1 to arg2.
s32 func_L00_0052BFD8(u8 *arg0, u8 *arg1, s32 *arg2) {
    s32 zero[3];
    s32 *a;
    s32 *b;
    s32 result;

    func_0011A518(zero, 0, 0xC);
    a = arg0 ? (s32 *)(arg0 + 8) : zero;
    b = arg1 ? (s32 *)(arg1 + 8) : zero;
    if (a[0] > b[0]) {
        result = 1;
    } else if (a[0] < b[0]) {
        result = -1;
    } else if ((u32)a[1] > (u32)b[1]) {
        result = 1;
    } else if ((u32)a[1] < (u32)b[1]) {
        result = -1;
    } else if ((u32)a[2] > (u32)b[2]) {
        result = 1;
    } else {
        result = (u32)a[2] < (u32)b[2] ? -1 : 0;
    }
    *arg2 = result;
    return 0;
}

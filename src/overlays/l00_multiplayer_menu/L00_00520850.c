/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00520548(u8 *arg0);
extern s32 func_L00_005208E8(s32, s32, s32, s32, void *, s32);

/* Asks func_L00_005208E8 for an index and removes that entry from the array at arg0, shrinking its count. */
s32 func_L00_00520850(s32 *arg0, s32 arg1, s32 arg2) {
    s32 sp0;
    s32 sp4;
    s32 i;
    s32 n;

    sp0 = 0;
    i = func_L00_005208E8((s32)arg0, arg1, arg2, (s32)&sp0, &sp4, 0);
    if (i != 0) {
        return i;
    }
    func_L00_00520548((u8 *)sp4);
    n = arg0[1] - 1;
    for (i = sp0 - 1; i < n; i++) {
        ((s32 *)arg0[3])[i] = ((s32 *)arg0[3])[i + 1];
    }
    arg0[1]--;
    return 0;
}

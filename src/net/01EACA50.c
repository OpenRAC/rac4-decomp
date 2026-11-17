/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_01EA9550(s32 *arg0, s64 arg1);
extern s32 func_01EA95C0(s32*);
extern s32 func_01EAC9A8(s32 arg0, s32 *arg1);

/* Copies a buffer through a scratch allocation, runs a callback on it, and copies it back. */
s32 func_01EACA50(s32 arg0, s32 *arg1) {
    s32 sp[1];
    s32 n;

    if (arg1 == 0) {
        return 0xDAC2;
    }
    if (func_01EA9550(sp, (u32)(arg1[1] * 4)) != 0) {
        return 0xDAC4;
    }
    n = arg1[1] * 4;
    func_0011A370((u8 *)sp[0], (u8 *)arg1[2], n);
    func_01EA95C0(arg1 + 2);
    if (func_01EAC9A8(arg0, arg1) != 0) {
        return 0xDAC4;
    }
    func_0011A370((u8 *)arg1[2], (u8 *)sp[0], n);
    func_01EA95C0(sp);
    return 0;
}

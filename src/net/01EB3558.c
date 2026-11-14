/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern void func_0011A370(u8 *, u8 *, s32);
extern s32 func_01EA90F0(s32);
extern s32 func_01EA94D0(s32 *out, s64 id);
extern void func_01EAE2C0(s32, s32);
extern s32 func_01EB2EE0(s32 arg0);

/* Fills the connection's buffers for a send, then sends the data. */
s32 func_01EB3558(s32 arg0, s32 arg1, s32 arg2) {
    u8 *ctx;

    ctx = (u8 *)func_01EA90F0(arg0);
    if (ctx == NULL) {
        return -1;
    }
    if (func_01EB2EE0(arg2) != 0) {
        return -1;
    }
    if (*(s32 *)(ctx + 0x2C) == 0) {
        func_01EA94D0((s32 *)(ctx + 0x2C), 0x40);
    }
    if (*(s32 *)(ctx + 0x24) == 0) {
        func_01EA94D0((s32 *)(ctx + 0x24), 0x10C);
    }
    if (*(s32 *)(ctx + 0x28) == 0) {
        func_01EA94D0((s32 *)(ctx + 0x28), 0x10C);
    }
    *(s32 *)(ctx + 0x18) = arg1;
    func_0011A370((u8 *)*(s32 *)(ctx + 0x2C), (u8 *)arg2, 0x40);
    func_01EAE2C0(*(s32 *)(ctx + 0x24), arg2);
    func_01EAE2C0(*(s32 *)(ctx + 0x28), arg2);
    return 0;
}

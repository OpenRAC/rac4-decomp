/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_01EAA130(s32, s32, void *, s32);
extern s32 func_01EAA218(s32, s32, void *);
s32 func_01EDB478(s32 arg0, u8 *arg1, u8 *arg2);
s32 func_01EDB5C0(s32 ctx, u8 *buf, u8 *o) {
    if (buf == 0) {
        return -0x15;
    }
    if (o == 0) {
        return -0x15;
    }
    if (func_01EAA130(ctx, (s32)buf, o + 0x2C, 4) == 0) {
        return -0xA;
    }
    if (func_01EAA218(ctx, (s32)buf, o + 0x28) == 0) {
        return -0xA;
    }
    return func_01EDB478(ctx, buf, o);
}

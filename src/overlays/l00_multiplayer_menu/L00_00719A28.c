#include "common.h"

extern void func_0072A128(void *);
extern void func_0072A150(void *, s32);
extern s32 func_0072A928(void *);
extern void func_L00_00719880(void *arg0, s32 arg1, s32 arg2);
extern void func_L00_0072A178(void *, s32, s32, f32);

/* Configures the 0x90 object, sets its byte at 0x269, sends event 0xB and starts it. */
s32 func_L00_00719A28(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7) {
    u8 *o = *(u8 **)((u8 *)arg0 + 0x90);

    if (o != 0) {
        func_0072A128(o);
        func_0072A150(o, arg2);
        func_L00_0072A178(o, arg3, arg6, arg7);
        *(s8 *)(o + 0x269) = arg5;
        func_L00_00719880(arg0, 0xB, arg4);
        return func_0072A928(o);
    }
    return 0;
}

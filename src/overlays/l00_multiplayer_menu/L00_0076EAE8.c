#include "common.h"

extern void func_0011A9EC(void *, void *);
extern s32 func_0015A170(void *);
extern s32 func_0015AA58(void);
extern void func_00161118(s32 val);
extern u8 func_00161320(void);
extern void func_00161A98(s32 arg0);
extern void func_00162760(s32);
extern s32 func_L00_0076E678(void *, s32, s32, s32);
extern s32 func_L00_0076E838(void *, s32, s32);
extern s32 func_L00_0076EA40(void *);
extern void func_L00_0076F280(void *);
extern s32 func_L00_0076F770(void *);
extern s32 func_L00_0076FF18(void *);
extern void func_L00_0077CC50(s32);
extern void *D_002233A4;
extern u8 D_172160[];
extern u8 D_17233C[];

// Set up the object in arg0, run the transfer steps, and return the status.
s32 func_L00_0076EAE8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 var_s0;
    u8 *s4p;

    if (func_L00_0076FF18(arg0) == 0) {
        return 0;
    }
    s4p = D_172160;
    func_L00_0077CC50(*(s32 *)((u8 *)D_002233A4 + 0x68));
    arg0[3] = 0;
    arg0[0x11] = 0;
    *(s32 *)(s4p + 0x124) = arg1;
    var_s0 = func_L00_0076E678(arg0, arg1, arg2, arg4);
    if (var_s0 != 0) {
        var_s0 = (func_0015A170(arg0 + 0x48) != 0) ? 0 : var_s0;
        if (var_s0 != 0) {
            *(s32 *)(s4p + 0x2C) = arg3;
            var_s0 = (func_0015AA58() != 0) ? 0 : var_s0;
        }
    }
    if (func_00161320() != 0) {
        if (var_s0 == 0) {
            func_L00_0076F280(arg0);
        }
        return var_s0;
    }
    if (var_s0 != 0) {
        func_00161118(arg1);
        var_s0 = func_L00_0076E838(arg0, arg5, arg6);
        if (var_s0 != 0) {
            var_s0 = func_L00_0076EA40(arg0);
            if (var_s0 != 0 && arg0[0x12] == 0) {
                var_s0 = func_L00_0076F770(arg0);
            }
        }
    }
    if (arg2 != 0) {
        func_0011A9EC(D_17233C, (void *)arg2);
    } else {
        D_172160[0x1DC] = 0;
    }
    if (var_s0 == 0) {
        func_L00_0076F280(arg0);
    } else {
        func_00161A98(6);
        func_00162760(1);
    }
    return var_s0;
}

#include "common.h"

extern void func_0015E718();
extern s32 func_L00_0071B550();
extern s32 func_L00_007647B0(s32 identifier);
extern void func_L00_0076F280(void *);
extern s32 D_002233A4;
extern s32 *D_00220D14;

// Menu state step: sets state 0x17 or 0x18 and forwards to func_L00_0071B550 when nothing changed.
s32 func_L00_007457F0(s32 arg0, s32 arg1) {
    s32 temp_s1;
    s32 var_s0;
    s32 var_v1;
    s32 *temp_s3;

    temp_s3 = D_00220D14;
    var_v1 = 0;
    var_s0 = 0x18;
    temp_s1 = ((s32 *)D_002233A4)[18];
    if (arg1 == 5) {
        var_s0 = 0x17;
        var_v1 = 1;
    }
    if (var_s0 != 0x18) {
        func_0015E718();
        func_L00_0076F280((void *)temp_s1);
        func_L00_007647B0(0x13);
        temp_s3[70] = var_s0;
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        var_v1 = func_L00_0071B550(arg0, arg1);
    }
    return var_v1;
}

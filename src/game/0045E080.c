#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_0045E360();
extern void *D_0021DDCC;
extern s32 D_221384;

/* Passes arg0 on, or the table entry's value when it is positive and a flag is set. */
void func_0045E080(s32 arg0) {
    s16 temp_a0;
    s32 var_s0;

    var_s0 = arg0;
    temp_a0 = *(s16 *)((func_0045E360() << 4) + D_221384 + 6);
    if (temp_a0 > 0) {
        var_s0 = (((u8 *)D_0021DDCC)[0x550] != 0) ? temp_a0 : var_s0;
    }
    func_0045E038(var_s0);
}

#include "common.h"

extern void *func_00698D80();
extern void func_L00_00697808(s32, s32);
extern s32 D_00223148[];

/* Calls func_L00_00697808 with arg0 and the word at the selected element of the object at +4 of D_222038 (or of func_00698D80's result), returning 1 if it was called. */
s32 func_L00_0069DCD8(s32 arg0) {
    void *var_v0;
    void *temp_v1;
    s32 var_a0;
    s32 var_s1;

    var_s1 = 0;
    temp_v1 = D_00223148;
    if (*(void **)((u8 *)temp_v1 + 4) != NULL) {
        var_v0 = temp_v1;
    } else {
        var_v0 = func_00698D80();
    }
    temp_v1 = *(void **)((u8 *)var_v0 + 4);
    var_a0 = 0;
    if (temp_v1 != NULL) {
        var_a0 = *(s32 *)((u8 *)temp_v1 + (*(s32 *)((u8 *)temp_v1 + 0x14) << 2));
    }
    if (var_a0 != 0) {
        var_s1 = 1;
        func_L00_00697808(var_a0, arg0);
    }
    return var_s1;
}

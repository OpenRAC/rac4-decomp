/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004F3ED8(void);
extern void func_L00_004F3F50(void);
extern s32 func_L00_004F4F60(s32, s32, s32);
extern s32 func_L00_004F5018(s32, s32, s32);

extern s32 D_00498D74[];
extern s32 D_00498D88[];
extern s32 D_00498D90[];

s32 func_L00_004F50B8(s32 arg0, s32 arg1) {
    s32 temp_s2;
    s32 var_v0;

    temp_s2 = func_L00_004F3ED8();
    if (D_00498D88[0] != 0) {
        var_v0 = func_L00_004F4F60(D_00498D90[0], arg0, arg1);
    } else {
        var_v0 = func_L00_004F5018(D_00498D74[0], arg0, arg1);
    }
    if (temp_s2 >= 0) {
        func_L00_004F3F50();
    }
    return var_v0;
}

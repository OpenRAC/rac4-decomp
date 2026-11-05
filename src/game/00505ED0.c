#include "common.h"
extern void *func_005005E8(s32, s32);
extern void *func_005010E0();
extern s32 func_0050CAC0(void *, s32, s32);
extern s32 D_00220B54;
extern s32 D_222038_[];
s32 func_00505ED0(s32 arg0, s32 arg1, s32 arg2) {
    void *var_v0;
    void *temp_v1;
    s32 var_a0;
    s32 var_s3;
    u8 *handle;
    u8 *obj;

    var_s3 = 0;
    temp_v1 = D_222038_;
    if (*(void **)((u8 *)temp_v1 + 4) != NULL) {
        var_v0 = temp_v1;
    } else {
        var_v0 = func_005010E0();
    }
    temp_v1 = *(void **)((u8 *)var_v0 + 4);
    var_a0 = 0;
    if (temp_v1 != NULL) {
        var_a0 = *(s32 *)((u8 *)temp_v1 + (*(s32 *)((u8 *)temp_v1 + 0x14) << 2));
    }
    handle = func_005005E8(var_a0, arg0);
    obj = (handle != 0 && (*(s32 (**)(void *, s32))(*(u8 **)(handle + 8) + 0x14))(handle, D_00220B54) != 0) ? handle : 0;
    if (obj != 0) var_s3 = func_0050CAC0(obj, arg1, arg2);
    return var_s3;
}

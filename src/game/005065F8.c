#include "common.h"

extern void *func_005005E8(s32 arg0, s32 arg1);
extern void *func_005010E0();
extern void func_0050EF88(void *arg0, s32 arg1, s32 arg2);
extern s32 D_222038_[];
extern s32 D_00220B68;

static inline u8 *func_005065F8_cast(u8 *obj) {
    if (obj != NULL && (*(s32 (**)(void *, s32))(*(u8 **)(obj + 8) + 0x14))(obj, D_00220B68) != 0) {
        return obj;
    }
    return NULL;
}

/* Looks up an object by arg0 in the current table entry; if it supports D_00220B68, runs func_0050EF88 on it with arg1/arg2 and returns 1. */
s32 func_005065F8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *var_v0;
    u8 *temp_v1;
    s32 var_a0;
    s32 var_s3;
    u8 *obj;
    u8 *hit;

    var_s3 = 0;
    if (D_222038_[1] != 0) {
        var_v0 = (u8 *)D_222038_;
    } else {
        var_v0 = func_005010E0();
    }
    temp_v1 = *(u8 **)(var_v0 + 4);
    var_a0 = 0;
    if (temp_v1 != NULL) {
        var_a0 = *(s32 *)(temp_v1 + (*(s32 *)(temp_v1 + 0x14) << 2));
    }
    obj = func_005005E8(var_a0, arg0);
    hit = func_005065F8_cast(obj);
    if (hit != NULL) {
        var_s3 = 1;
        func_0050EF88(hit, arg1, arg2);
    }
    return var_s3;
}

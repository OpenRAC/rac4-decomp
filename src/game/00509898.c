#include "common.h"

extern s32 D_00220B68;
extern void func_0050C058(void *arg0, s32 arg1, s32 arg2);

/* If the object supports D_00220B68, call func_0050C058 on it with arg1 and arg2 and return 1; otherwise return 0. */
s32 func_00509898(void *handle, s32 arg1, s32 arg2) {
    u8 *object = handle;
    u8 *table = *(u8 **)(object + 8);
    s32 (*method)(void *, s32) = *(s32 (**)(void *, s32))(table + 0x14);
    if (method(handle, D_00220B68) != 0) {
        func_0050C058(handle, arg1, arg2);
        return 1;
    }
    return 0;
}

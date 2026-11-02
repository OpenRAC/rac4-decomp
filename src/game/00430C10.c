#include "common.h"
typedef struct __attribute__((packed,aligned(4))) Type1 { u64 f0; s32 f8; } Type1;
extern s32 func_0053FBA8(s32, s32, s32 *, s32);
extern void func_0053CAA8(s32, void *, s32);
static inline void put(s32 handle, s32 v) { func_0053CAA8(handle, &v, 4); }
s32 func_00430C10(s32 arg0, Type1 *arg1, Type1 *arg2, s32 arg3, s32 arg4) {
    Type1 first;
    Type1 second;
    s32 handle;
    s32 result;
    first = *arg1;
    second = *arg2;
    handle = 0;
    result = func_0053FBA8(0x1AFC, 0x40, &handle, arg0);
    if (handle != 0) {
        func_0053CAA8(handle, &first, 12);
        func_0053CAA8(handle, &second, 12);
        put(handle, arg3);
        put(handle, arg4);
    }
    return result;
}

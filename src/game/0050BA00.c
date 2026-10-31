#include "common.h"

extern s32 D_00220B54;
void func_0050C768(void *object);

// If the object supports D_00220B54 (checked with the method at +0x14 of its +8 table), run func_0050C768 on it and return 1; otherwise return 0.
s32 func_0050BA00(void *handle) {
    if ((*(s32 (**)(void *, s32))(*(u8 **)((u8 *)handle + 8) + 0x14))(handle, D_00220B54) != 0) {
        func_0050C768(handle);
        return 1;
    }
    return 0;
}

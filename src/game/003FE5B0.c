#include "common.h"

s32 func_003FE588(void);

s32 func_003FE5B0(void *arg0) {
    s32 var_v0;

    var_v0 = func_003FE588();
    if (var_v0 != 0) {
        return var_v0;
    }
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x2C) & 1) ? 0 : 0x202;
    return var_v0;
}

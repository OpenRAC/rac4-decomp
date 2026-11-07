#include "common.h"

s32 func_L00_005468B0(void **arg0, s64 arg1) {
    void *temp_v1;

    if (arg1 <= 0) {
        return 1;
    }
    if (arg1 >= 2) {
        temp_v1 = *arg0;
        if (((*(u8 *)((s8 *)(temp_v1) + (0))) == 0) && ((*(u8 *)((s8 *)(temp_v1) + (1))) == 0)) {
            *arg0 = temp_v1 + 2;
            return 1;
        }
    }
    return 0;
}

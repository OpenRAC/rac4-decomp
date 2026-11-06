#include "common.h"
s32 func_L02_00616130(void *arg0) {
    void *temp_a0;

    if ((arg0 == NULL) || (temp_a0 = (*(void **)((u8 *)(arg0) + 0xAC)), (temp_a0 == NULL))) {
        return 0;
    }
    return (*(s32 *)((u8 *)(temp_a0) + 0xE0));
}

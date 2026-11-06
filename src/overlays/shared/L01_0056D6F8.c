#include "common.h"

s32 func_L01_0056D6F8(const u8 *list, const void *item, s32 *out_index)
{
    s32 i;
    s32 count;
    if (item == NULL) {
        return 0;
    }
    count = *(const s32 *)(list + 0x40);
    for (i = 0; i < count; i++) {
        if (*(const void *const *)((u32)list + (u32)i * 4u) == item) {
            if (out_index != NULL) {
                *out_index = i;
            }
            return 1;
        }
    }
    return 0;
}

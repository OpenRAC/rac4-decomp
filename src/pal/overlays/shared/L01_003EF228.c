#include "common.h"
s32 func_L01_0056E308(void *object);
s32 func_L01_00570060(void *extension, void *object);
f32 func_L01_003EF228(void *object)
{
    f32 result;
    s32 count;
    s32 total;
    void *extension;
    void *node;

    count = 0;
    extension = *(void **)((u8 *)object + 0xAC);
    node = *(void **)((u8 *)extension + 0x3F0);
    total = 0;
    if (node != NULL) {
        do {
            total = (s32)((u32)total + 2U);
            if (func_L01_0056E308(node) != 0) {
                count = (s32)((u32)count + 1U);
            }
            if (func_L01_00570060(extension, node) != 0) {
                count = (s32)((u32)count + 1U);
            }
            node = *(void **)((u8 *)node + 0x1AC);
        } while (node != NULL);
    }
    if (total != 0) {
        result = (f32)count / (f32)total;
    } else {
        result = 1.0f;
    }
    return result;
}

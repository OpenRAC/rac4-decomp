#include "common.h"

extern void *func_00510BE8(s32 arg0);

// Copies a 64-bit field of the sub-object at 0x2EF0 of the object returned by func_00510BE8(0) into arg0.
void func_00476C38(void *arg0) {
    void *temp_v0 = func_00510BE8(0);
    if (temp_v0 != 0) {
        s32 temp_v0_2 = *(s32 *)((u8 *)temp_v0 + 0x2EF0);
        if (temp_v0_2 != 0) {
            *(s64 *)((u8 *)arg0 + 0x38) = *(s64 *)((u8 *)temp_v0_2 + 0x38);
        }
    }
}

#include "common.h"

/* Changes the byte at offset 8 of the object from func_0048A970 from 3 to 4 when arg0 is neither 0 nor 0xFFFFFFFF. */
extern void *func_0048A970(u32 arg0);

void func_0048AF30(u32 arg0, s64 arg1) {
    u8 *temp_v0;

    temp_v0 = func_0048A970((s32) arg1);
    if (temp_v0 != NULL && arg0 != 0 && arg0 != 0xFFFFFFFF) {
        if (temp_v0[8] == 3) {
            temp_v0[8] = 4;
        }
    }
}

/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E5E0;
extern s32 D_00170A60[];

void **func_01F03530(void) {
    void **temp_v0;

    if (D_0016E5E0 == NULL) {
        temp_v0 = func_01EF3654(4);
        *temp_v0 = D_00170A60;
        D_0016E5E0 = temp_v0;
    }
    return D_0016E5E0;
}

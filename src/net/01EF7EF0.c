/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E58C;
extern s32 D_001703B0[];

void **func_01EF7EF0(void) {
    void **temp_v0;

    if (D_0016E58C == NULL) {
        temp_v0 = func_01EF3654(4);
        *temp_v0 = D_001703B0;
        D_0016E58C = temp_v0;
    }
    return D_0016E58C;
}

/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E66C;
extern s32 D_00171050[];

void **func_01F0BB78(void) {
    void **temp_v0;

    if (D_0016E66C == NULL) {
        temp_v0 = func_01EF3654(4);
        *temp_v0 = D_00171050;
        D_0016E66C = temp_v0;
    }
    return D_0016E66C;
}

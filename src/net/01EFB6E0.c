/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E5B0;
extern s32 D_00170580[];

void **func_01EFB6E0(void) {
    void **temp_v0;

    if (D_0016E5B0 == NULL) {
        temp_v0 = func_01EF3654(4);
        *temp_v0 = D_00170580;
        D_0016E5B0 = temp_v0;
    }
    return D_0016E5B0;
}

/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E590;
extern s32 D_001703E8[];

void **func_01EF8050(void) {
    void **temp_v0;

    if (D_0016E590 == NULL) {
        temp_v0 = func_01EF3654(4);
        *temp_v0 = D_001703E8;
        D_0016E590 = temp_v0;
    }
    return D_0016E590;
}

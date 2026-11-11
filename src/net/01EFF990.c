/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
#include "common.h"

void **func_01EF3654(s32);
extern void **D_0016E5CC;
extern s32 D_001708B0[];

void **func_01EFF990(void) {
    void **temp_v0;

    if (D_0016E5CC == NULL) {
        temp_v0 = func_01EF3654(8);
        *temp_v0 = D_001708B0;
        D_0016E5CC = temp_v0;
    }
    return D_0016E5CC;
}

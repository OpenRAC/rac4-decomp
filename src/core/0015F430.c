#include "common.h"

struct S00172160 {
    u8 pad[0x15AC];
    s32 arr[16];
};

extern struct S00172160 D_00172160;

s32 func_0015F430(s32 arg0) {
    s32 found = 0;
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_00172160.arr[i] == arg0) {
            found = 1;
            D_00172160.arr[i] = -1;
            break;
        }
    }
    return found;
}

/* cflags: -fno-opt-stack */
#include "common.h"

extern s32 *(*D_0016F740[])(s32, s32);

// Allocates a 0xC-byte record, stores arg0 in it and a second allocation's pointer in its third word, then returns it through arg1; returns 1 when the first allocation fails.
s32 func_0014A410(s32 arg0, void **arg1) {
    s32 *temp_v0;

    temp_v0 = D_0016F740[0](1, 0xC);
    if (temp_v0 != NULL) {
        *arg1 = temp_v0;
        temp_v0[0] = arg0;
        temp_v0[1] = 0;
        temp_v0[2] = (s32)D_0016F740[0](arg0, 4);
        return 0;
    }
    return 1;
}

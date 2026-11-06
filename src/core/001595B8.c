#include "common.h"

s32 func_00136DA8();
s32 D_0021DCB4 = 0;
s32 D_0021DCB8 = 0;

/* Returns the previous D_0021DCB8 and stores arg0 there when D_0021DCB4 is set; otherwise calls func_00136DA8. */
s32 func_001595B8(s32 arg0) {
    s32 temp_v0;

    if (D_0021DCB4 == 0) {
        return func_00136DA8();
    }
    temp_v0 = D_0021DCB8;
    D_0021DCB8 = arg0;
    return temp_v0;
}

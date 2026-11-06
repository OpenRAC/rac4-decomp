/* cflags: -Wuninitialized */
#include "common.h"

extern s64 func_L15_00503B60(void);
extern s64 func_L15_005037D8(void);
extern s32 D_0023C270[];

void func_L15_00502480(void)
{
    if (D_0023C270[0] != 1) {
        if (D_0023C270[0] == 2)
            func_L15_005037D8();
    } else {
        func_L15_00503B60();
    }
}

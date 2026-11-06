/* cflags: -Wuninitialized */
#include "common.h"

extern s64 func_L15_00501AF8(void);
extern s64 func_L15_00501770(void);
extern s32 D_0023C170[];

void func_L15_00500480(void)
{
    if (D_0023C170[0] != 1) {
        if (D_0023C170[0] == 2)
            func_L15_00501770();
    } else {
        func_L15_00501AF8();
    }
}

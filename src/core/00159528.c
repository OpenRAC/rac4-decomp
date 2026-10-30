#include "common.h"

/* Calls func_00158C60 with 0x37 when the flag at D_0021DCB4 is set, otherwise returns func_00138048's result. */
extern s32 func_00138048();
extern void func_00158C60(s32, s32, void *, s32, s32);
s32 D_0021DCB4 = 0;

s32 func_00159528(void) {
    if (D_0021DCB4 == 0) {
        return func_00138048();
    }
    func_00158C60(0x37, 0, 0, 0, 0);
    return 1;
}

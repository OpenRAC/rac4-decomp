#include "common.h"

/* Calls the object's method at 0x3C when arg2 is nonzero, else the one at 0x5C; does nothing when the object is null. */
extern s32 D_00167F40_[];

void func_01EA5688(s32 arg0, s32 arg1, s32 arg2) {
    u8 *obj = (u8 *)D_00167F40_[0];

    if (obj != NULL) {
        if (arg2 == 0) {
            (*(void (**)(void))(obj + 0x5C))();
        } else {
            (*(void (**)(void))(obj + 0x3C))();
        }
    }
}

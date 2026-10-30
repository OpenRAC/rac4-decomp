#include "common.h"

extern void func_00464AF8(int);
extern s32 D_00171950_[];
#define D_00171950 (D_00171950_[0])
extern s32 D_21DADC;

/* Calls func_00464AF8 with 4, or with 7 when the second global matches the first at 2. */
void func_00465980(void) {
    if (D_00171950 != 2) {
        func_00464AF8(4);
    } else if (D_21DADC == D_00171950) {
        func_00464AF8(7);
    }
}

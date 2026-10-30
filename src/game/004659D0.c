#include "common.h"

extern void func_00464AF8(int);
extern s32 D_00171950_[];
#define D_00171950 (D_00171950_[0])
extern s32 D_21DADC;

/* Calls func_00464AF8 with 4 when the first global is not 2, or with 0xE when the second is set. */
void func_004659D0(void) {
    if (D_00171950 != 2) {
        func_00464AF8(4);
    } else if (D_21DADC != 0) {
        func_00464AF8(0xE);
    }
}

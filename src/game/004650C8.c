#include "common.h"

/* Calls func_00464AF8 with 4 unless D_00171950 is 2, then with 0xC if D_21DAE4 has bits 0x806 set. */
extern void func_00464AF8(s32);
extern s32 D_00171950_[];
#define D_00171950 (D_00171950_[0])
extern s32 D_21DAE4;

void func_004650C8(void) {
    if (D_00171950 != 2) {
        func_00464AF8(4);
    } else if (D_21DAE4 & 0x806) {
        func_00464AF8(0xC);
    }
}

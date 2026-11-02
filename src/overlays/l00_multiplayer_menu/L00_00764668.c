#include "common.h"

void func_L00_00764530();
extern s32 D_004EE5E8[];
#define D_004EE5B8 (D_004EE5E8[0])

s32 *func_L00_00764668(void) {
    if (D_004EE5B8 == 0) {
        func_L00_00764530();
    }
    return &D_004EE5B8;
}

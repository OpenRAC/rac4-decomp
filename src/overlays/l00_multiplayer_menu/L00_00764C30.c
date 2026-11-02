#include "common.h"

s32 func_L00_00764B20();
extern s32 D_004EE640[];
#define D_004EE5B8 (D_004EE640[0])

s32 *func_L00_00764C30(void) {
    if (D_004EE5B8 == 0) {
        func_L00_00764B20();
    }
    return &D_004EE5B8;
}

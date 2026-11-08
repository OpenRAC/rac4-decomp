#include "common.h"

extern s32 D_0023AC90[];

/* PAL: from rac3-decomp's func_L39_0061C258 */
void func_L13_00500640(s32 a0) {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (D_0023AC90[i] == 0) {
            D_0023AC90[i] = a0;
            break;
        }
    }
}

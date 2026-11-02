#include "common.h"
extern unsigned int *D_00222EE0;
extern char D_0020BCB0[];

/* Writes four command words and advances the output pointer. */
void func_L00_005C50F8(void) {
    D_00222EE0[0] = 0x30000026;
    D_00222EE0[1] = (unsigned int)D_0020BCB0;
    D_00222EE0[2] = 0;
    D_00222EE0[3] = 0x50000026;
    D_00222EE0 += 4;
}

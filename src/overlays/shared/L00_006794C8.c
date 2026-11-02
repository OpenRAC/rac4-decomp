#include "common.h"
extern unsigned int *D_00222EE0;
extern unsigned char D_004CAF70[];

/* Append four words to the command stream. */
void func_L00_006794C8(void) {
    D_00222EE0[0] = 0x30000004;
    D_00222EE0[1] = (unsigned int)D_004CAF70;
    D_00222EE0[2] = 0;
    D_00222EE0[3] = 0x50000004;
    D_00222EE0 += 4;
}

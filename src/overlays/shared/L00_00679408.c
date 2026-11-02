#include "common.h"
extern unsigned int *D_00222EE0;
extern char D_004CB970[];

/* Append four words to the current command buffer. */
void func_L00_00679408(void) {
    D_00222EE0[0] = 0x30000003;
    D_00222EE0[1] = (unsigned int) D_004CB970;
    D_00222EE0[2] = 0;
    D_00222EE0[3] = 0x50000003;
    D_00222EE0 += 4;
}

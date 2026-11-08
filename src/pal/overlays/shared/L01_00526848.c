#include "common.h"

extern char * D_00222A90 ;
extern char *D_00222A90;
extern char *D_00222A90 ;

/* PAL: from rac3-decomp's func_L01_003EC9E0, constants adapted */
void func_L01_00526848(int i) {
    unsigned char *q;
    q = *(unsigned char **)(D_00222A90 + i * 0x20 + 0x1C);
    q[0xb3] = 1;
    q[0xb4] = 0;
}

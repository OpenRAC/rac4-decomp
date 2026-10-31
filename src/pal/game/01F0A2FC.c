#include "common.h"
extern u32 D_00170FD8;

void func_01F0A2FC(void *p) {
    u32 *q=(u32*)p;
    q[0]=(u32)&D_00170FD8;
    q[0x208/4]=0;
    q[0x20C/4]=0;
    q[0x210/4]=0;
}

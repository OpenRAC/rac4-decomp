#include "common.h"

/* If arg0 differs from the cached value at D_1DFC60+0x20, calls func_00461990 and func_00461CD8 with the cached fields. */
extern u8 D_1DFC60[];
extern void func_00461990(int arg0, int arg1);
extern void func_00461CD8(int arg0, int arg1);

void func_00461E48(int arg0) {
    u8 *p;

    p = D_1DFC60;
    if (arg0 != *(int *)(p + 0x20)) {
        func_00461990(arg0, 1);
        func_00461CD8(*(int *)(p + 0x24), *(int *)(p + 0x2C));
    }
}

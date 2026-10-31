#include "common.h"

extern void func_00461990(int arg0, int arg1);
extern void func_00461CD8(int arg0, int arg1);
extern char D_1DFC60[];

/* Conditionally calls func_00461990 and func_00461CD8 if arg0 differs from a cached value. */
void func_00461E08(int arg0) {
    if (arg0 != *(int *)D_1DFC60) {
        func_00461990(arg0, 0);
        func_00461CD8(*(int *)(D_1DFC60 + 4), *(int *)(D_1DFC60 + 12));
    }
}

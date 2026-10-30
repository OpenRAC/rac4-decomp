#include "common.h"

extern void *func_00448A20();

/* Loads two floats from the result of func_00448A20 and stores them in arg1 and arg2. */
void func_00448C10(void *arg0, float *arg1, float *arg2) {
    void *result;

    result = func_00448A20();
    *arg1 = *(float *)((char *)result + 0x10);
    *arg2 = *(float *)((char *)result + 0x14);
}

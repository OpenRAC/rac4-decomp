#include "common.h"

typedef int u128 __attribute__((mode(TI)));

u8 *D_00221580 = 0;

/* Store the 16-byte argument through the global pointer. */
void func_L00_00753158(u128 arg0) {
    *(u128 *)D_00221580 = arg0;
}

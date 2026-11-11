#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern u128 D_003B67C0[];

void func_L01_005487C0(u128 *arg0, u128 *arg1) {
    D_003B67C0[0] = *arg0;
    D_003B67C0[1] = *arg1;
}

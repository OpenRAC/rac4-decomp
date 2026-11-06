#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_L01_00479178(u8 *, u128, u128);

void func_L01_00479570(u8 *arg0, u8 *arg1) {
    func_L01_00479178(arg0, *(u128 *)(arg0 + 0xC0), *(u128 *)arg1);
}

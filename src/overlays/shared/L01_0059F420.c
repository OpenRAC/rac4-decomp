#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern void func_L00_005EFEE8(u128);

void func_L01_0059F420(u8 *arg0) {
    func_L00_005EFEE8(*(u128 *)(arg0 + 0x10));
}

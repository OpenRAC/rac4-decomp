#include "common.h"

typedef int u128 __attribute__((mode(TI)));
extern void func_L01_00445A10(void *a, u128 b);
extern void func_L01_004457B8(void *a, u128 b);

// Calls two helpers with the object and the 128-bit value at offset 0x20 of its sub-object.
void func_L01_00445778(void *arg0) {
    u8 *sub = *(u8 **)((u8 *)arg0 + 0xAC);
    func_L01_00445A10(arg0, *(u128 *)(sub + 0x20));
    func_L01_004457B8(arg0, *(u128 *)(sub + 0x20));
}

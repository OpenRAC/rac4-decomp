#include "common.h"

/* Passes the 128-bit arg1 to func_004312D0, then stores it at offset 0x70 of the object that arg0 holds at offset 0xAC. */
typedef int u128 __attribute__((mode(TI)));
extern void func_004312D0(u128, s32, void *, s32);

void func_00431568(void *arg0, u128 arg1, s32 arg2) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0xAC);
    func_004312D0(arg1, arg2, temp_s1, 6);
    *(u128 *)((u8 *)temp_s1 + 0x70) = arg1;
}

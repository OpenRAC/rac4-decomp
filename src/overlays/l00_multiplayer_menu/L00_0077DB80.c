#include "common.h"

extern void func_0015DB88(int *arg0, int arg1);
extern u8 D_0016FD20[];

/* Store the address of D_0016FD20 through arg0, then call func_0015DB88 when arg1 has bit 0 set. */
void func_L00_0077DB80(void **arg0, s32 arg1) {
    s32 temp = arg1 & 1;
    *arg0 = D_0016FD20;
    if (temp != 0) {
        func_0015DB88((int *)arg0, temp);
    }
}

#include "common.h"

extern void func_L04_004DCF70(void *);

void func_L04_004DD400(u8 *arg0) {
    func_L04_004DCF70(arg0);
    *(u16 *)(arg0 + 0x7E) = 0;
}

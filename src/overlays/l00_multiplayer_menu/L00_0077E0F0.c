#include "common.h"

extern void func_0015DB88(void);
extern u8 D_0016FDC0[];

/* Store address of D_0016FDC0 to arg0+0x10, then conditionally call func_0015DB88 if arg1 & 1 != 0 */
void func_L00_0077E0F0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x10) = D_0016FDC0;

    if ((arg1 & 1) != 0) {
        func_0015DB88();
    }
}

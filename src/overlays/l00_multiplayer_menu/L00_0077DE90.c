#include "common.h"

extern void func_0015DB88(void);
extern u8 D_0016FE18[];

/* Store address of D_0016FE18 to arg0+0xD8, then conditionally call func_0015DB88 if arg1 & 1 != 0 */
void func_L00_0077DE90(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0xD8) = D_0016FE18;

    if ((arg1 & 1) != 0) {
        func_0015DB88();
    }
}

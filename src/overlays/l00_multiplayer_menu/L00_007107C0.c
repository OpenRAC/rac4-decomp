#include "common.h"

extern void func_0015DB88(void);
extern u8 D_004B7A38[];

/* Store address of D_004B7A38 to arg0+0x58, then conditionally call func_0015DB88 if arg1 & 1 != 0 */
void func_L00_007107C0(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 0x58) = D_004B7A38;

    if ((arg1 & 1) != 0) {
        func_0015DB88();
    }
}

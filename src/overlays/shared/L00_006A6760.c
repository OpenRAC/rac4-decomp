#include "common.h"

extern void func_0015DB88(void);
extern u8 D_004B46E8[];

/* Store address of D_004B46E8 to arg0+8, then conditionally call func_0015DB88 if arg1 & 1 != 0 */
void func_L00_006A6760(void *arg0, s32 arg1) {
    *(void **)((char *)arg0 + 8) = D_004B46E8;

    if ((arg1 & 1) != 0) {
        func_0015DB88();
    }
}

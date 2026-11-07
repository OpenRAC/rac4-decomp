#include "common.h"

extern u8 *D_0021DF68;
extern void func_01EEEDD0(u8 *, s32);

void func_L00_0071A1D0(void) {
    if (D_0021DF68 != NULL) {
        func_01EEEDD0(D_0021DF68, 0);
        D_0021DF68 = NULL;
    }
}

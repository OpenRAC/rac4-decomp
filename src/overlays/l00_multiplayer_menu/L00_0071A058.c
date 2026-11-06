#include "common.h"

extern u8 *D_0021DF68;
extern void func_01EEF414(u8 *, s32);

void func_L00_0071A058(void) {
    u8 *p;

    p = D_0021DF68;
    if (p != NULL) {
        func_01EEF414(p, 3);
    }
}

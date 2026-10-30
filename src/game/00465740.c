#include "common.h"

/* Calls and clears the callback in D_0021F164 if set, then calls func_00464AF8(6) when D_21DADC is 3. */
void (*D_0021F164)(void) = 0;
extern s32 D_21DADC;
extern void func_00464AF8(int);

void func_00465740(void) {
    if (D_0021F164 != 0) {
        D_0021F164();
        D_0021F164 = 0;
    }
    if (D_21DADC == 3) {
        func_00464AF8(6);
    }
}

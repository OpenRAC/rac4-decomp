#include "common.h"

/* Calls and clears the callback in D_0021F168 if set, then calls func_00464AF8(0xB) when D_21DADC is 3. */
void (*D_0021F168)(void) = 0;
extern s32 D_21DADC;
extern void func_00464AF8(int);

void func_004656A8(void) {
    if (D_0021F168 != 0) {
        D_0021F168();
        D_0021F168 = 0;
    }
    if (D_21DADC == 3) {
        func_00464AF8(0xB);
    }
}

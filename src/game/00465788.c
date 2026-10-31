#include "common.h"

extern void func_00464AF8(int);
extern void func_00465F18(void);
extern u8 D_00171948[];
extern s32 D_21DAE4;

/* Clear the flag bit 4 in D_21DAE4, then raise the pending events for the state block. */
void func_00465788(void) {
    u8 *w;
    s32 tmp;

    tmp = D_21DAE4 & ~4;
    D_21DAE4 = tmp;
    w = D_00171948;
    if (*(s32 *)(w + 0x1C4) == 2) {
        if (*(s32 *)(w + 0x1CC) < 0) {
            if (*(s32 *)(w + 0x1D4) != 0) {
                func_00465F18();
                func_00464AF8(0x16);
            } else {
                func_00464AF8(2);
            }
        }
    }
}

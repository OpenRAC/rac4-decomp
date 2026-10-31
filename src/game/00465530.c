#include "common.h"

extern void func_00464AF8(int);
extern u8 D_00171948[];

void *D_0021F160 = 0;
u16 D_0021F16C = 0;

/* Runs the pending callback once, then resets the record at D_00171948 and calls func_00464AF8(0x17). */
void func_00465530(void) {
    u8 *s0 = D_00171948;

    if (*(s32 *)(s0 + 0x1C4) == 2) {
        if (*(s32 *)(s0 + 0x1CC) < 0) {
            if (D_0021F160 != 0) {
                ((void (*)(int))D_0021F160)(2);
                D_0021F160 = 0;
            }
            *(s32 *)(s0 + 0x1B0) = 0;
            *(u16 *)(s0 + 0x18) = D_0021F16C;
            func_00464AF8(0x17);
        }
    }
}

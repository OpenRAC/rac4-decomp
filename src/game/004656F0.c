#include "common.h"

extern void func_00464AF8(int);
extern u8 D_00171948[];
/* Calls func_00464AF8 with 4, or with 5 when the block at D_00171948 has its word at 8 equal to 2 and its word at 0x10 set. */
void func_004656F0(void) {
    u8 *base;

    base = D_00171948;
    if (*(s32 *)(base + 8) != 2) {
        func_00464AF8(4);
    } else if (*(s32 *)(base + 0x10) != 0) {
        func_00464AF8(5);
    }
}

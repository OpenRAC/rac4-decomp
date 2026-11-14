#include "common.h"

extern void func_L00_005DD4A0(void *);

// Release the two pointers held in the object's sub-block, then clear its fields.
void func_L41_004489F0(u8 *arg0) {
    u8 *s0 = *(u8 **)(arg0 + 172);
    void *temp_a0 = *(void **)(s0 + 24);
    void *temp_a0_2;
    if (temp_a0 != 0) {
        func_L00_005DD4A0(temp_a0);
    }
    temp_a0_2 = *(void **)(s0 + 28);
    *(void **)(s0 + 24) = 0;
    if (temp_a0_2 != 0) {
        func_L00_005DD4A0(temp_a0_2);
    }
    *(void **)(s0 + 28) = 0;
    *(s32 *)(s0 + 132) = 0;
}

#include "common.h"

s32 D_00220A0C = 0;
s32 D_00220A10 = 0;
s32 D_00220A14 = 0;

/* Pops the head of the list and pushes it onto the free list. */
s32 func_L00_007099F0(void) {
    s32 head = D_00220A10;

    if (head != 0) {
        D_00220A10 = *(s32 *)((u8 *)head + 0x19C);
        if (D_00220A10 == 0) {
            D_00220A14 = 0;
        }
        *(s32 *)((u8 *)head + 0x19C) = D_00220A0C;
        D_00220A0C = head;
    }
    return head;
}

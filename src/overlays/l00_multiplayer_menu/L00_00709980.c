#include "common.h"

s32 D_00220A0C = 0;

/* Pop the head of the free list and clear its link. */
s32 func_L00_00709980(void) {
    s32 head = D_00220A0C;

    if (head != 0) {
        D_00220A0C = (*(s32 *)((u8 *)head + 0x19C));
        (*(s32 *)((u8 *)head + 0x19C)) = 0;
    }
    return head;
}

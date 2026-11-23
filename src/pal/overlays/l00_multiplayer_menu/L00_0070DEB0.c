#include "common.h"

void *D_00220AD8 = 0;

/* Replaces the current owner, notifying the old and new owners. */
void *func_L00_0070DEB0(void *arg0)
{
    void *previous = D_00220AD8;

    if (previous != 0) {
        (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)previous + 0x58) + 0x20))(previous, 1, 0);
    }
    if (arg0 != 0) {
        (*(void (**)(void *, s32, s32))((u8 *)*(void **)((u8 *)arg0 + 0x58) + 0x20))(arg0, 1, 0);
    }
    D_00220AD8 = arg0;
    return previous;
}

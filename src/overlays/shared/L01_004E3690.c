#include "common.h"

extern void func_L01_004E3640(void *);

/* Calls func_L01_004E3640 on the object, then reports whether its state's +0x334 word is negative when inverted. */
s32 func_L01_004E3690(u8 *arg0) {
    u8 *obj;
    u8 *state;
    s32 zero;

    obj = arg0;
    state = *(u8 **)(obj + 0xAC);
    func_L01_004E3640(obj);
    zero = 0;
    return ~*(s32 *)(state + 0x334) < zero;
}

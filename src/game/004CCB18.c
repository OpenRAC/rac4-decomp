#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s16 func_00547D58(s32 arg0, s32 arg1);

/* Plays one of five sounds picked by the current player's state value. */
void func_004CCB18(void) {
    u8 *obj;

    obj = func_00510BE8(func_00505B20());
    func_0045E038(-1);
    switch (func_00547D58(*(s32 *)(obj + 0x26E4), 1)) {
    case 0:
        func_0045E038(0x33B1);
        return;
    case 1:
        func_0045E038(0x33B2);
        return;
    case 2:
        func_0045E038(0x33B3);
        return;
    case 3:
        func_0045E038(0x33B4);
        return;
    default:
        func_0045E038(0x33B5);
        return;
    }
}

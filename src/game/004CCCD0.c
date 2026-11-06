#include "common.h"

extern s32 func_0045E038(s32);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s16 func_00547D58(s32 arg0, s32 arg1);

/* Plays one of five sounds chosen by a state lookup on the current object. */
void func_004CCCD0(void) {
    s32 temp_v0;
    char *temp_s0;

    temp_s0 = func_00510BE8(func_00505B20());
    func_0045E038(-1);
    temp_v0 = func_00547D58(*(s32 *)(temp_s0 + 0x26E4), 1);
    switch (temp_v0) {
    case 0:
        func_0045E038(0x33A9);
        return;
    case 1:
        func_0045E038(0x33AA);
        return;
    case 2:
        func_0045E038(0x33AB);
        return;
    case 3:
        func_0045E038(0x33AC);
        return;
    default:
        func_0045E038(0x33AD);
        return;
    }
}

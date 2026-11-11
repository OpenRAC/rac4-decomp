#include "common.h"

extern f32 func_004A8430(void *arg0);
extern u8 func_004A85D0(f32 arg0);
extern s32 func_00505B20(void);
extern void *func_00510BE8(s32 arg0);
extern s32 func_00548DA0();
extern s32 D_003D1738[];
extern s32 D_003D17A0[];
extern s32 D_00308108[];

/* Return the current character's table slot, or 4 when the angle is 360 or the slot is unavailable. */
s32 func_004A8600(void) {
    s32 index = func_00505B20();
    s32 *entry = (s32 *)((u8 *)D_00308108 + index * 0xB8);
    void *obj = func_00510BE8(index);
    f32 angle = func_004A8430(obj);
    s32 slot;
    s32 value;
    s32 *row;

    if (angle != 360.0f) {
        slot = func_004A85D0(angle);
        row = (s32 *)((u8 *)D_003D17A0 + (entry[0x23] << 5));
        value = row[D_003D1738[slot]];
        if (value == 0 || (func_00548DA0(*(s32 *)((u8 *)obj + 0x26E4), value) & 0xFF) == 0) {
            slot = 4;
        }
    } else {
        slot = 4;
    }
    return slot;
}

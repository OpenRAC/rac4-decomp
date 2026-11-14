#include "common.h"

extern s32 func_L00_007647B0(s32 identifier);
extern u8 *D_00220D14;
extern u8 *D_002233A4;

// Update a menu state: drop the pending flag at +0x274 when the object at +0x108 is not ready, and set a state code at +0x118 in those cases or when +0x0 of the table is -1. Returns whether a change was made.
s32 func_L00_00722348(u8 *arg0) {
    s32 ret = 0;
    u8 *table = *(u8 **)(D_002233A4 + 0x3C);
    u8 *sel;
    u8 *obj;

    if (arg0[0x274] != 0) {
        obj = *(u8 **)(D_00220D14 + 0x108);
        sel = 0;
        if (obj != 0) {
            if (obj[0xA8] == 1) {
                sel = obj;
            }
        }
        if (sel == 0) {
            arg0[0x274] = 0;
            ret = 1;
            *(s32 *)(D_00220D14 + 0x118) = 0x1B;
        }
    }
    if (table[0x30] == 0) {
        if (*(s32 *)table == -1) {
            func_L00_007647B0(0x3B);
            *(s32 *)(D_00220D14 + 0x118) = 7;
            ret = 1;
        }
    }
    return ret;
}

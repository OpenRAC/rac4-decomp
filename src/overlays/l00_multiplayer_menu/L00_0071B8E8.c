#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*unk20)(void *, s32, s32);
} Type2;
typedef struct {
    s32 pad0;
    s32 unk4;
    u8 pad8[0x50];
    Type2 *unk58;
} Type1;
typedef struct {
    u8 pad0[0xB0];
    Type1 *unkB0[(0x230 - 0xB0) / 4];
    s32 unk230;
} Type0;
void func_005E64A8(s32); /* extern */
// Moves the selection from the current slot to slot arg1, notifying both slots, and returns the old index.
s32 func_L00_0071B8E8(Type0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;
    Type1 *temp_a0;
    Type1 *temp_a0_2;

    temp_s2 = arg0->unk230;
    if (temp_s2 >= 0) {
        temp_a0 = arg0->unkB0[temp_s2];
        if (temp_a0->unk4 >= 4) {
            temp_a0->unk58->unk20(temp_a0, 4, 0);
        }
    }
    arg0->unk230 = arg1;
    if (arg1 >= 0) {
        temp_a0_2 = arg0->unkB0[arg1];
        if (temp_a0_2->unk4 >= 4) {
            temp_a0_2->unk58->unk20(temp_a0_2, 5, arg2);
        } else {
            arg0->unk230 = -1;
        }
    }
    func_005E64A8(1);
    return temp_s2;
}

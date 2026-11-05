#include "common.h"

extern u8 D_0030ECC0[];
extern s32 D_00171C88[];

s32 func_00506BB8(void);
void func_00502520(s32 arg0);
void func_004CEFD0(void);
void func_004CED68(void);
void func_004CEDA8(void);
void func_004A2468(s32 arg0);
void func_004CEE80(void);

void func_004CEB68(s32 arg0) {
    s32 index;
    s32 record;
    s32 valueAddress;
    s32 value;
    s32 state;

    index = func_00506BB8();
    record = (s32)D_0030ECC0 + index * 0x280;
    valueAddress = (s32)D_0030ECC0 + 0x27C + index * 0x280;
    value = *(s32 *)valueAddress;
    if (value != -1) {
        if (value >= 0) {
            D_00171C88[(u32)value >> 5] &= ~(1 << (value & 0x1F));
        }
        *(s32 *)valueAddress = -1;
    }
    state = *(s32 *)record;
    switch (state) {
        case 1:
            *(s32 *)record = 0;
            break;
        case 2:
            func_00502520(arg0);
            break;
        case 0:
            func_004CEFD0();
            break;
    }
    if ((*(s32 *)(record + 8) & 1) != 0) {
        func_004CED68();
    }
    if ((*(s32 *)(record + 8) & 2) != 0) {
        func_004CEDA8();
    }
    func_004A2468(record + 0x210);
    state = *(s32 *)(record + 8);
    state &= 4;
    if (state != 0) {
        func_004CEE80();
    }
}

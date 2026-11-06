#include "common.h"

extern s32 D_00307354[];
extern s32 func_00506BB8(void);
extern s32 func_004A0F40(s32);
extern s32 func_004A0728(s32);
extern void func_004A08B0(s32);
extern void func_004A0660(s32);
extern f32 func_00498038(void *, s32);
extern void func_004A0928(s32);
extern void func_0049AA18(s32);
extern void func_00506590(s32, s32);

void func_004A0230(void) {
    s32 index = func_00506BB8();
    s32 *record = D_00307354 + index * 0x80;
    f32 value;
    f32 zero;
    s32 first;
    s32 second;

    if (((u8 *)record)[0x24] != 0) {
        if (*(f32 *)(record + 0xA) == 1.0f && record[0xC] == record[0xD]) {
            if (func_004A0728(func_004A0F40(index)) == 0) {
                func_004A08B0(1);
            }
            func_004A0660(index);
            return;
        }
    }
    value = *(f32 *)(record + 0xA);

fallback:
    zero = 0.0f;
    if (value != zero || ((u8 *)record)[0x24] != 0) {
        first = func_00498038(record + 0xA, ((u8 *)record)[0x24]) != zero;
        second = func_00498038(record + 0xE, 0) != zero;
        if ((second | first) != 0) {
            func_004A0928(index);
        }
        return;
    }

    if (record[0x14] == 0) {
        return;
    }
    func_0049AA18(record[0x14]);
    record[0x14] = 0;
    func_00506590(index * 0x40 + 0x140004, 0);
}

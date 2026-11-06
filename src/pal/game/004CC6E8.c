#include "common.h"

extern s32 func_00506BB8(void);
extern void func_004CD2F0(void);
extern void func_004CDEA8(void);
extern void func_004CC7D8(void);
extern s32 func_004A2798(s32 *, s32);
extern void func_0049DEA8(s32, s32, s32);
extern void func_0049DFB8(s32, s32);
extern void func_0049D138(s32, s32, s32, s32, s32);
extern void func_0049CFC8(s32, s32);
extern void func_004CCFE8(s32);
extern u8 D_0030EAA0[];
extern s32 D_00221A20;

void func_004CC6E8(void)
{
    s32 index = func_00506BB8();
    s32 *record = (s32 *)(D_0030EAA0 + index * 100);
    s32 value;
    s32 other;

    record[1] = -1;
    record[0] = 1;
    func_004CD2F0();
    func_004CDEA8();
    func_004CC7D8();
    value = func_004A2798(&D_00221A20, 0x22);
    func_0049DEA8(index, 0, value);
    func_0049DFB8(index, 1);
    other = D_00221A20;
    value = func_004A2798(&D_00221A20, 0x22);
    func_0049D138(index, 0, other, value, 0);
    if (record[1] >= 0) {
        func_0049CFC8(index, 1);
    }
    func_004CCFE8(record[1]);
    record[2] = 1;
}

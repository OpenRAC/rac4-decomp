#include "common.h"

extern s32 D_0031B6B0[];
extern s32 *D_003D2A70[];
extern s32 func_00506BB8(void);
extern void func_00498090(s32, s32, s32);
extern s32 func_00499120(s32);
extern void func_004D37F0(s32);
extern s32 func_004981D8(void *, s32, void *);
extern s32 func_00498280(void *, s32, void *);
extern void func_004D37A8(void);
extern void func_004D3898(s32);
extern void func_004E3138(s32, s32, s32);
extern void func_004E17B8(void);

void func_004D3AD0(void) {
    s32 index = func_00506BB8();
    s32 *record = D_0031B6B0 + index * 7;
    s32 result = 0;
    s32 mode;
    s32 value;
    s32 *entry;

    func_00498090(index, 3, 4);
    mode = func_00499120(4);
    switch (mode) {
    case 1:
        value = record[1];
        if (value >= 0) {
            entry = (s32 *)((u8 *)D_003D2A70 + value * 0x18);
            ((void (*)(u32))entry[3])(0xFFFFFFFFU);
        }
        break;
    case 2:
        ((void (*)(u32))record[4])(0xFFFFFFFFU);
        break;
    case 5:
        if (record[1] >= 0) {
            func_004D37F0(record[1]);
            result = func_004981D8(record + 1, 5, func_004D37A8);
            goto case6;
        }
        break;
    case 6:
        if (record[1] >= 0) {
            func_004D37F0(record[1]);
            result = func_00498280(record + 1, 5, func_004D37A8);
        }
        break;
    }
case6:
    if (result != 0) {
        func_004D3898(record[1]);
        record[2] |= 1;
        func_004E3138(0x12, 0, 0);
        func_004E17B8();
    }
}

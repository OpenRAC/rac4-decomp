#include "common.h"

extern void func_00497438(s32 i, s32 a, s32 b);
extern void func_004B2520(void);
extern void func_004B2610(void);
extern void func_004B26F0(void);
extern void func_004B29D8(void);
extern void func_004B2AD8(void);
extern void func_004B2C80(void);
extern void func_004B2E08(void);
extern void func_004B2EF0(void);
extern void func_004B2F58(void);
extern void func_004B31D0(void);
extern void func_004B36C0(void);
extern void func_004B3BA8(void);
extern void func_004B3DE0();
extern void func_004B3EF8(void);
extern void func_004B4348(void);
extern void func_004B4A40(void);
extern void func_005014B0(s32 *a0);
extern void *func_00510BE8(s32 arg0);
extern s32 *D_0021DDA4;
extern s32 D_003096A8[];

void func_004B2348(s32 *arg0) {
    s32 i;

    for (i = 0; i < *D_0021DDA4; i++) {
        *(s16 *)((u8 *)func_00510BE8(i) + 0x3BA) = 5;
        func_00497438(i, 5, 2);
    }
    if (D_003096A8[31] != 0) {
        D_003096A8[31]--;
    } else {
        switch (D_003096A8[0]) {
        case 0:
            func_004B4348();
            D_003096A8[0] = 1;
            break;
        case 1:
            func_004B2520();
            break;
        case 2:
            func_004B2610();
            break;
        case 3:
            func_004B26F0();
            break;
        case 4:
            func_004B29D8();
            break;
        case 5:
            func_004B2AD8();
            break;
        case 6:
            func_004B2C80();
            break;
        case 7:
            func_004B2E08();
            break;
        case 8:
            func_004B3EF8();
            D_003096A8[0] = 9;
            break;
        case 9:
            func_004B2EF0();
            break;
        case 10:
            func_004B2F58();
            break;
        case 11:
            func_004B31D0();
            break;
        case 12:
            func_004B36C0();
            break;
        case 13:
            func_004B3BA8();
            break;
        case 15:
            func_004B3DE0();
            break;
        case 16:
            func_005014B0(arg0);
            break;
        }
    }
    func_004B4A40();
}

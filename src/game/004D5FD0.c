#include "common.h"

extern u8 D_31D100[];
extern s32 func_004A1730(void *a0);
extern void func_004D6098(void);
extern void func_004D62F0(void);
extern void func_004D64F0(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);

void func_004D5FD0(s32 arg0) {
    s32 *entry = (s32 *)(func_00505B20() * 0x528 + D_31D100);

    switch (entry[0]) {
    case 0:
        entry[0] = 2;
        break;
    case 1:
        func_005014B0(arg0);
        break;
    case 2:
        func_004D6098();
        break;
    }
    if (entry[1] & 1) {
        func_004D64F0();
    }
    func_004A1730((u8 *)entry + 0x4BC);
    if (entry[1] & 2) {
        func_004D62F0();
    }
}

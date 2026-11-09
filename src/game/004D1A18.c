#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
} Type1;

extern s32 func_004A1730(void *);
extern void func_004D1BC0(void);
extern void func_004D1C00(void);
extern void func_004D1CF8(void);
extern void func_004D1E38(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern u8 D_0031B050[];

void func_004D1A18(s32 arg0) {
    Type1 *entry = (Type1 *)(D_0031B050 + func_00505B20() * 0x15C);

    switch (entry->f0) {
    case 1:
        entry->f0 = 0;
        break;
    case 2:
        func_005014B0(arg0);
        break;
    case 0:
        func_004D1E38();
        break;
    }
    if (entry->f8 & 1) {
        func_004D1BC0();
    }
    if (entry->f8 & 2) {
        func_004D1C00();
    }
    func_004A1730((u8 *)entry + 0xF0);
    if (entry->f8 & 4) {
        func_004D1CF8();
    }
}

#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    void (*fC)(u32);
    s32 f10;
    s32 f14;
} Type2;

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    void (*f10)(u32);
    s32 f14;
    s32 f18;
} Entry;

extern void func_00497438(s32, s32, s32);
extern s32 func_00497580(s32 *, s32, s32 (*)(s32));
extern s32 func_00497628(s32 *, s32, s32 (*)(s32));
extern s32 func_004983E8(s32);
extern s32 func_004D2898(s32);
extern void func_004D28E0(s32);
extern void func_004D2988(s32);
extern void func_004E0858(void);
extern s32 func_004E21D8(u32, s32, s32);
extern s32 func_00505B20(void);
extern Type2 D_003D2A00[];
extern Entry D_0031B6B0[];

void func_004D2BC0(void) {
    s32 result = 0;
    s32 i = func_00505B20();
    Entry *e = &D_0031B6B0[i];

    func_00497438(i, 3, 4);
    switch (func_004983E8(4)) {
    case 1:
        {
            s32 idx = e->f4;
            if (idx >= 0) {
                ((Type2 *)(idx * 0x18 + (u8 *)D_003D2A00))->fC(0xFFFFFFFF);
            }
        }
        break;
    case 2:
        e->f10(0xFFFFFFFF);
        break;
    case 5:
        if (e->f4 >= 0) {
            func_004D28E0(e->f4);
            result = func_00497580(&e->f4, 5, func_004D2898);
        }
        break;
    case 6:
        if (e->f4 >= 0) {
            func_004D28E0(e->f4);
            result = func_00497628(&e->f4, 5, func_004D2898);
        }
        break;
    }
    if (result != 0) {
        func_004D2988(e->f4);
        e->f8 |= 1;
        func_004E21D8(0x12, 0, 0);
        func_004E0858();
    }
}

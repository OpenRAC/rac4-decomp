#include "common.h"

typedef struct Display {
    u8 fields[0x150];
    s16 width;
    s16 height;
} Display;
extern Display D_00206A40;
extern s32 D_00222B10;
extern void func_0044DE80(s32, s32, s32, s32);
extern void func_00449E98(s32, s32, s32, s32, u64);

void func_L01_00435A70(void) {
    func_0044DE80((s32)&D_00222B10, 0x42, 0x48, 0);
    func_00449E98(0, D_00206A40.height, 0, D_00206A40.width, (s32)0x80808080);
}

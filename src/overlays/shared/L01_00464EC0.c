#include "common.h"
extern void func_0044DE80(s32, s32, s32, s32);
extern void func_00449E98(int, int, int, int, u64);
typedef struct Display { u8 fields[0x150]; s16 width; s16 height; } Display;
extern Display D_00206A40;
extern s32 D_00222B10;
void func_L01_00464EC0(void) {
    func_0044DE80((s32)&D_00222B10, 0x42, 0x48, 0);
    func_00449E98(0, D_00206A40.height, 0, D_00206A40.width, (s32)0x80808080);
}

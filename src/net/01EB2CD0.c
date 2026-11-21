/* cflags: @ee296 -O2 -G0 */
#include "common.h"

extern s32 D_001681A0[];
extern s32 D_01EB30B8[];
extern s32 D_1B25C0[];
extern s32 func_01EA90F0();
extern s32 func_01EB1B30();
extern s32 func_01EB1B90();
extern s32 func_01EB3028();
extern s32 func_01EB30C8();
extern s32 func_01EB3138();
extern s32 func_01EB31D8();
extern s32 func_01EB32C8();
extern s32 func_01EB32F8();
extern s32 func_01EB33E0();
extern s32 func_01EB3470();
extern s32 func_01EB3558();
extern s32 func_01EB3628();
extern s32 func_01EB36A0();
extern s32 func_01EB37A8();
extern s32 func_01EB3838();
extern s32 func_01EB38E0();
extern s32 func_01EB3970();
extern s32 func_01EB3A88();
extern s32 func_01EB3B78();
extern s32 func_01EB3C70();
extern s32 func_01EB3CE0();
extern s32 func_01EB3E08();
extern s32 func_01EB3F10();
extern s32 func_01EB3F68();
extern s32 func_01EB42C0();
extern s32 func_01EB4518();
extern s32 func_01EB4778();
extern s32 func_01EB4990();
extern s32 func_01EB4A28();

/* Fills the function table at D_1B25C0 and points D_001681A0 at it. */
void func_01EB2CD0(void) {
    D_1B25C0[0x0 / 4] = (s32) func_01EA90F0;
    D_1B25C0[0x4 / 4] = (s32) func_01EB3028;
    D_1B25C0[0x8 / 4] = (s32) func_01EB42C0;
    D_1B25C0[0xC / 4] = (s32) func_01EB4778;
    D_1B25C0[0x10 / 4] = (s32) D_01EB30B8;
    D_1B25C0[0x14 / 4] = (s32) func_01EB31D8;
    D_1B25C0[0x18 / 4] = (s32) func_01EB32F8;
    D_1B25C0[0x1C / 4] = (s32) func_01EB33E0;
    D_1B25C0[0x20 / 4] = (s32) func_01EB3470;
    D_1B25C0[0x24 / 4] = (s32) func_01EB3558;
    D_1B25C0[0x28 / 4] = (s32) func_01EB3628;
    D_1B25C0[0x2C / 4] = (s32) func_01EB36A0;
    D_1B25C0[0x30 / 4] = (s32) func_01EB37A8;
    D_1B25C0[0x34 / 4] = (s32) func_01EB3838;
    D_1B25C0[0x38 / 4] = (s32) func_01EB38E0;
    D_1B25C0[0x3C / 4] = (s32) func_01EB3F68;
    D_1B25C0[0x40 / 4] = (s32) func_01EB4518;
    D_1B25C0[0x44 / 4] = (s32) func_01EB3970;
    D_1B25C0[0x48 / 4] = (s32) func_01EB3A88;
    D_1B25C0[0x4C / 4] = (s32) func_01EB3B78;
    D_1B25C0[0x50 / 4] = (s32) func_01EB3C70;
    D_1B25C0[0x54 / 4] = (s32) func_01EB3F10;
    D_1B25C0[0x58 / 4] = (s32) func_01EB32C8;
    D_1B25C0[0x5C / 4] = (s32) func_01EB3CE0;
    D_1B25C0[0x60 / 4] = (s32) func_01EB3E08;
    D_1B25C0[0x64 / 4] = (s32) func_01EB30C8;
    D_1B25C0[0x68 / 4] = (s32) func_01EB1B30;
    D_1B25C0[0x6C / 4] = (s32) func_01EB3138;
    D_1B25C0[0x70 / 4] = (s32) func_01EB1B90;
    D_1B25C0[0x74 / 4] = (s32) func_01EB4990;
    D_1B25C0[0x78 / 4] = (s32) func_01EB4A28;
    D_001681A0[0] = (s32) D_1B25C0;
}

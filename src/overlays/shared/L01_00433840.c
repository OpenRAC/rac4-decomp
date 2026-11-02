#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern u8 *D_00223800;

extern u8 *func_005869E0(s32, s32);
extern f32 func_0058FF80(f32, f32);
extern void func_0058DF58(u8 *);

// Creates a moby of class 0x201C with 0x80 bytes of data: copies pos and dir, random angles
// from func_0058FF80(-pi, pi), twice its class scale at +0x70, the arguments, then calls
// func_0058DF58 and stores it in D_00223800. Returns the moby or NULL.
u8 *func_L01_00433840(u128 *pos, u128 *dir, s32 arg2, s32 arg3, s32 arg4, u128 *arg5) {
    u8 *moby = func_005869E0(0x201C, 0x80);

    if (moby != NULL) {
        u8 *vars;
        moby[0x30] = 0xFF;
        *(s16 *)(moby + 0x32) = 0x1FF;
        moby[0x31] = 1;
        moby[0x20] = 0;
        vars = *(u8 **)(moby + 0xAC);
        *(u128 *)(moby + 0x10) = *pos;
        *(u128 *)(vars + 0) = *dir;
        *(s32 *)(vars + 0x50) = 0;
        *(f32 *)(moby + 0xF0) = func_0058FF80(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF4) = func_0058FF80(-3.1415927f, 3.1415927f);
        *(f32 *)(moby + 0xF8) = func_0058FF80(-3.1415927f, 3.1415927f);
        *(s32 *)(moby + 0xFC) = 0;
        *(f32 *)(moby + 0x70) = 2.0f * *(f32 *)(*(u8 **)(moby + 0x24) + 0x24);
        *(s32 *)(vars + 0x68) = arg4;
        *(u128 *)(vars + 0x40) = *arg5;
        func_0058DF58(moby);
        D_00223800 = moby;
        *(s32 *)(vars + 0x58) = 0x32;
        *(s32 *)(vars + 0x60) = arg3;
        *(s32 *)(vars + 0x64) = arg2;
    }
    return moby;
}

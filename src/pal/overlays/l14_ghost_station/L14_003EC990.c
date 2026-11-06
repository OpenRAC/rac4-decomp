/* cflags: -mno-split-addresses */
#include "common.h"

typedef int u128 __attribute__((mode(TI)));

extern f32 D_0022270C;
extern u8 D_002226A0[];
extern u128 func_004FF0F0(u128, f32);
extern s32 func_00472E40(s32);
extern u128 func_L01_005A32E0(u8 *, u128, f32, f32, f32);
extern void func_L01_00555640(u8 *, u128, u128, f32, f32, f32, s32, s32, s32, s32, s32);
extern s16 func_004E2EF0(s32, s32, u8 *);

// While D_0022270C is below 0.9: three times, when func_00472E40 (11, 9, 11) returns 0,
// gets a point from func_L01_005A32E0 (offsets scaled by the moby's +0x70) and passes it to
// func_L01_00555640 with the value from func_004FF0F0, then calls func_004E2EF0(0, 0, moby).
// The vector passed to func_L01_005A32E0 is the previous result (unset the first time).
void func_L14_003EC990(u8 *moby) {
    u128 pos[1];
    u128 val;

    if (D_0022270C < 0.9f) {
        val = func_004FF0F0(*(u128 *)(moby + 0xD0), 0.120000005f);
        if (func_00472E40(11) == 0) {
            pos[0] = func_L01_005A32E0(moby, pos[0], *(f32 *)(moby + 0x70) * 10.0f, *(f32 *)(moby + 0x70) * 9.0f,
                                       *(f32 *)(moby + 0x70) * 5.0f);
            func_L01_00555640(D_002226A0, pos[0], val, 0.15f, 0.10000001f, 0.0f, 3, 2, 30, 0xFE5050, 0);
            func_004E2EF0(0, 0, moby);
        }
        if (func_00472E40(9) == 0) {
            pos[0] = func_L01_005A32E0(moby, pos[0], *(f32 *)(moby + 0x70) * 6.0f, *(f32 *)(moby + 0x70) * 9.0f,
                                       *(f32 *)(moby + 0x70) * -5.0f);
            func_L01_00555640(D_002226A0, pos[0], val, 0.15f, 0.10000001f, 0.0f, 3, 2, 30, 0xFE5050, 0);
            func_004E2EF0(0, 0, moby);
        }
        if (func_00472E40(11) == 0) {
            pos[0] = func_L01_005A32E0(moby, pos[0], *(f32 *)(moby + 0x70) * -7.0f, *(f32 *)(moby + 0x70) * 9.0f,
                                       *(f32 *)(moby + 0x70));
            func_L01_00555640(D_002226A0, pos[0], val, 0.15f, 0.10000001f, 0.0f, 3, 2, 30, 0xFE5050, 0);
            func_004E2EF0(0, 0, moby);
        }
    }
}
